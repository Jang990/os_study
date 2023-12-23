public class MonitorWaitSignalSolution {
    public static void main(String[] args) throws InterruptedException {
        Thread plus = new Thread(new Plus());
        Thread minus = new Thread(new Minus());
        minus.start();
        plus.start();

        minus.join();
        plus.join();

        System.out.println("========================");
        System.out.println("기댓값 : 0 \t실제값 : " + sharedObject.result);
        System.out.println("========================");
    }
//    static int result = 0;
    static MyNumber sharedObject = new MyNumber();
    static int loopCnt = 100000;

    static class MyNumber {
        int result = 0;

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
                    if (sharedObject.result == 0) {
                        System.out.println("마이너스 싫다" + sharedObject.result);
                        try {
                            sharedObject.wait();
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                    }

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
                    if(sharedObject.result > 0)
                        sharedObject.notify();
                }
            }
        }
    }


}
