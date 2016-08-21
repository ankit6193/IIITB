/*fibonacci using Math Trick with faster Multiplication O(logn) */

#include<stdio.h>

void multiply(int M[2][2] , int N[2][2]);

void matpow(int M[2][2], int n);

int fib(int n){
	int M[2][2] = { {1,1} ,
			{1,0} } ;
	if(n==0)
		return 0;
	
	matpow(M, n-1);

	return M[0][0];
}

void multiply(int M[2][2] , int N[2][2]){
	
	int w = M[0][0]*N[0][0] + M[0][1]*N[1][0] ;
	int x = M[0][0]*N[0][1] + M[0][1]*N[1][1] ;
	int y = M[1][0]*N[0][0] + M[1][1]*N[1][0] ;
	int z = M[1][0]*N[0][1] + M[1][1]*N[1][1] ;
	
	M[0][0] = w;
	M[0][1] = x;
	M[1][0] = y;
	M[1][1] = z;
}

void matpow(int M[2][2] , int n){
	if( n==0 || n==1)
		return;
	int N[2][2] = { {1,1},
			{1,0} };
	
	matpow(M , n/2);
	multiply(M,M);
	
	if(n % 2 != 0)
		multiply(M,N);
}

void main(){
	int input;
	scanf("%d",&input);
	printf("%d",fib(input));	
}

/* 
 *
 *10000000 (10^7)
 *75
 *real	0m3.261s
 *user	0m0.272s
 *sys	0m0.004s

*/

