#include <stdio.h>
#include <stdlib.h>

#define MAX_VAL 1005
int a[MAX_VAL][MAX_VAL];

typedef struct coordonate {
	int r1, c1, r2, c2, s, s1, s2;
} coordonate;

void citire_teren(int n, int m)
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (scanf("%d", &a[i][j]) != 1)
				return;
		}
	}
}

void proceseaza_elicopter(coordonate c_curr, int *corecte, int *is_wrong)
{
	// Aflu marginile din ipoteză
	int r_min, c_min;
	if (c_curr.r1 < c_curr.r2)
		r_min = c_curr.r1;
	else
		r_min = c_curr.r2;

	if (c_curr.c1 < c_curr.c2)
		c_min = c_curr.c1;
	else
		c_min = c_curr.c2;

	int l_cateta = abs(c_curr.r1 - c_curr.r2) + 1;

	// gasesc dimensiunea varfului
	if (c_curr.s == 1) {
		if (c_curr.r1 < c_curr.r2)
			c_curr.s1 = c_curr.r1;
		else
			c_curr.s1 = c_curr.r2;

		if (c_curr.r1 > c_curr.r2)
			c_curr.s2 = c_curr.c1;
		else
			c_curr.s2 = c_curr.c2;
	} else {
		if (c_curr.r1 > c_curr.r2)
			c_curr.s1 = c_curr.r1;
		else
			c_curr.s1 = c_curr.r2;

		if (c_curr.r1 < c_curr.r2)
			c_curr.s2 = c_curr.c1;
		else
			c_curr.s2 = c_curr.c2;
	}

	int total_triunghi = 0;
	int umbra_triunghi = 0;

	// parcurg patratul de la r_min si c_min
	for (int i = r_min; i < r_min + l_cateta; i++) {
		for (int j = c_min; j < c_min + l_cateta; j++) {
			int inside = 0;
			int dist_r = abs(i - c_curr.s1);
			int dist_c = abs(j - c_curr.s2);
			if (dist_r + dist_c < l_cateta)
				inside = 1;

			if (inside) {
				total_triunghi++;
				if (a[i][j] == 0)
					umbra_triunghi++;
			}
		}
	}

	if (umbra_triunghi == 0)
		(*corecte)++;

	if (umbra_triunghi > total_triunghi / 2)
		*is_wrong = 1;
}

int main(void)
{
	int n, m, k;
	int corecte_total = 0, gresite = 0;
	int vesct_gresite[MAX_VAL];
	coordonate coord[MAX_VAL];

	if (scanf("%d %d", &n, &m) != 2)
		return 0;

	citire_teren(n, m);

	if (scanf("%d", &k) != 1)
		return 0;

	for (int idx = 1; idx <= k; idx++) {
		scanf("%d %d %d %d %d", &coord[idx].r1, &coord[idx].c1,
			  &coord[idx].r2, &coord[idx].c2, &coord[idx].s);

		// validare pozitii
		if (coord[idx].c1 == coord[idx].c2 ||
			coord[idx].r1 == coord[idx].r2 ||
			abs(coord[idx].r1 - coord[idx].r2) !=
			abs(coord[idx].c1 - coord[idx].c2)) {
			printf("Elicopterul %d este pozitionat ", idx);
			printf("necorespunzator!\n");
			continue;
		}

		int is_wrong = 0;
		proceseaza_elicopter(coord[idx], &corecte_total, &is_wrong);

		if (is_wrong) {
			vesct_gresite[gresite] = idx;
			gresite++;
		}
	}

	// afisare rezultate
	printf("%d\n", corecte_total);
	printf("%d\n", gresite);
	for (int i = 0; i < gresite; i++) {
		printf("%d ", vesct_gresite[i]);
	}
	printf("\n");

	return 0;
}
