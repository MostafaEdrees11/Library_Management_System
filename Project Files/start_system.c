#include "definition.h"


struct Owner owner = {1234 , "Owner"} ;
extern struct Admins *first_admin ;
extern struct Users *first_user ;
struct Books *head_book ;
extern int tries ;

void add_admin_user_book(void)
{
	first_admin = add_new_admin(first_admin , 1 , 1010 , "Admin1");
	first_admin = add_new_admin(first_admin , 2 , 2020 , "Admin2");
	first_admin = add_new_admin(first_admin , 3 , 3030 , "Admin3");
	
	first_user = add_new_user(first_user , 1 , 1111 , "User1" , 0 , 10);
	first_user = add_new_user(first_user , 2 , 2222 , "User2" , 0 , 20);
	first_user = add_new_user(first_user , 3 , 3333 , "User3" , 0 , 30);
	
	head_book = Add_Books(head_book , 1 , "Hamlet" , "William Shakespeare" , "Available" , 5);
	head_book = Add_Books(head_book , 2 , "Richard II" , "William Shakespeare" , "Available", 10);
	head_book = Add_Books(head_book , 3 , "As You Like It" , "William Shakespeare" , "Available", 15);
	head_book = Add_Books(head_book , 4 , "King Lear" , "William Shakespeare" , "Available", 20);
	head_book = Add_Books(head_book , 5 , "The Tempest" , "William Shakespeare" , "Not Available", 25);

	head_book = Add_Books(head_book , 6 , "Ulysses" , "James Joyce" , "Not Available", 30);
	head_book = Add_Books(head_book , 7 , "Finn's Hotel" , "James Joyce" , "Available", 35);
	head_book = Add_Books(head_book , 8 , "Dubliners" , "James Joyce" , "Available", 40);
	head_book = Add_Books(head_book , 9 , "Finnegans Wake" , "James Joyce" , "Available", 45);
	head_book = Add_Books(head_book , 10 , "Chamber Music" , "James Joyce" , "Available", 50);
	head_book = Add_Books(head_book , 11 , "UStephen Hero" , "James Joyce" , "Available", 55);

	head_book = Add_Books(head_book , 12 , "Tomb of Sand" , "Geetanjali Shree’s" , "Available", 60);
	head_book = Add_Books(head_book , 13 , "Between Two Worlds" , "Geetanjali Shree’s" , "Available", 65);

	head_book = Add_Books(head_book , 14 , "War and Peace" , "Leo Tolstoy" , "Available", 70);
	head_book = Add_Books(head_book , 15 , "The Great Gatsby" , "F. Scott Fitzgerald" , "Available", 75);
	head_book = Add_Books(head_book , 16 , "Don Quixote" , "Miguel de Cervantes" , "Available", 80);
	head_book = Add_Books(head_book , 17 , "Hear Yourself" , "Prem Rawat" , "Available", 85);
	head_book = Add_Books(head_book , 18 , "Lal Salam" , "Smriti Irani" , "Available", 90);
	head_book = Add_Books(head_book , 19 , "Queen of Fire" , "Devika Rangachari" , "Available", 95);
	head_book = Add_Books(head_book , 20 , "When Breath Becomes Air" , "Paul Kalanithi" , "Available", 100);
	
	
}
void start_system(void)
{
	
	int choose_mode = 0 ;
	printf("***********************\n");
	printf("** 1- for owner mode **\n");
	printf("** 2- for admin mode **\n");
	printf("** 3- for user mode  **\n");
	printf("***********************\n");
	
	printf("You choose : ");
	scanf("%d",&choose_mode);
	
	switch(choose_mode)
	{
		case 1 :
		{
			printf("\t\t\t**Owner Mode**\n\n");
			check_user_name(owner.owner_user_name , owner.owner_pass);
			Owner_mode();
			restart_system();
			break;
		}
		case 2 :
		{
			printf("\t\t\t**Admin Mode**\n\n");
			Admin_mode();
			restart_system();
			break;
		}
		case 3 :
		{
			printf("\t\t\t**User Mode**\n\n");
			User_mode();
			restart_system();
			break;
		}
		default :
		{
			printf("You Enter invalid choose\n");
			restart_system();
			break;
		}
	}
}


void restart_system(void)
{
	int restart_choose = 0 ;
	tries = 0;
	printf("\n");
	printf("****************\n");
	printf("** Run again? **\n");
	printf("** 1- yes     **\n");
	printf("** 2- no      **\n");
	printf("****************\n");
	
	printf("You choose : ");
	scanf("%d",&restart_choose);
	
	switch(restart_choose)
	{
		case 1 :
		{
			start_system();
			break;
		}
		case 2 :
		{
			printf("End program\n");
			exit(0);
			break;
		}
		default :
		{
			printf("You Enter invalid choose\n");
			restart_system();
			break;
		}
	}
}