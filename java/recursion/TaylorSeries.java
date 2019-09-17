package recursion;

class TaylorSeries {
    
    static double p = 1, f = 1, sum =1;

    double exp(int x, int n) {
        if (n == 0) {
            return sum;
        }
        sum = 1 + (double) x / n * sum;
        return exp(x, n - 1);
    }
    
    double e(int x, int n) {
        double r;
        if (n == 0) {
            return 1;
        }
        r = e(x, n - 1);
        p = p * x;
        f = f * n ;
        return r + p/f;
    }

    public static void main(String[] args) {
        
        TaylorSeries series = new TaylorSeries();
        System.out.println("value for exponent e with power 1 and precision 10 " + series.e(1, 10));

        System.out.println("value for exponent e with power 1 and precision 10 " + series.exp(1, 10));
        
    }
}