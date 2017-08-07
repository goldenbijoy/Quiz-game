#include <bits/stdc++.h>
using namespace std;

int main()
{
    FILE* fp;

    for( int i=1;i<23;i++){
        char name[100];
        itoa(i,name,10);
        fp = fopen(name,"w");
        char x;
        while(x = getc()){
            if(x=='/') break;
            fputc(x,fp);
        }
        fclose(fp);
    }
}
