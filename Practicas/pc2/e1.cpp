/*1. (Habilidad 1,2) Cree un array en stack en C++ de tamaño “n” lleno de enteros.
a. Elimine todos los enteros repetidos consecutivos, comenzando desde la izquierda del
array, desplazando hacia la izquierda todos los enteros posteriores en las posiciones de
los enteros repetidos en el orden original de los números. Coloque ceros en las
posiciones sobrantes a la derecha. El programa debe imprimir el array original y el
resultante.
b. En el caso de que se formen nuevos grupos de enteros consecutivos, elimínelos
nuevamente como en el punto anterio*/

#include <iostream>

using namespace std;

bool iguales(int *ini,int *fin){
    bool bandera=false;
    for(int *p=ini;p<fin;p++){
        if(*p!=0 && *p==*(p+1)){
            bandera =true;
            break;
        }
    }
    return bandera;
}

int main(){

    int tam=11;
    int A[tam]={1,4,2,2,1,1,4,3,3,3,4};

    while(iguales(A,A+tam)){

    for(int *ptr=A;ptr<A-1+tam;){
        bool bandera=false;
        if(*ptr==*(ptr+1) && *ptr!=0){
            int repeticiones=0;
            int temp=*ptr;

            for(int *ptr2=ptr;ptr2<A+tam && *ptr2==temp;ptr2++){
                repeticiones++;
                *ptr2=0;

            }
            for(int *ptr3=ptr;ptr3+repeticiones<A+tam;ptr3++){
                swap(*ptr3,*(ptr3+repeticiones));
            }
            for(int *i=A;i<A+tam;i++){
                cout<<*i<<"  ";
            }
            cout<<"\n_________________________"<<endl;
            //ptr=A-1;
            bandera=true;
        }
        if(bandera==false){
            ptr++;
        }
    }

    }

return 0;
}
