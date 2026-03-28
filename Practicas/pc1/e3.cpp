/*3. (Habilidad 1,2) Cred un array en stack lleno de enteros y un número “n”, para que replique “n”
veces los números mayores a 0 dentro del array. Utilice punteros no use índices. (6 puntos)*/

#include <iostream>


using namespace std;

int main(){

    int tam=12;
    int arr[tam]={1,3,2,4,0,0,0,0,0,0,0,0};
    int n=0;

    cout<<"Ingesa el numero de replicas :";cin>>n;

    int newtam=0;
    for(int *ptr1=arr;ptr1<arr+tam;ptr1++){
        if(*ptr1!=0){
            newtam++;
        }
    }
    newtam=newtam*n;

    int newArray[newtam];
    int *ptr2=newArray;

    for(int *ptr3=arr;ptr3<arr+tam;ptr3++){
        if(*ptr3!=0){
            for(int i=0;i<n;i++){
                *ptr2=*ptr3;
                ptr2++;
            }
        }
    }
    for(int *ptr4=newArray;ptr4<newArray+newtam;ptr4++){
        cout<<*ptr4<<"  ";
    }

return 0;

}
