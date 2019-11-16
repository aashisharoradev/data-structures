package recursion;

public class TowerOfHanoi {

    private void performAction(int numberOfRings, String towerA, String towerB, String towerC) {
        if (numberOfRings > 0) {
            performAction(numberOfRings - 1, towerA, towerC, towerB);

            System.out.println("Moving Ring from " + towerA + " to " + towerC);

            performAction(numberOfRings - 1, towerB, towerA, towerC);
        }
    }
    public static void main(String[] args) {
        new TowerOfHanoi().performAction(4, "A", "B", "C");
    }
}