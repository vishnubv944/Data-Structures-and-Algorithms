// You are given a positive integer ‘N’. Your task is to print all prime numbers less than or equal to N.
// Note: A prime number is a natural number that is divisible only by 1 and itself. Example - 2, 3, 17, etc.
// You can assume that the value of N will always be greater than 1. So, the answer will always exist.
// Input Format:
// The input contains a single positive integer ‘N’.


// Output Format :
// Print single space-separated prime numbers less than or equal to ‘N’ in increasing order.

// Note :
// You do not need to print anything; it has already been taken care of. Just implement the function.
// Constraints:
// 2 <= N <= 10^7

// Where ‘N’ is the given positive integer.

// Time Limit: 1sec
// Sample Input 1 :
// 7
// Sample Output 1 :
// 2 3 5 7
// Sample Output 1 Explanation:
// For the given input, all prime numbers from 2 to 7 are 2, 3, 5 and 7.
// Sample Input 2 :
// 30
// Sample Output 2 :
// 2 3 5 7 11 13 17 19 23 29

#include<bits/stdc++.h>
vector<int> primeNumbersTillN(int n) 
{ 
    bool arr[n + 1];
    memset(arr, 1, sizeof(arr));
    arr[0] = false;
    arr[1] = false;
    for (int i = 2; i * i <= n; i++) {
      if (arr[i] == true) {
        for (int j =i*i; j <= n; j = j + i) {
          if (j % i == 0) {
            arr[j] = false;
          }
        }
      }
    }
        vector<int> ans;
    for(int i = 0; i <= n; i++){
        if(arr[i] == true){
            ans.push_back(i);
        }
    }
	return ans;
}














