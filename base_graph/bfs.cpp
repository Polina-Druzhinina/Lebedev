#include "bfs.h"

bool BFS::connected(Node* begin, Node* end){
    queue<Node*> nodes;
    set<Node*> visited;
    nodes.push(begin);
    while ((!nodes.empty())){
        Node* next = nodes.front();
        nodes.pop();
        if(end==next) return true;
        visited.insert(next);
        for (node_iterator it = next->nb_begin(); it != next->nb_end(); it++){
            if(visited.find(*it) == visited.end())
                nodes.push(*it);
        }
    }
    return false;
}

set<Node*> BFS::component(Node* begin) {
    queue<Node*> nodes;
    set<Node*> visited;
    nodes.push(begin);

    while (!nodes.empty()) {
        Node* next = nodes.front();
        nodes.pop();

        if (visited.find(next) != visited.end()) continue;
        visited.insert(next);

        for (node_iterator it = next->nb_begin(); it != next->nb_end(); it++) {
            if (visited.find(*it) == visited.end())
                nodes.push(*it);
        }
    }

    return visited;
}
