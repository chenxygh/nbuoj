#include <stdio.h>
#include <math.h>

int cnt = 1;

void coverGrid (int grid[32][32], int x, int y, int obstacleX, int obstacleY, int gridSize) {
	if (gridSize == 1) return;	
	gridSize /= 2;
	int t = cnt++;
	if (obstacleX < x + gridSize && obstacleY < y + gridSize) {
		coverGrid (grid, x, y, obstacleX, obstacleY, gridSize);
	} else {
		grid[x + gridSize - 1][y + gridSize - 1] = t;
		coverGrid (grid, x, y, x + gridSize - 1, y + gridSize - 1, gridSize);
	}

	if (obstacleX < x + gridSize && obstacleY >= y + gridSize) {
		coverGrid (grid, x, y + gridSize, obstacleX, obstacleY, gridSize);
	} else {
		grid[x + gridSize - 1][y + gridSize] = t;
		coverGrid (grid, x, y + gridSize, x + gridSize - 1, y + gridSize, gridSize);
	}

	if (obstacleX >= x + gridSize && obstacleY < y + gridSize) {
		coverGrid (grid, x + gridSize, y, obstacleX, obstacleY, gridSize);
	} else {
		grid[x + gridSize][y + gridSize - 1] = t;
		coverGrid (grid, x + gridSize, y, x + gridSize, y + gridSize - 1, gridSize);
	}

	if (obstacleX >= x + gridSize && obstacleY >= y + gridSize) {
		coverGrid (grid, x + gridSize, y + gridSize, obstacleX, obstacleY, gridSize);
	} else {
		grid[x + gridSize][y + gridSize] = t;
		coverGrid (grid, x + gridSize, y + gridSize, x + gridSize, y + gridSize, gridSize);
	}
}

int main(int argc, char const *argv[])
{
	int k = 0, obstacleX = 0, obstacleY = 0, length = 0;
	scanf ("%d%d%d", &k, &obstacleX, &obstacleY);
	length = pow (2, k);
	int grid[32][32] = {0};

	coverGrid (grid, 0, 0, obstacleX, obstacleY, length);
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {
			printf("%4d", grid[i][j]);
		}
		printf("\n");
	}

	return 0;
}