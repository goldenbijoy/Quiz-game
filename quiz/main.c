#include<stdio.h>
#include<conio.h>
#include <windows.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#include<dos.h>


// Main Home function
char Home()
{
     system("cls");
     puts("\n\t\t WELCOME TO the Quiz GAME\n\n") ;
     puts("\n\t\t-------------------------------");
     puts("\n\t\t Enter 'S' to start game       ");
     puts("\n\t\t Enter 'V' to view high score  ");
     puts("\n\t\t Enter 'H' for help            ");
     puts("\n\t\t Enter 'Q' to quit             ");
     printf("\n\t\t-------------------------------\n\n\t\t  ");
     char ch = toupper(getch());
     return ch;
}

// Help function

void help()
{
    system("cls");
    printf("\n\n\n\tThis game is very easy to play. You'll be asked some general");
    printf("\n\n\tknowledge questions and the right answer is to be chosen among");
    printf("\n\n\tthe four options provided. Your score will be calculated at the");
    printf("\n\n\tend. Remember that the more quicker you give answer the more");
    printf("\n\n\tscore you will secure. Your score will be calculated and displayed");
    printf("\n\n\tat the end and displayed. If you secure highest score, your score");
    printf("\n\n\twill be recorded. So BEST OF LUCK.");
}

 // top scorer

 void writescore(float score, char plnm[20])
{
    float sc;
    char nm[100];
    FILE *f;
    system("cls");
    f=fopen("score.txt","r");
    fgets(nm,100,f);
    fscanf(f,"%f",&sc);
    if (score>=sc){
        sc=score;
        fclose(f);
        f=fopen("score.txt","w");
        fputs(nm,f);
        fprintf(f,"%f",sc);
        fclose(f);
    }
 }

//show score

void displayscore()
{
    char name[100];
    float s;
    FILE *f;
    system("cls");
    f=fopen("score.txt","r");
    fgets(name,100,f);
    fscanf(f,"%f",&s);
    printf("\n\n\t\t ");
    printf("\n\n\t\t %s has secured the Highest Score %.2f",name,s);
    printf("\n\n\t\t ");
    fclose(f);
    getch();
}

char name[100];
int nq[100];
int game_start()
{
    time_t ini_time,final_time;
    system("cls");
    printf("\n\n\n\t\t\tEnter your name...");
    printf("\n\n\t\t\t");
    gets(name);
    memset(nq,0,sizeof(int));
    int q = 0;
    Home:
        system("cls");
        ini_time = time(NULL);
        int countq,countr;
        countr= countq = 0;
        int i = 1;
        start:
            srand ( time(NULL) );
            int r=rand()%23+1; // total 23 question (can increase manually adding question)
            if(nq[r]!=0) goto start;
            else{
                countq++;
                q++;
                nq[r] = r;
                FILE *fp;
                if(q%23==0) memset(nq,0,sizeof(int));
                char z[100];
                char dir[] = "questions/";
                itoa(r,z,10);
                strcat(dir,z);
                fp = fopen(dir,"r");
                int j;
                for(j=0;j<5;j++){
                    fgets(z,100,fp);
                    puts(z);
                }
                fgets(z,100,fp);
                //puts(z);
                char x;
                scanf("%c",&x);
                getchar();
                x = toupper(x);
                if(z[0]==x) printf("Correct!!!\n"),countr++;
                else{
                    printf("inCorrect!!! The correct answer is: ");
                    printf("%c\n",z[0]);
                }
                fclose(fp);
                if(i<5){
                    i++;
                    goto start;
                }
                else{
                    final_time=time(NULL);
                    float score=(float)countr/countq*100-difftime(final_time,ini_time)/3;
                    if (score<0) score=0;
                    printf("\n\n\nYour Score: %.2f",score);
                    if (score==100) printf("\n\nEXCELLENT!!! KEEP IT UP");
                    else if (score>=80 && score<100) printf("\n\nVERY GOOD!!");
                    else if (score>=60 &&score<80) printf("\n\nGOOD! BUT YOU NEED TO KNOW MORE.");
                    else if (score>=40 && score<60) printf("\n\nSATISFACTORY RESULT, BUT THIS MUCH IS MUCH SUFFICIENT.");
                    else printf("\n\nYOU ARE VERY POOR IN G.K.,WORK HARD");
                    puts("\n\nNEXT PLAY?(Y/N)");
                    if (toupper(getch())=='Y') goto Home;
                    else{
                        writescore(score,name);
                        return 1;
                    }
                }
            }

}

int main()
{
    char z;
    int l;
    Menu:
        z = Home();
        if(z=='V'){
            displayscore();
            goto Menu;
        }
        if(z == 'Q') return 0;
        if(z=='H'){
            help();
            goto Menu;
        }
        if( z == 'S'){
            l = game_start();
            goto Menu;
        }
}
