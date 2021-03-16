#include <stdio.h>
#include <math.h>

int costs[1000];
int nCosts = 1000;

int sumCosts() {
    int sum = 0;
    
    int i = 0;
    for (i = 0; i < nCosts; i++) {
        sum += costs[i];
    }
    return sum;
}

int main() {
    for (;;) {
        scanf("%d", &nCosts);
        if (nCosts == 0) { 
            break;
        }
        
        int c = 0;
        for (c = 0; c < nCosts; c++) {
            int dollars;
            int cents;
            scanf("%d.%d", &dollars, &cents);
            costs[c] = dollars * 100 + cents;            
        }
        
        int sumCents = sumCosts();
        double avgCents = ((double) sumCents) / nCosts;
        double taken = 0;
        double given = 0;
        
        int i;
        for (i = 0; i < nCosts; i++) {
            double deltaCents = costs[i] - avgCents;
            if (deltaCents < 0) {
                taken += -((int) deltaCents) / 100.0;
            } else {
                given += ((int) deltaCents) / 100.0;
            }
        }
        
        printf("$%.2f\n", taken > given ? taken : given);
    }
    return 0;
}