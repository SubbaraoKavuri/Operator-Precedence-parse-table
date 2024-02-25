#include <stdio.h>
#include <string.h>

void main()
{
	char W[20],STACK[20],TERMINALS[20],
		PRECEDENCE_TABLE[20][20][1];
           char name[20];
           char rollno[15];
	int TERMINALS_N,i,j,k,IP = 0,TOP = 0,FLAG = 1,
		COLUMN,ROW; 
	for(i=0;i<20;i++)
	{
		STACK[i]=(int)NULL;
		W[i]=(int)NULL;
		for(j=0;j<20;j++)
		{
			PRECEDENCE_TABLE[i][j][1]=(int)NULL;
		}
	}
	printf("INPUT STRING WITH DOLLAR ($) SIGN  : ");
	gets(W);
printf("enter the name of the student:");
scanf("%s",name);
printf("\nenter the roll no of the student:");
scanf("%s",&rollno);
printf("\nthe name of the student is :%s",name);
printf("\nthe rollno of the student is :%s",rollno);

	printf("\nNO. OF TERMINALS  : ");
	scanf("%d",&TERMINALS_N);
	printf("\nENTER TERMINALS (SERIALLY WITHOUT SPACES) :\n");
	scanf("%s",TERMINALS);
	printf("\nENTER OPERATOR PRECEDENCE TABLE  :\n\n");
	for(i=0;i<TERMINALS_N;i++)
	{
		for(j=0;j<TERMINALS_N;j++)
		{
			printf("ENTER PRECEDENCE FOR  %c  AND  %c  : ",TERMINALS[i],TERMINALS[j]);
			_flushall();
			scanf("%c",&PRECEDENCE_TABLE[i][j]);
		}
	}
	printf("\n\n----- OPERATOR PRECEDENCE TABLE -----\n\n");
	for(i=0;i<TERMINALS_N;i++)
	{
		printf("\t%c",TERMINALS[i]);
	}
	printf("\n");
	for(i=0;i<TERMINALS_N;i++)
	{
		printf("\n%c",TERMINALS[i]);
		for(j=0;j<TERMINALS_N;j++)
		{
			printf("\t%c",PRECEDENCE_TABLE[i][j][0]);
		}
	}
	STACK[TOP] = '$';
	printf("\n");
	printf("\n\nSTACK\t\t\tINPUT STRING\t\t\tACTION\n");
	printf("\n%s\t\t\t%s\t\t\t",STACK,W);
	while(IP <= strlen(W))
	{
		for(k=0;k<TERMINALS_N;k++)
		{
			if(STACK[TOP] == TERMINALS[k])
			{
				COLUMN = k;
			}
			if(W[IP] == TERMINALS[k])
			{
				ROW = k;
			}
		}
		if((STACK[TOP] == '$') && (W[IP] == '$'))		//SUCCESSFUL PARSING
		{
			printf("\n\n\n\t----- INPUT STRING SUCCESSFULLY PARSED -----\n");
			break;
		}
		else if((PRECEDENCE_TABLE[COLUMN][ROW][0] == '<') || (PRECEDENCE_TABLE[COLUMN][ROW][0] == '='))		//PUSHING IF STACK ELEMENT IS LESS THAN OR EQUAL TO INPUT STRING ELEMENT
		{
			STACK[++TOP] = PRECEDENCE_TABLE[COLUMN][ROW][0];			//DEFINITELY NEEDED
			STACK[++TOP] = W[IP];
			printf("SHIFT OPERATION ON  %c",W[IP]);
			IP++;
		}
		else		//POPPING IF STACK ELEMENT IS GREATER THAN INPUT STRING ELEMENT
		{
			if(PRECEDENCE_TABLE[COLUMN][ROW][0] == '>')
			{
				while(STACK[TOP] != '<')
				{
					--TOP;
				}
				TOP--;			//MAY NOT BE NEEDED
				printf("REDUCE OPERATION");
			}
			else
			{
				printf("\n\n----- UNABLE TO PARSE STRING -----");
				break;
			}
		}
		printf("\n");
		for(i=0;i<=TOP;i++)
		{
			printf("%c",STACK[i]);
		}
		printf("\t\t\t");
		for(k=IP;k<strlen(W);k++)
		{
			printf("%c",W[k]);
		}
		printf("\t\t\t");
	}
}