#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <list>
#include <iterator>
#include <vector>

namespace data_struct{
    
    class Graph{
        private:
            int v;
            std::vector <std::list <int> > adjList;
        public:
            Graph(int vert);
            void addEdge(int src, int dest);
            void showList();
            void breadth_first_search(int src);
    };

}


#endif