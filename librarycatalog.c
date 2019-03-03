/* This C Program Manages a Library Catalog */

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable: 4996)
#define libItems 100
typedef struct
{
	int itemNumber;
	char Title[25];
	char Author[25];
	char Genre[15];
	char Format[7];
	char Description[100];
} Library;

void addItem(Library *ptr, int *count);
void modifyItem(Library *ptr, int *count);
void displayAnItem(Library *ptr, int *count);
void displayAllItems(Library *ptr, int *count);

void main()
{
	int ch=0,check=1,i=0,*count = &i;
	Library arr[libItems], *ptr;
	FILE *fp;
	ptr=arr;
	while(ch!=5)
	{
		printf("\nWelcome to my Library Catalog!\nPress 1 to Add a new item\nPress 2 to Modify an existing item\nPress 3 to Display an item\nPress 4 to Display all Catalog items\nPress 5 to EXIT\nPlease select your choice=> ");
		scanf("%d",&ch);
		if(ch==1)
		{
			system("cls");
			printf("You are adding a new item!\n");
			addItem(arr, &i);
			i++;
			check=0;
		}
		else if(ch==2)
		{
			system("cls");
			if(check==0)
			{
				printf("You are modifying an existing Item! \n");
				modifyItem(arr,&i);
			}
			else
			{
				printf("Sorry! You did not add any item which can be modified. Please try again.\n");
			}
		}
		else if(ch==3)
		{
			system("cls");
			if(check==0)
			{
				displayAnItem(arr,&i);
			}
			 else
			{
				printf("Sorry! You did not add any item which can be displayed. Please try again.\n");
			}
		}
		else if(ch==4)
		{
			system("cls");
			if(check==0)
			{
				displayAllItems(arr,&i);
			}
			 else
			{
				printf("Sorry! You did not add any item which can be displayed. Please try again.\n");
			}
		}
		else if(ch==5)
		{
			fp = fopen("PRG255_LAB_PROJECT", "at+");
			if(fp == NULL)
				printf("\n\nFailed to Open file\n");
			else
			{
				int j;
	            for(j=0;j<*count;j++) {
		        fprintf(fp,"Item Catalog Number:%d\tTitle:%s\tAuthor:%s\tGenre:%s\tFormat:%s\tDescription:%s\n",
					   (*(ptr+j)).itemNumber,(*(ptr+j)).Title,(*(ptr+j)).Author,(*(ptr+j)).Genre,(*(ptr+j)).Format,(*(ptr+j)).Description);
				}
			}
			fclose(fp);
			break;
		}
		else{
			printf("You entered a wrong choice! Please try again...");
			ch=0;
		}
	}
	getch();
}

void addItem(Library *ptr,int *count)
{
	printf("Enter the Item Catalog number => ");
	scanf("%d",&(*(ptr+*count)).itemNumber);
	printf("Enter the title of the item => ");
	fflush(stdin);
	gets((ptr+*count)->Title);
	printf("Enter the Author's name (first name space last name) =>");
	fflush(stdin);
	gets((ptr+*count)->Author);
	printf("Enter the Genre of the item => ");
	fflush(stdin);
	gets((ptr+*count)->Genre);
	printf("Enter the format of the item => ");
	fflush(stdin);
	gets((ptr+*count)->Format);
	fflush(stdin);
	printf("Enter the description of the item => ");
	fflush(stdin);
	gets((ptr+*count)->Description);
	printf("This item has been successfully added!\n");
}

void modifyItem(Library *ptr,int *count)
{
   char bookTitle[25];
   int choice,j,c=0;
   for(j=0;j<*count;j++) {
		printf("Item Catalog Number:%d\nTitle:%s\nAuthor:%s\nGenre:%s\nFormat:%s\nDescription:%s\n\n",(*(ptr+j)).itemNumber,(*(ptr+j)).Title,(*(ptr+j)).Author,(*(ptr+j)).Genre,(*(ptr+j)).Format,(*(ptr+j)).Description);
	}
   for(j=0;j<*count;j++) {
		printf("Enter %d for modifying information about the item title %s\n",j+1,(*(ptr+j)).Title);
	}
	printf("\nPlease enter your choice = ");
	scanf("%d",&c);
    for(j=0;j<*count;j++) {
		if(c==j+1) {
			printf("ITEM FOUND!\nPress 1 to modify Item Catalog Number, 2 for modifying Author's Name, 3 for Genre, 4 for format and 5 for Description..\nEnter your choice => ");
			scanf("%d",&choice);
			if(choice==1) {
				printf("Enter the new Item Catalog number = ");
				fflush(stdin);
				scanf("%d",&(ptr+j)->itemNumber);
				printf("\nChange done!");
			}
			else if(choice==2) {
				printf("Enter the Author's name you want to change = ");
				fflush(stdin);
				gets((ptr+j)->Author);
				printf("\nChange done!");
			}
			else if(choice==3) {
				printf("Enter the new Genre name = ");
				fflush(stdin);
				gets((ptr+j)->Genre);
				printf("\nChange done!");
			}
			else if(choice==4) {
				printf("Enter the new format = ");
				fflush(stdin);
				gets((ptr+j)->Format);
				printf("\nChange done!");
			}
			else if(choice==5) {
				printf("Enter the new Description = ");
				fflush(stdin);
				gets((ptr+j)->Description);
				printf("\nChange done!");
			}
			else {
				printf("Sorry! You entered wrong choice.. Try Again!\n");
			}
		}
    }
}

void displayAnItem(Library *ptr, int *count)
{
	char bookTitle[25];
	int j,c=0;
	for(j=0;j<*count;j++) {
		printf("Enter %d for displaying information about the book title %s\n",j+1,(*(ptr+j)).Title);
	}
	printf("\nPlease enter your choice = ");
	scanf("%d",&c);
	for(j=0;j<*count;j++) {
		if(c==j+1){
			printf("The book's information is displayed below:\nItem Catalog Number:%d\nTitle:%s\nAuthor:%s\nGenre:%s\nFormat:%s\nDescription:%s\n\n",(*(ptr+j)).itemNumber,(*(ptr+j)).Title,(*(ptr+j)).Author,(*(ptr+j)).Genre,(*(ptr+j)).Format,(*(ptr+j)).Description);
		}
	}
}

void displayAllItems(Library *ptr, int *count)
{
	int k,j;
	Library temp[libItems];
	printf("The information of all books is displayed below:\n");
    for(k=0;k<*count;k++)
    {
		for(j=k+1;j<*count;j++) {
			if(strcmp(((*(ptr+k)).Format),((*(ptr+j)).Format))>0) 
			{
				temp[k]=(*(ptr+k));
				(*(ptr+k))=*(ptr+j);
				*(ptr+j)=temp[k];
			}
		}
	}
	for(k=0;k<*count;k++)
	{
		printf("Item Catalog Number:%d\nTitle:%s\nAuthor:%s\nGenre:%s\nFormat:%s\nDescription:%s\n\n",
		(*(ptr+k)).itemNumber,(*(ptr+k)).Title,(*(ptr+k)).Author,(*(ptr+k)).Genre,(*(ptr+k)).Format,(*(ptr+k)).Description);
	}
}