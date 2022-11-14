//https://www.codingninjas.com/codestudio/problems/minimum-k-product_758960

#include<bits/stdc++.h>

int minProduct(vector<int> &arr, int n, int k) {
    long long m = 1000000000 + 7;
    sort(arr.begin(), arr.end());
    long long ans = 1;
    for(int i = 0; i < k; i++){
        ans = ((ans % m) * (arr[i] % m)) % m;
    }
    return (ans);
}