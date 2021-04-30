#include<iostream>
#include<math.h>

using namespace std;

struct node{
	int data;
	node* next;
};
typedef node* List[10];

void readArray(int a[], int n){
	cout << "Enter " << n << " Element's content in any order" << endl;
	for(int i = 0; i < n; i++)
		cin >> a[i];
}

void printArray(int a[], int n){
	for(int i = 0; i < n; i++)
		cout << a[i] << "  ";
	cout << endl;
}

// Count the number of digits of a positive number n
int logarit(int n){
	int count = 0;
	while(n >= 10){
		n /= 10;
		count++;
	}
	return count;
}

// Find the Max number of digits in array
int getDigits(int a[], int n){
	int max = 0;
	for(int i = 0; i < n; i++)
		if(max < logarit(a[i]) + 1)
			max = logarit(a[i]) + 1;
	return max;
}

//Create 10 null buckets from 0 to 9
void createNullList(List &L){
	for(int i = 0; i < 10; i++){
		L[i] = new node;
		L[i]->next = NULL;
	}
}

//Find the last position in list
node* last(node* L){
	node* p = L;
	while(p->next != NULL)
		p = p->next;
	return p;
}

//Insert new value into the last position of 
//linked list L[key] with key is 0->9
void insert(List &L, int value, int key){
	node* temp = new node;
	temp->data = value;
	temp->next = last(L[key])->next;
	last(L[key])->next = temp;
}

void radixSort(int a[], int n, int m, List &L){
	//the max number of digits is the loop times
	for(int i = 0; i < m; i++){
		
		//divide into L[key]
		for(int j = 0; j < n; j++){
			int key = (int)(a[j] / pow(10, i)) % 10;
			insert(L, a[j], key);
		}
		
		//transfer each element of L[key]s into array a[]
		int pos = 0;
		for(int i = 0; i < 10; i++){
			node* temp = L[i];
			while(temp->next != NULL){
				a[pos] = temp->next->data;
				pos++;
				temp = temp->next;
			}
			
			//reset L[i] 
			L[i]->next = NULL;
		}
	}
}

int main(){
	int n;
	
	do{
		cout << "How many elemets are there in Array? ";
		cin >> n;
	} while(n <= 0);
	
	int a[n];
	
	readArray(a, n);
	
	cout << "=====Given Array=====" << endl;
	printArray(a, n);
	
	int m = getDigits(a, n);
	
	List L;
	createNullList(L);
	
	radixSort(a, n, m, L);
	
	cout << "=====Sorted Array=====" << endl;
	printArray(a, n);
	
	return 0;
}
