#include<stdio.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)


    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);
}
int main() {
	int tc, r, median, x[505], i, ans;

	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &r);

		for (i = 0; i < r; i++) {
			scanf("%d", &x[i]);
		}
		bubbleSort(x,r);
		median = x[r / 2];

		ans = 0;
		for ( i = 0; i < r; i++) {
			ans += abs(median - x[i]);
		}

		printf("%d\n", ans);
	}

	return 0;
}
