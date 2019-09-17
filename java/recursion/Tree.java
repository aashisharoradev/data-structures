package recursion;

public class Tree {
    void printNumber(int num) {
        if (num > 0) {
            System.out.print(num);
            this.printNumber(num - 1);
            this.printNumber(num - 1);
        }
    }
    public static void main(String[] args) {
        Tree tree = new Tree();
        tree.printNumber(3);
        System.out.println("");
    }
}