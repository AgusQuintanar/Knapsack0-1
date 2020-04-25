#ifdef LOCAL
#include <iostream>
#define debug(x) cerr<<"["<<#x<<"]: "<<x<<endl;
#define EPS 0.0000001
#else
#include <bits/stdc++.h>
#define debug(x) 42
#define debug_c(a) 42
#endif

#include <chrono>


using namespace std;
#include <vector>
#include <iomanip>
#include <string>

typedef struct {
   long long int originalIndex; 
   float pw; // profit / weight
   long long int weight;
   long long int profit;
} Item;

bool comparePW(Item i1, Item i2) {
   return (i1.pw > i2.pw);
} 


void solve(long long int n, vector<Item> &items, long long int k){
	//Knapsack 0-1
	//Dados los weights y profits, encuentra el máximo profit que
	//puede lograr una mochila con cierta capacidad tomando máximo 1 elemento.

    sort(items.begin(), items.end(), comparePW); //ordena el vector por introsort

    long long int maxprofit = 0, //ganancia maxima
                 carriedWeight = 0; //peso cargado en la mochila
	Item currentItem; 
    string usedItems = ""; //string que contiene todos los items usados

    for (long long int i=0; i<n; i++) {
        currentItem = items[i];
        if (currentItem.weight + carriedWeight > k) break; //si se pasa del peso
        else {
            maxprofit += currentItem.profit; // a la ganancia maxina se le suma el profit del item actual
            carriedWeight += currentItem.weight; // al peso acumulado de la mochila se le suma el peso del item
            usedItems += to_string(currentItem.originalIndex) + " "; // concatena lista de items usados
        }
    }

    cout << maxprofit << endl; 
    cout << usedItems << endl;
}

int main(){

    ios::sync_with_stdio(false); // deshabilita librerias de C
	cin.tie(0); //desincroniza entradas y salidas de consola
    cout.tie(0);

	long long int n; // Num. de elementos
	cin>>n;
    if (n<=0) {
        cerr<<"Error en Input"<<endl;
        return -1; //checa entrada invalida
    }
    vector<long long int> p(n); // vector de profits
    for(long long int i=0; i<n; i++) {
        cin>>p[i]; //agarra profits de input
        if (p[i]<=0) {
            cerr<<"Error en Input"<<endl;
            return -1; //checa entrada invalida
        } 
    }
    
	vector<Item> items(n); // vector que contiene los items
    long long int w; // weight de un objeto

	for(long long int i=0; i<n; i++) { // Recorre el vector de todos los items
        items[i].pw = p[i] / w; //obtiene el beneficio / peso
        items[i].originalIndex = i+1; //guarda el indice original (1 basado)
        cin >> w; // toma el peso del obejto por consola
        if (w<=0) {
            cerr<<"Error en Input"<<endl;
            return -1; //checa entrada invalida
        }
        items[i].weight = w;
        items[i].profit = p[i]; //asigna el beneficio del objeto
    }

	long long int k; // Capacidad de mochila
	cin>>k; //toma por consola la capacidad de la mochila
    if (k<=0) {
            cerr<<"Error en Input"<<endl;
            return -1; //checa entrada invalida
    }


    auto t1 = std::chrono::high_resolution_clock::now();
    
	solve(n, items, k); 

    auto t2 = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

    std::cout << duration << endl;
}

