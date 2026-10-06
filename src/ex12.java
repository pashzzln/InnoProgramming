import java.io.File;
import java.util.Scanner;

public class ex12 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter path: ");
        String path = input.nextLine();

        File file = new File(path);

        if (file.exists()) {
            System.out.println("Exists");
        } else {
            System.out.println("Does not exist");
        }
    }
}
