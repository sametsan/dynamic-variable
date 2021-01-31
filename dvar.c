#include "dvar.h"

int dvar_init(dvar *var,size_t type_size){

    var->data = malloc(type_size);
    var->count = 0;
    var->size = type_size;
    var->type_size = type_size;

    if(var->data)
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}

int dvar_add(dvar *var,void *value){
    if(var->size == (var->count * var->type_size)){
        var->size += var->type_size;
        var->data = realloc(var->data, var->size);
    }
    memcpy((var->data + (var->count * var->type_size)),value,var->type_size);
    var->count++;
    return EXIT_SUCCESS;
}

int dvar_get(dvar *var,void* target,size_t index){
    if(index >= var->count)
        return EXIT_FAILURE;

    memcpy(target,var->data + (index * var->type_size),var->type_size);
    return EXIT_SUCCESS;
}

int dvar_set(dvar *var,void* value,size_t index){
    if(index >= var->count)
        return EXIT_FAILURE;

    memcpy(var->data + (index * var->type_size),value,var->type_size);
    return EXIT_SUCCESS;   
}

int dvar_copy(dvar *var,dvar *value){
    var->count = value->count;
    var->size = value->size;
    var->type_size = value->type_size;
    var->data = realloc(var->data, value->size);
    memcpy(var->data,value->data,value->size);
    return EXIT_SUCCESS;       
}

void dvar_print(dvar *var,const char *t){
    unsigned char *byte;

    for(int i=0;i < var->size;i++ ){
        byte  = var->data + i;
        printf(t,*byte);
    }
    printf("\n");
}

int dvar_getCount(dvar *var){
    return var->count;
}

int dvar_getSize(dvar *var){
    return var->size;
}

int dvar_free(dvar *var){

    for(int i=0;i<var->count;i++)
        free(var->data + i);

    free(var);
    return EXIT_SUCCESS;
}

