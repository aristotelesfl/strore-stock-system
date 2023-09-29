#include <string.h>
#define initial_balance 1000

float balance = initial_balance;

typedef struct{
    unsigned int id, quantity;
    float price;
    char name[20];
}Stock;

Stock __init__(Stock product,int id, char name[20], float price, int quantity){
    product.id = id;
    strcpy(product.name, name);
    product.quantity = quantity;
    product.price = price;
    return product;
}