//
// RandOpPeriodic3d
//
// This operator class, derived from RandOp3d, initializes all values
// of a GridFunction3d instance with random values that are uniformly
// distributed in [-1,1] and enforces periodicity.
//
//
// Initial Construction : Feb. 27, 2025
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

#ifndef SCC_RandOpPeriodic3d_
#define SCC_RandOpPeriodic3d_

namespace SCC
{
class RandOpPeriodic3d : public RandOp3d
{
    public :

	RandOpPeriodic3d() : RandOp3d(){}

    virtual ~RandOpPeriodic3d(){}

    virtual void randomize(GridFunction3d& v)
    {
    	RandOp3d::randomize(v);
        v.enforcePeriodicity();

    }
};
 
}
#endif
