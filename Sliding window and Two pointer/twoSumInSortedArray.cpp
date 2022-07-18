#include <iostream>
#include <bits/stdc++.h>
#include <numeric>
#define ll long long
using namespace std;
 
 
void precal(){
}
 
void solve(){
    int n,target;
    cin>>n>>target;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    
    int start=0,end=n-1;
    while(start<end){
        if(a[start]+a[end]>target) end--;
        else if(a[start]+a[end]<target) start++;
        else{
            cout<<start<<" "<<end<<"\n";
            return;
        }
    }
    cout<<-1<<" "<<-1<<"\n";
}   
 
int main(){
    ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            cout<<fixed;
            cout<<setprecision(10);
    //        freopen("timber_input.txt", "r", stdin);
    //        freopen("timber_output.txt", "w", stdout);
            precal();
            int t=1;
            // cin>>t;
            for(int i=1;i<=t;i++){
            //    cout<<"Case #"<<i<<": ";  
                solve();
    }
    return 0;
}