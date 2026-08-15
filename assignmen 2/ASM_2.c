#include <stdio.h>
#include <stdlib.h>

#define MAX 50

//================= CHỨC NĂNG 1 =================
void kiemTraSoNguyen() {
    float x;
    printf("\nNhap so: ");
    scanf("%f", &x);

    if (x == (int)x)
        printf("%.0f la so nguyen.\n", x);
    else
        printf("%.2f khong phai la so nguyen.\n", x);
}

//================= CHỨC NĂNG 2 =================
int UCLN(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return abs(a);
}

void timUCLNBCNN() {
    int a, b;
    printf("\nNhap a: ");
    scanf("%d", &a);
    printf("Nhap b: ");
    scanf("%d", &b);

    int ucln = UCLN(a, b);
    int bcnn = abs(a * b) / ucln;

    printf("UCLN = %d\n", ucln);
    printf("BCNN = %d\n", bcnn);
}

//================= CHỨC NĂNG 3 =================
void karaoke() {
    int gioBatDau, gioKetThuc;
    float tien;

    printf("\nNhap gio bat dau (12-23): ");
    scanf("%d", &gioBatDau);

    printf("Nhap gio ket thuc: ");
    scanf("%d", &gioKetThuc);

    int soGio = gioKetThuc - gioBatDau;

    tien = soGio * 150000;

    if (soGio > 3)
        tien -= (soGio - 3) * 150000 * 0.3;

    if (gioBatDau >= 14 && gioBatDau <= 17)
        tien *= 0.9;

    printf("Tong tien: %.0f VND\n", tien);
}

//================= CHỨC NĂNG 4 =================
void tinhTienDien() {

    float soDien, tien = 0;

    printf("\nNhap so kWh: ");
    scanf("%f", &soDien);

    if (soDien <= 50)
        tien = soDien * 1678;

    else if (soDien <= 100)
        tien = 50 * 1678 + (soDien - 50) * 1734;

    else if (soDien <= 200)
        tien = 50 * 1678 + 50 * 1734 + (soDien - 100) * 2014;

    else if (soDien <= 300)
        tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + (soDien - 200) * 2536;

    else if (soDien <= 400)
        tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + (soDien - 300) * 2834;

    else
        tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + 100 * 2834 + (soDien - 400) * 2927;

    printf("Tien dien = %.0f VND\n", tien);
}

//================= CHỨC NĂNG 6 =================
void laiSuat() {

    float tienVay = 500000000;
    float lai = 0.05 / 12;
    float goc = tienVay / 288;

    printf("\n%-5s %-15s %-15s %-15s %-15s\n",
           "Thang", "Goc", "Lai", "Tong Tra", "Con Lai");

    for (int i = 1; i <= 288; i++) {

        float laiThang = tienVay * lai;
        float tong = goc + laiThang;

        tienVay -= goc;

        printf("%-5d %-15.0f %-15.0f %-15.0f %-15.0f\n",
               i, goc, laiThang, tong, tienVay);
    }
}

//================= CHỨC NĂNG 8 =================

struct SinhVien {
    char ten[30];
    float diem;
};

void sapXepSinhVien() {

    int n;

    printf("\nNhap so sinh vien: ");
    scanf("%d", &n);

    struct SinhVien ds[MAX];

    for (int i = 0; i < n; i++) {
        printf("\nSinh vien %d\n", i + 1);

        printf("Ten: ");
        scanf(" %[^\n]", ds[i].ten);

        printf("Diem: ");
        scanf("%f", &ds[i].diem);
    }
for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (ds[i].diem < ds[j].diem) {

                struct SinhVien temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }

    printf("\n===== DANH SACH =====\n");

    for (int i = 0; i < n; i++) {

        printf("%-25s %.2f\n", ds[i].ten, ds[i].diem);
    }
}

//================= CHỨC NĂNG 10 =================

typedef struct {
    int tu;
    int mau;
} PhanSo;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return abs(a);
}

void rutGon(PhanSo *p) {

    int u = gcd(p->tu, p->mau);

    p->tu /= u;
    p->mau /= u;
}

void tinhPhanSo() {

    PhanSo a, b, tong;

    printf("\nNhap phan so thu nhat:\n");
    scanf("%d%d", &a.tu, &a.mau);

    printf("Nhap phan so thu hai:\n");
    scanf("%d%d", &b.tu, &b.mau);

    tong.tu = a.tu * b.mau + b.tu * a.mau;
    tong.mau = a.mau * b.mau;

    rutGon(&tong);

    printf("Tong = %d/%d\n", tong.tu, tong.mau);
}

//================= MENU =================

int main() {

    int chon;

    do {

        printf("\n================ MENU ================\n");
        printf("1. Kiem tra so nguyen\n");
        printf("2. Tim UCLN - BCNN\n");
        printf("3. Tinh tien Karaoke\n");
        printf("4. Tinh tien dien\n");
        printf("5. Tinh lai suat vay tra gop\n");
        printf("6. Sap xep sinh vien\n");
        printf("7. Tinh toan phan so\n");
        printf("0. Thoat\n");

        printf("\nNhap lua chon: ");
        scanf("%d", &chon);

        switch (chon) {

        case 1:
            kiemTraSoNguyen();
            break;

        case 2:
            timUCLNBCNN();
            break;

        case 3:
            karaoke();
            break;

        case 4:
            tinhTienDien();
            break;

        case 5:
            laiSuat();
            break;

        case 6:
            sapXepSinhVien();
            break;

        case 7:
            tinhPhanSo();
            break;

        case 0:
            printf("\nTam biet!\n");
            break;

        default:
            printf("\nLua chon khong hop le!\n");
        }

    } while (chon != 0);

    return 0;
}