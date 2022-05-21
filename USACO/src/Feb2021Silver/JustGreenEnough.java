import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class JustGreenEnough {
	static boolean debug = true;
	static int[][] G;

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(in.readLine());
		G = new int[N + 1][N + 1];
		for (int i = 1; i <= N; i++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			for (int j = 1; j <= N; j++)
				G[i][j] = Integer.parseInt(st.nextToken()) + G[i - 1][j] + G[i][j - 1];
		}
		if (debug)
			for (int[] a : G)
				System.out.println(Arrays.toString(a));
		int res = 0;
		for (int A = 1; A <= N; A++)
			for (int B = 1; B <= N; B++)
				for (int a = 0; a < A; a++)
					for (int b = 0; b < B; b++)
						if (G[A][B] - G[a][B] - G[A][b] + G[a][b] >= 100)
							res++;
		System.out.println(res);
//		System.out.println(8);
	}
}
