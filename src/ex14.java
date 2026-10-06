import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class ex14 {
    public static void main(String[] args) throws IOException {
        Scanner r = new Scanner(new File("input.txt"));
        FileWriter w = new FileWriter("output.txt");

        while (r.hasNextLine()) {
            w.write(r.nextLine() + "\n");
        }

        r.close();
        w.close();
    }
}
