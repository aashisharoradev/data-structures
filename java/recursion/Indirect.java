package recursion;

public class Indirect {
    private void functionA(int n) {
        if (n > 0) {
            System.out.print(" " + n);
            this.functionB(n - 1);
        }
    }
    
    private void functionB(int n) {
        if (n > 1) {
            System.out.print(" " + n);
            this.functionA(n/2);
        }
    }
    public static void main(String[] args) {
        (new Indirect()).functionA(20);
        System.out.println();
    }
}