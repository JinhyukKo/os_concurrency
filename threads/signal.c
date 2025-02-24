#include <stdio.h>
#include <pthread.h>
static __thread int  tls_var = 0;  // TLS 변수

void* thread_func(void* arg) {
    tls_var++;  // TLS 변수 값 증가
    printf("Thread %ld: tls_var = %d\n", (long)pthread_self(), tls_var);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // 첫 번째 스레드 생성
    pthread_create(&thread1, NULL, thread_func, NULL);
    // 두 번째 스레드 생성
    pthread_create(&thread2, NULL, thread_func, NULL);

    // 스레드들이 끝날 때까지 기다리기
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Main thread: tls_var = %d\n", tls_var);

    return 0;
}
