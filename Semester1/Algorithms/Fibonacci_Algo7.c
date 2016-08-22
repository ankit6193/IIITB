/* Algorithm by using binary input from a file --> O(log n)
 */

#include <stdio.h>
#include <ctype.h>

int MAX = 100000,F[1000000] , MSB , LSB;

int N[2][2] = { {1,1},
		{1,0} } ;
	
int M[2][2] = { {1,0},
		{0,1} } ;

int matpow(int arr[]);
void multiply(int M[][2],int N[][2]);
void divide_by_2(int arr[]);
int isZero(int arr[]); 

int matpow(int arr[]){

	while(!isZero(arr)){

		if(arr[LSB] % 2 != 0)
			multiply(M,N);

		multiply(M,M);
		divide_by_2(arr);

	}
	
	return M[1][0];
}

void divide_by_2(int arr[]){  //right shift bit
	LSB--;
}

void multiply(int M[2][2] , int N[2][2]){
	
	int w = ( M[0][0]*N[0][0] + M[0][1]*N[1][0] ) % 100 ;
	int x = ( M[0][0]*N[0][1] + M[0][1]*N[1][1] ) % 100 ;
	int y = ( M[1][0]*N[0][0] + M[1][1]*N[1][0] ) % 100 ;
	int z = ( M[1][0]*N[0][1] + M[1][1]*N[1][1] ) % 100 ;
	
	M[0][0] = w;
	M[0][1] = x;
	M[1][0] = y;
	M[1][1] = z;
}
int isZero(int arr[]){
	if(MSB > LSB || arr[MSB] == 0)
		return 1;
	else
		return 0; 
}

void main(){
	FILE *fp;
	fp = fopen("input" , "r");
	char c;
	for(long i = 0 ; i < MAX ; i++) {
		if((c=fgetc(fp))!=EOF && isdigit(c)) {	
	//		printf("%c", c);
			F[i] = c - '0';
		}
		else 
			break;
	
	}
	fclose(fp);

	MSB = 0;
	LSB = MAX - 1;
	
	printf("%d",matpow(F));
	
}
