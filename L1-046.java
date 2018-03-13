import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt();
        BigInteger bigX = new BigInteger(String.valueOf(x));

        StringBuilder builder = new StringBuilder();
        while (true) {
            builder.append("1");
            BigInteger bigInteger = new BigInteger(builder.toString());
            if (bigInteger.mod(bigX).equals(BigInteger.ZERO)) {
                System.out.print(bigInteger.divide(bigX) + " " + bigInteger.toString().length());
                break;
            }
        }
    }
}
