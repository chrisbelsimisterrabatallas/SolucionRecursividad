#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

//1) Diseñe la función que utilizando multiplicaciones sucesivas por 10,
// devuelva el total de cifras que tiene un número.

int cuentacifras (int num)
{
    int i=1, cont=0;
    if(num<0) num=num*-1; //Si el numero es negativo, se lo hace positivo.
    while (i <= num)
    {
        i=i*10;
        cont++;
    }
    return cont;
}

bool primo (int num)
{
    bool esPrimo=true;
    int i=2;
    while(i<=num/2 && esPrimo){
        if(num%i==0)
            esPrimo= false;
        i++;
    }
    return esPrimo;
}

int sumaprimos(int n)
{
    int i=1, cont=1;
    int suma=0;
    while(i<=n){
        cont++;
        if(primo(cont))
        {
         suma+=cont;
         i++;
        }
    }
    return suma;
}

int sumaprimosrecursivo(int limite, int n)
{
    if(limite>0) {
        if (primo(n))
            return sumaprimosrecursivo(limite - 1, n + 1) + n;
        else
            return sumaprimosrecursivo(limite, n + 1);
    }
    else
    return 0;
}

void adivinaElNumero(int oportunidades) {
    //Numeros aleatorios entre 0 y 50:
    int num=1 + (rand()%51);
    //int num = 15;
    int n;
    bool adivinaste= false;
    cout << endl << "Adivina el NUMERO entre 1 y 50";

    int i = 1;
    while (i <= oportunidades && adivinaste == false) {
        cout << endl << "OPORTUNIDAD #: " << i;
        cout << endl << "Ingresa tu NUMERO: ";
        cin >> n;

        {
            if (n > num)
                cout << endl << "Debes ingresar un NUMERO mas bajo... ";
            else if (n < num)
                cout << endl << "Debes ingresar un NUMERO mas alto.. ";
            else
                cout << endl << "FELICIDADES, GANASTE UN PASAJE A GALAPAGOS.. ";
            adivinaste = true;
        }
        i++;
    }
    if (adivinaste)
        cout << endl << "ERES EL CAMPEON ";
    else
        cout << endl << "Vuelve a intentar ";
}
int main() {
    int num= -890;
cout<<endl<<" El numero " <<num<< " tiene " <<cuentacifras(num)<< " cifras ";
cout<<endl;
num=9;
if(primo(num))
    cout<<endl<<num<<" Es primo " ;
else
    cout<<endl<<num<<" No es primo " ;

    cout<<endl<<"La suma de los primeros 4 primos es: (2+3+5+7)= "<<sumaprimos(4);

    cout<<endl<<"La suma de los primeros 4 primos es: (2+3+5+7)= "<<sumaprimosrecursivo(4,2);


    srand(time(NULL));

    //Numeros aleatorios entre 0 y 50:
    num=rand()%51;
    cout<<endl<<"Aleatorios: "<<num;

    int opcion;
    bool salir=true;
    while(true){
        cout<<endl<<endl<<"MENU PRINCIPAL - ADIVINA EL NUMERO ";
        cout<<endl<<"1. JUGAR ";
        cout<<endl<<"2. SALIR ";
        cout<<endl<<"CUAL ES TU OPCION: "; cin>>opcion;
        switch(opcion){
            case 1:
                adivinaElNumero(5);
                break;
            case 2:
                salir=true;
                break;
            default:
                cout<<endl<<"OPCION NO VALIDA ";
        }
        if(salir)
            break;
    }
    return 0;
}
