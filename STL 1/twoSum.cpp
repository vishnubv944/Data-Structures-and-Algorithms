// You are given an array of integers 'ARR' of length 'N' and an integer Target. Your task is to return all pairs of elements such that they add up to Target.
// Note:
// We cannot use the element at a given index twice.
// Follow Up:
// Try to do this problem in O(N) time complexity. 

// Input Format:
// The first line of input contains an integer ‘T’ denoting the number of test cases to run. Then the test case follows.

// The first line of each test case contains two single space-separated integers ‘N’ and ‘Target’ denoting the number of elements in an array and the Target, respectively.

// The second line of each test case contains ‘N’ single space-separated integers, denoting the elements of the array.
// Output Format :
// For each test case, print a single line containing space-separated integers denoting all pairs of elements such that they add up to the target. A pair (a, b) and (b, a) is the same, so you can print it in any order.

// Each pair must be printed in a new line. If no valid pair exists, print a pair of (-1, -1). Refer to sample input/output for more clarity.
// Note:
// You do not need to print anything; it has already been taken care of. Just implement the given function.
// Constraints:
// 1 <= T <= 100
// 1 <= N <= 5000
// -10 ^ 9 <= TARGET <=10 ^ 9
// -10 ^ 9 <= ARR[i] <=10 ^ 9

// Where 'T' denotes the number of test cases, 'N' represents the size of the array, 'TARGET' represents the sum required, and 'ARR[i]' represents array elements.

// Time Limit: 1 sec.


// Sample Input 1 :
// 2
// 4 9
// 2 7 11 13
// 5 1
// 1 -1 -1 2 2
// Sample Output 1:
// 2 7
// -1 2
// -1 2
// Explanation for Sample 1:
// For the first test case, we can see that the sum of  2 and 7 is equal to 9 and it is the only valid pair.

// For the second test case, there are two valid pairs (-1,2) and (-1,2), which add up to 1.
// Sample Input 2 :
// 1
// 4 16
// 2 7 11 13
// Sample Output 2 :
// -1 -1

vector<pair<int,int>> twoSum(vector<int>& arr, int target, int n)
{
	vector<pair<int, int>> ans;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        v[i] = arr[i];
        //cout<<mp[i]<<endl;
    }
    sort(v.begin(), v.end());
    int si = 0, ei = n-1;
    while(si < ei){
        if((v[si] + v[ei]) == target){
            ans.push_back(make_pair(v[si], v[ei]));
            si++;
            ei--;
        }
        else if((v[si] + v[ei]) > target){
            ei--;
        }
        else{
            si++;
        }
    }
    if(ans.size() == 0){
        ans.push_back(make_pair(-1, -1));
    }
    return ans;
}
