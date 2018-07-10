#include "WGraph.hpp"

data_structure::WGraph::WGraph(int v){
    this->v = v;
    for(int i=0;i<this->v;i++){
        std::list< std::pair<int,int> > temp;
        this->adjList.push_back(temp);
    }
}

void data_structure::WGraph::addEdge(int src, int dest, int weight){
    if(src < v && dest < v){
        std::pair <int, int> temp;
        temp.first = dest;
        temp.second = weight;
        adjList[src].push_back(temp);

        std::pair<int,int> temp2;
        temp2.first = src;
        temp2.second = weight;
        adjList[dest].push_back(temp2);

        // adding to the edges_tree
        std::array<int, 3> temp_edge = {src, dest, weight};
        this->edge_tree.add_node(temp_edge);

        return;
    }

    std::cout << "src or destination out of range" << std::endl;
}

void data_structure::WGraph::showList(){
    std::list<std::pair <int,int> >::iterator iter;
    for(int i=0;i<v;i++){
        std::cout << "|" << i << "|";
        for(iter=adjList[i].begin();iter!=adjList[i].end();++iter){
            std::cout << "--[" << (*iter).first << "," << (*iter).second << "]";
        }
        std::cout << std::endl;
    }
}

void data_structure::WGraph::export_graph_string(){
    std::ofstream graph_json_out;

    nlohmann::json graph_json_data;
    graph_json_data = this->adjList;
    std::string value = graph_json_data.dump();

    graph_json_out.open("./visualize_graph/graph.json");
    graph_json_out << value;
    graph_json_out.close();
    
}


void data_structure::WGraph::shortest_path(int src, int dest){
    // Implementing Dijkstras Algorithm
    int no_of_visited = 1;
    std::list<std::pair<int,int> >::iterator iter;
    int visited[this->v],selected;
    int distance[this->v];
    int min;

    for(int i=0;i<v;i++){
        visited[i] = 0;
        distance[i] = INT32_MAX;
    }

    distance[src] = 0;
    selected = src;
    while(no_of_visited != this->v){
        // visited[selected] = 1;
        std::cout << selected << std::endl;
        for(iter=adjList[selected].begin();iter!=adjList[selected].end();++iter){
            if(visited[iter->first] != 1){
                std::cout << iter->first << "<-" << std::endl;
                if(distance[selected] + iter->second < distance[iter->first]){
                    distance[iter->first] = distance[selected] + iter->second;
                }
            }
        }
        visited[selected] = 1;
        
        min = INT32_MAX;

        for(int i=0;i<v;i++){
            if(visited[i] != 1 && distance[i] < min){
                selected = i;
                min = distance[i];
            }
        }
        no_of_visited++;
    }
    std::cout << distance[dest] << std::endl;
    // std::cout << no_of_visited << std::endl;
}

int data_structure::WGraph::minimum_spanning_tree(){
    std::vector<std::array<int,3> > edge_storage;
    this->edge_tree.traverse_tree(edge_storage);
    DisjointSet edge_set(this->v);

    int total_cost = 0;
    
    for(int i=0;i<edge_storage.size();i++){
        if(edge_set._find(edge_storage[i][0],edge_storage[i][1])){
            continue;
        }
        total_cost += edge_storage[i][2];
        edge_set._union(edge_storage[i][0], edge_storage[i][1]);
        std::cout << edge_storage[i][0] << "," << edge_storage[i][1] << "," <<edge_storage[i][2] <<std::endl;
    }

    return total_cost;
}


data_structure::WGraph::~WGraph(){

}