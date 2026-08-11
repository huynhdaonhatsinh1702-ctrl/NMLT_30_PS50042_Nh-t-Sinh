#include <stdio.h>
#include <string.h>

// --- KHAI BÁO CÁC NGUYÊN MẪU HÀM ---
void demNguyenAmPhuAm();
void dangNhapHeThong();
void sapXepChuoiAlphabet();
void chuyenDoiThapPhanNhiPhan();

// --- HÀM MAIN CHÍNH ---
int main() {
    int luaChon;

    do {
        // Hien thi giao dien Menu
        printf("+---------------------------------------------------+\n");
        printf("|              MENU CHUONG TRINH LAB 7              |\n");
        printf("+---------------------------------------------------+\n");
        printf("| 1. Dem Nguyen am va Phu am trong chuoi            |\n");
        printf("| 2. Dang nhap he thong (User & Password)           |\n");
        printf("| 3. Sap xep danh sach Chuoi theo Alphabet          |\n");
        printf("| 4. Chuyen doi so Thap phan sang Nhi phan (Chuoi)  |\n");
        printf("| 5. Thoat chuong trinh                             |\n");
        printf("+---------------------------------------------------+\n");
        printf(">> Xin moi chon chuc nang (1-5): ");
        scanf("%d", &luaChon);

        // Xoa bo nho dem de tranh loi
        while (getchar() != '\n'); 

        // Cau truc dieu khien switch-case
        switch (luaChon) {
            case 1:
                demNguyenAmPhuAm();
                break;
            case 2:
                dangNhapHeThong();
                break;
            case 3:
                sapXepChuoiAlphabet();
                break;
            case 4:
                chuyenDoiThapPhanNhiPhan();
                break;
            case 5:
                printf("\nThoat chuong trinh. Tam biet!\n");
                break;
            default:
                printf("\nLua chon khong hop le! Vui long chon lai.\n\n");
        }
    } while (luaChon != 5);

    return 0;
}