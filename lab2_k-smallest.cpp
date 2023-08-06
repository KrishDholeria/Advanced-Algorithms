#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int p, int q){
    int z = p-1;
    int pivot = arr[q];
    for(int j = p; j < q; j++){
        if(arr[j]<pivot){
            z++;
            swap(arr[z],arr[j]);
        }
    }
    swap(arr[z+1],arr[q]);
    return z+1;
}

int randomize_partition(int arr[],int p, int q){
    int t = p + rand()%(q-p+1);
    swap(arr[t],arr[q]);
    return(partition(arr,p,q));
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int find(int arr[], int p, int r, int k){
    if(k > 0 && k <= r - p + 1){
        int q = randomize_partition(arr,p,r);
        if(k-1 == q-p){
            return arr[q];
        }
        if(k-1 < q-p){
            return find(arr,p,q-1,k);
        }
        return find(arr,q+1,r,k+p-q-1);
    }
    return INT_MAX;
}
 int main(){
    srand(time(NULL));
    int arr[20] = {10,40,30,50,70,20,90,80,100,60,110,150,120,160,130,170,140,180,200,190};
    cout<<find(arr,0,19,11);
    return 0;
 }