///https://www.hackerearth.com/practice/algorithms/sorting/advanced-sorting/practice-problems/algorithm/the-monk-and-class-marks/

#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    int m;
    string s;
    map<int, vector<string>> mp;
    map<int, vector<string>> :: iterator it = mp.begin();
    vector<string> temp; 
    cin>>t;
    for(int i = 0; i < t; i++){
        cin>>s>>m;
        it = mp.find(m);
        if(it == mp.end()){
            temp.push_back(s);
            mp.insert(make_pair(m, temp));
            temp.clear();
        }
        else{

            temp = it->second;
            temp.push_back(s);
            it -> second = temp;
            temp.clear();
        }
    }
    it = mp.begin();
    while(it != mp.end()){
        if(it -> second.size() > 1){
            temp = it -> second;
            sort(temp.begin(), temp.end());
            it -> second = temp;
        }
        it++;
    }
    it = mp.end();
    it--;
    int c = mp.size();
    while(c--){
        if(it -> second.size() > 1){
           for(int i = 0; i < it -> second.size(); i++){
            cout<<it -> second[i]<<" "<<it -> first<<endl;
           } 
        }
        else{
            cout<<it -> second[0]<<" "<<it -> first<<endl;
        }

        it--;
    }
    
}

