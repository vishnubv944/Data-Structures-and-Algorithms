/*
Problem Link: https://codeforces.com/problemset/problem/17/A
*/

#include<bits/stdc++.h>
using namespace std;

bool isPrime[10000];
int setBits = 0;

set<int> s;

void preprocessing(){
    int n = 10000;
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
    for(int i = 1; i <= n; i++){
        if(isPrime[i] == true){
            s.insert(i);
        }
    }
}


bool check(int n){
    n--;
    int temp = 0;
    set<int> :: iterator it = s.begin();
    set<int> :: iterator itPerv;
    while(it != s.end()){
        itPerv = it++;
        if((itPerv != s.end()) && ((*it + *itPerv) == n)){
            return true;
        }
    }
    return false;
}



int main(){
    preprocessing();
    int n, k, c = 0;
    cin>>n>>k;
    for(int i = 1; i <= n; i++){

        if(check(i) && isPrime[i]){
            c++;
        }
    }
    if(c >= k){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

}