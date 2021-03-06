/***************************************************************************
 *   Copyright (C) 2018 by Ángel Bravo Sáenz                               *
 *   angelbravosaenz@gmail.com                                             *
 *                                                                         *
 *   This file is part of Stac.                                            *
 *                                                                         *
 *   Stac is free software; you can redistribute it and/or modify          *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 2 of the License.               *
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
#include <fstream>
#include "vector.hpp"

//======== funciones de vectores ========

Vector::Vector() {}

void Vector::leerArchivo() {
	std::fstream archivo;
	archivo.open("vector.dat", std::ios::in | std::ios::binary);
	crearVectorVacio();
	for (unsigned int i = 0; i < longitudVector; i++) {
		archivo >> vector[i];
		}
	archivo.close();
	}

void Vector::verificarArchivo() {
	std::fstream archivo;
	archivo.open("datos.dat", std::ios::in | std::ios::binary);
	if (archivo.is_open()) {
		std::cout << "Fichero leído" << '\n';
		}
	else {
		std::cout << "Fichero inexistente" << '\n';
		exit(-1);
		}
	archivo.close();
	}

void Vector::leerTeclado() {
	crearVectorVacio();
	editarVectorVacio();
	}

void Vector::desdeDondeLeeVector() {
	if (leerDesdeArchivo == true) {
		verificarArchivo();
		leerArchivo();
		}
	else {
		leerTeclado();
		}
	}

void Vector::crearVectorVacio() {
	vector = new double [longitudVector];
	}

void Vector::editarVectorVacio() {
	for (unsigned int i = 0; i < longitudVector; i++) {
		std::cout << "Elemento " << i + 1  << ": ";
		std::cin >> vector[i];
		}
	std::cout << '\n';
	}

void Vector::mostrarVector() {
	std::cout << "( ";
	for (unsigned int i = 0; i < longitudVector; i++) {
		std::cout << vector[i] << " ";
		}
	std::cout << ")" << '\n';
	}

void Vector::ordenarVector() {
	double *vectorOrdenado;
	/*
	 *	vectorOrdenado = new double [longitudVector];
	 *	for(unsigned int i = 0; i < longitudVector; i++)     {
	 *		vectorOrdenado[i] = vector[i];
	}*/
	}

/*
 * void Vector::mostrarVectorCopia() {
 *	std::cout << "( ";
 *	for(unsigned int i = 0; i < getLongitudVector(); i++) {
 *		std::cout << vectorCopia[i] << " ";
 *	}
 *	std::cout << ")";
 *	std::cout << '\n';
 * }
 */
