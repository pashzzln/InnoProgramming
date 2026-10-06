import java.util.ArrayList;
import java.util.Scanner;

public class ex11 {
    public static void main(String[] args) {

        ArrayList<Integer> nums = new ArrayList<Integer>();

        Scanner input = new Scanner(System.in);
        System.out.print("Enter number of numbers: ");
        int n = Integer.parseInt(input.nextLine());

        for (int i = 0; i < n; i++) {
            System.out.print("Enter number: ");
            nums.add(Integer.parseInt(input.nextLine()));
        }

        ArrayList<Integer> duplicates = new ArrayList<>();

        for (int i = 0; i < nums.size()-1; i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums.get(i).equals(nums.get(j)) && !duplicates.contains(nums.get(i))) {duplicates.add(nums.get(i)); break;}
            }
        }

        System.out.println("Duplicates - " + duplicates);
    }
}
