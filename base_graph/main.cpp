#include <fstream>
#include <iostream>
#include "node.h"
#include "bfs.h"
using namespace std;

void printGraph(const Graph& graph) {
    for (set<Node*>::const_iterator it = graph.begin(); it != graph.end(); ++it) {
        Node* node = *it;
        cout << node->getName() << ": ";

        for (node_iterator nb = node->nb_begin(); nb != node->nb_end(); nb++) {
            cout << (*nb)->getName() << " ";
        }
        cout << endl;
    }
}

void writeComponent(const set<Node*>& component, int number) {
    string fileName = "Graph" + to_string(number) + ".txt";
    ofstream file(fileName.c_str());

    file << "Source Target" << endl;

    for (set<Node*>::const_iterator it = component.begin(); it != component.end(); ++it) {
        Node* node = *it;

        for (node_iterator nb = node->nb_begin(); nb != node->nb_end(); nb++) {
            if (component.find(*nb) != component.end()
                && node->getName() < (*nb)->getName()) {
                file << node->getName() << " " << (*nb)->getName() << endl;
            }
        }
    }

    cout << "Component " << number << " written to " << fileName << endl;
}

int main() {
    Graph graph("TestGraph.txt");

    if (graph.begin() == graph.end()) {
        cout << "TestGraph.txt is empty or not found" << endl;
        return 1;
    }

    cout << "Graph" << endl;
    printGraph(graph);

    BFS bfs(graph);
    set<Node*> visited;
    int componentNumber = 1;

    for (set<Node*>::const_iterator it = graph.begin(); it != graph.end(); ++it) {
        Node* node = *it;

        if (visited.find(node) == visited.end()) {
            set<Node*> component = bfs.component(node);
            writeComponent(component, componentNumber);

            for (set<Node*>::const_iterator c = component.begin(); c != component.end(); ++c) {
                visited.insert(*c);
            }

            componentNumber++;
        }
    }

    return 0;
}
