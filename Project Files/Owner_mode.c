#include "definition.h" 

extern struct Admins *first_admin , *new_admin ;
int per_for_add_or_remove_member = 1 ;
int per_for_add_or_remove_book = 1 ;
int per_for_make_book_reserved = 1 ;


void Owner_mode(void)
{
	int permission_choose , enter_again_or_not;

	do
	{
		printf("\n*****************************************\n");
		printf("** 1- For add new admin or remove admin**\n");
		printf("** 2- Ask for permission               **\n");
		printf("*****************************************\n");

		printf("You choose : ");	
		scanf("%d",&permission_choose);

		switch(permission_choose)
		{
			case 1 : 
			{
				add_admin_or_remove();
				new_admin = first_admin ;
		
				while(new_admin != NULL)
				{
					printf("%d %s\n",new_admin->admin_id ,new_admin->admin_user_name);
					new_admin = new_admin->next_admin ;
				}
				break;
			}
			case 2 :
			{
				ask_for_permission();
				break;
			}
		}
		printf("Do you want to do anthor thing?\n");
		printf("****************\n");
		printf("** 1- yes     **\n");
		printf("** 2- no      **\n");
		printf("****************\n");
		scanf("%d",&enter_again_or_not);
	}while(enter_again_or_not == 1);
	
}



void ask_for_permission(void)
{
	printf("Ask for permission : \n");
	printf("Do you want to give the admin permission for add or remove member ?\n");
	printf("****************\n");
	printf("** 1- yes     **\n");
	printf("** 2- no      **\n");
	printf("****************\n");
	scanf("%d",&per_for_add_or_remove_member);
	
	while(per_for_add_or_remove_member != 1 && per_for_add_or_remove_member != 2)
	{
		printf("You enter invalid choose\n");
		scanf("%d",&per_for_add_or_remove_member);
	}
	
	printf("Do you want to give the admin permission for add or remove book ?\n");
	printf("****************\n");
	printf("** 1- yes     **\n");
	printf("** 2- no      **\n");
	printf("****************\n");
	scanf("%d",&per_for_add_or_remove_book);
	
	while(per_for_add_or_remove_book != 1 && per_for_add_or_remove_book != 2)
	{
		printf("You enter invalid choose\n");
		scanf("%d",&per_for_add_or_remove_book);
	}
	
	
	printf("Do you want to give the admin permission for make a book reservation ?\n");
	printf("****************\n");
	printf("** 1- yes     **\n");
	printf("** 2- no      **\n");
	printf("****************\n");
	scanf("%d",&per_for_make_book_reserved);
	
	while(per_for_make_book_reserved != 1 && per_for_make_book_reserved != 2)
	{
		printf("You enter invalid choose\n");
		scanf("%d",&per_for_make_book_reserved);
	}
	
}

