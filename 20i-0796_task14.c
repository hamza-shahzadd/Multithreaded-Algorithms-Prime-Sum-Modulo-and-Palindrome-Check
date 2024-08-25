#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  
#include <pthread.h>


int size;

void* func2(void* args)
{
	int *a = (int *) args;
	printf("val= %i\n", *a);
	int mod;
	
	while(*a>300)
	{
		mod=*a%300;
		*a=mod;
	}
	printf("%d Value after dividing by 300.\n", *a);
	pthread_exit((void*)*a);
}

void* func1(void* args)
{
	int *val_p = (int *) args;
	int arr_size = size;
	int prime=0;
	
	int count=0;
	
	for(int i=0; i< 5;i++)
	{
		for(int j=1; j<= val_p[i];j++)
		{
			if(val_p[i] % j == 0)
			count++;
			
		}
		if(count  <= 2)
		prime=prime+val_p[i];
		
		count=0;	
		
	}
	
	printf("Prime count =%i \n", prime);
	//*p2 = prime;
		
	pthread_exit((void*)prime);
 
}



int main()
{

	printf("Enter size of array\n");
	scanf("%d", &size);
	int arr1[size];
	int ans;
	
	for(int i=0; i< size;i++)
	{
		printf("Enter %ivalue of array \n", i);
		scanf("%d",&arr1[i]);
	}
	
	pthread_t thread1;
	pthread_create(&thread1, NULL, func1,(void*)&arr1);
	pthread_join(thread1,(void*)&ans);
	int r= (int*)ans;
	
	
	
	pthread_t thread2;
	int two,t2;
	pthread_create(&thread2, NULL, func2,(void*)&r);
	pthread_join(thread2,(void*)&two);
	t2=(int*)two;
	 
	int n,reversed = 0, remainder, original;
   	n=t2;
    original = n;

    // reversed integer is stored in reversed variable
    while (n != 0) {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }
    

    // palindrome if orignal and reversed are equal
    if (original == reversed)
        printf("%d is a palindrome.", original);
    else
        printf("%d is not a palindrome.", original);

	
	
	return 0;
}
