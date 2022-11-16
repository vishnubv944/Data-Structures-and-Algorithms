// A number is called super-prime if it has exactly two distinct prime divisors
// Example 10 , 6
// You are supposed to find the count of super-prime numbers between 1 and N (inclusive).
// Input Format:
// Contain an integer N
// Output Format:
// Print the number of super prime between [1, N]
// Constraints:
// 1 <= N <= 10^6
// Sample Input 1:
// 10
// Sample Output 1:
// 2
// Sample Input 2:
// 25
// Sample Output 2:
// 10
// Explanation:
// The super-primes are: 6, 10, 12, 14, 15, 18, 20, 21, 22, 24.

#include<bits/stdc++.h>

using namespace std;

bool isPrime[1000000];

void makeSieve(){
    int n = 1000000;
    for(int i=0;i<=n;i++){
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i=2;i*i<=n;i++){
        if(isPrime[i] == true){
            for(int j=i*i;j<=n;j+=i){
                isPrime[j] = false;
            }
        }
    }
}

int primeFactors(int n) 
{ 
    set<int> s;
    while (n%2 == 0) 
    { 

        s.insert(2);
        n = n/2; 
    } 
     

    for (int i = 3; i <= sqrt(n); i = i+2) 
    { 

        while (n%i == 0) 
        { 

            s.insert(i);
            n = n/i; 
        } 
    } 
     

    if (n > 2){
        s.insert(n);
    } 
        
    return s.size();
} 


int main(){
    int n;
    cin>>n;
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(primeFactors(i) == 2){
            count++;
        }
    }
    cout<<count<<endl;

}
