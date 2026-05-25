#pragma once
#include "node.h"
#include <set>
class DFS{
    const Graph& graph;
    set<Node*> visited;
    bool connected(Node* begin, Node* end, int depth);
public:
    DFS(const Graph& argraph):graph(argraph){};
    bool connected(Node* begin, Node* end);
};
