#include <stdio.h>

int main() {
    int a;
    int B[5] = {3, 6, 7, 9, 5}; //B[0] = 3, B[1] = 6
    //khai bao mang B
    //kích thước mảng 5
    //gán giá trị ban đầu
    float D[10] ;
    printf("\n");
    for(int i=0;i<5;i++)
    {
        printf("B[%d] = %d\n", i, B[i]);
    }
    return 0;
}
