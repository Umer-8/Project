#include<stdio.h>
 
struct Book {
    char title[100];
    int id;
    char author[100];
    int available=1;
    char genre[100];
} books[100];
struct Member {
    char name[100];
    int id;
    int contactnum[20];
    int av=0;
} members[500];

void issuebook(struct Book books[],struct Member members[]) ;
{
    int uid;
    printf("Enter your USER ID \n");
    scanf("%d",&uid);
    int id1;
     Displaybook();
     for (int i = 0; i < 10; i++)
     {
         if(uid==members[i].id)
         {
            printf("Welcome to Library Management System \n");
         }
         else
         {
             printf("You have entered invalid ID,Please try again. \n");
         }
     printf("Enter book ID \n");
     scanf("%d",&id);
     if(books[i].id==id1;) 
     {
      if (books[i].available==0)
     {
        printf("Sorry, this book is already issued\n");
      }
      else 
      {
        printf("You have successfully borrowed book of ID %d \n ",books[i].id);
        books[i].available=0;
        members[i].av=1;
           break;
      }
      break;
      else
      {
        printf("You have entered wrong ID.Try again \n");
      }
     }
     }
}


 int count = loadBooksFromFile(books);
 void  Displaybook(struct Book books[],int count) {
     printf("Available Books are:\n");
    printf("ID Title Author\n");
    for (int i=0; i<count;i++) {
        if (books[i].isAvailable==1) { 
            printf("%d  %s  %s\n", books[i].id, books[i].title, books[i].author);
        }
    }
}
 
void issuebook(struct Book books[],struct Member members[]) ;
{
    int uid;
    printf("Enter your USER ID \n");
    scanf("%d",&uid);
    int id1;
     Displaybook();
     for (int i = 0; i < 10; i++)
     {
         if(uid==members[i].id)
         {
            printf("Welcome to Library Management System \n");
         }
         else
         {
             printf("You have entered invalid ID,Please try again. \n");
         }
     printf("Enter book ID \n");
     scanf("%d",&id);
     if(books[i].id==id1;) 
     {
      if (books[i].available==0)
     {
        printf("Sorry, this book is already issued\n");
      }
      else 
      {
        printf("You have successfully borrowed book of ID %d \n ",books[i].id);
        books[i].available=0;
        members[i].av=1;
        break;
      }
      break;
      else
      {
        printf("You have entered wrong ID.Try again \n");
      }
     }
     }
}
void returnbook(struct Book books[])
{
    int id1;
     for (int i = 0; i < 10; i++)
     {
     printf("Enter book ID to return \n");
     scanf("%d",&id);
     if(books[i].id==id1;) 
     {
      if (books[i].available==1)
     {
        printf("Sorry, this book is not borrowed \n");
     }
      else 
      {
        if(members[i].av=1)
        {
        printf("You have successfully returned book of ID %d \n ",books[i].id);
        books[i].available=1;
        break;
        }
        else
        {
              printf("You have not borrowed a book \n");
          
        }
      }
      break;
      else
      {
        printf("You have entered wrong ID.Try again \n");
      }
     }
     }
}
int main()
{
int choice;
printf("Choose from the following options:\n 1- Issue book\n 2- Return book\n 3- Display all books \n 4-Add a Member\n 5- Exit\n");
printf("Enter your choice: ");
scanf("%d",&choice);
switch (choice) {
    case 1:
    issuebook(struct books[40],struct Member members[]);
    break;
    case 2:
    returnbook();
    break;
    case 3:
    Displaybook();
    break;
     case 4:
    addmember();
    break;
      case 5:
    printf("Thank you for visiting our library management system. Please come again!\n");
    break;
}
  

    return 0;
}