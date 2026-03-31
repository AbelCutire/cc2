/*1. Dado un array de caracteres de tamaño par con un texto de tamaño par,  cree un programa en
C++ que centre todo el texto del array dejando la misma cantidad de espacios al inicio y al final
. El programa debe imprimir el array original y el resultante. Realice la implementación utilizando
sólo punteros. No use índices.
*/
#include <iostream>

using namespace std;

int espacios(char *ini, char *fin){
    int espac=0;
    for(char *p=ini;p<fin && *p==' ';p++) espac++;
    for(char *q=fin;q>ini && *q==' ';q--) espac++;

    return espac;
}

int main(){
    int tam=12;
    int espacios_ini=0;
    char A[tam]={' ',' ',' ',' ','j','a','v','a',' ','+',' ',' '};
    int espacioss=espacios(A,A+tam-1);

    for(char *p=A;p<A+tam && *p==' ';p++) espacios_ini++;
    int diferencia=(espacioss-espacios_ini)/2;

    cout<<"|";
    for(char *n=A;n<A+tam;n++){
        cout<<*n<<"|";
    }

    if(espacios_ini>espacioss-espacios_ini){
        for(char *ptr1=A+espacioss/2;ptr1 + diferencia<A+tam;ptr1++){
            swap(*ptr1,*(ptr1+diferencia));
        }
    }
    else{
        for(char *ptr2=A+tam-1-espacioss/2;ptr2-diferencia>A;ptr2--){
            swap(*ptr2,*(ptr2-diferencia));
        }

    }


    cout<<endl;
    cout<<"|";
    for(char *n=A;n<A+tam;n++){
        cout<<*n<<"|";
    }


return 0;
}
