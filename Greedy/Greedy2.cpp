#ifdef LOCAL
#include <iostream>
#define debug(x) cerr<<"["<<#x<<"]: "<<x<<endl;
#define EPS 0.0000001
#else
#include <bits/stdc++.h>
#define debug(x) 42
#define debug_c(a) 42
#endif

using namespace std;
#include <vector>
#include <iomanip>

typedef struct {
   long long int originalIndex; 
   float pb; // weight- profit
   long long int weight;
   long long int profit;
} Item;

bool comparePB(Item i1, Item i2) {
   return (i1.pb > i2.pb);
} 


void solve(long long int n, vector<Item> &items, long long int k){
	//Knapsack 0-1
	//Dados los weights y profits, encuentra el máximo profit que
	//puede lograr una mochila con cierta capacidad tomando máximo 1 elemento.
    vector<long long int> usedItems (n);
    sort(items.begin(), items.end(), comparePB);

    long long int maxprofit = 0, 
                 carriedWeight = 0;
	Item currentItem;

    for (long long int i=0; i<n; i++) {
        currentItem = items[i];
        if (currentItem.weight + carriedWeight > k) break; //si se pasa del peso
        else {
            maxprofit += currentItem.profit;
            carriedWeight += currentItem.weight;
            usedItems[currentItem.originalIndex] = 1; // accedes al vector original
            items[i] = {}; // elimina registro temporal
        }
    }

    cout << maxprofit << endl;
    for (int j=0; j<n; j++) cout << usedItems[j] << " ";
    cout << endl;
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(0);
    cout.tie(0);

	long long int n; // Num. de elementos
	cin>>n;
    vector<long long int> p(n); // profits
    for(long long int i=0; i<n; i++) cin>>p[i];
    
	vector<Item> items(n); // Items
    long long int w; // weight de un objeto

	for(long long int i=0; i<n; i++) { // Recorre el vector de todos los items
        items[i].pb = p[i] / w; //obtiene el beneficio / peso
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
	solve(n, items, k);

}

