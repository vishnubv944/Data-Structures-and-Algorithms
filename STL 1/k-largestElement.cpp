// You are given with an integer k and an array of integers that contain numbers in random order. You have to find k largest numbers from given array. You need to save them in an array and return it.
// Note:
// 1. Time complexity should be O(n * logk) and space complexity should not be more than O(k).
// 2. Order of elements in the output is not important.

// Input Format:
// The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
// The following line contains N space separated integers, that denote the value of the elements of the array.
// The following contains an integer, that denotes the value of k.
// Output Format :
// The first and only line of output contains k largest elements.
// Constraints:
// Time Limit: 1 sec

// Sample Input 1:
// 13
// 2 12 9 16 10 5 3 20 25 11 1 8 6 
// 4
// Sample Output 1:
// 12 16 20 25

vector<int> kLargest(int arr[], int n, int k) {
    vector<int> ans;
    priority_queue<int> pq;
    for(int i = 0; i < n; i++){
        pq.push(arr[i]);
    }
    for(int i = 0; i < k; i++){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}