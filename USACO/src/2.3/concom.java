/*
ID: ateh0701
LANG: JAVA
TASK: concom
*/

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class concom {
	static int[][] shares = new int[101][101];
	static boolean[][] owns = new boolean[101][101];
	static boolean debug = false;
	static int max = 0;

	public static void main(String[] args) throws IOException {
		for (int i = 1; i < 101; i++)
			owns[i][i] = true;
		BufferedReader br = new BufferedReader(new FileReader("concom.in"));
		for (int i = 0, N = Integer.parseInt(br.readLine()); i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			add(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
			if (debug)
				print();
		}
		br.close();
		PrintWriter pw = new PrintWriter("concom.out");
		for (int i = 1; i < 101; i++)
			for (int j = 1; j < 101; j++)
				if (owns[i][j] && i != j)
					pw.println(i + " " + j);
//					System.out.println(i + " " + j);
		pw.close();
	}

	static void add(int a, int b, int p) {
		if (debug) {
			System.out.println(a + " " + b + " " + p);
			max = Math.max(max, Math.max(a, b));
		}
		for (int i = 1; i < 101; i++) {
			if (owns[i][a])
				shares[i][b] += p;
			if (shares[i][b] > 50)
				inherit(i, b);
		}
	}

	static void inherit(int a, int b) {
		if (debug)
			System.out.println(a + " " + b);
		if (owns[a][b])
			return;
		owns[a][b] = true;
		for (int i = 1; i < 101; i++) {
			shares[a][i] += shares[b][i];
			if (owns[i][a])
				inherit(i, b);
			if (shares[a][i] > 50)
				inherit(a, i);
		}
	}

	static void print() {
		int N = max;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++)
				System.out.print((shares[i][j] < 10 ? " " : "") + shares[i][j] + " ");
			System.out.println();
		}
		System.out.println();
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++)
				System.out.print(owns[i][j] ? " 1 " : " 0 ");
			System.out.println();
		}
		System.out.println("--------");
	}
}
