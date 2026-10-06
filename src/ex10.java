import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class ex10 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        ArrayList<Integer> nums = new ArrayList<>(List.of(0, 1, 2, 3, 4, 5, 6, 7, 8, 9));
        System.out.println("Old array: " + nums);

        System.out.print("Enter index and number: ");
        nums.add(input.nextInt(), input.nextInt());
        System.out.println("New array: " + nums);
    }
}
