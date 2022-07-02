// Check whether a given String S is a palindrome using recursion. Return true or false.

// Input Format :
// String S
// Output Format :
// 'true' or 'false'
// Constraints :
// 0 <= |S| <= 1000
// where |S| represents length of string S.

// Sample Input 1 :
// racecar
// Sample Output 1:
// true

// Sample Input 2 :
// ninja
// Sample Output 2:
// false

bool checkPalindromeRec(char input[], int start, int end, int n){
    if(n <= 1){
        return true;
    }
    if(input[start] != input[end]){
        return false;
    }
    return checkPalindromeRec(input, start + 1, end - 1, n-1);
}

bool checkPalindrome(char input[]) {
    return checkPalindromeRec(input, 0, strlen(input) - 1, strlen(input));

}
