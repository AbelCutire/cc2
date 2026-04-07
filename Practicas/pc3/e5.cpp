/*5. Cree un array en stack en C++ de tamaño “n” lleno de valores enteros. Elabore un programa
que, dado un entero “m”, reduzca el array considerando como nuevos elementos al resultado
de la suma de grupos de “m” enteros comenzando desde la primera posición del array. En caso
de que sobren enteros, al final del array, que no alcancen a formar un grupo, estos deben ser
copiados al final luego de los resultados de los grupos y en el orden original. Si luego de la
reducción, se crean nuevos grupos de “m” enteros, estos deben ser nuevamente reducidos,
hasta que ya no queden más grupos. Realice la implementación utilizando sólo punteros. No use
índices.
El programa debe imprimir el array en cada reducción realizada.
3 1 0 -5 2 3 4 2 0 1 5
4 0 6 1 5
10 1 5
16
Fig. 4. Ejemplo de reducción de Array par m = 3*/

#include <iostream>

using namespace std;

int main(){

    int n=11;
    int m=0;
    int *A=new int[n]{3,1,0,-5,2,3,4,2,0,1,5};
    cout<<"Ingesa el valor de 'm' :";cin>>m;

    cout<<"\nArray original : "<<endl;
    for(int *original=A;original<A+n;original++){
        cout<<*original<<"  ";
    }

    while(n>=m){
        int *p=A;
        int newtam=(n/m) +(n%m);
        int *dinamico=new int [newtam];
        int *pos=dinamico;

        while(p<A+n){
            if(p+m-1<A+n ){
                int contador=m;
                *pos=0;
                while(contador>0){
                    *pos+=*p;
                    p++;
                    contador--;
                }
                pos++;
            }
            else{
                *pos=*p;
                p++;
                pos++;
            }
        }
        cout<<"\nArray original : "<<endl;
        for(int *modificado=dinamico;modificado<dinamico+newtam;modificado++){
            cout<<*modificado<<"  ";
        }
        cout<<endl;

        delete[] A;
        A=dinamico;
        n=newtam;

    }

return 0;
}
