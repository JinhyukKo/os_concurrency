#include <stdio.h>
#include <omp.h>

#define SIZE 1000000

int main() {
    // int arr[SIZE];
    // long long sum = 0;
    //
    // // 배열 초기화
    // for (int i = 0; i < SIZE; i++) {
    //     arr[i] = 1;  // 모든 값에 1을 대입
    // }

    #pragma omp parallel for
    for (int i = 0; i < 20; i++) {
        printf("%d\n",i);
    }

    printf("Sequential \n");

    return 0;
}
