#include<stdio.h>
struct Book {
    char name[100];
    int id;
    char author[100];
    int issuedstatus;
} books[500];
struct Member {
    char name[100];
    int id;
    int contactnum[20];
} Members[500];
int main()
{
int choice;
printf("Choose from the following options:\n 1- Issue book\n 2- Return book\n 3- Display all books \n 4-Add a Member\n 5- Exit\n");
printf("Enter your choice: ");
scanf("%d",&choice);
switch (choice) {
    case 1:
    issuebook();
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