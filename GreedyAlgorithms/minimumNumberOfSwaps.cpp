// You are given a string ‘S’ of length ‘N’, an array A of length ‘M’ ( consisting of lowercase letters). and a positive integer ‘K’. You can take a character from 'A' and change any character in 'S' with this character. The task is to minimize the number of swaps required ( between ‘S’ and ‘A’ ) to make the string ‘S’ ‘k’-periodic.
// Note:
// 1. A string ‘S’ is said to be ‘K’ periodic, if for each position  ‘i’ in the string S[i] = S[i+K].

//    Consider string ‘S’,
//    if S = ”abcabc”, it is 3 periodic string.
//    if S= ”aaaaa”,  it is 1 periodic string.

// 2. In one move, only one character of ‘S’ can be swapped with a character of ‘A’.

// 3. The characters in ‘A’ can be used more than once.

// 4. All characters of K-periodic string ‘S’ are elements of array ‘A’.
// Input Format:
//  First-line will contain an integer ‘T’, the number of test cases. Then the test cases follow-

//  Each test case contains three lines of input. 

//  The first line contains three integers ‘N’, ‘M’, ‘K’. The second line contains a string of length ‘N’. 

//  The third line contains ‘M’ space-separated smaller case letters.
// Output Format:
// For each test case output an integer i.e minimum number of swaps required to make string K-periodic.
// Constraints:
// 1 <= T <= 5
// 1 <= N, M <= 2 * 10 ^ 4
// 1 <=  K < = N

// Time limit: 1 sec.
// Sample Input 1:
// 2
// 7 3 3
// abcbbde
// a b c
// 5 2 2
// ninja
// n i
// Sample Output 1:
// 3
// 2
// Explanation:
// In first test case, We need at least 3 swaps to make the string “abcbbde” 3 periodic. One swap between characters at index 3 in string and letter ‘a’ from the array. Second swap between character at index 6 in string and letter ‘a’ from array Third swap between character at index 5 in string and letter ‘c’ from the array.
// Sample Input 2:
// 1
// 3 1 1
// aaa
// a
// Sample Output 2:
// 0
// Explanation:
// In total 0 swaps are required to make string ‘1’-periodic.


bool search(char ch, vector<char> &arr, int n){
    for(int i = 0; i < n; i++){
        if(ch == arr[i]){
            return true;
        }
    }
    return false;
}

int minSwap (int N, int M, int K, string &S, vector<char> &arr)
{
    vector<vector<int>> vect( K , vector<int> (29, 0));
    char ch;
    int x;
    bool f = false;
	for(int i = 0; i < N; i++){
        ch = S[i];
        x = i % K;
        f = search(ch, arr, M);
        if(f == true){
            vect[x][ch - 'a']++;
            int v = vect[x][ch - 'a'];
            if(v > vect[x][26]){
                vect[x][26] = v;
            }
            vect[x][28]++;
        }
        else{
            vect[x][27]++;
            vect[x][28]++;
        }
    }
    int result = 0;
    for(int i = 0; i < K; i++){
        result = result + (vect[i][28] - vect[i][26]);
    }
    return result;
}