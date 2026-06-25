#include <stdio.h>

#define MAX 10001

typedef struct {
	long long t;
	long long x;
} vect;

long long cmmdc(long long a, long long b)
{
	if (b == 0)
		return a;
	return cmmdc(b, a % b);
}

long long cmmmc(long long a, long long b)
{
	long long d = cmmdc(a, b);
	return (a / d) * b;
}

int main(void)
{
	short window;
	vect v[MAX];
	short count = 0;

	if (scanf("%hd", &window) != 1)
		return 0;

	while (count < MAX) {
		long long current_t, current_x;
		if (scanf("%lld %lld", &current_t, &current_x) != 2)
			break;
		if (current_t == 0 && current_x == 0)
			break;

		v[count].x = current_x;
		v[count].t = current_t;
		count++;
	}

	for (int i = 0; i < count; i++) {
		for (int j = i + 1; j < count; j++) {
			if (v[j].t - v[i].t <= (long long)window) {
				long long v_cmmdc = cmmdc(v[i].x, v[j].x);
				long long v_cmmmc = cmmmc(v[i].x, v[j].x);

				printf("%lld %lld\n", v_cmmmc, v_cmmdc);
			}
		}
	}
	return 0;
}
