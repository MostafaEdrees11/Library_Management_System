#include "definition.h" 


extern struct Books *head_book ;
struct Books *last_book ;
int end ;

struct Books * Add_Books(struct Books *first_book , int id , char name[30] , char auth_name[30] , char state[20] , int price)
{
	struct Books *check_books , *last_book ;
	if(first_book == NULL)
	{
		last_book = (struct Books *)malloc(sizeof(struct Books));
		first_book = last_book ;
	}
	else
	{
		check_books = first_book ;
		while(check_books->next_book != NULL)
		{
			check_books = check_books->next_book ;
		}
		last_book = (struct Books *)malloc(sizeof(struct Books));
		check_books->next_book = last_book ;
	}
	last_book->book_id = id ;
	last_book->book_price = price ;
	strcpy(last_book->book_name , name);
	strcpy(last_book->author_name , auth_name);
	strcpy(last_book->book_state , state);
	last_book->next_book = NULL;
	
	end = last_book->book_id ;
	
	return first_book ;
}

void view_all_books_data(struct Books *first_book)
{
	struct Books *ptr = first_book ;
	printf("----------------------------------------------------------------------------------------\n");
	printf("Id : \t| Book Name : \t\t\t| Book Author Name : \t| State : \t| Price\n");
	printf("----------------------------------------------------------------------------------------\n");
	while(ptr != NULL)
	{
		while(strlen(ptr->book_name) < 24)
		{
			strcat(ptr->book_name , " ");
		}
		while(strlen(ptr->author_name) < 20)
		{
			strcat(ptr->author_name , " ");
		}
		printf("%d\t| %s\t| %s\t| %s\t| %d\n",ptr->book_id ,ptr->book_name ,ptr->author_name ,ptr->book_state ,ptr->book_price);
		ptr = ptr->next_book ;
	}
}


void add_book_or_remove(void)
{
	int add_book_or_not , new_book_id , new_book_price , remove_id ;
	char new_book_name[30] , new_book_author_name[30] ;
	
	printf("\n");
	printf("*************************************************\n");
	printf("Do you need to add new book or remove book :   **\n");
	printf("** 1- Add                                      **\n");
	printf("** 2- Remove                                   **\n");
	printf("*************************************************\n");
	printf("You choose : ");
	scanf("%d",&add_book_or_not);
	switch(add_book_or_not)
	{
		case 1 :
		{
			printf("Enter book id : ");
			scanf("%d",&new_book_id);
			printf("Enter book name : ");
			scanf("%s",&new_book_name);
			printf("Enter book author name : ");
			scanf("%s",&new_book_author_name);
			printf("Enter book price : ");
			scanf("%d",&new_book_price);
			printf("\n==============================================================\n");
			printf("id : %d\t Book name : %s\t Book author name : %s\n",new_book_id ,new_book_name ,new_book_author_name);
			printf("================================================================\n");
			head_book = Add_Books(head_book , new_book_id , new_book_name , new_book_author_name , "Available" , new_book_price);
			break;
		}
		case 2 :
		{
			printf("Enter id of the book that yoy need to remove : ");
			scanf("%d",&remove_id);
			struct Books *check_list , *previous_book ;
			check_list = head_book ;
			previous_book = NULL ; 
			while(check_list != NULL)
			{
				if(remove_id == check_list->book_id)
				{
					printf("=============================================================\n");
					printf("id : %d\t Book name : %s\t Book author name : %s\n",check_list->book_id ,check_list->book_name ,check_list->author_name);
					printf("=============================================================\n");
					if(head_book == check_list)
					{
						head_book = head_book->next_book;
						free(check_list);
					}
					else
					{
						previous_book->next_book = check_list->next_book;
						free(check_list);
						previous_book = NULL ;
					}
				}
				previous_book = check_list ;
				check_list = check_list->next_book;
			}
			break;
		}
	}
}