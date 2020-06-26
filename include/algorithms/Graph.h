#include<iostream>
#include <list>
#pragma once
using namespace std;

// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V;    // No. of vertices

    // Pointer to an array containing adjacency
    // lists
    list<int> *adj;
    void DFSUtil(int v, bool visited[]);
public:


    Graph(int V);  // Constructor
    ~Graph();
    int size(){return V;};
    list<int>& get_adj(int i){return adj[i];};
    // function to add an edge to graph
    void addEdge(int v, int w);

    // prints BFS traversal from a given source s
    //Depth First Traversal
    void DFS(int v);
    //Breadth First Traversal
    void BFS(int s);
};


