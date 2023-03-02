#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 3
#define COLS 3

int validate(int tab[ROWS][COLS], int row, int col, int number) {
    // Savoir si la valeur est présente dans la row ou la col
    for (int i = 0; i < number; i++) {
        if (tab[row][i] == number || tab[i][col] == number) {
            return 0;
        }
    }
    // Savoir si la valeur est présent dans un carré 
    int fourrow = (row / 3) * 3;
    int fourcol = (col / 3) * 3;
    for (int i = fourrow; i < fourrow + 3; i++) {
        for (int j = fourcol; j < fourcol + 3; j++) {
            if (tab[i][j] == number) {
                return 0;
            }
        }
    }
    return 1;
}

int calsudo(int tab[ROWS][COLS], int row, int col){
    // on vérifie les col et dans chaque col on vérifie les row
    if (col == COLS) {
        col = 0;
        row++;
        if (row == ROWS) {
            return 1;
        }
    }
    // si la case n'est pas vide on la skip
    if (tab[row][col] != 0){
        return calsudo(tab, row, col + 1);
    }
    // on test les 9 valeurs de la case
    for (int number = 1; number <= 9; number++) {
        if (validate(tab, row, col, number)) {
            tab[row][col] = number;
            if (calsudo(tab, row, col + 1)) {
                return 1;
            }
            tab[row][col] = 0;
        }
    }
    return 0;
}

int main() {
    int tab[ROWS][COLS] = {0};
    for (int k = 0; k < 9; k++){
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                printf("%d ", tab[i][j]);
            }
            printf("| ");
        }
        printf("\n");
        if (k == 2 || k == 5) {
            printf("------+-------+------\n");
        }
    }

    system("pause");
    return 0;
}

/*  int randomNumber = rand() % 9+ 1;
  printf("%d\n", randomNumber);
}*/