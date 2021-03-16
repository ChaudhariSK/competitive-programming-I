#include <stdio.h> 
 
int sumdigits(int n) 
{ 
    int sum = 0; 
    while (n != 0) 
    { 
        sum = sum + n % 10; 
        n = n / 10; 
    } 
    return sum; 
} 
 
int main(){ 
    int n;  
    scanf("%d",&n); 
    int biggest = 0; 
    int best = 0; 
    int sum; 
    for (int i = 1; i <= n; i++) 
    { 
        if (n % i == 0) 
        { 
            sum = sumdigits(i); 
            if (biggest < sum) 
            { 
                biggest = sum; 
                best = i; 
            } 
        } 
    } 
    printf("%d\n", best); 
    return 0; 
}