#include <bits/stdc++.h>
using namespace std;

/*
Time complexity: O(n^2)
Space complexity: O(1)
*/
void Bubble_sort(vector<int>&v){
    bool swapped = false;
    for(int i=0;i<v.size();i++){
        swapped = false;
        for(int j=0;j<v.size()-i;j++){
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
                swapped = true;
            }
        }
        // it's sorted
        if(!swapped)
            break;
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
    Bubble_sort(v);
    cout << "\nThe vector after sorting\n";
    for(int i=0;i<n;i++){
        cout << v[i] << ' ';
    }
    return 0;
}