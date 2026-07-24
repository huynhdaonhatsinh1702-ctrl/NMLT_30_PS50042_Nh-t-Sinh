#include <stdio.h>
#include <math.h>

int main() {
    int chon;
    float diem;
    float a, b, c, delta, x1, x2;
    int kwh;
    double tien;

    do {
        printf("\n+---------------------------------------------+\n");
        printf("|           MENU CHUONG TRINH LAB 3           |\n");
        printf("+---------------------------------------------+\n");
        printf("| 1. Tinh hoc luc sinh vien                   |\n");
        printf("| 2. Giai phuong trinh bac hai                |\n");
        printf("| 3. Tinh tien dien tieu thu hang thang       |\n");
        printf("| 4. Thoat chuong trinh                       |\n");
        printf("+---------------------------------------------+\n");
        printf(">> Chon chuc nang (1-4): ");
        scanf("%d", &chon);

        switch (chon) {

        //================= CHUC NANG 1 =================
        case 1:
            printf("\nNhap diem sinh vien (0 - 10): ");
            scanf("%f", &diem);

            if (diem < 0 || diem > 10) {
                printf("Diem so nhap vao khong hop le!\n");
            } else if (diem >= 9.0) {
                printf("Hoc luc: Xuat sac\n");
            } else if (diem >= 8.0) {
                printf("Hoc luc: Gioi\n");
            } else if (diem >= 6.5) {
                printf("Hoc luc: Kha\n");
            } else if (diem >= 5.0) {
                printf("Hoc luc: Trung binh\n");
            } else if (diem >= 3.5) {
                printf("Hoc luc: Yeu\n");
            } else {
                printf("Hoc luc: Kem\n");
            }
            break;

        //================= CHUC NANG 2 =================
        case 2:
            printf("\nNhap a = ");
            scanf("%f", &a);
            printf("Nhap b = ");
            scanf("%f", &b);
            printf("Nhap c = ");
            scanf("%f", &c);

            if (a == 0) {
                if (b == 0) {
                    if (c == 0) {
                        printf("Phuong trinh co vo so nghiem.\n");
                    } else {
                        printf("Phuong trinh vo nghiem.\n");
                    }
                } else {
                    printf("Phuong trinh co nghiem x = %.2f\n", -c / b);
                }
            } else {
                delta = b * b - 4 * a * c;

                if (delta < 0) {
                    printf("Phuong trinh vo nghiem.\n");
                } else if (delta == 0) {
                    printf("Phuong trinh co nghiem kep x = %.2f\n", -b / (2 * a));
                } else {
                    x1 = (-b + sqrt(delta)) / (2 * a);
                    x2 = (-b - sqrt(delta)) / (2 * a);
                    printf("Phuong trinh co 2 nghiem:\n");
                    printf("x1 = %.2f\n", x1);
                    printf("x2 = %.2f\n", x2);
                }
            }
            break;

        //================= CHUC NANG 3 =================
        case 3:
            printf("\nNhap so kWh tieu thu: ");
            scanf("%d", &kwh);

            if (kwh < 0) {
                printf("So kWh khong hop le!\n");
            } else {
                if (kwh <= 50)
                    tien = kwh * 1678;
                else if (kwh <= 100)
                    tien = 50 * 1678 +
                           (kwh - 50) * 1734;
                else if (kwh <= 200)
                    tien = 50 * 1678 +
                           50 * 1734 +
                           (kwh - 100) * 2014;
                else if (kwh <= 300)
                    tien = 50 * 1678 +
                           50 * 1734 +
                           100 * 2014 +
                           (kwh - 200) * 2536;
                else if (kwh <= 400)
                    tien = 50 * 1678 +
                           50 * 1734 +
                           100 * 2014 +
                           100 * 2536 +
                           (kwh - 300) * 2834;
                else
                    tien = 50 * 1678 +
                           50 * 1734 +
                           100 * 2014 +
                           100 * 2536 +
                           100 * 2834 +
                           (kwh - 400) * 2927;

                printf("Tien dien phai tra: %.0lf VND\n", tien);
            }
            break;

        //================= THOAT =================
        case 4:
            printf("\nCam on ban da su dung chuong trinh!\n");
            break;

        default:
            printf("\nLua chon khong hop le! Vui long chon lai.\n");
        }

    } while (chon != 4);

    return 0;
}