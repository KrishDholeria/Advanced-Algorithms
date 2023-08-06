#include <bits/stdc++.h>
using namespace std;
int count1 = 0;

int partition(int arr[], int p, int q){
    int z = p-1;
    int pivot = arr[q];
    for(int j = p; j < q; j++){
        if(arr[j]<pivot){
            z++;
            swap(arr[z],arr[j]);
        }
    }
    count1 = count1 + (q-p);
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

void randomize_quickSort(int arr[], int p, int q){
    
    if(p < q){
        int mid = randomize_partition(arr,p,q);
        randomize_quickSort(arr,p,mid-1);
        randomize_quickSort(arr,mid+1,q);
    }
}

int main()
{
    srand(time(NULL));
    int arr[1000];
    for(int i = 0; i < 1000; i++){
        arr[i] = 1000-i;
    }
    
    randomize_quickSort(arr,0,999);
    
    cout<<"no of comparision"<<count1<<" ";

    return 0;
}


