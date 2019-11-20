package arrays;

public class Dynamic {
    public static void main(String[] args) {
        int a[] = new int[5]; // this array will be created in heap
        int[] b = new int[] { 2, 4, 6, 8, 10 };
        
        for (int i = 0; i < b.length; i++) {
            System.out.println("Value :: " + b[i]);
        }

        // no memory clean up needed as java garbage collector will take care of it
    }
}