#pragma once

void mostrar_tablero();
void minar_tablero(int cantbombas);
bool control_minado(int cantbombas);
int Control_Peligro(int i, int j);
void Grabar_posiciones();
void limpieza(int i, int j);
void realizar_jugada();
int estado_jugador(int cantbombas);
void inicializar_matrices();
int solicitar_cant_bombas();
int solicitar_filas();
int solicitar_columnas();