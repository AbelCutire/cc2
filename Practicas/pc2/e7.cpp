/*7. (Habilidad 1,2) Dado dos arrays de enteros ordenados de tamaño “n” cree un programa en C++
que cree un array de tamaño “2n” ordenado con todos los números de dichos arrays. El
programa debe imprimir los dos arrays orginales y el array resultante
1 4 6 11 12 18
0 1 2 3 4 5
0 1 1 2 3 4 4 5 6 11 12 18
Fig. 5. Ejemplo de creación de array ordenado
*/
#include <iostream>

using namespace std;
int main(){
    int n=6;
    int arr1[n]={1,4,6,11,12,18};
    int arr2[n]={0,1,2,3,4,5};
    int *arr3=new int[2*n];
    int *p=arr3;
    cout<<"\nArray A: "<<endl;
    for(int *ptr3=arr1;ptr3<arr1+n;ptr3++){
        cout<<*ptr3<<"  ";
    }
    cout<<"\nArray B : "<<endl;
    for(int *ptr3=arr2;ptr3<arr2+n;ptr3++){
        cout<<*ptr3<<"  ";
    }

    for(int *ptr=arr1; ptr<arr1+n ;ptr++){
        *p=*ptr;
        p++;
    }
    for(int *ptr2=arr2; ptr2<arr2+n;ptr2++){
        *p=*ptr2;
        p++;
    }
    cout<<"\nArray unido : "<<endl;
    for(int *ptr3=arr3;ptr3<arr3+2*n;ptr3++){
        cout<<*ptr3<<"  ";
    }

    for(p=arr3;p<arr3+2*n;p++){
        for(int *q=arr3;q<arr3+n*2;q++){
            if(*p<*q){
                swap(*p,*q);
            }
        }
    }
    cout<<"\nArray oordenado : "<<endl;
    for(int *ptr3=arr3;ptr3<arr3+2*n;ptr3++){
        cout<<*ptr3<<"  ";
    }


return 0;
}
