#include <stdio.h>
#include <string.h>



int main(int argc, char const *argv[])
{
	int n = 0, m = 0;
	scanf ("%d%d", &n, &m);
	int obstacleGrid[n][n];
	memset (obstacleGrid[0], 0, n * n * sizeof (int));
	while (m--) {
		int x = 0, y = 0;
		scanf ("%d%d", &x, &y);
		obstacleGrid[x - 1][y - 1] = 1;
	}

	int a[n], b[n];
    int *preResult = a, *result = b;
    int k = 0;
    while (k < n && obstacleGrid[0][k] == 0) preResult[k++] = 1;
    while (k < n) preResult[k++] = 0;

    for (int i = 1; i < n; ++i) {
        result[0] = preResult[0] == 0? 0: !obstacleGrid[i][0];
        for (int j = 1; j < n; ++j) {
            result[j] = (obstacleGrid[i][j] == 0? result[j - 1] + preResult[j]: 0) % 10000;
        }
        int *temp = result;
        result = preResult;
        preResult = temp;
    }

    printf("%d\n", preResult[n - 1]);
	return 0;
}