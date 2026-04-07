/*Dado dos arrays de enteros ordenados de tamaño “n” cree un programa en C++ que cree un
array de tamaño “2n” ordenado con todos los números de dichos arrays. El programa debe
imprimir los dos arrays orginales y el array resultante. Realice la implementación utilizando sólo
punteros. No use índices.
1 4 6 11 12 18
0 1 2 3 4 5
0 1 1 2 3 4 4 5 6 11 12 18
Fig. 6. Ejemplo de creación de array ordenado
*/

#include <iostream>

using namespace std;

int main(){
    const int n=6;
    int A[n]={1,4,6,11,12,18};
    int B[n]={0,1,2,3,4,5};

    cout<<"\nArray A : "<<endl;
    for(int*ptr=A;ptr<A+n;ptr++){
        cout<<*ptr<<"  ";
    }
    cout<<"\nArray B : "<<endl;
    for(int*ptr2=B;ptr2<B+n;ptr2++){
        cout<<*ptr2<<"  ";
    }

    int *c =new int[2*n];
    int *ptr=A;
    int *ptr2=B;

    for(int *p=c;p<c+(2*n);p++){
        if(p<c+n){
            *p=*ptr;
            ptr++;
        }
        else{
            *p=*ptr2;
            ptr2++;
        }
    }
    cout<<"\nArray c : "<<endl;
    for(int*ptr3=c;ptr3<c+(2*n);ptr3++){
        cout<<*ptr3<<"  ";
    }

    for(int *ptr4=c;ptr4<c+(2*n);ptr4++){
        for(int *ptr5=c;ptr5<c+(2*n)-1;ptr5++){
            if(*ptr5>*(ptr5+1)){
                swap(*ptr5,*(ptr5+1));
            }
        }
    }
    cout<<"\nArray c : "<<endl;
    for(int*ptr3=c;ptr3<c+(2*n);ptr3++){
        cout<<*ptr3<<"  ";
    }

return 0;
}
