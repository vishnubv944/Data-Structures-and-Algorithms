// Given a string S, remove consecutive duplicates from it recursively.

// Input Format :
// String S
// Output Format :
// Output string
// Constraints :
// 1 <= |S| <= 10^3

// where |S| represents the length of string
// Sample Input 1 :
// aabccba
// Sample Output 1 :
// abcba

// Sample Input 2 :
// xxxyyyzwwzzz
// Sample Output 2 :
// xyzwz

void removeConsecutiveDuplicates(char *input) {
    if(strlen(input) == 0){
        return;
    }
    removeConsecutiveDuplicates(input + 1);
    if(input[0] == input[1]){
        int i = 0;
        for(i = 1; i <= strlen(input); i++){
            input[i] = input[i+1];
        }
        input[i] = '\0';
        
    }

}