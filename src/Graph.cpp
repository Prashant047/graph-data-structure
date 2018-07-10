#include "Graph.hpp"

data_struct::Graph::Graph(int v){
    this->v = v;
    for(int i=0;i<v;i++){
        std::list <int> temp;
        adjList.push_back(temp);
    }
}

void data_struct::Graph::addEdge(int src,int dest){
    if(src < v && dest << v){
        adjList.at(src).push_back(dest);
        adjList.at(dest).push_back(src);
    }
    return;
}

void data_struct::Graph::showList(){
    std::list <int>::iterator iter;
    for(int i=0;i<v;i++){
        std::cout << "|" << i << "|";
        for(iter = adjList[i].begin();iter != adjList[i].end();++iter){
            std::cout << "-" << *iter;
        }
        std::cout << std::endl;
    }

}

void data_struct::Graph::breadth_first_search(int src){
    std::list<int> visit;
    int visited[this->v];
    for(int i=0;i<this->v;i++){
        visited[i] = 0;
    }

    bool is_in_visited = false;
    int current;

    std::list<int>::iterator iter;
    std::list<int>::iterator visit_iter;

    visit.push_back(src);
    while(!visit.empty()){
        current = visit.front();
        visited[current] = 1;
        for(iter=adjList[current].begin();iter!=adjList[current].end();++iter){
            if(visited[*iter] != 1){

                for(visit_iter=visit.begin();visit_iter!=visit.end();++visit_iter){
                    if(*visit_iter == *iter){
                        is_in_visited = true;
                    }
                }

                if(!is_in_visited){
                    visit.push_back(*iter);
                }
                is_in_visited = false;
            }
        }
        visit.pop_front();
        std::cout << current << std::endl;
    }


}