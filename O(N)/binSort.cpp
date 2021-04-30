#include<iostream>
#include<math.h>

using namespace std;

struct node{
	int data;
	node* next;
};

struct bin{
	node* header;
	node* end;
};
typedef bin List[10];

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

int logarit(int n){
	int count = 0;
	while(n >= 10){
		n /= 10;
		count++;
	}
	return count;
}

int getDigits(int a[], int n){
	int max = 0;
	for(int i = 0; i < n; i++)
		if(max < logarit(a[i]) + 1)
			max = logarit(a[i]) + 1;
	return max;
}

void createNullBin(List &B){
	for(int i = 0; i < 10; i++){
		B[i].header = NULL;
		B[i].end = NULL;
	}
}

bool emptyBin(bin B){
	if(B.header == NULL && B.end == NULL)
		return true;
	else
		return false;
}

void insertBin(bin &B, int value){
	if(emptyBin(B)){
		B.end = new node;
		B.header = B.end;
	}
	else{
		B.end->next = new node;
		B.end = B.end->next;
	}
	B.end->data = value;
	B.end->next = NULL;
}

void concatenate(bin &B1, bin B2){
	if(B1.header == NULL)
		B1.header = B2.header;
	else
		B1.end->next = B2.header;
	B1.end = B2.end;
}

void binSort(int a[], int n, int m, List &B){
	for(int i = 0; i < m; i++){
		
		//insert elements into list B 
		//with each B[key] is linked list and key is 0-9
		for(int j = 0; j < n; j++){
			int key = (int)(a[j] / pow(10, i)) % 10;
			insertBin(B[key], a[j]);
		}
		
		//concatenate B[j]s into B[0] with j is 1-9
		for(int j = 1; j < 10; j++)
			if(!emptyBin(B[j]))
				concatenate(B[0], B[j]);
		
		//update array a[]		
		int j = 0;
		while(B[0].header != NULL){
			a[j] = B[0].header->data;
			B[0].header = B[0].header->next;
			j++;
		}
		
		//reset list B
		createNullBin(B);
	}
}

int main(){
	int n;
	
	do{
		cout << "How many elements are there in Array?" << endl;
		cin >> n;
	} while(n <= 0);
	
	int a[n];
	
	readArray(a, n);
	
	cout << "=====Given Array=====" << endl;
	printArray(a, n);
	
	int m = getDigits(a, n);
	
	List B;
	createNullBin(B);
	
	binSort(a, n, m, B);
	
	cout << "=====Sorted Array=====" << endl;
	printArray(a, n);
	
	return 0;
}
