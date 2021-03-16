#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
 
int next_permutation(int n, char **s) 
{ 
 /** 
 * Complete this method 
 * Return 0 when there is no next permutation and 1 otherwise 
 * Modify array s to its next permutation 
 */ 
    for (int i = n - 1; i > 0; i--) 
        if (strcmp(s[i], s[i - 1]) > 0) 
        { 
            int j = i + 1; 
            for (; j < n; j++) if (strcmp(s[j], s[i - 1]) <= 0) break; 
            char *t = s[i - 1]; 
            s[i - 1] = s[j - 1]; 
            s[j - 1] = t; 
            for (; i < n - 1; i++, n--) 
            { 
                t = s[i]; 
                s[i] = s[n - 1]; 
                s[n - 1] = t; 
            } 
            return 1; 
        } 
    for (int i = 0; i < n - 1; i++, n--) 
    { 
        char *t = s[i]; 
        s[i] = s[n - 1]; 
        s[n - 1] = t; 
    } 
    return 0; 
}