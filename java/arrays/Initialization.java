package arrays;

public class Initialization {
    public static void main(String args[]) {
        int a[] = { 2, 4, 6, 8, 10 };
        
        int[] b = { 1, 3, 5, 7, 9 }; // this array is created in stack

        String[] c = { "1", "2" , "3" , "4" , "5" };

        for (int i = 0; i < a.length; i++) {
            System.out.println("Value :: " + a[i]);
        }

        for (int i = 0; i < c.length; i++) {
            System.out.println("Value :: " + c[i]);
        }
    }
}