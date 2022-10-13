// You are given an array/list ARR of N distinct positive integers. You are also given a non-negative integer B.
// Your task is to find all unique combinations in the array whose sum is equal to B. A number can be chosen any number of times from array/list ARR.
// Elements in each combination must be in non-decreasing order.
// For example:
// Let the array ARR be [1, 2, 3] and B = 5. Then all possible valid combinations are-

// (1, 1, 1, 1, 1)
// (1, 1, 1, 2)
// (1, 1, 3)
// (1, 2, 2)
// (2, 3)
// Input Format
// The first line of input contains an integer ‘T’ denoting the number of test cases to run. Then the test case follows.

// Then the first line of each test case contains two space separated integers  ‘N’ and ‘B’ denoting the number of elements in the array/list and the target sum respectively.

// The second line of each test case contains N space separated integers the elements of array/list ARR.
// Output Format :
// For each test case, print all possible valid combinations in separate lines. You can print combinations in any order. Elements in each combination must be in non-decreasing order.

// Output for each test case will be printed in a new line. 
// Note:
// You do not need to print anything; it has already been taken care of. Just implement the given function.
// Constraints:
// 1 <= T <= 5
// 1 <= N <= 15
// 1 <= B <= 20
// 1 <= ARR[i] <= 20

// Time Limit: 1sec
// Sample Input 1 :
// 2
// 3 8
// 2 3 5
// 1 2
// 1
// Sample Output 1:
// 2 2 2 2
// 2 3 3 
// 3 5
// 1 1
// Sample Input 2 :
// 1
// 3 5
// 1 2 3 
// Sample Output 2:
// 1 1 1 1 1
// 1 1 1 2 
// 1 1 3
// 1 2 2
// 2 3

#include<bits/stdc++.h>
//vector<vector<int>> sol;
set<vector<int>> st;
void recfun(vector<int> arr, int b, int i, vector<int> ans, int n){
    if(b == 0){
        //sol.push_back(ans);
        st.insert(ans);
        return;
    }
    if(i >= n || b - arr[i] < 0){
        return;
    }
    ans.push_back(arr[i]);
    
    
    recfun(arr, b - arr[i], i, ans, n);

	ans.pop_back();
    
    recfun(arr, b, i+1, ans, n);
}

vector<vector<int>> combSum(vector<int>& ARR, int B)
{
    vector<int> ans;
    sort(ARR.begin(), ARR.end());
    int n = ARR.size();
	recfun(ARR, B, 0, ans, n);
    vector<vector<int>> sol;
    for(auto it = st.begin(); it != st.end(); it++){
        sol.push_back(*it);
    }
    st.clear();
    return sol;
}
