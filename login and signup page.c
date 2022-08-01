#include <stdio.h>
#include <conio.h>
#include <string.h>

struct
{
   	char username[50];
   	char passward[50];
}enter;

void login()
{
	FILE *fp;
	int i;
	char c;
	char UserName[50],Passward[50],chku,chkp;  
	fp=fopen("data manage","rb");
	
	printf("\t\t\t\t\t\tUSERNAME  :");                               //signup
	scanf("%s",&UserName);
	//textcolor(red+blink);
    printf("\n\t\t\t\t\t\tPassward  :"); 
    c=getch();
	for(i=0;c!='\r';i++)
	{
		Passward[i]=c;
		printf("*");
		c=getch();
	}
	
	Passward[i]='\0';
	
	while(!feof(fp))
	{
	    fread(&enter,sizeof(enter),1,fp);
		chku=strcmp(UserName,enter.username);
		chkp=strcmp(Passward,enter.passward);
                         
    if(chku!=0 && chkp!=0)
        printf("\n\t\t\t\t\tINVALID USERNAME AND PASSWARD "); 
    else if(chku==0 && chkp!=0)
        printf("\n\t\t\t\t\tINVALID PASSWARD");
    else if(chku!=0 && chkp==0)
        printf("\n\t\t\t\t\tINVALID USERNAME");
    else if(chku==0 && chkp==0)
    {
    	printf("\n\n\t\t\t\t\t welcome %s in our world",enter.username);
	}
    }
}

void signup()
{
	FILE *fp;
	int i,a;
	char c;
	fp=fopen("data manage.txt","ab");
    printf("\t\t\t\t\t\tSET USERNAME  :");                               //signup
	scanf("%s",&enter.username);                                             
    printf("\n\t\t\t\t\t\tSET PASSWARD  :");
	for(i=0;c=getche()!=13;i++)
	{
		enter.passward[i]=c;
	}
	printf("\n\t\t\t\t\tpress ENTER to continue.....");
	if(getch()==13)
	{
    	fwrite(&enter,sizeof(enter),1,fp);
		printf("\n\t\t\t\t\tinformation saved sucessfully.....");
	}
	fclose(fp);
}



int main()
{
	while(1)
	{
	printf("\n\n");
	FILE *fp;
    int ENTER;
	printf("\n\t\t\t\t\t ***HELLOBOOK WELCOMES YOU***\n");
	printf("\t\t\t\t\t______________________________\n");
	printf("\n\t\t\t\t\t\tPRESS 1: SIGNUP\n\t\t\t\t\t\tPRESS 2:LOGIN\n\t\t\t\t\t\tPRESS 3: EXIT\n");
	printf("\t\t\t\t\t______________________________\n");
	scanf("%d",&ENTER);
	switch(ENTER)
	{
	    case 1:printf("\n\t\t\t\t   s \t i\tg\tn\tu\tp\n\n\n");
		       signup();
		       break;
		       
		case 2:printf("\n\t\t\t\t\t\tl\to\tg\ti\tn\n\n\n");
		       login();
		       break;
		       
		case 3:printf("\n\t\t\t\t\t\tthanks for using");
		       return 0;;
		       break;
		       
		default:printf("enter correct input");
	}
    } 
	return 0;	
}
