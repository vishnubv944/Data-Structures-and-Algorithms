// You are given an integer N and asked to find the Xor of first N natural numbers.
// Input Format:
// The first line of input will contain T(number of test cases), each test case follows as.
// The only line of input contains an integer N.
// Output Format:
// For each test case print the Xor of first N natural number in a new line.
// Constraints:
// 1 <= T <= 10^5
// 1 <= N <= 10^9
// Sample Input:
// 1 
// 8
// Sample Output:
// 8

#include<bits/stdc++.h>
using namespace std;
int main(){
	int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        if(n % 4 == 0){
            cout<<n<<endl;
        }
        else if(n % 4 == 1){
            cout<<1<<endl;
        }
        else if(n % 4 == 2){
            cout<<n+1<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
}