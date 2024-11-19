#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define MAX_NAME 100

struct banking_update
{
    char name[MAX_NAME];
    int age, balance, check_balance;
    long long int account_number, phone_number;
    char gender, catagory[MAX_NAME];
};
long long int generate_random()
{
    srand(time(0));
    long long int num1 = (rand() % 900000) + 1000000;
    long long int num2 = (rand() % 9000000) + 10000000;
    return num1 * 10000000 + num2;
}
void add_account(struct banking_update banking_updates[], int *count);
void fetch_data(struct banking_update banking_updates[], int count);
void update_balance(struct banking_update banking_updates[], int *count);
void withdrawal(struct banking_update banking_updates[], int *count);

int main()
{
    struct banking_update banking_updates[MAX_NAME];
    int choice;
    int count = 0;
    while (1)
    {
        printf("\n WELCOME \n");
        printf(" 1)ADD USER\n");
        printf(" 2)CHECK BALANCE\n");
        printf(" 3)DEPOSITE\n");
        printf(" 4)WITHDRAWAL\n");
        printf(" 5)EXIT!\n");
        printf("ENTER YOUR CHOICE :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add_account(banking_updates, &count);
            break;
        case 2:
            fetch_data(banking_updates, count);
            break;
        case 3:
            update_balance(banking_updates, &count);
            break;
        case 4:
            withdrawal(banking_updates, &count);
            break;
        case 5:
            return 0;
        default:
            printf("INVALID INPUT!");
        }
    }
    return 0;
}
void add_account(struct banking_update banking_updates[], int *count)
{
    if (*count >= MAX_NAME)
    {
        printf("SIZE NOT SUPORTED!");
        return;
    }
    int number_count = 0;
    printf("ENTER YOUR NAME :");
    getchar();
    fgets(banking_updates[*count].name, MAX_NAME, stdin);
    banking_updates[*count].name[strcspn(banking_updates[*count].name, "\n")] = 0;

    printf("ENTER YOUR GENDER (M/F) :");
    scanf(" %c", &banking_updates[*count].gender);

    printf("ENTER YOUR CASTE :");
    getchar();
    fgets(banking_updates[*count].catagory, MAX_NAME, stdin);
    banking_updates[*count].catagory[strcspn(banking_updates[*count].catagory, "\n")] = 0;

    printf("ENTER YOUR AGE :");
    scanf("%d", &banking_updates[*count].age);

    if (banking_updates[*count].age < 18)
    {
        printf("\nAGE MUST BE ATLEAST 18 YEARS!\n");
        printf("CANNOT ADD USER\n");
        return;
    }

    printf("ENTER YOUR PHONE NUMBER :");
    scanf("%lld", &banking_updates[*count].phone_number);

    long long int tempPhoneNumber = banking_updates[*count].phone_number;
    while (tempPhoneNumber != 0)
    {
        tempPhoneNumber /= 10;
        number_count++;
    }
    if (number_count != 10)
    {
        printf("Invalid phone number. Please enter a 10-digit number.\n");
        return;
    }
    printf("ENTER THE AMOUNT YOU WANT TO DEPOSITE :");
    scanf("%d", &banking_updates[*count].balance);

    banking_updates[*count].account_number = generate_random();

    printf("ACCOUNT NUMBER : %lld\n", banking_updates[*count].account_number);
    (*count)++;
}
void fetch_data(struct banking_update banking_updates[], int count)
{
    long long int search_id;
    int found = 0;
    printf("ENTER YOUR ACCOUNT NUMBER :");
    scanf("%lld", &search_id);
    for (int i = 0; i < count; i++)
    {
        if (banking_updates[i].account_number == search_id)
        {
            printf("\nACCOUNT FOUND!\n");
            printf("NAME: %s\n", banking_updates[i].name);
            printf("GENDER: %c\n", banking_updates[i].gender);
            printf("CASTE: %s\n", banking_updates[i].catagory);
            printf("AGE: %d\n", banking_updates[i].age);
            printf("PHONE NUMBER: %lld\n", banking_updates[i].phone_number);
            printf("BALANCE: %d\n", banking_updates[i].balance);
            if (banking_updates[i].balance < 1500)
            {
                printf("Sufficient balance is not maintained!\n");
            }
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("WRONG ACCOUNT NUMBER TRY AGAIN!");
    }
}
void update_balance(struct banking_update banking_updates[], int *count)
{
    long long int search_id;
    int new_balance;
    int found = 0;

    printf("ENTER YOUR ACCOUNT NUMBER : ");
    scanf("%lld", &search_id);

    for (int i = 0; i < *count; i++)
    {
        if (banking_updates[i].account_number == search_id)
        {
            printf("ENTER THE DEPOSITE AMOUNT : ");
            scanf("%d", &new_balance);

            banking_updates[i].balance += new_balance;

            printf("AMOUNT CREDITED SUCCESSFULLY!\n");
            printf("NEW BALANCE: %d\n", banking_updates[i].balance);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("ACCOUNT NUMBER NOT FOUND. PLEASE TRY AGAIN.\n");
    }
}
void withdrawal(struct banking_update banking_updates[], int *count)
{
    long long int search_id;
    int new_balance;
    int found = 0;

    printf("ENTER YOUR ACCOUNT NUMBER : ");
    scanf("%lld", &search_id);

    for (int i = 0; i < *count; i++)
    {
        if (banking_updates[i].account_number == search_id)
        {
            printf("ENTER THE WITHDRAWAL AMOUNT : ");
            scanf("%d", &new_balance);

            banking_updates[i].balance -= new_balance;

            printf("AMOUNT DEBITED SUCCESSFULLY!\n");
            printf("NEW BALANCE: %d\n", banking_updates[i].balance);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("ACCOUNT NUMBER NOT FOUND. PLEASE TRY AGAIN.\n");
    }
}
