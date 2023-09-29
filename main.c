#include <stdlib.h>
#include "core.h"

int main(void){
    Stock *db;
    int i=0;
    db = (Stock*)malloc(1*sizeof(Stock));
    if (db == NULL) {
        printf("Erro ao alocar memória\n");
        return 0;
    }
    for (i=0; i<2; i++){
        db = (Stock*)realloc(db ,(i+1)*sizeof(Stock));
        if (db == NULL) {
            printf("Erro ao realocar memória\n");
            return 0;
        }
        db[i] = create_product(db, i+1);
    }
}
