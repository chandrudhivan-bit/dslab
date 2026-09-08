#include<stdio.h>
#include<stdlib.h>

struct Node{
   int data;
   struct Node* next;
  };
  
  struct Node* createNode(int data) {
  struct Node* newNode = (struct Node*)malloc (sizeof(struct Node));
  if(newNode == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
    }
    
    void insertAtEnd(struct Node** head,int data) {
          struct Node* newNode = createNode(data);
          if(*head == NULL) {
              *head = newNode;
               return;
               }
               struct Node* temp = *head;
               while(temp->next != NULL) {
                  temp = temp->next;
                  }
                  temp->next = newNode;
                }
                
                void insertAtpostion(struct Node** head, int data, int position) {
                    if(position < 0) {
                    printf("error: Invalid position.\n");
                    return;
                }
                
                struct Node* newNode = createNode(data);
                
                if(position == 0) {
                   newNode->next = *head;
                   *head = newNode;
                   return;
                   }
                   
                   struct Node* current = *head;
                   struct Node* previous = NULL;
                   int currentPos = 0;
                   while((current != NULL) && (currentPos < position)) {
                        previous = current;
                        current = current->next;
                        currentPos++;
                   }
                   if(currentPos != position) {
                     printf("Error: Invalid position.\n");
                     free(newNode);
                     return;
                   }

                   previous->next = newNode;
                   newNode->next = current;
                }

                void searchElement(struct Node* head, int data) {
                    struct Node* temp = head;
                    int position = 0;

                    while(temp != NULL) {
                        if(temp->data == data) {
                            printf("Element %d found at position %d.\n", data, position);
                            return;
                        }
                        temp = temp->next;
                        position++;
                    }

                    printf("Element %d not found.\n", data);
                }
      void deleteElement(struct Node** head, int position) {
                    struct Node* current = *head;
                    struct Node* previous = NULL;
                    int currentPos = 0;

                    if(current == NULL) {
                        printf("List is empty.\n");
                        return;
                    }

                    if(position < 0) {
                        printf("Error: Invalid position.\n");
                        return;
                    }

                    if(position == 0) {
                        *head = current->next;
                        free(current);
                       
                        return;
                    }

                    while(current != NULL && currentPos < position) {
                        previous = current;
                        current = current->next;
                        currentPos++;
                    }

                    if(current == NULL) {
                        printf("Error: Invalid position.\n");
                        return;
                    }

                    previous->next = current->next;
                    free(current);

                   
                }
         void display(struct Node* head) {
                    struct Node* temp = head;

                    if(temp == NULL) {
                        printf("List is empty.\n");
                        return;
                    }

                    printf("Linked List: ");

                    while(temp != NULL) {
                        printf("%d -> ", temp->data);
                        temp = temp->next;
                    }

                    printf("NULL\n");
                }

                int main() {
                    struct Node* head = NULL;
                    int choice, data, position;

                    while(1) {
                        printf("\n Singly Linked List Operations Menu \n");
                        printf("1. Insert at End\n");
                        printf("2. Insert at Position\n");
                        printf("3. Search Element\n");
                        printf("4. Delete Element\n");
                        printf("5. Display List\n");
                        printf("6. Exit\n");

                        printf("Enter your choice: ");
                        scanf("%d", &choice);

                        switch(choice) {
                            case 1:
                                printf("Enter data to insert at the end: ");
                                scanf("%d", &data);

                                insertAtEnd(&head, data);
                                break;

                            case 2:
                                printf("Enter data to insert: ");
                                scanf("%d", &data);

                                printf("Enter position to insert (0 - based index): ");
                                scanf("%d", &position);

                                insertAtpostion(&head, data, position);
                                break;

                            case 3:
                                printf("Enter element to search: ");
                                scanf("%d", &data);

                                searchElement(head, data);
                                break;

                            case 4:
                                printf("Enter position to delete (0 - based index): ");
                                scanf("%d", &data);

                                deleteElement(&head, data);
                                break;

                            case 5:
                                display(head);
                                break;

                            case 6:
                                printf("Exiting program...\n");
                                exit(0);

                            default:
                                printf("Invalid choice.\n");
                        }
                    }

                    return 0;
                }

