#include <stdio.h>
#include <stdbool.h>

void read_mtx(char a[105][105], int n, int m) {
    int i = 0, j = 0;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            scanf(" %c", &a[i][j]);
        }
    }
}

bool ok(char c) {
    if (c != '#' && c != '0' && c != '1' && c != '2' && c != '3' && c != '4') {
        return true;
    }
    return false;
}

void optiunea_1_light(char a[105][105], int n, int m) {
    int i = 0, j = 0, r = 0, c = 0;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            if (a[i][j] == 'L') {
                r = i - 1;
                while (r >= 0 && ok(a[r][j]) == 1) {
                    if (a[r][j] == '-')
                        a[r][j] = 'x';
                    r--;
                }
                r = i + 1;
                while (r < n && ok(a[r][j]) == 1){
                    if (a[r][j] == '-')
                        a[r][j] = 'x';
                    r++;
                }
                c = j - 1;
                while (c >= 0 && ok(a[i][c]) == 1) {
                    if (a[i][c] == '-')
                        a[i][c] = 'x';
                    c--;
                }
                c = j + 1;
                while (c < m && ok(a[i][c]) == 1) {
                    if (a[i][c] == '-')
                        a[i][c] = 'x';
                    c++;
                }
            }
        }
    }
}

void optiunea_1_numarare(char a[105][105], int n, int m) {
    int i = 0, j = 0, r = 0, c = 0, count = 0;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            count = 0;
            if (a[i][j] == '0' || a[i][j] == '1' || a[i][j] == '2' || a[i][j] == '3' || a[i][j] == '4') {
                if (a[i - 1][j] == 'L')
                    count++;
                if (a[i][j - 1] == 'L')
                    count++;
                if (a[i + 1][j] == 'L')
                    count++;
                if (a[i][j + 1] == 'L')
                    count++;
                if (count == a[i][j] - '0') {
                    if (a[i - 1][j] == '-')
                        a[i - 1][j] = 'x';
                    if (a[i][j - 1] == '-')
                        a[i][j - 1] = 'x';
                    if (a[i + 1][j] == '-')
                        a[i + 1][j] = 'x';
                    if (a[i][j + 1] == '-')
                        a[i][j + 1] = 'x';
                }
            }
        }
    }
}

bool optiunea_2_verificare(char a[105][105], int n, int m) {
    int i = 0, j = 0, r = 0, c = 0;
    bool some = 1;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            if (a[i][j] == 'L') {
                some = 1;
                r = i - 1;
                while (r >= 0 && ok(a[r][j])) {
                    if (a[r][j] == 'L') {
                        some = false;
                        return some;
                    }
                    r--;
                }
                r = i + 1;
                while (r < n && ok(a[r][j])) {
                    if (a[r][j] == 'L') {
                        some = false;
                        return some;
                    }
                    r++;
                }
                c = j - 1;
                while (c >= 0 && ok(a[i][c])) {
                    if (a[i][c] == 'L') {
                        some = false;
                        return some;
                    }
                    c--;
                }
                c = j + 1;
                while (c < m && ok(a[i][c])) {
                    if (a[i][c] == 'L') {
                        some = false;
                        return some;
                    }
                    c++;
                }
            }
        }
    }
    return some;
}

bool optiunea_2_numarare(char a[105][105], int n, int m) {
    int i = 0, j = 0, count = 0;
    bool ok = true;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            count = 0;
            if (a[i][j] == '0' || a[i][j] == '1' || a[i][j] == '2' || a[i][j] == '3' || a[i][j] == '4') {
                if (a[i - 1][j] == 'L')
                    count++;
                if (a[i + 1][j] == 'L')
                    count++;
                if (a[i][j - 1] == 'L')
                    count++;
                if (a[i][j + 1] == 'L')
                    count++;
            }
            if (count > a[i][j] - '0')
                ok = false;
        }
    }
    if (ok)
        return true;
    return false;
}

void print_mtx(char a[105][105], int n, int m) {
    int i = 0, j = 0;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            printf("%c", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int o, n, m;
    char a[105][105];
    scanf("%d%d%d", &o, &n, &m);
    read_mtx(a, n, m);
    if (o == 1) {
        optiunea_1_light(a, n, m);
        optiunea_1_numarare(a, n, m);
        print_mtx(a, n, m);
    }
    if (o == 2) {
        bool ok;
        ok = optiunea_2_verificare(a, n, m);
        ok = optiunea_2_numarare(a, n, m);
        if (ok == 1)
            printf("ichi");
        else
            printf("zero");
    }
}
