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
			printf("%d��\n����:%s\n�ѱ�:%s\n\n", i, wardE[i], wardK[i]);
		}
	}
	pause();
}

void input()
{
	cls();
	for(i=0; i<max; i++)
	{
		printf("\n%d��\n\n����:", i);
		gets(wardE[i]);
		if(wardE[i][0]=='!')
		{
			break;
		}
		printf("�ѱ�:");
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
		printf("\n��ȣ:");
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
				printf("%d��\n%s:%s\n����:", i, wardE[i], wardK[i]);
				gets(wardE[i]);
				printf("�ѱ�:");
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

void ptcK() //����-�ѱ�
{
	while(1)
	{
		i=rand() % max;
		if(i!=0)
		{
			cls();
			printf("%s:", wardE[i]);
			gets(text);
			printf("��:%s\n", wardK[i]);
			if(text[0]=='!')
			{
				break;
			}
			pause();
		}
	}
}

void ptcE() //�ѱ�-����
{
	while(1)
	{
		i=rand() % max;
		if(i!=0)
		{
			cls();
			printf("%s:", wardK[i]);
			gets(text);
			printf("��:%s\n", wardE[i]);
			if(text[0]=='!')
			{
				break;
			}
			pause();
		}
	}
}

void intro() //��Ʈ��
{
	puts("	            ______________________ ");
	puts("                   /       Terry 	 / ");
	puts("                  /    C Language       /	 ");
	puts("                 /                     /   ");
	puts("                /_____________________/    ");
	pause();	
}

void check2() //�ܾ� Ȯ�� 
{
	cls();
	for(i=0; i<max; i++)
	{
		if(i!=0)
		{
			printf("%d��\n����:%s\n�ѱ�:%s\n", i, wardE[i], wardK[i]);
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
			printf("%d��\n����:%s    %s\n�ѱ�:%s    %s\n\n", i, wardE[i], copyE[i], wardK[i], copyK[i]);
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
		printf("O C\n�Է�:");
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
		printf("%d�� %s:%s\n", i, wardE[i], wardK[i]);
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
		puts("��.����������������������������������������������������������");
		puts("��    1:�Է�  2:Ȯ��  3:����   ��");
		puts("��    4:������  5:�ѽ���       ��");
		puts("��    6:������  7:�ѿ���       ��");
		puts("��    8:Ȯ��2   9:����         ��");
		puts("��                             ��");
		puts("��                             ��");
		puts("��                             ��");
		puts("��'����������������������������������������������������������");
		printf("�Է�:");
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
