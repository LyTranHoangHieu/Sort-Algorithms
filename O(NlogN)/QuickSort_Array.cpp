#include<iostream>
using namespace std;
const int MAX = 100;
void swap(int &x, int &y){
	int temp = x;
	x = y;
	y = temp;
}
void partitionSort(int a[], int first, int last){
	if(first >= last)
		return;
	int x = a[(first+last)/2];
	int i = first, j = last;
	do{
		while(a[i] < x)
			i++;
		while(a[j] > x)
			j--;
		if(i <= j){
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}while(i <= j);
	partitionSort(a, first, j);
	partitionSort(a, i, last);
}
void quickSort(int a[], int n){
	partitionSort(a, 0, n-1);
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
	int a[MAX];
	int n;
	do{
		cout << "How many elements are there in Array? ";
		cin >> n;
	} while(n <= 0 || n > MAX);
	readArray(a, n);
	cout << "=====Given Array=====" << endl;
	printArray(a, n);
	quickSort(a, n);
	cout << "=====Quick Sort Array=====" << endl;
	printArray(a, n);
	return 0;
}
