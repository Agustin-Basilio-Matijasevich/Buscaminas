#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX = 30;
int FIL;
int COL;

void mostrar_tablero(char mascara[MAX][MAX])
{
	for (int i = 1; i <= FIL; i++)
	{
		for (int j = 1; j <= COL; j++)
		{
			cout << setw(2) << mascara[i][j];
		}
		cout << endl;
	}
}

void minar_tablero(int tablero[MAX][MAX], int cantbombas)
{
	cout << "Colocando bombas..." << endl;

	int alfil, alcol;

	for (int i = 0; i < cantbombas; i++)
	{
		do
		{
			Sleep(10);
			alfil = rand() % (FIL)+1;
			Sleep(10);
			alcol = rand() % (COL)+1;
			Sleep(10);
		} while (tablero[alfil][alcol] == 1);

		if (tablero[alfil][alcol] == 0)
		{
			tablero[alfil][alcol] = 1;
		}
		else
		{
			i--;
		}
	}
}

bool control_minado(int tablero[MAX][MAX], int cantbombas)
{
	int count = 0;

	for (int i = 0; i <= FIL; i++)
	{
		for (int j = 0; j <= COL; j++)
		{
			if (tablero[i][j] == 1)
			{
				count++;
			}
		}
	}

	if (count == cantbombas)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void realizar_jugada(int tablero[MAX][MAX], char mascara[MAX][MAX])
{
	int i, j;

jugada:

	fflush(stdin);

	cout << "Ingrese fila y columna separados por un espacio: ";
	cin >> i >> j;


	if (i<1 || i>FIL)
	{
		cout << "Posicion de fila inexistente, intente nuevamente" << endl;
		goto jugada;
	}

	if (j<1 || j>COL)
	{
		cout << "Posicion de columna inexistente, intente nuevamente" << endl;
		goto jugada;
	}

	if (mascara[i][j] == '#')
	{
		if (tablero[i][j] == 1)
		{
			mascara[i][j] = '*';
		}
		else
		{
			int peligro = 0;
			peligro += tablero[i][j - 1];
			peligro += tablero[i - 1][j - 1];
			peligro += tablero[i - 1][j];
			peligro += tablero[i - 1][j + 1];
			peligro += tablero[i][j + 1];
			peligro += tablero[i + 1][j + 1];
			peligro += tablero[i + 1][j];
			peligro += tablero[i + 1][j - 1];

			if (peligro == 0)
			{
				mascara[i][j] = '_';
			}
			else if (peligro == 1)
			{
				mascara[i][j] = '1';
			}
			else if (peligro == 2)
			{
				mascara[i][j] = '2';
			}
			else if (peligro == 3)
			{
				mascara[i][j] = '3';
			}
			else if (peligro == 4)
			{
				mascara[i][j] = '4';
			}
			else if (peligro == 5)
			{
				mascara[i][j] = '5';
			}
			else if (peligro == 6)
			{
				mascara[i][j] = '6';
			}
			else if (peligro == 7)
			{
				mascara[i][j] = '7';
			}
			else if (peligro == 8)
			{
				mascara[i][j] = '8';
			}
		}
	}
	else
	{
		cout << "La posicion fue selecionada anteriormente, por favor seleccione otra" << endl;
		goto jugada;
	}
}

int estado_jugador(char mascara[MAX][MAX], int cantbombas)
{
	int count = 0;

	for (int i = 0; i <= FIL; i++)
	{
		for (int j = 0; j <= COL; j++)
		{
			if (mascara[i][j] == '*')
			{
				return 2;
			}
			else if (mascara[i][j] != '#')
			{
				count++;
			}
		}
	}

	if (count == (FIL * COL - cantbombas))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void inicializar_matrices(int tablero[MAX][MAX], char mascara[MAX][MAX])
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			tablero[i][j] = 0;
			mascara[i][j] = '#';
		}
	}
}

int solicitar_cant_bombas()
{
	int count = 0;
	int cantbombas;

	do
	{
		fflush(stdin);

		if (count == 0)
		{
			cout << "Ingrese la cantidad de bombas: ";
			cin >> cantbombas;
		}
		else
		{
			cout << "El valor ingresado es erroneo, por favor ingrese un valor entre " << 0 << " y " << FIL * COL << " sin incluir los mismos: ";
			cin >> cantbombas;
		}

		count++;
	} while (cantbombas <= 0 || cantbombas >= FIL * COL);

	return cantbombas;
}

int solicitar_filas()
{
	int filas;
	int count = 0;

	do
	{
		fflush(stdin);

		if (count > 0)
		{
			cout << "El numero ingresado es erroneo, intente nuevamente" << endl;
		}

		cout << "Ingrese la cantidad de filas para el tablero (MAX=" << 25 << "), (MIN=2): ";
		cin >> filas;

		count++;

	} while (filas < 2 || filas>25);

	return filas;
}

int solicitar_columnas()
{
	int columnas;
	int count = 0;

	do
	{
		fflush(stdin);

		if (count > 0)
		{
			cout << "El numero ingresado es erroneo, intente nuevamente" << endl;
		}

		cout << "Ingrese la cantidad de columnas para el tablero (MAX=" << 25 << "), (MIN=2): ";
		cin >> columnas;

		count++;

	} while (columnas < 2 || columnas>25);

	return columnas;
}

int main()
{
	cout << "Buscaminas V2.1" << endl << "---------------" << endl;

	srand(time(NULL));

	FIL = solicitar_filas();
	COL = solicitar_columnas();

	int tablero[MAX][MAX];
	int cantbombas;
	int estadoJ;
	char mascara[MAX][MAX];

	inicializar_matrices(tablero, mascara);
	cantbombas = solicitar_cant_bombas();

	do
	{
		Sleep(1000);
		minar_tablero(tablero, cantbombas);
		Sleep(1000);
		if (control_minado(tablero, cantbombas))
		{
			inicializar_matrices(tablero, mascara);
		}
	} while (control_minado(tablero, cantbombas));

ciclo_juego:

	cout << endl;
	mostrar_tablero(mascara);
	cout << endl;
	realizar_jugada(tablero, mascara);
	estadoJ = estado_jugador(mascara, cantbombas);


	switch (estadoJ)
	{
	case 0:
	{
		goto ciclo_juego;
	}
	case 1:
	{
		cout << endl;
		mostrar_tablero(mascara);
		cout << endl;
		cout << "Juego terminado" << endl << "Usted gana el juego, Felicidades";
		break;
	}
	case 2:
	{
		cout << endl;
		mostrar_tablero(mascara);
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
