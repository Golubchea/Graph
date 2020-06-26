

// A C Program to demonstrate adjacency list
// representation of graphs
#include <stdio.h>
#include <stdlib.h>
#include "algorithms/Graph.h"
#include "visual/visual.h"


int main(int argc, char **argv)
{


    Graph g1(4);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(2, 0);
    g1.addEdge(2, 3);
    g1.addEdge(3, 0);

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g1.BFS(2);
    cout << "Following is Depth First Traversal "
         << "(starting from vertex 2) \n";
    g1.DFS(2);
    Visual vz(&g1);


}


