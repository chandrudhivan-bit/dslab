#include <stdio.h>
#define MAX_SIZE 100
void createarray(int arr[], int*size) {
  int n, i;
  printf("Enter the number of element: ");
  scanf("%d",&n);
  if(n >MAX_SIZE) {
    printf ("error: number of element exceeds the maximum array size.\n");
    return;
  }
  printf("enter %d elements: ", n);
  for(i=0; i<n; i++) {
    scanf("%d", &arr[i]);
  }
  *size = n;
  printf("array created successfully.\n");
}
void inserElement(int arr[], int*size, int element, int position){
  int i;
  if(*size >= MAX_SIZE) {
    printf("error: array is full. cannot insert element.\n");
    return;
  }
  if((position <0) || (position > *size)) {
    printf("Error: invalid position.\n");
    return;
  }
  for(i=*size; i> position; i--) {
    arr[i] = arr[i -1];
  }
  arr[position] = element;
  (*size)++;
  printf("element inserted successfully.\n");
}
int searchelement(int arr[], int size, int element){
  int i;
  for (i=0; i < size; i++) {
    if(arr[i == element]) {
      return i;
    }
  }
  return -1;
}
void deleteElement(int arr[], int *size,  int position) {
  int i;
  if((position <0) || (position >= *size)) {
    printf("Error: invalid position.\n");
    return;
  }
  for(i = position; i < *size -1; i++) {
    arr[i] = arr[i+1];
  }
  (*size)--;
  printf("element deleted successfully.\n");
}
void displayarray(int arr[], int size) {
  int i;
  if (size==0) {
    printf("array is empty.\n");
    return ;
  }
  printf("array elements:");
  for(i=0; i< size; i++) {
    printf("%d",arr[i]);
  }
  printf("\n");
}
int main() {
  int arr[MAX_SIZE];
  int size=0;
  int choice, element, position, result;
  while(1) {
    printf("\narray Operation Menu:\n");
    printf("1.create array\n");
    printf("2.insert element\n");
    printf("3.search element\n");
    printf("4.delete element\n");
    printf("5.display array\n");
    printf("6.exit\n");
    printf("enter your choice");
    scanf("%d", &choice);
    switch(choice) {
      case 1:
        createarray(arr, &size);
        break;
      case 2:
        printf("enter element to insert: ");
        scanf("%d", &element);
        printf("enter position to insert (0 to %d): ", size);
        scanf("%d", &position);
        inserElement(arr, &size, element, position);
        break;
      case 3:
        printf("enter element to search: ");
        scanf("%d", &element);
        result = searchelement (arr, size, element);
        if(result != -1)
          printf("element found at position: %d\n", result);
        else 
          printf("element not found in the array\n");
        break;
      case 4:
        printf("enter position to delete (0 to %d): ", size-1);
        scanf("%d", &position);
        deleteElement(arr, &size, position);
        break;
      case 5:
        displayarray (arr, size);
        break;
      case 6:
        return 0;
      default:
        printf("invalid choice! please enter a valid option.\n");
    }
  }
  return 0;
}  
