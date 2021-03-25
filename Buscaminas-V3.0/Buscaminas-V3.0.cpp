#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX = 30;
int FIL;
int COL;
int tablero[MAX][MAX];
char mascara[MAX][MAX];


void mostrar_tablero()
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

void minar_tablero(int cantbombas)
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

bool control_minado(int cantbombas)
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

int Control_Peligro(int i, int j)
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
		return peligro;
	}
	else if (peligro == 1)
	{
		mascara[i][j] = '1';
		return peligro;
	}
	else if (peligro == 2)
	{
		mascara[i][j] = '2';
		return peligro;
	}
	else if (peligro == 3)
	{
		mascara[i][j] = '3';
		return peligro;
	}
	else if (peligro == 4)
	{
		mascara[i][j] = '4';
		return peligro;
	}
	else if (peligro == 5)
	{
		mascara[i][j] = '5';
		return peligro;
	}
	else if (peligro == 6)
	{
		mascara[i][j] = '6';
		return peligro;
	}
	else if (peligro == 7)
	{
		mascara[i][j] = '7';
		return peligro;
	}
	else if (peligro == 8)
	{
		mascara[i][j] = '8';
		return peligro;
	}
}

void Grabar_posiciones()
{

}

void limpieza(int i, int j)
{
	int peligro = 0;
	int memfil[1000];
	int memcol[1000];

	for (int c = 0; c < 1000; c++)
	{
		memfil[c] = 0;
		memcol[c] = 0;
	}

	/*grabar posiciones iniciales*/

	memfil[0] = i + 1;
	memfil[1] = i + 1;
	memfil[2] = i + 1;
	memfil[3] = i;
	memfil[4] = i - 1;
	memfil[5] = i - 1;
	memfil[6] = i - 1;
	memfil[7] = i;

	memcol[0] = j - 1;
	memcol[1] = j;
	memcol[2] = j + 1;
	memcol[3] = j + 1;
	memcol[4] = j + 1;
	memcol[5] = j;
	memcol[6] = j - 1;
	memcol[7] = j - 1;

	for (int mem = 0; mem < 1000; mem++)
	{
		if (memfil[mem] != 0 && memcol[mem] != 0)
		{
			peligro = Control_Peligro(memfil[mem], memcol[mem]);

			if (peligro == 0)
			{
				Grabar_posiciones();
			}
		}
		else
		{
			break;
		}
	}
}

void realizar_jugada()
{
	int i, j;
	int peligro;

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
			peligro = Control_Peligro(i, j);

			if (peligro == 0)
			{
				limpieza(i, j);
			}
		}
	}
	else
	{
		cout << "La posicion fue selecionada anteriormente, por favor seleccione otra" << endl;
		goto jugada;
	}
}

int estado_jugador(int cantbombas)
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

void inicializar_matrices()
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