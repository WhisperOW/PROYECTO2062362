#include <iostream>
#include <string>
using namespace std;

int main() {

	int NumArt{}, opcion, desicion;
	string NomArt, Desc, Genero, Clas, Plat;
	
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
		printf("\nIngrese el numero del articulo\n"); cin >> NumArt; cin.ignore();
		printf("Ingrese el nombre del producto\n"); getline(cin, NomArt);
		printf("Ingrese la descripcion\n"); getline(cin, Desc);
		printf("Ingrese el genero\n"); getline(cin, Genero);
		printf("Ingrese la clasificacion\n"); getline(cin, Clas);
		printf("Ingrese la plataforma del juego\n"); getline(cin, Plat);

		printf("\ndesea dar otro articulo de alta  1.Si  2.No\n");
			cin >> desicion;
			if (desicion == 1)
				return main();
		break;

	case 2:
		break;

	case 3:
		break;

	case 4:
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

}