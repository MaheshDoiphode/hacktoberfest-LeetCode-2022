// Given an integer n, return a string array answer (1-indexed) where:

// answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
// answer[i] == "Fizz" if i is divisible by 3.
// answer[i] == "Buzz" if i is divisible by 5.
// answer[i] == i (as a string) if none of the above conditions are true.
 

// Example 1:

// Input: n = 3
// Output: ["1","2","Fizz"]
// Example 2:

// Input: n = 5
// Output: ["1","2","Fizz","4","Buzz"]
// Example 3:

// Input: n = 15
// Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
 

// Constraints:

// 1 <= n <= 104

//Solution:
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** fizzBuzz(int n, int* returnSize){
    char **arr;
    arr=(char**)malloc(n*sizeof(char*));
    for(int i=0;i<n;i++)
       arr[i]=(char*)malloc(9*sizeof(char)); 
    for(int i=0;i<n;i++)
    {
        char *str=(char*)malloc(9*sizeof(char));
        strcpy(str,"\0");
        if((i+1)%3==0)
            strcat(str,"Fizz");
        if((i+1)%5==0)
            strcat(str,"Buzz");
        if((i+1)%3!=0 && (i+1)%5!=0)
            sprintf(str,"%d",i+1);
        strcpy(arr[i],str);
    }
    *returnSize=n;
    return arr;
}