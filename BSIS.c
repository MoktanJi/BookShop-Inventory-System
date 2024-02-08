#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
 void mainWindow();
 void login();
 void mainMenu();
 void Menu();
 void feedData();
 void editData(int);
 void showData(int);
 void listBook();
 void searchBook(int);
 struct Book
 {
 	char author[25],title[35],publisher[35];
 	int nocopy,id;
 };
 struct Book c;
 FILE *fptr;
 
 int main()
 {  
	fptr=fopen("Book.txt","r+");
	if(fptr==NULL)
	  {
	  	printf("File not opened");
	  	exit(0);
	  }
 	mainWindow();
 	login();
 }
 
 void mainWindow()
 {
  	char enter;
 	printf("\n\n\n\n\n\n");
 	printf("\t\t\t\t#########################################\n");
 	printf("\t\t\t\t#                                       #\n");
 	printf("\t\t\t\t#                                       #\n");
	printf("\t\t\t\t#\tBookshop Inventory System       #\n");
	printf("\t\t\t\t#                                       #\n");
	printf("\t\t\t\t#                                       #\n");
	printf("\t\t\t\t#########################################\n");
	printf("\t\t\t\t\t Press enter to continue");
	enter=getchar();
	system("cls");
 }
 
 void login()
 {
 	system("cls");
 	char username[20],password[20],ch,enter;
 	char uname[]="BookShop";
 	char pword[]="MyBooks";
 	int i;
 	printf("\n\n\n\n\n\n");
 	printf("\t\t\t\t\tLogin\n");
 	printf("\t\t\t\t\tEnter the username:");
 	scanf("%s",username);
 	printf("\t\t\t\t\tEnter the password:");
 	for(i=0;i<100;i++)
 	   {
 	   	    ch=getch();
 	   	    if(ch==13)
				break;
			password[i]=ch;
			ch='*';
			printf("%c",ch);
		}
	password[i]='\0';
	if(strcmp(username,uname)==0 && strcmp(password,pword)==0)
	  {
	  	fflush(stdin);
	  	printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
	  	printf("\t\t\t\t\tId and password matched\n");
	  	printf("\t\t\t\t\tPress enter to continue");
	  	enter=getchar();
	  	mainMenu();
	  }
	else
	  {
	  	printf("\n------------------------------------------------------------------------------------------------------------------------\n");
	  	printf("\t\t\t\t\t\tInvalid Id or Password");
	  	printf("\n\t\t\t\t\tPress enter to repeat again");
		fflush(stdin);
		enter=getchar();
		login();			
	  }
}
	
 void mainMenu()
 {
		system("cls");
		fflush(stdin);
		char option,enter;
		printf("\n\n\n\n\n\n");
		printf("\t\t\t\t\t################################\n");
		printf("\t\t\t\t\t#\t     M Menu            #\n");
		printf("\t\t\t\t\t#\t     X Exit            #\n");
		printf("\t\t\t\t\t################################\n");
		printf("\t\t\t\t\t Choose any option from above:");
		option=getchar();
		
		switch(option)
		 {
		 	case 'M':
		 	Menu();
		 	break;
				 			
			case 'X':
			exit(0);
			break;
			
			default:
			printf("\n\t\t\t\t\tInvalid Choice\n");
			printf("\t\t\t\t  Press enter to repeat again");
			fflush(stdin);
			enter=getchar();
			mainMenu();		
		 }
}

 void Menu()
 {
 	system("cls");
 	fflush(stdin);
 	char option,enter;
 	int bookSearch;
 	printf("\n\n\n\n\n\n");
 	printf("\t\t\t\t\t#############################\n");
	printf("\t\t\t\t\t#\t   Menu             #\n");
	printf("\t\t\t\t\t#\t 1 Feed Data        #\n");
	printf("\t\t\t\t\t#\t 2 Edit Data        #\n");
	printf("\t\t\t\t\t#\t 3 Show Data        #\n");
	printf("\t\t\t\t\t#\t 4 List Book        #\n");
	printf("\t\t\t\t\t#\t 5 Search Book      #\n");
	printf("\t\t\t\t\t#\t X Exit             #\n");
	printf("\t\t\t\t\t#############################\n");
	printf("\t\t\t\t\tChoose any option from above:");
	option=getchar();
	
	switch(option)
	{
		case '1':
		feedData();
		break;
			
		case '2':
		printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
	    printf("\t\t\t\t\tEnter Id of the book you want to edit:");
	    scanf("%d",&bookSearch);
	    editData(bookSearch);
		break;
			
		case '3':
		printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
	    printf("\t\t\t\t\tEnter Id of the book you want to see:");	
	    scanf("%d",&bookSearch);
		showData(bookSearch);
		break;
		
		case '4':
		listBook();
		break;
		
		case '5':
		printf("\n-----------------------------------------------------------------------------------------------------------------------\n");	
		printf("\t\t\t\t\tEnter Id of the book to search:");
		scanf("%d",&bookSearch);
		searchBook(bookSearch);
		break;
			
		case 'X':
		exit(0);
		break;
		
		default:
		printf("\n-----------------------------------------------------------------------------------------------------------------------\n");	
		printf("\n\t\t\t\t\t\tInvalid Choice\n");
		printf("\t\t\t\t\t  Press enter to repeat again");
		fflush(stdin);
		enter=getchar();
		Menu();			
	}
 }
  
 void feedData()
 {
 	char enter;
 	system("cls");
 	printf("\n\n\n\n\n\n");
 	printf("\t\t\t\t\tEnter the details\n");
 	printf("\t\t\t\t\tEnter Id of book:");
 	scanf("%d",&c.id);
 	printf("\t\t\t\t\tEnter Author Name:");
 	fflush(stdin);
 	gets(c.author);  
 	printf("\t\t\t\t\tEnter Title:");
 	fflush(stdin);
 	gets(c.title);
 	printf("\t\t\t\t\tEnter Publisher Name:");
 	fflush(stdin);
 	gets(c.publisher);
 	fseek(fptr,0,2);
 	fwrite(&c,sizeof(c),1,fptr);
 	printf("\t\t\t\t\tPress enter to continue");
	fflush(stdin);
	enter=getchar();
	Menu();
 }
 
 void editData(int bookid)
 {
  	char ch,enter;
  	rewind(fptr);
  	int i;
  	while(fread(&c,sizeof(c),1,fptr)==1)
  	     {
  	     	i++;
  	     	if(c.id=bookid)
  	     	  {
  	     	  	 	char newauthor[25],newtitle[35],newpublisher[35];
  	     	  	 	printf("\n\n");
  	     	  	 	printf("\t\t\t\t\tThe details of book are:\n");
				 	printf("\t\t\t\t\tAuthor Name:%s\n",c.author);
				 	printf("\t\t\t\t\tTitle :%s\n",c.title);
				 	printf("\t\t\t\t\tPublisher Name:%s\n",c.publisher);
				 	printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
				 	printf("\t\t\t\t\tEnter details of book again:\n");
					printf("\t\t\t\t\tEnter New Author Name:");
				 	fflush(stdin);
				 	gets(newauthor);
				 	strcpy(c.author,newauthor);
				 	printf("\t\t\t\t\tEnter New Title :");
				 	fflush(stdin);
				 	gets(newtitle);
				 	strcpy(c.title,newtitle);
				 	printf("\t\t\t\t\tEnter New Publisher Name:");
				 	fflush(stdin);
				 	gets(newpublisher);
				 	strcpy(c.publisher,newpublisher);
				 	fseek(fptr,(i-1)*sizeof(c),0);
				 	fwrite(&c,sizeof(c),1,fptr);
				 	break;
			  }
		 }
	printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\tPress enter continue");
	fflush(stdin);
	enter=getchar();
	Menu();				 
 }
 
 void showData(int nocopy)
 {
  	char ch,enter;
  	rewind(fptr);
    int see=0;
  	while(fread(&c,sizeof(c),1,fptr)==1)
	  {
	  	if(c.id==nocopy)
  		 {				 		 	
		  	printf("\n\n");
		  	printf("\t\t\t\t\tThe details are\n");
		  	printf("\t\t\t\t\tAuthor Name:%s\n",c.author);
		  	printf("\t\t\t\t\tTitle:%s\n",c.title);
		  	printf("\t\t\t\t\tPublisher Name:%s\n",c.publisher);
		  	fseek(fptr,(see-1)*sizeof(c),0);
		  
 		 }	
 	}
	printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\tPress enter to continue");
	fflush(stdin);
	enter=getchar();
	Menu();	 
}

 void listBook()
 {
 	char ch,enter;
 	rewind(fptr);
 	fseek(fptr,0,0);
 	while(fread(&c,sizeof(c),1,fptr)==1)
 	      { 
 	        printf("\n\t\t\t\t\t\tBook");
			printf("\n\t\t\t\t\tAuthor Name:%s\n",c.author);
  			printf("\t\t\t\t\tTitle:%s\n",c.title);
  			printf("\t\t\t\t\tPublisher Name:%s\n",c.publisher);	      	
		  }
	printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\tPress enter to continue");
	fflush(stdin);
	enter=getchar();
	Menu();	 	  
 }
	 	
 void searchBook(int nocopy)
 {
 	char ch,enter;
 	rewind(fptr);
 	int found=0;
 	while(fread(&c,sizeof(c),1,fptr)==1)
 		 {
 		 	if(c.id==nocopy)
  		 	 {	
  		 	    printf("\n\n");
  		 		printf("\t\t\t\t\t\tBook available");
  				found=1;
	     	 }	
 		 }
 	if(found==0)
	  { 
         printf("\n-----------------------------------------------------------------------------------------------------------------------\n");	  
   	  	 printf("\t\t\t\t\t\tBook not available");
	  }	 
	printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\tPress enter to go menu ");
	fflush(stdin);
	enter=getchar();
	Menu();
}

 	

 
 
