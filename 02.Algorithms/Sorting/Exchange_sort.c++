/*
Time complexity: O(n^2)
Space complexity: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

void Exchange_sort(vector<int>&v , int n){
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if(v[i] > v[j]){
                swap(v[i],v[j]);
            }
        }
    }
}


int main(){
    int n; cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout << "The vector before sorting:\n";
    for(int i=0;i<n;i++){
        cout << v[i] << ' ';
    }
    Exchange_sort(v , n);
    cout << "\nThe vector after sorting:\n";
    for(int i=0;i<n;i++){
        cout << v[i] << ' ';
    }
    cout << '\n';
}