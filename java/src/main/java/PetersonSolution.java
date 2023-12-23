public class PetersonSolution {
    public static void main(String[] args) throws InterruptedException {
        Thread plus = new Thread(new Plus());
        Thread minus = new Thread(new Minus());
        plus.start();
        minus.start();

        plus.join();
        minus.join();

        System.out.println("========================");
        System.out.println("기댓값 : 0 \t실제값 : " + result);
        System.out.println("========================");
    }
    static int result = 0;
    static int loopCnt = 20000;

    // 기본 아이디어 : 다른 프로세스(스레드)의 turn이고, flag가 true라면 대기한다.
    static boolean[] flag = new boolean[2]; // 추가
    static int turn; // 추가

    static class Minus implements Runnable {
        static final int id = 0;
        @Override
        public void run() {
            for (int i = 0; i < loopCnt; i++) {
                flag[this.id] = true; // 추가
                turn = Plus.id; // 추가
                while(flag[Plus.id] && turn == Plus.id) // Plus의 상태를 확인함.
                    ; // 루프를 돌고 임계구역을 진입하지 않음.

                result--; // 임계 구역

                flag[this.id] = false; // 추가
            }
        }
    }

    static class Plus implements Runnable {
        static final int id = 1;
        @Override
        public void run() {
            for (int i = 0; i < loopCnt; i++) {
                flag[this.id] = true;
                turn = Minus.id;//
                while(flag[Minus.id] && turn == Minus.id) // Minus의 상태를 확인함.
                    ; // 루프를 돌고 임계구역을 진입하지 않음.

                result++; // 임계 구역

                flag[this.id] = false; // 추가
            }
        }
    }


}
