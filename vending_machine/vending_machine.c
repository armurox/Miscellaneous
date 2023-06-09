#include <stdio.h>

#define NUM_ITEMS 3
typedef struct Item
{
    char *item;
    float price;
}Item;

void set_items(Item array[]);
void print_sold_items(int index, float paid);

int main()
{
    // Print welcomemessage to user
    printf("Welcome to the Vending Machine!\n");
    printf("Enter your choice by # and input case amount, repeatedly (^d to end),\n");
    
    Item arr[NUM_ITEMS];
    set_items(arr);
    // Print current status
    int index;
    float paid;

    // Error handling
    while (scanf("%d %.3f", &index, &paid) == 2)
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

        print_sold_items(index, paid);

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
    array[1].item = "candybar";
    array[1].price = 1.25;
    array[2].item = "popcorn";
    array[2].price = 0.50;
}

void print_sold_items(int index, int paid)
{
    
}
