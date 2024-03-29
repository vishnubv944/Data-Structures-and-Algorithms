// Given an integer array 'ARR' of size 'N' and an integer 'K', return all the subsets of 'ARR' which sum to 'K'.
// Subset of an array 'ARR' is a tuple that can be obtained from 'ARR' by removing some (possibly all) elements of 'ARR'.
// Note :
// The order of subsets is not important. 

// The order of elements in a particular subset should be in increasing order of the index.
// Input Format
// The first line of input contains an integer 'N', which denotes the size of the array.

// The second line contains 'N' single-space separated integers representing the elements of the array.

// The third line contains a single integer 'K', which denotes the integer to which the subsets should sum to.
// Output Format:
// For each test case, print single-space separated integers of a subset of 'ARR' having sum = 'K'. 

// The output of each test case will be printed in a separate line.
// Note:
// You do not need to print anything, it has already been taken care of. Just implement the given function.
// Constraints:
// 1 <= 'N' <= 16
// - (10 ^ 6) <= ARR[i] <= (10 ^ 6)
// - 16 * (10 ^ 6) <= 'K' <= 16 * (10 ^ 6)

// Where ‘ARR[i]’ denotes the value for ‘ith’ element of the array ‘ARR’ and 'K' is the given sum.

// Time Limit: 1 sec.
// Sample Input 1:
// 3
// 2 4 6
// 6
// Sample Output 1:
// 2 4
// 6
// Explanation of the Sample Input 1:
// For the array'ARR' = {2, 4, 6}, we can have subsets {}, {2}, {4}, {6}, {2, 4}, {2, 6}, {4, 6}, {2, 4, 6}. Out of these 8 subsets, {2, 4} and {6} sum to the given 'K' i.e. 6. 
// Sample Input 2:
// 6 
// 5 -1 8 2 7 0
// 7
// Sample Output 2:
// -1 8 
// -1 8 0 
// 5 2 
// 5 2 0 
// 7 
// 7 0 

vector<vector<int>> sol;

void rec(vector<int> arr, int n, int i, int k, vector<int> ans, int sum){
    if(i == n){
        if(sum == k){
            sol.push_back(ans);
        }
        return;
    }
    rec(arr, n, i+1, k, ans, sum);
    ans.push_back(arr[i]);
    sum = sum + arr[i];
    rec(arr, n, i+1, k, ans, sum);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<int> ans;
    rec(arr, n, 0, k, ans, 0);
    return sol;
}