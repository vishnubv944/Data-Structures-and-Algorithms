// Given an array, print the Next Greater Element (NGE) for every element. The Next greater Element for an element x, is the first greater element on right side of x in the array. Elements for which no greater element exist, consider next greater element as -1.

// Input format :
// Line 1 : Size of input array
// Line 2 : Array elements (separated by space)
// Constraints:
// Time Limit: 1 second
// Size of input array lies in the range: [1, 1000000]

// Sample Input
// 5
// 3  8  1  2  0
// Sample Output
// 8 -1  2 -1 -1

vector<int> nextGreaterElement(vector<int> input) {
    int n = input.size();
	stack<int> s;
    vector<int> ans(n);
    
    for(int i = n - 1; i >= 0; i--){
        if(s.empty()){
            ans[i] = -1;
            s.push(input[i]);
        }
        else{
            while(!s.empty() && s.top() <= input[i]){
                s.pop();
            }
            if(s.empty()){
                ans[i] = -1;
                s.push(input[i]);
            }
            else{
                ans[i] = s.top();
                s.push(input[i]);
            }
        }
    }
    return ans;

}