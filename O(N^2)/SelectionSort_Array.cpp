#include<iostream>
using namespace std;

void swap(int &x, int &y){
	int temp = x;
	x = y;
	y = temp;
}
void selectionSort(int a[], int n){
	int i = 0, posMin;
	while(i < n-1){
		int min = a[i];
		posMin = i;
		for(int pos = i+1; pos < n; pos++){
			if(min > a[pos]){
				min = a[pos];
				posMin = pos;
			}
		}
		swap(a[posMin], a[i]);
		i++;
	}
}
void readArray(int a[], int n){
	cout << "Enter " << n << " Element's content in any order" << endl;
	for(int i = 0; i < n; i++)
		cin >> a[i];		
}
void printArray(int a[], int n){
	for(int i = 0; i < n; i++)
		cout << a[i] << '\t';
	cout << endl;
}
int main(){
	int n;
	do{
		cout << "How many elements are there in Array? ";
		cin >> n;
	} while(n <= 0);
	int a[n];
	readArray(a, n);
	cout << "=====Given Array=====" << endl;
	printArray(a, n);
	selectionSort(a, n);
	cout << "=====Selection Sort Array=====" << endl;
	printArray(a, n);
	return 0;
}
