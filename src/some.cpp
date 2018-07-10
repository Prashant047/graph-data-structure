#include <iostream>
#include <string>
#include <math.h>
#include <stack>
// #include "Graph.hpp"
#include "WGraph.hpp"

// #include "Graph2.hpp"

// #include "Algo.hpp"
#include "DisjointSet.hpp"


void printArray(int arr[],int size){
    std::cout << "[";
    for(int i=0;i<size;i++){
        if(i == size-1){
            std::cout << arr[i];
        }
        else{
            std::cout << arr[i] << ",";
        }
    }
    std::cout << "]" << std::endl;
}


int main(int argc, char *argv[]){
    data_structure::WGraph* graph = new data_structure::WGraph(5);
    int edge_map[][3] = {
        {0,1,1},{0,4,7},{4,3,6},{1,4,5},{1,3,3},{1,2,4},{2,3,2}
    };

    for(int i=0;i<sizeof(edge_map)/sizeof(*edge_map);i++){
        graph->addEdge(edge_map[i][0],edge_map[i][1],edge_map[i][2]);
    }
    // graph->showList();
    std::cout << graph->minimum_spanning_tree() << std::endl;
    graph->export_graph_string();

    return 0;
}
