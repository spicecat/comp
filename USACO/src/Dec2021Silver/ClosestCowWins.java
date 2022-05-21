import java.io.*;
import java.util.*;

class FastIO extends PrintWriter {
    private InputStream stream;
    private byte[] buf = new byte[1 << 16];
    private int curChar;
    private int numChars;

    public FastIO() {
        this(System.in, System.out);
    }

    public FastIO(InputStream i, OutputStream o) {
        super(o);
        stream = i;
    }

    public FastIO(String i, String o) throws IOException {
        super(new FileWriter(o));
        stream = new FileInputStream(i);
    }

    private int nextByte() {
        if (numChars == -1)
            throw new InputMismatchException();
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (numChars == -1)
                return -1;
        }
        return buf[curChar++];
    }

    // to read in entire lines, replace c <= ' '
    // with a function that checks whether c is a line break
    public String next() {
        int c;
        do
            c = nextByte();
        while (c <= ' ');
        StringBuilder res = new StringBuilder();
        do {
            res.appendCodePoint(c);
            c = nextByte();
        } while (c > ' ');
        return res.toString();
    }

    public int nextInt() { // () would be implemented similarly
        int c;
        do
            c = nextByte();
        while (c <= ' ');
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = nextByte();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res = 10 * res + c - '0';
            c = nextByte();
        } while (c > ' ');
        return res * sgn;
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }
}

public class ClosestCowWins {

    public static void main(String[] args) throws Exception {
        FastIO io = new FastIO();
        // FastIO io = new FastIO("test.in", "test.out");
        int K = io.nextInt(), M = io.nextInt(), N = io.nextInt();
        int[] t = new int[200002];
        long[] res = new long[200002];
        for (int i = 0; i < K; i++)
            t[io.nextInt() + 1] = io.nextInt();
        for (int i = 0; i < M; i++)
            t[io.nextInt() + 1] = -1;
        io.close();
        long[] cur = new long[200002];
        int last = 0;
        for (int i = 1; i < 200002; i++) {
            if (t[i] == -1) {
                if (last == 0)
                    res[i - 1] = cur[i - 1];
                else {
                    long m = 0;
                    for (int j = last, d = (i - last) / 2; j < last + d; j++)
                        if (cur[j + d] - cur[j] > m) {
                            m = cur[j + d] - cur[j];
                        }
                    res[i - 1] = m;
                    res[i] = cur[i - 1] - m;
                }
                last = i;
            } else
                cur[i] = cur[i - 1] + t[i];
        }
        res[200001] = cur[200001];
        Arrays.sort(res);
        long s = 0;
        for (int i = 200002 - N; i < 200002; i++)
            s += res[i];
        System.out.println(s);
    }
}
