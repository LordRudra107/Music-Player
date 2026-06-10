#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define PUSH_BACK(v,type,element) do{           \
        type temp=(element);                     \
            push_back((v),&temp);               \
}while(0)
#define ELEMENT_AT(v,type,index)   *(type*)element_at((v),index)
typedef struct{
    void* begin;
    size_t capacity;
    size_t size;
    size_t element_size;    
}Vector;
void vector_init(Vector* v,int size){
    v->size=0;
    v->capacity=8;
    v->element_size=size;
    v->begin=malloc(v->element_size*v->capacity);
}
void push_back(Vector* v,void *element){
    if(v->size==v->capacity){
        v->begin=realloc(v->begin,v->capacity*2*v->element_size);
        v->capacity*=2;
    }
    memcpy(((char*)v->begin+v->size*v->element_size),element,v->element_size);
    v->size++;
}
void* element_at(Vector* v,int index){
    if(index>=v->size){
        printf("OVERFLOWWW!");
        return NULL;
    }
    return  ((char*)v->begin+index*v->element_size);
}
