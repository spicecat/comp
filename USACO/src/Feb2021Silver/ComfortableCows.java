import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class ComfortableCows {
	static boolean[][] cow = new boolean[3000][3000];
	static int added = 0;

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(in.readLine());
		for (int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			int x = Integer.parseInt(st.nextToken()) + 1500, y = Integer.parseInt(st.nextToken()) + 1500;
			added--;
			add(x, y);
			System.out.println(added);
		}
	}

	static void add(int x, int y) {
		if (cow[x][y])
			return;
		cow[x][y] = true;
		added++;
		check(x, y);
		if (cow[x - 1][y])
			check(x - 1, y);
		if (cow[x + 1][y])
			check(x + 1, y);
		if (cow[x][y - 1])
			check(x, y - 1);
		if (cow[x][y + 1])
			check(x, y + 1);
	}

	static void check(int x, int y) {
		if ((cow[x - 1][y] ? 1 : 0) + (cow[x + 1][y] ? 1 : 0) + (cow[x][y - 1] ? 1 : 0)
				+ (cow[x][y + 1] ? 1 : 0) == 3) {
			if (!cow[x - 1][y])
				add(x - 1, y);
			else if (!cow[x + 1][y])
				add(x + 1, y);
			else if (!cow[x][y - 1])
				add(x, y - 1);
			else
				add(x, y + 1);
		}
	}
}
