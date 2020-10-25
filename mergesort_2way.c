#include <stdio.h>
#include <stdlib.h>

#define N 10

int min(int x, int y){
	return (x < y) ? x : y;
}

void merge(int A[], int temp[], int start, int mid, int end) {
	int k = start, i = start, j = mid + 1;

	while (i <= mid && j <= end){
		if (A[i] < A[j])
			temp[k++] = A[i++];
		else
			temp[k++] = A[j++];
	}
	while (i <= mid)
		temp[k++] = A[i++];

	for (int i = start; i <= end; i++)
		A[i] = temp[i];
}

void mergesort(int A[], int temp[], int n) {
	
	for (int m = 1; m < n; m = 2*m) {
		for (int i = 0; i < n - 1; i += 2*m) {
			int start = i;
			int mid = i + m - 1;
			int end = min(i + 2 * m - 1, n - 1);
			merge(A, temp, start, mid, end);
		}
	}
}

int printArray(int A[], int n){
	for (int i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}

int main() {
	int A[N], temp[N];
	int n;
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	printf("Enter the elements:\n");
	for (int i = 0; i < n; i++){
	    scanf("%d", &A[i]);
	    temp[i] = A[i];
	}
	printf("Initial Array : ");
	printArray(A, n);
	mergesort(A, temp, n);

	printf("Sorted Array : ");
	printArray(A, n);

	return 0;
}
