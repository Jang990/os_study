public class ConcurrentErrorJava {
    public static void main(String[] args) throws InterruptedException {
        Thread plus = new Thread(new Plus());
        Thread minus = new Thread(new Minus());
        plus.start();
        minus.start();

        Thread.sleep(1000);
        System.out.println("========================");
        System.out.println("기댓값 : 0 \t실제값 : " + result);
        System.out.println("========================");
    }
    static int result = 0;
    static int loopCnt = 10000;

    static class Minus implements Runnable {
        @Override
        public void run() {
            for (int i = 0; i < loopCnt; i++) {
                result--;
            }
        }
    }

    static class Plus implements Runnable {
        @Override
        public void run() {
            for (int i = 0; i < loopCnt; i++) {
                result++;
            }
        }
    }


}
