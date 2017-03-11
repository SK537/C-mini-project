#include<graphics.h>
#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<dos.h>
#include<windows.h>
int amount_won,life1,life2,life3,life4,file_num;
char ans;
void sgame();
int game(char*,char*,char*,char*,char*,char);
void correct(int,int,int,int);
void wrong(int,int,int,int);
void window(void);
void redgreen(int,int,int);

void reset(void)                                        ///Resets amount won and lifelines left to zero
{
    amount_won=0;life1=0;life2=0;life3=0;life4=0;
}


int main()
{
    char inputer,a;
    time_t current_time;
    current_time=time(NULL);
    system("cls");
  //  reset();                                //reset any previous game values
    printf("********************WELCOME TO KBC GAME********************");
    puts(ctime(&current_time));
    printf("\n\n \t \t \t 1.Start Game");
    printf("\n\n \t \t \t 2.High Score");
    printf("\n\n \t \t \t 3.Help");
    printf("\n\n \t \t \t 4.About");
    printf("\n\n \t \t \t 5.Quit");
    printf("\n\n \t \t \t SELECT YOUR OPTION(1/2/3/4/5): ");
    inputer=_getch();
    switch(inputer)
    {
        case '1':
             printf("Starting the Game");
             reset();
             sgame();
             break;
        case '2':
            system("cls");

            FILE *pf;
            int high_score;
            pf=fopen("NOONE.txt","r");
             fscanf(pf,"%d",&high_score);
            printf("Your high score is %d",high_score);
            printf("\nYour last score is %d",amount_won);
              fclose(pf);
              printf("\nPress r to reset highscore ");
            printf("\n Press 2 to quit \n Press 1 to return to mainmenu");
            a=_getch();
            if(a=='1')
            main();
            else if(a=='2')
            exit(0);
            else if(a=='r')
            {
                 pf=fopen("NOONE.txt","w");
                 fprintf(pf,"0");
                 fclose(pf);
                 main();
            }
          break;
        case '3':
            system("cls");
            printf("\t \t \tHELP\t \t \t \n");
            printf("This game is based on one reality show.In this game there is 15 questions and 4 options in each questions with 4 lifeline.If your answer is correct you will win some money(Rs 5000 for 1st question and will doubled in each next questions)   and  proceed to next question.Lifelines are:-\n1.Phone a friend:You can call your friend and ask question to him/her.\n2.*2:-You can answer twice even your answer is wrong.\n3.Flip the question:-The question will removed and replaced by new one.\n(Note:You can't use same lifeline twice) ");
            printf("\n \n \n 1.Press 2 to quit \n 2.Press 1 to return to mainmenu");
            a=_getch();
            if(a=='1')
                main();
            else if(a=='2')
                exit(0);
                break;
        case '4':
            system("cls");
            printf("\t \t ABOUT GAME \t \t \n");
            printf("This game is developed by Group of Sabal,Rabindra,Subash and Shrawan(Students of Pulchowk campus,Computer Engineering) ");
            printf("\n Press 2 to quit \n Press 1 to return to mainmenu");
            a=_getch();
            if(a=='1')
                main();
            else if(a=='2')
                exit(0);
                break;
        case '5':
            exit(0);

        default:
            printf("ENTER VALID KEY");
            delay(1000);
            main();
    }


     return 0;
}

void sgame()
{
    char ques[50],a[15],b[15],c[15],d[15],garbage,correct;
    int status,linenumber[15],index=0,i;
    window();
    srand(time(NULL));
    FILE *fp;
    fp=fopen("a.txt","r");
    if (fp==NULL)
        printf("File not read successfully...");

    int flag,len,linee;
    char  line1[100];


    while (1)
    {
        linee=rand()%10;
        for (i=0;i<index;i++)               ///To prevent repetition of questions
        {
            if (linenumber[i]==linee)
            {
                    linee=rand()%10;
                    i=0;
            }


        }
        linenumber[index]=linee;
        index++;


        flag=0;
        while(!feof(fp))
        {
        fgets(line1,100,fp);
        len = strlen(line1);
        if(line1[len-1] == '\n')
            {
            if (flag==linee)
                {

                    fscanf(fp,"%[^!]",&ques);
                    fscanf(fp,"%c %s %s %s %s %c",&garbage,&a,&b,&c,&d,&correct);
                    break;
                }
            else
                flag++;
            }

        }
        status=game(ques,a,b,c,d,correct);
        if (status==0)
        {
             FILE *pf;
     pf=fopen("NOONE.txt","r");



    while(!feof(pf))
    {
    fscanf(pf,"%d",&file_num);
     if(amount_won>file_num)
    {
    pf=fopen("NOONE.txt","w");
         fprintf(pf,"%d",amount_won);

        fflush(stdin);
        fclose(pf);
          break;
    }
    }
       break; }

        rewind(fp);

    }
    fclose(fp);
    closegraph();
    initwindow(1010,700,"CHEQUE");
    setfillstyle(HATCH_FILL,BLUE);
    floodfill(100,100,WHITE);
    bar(0,0,1010,700);
    floodfill(100,100,WHITE);
    setcolor(YELLOW);
     for(int i=10;i>=0;i--)
    {
            rectangle(10-i,100-i,1000-i,600-i);

    }
    settextstyle(1,HORIZ_DIR,3);
    setcolor(YELLOW);
    char damount[100];
    sprintf(damount,"CONGRATULATIONS YOU HAVE WON Rs.%d",amount_won);
    outtextxy(1,1,damount);
    setfillstyle(WIDE_DOT_FILL,RED);
    floodfill(140,250,YELLOW);
    setcolor(WHITE);
    settextstyle(1,HORIZ_DIR,5);
    outtextxy(20,110,"KBC WINNER'S CHEQUE");
    //setcolor(WHITE);
    settextstyle(1,HORIZ_DIR,2);
    outtextxy(20,220,"NAME:");
    char ch1[20]={"Rabindra Regmi"};
    char ch2[20];
    sprintf(ch2,"Rs.%d",amount_won);
    outtextxy(160,210,ch1);
    rectangle(150,200,600,250);
    outtextxy(20,320,"AMOUNT WON:");
    settextstyle(1,HORIZ_DIR,4);
    setcolor(YELLOW);
    outtextxy(350,310,ch2);
    setcolor(WHITE);
    rectangle(290,300,750,350);
     settextstyle(1,HORIZ_DIR,2);
    outtextxy(20,420,"ACCOUNT NO:");
    long int accountno=1222056745;
    char acc[100];
    int t=textwidth("ACCOUNT NO:");
    sprintf(acc,"%ld",accountno);
    settextstyle(1,HORIZ_DIR,4);
     rectangle(270,400,720,450);
    setcolor(YELLOW);
    outtextxy(t+70,410,acc);

    setcolor(YELLOW);
    settextstyle(4,HORIZ_DIR,2);
    outtextxy(820,560,"SIGNATURE");
    setlinestyle(1,1,3);
        line(820,550,990,550);
    settextstyle(5,HORIZ_DIR,4);
    setcolor(WHITE);
    outtextxy(820,510,"Rabindra");

    //delay(8000);
    getch();
    closegraph();

    main();

}



void window()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\bgi");
    initwindow(1360,700,"Sample for mini project");
    setfillstyle(SOLID_FILL,BLUE);
    floodfill(1,1,WHITE);
    bar(0,0,1360,700);


}
int game(char *ques1,char *a1,char* b1,char* c1,char* d1,char correct1)
{
    int life=1;
    char ans,displaycorrect[50],correctentry[50],phone[50],audiencepoll[50];
    sprintf(phone,"%c",correct1);
    sprintf(displaycorrect,"The correct answer is : %c               ",correct1);
    sprintf(correctentry,"CORRECT!!!!                                ");

    int x1=50,y1=215,x2=440,y2=265,x3=460,y3=900,textha1,texthb1,texthc1,texthd1,texthques1,i;
    setfillstyle(XHATCH_FILL,BLUE);
    floodfill(1,1,WHITE);
    bar(0,0,900,400);
    //code for lifeline,amount and other instructions:
    settextstyle(6,HORIZ_DIR,1);
    setcolor(YELLOW);
    outtextxy(x1,(y2+60)+100,"Press a b c or d to select an option...press 1 2 3 4 to use the lifeline...press q to quit");
    outtextxy(x1,(y2+60)+150,"1.   Phone a friend");
    readimagefile("audience.jpg",0,0,100,100);
    outtextxy(x1,(y2+60)+180,"2.   X 2");
    outtextxy(x1,(y2+60)+210,"3.   Flip the question");
    outtextxy(x1,(y2+60)+240,"4.   Audience poll");
    circle(x1+300,(y2+60)+155,10);
    circle(x1+300,(y2+60)+185,10);
    circle(x1+300,(y2+60)+215,10);
    circle(x1+300,(y2+60)+245,10);
    (life1==0)?redgreen(x1+300,(y2+60)+155,1):redgreen(x1+300,(y2+60)+155,0);
    (life2==0)?redgreen(x1+300,(y2+60)+185,1):redgreen(x1+300,(y2+60)+185,0);
    (life3==0)?redgreen(x1+300,(y2+60)+215,1):redgreen(x1+300,(y2+60)+215,0);
    (life4==0)?redgreen(x1+300,(y2+60)+245,1):redgreen(x1+300,(y2+60)+245,0);


    char arr[100],amount[100];
    int a;
    outtextxy(y3+100,50,"Amount won:");
    sprintf(arr,"Rs. %d",amount_won);
    outtextxy(y3+240,50,arr);
    rectangle(y3+100,80,y3+400,600);
    int k;
    int amtt=500;
    for(k=1;k<520;k++)
    {if(amtt<=10000000)
    {
        if (k==5||k==9||k==11)
            setcolor(WHITE);
        sprintf(amount,"%d.Rs %d",k,amtt);
        outtextxy(y3+105,590-30*k,amount);
        setcolor(YELLOW);
        circle(y3+355,597-30*k,10);
        if (amount_won>=amtt)
            redgreen(y3+355,597-30*k,1);
        if(amtt==256000)
            amtt=amtt+244000;
        else amtt=amtt*2;

    }
    else
        break;
    }




    //code for displaying questions and options:
    settextstyle(9,HORIZ_DIR,2);
    outtextxy(0,0,"Sample for mini project game");
    setcolor(YELLOW);
    textha1=textheight(a1);
    texthb1=textheight(b1);
    texthc1=textheight(c1);
    texthd1=textheight(d1);
    texthques1=textheight(ques1);
    rectangle(x1,110,y3,210);
    rectangle(x1,y1,x2,y2);
    rectangle(x3,y1,y3,y2);
    rectangle(x1,y1+60,x2,y2+60);
    rectangle(x3,y1+60,y3,y2+60);
    setcolor(WHITE);
    outtextxy(x1+10,110+50-texthques1/2,ques1);
    outtextxy(x1+10,y1+(y2-y1)/2-textha1/2,a1);
    outtextxy(x3+10,y1+(y2-y1)/2-texthb1/2,b1);
    outtextxy(x1+10,y1+60+(y2-y1)/2-texthc1/2,c1);
    outtextxy(x3+10,y1+60+(y2-y1)/2-texthd1/2,d1);


    char timer[10];
    int j=30;
    fflush(stdin);
    while(j>=0)
    {
            if (j>=10)
                sprintf(timer,"\r00:%d",j);
            else
                sprintf(timer,"\r00:0%d",j);
            outtextxy(y2+200,100,timer);
            delay(1000);
            if (kbhit())
            {
                ans=tolower(getch());
                if (ans=='a'||ans=='b'||ans=='c'||ans=='d'||(ans=='1'&&life1==0)||(ans=='2'&&life2==0)||(ans=='3'&&life3==0)||(ans=='4'&&life4==0)||ans=='q')
                    break;
                else
                    fflush(stdin);
            }
            if (j==0)
            {
                outtextxy(x1,(y2+60)+50,"TIME UP!!!!!!!!              ");
                getch();
                ans='e';
            }
            j--;

    }


while(1)
{
     //case for quit
    if (ans=='q')
    {
        outtextxy(x1,(y2+60)+50,"You have decide to quit with won money..press any key                                  ");
        getch();
        return 0;

    }


     //case for lifeline:
    if (ans=='1'&&life1==0)
    {
        redgreen(x1+300,(y2+60)+155,2);
        outtextxy(x1,(y2+60)+50,"Calling......");
        Beep(220,500);
        Beep(220,500);
        delay(2000);
        outtextxy(x1,(y2+60)+50,"Friend's answer =                        ");
        outtextxy(x1+300,(y2+60)+50,phone);
        life1++;
        ans=tolower(getch());
    }

    if (ans=='2'&&life2==0)
    {
        redgreen(x1+300,(y2+60)+185,2);
        life--;
        life2++;
        ans=tolower(getch());
    }

    if (ans=='3'&&life3==0)
    {
        redgreen(x1+300,(y2+60)+215,2);
        life3 ++;
        return 1;
    }

    if (ans=='4'&&life4==0)
    {
        redgreen(x1+300,(y2+60)+245,2);
        int perA,perB,perC,perD,perCorrect,totalleft;
        srand(time(0));
        perCorrect=rand()%40+40;
        totalleft=100-perCorrect;
        if (correct1=='a')
        {
            perA=perCorrect;
            perC=rand()%totalleft;
            perB=rand()%(totalleft-perC);
            perD=totalleft-perB-perD;
        }
        else if (correct1=='b')
        {
            perB=perCorrect;
            perA=rand()%totalleft;
            perC=rand()%(totalleft-perA);
            perD=totalleft-perA-perC;
        }
        else if (correct1=='c')
        {
            perC=perCorrect;
            perA=rand()%totalleft;
            perB=rand()%(totalleft-perA);
            perD=totalleft-perA-perB;
        }
        else
        {
            perD=perCorrect;
            perA=rand()%totalleft;
            perB=rand()%(totalleft-perA);
            perC=totalleft-perA-perB;
        }
        sprintf(audiencepoll,"A:%d\%% B:%d\%% C:%d\%% D:%d\%%",perA,perB,perC,perD);
        outtextxy(x1,(y2+60)+50,audiencepoll);
        life4 ++;
        ans=tolower(getch());
    }


    while (life<2)
    {
        life++;
    //case for correct answer
        if (ans=='a'&&ans==correct1)
            correct(x1,y1,x2,y2);
        else if (ans=='b'&&ans==correct1)
            correct(x3,y1,y3,y2);
        else if (ans=='c'&&ans==correct1)
            correct(x1,y1+60,x2,y2+60);
        else if (ans=='d'&&ans==correct1)
            correct(x3,y1+60,y3,y2+60);
        if (ans==correct1)
        {
                outtextxy(x1,(y2+60)+50,correctentry);
                break;
        }

    //case for wrong answer
        if (ans=='a'&&ans!=correct1)
            wrong(x1,y1,x2,y2);
        else if (ans=='b'&&ans!=correct1)
            wrong(x3,y1,y3,y2);
        else if (ans=='c'&&ans!=correct1)
            wrong(x1,y1+60,x2,y2+60);
        else if (ans=='d'&&ans!=correct1)
            wrong(x3,y1+60,y3,y2+60);

    //case for *2
        if (life==1&&ans==correct1)
            break;
        else if (life==1&&ans!=correct1)
            ans=tolower(getch());

    }

    //For displaying correct
    if ((ans=='a'||ans=='b'||ans=='c'||ans=='d'||ans=='e'))
    {
        if (ans!=correct1)
            outtextxy(x1,(y2+60)+50,displaycorrect);
        break;
    }
    else
    {
        outtextxy(x1,(y2+60)+50,"input answer                                   ");
        ans=tolower(getch());
        life--;
    }

 }




    getch();
    cleardevice();
    if (ans==correct1)
        return 1;
    else
        return 0;

}

void correct(int a,int b,int c,int d)
{
    int i;
    if(amount_won==0)
    amount_won=amount_won+500;
    else amount_won=amount_won*2;


        rectangle(a,b,c,d);
        setfillstyle(HATCH_FILL,YELLOW);
        floodfill(a+1,b+1,WHITE);
        delay(2000);
        for (i=0;i<5;i++)
        {
            if (i%2==0)
            {
                setfillstyle(HATCH_FILL,GREEN);
                rectangle(a,b,c,d);
                floodfill(a+1,b+1,WHITE);
                delay(300);
            }
            else
            {
                setfillstyle(HATCH_FILL,BLUE);
                rectangle(a,b,c,d);
                floodfill(a+1,b+1,WHITE);
                delay(300);
            }
         }

}

void wrong(int a,int b,int c,int d)
{
        rectangle(a,b,c,d);
        int i;
        setfillstyle(HATCH_FILL,YELLOW);
        floodfill(a+1,b+1,WHITE);
        delay(2000);
        for (i=0;i<5;i++)
        {
            if (i%2==0)
            {
                setfillstyle(HATCH_FILL,RED);
                rectangle(a,b,c,d);
                floodfill(a+1,b+1,WHITE);
                delay(300);
            }
            else
            {
                setfillstyle(HATCH_FILL,BLUE);
                rectangle(a,b,c,d);
                floodfill(a+1,b+1,WHITE);
                delay(300);
            }
         }
}

void redgreen(int x,int y, int greenred)
{
    switch(greenred)
    {
        case 0:
        {
            setfillstyle(SOLID_FILL,RED);
            floodfill(x,y,YELLOW);
            break;
        }
        case 1:
        {
            setfillstyle(SOLID_FILL,GREEN);
            floodfill(x,y,YELLOW);
            break;
        }
        case 2:
        {
            setfillstyle(SOLID_FILL,YELLOW);
            floodfill(x,y,YELLOW);
            break;
        }
    }

}

