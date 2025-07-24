//
// RandOpBC2d
//
// This operator class, derived from RandOp2d, initializes all values
// of a GridFunction2d instance with random values that are uniformly
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

#include "RandOp2d.h"
#include "GridFunctionNd/SCC_GridFunction2d.h"

#ifndef SCC_RAND_OP_BC_2D_
#define SCC_RAND_OP_BC_2D_

namespace SCC
{
class RandOpBC2d : public RandOp2d
{
    public :

	enum {DIRICHLET,PERIODIC};

	RandOpBC2d() : RandOp2d()
	{
	X_BC = RandOpBC2d::DIRICHLET;
	Y_BC = RandOpBC2d::DIRICHLET;
	}

	RandOpBC2d(const RandOpBC2d& R) : RandOp2d(R)
	{
	X_BC = R.X_BC;
	Y_BC = R.Y_BC;
	}

	RandOpBC2d(int X_BC = RandOpBC2d::DIRICHLET,
			   int Y_BC = RandOpBC2d::DIRICHLET) : RandOp2d()
	{
	this->X_BC = X_BC;
	this->Y_BC = Y_BC;
	}


    virtual ~RandOpBC2d(){}

    virtual void randomize(GridFunction2d& V)
    {
		RandOp2d::randomize(V);
		if(X_BC == RandOpBC2d::DIRICHLET) {V.setXboundaryValues(0.0);}
		if(Y_BC == RandOpBC2d::DIRICHLET) {V.setYboundaryValues(0.0);}

		if(X_BC == RandOpBC2d::PERIODIC) {V.enforceXperiodicity();}
		if(Y_BC == RandOpBC2d::PERIODIC) {V.enforceYperiodicity();}
    }

    int X_BC; int Y_BC;
};
 
}
#endif
