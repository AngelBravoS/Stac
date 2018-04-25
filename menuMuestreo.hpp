/***************************************************************************														*
 *   Copyright (C) 2018 by Ángel Bravo Sáenz  										*
 *   angelbravosaenz@gmail.com  															*
 *																									*
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

#ifndef _MENUMUESTREO_HPP_
#define _MENUMUESTREO_HPP_

#include "cli.hpp"
#include "calculosMuestreo.hpp"
#include<fstream>

class MenuMuestreo : public CLI {
		//Obtener = Get
		//Establecer = Set
	public:
		//bool getAgrupados();
		//void setAgrupados(bool agrupadosPublico);
		//CalculosMuestreo muestra(bool archivo, char muestreo, int longitudFila, unsigned int longitudColumna, bool datosAgrupados);
		//========  funciones de muestreo ======== 
		void menuSecundario();
		unsigned int tamanoColumna(bool agrupados);
		char tipoDeMuestreo();
		//bool datosAgrupados();
		void recogerDatosMuestra();
		void mostrarDatosMuestra();
	//protected:
	
};

#endif /* _MENUMUESTREO_HPP_ */
