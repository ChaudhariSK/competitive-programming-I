#include <stdio.h>
#include <stdlib.h>

int main(){
    long long n;
    int cont;

    while(scanf("%llu",&n)){
       if(n==1){
            printf("Stan wins.");
            continue;
        }
        cont=0;
        while(n>1){
            cont++;
            if(cont%2==1) n=(n+8)/9;
            else n=(n+1)/2;
        }
        if(cont%2==1) printf("Stan wins.");
        else printf("Ollie wins.");
    }
    return 0;
}
