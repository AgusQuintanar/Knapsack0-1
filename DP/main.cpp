#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>

using namespace std;
typedef int ulli;

ulli max(ulli a, ulli b){
	return a >= b ? a : b;
}

void solveA(ulli n, vector<ulli> &b, vector<ulli> &w, ulli k){
	//Knapsack 0-1
	//Dados los pesos y beneficios, encuentra el máximo beneficio que
	//puede lograr una mochila con cierta capacidad tomando máximo 1 elemento.
	
	vector<vector<ulli> > dp = vector<vector<ulli> >(n+1, vector<ulli>(k+1));
	for(ulli i=0; i<k+1; i++){
		dp[0][i] = 0;
	}
	for(ulli i=0; i<n+1; i++){
		dp[i][0] = 0;
	}
		
	for(ulli i=1; i<n+1; i++){
		for(ulli j=1; j<k+1; j++){
			dp[i][j] = max(dp[i-1][j], j-w[i-1] < 0 ? 0 : dp[i-1][j-w[i-1]] + b[i-1]);		
		}
	}
		
	for(ulli i=0; i<n+1; i++){
		for(ulli j=0; j<k+1; j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<'\n';
	}

	cout<<dp[n][k]<<endl;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	ulli n; // Num. de elementos
	cin>>n;

	vector<ulli> b(n); // Beneficios
	vector<ulli> w(n); // Pesos

	for(ulli i=0; i<n; i++) cin>>b[i];
	for(ulli i=0; i<n; i++) cin>>w[i];

	ulli k; // Capacidad de mochila
	cin>>k;

	solveA(n, b, w, k);

}
