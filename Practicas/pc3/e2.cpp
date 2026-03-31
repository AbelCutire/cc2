/*2. Cree un array en stack en C++ de tamaño “n” lleno de valores enteros. Implemente el algoritmos
de ordenamiento bubble sort utilizando solo punteros, No use índices. El programa debe
imprimir el array original y el resultante.*/

#include <iostream>

using namespace std;

int main(){

    const int n=10;
    int A[n]={3,56,1,6,7,1,5,0,5,8};

    for(int *original=A;original<A+n;original++){
        cout<<*original<<"  ";
    }
    for(int *q=A;q<A+n;q++){
        for(int *p=A;p<A+n-1;p++){
            if(*p>*(p+1)){
                swap(*p,*(p+1));
            }
        }
    }

    cout<<"\nArray ordeando : "<<endl;
    for(int *ordenado=A;ordenado<A+n;ordenado++){
        cout<<*ordenado<<"  ";
    }


return 0;
}

