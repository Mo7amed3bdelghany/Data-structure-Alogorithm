#include <bits/stdc++.h>
using namespace std;
/*
Time complexity: O(n log n)
Space complexity: O(n)
*/

void merge(vector<int> &v, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++){
        L[i] = v[left + i];
    }
    for (int i = 0; i < n2; i++){
        R[i] = v[mid + i + 1];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            v[k] = L[i++];
        }
        else{
            v[k] = R[j++];
        }

        k++;
    }

    while (i < n1){
        v[k++] = L[i++];
    }
    while (j < n2){
        v[k++] = R[j++];
    }
}

void merge_sort(vector<int> &v, int left, int right)
{
    if (left >= right)
        return; // Base case
    int mid = (left + right) / 2;
    merge_sort(v, left, mid);
    merge_sort(v, mid + 1, right);
    merge(v, left, mid, right);
}

int main(){
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    cout << "The vector before sorting:\n";
    for (int i = 0; i < n; i++){
        cout << v[i] << ' ';
    }
    merge_sort(v, 0, n-1);
    cout << "\nThe vector after sorting:\n";
    for (int i = 0; i < n; i++){
        cout << v[i] << ' ';
    }
    cout << '\n';

    return 0;
}