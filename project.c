 #include<stdio.h>
 #include <string.h>
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
     return;
 }
 int count1=0;
    while(fscanf(fptr,"%49[^,],%d,%49[^,]\n",&members[count1].name,&members[count1].id,members[count1].pass)==3)
    {
    count1++;
    }
    fclose(fptr);
    return count1;
}
void login(struct Member members[100],int uid,char upass,int count1)
{
for(int i=0;i<count1;i++)
{
    if(members[i].id==uid) {
      if (strcmp(members[i].pass,upass)==0) {
    printf("Welcome to Library management system");
     return;
    }
    else
    {
      printf("Invalid Password entered \n");
    }
    }
    else {
    printf("Invalid User ID entered. \t Please enter a valid ID\n");
    break;
    }
}
}
void updatebooks(struct Book *books,int count)
{
    FILE *fptr=fopen("books.txt","w");
      if(fptr==NULL)
      {
        printf("File does not exist \n");
        return 0;
      }
  for(int i=0;i<count;i++)
  {
  fprintf(fptr,"%d,%s,%s,%s,%d\n",books[i].id,books[i].titile,books[i].author,books[i].genre,books[i].available);
    }
  fclose(fptr);
}
void issuebook(struct Book books[40],int id,int count) {
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
            printf("%d  %s  %s\n", books[i].id, books[i].title, books[i].author);
           }
        }
 }
int main()
{
 int count1=loadmembers(members);   
int uid;
int upass;
printf("Enter your member ID: ");
scanf("%d",&uid);
printf("Enter your password: ");
scanf("%s",upass);
login(members,uid,upass,count1);

int choice;
printf("Choose from the following options:\n 1- Issue book\n 2- Return book\n 3- Display all books \n 4-Add a Member\n 5- Exit\n");
printf("Enter your choice: ");
scanf("%d",&choice);
int id;

printf("Enter Book ID \n");
scanf("%d",&id);

int count=loadbooks(books);

switch (choice) 
{
     case 1:
     issuebook(books,id,count);
    updatebooks(books,count);
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
    default:
    printf("Invalid choice \n");
}
return 0;
}