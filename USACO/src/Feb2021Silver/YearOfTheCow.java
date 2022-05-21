import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class YearOfTheCow {
	static boolean debug = false;
	static int res = 0;

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(in.readLine());
		int N = Integer.parseInt(st.nextToken()), K = Integer.parseInt(st.nextToken()) - 1;
		HashSet<Integer> years = new HashSet<>();
		for (int i = 0; i < N; i++)
			years.add(Integer.parseInt(in.readLine()) / 12 + 1);
		years.add(0);
		ArrayList<Integer> sort = new ArrayList<>();
		sort.addAll(years);
		Collections.sort(sort);
		res = sort.get(sort.size() - 1);
		int[] dif = new int[sort.size() - 1];
		ArrayList<Integer> sortdif = new ArrayList<>();
		for (int i = 0; i < dif.length; i++)
			sortdif.add(dif[i] = sort.get(i + 1) - sort.get(i) - 1);
		Collections.sort(sortdif);
		Collections.reverse(sortdif);
		if (debug) {
			System.out.println(sort);
			System.out.println(Arrays.toString(dif));
			System.out.println(sortdif);
		}
		for (int i = 0; i < K; i++)
			res -= sortdif.remove(0);
		System.out.println(res * 12);
	}
}
