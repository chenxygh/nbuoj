#include <stdio.h>

#define INT_MIN -2147483648

int max (int a, int b) {
    return a > b? a: b;
}

int main () {
    int t = 0, m = 0;
    scanf ("%d%d", &t, &m);
    int values[m + 1], costs[m + 1];
    values[0] = costs[0] = 0;
    for (int i = 1; i <= m; ++i) {
        scanf ("%d%d", costs + i, values + i);
    }
    int a[t + 1], b[t + 1], *preRes = a, *res = b;
    for (int i = 0; i <= t; ++i) preRes[i] = 0;
    res[0] = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= t; ++j) {
            if (j < costs[i]) {
                res[j] = preRes[j];
            } else {
                res[j] = max (preRes[j], preRes[j - costs[i]] + values[i]);
            }
        }
        int *temp = res;
        res = preRes;
        preRes = temp;
    }
    printf("%d\n", preRes[t]);

    return 0;
}
