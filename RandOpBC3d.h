//
// RandOpBC3d
//
// This operator class, derived from RandOp3d, initializes all values
// of a GridFunction3d instance with random values that are uniformly
// distributed in [-1,1] and enforces either homogeneous Dirichlet or
// periodicity in individual coordinate directions.
//
//
// Initial Construction : June, 23, 2025
/*
#############################################################################
#
# Copyright  2025 Chris Anderson
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the Lesser GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# For a copy of the GNU General Public License see
# <http://www.gnu.org/licenses/>.
#
#############################################################################
*/

#include "RandOp3d.h"
#include "GridFunctionNd/SCC_GridFunction3d.h"

#ifndef SCC_RAND_OP_BC_3D_
#define SCC_RAND_OP_BC_3D_

namespace SCC
{
class RandOpBC3d : public RandOp3d
{
    public :

	enum {DIRICHLET,PERIODIC};

	RandOpBC3d() : RandOp3d()
	{
	X_BC = RandOpBC3d::DIRICHLET;
	Y_BC = RandOpBC3d::DIRICHLET;
	Z_BC = RandOpBC3d::DIRICHLET;
	}

	RandOpBC3d(const RandOpBC3d& R) : RandOp3d(R)
	{
	X_BC = R.X_BC;
	Y_BC = R.Y_BC;
	Z_BC = R.Z_BC;
	}

	RandOpBC3d(int X_BC = RandOpBC3d::DIRICHLET,
			   int Y_BC = RandOpBC3d::DIRICHLET,
			   int Z_BC = RandOpBC3d::DIRICHLET) : RandOp3d()
	{
	this->X_BC = X_BC;
	this->Y_BC = Y_BC;
	this->Z_BC = Z_BC;
	}


    virtual ~RandOpBC3d(){}

    virtual void randomize(GridFunction3d& V)
    {
		RandOp3d::randomize(V);
		if(X_BC == RandOpBC3d::DIRICHLET) {V.setXboundaryValues(0.0);}
		if(Y_BC == RandOpBC3d::DIRICHLET) {V.setYboundaryValues(0.0);}
		if(Z_BC == RandOpBC3d::DIRICHLET) {V.setZboundaryValues(0.0);}

		if(X_BC == RandOpBC3d::PERIODIC) {V.enforceXperiodicity();}
		if(Y_BC == RandOpBC3d::PERIODIC) {V.enforceYperiodicity();}
		if(Z_BC == RandOpBC3d::PERIODIC) {V.enforceZperiodicity();}
    }

    int X_BC; int Y_BC;  int Z_BC;
};
 
}
#endif
