package recursion;

public class Exponent {
    int exponent(int base, int power) {
        if (power > 0) {
            return exponent(base, power -1 ) * base;
        }
        return 1;
    }
    
    int exponentReduceMultiply(int base, int power) {
        if (power == 0) {
            return 1;
        } else if (power % 2 == 0) {
            return exponentReduceMultiply(base * base, power / 2);
        } else {
            return base * exponentReduceMultiply(base * base, (power - 1) / 2);
        }
    }
    
    public static void main(String[] args) {
        Exponent exp = new Exponent();
        System.out.println("2 power 8 is "+exp.exponent(2, 8));
        System.out.println("2 power 9 is "+exp.exponentReduceMultiply(2, 9));
    }
}