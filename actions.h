#include "models.h"

int search_id(int id, Stock db[], int size_db){
    int index=0;
    for (index; index<size_db; index++){
        if(id==db[index].id){
            return 1;
        }
    }
    return 0;
}

int validation_token(Stock token){
    if (strcmp(token.name, "void")==0){
        return 0;
    }
    return 1;
}