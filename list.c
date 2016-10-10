#include <stdio.h>
#include <stdlib.h>

struct node {int i; struct node *next; };

int print_list(struct node *start){
  printf("{ ");
  return printHelper(start);
}

int printHelper(struct node *x){
  if(x == 0 ){
    printf("}\n");
    return 0;
  }
  if(x->next == 0){
    printf("%d }\n", x->i);
    return 0;
  }
  printf("%d ", x->i);
  return printHelper(x->next);
}

struct node * insert_front(struct node *beginning, int x){
  struct node *k = (struct node *)calloc(1, sizeof(struct node *));
  k->next = beginning;
  k->i = x;
  return k;
}

struct node * free_list(struct node *beginning){
  if(beginning == NULL){
    return beginning;
  }
  if(free_list(beginning->next) == NULL){
    //beginning->i = NULL;
    free(beginning);
  }
  return NULL;
}

int main(){
  struct node *beginning=0;
  int length = 0;
  int option;
  while(1){
    printf("\n\n\nPlease enter, 1 to print the list, 2 to add an integer to the list or any other integer to terminate this program :");
    scanf("%d", &option);
    printf("\n");
    if(option == 1){
      print_list(beginning);
    }else if(option == 2){
      int k;
      printf("choose the integer to insert: ");
      scanf("%d", &k);
      beginning = insert_front(beginning, k);
    }else{
      free_list(beginning);
      return 0;
    }
  }
}
