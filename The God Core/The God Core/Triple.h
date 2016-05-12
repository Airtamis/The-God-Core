/*************************************************************\
 * Triple.h                                                  *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the declaration of the Triple class    *
 * Which is just a simple 3-tuple really                     *
\*************************************************************/

#ifndef TRIPLE_H
#define TRIPLE_H

class Triple
{
public:
	double a, b, c;
};

// For converting to a triple
Triple makeTrip(double _a, double _b, double _c);

#endif