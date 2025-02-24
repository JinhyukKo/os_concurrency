public class threadpool {

    public static void main(String[] args) {
        // 새로운 스레드 생성
        Thread worker = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    // 작업을 반복하면서 인터럽트 상태를 확인
                    while (!Thread.currentThread().isInterrupted()) {
                        // 간단한 작업 (예: 1초마다 출력)
                        System.out.println("Working...");
                        Thread.sleep(1000); // 1초 대기
                    }
                } catch (InterruptedException e) {
                    // InterruptedException이 발생하면, 스레드가 인터럽트 된 것
                    System.out.println("Thread was interrupted.");
                }
            }
        });

        // 스레드 시작
        worker.start();

        // 5초 후 스레드 인터럽트
        try {
            Thread.sleep(5000);  // 5초 대기
            worker.interrupt();  // worker 스레드에 인터럽트 신호 전송
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
