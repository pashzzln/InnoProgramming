import java.util.Scanner;

public class ex1 {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int a = input.nextInt();
        int b = input.nextInt();

        System.out.printf("a is %d, b is %d\n", a, b);

        int temp = a;
        a = b;
        b = temp;

        System.out.printf("a is %d, b is %d\n", a, b);
    }
}
