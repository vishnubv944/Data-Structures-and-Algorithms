//PARTIALLY SOLVED

// You have been given two arrays, 'AT' and 'DT', representing the arrival and departure times of all trains that reach a railway station.
// Your task is to find the minimum number of platforms required for the railway station so that no train needs to wait.
// Note :
// 1. Every train will depart on the same day and the departure time will always be greater than the arrival time. For example, A train with arrival time 2240 and departure time 1930 is not possible.

// 2. Time will be given in 24H format and colons will be omitted for convenience. For example, 9:05AM will be given as "905", or 9:10PM will be given as "2110".

// 3. Also, there will be no leading zeroes in the given times. For example, 12:10AM will be given as “10” and not as “0010”.
// Input Format
// The first line of input contains an integer 'T' representing the number of test cases.

// The first line of each test case contains an integer 'N', representing the total number of trains.

// The second line of each test case contains 'N' single-spaced separated elements of the array 'AT',  representing the arrival times of all the trains.

// The third line of each test case contains 'N' single-spaced separated elements of the array 'DT', representing the departure times of all the trains.
// Output Format:
// For each test case, return the minimum number of platforms required for the railway station so that no train needs to wait.
// Note :
// You don't need to print the output, it has already been taken care of. You just need to implement the given function.
// Follow up :
// Try to solve the problem in O(N) time and O(1) space.
// Constraints:
// 1 <= T <= 10
// 1 <= N <= 50000
// 0 <= AT[i] <= DT[i] <= 2359

// Where 'AT[i]' and 'DT[i]' are the elements of the arrival and the departure arrays respectively.

// Time limit: 1 sec
// Sample Input 1:
// 2
// 6
// 900 940 950 1100 1500 1800
// 910 1200 1120 1130 1900 2000
// 4
// 100 200 300 400
// 200 300 400 500
// Sample Output 1:
// 3
// 2
// Explanation of the Sample Output 1:
// In test case 1, For the given input, the following will be the schedule of the trains:

// Train 1 arrived at 900 on platform 1. 
// Train 1 departed at 910 from platform 1. 
// Train 2 arrived at 940 on platform 1.
// Train 3 arrived at 950 on platform 2 (since platform 1 was already occupied by train 1).
// Train 4 arrived at 1100 on platform 3 (since both platforms 1 and 2 were occupied by trains 2 and 3 respectively).
// Train 3 departed at 1120 from platform 2 (platform 2 becomes vacant).
// Train 4 departed at 1130 from platform 3 (platform 3 also becomes vacant).
// Train 2 departed at 1200 from platform 1 (platform 1 also becomes vacant).
// Train 5 arrived at 1500 on platform 1.
// Train 6 arrived at 1800 on platform 2.
// Train 5 departed at 1900 from platform 1.
// Train 6 departed at 2000 from platform 2.

// Thus, minimum 3 platforms are needed for the given input.

// In test case 2, For the given input, the following will be the schedule of the trains:

// Train 1 arrived at 100 on platform 1. 
// Train 2 arrived at 200 from platform 2 (as platform 1 is occupied by train 1).
// Train 1 departed at 200 from platform 1. 
// Train 3 arrived at 300 on platform 1.
// Train 2 departed at 300 from platform 2.
// Train 4 arrived at 400 on platform 2.
// Train 3 departed at 400 from platform 1.
// Train 4 departed at 500 from platform 2. 

// Thus, 2 platforms are needed for the given input.
// Sample Input 2:
// 2
// 2
// 900 1000
// 999 1100
// 3
// 1200 1300 1450
// 1310 1440 1600    
// Sample Output 2:
// 1
// 2
// Explanation of the Sample Output 2:
// In test case 1, For the given input, the following will be the schedule of the trains:

// Train 1 arrived at 900 on platform 1. 
// Train 1 departed at 999 from platform 1. 
// Train 2 arrived at 1000 on platform 1.
// Train 2 arrived at 1100 on platform 1.

// Thus, only 1 platform is needed for the given input.

// In test case 2, For the given input, the following will be the schedule of the trains:

// Train 1 arrived at 1200 on platform 1. 
// Train 2 arrived at 1300 on platform 2. (since platform 1 was already occupied by train 1). 
// Train 1 departed at 1310 from platform 1.
// Train 2 departed at 1440 from platform 2.
// Train 3 arrived at 1450 on platform 1.
// Train 3 departed at 1600 on platform 1.

// Thus, minimum 2 platforms are needed for the given input.

int calculateMinPatforms(int at[], int dt[], int n) {
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        mp.insert(make_pair(at[i], dt[i]));
    }
    map<int, int>::iterator itr = mp.begin();
    map<int, int>::iterator itf = mp.begin();
    int c = 0;
    for (itr = mp.begin(); itr != mp.end(); ++itr) { 
         int var = itr -> second;
         itf = mp.upper_bound(var);
         
         if(itf == mp.end()){
                 //c++;
          }
          else{
            mp.erase(itf -> first);
          }
          c++;
    }
    return c;
}
// Second Approach
// The main idea behind this approach is to consider all the events in the sorted order. Once the events are in the sorted order, we find the number of trains at any time by keeping track of the trains that have arrived but not yet departed. The minimum number of platforms required will be the maximum number of trains at any time.

 

// The steps are as follows:

 

// Sort the array ‘AT' and ‘DT’.
 
// Use two pointers ‘i’ and ‘j’, both initialized to 0, to traverse the arrays ‘AT’ and ‘DT’ respectively. Also, we use the variable 'MIN_NUM_OF_PLATFORMS' to denote the minimum number of platforms required and the variable 'CUR_NUM_OF_PLATFORMS' to denote the current number of platforms required at any given time.
 
// Run a loop while ‘i’ < ‘N’ and ‘j’ < ‘N’ and compare the elements ‘AT[i]’ and ‘DT[j]’:


// If ‘AT[i]’ <= ‘DT[j]’, then one more platform is needed. Thus, 'CUR_NUM_OF_PLATFORMS' = 'CUR_NUM_OF_PLATFORMS' + 1 and ‘i’ = ‘i’ + 1.
 
// Else one less platform is needed. Thus, 'CUR_NUM_OF_PLATFORMS' = 'CUR_NUM_OF_PLATFORMS' -1 and 'j' = 'j' + 1
 
// Update 'MIN_NUM_OF_PLATFORMS' if 'CUR_NUM_OF_PLATFORMS' is greater than 'MIN_NUM_OF_PLATFORMS' i.e. 'MIN_NUM_OF_PLATFORMS' = max('MIN_NUM_OF_PLATFORMS', 'CUR_NUM_OF_PLATFORMS')
 
// Return 'MIN_NUM_OF_PLATFORMS' as the answer.

#include<bits/stdc++.h>
int calculateMinPatforms(int at[], int dt[], int n) {
    vector<int> a(n);
    vector<int> d(n);
    for(int i = 0; i < n; i++){
        a[i] = at[i];
        d[i] = dt[i];
    }
    sort(a.begin(), a.end());
    sort(d.begin(), d.end());
    int i = 0, j = 0, mp = 0, cp = 0;
    while((i < n)&&(j < n)){
        if(a[i] <= d[j]){
            cp++;
            i++;
        }
        else{
            cp--;
            j++;
        }
        mp = max(mp, cp);
    }
    
    return mp;
    
}