#pragma once
#include "node.h"

class ReadGraphs{
public:
    static bool load(const string& filename, Graph& graph, map<int, Node*>& nodeMap);
    static void cleanup(Graph& graph, map<int, Node*>& nodeMap);
};