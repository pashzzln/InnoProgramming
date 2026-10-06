import java.io.File;
import java.util.Scanner;

public class ex13 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter path: ");
        String path = input.nextLine();

        File file = new File(path);

        if (file.isDirectory()) {
            System.out.println("This is a directory");
        } else if (file.isFile()) {
            System.out.println("This is a file");
        } else {
            System.out.println("Path does not exist");
        }
    }
}