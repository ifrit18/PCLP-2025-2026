#include <stdbool.h>
#include <stdio.h>

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
          if (a[r][j] == '-') a[r][j] = 'x';
          r--;
        }
        r = i + 1;
        while (r < n && ok(a[r][j]) == 1) {
          if (a[r][j] == '-') a[r][j] = 'x';
          r++;
        }
        c = j - 1;
        while (c >= 0 && ok(a[i][c]) == 1) {
          if (a[i][c] == '-') a[i][c] = 'x';
          c--;
        }
        c = j + 1;
        while (c < m && ok(a[i][c]) == 1) {
          if (a[i][c] == '-') a[i][c] = 'x';
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
      if (a[i][j] == '0' || a[i][j] == '1' || a[i][j] == '2' ||
          a[i][j] == '3' || a[i][j] == '4') {
        if (a[i - 1][j] == 'L') count++;
        if (a[i][j - 1] == 'L') count++;
        if (a[i + 1][j] == 'L') count++;
        if (a[i][j + 1] == 'L') count++;
        if (count == a[i][j] - '0') {
          if (a[i - 1][j] == '-') a[i - 1][j] = 'x';
          if (a[i][j - 1] == '-') a[i][j - 1] = 'x';
          if (a[i + 1][j] == '-') a[i + 1][j] = 'x';
          if (a[i][j + 1] == '-') a[i][j + 1] = 'x';
        }
      }
    }
  }
}

void optiunea_2_light(char a[105][105], bool illum[105][105], int n, int m) {
  int i = 0, j = 0, r = 0, c = 0;

  for (i = 0; i < n; ++i) {
    for (j = 0; j < m; ++j) {
      illum[i][j] = (a[i][j] == 'x');
    }
  }

  for (i = 0; i < n; ++i) {
    for (j = 0; j < m; ++j) {
      if (a[i][j] == 'L') {
        r = i - 1;
        while (r >= 0 && ok(a[r][j]) == 1) {
          illum[r][j] = true;
          r--;
        }
        r = i + 1;
        while (r < n && ok(a[r][j]) == 1) {
          illum[r][j] = true;
          r++;
        }
        c = j - 1;
        while (c >= 0 && ok(a[i][c]) == 1) {
          illum[i][c] = true;
          c--;
        }
        c = j + 1;
        while (c < m && ok(a[i][c]) == 1) {
          illum[i][c] = true;
          c++;
        }
      }
    }
  }
}

bool optiunea_2_numarare(char a[105][105], int n, int m) {
  int i = 0, j = 0, r = 0, c = 0, count = 0, ok = 1;
  for (i = 0; i < n; ++i) {
    for (j = 0; j < m; ++j) {
      count = 0;
      if (a[i][j] == '0' || a[i][j] == '1' || a[i][j] == '2' ||
          a[i][j] == '3' || a[i][j] == '4') {
        if (a[i - 1][j] == 'L') count++;
        if (a[i][j - 1] == 'L') count++;
        if (a[i + 1][j] == 'L') count++;
        if (a[i][j + 1] == 'L') count++;
        if (count > a[i][j] - '0') {
          return false;
        }
      }
    }
  }
  return true;
}

bool verifica_becuri_pe_linii(char a[105][105], int n, int m) {
  bool bec_vazut = false;
  for (int i = 0; i < n; i++) {
    bec_vazut = false;
    for (int j = 0; j < m; j++) {
      if (ok(a[i][j]) == false)
        bec_vazut = false;
      else if (a[i][j] == 'L') {
        if (bec_vazut) return false;
        bec_vazut = true;
      }
    }
  }
  return true;
}

bool verifica_becuri_pe_coloane(char a[105][105], int n, int m) {
  bool bec_vazut = false;
  for (int j = 0; j < m; j++) {
    bec_vazut = false;
    for (int i = 0; i < m; i++) {
      if (ok(a[i][j]) == false)
        bec_vazut = false;
      else if (a[i][j] == 'L') {
        if (bec_vazut) return false;
        bec_vazut = true;
      }
    }
  }
  return true;
}

void optiunea2_valideaza(char a[105][105],int n, int m){
    bool illum[105][105];

    optiunea_2_light(a,illum,n,m);
    if (verifica_becuri_pe_coloane(a,n,m) && verifica_becuri_pe_linii(a,n,m) && optiunea_2_numarare(a,n,m))
        printf("ichi\n");
    else 
        printf("zero\n");
}

void print_mtx(char a[105][105], int n, int m) {
  int i = 0, j = 0;
  for (i = 0; i < n; ++i) {
    for (j = 0; j < m; ++j) {
      printf("%c ", a[i][j]);
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
  else{
    optiunea2_valideaza(a,n,m);
  }
}