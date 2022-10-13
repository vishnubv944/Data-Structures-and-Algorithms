// Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
// Note : The order of strings are not important. Just print different strings in new lines.
// Input Format :
// Integer n
// Output Format :
// All possible strings in different lines
// Constraints :
// 1 <= n <= 10^6
// Sample Input:
// 23
// Sample Output:
// ad
// ae
// af
// bd
// be
// bf
// cd
// ce
// cf

#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;

vector<string> data = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 

void recfun(vector<int> arr, int j, string str){
    if(j == -1){
        cout<<str<<endl;
        return;
    }
    string s = data[arr[j] - 2];
    for(int i = 0; s[i] != '\0'; i++){
        str.push_back(s[i]);
        recfun(arr, j-1, str);
        str.pop_back();
    }
}

void printKeypad(int num){
	string str = "";
    vector<int> numm;
    while(num != 0){
        numm.push_back(num%10);
        num = num / 10;
    }
    int m = numm.size();
    recfun(numm, m-1, str);
}
