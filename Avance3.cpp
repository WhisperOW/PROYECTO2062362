#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <locale.h>

using namespace std;

void ALTA();
void MODIFICAR();
void BAJA();
void LISTA();
void ARCHIVO();

struct Tienda {

	int NumArt ,year;
	float sub, iva, total;
	string NomArt, Desc, Genero, Clas, Plat, status;

};

bool rep(int N, int i);
bool año(int F);
int alta;

Tienda* Articulos;

int main() {
	setlocale(LC_CTYPE, "spanish");
	int opc;
	printf("\n\t%cMenú de Opciones%c\n", 16, 17);
	printf("%c1. Alta\n%c2. Modificar\n%c3. Baja\n%c4. Lista\n%c5. Limpiar pantalla\n%c6. Salir\n", 175, 175, 175, 175, 175, 175);
	scanf_s("%d", &opc);

	switch (opc) {

	case 1:
		ALTA();
		return main();
		break;
	case 2:
		MODIFICAR();
		return main();
		break;
	case 3:
		BAJA();
		return main();
		break;
	case 4:
		LISTA();
		return main();
		break;
	case 5:
		system("cls");
		return main();
		break;
	case 6:
		ARCHIVO();
		exit(1);
		break;
	default:
		printf("Ingrese una opción válida\n");
		return main();
		break;
	}



}

void ALTA() {

	printf("\nIngrese el número de registros\n");
	scanf_s("%d", &alta);

	Articulos = new Tienda[alta];

	for (int i = 0; i < alta; i++) {

		int N, F;

		cin.ignore();
		printf("\nIngrese el número de artículo %d\n", i + 1); scanf_s("%d", &N);
		while (rep(N, i))
		{
			printf("Este número ya está en existencia\n");
			printf("Ingrese el número de artículo %d\n", i + 1);
			scanf_s("%d", &N);
		}
		Articulos[i].NumArt = N;
		cin.ignore();
		printf("Ingrese el nombre del producto\n"); getline(cin, Articulos[i].NomArt);
		printf("Ingrese el precio\n"); scanf_s("%f", &Articulos[i].sub);
		cin.ignore();
		Articulos[i].iva = Articulos[i].sub * 0.16;
		Articulos[i].total = Articulos[i].sub + Articulos[i].iva;
		printf("Ingrese el año de lanzamiento\n"); scanf_s("%d", &F);
		while (año(F))
		{
			printf("Año no válido\n");
			printf("Ingrese el año de lanzamiento\n");
			scanf_s("%d", &F);
		}
		Articulos[i].year = F;
		cin.ignore();
		printf("Ingrese la descripción\n"); getline(cin, Articulos[i].Desc);
		printf("Ingrese el género\n"); getline(cin, Articulos[i].Genero);
		printf("Ingrese la clasificación\n"); getline(cin, Articulos[i].Clas);
		printf("Ingrese la plataforma del juego\n"); getline(cin, Articulos[i].Plat);
		Articulos[i].status = "ACTIVO";
	}
}

bool rep(int N, int i) 
{
	for (int j = 0; j < i; j++) 
	{
		if (N == Articulos[i].NumArt)
		{
			return true;
		}
	}
	return false;
}

bool año(int F) 
{
	if (F < 1960 || F>2025) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

void MODIFICAR() {

	int j, op, op2, N, F;
	do
	{
		printf("\nIngrese el número de Artículo a modificar\n");
		scanf_s("%d", &j);
		while (j > alta || j <= 0)
		{
			printf("Número de registro NO válido\n");
			printf("Ingrese el número de Artículo a modificar\n");
			scanf_s("%d", &j);
		}
		j = j - 1;

		for (int i = j; i == j; i++)
		{
			if ((Articulos[i].status == "ELIMINADO"))
			{
				printf("REGISTRO %d ELIMINADO", i + 1);
				printf("Ingrese un registro válido \n");
				op = 1;
			}
			else
			{
				op = 2;
			}
		}
	} while (op == 1);

	printf("Ingrese que desea modificar\n%c1.-Número\n%c2.- Nombre\n%c3.- Precio\n%c4.-Año\n%c5.-Descripción\n%c6.- Género\n%c7.- Clasificación\n%c8.-Plataforma\n", 175, 175, 175, 175, 175, 175, 175, 175);
	cin >> op2;

	switch (op2)
	{
	case 1:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			printf("\nIngrese el nuevo número de artículo %d\n"); scanf_s("%d", &N);
			while (rep(N, i))
			{
				printf("Este número ya está en existencia\n");
				printf("Ingrese el nuevo número de artículo %d\n", i + 1);
				scanf_s("%d", &N);
			}
			Articulos[i].NumArt = N;
		}
		break;
	case 2:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			printf("Ingrese el nuevo nombre");
			getline(cin, Articulos[i].NomArt);
		}
		break;
	case 3:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			printf("Ingrese el nuevo precio\n");
			scanf_s("%d", &Articulos[i].sub);
			Articulos[i].iva = Articulos[i].sub * 0.16;
			Articulos[i].total = Articulos[i].sub + Articulos[i].iva;
		}
		break;
	case 4:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			printf("Ingrese el nuevo año de lanzamiento\n"); scanf_s("%d", &F);
			while (año(F))
			{
				printf("Año no válido\n");
				printf("Ingrese el nuevo año de lanzamiento\n");
				scanf_s("%d", &F);
			}
			Articulos[i].year = F;
		}
		break;
	case 5:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			printf("Ingrese la nueva descripción\n");
			getline(cin, Articulos[i].Desc);
		}
		break;
	case 6:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			printf("Ingrese el nuevo género\n");
			getline(cin, Articulos[i].Genero);
		}
		break;
	case 7:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			printf("Ingrese la nueva clasificación\n");
			getline(cin, Articulos[i].Clas);
		}
		break;
	case 8:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			printf("Ingrese la nueva plataforma\n");
			getline(cin, Articulos[i].Plat);
		}
		break;
	default:
		printf("Ingrese una opción válida\n");
		return MODIFICAR();
		break;
	}

}

void BAJA() {

	int j;
	printf("\nIngrese el registro a dar de baja\n");
	scanf_s("%d", &j);
	while (j > alta || j <= 0) 
	{
		printf("Número de registro NO válido\n");
		printf("Ingrese el registro a dar de baja\n");
		scanf_s("%d", &j);
	}
	j = j - 1;
	for (int i = j; i == j; i++)
	{
		printf("Eliminando registro %d\n", j + 1);
		Articulos[i].status = "ELIMINADO";

	}

}

void LISTA() {

	for (int i = 0; i < alta; i++) {

		if (Articulos[i].status == "ELIMINADO") {

			printf("\nArtículo %d Elimidado\n", i + 1);

		}
		else {
			printf("\tArtículo %d", i + 1);
			printf("\nNúmero de Artículo: %d\n", Articulos[i].NumArt);
			printf("Nombre: %s%c\n", Articulos[i].NomArt.c_str(), 169);
			printf("Subtotal: %f, IVA: %f, Total: %f\n", Articulos[i].sub, Articulos[i].iva, Articulos[i].total);
			printf("Año de lanzamiento: %d\n", Articulos[i].year);
			printf("Descripción: %s\n", Articulos[i].Desc.c_str());
			printf("Género: %s\n", Articulos[i].Genero.c_str());
			printf("Clasificación: %s\n", Articulos[i].Clas.c_str());
			printf("Plataforma: %s\n", Articulos[i].Plat.c_str());
		}
	}

}

void ARCHIVO() {

	ofstream archivo;
	string nombrearchivo;

	nombrearchivo = "altasmatricula.txt";

	archivo.open(nombrearchivo.c_str(), ios::out);

	if (archivo.fail())
	{
		printf("ERROR NO SE PUDO CREAR EL ARCHIVO");
		exit(1);
	}

	archivo << "NUMERO DE ARTICULO" << "\t";
	archivo << "NOMBRE" << "\t";
	archivo << "PRECIO" << "\t";
	archivo << "LANZAMIENTO" << "\t";
	archivo << "DESCRIPCION" << "\t";
	archivo << "CLASIFICACION" << "\t";
	archivo << "PLATAFORMA" << "\t";
	archivo << "STATUS" << "\n";

	for (int i = 0; i < alta; i++)
	{
		if (Articulos[i].status == "ELIMINADO")
		{
			archivo << "Articulo " << i + 1 << "Eliminado\n";
		}
		else
		{
			archivo << Articulos[i].NumArt << "\t" << "\t";
			archivo << Articulos[i].NomArt << "\t" << "\t";
			archivo << Articulos[i].total << "\t" << "\t";
			archivo << Articulos[i].year << "\t" << "\t";
			archivo << Articulos[i].Desc << "\t" << "\t";
			archivo << Articulos[i].Clas << "\t" << "\t";
			archivo << Articulos[i].Plat << "\t" << "\t";
			archivo << Articulos[i].status << "\t" << "\t";
		}
	}


	archivo.close();

}