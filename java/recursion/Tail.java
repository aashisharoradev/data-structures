package recursion;

public class Tail {
    void printNumber(int num) {
        if (num > 0) {
            System.out.print(num);
            this.printNumber(num - 1);
        }
    }
    public static void main(String[] args) {
        Tail tail = new Tail();
        tail.printNumber(3);
        System.out.println("");
    }
}