#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *thread_function(void *arg) {
    printf("스레드 실행 중! (Thread ID: %ld)\n", pthread_self());
    sleep(5); // 스레드가 오래 실행되도록 대기
    printf("스레드 실행 종료! (Thread ID: %ld)\n", pthread_self());
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // 스레드 2개 생성
    pthread_create(&t1, NULL, thread_function, NULL);
    pthread_create(&t2, NULL, thread_function, NULL);

    sleep(1); // 모든 스레드가 실행될 시간을 줌

    printf("부모 프로세스에서 fork() 호출!\n");

    pid_t pid = fork();

    if (pid == 0) { // 자식 프로세스
        printf("자식 프로세스 실행! (PID: %d)\n", getpid());
        sleep(3);
    } else { // 부모 프로세스
        printf("부모 프로세스 실행 중! (PID: %d)\n", getpid());
    }

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
