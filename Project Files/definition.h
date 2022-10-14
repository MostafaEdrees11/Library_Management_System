#ifndef FILE_H
#define FILE_H

//header files
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//Struct definition
struct Owner
{
	int owner_pass ;
	char owner_user_name[10] ;	
};

struct Admins
{
	int admin_id ;
	int admin_pass ;
	char admin_user_name[10] ;
	struct Admins *next_admin ;
};

struct Make_request
{
	int id_of_book , id_of_user , request_state ;
	char name_of_book[30] , author_name_of_book[30] , state_book[20] ;
	struct Make_request *next_request ;
};


struct Users
{
	int user_id ;
	int user_pass ;
	int num_of_borrow_books ;
	int library_card ;
	char user_user_name[10] ;
	struct Users *next_user ;
};


struct Books
{
	int book_id ;
	int book_price;
	char book_name[30] ;
	char author_name[30] ;
	char book_state[20] ;
	struct Books *next_book ;
};

struct request_for_future_books
{
	char name_of_book[30] , author_name_of_book[30] ;
	struct request_for_future_books *next_request_provided ;
};




//Functions Prototybes
void add_admin_user_book(void);
void start_system(void);
void restart_system(void);
void ask_for_permission(void);
void check_user_name(char user_name[10] , int password);
void check_password(int password);
struct Admins * add_new_admin(struct Admins *head_admin , int id , int password , char user_name[10]);
void add_admin_or_remove(void);
void Owner_mode(void);
void Admin_mode(void);
void User_mode(void);
struct Users * add_new_user(struct Users *head_user , int id , int password , char user_name[10] , int num_of_borrow_books , int library_card);
void add_user_or_remove(void);
void view_all_users_data(void);
void Edit_user_id(void);
struct Books * Add_Books(struct Books *first_book , int id , char name[30] , char auth_name[30] , char state[20] , int price);
void view_all_books_data(struct Books *first_book);
void add_book_or_remove(void);
void search_book(void);
void Make_Request(void);
void show_requestes(void);
void delete_requestes(void);
void Showing_requests_status(void);
void borrow_books(void);
void Buy_Book(void);
void Pay(int library_card);
void make_a_reserved_book_available(void);
void Reserve_book(void);
void provided_book_in_future(void);




#endif

