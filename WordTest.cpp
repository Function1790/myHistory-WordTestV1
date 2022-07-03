#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#define max 12
#define line 30

int i, j, number, ch1, ch2;
char wardE[max][line], wardK[max][line]; 
char writeE[max][line], writeK[max][line], text[100]; 
char copyK[max][line], copyE[max][line];

void cls()
{
	system("cls");
}

void pause()
{
	system("pause");
}

void check()
{
	cls();
	for(i=0; i<max; i++)
	{
		if(i!=0)
		{
			printf("%d번\n영어:%s\n한글:%s\n\n", i, wardE[i], wardK[i]);
		}
	}
	pause();
}

void input()
{
	cls();
	for(i=0; i<max; i++)
	{
		printf("\n%d번\n\n영어:", i);
		gets(wardE[i]);
		if(wardE[i][0]=='!')
		{
			break;
		}
		printf("한글:");
		gets(wardK[i]);
		if(wardK[i][0]=='!')
		{
			break;
		}
	}
	pause();
}

void modify()
{
	while(1)
	{
		cls();
		check();
		printf("\n번호:");
		scanf("%d", &i);
		if(i==0)
		{
			break;	
		}
		else if(i<=max)
		{
			for(j=0; j<2; j++)
			{
				cls();
				printf("%d번\n%s:%s\n영어:", i, wardE[i], wardK[i]);
				gets(wardE[i]);
				printf("한글:");
				gets(wardK[i]);
			
			}
		}
	}
}

void testE() 
{
	cls();
	for(i=0; i<max; i++)
	{
		printf("\n%s:", wardE[i]);
		gets(writeK[i]);
		if(writeK[i][0]=='!')
		{
			break;
		}
	}
	cls();
	for(i=1; i<max; i++)
	{
		printf("\n%s:%s(%s)", wardE[i], writeK[i], wardK[i]);
	}
	printf("\n");
	pause();
}

void testK() 
{
	cls();
	for(i=0; i<max; i++)
	{
		printf("\n%s:", wardK[i]);
		gets(writeE[i]);
		if(writeE[i][0]=='!')
		{
			break;
		}
	}
	cls();
	for(i=1; i<max; i++)
	{
		printf("\n%s:%s(%s)", wardK[i], writeE[i], wardE[i]);
	}
	printf("\n");
	pause();
}

void ptcK() //영어-한글
{
	while(1)
	{
		i=rand() % max;
		if(i!=0)
		{
			cls();
			printf("%s:", wardE[i]);
			gets(text);
			printf("답:%s\n", wardK[i]);
			if(text[0]=='!')
			{
				break;
			}
			pause();
		}
	}
}

void ptcE() //한글-영어
{
	while(1)
	{
		i=rand() % max;
		if(i!=0)
		{
			cls();
			printf("%s:", wardK[i]);
			gets(text);
			printf("답:%s\n", wardE[i]);
			if(text[0]=='!')
			{
				break;
			}
			pause();
		}
	}
}

void intro() //인트로
{
	puts("	            ______________________ ");
	puts("                   /       Terry 	 / ");
	puts("                  /    C Language       /	 ");
	puts("                 /                     /   ");
	puts("                /_____________________/    ");
	pause();	
}

void check2() //단어 확인 
{
	cls();
	for(i=0; i<max; i++)
	{
		if(i!=0)
		{
			printf("%d번\n영어:%s\n한글:%s\n", i, wardE[i], wardK[i]);
		}
	}
	pause();
}

void check3()
{
	cls();
	for(i=0; i<max; i++)
	{
		if(i!=0)
		{
			printf("%d번\n영어:%s    %s\n한글:%s    %s\n\n", i, wardE[i], copyE[i], wardK[i], copyK[i]);
		}
	}
	pause();
}

void NumC() //Number Change
{
	cls();
	printf("Original Change\n");
	while(1)
	{
		check3();
		printf("O C\n입력:");
		scanf("%d %d", &ch1, &ch2);
		if(ch1==0 || ch2==0)
		{
			break;
		}
		strcpy(copyK[ch2],wardK[ch1]);
		strcpy(copyE[ch2],wardE[ch1]);
	}
	cls();
	for(i=0; i<max; i++)
	{
		strcpy(wardE[i],copyE[i]);
		strcpy(wardK[i],copyK[i]);
		printf("%d번 %s:%s\n", i, wardE[i], wardK[i]);
	}
	pause();
}

int main(void)
{
	intro;
	while(1)
	{
		cls();
		system("color 9b");
		puts("┌.────────────────────────────┐");
		puts("│    1:입력  2:확인  3:수정   │");
		puts("│    4:영시험  5:한시험       │");
		puts("│    6:영연습  7:한연습       │");
		puts("│    8:확인2   9:순서         │");
		puts("│                             │");
		puts("│                             │");
		puts("│                             │");
		puts("└'────────────────────────────┘");
		printf("입력:");
		scanf("%d", &number);
		if(number==1)
		{
			input();
		}
		else if(number==2)
		{
			check();
		}
		else if(number==3)
		{
			modify();
		}
		else if(number==4)
		{
			testE();
		}
		else if(number==5)
		{
			testK();
		}
		else if(number==6)
		{
			ptcK();
		}
		else if(number==7)
		{
			ptcK();
		}
		else if(number==8)
		{
			check2();
		}
		else if(number==9)
		{
			NumC();
		}
		else if(number==0)
		{
			break;
		}
	}
	return 0;
}
