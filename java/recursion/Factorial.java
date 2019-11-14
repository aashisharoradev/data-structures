package recursion;

public class Factorial {
    int factorial(int num)
    {
        if(num > 0) {
            return factorial(num - 1) * num;
        }
        return 1;
    }

    int factorialLoop(int num) {
        int factorial = 1;
        while (num >= 1)
        {
            factorial *= num;
            num--;
        }
        return factorial;
    }
    public static void main(String[] args) {
        Factorial fact = new Factorial();
        System.out.println("Factorial of 5 is " + fact.factorial(5));
        System.out.println("Factorial of 6 is " + fact.factorialLoop(5));
    }
}