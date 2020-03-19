#include <stdlib.h>
#include <stdio.h>

struct node
{
  int data;
  struct node *next;
};
struct node *head;

void insert_begn();
void insert_spec();
void insert_last();
void delete_begn();
void deleted_spec();
void delete_last();
void display();
void search();

int main()
{
  int choice = 0;

  while(choice != 9)
  {
    printf("\n*********************Main Menu*********************\n\n");
    printf("Choose a following Option:\n");
    printf("1.Insert at Beginning\n2.Insert at specific Location\n3.Insert at End\n4.Delete from Beginning\n5.Delete at Specific Location\n6.Delete from End\n7.Display All Elements\n8.Search for an Element\n9.Exit\n\n");
    printf("***************************************************\n");

    printf("\nEnter an Option:\n");
    scanf("%d",&choice);

    switch(choice)
    {
      case 1: insert_begn();
              break;
      case 2: insert_spec();
              break;
      case 3: insert_last();
              break;
      case 4: delete_begn();
              break;
      case 5: deleted_spec();
              break;
      case 6: delete_last();
              break;
      case 7: display();
              break;
      case 8: search();
              break;
      case 9: exit(0);
              break;
      default:printf("Invalid Choice, Choose between 1-9\n");
              break;
    }
  }

  return 0;
}

void insert_begn()
{
  struct node *ptr;
  int item;
  ptr = (struct node *)malloc(sizeof(struct node *));
  if(ptr ==  NULL)
  {
    printf("Overflow!\n");
  }
  else
  {
    printf("Enter the Item to be Inserted:\n");
    scanf("%d",&item);
    ptr -> data = item;
    ptr -> next = head;
    head = ptr;
    printf("Successfully Inserted Node!\n");
  }
}

void insert_spec()
{
  int i,loc,item;
  struct node *ptr,*temp;
  ptr = (struct node *)malloc(sizeof(struct node*));
  if(ptr == NULL)
  {
    printf("Overflow\n");
  }
  else
  {
    printf("Enter the Item to be Inserted:\n");
    scanf("%d",&item);
    ptr -> data = item;
    printf("Enter the Location to Insert Data:\n");
    scanf("%d",&loc);
    temp = head;

    for(i = 0; i < loc; i++)
    {
      temp = temp -> next;
    }
    
    if(temp == NULL)
    {
      printf("Fatal! cannot insert at the location!\n");
    }

    ptr -> next = temp -> next;
    temp -> next = ptr;
    printf("Successfully Inserted Node!\n");
  }
}

void insert_last()
{
  struct node *ptr,*temp;
  int item;
  ptr = (struct node *)malloc(sizeof(struct node *));
  if(ptr == NULL)
  {
    printf("Overflow!\n");
  }
  else
  {
    printf("Enter the Item to be Inserted:\n");
    scanf("%d",&item);
    ptr -> data = item;
    if(head == NULL)
    {
      ptr -> next = NULL;
      head = ptr;
      printf("Successfully Inserted Node!\n");
    }
    else
    {
      temp = head;
      while(temp -> next != NULL)
      {
        temp = temp -> next;
      }
      temp -> next = ptr;
      ptr -> next = NULL;
      printf("Successfully Inserted Node!\n");
    }
  }
}

void delete_begn()
{
  struct node *ptr;
  ptr = (struct node *)malloc(sizeof(struct node *));
  if(ptr == NULL)
  {
    printf("Linked List is Empty!\n");
  }
  else
  {
    ptr = head;
    head = ptr -> next;
    free(ptr);
    printf("Successfully deleted First Node!\n");
  }
}

void deleted_spec()
{
  struct node *ptr, *temp;
  int i,loc;
  printf("Enter the Location of the Node to be Deleted:\n");
  scanf("%d",&loc);
  ptr = head;
  for(i = 0; i < loc; i++)
  {
    temp = ptr;
    ptr = ptr -> next;

    if(ptr == NULL)
    {
      printf("Fatal! cannot Delete at the location!\n");
    }
  }
  temp -> next = ptr -> next;
  free(ptr);
  printf("Successfully Deleted Node at Location!\n");
}

void delete_last()
{
  struct node *ptr,*temp;
  if(head == NULL){
    printf("Linked List is Empty!\n");
  }
  else if(head -> next == NULL)
  {
    head = NULL;
    free(head);
    printf("Deleted the Head Node!\n");
  }
  else
  {
    ptr = head;
    while(ptr -> next != NULL)
    {
      temp = ptr;
      ptr = ptr -> next;
    }
    temp -> next = NULL;
    free(ptr);
    printf("Successfully Deleted Last Node!\n");
  }
}

void display()
{
  struct node *ptr;
  ptr = head;
  if(ptr == NULL)
  {
    printf("Linked List is Empty!\n");
  }
  else
  {
    printf("Linked List Contents:\n");
    while(ptr != NULL)
    {
      printf("%d\n",ptr->data);
      ptr = ptr->next;
    }
  }
}

void search()
{
 struct node *ptr;
 int i = 0,item,flag=0;
 ptr = head;
 if(ptr == NULL)
 {
   printf("Linked List Empty!\n");
 }
 else
 {
   printf("Enter the Item to be Located:\n");
   scanf("%d",&item);
   while(ptr != NULL)
   {
     if(ptr -> data == item)
     {
       printf("%d found in :Location: %d\n",item,i);
       flag = 0;
       break;
     }
     else
     {
       flag = 1;
     } 
     i++;
     ptr = ptr -> next;
    
   }
   if(flag == 1)
   {
     printf("item not found!\n");
   }
 }
}

