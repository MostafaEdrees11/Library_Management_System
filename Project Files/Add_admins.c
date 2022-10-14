#include "definition.h" 

struct Admins *first_admin  , *last_admin , *new_admin ;

struct Admins * add_new_admin(struct Admins *head_admin , int id , int password , char user_name[10])
{
	struct Admins *check_list;
	if(head_admin == NULL)
	{
		last_admin = (struct Admins *)malloc(sizeof(struct Admins));
		head_admin = last_admin;
	}
	else
	{
		check_list = head_admin ;
		while(check_list->next_admin != NULL)
		{
			check_list = check_list->next_admin ;
		}
		last_admin = (struct Admins *)malloc(sizeof(struct Admins));
		check_list->next_admin = last_admin ;
	}
	last_admin->admin_id = id ;
	strcpy(last_admin->admin_user_name , user_name);
	last_admin->admin_pass = password ;
	last_admin->next_admin = NULL;
	
	return head_admin ;
}



void add_admin_or_remove(void)
{
	int add_admin_or_not , new_id , new_pass , remove_id ;
	char new_user_name[10] ;
	
	printf("\n");
	printf("*************************************************\n");
	printf("Do you need to add new admin or remove admin : **\n");
	printf("** 1- Add                                      **\n");
	printf("** 2- Remove                                   **\n");
	printf("*************************************************\n");
	printf("You choose : ");
	scanf("%d",&add_admin_or_not);
	switch(add_admin_or_not)
	{
		case 1 :
		{
			printf("Enter id : ");
			scanf("%d",&new_id);
			printf("Enter user name : ");
			scanf("%s",&new_user_name);
			printf("Enter password : ");
			scanf("%d",&new_pass);
			add_new_admin(first_admin , new_id , new_pass , new_user_name);
			break;
		}
		case 2 :
		{
			printf("Enter id that yoy need to remove : ");
			scanf("%d",&remove_id);
			struct Admins *check_list , *previous_admin ;
			check_list = first_admin ;
			previous_admin = NULL ; 
			while(check_list != NULL)
			{
				if(remove_id == check_list->admin_id)
				{
					if(first_admin == check_list)
					{
						first_admin = first_admin->next_admin;
						free(check_list);
					}
					else
					{
						previous_admin->next_admin = check_list->next_admin;
						free(check_list);
						previous_admin = NULL ;
					}
				}
				previous_admin = check_list ;
				check_list = check_list->next_admin;
			}
			break;
		}
	}
}
