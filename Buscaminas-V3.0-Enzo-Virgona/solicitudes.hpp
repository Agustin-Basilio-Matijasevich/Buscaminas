int solicitar_cant_bombas()
{
	int count = 0;
	int cantbombas;

	do
	{
		fflush(stdin);

		if (count == 0) {
			cout << "Ingrese la cantidad de bombas: ";
			cin >> cantbombas;
		}
		else {
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

	do {
		fflush(stdin);

		if (count > 0) cout << "El numero ingresado es erroneo, intente nuevamente" << endl;

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

	do {
		fflush(stdin);

		if (count > 0) cout << "El numero ingresado es erroneo, intente nuevamente" << endl;

		cout << "Ingrese la cantidad de columnas para el tablero (MAX=" << 25 << "), (MIN=2): ";
		cin >> columnas;

		count++;
	} while (columnas < 2 || columnas>25);

	return columnas;
}