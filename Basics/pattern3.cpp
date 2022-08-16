// Print the following pattern
// Pattern for N = 4



// The dots represent spaces.



// Input Format :
// N (Total no. of rows)
// Output Format :
// Pattern in N lines
// Constraints :
// 0 <= N <= 50
// Sample Input 1 :
// 3
// Sample Output 1 :
//    *
//   *** 
//  *****
// Sample Input 2 :
// 4
// Sample Output 2 :
//     *
//    *** 
//   *****
//  *******

#include<iostream>
using namespace std;


int main(){
	int n, k = -1, sp = 0, temp = 0;
    cin>>n;
    for(int i = 1; i <= n; i++){
        sp = n-i;
        while(sp--){
            cout<<" ";
        }
        k = k + 2;
        temp = k;
        while(temp--){
            cout<<"*";
        }
        cout<<endl;
    }
}


