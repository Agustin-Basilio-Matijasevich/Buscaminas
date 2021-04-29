void Grabar_posiciones() {

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

			if (peligro == 0)Grabar_posiciones();
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

	do {
		fflush(stdin);
		cout << "Ingrese fila y columna separados por un espacio: ";
		cin >> i >> j;

		if (i<1 || i>FIL) cout << "Posicion de fila inexistente, intente nuevamente" << endl;

		if (j<1 || j>COL) cout << "Posicion de columna inexistente, intente nuevamente" << endl;

		if (mascara[i][j] == '#') {
			if (tablero[i][j] == 1) mascara[i][j] = '*';
			else {
				peligro = Control_Peligro(i, j);

				if (peligro == 0) limpieza(i, j);
			}
		}
		else cout << "La posicion fue selecionada anteriormente, por favor seleccione otra" << endl;
	} while (i<1 || i>FIL || j<1 || j>COL);
}

int estado_jugador(int cantbombas)
{
	int count = 0;

	for (int i = 0; i <= FIL; i++) {
		for (int j = 0; j <= COL; j++) {
			if (mascara[i][j] == '*') return 2;
			else if (mascara[i][j] != '#') count++;
		}
	}

	if (count == (FIL * COL - cantbombas)) return 1;
	else return 0;
}

void inicializar_matrices()
{
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			tablero[i][j] = false;
			mascara[i][j] = '#';
		}
	}
}