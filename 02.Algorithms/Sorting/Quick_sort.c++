#include <bits/stdc++.h>
using namespace std;
/*
Time Complexity-> O(n^2)
Space Complecxity-> O(1)
*/
int partition(vector<int>&arr, int low, int high){
    int pivot = arr[high];
    int i = low-1;
    for(int j=low; j<=high; j++){
        if(arr[j]<=arr[pivot]){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[high]);

    return i + 1;
}
void quick_sort(vector<int>&arr, int low, int high){
    if(low<high){
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi-1);
        quick_sort(arr, pi + 1, high);
    }
}

int main(){
    
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    cout << "The vector before sorting:\n";
    for (int i = 0; i < n; i++){
        cout << v[i] << ' ';
    }
    quick_sort(v, 0, n-1);
    cout << "\nThe vector after sorting:\n";
    for (int i = 0; i < n; i++){
        cout << v[i] << ' ';
    }
    cout << '\n';
    
return 0;
}