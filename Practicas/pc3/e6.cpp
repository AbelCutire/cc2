/*6. Cree un array en stack en C++ de tamaño “n” lleno de caracteres. Luego, dada una palabra de
tamaño “m”, encuentre y elimine dicha palabra del array, desplazando hacia la izquierda todos
los caracteres posteriores en las posiciones de los caracteres de la palabra en el orden original
del array. Coloque espacios en blanco “ “ en las posiciones sobrantes a la derecha. El programa
debe imprimir el array original y el resultante. Realice la implementación utilizando sólo
punteros. No use índices.
Palabra: “c++”
c + + j a v a c + +
j a v a
Fig. 5. Ejemplo de eliminación de palabra*/

#include <iostream>

using namespace std;

int espacios(char *ini, char *fin){
    int espac=0;
    while(ini<=fin && *ini==' '){
        espac++;
        ini++;
    }
    return espac;
}


int main(){
    int tam=11;
    int m=3;
    char A[tam]={'c','+','+',' ','j','a','v','a','c','+','+'};
    char palabra[3]={'c','+','+'};


    cout<<"\nArray original : "<<endl;
    for(char *p=A;p<A+tam;p++){
        cout<<*p<<"  ";
    }
    cout<<endl;

    for(char *ptr=A;ptr<A+tam;ptr++){
        char *p=palabra;
        if(*ptr==*p){
            char *pp=p;
            char *ptr2=ptr;
            for(;ptr2<ptr+m && *ptr2==*pp; ptr2++,pp++);
            if (ptr2==ptr+m){
                for(char *ptr3=ptr;ptr3<ptr+m;ptr3++){
                    *ptr3=' ';
                }
                for(char *ptr4=ptr;ptr4+m<A+tam;ptr4++){
                    swap(*ptr4,*(ptr4+m));
                }
            }


        }

    }

    int espac=espacios(A,A+tam-1);
    if(espac!=0){
        for(char *ptr5=A;ptr5<A+tam;ptr5++){
            swap(*ptr5,*(ptr5+espac));
        }
    }
    cout<<"\nArray modificado : "<<endl;
    for(char *p=A;p<A+tam;p++){
        cout<<*p<<"  ";
    }
    cout<<endl;




return 0;
}
