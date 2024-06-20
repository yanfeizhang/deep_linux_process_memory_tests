#include <stdio.h>  
int func(int p){   
	return 1;
}  
int main()  
{  
	int i;  
	for(i=0; i<100000000; i++){  
		func(2);  
	}  
	return 0;  
}