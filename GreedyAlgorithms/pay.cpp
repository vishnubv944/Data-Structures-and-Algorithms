// Ninja works in an XYZ MNC which follows a very strict rule regarding the pay. Ninja has been assigned ‘N’ tasks. Each task requires some days to finish, which is given in the form of an array ‘TIME’. For each day of delay before starting to work in task ‘i’ a loss is incurred on Ninjas’ pay which is given in an array ‘LOSS’. Ninja asks you for help to find the order in which the tasks should be completed such that there is a minimum loss in Ninjas’ pay.
// Note:
// If there are multiple solutions, print the order with smaller indices first.
// Example:
// Let ‘TIME’ array be: [2, 4, 1]
// Let ‘LOSS’ array be: [1, 2, 3]
// Order 1 2 3 will cause loss of 4 + 18 = 22
// Order 3 1 2 will cause loss of 1+ 6 = 7 which is the minimum possible loss.
// Hence the answer is [3, 1, 2].
// Input Format :
// The first line of input contains an integer ‘T’, the number of test cases.

// The first line of each test case contains a single integer ‘N’, representing the number of tasks.

// The second line of each test case contains ‘N’ space-separated integers, representing the number of days required to finish the ‘N’ tasks.

// The third line of each test case contains ‘N’ space-separated integers, representing the loss incurred on Ninjas’ pay for each day of delay.
// Output Format :
// For each test case, print the space-separated integers representing the order in which tasks should be completed.

// Print output of each test case in a separate line.
// Note :
// You do not need to print anything. It has already been taken care of. Just implement the given function.
// Constraints :
// 1 <= T <= 10
// 1 <= N <= 10^5
// 1<= TIME[i], LOSS[i] <= 10^7

// Time Limit: 1 sec
// Sample Input 1 :
// 2
// 4
// 4 1000 2 5
// 3 1 2 4
// 3
// 2 4 1
// 1 2 3
// Sample Output 1 :
// 3 4 1 2
// 3 1 2
// Explanation For Sample Input 1 :
// For test case 1: 
// Order 1 2 3 4 will cause a loss of 4 + 2008 + 4024 = 6036
// Order 2 3 1 4 will cause loss of 2000 + 6006 + 4024 = 12030
// Order 3 4 1 2 wil.l cause loss of 8 + 21 + 11 = 40 which is the minimum possible loss.

// For test case 2: 
// Order 1 2 3 will cause loss of 4 + 18 = 22
// Order 3 1 2 will cause loss of 3 + 3 = 6 which is the minimum possible loss.
// Sample Input 2 :
// 1
// 5
// 2 4 1 3 2
// 1 2 3 5 6
// Sample Output 2 :
// 3 5 4 1 2

#include<bits/stdc++.h>

bool cmp(pair<double,int> &a, pair<double,int> &b)
{
    return (a.first < b.first);
}


vector<int> minLoss(int n, vector<int> &time, vector<int> &loss) {
    vector<pair<double, int>> v(n);
    float var = 0.0;
    for(int i = 0; i < n; i++){
        var = (double)time[i] / (double)loss[i];
        v[i].first = var;
        v[i].second = i+1;
    }
    sort(v.begin(), v.end());
    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        ans[i] = v[i].second;
    }
    return ans;
        
}