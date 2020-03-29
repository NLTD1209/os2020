#include <stdio.h>
#include <string.h>
#include <pthread.h>

void *prime()
{
	int i = 2;
	int check = 1;
	while(i <= 1000000)
	{
		check = 1;
		for (int j = 2; j < i; j++)
			if ((i % j) == 0)
			{
				check = 0;
				break;
			}
		if (check) 
			{
				printf("%d\n \n \n",i);
			}
		i++;
	}
}

char t[100000];

void bignumadd(char u[], char v[])
{
	while (strlen(u) < strlen(v))
	 {
	 	char s2[1000000] = "0";
		strcat(s2,u);
		strcpy(u,s2);
	 }
	while (strlen(v) < strlen(u))
	 {
	 	char s2[100000] = "0";
		strcat(s2,v);
		strcpy(v,s2);
	 }
	int m,n,carry,sum;
	for (int i = 0; i < strlen(u); i++) t[i] = '0';
	carry = 0;
	for (int i = strlen(u)-1; i >= 0; i--)
	{
		m = u[i] - '0';
		n = v[i] - '0';
		sum = m+n;
		if (carry == 1) sum++;
		t[i] = (sum % 10) + '0';
		if (sum > 9) carry = 1; else carry = 0;
	}
	if (carry == 1) 
		{
			char s2[100000] = "1";
			strcat(s2,t);
			strcpy(t,s2);
		}

}
void *fibo()
{
	char a[100000] = "0";
	char b[100000] = "1";
	int count = 3;
	printf("%s\n",a);
	printf("%s\n",b);
	while (count <= 20000)// prime thread stop at about 90000th fibonacci(count = 90000)
	{
		char c[100000];
		bignumadd(a,b);
		strcpy(c,t);
		count++;
		printf("%s\n",c);
		strcpy(a,b);
		strcpy(b,c); 
	}
}

int main()
{
	pthread_t tid1;
	pthread_t tid2;

	pthread_create(&tid1,NULL,fibo,NULL);

	pthread_create(&tid2,NULL,prime,NULL);

	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	return 0;
}