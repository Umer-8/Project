#include<stdio.h>
#include <string.h>
struct Book 
{
    char title[100];
    int id;
    char author[100];
    int available;
    char genre[100];
    float rsum;
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
    while(fscanf(fptr,"%d,%[^,],%[^,],%[^,],%d,%f,%d\n",&books[count].id,books[count].title,books[count].author,books[count].genre,&books[count].available,&books[count].rsum,&books[count].rborrow)==7)
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
   while (fscanf(fptr, "%49[^,],%d,%49[^,\n]\n", members[count1].name, &members[count1].id, members[count1].pass) == 3)
  {
    count1++;
  }
    fclose(fptr);
    return count1;
}
int login(struct Member members[100],int uid,char *upass,int count1)
{
for (int i = 0; i < count1; i++) 
{
    if (members[i].id == uid) 
    {
        if (strcmp(members[i].pass,upass) == 0) 
        {
            printf("Welcome to Library management system\n");
            return i;
        }
         else 
        {
            printf("Invalid password entered.Please try again\n");
            return -1;
        }
    }
}
           printf("Invalid user id entered.Please try again\n");
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
  fprintf(fptr,"%d,%s,%s,%s,%d,%.1f,%d\n",books[i].id,books[i].title,books[i].author,books[i].genre,books[i].available,books[i].rsum,books[i].rborrow);
  }
  fclose(fptr);
}
void issuebook(struct Book books[40],int count) 
{
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
            	if (books[i].rborrow>0)
               {
			           float rating1=books[i].rsum/books[i].rborrow;
			           printf("The rating for this book is: %.1f \n",rating1);
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
 void returnbook(struct Book books[40],int count) {
 int id;
printf("Enter Book ID \n");
scanf("%d",&id);
  int found=0,days,fine=0,daysf;
  float rating;
      for(int i=0;i<count;i++)
      {
         if(books[i].id==id)
         {
            if(books[i].available==0)
            {
            	printf("Enter number of days passed since you borrowed this book: ");
            	scanf("%d",&days);
            	  if (days>14)
                {
            		daysf=days-14;
            		fine=25*daysf;
            		printf("You are returning the book late. You need to pay a fine of %d \n",fine);
				        }
                printf("You have successfully returned book of ID %d and title %s by %s \n",books[i].id,books[i].title,books[i].author);
                books[i].available=1;
                found=1;
                while (1)
                {
				         printf("Please rate the book out of 5:");
                 scanf("%f",&rating);
                 if (rating>=1 && rating<=5) 
                {
                books[i].rsum+=rating;
                books[i].rborrow++;
                break;
                }
				        else
                {
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
 void  Displaybook(struct Book books[40],int count) 
 {

  printf("Available Books are:\n");
  printf("ID \t\t Title\t\t\t\t\t\tAuthor\n");
       for (int i=0; i<count;i++) 
        {
           if (books[i].available==1) 
           { 
            printf("%d \t\t %s\t\t\t\t\t%s\n", books[i].id, books[i].title, books[i].author);
           }
        }
 }
void listusers(struct Member members[100], int count1) 
{
    printf("List of all members:\n");
    printf("ID\t\tName\n");
    for (int i = 0; i < count1; i++)
     {
        printf("%d\t\t%s\n",members[i].id, members[i].name);
     }
}
void addmember(char name[40]) {
    int id;
    char pass[15];
    FILE *fptr = fopen("users.txt", "a");
    if (fptr == NULL) {
        printf("Unable to open file users.txt\n");
        return;
    }
    printf("Enter name: ");
    scanf("%s", name);  
    printf("Enter ID: ");
    scanf("%d", &id);
    printf("Enter password (max 15 characters): ");
    scanf("%s", pass);  
    fprintf(fptr, "%s,%d,%s\n", name, id, pass);
    fclose(fptr);
}

void changememberpwd(int i, int count1, struct Member members[])
{
    char password[15];
    printf("\n Enter new password (max 15 characters): ");
    scanf("%s", password);
    strcpy(members[i].pass, password);
    FILE *fptr = fopen("users.txt", "w");
    if (fptr == NULL)
    {
        printf("Unable to update Members file\n");
        return;
    }
    for (int j = 0; j < count1; j++)
    {
        fprintf(fptr, "%s,%d,%s\n", members[j].name, members[j].id, members[j].pass);
    }
    fclose(fptr);
    printf("Password updated successfully!\n");
}
int main()
{
    char name[40];
int count1=loadmembers(members);   
int uid,choiceu,choicea;
 char ua;
char upass[15];


printf("Enter a for admin and u for user:");
scanf(" %c",&ua);

if(ua=='u')
{
printf("Enter your member ID: ");
scanf("%d",&uid);
printf("Enter your password: ");
scanf("%s",upass);
int currentmember = login(members,uid,upass,count1);
if (currentmember==-1) 
{
printf("Login unsuccessful. Please try again next time\n");
  return 0;
}
while(1)
{
printf("Choose from the following options:\n 1- Issue book\n 2- Return book\n 3- Display all books\n 4-Change member password\n 5-Exit the program.\n");
printf("Enter your choice: ");
scanf("%d",&choiceu);
int count=loadbooks(books);
switch (choiceu) 
{
    case 1:
    issuebook(books,count);
    break;
    case 2:
    returnbook(books,count);
    break;
    case 3:
    Displaybook(books,count);
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
}
else if(ua=='a')
{
  while(1)
  {
    printf("Choose from the following options:\n 1- Add member\n 2- List Users\n 3-Exit the program.\n");
    printf("Enter your choice: ");
    scanf("%d",&choicea);
    switch (choicea) 
  {
    case 1:
    addmember(name);
    break;
    case 2:
	   count1=loadmembers(members);   
    listusers(members, count1); 
    break;
    case 3:
    printf("Exiting program\n");
    return 0;
    default:
    printf("Invalid choice. Please try again.\n");
  }
  }
  }
return 0;
}

