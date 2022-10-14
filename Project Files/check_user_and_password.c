#include "definition.h"


int tries = 0 ;

void check_user_name(char user_name[10] , int password)
{
	char Enterd_user_name[10];
	printf("User Name : ");
	scanf("%s",&Enterd_user_name);
	
	if(strcmp(user_name , Enterd_user_name) == 0)
	{
		check_password(password);
		tries = 0; 
	}
	else
	{
		printf("You enter wrong user name\n");
		tries++;
		if(tries >= 3)
		{
			printf("You Enter 3 times wrong\n");
			restart_system();
		}
		else
		{
			check_user_name(user_name , password);
		}
	}
}


void check_password(int password)
{
	int Enterd_password ;
	printf("Password : ");
	scanf("%d",&Enterd_password);
	
	if(password == Enterd_password)
	{
		printf("\t\t\t****Welcome to Library management system****\n");
	}
	else
	{
		printf("You enter wrong password\n");
		tries++;
		if(tries >= 3)
		{
			printf("You Enter 3 times wrong\n");
			restart_system();
		}
		else
		{
			check_password(password);
		}
	}
}