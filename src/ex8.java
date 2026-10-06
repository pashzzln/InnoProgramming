import java.util.Scanner;

public class ex8 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = Integer.parseInt(input.nextLine());

        String binary = Integer.toBinaryString(n);
        String hexadecimal = Integer.toHexString(n);

        System.out.println("Binary - " + binary);
        System.out.println("Hexadecimal - " + hexadecimal);

        String b = input.nextLine();

        System.out.println("Binary to Decimal - " + Integer.parseInt(b, 2));

        String h = input.nextLine();

        System.out.println("Hexadecimal to Decimal - " + Integer.parseInt(h, 16));

    }
}
