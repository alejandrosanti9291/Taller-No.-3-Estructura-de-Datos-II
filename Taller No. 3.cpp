/*
*   Programa:
*   Fecha:
*   Nombre:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct nodo{
    float num;
    nodo *siguiente;
};

struct nodo2{
    char oper;
    nodo2 *siguiente;
};

void menu();
bool pilaVacia();
void ingresar_posfija(nodo *&, nodo2 *&, char *);
void mostrar_pila(nodo *, nodo2 *);
void insertarElementoPila(nodo *&, float);
void hacerOperacionPostfijo(nodo *&, char *);
float hacerOperacion(float, float, char);
bool esNumero(char);
bool esOperador(char);
bool esEspacio(char);
void mostrarResultadosOperacionPostfijo(nodo *&, char *);
float convertirCadenaNumero(char []);

int main(){
    menu();

    return 0;
}

void menu(){
    nodo *pila = NULL;
    nodo2 *pila2 = NULL;
    char arreglo[50], *pa = arreglo;
    int opcion;

    do{
        printf("\t\t|--------------|\n");
		printf("\t\t|     MENU     |\n");
		printf("\t\t|--------------|\n");
		printf("\t\t|  1.Ingresar  |\n");
		printf("\t\t|  2.Mostrar   |\n");
		printf("\t\t|  3.Operar    |\n");
		printf("\t\t|  4.Resultado |\n");
		printf("\t\t|  0.Salir     |\n");
		printf("\t\t|--------------|\n\n");
		printf("\t\tIngrese una opcion: ");
		scanf("%d",&opcion);

		switch(opcion){
			case 1: ingresar_posfija(pila, pila2, pa);
				break;
			case 2: mostrar_pila(pila, pila2);
				break;
			case 3: hacerOperacionPostfijo(pila, arreglo);
				break;
            case 4: mostrarResultadosOperacionPostfijo(pila, arreglo);
				break;
            case 0:exit(0);
				break;
			default:printf("No es una opcion valida\n");
				break;
		}
		system("pause");
		system("cls");
	}while(opcion != 0);

}

bool pilaVacia(nodo *pila){
    return (pila == NULL)?true:false;
}

void ingresar_posfija(nodo *&pila, nodo2 *&pila2, char *pa){
    fflush(stdin);
    char a[10];
    int n, c=0;
    printf("Ingrese operacion posfija dejando espacio entre cada digito: ");
    fgets(pa,50,stdin);

    for(int i=0;i<strlen(pa);i++)
    {
        if(pa[i]!=' ')
        {
            a[c]=pa[i];
            c++;
        }
        else
        {
            n=atoi(a);
            nodo *nuevo_nodo=(nodo*)malloc(sizeof(nodo));
            nuevo_nodo->num=n;
            nuevo_nodo->siguiente=pila;
            pila=nuevo_nodo;
            for(int r=0;r<c;r++)
            {
                a[r]=' ';
            }
            c=0;
        }

        if(pa[i]=='+' || pa[i]=='-' || pa[i]=='*' || pa[i]=='/' || pa[i]=='^')
        {
            nodo2 *nuevo2=(nodo2*)malloc(sizeof(nodo2));
            nuevo2->oper=pa[i];
            nuevo2->siguiente=pila2;
            pila2=nuevo2;
        }
    }
}

void mostrar_pila(nodo *pila, nodo2 *pila2){
     int n;
    char c;
    printf("Numero Pila:\n");
    while(pila!=NULL)
    {
        nodo *aux=pila;
        n=aux->num;
        pila=aux->siguiente;
        printf("%d\n",n);
    }

    printf("\nOperadores Pila:\n");
    while(pila2!=NULL)
    {
        nodo2 *aux2=pila2;
        c=aux2->oper;
        pila2=aux2->siguiente;
        printf("%c\n",c);
    }
}

void hacerOperacionPostfijo(nodo *&pila, char arreglo[50]){
    int i, longitud, j = 0;
    float numero_insertar, a, b ,c;
    char numero[50];
    longitud = strlen(arreglo);

    for(i = 0; i < longitud; i++){
        if(esNumero(arreglo[i])){
            numero[j] = arreglo[i];
            j+=1;
        }
        if(esEspacio(arreglo[i])){
            numero_insertar = convertirCadenaNumero(numero);
            insertarElementoPila(pila, numero_insertar);
            j = 0;
        }
        if(esOperador(arreglolementoPila(pila)));
            b = eliminarElementoPila(pila);

            c = hacerOperacion(a,b,arreglo[i]);
            insertarElementoPila(pila,c);

            i+=1;
        }
}

float hacerOperacion(float a, float b, char operador){
    int ope = operador;
    float c;

     switch(ope)
    {
    case 43:
        c=a+b;
    break;
    case 45:
        c=a-b;
    break;
    case 47:
        c=a/b;
    break;
    case 94:
        c=pow(a,b);
    break;
    case 42:
        c=a*b;
    break;
    }
    return c;
}
bool esNumero(char valor){
    int numero = valor;
    return (numero > 47 && numero < 58) ? true: false;
}
bool esOperador(char valor){
    int numero = valor;
    return (numero == 43 || numero == 45 || numero == 42 || numero == 47 || numero == 94) ? true: false;
}
bool esEspacio(char valor){
    int numero = valor;
    return (numero == 32) ? true: false;
}

void insertarElementoPila(nodo *&pila, float n){
    nodo *nuevo_nodo = (nodo*)malloc(sizeof(nodo));
    nuevo_nodo->num = n;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;
}

 float eliminarElementoPila(nodo *&pila){
    float n;
    nodo *aux = pila;
    n = aux->num;
    pila = aux->siguiente;
    free(aux);
    return n;
}

float convertirCadenaNumero(char numero[50]){
    float num;
    num = atoi(numero);
    return num;
}
