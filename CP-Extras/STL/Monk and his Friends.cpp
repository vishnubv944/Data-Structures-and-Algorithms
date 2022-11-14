/*
Problem Link: https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/monk-and-his-friends/
*/

#include<bits/stdc++.h>

using namespace std;

int main(){
   int t;
   cin>>t;
   while(t--){
    long long n, m;
    cin>>n>>m;
    set<long long> s;
    long long x;
    for(int i = 0; i < n; i++){
        cin>>x;
        s.insert(x);
    }
    set<long long> :: iterator it = s.begin();
    long long prev = 0, newv = 0;
    while(m--){
        prev = s.size();
        cin>>x;
        s.insert(x);
        newv = s.size();
        if(prev == newv){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
            prev = newv;
        }
        
    }
   }
}

