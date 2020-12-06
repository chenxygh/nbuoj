#include <stdio.h>

#define INT_MIN -2147483648

int max (int a, int b) {
    return a > b? a: b;
}

int main () {
    int p[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30}, n;
    scanf ("%d", &n);
    int r[11] = {0};
    r[0] = 0;
    for (int i = 1; i <= 10; ++i) {
        int q = INT_MIN;
        for (int j = 1; j <= i; ++j) {
            q = max (p[j] + r[i - j], q);
        }
        r[i] = q;
    }
    int res = n / 10 * r[10] + r[n % 10];
    printf("%d\n", res);
    return 0;
}
