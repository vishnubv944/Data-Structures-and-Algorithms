/*
Problem Link: https://codeforces.com/problemset/problem/776/B
*/

#include<bits/stdc++.h>
using namespace std;

bool isPrime[100000];
int setBits = 0;

void preprocessing(){
    int n = 100000;
    for(int i=0;i<=n;i++){
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i=2;i*i<=n;i++){
        if(isPrime[i] == true){
            for(int j=i*i;j<=n;j+=i){
                isPrime[j] = false;
            }
        }
    } 
}




int main(){
    preprocessing();
    int n;
    cin>>n;
    int arr[n+1];
    int f1 = 0, f2 = 0;
    vector<int> v;
    for(int i = 2; i <= n+1; i++){
        if(isPrime[i] == true){
            v.push_back(1);
            f1 = 1;
        }
        else{
            v.push_back(2);
            f2 = 1;
        }
    }
    if(f1 == 1 && f2 == 1){
        cout<<2<<endl;
    }
    else{
        cout<<1<<endl;
    }
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }

}