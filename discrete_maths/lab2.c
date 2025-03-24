#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 15

bool dfs(int mat[MAX_N][MAX_N], int n, int k, int current, int start, int depth,
         bool visited[MAX_N]) {
    if (depth == k) {
        return current == start;
    }

    visited[current] = true;
    for (int susjedni = 0; susjedni < n; susjedni++) {
        if (mat[current][susjedni]) {
            if (!visited[susjedni] || (depth + 1 == k && susjedni == start)) {
                if (dfs(mat, n, k, susjedni, start, depth + 1, visited)) {
                    return true;
                }
            }
        }
    }
    visited[current] = false;
    return false;
}

bool ima_ciklus(int mat[MAX_N][MAX_N], int n, int k) {
    for (int start = 0; start < n; start++) {
        bool visited[MAX_N] = {false};
        if (dfs(mat, n, k, start, start, 0, visited)) {
            return true;
        }
    }
    return false;
}

int main() {
    char filename[] = "";
    int n, k;
    int mat[MAX_N][MAX_N];

    printf("Unesite ime datoteke: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Datoteka '%s' nije pronađena.\n", filename);
        return false;
    }

    fscanf(file, "%d", &n);
    fscanf(file, "%d", &k);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            fscanf(file, " %c", &c);
            mat[i][j] = c - '0';
        }
    }

    fclose(file);

    int stupnjevi[n];
    for (int i = 0; i < n; i++) {
        stupnjevi[i] = 0;
        for (int j = 0; j < n; j++) {
            stupnjevi[i] += mat[i][j];
        }
    }

    int count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++) {
        if (stupnjevi[i] >= 2) {
            count1++;
        }
        if (stupnjevi[i] >= n / 2) {
            count2++;
        }
    }

    if (count1 < k || k > n) {
        printf("0");
    } else if (count2 >= k) {
        printf("1");
    } else {
        if (ima_ciklus(mat, n, k)) {
            printf("1");
        } else {
            printf("0");
        }
    }

    return 0;
}
