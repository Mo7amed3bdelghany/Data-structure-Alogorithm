#include <bits/stdc++.h>
using namespace std;

/*
Time complexity: O(n^2)
Space complexity: O(1)
*/
void Insertion_sort(vector<int>&v){
    for(int i=1;i<v.size();i++){
        int j = i - 1, key = v[i];
        while(j>=0 && v[j]>key){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
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
    Insertion_sort(v);
    cout << "The vector after sorting\n";
    for(int i=0;i<n;i++){
        cout << v[i] << ' ';
    }
    return 0;
}