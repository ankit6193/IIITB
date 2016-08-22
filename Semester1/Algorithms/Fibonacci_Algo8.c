/* algorithm explaining periodic repeatation when using modulous i.e. approximately 6m , uses very less space*/

#include<stdio.h>
#include<ctype.h>

int compute(int arr[] , int n);
int modulous(int arr[] , int l , int period);
int m = 5,F[1000000],MAX=1000000;			//give m according to need

int compute(int arr[] , int n){
	arr[0] = 0;
	arr[1] = 1;

	for(int i = 2 ; i <= n ; i++)
		arr[i] = (arr[i-1] + arr[i-2]) % m;

	return arr[n] ;

}

int modulous ( int arr[] , int l , int period ){

	int digit = 0 ; 
	int carry = 0 ;

	for(int i = 0 ; i < l ; i++){
		digit = carry * 10 + arr[i];
		carry = digit % period ;
	}
	
	return carry ;
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

	int arr[6*m + 1];
	
	compute(arr , 6*m);
	
	int period = 0;
	
	for(int i = 2 ; i <= 6*m ; i++){
		if(arr[i] == 0 && arr[i+1] == 1){
			period = i;
			break;
		}	
	}
	
	int resultIndex = modulous(F , MAX , period);

	printf("%d",arr[resultIndex]);	
}
