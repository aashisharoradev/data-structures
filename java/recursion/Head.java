package recursion;

public class Head {
    void printNumber(int num) {
        if (num > 0) {
            this.printNumber(num - 1);
            System.out.print(num);
        }
    }
    public static void main(String[] args) {
        Head head = new Head();
        head.printNumber(3);
        System.out.println("");
    }
}