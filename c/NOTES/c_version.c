#include<stdio.h>
#include<stdlib.h>

int main()
{
 if(__STDC_VERSION__==199409L)
    printf("C89\n");
 else if(__STDC_VERSION__==199901L)
    printf("C99\n");
 else if(__STDC_VERSION__==201112L)
    printf("C11\n");
 else if(__STDC_VERSION__==201710L)
    printf("C17\n");
 return 0;
}
