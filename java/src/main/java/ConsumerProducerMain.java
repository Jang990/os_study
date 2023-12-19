

// 책에서 다루는 동시성 문제가 있는 : 생산자 - 소비자 모델
// 이 코드는 동시성 문제를 확인하기 어려우니 ConcurrentErrorJava.class에서 확인할 것.
public class ConsumerProducerMain {
    public static void main(String[] args) {
        buffer = new int[5];
        Thread consumer = new Thread(new Consumer());
        Thread producer = new Thread(new Producer());
        producer.start();
        consumer.start();
    }

    static int[] buffer;
    static int count = 0; // 동시성 오류 발생 가능.
    
    static class Consumer implements Runnable {
        int out = 0;
        @Override
        public void run() {
            while (true) {
                int stopCnt = 0;
                while (count == 0)
                    /* 이미 버퍼를 다 읽었으므로 생산자가 버퍼를 채우도록 대기 */;

                out = (out + 1) % buffer.length;
                count--;
            }
        }
    }

    static class Producer implements Runnable {
        int in = 0;
        int myNumber = 0;
        @Override
        public void run() {
            while (true) {
                int stopCnt = 0;

                while (count == buffer.length)
                    /* 이미 버퍼를 다 채웠으므로 소비자가 버퍼를 읽도록 대기 */;

                buffer[in] = myNumber++;
                in = (in + 1) % buffer.length;
                count++;
            }
        }
    }

}
