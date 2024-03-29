// Aahad and Harshit always have fun by solving problems. Harshit took a sorted array consisting of distinct integers and rotated it clockwise by an unknown amount. For example, he took a sorted array = [1, 2, 3, 4, 5] and if he rotates it by 2, then the array becomes: [4, 5, 1, 2, 3].
// After rotating a sorted array, Aahad needs to answer Q queries asked by Harshit, each of them is described by one integer Q[i]. which Harshit wanted him to search in the array. For each query, if he found it, he had to shout the index of the number, otherwise, he had to shout -1.
// For each query, you have to complete the given method where 'key' denotes Q[i]. If the key exists in the array, return the index of the 'key', otherwise, return -1.
// Note:
// Can you solve each query in O(logN) ?
// Input Format:
// The first line of input contains the size of the array: N

// The second line contains N single space-separated integers: A[i].

// The third line of input contains the number of queries: Q

// The next Q lines of input contain: the number which Harshit wants Aahad to search: Q[i]
// Output Format:
// For each test case, print the index of the number if found, otherwise -1.

// Output for every test case will be printed in a separate line.
// Note:
// You are not required to explicitly print the expected output, just return it and printing has already been taken care of.
// Constraints:
// 1 <= N <= 10^6
// -10^9 <= A[i] <= 10^9
// 1 <= Q <= 10^5
// -10^9 <= Q[i] <= 10^9

// Time Limit: 1sec
// Sample Input 1:
// 4
// 2 5 -3 0
// 2
// 5
// 1
// Sample Output 1:
// 1
// -1
// Explanation For Sample Input 1:
// In the 1st test case, 5 is found at index 1

// In the 2nd test case, 1 is not found in the array, hence return -1.
// Sample Input 2:
// 5
// 100 -2 6 10 11
// 2
// 100
// 6
// Sample Output 2:
// 0
// 2

int bs(int *arr, int l, int h, int k){
	if(l <= h){
		int mid = (l + h)/2;
		if(arr[mid] == k){
			return mid;
		}
		else if(arr[mid] > k){
			return bs(arr, l, mid-1, k);
		}
		else{
			return bs(arr, mid + 1, h, k);
		}

	}
		
}

int cusBinarySearch(int *arr, int l, int h){
	if(l <= h){
		int m = (l + h)/2;
		if(arr[m] > arr[m-1] && arr[m] > arr[m+1]){
			return m;
		}
		else if(arr[l] > arr[m]){
			cusBinarySearch(arr, l, m-1);
		}
		else{
			cusBinarySearch(arr, m+1, h);
		}
	}
}

int search(int* arr, int n, int key) {
    int d = cusBinarySearch(arr, 0, n-1);
    int ans1 = bs(arr, 0, d, key);
    int ans2 = bs(arr, d+1, n, key);
    if(arr[ans1] == key){
        return ans1;
    }
    else if(arr[ans2] == key){
        return ans2;
    }
    else{
        return -1;
    }
}