#include "node.h"
#include <fstream>
#include <cstdlib>

Graph::Graph(const char* fileName): owner(true) {
    ifstream file(fileName);
    string source;
    string target;

    while (file >> source >> target) {
        if (source == "Source" || target == "Target") continue;
        addEdge(source, target);
    }
}

Graph::~Graph() {
    if (!owner) return;
    for (set<Node*>::iterator it = nodes.begin(); it != nodes.end(); ++it) {
        delete *it;
    }
    nodes.clear();
    nodeByName.clear();
}

Node* Graph::getOrCreateNode(const string& name) {
    Node* node = getNode(name);
    if (node) return node;

    node = new Node(name);
    addNode(node);
    return node;
}

void Graph::addNode(Node* node){
    if(node){
        nodes.insert(node);
        nodeByName[node->getName()] = node;
    }
}

void Graph::removeEdge(Node* begin, Node* end){
    if(nodes.find(begin) == nodes.end()) return;
    if(nodes.find(end) == nodes.end()) return;

    begin -> removeNeighbour(end);
    end -> removeNeighbour(begin);
}

void Graph::removeNode(Node* node){
    nodes.erase(node);
    if (node) nodeByName.erase(node->getName());
    for(set<Node*>::iterator it = nodes.begin(); it != nodes.end(); it++){
        (*it) -> removeNeighbour(node);
    }
    
}

void Graph::addEdge(Node* begin, Node* end, int weight){
    if(nodes.find(begin) == nodes.end()) return;
    if(nodes.find(end) == nodes.end()) return;

    begin -> addNeighbour(end, weight);
    end -> addNeighbour(begin, weight);
}

void Graph::addEdge(const string& begin, const string& end) {
    Node* beginNode = getOrCreateNode(begin);
    Node* endNode = getOrCreateNode(end);
    addEdge(beginNode, endNode, 1);
}

Node* Graph::getNode(const string& name) const {
    map<string, Node*>::const_iterator it = nodeByName.find(name);
    if (it == nodeByName.end()) return 0;
    return it->second;
}

void Node::addNeighbour(Node* neighbour, int weight){
    if(neighbour){
        neighbours[neighbour] = weight;
    }
}

void Node::removeNeighbour(Node* neighbour) {
    if (neighbour) {
        neighbours.erase(neighbour);
    }
}

int Node::getWeight(Node* node) const {
    map<Node*, int>::const_iterator it = neighbours.find(node);
    if (it == neighbours.end()) return -1;
    return it->second;
}
