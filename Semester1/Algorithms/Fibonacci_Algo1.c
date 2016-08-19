/* to check the time program takes to give correct output in one second*/

#include <stdio.h>

int rec (int n){
		if (n<2) 
			return (n);
		else
			return((rec(n-1)+rec(n-2))%100);
}

void main(){
	int n;
	scanf("%d",&n);

	printf("%d",rec(n));
}


/* 
 *result--- 
 *38
 *69
 *real	0m2.511s
 *user	0m1.112s
 *sys	0m0.004s
*/
