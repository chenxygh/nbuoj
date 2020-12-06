#include <stdio.h>

#define INT_MIN -2147483648

typedef struct {
    int index;
    int val;
} Dp;

int main () {
    int n = 0;
    scanf ("%d", &n);
    int nums[n];
    for (int i = 0; i < n; ++i) {
        scanf ("%d", nums + i);
    }
    Dp dp[n];
    int index = 0, max = INT_MIN;
    for (int i = 0; i < n; ++i) {
        dp[i].index = i;
        dp[i].val = 1;
        for (int j = 0; j < i; ++j) {
            if (nums[j] <= nums[i] && dp[j].val + 1 >= dp[i].val) {
                dp[i].val = dp[j].val + 1;
                dp[i].index = j;
            }
        }
        if (dp[i].val >= max) {
            max = dp[i].val;
            index = i;
        }
    }
    int size = dp[index].val;
    printf("%d\n%d", size, nums[index]);
    --size;
    index = dp[index].index;
    while (size--) {
        printf(" %d", nums[index]);
        index = dp[index].index;
    }
    printf("\n");

    return 0;
}
