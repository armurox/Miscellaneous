#include <stdio.h>

#define NUM_ITEMS 3
typedef struct Item
{
    char *item;
    float price;
    int num_left;
}Item;

void set_items(Item array[]);
void print_sold(int ind, float amt, Item array[]);

int main()
{
    // Print welcome message to user
    printf("Welcome to the Vending Machine!\n");
    printf("Enter your choice by # and input case amount, repeatedly (^d to end).\n");
    
    Item arr[NUM_ITEMS];
    set_items(arr);

    // Print current status
    int index;
    float paid;
    for (int i = 0; i < NUM_ITEMS; i++)
    {
        printf("[%d] %d %s left: cost is $%.2f\n", i, arr[i].num_left, arr[i].item, arr[i].price);
    }
    printf("Money made so far is %.2f\n", 0.00);

    // Error handling
    int num_read = scanf("%d %f", &index, &paid);
    while (num_read == 2)
    {
        if (paid < 0 || index < 0)
        {
            fprintf(stderr, "Malformed expression\n");
            return 1;
        }

        if (index > 2)
        {
            fprintf(stderr, "Invalid Item\n");
            return 2;
        }

        if (paid < arr[index].price)
        {
            fprintf(stderr, "Not enough money\n");
            return 3;
        }

        print_sold(index, paid, arr);
        num_read = scanf("%d %f", &index, &paid);

    }
    
    if (num_read == EOF)
    {
        printf("Thanks for your patronage!\n");
        return 0;
    }

    // Missing inputs
    printf("Malformed expression\n");
    return 1;
    // EOF case
}

void set_items(Item array[])
{
    array[0].item = "cola";
    array[0].price = 0.75;
    array[0].num_left = 5;
    array[1].item = "candybar";
    array[1].price = 1.25;
    array[1].num_left = 5;
    array[2].item = "popcorn";
    array[2].price = 0.50;
    array[2].num_left = 5;
}

void print_sold(int ind, float amt, Item array[])
{
    static float money_made = 0;
    if (array[ind].num_left == 0)
    {
        printf("No %s left! Try another item\n", array[ind].item);
        return;
    }
    array[ind].num_left--;
    money_made += array[ind].price;
    printf("%s is dispensed and $%.2f returned\n", array[ind].item, amt - array[ind].price);
    for (int i = 0; i < NUM_ITEMS; i++)
    {
        printf("[%d] %d %s left: cost is $%.2f\n", i, array[i].num_left, array[i].item, array[i].price);
    }
    printf("Money made so far is %.2f\n", money_made);
}
