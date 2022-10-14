#include "definition.h" 

struct Users *first_user  , *last_user , *new_user ;

struct Users * add_new_user(struct Users *head_user , int id , int password , char user_name[10] , int num_of_borrow_books , int library_card)
{
	struct Users *check_list;
	if(head_user == NULL)
	{
		last_user = (struct Users *)malloc(sizeof(struct Users));
		head_user = last_user;
	}
	else
	{
		check_list = head_user ;
		while(check_list->next_user != NULL)
		{
			check_list = check_list->next_user ;
		}
		last_user = (struct Users *)malloc(sizeof(struct Users));
		check_list->next_user = last_user ;
	}
	last_user->user_id = id ;
	strcpy(last_user->user_user_name , user_name);
	last_user->user_pass = password ;
	last_user->num_of_borrow_books = num_of_borrow_books;
	last_user->library_card = library_card;
	last_user->next_user = NULL;
	
	return head_user ;
}



void add_user_or_remove(void)
{
	int add_user_or_not , new_id , new_pass , num_of_books , remove_id , library_card;
	char new_user_name[10] ;
	
	printf("\n");
	printf("*************************************************\n");
	printf("Do you need to add new user or remove user :   **\n");
	printf("** 1- Add                                      **\n");
	printf("** 2- Remove                                   **\n");
	printf("*************************************************\n");
	printf("You choose : ");
	scanf("%d",&add_user_or_not);
	switch(add_user_or_not)
	{
		case 1 :
		{
			printf("Enter id : ");
			scanf("%d",&new_id);
			printf("Enter user name : ");
			scanf("%s",&new_user_name);
			printf("Enter password : ");
			scanf("%d",&new_pass);
			printf("Enter number of borrow books : ");
			scanf("%d",&num_of_books);
			printf("Enter the balance of library card : ");
			scanf("%d",&library_card);
			printf("\n=====================================================\n");
			printf("id : %d\t name : %s\t password : %d\n",new_id ,new_user_name ,new_pass);
			printf("=====================================================\n");
			add_new_user(first_user , new_id , new_pass , new_user_name , num_of_books , library_card);
			break;
		}
		case 2 :
		{
			printf("Enter id that yoy need to remove : ");
			scanf("%d",&remove_id);
			struct Users *check_list , *previous_user ;
			check_list = first_user ;
			previous_user = NULL ; 
			while(check_list != NULL)
			{
				if(remove_id == check_list->user_id)
				{
					printf("=====================================================\n");
					printf("id : %d\t name : %s\t password : %d\n",check_list->user_id ,check_list->user_user_name ,check_list->user_pass);
					printf("=====================================================\n");
					if(first_user == check_list)
					{
						first_user = first_user->next_user;
						free(check_list);
					}
					else
					{
						previous_user->next_user = check_list->next_user;
						free(check_list);
						previous_user = NULL ;
					}
					
				}
				previous_user = check_list ;
				check_list = check_list->next_user;
			}
			break;
		}
	}
}
