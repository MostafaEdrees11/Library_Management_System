#include "definition.h"

extern struct Users *first_user ;
extern struct Books *head_book ;
struct Users *check_list ;
struct Make_request *first_request = NULL , *last_request , *ptr_request ;
struct request_for_future_books *fir_req_provided = NULL , *last_req_provided , *provided_req ;
int total_price = 0 ;
int Entered_id ;

void User_mode(void)
{
	int choose_option , buy_or_not = 1 , enter_again_or_not;
	check_list = first_user ;
	
	printf("Enter your id : ");
	scanf("%d",&Entered_id);
	
	while(check_list != NULL)
	{
		if(Entered_id == check_list->user_id)
		{
			check_user_name(check_list->user_user_name , check_list->user_pass);
			
			do
			{
				printf("\n***********************************************\n");
				printf("**1- For view the user data.                 **\n");
				printf("**2- For change user password.               **\n");
				printf("**3- For view all books data.                **\n");
				printf("**4- For search a book                       **\n");
				printf("**5- For make a request to borrow a book     **\n");
				printf("**6- For Buy an available book               **\n");
				printf("**7- For provided a book in the future       **\n");
				printf("**8- For showing requests status             **\n");
				printf("**9- For log out                             **\n");
				printf("***********************************************\n");
			
				printf("\nYou choose : ");
				scanf("%d",&choose_option);
			
			
			
				switch(choose_option)
				{
					case 1 :
					{
						printf("\n--------------------------\n");
						printf("Id : %d\nName : %s\n",check_list->user_id ,check_list->user_user_name );
						printf("Password : %d\nNum of borrowed books : %d\n",check_list->user_pass ,check_list->num_of_borrow_books);
						printf("--------------------------\n");
						break;
					}
					case 2 :
					{
						int new_password ;
						printf("Enter new password : ");
						scanf("%d",&new_password);
						check_list->user_pass = new_password ;
						start_system();
						break;
					}
					case 3 :
					{
						view_all_books_data(head_book);
						break;
					}
					case 4 :
					{
						search_book();
						break;
					}
					case 5 :
					{
						Make_Request();
						start_system();
						break;
					}
					case 6 :
					{
						Buy_Book();
						while(1)
						{
							printf("\nDo you want to buy anthor book ?\n");
							printf("****************\n");
							printf("1- for yes\n");
							printf("1- for no\n");
							printf("****************\n");
							scanf("%d",&buy_or_not);
							if(buy_or_not == 1)
							{
								Buy_Book();
							}
							else
							{
								printf("The totel price is : %d\n", total_price);
								Pay(check_list->library_card);
								break;
							}
						}
						break;
					}
					case 7 :
					{
						provided_book_in_future();
						break;
					}
					case 8 :
					{
						Showing_requests_status();
						delete_requestes();
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
		check_list = check_list->next_user;
	}
}



void Make_Request(void)
{
	int id ;
	printf("Enter the id of the book : ");
	scanf("%d",&id);
	
	struct Books *ptr_book ;
	ptr_book = head_book ;
	
	while(ptr_book != NULL)
	{
		if(id == ptr_book->book_id)
		{
			if(first_request == NULL)
			{
				last_request = (struct Make_request *)malloc(sizeof(struct Make_request));
				first_request = last_request ;
			}
			else
			{
				ptr_request = first_request ;
				while(ptr_request->next_request != NULL)
				{
					ptr_request = ptr_request->next_request ;
				}
				last_request = (struct Make_request *)malloc(sizeof(struct Make_request));
				ptr_request->next_request = last_request ;
			}
			last_request->id_of_book = ptr_book->book_id;
			strcpy(last_request->name_of_book , ptr_book->book_name);
			strcpy(last_request->author_name_of_book , ptr_book->author_name);
			strcpy(last_request->state_book , ptr_book->book_state);
			last_request->id_of_user = check_list->user_id ;
			last_request->next_request = NULL ;
			break;
		}
		ptr_book = ptr_book->next_book;
	}
}


void Showing_requests_status(void)
{
	struct Make_request *print_requests ;
	print_requests = first_request ;
	
	struct Users *ptr_user = first_user ;
	while(ptr_user != NULL)
	{
		if(ptr_user->user_id == Entered_id)
		{
			while(print_requests != NULL)
			{
				printf("\n-------------------------------------------\n");
				printf("User Id : %d\n",print_requests->id_of_user);
				printf("Book Id : %d\n",print_requests->id_of_book);
				printf("Book Name : %s\n",print_requests->name_of_book);
				printf("Author Name : %s\n",print_requests->author_name_of_book);
				printf("Book State : %s\n",print_requests->state_book);
				printf("-------------------------------------------\n");
		
				printf("Request State : \n");
				if(print_requests->request_state == 1)
				{
					printf("Your request is approved.\n");
				}
				else if(print_requests->request_state == 2)
				{
					printf("Your request is denied.\n");
				}
				else
				{
					printf("Your request is waiting.\n");
				}
				print_requests = print_requests->next_request ;
			}
		}
		ptr_user = ptr_user->next_user;
	}
} 


void Buy_Book(void)
{
	int id ;
	printf("Enter the id of the book : ");
	scanf("%d",&id);
	
	struct Books *ptr ;
	ptr = head_book ;
	
	while(ptr != NULL)
	{
		if(id == ptr->book_id)
		{
			if(strcmp(ptr->book_state , "Available") == 0)
			{
				printf("The book is available\n");
				printf("You can buy it.\n");
				total_price += ptr->book_price ;
				strcpy(ptr->book_state , "Not Available");
			}
			else
			{
				printf("Sorry, The book is not available\n");
				printf("You can not buy it.");
			}
		}
		ptr = ptr->next_book;
	}
}


void Pay(int library_card)
{
	int pay_way ;
	printf("Enter the way that you will pay with it : \n");
	printf("1- for Cash\n");
	printf("2- for Library Card\n");
	
	printf("\nYou choose : ");
	scanf("%d",&pay_way);
	
	if(pay_way == 1)
	{
		printf("You will pay cash.\n");
		printf("You should pay : %d\n",total_price);
	}
	else if(pay_way == 2)
	{
		if(library_card >= total_price)
		{
			printf("Paid Done\n");
			printf("You have balance %d in library card\n",library_card-total_price);		
		}
		else
		{
			printf("You don't have enough money in your card\n");
			printf("You should pay cash\n");
			printf("You should pay : %d\n",total_price);
			total_price = 0;
		}
	}
}



void provided_book_in_future(void)
{
	char name_of_book[30] , name_of_author[30] ;
	if(fir_req_provided == NULL)
	{
		last_req_provided = (struct request_for_future_books *)malloc(sizeof(struct request_for_future_books));
		fir_req_provided = last_req_provided;
	}
	else
	{
		provided_req = fir_req_provided;
		while(provided_req->next_request_provided != NULL)
		{
			provided_req = provided_req->next_request_provided ;
		}
		last_req_provided = (struct request_for_future_books *)malloc(sizeof(struct request_for_future_books));
		provided_req->next_request_provided = last_req_provided ;
	}
	
	
	fflush(stdin);
	
	printf("Enter the Book Name : ");
	gets(last_req_provided->name_of_book);
	
	fflush(stdin);
	
	printf("Enter the Author Name : ");
	gets(last_req_provided->author_name_of_book);
	
	printf("This Book will provided in soon time.\n");
	printf("Book Name : %s\n",last_req_provided->name_of_book);
	printf("Author Name : %s\n",last_req_provided->author_name_of_book);
	
	
}