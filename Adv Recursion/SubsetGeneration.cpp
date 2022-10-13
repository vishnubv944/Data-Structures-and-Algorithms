// You are given an array ‘arr’ of ‘N’ distinct integers. Your task is to find all the non-empty subsets of the array.
// Note: You can return the subsets in any order, you don’t have to specifically sort them.
 

// Input Format :
// The first line contains a single integer ‘T’ denoting the number of test cases, then each test case follows

// The first line of each test case contains a single integers ‘N’ denoting the length of the array.

// The second line of each test case contains ‘N’ integers denoting the array elements.
// Output Format :
// For each test case print each subset in a separate line.

// Output for each test case will be printed in a separate line.
// Note :
// You are not required to print anything; it has already been taken care of. Just implement the function.
// Constraints :
// 1 <= T <= 10      
// 1 <= N <= 10
// 10^-9 <= arr[i] <= 10^9

// Time limit: 1 sec
// Sample Input 1 :
// 2
// 3
// 1 2 3
// 1
// 10
// Sample Output 1 :
// 1
// 1 2
// 1 2 3
// 1 3
// 2
// 2 3
// 3
// 10
// Explanation Of Sample Output 1 :
// For test case 1 :
// Total 7 possible subsets can be formed: {1}, {1,2}, {1,2,3}, {1,3}, {2}, {2,3}, {3}

// For test case 2 :
// Only a single subset {10} is possible for the given input array.
// Sample Input 2 :
// 2
// 2
// 1 2
// 3
// 1 2 3
// Sample Output 2 :
// 1 
// 1 2 
// 2 
// 1 
// 1 2 
// 1 2 3 
// 1 3 
// 2 
// 2 3 
// 3 

vector<vector<int>> sol;
//int j = 0;

vector<vector<int>> subset(int n, vector<int> &arr, int i, vector<int> temp){
    if(i == n){
        vector<int> t;
        int m = temp.size();
        for(int k = 0; k < m; k++){
            t.push_back(temp[k]);
        }
        sol.push_back(t);
        return sol;
    }
    temp.push_back(arr[i]);
	 subset(n, arr, i+1, temp);
    temp.pop_back();
     subset(n, arr, i+1, temp);
    return sol;
}

vector<vector<int>> FindAllSubsets(int n, vector<int> &arr){
    vector<int> temp;
    vector<vector<int>> solu;
	solu = subset(n, arr, 0, temp);
    sol.clear();
    return solu;
}