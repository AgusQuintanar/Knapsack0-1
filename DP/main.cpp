#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>

using namespace std;
typedef int ulli;


ulli max(ulli a, ulli b){
	//max, recibe dos numeros, retorna el mayor.
	return a >= b ? a : b;
}

void solveA(ulli n, vector<ulli> &b, vector<ulli> &w, ulli k){
	//Knapsack 0-1
	//Dados los pesos y beneficios, encuentra el máximo beneficio que
	//puede lograr una mochila con cierta capacidad tomando máximo 1 elemento.
	
	vector<vector<ulli> > dp = vector<vector<ulli> >(n+1, vector<ulli>(k+1));

	//Relacion de recurrencia	
	for(ulli i=1; i<n+1; i++){
		for(ulli j=1; j<k+1; j++){
			if(j-w[i-1] < 0){ // Si no cabe
				dp[i][j] = dp[i-1][j]; //Toma maximo anterior
			}
			else{ // Si cabe
				if(dp[i-1][j] < dp[i-1][j-w[i-1]] + b[i-1]){
					dp[i][j] = dp[i-1][j-w[i-1]] + b[i-1]; // Es mejor agarrar el actual y llenar lo que resta con lo mejor
				}
				else dp[i][j] = dp[i-1][j]; // El anterior es mejor que agarrar el nuevo y lo que restaba
			}	
		}
	}

	//Impresion del beneficio máximo
	cout<<dp[n][k]<<'\n';

	//Impresion de elementos usados
	#ifdef ELEMENTS
	for(int i=n, j=k; i>= 1; i--){
		if(j<1) break;
		if(dp[i][j] != dp[i-1][j]){ // Si diferente al de arriba, eligio el elemento
			j -= w[i-1];
			cout<<i<<" ";
		}
	}
	cout<<'\n';
	#endif	

	//Impresion de matriz
	#ifdef MATRIX
	for(ulli i=0; i<n+1; i++){
		for(ulli j=0; j<k+1; j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<'\n';
	}
	#endif
}


void solveB(ulli n, vector<ulli> &b, vector<ulli> &w, ulli k){
    vector<vector<int> > dp(2, vector<int>(k+1));
  
    // iterate through all items 
    int i = 0; 
    while (i < n) // one by one traverse each element 
    { 
        int j = 0; // traverse all weights j <= W 
  
        // if i is odd that mean till now we have odd 
        // number of elements so we store result in 1th 
        // indexed row 
        if (i%2!=0) 
        { 
            while (++j <= k) // check for each value 
            {
                if (w[i] <= j){ // include element
			if(b[i] + dp[0][j-w[i]] > dp[0][j]){
				dp[1][j] = b[i] + dp[0][j-w[i]];
			}
			else dp[1][j] = dp[0][j];
			
		}
                else           // exclude element 
                    	dp[1][j] = dp[0][j]; 
            } 
  
        } 
  
        // if i is even that mean till now we have even number 
        // of elements so we store result in 0th indexed row 
        else
        { 
            while(++j <= k) 
            { 
                if (w[i] <= j){
			if(b[i] + dp[1][j-w[i]] > dp[1][j]){
				dp[0][j] = b[i] + dp[1][j-w[i]];
			}
			else dp[0][j] = dp[1][j];
		}
                else
                    dp[0][j] = dp[1][j]; 
            } 
        } 
        i++; 
    } 
  
    // Return mat[0][W] if n is odd, else mat[1][W] 
    cout<<( (n%2 != 0)? dp[0][k] : dp[1][k])<<'\n'; 
    
	#ifdef MATRIX
	for(ulli i=0; i<2; i++){
		for(ulli j=0; j<k+1; j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<'\n';
	}
	#endif

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
	
	#ifdef OPTIMIZE
	solveB(n, b, w, k);
	#else
	solveA(n, b, w, k);
	#endif
}
