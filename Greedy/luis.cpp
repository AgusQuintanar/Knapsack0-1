#include <iostream>
using namespace std;

typedef struct {
   int v;
   int c;
   float d;
} Item;

bool compareDensity(Item i1, Item i2) {
   return (i1.d > i2.d);
} 

void solve(int totalItems, Item items[], int budget, int original[], int used[]){
	int maxVal = 0;
	int i = 0;
	int b = budget;
	while(b >= 0 && i < totalItems) {
		if( items[i].c <= b) {
			maxVal += items[i].v;
			b -= items[i].c;
			for(int j = 0; j < totalItems; j++){
				if(original[j] == items[i].v){
					used[j] = 1;
				}
			}
			i+=1;
		}
		else {
			i += 1;
		}
	}
	cout << "DONE; MaxValue = " << maxVal << endl;
	for(int i = 0; i < totalItems; i++){
		cout << used[i];
	}
	cout << endl;
}

void density(int cost[], int value[], int totalItems, int budget){
	int original[totalItems];
	Item items[totalItems];
	int used[totalItems];
	for(int i = 0; i < totalItems; i++) {
		items[i].v = value[i];
		items[i].c = cost[i];
		items[i].d = value[i]/cost[i];

		used[i] = 0;
	}
	sort(items, items+totalItems, compareDensity); 
	solve(totalItems,items,budget,value,used);
}

int main() {
	int n; cin >> n;
	int v[n];
	for (int i=0; i<n; i++) cin >> v[i];
	int c[n];
	for (int i=0; i<n; i++) cin >> c[i];
	//int c[5] = {1, 1, 1, 1, 1};
	//int v[5] = {3, 8, 5, 1, 4};
	int k; cin >> k;
	density(c,v,n,k);
}