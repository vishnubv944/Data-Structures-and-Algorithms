/*
Problem Link: https://www.hackerearth.com/problem/algorithm/monks-birthday-party/
*/

#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        set<string> s;
        string str;
        for(int i = 0; i < n; i++){
            cin>>str;
            s.insert(str);
        }
        set<string> :: iterator it = s.begin();
        while(it != s.end()){
            cout<<*it<<endl;
            it++;
        }
    }

}