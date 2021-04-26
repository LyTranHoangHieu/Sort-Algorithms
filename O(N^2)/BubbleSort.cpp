#include<iostream>
using namespace std;

void swap(int &x, int &y){
	int temp = x;
	x = y;
	y = temp;
}
void bubbleSort(int a[], int n){
	for(int i = 0; i < n-1; i++)
		for(int j = n-1; j > i; j--)
			if(a[j] < a[j-1])
				swap(a[j], a[j-1]);
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
	do
	{
		cout << "How many elements are there in Array? ";
		cin >> n;
	} while(n <= 0);
	int a[n];
	readArray(a, n);
	cout << "=====Given Array=====" << endl;
	printArray(a, n);
	bubbleSort(a, n);
	cout << "=====Bubble Sort Array=====" << endl;
	printArray(a, n);
	return 0;
}
