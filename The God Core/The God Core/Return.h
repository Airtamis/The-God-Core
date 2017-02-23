/*************************************************************\
 * Return.h                                                  *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains varius return codes for when things    *
 * Go horribly wrong (and they do)                           *
 * (just hopefully not during my senior defense)             *
\*************************************************************/

#ifndef RETURN_H
#define RETURN_H

#define EXIT_OK 0 // Indicates an intended exit
#define EXIT_EARLY 1 // If we exit OpenGL main loop early
#define FMOD_ERROR 2 // Fmod can't load sound
#define DATABASE_ERROR 3 // sqlite can't load database
#define STATEMENT_ERROR 4 // sqlite statement fails to execute
#define SOIL_ERROR 5 // SOIl fails to load image
#define DATA_ENTRY_ERROR 6 // Indicates an internal error in a database entry
#define BINDING_ERROR 7 // Error binding a trigger
#define FILE_NOT_FOUND 8 // A file is not found

#endif
