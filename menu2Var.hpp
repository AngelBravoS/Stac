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

#ifndef _MENU2VAR_HPP_
#define _MENU2VAR_HPP_

#include "cli.hpp"
#include "calculos2Var.hpp"
#include "calculosTablasContBid.hpp"
#include<fstream>

class Menu2Var : public CLI {
		//Obtener = Get
		//Establecer = Set
	public:
		//Calculos2Var variableXeY(bool, unsigned int, unsigned int);
		//========  funciones de muestreo ======== 
		void menuSecundario();
		void menuMuestra2Var();
		void menuFmp2Var();
		unsigned int preguntarNumeroColumnas();
		bool esMuestra();
};

#endif /* _MENU2VAR_HPP_ */
