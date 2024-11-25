#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 9
#define Q 3

int main(void) {
    srand(time(NULL));

    int source[Q][Q + 2];
    int target[N][N] = {0};

    for (int i = 0; i < Q; i++) {
        for (int j = 1; j < Q + 1; j++) {
            source[i][j] = rand() % N;
        }

        source[i][0] = source[i][1];
        source[i][Q + 1] = source[i][Q];
    }

    puts("Source:");
    for (int i = 0; i < Q; i++) {
        for (int j = 0; j < Q + 2; j++) {
            printf("%02d ", source[i][j]);
            if (j == 0 || j == Q) {
                printf("| ");
            }
        }
        
        printf("\n");
    }

    puts("\nPares de Source:");
    for (int i = 0; i < Q; i++) {
        for (int j = 0; j < Q + 1; j++) {
            int x = source[i][j];
            int y = source[i][j + 1];

            printf("x = %d, y = %d\n", x, y);
            target[x][y]++;
        }
    }

    puts("\nTarget:");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%02d ", target[i][j]);
        }

        printf("\n");
    }

    return 0;
}
