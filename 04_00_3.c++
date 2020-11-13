#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
using namespace std;

int n, num;
int a[20] = {0};
bool y[41], x1[41], x2[41];
 
void func (int x) { 
    if (x > n) {
    	++num;
    	if (num <= 3) {
    		printf("%d", a[1]);
			for (int i = 2; i <= n; ++i) {
				printf(" %d", a[i]);
			}
			printf("\n");
    	}
    } else {
    	for(int i = 1;i <= n;++i) {
    		if (y[i] == 0 && x1[x + i] == 0 && x2[x - i + n] == 0) { 
				a[x] = i;
				y[i] = 1;
				x1[x + i] = 1;
				x2[x - i + n] = 1;
				func (x + 1);
				y[i] = 0;
				x1[x + i] = 0;
				x2[x - i + n] = 0;
			}
    	}
    }
}

int main(int argc, char const *argv[])
{
	scanf ("%d", &n);
	func (1);
	printf("%d\n", num);
	return 0;
}