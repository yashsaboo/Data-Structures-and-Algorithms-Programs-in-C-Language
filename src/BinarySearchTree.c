/*WAP to create a Binary Search Tree Program which features: Create, Traverse using different techniques, Search and Delete*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 20

struct node
{
  int data;
  struct node *left;
  struct node *right;
};

struct node *root = NULL;
struct node *temp = NULL;

//Checking if node is empty or full
int isEmpty(struct node *binTree)
{
  if(binTree == NULL)
    return 1;
  else
    return 0;
}

//Allocating memory to new Node
struct node *createNewNode()
{
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  return newNode;
}

//Function to insert data to node
void insert(int input, struct node **n)
{
  if(isEmpty(*n) == 1)
  {
    temp = createNewNode();
    temp->data = input;
    temp->left = NULL;
    temp->right = NULL;
    *n = temp;
    return;
  }

  if((*n)->data >= input)
    insert(input, &(*n)->left);
  else if((*n)->data < input)
    insert(input, &(*n)->right);
}

void createTree(struct node **n, int noOfTimes)
{
  int i, input;

  for(i = 0; i < noOfTimes; i++)
  {
    printf("Enter data : ");
    scanf("%d", &input);
    insert(input, n);
  }
  if(root != NULL)
    printf("\n\nTree created successfully.\n");
  else
    printf("\n\nTree not created.\n");
}

//Inorder Traversal
void showInorder(struct node *t)
{
  if(t)
  {
    showInorder(t->left);
    printf("%d\t", t->data);
    showInorder(t->right);
  }
}

//PostOrder Traversal
void showPostorder(struct node *t)
{
  if(t)
  {
    showPostorder(t->left);
    showPostorder(t->right);
    printf("%d\t", t->data);
  }
}

//PreOrder Traversal
void showPreorder(struct node *t)
{
  if(t)
  {
    printf("%d\t", t->data);
    showPreorder(t->left);
    showPreorder(t->right);
  }
}

//Search in Binary tree
struct node *search(struct node *t, int key)
{
  if(!t)
    return NULL;
  if(key == t->data)
    return t;
  if(key < t->data)
    return search(t->left, key);
  else
    return search(t->right, key);
}

//Delete element in Binary Tree
int deleteBinaryTree(int element)
{
  struct node  *move, *back;

  if(root == NULL)
  {
    printf("Empty binary tree.\n");
    return -1;
  }
  else
  {
    move = root;
    back = move;

    while(move->data != element)
    {
      back = move;
      if(element < move->data)
      {
        move = move->left;
      }
      else
      {
        move = move->right;
      }
    }

    //if parent node has two child nodes
    if(move->left != NULL && move->right != NULL)
    {
      temp = move->right;
      while(temp->left != NULL)
      {
        back = temp;
        temp = temp->left;
      }

      move->data = temp->data;
      move = temp;
    }

    //if node has no child nodes
    if(move->left == NULL && move->right == NULL)
    {
      if(back->right == move)
      {
        back->right = NULL;
      }
      else
        back->left = NULL;

      free(move);
      return 0;
    }

    //if node has right child node
    if(move->left == NULL && move->right != NULL)
    {
      if(back->left == move)
      {
        back->left = move->right;
      }
      else
        back->right = move->right;

      free(move);
      return 0;
    }

    //if node has left child node
    if(move->left != NULL && move->right == NULL)
    {
      if(back->left == move)
        back->left = move->left;
      else
        back->right = move->left;

      free(move);
      return 0;
    }
  }
}
void menu()
{
  system("clear");
  printf("\tMENU\
          \n1. CREATE\
          \n2. DISPLAY\
          \n3. SEARCH\
          \n4. DELETE\
          \n5. EXIT\
          \n\nEnter choice : ");
}

void displayMenu()
{
  system("clear");
  printf("\tDISPLAY\
          \n1. INORDER\
          \n2. PREORDER\
          \n3. POSTORDER\
          \n\nEnter choice : ");
}
int main()
{

  int choice, ch, buffer,input, element, noOfElements;

  do
  {
    menu();
    scanf("%d", &choice);
    switch(choice)
    {
      case 1: system("clear");
              printf("CREATE TREE\n\n");
              printf("Enter number of nodes : ");
              scanf("%d", &noOfElements);
              createTree(&root, noOfElements);
              printf("\nPress 1 to continue.");
              scanf("%d", &buffer);
              break;

              printf("Press 1 to continue.");
              scanf("%d", &buffer);
              break;
      case 2: printf("DISPLAY\n");
              displayMenu();
              scanf("%d", &ch);
              switch(ch)
              {
                case 1: printf("INORDER\n");
                        printf("Inorder (RECURSIVE) : \n");
                        showInorder(root);


                        break;
                case 2: printf("PREORDER\n");
                        showPreorder(root);

                        break;
                case 3: printf("POSTORDER\n");
                        printf("\nPostorder (RECURSIVE) : \n");
                        showPostorder(root);

                        break;
                default: displayMenu();

              }
              printf("\n\nPress 1 to continue.");
              scanf("%d", &buffer);
              break;
      case 3: system("clear");
              printf("SEARCH\n");
              printf("\nEnter element to search : ");
              scanf("%d", &element);
              struct node *result = search(root, element);
              if(result == NULL)
                printf("\n\nElement not found.\n");
              else
                printf("%d found.\n", result->data);

              printf("\n\nPress 1 to continue.");
              scanf("%d", &buffer);
              break;
      case 4: system("clear");
              printf("DELETE\n");
              printf("Enter element to delete : ");
              scanf("%d", &input);
              element = deleteBinaryTree(input);
              if(element == 0)
                printf("\nElement deleted.\n");
              else
                printf("\nElement not deleted.\n");
              printf("\nPress 1 to continue.");
              scanf("%d", &buffer);
              break;

      default:menu();
    }
  } while(choice != 5);
  return 0;
}
