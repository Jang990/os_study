public class MonitorPetersonSolution {
    public static void main(String[] args) throws InterruptedException {
        Thread plus = new Thread(new Plus());
        Thread minus = new Thread(new Minus());
        plus.start();
        minus.start();

        plus.join();
        minus.join();

        System.out.println("========================");
        System.out.println("기댓값 : 0 \t실제값 : " + sharedObject.result);
        System.out.println("========================");
    }
//    static int result = 0;
    static MyNumber sharedObject = new MyNumber();
    static int loopCnt = 20000;

    static class MyNumber {
        int result = 0;

        public int getResult() {
            return result;
        }

        void plus() {
            result++;
        }

        void minus() {
            result--;
        }
    }

    static class Minus implements Runnable {
        static final int id = 0;
        @Override
        public void run() {
            for (int i = 0; i < loopCnt; i++) {
                synchronized (sharedObject) {
                    sharedObject.minus();
                }
            }
        }
    }

    static class Plus implements Runnable {
        static final int id = 1;
        @Override
        public void run() {
            for (int i = 0; i < loopCnt; i++) {
                synchronized (sharedObject) {
                    sharedObject.plus();
                }
            }
        }
    }


}
