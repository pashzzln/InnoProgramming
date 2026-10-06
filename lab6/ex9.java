import java.util.ArrayList;
import java.util.Scanner;

public class ex9 {
    public static void main(String[] args) {
        ArrayList<Integer> nums = new ArrayList<Integer>();

        Scanner input = new Scanner(System.in);
        System.out.print("Enter number of numbers: ");
        int n = Integer.parseInt(input.nextLine());

        for (int i = 0; i < n; i++) {
            System.out.print("Enter number: ");
            nums.add(Integer.parseInt(input.nextLine()));
        }

        int sum = 0;
        for (int x : nums) {
            sum += x;
        }

        System.out.println("Average value is " + (float) sum / nums.size());
    }
}
