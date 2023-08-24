#include <stdio.h>
#include <math.h>
int main(){
	long long int max = (long long int) (pow(2,63) -1);
	long long int min = (long long int) (pow(2,63) *(-1));
	printf("Minimum value is %lld\n",min);
	printf("Maximum value is %lld\n",max);
	return 0;
}
