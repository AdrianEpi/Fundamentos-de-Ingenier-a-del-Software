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
#include <time.h>
/*------------------------------------------------*/


/*----------  DECLARACION DE FUNCIONES  ----------*/
#include "usuarios.h"
#include "campus.h"
/*------------------------------------------------*/



void penalizacion()
{

  cout << "Ha excedido el numero de intentos, debe esperar 30 segundos para volver a intentarlo.\n";

  clock_t espera1;
  espera1 = clock() + 3 * CLOCKS_PER_SEC;
  while (clock() < espera1)
  {
  }
  system("clear");
  clock_t espera2;
  espera2 = clock() + 30 * CLOCKS_PER_SEC;
  while (clock() < espera2)
  {
	cout << "Tiempo restante: ";

	cout << ((clock() - espera2) * -1) / 1000000 << " segundos.\n";
	cout << "\e[A";
	cout << "\e[A";
  }
  system("clear");
}



void tecla()
{
  string tecla;
  cout << "Pulse una tecla para continuar: ";
  cin >> tecla;
}



int main()
{
  int opcion;
  Usuario usu;
  Campus campus;
  string user;
  string passwd;

  int resultado = 0;
  bool correcto_ = false;
  bool antenticado_ = false;
  int num_intentos = 0;

//Menu login
  do
  {
	correcto_ = false;
	system("clear");

	cout << "[1] Registrarse" << endl;
	cout << "[2] Iniciar sesión" << endl;
	cout << "[0] Salir" << endl;
	cin >> opcion;

	system("clear");

	switch (opcion)
	{
	case 1:
	  cout << "----REGISTRO----" << endl;
	  usu.crear_usuario();
	  tecla();
	  antenticado_ = true;
	  break;

	case 2:

	  while (correcto_ == false)
	  {
		cout << "----LOGIN----" << endl;

		cout << "Usuario: ";
		cin >> user;
		cout << "Contraseña: ";
		cin >> passwd;

		resultado = campus.iniciar_sesion(user, passwd, usu);
		tecla();

		if ((resultado == 1) || (resultado == 0))
		  correcto_ = true;

		else
		  correcto_ = false;

		if (num_intentos == 4)
		{

		  system("clear");
		  penalizacion();
		  num_intentos = -1;
		}

		if ((num_intentos >= 0) && (correcto_ == false))
		  cout << "Intentos restantes: " << 4 - num_intentos << "\n\n";

		num_intentos++;
	  }
	  antenticado_ = true;
	  break;

	case 0:

	  cout << "\n\t\tFinalizando ejecución..." << endl;
	  for (int i = 0; i < 500000000; i++) {}
	  cout << "\n\t\tTerminando procesos..." << endl;
	  for (int i = 0; i < 500000000; i++){}

	  cout << "\n\t\tCerrando subrutinas..." << endl;
	  for (int i = 0; i < 500000000; i++){}

	  cout << "\n\t\t----SALIENDO DEL PROGRAMA----" << endl;
	  for (int i = 0; i < 500000000; i++){}

	  system("clear");

	  return 0;
	  break;
	}
  } while (antenticado_ != true);


//Menu "post-login"
  do
  {
	correcto_ = false;
	system("clear");

	cout << "[1] Recordar datos" << endl;
	cout << "[2] Acceder Asignaturas" << endl;
	cout << "[0] Salir" << endl;
	cin >> opcion;

	system("clear");

	switch (opcion)
	{
		case 1:
		  cout << "----MOSTRAR DATOS----" << endl;

		  usu.mostrar_datos();
		  tecla();

		  break;

		case 2:

		  campus.menu_asignaturas(usu);
		  break;

		case 0:

		  cout << "\n\t\tFinalizando ejecución..." << endl;
		  for (int i = 0; i < 500000000; i++){}
		  cout << "\n\t\tTerminando procesos..." << endl;
		  for (int i = 0; i < 500000000; i++){}

		  cout << "\n\t\tCerrando subrutinas..." << endl;
		  for (int i = 0; i < 500000000; i++){}

		  cout << "\n\t\t----SALIENDO DEL PROGRAMA----" << endl;
		  for (int i = 0; i < 500000000; i++){}

		  system("clear");

		  break;
	}

  } while (opcion != 0);
}
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