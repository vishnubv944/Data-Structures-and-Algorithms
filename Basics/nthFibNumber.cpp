// Nth term of Fibonacci series F(n), where F(n) is a function, is calculated using the following formula -
//     F(n) = F(n-1) + F(n-2), 
//     Where, F(1) =  0, 
//            F(2) = 1
// Provided N you have to find out the Nth Fibonacci Number.
// Input Format :
// The first line of each test case contains a real number ‘N’.
// Output Format :
// For each test case, return its equivalent Fibonacci number.
// Constraints:
// 1 <= N <= 10000     
// Where ‘N’ represents the number for which we have to find its equivalent Fibonacci number.

// Time Limit: 1 second
// Sample Input 1:
// 6
// Sample Output 1:
// 8
// Explanation of Sample Input 1:
// Now the number is ‘6’ so we have to find the “6th” Fibonacci number
// So by using the property of the Fibonacci series i.e 

// [ 1, 1, 2, 3, 5, 8]
// So the “6th” element is “8” hence we get the output.

#include<bits/stdc++.h>
using namespace std;

int fib(int n){
	if(n == 1){
        return 0;
    }
    else if(n == 2){
        return 1;
    }
    return fib(n-1) + fib(n-2);
}


int main()
{
	int n;
    cin>>n;
    int ans = fib(n+1);
    cout<<ans<<endl;
}