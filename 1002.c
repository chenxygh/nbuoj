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

void func (int *nums, int numsSize, int left, int right) {
	findPre (nums, numsSize, right);
	findPre (nums, right, left);
}

int main(int argc, char const *argv[])
{
	int nums[500000] = {0}, numsSize = 0, num = -1, left = 4, right = 10;
	scanf ("%d", &num);
	while (num != 0) {
		nums[numsSize++] = num;
		scanf ("%d", &num);
	}
	func (nums, numsSize, left, right);
	for (int i = left; i < right; ++i) {
		printf("%d\n", nums[i]);
	}

	return 0;
}