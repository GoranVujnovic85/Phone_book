
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
#define stop_the_program              0
#define load_users                    1
#define add_a_user                    2
#define view_all_users                3
#define remove_a_user_from_arrey      4
#define remove_a_user_from_FILE       5


// Global variables.
const char* filename = "Format_Imenika.txt";
int counter = 0;


// Defining user data type.
typedef struct
{
	char name[20];
	char surname[20];
	int number;

}User;
User arrey[20];


// All function prototypes.
void Print_menu();
int Stop_the_program();
void Load_users();
int Adding_users_to_the_arrey();
void View_all_users();
void Add_a_user();
void Add_new_user_in_txt();
void Remove_a_user_from_arrey();
void Remove_a_user_from_FILE();


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
    printf("\t\t\t4) Remove a user from arrey\n\n");
    printf("\t\t\t5) Remove a user from FILE\n\n");
    printf("\t\t\t\tEnter your Choice : ");
    fflush(stdout);
}


// This function will stop the program.
int Stop_the_program()
{
	printf("\n\n");
	printf("\n\t\t\t\t******************************************************************************\n");
	printf("\t\t\t\t*                  Program is stopped!                                       *\n");
	printf("\t\t\t\t*                  You have to restart the program...                        *\n");
	printf("\t\t\t\t******************************************************************************\n\n\n");
	fflush(stdout);

	return 1;
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
		 char* number_str = strtok(NULL, "\n");

		 long number = atol(number_str);

		 Adding_users_to_the_arrey(name, surname, number, arrey);
	 }

	 fclose(file);

 	 printf("\n\t\t\t\t******************************************************************************\n");
 	 printf("\t\t\t\t*                  You have successfully loaded users                        *\n");
 	 printf("\t\t\t\t******************************************************************************\n\n\n");
}


 // This function adding users to the array.
 int Adding_users_to_the_arrey(char* name, char* surname, long number, User* arrey)
 {
	 strcpy(arrey[counter].name, name);
 	 strcpy(arrey[counter].surname, surname);
 	 arrey[counter].number = number;

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

 		 printf("\t\t\t\t%d) Name: %s, Surname: %s, Number: %ld\n\n", i + 1, arrey[i].name, arrey[i].surname, arrey[i].number );

 		 i++;
 		 fflush(stdout);

 	 } while(i < size);

 }


 // This function adds a new user
 void Add_a_user()
 {
 	char name[20], surname[20];
	int number;

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
 	scanf("%d",&number);

 	if (Adding_users_to_the_arrey(name, surname, number, arrey))
 	{
 		Add_new_user_in_txt(filename, name, surname, number);

 		printf("\n\n");
 		printf("\t\t\t\tUser added successfully!\n\n");
 		fflush(stdout);
 	}
 	else
 	{
 		printf("\n\n");
 		printf("\t\t\t\tFailed to add user!\n");
 		fflush(stdout);
 	}
 }


 // This function writes a new user in a txt file
 void Add_new_user_in_txt(const char* filename, const char* name, const char* surname, long number)
 {
	 FILE *file;
 	 file = fopen(filename, "a+");
 	 fprintf(file, "%s|%s|%ld\n", name, surname, number);

 	 fclose(file);
 }


// This function remove a user from arrey
 void Remove_a_user_from_arrey()
 {
	 int number;

	 printf("\n\t\t\t\t******************************************************************************\n");
	 	 printf("\t\t\t\t*                     Pay attention!                                         *\n");
	 	 printf("\t\t\t\t*          You will delete the user from the Arrey                           *\n");
	 	 printf("\t\t\t\t******************************************************************************\n\n\n");
	 	 printf("\t\t\t\tEnter Phone number of the user you want to remove from phone book: ");
	 fflush(stdout);
	 scanf("%d", &number);

	 int found_index = -1;

	 for(int i = 0; i < counter; i++)
	 {
		 if(arrey[i].number == number)
		 {
			 found_index = i;
			 printf("\n\n");
			 printf("\t\t\t\tThe selected user was located on the %d index!\n", i);
			 break;
		 }
	 }

	 if(found_index != -1)
	 {
		 for(int i = found_index; i < counter - 1; i++)
		 {
			 arrey[i] = arrey[i + 1];
		 }
		 counter--;

		 printf("\n\n");
		 printf("\t\t\t\tUser removed from the array.\n");
	 }
	 else
	 {
		 printf("\t\t\t\tUser was not found in the array.\n");
	 }
 }

 // This function remove a user from FILE
 void Remove_a_user_from_FILE()
 {
	 int number;
	 User user;
	 int flag = 0;

	 printf("\n\t\t\t\t******************************************************************************\n");
	 printf("\t\t\t\t*                     Pay attention!                                         *\n");
	 printf("\t\t\t\t*          You will delete the user from the FILE                            *\n");
	 printf("\t\t\t\t******************************************************************************\n\n\n");
	 printf("\t\t\t\tEnter Phone number of the user you want to remove from phone book: ");
	 fflush(stdout);
	 scanf("%d", &number);

	 FILE *file, *temp;
	 char line[100];

	 file = fopen("Format_Imenika.txt", "r");
	 temp = fopen("temp.txt", "w+");

	 while(fgets(line, sizeof(line), file))
	 {
		 sscanf(line, "%[^|]|%[^|]|%d\n", user.name, user.surname, &user.number);

		 if(user.number == number)
		 {
			 flag = 1;
			 printf("\n\n");
			 printf("\t\t\t\tPerson removed successfully\n");
		 }
		 else
		 {
			 fputs(line, temp);
		 }
	 }

	 fclose(file);
	 fclose(temp);

	 if(flag == 0)
	 {
		 printf("No record found for %d number\n",number);
	 }

	 remove("Format_Imenika.txt");
	 rename("temp.txt","Format_Imenika.txt");

 }


// This function will start our program.
void start()
{
	int choice;
	//int stop;
	while(1)
	{
		Print_menu();

		scanf("%d",&choice);
		switch(choice)
		{
			case stop_the_program:
			{
				//stop = 1;
				Stop_the_program();
				return;
			}
			break;

			case load_users:
			{
				Load_users(filename);
			}
			break;

			case add_a_user:
			{
				Add_a_user();
			}
            break;

			case view_all_users:
			{
				if (counter > 0)
		    	 {
					View_all_users(arrey, counter);

		    	 }
				else
		    	 {
					printf("No users to display.\n");
		    	    fflush(stdout);
		    	 }
			}
		    break;

			case remove_a_user_from_arrey:
			{
				Remove_a_user_from_arrey();
			}
			break;

			case remove_a_user_from_FILE:
			{
				Remove_a_user_from_FILE();
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




