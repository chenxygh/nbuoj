#include <stdio.h>

int partition (int *nums, int left, int right) {
	int pivot = nums[left];
	while (left < right) {
		while (left < right && pivot <= nums[right]) --right;
		nums[left] = nums[right];
		while (left < right && pivot >= nums[left]) ++left;
		nums[right] = nums[left];
	}
	nums[left] = pivot;
	return left;
}

void findPre (int *nums, int numsSize, int n) {
	int left = 0, right = numsSize - 1;
	int pivotPos = partition (nums, left, right);
	while ((pivotPos + 1) != n) {
		if (pivotPos + 1 < n) {
			left = pivotPos + 1;
		} else {
			right = pivotPos - 1;
		}
		pivotPos = partition (nums, left, right);
	}
}

int main(int argc, char const *argv[])
{
	int n = 0, k = 0;
	scanf ("%d%d", &n, &k);
	int nums[n];
	for (int i = 0; i < n; ++i) {
		scanf ("%d", nums + i);
	}
	findPre (nums, n, k);
	printf("%d\n", nums[k - 1]);

	return 0;
}