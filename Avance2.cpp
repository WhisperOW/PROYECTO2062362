#include <iostream>
#include <string>
#include <string.h>
using namespace std;

struct Articulos {

	int NumArt{}, precio, IVA, PF;
	string NomArt, Desc, Genero, Clas, Plat;

};

int main() {

	Articulos datos[3];
	int opcion;
	do
	{
	
	printf("\t **Menu de Opciones**\n");
	printf("1. Alta de Articulos\n");
	printf("2. Modificacion de Articulos\n");
	printf("3. Baja de Articulos\n");
	printf("4. Lista de Articulos\n");
	printf("5. Limpiar Pantalla\n");
	printf("6. Salir\n");
	cin >> opcion;


		switch (opcion) {

		case 1:
			for (int i = 0; i <= 2; i++) {
				printf("\nIngrese el numero del articulo\n"); scanf_s("%d", &datos[i].NumArt);
				cin.ignore();
				printf("Ingrese el nombre del producto\n"); getline(cin, datos[i].NomArt);
				printf("Ingrese el precio\n"); scanf_s("%d", &datos[i].precio);
				cin.ignore();
				datos[i].IVA = datos[i].precio * 0.16;
				datos[i].PF = datos[i].IVA + datos[i].precio;
				printf("Ingrese la descripcion\n"); getline(cin, datos[i].Desc);
				printf("Ingrese el genero\n"); getline(cin, datos[i].Genero);
				printf("Ingrese la clasificacion\n"); getline(cin, datos[i].Clas);
				printf("Ingrese la plataforma del juego\n"); getline(cin, datos[i].Plat);
			}

			break;

		case 2:
			break;

		case 3:
			break;

		case 4:

			for (int i = 0; i <= 2; i++) {

				printf("\nNumero de Articulo: %d\n", datos[i].NumArt);
				printf("Nombre: %s\n", datos[i].NomArt.c_str());
				printf("Cuesta: %d, con un precio original de: %d, y IVA de: %d\n", datos[i].PF, datos[i].precio, datos[i].IVA);
				printf("Descripcion: %s\n", datos[i].Desc.c_str());
				printf("Genero: %s\n", datos[i].Genero.c_str());
				printf("Clasificacion: %s\n", datos[i].Clas.c_str());
				printf("Plataforma: %s\n", datos[i].Plat.c_str());

			}



			break;

		case 5:
			system("cls");
			break;

		case 6:
			exit(1);
			break;

		default:
			printf("opcion invalida\n");
			return main();
		}

	} while (opcion != 6);

}