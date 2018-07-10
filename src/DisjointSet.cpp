#include "DisjointSet.hpp"

data_structure::DisjointSet::DisjointSet(int n){
    this->N = n;
    track_arr = new int[this->N];
    size = new int[this->N];

    for(int i=0;i<N;i++){
        track_arr[i] = i;
        size[i] = 1;
    }
}

int data_structure::DisjointSet::root(int x){
    int i = track_arr[x];
    while(i != track_arr[i]){
        i = track_arr[i];
    }
    return i;
}

void data_structure::DisjointSet::_union(int a, int b){
    int root_a = root(a);
    int root_b = root(b);

    if(size[root_a] < size[root_b]){
        track_arr[root_a] = track_arr[root_b];
        size[root_b] = size[root_a];
    }
    else{
        track_arr[root_b] = track_arr[root_a];
        size[root_a] = size[root_b];
    }
}

bool data_structure::DisjointSet::_find(int a, int b){
    if(root(a) == root(b)){
        return true;
    }
    return false;
}

data_structure::DisjointSet::~DisjointSet(){
    delete track_arr;
    delete size;
}