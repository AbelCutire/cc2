#include <iostream>

using namespace std;
    const int caras=3;
    const int filas=14;
    const int columnas=8;

void sonearCara(int (*cara)[columnas], int (*marcas)[columnas], int i, int j, int filas, int columnas){

    if(i<0||i>=filas || j<0||j>= columnas) return;

    int *actual=*(cara+i)+j;
    int *marca=*(marcas+i)+j;
    if(*actual==0 || *marca==1) return;
    *marca = 1;

    sonearCara(cara, marcas, i-1, j, filas, columnas);//arriba
    sonearCara(cara, marcas, i+1, j, filas, columnas);//abajo
    sonearCara(cara, marcas, i, j-1, filas, columnas);//izquierda
    sonearCara(cara, marcas, i, j+1, filas, columnas);//derecha

    sonearCara(cara, marcas, i-1, j+1, filas, columnas);//superior derecha
    sonearCara(cara, marcas, i-1, j-1, filas, columnas);//superio izquierda
    sonearCara(cara, marcas, i+1, j+1, filas, columnas);//inferior derecha
    sonearCara(cara, marcas, i+1, j-1, filas, columnas);//inferiro izquierda

}

void sonearCubo(int (*cubo)[filas][columnas], int (*marcas)[filas][columnas], int i, int j,int k,int caras, int filas, int columnas){

    if(i<0||i>=caras || j<0||j>= filas || k<0||k>= columnas) return;
    int *actual=*(*(cubo+i)+j)+k;
    int *marca=*(*(marcas+i)+j)+k;
    if(*actual==0 || *marca==1) return;
    *marca = 1;

    for(int casos_i=-1; casos_i<=1; casos_i++){
    for(int casos_j=-1; casos_j<=1; casos_j++){
        for(int casos_k=-1; casos_k<=1; casos_k++){
            if(casos_i==0 && casos_j==0 && casos_k==0) continue;

            sonearCubo(cubo, marcas,i+casos_i,j+casos_j,k+casos_k,caras,filas,columnas);
        }
    }
}
}


int main(){

/*  A :     Elaborar un programa en C++ que represente un territorio con minas por medio de un
            array 3D de enteros x ϵ {0,1}, donde grupos contiguos de unos representan una mina y
            números cero representan espacios sin mineral (celdas en blanco en la Fig.1)*/
    cout<<"\n=============================PARTE A====================================="<<endl;

    int BuscaMinas[caras][filas][columnas] = {
        {
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,1,0},
            {0,1,0,1,0,0,0,1},
            {0,1,0,1,0,0,0,0},
            {0,1,1,0,0,0,0,0},
            {0,0,1,0,0,0,0,0},
            {0,0,0,1,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,1},
            {0,0,0,0,0,0,1,0},
            {0,0,0,0,0,0,1,0},
            {0,0,0,0,1,1,1,0}
        },
        {
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,1,0,1,0,0,0,0},
            {0,1,0,1,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,1,1,1,0}
        },
        {
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,1,0},
            {0,0,0,0,0,0,0,1},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {1,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,1,0},
            {1,0,0,0,0,0,1,0},
            {1,0,0,0,1,1,1,0}
        }
    };

/*  B  :Elaborar un programa que imprima toda la matriz 3D en la pantalla, imprimiendo cada
        cara separada por un retorno de carro, cada fila de una cara en un renglón diferente de
        la pantalla.*/
    cout<<"\n=============================PARTE B====================================="<<endl;

    for(int (*p)[filas][columnas]=BuscaMinas; p<BuscaMinas+caras; p++){
        for(int (*q)[columnas]=*p; q<(*p)+filas; q++){
            for(int *r=*q; r<(*q)+columnas; r++){
                cout<<*r<<"  ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

/*  C : Elaborar un programa que recorra una cara de la matriz 3D e imprima la cantidad de
        unos de dicha cara. En la Fig.1 para la primera cara debe imprimir 16.*/

        cout<<"\n=============================PARTE C====================================="<<endl;

        int (*ptr1)[filas][columnas]=BuscaMinas;
        int numUnos=0;
        for(int (*q)[columnas]=*ptr1;q<(*ptr1)+filas;q++){
            for(int *r=*q;r<(*q)+columnas;r++){
                if(*r==1)numUnos++;
            }
        }
        cout<<"Numeros de 1's en una cara :"<<numUnos<<endl;


/*  D : Elaborar un programa que recorra cada cara de la matriz 3D e imprima la cantidad de
        unos de cada cara. En la Fig.1 debe imprimir 16, 7, 12*/

    cout<<"\n=============================PARTE D====================================="<<endl;

    for(int (*p)[filas][columnas]=BuscaMinas; p<BuscaMinas+caras; p++){
        int unos=0;
        for(int (*q)[columnas]=*p; q<(*p)+filas; q++){
            for(int *r=*q; r<(*q)+columnas; r++){
                if(*r==1)unos++;
            }
        }
        cout<<"\nNumero de unos:"<<unos<<endl;
    }
/*  E : Elaborar un programa que recorra cada fila de una cara de la matriz 3D e imprima la
        cantidad de minas (grupos de unos contiguos) en cada fila. En la Fig.1 para la primera
        cara debe imprimir 1,3,2,1,1,1,1,1,1,1.*/

    cout<<"\n=============================PARTE E====================================="<<endl;

    int (*ptr2)[filas][columnas]=BuscaMinas;
        for(int (*q)[columnas]=*ptr2;q<(*ptr2)+filas;q++){
            int numMinas=0;
            for(int *r=*q;r<(*q)+columnas;r++){
                if(*r==1){
                    for(;r<(*q)+columnas && *r==1;r++);
                    numMinas++;
                }
            }
            cout<<numMinas<<"  ";
        }



/*  F : Elaborar un programa que recorra cada fila de cada cara de la matriz 3D e imprima la
        cantidad de minas (grupos de unos contiguos) en cada fila de cada cara. Los resultados
        de una fila en un renglón de la pantalla. En la Fig.1 debería imprimir:
        1,3,2,1,1,1,1,1,1,1
        2,2,1
        1,1,2,2,2,2                                                                               */

    cout<<"\n=============================PARTE F====================================="<<endl;

    for(int (*p)[filas][columnas]=BuscaMinas; p<BuscaMinas+caras; p++){
        cout<<"\nCARA  : "<<endl;
        for(int (*q)[columnas]=*p; q<(*p)+filas; q++){
            int minas=0;
            for(int *r=*q; r<(*q)+columnas; r++){
                if(*r==1){
                    for(;r<(*q)+columnas && *r==1;r++);
                    minas++;
                }
            }
            cout<<minas<<"  ";
        }
    }

/*  G : Elaborar un programa que recorra una cara de la matriz 3D e imprima la cantidad de
        minas (grupos de unos contiguos). En la Fig.1 para la primera cara debe imprimir 3.*/

    cout<<"\n=============================PARTE G====================================="<<endl;

        int (*ptr3)[filas][columnas]=BuscaMinas;
        int minasGrupos=0;
        int posiciones[filas][columnas];
        for(int (*ptr4)[columnas]=posiciones;ptr4<posiciones+filas;ptr4++){
            for(int *ptr5=*ptr4;ptr5<(*ptr4)+columnas;ptr5++)*ptr5=0;
        }

        for(int (*q)[columnas]=*ptr3;q<(*ptr3)+filas;q++){
            for(int *r=*q;r<(*q)+columnas;r++){
                int *ptr5=*(posiciones+(q-(*ptr3)))+(r-(*q));
                if(*r==1 && *ptr5==0){
                    minasGrupos++;
                    sonearCara(*ptr3,posiciones,q-(*ptr3),r-(*q),filas,columnas);
                }
            }
        }
        cout<<"Totald e minas de la primera cara : "<<minasGrupos<<endl;

/*  H : Elaborar un programa que recorra cada cara de la matriz 3D imprima la cantidad de
        minas (grupos de unos contiguos) de cada cara. En la Fig.1 el programa debe mostrar
        como resultado 3,3,3.
*/
        cout<<"\n=============================PARTE H====================================="<<endl;
        for(int (*p)[filas][columnas]=BuscaMinas;p<BuscaMinas+caras;p++){
            int minasGrupos=0;
            int posiciones[filas][columnas];
            for(int (*ptr4)[columnas]=posiciones;ptr4<posiciones+filas;ptr4++){
                for(int *ptr5=*ptr4;ptr5<(*ptr4)+columnas;ptr5++)*ptr5=0;
            }
            for(int (*q)[columnas]=*p;q<(*p)+filas;q++){
                for(int *r=*q;r<(*q)+columnas;r++){
                    int *ptr5=*(posiciones+(q-(*p)))+(r-(*q));
                    if(*r==1 && *ptr5==0){
                        minasGrupos++;
                        sonearCara(*p,posiciones,q-(*p),r-(*q),filas,columnas);
                    }
                }
            }
            cout<<"Totald e minas de la primera cara : "<<minasGrupos<<endl;
        }
/*  I : Elaborar un programa que recorra toda la matriz 3D e imprima la cantidad de minas de
        toda la matriz. En la Fig.1 el programa debe mostrar como resultado 5.
*/
        cout<<"\n=============================PARTE I====================================="<<endl;

        int gruposMinasTotales=0;
        int cuboMarca[caras][filas][columnas];

        for(int (*x)[filas][columnas]=cuboMarca;x<cuboMarca+caras;x++){
            for(int (*y)[columnas]=*x;y<(*x)+filas;y++){
                for( int *z=*y;z<(*y)+columnas;z++)*z=0;
            }
        }
        int (*recorrido)[filas][columnas]=cuboMarca;
        for(int (*p)[filas][columnas]=BuscaMinas;p<BuscaMinas+caras;p++,recorrido++){
            for(int (*q)[columnas]=*p;q<(*p)+filas;q++){
                for(int *r=*q;r<(*q)+columnas;r++){
                    int *ptr5=*((*recorrido)+(q-(*p)))+(r-(*q));
                    if(*r==1 && *ptr5==0){
                        gruposMinasTotales++;
                        sonearCubo(BuscaMinas,cuboMarca,p-BuscaMinas,q-(*p),r-(*q),caras,filas,columnas);
                    }
                }
            }
        }
        cout<<"\nTotal de minas en el juego : "<<gruposMinasTotales<<endl;

    return 0;
}
