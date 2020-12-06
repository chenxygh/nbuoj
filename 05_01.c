#include <stdio.h>

int main () {
    int n = 0;
    scanf ("%d", &n);
    int nums[n], res[210] = {0};
    for (int i = 0; i < n; ++i) {
        scanf ("%d", nums + i);
    }
    int dp[n] = {0};
    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
    }
    for (int i = n - 2; i >= 0; --i) {
        for (int j = n - 1; j > i; --j) {
            if (nums[i] <= nums[j]) {
                dp[i] = dp[j] + 1;

            }
        }
    }
    return 0;
}
