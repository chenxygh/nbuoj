#include<iostream>
#include<cstring>
#include <stdio.h>

using namespace std;
int grid[40][40]; 
int n;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int cnt = 0;
int maxn = 0;
int id = 3;
int max_id = id;
 
 
void dfs(int x, int y)
{
	if (x < 0 || x > n + 1 || y < 0 || y > n + 1 || grid[x][y] != 0) return;
	grid[x][y] = id;
	cnt++;
	for (int i = 0; i < 4; i++) {
		dfs (x + dir[i][0], y + dir[i][1]);
	} 
}


int main(int argc, char const *argv[]) {
	scanf ("%d", &n);
	memset (grid, 0, sizeof(grid)); 
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf ("%d", &(grid[i][j]));
		}
	}

	dfs(0, 0);
	id++;
	
	for (int i = 2; i < n; i++) {
		for (int j = 2; j < n; j++) {
			cnt = 0;
			dfs(i, j);
			if(cnt > maxn){
				maxn = cnt;
				max_id = id;
			}
			id++;	
		}
	}
	for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (grid[i][j] == 1)
					cout << grid[i][j] << " ";
				else if(grid[i][j] != max_id)
					cout << '0' << " ";
				else 
					cout << '2' << " ";

			}	
			cout << endl;
		
		}	

	return 0;
}