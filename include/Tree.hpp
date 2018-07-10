#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
#include <vector>
#include <array>


struct edge_node{
    edge_node* left = NULL;
    edge_node* right = NULL;
    int weight;
    std::vector<std::array<int,2> > edges;
};

namespace data_structure{
    class BST{
            edge_node* root_node = NULL;
            void add_node_util(std::array<int, 3> edge,edge_node* node);
            void traverse_tree_util(edge_node* edge, std::vector<std::array<int,3> > &edges_storage);
        public:
            void add_node(std::array<int, 3> edge);
            void traverse_tree(std::vector<std::array<int,3> > &edges_storage);
    };
}

#endif



