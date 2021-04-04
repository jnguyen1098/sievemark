import java.util.*;
import java.io.*;
import java.text.DecimalFormat;

public class Sieve {
    public static void main(String[] args) {
        final int NUM_PRIMES = 9592;
        final int NUM_LIMIT = 100000;
        Scanner scanner = null;
        try {
            scanner = new Scanner(new File("primes.txt"));
        } catch (Exception e) {
            System.out.println("What the hell");
            e.printStackTrace();
            System.exit(1);
        }
        int[] primes = new int[NUM_PRIMES];
        int num = 0;
        while (scanner.hasNextInt()) {
            primes[num++] = scanner.nextInt();
        }
        DecimalFormat lmao = new DecimalFormat("0.000000");
        double startTime = System.nanoTime();

        int n = 0;
        int numbers[] = new int[NUM_LIMIT + 1];
        int results[] = new int[NUM_PRIMES];
        for (int i = 2; i <= NUM_LIMIT; i++) {
            for (int j = 2 * i; j <= NUM_LIMIT; j += i) {
                numbers[j] = 1;
            }
        }

        for (int i = 2; i <= NUM_LIMIT; i++) {
            if (numbers[i] == 0) {
                results[n++] = i;
            }
        }

        for (int i = 0; i < NUM_PRIMES; i++) {
            if (primes[i] != results[i]) {
                System.out.println("Fail");
                System.exit(0);
            }
        }

        double endTime = System.nanoTime();
        System.out.println(lmao.format((endTime - startTime) / 1_000_000_000));
    }
}
