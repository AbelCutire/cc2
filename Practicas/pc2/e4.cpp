/*4. (Habilidad 1,2) Cree un array en stack en C++ de tamaño “n” lleno de caracteres. Luego, dada
una palabra de tamaño “m”, encuentre y elimine dicha palabra del array, desplazando hacia la
izquierda todos los caracteres posteriores en las posiciones de los caracteres de la palabra en el
orden original del array. Coloque espacios en blanco “ “ en las posiciones sobrantes a la derecha.
El programa debe imprimir el array original y el resultante.
ejemplo:
Palabra: “c++”
c + + j a v a c + +
j a v a

*/

#include <iostream>

using namespace std;


int espacios(char* ini, char* fin){
    int espacios=0;
    for(;*ini==' ' && ini<fin;ini++) espacios++;
    return espacios;
}


int main(){
    int tam=11;
    int m=3;
    char A[tam]={'c','+','+',' ','j','a','v','a','c','+','+'};
    char palabra[3]={'c','+','+'};
    char *p=palabra;
    cout<<"\nArray original : "<<endl;
    for(char *original=A;original<A+tam;original++){
        cout<<*original<<"  ";
    }
    for(char *ptr=A;ptr<A+tam;ptr++){
        if(*ptr==*p){
            char *pp=p;
            char *ptr3=ptr;
            for(;ptr3<ptr+m && *ptr3==*pp;ptr3++,pp++);
            if(pp==p+m){
                for(char *ptr4=ptr;ptr4<ptr+m;ptr4++){
                    *ptr4=' ';
                }
                for(char *ptr5=ptr;ptr5+m<A+tam;ptr5++){
                    swap(*ptr5,*(ptr5+m));
                }
                cout<<endl;
                for(char *modificado=A;modificado<A+tam;modificado++){
                    cout<<*modificado<<"  ";
                }
                cout<<endl;

            }

        }
    }
    int espac=espacios(A,A+tam-1);
    if(espac!=0){
        for(char *ptr6=A;ptr6+espac<A+tam;ptr6++){
            swap(*ptr6,*(ptr6+espac));
        }
    }
    cout<<"\nArray final : "<<endl;
    for(char *final=A;final<A+tam;final++){
        cout<<*final<<"  ";
    }



return 0;
}
