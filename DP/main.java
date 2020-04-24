import java.util.Scanner;

class Main{

	public static int max(int a, int b){
		return a >= b ? a : b;
	}

	public static void solve(int n, int[] b, int[] w, int k){
		int[][] dp = new int[n+1][k+1];
		
		for(int i=1; i<n+1; i++){
			for(int j=1; j<k+1; j++){
				dp[i][j] = max(dp[i-1][j], j-w[i-1] < 0 ? 0 : dp[i-1][j-w[i-1]] + b[i-1]);		
			}
		}
		
		for(int i=0; i<n+1; i++){
			for(int j=0; j<k+1; j++){
				System.out.print(dp[i][j] + " ");
			}
			System.out.println();
		}

		System.out.println(dp[n][k]);

	}

	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int n, k;
		n = sc.nextInt();
		int[] b = new int[n];
		int[] w = new int[n];

		for(int i=0; i<n; i++){
			b[i] = sc.nextInt();
		}
		for(int i=0; i<n; i++){
			w[i] = sc.nextInt();
		}
		k = sc.nextInt();
		solve(n, b, w, k);
	}
}	
