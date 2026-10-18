#include <stdio.h>
#include <stdlib.h>

struct node {
    int id;
    char name[30];
    char dept[30];
    int marks;
    struct node *next;
};

struct node *head = NULL;

// ADD
void add_student() {
    struct node *newnode, *temp;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter ID: ");
    scanf("%d", &newnode->id);

    printf("Enter Name: ");
    scanf("%s", newnode->name);

    printf("Enter Department: ");
    scanf("%s", newnode->dept);

    printf("Enter Marks: ");
    scanf("%d", &newnode->marks);

    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newnode;
    }

    printf("Student Added Successfully\n");
}

// DELETE
void delete_student() {
    int id;
    struct node *temp, *prev;

    printf("Enter ID to delete: ");
    scanf("%d", &id);

    temp = head;
    prev = NULL;

    while (temp != NULL) {
        if (temp->id == id) {
            if (prev == NULL)
                head = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            printf("Deleted Successfully\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Student not found\n");
}

// SEARCH
void search_student() {
    int id;
    struct node *temp = head;

    printf("Enter ID to search: ");
    scanf("%d", &id);

    while (temp != NULL) {
        if (temp->id == id) {
            printf("\nStudent Found:\n");
            printf("ID: %d\n", temp->id);
            printf("Name: %s\n", temp->name);
            printf("Dept: %s\n", temp->dept);
            printf("Marks: %d\n", temp->marks);
            return;
        }

        temp = temp->next;
    }

    printf("Student not found\n");
}

// DISPLAY
void display_students() {
    struct node *temp = head;

    if (temp == NULL) {
        printf("No records\n");
        return;
    }

    printf("\n--- Student List ---\n");

    while (temp != NULL) {
        printf("ID: %d | Name: %s | Dept: %s | Marks: %d\n",
               temp->id, temp->name, temp->dept, temp->marks);

        temp = temp->next;
    }
}

// MAIN MENU
int main() {
    int choice;

    while (1) {
        printf("\n1.Add 2.Delete 3.Search 4.Display 5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student();
                break;

            case 2:
                delete_student();
                break;

            case 3:
                search_student();
                break;

            case 4:
                display_students();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}

