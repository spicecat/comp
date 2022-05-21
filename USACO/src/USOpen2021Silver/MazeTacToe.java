import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;

public class MazeTacToe {
	static boolean debug = false;
	static int N, B;// , res;
	static HashSet<Integer> res = new HashSet<>();
	static HashMap<Integer, HashSet<P>> boards = new HashMap<>();
//	static HashSet<Integer> boards = new HashSet<>();
	static HashSet<P> P = new HashSet<>();
	static boolean[][] wall;

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(in.readLine());
		wall = new boolean[N][N];
		for (int i = 0; i < N; i++) {
			String line = in.readLine(), p;
			for (int j = 0; j < N; j++) {
				p = line.substring(j * 3, j * 3 + 3);
				if (p.equals("BBB"))
					B = N * j + i;
				else if (p.equals("...") || (wall[i][j] = p.equals("###")))
					;
				else
					P.add(new P(p.charAt(0) == 'M', i, j, p.charAt(1) - 49, p.charAt(2) - 49));
			}
		}
		P r = new P(true, -1, -1, -1, -1);
		tree(B % N, B / N, new int[3][3], r);
		println(boards);
		share(r);
		recur(new int[3][3], r);
		System.out.println(res.size());
	}

	static void tree(int x, int y, int[][] board, P last) {
		if (wall[x][y])
			return;
		wall[x][y] = true;
//		println(y + "," + x);
		for (P p : P)
			if (p.i == x && p.j == y) {
				println(p);
				if (last != null)
					last.n.add(p);
				last = p;
//				}
				break;
			}
		tree(x + 1, y, clone(board), last);
		tree(x - 1, y, clone(board), last);
		tree(x, y + 1, clone(board), last);
		tree(x, y - 1, clone(board), last);
	}

	static boolean check(int[][] board, int x, int y) {
		if (board[x][1] == 1 && board[x][0] + board[x][2] == 3)
			return true;
		if (board[1][y] == 1 && board[0][y] + board[2][y] == 3)
			return true;
		if (x == y || x == 2 - y)
			if (board[1][1] == 1 && board[0][0] + board[2][2] == 3 || board[0][2] + board[2][0] == 3)
				return true;
		return false;
	}

	static int hash(int[][] board) {
		int s = 0;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				s += board[i][j] * Math.pow(3, (3 * i + j));
		return s;
	}

	static void share(P r) {
		for (P p : r.n) {
			share(p);
			p.n.addAll(r.n);
		}
	}

	static void recur(int[][] board, P r) {
		boards.putIfAbsent(hash(board), new HashSet<>());
		if (!boards.get(hash(board)).add(r))
//		if (!boards.add(hash(board)))
			return;
		println(r + " " + r.n + " " + hash(board));
		for (P p : r.n) {
			int[][] next = clone(board);
			if (next[p.x][p.y] == 0) {
				next[p.x][p.y] = p.m ? 2 : 1;
				for (int[] i : next)
					println(Arrays.toString(i));
				if (check(next, p.x, p.y)) {
					if (res.add(hash(next)))
						println(hash(next) + "!");
					return;
				}
			}
			recur(clone(next), p);
			recur(clone(next), r);
		}
	}

	static class P {
		boolean m;
		int i, j, x, y;
		HashSet<P> n = new HashSet<>();

		P(boolean m, int i, int j, int x, int y) {
			this.m = m;
			this.i = i;
			this.j = j;
			this.x = x;
			this.y = y;
		}

		public String toString() {
			return (this.m ? "M" : "O") + (this.x + 1) + (this.y + 1) + " " + this.j + "," + this.i;
		}

		public void n() {
			print("{");
			for (P p : n) {
				print("" + p);
				p.n();
				print(",");
			}
			println("}");
		}
	}

	static int[][] clone(int[][] a) {
		int[][] b = new int[3][3];
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				b[i][j] = a[i][j];
		return b;
	}

	static void println(Object s) {
		if (debug)
			System.out.println(s);
	}

	static void println() {
		if (debug)
			System.out.println();
	}

	static void print(Object s) {
		if (debug)
			System.out.print(s);
	}
}
