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

#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

using namespace std;

/*------------------------------------------------*/


class Usuario
{
private:
	string nombre_;		// Este atributo se encarga de almacenar el nombre del usuario
	string contrasena_; // Este atributo se encarga de almacenar la contrase�a del usuario
	bool privilegio_;   // Este atributo es para poder diferenciar a un alumno de un profesor profesor=true alumno=false
	vector<int> asignaturas;

public:

	Usuario()
	{
		nombre_ = "";
		contrasena_ = "";
		privilegio_ = false;
	}

	Usuario(string nombre, bool privilegio, string contrasena)
	{
		nombre_ = nombre;
		contrasena_ = contrasena;
		privilegio_ = privilegio;
	}

	void crear_usuario(void)
	{
		int sz;
		string asig;
		cout << "Por favor, introduzca su nombre :" << "\n";
		do
		{
			cin >> nombre_;
			if (nombre_ == "")
				cout << "Por favor, introduzca un nombre" << "\n";
			
		} while (nombre_ == "");

		cout << "Ahora introduzca la contraseña que desea emplear, debe ser como minimo de 6 caracteres" << "\n";
		do
		{
			cin >> contrasena_;
			if (contrasena_.size() < 6)
				cout << "Por favor, introduzca una contraseña valida" << "\n";

		} while (contrasena_.size() < 6);

		cout << "¿Es usted \"profesor\" o \"alumno\"?" << "\n";
		string ser;
		do
		{
			cin >> ser;
			if (ser == "profesor")
				privilegio_ = true;

			else if (ser == "alumno")
				privilegio_ = false;
			
			else
				cout << "Por favor, indique correctamente qué tipo de usuario es" << "\n";
			
		} while (ser != "profesor" && ser != "alumno");

		ifstream fich1;
		ofstream fich2;
		fich1.open("passwd.txt", ios::in);

		if (fich1.fail())
		{
			fich2.open ("passwd.txt");
			fich1.open("passwd.txt", ios::in);
			fich2.close();
		}

			bool encontrado_ = false;
			bool pass_corr_ = false;
			string usu;
			string pass;

			while (!fich1.eof() && ((pass_corr_ && encontrado_) != true))
			{
				getline(fich1, usu, '\n');
				getline(fich1, pass, '\n');

				if (nombre_ == usu)
				{
					if (contrasena_ == pass)
						pass_corr_ = true;
					
					else
						pass_corr_ = false;
					
					encontrado_ = true;
				}
				else
					encontrado_ = false;
				
			}

			if ((encontrado_ == true) && (pass_corr_ == true))
				cout << "Usuario ya existente" << endl;
			

			else if ((encontrado_) && (pass_corr_ == false))
				cout << "Usuario ya registrado con otra contraseña\n";
			
			else
			{
				cout << "Introduzca el número de asignaturas matriculadas [1-3]: ";
                do{
					cin >> sz;
 		        }while(sz< 0 || sz>3 );

				int cont=0;
				asignaturas.clear();
				while (sz != cont)
				{
					cout << "Asignatura " << cont + 1 << ":";
					cin >> asig;
					if (asig == "Lengua")
					{
						asignaturas.push_back(1);
  						cont++;
					}
					else if (asig == "Matemáticas")
					{
						asignaturas.push_back(2);
						cont++;
					}
					else if (asig == "Informática")
					{
						asignaturas.push_back(3);
						cont++;
					}
					else
						cout << "Asignatura no reconocida en el sistema" << endl;
				}

				escribir_fichero(/*nombre_, contrasena_,*/ ser);
				cout << "\nEl registro ha sido completado con EXITO \n\n";
			}

			fich1.close();
	}

	void escribir_fichero(/*string usu, string pass,*/ string ser)
	{
		ofstream fich2;
		fich2.open("passwd.txt", ios::app);
		fich2 << nombre_ << endl;
		fich2 << contrasena_ << endl;
		fich2 << ser << endl;
		fich2 << asignaturas.size() << endl;
		for (int i = 0; i < asignaturas.size(); i++)
		{
			if (asignaturas[i] == 1)
				fich2 << "Lengua" << endl;
			else if (asignaturas[i] == 2)
				fich2 << "Matemáticas" << endl;
			else if (asignaturas[i] == 3)
				fich2 << "Informática" << endl;
		}
	}

	void mostrar_datos(void)
	{
		cout << "El nombre del usuario es: " << nombre_ << "\n\n";
		cout << "Su contraseña es: " << contrasena_ << "\n\n";
		cout << "Su nivel de privilegio es de: ";
		if (privilegio_ == true)
			cout << "Profesor" << "\n\n";

		else
			cout << "Alumno" << "\n\n";

		cout << "Sus asignaturas matriculadas son: ";

		for (int i = 0; i < asignaturas.size(); i++)
		{
			if (asignaturas[i] == 1)
				cout << "Lengua";
			else if (asignaturas[i] == 2)
				cout << "Matemáticas";
			else if (asignaturas[i] == 3)
				cout << "Informática";
                if (asignaturas.size()!=1 && asignaturas.size()-1!=i)
					cout << ", ";
					
		}
		cout << "\n\n";
	}

	void set_nombre(string usu)
	{
		nombre_ = usu;
	}
	void set_pass(string pass)
	{
		contrasena_ = pass;
	}
	void set_privilegio(string x)
	{

		if (x == "profesor")
			privilegio_ = true;
		
		else if (x == "alumno")
			privilegio_ = false;
		
	}

	bool get_privilegio()
	{
		return privilegio_;
	}

	void add_asig(int x)
	{
		asignaturas.push_back(x);
	}

	bool buscar_asig(int x)
	{
		for (int i = 0; i < asignaturas.size(); i++)
		{
			if (asignaturas[i] == x)
				return true;
		}
		return false;
	}

	void clear_asig()
	{
		asignaturas.clear();
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