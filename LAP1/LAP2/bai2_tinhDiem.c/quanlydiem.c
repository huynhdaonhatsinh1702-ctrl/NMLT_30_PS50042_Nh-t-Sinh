#include <stdio.h>

int main() {
    // Khai báo biến điểm số cho 3 môn
    float toan, ly, hoa;
    float diemTrungBinh;

    // Nhập dữ liệu từ bàn phím
    printf("Nhap diem mon Toan: ");
    scanf("%f", &toan);

    printf("Nhap diem mon Ly: ");
    scanf("%f", &ly);

    printf("Nhap diem mon Hoa: ");
    scanf("%f", &hoa);

    // Tính điểm trung bình theo hệ số (Toán nhân 3, Lý nhân 2, Hóa nhân 1)
    // Ép kiểu (float) ở tử số để đảm bảo phép chia ra số thập phân chính xác
    diemTrungBinh = (float)(toan * 3 + ly * 2 + hoa) / 6;

    // Hiển thị kết quả làm tròn 2 chữ số sau dấu phẩy (%.2f)
    printf("\nDiem trung binh cua sinh vien la: %.2f\n", diemTrungBinh);

    return 0;
}