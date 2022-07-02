// Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.

// Input format :
// Numeric string S (string, Eg. "1234")
// Output format :
// Corresponding integer N (int, Eg. 1234)
// Constraints :
// 0 <= |S| <= 9
// where |S| represents length of string S.

// Sample Input 1 :
// 00001231
// Sample Output 1 :
// 1231

// Sample Input 2 :
// 12567
// Sample Output 2 :
// 12567

int ans = 0;

void stringToNumberRec(char input[], int n){
    if(n == 0){
        return;
    }
    ans = ans * 10 + (input[0] - '0');
    stringToNumberRec(input + 1, n - 1);
}



int stringToNumber(char input[]) {
    stringToNumberRec(input, strlen(input));
    return ans;
}
