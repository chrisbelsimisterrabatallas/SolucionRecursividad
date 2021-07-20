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
    srand(time(NULL));
    //Numeros aleatorios entre 0 y 50:
    int num=1 + (rand()%51);
    //int num = 15;
    int n;
    bool adivinaste= false;
    cout << endl << "Adivina el NUMERO entre 1 y 50";

    int i = 1;
    while (i <= oportunidades && adivinaste == false) {
        cout << endl << "OPORTUNIDAD #: " << i;
        cout << endl << "INGRESA TU NUMERO: ";
        cin >> n;

            if (n > num)
                cout << endl << "Debes ingresar un NUMERO mas bajo... ";
            else if (n < num)
                cout << endl << "Debes ingresar un NUMERO mas alto.. ";
            else{
                cout << endl << "FELICIDADES, GANASTE UN PASAJE A GALAPAGOS.. ";
            adivinaste = true;

        }
        i++;
    }
    if (adivinaste)
        cout << endl << "ERES EL CAMPEON ";
    else
        cout << endl << "PERDISTE VUELVE HA INTENTARLO...";
}

//El juego de dados:
//
//Diseñe la función que simule el lanzamiento de 2 dados. Cada dado debe generar un
// número entre 1 y 6. Se pide usar números aleatorios.
//
//El usuario tiene entre entre 2 o 3 oportunidades (usted decide si son 2 o 3 oportunidades).
//
//El usuario gana cuando los números de ambos dados coinciden o si saca un 11, es decir,
// gana si saca par de unos (1 y 1), par de dos (2 y 2) , . . . .o par de seis ( 6 y 6) o también si saca un 11 ( 5 y 6).
//
//Se pide imprimir la cantidad de "*" según sea el número que sacó el dado, por ejemplo:
//si el dado sacó 5 se imprimirá *****; si sacó 3 se imprime ***; se sacó 6 se imprime ******; etc.
//
//Para tirar los dados puede usar:
//
//1) presiona enter para tirar los dados
//string cad
//getline(cin, cad);
//2) Ingresa 1 para tirar los dados; 2 para salir
//3) Deseas tirar los dados (S/N)

void juegodeDados (int oportunidades) {
    //Numeros aleatorios entre 1 y 6:
    int dado1;
    1+rand()%6;//tiro del primer dado
    int dado2;
    1+rand()%6;//tiro del segundo dado
    bool lanzar= false;
    cout << endl << endl << "Tira los dados, la suma de los dados debe ser entre 1, 6 y 11 ";

    int i = 1;
    while (i <= oportunidades && !lanzar) {

        cout << endl << "OPORTUNIDAD #: " << i;
        cout << endl << "Ingresa el numero del primer dado: ";
        cin>>dado1;

        cout << endl << "Ingresa el numero del segundo dado: ";
        cin>>dado2;

        {
            if (dado1+dado2 == (1 + 1)  or dado1+dado2 == (2+2) or dado1+dado2 == (3+3) or dado1+dado2 == (6+6) or dado1+dado2 == (5+6))
            {
                cout<<"\n°°° Felicidades haz ganado °°°"<<endl;
                lanzar= true;
            }
            else
                cout<<"\n*** Haz perdido ***"<<endl;
        }
        i++;
    }
    if (lanzar)
        cout << endl << "ERES EL MEJOR... ";
    else
        cout << endl << " PERDISTE VUELVE HA INTENTARLO... ";
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
    int opcion;
    bool salir=false;
    //Numeros aleatorios entre 0 y 50:
    num=rand()%51;
    cout<<endl<<"Aleatorios: "<<num;

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


    //Numeros aleatorios entre 1, 6 y solo 11:
    int dado1;
    1+rand()%6;//tiro del primer dado
    int dado2;
    1+rand()%6;//tiro del segundo dado
    string lanzar;
    salir= true;

    while (true){
        cout << endl << " Presiona cualquier tecla para empezar el juego ";
        cin >> lanzar;
        cout<<endl<<"1. Ingresa 1 para tirar los dados; 2 para salir ";
        cout<<endl<<"2. Deseas tirar los dados (S/N)";
        cout<<endl<<"CUAL ES TU OPCION: "; cin>>opcion;
        switch(opcion){
            case 1:
                juegodeDados(3);
                break;
            case 2:;
                break;
            default:
                cout<<endl<<"OPCION NO VALIDA ";
        }
        break;
    }
    return 0;
}
