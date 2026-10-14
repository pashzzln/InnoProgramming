import java.util.Scanner;

class Calculator{
    public int arg1;
    public int arg2;
    public String sign;

    public Calculator(int a1, int a2, String s){
        this.arg1 = a1;
        this.arg2 = a2;
        this.sign = s;
    }

    public double calculate(){

        if (this.sign.equals("+")) return (double) this.arg1 + this.arg2;
        if (this.sign.equals("-")) return (double) this.arg1 - this.arg2;
        if (this.sign.equals("*")) return (double) this.arg1 * this.arg2;
        if (this.sign.equals("/") && this.arg2 != 0) return (double) this.arg1 / this.arg2;

        else return -1;
    }

}

public class ex1 {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int arg1 = input.nextInt();
        String sign = input.next();
        int arg2 = input.nextInt();

        Calculator c = new Calculator(arg1, arg2, sign);

        System.out.println(c.calculate());
    }
}
