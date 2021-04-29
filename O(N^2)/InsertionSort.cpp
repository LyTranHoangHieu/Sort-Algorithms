#include<iostream>

using namespace std;

void insertionSort(int a[], int n){
	int i = 1, pos;
	while(i < n){
		int x = a[i];
		pos = 0;
		while(x > a[pos])
			pos++;
		for(int j = i; j > pos; j--)
			a[j] = a[j-1];
		a[pos] = x;
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
	
	do
	{
		cout << "How many elements are there in Array? ";
		cin >> n;
	} while(n <= 0);
	
	int a[n];
	
	readArray(a, n);
	
	cout << "=====Given Array=====" << endl;
	printArray(a, n);
	
	insertionSort(a, n);
	
	cout << "=====Insertion Sort Array=====" << endl;
	printArray(a, n);
	
	return 0;
}
