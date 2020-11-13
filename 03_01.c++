#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

typedef struct {
	int left;
	int right;
} interval;

bool cmp (interval &a, interval &b) {
	return a.left < b.left || (a.left == b.left && a.right < b.right);
}
int main(int argc, char const *argv[])
{
	int n = 0, cnt = 0;
	interval a[2000], r[2000];
	scanf ("%d", &n);
	for (int i = 0; i < n; ++i) scanf ("%d%d", &(a[i].left), &(a[i].right));
	sort(a, a + n, cmp);
	int end = a[n - 1].right;
	int right = a[0].left - 1;
	for(int i = 0; i < n - 1; ){
		int max_right = a[i].right, max_index = i;
		while (a[i].left <= right + 1 && i < n) {
			if (a[i].right > max_right) {
				max_right = a[i].right;
				max_index = i;
			}
			i++;
		} 
		right = max_right;
		r[cnt++] = a[max_index];
		i = max_index;
		if(right == end) break;
	}

	for(int i = 0; i < cnt; i++) {
		printf("%d %d\n", r[i].left, r[i].right);
	}

	return 0;
}