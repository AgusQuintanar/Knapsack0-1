#include <iostream>
#include <vector>

using namespace std;


void solve(int n, vector<int> &b, vector<int> &w, int k){
	//Knapsack 0-1
	//Dados los pesos y beneficios, encuentra el máximo beneficio que
	//puede lograr una mochila con cierta capacidad tomando máximo 1 elemento.

	cout<<k<<endl;
}

int main(){
	int n; // Num. de elementos
	cin>>n;

	vector<int> b(n); // Beneficios
	vector<int> w(n); // Pesos

	for(int i=0; i<n; i++){
		cin>>b[i];
		if(b[i] <=0 ){
			cerr<<"Error en input"<<endl;
			return -1;
		}
	}
	for(int i=0; i<n; i++){
		cin>>w[i];
		if(w[i] <=0 ){
			cerr<<"Error en input"<<endl;
			return -1;
		}
	}


	int k; // Capacidad de mochila
	cin>>k;

	solve(n, b, w, k);
}
