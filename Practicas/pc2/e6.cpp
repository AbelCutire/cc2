/*6. (Habilidad 1,2) Dado un array de caracteres de tamaño “n” cree un programa en C++ que
verifique si contiene una secuencia de caracteres de tamaño “m”. El programa debe imprimir el
array original y la palabra “Sí” en caso exista la secuencia y “No” en caso contrario.
Secuencia: “lma”
e l  a l a  a m a
 “Sí”
Fig. 5. Ejemplo de detección de secuencia*/

#include <iostream>

using namespace std;

int main(){
    int n=12;
    int tam=3;
    char palabras[n]={'e','l',' ','a','l','a',' ','a','m','a',' ',' '};
    char palabra[tam]={'a','l','a'};

    bool encontrado=false;
    for(char *ptr=palabras;ptr<=palabras+n-tam ;ptr++){
        char *ptr2=palabra;
        if(*ptr==*ptr2){
            for(char *ptr3=ptr; ptr2<palabra+tam; ptr3++,ptr2++){
                if(*ptr3!=*ptr2){
                    break;
                }
            }
            if(ptr2==palabra+tam){
                encontrado=true;
                break;
            }
        }
    }

    if(encontrado==true){
        cout<<"la palabra existe en el array"<<endl;
    }
    else{
        cout<<"No existe la palabra"<<endl ;
    }

return 0;
}
