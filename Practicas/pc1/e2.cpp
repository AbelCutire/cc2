/*

2. (Habilidad 1,2) Cree un array en stack en C++ de tamaño “n” lleno de valores enteros. Elabore
un programa que, dado un entero “m”, reduzca el array considerando como nuevos elementos
al resultado de la suma de grupos de “m” enteros comenzando desde la primera posición del
array. En caso de que sobren enteros, al final del array, que no alcancen a formar un grupo, estos
deben ser copiados al final luego de los resultados de los grupos y en el orden original. Si luego
de la reducción, se crean nuevos grupos de “m” enteros, estos deben ser nuevamente reducidos,
hasta que ya no queden más grupos. Realice la implementación utilizando sólo punteros. No use
índices.
*/

#include <iostream>

using namespace std;

int main(){

    //tamReducir =m
    int tam=0;
    int tamReducir=0;
    cout<<"Ingresa el tamaño del array :";cin>>tam;
    int *A=new int [tam];

    for(int *p=A;p<A+tam;p++){
        cout<<"Ingresa el valor para la posicion :";cin>>*p;
    }
    cout<<"Ahora ingresa en tamaño en los que quieres que se vea reduciendo: ";cin>>tamReducir;

    int *dinamico=new int [tam];

    cout<<"Array oriignal : " <<endl;
    for(int *i=A;i<A+tam;i++){
        cout<<*i<<"  ";
    }
    cout<<"\n********************************"<<endl;



    //dividir mas modulo paera craer el nuevop array;

    while(tam!=1){
        int tamIni=tam;
        int tamNew=tamIni/tamReducir +tamIni%tamReducir;

        int *dinamico=new int [tamNew];
        int *ptr1=A;
        int *ptr2=dinamico;

        while(ptr1<A+tamIni){
            if(ptr1+tamReducir<A+tamIni){
                *ptr2=0;//quitamos valor basura dx
                for( int *ptr3=ptr1;ptr3<ptr1+tamReducir;ptr3++){
                    *ptr2+=*ptr3;
                }
                ptr1+=tamReducir;
            }
            else{
                *ptr2=*ptr1;
                ptr1++;
            }
            ptr2++;
        }
        for(int *ptr4=dinamico;ptr4<dinamico+tamNew;ptr4++){
            cout<<*ptr4<<"  ";
        }
        cout<<endl;
        delete []A;
        A=dinamico;
        tam=tamNew;

    }

    delete[]A;

return 0;
}
