/***************************************************************************
 *   Copyright (C) 2018 by Ángel Bravo Sáenz                               *
 *   angelbravosaenz@gmail.com                                             *
 *                                                                         *
 *   This file is part of Stac.                                            *
 *                                                                         *
 *   Stac is free software; you can redistribute it and/or modify          *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   Stac is distributed in the hope that it will be useful,               *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with Stac; if not, write to the                                 *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <iostream>
#include "calculosAlgebra.hpp"

CalculosAlgebra::CalculosAlgebra() {
	}

CalculosAlgebra::CalculosAlgebra(bool archivo, unsigned int longitudFila, unsigned int longitudColumna) {
	desdeArchivo = archivo;
	filas = longitudFila;
	filasDeB = filas;
	columnas = longitudColumna;
	columnasDeB = columnas;
	}

double CalculosAlgebra::traza() {
	double traza = 0;
	for (unsigned int i = 0; i < filas; i++) {
		traza += matriz[i][i];
		}
	return traza;
	}

double CalculosAlgebra::determinante() {
	//unsigned int const n = filas;
	double determinante = 0;
	switch (filas) {
		case 1:
			determinante = matriz[0][0];
			break;
		case 2://caso base para la recursividad
			determinante = matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
			break;
		case 3://por sarrus
			determinante = (matriz[0][0] * matriz[1][1] * matriz[2][2] +
								 matriz[0][2] * matriz[1][0] * matriz[2][1] +
								 matriz[0][1] * matriz[1][2] * matriz[2][0]) -
								(matriz[0][2] * matriz[1][1] * matriz[2][0] +
								 matriz[0][1] * matriz[1][0] * matriz[2][2] +
								 matriz[0][0] * matriz[1][2] * matriz[2][1]);
			break;
		default :
		/*	for (unsigned int n = 1; n < filas; n++) {
				for (unsigned int i = 2; i < filas; i++) {
					for (unsigned int j = 1; j < n-1; j++) {
						matrizB[i-1,j] = matriz[i,j];
						for (unsigned int j = 1; j < n-1; j++) {
							matrizB[i-1,j-1] = matriz[i,j];
						}
					}					
					if ((1+n) % 2 == 0){
						i = 1;
					} else {
						i = -1;
					}
					det:= det + i * m1[1,n] * determinante(B,dimension-1);

				
				
			*/
			std::cout << "Determinantes de orden >3 aún no disponible." << '\n';
			break;
		}
	return determinante;
	}

void CalculosAlgebra::traspuesta() {
	crearMatrizVaciaB();
	copiarMatrizA();
	for (unsigned int i = 0; i < filas; i++) {
		for (unsigned int j = 0; j < columnas; j++) {
			matrizB[i][j] = matriz[j][i];
			}
		}
	}

void CalculosAlgebra::adjunta() {
	crearMatrizVaciaB();
	switch (filas){
		case 1:
			matrizB[0][0] = matriz[0][0];
			break;
		case 2:
			matrizB[0][0] = matriz[1][1];
			matrizB[0][1] = -matriz[0][1];
			matrizB[1][0] = -matriz[1][0];
			matrizB[1][1] = matriz[0][0];
			break;
		case 3:
			matrizB[0][0] = (matriz[1][1]*matriz[2][2]) - (matriz[1][2]*matriz[2][1]);
			matrizB[0][1] = (matriz[1][2]*matriz[2][0]) - (matriz[1][0]*matriz[2][2]);
			matrizB[0][2] = (matriz[1][0]*matriz[2][1]) - (matriz[1][1]*matriz[2][0]);
			matrizB[1][0] = (matriz[2][1]*matriz[0][2]) - (matriz[2][2]*matriz[0][1]);
			matrizB[1][1] = (matriz[2][2]*matriz[0][0]) - (matriz[2][0]*matriz[0][2]);
			matrizB[1][2] = (matriz[2][0]*matriz[0][1]) - (matriz[2][1]*matriz[0][0]);
			matrizB[2][0] = (matriz[0][1]*matriz[1][2]) - (matriz[0][2]*matriz[1][1]);
			matrizB[2][1] = (matriz[0][2]*matriz[1][0]) - (matriz[0][0]*matriz[1][2]);
			matrizB[2][2] = (matriz[0][0]*matriz[1][1]) - (matriz[0][1]*matriz[1][0]);
			break;
		default:
			std::cout << "aún no disponible" << '\n';
	}
	}

void CalculosAlgebra::inversa() {
	crearMatrizVaciaB();
	double det = determinante();
	double frac = 1/det;
	if (determinante() != 0) {
		switch (filas){
			case 1:
				matrizB[0][0] = matriz[0][0];
				break;
			case 2:
				matrizB[0][0] = frac * matriz[1][1];
				matrizB[0][1] = frac * (-matriz[0][1]);
				matrizB[1][0] = frac * (-matriz[1][0]);
				matrizB[1][1] = frac * matriz[0][0];
				break;
			case 3:
				matrizB[0][0] = frac * ((matriz[1][1]*matriz[2][2]) - (matriz[1][2]*matriz[2][1]));
				matrizB[1][0] = frac * ((matriz[1][2]*matriz[2][0]) - (matriz[1][0]*matriz[2][2]));
				matrizB[2][0] = frac * ((matriz[1][0]*matriz[2][1]) - (matriz[1][1]*matriz[2][0]));
				matrizB[0][1] = frac * ((matriz[2][1]*matriz[0][2]) - (matriz[2][2]*matriz[0][1]));
				matrizB[1][1] = frac * ((matriz[2][2]*matriz[0][0]) - (matriz[2][0]*matriz[0][2]));
				matrizB[2][1] = frac * ((matriz[2][0]*matriz[0][1]) - (matriz[2][1]*matriz[0][0]));
				matrizB[0][2] = frac * ((matriz[0][1]*matriz[1][2]) - (matriz[0][2]*matriz[1][1]));
				matrizB[1][2] = frac * ((matriz[0][2]*matriz[1][0]) - (matriz[0][0]*matriz[1][2]));
				matrizB[2][2] = frac * ((matriz[0][0]*matriz[1][1]) - (matriz[0][1]*matriz[1][0]));
				break;
			default:
				std::cout << "aún no disponible" << '\n';
		}
	} else {
		std::cout << "La matriz no tiene inversa" << '\n';
		}
	}

void CalculosAlgebra::triangular() {
	/*for ( int i = 1, i <= n, i++ ) {
		if ( matriz[i, i] = 0 ) {
			for ( j = i + 1, j <= n, j++ ) {
				if ( matriz[j, i] != 0 ) {
				k = j:
					}

				}
			}
		}*/
	}

/*
Si A11=0, se busca el primer coeficiente no nulo de la getColumna
e intercambiamos fila.
Si A11 =/= 0 para i = 2...n, mi1=-ai1/a11, así hacemos 0 todo elemento
de la columna debajo del pivote
*/
void CalculosAlgebra::gauss() {
	/*unsigned int const n = filas;
	copiarMatrizA();
	for (int i = 1; i < n; i++) {
		if (matrizB[i][i] == 0) {
			for (int j = i + 1; j < n; j++) {
				}
			}
		else {
			//copiaDeMatriz[i][j] =;
			}
		}
	setMatrizB(matrizB);*/
	}

void CalculosAlgebra::descomposicionLU() {
	/*unsigned int const n = filas;
	unsigned int i, j, k;
	double matrizL [n][n];
	double matrizU [n][n];
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (j < i) {
				matrizL[j][i] = 0;
				}
			else {
				matrizL [j][i] = matriz [j][i];
				for (k = 0; k < i; k++) {
					matrizL [j][i] -= (matrizL [j][k] * matrizU [k][i]);
					}
				}
			}
		for (j = 0; j < n; j++) {
			if (j < i) {
				matrizU [i][j] = 0;
				}
			else if (j == i) {
				matrizU [i][j] = 1;
				}
			else {
				matrizU [i][j] = matriz[i][j] / matrizL [i][i];
				for (k = 0; k < i; k++) {
					matrizU [i][j] -= ((matrizL [i][k] * matrizU [k][j]) / matrizL [i][i]);
					}
				}
			}
		}
	copiarMatrizA();
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			matrizB[i][j] = matrizL[i][j];
			}
		}
	mostrarMatrizB();
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			matrizB[i][j] = matrizU[i][j];
			}
		}
	mostrarMatrizB();*/
	}

void CalculosAlgebra::sumaDeMatrices() {
	}

void CalculosAlgebra::Kronecker() {
	}

void CalculosAlgebra::multiplicacionDeMatrices() {
	Matriz matrizResultado(filas, columnas);
	matrizResultado.crearMatrizVacia();
	for (unsigned int i = 0; i < filas; i++) {
		for (unsigned int j = 0; j < columnas; j++) {
			
			}
		}
	//mostrarMatriz ( copiaDeMatriz );
	}

/*
(*---procedimiento para multiplicar matrices---*)

Procedure MultiplicarMat(m1,m2: Matriz; var resul:Matriz);
	Var
		i,j,k:1 .. W;
	Begin
		for i:=1 to dimension do
		for j:=1 to dimension do
		begin
			resul[i,j]:=0;
			for k:=1 to dimension do
			resul[i,j]:=resul[i,j]+m1[i,k]*m2[k,j];
		end;
	End;	(*MultiplicarMat*)*/
