// For a given integer array/list 'ARR' of size 'N' containing all distinct values, find the total number of 'Inversions' that may exist.
// An inversion is defined for a pair of integers in the array/list when the following two conditions are met.
// A pair ('ARR[i]', 'ARR[j]') is said to be an inversion when:

// 1. 'ARR[i] > 'ARR[j]' 
// 2. 'i' < 'j'

// Where 'i' and 'j' denote the indices ranging from [0, 'N').
// Input format :
// The first line of input contains an integer 'N', denoting the size of the array.

// The second line of input contains 'N' integers separated by a single space, denoting the elements of the array 'ARR'.
// Output format :
// Print a single line containing a single integer that denotes the total count of inversions in the input array.
// Note:
// You are not required to print anything, it has been already taken care of. Just implement the given function.  
// Constraints :
// 1 <= N <= 10^5 
// 1 <= ARR[i] <= 10^9

// Where 'ARR[i]' denotes the array element at 'ith' index.

// Time Limit: 1 sec
// Sample Input 1 :
// 3
// 3 2 1
// Sample Output 1 :
// 3
// Explanation of Sample Output 1:
// We have a total of 3 pairs which satisfy the condition of inversion. (3, 2), (2, 1) and (3, 1).
// Sample Input 2 :
// 5
// 2 5 1 3 4
// Sample Output 2 :
// 4
// Explanation of Sample Output 1:
// We have a total of 4 pairs which satisfy the condition of inversion. (2, 1), (5, 1), (5, 3) and (5, 4).

#include <bits/stdc++.h> 

long long merge(long long *a, int start, int mid, int end){
    vector<int>left,right;
    for(int i=start;i<=mid;i++) left.push_back(a[i]);
    for(int i=mid+1;i<=end;i++) right.push_back(a[i]);
    
    long long total=0;
    int n=left.size();
    int m=right.size();
    int left_ptr=0;
    int right_ptr=0;
    int curr=start;
    
    while(left_ptr<n && right_ptr<m){
        if(left[left_ptr]<=right[right_ptr]){
            a[curr] = left[left_ptr];
            curr++;
            left_ptr++;
        }
        else{
            a[curr] = right[right_ptr];
            total+=(n-left_ptr);
            curr++;
            right_ptr++;
        }
    }
    while(left_ptr<n){
        a[curr] = left[left_ptr];
        curr++;
        left_ptr++;
    }
    while(right_ptr<m){
        a[curr] = right[right_ptr];
        curr++;
        right_ptr++;
    }
    return total;
}

long long mergeSort(long long *arr, int start, int end){
	if(start>=end) return 0;
    int mid = (start+end)/2;
    long long total=0;
    total+=mergeSort(arr,start,mid);
    total+=mergeSort(arr,mid+1,end);
    total+=merge(arr, start, mid, end);
    return total;
}

long long getInversions(long long *arr, int n){
    return mergeSort(arr, 0, n-1);
}