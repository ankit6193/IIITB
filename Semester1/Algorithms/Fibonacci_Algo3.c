/*fibonacci with 2 variables*/
#include<stdio.h>
int fib(int n){
	int a = 1, b = 1;
	for(int i = 3 ; i <= n; i++){
		int c = (a + b) % 100;   //extra assignment and calculation i.e. slower then algo 2 
		a = b;
		b = c;	
	}
	return (b);
}
void main(){
	int input;
	scanf("%d",&input);
	printf("%d",fib(input));
}

/* 
 *
 *100000000
 *75
 *real	0m4.903s
 *user	0m1.224s
 *sys	0m0.004s
*/

