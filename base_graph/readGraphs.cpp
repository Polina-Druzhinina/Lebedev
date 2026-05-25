#include "readGraphs.h"
#include <fstream>
#include <iostream>

bool ReadGraphs::load(const string& filename, Graph& graph, map<int, Node*>& nodeMap){
    ifstream file(filename);

    if(!file.is_open()){
        cout << "File not open" << endl;
        return false;
    }

    int num;

    if (!(file >> num) || num <= 0) {
        cout << "Ошибка: файл должен начинаться с числа вершин (>0)" << endl;
        return false;
    }

    for (int i = 0; i < num; ++i) {
        Node* node = new Node(to_string(i));
        graph.addNode(node);
        nodeMap[i] = node;
    }

    int u, v, weight;

    while(file >> u >> v >> weight){

        map<int, Node*>::iterator itU = nodeMap.find(u);
        map<int, Node*>::iterator itV = nodeMap.find(v);

        if (itU != nodeMap.end() && itV != nodeMap.end()) {
            graph.addEdge(itU->second, itV->second, weight);
        } else {
            cout << "Ребро (" << u << ", " << v
                 << ") ссылается на несуществующую вершину";
        }
    }

    return true;
}

void ReadGraphs::cleanup(Graph& graph, map<int, Node*>& nodeMap) {
    for (map<int, Node*>::iterator it = nodeMap.begin(); it != nodeMap.end(); ++it) {
        graph.removeNode(it->second);
        delete it->second;
    }
    nodeMap.clear();
}