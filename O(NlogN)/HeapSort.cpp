#include<iostream>
using namespace std;
const int MAX = 100;
void swap(int &x, int &y){
	int temp = x;
	x = y;
	y = temp;
}
void createHeap(int a[], int n){
	int i, j, t;
	for(t = n/2; t > 0; t--){
		i = t;
		j = 2 * i;
		do{
			if(j < n)
				if(a[j] < a[j+1])
					j = j + 1;
			if(a[i] < a[j]){
				swap(a[i], a[j]);
				i = j;
				j = 2 * i;
			}
		}while(j <= n && a[i] < a[j]);
	}
}
void heapSort(int a[], int n){
	int p, i;
	p = n;
	while(p > 1){
		createHeap(a, p);
		swap(a[1], a[p]);
		p = p - 1;
	}
}
void readArray(int a[], int n){
	cout << "Enter " << n << " Element's content in any order" << endl;
	for(int i = 1; i <= n; i++)
		cin >> a[i];		
}
void printArray(int a[], int n){
	for(int i = 1; i <= n; i++)
		cout << a[i] << '\t';
	cout << endl;
}
int main(){
	int a[MAX];
	int n;
	do{
		cout << "How many elements are there in Array? ";
		cin >> n;
	} while(n <= 0 || n > MAX);
	readArray(a, n);
	cout << "=====Given Array=====" << endl;
	printArray(a, n);
	heapSort(a, n);
	cout << "=====Heap Sort Array=====" << endl;
	printArray(a, n);
	return 0;
}
