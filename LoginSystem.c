#include <stdio.h>
#include <windows.h>

void FrontPage();
void createAccount();
void Login();
void menu();
struct userProfile
{
    char Name[500];
	char Pass[10];
    char Number[12];
};

int main()
{
    FrontPage();
    return 0;
}

void FrontPage()
{
    system("color 7a");
    system("cls");
    printf("\n\n\t\t:::::::::: LOGIN MANAGMENT SYSTEM :::::::::");
	printf("\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ASTRO CODER \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf("\t\tPress 1 : Create New Account\n \t\tPress 2 : Login\n\n");
    printf("\t\tPress any key to start :- ");
		int user_Input;
		scanf("%d", &user_Input);
		switch (user_Input)
		{
			case 1:
                createAccount();
				break;
			case 2:
                Login();
				break;
        }
}

void createAccount()
{
    system("color 7a");
    system("cls");
    printf("\n\n\t\t\t::::::::: ASTRO CODER :::::::::\n\n");
	printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2 CREATE NEW ACCOUNT \xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    struct userProfile users;
    FILE *fptr;
	fptr = fopen("Data.txt", "a");
    printf("\t\tEnter your Name :- ");
	scanf("%s", &users.Name);
	printf("\t\tEnter your Number :- ");
	scanf("%s", &users.Number);
    printf("\t\tSet a 6 digit Password :- ");
	scanf("%s", users.Pass);
    fprintf(fptr, "\n%s %s %s", users.Name, users.Number, users.Pass);
	fclose(fptr);
    printf("\t\tAccount Created......\n");
    printf("\t\tPress 1 : For Login\n");
    printf("\t\tPress any key to start :- ");
	int user_Input;
	scanf("%d", &user_Input);
    if (user_Input==1)
    {
        Login();
    }
}

void Login()
{
    system("color 7a");
    system("cls");
    printf("\n\n\t\t\t:::::::: ASTRO CODER BANK ::::::::\n\n");
	printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Login Page \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    char Nam[500], pss[10];
    struct userProfile users;
    FILE *fptr;
    printf("\t\tEnter your Name :- ");
	scanf("%s", &Nam);
    printf("\t\tEnter your Password :- ");
	scanf("%s", &pss);
    fptr = fopen("Data.txt", "r");
    while(fscanf(fptr,"%s %s", users.Name, users.Pass)!=EOF){
      		if(strcmp(Nam,users.Name)&&strcmp(pss,users.Pass)==0)
			{
                menu(Nam);
			}
		}
}

void menu(char userName[])
{
    system("color 7a");
    system("cls");
    printf("\n\n\t\t:::::::::: LOGIN MANAGMENT SYSTEM :::::::::");
	printf("\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ASTRO CODER \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf("\t\t\tWelcome %s\n", userName);
}