import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Acowdemia {
	static boolean debug = false;
	static int N, K, L;
	static int[] P, S;

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(in.readLine());
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		L = Integer.parseInt(st.nextToken());
		P = new int[N];
		S = new int[N];
		st = new StringTokenizer(in.readLine());
		for (int i = 0; i < N; i++)
			P[i] = Math.min(N, Integer.parseInt(st.nextToken()));
		Arrays.sort(P);
		for (int i = 0; i < N; i++)
			S[i] = (i == 0 ? 0 : S[i - 1]) + P[i];
		if (debug) {
			System.out.println(Arrays.toString(P));
			System.out.println(Arrays.toString(S));
		}
		for (int m = N; m > 0; m--) {
			if (m - P[N - m] > K)
				continue;
			int M = K * L;
			boolean v = true;
			for (int p = N - m; p < N; p++) {
				if (M < 0) {
					v = false;
					break;
				}
				M -= m - Math.min(m, P[p]);
			}
			if (v) {
				System.out.println(m);
				break;
			}
		}
	}

}
