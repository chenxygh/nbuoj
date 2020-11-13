#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solutionsSize;

void solve(int** solutions, int* queens, int n, int row, int columns, int diagonals1, int diagonals2) {
    if (row == n) {
        int *res = (int *) malloc (sizeof (int) * n);
    	for (int i = 0; i < n; ++i) res[i] = queens[i] + 1;
        solutions[solutionsSize++] = res;
    } else {
        int availablePositions = ((1 << n) - 1) & (~(columns | diagonals1 | diagonals2));
        while (availablePositions != 0) {
            int position = availablePositions & (-availablePositions);
            availablePositions = availablePositions & (availablePositions - 1);
            int column = __builtin_ctz(position);
            queens[row] = column;
            solve(solutions, queens, n, row + 1, columns | position, (diagonals1 | position) >> 1, (diagonals2 | position) << 1);
            queens[row] = -1;
        }
    }
}

int** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    int** solutions = (int **)malloc(sizeof(int*) * 501);
    solutionsSize = 0;
    int queens[n];
    memset(queens, -1, sizeof(queens));
    solve(solutions, queens, n, 0, 0, 0, 0);
    *returnSize = solutionsSize;
    *returnColumnSizes = (int *)malloc(sizeof(int) * solutionsSize);
    for (int i = 0; i < solutionsSize; i++) {
        (*returnColumnSizes)[i] = n;
    }
    return solutions;
}

int main(int argc, char const *argv[])
{
	int returnSize = 0, *returnColumnSizes, n;
	scanf ("%d", &n);
	int **solutions = solveNQueens (n, &returnSize, &returnColumnSizes);
	for (int i = 0; i < returnSize; ++i) {
		for (int k = 0; k < returnColumnSizes[i]; ++k) {
			if (k == 0) {
				printf("%d", solutions[i][k]);
			} else {
				printf(" %d", solutions[i][k]);
			}
		}
		printf("\n");
	}
	printf("%d\n", returnSize);
	return 0;
}