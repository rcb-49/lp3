#include<bits/stdc++.h>
using namespace std;

// 10, 7, 8, 9, 1, 5
// 


int deterministicPartition(vector<int>& arr,int low,int high){
    int pivot = arr[low];
    int i = low ;
    int j = high;
    while(i<j){
        while(i<=high && arr[i] <= pivot) i++;
        while(j>=low && arr[j] > pivot) j--;
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[j],arr[low]);
    return j;
}

void deterministicQuickSort(vector<int>& arr,int low,int high,int &comparisons, int &swaps){
    if(low<high){
        int pind = deterministicPartition(arr,low,high);
        comparisons+=high-low;
        swaps+=2;
        deterministicQuickSort(arr,low,pind-1,comparisons,swaps);
        deterministicQuickSort(arr,pind+1,high,comparisons,swaps);
    }
}

int randomizedPartition(vector<int>& arr,int low,int high){
    int pivotIndex = low + rand() % (high-low + 1);
    swap(arr[low],arr[pivotIndex]);
    int pivot = arr[low];
    int i = low ;
    int j = high;
    while(i<j){
        while(i<=high && arr[i] <= pivot) i++;
        while(j>=low && arr[j] > pivot) j--;
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[j],arr[low]);
    return j;
}

void randomizedQuickSort(vector<int>& arr,int low,int high,int &comparisons, int &swaps){
    if(low<high){
        int pind = randomizedPartition(arr,low,high);
        comparisons+=(high-low);
        swaps+=2;
        randomizedQuickSort(arr,low,pind-1,comparisons,swaps);
        randomizedQuickSort(arr,pind+1,high,comparisons,swaps);
    }
}

void print(vector<int>&arr){
    for(auto &it:arr){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main(){
    int dcomp=0 , rcomp = 0, dswaps = 0, rswaps=0;
    vector<int> a = {4,6,2,5,7,9,1,3};
    vector<int> b = a;
    deterministicQuickSort(a,0,a.size()-1,dcomp,dswaps);
    cout << "Sorted array (Deterministic):\n";
    print(a);
    cout << "Deterministic Quick Sort Comparisons: " << dcomp<< endl;
      cout << "Deterministic Quick Sort Swaps: " << dswaps << endl;
    randomizedQuickSort(b,0,b.size()-1,rcomp,rswaps);
     cout << "Sorted array (Randomized):\n";
    print(b);
    cout << "Randomized Quick Sort Comparisons: " << rcomp << endl;
    cout << "Randomized Quick Sort Swaps: " << rswaps << endl;
    return 0;
}