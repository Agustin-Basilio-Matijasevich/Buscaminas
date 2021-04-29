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
		do {
			Sleep(10);
			alfil = rand() % (FIL)+1;
			Sleep(10);
			alcol = rand() % (COL)+1;
			Sleep(10);
		} while (tablero[alfil][alcol] == 1);

		if (tablero[alfil][alcol]) i--;
		else tablero[alfil][alcol] = true;
	}
}