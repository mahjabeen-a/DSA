#include <stdio.h>
#include <stdbool.h>
#define N 8

//this assumes queens till col-1 are placed in proper order
bool isSafe(int board[N][N], int row, int col){
    for (int c = 0; c < col; c++){
        if (board[row][c] == 1) return false;
    }
    int i,j;
    for (i = row, j = col; i < N && j >= 0; i++, j--){
        if (board[i][j] == 1) return false;
    }
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--){
        if (board[i][j] == 1) return false;
    }
    return true;
}

bool isSolvable(int board[N][N], int col){
    if (col >= N) return true;
    for (int row = 0; row < N; row++){
        if (isSafe(board, row, col)){
            board[row][col] = 1;
            if (isSolvable(board, col + 1)) return true;
            board[row][col] = 0;
        }
    }
    return false;
}
void display(int board[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int board[N][N] = {0};
    if (isSolvable(board, 0)){
        printf("One possible solution:\n");
        display(board);
    }
    else{
        printf("NO SOLUTION\n");
    }
    return 0;
}
