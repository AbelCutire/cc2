
/*
1. (Habilidad 1,2) Cree un array en stack de tamaño “n” lleno de caracteres con espacios entre
palabras. Luego alinee los caracteres al lado derecho en el array. El programa debe imprimir el
array original y el array alineado. Realice la implementación utilizando sólo punteros. No use
índices.
*/

#include <iostream>

using namespace std;


int main(){
    int tam=11;
    char A[tam]={'c','+','+',' ','j','a','v','a',' ',' ',' '};

    int spacios=0;
    char *ptr1=A+tam-1;
    while(*ptr1==' '){
        spacios++;
        ptr1--;
    }

    cout<<"array original"<<endl;

    for(char *i=A;i<A+tam;i++){
        cout<<*i<<"  ";
    }

    for( char *p=A+ tam-1;p>=A+spacios;p--){
        char temp=*p;
        *p=*(p-spacios);
        *(p-spacios)=temp;
    }

    cout<<"\n  array a la derecha"<<endl;

    for(char *i=A;i<A+tam;i++){
        cout<<*i<<"  ";
    }

return 0;
}


