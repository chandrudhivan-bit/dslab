#include<stdio.h>
#define MAX_SIZE 100

void createArray(int arr[], int*size) {
    int n,i;
    printf("Enter the number of element: ");
    scanf("%d",&n);
    if(n > MAX_SIZE) {
        printf("error: number of elements exceeds the maximum array size.\n");
        return;
        }
        printf("Enter %d elements: ",n);
        for(i = 0;i < n; i++) {
            scanf("%d", &arr[i]);
            }
            
            *size = n;
            printf("Array created successfully.\n");
        }
        
        void insertElement(int arr[], int *size, int element, int position)
{
    if (position< 0 || position > *size) {
        printf("Invalid position\n");
        return;
    }

    if (*size >= 100) {
        printf("Array is full\n");
        return;
    }

    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = element;
    (*size)++;

    printf("Element inserted successfully.\n");
}
        
        int searchElement(int arr[],int size,int element) {
           int i;
           for(i=0;i<size; i++) {
               if(arr[i] == element) {
                 return i;
                 }
            }
            return -1;
        }
        void deleteElement(int arr[],int*size, int postion) {
        int i;
        if((postion < 0) || (postion >= *size)){
            printf("error: invalid position.\n");
            return;
        }
        for(i = postion; i< *size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        (*size)--;
        printf("Element deleted successfully.\n");
        }
      
      void displayarray(int arr[],int size) {
         int i;
         if(size == 0) {
              printf("Array is empty.\n");
              return;
          }
          printf("Array elements: ");
          for(i = 0;i < size;i++) {
              printf("%d ",arr[i]);
           }
           printf("\n");
          }
          
          int main() {
             int arr[MAX_SIZE];
             int size=0;
             int choice, element,position,result;
             
             while(1) {
                printf("\nArray operation menu:\n");
                printf("1. create array\n");
                printf("2. insert element\n");
                printf("3. search element\n");
                printf("4. delete element\n");
                printf("5. display array\n");
                printf("6. exit\n");
                printf("enter your choice: ");
                scanf("%d",&choice);
                
                switch(choice) {
                    case 1:
                     createArray(arr,&size);
                     break;
                    case 2:
                     printf("Enter element to insert: ");
                     scanf("%d", &element);
                     printf("Enter position to insert (0 to %d): ", size);
                     scanf("%d",  &position);
                     insertElement(arr,&size,element,position);
                     break;
                    case 3:
                    printf("Enter element to search: ");
                    scanf("%d",&element);
                    result  = searchElement(arr,size,element);
                    if(result != -1)
                        printf("element found at position: %d\n", result);
                    else 
                        printf("Element not found in the array\n");
                    break;
                    case 4:
                        printf("Enter position to delete (0 to %d): ",size-1);
                        scanf("%d",&position);
                        deleteElement(arr,&size,position);
                        break;
                    case 5:
                         displayarray(arr, size);
                         break;
                    case 6:
                         return 0;
                        default:
                           printf("Invalid choice! please enter a valid option.\n");
                  }
                }
                return 0;
            }    
                         
                    
             
                 
                         
                    
             
