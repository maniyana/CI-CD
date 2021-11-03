#include<stdio.h>
main()
{
	int n,i,fact=1,num;
	printf("Enter any number:");
	scanf("%d", &num);
	for(i=1; i<=num;i++){
		fact = fact*i;
	}
	printf("Fact of %d is: %d", num,fact);
}