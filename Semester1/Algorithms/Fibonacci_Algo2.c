/*fibonacci using dyanamic programming very fast then recursive one*/
#include<stdio.h>
int fib(int n){
	int f[n+1];
	f[1]=f[2]=1;
	for(int i=3;i<=n;i++)
		f[i]=(f[i-1]+f[i-2])%100;

	return f[n];
}
void main(){
	int input;
	scanf("%d",&input);
	printf("%d",fib(input));
}

/* 
 *Limits input to 10^6 because of use of array
 * 
 *1000000
 *75 
 *real	0m3.396s
 *user	0m0.020s
 *sys	0m0.012s
*/

