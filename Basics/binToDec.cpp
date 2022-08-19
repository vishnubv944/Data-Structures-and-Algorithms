// Given a binary number as an integer N, convert it into decimal and print.
// Input format :
// An integer N in the Binary Format
// Output format :
// Corresponding Decimal number (as integer)
// Constraints :
// 0 <= N <= 10^9
// Sample Input 1 :
// 1100
// Sample Output 1 :
// 12
// Sample Input 2 :
// 111
// Sample Output 2 :
// 7

#include<bits/stdc++.h>
using namespace std;

int main() {
	int b = 0;
    cin>>b;
    int d = 0, num = 0, i = 0;
    
    while(b > 0){
        d = b % 10;
        num = num + (d * pow(2, i));
        i++;
        b = b / 10;
    }
    cout<<num<<endl;
}
