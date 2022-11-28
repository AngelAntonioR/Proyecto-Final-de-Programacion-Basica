#include<iostream>
#include <string>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <fstream>

using namespace std;


struct informacion 
{
	string nombre_juego, descripcion_juego,genero_juego,clasificacion_juego;
	int año_lanzamiento, precio, precio_impuestos,numero_juego;
	float precio_total;
}informacion[3];

void archivo();

int numero_articulo = 0;
int i = 0;
int articulo_borrado = -1;

int main() 
{
	int opmenu, agregar, modificar;
	cout << "\t\t----------------------------------------------------" << endl;
	cout << "\t\t\tBienvenido a la Tienda de Videojuegos Rataland\t\t" << endl;
	cout << "\t\t----------------------------------------------------" << endl;
	cout << "\t\t 1.Agregar articulo \t\t" << endl;
	cout << "\t\t 2.Modificar videojuego\t\t" << endl;
	cout << "\t\t 3.Eliminar videojuego\t\t" << endl;
	cout << "\t\t 4.Lista de videojuegos\t\t" << endl;
	cout << "\t\t 5.Limpiar pantalla\t\t" << endl;
	cout << "\t\t 6.Salir \t\t" << endl;
	cout << "\t\t----------------------------------------------------" << endl;
	cin >> opmenu;
	cin.ignore();

	switch (opmenu)
	{
	    case 1:
			    
				cout << "Articulo numero:" << numero_articulo + 1 << endl;
			    	
				cout << "Nombre del videojuego?" << endl;
				getline(cin, informacion[numero_articulo].nombre_juego);
				

				cout << "Descripcion del videojuego?" << endl;
				getline(cin, informacion[numero_articulo].descripcion_juego);
				

				cout << "Genero del videojuego?" << endl;
				getline(cin, informacion[numero_articulo].genero_juego);
				

				cout << "Clasificacion del videojuego?" << endl;
				getline(cin, informacion[numero_articulo].clasificacion_juego);

				cout << "Cual es el año de lanzamiento?" << endl;
				cin>> informacion[numero_articulo].año_lanzamiento;
		
				cout << "\tCual es el precio?\t" << endl;
				cin >> informacion[numero_articulo].precio;
				cin.ignore();

				informacion[numero_articulo].precio_impuestos = (informacion[numero_articulo].precio * 0.16);
				informacion[numero_articulo].precio_total = (informacion[numero_articulo].precio + informacion[numero_articulo].precio_impuestos);
				cout << "\tSu IVA es de\t" << informacion[numero_articulo].precio_impuestos << endl;
				cout << "\tEl precio total es de\t" << informacion[numero_articulo].precio_total << endl;
				numero_articulo = numero_articulo + 1;
			
		break;
		case 2: 
		{
			cout << "----------------------------------------------------" << endl;
			cout << "Modificando videojuego\t\t" << endl;
			cout << "----------------------------------------------------" << endl;
			cout << "Que numero de articulo quiere modificar?" << endl;
			cin >> numero_articulo;
			numero_articulo = numero_articulo - 1;
			cout << "Eliga la opcion que desea modificar?" << endl;
			cout << "1.Nombre del videojuego" << endl;
			cout << "2.Descripcion:" << endl;
			cout << "3.Genero:" << endl;
			cout << "4.Clasificacion:" << endl;
			cout << "5.Año: " << endl;
			cout << "6.Precio:" << endl;
			cin >> modificar;
			cin.ignore();
			switch (modificar)
			{
			case 1:
				cout << "Renombrar videojuego:" << endl;
				getline(cin, informacion[numero_articulo].nombre_juego);
				break;
			case 2:
				cout << "Nueva Descripcion:" << endl;
				getline(cin, informacion[numero_articulo].descripcion_juego);
				break;
			case 3:
				cout << "Nuevo Genero:" << endl;
				getline(cin, informacion[numero_articulo].genero_juego);
				break;
			case 4:
				cout << "Nueva Clasificacion:" << endl;
				getline(cin, informacion[numero_articulo].clasificacion_juego);
				break;
			case 5:
				cout << "Nuevo Año de Lanzamiento:" << endl;
				cin >> informacion[numero_articulo].año_lanzamiento;
				break;
			case 6:
				cout << "Nuevo Precio:" << endl;
				cin >> informacion[numero_articulo].precio;
				informacion[numero_articulo].precio_impuestos = (informacion[numero_articulo].precio * 0.16);
				informacion[numero_articulo].precio_total = (informacion[numero_articulo].precio + informacion[numero_articulo].precio_impuestos);
				break;
			}
		}
		break;

		case 3:
			cout << "Cual es el numero del videojuego que desea eliminar?" << endl;
			cin >> numero_articulo;
			numero_articulo = numero_articulo - 1;
			informacion[numero_articulo].nombre_juego = "";
			informacion[numero_articulo].descripcion_juego = "";
			informacion[numero_articulo].genero_juego = "";
			informacion[numero_articulo].clasificacion_juego = "";
			informacion[numero_articulo].año_lanzamiento = 0;
			informacion[numero_articulo].precio = 0;
			informacion[numero_articulo].precio_impuestos = 0;
			informacion[numero_articulo].precio_total= 0;
			cout << "Videojuego eliminado" << endl;
			break;

		case 4:
			cout << "----------------------------------------------------" << endl;
			cout << "Lista de Aticulos\t\t" << endl;
			for (i = 0; i < 3; i++)
			{
				cout << "----------------------------------------------------" << endl;
				cout << "Nombre del videojuego:"<< informacion[i].nombre_juego << endl;
				cout << "Descripcion:"<<informacion[i].descripcion_juego << endl;
				cout << "Genero :"<<informacion[i].genero_juego << endl;
				cout << "Clasificacion:"<<informacion[i].clasificacion_juego << endl;
				cout << "Año de lanzamiento:"<<informacion[i].año_lanzamiento << endl;
				cout << "Precio:"<<informacion[i].precio << endl;
				cout << "Inpuesto(IVA):"<<informacion[i].precio_impuestos << endl;
				cout << "Precio Total:"<<informacion[i].precio_total << endl;
				if (i == 2) {
					cout << "----------------------------------------------------" << endl;
				}
			}
			break;
		case 5:
			system("cls");
			break;
		case 6:
			archivo();
			system("cls");
			cout << endl << "\t\t\t\tSaliendo del sistema..........";
			exit(0);
			break;

		default:
			system("cls");
			cout << "Eliga una opcion correcta" << endl;
			break;
	}
	if (opmenu != 6)
	{
		return main();
	}
}

void archivo()
{
	ofstream almacenar;
	string juegos;
	juegos = "lista_videojuegos";
	almacenar.open(juegos.c_str(), ios::out);
	if (almacenar.fail()) 
	{
		cout << "No se pudo crear el archivo" << endl;
		exit(1);
	}
	for (int i = 0; i < 3; i++)
	{
		almacenar << "Nombre del videojuego:" << informacion[1].nombre_juego << endl;
		almacenar << "Descripcion:" << informacion[1].descripcion_juego << endl;
		almacenar << "Genero: " << informacion[1].genero_juego << endl;
		almacenar << "Clasificacion:"<< informacion[1].clasificacion_juego << endl;
		almacenar << "Año de lanzamiento:" << informacion[1].año_lanzamiento << endl;
		almacenar << "Precio:" << informacion[1].precio << endl;
	}
	almacenar.close();
}