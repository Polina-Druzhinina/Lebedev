#pragma once
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
using namespace std;
class Node;
class Graph{
    set<Node*> nodes;
    map<string, Node*> nodeByName;
    bool owner;
    Node* getOrCreateNode(const string& name);
public:
    Graph(): owner(false) {}
    Graph(const char* fileName);
    ~Graph();
    void addNode(Node* node);
    void removeNode(Node* node);
    void addEdge(Node* begin, Node* end, int weight);
    void addEdge(const string& begin, const string& end);
    void removeEdge(Node* begin, Node* end);
    Node* getNode(const string& name) const;
    set<Node*>::const_iterator begin() const{
        return nodes.begin();
    }
    set<Node*>::const_iterator end() const {
        return nodes.end();
    }
};

class Node{
    string name;
    map<Node*, int> neighbours;
    void addNeighbour(Node* neighbour, int weight);
    void removeNeighbour(Node* neighbour);
public:
    class node_iterator{
        map<Node*, int>::const_iterator it;
    public:
        node_iterator(map<Node*, int>::const_iterator ait): it(ait) {};
        node_iterator& operator++() {
            ++it;
            return *this;
        }
        node_iterator operator++(int) {
            node_iterator old = *this;
            ++it;
            return old;
        }
        bool operator!=(const node_iterator& other) const {
            return it != other.it;
        }
        Node* operator*() const {
            return it->first;
        }
    };
    Node(const string& aname): name(aname) {};
    const string& getName() const {
        return name;
    }
    int getWeight(Node* node) const;
    typedef map<Node*, int>::const_iterator weight_nb_iterator;
    node_iterator nb_begin() const { return node_iterator(neighbours.begin()); };
    node_iterator nb_end()   const { return node_iterator(neighbours.end()); };
    weight_nb_iterator weight_nb_begin() const { return neighbours.begin(); };
    weight_nb_iterator weight_nb_end()   const { return neighbours.end(); };
    friend class Graph;
};

typedef Node::node_iterator node_iterator;
