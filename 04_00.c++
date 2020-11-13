#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solutionsSize;

void backtrack(int** solutions, int* queens, int n, int row, int* columns, int* diagonals1, int* diagonals2) {
    if (row == n) {
    	int *res = (int *) malloc (sizeof (int) * n);
    	for (int i = 0; i < n; ++i) res[i] = queens[i] + 1;
        solutions[solutionsSize++] = res;
    } else {
        for (int i = 0; i < n; i++) {
            if (columns[i]) {
                continue;
            }
            int diagonal1 = row - i + n - 1;
            if (diagonals1[diagonal1]) {
                continue;
            }
            int diagonal2 = row + i;
            if (diagonals2[diagonal2]) {
                continue;
            }
            queens[row] = i;
            columns[i] = true;
            diagonals1[diagonal1] = true;
            diagonals2[diagonal2] = true;
            backtrack(solutions, queens, n, row + 1, columns, diagonals1, diagonals2);
            queens[row] = -1;
            columns[i] = false;
            diagonals1[diagonal1] = false;
            diagonals2[diagonal2] = false;
        }
    }
}

int** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    int** solutions = (int **)malloc(sizeof(int*) * 501);
    solutionsSize = 0;
    int queens[n];
    int columns[n];
    int diagonals1[n + n];
    int diagonals2[n + n];
    memset(queens, -1, sizeof(queens));
    memset(columns, 0, sizeof(columns));
    memset(diagonals1, 0, sizeof(diagonals1));
    memset(diagonals2, 0, sizeof(diagonals2));
    backtrack(solutions, queens, n, 0, columns, diagonals1, diagonals2);
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