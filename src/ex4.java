import java.util.Scanner;

public class ex4 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        String a = input.nextLine();
        String b = input.nextLine();

        if (a.compareTo(b) == 0){
            System.out.println("Strings are equal");
        } else if (a.compareTo(b) > 0){
            System.out.println("First string is bigger");
        } else System.out.println("Second string is bigger");

    }
}
