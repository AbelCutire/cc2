/*
5. (Habilidad 1,2) Realice lo mismo que la pregunta anterior en cada fila de una matriz con una
cantidad par de columnas. El programa debe imprimir la matriz original y la resultante.
*/

#include <iostream>

using namespace std;

int espacios(char* ini, char* fin){
    int espacios=0;
    for(;*ini==' ' && ini<fin;ini++) espacios++;
    return espacios;
}

int main(){

    char matriz[10][10] = {
    {'C','+','n','x','y','z','P','A','S','o'},
    {'j','a','v','a','C','+','+','1','2','3'},
    {'P','y','t','h','o','n',' ','C','+','+'},
    {'C','+','+','C','+','+','a','b','c','d'},
    {'q','w','e','r','t','y','u','C','+','+'},
    {'1','C','+','+','2','C','+','+','3','4'},
    {'C','+','+',' ',' ',' ',' ','C','+','+'},
    {'x','C','+','+','y','z','w','v','u','t'},
    {'A','B','C','D','E','F','G','C','+','+'},
    {'h','o','l','a','C','+','+','c','p','p'}
};

    int tam=10;
    int m=3;
    char palabra[3]={'C','+','+'};

    cout<<"\nMatriz original : "<<endl;
        for(char (*original)[10]=matriz;original<matriz+10;original++){
            for(char (*ori)=*original;ori<(*original)+10;ori++){
                cout<<*ori<<" ";
            }
            cout<<endl;
        }

for(char (*n)[10]=matriz;n<matriz+10;n++){
    char *A=*n;
    char *p=palabra;
    for(char *ptr=A;ptr<A+tam;ptr++){
        if(*ptr==*p){
            char *pp=p;
            char *ptr3=ptr;
            for(;ptr3<ptr+m && *ptr3==*pp;ptr3++,pp++);
            if(pp==p+m){
                for(char *ptr4=ptr;ptr4<ptr+m;ptr4++){
                    *ptr4=' ';
                }
                for(char *ptr5=ptr;ptr5+m<A+tam;ptr5++){
                    swap(*ptr5,*(ptr5+m));
                }

            }

        }
    }
    int espac=espacios(A,A+tam-1);
    if(espac!=0){
        for(char *ptr6=A;ptr6+espac<A+tam;ptr6++){
            swap(*ptr6,*(ptr6+espac));
        }
    }

}
cout<<"\nMatriz final : "<<endl;
    for(char (*final)[10]=matriz;final<matriz+10;final++){
        for(char (*ori)=*final;ori<(*final)+10;ori++){
            cout<<*ori<<" ";
        }
        cout<<endl;
    }

return 0;
}
