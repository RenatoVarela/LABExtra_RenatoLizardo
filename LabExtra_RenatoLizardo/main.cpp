#include <iostream>
#include "Matriz.h"
#include <string.h>
#include <vector>
#include <cstdlib>

using namespace std;

void CrearMatriz();
void ListarMatriz();
void EliminarMatriz();
void Operar();
void limpiar(); //LIBERA VECTORES Y  MATRICES AL SALIR
int BuscarMatriz(string);
vector<string> Valores(size_t);

vector<Matriz*>matrices;
vector<Matriz*>matrices_operadas;

int main(){
	
	int opcion = 0;
	bool salir = false;
	int posicion;
	

	while(salir == false){
		cout << "Ingrese una de las siguientes opciones:"<<endl
			<< "1)Crear Matriz:"<<endl
			<< "2)Listar Matrices:"<<endl
			<< "3)Eliminar Matrices:"<<endl
			<< "4)Operar con matrices:"<<endl
			<< "5)Salir:"<<endl;	
		cin>> opcion;
		
		
		switch(opcion){
			case 1:
				CrearMatriz();
				break;
				
			case 2:
				ListarMatriz();
				
				break;
				
			case 3:
				cout << "Matrices: " << endl;
			    ListarMatriz();
			    
			    cout << "Ingrese la posicion de la matriz a eliminar: " << endl;
			    cin >> posicion;
			    matrices.erase(matrices.begin() + posicion);
				
				break;
				
				
			case 4:
				Operar();
				break;
				
			case 5:
				limpiar();
				salir = true;
				break;
		
		
		}
	
	}
	
	return 0;
}


void CrearMatriz(){
	int tamano =0;
	string nombre;
	Matriz *matriz;
  	int valor =0;
  
	cout<<"Ingrese el nombre de la matriz" <<endl;
  	cin>>nombre;
  	
  	while(BuscarMatriz(nombre) != -1){
  		cout<<"Ese nombre esta repetido ingrese otro" <<endl;
  		cin>>nombre;
	}
 	 
  	cout<<"Ingrese el tamano de la matriz" <<endl;
  	cin>>tamano;
 
  
 	matriz = new Matriz(nombre,tamano);
 	matriz->CrearMatriz();
 	matriz->llenarmatriz();
 
 	matrices.push_back(matriz);
	
}
void ListarMatriz(){
	
	cout<<"Matrices creadas"<<endl;
	
		for(int i = 0;i < matrices.size();i++) {
		
		cout<< i <<")"<<matrices[i]->getNombre() <<endl;
		matrices[i]->imprimirMatriz();
		cout<<matrices[i]->Determinante(matrices[i]->getMatriz(),matrices[i]->getTamano())<<endl;
		cout<<"-----------------------------------------------------"<<endl;
		
	}
	
	cout<<endl<<endl;
	
	cout<<"Operaciones Realizadas: "<<endl;
	
		for(int i = 0;i < matrices_operadas.size();i++) {
		
		cout<< matrices_operadas[i]->getNombre() <<endl;
		matrices_operadas[i]->imprimirMatriz();
		cout<<matrices_operadas[i]->Determinante(matrices_operadas[i]->getMatriz(),matrices_operadas[i]->getTamano())<<endl;
		cout<<"-----------------------------------------------------"<<endl;
		
	}
	cout<<endl<<endl;
	
	
}



void EliminarMatriz(){
	
	
}


void Operar(){
	
	vector<string> coordenadas;
	
	string cadena = "";
	Matriz* Matriz_Operada;
	
	size_t indicador;
	
	
	//variables a utilizar
	
	int valor1 = 0; //valor antes del simbolo
	int valor2 =0; //valor despues del simbolo
	
	int escalar; //para la multiplicacion dentro de espacio vectorial
	
	cout << "Ingrese una de las siguientes operaciones:"<<endl
			<< "1)Suma [|]:"<<endl
			<< "2)Incremento [++]:"<<endl
			<< "3)Decremento [--]:"<<endl
			<< "4)Multiplicacion por escalar [<]:"<<endl
			<< "5)Producto entre matrices [&]:"<<endl
			<< "6)Suma dentro del espacio vectorial [+]:"<<endl
			<< "7)Multiplicacion dentro del espacio vectorial [*]:"<<endl;		
	cin>> cadena;
	
	
		if(strstr(cadena.c_str(),">"))
		{
			indicador = cadena.find(">");
        	coordenadas.push_back(cadena.substr(0,indicador));
        	coordenadas.push_back(cadena.substr(indicador+1,cadena.size()) );	
        	valor1 =  atoi(coordenadas[0].c_str());
        	valor2 = BuscarMatriz(coordenadas[1]);
        	
        	
        	
           	if(valor1 != -1){
           		Matriz_Operada = new Matriz(cadena,2);
           		Matriz_Operada->CrearMatriz();
           		Matriz_Operada->setMatriz(matrices[valor2]->operator >(valor1));
           		Matriz_Operada->imprimirMatriz();
           		matrices_operadas.push_back(Matriz_Operada);
				   	
			}else{
				cout<<"Revise las ordenes de las matrices o si la matriz existe"<<endl;
			}	
        	
		}
		
		
		else if(strstr(cadena.c_str(),"&"))
		{
			indicador = cadena.find("&");
        	coordenadas.push_back(cadena.substr(0,indicador));
        	coordenadas.push_back(cadena.substr(indicador+1,cadena.size()) );	
        	valor1 =  BuscarMatriz(coordenadas[0]);
        	valor2 = BuscarMatriz(coordenadas[1]);
        	
           	if(valor1 != -1  && valor2 != -1 && matrices[valor1]->getTamano() == matrices[valor2]->getTamano()){
           		Matriz_Operada = new Matriz(cadena,matrices[valor1]->getTamano());
           		Matriz_Operada->CrearMatriz();
           		Matriz_Operada->setMatriz(matrices[valor1]->operator &(matrices[valor2]->getMatriz()));
           		Matriz_Operada->imprimirMatriz();
           		matrices_operadas.push_back(Matriz_Operada);
				   	
			}else{
				cout<<"Revise las ordenes de las matrices o si la matriz existe"<<endl;
			}	
        	
		}
		
		else if(strstr(cadena.c_str(),"|"))
		{
			indicador = cadena.find("|");
        	coordenadas.push_back(cadena.substr(0,indicador));
        	coordenadas.push_back(cadena.substr(indicador+1,cadena.size()) );	
        	valor1 =  BuscarMatriz(coordenadas[0]);
        	valor2 = BuscarMatriz(coordenadas[1]);
        	
           	if(valor1 != -1  && valor2 != -1 && matrices[valor1]->getTamano() == matrices[valor2]->getTamano()){
           		Matriz_Operada = new Matriz(cadena,matrices[valor1]->getTamano());
           		Matriz_Operada->CrearMatriz();
           		Matriz_Operada->setMatriz(matrices[valor1]->operator |(matrices[valor2]->getMatriz()));
           		Matriz_Operada->imprimirMatriz();
           		matrices_operadas.push_back(Matriz_Operada);
				   	
			}else{
				cout<<"Revise las ordenes de las matrices o si la matriz existe"<<endl;
			}	
        	
		}
		
		
		else if(strstr(cadena.c_str(),"++"))
		{
			indicador = cadena.find("++");
        	coordenadas.push_back(cadena.substr(2,cadena.size()) );	
        	valor2 = BuscarMatriz(coordenadas[0]);
        	
           	if(valor2 != -1){
           		Matriz_Operada = new Matriz(cadena,matrices[valor2]->getTamano());
           		Matriz_Operada->CrearMatriz();
           		Matriz_Operada->setMatriz(matrices[valor2]->operator ++(matrices[valor2]->Determinante(matrices[valor2]->getMatriz(),matrices[valor2]->getTamano())));
           		Matriz_Operada->imprimirMatriz();
           		matrices_operadas.push_back(Matriz_Operada);
				   	
			}else{
				cout<<"Revise las ordenes de las matrices o si la matriz existe"<<endl;
			}	
        	
		}
		
		
		else if(strstr(cadena.c_str(),"--"))
		{
			indicador = cadena.find("--");
        	coordenadas.push_back(cadena.substr(2,cadena.size()) );	
        	valor2 = BuscarMatriz(coordenadas[0]);
        	
           	if(valor2 != -1){
           		Matriz_Operada = new Matriz(cadena,matrices[valor2]->getTamano());
           		Matriz_Operada->CrearMatriz();
           		Matriz_Operada->setMatriz(matrices[valor2]->operator --(matrices[valor2]->Determinante(matrices[valor2]->getMatriz(),matrices[valor2]->getTamano())));
           		Matriz_Operada->imprimirMatriz();
           		matrices_operadas.push_back(Matriz_Operada);
				   	
			}else{
				cout<<"Revise las ordenes de las matrices o si la matriz existe"<<endl;
			}
        	
		}
		
		
		else if(strstr(cadena.c_str(),"+"))
		{
			indicador = cadena.find("+");
        	coordenadas.push_back(cadena.substr(0,indicador));
        	coordenadas.push_back(cadena.substr(indicador+1,cadena.size()) );	
        	valor1 =  BuscarMatriz(coordenadas[0]);
        	valor2 = BuscarMatriz(coordenadas[1]);
        	
           	if(valor1 != -1 && valor2 != -1 && matrices[valor1]->getTamano() == matrices[valor2]->getTamano()){
           		Matriz_Operada = new Matriz(cadena,matrices[valor1]->getTamano());
           		Matriz_Operada->CrearMatriz();
           		Matriz_Operada->setMatriz(matrices[valor1]->operator +(matrices[valor2]->getMatriz()));
           		Matriz_Operada->imprimirMatriz();
           		matrices_operadas.push_back(Matriz_Operada);
				   	
			}else{
				cout<<"Revise las ordenes de las matrices o si la matriz existe"<<endl;
			}	
        	
		}
		
		
		else if(strstr(cadena.c_str(),"*"))
		{
			indicador = cadena.find("*");
        	coordenadas.push_back(cadena.substr(0,indicador));
        	coordenadas.push_back(cadena.substr(indicador+1,cadena.size()) );	
        	valor1 =  atoi(coordenadas[0].c_str());
        	valor2 = BuscarMatriz(coordenadas[1]);
        	
           	if(valor2 != -1 && valor1 !=0){
           		Matriz_Operada = new Matriz(cadena,matrices[valor2]->getTamano());
           		Matriz_Operada->CrearMatriz(); 		
           		Matriz_Operada->setMatriz(matrices[valor2]->operator *(Matriz_Operada->getMatriz()));
           		escalar = (Matriz_Operada[valor2].Determinante(Matriz_Operada[valor2].getMatriz(),Matriz_Operada[valor2].getTamano()))/valor1;
           		Matriz_Operada->setMatriz(Matriz_Operada[valor2].operator >(escalar));
           		Matriz_Operada->imprimirMatriz();
           		matrices_operadas.push_back(Matriz_Operada);
				   	
			}else{
				cout<<"Revise las ordenes de las matrices o si la matriz existe"<<endl;
			}	
        	
		}
		
		else{
			
					cout<<"Eso no existe"<<endl;
		}
		
		
		
		
		
}

int BuscarMatriz(string nombre){
	int posicion = -1;
	
	for(int i = 0; i < matrices.size(); i++){
		if(matrices[i]->getNombre() == nombre){
			posicion = i;
		}
	}
		
	return posicion;	
	
}

void limpiar(){
			//liberar la memoria de los matrices creadas
	 		for (int i = 0; i < matrices.size(); i++)
            {
                matrices[i]->liberarMatriz();
            }
          
            for (int i = 0; i < matrices.size(); i++)
            {
                delete matrices[i];
                matrices[i] = NULL;
            }
            matrices.clear();
                   
            //liberar memoria de las matrices operadas
            for (int i = 0; i < matrices_operadas.size(); i++)
            {
                matrices_operadas[i]->liberarMatriz();
            }
            for (int i = 0; i < matrices_operadas.size(); i++)
            {
                delete matrices_operadas[i];
                matrices_operadas[i] = NULL;
            }
            matrices_operadas.clear();
}
