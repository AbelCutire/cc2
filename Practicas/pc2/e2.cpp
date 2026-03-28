/*2. (Habilidad 1,2) Dado un array de caracteres de tamaño “n” cree un programa en C++ que
verifique si contiene un palíndromo. Un palíndromo es una palabra que se lee igual de izquierda
a derecha que de derecha a izquierda. El programa debe imprimir el array original y la palabra
“Palíndromo si el array contiene por lo menos un palíndromo” o la palabra “Sin Palíndromo” en
caso contrario.*/

#include <iostream>

using namespace std;

bool polindromo( char *ini, char* fin){
    fin--;
    bool polin=true;
    while(ini<fin){
        if(*ini!=*fin){
            return false;
        }
        ini++;
        fin--;
    }
    return true;
}

int main(){
    int n=12;
    int tam=0;
    char palabras[n]={'e','l',' ','a','l','a',' ','a','m','a',' ',' '};

    for(char *i=palabras;i<palabras+n;i++){
        cout<<*i<<"  ";
    }


    bool bandera=false;
    char *ini=palabras;
    for(char *ptr=palabras;ptr<=palabras+n;ptr++){
        if(ptr==palabras+n ||*ptr==' '){
            if(ini<ptr){
                if(polindromo(ini,ptr)){
                    bandera=true;
                    cout<<"\nPolindromo encontrado :"<<endl;
                    for(char *ptr2=ini;ptr2<ptr;ptr2++){
                        cout<<*ptr2;
                    }
                    cout<<endl;
                }
            }
            ini=ptr+1;
        }
    }
    if(bandera==false){
        cout<<"No hay polindromos:"<<endl;
    }





return 0;
}

