#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{

    long postalCode;
    char street[20];
    char city[20];

} location;

typedef struct
{

    char firstName[20];
    char lastName[20];
    int age;
    location address;

} people;


// Declaring Global variables
int listLength, i;
char choice;

// Declaring function

// Main menu run first
void menuMain();

// 2nd Menu run after user enter data
void menu(people human[]);

// Run after Main Menu
void addPeople();

// Add more people
//void addMorePeople(people human[]);

// Run to display data, if I chose that in the 2nd menu
void displayPeople(people human[]);

// Run to update insert data, if I chose that in the 2nd menu
void updatePeople(people human[]);

// Run to erase insert data, if I chose that in the 2nd menu
void erasePeople(people human[]);


int main()
{

    printf("----------------------------------------------------------------");
    printf("\n--You're in the home section of the People Manager application--");
    printf("\n----------------------------------------------------------------");

    menuMain();

    return 0;
}

void menuMain()
{

    printf("\n--------------------------Start Menu----------------------------");
    printf("\n----------------------------------------------------------------");
    printf("\n-----------------You Had One Choice to Make !!!-----------------\n");

    do
    {

        printf("\nEnter 'I' or 'i' to start entering information for your people.\n");
        printf("\nEnter 'D' or 'd' to display your list of people.\n");
        printf("\nEnter 'U' or 'u' to update a person in your list.\n");
        printf("\nEnter 'E' or 'e' to delete a person from your list.\n");
        printf("\nEnter 'O' or 'o' to exit the application.\n");
        printf("\nEnter Your Choice: ");
        scanf("%s", &choice);

        if (choice == 'I' || choice == 'i')
        {

            choice = 'i';

        }
        else if (choice == 'D' || choice == 'd')
        {

            choice = 'd';

        }
        else if (choice == 'U' || choice == 'u')
        {

            choice = 'u';

        }
        else if (choice == 'E' || choice == 'e')
        {

            choice = 'e';

        }
        else if (choice == 'O' || choice == 'o')
        {

            choice = 'o';

        }

    }

    while ( choice != 'i' && choice != 'd' && choice != 'u' && choice != 'e' && choice != 'o');


    switch (choice)
    {

    case 'i':
        addPeople();
        break;

    case 'd':
        printf("\nOops! There is no data to display!\n");
        menuMain();
        break;

    case 'u':
        printf("\nOops! There is no data to update!\n");
        menuMain();
        break;

    case 'e':
        printf("\nOops! There is no data to delete!\n");
        menuMain();
        break;

    case 'o':
        exit(0);
        break;

    };

}

void menu(people human[])
{

    printf("\n------------------------------Menu------------------------------");
    printf("\n----------------------------------------------------------------");
    printf("\n-----------------You Had One Choice to Make !!!-----------------\n");

    do
    {

        printf("\nEnter 'A' or 'a' to start adding more people to your list.\n");
        printf("\nEnter 'D' or 'd' to display your list of people.\n");
        printf("\nEnter 'U' or 'u' to update a person in your list.\n");
        printf("\nEnter 'E' or 'e' to delete a person from your list.\n");
        printf("\nEnter 'O' or 'o' to exit the application.\n");
        printf("\nEnter Your Choice: ");
        scanf("%s", &choice);

        if (choice == 'A' || choice == 'a')
        {

            choice = 'a';

        }
        else if (choice == 'D' || choice == 'd')
        {

            choice = 'd';

        }
        else if (choice == 'U' || choice == 'u')
        {

            choice = 'u';

        }
        else if (choice == 'E' || choice == 'e')
        {

            choice = 'e';

        }
        else if (choice == 'O' || choice == 'o')
        {

            choice = 'o';

        }

    }

    while ( choice != 'a' && choice != 'd' && choice != 'u' && choice != 'e'  && choice != 'o');

    switch (choice)
    {

    case 'a':

        printf("\nAt the moment, you cannot add more people!!?\n");
        menu(human);
        break;

    case 'd':

        displayPeople(human);
        break;

    case 'u':
        updatePeople(human);
        break;

    case 'e':
        erasePeople(human);
        break;

    case 'o':
        exit(0);
        break;

    };

}

void addPeople()
{

    printf("\n----------------------------------------------------------------");
    printf("\n----You\'re in the section for entering people's information-----");
    printf("\n----------------------------------------------------------------");
    printf("\n--Enter '0' to exit this section and return to your start menu--");
    printf("\n----------------------------------------------------------------\n");

    printf("\n----------------------------------------------------------------");
    printf("\n-----------Please enter the length of your list: ");
    scanf("%d", &listLength);

    if (listLength == 0)
    {

        menuMain();

    }

    people human[listLength];

    for(i = 0; i < listLength; i++)
    {
        printf("----------------------------------------------------------------");
        printf("\n-----------Please enter person number %d information-------------\n", i + 1);

        printf("\nPlease enter this person First Name: ");
        scanf(" %[^\n]", &human[i].firstName);

        if (strcmp(human[i].firstName, "0") == 0)
        {
            menuMain();

        }

        printf("\nPlease enter %s\'s Last Name: ", human[i].firstName);
        scanf(" %[^\n]", &human[i].lastName);

        if (strcmp(human[i].lastName, "0") == 0)
        {
            menuMain();

        }

        printf("\nPlease enter %s\'s Age: ", human[i].firstName);
        scanf("%d", &human[i].age);

        if (human[i].age == 0)
        {
            menuMain();

        }

        printf("\nPlease enter %s\'s Postal Code: ", human[i].firstName);
        scanf("%ld", &human[i].address.postalCode);

        if (human[i].address.postalCode == 0)
        {
            menuMain();

        }

        printf("\nPlease enter %s\'s Street Address: ", human[i].firstName);
        scanf(" %[^\n]", &human[i].address.street);

        if (strcmp(human[i].address.street, "0") == 0)
        {
            menuMain();

        }

        printf("\nPlease enter %s\'s City Name: ", human[i].firstName);
        scanf(" %[^\n]", &human[i].address.city);
        printf("\n");

        if (strcmp(human[i].address.city, "0") == 0)
        {
            menuMain();

        }

    }

    menu(human);

}


void displayPeople(people human[])
{

    printf("\n----------------------------------------------------------------");
    printf("\n---You\'re in the section for displaying people's information----");
    printf("\n----------------------------------------------------------------");

    for(i = 0; i < listLength; i++)
    {

        printf("\n------------------Person number %d information-------------------\n", i + 1);

        printf("\nHis/Her Full Name is: %s, %s", human[i].lastName, human[i].firstName);
        printf("\nHis/Her Age is: %d", human[i].age);
        printf("\nHis/Her Address is: %ld, %s, %s\n", human[i].address.postalCode, human[i].address.street, human[i].address.city);

    }

    int noExit;
    printf("\n----------------------------------------------------------------");
    printf("\nEnter '1' to exit this section and return to your start menu,\nOr enter '0' to exit the entire program: ");
    scanf("%d",&noExit);
    printf("----------------------------------------------------------------\n");

    if(noExit == 1)
    {
        menu(human);
    }
    else
    {
        exit(0);
    }

}

void updatePeople(people human[])
{

    printf("\n----------------------------------------------------------------");
    printf("\n----You\'re in the section for updating people's information-----");
    printf("\n----------------------------------------------------------------\n");

    int personId;
    int updateNumber;

    printf("\nPlease enter the list number of the person you want to update.");
    printf("\nIf you don't remember,\nenter '0' to display your list and choose a person: ");
    scanf("%d", &personId);

    if (personId == 0)
    {

        displayPeople(human);

    }
    else
    {
        for(i = 0; i < listLength; i++)
        {

            if (i == (personId - 1))
            {


                printf("\n------------------Person number %d information-------------------\n", i + 1);

                printf("\n1. His/Her First Name is: %s", human[i].firstName);
                printf("\n2. His/Her Last Name is: %s", human[i].lastName);
                printf("\n3. His/Her Age is: %d", human[i].age);
                printf("\n4. His/Her Postal Code is: %ld", human[i].address.postalCode);
                printf("\n5. His/Her Street is: %s", human[i].address.street);
                printf("\n6. His/Her City is: %s", human[i].address.city);

                do
                {

                    printf("\n\nPlease chose one number to specify what you want to update: ");
                    scanf("%d", &updateNumber);

                }
                while(updateNumber != 1 && updateNumber != 2 && updateNumber != 3 && updateNumber != 4 && updateNumber != 5 && updateNumber != 6);

                switch (updateNumber)
                {

                case 1:

                    printf("\nPlease enter the new first name: ");
                    scanf("%s", &human[i].firstName);
                    break;

                case 2:

                    printf("\nPlease enter the new last name: ");
                    scanf("%s", &human[i].lastName);
                    break;

                case 3:

                    printf("\nPlease enter the new age: ");
                    scanf("%s", &human[i].age);
                    break;

                case 4:

                    printf("\nPlease enter the new postal code: ");
                    scanf("%s", &human[i].address.postalCode);
                    break;

                case 5:

                    printf("\nPlease enter the new street: ");
                    scanf("%s", &human[i].address.street);
                    break;

                case 6:

                    printf("\nPlease enter the new first name: ");
                    scanf("%s", &human[i].address.city);
                    break;

                };

                break;

            }

        }

        menu(human);
    }

}

/*void erasePeople(people human[])
{

    int personId;
    int updateNumber;
    printf("\n--------------------------------------------------------------");
    printf("\nPlease enter your the person list number that you want to eraseee.");
    printf("\nIf you didn't remmber just enter \"0\" to display your list and chose from them your person: ");
    scanf("%d", &personId);

    if (personId == 0)
    {

        displayPeople(human);

    }
    else
    {
        for(i = personId - 1; i < listLength - 1; i++)
        {

            human[i] = human[i + 1];

        }

        listLength--;
        menu(human);

    }

}*/


void erasePeople(people human[])
{

    printf("\n----------------------------------------------------------------");
    printf("\n-----You\'re in the section for deleting people's information----");
    printf("\n----------------------------------------------------------------");

    int noOrYes;
    printf("\n\nIf you don't remember,\nenter '0' to display your list and choose a person.\nIf you do remember,\nenter '1' to continue the deletion process: ");
    scanf("%d", &noOrYes);

    if (noOrYes == 0)
    {

        displayPeople(human);

    }
    else
    {
        int numErase;

        printf("\n----------------------------------------------------------------");
        printf("\n-------Please enter the number of people you want to delete: ");
        scanf("%d", &numErase);
        printf("----------------------------------------------------------------");

        int personsId[numErase];

        for(i = 0; i < numErase; i++)
        {

            printf("\nPlease enter the listNumber of the person you want to delete: ");
            scanf("%d", &personsId[i]);
            printf("----------------------------------------------------------------\n");

        }


        printf("\n----------------------------------------------------------------");
        printf("\n--------Are you sure you want to delete these people?-----------\n");

        for(i = 0; i < numErase; i++)
        {

            printf("\n------------------Person number %d information-------------------\n", personsId[i]);

            printf("\nHis/Her Full Name is: %s, %s", human[personsId[i]-1].lastName, human[personsId[i]-1].firstName);
            printf("\nHis/Her Age is: %d", human[personsId[i]-1].age);
            printf("\nHis/Her Address is: %ld, %s, %s\n", human[personsId[i]-1].address.postalCode, human[personsId[i]-1].address.street, human[personsId[i]-1].address.city);

        }

        int com;
        printf("\n----------------------------------------------------------------");
        printf("\n----------------Please enter \'1\' to confirm or \'0\' to cancel: ");
        scanf("%d", &com);

        if(com == 1)
        {

            for(i = 0; i < numErase; i++)
            {
                strcpy(human[personsId[i]-1].firstName, " ");
                strcpy(human[personsId[i]-1].lastName, " ");
                human[personsId[i]-1].age = 0;
                human[personsId[i]-1].address.postalCode = 0;
                strcpy(human[personsId[i]-1].address.street, " ");
                strcpy(human[personsId[i]-1].address.city, " ");

            }

            //The problem here is I want to reorder the human array so that i could move the empty cases to the end of the array.
            /*for(i = 0; i < listLength - 1; i++)
            {

                for(int j = 0; j < numErase; j++)
                {

                    if(i != (personsId[j]-1)){

                        human[i] = human[i+1];

                    }else continue;

                }

            }*/

            printf("\n--------------------------Your New List-------------------------");
            printf("\n----------------------------------------------------------------");

            for(i = 0; i < listLength; i++)
            {


                printf("\n------------------Person number %d information-------------------\n", i + 1);

                printf("\nHis/Her Full Name is: %s, %s", human[i].lastName, human[i].firstName);
                printf("\nHis/Her Age is: %d", human[i].age);
                printf("\nHis/Her Address is: %ld, %s, %s\n", human[i].address.postalCode, human[i].address.street, human[i].address.city);

            }

            printf("\nSorry, we are still facing issues with placing the empty cases at the end of the list!\n");
            menu(human);

        }
        else menu(human);

    }

}
