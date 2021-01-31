#include <stdio.h>

#include "dvar.h"


int main(){

    dvar test;
    int a=9999999,c=256;
    int b,k=34534;

    if(dvar_init(&test,sizeof(int)) == EXIT_FAILURE){
        perror("Init failed\n");
    }

    if(dvar_add(&test,&a) == EXIT_FAILURE){
        perror("A Add failed\n");
    }

    if(dvar_add(&test,&c) == EXIT_FAILURE){
        perror("C Add failed\n");
    }

    
    dvar_add(&test,&k);

    dvar_print(&test,"0x%02x ");

    dvar_get(&test,&b,1);

    printf("%d \n",b);

    return 0;
}