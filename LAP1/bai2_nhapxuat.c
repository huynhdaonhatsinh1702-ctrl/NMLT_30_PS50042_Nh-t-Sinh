#include <stdio.h>

int main() {
    char mssv[9];        // 7 ký tự + 1 ký tự dự phòng + null terminator
    char hoten[100];
    int namsinh;
    float diemtb;
    int tuoi;

    // Nhập dữ liệu
    printf("Nhap ma so sinh vien (MSSV): ");
    scanf("%8s", mssv);                    // Giới hạn 8 ký tự (7 + 1)

    printf("Nhap ho va ten: ");
    getchar();                             // Xóa ký tự newline còn sót
    fgets(hoten, sizeof(hoten), stdin);
    
    // Xóa ký tự newline ở cuối nếu có
    for(int i = 0; hoten[i] != '\0'; i++) {
        if(hoten[i] == '\n') {
            hoten[i] = '\0';
            break;
        }
    }

    printf("Nhap nam sinh: ");
    scanf("%d", &namsinh);

    printf("Nhap diem trung binh: ");
    scanf("%f", &diemtb);

    // Tính tuổi theo yêu cầu (2026 - năm sinh)
    tuoi = 2026 - namsinh;

    // Xuất theo đúng định dạng mẫu
    printf("\n");
    printf("====================================\n");
    printf("FPT Education\n");
    printf("NHAP MON LAP TRINH\n\n");
    
    printf("Ma so sinh vien: %s\n", mssv);
    printf("Ho Va Ten: %s\n", hoten);
    printf("Nam sinh: %d\n", namsinh);
    printf("Tuoi: %d\n", tuoi);
    printf("Diem Trung Binh: %.2f\n", diemtb);
    printf("====================================\n");

    return 0;
}
