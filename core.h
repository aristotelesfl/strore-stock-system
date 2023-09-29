#include <stdio.h>
#include "actions.h"


Stock create_product(Stock db[], int size_db){
    Stock new_product_token;
    unsigned int id, quantity, product_in_stock;
    float price;
    char name[20];
    printf("___Cadastrar novo produto___\n");
    do{
        printf("Código do produto: ");
        scanf("%d", &id);
        product_in_stock = search_id(id, db, size_db);
        if (product_in_stock==1){
            printf("Produto já cadastrado no sistema!\n");
        }
    }while(product_in_stock!=0);
    scanf("%*[^\n]"); scanf("%*c");
    printf("Nome do produto: ");
    scanf("%[^\n]", name);
    printf("Preço unitário de %s: ", name);
    scanf("%f", &price);
    printf("Quantidade de %s: ", name);
    scanf("%d", &quantity);
    if (price*quantity<=balance){
        balance -= price*quantity;
        new_product_token = __init__(new_product_token, id, name, price, quantity);
        printf("___Novo produto cadastrado com sucesso___\n");
        return new_product_token;
    }
    printf("___Saldo insuficiente___\nProduo não foi cadastrado no sistema\n");
    Stock void_token = __init__(void_token, 0, "NULL", 0, 0);
    return void_token;
}