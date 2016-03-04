/******************************************************************************
*       SOFA, Simulation Open-Framework Architecture, development version     *
*                (c) 2006-2016 INRIA, USTL, UJF, CNRS, MGH                    *
*                                                                             *
* This library is free software; you can redistribute it and/or modify it     *
* under the terms of the GNU Lesser General Public License as published by    *
* the Free Software Foundation; either version 2.1 of the License, or (at     *
* your option) any later version.                                             *
*                                                                             *
* This library is distributed in the hope that it will be useful, but WITHOUT *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or       *
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License *
* for more details.                                                           *
*                                                                             *
* You should have received a copy of the GNU Lesser General Public License    *
* along with this library; if not, write to the Free Software Foundation,     *
* Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA.          *
*******************************************************************************
*                              SOFA :: Framework                              *
*                                                                             *
* Authors: The SOFA Team (see Authors.txt)                                    *
*                                                                             *
* Contact information: contact@sofa-framework.org                             *
******************************************************************************/
#include "SingleMatrixAccessor.h"
#include <iostream>
using std::cerr;
using std::endl;

namespace sofa
{

namespace component
{

namespace linearsolver
{

SingleMatrixAccessor::~SingleMatrixAccessor()
{
}


void SingleMatrixAccessor::setMatrix( BaseMatrix* m )
{
    matrix = m;
    matRef.matrix = m;
}

SingleMatrixAccessor::InteractionMatrixRef SingleMatrixAccessor::getMatrix(const core::behavior::BaseMechanicalState*, const core::behavior::BaseMechanicalState* ) const
{
    assert(false);
    InteractionMatrixRef ref;
    return ref;
}

SingleMatrixAccessor::MatrixRef SingleMatrixAccessor::getMatrix(const core::behavior::BaseMechanicalState*) const
{
//    cerr<<"SingleMatrixAccessor::getMatrix" << endl;
    return matRef;
}


} // namespace behavior

} // namespace core

} // namespace sofa
