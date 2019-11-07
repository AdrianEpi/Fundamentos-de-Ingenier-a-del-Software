/*===============================================================================
=================================================================================

    =               Proyecto:      Campus Virtual                           =
    =               Archivo:       main.cpp                                 =
    =																		=
    =               Autores:         					                    =
    =            				Adrián Emilio Padilla Rojas					=
	=							Adrián Ruiz Olivero							=
	=							Adrián Epifanio Rodríguez Hernández 		=
	=							David Valverde Gómez						=
	=							Jorge Quintana García						=
	=							Kabir Chetwani Kaknani						=
	=							Milton Daniel Rivas Quintero				=
	=							Diego Díaz Fernández						=
	=																		=
    =               Fecha:         23/05/2019                            	=
    =               Asignatura:    Fundamentos de ingeniería del software   =
    =               Lenguaje:      C++                                   	= 

=================================================================================          
===============================================================================*/

/*----------  DECLARACION DE LIBRERIAS  ----------*/
#pragma once

#include <set>
#include <fstream>
#include <cstdio>
#include <iostream>
#include <cstring>
/*------------------------------------------------*/


/*----------  DECLARACION DE FUNCIONES  ----------*/
#include "usuarios.h"
#include "asignatura.h"
/*------------------------------------------------*/



class Campus
{

private:
	//set<Asignatura> asignaturas_;
	set<Usuario> alumnado_;

public:
	Campus(){}

	int iniciar_sesion(string usu_, string pass_, Usuario &alu)
	{
		ifstream fich1;
		fich1.open("passwd.txt", ios::in);
		if (fich1.fail())
			cout << "No se pudo leer del fichero de datos\n";

		else
		{

			bool encontrado_ = false;
			bool pass_corr_ = false;
			string usu;
			string pass;
			string privilegio;
			string size;
			int sz;
			string asig;

			while (!fich1.eof() && ((pass_corr_ && encontrado_) != true))
			{

				getline(fich1, usu, '\n');
				getline(fich1, pass, '\n');
				getline(fich1, privilegio, '\n');

				alu.clear_asig();

				getline(fich1, size, '\n');
				sz = stoi(size);
				for (int i = 0; i < sz; i++)
				{
					getline(fich1, asig, '\n');
					if (asig == "Lengua")
						alu.add_asig(1);

					else if (asig == "Matemáticas")
						alu.add_asig(2);

					else if (asig == "Informática")
						alu.add_asig(3);

					else
						cout << "Asignatura no reconocida" << endl;
				}

				if (usu_ == usu)
				{

					if (pass_ == pass)
						pass_corr_ = true;

					else
						pass_corr_ = false;

					encontrado_ = true;
				}
				else
					encontrado_ = false;

			}

			if ((encontrado_ == true) && (pass_corr_ == true))
			{
				cout << "Sesión iniciada con éxito" << endl;

				alu.set_nombre(usu);
				alu.set_pass(pass);
				alu.set_privilegio(privilegio);

				if (privilegio == "alumno")
					return 0;

				else if (privilegio == "profesor")
					return 1;

			}
			else if (encontrado_ == false)
			{
				cout << "Usuario no registrado en el sistema.\n";
				return 2;
			}
			else if (pass_corr_ == false)
			{
				cout << "Contraseña incorrecta.\n";
				return 2;
			}

			fich1.close();
		}
	}



	void menu_asignaturas(Usuario & alu)
	{

		int asig;
		int opcion;
		bool salir = false;
		bool salir2 = false;
		string tecla;

		Asignatura lengua(1);
		Asignatura mates(2);
		Asignatura informatica(3);

		while (!salir)
		{

			salir2 = false;

			system("clear");

			cout << "----ACCESO ASIGNATURA----" << endl;

			cout << "[1] Lengua" << endl;
			cout << "[2] Matemáticas" << endl;
			cout << "[3] Informática" << endl;
			cout << "[0] Salir" << endl;
			cin >> asig;

			system("clear");

			switch (asig)
			{

			case 1:

				if (alu.buscar_asig(asig))
				{

					while (!salir2)
					{
						cout << "----LENGUA----" << endl;

						switch (alu.get_privilegio())
						{

						case true:

							cout << "[1] Subir contenido" << endl;
							cout << "[2] Pedir tarea" << endl;
							cout << "[3] Subir cuestionario" << endl;
							cout << "[4] Calificaciones" << endl;
							cout << "[5] Chat" << endl;
							cout << "[0] Salir" << endl;

							cin >> opcion;

							switch (opcion)
							{

							case 1:
								cout << "----SUBIR CONTENIDO----" << endl;
								lengua.subir_contenido();
								break;

							case 2:
								cout << "----PEDIR TAREA----" << endl;
								lengua.pedir_tarea();
								break;


							case 3:
								cout << "----SUBIR CUESTIONARIO----" << endl;
								lengua.subir_cuestionario();
								break;
							case 4:
								cout << "----CALIFICACIONES----" << endl;
								break;

							case 5:
								cout << "----CHAT----" << endl;
								break;

							case 0:
								salir2 = true;
								break;
							}
							break;

						case false:

							cout << "[1] Descargar contenido" << endl;
							cout << "[2] Entregar tarea" << endl;
							cout << "[3] Calificaciones" << endl;
							cout << "[4] Resolver cuestionario" << endl;
							cout << "[5] Chat" << endl;
							cout << "[0] Salir" << endl;

							cin >> opcion;

							switch (opcion)
							{

							case 1:
								cout << "----DESCARGAR CONTENIDO----" << endl;
								lengua.descargar_contenido();
								break;

							case 2:
								cout << "----ENTREGAR TAREA----" << endl;
								lengua.entregar_tarea();
								break;

							case 3:
								cout << "----CALIFICACIONES----" << endl;
								break;

							case 4:
								cout << "----RESOLVER CUESTIONARIO----" << endl;
								lengua.entregar_cuestionario();
								break;

							case 5:
								cout << "----CHAT----" << endl;
								break;

							case 0:
								salir2 = true;
								break;
							}
							break;
						}
					}
				}

				else
				{
					cout << "Asignatura no matriculada" << endl;
					cout << "Pulse una tecla: ";
					cin >> tecla;
				}

				break;

			case 2:

				if (alu.buscar_asig(asig))
				{

					while (!salir2)
					{
						cout << "----MATEMÁTICAS----" << endl;

						switch (alu.get_privilegio())
						{

						case true:

							cout << "[1] Subir contenido" << endl;
							cout << "[2] Pedir tarea" << endl;
							cout << "[3] Subir cuestionario" << endl;
							cout << "[4] Calificaciones" << endl;
							cout << "[5] Chat" << endl;
							cout << "[0] Salir" << endl;

							cin >> opcion;

							switch (opcion)
							{

							case 1:
								cout << "----SUBIR CONTENIDO----" << endl;
								mates.subir_contenido();
								break;

							case 2:
								cout << "----PEDIR TAREA----" << endl;
								mates.pedir_tarea();
								break;

							case 3:
								cout << "----SUBIR CUESTIONARIO----" << endl;
								mates.subir_cuestionario();
								break;
							case 4:
								cout << "----CALIFICACIONES----" << endl;
								break;

							case 5:
								cout << "----CHAT----" << endl;
								break;

							case 0:
								salir2 = true;
								break;
							}
							break;

						case false:

							cout << "[1] Descargar contenido" << endl;
							cout << "[2] Entregar tarea" << endl;
							cout << "[3] Calificaciones" << endl;
							cout << "[4] Resolver cuestionario" << endl;
							cout << "[5] Chat" << endl;
							cout << "[0] Salir" << endl;
							cin >> opcion;

							switch (opcion)
							{

							case 1:
								cout << "----DESCARGAR CONTENIDO----" << endl;
								mates.descargar_contenido();
								break;

							case 2:
								cout << "----ENTREGAR TAREA----" << endl;
								mates.entregar_tarea();
								break;

							case 3:
								cout << "----CALIFICACIONES----" << endl;
								break;

							case 4:
								cout << "----RESOLVER CUESTIONARIO----" << endl;
								mates.entregar_cuestionario();
								break;

							case 5:
								cout << "----CHAT----" << endl;

								break;

							case 0:
								salir2 = true;
								break;
							}
							break;
						}
					}
				}

				else
				{
					cout << "Asignatura no matriculada" << endl;
					cout << "Pulse una tecla: ";
					cin >> tecla;
				}

				break;

			case 3:

				if (alu.buscar_asig(asig))
				{

					while (!salir2)
					{
						cout << "----INFORMÁTICA----" << endl;

						switch (alu.get_privilegio())
						{

						case true:

							cout << "[1] Subir contenido" << endl;
							cout << "[2] Pedir tarea" << endl;
							cout << "[3] Subir cuestionario" << endl;
							cout << "[4] Calificaciones" << endl;
							cout << "[5] Chat" << endl;
							cout << "[0] Salir" << endl;

							cin >> opcion;

							switch (opcion)
							{

							case 1:
								cout << "----SUBIR CONTENIDO----" << endl;
								informatica.subir_contenido();
								break;

							case 2:
								cout << "----PEDIR TAREA----" << endl;
								informatica.pedir_tarea();
								break;

							case 3:
								cout << "----SUBIR CUESTIONARIO----" << endl;
								informatica.subir_cuestionario();
								break;
							case 4:
								cout << "----CALIFICACIONES----" << endl;
								break;

							case 5:
								cout << "----CHAT----" << endl;
								break;

							case 0:
								salir2 = true;
								break;
							}
							break;

						case false:

							cout << "[1] Descargar contenido" << endl;
							cout << "[2] Entregar tarea" << endl;
							cout << "[3] Calificaciones" << endl;
							cout << "[4] Resolver cuestionario" << endl;
							cout << "[5] Chat" << endl;
							cout << "[0] Salir" << endl;

							cin >> opcion;

							switch (opcion)
							{

							case 1:
								cout << "----DESCARGAR CONTENIDO----" << endl;
								informatica.descargar_contenido();
								break;

							case 2:
								cout << "----ENTREGAR TAREA----" << endl;
								informatica.entregar_tarea();
								break;

							case 3:
								cout << "----CALIFICACIONES----" << endl;
								break;

							case 4:
								cout << "----RESOLVER CUESTIONARIO----" << endl;
								informatica.entregar_cuestionario();
								break;

							case 5:
								cout << "----CHAT----" << endl;
								break;

							case 0:
								salir2 = true;
								break;
							}
							break;
						}
					}
				}

				else
				{
					cout << "Asignatura no matriculada" << endl;
					cout << "Pulse una tecla: ";
					cin >> tecla;
				}

				break;

			case 0:
				salir = true;
				break;
			}
		}
	}
	

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