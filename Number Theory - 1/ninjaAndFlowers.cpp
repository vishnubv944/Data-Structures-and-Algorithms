// Ninja wants to get N flowers and he will pay i + 1 amount of money for the Ith flower, example (if n=3 he will pay {2,3,4})
// Now he wants to pack these N flowers in boxes of different colours. With one condition if the cost of a flower is a prime divisor of another flower they needed to be of a different colour.
// As we know that ninja is a little money minded he wants to minimize the number of different colours of boxes that he needs.
// Input Format:
// The only line of input will contain an integer N (number of flowers).
// Output Format:
// In first-line print K, the minimum number of different colour boxes that are needed to pack the flowers.
// Next line contains K space-separated integers in sorted order denoting the counts of the different coloured boxes.
// Constraints:
// 1 <= N <= 2*10^5
// Sample Input:
// 4
// Sample Output:
// 2
// 1 3

#include<bits/stdc++.h>

using namespace std;

set<int> s;

void primeFactors(int n) 
{ 
    
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
        
} 


int main(){
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        primeFactors(i+1);
    }
    int c = 0;
    set<int> :: iterator it = s.begin();
    while(it != s.end()){
        if(*it <= n+1){
            c++;
        }
        
        it++;
    }
    if(c == n){
        cout<<1<<endl;
        cout<<c<<endl;
    }
    else{
        int a = max(c, (n-c));
        int b = min(c, (n-c));
        cout<<2<<endl;
        cout<<b<<" "<<a<<endl;   
    }



}
