//Encabezados
#include "Librerias.hpp"
#include "Espacios de Memoria Universales.hpp"
#include "Algoritmos.hpp"

using namespace std;

int main()
{
	cout << "Buscaminas V2.1" << endl << "---------------" << endl;

	srand((unsigned) time(NULL));

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

ciclo_juego:

	cout << endl;
	mostrar_tablero();
	cout << endl;
	realizar_jugada();
	estadoJ = estado_jugador(cantbombas);


	switch (estadoJ)
	{
	case 0:
	{
		goto ciclo_juego;
	}
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

		for (int i = 1; i <= FIL; i++)
		{
			for (int j = 1; j <= COL; j++)
			{
				cout << setw(2) << tablero[i][j];
			}
			cout << endl;
		}

		break;
	}
	}

	cout << endl;
	system("pause");
	return 0;
}