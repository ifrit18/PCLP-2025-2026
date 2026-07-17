#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// functie din care extragi lungimea navei
int length_ship(char ch) {
  if (ch == 'A') return 1;
  if (ch == 'L') return 2;
  if (ch == 'B') return 3;
  if (ch == 'Y') return 4;
  if (ch == 'S') return 5;
  return 0;
}

// functie din care iei numele navei in functie de identificator
char* get_name(char s) {
  switch (s) {
    case 'S':
      return "Shinano";
    case 'L':
      return "Laffey";
    case 'Y':
      return "Yamato";
    case 'B':
      return "Belfast";
    case 'A':
      return "Albacore";

      // lipseste caz default; o sa dea warning
  }
}

// alocare dinamic matrice
int** mtx_all(int n, int m) {
  // eroare de alocare de memorie
  int** a = malloc(sizeof(int*) * n);

  for (int i = 1; i <= n; ++i) {
    a[i] = malloc(sizeof(int) * m);
    // initializez matricea
    for (int j = 1; j <= m; ++j) {
      a[i][j] = 0;
    }
  }
  return a;
}

// eliberare spatiu matrice
void mtx_deall(int** a, int n, int m) {
  // m nu este folosit
  for (int i = 1; i <= n; ++i) free(a[i]);
  free(a);
}

int main(void) {
  int j;
  scanf("%d", &j);

  int i = 1;

  // vectorii nu au fost folositi
  int nave1[105], nave2[105];

  int **tabla1, **tabla2;

  // bucla infinita
  while (i <= j) {
    int coord_x[105], coord_y[105];  // variabile nefolosite

    int n, m;
    scanf("%d%d", &n, &m);

    int k = n * m / 20 + n * m / 30 + n * m / 40 + n * m / 55 + n * m / 70;

    tabla1 = mtx_all(n, m);
    tabla2 = mtx_all(n, m);

    // eroare de alocare
    int *jucator1_coordx2, *jucator1_coordy2;
    jucator1_coordx2 = (int*)malloc(k * sizeof(int));
    jucator1_coordy2 = (int*)malloc(k * sizeof(int));

    int *jucator2_coordx2, *jucator2_coordy2;
    jucator2_coordx2 = (int*)malloc(k * sizeof(int));
    jucator2_coordy2 = (int*)malloc(k * sizeof(int));

    bool* jucator2_carac;
    jucator2_carac = malloc(k * sizeof(bool));

    // aceleasi linii de 2 ori
    bool* jucator2_carac;
    jucator2_carac = malloc(k * sizeof(bool));

    int contor1 = 1, contor2 = 1, x, y;

    char type, ori;

    char* tip_jucator1 = (char*)malloc(k * sizeof(char));
    char* orientare_jucator1 = (char*)malloc(k * sizeof(char));
    int* coord_x1 = (int*)malloc(k * sizeof(int));
    int* coord_y1 = (int*)malloc(k * sizeof(int));
    int* lung_nava1 = (int*)malloc(k * sizeof(int));
    int* nr_de_lovituri1 = (int*)malloc(k * sizeof(int));

    char* tip_jucator2 = (char*)malloc(k * sizeof(char));
    char* orientare_jucator2 = (char*)malloc(k * sizeof(char));
    int* coord_x2 = (int*)malloc(k * sizeof(int));
    int* coord_y2 = (int*)malloc(k * sizeof(int));
    int* lung_nava2 = (int*)malloc(k * sizeof(int));
    int* nr_de_lovituri2 = (int*)malloc(k * sizeof(int));

    int current_player = 1;

    while (contor1 <= k || contor2 <= k) {
      // eroare de citire
      scanf("%c%c%d%d", &type, &ori, &x, &y);
      int lung;
      lung = length_ship(type);

      bool valid = 1;

      if (ori == 'H') {
        if (y + lung - 1 > m) {
          valid = 0;
        }
      }

      // ce inseamna L??
      if (ori == 'L') {
        if (x - lung + 1 < 1) {
          valid = 0;
        }
      }

      int** current_table = tabla1;

      if (current_player == 1) {
        current_table = tabla1;
      } else {
        current_table = tabla2;
      }

      if (ori == 'H') {
        int copy_y = y;
        // eroare de logica
        while (y <= y + lung - 1) {
          if (a[x][y] != 0) valid = 0;
          y++;
        }
        y = copy_y;
      }

      if (ori == 'L') {
        int copy_x = x;
        // la fel ca mai sus
        while (x >= x - lung + 1) {
          // variabila a nu exosta
          if (a[x][y] != 0) valid = 0;
          x--;
        }
        x = copy_x;
      }

      if (valid == 0) {
        if (ori == 'H') {
          // eroare de format
          printf(
              "Nava %c nu poate fi amplasata orizontal la coordonatele (%d, "
              "%d).",
              type, x, y);
        }
        if (ori == 'L') {
          printf(
              "Nava %c nu poate fi amplasata vertical la coordonatele (%d, "
              "%d).",
              type, x, y);
        }
      }

      // unde se vede ship_id??
      int ship_id;
      if (valid == 1) {
        if (current_player == 1) {
          ship_id = contor1;
        } else {
          ship_id = contor2;
        }
      }
      // daca valid ==0, va continua sa execute ceea ce e mai jos

      if (current_player == 1) {
        tip_jucator1[ship_id] = type;
        orientare_jucator1[ship_id] = ori;
        coord_x1[ship_id] = x;
        coord_y1[ship_id] = y;
        lung_nava1[ship_id] = lung;
        // nava nu se intinde si pe orizontala si pe veritcala
        jucator1_coordx2[ship_id] = x - lung + 1;
        jucator1_coordy2[ship_id] = y + lung - 1;
        contor1++;
      }

      if (current_player == 2) {
        tip_jucator2[ship_id] = type;
        orientare_jucator2[ship_id] = ori;
        coord_x2[ship_id] = x;
        coord_y2[ship_id] = y;
        lung_nava2[ship_id] = lung;
        jucator2_coordx2[ship_id] = x - lung + 1;
        jucator2_coordy2[ship_id] = y + lung - 1;
        contor2++;
      }

      if (ori == 'H') {
        int copy_y = y;
        // eroare la fel ca mai sus
        while (y <= y + lung - 1) {
          a[x][y] = ship_id;
          y++;
        }
        y = copy_y;
      }

      if (ori == 'L') {
        int copy_x = x;
        while (x >= x - lung + 1) {
          a[x][y] = ship_id;
          x--;
        }
        x = copy_x;
      }

      if (valid == 1 && current_player == 1) {
        current_player = 2;
      } else if (valid == 1 && current_player == 2) {
        current_player = 1;
      }
    }

    // compilarea se va opri aici
    int atac_jucator1_x, atac_jucator1_y, atac_jucator2_x, atac_jucator2_y,
        nave_jucator1 = ship_id, nave_jucator2 = ship_id;

    int atac_jucator_x, atac_jucator_y;

    current_player = 1;

    int** current_table;

    int ship_id1 = 1, ship_id2 = 1;

    char orientare_jucator;

    // nume puse gresit
    while (nave_jucator_1 != 0 || nave_jucator_2 != 0) {
      bool valid = 1;
      if (current_player == 1) {
        scanf("%d%d", &atac_jucator1_x, &atac_jucator1_y);
        atac_jucator_x = atac_jucator1_x;
        atac_jucator_y = atac_jucator1_y;
        orientare_jucator = orientare_jucator1[ship_id1];
        current_table = tabla2;
      } else {
        scanf("%d%d", &atac_jucator2_x, &atac_jucator2_y);
        atac_jucator_x = atac_jucator2_x;
        atac_jucator_y = atac_jucator2_y;
        orientare_jucator = orientare_jucator2[ship_id2];
        current_table = tabla1;
      }

      // nu e logica buna + nu ai pus operatori
      if (current_table[atac_jucator_x][atac_jucator_y] == 1 ||
          current_table[atac_jucator_x][atac_jucator_y] ==
              2 current_table[atac_jucator_x][atac_jucator_y] ==
              3 current_table[atac_jucator_x][atac_jucator_y] ==
              4 current_table[atac_jucator_x][atac_jucator_y] == 5) {
        // logica nu e buna; nu se afiseaza nimic
        if (orientare_jucator == 'H') {
          if (current_table[atac_jucator_x][atac_jucator_y - 1] ==
              current_table[atac_jucator_x][atac_jucator_y])
            if (current_player == 1) {
              nave_jucator2--;
            }
        } else {
          nave_jucator1--;
        }

        if (orientare_jucator == 'L') {
          if (current_table[atac_jucator_x + 1][atac_jucator_y] ==
              current_table[atac_jucator_x][atac_jucator_y])
            if (current_player == 1) {
              nave_jucator2--;
            } else {
              nave_jucator1--;
            }
        }
      }
    }
    // eroare de memorie. nu exista free()
  }

  // atentie cand sunt afisate board-urile!
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      // nu trebuie afisat id-ul ei
      printf("%d ", tabla1[i][j]);
    }
    printf("\n");
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      printf("%d ", tabla2[i][j]);
    }
    printf("\n");
  }

  printf("\n");

  // inca o afisare??
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      printf("%d ", tabla2[i][j]);
    }
    printf("\n");
  }

  return 0;
}