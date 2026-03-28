/*3. (Habilidad 1,2) Dado un array de caracteres de tamaño par con un texto de tamaño par, cree
un programa en C++ que centre todo el texto del array dejando la misma cantidad de espacios
al inicio y al final . El programa debe imprimir el array original y el resultante.
Ej.
_-_-j a v a +
_-_j a v a +
*/

#include <iostream>

using namespace std;

int numEspacios(char *ini,char *fin){
    int espacios=0;
    char*ptr=ini;
    for(;*ptr==' ' && ptr<fin;ptr++) espacios++;
    for(;*fin==' ' && fin>ini;fin--) espacios++;

    return espacios;
}

int main(){
    int tam=12;
    int espacios_inicio=0;
    char A[tam]={' ',' ',' ',' ','j','a','v','a',' ','+',' ',' '};
    int espacios=numEspacios(A,A+11);
    for(char *p=A;*p==' ' && p<A+tam;p++) espacios_inicio++;
    int diferencia=(espacios-espacios_inicio)/2;

    cout<<"\nArray orinal : "<<endl;
    for(char *original=A;original<A+tam;original++){
        cout<<*original<<"| ";
    }

    if(espacios_inicio>espacios-espacios_inicio){
        for(char *ptr2=A+(espacios/2);ptr2+diferencia<A+tam;ptr2++){
            swap(*ptr2,*(ptr2+diferencia));
        }
    }
    else{
        for(char *ptr3=A+(tam-1-espacios/2);ptr3-diferencia>A ;ptr3--){
            swap(*ptr3,*(ptr3-diferencia));
        }
    }

    cout<<"\nArray modificado : "<<endl;
    for(char *modificado=A;modificado<A+tam;modificado++){
        cout<<*modificado<<"| ";
    }

return 0;
}
