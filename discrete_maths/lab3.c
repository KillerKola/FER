#include <stdbool.h>
#include <stdio.h>

static int brBoja = 0;

int obojaj(int *redak, int n) {
    int boja = 1;
    for (; boja <= n + 1; boja++) {
        if (boja > brBoja) {
            brBoja = boja;
        }
        for (size_t i = 0; i < n; i++) {
            if (*(redak + i) == boja) {
                break;
            }
            if (i == n - 1) {
                return boja;
            }
        }
    }
    return -1;
}

int main(void) {
    char ime[20];
    printf("Unesite ime datoteke: \n");
    scanf("%s", ime);

    FILE *ptr = fopen(ime, "r");

    int n, k;
    fscanf(ptr, "%d%d", &n, &k);

    printf("%d %d\n", n, k);
    int mat[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(ptr, "%1d", &mat[i][j]);
        }
    }

    int stupanj[n];

    for (int i = 0; i < n; i++) {
        stupanj[i] = 0;
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1) {
                stupanj[i]++;
            }
        }
    }

    int najveciStupanj = 0;
    int potpun = 1;
    int maxInd[n];
    for (int i = 0; i < n; i++) {
        maxInd[i] = i;
        if (stupanj[i] > najveciStupanj) {
            najveciStupanj = stupanj[i];
        }
        if (stupanj[i] != n - 1) {
            potpun = 0;
        }
    }

    int najveci;
    int indeks;
    int temp;
    for (int i = 0; i < n; i++) {
        najveci = stupanj[i];
        indeks = i;
        for (int j = i + 1; j < n; j++) {
            if (stupanj[j] > najveci) {
                najveci = stupanj[j];
                indeks = j;
            }
        }
        temp = stupanj[i];
        stupanj[i] = stupanj[indeks];
        stupanj[indeks] = temp;

        temp = maxInd[i];
        maxInd[i] = maxInd[indeks];
        maxInd[indeks] = temp;
    }

    if (((k >= najveciStupanj) && !potpun) || k > najveciStupanj) {
        printf("1");
    } else {
        int matBoja[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matBoja[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            matBoja[maxInd[i]][maxInd[i]] = obojaj(&matBoja[maxInd[i]][0], n);
            for (int j = 0; j < n; j++) {
                if (mat[j][maxInd[i]] == 1) {
                    matBoja[j][maxInd[i]] = matBoja[maxInd[i]][maxInd[i]];
                }
            }
        }
        if (brBoja <= k) {
            printf("1\n");
        } else {
            printf("0\n");
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", matBoja[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
