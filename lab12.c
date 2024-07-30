#include <stdio.h>
#include <stdbool.h>
#define MAX_N 10
int main() {
int N;
printf("Enter the number of queens: ");
scanf("%d", &N);
if (N <= 0 || N > MAX_N) {
printf("Invalid input. Size should be between 1 and %d\n", MAX_N);
return 1;
}
solveNQ(N);
return 0;
}
bool solveNQ(int N) {
int board[MAX_N][MAX_N] = {{0}};
int soln = 0;
if (!solveNQUtil(board, 0, N, &soln)) {
printf("No solution exists for the given problem instance.\n");
return false;
}
printf("Number of solutions for the given problem instance is: %d\n", soln);
return true;
}
bool solveNQUtil(int board[MAX_N][MAX_N], int col, int N, int *soln) {
if (col >= N) {
(*soln)++;
printSolution(board, N, *soln);
return true;
}
bool res = false;
for (int i = 0; i < N; i++) {
if (isSafe(board, i, col, N)) {
board[i][col] = 1;
res = solveNQUtil(board, col + 1, N, soln) || res;
board[i][col] = 0; 
}
}
return res;
}
bool isSafe(int board[MAX_N][MAX_N], int row, int col, int N) {
int i, j;
for (i = 0; i < col; i++)
if (board[row][i])
return false;
for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
if (board[i][j])
return false;
for (i = row, j = col; j >= 0 && i < N; i++, j--)
if (board[i][j])
return false;
return true;
}
void printSolution(int board[MAX_N][MAX_N], int N, int soln) { 
printf("Solution #%d\n\n", soln);
for (int i = 0; i < N; i++) {
for (int j = 0; j < N; j++)
printf("%c ", board[i][j] ? 'Q' : '#');
printf("\n");
}
printf("\n");
}
