import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.BitSet;
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

public class SearchingForSoulmates {
    static int bitdif(long p, long t) {
        int bitdif = Long.toBinaryString(t).length() - Long.toBinaryString(p).length();
        if (t >> bitdif > p)
            bitdif++;
        return bitdif;
    }

    static long steps(long p, long t) {
        BitSet pb = BitSet.valueOf(new long[] { p }), tb = BitSet.valueOf(new long[] { t });
        int bitdif = tb.length() - pb.length();
        if (t >> bitdif > p)
            bitdif++;
        System.out.println(bitdif + " " + ((t >> bitdif) - p));
        return ((t >> bitdif) - p) + Long.bitCount(t - (t >> bitdif << bitdif)) + bitdif;
    }

    public static void main(String[] args) throws IOException {
        FastIO io = new FastIO("test.in", "test.out");
        // FastIO io = new FastIO();
        int N = io.nextInt();
        for (int i = 0; i < N; i++) {
            long p = io.nextInt(), t = io.nextInt();
            if (p <= t) {
                System.out.println(steps(p, t));
            } else {
                // long min = 999999999;
                // int a = 0;
                // while (p > 1) {
                // int bitdif2;
                // if (p <= t)
                // bitdif2 = 0;
                // else {
                // bitdif2 = bitdif(t, p);
                // // System.out.println(bitdif2);
                // // if (t << bitdif2 < p)
                // // bitdif2++;
                // // System.out.println(bitdif2 + " " + (t << bitdif2 < p));
                // }
                // min = Long.min(min, a + bitdif2 + steps(p, t << bitdif2));
                // // System.out.println(i + ":" + p + " " + t + "=" + (t << bitdif2) + "=" +
                // min);
                // if (p % 2 == 1) {
                // a += 1;
                // p += 1;
                // }
                // p /= 2;
                // a += 1;
                // }
                // // System.out.println(min);
            }
        }
        io.close();
    }
}
