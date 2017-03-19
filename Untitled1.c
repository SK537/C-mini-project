#include<stdio.h>
#include<conio.h>
int main()
{
    FILE *fp;
    fp=fopen("b.txt","r");
        char ques[50],a[15],b[15],c[15],d[15],garbage1,garbage2,garbage3,garbage4,garbage5,correct;
    //fscanf(fp,"%[^!]s %c %[^@]s %c %[^#]s %c %[^*]s %c %[^)]s %c %c",&ques,&garbage1,&a,&garbage2,&b,&garbage3,&c,&garbage4,&d,&garbage5,&correct);
                    fscanf(fp,"%[^!]",&ques);
                    fscanf(fp,"%c",&garbage1);
                   fscanf(fp,"%[^@]s",&a);
                    fscanf(fp,"%c",&garbage1);
                    fscanf(fp,"%[^#]s",&b);
                    fscanf(fp,"%c",&garbage1);
                    fscanf(fp,"%[^*]s",&c);
                    fscanf(fp,"%c",&garbage1);
                    fscanf(fp,"%[^)]s",&d);
                    fscanf(fp,"%c",&garbage1);
                    fscanf(fp,"%c",&correct);

    printf("%s %s %s %s %s %c",ques,a,b,c,d,correct);
    return 0;
}
