#ifndef WGRAPH_HPP
#define WGRAPH_HPP

#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <iterator>
#include <limits.h>
#include "json.hpp"
#include <string>
#include <fstream>
#include <array>
#include "Tree.hpp"
#include "DisjointSet.hpp"

namespace data_structure{
    class WGraph{
        private:
            int v;
            std::vector< std::list<std::pair<int,int> > > adjList;
            BST edge_tree;
            ~WGraph();
        public:
            WGraph(int v);
            void addEdge(int src, int dest, int weight);
            void showList();
            void shortest_path(int src, int dest);
            void export_graph_string();
            int minimum_spanning_tree();

    };
}

#endif