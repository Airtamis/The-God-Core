/*************************************************************\
 * Triple.cpp                                                *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the definition of the TwoD class       *
 * For more information, see Triple.h                        *
\*************************************************************/

#include "Triple.h"

Triple makeTrip(double _a, double _b, double _c)
{
	Triple ret;
	ret.a = _a;
	ret.b = _b;
	ret.c = _c;

	return ret;
}