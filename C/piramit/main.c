#include <stdio.h>

int main() {
    int i, j, k, space, rows;

    printf("Piramidin boyutunu giriniz: ");
    scanf("%d", &rows);

    // Üst kýsým
    for (i = 1; i <= rows; ++i) {
        // Boþluklarý ekle
        for (space = 1; space <= rows - i; ++space) {
            printf("  ");
        }
        // Artan sýralý sayýlarý ekle
        for (j = 1; j <= i; ++j) {
            printf("%d ", j);
        }
        // Azalan sýralý sayýlarý ekle
        for (k = i - 1; k >= 1; --k) {
            printf("%d ", k);
        }
        printf("\n");
    }

    return 0;
}
