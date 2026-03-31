/*4. Cree un array en stack lleno de enteros y un número “n”, para que replique “n” veces los
números mayores a 0 dentro del array. Utilice punteros no use índices.
Ej.
Array original:
1 3 2 4 0 0 0 0 0 0 0 0
Y n=3
Array resultado:
1 1 1 3 3 3 2 2 2 4 4 4
Fig. 3. Ejemplo de Replicación
*/

#include <iostream>

using namespace std;

int main(){
    const int tam=12;
    int A[tam]={1,3,2,4,0,0,0,0,0,0,0,0};
    int n=0;
    cout<<"Ingresa el numero de replicas : ";cin>>n;

    int numeros=0;
    for(int *p=A;p<A+tam;p++){
        if(*p>0){
            numeros++;
        }
    }
    int *arr=new int [numeros*n];
    int *ptr=arr;
    for(int *ptr2=A;ptr2<A+tam;ptr2++){
        if(*ptr2>0){
            int contador=n;
            while(contador>0){
                *ptr=*ptr2;
                ptr++;
                contador--;
            }
        }
    }
    for(ptr=arr;ptr<arr+(n*numeros);ptr++){
        cout<<*ptr<<"  ";
    }
    delete[] arr;


return 0;
}
