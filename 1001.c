#include <stdio.h>
#include <string.h>

void bigAdd (int *a, int *b, int *c) {
	int carry = 0;
    for(int i = 999; i >= 0; --i)
    {
        c[i] = a[i] + b[i] + carry;
        carry = c[i] / 10;
        c[i] %= 10;
    }
}

int main(int argc, char const *argv[])
{
	int n = 0;
	scanf ("%d", &n);
	if (n == 1) {
		printf("%d\n", 1);
		return 0;
	}
	if (n == 2) {
		printf("%d\n", 3);
		return 0;
	}
	int a[1000] = {0}, b[1000] = {0}, c[1000] = {0}, d[1000] = {0};
	int *p = a, *q = b, *r = c, *t = d;
	a[999] = 1;
	b[999] = 3;
	for (int i = 3; i <= n; ++i) {
		memset (r, 0, sizeof (int) * 1000);
		memset (t, 0, sizeof (int) * 1000);
		bigAdd (p, q, t);
		bigAdd (t, p, r);
		t = p;
		p = q;
		q = r;
		r = t;
	}
	int index = 0;
	while (q[index] == 0) ++index;
	while (index < 1000) {
		printf("%d", q[index++]);
	}
	printf("\n");
	return 0;
}