#include "Graph2.hpp"

data_structure::Graph2::Graph2(int v){
    this->V = v;
    std::list<int> temp;
    for(int i=0;i<this->V;i++){
        this->adj_list.push_back(temp);
    }
}

void data_structure::Graph2::addEdge(int src,int dest, bool is_directed){
    if(src < this->V && dest < this->V){
        if(is_directed){
            this->adj_list[src].push_back(dest);
            return;
        }
        this->adj_list[src].push_back(dest);
        this->adj_list[dest].push_back(src);
    }
}


void data_structure::Graph2::print_graph(){
    for(int i=0;i<this->V;i++){
        std::cout << "|" << i << "|";
        for(auto it=adj_list[i].begin();it != adj_list[i].end();++it){
            std::cout << "--" << *it ;
        }
        std::cout << std::endl;
    }
}

void data_structure::Graph2::topological_sort_util(int v, bool visited[], std::stack<int> &stack){
    visited[v] = true;
    for(auto it=adj_list[v].begin();it!=adj_list[v].end();++it){
        if(!visited[*it]){
            this->topological_sort_util(*it,visited,stack);
        }
    }
    stack.push(v);
}

// void topological_sort_util(int v, bool visited, std::stack<int>* stack){
//     visited[i] = true;
//     for(auto it=)
// }


void data_structure::Graph2::topological_sort(bool reverse){
    std::stack<int> stack;
    bool visited[this->V];
    for(int i=0;i<this->V;i++){
        visited[i] = false;
    }

    for(int i=0;i<this->V;i++){
        if(!visited[i]){
            this->topological_sort_util(i, visited,stack);
        }
    }
    if(reverse){
        std::stack<int> rev_stack;
        while(!stack.empty()){
            rev_stack.push(stack.top());
            stack.pop();
        }
        while(!rev_stack.empty()){
            std::cout << rev_stack.top() << "->";
            rev_stack.pop(); 
        }
        std::cout << std::endl;
        return;
    }

    while(!stack.empty()){
        std::cout << stack.top() << "->";
        stack.pop(); 
    }
    std::cout << std::endl;
}


bool data_structure::Graph2::detect_cycle(){
    std::stack<int> dfs_stack;
    int selected;
    bool has_neighbour;

    for(int i=0;i<this->V;i++){
        
        bool visited[this->V];
        for(int m=0;m<this->V;m++){
            visited[m] = false;
        }

        dfs_stack.push(i);
        while(!dfs_stack.empty()){
            selected = dfs_stack.top();
            has_neighbour = false;
            visited[selected] = true;
            for(auto it=adj_list[selected].begin();it!=adj_list[selected].end();++it){
                if(*it == i){
                    return true;
                }
                if(!visited[*it]){
                    dfs_stack.push(*it);
                    has_neighbour = true;
                    break;
                }                
            }
            if(!has_neighbour){
                dfs_stack.pop();
            }
        }

    }

    return false;

}