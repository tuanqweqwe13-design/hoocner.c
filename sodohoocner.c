#include <stdio.h>
#define MAX 1000

void sodohoocner(double a[], int n, double c) {
    double b[MAX + 1];
    double ketqua[MAX + 1];
    
    for (int i = 0; i <= n; i++) b[i] = a[i];

    printf("\n%-10s |", "P(x)");
    for (int i = 0; i <= n; i++) printf("%10.2f", a[i]);
    printf("\n-----------+---------------------------------------------------------------------\n");

    for (int step = 0; step <= n; step++) {
        int bachientai = n - step;
        
        if (step < n) printf("P%-2d(x) [%.0f]|", step + 1, c);
        else printf("P%-2d(*)    |", step + 1);
        
        for (int i = 1; i <= bachientai; i++) {
            b[i] = b[i] + b[i-1] * c;
        }

        for (int i = 0; i <= bachientai; i++) {
            if (i == bachientai) printf("[%9.2f]", b[i]); 
            else printf("%10.2f", b[i]);
        }
        
        ketqua[step] = b[bachientai];
        printf("  (y^%d)\n", step);

        printf("           | ");
        for (int k = 0; k <= bachientai; k++) printf("----------");
        printf("\n");
    }

    int timheso;
    char tieptuctim;
    
    do {
        printf("\nBan muon xem he so cua y bac may? (0 den %d): ", n);
        scanf("%d", &timheso);
        if (timheso >= 0 && timheso <= n) {
            printf("=> He so cua y^%d la: %.2f\n", timheso, ketqua[timheso]);
        } else {
            printf("=> Bac khong hop le!\n");
        }
        printf("Co muon xem he so khac cua P(y) khong? (y/n): ");
        scanf(" %c", &tieptuctim);
    } while (tieptuctim == 'y' || tieptuctim == 'Y');

    printf("\n=> P(y) = ");
    for (int i = n; i >= 0; i--) {
        if (ketqua[i] != 0) {
            printf("%+.2fy^%d ", ketqua[i], i);
        }
    }
    printf("\n");
}

int main() {
    int choice, n;
    double a[MAX + 1];
    double c;
    char tieptuc;
    double mau[] = {2, 4, 0, 0, -1, 1, 2}; 

    do {
        printf("\n============================================\n");
        printf("1. Chay ham mau: 2x^6 + 4x^5 - x^2 + x + 2\n");
        printf("2. Nhap ham moi\n");
        printf("3. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        if (choice == 3) break;

        if (choice < 1 || choice > 2) {
            printf("Lua chon khong hop le!\n");
            continue;
        }

        if (choice == 1) {
            n = 6;
            for(int i = 0; i <= n; i++) a[i] = mau[i];
        } else {
            printf("Nhap bac cua da thuc n: ");
            scanf("%d", &n);
            if (n > MAX) n = MAX;
            for (int i = 0; i <= n; i++) {
                printf("He so x^%d: ", n - i);
                scanf("%lf", &a[i]);
            }
        }

        do {
            printf("\nNhap gia tri c: ");
            scanf("%lf", &c);
            sodohoocner(a, n, c);

            printf("\nBan co muon thu gia tri c khac cho ham nay khong? (y/n): ");
            scanf(" %c", &tieptuc);
        } while (tieptuc == 'y' || tieptuc == 'Y');

        printf("\nBan co muon doi ham khac hoac quay lai menu khong? (y/n): ");
        scanf(" %c", &tieptuc);

    } while (tieptuc == 'y' || tieptuc == 'Y');

    printf("Tam biet!\n");
    return 0;
}