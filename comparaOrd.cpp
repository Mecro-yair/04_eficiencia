
//libreria
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <chrono>

using namespace std;
void metodoBurbuja(int [],int );
void quickSort(int [],int );
void reduce(int [],int ,int );

int main(){
	SetConsoleOutputCP(CP_UTF8);
	int n,op,cantidad;
	
	
	cout << "Digite la cantidad:\n"; cin >> n;
	int numeros[n];
	cout << "Digite el limite del arreglo (¿desde 0 hasta?):\n"; cin >> cantidad;
	srand(time(0));
	for(int i =0;i<n;i++){
		numeros[i]= rand() % (cantidad+1);
	}
	cout <<endl;
	cout << "Arreglo no ordenado.\n";
	for (int i =0;i<n;i++){
		cout << numeros[i]<<" ";
	}
		
	do{
		cout << "\n\n\nBienvenido a la comparacion de dos metodos de ordenamiento"
		<<"\n1. Método de Burbuja."
		<<"\n2. Método de QuickSort."
		<<"\n0.Salir."<<endl;
		cin >>op;
		switch (op){
			case 1:
				metodoBurbuja(numeros,n-1);
				break;
			case 2:
				quickSort(numeros,n-1);
				break;
		cout << "Arreglo ordenado.\n";
		for (int i =0;i<n;i++){
			cout << numeros[i]<<" ";
		}	
		}
	}while(op != 0);
		
		
	return 0;
}

//primero a comprarar
void metodoBurbuja(int a[],int  n){
	auto inicio = chrono::high_resolution_clock::now();
	int aux;
	for(int i=0;i<n;i++){
		for(int j =0;j<n;j++){
			if (a[j]>a[j+1]){
				aux = a[j];
				a[j]=a[j+1];
				a[j+1] = aux;
			}
		}
	}
	auto fin = chrono::high_resolution_clock::now();
	chrono::duration<double>duracion = fin-inicio;
	cout << "\nEl tiempo de ejecucion del algoritmo fue de : "<<duracion.count()<<" segundos."<<endl;
}
//segundo a comparar
void quickSort(int A[],int n){
	reduce(A, 0 ,n);
}
void reduce(int A[],int inicio,int final){
	int cen, pos,aux;
	int izq = inicio;
	int der = final;
	pos = izq;
	cen = 1;
	while(cen == 1){
		cen = 0;
		while((A[pos] <= A[der]) && (pos != der)){
			der--;
		}
		if (pos != der){
			aux = A[pos];
			A[pos]= A[der];
			A[der]=aux;
			pos = der;
			//recorrido de izquierda a derecha
			while((A[pos] >= A[izq]) && (pos != izq)){
				izq++;
			}
			if (pos != izq){
				aux = A[pos];
				A[pos] = A[izq];
				A[izq] = aux;
				pos = izq;
				cen =1;
			}
		}
		if (pos-1 > inicio){
			reduce(A,inicio,pos-1);
		}
		if (pos+1<final){
			reduce(A, pos+1, final);
		}
	}

}