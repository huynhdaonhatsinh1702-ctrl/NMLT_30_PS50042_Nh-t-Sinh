#include <stdio.h>
#include <math.h>
#include <string.h>

// Struct dùng cho Chức năng 6 (Sắp xếp sinh viên)
typedef struct {
    char ten[50];
    float diem;
} SinhVien;

// Struct dùng cho Chức năng 7 (Phân số)
typedef struct {
    int tu;
    int mau;
} PhanSo;

// Khai báo các hàm chức năng
void chucNang1();
void chucNang2();
void chucNang3();
void chucNang4();
void chucNang5();
void chucNang6();
void chucNang7();

// Hàm tìm UCLN dùng chung
int timUCLN(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    int chon;

    do {
        printf("\n+-----------------------------------------------------------+\n");
        printf("|                     MENU CHUONG TRINH                     |\n");
        printf("+-----------------------------------------------------------+\n");
        printf("| 1. Kiem tra so nguyen                                     |\n");
        printf("| 2. Tim Uoc so chung va Boi so chung cua 2 so             |\n");
        printf("| 3. Chuong trinh tinh tien cho quan Karaoke                |\n");
        printf("| 4. Tinh tien dien                                         |\n");
        printf("| 5. Tinh lai suat vay ngan hang (tra gop)                  |\n");
        printf("| 6. Sap xep thong tin sinh vien                            |\n");
        printf("| 7. Tinh toan phan so                                      |\n");
        printf("| 0. Thoat                                                  |\n");
        printf("+-----------------------------------------------------------+\n");
        printf(">> Chon chuc nang cua ban (0-7): ");
        scanf("%d", &chon);

        switch (chon) {
            case 1:
                chucNang1();
                break;
            case 2:
                chucNang2();
                break;
            case 3:
                chucNang3();
                break;
            case 4:
                chucNang4();
                break;
            case 5:
                chucNang5();
                break;
            case 6:
                chucNang6();
                break;
            case 7:
                chucNang7();
                break;
            case 0:
                printf("\nCam on ban da su dung chuong trinh. Tam biet!\n");
                break;
            default:
                printf("\nLoi: Chuc nang khong hop le. Vui long chon lai (0-7)!\n");
        }
    } while (chon != 0);

    return 0;
}

// -------------------------------------------------------------
// CHỨC NĂNG 1: Kiểm tra số nguyên
// -------------------------------------------------------------
void chucNang1() {
    float x;
    printf("\n--- CHUC NANG 1: KIEM TRA SO NGUYEN ---\n");
    printf("Nhap vao mot so x: ");
    scanf("%f", &x);

    // Kiem tra so nguyen
    if (x == (int)x) {
        printf("%.2f la so nguyen.\n", x);

        int n = (int)x;
        // Kiem tra so nguyen to
        if (n < 2) {
            printf("%d khong phai la so nguyen to.\n", n);
        } else {
            int laSoNguyenTo = 1;
            for (int i = 2; i <= sqrt(n); i++) {
                if (n % i == 0) {
                    laSoNguyenTo = 0;
                    break;
                }
            }
            if (laSoNguyenTo) {
                printf("%d la so nguyen to.\n", n);
            } else {
                printf("%d khong phai la so nguyen to.\n", n);
            }
        }

        // Kiem tra so chinh phuong
        int căn = sqrt(n);
        if (căn * căn == n) {
            printf("%d la so chinh phuong.\n", n);
        } else {
            printf("%d khong phai la so chinh phuong.\n", n);
        }
    } else {
        printf("%.2f KHONG phai la so nguyen.\n", x);
    }
}

// -------------------------------------------------------------
// CHỨC NĂNG 2: Tìm ƯỚC SỐ CHUNG và BỘI SỐ CHUNG của 2 số
// -------------------------------------------------------------
void chucNang2() {
    int a, b;
    printf("\n--- CHUC NANG 2: TIM UCLN VA BCNN ---\n");
    printf("Nhap so a: ");
    scanf("%d", &a);
    printf("Nhap so b: ");
    scanf("%d", &b);

    if (a == 0 && b == 0) {
        printf("Khong co UCLN va BCNN cho hai so 0!\n");
        return;
    }

    int ucln = timUCLN(a, b);
    long long bcnn = ((long long)abs(a) * abs(b)) / ucln;

    printf("Uoc so chung lon nhat (UCLN) cua %d va %d la: %d\n", a, b, ucln);
    printf("Boi so chung nho nhat (BCNN) cua %d va %d la: %lld\n", a, b, bcnn);
}

// -------------------------------------------------------------
// CHỨC NĂNG 3: Chương trình tính tiền cho quán Karaoke
// -------------------------------------------------------------
void chucNang3() {
    int gioBatDau, gioKetThuc;
    printf("\n--- CHUC NANG 3: TINH TIEN KARAOKE ---\n");
    printf("Nhap gio bat dau (12 - 23): ");
    scanf("%d", &gioBatDau);
    printf("Nhap gio ket thuc (12 - 23): ");
    scanf("%d", &gioKetThuc);

    if (gioBatDau < 12 || gioKetThuc > 23 || gioBatDau >= gioKetThuc) {
        printf("Gio nhap vao khong hop le! Quan chi mo cua tu 12h den 23h.\n");
        return;
    }

    int tongGio = gioKetThuc - gioBatDau;
    double tongTien = 0;

    if (tongGio <= 3) {
        tongTien = tongGio * 150000;
    } else {
        tongTien = 3 * 150000 + (tongGio - 3) * (150000 * 0.7);
    }

    // Giam gia 10% neu bat dau trong khoang 14h -> 17h
    if (gioBatDau >= 14 && gioBatDau <= 17) {
        tongTien = tongTien * 0.9;
    }

    printf("Tong tien karaoke phai thanh toan: %.0f VNĐ\n", tongTien);
}

// -------------------------------------------------------------
// CHỨC NĂNG 4: Tính tiền điện
// -------------------------------------------------------------
void chucNang4() {
    float kwh;
    double tongTien = 0;
    printf("\n--- CHUC NANG 4: TINH TIEN DIEN ---\n");
    printf("Nhap so kWh dien da su dung: ");
    scanf("%f", &kwh);

    if (kwh < 0) {
        printf("So kWh khong duoc am!\n");
        return;
    }

    // Tinh theo bac thang
    if (kwh <= 50) {
        tongTien = kwh * 1678;
    } else if (kwh <= 100) {
        tongTien = 50 * 1678 + (kwh - 50) * 1734;
    } else if (kwh <= 200) {
        tongTien = 50 * 1678 + 50 * 1734 + (kwh - 100) * 2014;
    } else if (kwh <= 300) {
        tongTien = 50 * 1678 + 50 * 1734 + 100 * 2014 + (kwh - 200) * 2536;
    } else if (kwh <= 400) {
        tongTien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + (kwh - 300) * 2834;
    } else {
        tongTien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + 100 * 2834 + (kwh - 400) * 2927;
    }

    printf("Tong tien dien phai trả: %.0f VNĐ\n", tongTien);
}

// -------------------------------------------------------------
// CHỨC NĂNG 5: Tính lãi suất vay ngân hàng (trả góp)
// -------------------------------------------------------------
void chucNang5() {
    double soTienVay;
    printf("\n--- CHUC NANG 5: TINH LAI SUAT VAY NGAN HANG ---\n");
    printf("Nhap so tien muon vay (VND): ");
    scanf("%lf", &soTienVay);

    double laiSuatThang = 0.05; // 5% moi thang
    int sohThang = 12;
    double tienGocThang = soTienVay / sohThang;
    double soDuConLai = soTienVay;

    printf("\n%-10s %-15s %-15s %-15s %-15s\n", "Thang", "Lai phai tra", "Goc phai tra", "Tong phai tra", "So du con lai");
    printf("---------------------------------------------------------------------------\n");

    for (int i = 1; i <= sohThang; i++) {
        double tienLaiThang = soDuConLai * laiSuatThang;
        double tongPhaiTraThang = tienGocThang + tienLaiThang;
        soDuConLai -= tienGocThang;

        printf("%-10d %-15.0f %-15.0f %-15.0f %-15.0f\n", i, tienLaiThang, tienGocThang, tongPhaiTraThang, (soDuConLai < 0 ? 0 : soDuConLai));
    }
}

// -------------------------------------------------------------
// CHỨC NĂNG 6: Sắp xếp thông tin sinh viên
// -------------------------------------------------------------
void chucNang6() {
    int n;
    printf("\n--- CHUC NANG 6: SAP XEP THONG TIN SINH VIEN ---\n");
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    getchar(); // Xoa bo nho dem

    SinhVien ds[100];

    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin sinh vien thu %d:\n", i + 1);
        printf("Ho va ten: ");
        fgets(ds[i].ten, sizeof(ds[i].ten), stdin);
        ds[i].ten[strcspn(ds[i].ten, "\n")] = 0; // Xoa ky tu xuong dong

        printf("Diem trung binh: ");
        scanf("%f", &ds[i].diem);
        getchar();
    }

    // Thuat toan Sap xep noi bot (Bubble Sort) giam dan theo diem
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].diem < ds[j].diem) {
                SinhVien temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }

    printf("\nDANH SACH SINH VIEN SAU KHI SAP XEP (GIAM DAN THEO DIEM):\n");
    printf("%-25s %-10s %-15s\n", "Ho Ten", "Diem", "Hoc Luc");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        char hocLuc[20];
        if (ds[i].diem >= 9.0) strcpy(hocLuc, "Xuat sac");
        else if (ds[i].diem >= 8.0) strcpy(hocLuc, "Gioi");
        else if (ds[i].diem >= 6.5) strcpy(hocLuc, "Kha");
        else if (ds[i].diem >= 5.0) strcpy(hocLuc, "Trung binh");
        else strcpy(hocLuc, "Yeu");

        printf("%-25s %-10.1f %-15s\n", ds[i].ten, ds[i].diem, hocLuc);
    }
}

// -------------------------------------------------------------
// CHỨC NĂNG 7: Tính toán phân số
// -------------------------------------------------------------
void rutGonPhanSo(PhanSo *ps) {
    int ucln = timUCLN(ps->tu, ps->mau);
    ps->tu /= ucln;
    ps->mau /= ucln;
    if (ps->mau < 0) { // Dua dau am len tu so neu mau am
        ps->tu = -ps->tu;
        ps->mau = -ps->mau;
    }
}

void chucNang7() {
    PhanSo p1, p2;
    printf("\n--- CHUC NANG 7: TINH TOAN PHAN SO ---\n");
    printf("Nhap phan so 1 (tu mau): ");
    scanf("%d %d", &p1.tu, &p1.mau);
    printf("Nhap phan so 2 (tu mau): ");
    scanf("%d %d", &p2.tu, &p2.mau);

    if (p1.mau == 0 || p2.mau == 0) {
        printf("Mau so phai khac 0!\n");
        return;
    }

    // Tong
    PhanSo tong = {p1.tu * p2.mau + p2.tu * p1.mau, p1.mau * p2.mau};
    rutGonPhanSo(&tong);

    // Hieu
    PhanSo hieu = {p1.tu * p2.mau - p2.tu * p1.mau, p1.mau * p2.mau};
    rutGonPhanSo(&hieu);

    // Tich
    PhanSo tich = {p1.tu * p2.tu, p1.mau * p2.mau};
    rutGonPhanSo(&tich);

    // Thuong
    if (p2.tu == 0) {
        printf("Khong the thuc hien phep chia vi tu so phan so 2 bang 0!\n");
    } else {
        PhanSo thuong = {p1.tu * p2.mau, p1.mau * p2.tu};
        rutGonPhanSo(&thuong);
        printf("Thuong: %d/%d\n", thuong.tu, thuong.mau);
    }

    printf("Tong:   %d/%d\n", tong.tu, tong.mau);
    printf("Hieu:   %d/%d\n", hieu.tu, hieu.mau);
    printf("Tich:   %d/%d\n", tich.tu, tich.mau);
}