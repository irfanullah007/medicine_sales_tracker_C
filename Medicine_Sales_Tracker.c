#include<stdio.h>
#include<string.h>

struct sales{

    char name[50];
    char area[50];
    int id;
    int amount;
    char response[20];

};

void feedback_of_employees (struct sales emp[])

{
    int i;
    char * p1;
    char * p2;
    char * p3;

    char find1[]="Good";
    char find2[]="Moderate";
    char find3[]="Bad";

    printf("\n\nFeedback of our representative to the company:\n");

    for(i=0;i<5;i++)
    {
       p1 = strstr(emp[i].response, find1);
       p2 = strstr(emp[i].response, find2);
       p3 = strstr(emp[i].response, find3);

       if (p1)
       {
           printf("\nDecision from the representative %d is:", i+1);
           printf("\nWell. Buyers are interested on our products. We have to do more sales activities.\n");
       }
       else if (p2)
       {
           printf("\nDecision from the representative %d is:", i+1);
           printf("\nWe have to update the quality of our product.\n");
       }
       else if (p3)
       {
           printf("\nDecision from the representative %d is:", i+1);
           printf("\nThe buyers are not interested to buy our products. Our R&D Department have to find out the problems. Our manufacturers should discuss with expertise pharmacist.\n");
       }
    }
}

void best_seller(struct sales emp[])
{
    int i;

    printf("\n\nOur best seller of the month is:");

    for (i=0;i<5;i++)
    {
        if (emp[i].amount>100)
        {
            printf("\n\nName: %s", emp[i].name);
            printf("\nID: %d", emp[i].id);
            printf("\nArea: %s\n", emp[i].area);
        }
    }
}

int main()
{
    struct sales emp[5];
    int i;
    int option;

    printf("\n\n\t\tThe Mediaid Pharmaceutical Company, Diacine Sales Reporting Software\n\t\t\t\t\t\tWelcome! ");

    for (i=0;i<5;i++)
    {
        printf("\n\nEnter the name of representative %d: ", i+1);
        gets(emp[i].name);

        printf("\nEnter the area of representative %d: ", i+1);
        gets(emp[i].area);

        printf("\nEnter the ID of representative %d: ", i+1);
        scanf("%d", &emp[i].id);

        printf("\nEnter the total amount selling product by representative %d: ", i+1);
        scanf("%d", &emp[i].amount);

        printf("\nFeedback from buyers of the area of the representative %d:", i+1);
        printf("\nHow was our product to them? (Good/Moderate/Bad): ");
        getchar();
        gets(emp[i].response);
    }

    while(1)
    {
        printf("_______________________________________________________________________________");
        printf("\nMENU:\n1) Feedback of the medical representatives from their selling perspectives \n2) The best seller of the month among all the medical representatives (based on the amount of selling products) \n3) Exit");
        printf("\nEnter Option: ");
        scanf("%d", &option);
        getchar();

        printf("_______________________________________________________________________________");

        if (option==1)
        {
            feedback_of_employees(emp);
        }
        else if (option==2)
        {
            best_seller(emp);
        }
        else if (option==3)
        {
            break;
        }
    }
}





