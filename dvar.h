// ------------------------------------------------------------
//  Dynamic Variable Library
//  Author : Samet SAN
//  Date : 07.2020
// ------------------------------------------------------------

#ifndef DVAR_H
#define DVAR_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct _dvar{
    int count;      // loaded data count 
    void *data;     // data package
    int size;       // structure total size
    int type_size;  // data type size
}dvar;

//  ---------------------------------------------------
//  Dynamic Variable Initialize
//  var  =  dvar type. Dynamic variable pointer
//  type_size = sizeof(type). This is data type size. Ex : int,float,doouble or struct
//  ----------------------------------------------------
int dvar_init(dvar *var,size_t type_size);

//  ---------------------------------------------------
//  Add data to Dynamic Variable
//  var  =  dvar type. Dynamic variable pointer
//  value = data pointer
//  ----------------------------------------------------
int dvar_add(dvar *var,void *value);

//  ---------------------------------------------------
//  Get data to Dynamic Variable
//  var  =  dvar type. Dynamic variable pointer
//  target = target pointer. data copy to target pointer
//  index = data index.
//  ----------------------------------------------------
int dvar_get(dvar *var,void* target,size_t index);

//  ---------------------------------------------------
//  Free Dynamic Variable
//  var  =  dvar type. Dynamic variable pointer
//  ----------------------------------------------------
int dvar_free(dvar *var);

//  ---------------------------------------------------
//  print Dynamic Variable
//  var  =  dvar type. Dynamic variable pointer
//  format = print data at format
//  ----------------------------------------------------
void dvar_print(dvar *var,const char *format);

//  ---------------------------------------------------
//  Get data count for Dynamic Variable
//  var  =  dvar type. Dynamic variable pointer
//  ----------------------------------------------------
int dvar_getCount(dvar *var);

//  ---------------------------------------------------
//  Get data size for Dynamic Variable
//  var  =  dvar type. Dynamic variable pointer
//  ----------------------------------------------------
int dvar_getSize(dvar *var);

//  ---------------------------------------------------
//  Get data size for Dynamic Variable
//  var  =  dvar type. Dynamic variable pointer
//  value  =  data pointer.
//  index  =  index for setting
//  ----------------------------------------------------
int dvar_set(dvar *var,void* value,size_t index);

//  ---------------------------------------------------
//  Get data size for Dynamic Variable
//  var  =  target dvar pointer
//  value  =  source dvar pointer
//  ----------------------------------------------------
int dvar_copy(dvar *var,dvar *value);


#endif