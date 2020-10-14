#include<stdio.h>

int main(){
	int i,a,b,n,hasil=0;
	
	printf("Angka: ");
	scanf("%d", &n);
	
	a=1;
	b=0;
	
	for(i=1;i<=n;i++){
		hasil=a+b;
		a=b;
		b=hasil;
		printf("%d\n",hasil);
	}
}
