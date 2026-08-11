#include <stdio.h>

int main() {
    int A [3] [6] = { 
        {1,2,3,4,5,6},
        {7,8,9,10,11,12}, 
        {13,14,15,16,17,18} 
        };
        // printf("A[%d,%d] =%d\n",2,2,A[2][2]);
        for(int i=0;i<3;i++){
            for(int j=0;j<6;j++){
                printf("A[%d,%d] = %d\n",i,j,A[i][j]);
            }
            printf("\n");
        }
    
    return 0;
    }
    
