#include<stdio.h>
#include<conio.h>
#include <windows.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#include<dos.h>


int main()
{
    FILE* fp;
    int i;
    for(i=1;i<=23;i++){
        char name[100];
        itoa(i,name,10);
        fp = fopen(name,"w");
        char x;
        while(x = getchar()){
            if(x=='/') break;
            fputc(x,fp);
        }
        fclose(fp);
    }
}

