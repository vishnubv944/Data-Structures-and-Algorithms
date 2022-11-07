// You are given an arbitrary array ‘arr’ consisting of N non-negative integers, where every element appears thrice except one. You need to find the element that appears only once.
// Input Format:
// The first line of the input contains a single integer T, representing the number of test cases. 

// The first line of each test case consists of a single integer N, representing the number of elements in the given array.

// The second line of each test case contains N space-separated integers, denoting the elements of the array.
// Output Format:
// For each test case, print a single integer representing the element that appears only once in the array.
// Note:
// You do not need to print anything. It has already been taken care of. Just implement the given function. 
// Constraints:
// 1 <= T <= 100
// 4 <= N <= 10^4
// 0 <= arr[i] < 10^9
// Time Limit: 1sec
// Follow Up:
// Try to solve this problem in O(N) time and O(1) space complexity.
// Sample Input 1:
// 1
// 4
// 1 2 1 1
// Sample Output 1:
// 2
// Explanation For Sample Input 1:
// Clearly, the 2 appears once while 1 appears thrice. Hence, 2 is the output.
// Sample Input 2:
// 1
// 7 
// 1 3 3 3 1 1 4
// Sample Output 2:
// 4
int elementThatAppearsOnce(vector<int> arr) {
    int n = arr.size();
	vector<int> f(32, 0);
    for(int i = 0; i < 32; i++){
        for(int j = 0; j < n; j++){
            if(arr[j] & (1 << i)){
                f[i]++;
            }
        }
    }
    int res = 0;
    for(int i = 0; i < 32; i++){
        if(f[i] % 3 != 0){
            res = res + (1 << i);
        }
    }
    return res;
}