#include <iostream>
#include <bits/stdc++.h>
#include <numeric>
#define ll long long
using namespace std;
 
 
void precal(){
}
 
void solve(){
    int n,k;
    cin>>n>>k;
    int maxi=0;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    
    if(k>n || k<=0){
        cout<<"invalid input!"<<"\n";
        return;
    }
    
    int curr_total=0;
    for(int i=0;i<n;i++){
        if(i<k) curr_total+=a[i];
        if(i==k-1) maxi=max(maxi,curr_total);
        else if(i>=k){
            curr_total+=a[i];
            curr_total-=a[i-k];
            maxi=max(maxi,curr_total);
        }
    }
    cout<<maxi<<"\n";
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