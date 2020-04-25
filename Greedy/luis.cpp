#include <iostream>
#include <vector>
using namespace std;

typedef struct {
   int v;
   int c;
   float d;
} Item;

bool compareDensity(Item i1, Item i2) {
   return (i1.d > i2.d);
} 

void solve(int totalItems, vector<Item> &items, int budget, vector<int> &original, vector<int> &used){
	int maxVal = 0;
	int b = budget;
	for(Item x : items) {
		if( x.c <= b ) { 
			maxVal += x.v;
			b -= x.c;
			for(int j = 0; j < totalItems; j++){
				if(original.at(j) == x.v){
					used.at(j) = 1;
					break;
				}
			}
		}
	}
	cout << "DONE; MaxValue = " << maxVal << endl;
	for(int i : used){
		cout << used.at(i);
	}
	cout << endl;
}

void density(vector<int> cost, vector<int> value, int totalItems, int budget){
	int original[totalItems];
	vector<Item> items(totalItems);
	vector<int> used(totalItems);
	for(int i=0; i<totalItems; ++i) {
		items.at(i).v = value.at(i);
		items.at(i).c = cost.at(i);
		items.at(i).d = value.at(i)/cost.at(i);
	}
	sort(items.begin(), items.end(), compareDensity); 
	solve(totalItems,items,budget,value,used);
}

int main() {
	vector<int> c { 5, 10, 20};
	vector<int> v { 50, 60, 140};
	density(c,v,3,30);
}

