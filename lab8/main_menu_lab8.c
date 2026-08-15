#include <stdio.h>
#include <string.h>

#define MAX_SV 100

struct SinhVien {
    char mssv[50];
    char tenSV[50];
    char nganhHoc[50];
    float diemTB;
};

void nhapXuatSinhVien(struct SinhVien mangSV[], int *n);
void sapXepSinhVien(struct SinhVien mangSV[], int n);
void timKiemSinhVien(struct SinhVien mangSV[], int n);
void xuatHocBong(struct SinhVien mangSV[], int n);
void inTieuDeDanhSach(void);

int main() {
    struct SinhVien mangSV[MAX_SV];
    int n = 0;
    int chon;

    do {
        printf("\n+---------------------------------------------------+\n");
        printf("|       HE THONG QUAN LY SINH VIEN (LAB 8)         |\n");
        printf("+---------------------------------------------------+\n");
        printf("| 1. Nhap va Xuat danh sach sinh vien              |\n");
        printf("| 2. Sap xep sinh vien theo diem TB tang dan       |\n");
        printf("| 3. Tim kiem sinh vien theo MSSV                  |\n");
        printf("| 4. Xuat danh sach sinh vien dat Hoc bong         |\n");
        printf("| 5. Thoat chuong trinh                            |\n");
        printf("+---------------------------------------------------+\n");
        printf(">> Xin moi chon chuc nang (1-5): ");
        scanf("%d", &chon);

        switch (chon) {
            case 1:
                nhapXuatSinhVien(mangSV, &n);
                break;
            case 2:
                if (n == 0) {
                    printf("\nChua co du lieu sinh vien. Hay chon chuc nang 1 truoc.\n");
                } else {
                    sapXepSinhVien(mangSV, n);
                }
                break;
            case 3:
                if (n == 0) {
                    printf("\nChua co du lieu sinh vien. Hay chon chuc nang 1 truoc.\n");
                } else {
                    timKiemSinhVien(mangSV, n);
                }
                break;
            case 4:
                if (n == 0) {
                    printf("\nChua co du lieu sinh vien. Hay chon chuc nang 1 truoc.\n");
                } else {
                    xuatHocBong(mangSV, n);
                }
                break;
            case 5:
                printf("\nDang thoat chuong trinh... Cam on ban da su dung!\n");
                break;
            default:
                printf("\nLua chon khong hop le. Vui long chon tu 1 den 5.\n");
                break;
        }
    } while (chon != 5);

    return 0;
}

void inTieuDeDanhSach(void) {
    printf("\n+-----+--------------------+----------------------+-----------+\n");
    printf("| STT | MSSV               | Ten SV               | Nganh     | Diem TB |\n");
    printf("+-----+--------------------+----------------------+-----------+--------+\n");
}

void nhapXuatSinhVien(struct SinhVien mangSV[], int *n) {
    int i;

    printf("\nNhap so luong sinh vien (1-%d): ", MAX_SV);
    scanf("%d", n);

    while (*n < 1 || *n > MAX_SV) {
        printf("So luong khong hop le. Vui long nhap lai (1-%d): ", MAX_SV);
scanf("%d", n);
    }

    for (i = 0; i < *n; i++) {
        printf("\nSinh vien thu %d\n", i + 1);
        printf("Nhap MSSV: ");
        scanf("%s", mangSV[i].mssv);
        printf("Nhap ho va ten: ");
        scanf("%s", mangSV[i].tenSV);
        printf("Nhap nganh hoc: ");
        scanf("%s", mangSV[i].nganhHoc);
        printf("Nhap diem trung binh: ");
        scanf("%f", &mangSV[i].diemTB);
    }

    printf("\nDanh sach sinh vien da nhap:\n");
    inTieuDeDanhSach();
    for (i = 0; i < *n; i++) {
        printf("| %-3d | %-18s | %-20s | %-9s | %-6.2f |\n",
               i + 1,
               mangSV[i].mssv,
               mangSV[i].tenSV,
               mangSV[i].nganhHoc,
               mangSV[i].diemTB);
    }
    printf("+-----+--------------------+----------------------+-----------+--------+\n");
}

void sapXepSinhVien(struct SinhVien mangSV[], int n) {
    int i, j;
    struct SinhVien temp;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (mangSV[i].diemTB > mangSV[j].diemTB) {
                temp = mangSV[i];
                mangSV[i] = mangSV[j];
                mangSV[j] = temp;
            }
        }
    }

    printf("\nDanh sach sinh vien sau khi sap xep theo diem TB tang dan:\n");
    inTieuDeDanhSach();
    for (i = 0; i < n; i++) {
        printf("| %-3d | %-18s | %-20s | %-9s | %-6.2f |\n",
               i + 1,
               mangSV[i].mssv,
               mangSV[i].tenSV,
               mangSV[i].nganhHoc,
               mangSV[i].diemTB);
    }
    printf("+-----+--------------------+----------------------+-----------+--------+\n");
}

void timKiemSinhVien(struct SinhVien mangSV[], int n) {
    char mssvTim[50];
    int i;
    int found = 0;

    printf("\nNhap MSSV can tim: ");
    scanf("%s", mssvTim);

    for (i = 0; i < n; i++) {
        if (strcmp(mangSV[i].mssv, mssvTim) == 0) {
            printf("\nTim thay sinh vien:\n");
            printf("MSSV: %s\n", mangSV[i].mssv);
            printf("Ho va ten: %s\n", mangSV[i].tenSV);
            printf("Nganh hoc: %s\n", mangSV[i].nganhHoc);
            printf("Diem TB: %.2f\n", mangSV[i].diemTB);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nKhong tim thay sinh vien co MSSV nay!\n");
    }
}

void xuatHocBong(struct SinhVien mangSV[], int n) {
    int i;
    int coHocBong = 0;

    printf("\nDanh sach sinh vien dat hoc bong (diem TB >= 8.0):\n");
    inTieuDeDanhSach();

    for (i = 0; i < n; i++) {
        if (mangSV[i].diemTB >= 8.0) {
            printf("| %-3d | %-18s | %-20s | %-9s | %-6.2f |\n",
                   i + 1,
                   mangSV[i].mssv,
                   mangSV[i].tenSV,
                   mangSV[i].nganhHoc,
                   mangSV[i].diemTB);
            coHocBong = 1;
        }
    }

    printf("+-----+--------------------+----------------------+-----------+--------+\n");

    if (!coHocBong) {
printf("\nKhong co sinh vien nao dat hoc bong (diem TB >= 8.0).\n");
    }
}
