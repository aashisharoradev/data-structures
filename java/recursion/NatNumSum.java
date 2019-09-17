package recursion;

class NatNumSum {
    int sum(int n) {
        return n * (1 + n) / 2;
    }
    
    int sumRecursion(int n) {
        if (n > 0)
        {
           return sumRecursion(n - 1) + n;
        }
        return 0;
    }
    
    int sumUsingWhile (int n) {
        int sum = 0;
        while (n > 0)
        {
            sum += n;
            n--;
        }
        return sum;
    }

    public static void main(String[] args) {
        NatNumSum instance = new NatNumSum();
        System.out.println("sum using series "+ instance.sum(20));  // o(1)
        System.out.println("sum of natural number "+ instance.sumRecursion(20)); // o(n)
        System.out.println("sum of natural number using while "+ instance.sumUsingWhile(20)); // time o(n) space o(1)
    }
}
