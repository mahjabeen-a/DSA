#include <limits.h> 
#include <stdio.h> 
#define N 10
int MatrixChainOrder(int p[], int n) { 

	//filling up from index 1,1
	int m[n][n]; 

	int i, j, k, L, q; 

	/* m[i, j] = Minimum number of 
	scalar multiplications 
	needed to compute the matrix 
	A[i]A[i+1]...A[j] = 
	A[i..j] where dimension of A[i] 
	is p[i-1] x p[i] */

	// cost is zero when multiplying one matrix. 
	//n = 2 means one matrix 
	for (i = 1; i < n; i++) 
		m[i][i] = 0; 

	// L is chain length. (number of matrices multiplied)
	for (L = 2; L < n; L++) { 
		for (i = 1; i + L - 1 < n; i++) { 
			j = i + L - 1; 
			m[i][j] = INT_MAX; 
			for (k = i; k < j; k++) { 
				q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]; 
				if (q < m[i][j]) 
					m[i][j] = q; 
			} 
		} 
	} 
	return m[1][n - 1]; 
} 

int main() { 
    int n;
    printf("Enter size of the array: ");
	scanf("%d", &n);
	printf("Enter the elements\n");
	int arr[N];
	for (int i = 0; i < n; i++){
	    scanf("%d", &arr[i]);
	}

	printf("Minimum number of multiplications is %d ", MatrixChainOrder(arr, n)); 
	return 0; 
}
