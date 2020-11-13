#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int n = 0;
	int res = 0;
	scanf ("%d", &n);
	int nums[n];
	for (int i = 0; i < n; ++i) scanf ("%d", nums + i);
	sort (nums, nums + n);
	
	for (int i = 0; i < n - 1; ++i) {
		nums[i + 1] += nums[i];
		int temp = nums[i + 1];
		res += temp;
		int j = i + 2;
		for (; j < n && nums[j] < temp; ++j) {
			nums[j - 1] = nums[j];
		}
		nums[j - 1] = temp;
	}

	printf("%d\n", res);

	return 0;
}