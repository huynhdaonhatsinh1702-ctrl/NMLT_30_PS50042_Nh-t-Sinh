#include <stdio.h>

int main() {
    float toan, ly, hoa;
    float diemTrungBinh;

    // Nhập điểm số 3 môn từ bàn phím
    printf("Nhap diem mon Toan: ");
    scanf("%f", &toan);

    printf("Nhap diem mon Ly: ");
    scanf("%f", &ly);

    printf("Nhap diem mon Hoa: ");
    scanf("%f", &hoa);

    // Tính điểm trung bình và áp dụng ép kiểu dữ liệu sang float
    // Việc chia cho số thực 6.0 hoặc ép kiểu (float) giúp tránh lỗi chia hai số nguyên
    diemTrungBinh = (float)(toan * 3 + ly * 2 + hoa) / 6;

    // Hiển thị điểm trung bình làm tròn 2 chữ số sau dấu phẩy
    printf("Diem trung binh: %.2f\n", diemTrungBinh);

    return 0;
}