#include <stdlib.h>
#include <stdio.h>
#include <string.h>

float balance = 1000;

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

Stock create_product(){
    Stock product;
    unsigned int id, quantity;
    float price;
    char name[20];
    printf("___Cadastrar novo produto___\n");
    printf("Código do produto: ");
    scanf("%d", &id);
    printf("Nome do produto: ");
    scanf("%s", name);
    printf("Preço unitário de %s: ", name);
    scanf("%f", &price);
    printf("Quantidade de %s: ", name);
    scanf("%d", &quantity);
    product = __init__(product, id, name, price, quantity);
    printf("___Novo produto cadastrado com sucesso___\n");
    return product;
}

void main(void){
    Stock *db;
    int index = 0;
    db = (Stock*)malloc(index*sizeof(Stock));
    db[index] = create_product();
    printf("%d", db[index].quantity);
}
