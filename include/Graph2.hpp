#ifndef GRAPH2_HPP
#define GRAPH2_HPP

#include <vector>
#include <iostream>
#include <list>
#include <stack>


namespace data_structure{
    class Graph2{
        std::vector<std::list<int> > adj_list;
        int V;
        void topological_sort_util(int v, bool visited[], std::stack<int> &stack);
        public:
            Graph2(int v);
            void addEdge(int src, int dest, bool is_directed);
            void print_graph();
            void topological_sort(bool reverse = false);
            bool detect_cycle();
                
    };
}

#endif