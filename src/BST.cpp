#include "Tree.hpp"

void data_structure::BST::add_node_util(std::array<int, 3> edge, edge_node* node){
    if(node->weight == edge[2]){
        std::array<int, 2> temp_edge = {edge[0], edge[1]};
        node->edges.push_back(temp_edge);
    }
    else if(edge[2] < node->weight){
        if(node->left == NULL){
            edge_node* new_node = new edge_node;
            std::array<int, 2> temp_edge = {edge[0], edge[1]};
            new_node->weight = edge[2];
            new_node->edges.push_back(temp_edge);
            node->left = new_node;
        }
        else{
            this->add_node_util(edge, node->left);
        }
    }
    else{
        if(node->right == NULL){
            edge_node* new_node = new edge_node;
            std::array<int, 2> temp_edge = {edge[0], edge[1]};
            new_node->weight = edge[2];
            new_node->edges.push_back(temp_edge); 
            node->right = new_node;
        }
        else{
            this->add_node_util(edge, node->right);
        }
    }
}

void data_structure::BST::add_node(std::array<int, 3> edge){
    if(root_node == NULL){
        edge_node* new_node = new edge_node;
        std::array<int, 2> temp_edge = {edge[0], edge[1]};
        new_node->weight = edge[2];
        new_node->edges.push_back(temp_edge);
        root_node = new_node;
        return;
    }

    this->add_node_util(edge, root_node);
}

void data_structure::BST::traverse_tree_util(edge_node* edge, std::vector<std::array<int,3> > &edges_storage){
    if(edge->left != NULL){
        this->traverse_tree_util(edge->left, edges_storage);
    }
    for(int i=0;i<edge->edges.size();i++){
        
        std::array<int,3> temp_edge;
        int src = edge->edges[i][0];
        int dest = edge->edges[i][1];
        int weight = edge->weight;
        temp_edge = {src, dest, weight};
        edges_storage.push_back(temp_edge);
    }
    if(edge->right != NULL){
        this->traverse_tree_util(edge->right, edges_storage);
    }
}


void data_structure::BST::traverse_tree(std::vector<std::array<int,3> > &edges_storage){
    if(root_node == NULL){
        std::cout << "tree is empty" << std::endl;
        return;
    }
    this->traverse_tree_util(root_node, edges_storage);
}