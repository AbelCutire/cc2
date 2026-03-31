/*3. Cree un array en stack de tamaño “n” lleno de caracteres con espacios entre palabras. Luego
justifique las palabras en el array de forma que los espacios sobrantes a los costados sean
distribuidos equitativamente entre las palabras. El programa debe imprimir el array original y el
array alineado. Realice la implementación utilizando sólo punteros. No use índices.
Ej.
c + + _ j a v a _ _ _
c + + _ _ _ _ j a v a
Fig. 2. Ejemplo de justificado de texto*/

#include <iostream>

using namespace std;

int main(){
    const int n=11;
    int tamPalabra1=0;
    int tamPalabra2=0;

    //char A[n]={' ','c','+','+',' ','j','a','v','a',' ',' '};
    char A[n]={'c','+','+',' ','j','a','v','a',' ',' ',' '};

    cout<<"|";
    for(char *ptr3=A;ptr3<A+n;ptr3++){
        cout<<*ptr3<<"|";
    }

    char *posPalabra1;
    char *posPalabra2;

    char *p=A;
    while(p<A+n &&*p==' ')p++;

    posPalabra1=p;
    for(char *tam1=p;tam1<A+n && *tam1 !=' ';tam1++){
        tamPalabra1++;
    }
    p=p+tamPalabra1;
    while(p<A+n &&*p==' ')p++;
    posPalabra2=p;
    for(char *tam2=p;tam2<A+n && *tam2!=' ';tam2++){
        tamPalabra2++;
    }

    //posPalabra1-A uso para poder saber cuanto jalar, es decir los espaciso k hay

    if(posPalabra1!=A){
        for(char *ptr=A;ptr+(posPalabra1-A)<posPalabra1+tamPalabra1;ptr++){
            swap(*ptr,*(ptr+(posPalabra1-A)));
        }
    }
    //((A+n-1) - (posPalabra2+tamPalabra2-1)) uso para saber cuanto jalar , es decir los esapcios k hay
    if(A+n-1!=posPalabra2+tamPalabra2-1){
        for(char *ptr2=A+n-1;ptr2-((A+n-1) - (posPalabra2+tamPalabra2-1))>=posPalabra2;ptr2--){
            swap(*ptr2,*(ptr2-((A+n-1) - (posPalabra2+tamPalabra2-1))));
        }
    }

    cout<<"\n|";
    for(char *ptr4=A;ptr4<A+n;ptr4++){
        cout<<*ptr4<<"|";
    }

return 0;
}
