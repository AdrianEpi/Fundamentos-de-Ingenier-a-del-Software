/*===============================================================================
=================================================================================

	=               Proyecto:      Campus Virtual                           =
	=               Archivo:       main.cpp                                 =
	=                                   									=
	=               Autores:                                      			=
	=                  		Adrián Emilio Padilla Rojas         			=
  	=             			Adrián Ruiz Olivero             				=
  	=             			Adrián Epifanio Rodríguez Hernández     		=
  	=             			David Valverde Gómez            				=
  	=             			Jorge Quintana García           				=
  	=             			Kabir Chetwani Kaknani          				=
  	=             			Milton Daniel Rivas Quintero    				=
  	=             			Diego Díaz Fernández            				=
  	=             			                      							=
	=               Fecha:         23/05/2019                            	=
	=               Asignatura:    Fundamentos de ingeniería del software   =
	=               Lenguaje:      C++                                    	= 

=================================================================================          
===============================================================================*/

/*----------  DECLARACION DE LIBRERIAS  ----------*/
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;
/*------------------------------------------------*/


class Asignatura
{

private:

	int asig;

public:
	Asignatura(int x):                //En el constructor creamos los diferentes tipos de fichero para cada asignaturs
	  asig(x){
		ifstream fich1;
		ofstream ficheroSalida;


		if (asig == 1){
		  fich1.open("TareasLengua.txt", ios::in);

			if (fich1.fail())
				ficheroSalida.open ("TareasLengua.txt");

		  fich1.close();
		  fich1.open("CuestionariosLengua.txt", ios::in);

			if (fich1.fail())
				ficheroSalida.open ("CuestionariosLengua.txt");

		  fich1.close();

		  fich1.open("NotasLengua.txt", ios::in);
			if (fich1.fail())
				ficheroSalida.open ("NotasLengua.txt");

		  fich1.close();

		  fich1.open("ContenidoLengua.txt", ios::in);
			if (fich1.fail())
				ficheroSalida.open ("ContenidoLengua.txt");

		  fich1.close();

		}
		else if (asig==2){

		  fich1.open("TareasMatemáticas.txt", ios::in);
			if (fich1.fail())
				ficheroSalida.open ("TareasMatemáticas.txt");

		  fich1.close();

		  fich1.open("CuestionariosMatemáticas.txt", ios::in);
			if (fich1.fail())
				ficheroSalida.open ("CuestionariosMatemáticas.txt");

		  fich1.close();

		  fich1.open("NotasMatemáticas.txt", ios::in);
			if (fich1.fail())
				ficheroSalida.open ("NotasMatemáticas.txt");

		  fich1.close();

		  fich1.open("ContenidoMatemáticas.txt", ios::in);
		  if (fich1.fail())

			ficheroSalida.open ("ContenidoMatemáticas.txt");

		  fich1.close();
		}
		else if (asig==3){

		  fich1.open("TareasInformática.txt", ios::in);
			if (fich1.fail())
				ficheroSalida.open ("TareasInformática.txt");

		  fich1.close();

		  fich1.open("CuestionariosInformática.txt", ios::in);
			if (fich1.fail())

				ficheroSalida.open ("CuestionariosInformática.txt");

		  fich1.close();

		  fich1.open("NotasInformática.txt", ios::in);
			if (fich1.fail())

				ficheroSalida.open ("NotasInformática.txt");

		  fich1.close();

		  fich1.open("ContenidoInformática.txt", ios::in);
			if (fich1.fail())

				ficheroSalida.open ("ContenidoInformática.txt");

		  fich1.close();

		}
	  }

	~Asignatura() {}


	void entregar_tarea() 
	{
	  ifstream arch1;
	  char opcion;
	  string tarea, tarea1;
	  bool encontrado;
	  system("clear");

	  do{
		  encontrado=false;
		  switch (asig){

		  case 1:
			  arch1.open("TareasLengua.txt", ios::in);
			  cout << "Introduzca la tarea a subir: ";
			  cin>> tarea;

			  while (!arch1.eof() && ( encontrado != true))
			  {
					getline(arch1, tarea1, '\n');
					if (tarea1==tarea)
					  encontrado=true;
			  }

			  if (encontrado ==true)
				cout << "Tarea entregada con éxito" << endl;

			  else
				cout << "Tarea no existente" << endl;

			  arch1.close();


			break;

		  case 2:
			  arch1.open("TareasMatemáticas.txt", ios::in);
			  cout << "Introduzca la tarea a subir: ";
			  cin>> tarea;

			  while (!arch1.eof() && ( encontrado != true))
			  {
					getline(arch1, tarea1, '\n');
					if (tarea1==tarea)
					  encontrado=true;
				
			  }

			 if (encontrado ==true)
				cout << "Tarea entregada con éxito" << endl;
			  
			  else
				cout << "Tarea no existente" << endl;

			  arch1.close();

			  break;

		  case 3:
			  arch1.open("TareasInformática.txt", ios::in);
			  cout << "Introduzca la tarea a subir: ";
			  cin>> tarea;

			  while (!arch1.eof() && ( encontrado != true))
			  {
					getline(arch1, tarea1, '\n');
					if (tarea1==tarea)
				  		encontrado=true;

			  }

			  if (encontrado ==true)
				cout << "Tarea entregada con éxito" << endl;
			  
			  else
				cout << "Tarea no existente" << endl;

			  arch1.close();
			  break;

		  default:
			  break;
		  }
		
		cout << "¿Desea entregar más tareas? [s/n]: ";
		cin >> opcion;
	  }while(opcion!='n');
	}


	void descargar_contenido() {//ofstream arch;
	  
	  ifstream arch1;
	  char opcion;
	  string tarea, tarea1;
	  bool encontrado;
	  system("clear");

	  do{
		  encontrado=false;
		  switch (asig){

		  case 1:
			  arch1.open("ContenidoLengua.txt", ios::in);
			  cout << "Introduzca el contenido a subir: ";
			  cin>> tarea;

			  while (!arch1.eof() && ( encontrado != true))
			  {

				getline(arch1, tarea1, '\n');
				if (tarea1==tarea)
				  encontrado=true;
				
			  }

			  if (encontrado ==true)
				cout << "Contenido descargado con éxito" << endl;
			  
			  else
				cout << "Contenido no existente" << endl;

			  arch1.close();
			break;

		  case 2:
			  arch1.open("ContenidoMatemáticas.txt", ios::in);
			  cout << "Introduzca el contenido a subir: ";
			  cin>> tarea;

			  while (!arch1.eof() && ( encontrado != true))
			  {
					getline(arch1, tarea1, '\n');
					if (tarea1==tarea)
					  encontrado=true;
				
			  }

			 if (encontrado ==true)
				cout << "Contenido descargado con éxito" << endl;
			  
			  else
				cout << "Contenido no existente" << endl;

			  arch1.close();
			  break;

		  case 3:
			  arch1.open("ContenidoInformática.txt", ios::in);
			  cout << "Introduzca el contenido a subir: ";
			  cin>> tarea;

			  while (!arch1.eof() && ( encontrado != true))
			  {

					getline(arch1, tarea1, '\n');
					if (tarea1==tarea)
					  encontrado=true;
			  }

			  if (encontrado ==true)
				cout << "Contenido descargado con éxito" << endl;
			  
			  else
				cout << "Contenido no existente" << endl;

			  arch1.close();
			  break;

		  default:
			  break;
		  }

		cout << "¿Desea entregar más tareas? [s/n]: ";
		cin >> opcion;
	  }while(opcion!='n');
	}
	

	void entregar_cuestionario() 
	{

	 ifstream arch1;
		  char opcion;
		  string tarea, tarea1;
		  bool encontrado;
		  system("clear");

		  do{
			  encontrado=false;
			  switch (asig){

			  case 1:
				  arch1.open("CuestionariosLengua.txt", ios::in);
				  cout << "Introduzca el cuestionario a subir: ";
				  cin>> tarea;

				  while (!arch1.eof() && ( encontrado != true))
				  {
						getline(arch1, tarea1, '\n');
						if (tarea1==tarea)
						  encontrado=true;
				  }

				  if (encontrado ==true)
					cout << "Cuestionario entregado con éxito" << endl;
				  
				  else
					cout << "Cuestionario no existente" << endl;

				  arch1.close();
				break;

			  case 2:
				  arch1.open("CuestionariosMatemáticas.txt", ios::in);
				  cout << "Introduzca el cuestionario a subir: ";
				  cin>> tarea;

				  while (!arch1.eof() && ( encontrado != true))
				  { 
					getline(arch1, tarea1, '\n');
					if (tarea1==tarea)
					  encontrado=true;
				  }

				 if (encontrado ==true)
					cout << "Cuestionario entregado con éxito" << endl;

				  else
					cout << "Cuestionario no existente" << endl;

				  arch1.close();

				  break;

			  case 3:
				  arch1.open("CuestionariosInformática.txt", ios::in);
				  cout << "Introduzca el cuestionario a subir: ";
				  cin>> tarea;

				  while (!arch1.eof() && ( encontrado != true))
				  {
						getline(arch1, tarea1, '\n');
						if (tarea1==tarea)
					 	 encontrado=true;
				  }

				  if (encontrado ==true)
					cout << "Cuestionario entregado con éxito" << endl;
				 
				  else
					cout << "Cuestionario no existente" << endl;

				  arch1.close();
				  break;

			  default:
				  break;
			  }
		
			cout << "¿Desea entregar más cuestionarios? [s/n]: ";
			cin >> opcion;
		  }while(opcion!='n');

	}


void subir_contenido() 
{
	  ofstream arch;
	  ifstream arch1;
	  char opcion;
	  string tarea, tarea1;
	  bool encontrado;
	  system("clear");

	  do{
		  encontrado=false;
		  switch (asig){

		  case 1:
			  arch.open("ContenidoLengua.txt", ios::app);
			  arch1.open("ContenidoLengua.txt", ios::in);
			  cout << "Introduzca el contenido a subir: ";
			  cin>> tarea;

			  while (!arch1.eof() && ( encontrado != true))
			  {
					getline(arch1, tarea1, '\n');
					if (tarea1==tarea)
					  encontrado=true;
			  }

			  if (encontrado ==true)
				cout << "Contenido ya existente" << endl;
			  
			  else
			  {
				arch << tarea;
				arch << endl;
				cout << "Contenido subido con éxito" << endl;
			  }
			  arch.close();
			  arch1.close();
			break;

		  case 2:
			  arch.open("ContenidoMatemáticas.txt", ios::app);
			  arch1.open("ContenidoMatemáticas.txt", ios::in);
			  cout << "Introduzca el contenido a subir: ";
			  cin>> tarea;

			  while (!arch1.eof() && ( encontrado != true))
			  {
					getline(arch1, tarea1, '\n');
					if (tarea1==tarea)
					  encontrado=true;
			  }

			  if (encontrado ==true)
				cout << "Contenido ya existente" << endl;
			  
			  else{
				arch << tarea;
				arch << endl;
				cout << "Contenido subido con éxito" << endl;
			  }
			  arch.close();
			  arch1.close();
			  break;

		  case 3:
			  arch.open("ContenidoInformática.txt", ios::app);
			  arch1.open("ContenidoInformática.txt", ios::in);
			  cout << "Introduzca el contenido a subir: ";
			  cin>> tarea;

			  while (!arch1.eof() && ( encontrado != true))
			  {
				getline(arch1, tarea1, '\n');
				if (tarea1==tarea)
				  encontrado=true;
			  }

			  if (encontrado ==true)
				cout << "Contenido ya existente" << endl;
			  
			  else{
				arch << tarea;
				arch << endl;
				cout << "Contenido subido con éxito" << endl;
			  }
			  arch.close();
			  arch1.close();
			  break;

		  default:
			  break;
		  }

		arch.close();
		cout << "¿Desea subir más contenido? [s/n]: ";
		cin >> opcion;
	  }while(opcion!='n');
	}


	void pedir_tarea() 
	{
	  ofstream arch;
	  ifstream arch1;
	  char opcion;
	  string tarea, tarea1;
	  bool encontrado;
	  system("clear");

	  do{
		  encontrado=false;
		  switch (asig){

		  case 1:
			  arch.open("TareasLengua.txt", ios::app);
			  arch1.open("TareasLengua.txt", ios::in);
			  cout << "Introduzca la tarea a subir: ";
			  cin>> tarea;

			  while (!arch1.eof() && ( encontrado != true))
			  {
					getline(arch1, tarea1, '\n');
					if (tarea1==tarea)
					  encontrado=true;
			  }

			  if (encontrado ==true)
				cout << "Tarea ya existente" << endl;
			  
			  else{
				arch << tarea;
				arch << endl;
				cout << "Tarea subida con éxito" << endl;
			  }
			  arch.close();
			  arch1.close();
			break;

		  case 2:
			  arch.open("TareasMatemáticas.txt", ios::app);
			  arch1.open("TareasMatemáticas.txt", ios::in);
			  cout << "Introduzca la tarea a subir: ";
			  cin>> tarea;

			  while (!arch1.eof() && ( encontrado != true))
			  {
				getline(arch1, tarea1, '\n');
				if (tarea1==tarea)
				  encontrado=true;
			  }

			  if (encontrado ==true)
				cout << "Tarea ya existente" << endl;

			  else{
				arch << tarea;
				arch << endl;
				cout << "Tarea subida con éxito" << endl;
			  }
			  arch.close();
			  arch1.close();
			  break;

		  case 3:
			  arch.open("TareasInformática.txt", ios::app);
			  arch1.open("TareasInformática.txt", ios::in);
			  cout << "Introduzca la tarea a subir: ";
			  cin>> tarea;

			  while (!arch1.eof() && ( encontrado != true))
			  {
				getline(arch1, tarea1, '\n');
				if (tarea1==tarea)
				  encontrado=true;
			  }

			  if (encontrado ==true)
				cout << "Tarea ya existente" << endl;
			  
			  else{
				arch << tarea;
				arch << endl;
				cout << "Tarea subida con éxito" << endl;
			  }
			  arch.close();
			  arch1.close();
			  break;

		  default:
			  break;
		  }

		arch.close();
		cout << "¿Desea subir más tareas? [s/n]: ";
		cin >> opcion;
	  }while(opcion!='n');
	}


	 void subir_cuestionario()
	 {
	  ofstream arch;
	  ifstream arch1;
	  char opcion;
	  string tarea, tarea1;
	  bool encontrado;
	  system("clear");

	  do{
		  encontrado=false;
		  switch (asig){
		  case 1:
			  arch.open("CuestionariosLengua.txt", ios::app);
			  arch1.open("CuestionariosLengua.txt", ios::in);
			  cout << "Introduzca el cuestionario a subir: ";
			  cin>> tarea;

			  while (!arch1.eof() && ( encontrado != true))
			  {
				getline(arch1, tarea1, '\n');
				if (tarea1==tarea)
				  encontrado=true;
			  }

			  if (encontrado ==true)
				cout << "Cuestionario ya existente" << endl;
			  
			  else{
				arch << tarea;
				arch << endl;
				cout << "Cuestionario subido con éxito" << endl;
			  }
			  arch.close();
			  arch1.close();
			break;

		  case 2:
			  arch.open("CuestionariosMatemáticas.txt", ios::app);
			  arch1.open("CuestionariosMatemáticas.txt", ios::in);
			  cout << "Introduzca el cuestionario a subir: ";
			  cin>> tarea;

			  while (!arch1.eof() && ( encontrado != true))
			  {
				getline(arch1, tarea1, '\n');
				if (tarea1==tarea)
				  encontrado=true;
			  }

			  if (encontrado ==true)
				cout << "Cuestionario ya existente" << endl;
			  
			  else{
				arch << tarea;
				arch << endl;
				cout << "Cuestionario subido con éxito" << endl;
			  }
			  arch.close();
			  arch1.close();
			  break;

		  case 3:
			  arch.open("CuestionariosInformática.txt", ios::app);
			  arch1.open("CuestionariosInformática.txt", ios::in);
			  cout << "Introduzca el cuestionario a subir: ";
			  cin>> tarea;

			  while (!arch1.eof() && ( encontrado != true))
			  {
				getline(arch1, tarea1, '\n');
				if (tarea1==tarea)
				  encontrado=true;
			  }

			  if (encontrado ==true)
				cout << "Cuestionario ya existente" << endl;
			  
			  else{
				arch << tarea;
				arch << endl;
				cout << "Cuestionario subido con éxito" << endl;
			  }
			  arch.close();
			  arch1.close();
			  break;

		  default:
			  break;
		  }
		arch.close();
		cout << "¿Desea subir más cuestionarios? [s/n]: ";
		cin >> opcion;
	  }while(opcion!='n');
	 }
	 void ver_notas() {}
	 void poner_notas() {}
	 void chat() {}
};
/**
 *
 *
 *  Autores:         					                   
 *   		Adrián Emilio Padilla Rojas				
 *			Adrián Ruiz Olivero
 *			Adrián Epifanio Rodríguez Hernández 	
 *			David Valverde Gómez					
 *			Jorge Quintana García					
 *			Kabir Chetwani Kaknani					
 * 			Milton Daniel Rivas Quintero			
 *			Diego Díaz Fernández
 *								
 *   Fecha: 23/05/2019
 *
 *
**/