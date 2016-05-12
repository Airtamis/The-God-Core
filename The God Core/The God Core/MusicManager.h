/*************************************************************\
 * MusicManager.h                                            *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the declaration of the MusicManager    *
 * Class, which uses the FMOD API to load .mp3 files into    *
 * Memory, play them when called, and release the memory     *
 * When the song is no longer needed.                        *
\*************************************************************/

#ifndef MUSICMANAGER_H
#define MUSICMANAGER_H

// FMOD API
#include <fmod.hpp>

// Creates new type for ease of use
typedef FMOD::Sound* SoundClass;

class MusicManager
{
private:
	// Pointer to dynamic system memory to load music
	FMOD::System *m_pSystem;

	// The path to the music folder
	static const char* MUSIC_PATH;

public:
	// Loads the song in memory
	void makeSound(SoundClass *psound, const char *song);
	// Plays the song (Always loops)
	void playSound(SoundClass pSound, bool bLoop = true);
	// Releases the song
	void releaseSound(SoundClass psound);
	// Initializes FMOD
	MusicManager();
};

#endif