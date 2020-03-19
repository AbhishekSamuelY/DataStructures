#include <stdlib.h>
#include <stdio.h>

// Declare node structure here

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
      default:printf("Invalid Choice, Choose between 1-10\n");
              break;
    }
  }
  return 0;
}

// write node functions

void insert_begn()
{

}

void insert_spec()
{

}

void insert_last()
{

}

void delete_begn()
{

}

void deleted_spec()
{

}

void delete_last()
{

}

void display()
{

}

void search()
{
 
}

