#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXLEN 30

//Struct for the list
typedef struct list 
{
    char name[MAXLEN]; //name of the list
    struct list *prevPtr; // prev list
    struct list *nextPtr; // next list
    struct item *firstitem; //first item of the list
}List;

//Struct for the item
typedef struct item
{
    char name[MAXLEN]; //name of the item
    struct item *prevPtrI; //prev item
    struct item *nextPtrI; //next item
}Item;


typedef List *ListPtr; //naming the structs
typedef Item *ItemPtr; 

// All function prototypes
void displayMenu();
void displayBoard(ListPtr Board);
void load_board(ListPtr Board);
void clear_board(ListPtr Board);
void edit_list(ListPtr Board);
void editListName(ListPtr Board);
void edit_board(ListPtr Board);
void editItemName(char listName[MAXLEN], ListPtr Board);
void addNewItem(char listName[MAXLEN], ListPtr Board);
void deleteItem(char listName[MAXLEN], ListPtr Board);
void editListName(ListPtr Board);
void addNewList(ListPtr Board);
void deleteList(ListPtr Board);
void save_board(ListPtr Board);


int user_input = 0;

int main(void)
{
    printf("\nKANBAN-STYLE BOARD GENERATOR\n**Lists are indicated by a colon after the name e.g. 'Abey:' as opposed to 'Abey'. Item names should not end with a colon**\n");
    
    ListPtr Board;

    
    List *list1 = malloc(sizeof(List));                          //Create Memory for 1st list
    strcpy(list1->name,"Nick:");                                 //add the name to the list
    list1->nextPtr = NULL;                                       //initalise the nextPtr
    Item *item1_1 = malloc(sizeof(Item));                        //Create Memory for 1st Item
    strcpy(item1_1->name, "3070 RTX");                           //add the name to the item

    item1_1->nextPtrI = NULL;                                    //Initalise the nextPtrI
    list1->firstitem = item1_1;                                  //Assign the first item to the list

    List *list2 = malloc(sizeof (List));
    strcpy(list2->name, "Tim:");
    list2->nextPtr = NULL;
    Item *item2_1 = malloc(sizeof (Item));
    strcpy(item2_1->name, "Oculus Quest 2");


    item2_1->nextPtrI = NULL;
    list2->firstitem = item2_1;

    List *list3 = malloc(sizeof (List));
    strcpy(list3->name, "Dante:");
    list3->nextPtr = NULL;
    Item *item3_1 = malloc(sizeof(Item));
    strcpy(item3_1->name, "Oculus Quest 1");
    Item *item3_2 = malloc(sizeof(Item));
    strcpy(item3_2->name, "3070 RTX");

    item3_1->nextPtrI = item3_2;
    item3_2->nextPtrI = NULL;
    list3->firstitem = item3_1;

    List *list4 = malloc(sizeof (List));
    strcpy(list4->name, "Abey:");
    list4->nextPtr = NULL;
    Item *item4_1 = malloc(sizeof(Item));
    strcpy(item4_1->name, "Oculus Pro");
    Item *item4_2 = malloc(sizeof(Item));
    strcpy(item4_2->name, "Oculus Quest 1");

    item4_1->nextPtrI = item4_2;
    item4_2->nextPtrI = NULL;
    list4->firstitem = item4_1;


    //Initalise the rest of the lists and assign the next and previous lists
    list1->prevPtr = NULL;
    list1->nextPtr = list2;
    list2->nextPtr = list3;
    list3->nextPtr = list4;

    list2->prevPtr = list1;
    list3->prevPtr = list2;
    list4->prevPtr = list3;

    //assign the start of the Lists to Board
    Board = list1;


    //If statements for user input
	while (user_input != 6)
	{
		displayMenu();

		if (user_input == 1)
		{
			displayBoard(Board);
		}

		else if (user_input == 2)
		{
			load_board(Board);
		}

		else if (user_input == 3)
		{
			edit_list(Board);
		}

		else if (user_input == 4)
		{
			edit_board(Board);
		}

		else if (user_input == 5)
		{
			save_board(Board);
		}
	}

    /*.----------------.  .----------------.  .----------------.  .----------------.  .----------------. 
    | .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |
    | |  ____  ____  | || |      __      | || | ____    ____ | || |   ________   | || |      __      | |
    | | |_   ||   _| | || |     /  \     | || ||_   \  /   _|| || |  |  __   _|  | || |     /  \     | |
    | |   | |__| |   | || |    / /\ \    | || |  |   \/   |  | || |  |_/  / /    | || |    / /\ \    | |
    | |   |  __  |   | || |   / ____ \   | || |  | |\  /| |  | || |     / /  _   | || |   / ____ \   | |
    | |  _| |  | |_  | || | _/ /    \ \_ | || | _| |_\/_| |_ | || |   _/ /__/ |  | || | _/ /    \ \_ | |
    | | |____||____| | || ||____|  |____|| || ||_____||_____|| || |  |________|  | || ||____|  |____|| |
    | |              | || |              | || |              | || |              | || |              | |
    | '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |
     '----------------'  '----------------'  '----------------'  '----------------'  '----------------' 

     .----------------.  .----------------.  .----------------.  .-----------------.
    | .--------------. || .--------------. || .--------------. || .--------------. |
    | |  _________   | || |     ____     | || |     _____    | || | ____  _____  | |
    | | |_   ___  |  | || |   .'    `.   | || |    |_   _|   | || ||_   \|_   _| | |
    | |   | |_  \_|  | || |  /  .--.  \  | || |      | |     | || |  |   \ | |   | |
    | |   |  _|  _   | || |  | |    | |  | || |      | |     | || |  | |\ \| |   | |
    | |  _| |___/ |  | || |  \  `--'  /  | || |     _| |_    | || | _| |_\   |_  | |
    | | |_________|  | || |   `.____.'   | || |    |_____|   | || ||_____|\____| | |
    | |              | || |              | || |              | || |              | |
    | '--------------' || '--------------' || '--------------' || '--------------' |
     '----------------'  '----------------'  '----------------'  '----------------'  */

	return 0;
}

//Displays the meny with the Options
void displayMenu(){

	puts("\nMenu:");
	fflush(stdout);
	puts("1. Display Board");
	fflush(stdout);
	puts("2. Load board from a file");
	fflush(stdout);
	puts("3. Edit list");
	fflush(stdout);
	puts("4. Edit Board");
	fflush(stdout);
	puts("5. Save board to a file");
	fflush(stdout);
	puts("6. Quit");
	fflush(stdout);

	scanf("%d", &user_input);
    fflush(stdin);
	printf("\n");

}

/*************************************************************************************************************************************
 *************************************************************************************************************************************
 *************************************************************************************************************************************/
// Displaying the Board

/*Assigns 'front' to the start of the list and goes into a while loop that keeps going until it reaches the end, prints the list name
and then goes into the list and prints the item names.
*/
void displayBoard(ListPtr Board)
{
	ListPtr front = Board;

    while(front != NULL)
    {
        printf("%s\n", front->name);
        fflush(stdout);
        ItemPtr itemT = front->firstitem;
        while (itemT != NULL)
        {
            printf("\t%s\n", itemT->name);
            fflush(stdout);
            itemT = itemT->nextPtrI;
        }

        front = front->nextPtr;

    }


}

/**************************************************************************************************************************************
 **************************************************************************************************************************************
 **************************************************************************************************************************************/
// Loading the board from a file

/* Goes through the Lists and the items of the lists and uses free to clear out the memory for them */
void clear_board(ListPtr Board)
{
	ListPtr currentList = Board;

	while (currentList != NULL)
	{
		ItemPtr currentItem = currentList->firstitem;
		while (currentItem != NULL)
		{
			ItemPtr nextItem = currentItem->nextPtrI;
			free(currentItem);
			currentItem = nextItem;
		}

		ListPtr nextList = currentList->nextPtr;
		free(currentList);
		currentList = nextList;

	}

	return;
}

/* Asks the user for input for filename and then opens file using a pointer to a file and fopen.
*/
void load_board(ListPtr Board)
{
    char filename[MAXLEN];

    printf("Enter filename: ");
    fgets(filename, MAXLEN, stdin);

    if (filename[strlen(filename) - 1] == '\n')
    {
        filename[strlen(filename) - 1] = '\0';
    }

    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("\nError: could not open file %s\n", filename);
        return;
    }
    else
    {
        char line[MAXLEN];
        ListPtr currentList = Board;

        // Clear existing data on the board
        clear_board(Board);

        // Read data from the file line by line
        while (fgets(line, MAXLEN, fp) != NULL)
        {
            
            if (line[strlen(line) - 1] == '\n')
            {
                line[strlen(line) - 1] = '\0';
            }

            // If line ends with ':',then that means it's a list name
            if (line[strlen(line) - 1] == ':')
            {
                // Create memory for new list
                ListPtr newList = malloc(sizeof(List));
                if (newList == NULL)
                {
                    printf("Memory allocation failed\n");
                    return;
                }
                // Initialize list properties
                strcpy(newList->name, line);
                newList->prevPtr = currentList;
                newList->nextPtr = NULL;
                newList->firstitem = NULL;

                // If current list is not NULL, update its nextPtr
                if (currentList != NULL)
                {
                    currentList->nextPtr = newList;
                }

                // Move currentList pointer to the new list
                currentList = newList;
            }

            else
            {
                // If name doesnt contain ':' then it's an item

                // Create memory for a new item
                ItemPtr newItem = malloc(sizeof(Item));
                if (newItem == NULL)
                {
                    printf("Memory allocation failed\n");
                    return;
                }
                // Initialize item properties
                strcpy(newItem->name, line);
                newItem->prevPtrI = NULL;
                newItem->nextPtrI = NULL;

                // If currentlist has no items, set newItem as the first item
                if (currentList->firstitem == NULL)
                {
                    currentList->firstitem = newItem;
                }

                else
                {
                    // Otherwise find the last item and add newItem to it
                    ItemPtr lastItem = currentList->firstitem;
                    while (lastItem->nextPtrI != NULL) 
                    {
                        lastItem = lastItem->nextPtrI;
                    }

                    lastItem->nextPtrI = newItem;
                    newItem->prevPtrI = lastItem;
                }
            }
        }
        //close the file
        fclose(fp);
        printf("Board loaded successfully from %s\n", filename);
    }

    return;
}

/*********************************************************************************************
 * *******************************************************************************************
 */
// Editing the Lists

void editItemName(char listName[MAXLEN], ListPtr Board)
{
    char oldName[MAXLEN], newName[MAXLEN];

    //Initalise pointer
    ListPtr currentList = Board;

    //Find the match or until currentList reaches the end
    while (currentList != NULL && strcmp(currentList->name, listName) != 0)
    {

        currentList = currentList->nextPtr;
    }

    //if The list name is found
    if (currentList != NULL)
    {

        printf("\nEnter the name of the item to edit:");
        fgets(oldName, MAXLEN, stdin);
        fflush(stdin);

        if (oldName[(strlen(oldName) - 1)] == '\n')
        {
        	oldName[(strlen(oldName) - 1)] = '\0';
        }

        //initalise pointer for first item
        ItemPtr currentItem = currentList->firstitem;

        //Find the match for the item or until currentItem reaches the end
        while (currentItem != NULL && strcmp(currentItem->name, oldName) != 0)
        {

        	currentItem = currentItem->nextPtrI;
        }

        //if item name is found
        if (currentItem != NULL)
        {
            printf("\nEnter new name for item '%s':", oldName);
            fgets(newName, MAXLEN, stdin);
            fflush(stdin);

            if (newName[(strlen(newName) - 1)] == '\n')
            {
            	newName[(strlen(newName) - 1)] = '\0';
            }

            //copy the newname to the item which replaces the old name
            strcpy(currentItem->name, newName);
            printf("\nItem name updated successfully.\n\n");

        }

        else
        {
        	printf("\nItem was not found\n\n");
        }
    }

    else
    {
        printf("\nList was not found\n\n");
    }

    return;
}

void addNewItem(char listName[MAXLEN], ListPtr Board)
{   
    //create Memory for new item
    ItemPtr newItem = malloc(sizeof(Item));


    if (newItem == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    //initalise the item
    newItem->prevPtrI = NULL;
    newItem->nextPtrI = NULL;


    printf("\nEnter the name of the new item: ");
    fgets(newItem->name, MAXLEN, stdin);
    fflush(stdin);

    if (newItem->name[strlen(newItem->name) - 1] == '\n')
    {
    	newItem->name[strlen(newItem->name) - 1] = '\0';
    }

    //initalise pointer
    ListPtr currentList = Board;

        //Find the match for the list or until currentList reaches the end
        while (currentList != NULL && strcmp(currentList->name, listName) != 0)
        {
            currentList = currentList->nextPtr;
        }


        //if List is found
        if (currentList != NULL)
        {
            //if list has no items then add the newitem to the firstitem of the list
            if (currentList->firstitem == NULL)
            {
                currentList->firstitem = newItem;
            }

            else
            {
                //initalise the pointer 
                ItemPtr lastItem = currentList->firstitem;

                //find the last item and attach the new item to the end of the list
                while (lastItem->nextPtrI != NULL)
                {   
                    lastItem = lastItem->nextPtrI;
                }

                //initalise the previous and next pointers
                lastItem->nextPtrI = newItem;
                newItem->prevPtrI = lastItem;
            }

            printf("New item added successfully.\n\n");
        }

        else
        {
            printf("\nList not found\n\n");
            free(newItem);
        }
}

void deleteItem(char listName[MAXLEN], ListPtr Board)
{

	char nameToDelete[MAXLEN];

	printf("\nEnter the name of the item to delete:");
    fgets(nameToDelete, MAXLEN, stdin);
    fflush(stdin);

    if (nameToDelete[(strlen(nameToDelete) - 1)] == '\n')
    {
        nameToDelete[(strlen(nameToDelete) - 1)] = '\0';
    }

    //initalise pointer
    ListPtr currentList = Board;

    //Find the match for the list or until currentList reaches the end
    while(currentList != NULL && strcmp(currentList->name, listName) != 0)
    {
    	currentList = currentList->nextPtr;
    }

    //if list is found
    if (currentList != NULL)
    {
        //initalise pointers for items
        ItemPtr currentItem = currentList->firstitem;
        ItemPtr prevItem = NULL;
        
        //Find the match for the item or until currentItem reaches the end
        while (currentItem != NULL && strcmp(currentItem->name, nameToDelete) != 0)
        {
            //moving pointer to next item
            prevItem = currentItem;
            currentItem = currentItem->nextPtrI;
        }

        //if item is found
        if (prevItem != NULL)
        {
        	//connecting previous item and next item
        	prevItem->nextPtrI = currentItem->nextPtrI;
        }
        else
        {
            //if item to delete is first item in list
        	currentList->firstitem = currentItem->nextPtrI;
        }

        //if item to delete is not last item
        if (currentItem->nextPtrI != NULL)
        {
        	currentItem->nextPtrI->prevPtrI = prevItem;
        }

        //freeing memory
        free(currentItem);

        printf("Item deleted successfully\n\n");


    }

    return;

}

void edit_list(ListPtr Board)
{
    char listName[MAXLEN];

    printf("\nEnter the name of the list to edit:");
    fgets(listName, MAXLEN, stdin);
    fflush(stdin);

    if (listName[(strlen(listName) - 1)] == '\n')
    {
    	listName[(strlen(listName) - 1)] = '\0';
    }

    //initalise pointer for list
    ListPtr currentList = Board;

    //Find the match for the list or until currentList reaches the end
    while (currentList != NULL && strcmp(currentList->name, listName) != 0)
    {

        currentList = currentList->nextPtr;
    }

    //if list is found get input from user on what they want to do to the list
    if (currentList != NULL)
    {
        char input[MAXLEN];
        int choice;

        printf("Options:\n1. Edit an item\n2. Add a new item\n3. Delete an item\n4. Return to main menu\nEnter your option:");
        fgets(input, MAXLEN, stdin);
        fflush(stdin);

        choice = atoi(input);
        if (choice == 1)
        {
        	editItemName(listName, Board);
            return;
        }
        else if (choice == 2)
        {
        	addNewItem(listName,Board);
            return;
        }
        else if (choice == 3)
        {
        	deleteItem(listName,Board);
            return;
        }
        else if (choice == 4)
        {
            return;
        }

        else
        {
            printf("\nInvalid input - Try again\n");
            edit_list(Board);
            return;
        }
    }

    else
    {
        printf("\nList was not found\n\n");
    }

    return;


}


/*********************************************************************************************
 * *******************************************************************************************
 */
// Editing the Board

void editListName(ListPtr Board)
{
    char oldName[MAXLEN], newName[MAXLEN];

    printf("\nEnter the name of the list to edit:");
    fgets(oldName, MAXLEN, stdin);
    fflush(stdin);
    //getting rid of newline character if present
    if (oldName[(strlen(oldName) - 1)] == '\n')
    {
        oldName[(strlen(oldName) - 1)] = '\0';
    }
    //initialising pointer for checking list names
    ListPtr currentList = Board;
    //checking inputted name against all list names until a match is found or no more lists to check
    while (currentList != NULL && strcmp(currentList->name, oldName) != 0)
    {
        //moving pointer to next list
        currentList = currentList->nextPtr;
    }

    //if match is found
    if (currentList != NULL)
    {
        printf("\nEnter the new name for list:");
        fgets(newName, MAXLEN, stdin);
        fflush(stdin);
        //getting rid of newline character if present
        if (newName[(strlen(newName) - 1)] == '\n')
        {
            newName[(strlen(newName) - 1)] = '\0';
        }
        //copying newly inputted name into list name
        strcpy(currentList->name, newName);
        printf("\nList name updated successfully.\n\n");
    }
    //match wasn't found
    else
    {
        printf("\nList was not found\n\n");
    }

    return;

}

void addNewList(ListPtr Board)
{
    //allocating memory for new list
    ListPtr newList = malloc(sizeof(List));

    //memeory allocation error
    if (newList == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    //initialising new list
    newList->prevPtr = NULL;
    newList->nextPtr = NULL;
    newList->firstitem = NULL;

    //taking input for name of list
    printf("\nEnter the name of the new list: ");
    fgets(newList->name, MAXLEN, stdin);
    fflush(stdin);
    //getting rid of newline character if present
    if (newList->name[strlen(newList->name) - 1] == '\n')
    {
        newList->name[strlen(newList->name) - 1] = '\0';
    }

    //initialising pointer for last list check
    ListPtr lastList = Board;

    //finding last list in board
    while (lastList->nextPtr != NULL)
    {
        lastList = lastList->nextPtr;
    }

    //inserting new list at the end of board
    lastList->nextPtr = newList;
    newList->prevPtr = lastList;

    printf("New list added successfully.\n\n");

    return;
}

void deleteList(ListPtr Board)
{
	char nameToDelete[MAXLEN];

	printf("\nEnter the name of the list to delete:");
    fgets(nameToDelete, MAXLEN, stdin);
    fflush(stdin);
    //getting rid of newline character if present
    if (nameToDelete[(strlen(nameToDelete) - 1)] == '\n')
    {
        nameToDelete[(strlen(nameToDelete) - 1)] = '\0';
    }
    //initialising pointer for checking list names
    ListPtr currentList = Board;
    ListPtr prevList = NULL;
    //checking inputted name against all list names until a match is found or no more lists to check
    while (currentList != NULL && strcmp(currentList->name, nameToDelete) != 0)
    {
        //moving pointer to next list
        prevList = currentList;
        currentList = currentList->nextPtr;
    }

    if (prevList != NULL)
    {
    	//connecting previous list and next list
        prevList->nextPtr = currentList->nextPtr;
    }
    else
    {
        //if list to delete is first list in board
        Board = currentList->nextPtr;
    }

    //if list to delete is not last list
    if (currentList->nextPtr != NULL)
    {
        currentList->nextPtr->prevPtr = prevList;
    }

    //freeing memory
    free(currentList);

    printf("List deleted successfully\n\n");

    return;
}

void edit_board(ListPtr Board)
{
    //temp variables for user input
    char input[MAXLEN];
    int choice;

    printf("Options:\n1. Edit the name of a list\n2. Add a new list\n3. Delete a list\n4. Return to main menu\nEnter your option:");
    fgets(input, MAXLEN, stdin);
    fflush(stdin);
    //converting string to int
    choice = atoi(input);
    if (choice == 1)
    {
        editListName(Board);
        edit_board(Board);
        return;
    }
    else if (choice == 2)
    {
    	addNewList(Board);
    	edit_board(Board);
        return;
    }
    else if (choice == 3)
    {
    	deleteList(Board);
    	edit_board(Board);
        return;
    }
    else if (choice == 4)
    {
        return;
    }
    //input didnt match options
    else
    {
        printf("\nInvalid input - Try again\n");
        //calling function again
        edit_board(Board);
        return;
    }
}


/*********************************************************************************************
 * *******************************************************************************************
 */
// Saving to a file

void save_board(ListPtr Board)
{
    char filename[MAXLEN];

    FILE *fp;

    printf("Enter the filename to save the board to: ");
    fgets(filename, MAXLEN, stdin);
    if (filename[strlen(filename) - 1] == '\n')
    {
        filename[strlen(filename) - 1] = '\0';
    }

    fp = fopen(filename, "w");

    if (fp == NULL)
    {
        printf("\nFile not found\n");
        return;
    }

    ListPtr currentList = Board;

    while (currentList != NULL)
    {
        fprintf(fp, "%s\n", currentList->name);
        ItemPtr currentItem = currentList->firstitem;

        while (currentItem != NULL)
        {
            fprintf(fp, "\t%s\n", currentItem->name);
            currentItem = currentItem->nextPtrI;
        }

        currentList = currentList->nextPtr;
    }

    fclose(fp);

    printf("Board saved successfully");
}