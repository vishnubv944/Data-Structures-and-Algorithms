// Print the following pattern
// Pattern for N = 4


// The dots represent spaces.



// Input Format :
// N (Total no. of rows)
// Output Format :
// Pattern in N lines
// Sample Input :
// 5
// Sample Output :


// The dots represent spaces.

#include <iostream>
using namespace std; 
int main()
{
    int n;
    cin>>n;
    int k = 1;
    for(int i = 1; i <= n; i++){
        k = i;
        for(int j = 1; j <= n; j++){
            if(j > n-i){
                cout<<k;
                k++;
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;

    }
}