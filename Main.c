/*
Author : Goran Vujnovic
Project Name : Phone_book
Date created : 04/08/2023
Description : By using this file we can save contacts and do these operations in it.
   0) stop the program
   1) load users
   2) add a user
   3) view all users
   4) remove a user
*/


// Included the headers
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


// Macro definitions
#define stop_the_program   0
#define load_users         1
#define add_a_user         2
#define view_all_users     3
#define remove_a_user      4


// Global variables.
const char* filename = "Format_Imenika.txt";
int counter = 0;


// Defining user data type.
typedef struct
{
	char name[20];
	char surname[20];
	char number[20];

}User;
User arrey[20];


// All function prototypes.
void Print_menu();
void Stop_the_program();
void Load_users();
int Adding_users_to_the_arrey();
void View_all_users();
void Add_a_user();
void Add_new_user_in_txt();


// This will print main menu.
void Print_menu()
{
    printf("\n\n");
    printf("\t\t****************************************************************\n");
    printf("\t\t*                  Welcome TO My phone book                    *\n");
    printf("\t\t****************************************************************\n\n");
    printf("\t\t\t0) Stop the program\n\n");
    printf("\t\t\t1) Load users\n\n");
    printf("\t\t\t2) Add a user\n\n");
    printf("\t\t\t3) View all users\n\n");
    printf("\t\t\t4) Remove a user\n\n");
    printf("\t\t\t\tEnter your Choice : ");
    fflush(stdout);
}


// This function will stop the program.
void Stop_the_program()
{
	printf("\n\n");
	printf("\t\t\t\tThe program is stopped !\n");
	printf("\t\t\t\tPress any key to continue....\n");
	fflush(stdout);
	exit(1);
}


// This function loads users from a .txt file
 void Load_users(const char* filename)
{
	 FILE *file;
	 char line[100];

	 file = fopen("Format_Imenika.txt", "r");

	 while (fgets(line, sizeof(line), file))
	 {
		 char* name = strtok(line, "|");
		 char* surname = strtok(NULL, "|");
		 char* number = strtok(NULL, "\n");

		 Adding_users_to_the_arrey(name, surname, number, arrey);
	 }

	 fclose(file);
}


 // This function adding users to the array.
 int Adding_users_to_the_arrey(char* name, char* surname, char* number, User* arrey)
 {
	 strcpy(arrey[counter].name, name);
 	 strcpy(arrey[counter].surname, surname);
 	 strcpy(arrey[counter].number, number);

 	 counter++;

 	 return 1;
 }


 // This function prints all users to the console
 void View_all_users(User* arrey, int size)
 {
	 int i = 0;

 	 printf("\n\t\t\t\t******************************************************************************\n");
 	 printf("\t\t\t\t*                  Here is all records listed in phonebook                   *\n");
 	 printf("\t\t\t\t******************************************************************************\n\n\n");

 	 do
 	 {

 		 printf("\t\t\t\t%d) Name: %s, Surname: %s, Number: %s\n\n", i + 1, arrey[i].name, arrey[i].surname, arrey[i].number);

 		 i++;
 		 fflush(stdout);

 	 } while(i < size);

 }


 // This function adds a new user
 void Add_a_user()
 {
 	char name[20], surname[20], number[20];

 	printf("\n\t\t\t\t******************************************************************************\n");
 	printf("\t\t\t\t*                  Enter information about the new user                        *\n");
 	printf("\t\t\t\t******************************************************************************\n\n\n");
 	printf("\t\t\t\tEnter name : ");
 	fflush(stdout);
 	scanf("%s",name);
 	printf("\n\n");
 	printf("\t\t\t\tEnter surname :  ");
 	fflush(stdout);
 	scanf("%s",surname);
 	printf("\n\n");
 	printf("\t\t\t\tEnter number : ");
 	fflush(stdout);
 	scanf("%s",number);

 	if (Adding_users_to_the_arrey(name, surname, number, arrey))
 	{
 		Add_new_user_in_txt(filename, name, surname, number);

 		printf("\n\n");
 		printf("\t\t\t\tUser added successfully!\n\n");

 	}
 	else
 	{
 		printf("\n\n");
 		printf("\t\t\t\tFailed to add user!\n");
 	}
 }

 void Add_new_user_in_txt(const char* filename, const char* name, const char* surname, const char* number)
 {
	 FILE *file;

 	 file = fopen(filename, "a+");

 	 fprintf(file, "%s|%s|%s\n", name, surname, number);

 	 fclose(file);
 }

// This function will start our program.
void start()
{
	int choice;
	while(1)
	{
		Print_menu();

		scanf("%d",&choice);
		switch(choice)
		{
			case 0:
				Stop_the_program();
				break;

			case 1:
				Load_users(filename);
		    	break;

			case 2:
		    	Add_a_user();
                break;

			case 3:
				if (counter > 0)
		    	 {
					View_all_users(arrey, counter);

		    	 }
		    	 else
		    	 {
		    	     printf("No users to display.\n");
		    	     fflush(stdout);
		    	 }
		    	 break;

		}
	}
}

// Program starts here.
int main()
{
    start();
    return 0;
}








