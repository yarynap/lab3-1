#include <stdio.h>
#define n 5
void bul(int a[n][n]);
int f(int a[n][n], int x);
int main(void) {
    int i,j,k;
    static int a[n][n];
    for (i = 0; i < n; i++){

        for (j = 0; j < n; j++){
            printf("a[%d][%d] = ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
    printf("old array\n");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++)

            printf ("%5d", a[i][j]);
        printf("\n");

    }

    bul(a);
    printf("\nnew array\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf ("%5d", a[i][j]);

        }

        printf("\n");

    }

    double r = 0;
    for (int i = 0; i < 4; i++)     {
        int x = f(a,i);
        printf("%d ", x);
        r += x;     }
        printf("\n%lf\n", r / 4.0);

}


void bul(int a[ ][n]) {     int i, k, j, c;

    for(i = 0; i < n; i++) {

        for(k = n - 1; k >= 0; k--) {

            for(j = 0; j < k; j++) {
                if(a[i][j] < a[i][j+1]) {
                    c = a[i][j];
                    a[i][j] = a[i][j+1];
                    a[i][j+1] =c;
                }
            }
        }
    }

}

int f(int a[n][n], int x) {
    int r = 1;
    for (int i = x + 1; i < 5; i++)
        r *= a[i][x];
}