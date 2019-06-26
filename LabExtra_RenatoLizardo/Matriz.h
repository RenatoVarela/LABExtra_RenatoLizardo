#ifndef MATRIZ_H
#define MATRIZ_H
#include <string>
using std::string;

class Matriz{
	private:
		string nombre;
		int tamano;
		int** matriz;
		
	public:
		Matriz();
	    Matriz(string,int);
		int** getMatriz();
		void setMatriz(int**);
		string getNombre();
		void setNombre(string);
		int getTamano();
		void setTamano(int);
		int Determinante(int**,int);
		int Cofactor(int**,int,int, int);	        
        int** operator>(int); //Multiplicacion por escalar
        int** operator&(int**); //Multiplicacion habitual de matrices
        int** operator|(int**);  //Suma de matrices
        int** operator*(int**);  //Multiplicacion dentro del espacio vectorial
        int** operator+(int**); //Suma dentro de espacio vectorial
        int** operator++(int); //incremento
        int** operator--(int); //decremento
        //para crear, librar, imprimir la matriz
        int** CrearMatriz();
		void imprimirMatriz( );
		void llenarmatriz();
		void liberarMatriz();
	
	
};
#endif
