	#include "Matriz.h"
	#include <iostream>
	#include <string>
	#include <cmath>
	
	using std::cin;
	using std::cout;
	using std::endl;
	using std::string;

		Matriz::Matriz(){
			
		}
		
		
		Matriz::Matriz(string nombre1,int tamano1){
			nombre = nombre1;
			tamano = tamano1;
				
		}
		
		int** Matriz::getMatriz(){
			return matriz;
		}
		
		void Matriz::setMatriz(int** matriz2){
			
			matriz = matriz2;
			
		}
	
	
	
	//Para sacar el determinante
		int Matriz::Determinante(int** matriz1, int tamano1){
			int determinante = 0;
	    	if (tamano1 == 1)
	    	{
	        	determinante = matriz1[0][0];
	    	}
	    	else
	    	{
	        	for (int i = 0; i < tamano1; i++)
	        	{
	            	determinante = determinante + matriz1[0][i] * Cofactor(matriz1,tamano1,0, i);
	        	}
	    	}
	    	return determinante;
			
			
			
		}
	
	
		int Matriz::Cofactor(int** matriz1,int tamano2,int fila, int columna)
		{
			
		    int ** matriz2 = NULL;
		    int orden = tamano2 - 1;
		    
		    matriz2 = new int *[orden];
		    for (int i = 0; i < orden; i++)
		    {
		    	
		        matriz2[i] = new int[orden];
		        
		    }
		    
		    int x = 0;
			int y = 0;
			
		    for (int i = 0; i < tamano2; i++)
		    {
		        for (int j = 0; j < tamano2; j++)
		        {
		        	
		        	
		            if (i != fila && j !=columna){
		                matriz2[x][y] = matriz1[i][j];
		                y++;
		                if (y>=orden){
		                    x++;
		                    y = 0;
		                }
		                
		            }
		        }
		    }
		    
		    
		    return pow(-1.0, fila + columna) * Determinante(matriz2, orden);
		}
	
	
	
	
		int** Matriz::operator > (const int escalar)
		{
		    cout<<"El escalar: "<<escalar<<" Multiplicador por "<< nombre<<endl;
		    
		    int ** Nueva = NULL;
		    Nueva = new int *[tamano];
		    for (int i = 0; i < tamano; i++)
		    {
		        Nueva[i] = new int[tamano];
		    }
		  
		    
		    for (int i = 0; i < tamano; i++)
		    {
		        for (int j = 0; j < tamano; j++)
		        {
		            Nueva[i][j] = matriz[i][j] * escalar  ;
		        }
		    }
		    return Nueva;
	    	
		}
		

        int** Matriz::operator&(int** matriz2){
        	
        	cout<<"Multiplicacion de matrices: "<<endl;
        	
        	int ** Nueva = NULL;
		    Nueva = new int *[tamano];
		    for (int i = 0; i < tamano; i++)
		    {
		        Nueva[i] = new int[tamano];
		    }
		    
        	
	        for (int i = 0; i < tamano; i++)
	    	{
	       		for (int j = 0; j < tamano; j++)
	        	{
	        		
	            	for (int x = 0; x < tamano; x++)
	            	{
	                	Nueva[i][j] += matriz[i][x] * matriz2[x][j];
	            	}
	        	}
	    	}
    
    
    		return Nueva; 	
     	
		}
		
		
        int** Matriz::operator|(int** matriz2){ //suma de matriz
        	cout<<"La suma de matrices es de:" <<endl;
        
        
        	int ** Nueva = NULL;
		    Nueva = new int *[tamano];
		    for (int i = 0; i < tamano; i++)
		    {
		        Nueva[i] = new int[tamano];
		    }
        
        
	        for (int i = 0; i < tamano; i++)
	    	{
	        	for (int j = 0; j < tamano; j++)
	        	{
	           		Nueva[i][j] = matriz[i][j] + matriz2[i][j];
	        	}
	   		}
	   		
	   		
	   		return Nueva;
        	
		}
		
		
        int** Matriz::operator*(int** Nueva)  //Multiplicacion dentro del espacio vectorial
        {
        	cout<<"Multiplicacion dentro del espacio vectorial:" <<endl;
        	
        	for (int i = 0; i < tamano; i++)
	    	{
	        	for (int j = 0; j < tamano; j++)
	        	{
	            	Nueva[j][i] = matriz[i][j];
	        	}
	    	}
    	
		return Nueva;
    	
        	
		}
        int** Matriz::operator+(int** matriz2) //Suma dentro de espacio vectorial
        {
        	cout<<"Suma dentro de espacio vectorial:" <<endl;
        	
  			int ** Nueva = NULL;
		    Nueva = new int *[tamano];
		    for (int i = 0; i < tamano; i++)
		    {
		        Nueva[i] = new int[tamano];
		    }
        	
        	for (int i = 0; i < tamano; i++)
		    {
		        for (int j = 0; j < tamano; j++)
		        {
		            if (i == j)
		            {
		                Nueva[i][j] = 2 * (matriz[i][j] - matriz2[i][j]);
		            }
		            else
		            {
		                Nueva[i][j] = matriz[i][j] + matriz2[i][j];
		            }
		        }
		    }
    		return Nueva;   	
		}
		
		
        int** Matriz::operator++(int determinante) //incremento
        {
			cout<<"El incremeto de la matriz:" <<endl;	
			
        	int diferencia = determinante - tamano;
		    int absoluto = abs(diferencia);
		    
		    int ** Nueva = NULL;
		    Nueva = new int *[tamano];
		    for (int i = 0; i < tamano; i++)
		    {
		        Nueva[i] = new int[tamano];
		    }
		    
		    for (int i = 0; i < tamano; i++)
		    {
		        for (int j = 0; j < tamano; j++)
		        {
		            Nueva[i][j] = absoluto + matriz[i][j];
		        }
		    }
		    return Nueva;
        	
		}
		
        int** Matriz::operator--(int determinante) //decremento
        {
        	
        	cout<<"El decremento de la matriz:" <<endl;
        	
        	int diferencia = determinante - tamano;
		    int absoluto = abs(diferencia);
		    
		    int ** Nueva = NULL;
		    Nueva = new int *[tamano];
		    for (int i = 0; i < tamano; i++)
		    {
		        Nueva[i] = new int[tamano];
		    }
		    
		    for (int i = 0; i < tamano; i++)
		    {
		        for (int j = 0; j < tamano; j++)
		        {
		            Nueva[i][j] = absoluto - matriz[i][j];
		        }
		    }
		    return Nueva;
        	
		}
	

	string Matriz::getNombre(){
		return nombre;
		
	}
	
	void Matriz::setNombre(string nombre2)
	{
		nombre = nombre2;
	}
	
	int Matriz::getTamano(){
		return tamano;
			
	}
	
	void Matriz::setTamano(int tamano2){
		tamano = tamano2;
		
	}
	
	//Manejo de las matrices 
	
	
	int** Matriz::CrearMatriz()
	{
	    matriz = new int *[tamano];
	    for (int i = 0; i < tamano; i++)
	    {
	        matriz[i] = new int[tamano];
	    }
	    return matriz;
	}



	void Matriz::imprimirMatriz()
	{
	
	    for (int i = 0; i < tamano; i++)
	    {
	        for (int j = 0; j < tamano; j++)
	        {
	            cout << "[" << matriz[i][j] << "] ";
	        }
	        cout << endl;
	    }
	}
	
	
	
	void Matriz::llenarmatriz()
	{
	    int numero = 0;
	    for (int i = 0; i < tamano; i++)
	    {
	        for (int j = 0; j < tamano; j++)
	        {
	            cout<<"Ingrese el numero: "<<endl;
	            cin>>numero;
	            matriz[i][j] = numero; 
	        }	
	    }
	}
	
	void Matriz::liberarMatriz()
	{
	    for (int i = 0; i < tamano; i++)
	    {
	        if (matriz[i] != NULL)
	        {
	            delete[] matriz[i];
	            matriz[i] = NULL;
	        }
	    }
	}



