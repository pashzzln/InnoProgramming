import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class ex5 {

    static int countVowels(String s){
        List<Character> vowels = new ArrayList<>(List.of('a', 'e', 'u', 'i', 'o'));
        int c = 0;
        for (int i = 0; i < s.length(); i++) {
            if (vowels.contains(s.charAt(i))){
                c += 1;
            }
        }
        return c;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String s = input.nextLine();
        s = s.toLowerCase();

        System.out.printf("%d vowels\n", countVowels(s));
    }
}

