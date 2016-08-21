/*fibonacci using Math Trick*/
#include<stdio.h>
int fib(int n){
	int M[2][2] = { {1,0} , 
			{0,1} } ;
	int w,x,y,z;
	
	for( int i = 1; i < n ; i++){
		w = M[0][0];
		x = M[0][1];
		y = M[1][0];
		z = M[1][1];	
		M[0][0] = ((w * 1) + (x * 1)) % 100;
		M[0][1] = (w * 1) % 100 ;
		M[1][0] = ((y * 1) + (z * 1)) % 100;
		M[1][1] = (y * 1) ; 	
	}
		
	return M[1][0];
	
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

