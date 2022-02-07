#include<stdio.h>
#include<stdlib.h>
/*include 
  1. sentinel value for end of char array
  2. normal instruction char array
  3. string (as char* or char array for reserving string bytes)
  4. resv-bytes (as integer for number of bytes to be reserved)*/

char sentinel = -1; //dummy sentinel value

int write_intstruction(char* to_wrt);
int resv_bytes(int bytes);

int test_read(){//for testing if written properly
	FILE* f = fopen("out.com","rb");
	char* read = malloc(2);
	while(fread(read,sizeof(char),1,f)==1){
		if(*read==0)
			printf("0\n");
		else
			printf("%s\n",read);
	}

	free(read);
	return fclose(f);
}

int main()
{
	FILE* f = fopen("out.com","w");
	fclose(f);
	char arr[7] = {'a','b','c','d',-1};
	int bytes = 10;
	write_intstruction(arr);
	resv_bytes(bytes);
	test_read();
}

int write_intstruction(char* wrt){
	FILE* f = fopen("out.com","ab");
	int i = 0;
	while(wrt[i]!=sentinel)
		i++;

	printf("i=%d\n",i);
	fwrite(wrt,sizeof(char),i,f);
	return fclose(f);
}
int resv_bytes(int bytes){
	FILE* f = fopen("out.com","ab");
	char zeroes[bytes];
	for (int i=0;i<bytes;i++)
		zeroes[i] = 0;

	fwrite(zeroes,sizeof(char),bytes,f);
	return fclose(f);
}
