#include <stdlib.h>
#include <stdio.h>

// Declare node structure here
struct node
{
  int data;
  struct node *next;
};

struct node *head;

// Node functions below

// Insert at Beginning
void insert_begn()
{
  int item;
  struct node *ptr;
  
  ptr = (struct node *)malloc(sizeof(struct node *));
  
  if(ptr == NULL)
  {
    printf("Overflow!\n");
  }
  else
  {
    printf("Enter the Item to be inserted:\n");
    scanf("%d",&item);

    ptr -> data = item;
    ptr -> next = head;
    head = ptr;

    printf("Successfully Inserted!\n");
  }
}

// Insert at Specific Location
void insert_spec()
{
  int i,loc,item;
  struct node *ptr,*temp;
  
  ptr = (struct node *)malloc(sizeof(struct node *));
  
  if(ptr == NULL)
  {
    printf("Overflow!\n");
  }
  else
  {
    printf("Enter Item to be Inserted:\n");
    scanf("%d",&item);
    ptr -> data = item;
    printf("Enter Location at which to be Inserted:\n");
    scanf("%d",&loc);
    
    temp = head;

    for(i = 0; i < loc - 1; i++)
    {
      temp = temp -> next;
    }

    ptr -> next = temp -> next;
    temp -> next = ptr;

    printf("Succefully Inserted!\n");
  }
}

// Insert at End
void insert_last()
{
  int item;
  struct node *ptr,*temp;
  ptr = (struct node *)malloc(sizeof(struct node *));
  if(ptr == NULL)
  {
    printf("Overflow!\n");
  }
  else
  {
    printf("Enter Item to be Inserted:\n");
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

    printf("Successfully Inserted!\n");
    }
  }
}

// Delete at Beginning
void delete_begn()
{
  struct node *ptr;

  if(head == NULL)
  {
    printf("Empty List!");
  }
  else
  {
    ptr = head;
    head = ptr -> next;
    free(ptr);

    printf("Successfully Deleted!\n");
  }
}

// Delete at Specific Location
void deleted_spec()
{
  int i,loc;
  struct node *ptr,*temp;

  if(head == NULL)
  {
    printf("Empty List!\n");
  }
  else
  {
    printf("Enter the Location at which Item will be Deleted:\n");
    scanf("%d",&loc);

    ptr = head;

    for(i = 0; i < loc; i++)
    {
      temp = ptr;
      ptr = ptr -> next;
    }

    temp -> next = ptr -> next;
    free(ptr);

    printf("Successfully Deleted!\n");
  }
}

// Delete at End
void delete_last()
{
  struct node *ptr, *temp;

  if(head == NULL)
  {
    printf("Empty List!\n");
  }
  else if(head -> next == NULL)
  {
    head = NULL;

    printf("Successfully Deleted!\n");
  }
  else {
    ptr = head;

    while(ptr -> next != NULL)
    {
      temp = ptr;
      ptr = ptr -> next;
    }

    temp -> next = NULL;
    free(ptr);

    printf("Successfully Deleted!\n");
  }
}

// Display Contents of List
void display()
{
  struct node *ptr;

  ptr = head;
  
  if(ptr == NULL)
  {
    printf("Empty List!\n");
  }
  else
  {
    printf("Contents of linked list:\n");
    
    while(ptr != NULL)
    {
      printf("%d\n",ptr -> data);
      ptr = ptr -> next;
    }
  }
}

// Search Specific Item 
void search()
{
  int i = 1,loc = 0,item,flag = 1;
  struct node *ptr,*temp;

  if(head == NULL)
  {
    printf("Empty List!\n");
  }

  printf("Enter the item to be serched:\n");
  scanf("%d",&item);

  ptr = head;

  while(ptr != NULL)
  {
    if(ptr -> data == item)
    {
      printf("%d found at %d\n",item,i - 1);
      flag = 0;
      break;
    }
    else 
    {
      i++;
      ptr = ptr -> next;
    }

  }
  if(flag == 1)
  {
    printf("%d NOT FOUND!\n",item);
    return;
  }
}

// Clear Console
void clear()
{
  system("clear");
}

//main class with meun 
int main()
{
  int choice = 0;

  while(choice != 9)
  {
    printf("\n********************* Main Menu *********************\n\n");
    printf("Choose a following Option:\n");
    printf("1.Insert at Beginning\n2.Insert at specific Location\n3.Insert at End\n4.Delete from Beginning\n5.Delete at Specific Location\n6.Delete from End\n7.Display All Elements\n8.Search for an Element\n9.Exit\n10.Clear\n\n");
    printf("*****************************************************\n");

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
      case 10: clear();
              break;
      default:printf("Invalid Choice, Choose between 1-10\n");
              break;
    }
  }
  return 0;
}
