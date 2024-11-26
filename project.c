#include<stdio.h>
 #include <string.h>
struct Book 
{
    char title[100];
    int id;
    char author[100];
    int available;
    char genre[100];
    int rsum;
    int rborrow;
} books[40];
struct Member
{
    char name[100];
    int id;
    char pass[40];
} members[100];

int loadbooks(struct Book books[40])
{
    FILE *fptr=fopen("books.txt","r");
  if(fptr==NULL)
 {
     printf("File does not exist \n");
     return 0;
 }
    int count=0;
    while(fscanf(fptr,"%d,%[^,],%[^,],%[^,],%d\n",&books[count].id,books[count].title,books[count].author,books[count].genre,&books[count].available)==5)
    {
    count ++;
    }
fclose(fptr);
return count;
}

int loadmembers(struct Member members[100])
{
    FILE *fptr=fopen("users.txt","r");
  if(fptr==NULL)
 {
     printf("File does not exist \n");
     return 0;
 }
 int count1=0;
    while(fscanf(fptr," %49[^,],%d,%39s",members[count1].name,&members[count1].id,members[count1].pass)==3)
    {
    count1++;
    }
    fclose(fptr);
    return count1;
}
int login(struct Member members[100],int uid,char *upass,int count1)
{
for(int i=0;i<count1;i++)
{
    if(members[i].id==uid) {
      if (strcmp(members[i].pass,upass)==0) {
    printf("Welcome to Library management system! \n");
     return i;
    }
    else
    {
      printf("Invalid Password entered \n");
      return -1;
    }
    }
}

    printf("Invalid User ID entered.\n");
    return -1;
    
}

void updatebooks(struct Book *books,int count)
{
    FILE *fptr=fopen("books.txt","w");
      if(fptr==NULL)
      {
        printf("File does not exist \n");
        return ;
      }
  for(int i=0;i<count;i++)
  {
  fprintf(fptr,"%d,%s,%s,%s,%d\n",books[i].id,books[i].title,books[i].author,books[i].genre,books[i].available);
    }
  fclose(fptr);
}
void issuebook(struct Book books[40],int count) {
    int id;
printf("Enter Book ID \n");
scanf("%d",&id);
  int found=0;
      for(int i=0;i<count;i++)
      {
         if(books[i].id==id)
         {
            if(books[i].available==1)
            {
            	if (books[i].rborrow>0) {
			float rating1= (float)books[i].rsum/books[i].rborrow;
			printf("The rating for this book is: %.3f",rating1);
			}
                printf("You have successfully borrowed book of ID %d and title %s by %s \n",books[i].id,books[i].title,books[i].author);
                books[i].available=0;
                found=1;
                }
            else
            {
            printf("The book of ID %d and title %s by %s is already borrowed \n",books[i].id,books[i].title,books[i].author);
            found=1;
            }
            break;
         }
      }
      if(found==0)
      {
        printf("You have entered wrong book ID \n");
      }
      updatebooks(books,count);
}


 void  Displaybook(struct Book books[40]) 
 {
  int count = loadbooks(books);
  printf("Available Books are:\n");
  printf("ID Title Author\n");
       for (int i=0; i<count;i++) 
        {
           if (books[i].available==1) 
           { 
            printf("%d\t%s\t%s\n", books[i].id, books[i].title, books[i].author);
           }
        }
 }
 void returnbook(struct Book books[40],int count) {
  int id;
printf("Enter Book ID \n");
scanf("%d",&id);
  int found=0,days,fine=0,daysf,rating;
      for(int i=0;i<count;i++)
      {
         if(books[i].id==id)
         {
            if(books[i].available==0)
            {
            	printf("Enter number of days passed since you borrowed this book: ");
            	scanf("%d",&days);
            	if (days>14) {
            		daysf=days-14;
            		fine=25*daysf;
            		printf("You are returning the book late. You need to pay a fine of %d",fine);
				}
                printf("You have successfully returned book of ID %d and title %s by %s \n",books[i].id,books[i].title,books[i].author);
                 books[i].available=1;
                found=1;
                while (1) {
				printf("Please rate the book out of 5.");
                scanf("%d",&rating);
                if (rating>=1 && rating<=5) {
                books[i].rsum+=rating;
                books[i].rborrow++;
                break;
                }
				else {
					printf("Invalid rating entered. Please enter a valid rating \n");
				}
			}
                
               
            }
            else
            {
            printf("The book of ID %d and title %s by %s is not  borrowed yet \n",books[i].id,books[i].title,books[i].author);
                 found=1;
            }
            break;
         }
      }
      if(found==0)
      {
        printf("You have entered wrong book ID \n");
      }
      updatebooks(books,count);
}
  void changememberpwd(int i,int count1,struct Member members[])
  {
  	char password[15];
  	printf("\n Enter new password (max 15 characters): ");
	  scanf("%s",password);
	 strcpy(members[i].pass, password);

    FILE *fptr=fopen("users.txt","w");
      if(fptr==NULL)
      {
        printf("Unable to update Memebers file\n");
        return;
      }
     for(int i=0;i<count1;i++)
  {
  fprintf(fptr,"%s,%d,%s\n",members[i].name,members[i].id,members[i].pass);
    }
  fclose(fptr);
}


int main()
{
 int count1=loadmembers(members);   
int uid, choice;
char upass[15];
printf("Enter your member ID: ");
scanf("%d",&uid);
printf("Enter your password: ");
scanf("%s",upass);
int currentmember = login(members,uid,upass,count1);
if (currentmember < 0) {
  printf("Login unsuccessful. Please try again next time\n");
  return 0;
}
while(1)
{
printf("Choose from the following options:\n 1- Issue book\n 2- Return book\n 3- Display all books \n 4-Change Member password \n 5- Exit the system\n");
printf("Enter your choice: ");
scanf("%d",&choice);
int count=loadbooks(books);
switch (choice) 
{
    case 1:
    issuebook(books,count);
    break;
    case 2:
    returnbook(books,count);
    break;
    case 3:
    Displaybook(books);
    break;
    case 4:
   changememberpwd(currentmember, count1, members);
  break;
    case 5:
    printf("Thank you for visiting our library management system. Please come again!\n");
    return 0;
    default:
    printf("Invalid choice. Please try again.\n");
}
}
return 0;
}