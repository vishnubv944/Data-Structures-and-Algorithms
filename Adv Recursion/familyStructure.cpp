// Aakash is a member of Ninja club. He has a weird family structure. Every male member (M) gives birth to a male child first and then a female child, whereas every female (F) member gives birth to a female child first and then to a male child. Aakash analyses this pattern and wants to know what will be the Kth child in his Nth generation. Can you help him?
// A sample generation tree is shown, where ‘M’ denotes the male member and ‘F’ denotes the female member. 


// Note
// The generation tree starts with a male member i.e. Aakash. 
// Every member has exactly two children. 
// The given N and K will always be valid. 
// Input Format:
// The first line contains an integer 'T' which denotes the number of test cases. Then the test cases follow.
// The first and the only line of each test case contains two space-separated integers ‘N’ and ‘K’ denoting the generation number and position of the child in Nth generation, respectively. 
// Output Format
// For each test case, print the gender of the Kth child in the Nth generation. If the gender is male, print “Male” else print “Female” (without quotes). 
// The output of each test case is printed in a separate line. 
// Note
// You don’t have to print anything, it has already been taken care of. Just implement the given function. 
// Constraints :
// 1 <= T <= 5
// 1 <= N <= 50
// 1 <= K <= 2^(N - 1)
// where ‘T’ is the number of test cases, ‘N’ is generation number and ‘K’ is the position of the child in the Nth generation. 
// Sample Input 1:
// 2
// 2 2 
// 3 4  
// Sample Output 1:
// Female
// Male
// Explanation for Sample Input 1:
// Test Case 1:  2nd child of the 2nd generation is shown in green colour. 


// Test Case 2:  4th child of the 3rd generation is shown in green colour. 


// Sample Input 2:
// 3
// 5 1 
// 3 1
// 4 4  
// Sample Output 2:
// Male
// Male
// Male 

string kthChildNthGeneration(int n, long long int k)
{
	if(n == 0 || k == 1){
        return "Male";
    }
    long long int par = (k + 1)/2;
    string pargen = kthChildNthGeneration(n-1, par);
    if(k == (2*par-1)){
        return pargen;
    }
    else{
        if(pargen == "Male"){
            return "Female";
        }
        else{
            return "Male";
        }
    }
}