// You have given two positive integers N and K. Your task is to print a series of numbers i.e subtract K from N until it becomes 0 or negative then add K until it becomes N. You need to do this task without using any loop.
// For Example:
// For  N = 5 , K = 2 
// Series = [ 5, 3, 1, -1, 1, 3, 5]
// Input format :
// The first line of input contains a single integer T, representing the number of test cases or queries to be run 

// The first line of each test contains two space-separated integers N and K. 
// Output format :
// For each test case, print a single line containing the required series.
// Note:
// You do not need to print anything, it has already been taken care of. Just implement the given function.
// Constraints :
// 1 <= T <= 100   
// 1 <= N <= 3000 
// 1 <= K <= N 

// Time Limit: 1sec
// Sample Input 1 :
// 2 
// 3 2
// 5 4
// Sample Output 1 :
// 3 1 -1 1 3
// 5 1 -3 1 5
// Explanation For Sample 1:
// For the 1st test case:
// The numbers in the sequence are 3, 3 - 2, 3 - 2 - 2, 3 - 2 - 2 + 2, 3 - 2 - 2 + 2 + 2, which is the same as 3, 1, -1, 1, 3. 

// For the 2nd test case:
// The numbers in the sequence are 5, 5 - 4, 5 - 4 - 4, 5 - 4 - 4 + 4, 5 - 4 - 4 + 4 + 4, which is the same as 5, 1, -3, 1, 5. 
// Sample Input 2 :
// 1
// 4 2
// Sample Output 2 :
// 4 2 0 2 4

vector<int> ans1;
vector<int> ans2;

void rec(int n, int k){
    if(n <= 0){
        ans1.push_back(n);
        return;
    }
    ans1.push_back(n);
    rec(n-k, k);
}

void rec2(int x, int n, int k){
    if(x == n){
        ans2.push_back(x);
        return;
    }
    ans2.push_back(x);
    rec2(x + k, n, k);
}
vector<int> printSeries(int n, int k)
{
    rec(n, k);
    int x = ans1.size();
    rec2(ans1[x-1], n, k);
    vector<int> ans;
    int m = ans1.size();
    for(int i = 0; i < m; i++){
        ans.push_back(ans1[i]);
    }
    m = ans2.size();
    for(int i = 1; i < m; i++){
        ans.push_back(ans2[i]);
    }
    ans1.clear();
    ans2.clear();
    return ans;
}