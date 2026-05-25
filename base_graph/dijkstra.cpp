#include "dijkstra.h"
#include <algorithm>

void PriorityQueue::push(Node* node, int mark, Node* previous) {
    nodes.insert(make_pair(mark, MarkedNode(node, mark, previous)));
}

MarkedNode PriorityQueue::pop() {
    multimap<int, MarkedNode>::iterator it = nodes.begin();
    MarkedNode node = it->second;
    nodes.erase(it);
    return node;
}

bool PriorityQueue::empty() const {
    return nodes.empty();
}

Way Dijkstra::shortestWay(Node* begin, Node* end) {
    PriorityQueue nodes;
    nodes.push(begin, 0, 0);
    map<Node*, MarkedNode> visited;

    while (!nodes.empty()) {
        MarkedNode next = nodes.pop();
        if (visited.find(next.node) != visited.end()) continue;
        visited[next.node] = next;
        if (end == next.node) return unroll(visited, begin, end);

        for (node_iterator it = next.node->nb_begin();
             it != next.node->nb_end(); it++) {
            int weight = (*it)->getWeight(next.node) + next.mark;
            if (visited.find(*it) == visited.end())
                nodes.push(*it, weight, next.node);
        }
    }
    return Way();
}

Way Dijkstra::unroll(map<Node*, MarkedNode>& visited, Node* begin, Node* end) {
    Way way;
    way.length = visited[end].mark;

    Node* current = end;
    while (current != 0) {
        way.nodes.push_back(current);
        if (current == begin) break;
        current = visited[current].previous;
    }

    reverse(way.nodes.begin(), way.nodes.end());
    return way;
}
