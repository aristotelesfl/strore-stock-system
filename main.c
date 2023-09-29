#include <stdlib.h>
#include <stdio.h>
#include <string.h>

float balance = 1000;

typedef struct{
    unsigned int id, quantity;
    float price;
    char name[20];
}Stock;

int search_id(int id, Stock db[], int size_db){
    for (int index=0; index<size_db; index++){
        if(id==db[index].id){
            return 1;
        }
    }
    return 0;
}

Stock __init__(Stock product,int id, char name[20], float price, int quantity){
    product.id = id;
    strcpy(product.name, name);
    product.quantity = quantity;
    product.price = price;
    return product;
}

Stock create_product(Stock db[], int size_db){
    Stock new_product;
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
    new_product = __init__(new_product, id, name, price, quantity);
    printf("___Novo produto cadastrado com sucesso___\n");
    return new_product;
}

int main(void){
    Stock *db;
    db = (Stock*)malloc(1*sizeof(Stock));
    if (db == NULL) {
        printf("Erro ao alocar memória\n");
        return 0;
    }
    for (int i=0; i<2; i++){
        db = (Stock*)realloc(db ,(i+1)*sizeof(Stock));
        if (db == NULL) {
            printf("Erro ao realocar memória\n");
            return 0;
        }
        db[i] = create_product(db, i+1);
    }
}
