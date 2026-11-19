
#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

struct Item {
    int id;
    char name[50];
    char category[30];
    char description[100];
    char location[50];
    char date[15];
    char type[10];
    char status[15];
};


int readInt(const char *prompt) {
    char input[50];
    int number;

    while (1) {
        printf("%s", prompt);

        if (fgets(input, sizeof(input), stdin) != NULL) {
            if (sscanf(input, "%d", &number) == 1) {
                return number;
            }
        }

        printf("Invalid input! Please enter a number.\n");
    }
}


void readLine(const char *prompt, char text[], int size) {
    while (1) {
        printf("%s", prompt);

        if (fgets(text, size, stdin) == NULL) {
            text[0] = '\0';
            return;
        }

        text[strcspn(text, "\n")] = '\0';

        if (strlen(text) > 0) {
            break;
        }

        printf("This field cannot be empty!\n");
    }
}

void displayMenu(void) {
    printf("\n====================================\n");
    printf("   LOST AND FOUND MANAGEMENT SYSTEM\n");
    printf("====================================\n");
    printf("1. Add New Record\n");
    printf("2. Display All Records\n");
    printf("3. Search Record\n");
    printf("4. Update Record\n");
    printf("5. Delete Record\n");
    printf("6. Summary Report\n");
    printf("7. Save Records\n");
    printf("8. Exit\n");
    printf("====================================\n");
}

void addRecord(struct Item items[], int *itemCount, int *nextId) {

    if (*itemCount >= MAX_ITEMS) {
        printf("\nStorage is full! Cannot add more records.\n");
        return;
    }

    printf("\n========== ADD NEW RECORD ==========\n");

    items[*itemCount].id = *nextId;

    printf("Generated Item ID: %d\n", *nextId);

    readLine("Enter Item Name: ",
             items[*itemCount].name, 50);

    readLine("Enter Category: ",
             items[*itemCount].category, 30);

    readLine("Enter Description: ",
             items[*itemCount].description, 100);

    readLine("Enter Location: ",
             items[*itemCount].location, 50);

    readLine("Enter Date (DD-MM-YYYY): ",
             items[*itemCount].date, 15);

    int typeChoice;

    do {
        printf("\nSelect Item Type:\n");
        printf("1. Lost\n");
        printf("2. Found\n");

        typeChoice = readInt("Enter choice: ");

        if (typeChoice != 1 && typeChoice != 2) {
            printf("Invalid choice! Select 1 or 2.\n");
        }

    } while (typeChoice != 1 && typeChoice != 2);

    if (typeChoice == 1) {
        strcpy(items[*itemCount].type, "Lost");
    } else {
        strcpy(items[*itemCount].type, "Found");
    }

    strcpy(items[*itemCount].status, "Pending");

    (*itemCount)++;
    (*nextId)++;

    printf("\nRecord added successfully!\n");
}

void displayRecords(struct Item items[], int itemCount) {

    if (itemCount == 0) {
        printf("\nNo records found!\n");
        return;
    }

    printf("\n========== ALL REGISTERED RECORDS ==========\n");

    for (int i = 0; i < itemCount; i++) {

        printf("\n--------------------------------------------\n");

        printf("Record Number: %d\n", i + 1);
        printf("Item ID: %d\n", items[i].id);
        printf("Item Name: %s\n", items[i].name);
        printf("Category: %s\n", items[i].category);
        printf("Description: %s\n", items[i].description);
        printf("Location: %s\n", items[i].location);
        printf("Date: %s\n", items[i].date);
        printf("Type: %s\n", items[i].type);
        printf("Status: %s\n", items[i].status);
    }

    printf("\n--------------------------------------------\n");
    printf("Total Records: %d\n", itemCount);
    printf("============================================\n");
}

// Function to search for a record
void searchRecord(struct Item items[], int itemCount) {

    if (itemCount == 0) {
        printf("\nNo records available to search!\n");
        return;
    }

    int searchChoice;
    int searchId;
    int found = 0;
    char searchName[50];

    printf("\n========== SEARCH RECORD ==========\n");
    printf("1. Search by Item ID\n");
    printf("2. Search by Item Name\n");

    searchChoice = readInt("Enter your choice: ");

    if (searchChoice == 1) {

        searchId = readInt("Enter Item ID: ");

        for (int i = 0; i < itemCount; i++) {

            if (items[i].id == searchId) {

                printf("\nRecord Found!\n");
                printf("Item ID: %d\n", items[i].id);
                printf("Item Name: %s\n", items[i].name);
                printf("Category: %s\n", items[i].category);
                printf("Description: %s\n", items[i].description);
                printf("Location: %s\n", items[i].location);
                printf("Date: %s\n", items[i].date);
                printf("Type: %s\n", items[i].type);
                printf("Status: %s\n", items[i].status);

                found = 1;
                break;
            }
        }

    } else if (searchChoice == 2) {

        readLine("Enter Item Name: ", searchName, 50);

        for (int i = 0; i < itemCount; i++) {

            if (strcmp(items[i].name, searchName) == 0) {

                printf("\nRecord Found!\n");
                printf("Item ID: %d\n", items[i].id);
                printf("Item Name: %s\n", items[i].name);
                printf("Category: %s\n", items[i].category);
                printf("Description: %s\n", items[i].description);
                printf("Location: %s\n", items[i].location);
                printf("Date: %s\n", items[i].date);
                printf("Type: %s\n", items[i].type);
                printf("Status: %s\n", items[i].status);

                found = 1;
            }
        }

    } else {
        printf("\nInvalid search choice!\n");
        return;
    }

    if (found == 0) {
        printf("\nNo matching record found!\n");
    }
}

// Main function
int main(void) {

    struct Item items[MAX_ITEMS];

    int itemCount = 0;
    int nextId = 101;
    int choice = 0;

    do {

        displayMenu();

        choice = readInt("Enter your choice: ");

        switch (choice) {

            case 1:
                addRecord(items, &itemCount, &nextId);
                break;

            case 2:
                displayRecords(items, itemCount);
                break;

            case 3:
                searchRecord(items, itemCount);
                break;

            case 4:
                printf("\nUpdate Record feature will be implemented soon.\n");
                break;

            case 5:
                printf("\nDelete Record feature will be implemented soon.\n");
                break;

            case 6:
                printf("\nSummary Report feature will be implemented soon.\n");
                break;

            case 7:
                printf("\nSave Records feature will be implemented soon.\n");
                break;

            case 8:
                printf("\nThank you for using the system!\n");
                break;

            default:
                printf("\nInvalid choice! Please select 1-8.\n");
        }

    } while (choice != 8);

    return 0;
}
