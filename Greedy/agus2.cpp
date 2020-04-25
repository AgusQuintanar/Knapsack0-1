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
   unsigned int index;
   float pb; // weight- profit
   unsigned int weight;
   unsigned int profit;
} Item;

bool comparePB(Item i1, Item i2) {
   return (i1.pb > i2.pb);
} 

void solve(unsigned int n, vector<Item> &items, unsigned int k){
	//Knapsack 0-1
	//Dados los weights y profits, encuentra el máximo profit que
	//puede lograr una mochila con cierta capacidad tomando máximo 1 elemento.

    sort(items.begin(), items.end(), comparePB);

    unsigned int maxprofit = 0, 
                 carriedWeight = 0;
	Item currentItem;

    for (unsigned int i=0; i<n; i++) {
        currentItem = items[i];
        if (currentItem.weight + carriedWeight > k) break; //si se pasa del peso
        else {
            maxprofit += currentItem.profit;
            carriedWeight += currentItem.weight;
            //cout << currentItem.index;
            items[i] = {}; // elimina registro temporal
        }
    }

    cout << maxprofit << endl;
    cout << endl;
}

int main(){

    time_t start, end;
    time(&start);

    ios::sync_with_stdio(false);
	cin.tie(0);
    cout.tie(0);

	unsigned int n; // Num. de elementos
	cin>>n;
    vector<unsigned int> p(n); // profits
    for(unsigned int i=0; i<n; i++) cin>>p[i];
    
	vector<Item> items(n); // Items
    unsigned int w; // weight

	for(unsigned int i=0; i<n; i++) {
        cin >> w;
        items[i].index = i+1;
        items[i].pb = p[i] / w;
        items[i].weight = w;
        items[i].profit = p[i];
    }

	unsigned int k; // Capacidad de mochila
	cin>>k;

	solve(n, items, k);

    time(&end); 

    // Calculating total time taken by the program. 
    double time_taken = double(end - start); 
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5); 
    cout << " sec " << endl; 
}

