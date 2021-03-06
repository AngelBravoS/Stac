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

#ifndef _MENUIO_HPP_
#define _MENUIO_HPP_

#include "cli.hpp"
#include <iostream>
#include "modelo.hpp"
#include "mmi.hpp"
#include "mmik.hpp"
#include "mmc.hpp"
#include "mmInfinit.hpp"
#include "mgi.hpp"

class MenuIO : public CLI  {
public:
	//======== constructor ========
	//Modelo io ( double, double, unsigned int  );
	void menuSecundario();
	void resultados(double lambdaUsuario, double muUsuario, unsigned int nUsuario, unsigned int cUsuario, unsigned int modeloSeleccionado);
	};

#endif /*	_MENUIO_HPP_ */
