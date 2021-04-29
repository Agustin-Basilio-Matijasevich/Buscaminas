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

	if (peligro == 0) mascara[i][j] = '_';
	else if (peligro > 0 && peligro < 9) mascara[i][j] = '0' + peligro;
	else {
		mascara[i][j] = 'E';
		cout << "Fatal Error In Function ''Control_Peligro''" << endl;
		system("Pause");
		return 1;
	}

	return peligro;
}