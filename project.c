 #include<stdio.h>
 
struct Book 
{
    char title[100];
    int id;
    char author[100];
    int available=1;
    char genre[100];
} books[40];
struct Member
{
    char name[100];
    int id;
    int contactnum[20];
    int av=0;
} members[100];

int loadbooks(struct Book books[40])
{
    FILE *ptr=fopen("books.txt","r");
  if(fptr==NULL)
 {
     printf("File does not exist \n");
     return 0;
 }
    int count=0;
    while(fscanf(fptr,"%d,%[^,],%[^,],%[^,],%d\n",&books[count].id,books[count].titile,books[count].author,books[count].genre,&books[count].available)==4)
    {
    count ++;
    }
fclose(fptr);
return count;
}
void issuebook(struct Book books[40],int id,int count) ;
{
    int found=0;
      for(int i=0;i<count;i++)
      {
         if(books[i].id…
[10:30 AM, 11/21/2024] Umer: #include<stdio.h>
 
struct Book 
{
    char title[100];
    int id;
    char author[100];
    int available=1;
    char genre[100];
} books[40];
struct Member
{
    char name[100];
    int id;
    char pass[10];
} members[100];

int loadmembers(struct Member members[100])
{
    FILE *ptr=fopen("users.txt","r");
  if(fptr==NULL)
 {
     printf("File does not exist \n");
     return;
 }
 int count1=0;
    while(fscanf(fptr,"%[^,],%d,%[^,]\n",&members[i].name,&members[i].id,members[i].pass)==3)
    {
    count1 ++;
    }
    fclose(fptr);
    return count1;
}
void login(struct Member members[100],int uid,char pass,int count1)
{
for(int i=0;i<count1;i++)
{
    if(members[i].id==uid && members[i].pass==upass)
    {
        printf("Welcome to Library management system");
    }
    else
    {
        printf("Invalid user ID or Password");
        return;
    }
}
}
int loadbooks(struct Book books[40])
{
    FILE *ptr=fopen("books.txt","r");
  if(fptr==NULL)
 {
     printf("File does not exist \n");
     return 0;
 }
    int count=0;
    while(fscanf(fptr,"%d,%[^,],%[^,],%[^,],%d\n",&books[count].id,books[count].titile,books[count].author,books[count].genre,&books[count].available)==5)
    {
    count ++;
    }
fclose(fptr);
return count;
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
                printf("You have successfully borrowed book of ID %d and title %s by %s \n",books[i].id,books[i].title,books[i].author);
                books[i].available=0;
                found=1;
            }
            else
            {
                 printf("The book of ID %d and title %s by %s is already borrowed \n",books[i]id,books[i].title,books[i].author);
                 found=1;
            }
            break;
         }
      }
      if(found==0)
      {
        printf("You have entered wrong book ID \n");
      }
}
void updatebooks(struct Book books[40],int count)
{
    FILE *ptr=fopen("books.txt","w");
      if(fptr==NULL)
      {
        printf("File does not exist \n");
        return 0;
      }
  for(int i=0;i<count;i++)
  {
      if (books[count].available==1)
      {
fprintf(fptr,"%d,%s,%s,%s,%d\n",books[count].id,books[count].titile,books[count].author,books[count].genre,books[count].available);
      }
  }
fclose(fptr);
}

 void  Displaybook(struct Book books[40]) 
 {
  int count = loadbooks(books);
  printf("Available Books are:\n");
  printf("ID Title Author\n");
       for (int i=0; i<count;i++) 
        {
           if (books[i].isAvailable==1) 
           { 
            printf("%d  %s  %s\n", books[i].id, books[i].title, books[i].author);
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
            	printf("Enter number of days passed since you borrowed this book: ")
            	scanf("%d",&days)
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
int main()
{
 int count1=loadmembers(members[100]);   
int uid;
int upass;
printf("Enter User ID \n");
scanf("%d",&uid);
printf("Enter User password \n");
scanf("%s",upass);
login(members[100],uid,upass,count1);

int choice;
printf("Choose from the following options:\n 1- Issue book\n 2- Return book\n 3- Display all books \n 4-Add a Member\n 5- Exit\n");
printf("Enter your choice: ");
scanf("%d",&choice);


int count=0;

int count=loadbooks(books[40]);


switch (choice) 
{
     case 1:
    issuebook(books[40],count);
    updatebooks(books[40],count);
    break;
    case 2:
    returnbook(books[40],count);
    break;
    case 3:
    Displaybook(books[40]);
    break;
    case 4:
    addmember();
    break;
    case 5:
    printf("Thank you for visiting our library management system. Please come again!\n");
    break;
    default:
    printf("Invalid choice \n");
}
return 0;
}