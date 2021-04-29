//Librerías
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <time.h>
#include <windows.h>

//Variables
int FIL;
int COL;
bool tablero[30][30];
char mascara[30][30];

using namespace std;

//Encabezados
#include "solicitudes.hpp"
#include "controles.hpp"
#include "tablero.hpp"
#include "extra.hpp"

int main()
{
	cout << "Buscaminas V3.0" << endl << "---------------" << endl;

	srand((unsigned)time(NULL));

	FIL = solicitar_filas();
	COL = solicitar_columnas();

	int cantbombas;
	int estadoJ;

	inicializar_matrices();
	cantbombas = solicitar_cant_bombas();

	do
	{
		Sleep(1000);
		minar_tablero(cantbombas);
		Sleep(1000);
		if (control_minado(cantbombas))
		{
			inicializar_matrices();
		}
	} while (control_minado(cantbombas));

	do {
		cout << endl;
		mostrar_tablero();
		cout << endl;
		realizar_jugada();
		estadoJ = estado_jugador(cantbombas);
	} while (estadoJ == 0);

	switch (estadoJ) {
	case 1:
	{
		cout << endl;
		mostrar_tablero();
		cout << endl;
		cout << "Juego terminado" << endl << "Usted gana el juego, Felicidades";
		break;
	}
	case 2:
	{
		cout << endl;
		mostrar_tablero();
		cout << endl;
		cout << "Juego Terminado" << endl << "Usted pierde el juego, Mejor suerte la proxima" << endl;
		cout << "Tablero de Bombas:" << endl;

		for (int i = 1; i <= FIL; i++) {
			for (int j = 1; j <= COL; j++) cout << setw(2) << tablero[i][j];

			cout << endl;
		}

		break;
	}
	}

	cout << endl;
	system("pause");
	return 0;
}
