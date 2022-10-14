#include "definition.h" 

extern struct Admins *first_admin ;
extern struct Users *first_user , *new_user ;
extern struct Books *head_book ;
extern struct Make_request *first_request , *last_request ;
extern int end ;
extern int per_for_add_or_remove_member ;
extern int per_for_add_or_remove_book ;
extern int per_for_make_book_reserved ;

void Admin_mode(void)
{
	int Entered_id , choose_option , reserve_book , enter_again_or_not;
	struct Admins *check_list = first_admin ;
	
	printf("Enter your id : ");
	scanf("%d",&Entered_id);
	
	while(check_list != NULL)
	{
		if(Entered_id == check_list->admin_id)
		{
			check_user_name(check_list->admin_user_name , check_list->admin_pass);
			
			do
			{
				printf("\n***********************************************\n");
				printf("**1- For view all users's data               **\n");
				printf("**2- For view all books data                 **\n");
				printf("**3- For add or remove a book to/from library**\n");
				printf("**4- For add or remove  users                **\n");
				printf("**5- For edit user id                        **\n");
				printf("**6- For search a book                       **\n");
				printf("**7- For reserve a book                      **\n");
				printf("**8- For make a reserved book available      **\n");
				printf("**9- For log out                             **\n");
				printf("***********************************************\n");
				
				printf("\nYou choose : ");
				scanf("%d",&choose_option);
				
				switch(choose_option)
				{
					case 1 :
					{
						view_all_users_data();
						break;
					}
					case 2 :
					{
						view_all_books_data(head_book);
						break;
					}
					case 3 :
					{
						if(per_for_add_or_remove_book == 1)
						{
							add_book_or_remove();
						}
						else if(per_for_add_or_remove_book == 2)
						{
							printf("You don't have access for that.\n");
						}
						break;
					}
					case 4 :
					{
						if(per_for_add_or_remove_member == 1)
						{
							add_user_or_remove();
						}
						else if(per_for_add_or_remove_member == 2)
						{
							printf("You don't have access for that.\n");
						}
						break;
					}
					case 5 :
					{
						Edit_user_id();
						break;
					}
					case 6 :
					{
						search_book();
						break;
					}
					case 7 :
					{
						if(per_for_make_book_reserved == 1)
						{
							printf("1- for Show requestes\n");
							printf("2- for Reserve a book\n");
							printf("You choose : ");
							scanf("%d",&reserve_book);
						
							if(reserve_book == 1)
							{
								show_requestes();
								start_system();
							}
							else if(reserve_book == 2)
							{
								Reserve_book();
							}
							else
							{
								printf("You enter invalid choose\n");
							}
						}
						else if(per_for_make_book_reserved == 2)
						{
							printf("You don't have access for that.\n");
						}
						break;
					}
					case 8 :
					{
						make_a_reserved_book_available();
						break;
					}
					case 9 :
					{
						exit(0);
					}
					default :
					{
						printf("You Enter invalid choose\n");
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
		check_list = check_list->next_admin;
	}
}

void view_all_users_data(void)
{
	new_user = first_user ;
	
	while(new_user != NULL)
	{
		printf("Id : %d\t User name : %s\t Password : %d\n",new_user->user_id ,new_user->user_user_name , new_user->user_pass);
		new_user = new_user->next_user ;
	}
}

void Edit_user_id(void)
{
	int old_id , new_id ;
	printf("Enter the id that you want to edit it : ");
	scanf("%d",&old_id);
	
	struct Users *check_list ;
	check_list = first_user ;
	while(check_list != NULL)
	{
		if(old_id == check_list->user_id)
		{
			printf("Id : %d\t User name : %s\t Password : %d\n",check_list->user_id ,check_list->user_user_name , check_list->user_pass);
			printf("Enter the new id : ");
			scanf("%d",&new_id);
			check_list->user_id = new_id ;
			printf("Id : %d\t User name : %s\t Password : %d\n",check_list->user_id ,check_list->user_user_name , check_list->user_pass);
		}
		check_list = check_list->next_user ;
	}
}



void search_book(void)
{
	int search_method ;
	printf("\n========================\n");
	printf("1- for book name\n");
	printf("2- for book id\n");
	printf("3- for book author\n");
	printf("========================\n");
	
	printf("Search method : ");
	scanf("%d",&search_method);
	
	struct Books *ptr ;
	ptr = head_book ;
	char b_name[30] , a_name[30] ;
	int id , start , mid ;
	switch(search_method)
	{
		case 1 :
		{
			fflush(stdin);
			printf("Enter the book name : ");
			gets(b_name);
			while(ptr->next_book != NULL)
			{
				if(strcmp(b_name , ptr->book_name) == 0)
				{
					printf("The book you search about it is : \n");
					printf("Id : %d\t Name : %s\t Author name : %s\t State : %s\n",ptr->book_id ,ptr->book_name ,ptr->author_name ,ptr->book_state);
					break;
				}
				ptr = ptr->next_book ;
				if(ptr == NULL)
					printf("This book is not exist.\n");
			}
			break;
		}
		case 2 : 
		{
			start = 1 ;
			printf("Enter the id of the book : ");
			fflush(stdin);
			scanf("%d",&id);
			
			while(start <= end)
			{
				mid = (start+end)/2 ;
				if(id > mid)
				{
					start = mid + 1 ;
				}
				else if(id < mid)
				{
					end = mid - 1 ;
				}
				else
				{
					printf("the book you search about it is : \n");
					while(ptr != NULL)
					{
						if(id == ptr->book_id)
						{
							printf("Id : %d\t Name : %s\t Author name : %s\t State : %s\n",ptr->book_id ,ptr->book_name ,ptr->author_name ,ptr->book_state);
						}
						ptr = ptr->next_book ;
					}
					break;
				}
			}
			if(start > end)
			{
				printf("This book is not exist\n");
				break;
			}
			break;
		}
		case 3 :
		{
			fflush(stdin);
			printf("Enter the book author name : ");
			gets(a_name);
			printf("the list of books you search about it is : \n");
			while(ptr != NULL)
			{
				if(strcmp(a_name , ptr->author_name) == 0)
				{
					printf("Id : %d\t Name : %s\t Author name : %s\t State : %s\n",ptr->book_id ,ptr->book_name ,ptr->author_name ,ptr->book_state);
				}
				ptr = ptr->next_book ;
				if(ptr == NULL)
					printf("Sorry, this book is not exist.\n");
			}
			break;
		}
		default :
		{
			printf("You Enter invalid choose\n");
			break;
		}
	}
}

void show_requestes(void)
{
	int admin_choose = 0 ;
	struct Make_request *print_requests , *previous ;
	struct Books *ptr_book ;
	ptr_book = head_book ;
	
	struct Users *ptr_user ;
	ptr_user = first_user ;
	
	print_requests = first_request ;
	while(print_requests != NULL)
	{
		printf("\n-------------------------------------------\n");
		printf("User Id : %d\n",print_requests->id_of_user);
		printf("Book Id : %d\n",print_requests->id_of_book);
		printf("Book Name : %s\n",print_requests->name_of_book);
		printf("Author Name : %s\n",print_requests->author_name_of_book);
		printf("Book State : %s\n",print_requests->state_book);
		printf("-------------------------------------------\n");
		
		printf("\nDo you accept?\n");
		printf("****************\n");
		printf("** 1- yes     **\n");
		printf("** 2- no      **\n");
		printf("****************\n");
		scanf("%d",&admin_choose);
		
		
		if(admin_choose == 1)
		{
			while(ptr_user != NULL)
			{
				if(print_requests->id_of_user == ptr_user->user_id)
				{
					if(ptr_user->num_of_borrow_books < 2)
					{
						while(ptr_book != NULL)
						{
							if(print_requests->id_of_book == ptr_book->book_id)
							{
								if(strcmp(ptr_book->book_state , "Available") == 0)
								{
									ptr_user->num_of_borrow_books++;
									strcpy(ptr_book->book_state , "Not Available");
									print_requests->request_state = 1 ;
								}
								else
								{
									printf("Sorry, The book is not available.\n");
									print_requests->request_state = 2 ;
								}
								break;
							}
							ptr_book = ptr_book->next_book;
						}
					}
					else
					{
						printf("Sorry, he can not borrow more than 2 books\n");
						print_requests->request_state = 2 ;
					}
					break;
				}
				ptr_user = ptr_user->next_user;
			}
		}
		print_requests = print_requests->next_request;
	}
}

void delete_requestes(void)
{
	struct Make_request *detlete_request = NULL , *check_request ;
	check_request = first_request ;
	while(check_request != NULL)
	{
		detlete_request = check_request;
		check_request = check_request->next_request;
		first_request = check_request;
		free(detlete_request);
	}
}

void Reserve_book(void)
{
	int id_of_user , id_of_book , reserve_or_not ;
	struct Users *ptr_user = first_user ;
	struct Books *ptr_book = head_book ;
	view_all_users_data();
	
	printf("\nEnter the user id : ");
	scanf("%d",&id_of_user);
	
	while(ptr_user != NULL)
	{
		if(id_of_user == ptr_user->user_id)
		{
			if(ptr_user->num_of_borrow_books < 2)
			{
				view_all_books_data(head_book);
				printf("\nEnter the book id : ");
				scanf("%d",&id_of_book);
				while(ptr_book->next_book != NULL)
				{
					if(id_of_book == ptr_book->book_id)
					{
						if(strcmp(ptr_book->book_state , "Available") == 0)
						{
							printf("Book is Reserved.\n"); 
							ptr_user->num_of_borrow_books++;
							strcpy(ptr_book->book_state , "Not Available");
							printf("Do you want to reserve anthor book ? \n");
							printf("\n1- for yes\n");
							printf("2-for no\n");
							scanf("%d",&reserve_or_not);
							if(reserve_or_not == 1)
							{
								Reserve_book();
							}
						}
						else
						{
							printf("Sorry , this book is not available\n");
							printf("Do you want to reserve anthor book ? \n");
							printf("\n1- for yes\n");
							printf("2-for no\n");
							scanf("%d",&reserve_or_not);
							if(reserve_or_not == 1)
							{
								Reserve_book();
							}
						}
						break;
					}
					ptr_book = ptr_book->next_book;
				}
			}
			else
			{
				printf("Sorry , this user can not borrow more two books\n");
			}
			break;
		}
		ptr_user = ptr_user->next_user;
	}
}


void make_a_reserved_book_available(void)
{
	int id ;
	printf("Enter the Book id : ");
	scanf("%d",&id);
	
	struct Books *ptr_book ;
	ptr_book = head_book ;
	
	while(ptr_book != NULL)
	{
		if(id == ptr_book->book_id)
		{
			strcpy(ptr_book->book_state , "Available");
			break;
		}
		ptr_book = ptr_book->next_book;
	}
}