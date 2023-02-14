//MEMOIZATION Solution
#include<bits/stdc++.h> 

int frogJmp(int i, vector<int> &heights, vector<int> &dp){
    if(i == 0){
        return 0;
    }
    if(dp[i] != -1){
        return dp[i];
    }
    int left = frogJmp(i-1, heights, dp) + abs(heights[i-1] - heights[i]);
    int right = INT_MAX;
    if(i > 1){
        right = frogJmp(i-2, heights, dp) + abs(heights[i-2] - heights[i]); 
    }
    dp[i] = min(left, right);
    return min(left, right);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1, -1);
    return frogJmp(n-1, heights, dp);
}

//TABULATION SOLUTION

#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1, 0);
    dp[0] = 0;
    int l, r = INT_MAX;
    for(int i = 1; i < n; i++){
        l = dp[i-1] + abs(heights[i-1] - heights[i]);
        if(i > 1){
            r = dp[i-2] + abs(heights[i-2] - heights[i]);
        } 
        dp[i] = min(r, l);
    }
    return dp[n-1];
}