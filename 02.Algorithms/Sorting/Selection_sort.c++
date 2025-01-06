#include <bits/stdc++.h>
using namespace std;

/*
Time complexity: O(n^2)
Space complexity: O(1)
 */
void Selection_sort(vector<int>&v){
    for(int i=0;i<v.size()-1;i++){
        // find the minimum element in unsorted subarray
        int min = i;
        for(int j=i+1;j<v.size();j++){
            if(v[j]<v[min]){
                min = j;
            }
        }
        if(min!=i) {
            swap(v[min], v[i]);
        }
    }
}
int main(){
    int n; cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout << "The vector before sorting\n";
    for(int i=0;i<n;i++){
        cout << v[i] << ' ';
    }
    Selection_sort(v);
    cout << "The vector after sorting\n";
    for(int i=0;i<n;i++){
        cout << v[i] << ' ';
    }
    return 0;
}