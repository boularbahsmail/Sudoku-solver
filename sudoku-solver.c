// ya bismillah hh
#include <stdio.h>
// Sudoku grid form
int grid[9][9];
// print solution function
void print_solution(void) {
  static int solutionNumber = 0;
  int i, j;
  // solution grid form
  printf("----- solution %d -----\n", ++solutionNumber);
  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) {
      printf("%d", grid[i][j]);
      if (j % 3 == 2) printf("  ");
    }
    printf("\n");
    if (i % 3 == 2) printf("\n");
  }
 
}
// search if row and column are empty or not
int safe(int row, int col, int n) {
  int i, j, br, bc;
 
  if (grid[row][col] == n) return 1;
  if (grid[row][col] != 0) return 0;
  for (j = 0; j < 9; j++)
    if (grid[row][j] == n) return 0;
  for (i = 0; i < 9; i++)
    if (grid[i][col] == n) return 0;
  br = row / 3;
  bc = col / 3;
  for (i = br * 3; i < (br + 1) * 3; i++)
    for (j = bc * 3; j < (bc + 1) * 3; j++)
      if (grid[i][j] == n) return 0;
 
  return 1;
}
// sudoku solved => print solution function
void solve(int row, int col) {
  int i, j;
 
  if (row == 9)
    print_solution();
  else
    for (i = 1; i <= 9; i++)
      if (safe(row, col, i)) {
	j = grid[row][col];
	grid[row][col] = i;
	if (col == 8)
	  solve(row + 1, 0);
	else
	  solve(row, col + 1);
 
	grid[row][col] = j;
      }
}
 
int main() {
  int i, j;
  // entering sudoku enteries values
  printf("enter the sudoku: \n");
  for(i=0;i<9;i++)
    for(j=0;j<9;j++) {
      printf("(%d, %d): ", i+1, j+1);
      scanf("%d", &grid[i][j]);
    }
  solve(0,0);
  return 0;
}
