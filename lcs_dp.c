#include <stdio.h>
#define SIZE 10

int max(int x, int y){
    return (x > y) ? x : y;
}

void LCS(char a[], int m, char b[], int n){
    int L[m + 1][n + 1];
    int i, j;
    for (i = 0; i < m + 1; i++){
        for (j = 0; j < n + 1; j++){
            if (i == 0 || j == 0){
                L[i][j] = 0;
            }
            else if (a[i - 1] == b[j - 1]){
                L[i][j] = 1 + L[i - 1][j - 1];
            }
            else {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]); 
            }
        }
    }
    
    int LCS_len = L[m][n];
    printf("The length of longest common subsequence is %d\n", LCS_len);
    
    i = m, j = n;
    char lcs[LCS_len + 1];
    while (i > 0 && j > 0){
        if (a[i - 1] == b[j - 1]) {
            lcs[LCS_len - 1] = a[i - 1];
            i--;
            j--;
            LCS_len--;
        }
        else {
            if (L[i - 1][j] > L[i][j-1]) i--;
            else j--;
        }
    }
    lcs[L[m][n]] = '\0';
    printf("The longest common subsequence is %s\n", lcs);
}

int main()
{
    char a[SIZE], b[SIZE];
    int m, n;
    printf("Enter length of string 1: ");
    scanf("%d", &m);
    printf("Enter string 1: ");
    scanf("%s", a);
    printf("Enter length of string 2: ");
    scanf("%d", &n);
    printf("Enter string 2: ");
    scanf("%s", b);
    
    LCS(a, m, b, n);
    return 0;
}
