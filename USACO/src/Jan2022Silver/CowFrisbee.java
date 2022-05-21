import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;

class FastIO extends PrintWriter {
    private InputStream stream;
    private byte[] buf = new byte[1 << 16];
    private int curChar;
    private int numChars;

    // standard input
    public FastIO() {
        this(System.in, System.out);
    }

    public FastIO(InputStream i, OutputStream o) {
        super(o);
        stream = i;
    }

    // file input
    public FastIO(String i) throws IOException {
        this(new FileInputStream(i), System.out);
    }

    public FastIO(String i, String o) throws IOException {
        super(new FileWriter(o));
        stream = new FileInputStream(i);
    }

    // throws InputMismatchException() if previously detected end of file
    private int nextByte() {
        if (numChars == -1) {
            throw new InputMismatchException();
        }
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (numChars == -1) {
                return -1; // end of file
            }
        }
        return buf[curChar++];
    }

    // to read in entire lines, replace c <= ' '
    // with a function that checks whether c is a line break
    public String next() {
        int c;
        do {
            c = nextByte();
        } while (c <= ' ');

        StringBuilder res = new StringBuilder();
        do {
            res.appendCodePoint(c);
            c = nextByte();
        } while (c > ' ');
        return res.toString();
    }

    public int nextInt() { // nextLong() would be implemented similarly
        int c;
        do {
            c = nextByte();
        } while (c <= ' ');

        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = nextByte();
        }

        int res = 0;
        do {
            if (c < '0' || c > '9') {
                throw new InputMismatchException();
            }
            res = 10 * res + c - '0';
            c = nextByte();
        } while (c > ' ');
        return res * sgn;
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }
}

public class CowFrisbee {
    public static void main(String[] args) throws IOException {
        FastIO io = new FastIO("test.in", "test.out");
        // FastIO io = new FastIO();
        int N = io.nextInt();
        int[] h = new int[N];
        for (int i = 0; i < N; i++)
            h[i] = io.nextInt();
        // long s = 0;
        long s = 2L * N - 2;
        for (int i = 0; i < N - 1; i++) {
            int max = h[i], min = h[i + 1];
            // System.out.println(i + " " + min + " " + max);
            for (int j = i + 2; j < N && min < max; j++) {
                // System.out.println(i + " " + j + " " + min + " " + max);
                if (h[j] > min) {
                    s += j - i + 1;
                    min = h[j];
                }
            }
        }
        System.out.println(s);
        io.close();
    }
}
