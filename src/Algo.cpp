#include "Algo.hpp"


void merge(int* left, int* right, int l_left, int l_right, int* a){
    int i = 0;
    int j = 0;
    int k = 0;

    while(i < l_left && j < l_right){
        if(left[i] < right[j]){
            a[k++] = left[i++];
        }
        else{
            a[k++] = right[j++];
        }
    }

    while(i < l_left){
        a[k++] = left[i++];
    }
    while(j < l_right){
        a[k++] = right[j++];
    }
}

void merge_sort(int *main, int size){
    if(size == 1){
        return;
    }
    int mid = size/2;
    int* left = new int[mid];
    int* right = new int[size-mid];

    for(int i=0;i<mid;i++){
        left[i] = main[i];
    }
    for(int i=mid;i<size;i++){
        right[i-mid] = main[i];
    }


    merge_sort(left,mid);
    merge_sort(right,size-mid);

    merge(left,right,mid,size-mid,main);

}

int partition(int* a, int p, int r){
    int x = a[r];
    int i = p - 1;
    int temp;
    for(int j=p;j<=r -1;j++){
        if(a[j] <= x){
            i = i+1;
            temp = *(a + i);
            *(a + i) = *(a + j);
            *(a + j) = temp; 
        }
    }
    temp = *(a + i + 1);
    *(a + i + 1) = *(a + r);
    *(a + r) = temp;
    return i + 1;
}

void quick_sort(int* a, int p, int r){
    if(p < r){
        int q = partition(a,p,r);
        quick_sort(a,p,q-1);
        quick_sort(a,q+1,r);
    }
}



