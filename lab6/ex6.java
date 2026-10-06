import java.util.Scanner;

public class ex6 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int f = input.nextInt();

        System.out.printf("It is %f degrees Celsius", ((float) f - 32) * 5/9);
    }
}
