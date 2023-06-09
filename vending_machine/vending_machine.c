#include <stdio.h>

#define NUM_ITEMS 3
typedef struct Item
{
    char *item;
    float num;
}Item;

void set_items(Item array[]);

int main()
{
    // Print welcomemessage to user
    printf("Welcome to the Vending Machine!\n");
    printf("Enter your choice by # and input case amount, repeatedly (^d to end),\n");
    
    Item arr[NUM_ITEMS];
    set_items(arr);
    // Print current status
    int index;
    while(scanf("%d %.3f", &index))
}