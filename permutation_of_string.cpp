#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void permutation(char a[], int i){
	// base case
	if(a[i]=='\0'){
		cout<<a<<"\n";
		return;
	}
	for(int j=i;a[j]!='\0';j++){
		swap(a[i],a[j]);  
		permutation(a,i+1);
		swap(a[i],a[j]);
	}
}

int main() {

     char a[]="abc";
     permutation(a,0);
  return 0;
}
