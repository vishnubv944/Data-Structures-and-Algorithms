// You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. Your task is to group all the array elements with ‘K-th’ bit (rightmost bit is ‘1st’ bit) equal to 0 followed by all the elements with ‘K-th’ bit equal to 1.
// Note 1: The relative order inside both the groups should remain as it was in the input.
// Note 2: You have to return the modified array/list..
// For Example :
// If ‘ARR’ is {1,2,3,4} and ‘K’ = 1, then after modification, ‘ARR’ should be {2,4,1,3} because ‘K-th’ (‘K’ = 1) of {2,4} is 0 and ‘K-th’ bit of {1,3} is 1.
// Input Format :
// The first line contains a single integer T representing the number of test cases.

// The first line of each test case contains two single space-separated integers ‘N’ and ‘K’ representing size of the input ‘ARR’ and the ‘Kth’ bit as discussed above.

// The next line of each test case contains ‘N’ single space-separated integers that represents the elements of the ‘ARR’.    
// Output Format :
// For each test case, return the modified array as discussed above.
// Note:
// You don’t need to print anything, it has already been taken care of. Just implement the given function.
// Follow Up:
// Can you do it in linear time?
// Constraints:
// 1 <= T <= 10
// 1 <= N <= 10^4
// 1 <= ARR[i] <= 10^9
// 1 <= K <= 31

// Time Limit: 1 sec
// Sample Input 1:
// 2
// 4 1
// 4 3 2 1
// 5 2
// 2 5 1 6 7
// Sample Output 1:
// 4 2 3 1
// 5 1 2 6 7
// Explanation For Sample Input 1:
// In example 1, the original ‘ARR’ is {4,3,2,1} and ‘K’ = 1. After modification, the ‘ARR’ should be {4,2,3,1} because {4,2} will come first as their 1st bit is 0 and {3,1} will come after that as their 1st bit is 1.

// In example 2, the original ‘ARR’ is {2,5,1,6,7} and ‘K’ = 2. After modification the ‘ARR’ should be {5,1,2,6,7} because {5,1} will come first as their 2nd bit is 0 and {2,6,7} will come after that as their 2nd bit is 1.
// Sample Input 2:
// 2
// 5 1
// 3 6 2 1 4
// 5 3
// 7 6 2 9 3
// Sample Output 2:
// 6 2 4 3 1
// 2 9 3 7 6
// Explanation For Sample Input 2:
// In example 1, the original ‘ARR’ is {3,6,2,1,4} and ‘K’ = 1. After modification the ‘ARR’ should be {6,2,4,3,1} because {6,2,4} will come first as their 1st bit is 0 and {3,1} will come after that as their 1st bit is 1.

// In example 2, the original ‘ARR’ is {7,6,2,9,3} and ‘K’ = 3. After modification the ‘ARR’ should be {2,9,3,7,6} because {2,9,3} will come first as their 3rd bit is 0 and {7,6} will come after that as their 3rd bit is 1.


vector<int> sortArrayByKBit(int n, int k, vector<int> &arr) {
    vector<int> arr0;
    vector<int> arr1;
    for(int i = 0; i < n; i++){
        if(arr[i] & (1 << (k - 1))){
            arr1.push_back(arr[i]);
        }
        else{
            arr0.push_back(arr[i]);
        }
    }
    vector<int> ans(n);
    int x = arr0.size(), y = arr1.size();
    int i = 0;
	for(i = 0; i < x; i++){
        ans[i] = arr0[i];
    }
    int a = i;
    for(int j = 0; j < y; j++){
        ans[a] = arr1[j]; 
        a++;
    }
    return ans;
	
}