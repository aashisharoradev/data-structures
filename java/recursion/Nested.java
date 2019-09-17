package recursion;

class Nested {
    private int printNumber(int n) {
        if (n > 0) {
            System.out.print(" " + n);
            return printNumber(printNumber(n - 1));
        }
        
        return 0;
    }
    public static void main(String[] args) {
        (new Nested()).printNumber(95);
    }
}