/*
Problem Link: https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/monk-and-the-magical-candy-bags/
*/

#include<bits/stdc++.h>

using namespace std;

int main(){
   int t;
   cin>>t;
   while(t--){
    long long n, k;
    cin>>n>>k;
    map<long long, long long> mp;
    long long x;
    map<long long, long long> :: iterator itr = mp.begin();
    for(int i = 0; i < n; i++){
        cin>>x;
        itr = mp.find(x);
        if(itr == mp.end()){
            mp.insert(make_pair(x, 1));
        }
        else{
            itr -> second = itr -> second + 1;
        }
        
    }
    itr = mp.begin();
    // while(itr != mp.end()){
    //     cout<<itr -> first<<"->"<<itr -> second<<endl;
    //     itr++;
    // }

    long long c = 0, temp = 0;
    map<long long, long long> :: iterator it = mp.end();
    it--;

    while(k--){

        temp = it -> first;
        it -> second = it -> second - 1;
        if(it -> second == 0){
            mp.erase(it -> first);   
        }
        itr = mp.find(temp/2);
        if(itr == mp.end()){
            mp.insert(make_pair(temp/2, 1));
        }
        else{
            itr -> second = itr -> second + 1;
        }
        
        c = c + temp;
        
        // mp.insert(make_pair(temp, 0));
        it = mp.end();
        it--; 
    }

    // cout<<"AFTERR"<<endl;
    // itr = mp.begin();
    // while(itr != mp.end()){
    //     cout<<itr -> first<<"->"<<itr -> second<<endl;
    //     itr++;
    // }
    cout<<c<<endl;
   }
}

