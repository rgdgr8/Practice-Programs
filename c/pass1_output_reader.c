#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define RD_LN_BUF_SZ 100 //maxsize of one line
#define TKN_BUF_SZ 20	//maxsize of one token
#define MAX_NUM_OF_TKS 20 //max number of tokens in one line
#define MAX_NUM_OF_LNS 200 //max number of lines

int read_all_lines(char**);//returns num of lines read
int get_tokens_from_line(char*,char**);//returns num of tokens in a given line

int main()
{
	char** lines = malloc(MAX_NUM_OF_LNS*sizeof(char*));
	for(int i=0;i<MAX_NUM_OF_LNS;i++)
		lines[i] = malloc(RD_LN_BUF_SZ);
	char** tokens = (char**)malloc(MAX_NUM_OF_TKS*sizeof(char*));
	for(int i=0;i<MAX_NUM_OF_TKS;i++)
		tokens[i] = malloc(TKN_BUF_SZ);

	int num_lines = read_all_lines(lines);
	for(int i=0;i<num_lines;i++)
		get_tokens_from_line(lines[i],tokens);

	for(int i=0;i<MAX_NUM_OF_LNS;i++)
		free(lines[i]);
	free(lines);
	for(int i=0;i<MAX_NUM_OF_TKS;i++)
		free(tokens[i]);
	free(tokens);
}

int read_all_lines(char** lines){
	FILE* f = fopen("output.txt","r");
	char line[RD_LN_BUF_SZ];
	int i = 0;
	while(fgets(line,RD_LN_BUF_SZ,f)){//reads line including newline char
		line[strcspn(line,"\r\n")] = 0;//removing the newline char if present
		strcpy(lines[i++],line);
		printf("%s\n",line);
	}
	fclose(f);
	printf("Number of lines is %d\n\n",i);
	return i;
}

int get_tokens_from_line(char* line,char** tokens){
	int i = 0;
	char* token = strtok(line," ");
	printf("Tokens of line:\n");
	while(token!=NULL){
		strcpy(tokens[i],token);
		printf("%s\n",tokens[i]);
		i++;
		token = strtok(NULL," ");
	}
	printf("Number of tokens in this line is %d\n\n",i);
	return i;
}


