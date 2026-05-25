#pragma once
#include "node.h"
#include <map>
#include <vector>

struct Way {
    vector<Node*> nodes;
    int length;
    Way() : length(-1) {}
};

struct MarkedNode {
    Node* node;
    int mark;
    Node* previous;
    MarkedNode(Node* anode = 0, int amark = 0, Node* aprevious = 0)
        : node(anode), mark(amark), previous(aprevious) {}
};

class PriorityQueue {
    multimap<int, MarkedNode> nodes;
public:
    void push(Node* node, int mark, Node* previous);
    MarkedNode pop();
    bool empty() const;
};

class Dijkstra {
    const Graph& graph;
    Way unroll(map<Node*, MarkedNode>& visited, Node* begin, Node* end);
public:
    Dijkstra(const Graph& agraph) : graph(agraph) {}
    Way shortestWay(Node* begin, Node* end);
};
