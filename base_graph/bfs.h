#pragma once
#include "node.h"
#include <set>
#include <queue>
using namespace std;
class BFS{
    const Graph& graph;
public:
    BFS(const Graph& agraph): graph(agraph){};
    bool connected(Node* begin, Node* end);
    set<Node*> component(Node* begin);
};
