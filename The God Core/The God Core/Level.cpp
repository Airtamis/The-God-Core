/*************************************************************\
 * Level.cpp                                                 *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the defintion of the Level class.      *
 * for more information, see Keyboard.h                      *
\*************************************************************/

// Class declaration
#include "Level.h"
// To use Planes
#include "Plane.h"
// Vectors to plop stuff in
#include "Globals.h"
// Return codes
#include "Return.h"
// System log
#include "Logger.h"
// Oject Types
#include "GCTypes.h"

#include <iostream>

using namespace std;

void Level::loadWalls(sqlite3 *db)
{
	walls.clear();
	// Prepared Statement
	sqlite3_stmt *stm;
	// SQL command
	string cmd;
	// Connection Error Test
	int err;
	cmd = "SELECT * FROM walls WHERE LEVEL = \"" + currLevel + "\"";

	err = sqlite3_prepare(db, cmd.c_str(), -1, &stm, 0);

	if (err != SQLITE_OK)
	{
		Logger log;
		vector<string> output = { "FATAL ERROR: failed to load walls from", currLevel };
		log.logLine(output);
		exit(STATEMENT_ERROR);
	}

	// While we still get rows of output
	while (sqlite3_step(stm) == SQLITE_ROW)
	{
		double x1, x2, x3, x4,
			y1, y2, y3, y4,
			z1, z2, z3, z4,
			r, g, b, a;
		string axis;

		x1 = sqlite3_column_double(stm, 2);
		x2 = sqlite3_column_double(stm, 3);
		x3 = sqlite3_column_double(stm, 4);
		x4 = sqlite3_column_double(stm, 5);

		y1 = sqlite3_column_double(stm, 6);
		y2 = sqlite3_column_double(stm, 7);
		y3 = sqlite3_column_double(stm, 8);
		y4 = sqlite3_column_double(stm, 9);

		z1 = sqlite3_column_double(stm, 10);
		z2 = sqlite3_column_double(stm, 11);
		z3 = sqlite3_column_double(stm, 12);
		z4 = sqlite3_column_double(stm, 13);

		r = sqlite3_column_double(stm, 14);
		g = sqlite3_column_double(stm, 15);
		b = sqlite3_column_double(stm, 16);
		a = sqlite3_column_double(stm, 17);

		axis = reinterpret_cast<const char*>(sqlite3_column_text(stm, 18));

		char ax;
		if (axis == "x") ax = 'x';
		else if (axis == "y") ax = 'y';
		else if (axis == "z") ax = 'z';
		else ax = 0;

		double verts[12] =
		{
			x1, y1, z1,
			x2, y2, z2,
			x3, y3, z3,
			x4, y4, z4
		};
		double colors[4] = { r, g, b, a };

		Plane rect(verts, colors, ax);

		walls.push_back(rect);
	}

	/*
	Logger log;
	vector<string> output = { "Loaded walls on", currLevel };
	log.logLine(output);
	*/

	// Deconstructs the statement
	sqlite3_finalize(stm);
}

void Level::loadDoors(sqlite3 *db)
{
	doors.clear();
	// Prepared Statement
	sqlite3_stmt *stm;
	// SQL command
	string cmd;
	// Connection Error Test
	int err;
	cmd = "SELECT * FROM doors WHERE LEVEL = \"" + currLevel + "\"";

	err = sqlite3_prepare(db, cmd.c_str(), -1, &stm, 0);

	if (err != SQLITE_OK)
	{
		Logger log;
		vector<string> output = { "FATAL ERROR: Can't load doors while loading", currLevel };
		log.logLine(output);

		exit(STATEMENT_ERROR);
	}

	// While we still get rows of output
	while (sqlite3_step(stm) == SQLITE_ROW)
	{
		double x1, x2, x3, x4,
			y1, y2, y3, y4,
			z1, z2, z3, z4,
			r, g, b, a;
		string id;
		string axis;

		id = reinterpret_cast<const char*>(sqlite3_column_text(stm, 0));
		x1 = sqlite3_column_double(stm, 2);
		x2 = sqlite3_column_double(stm, 3);
		x3 = sqlite3_column_double(stm, 4);
		x4 = sqlite3_column_double(stm, 5);

		y1 = sqlite3_column_double(stm, 6);
		y2 = sqlite3_column_double(stm, 7);
		y3 = sqlite3_column_double(stm, 8);
		y4 = sqlite3_column_double(stm, 9);

		z1 = sqlite3_column_double(stm, 10);
		z2 = sqlite3_column_double(stm, 11);
		z3 = sqlite3_column_double(stm, 12);
		z4 = sqlite3_column_double(stm, 13);

		r = sqlite3_column_double(stm, 14);
		g = sqlite3_column_double(stm, 15);
		b = sqlite3_column_double(stm, 16);
		a = sqlite3_column_double(stm, 17);

		a = sqlite3_column_double(stm, 17);

		axis = reinterpret_cast<const char*>(sqlite3_column_text(stm, 18));

		char ax;
		if (axis == "x") ax = 'x';
		else if (axis == "y") ax = 'y';
		else if (axis == "z") ax = 'z';
		else ax = 0;

		double verts[12] =
		{
			x1, y1, z1,
			x2, y2, z2,
			x3, y3, z3,
			x4, y4, z4
		};
		double colors[4] = { r, g, b, a };

		Plane rect(verts, colors, ax);

		doors.push_back(Door(rect, id));
	}

	Logger log;
	vector<string> output = { "Loaded doors on", currLevel };
	log.logLine(output);

	// Deconstructs the statement
	sqlite3_finalize(stm);
}

void Level::loadSwitches(sqlite3 *db)
{
	switches.clear();
	// Prepared Statement
	sqlite3_stmt *stm;
	// SQL command
	string cmd;
	// Connection Error Test
	int err;
	cmd = "SELECT * FROM switches WHERE LEVEL = \"" + currLevel + "\"";

	err = sqlite3_prepare(db, cmd.c_str(), -1, &stm, 0);

	if (err != SQLITE_OK)
	{
		Logger log;
		vector<string> output = { "FATAL ERROR: Can't load switches while loading", currLevel };
		log.logLine(output);

		exit(STATEMENT_ERROR);
	}

	// While we still get rows of output
	while (sqlite3_step(stm) == SQLITE_ROW)
	{
		double xt, yt, zt,
			xr, yr, zr;
		string target, s_type, id;
		int i_type;
		bool isOn;

		id = reinterpret_cast<const char*>(sqlite3_column_text(stm, 0));
		target = reinterpret_cast<const char*>(sqlite3_column_text(stm, 2));
		xt = sqlite3_column_double(stm, 3);
		yt = sqlite3_column_double(stm, 4);
		zt = sqlite3_column_double(stm, 5);

		xr = sqlite3_column_double(stm, 6);
		yr = sqlite3_column_double(stm, 7);
		zr = sqlite3_column_double(stm, 8);

		s_type = reinterpret_cast<const char*>(sqlite3_column_text(stm, 9));

		isOn = sqlite3_column_int(stm, 10);

		double translate[3] = { xt, yt, zt };
		double rotate[3] = { xr, yr, zr };

		if (s_type == "DOOR")
			i_type = T_DOOR;
		else if (s_type == "TERMINAL")
			i_type = T_TERMINAL;
		else if (s_type == "LEVEL_END")
			i_type = T_LEVEL_END;
		else
		{
			Logger log;
			vector<string> output = { "Failed to evaluate string type entry: ", s_type, "for switch ", id };
			log.logLine(output);

			exit(DATA_ENTRY_ERROR);
		}

		switches.push_back(Switch(translate, rotate, i_type, id, isOn));

		bool assigned = false;

		if (s_type == "LEVEL_END")
		{
			assigned = true;

			Logger log;
			vector<string> output = { "Switch ", id, " bound to end level" };
			log.logLine(output);
		}

		else if (s_type == "DOOR")
		{
			for (unsigned int i = 0; i < doors.size(); i++)
			{
				if (doors[i].getID() == target)
				{
					Logger log;
					vector<string> output = { "Binding switch ", id, " to door", target };
					log.logLine(output);

					switches[switches.size() - 1].assign(&(doors[i]));

					assigned = true;
				}
			}
		}

		else if (s_type == "TERMINAL")
		{
			for (unsigned int i = 0; i < terminals.size(); i++)
			{
				if (terminals[i].getID() == target)
				{
					Logger log;
					vector<string> output = { "Binding switch ", id, " to terminal", target };
					log.logLine(output);

					switches[switches.size() - 1].assign(&(terminals[i]));

					assigned = true;
				}
			}
		}

		if (!assigned)
		{
			Logger log;
			vector<string> output = { "Failed to bind switch ", id, " to a ", s_type };
			log.logLine(output);

			exit(BINDING_ERROR);
		}
	}

	Logger log;
	vector<string> output = { "Loaded switches on", currLevel };
	log.logLine(output);

	// Deconstructs the statement
	sqlite3_finalize(stm);
}

void Level::loadTerminals(sqlite3 *db)
{
	terminals.clear();
	// Prepared Statement
	sqlite3_stmt *stm;
	// SQL command
	string cmd;
	// Connection Error Test
	int err;
	cmd = "SELECT * FROM terminals WHERE LEVEL = \"" + currLevel + "\"";

	err = sqlite3_prepare(db, cmd.c_str(), -1, &stm, 0);

	if (err != SQLITE_OK)
	{
		Logger log;
		vector<string> output = { "FATAL ERROR: Can't load terminals while loading", currLevel };
		log.logLine(output);

		exit(STATEMENT_ERROR);
	}

	// While we still get rows of output
	while (sqlite3_step(stm) == SQLITE_ROW)
	{
		double xt, yt, zt,
			xr, yr, zr;
		string file, id;
		id = reinterpret_cast<const char*>(sqlite3_column_text(stm, 0));
		file = reinterpret_cast<const char*>(sqlite3_column_text(stm, 2));
		xt = sqlite3_column_double(stm, 3);
		yt = sqlite3_column_double(stm, 4);
		zt = sqlite3_column_double(stm, 5);

		xr = sqlite3_column_double(stm, 6);
		yr = sqlite3_column_double(stm, 7);
		zr = sqlite3_column_double(stm, 8);

		double translate[3] = { xt, yt, zt };
		double rotate[3] = { xr, yr, zr };

		Logger log;
		log.logLine(id);

		terminals.push_back(Terminal(translate, rotate, file, id));
	}


	Logger log;
	vector<string> output = { "Loaded terminals on", currLevel };
	log.logLine(output);

	// Deconstructs the statement
	sqlite3_finalize(stm);
}

void Level::loadTriggers(sqlite3 *db)
{
	triggers.clear();
	// Prepared Statement
	sqlite3_stmt *stm;
	// SQL command
	string cmd;
	// Connection Error Test
	int err;
	cmd = "SELECT * FROM triggers WHERE LEVEL = \"" + currLevel + "\"";

	err = sqlite3_prepare(db, cmd.c_str(), -1, &stm, 0);

	if (err != SQLITE_OK)
	{
		Logger log;
		vector<string> output = { "FATAL ERROR: Can't load triggers while loading", currLevel };
		log.logLine(output);

		exit(STATEMENT_ERROR);
	}

	// While we still get rows of output
	while (sqlite3_step(stm) == SQLITE_ROW)
	{
		string target, trigger, targetType, triggerType, id;
		int i_targetType, i_triggerType;
		
		id = reinterpret_cast<const char*>(sqlite3_column_text(stm, 0));
		trigger = reinterpret_cast<const char*>(sqlite3_column_text(stm, 2));
		target = reinterpret_cast<const char*>(sqlite3_column_text(stm, 3));
		triggerType = reinterpret_cast<const char*>(sqlite3_column_text(stm, 4));
		targetType = reinterpret_cast<const char*>(sqlite3_column_text(stm, 5));

		if (triggerType == "SWITCH")
			i_triggerType = T_SWITCH;
		else if (triggerType == "TERMINAL")
			i_triggerType = T_TERMINAL;
		else
		{
			Logger log;
			vector<string> output = { "Failed to evaluate string trigger type entry: ", triggerType, "for trigger ", id };
			log.logLine(output);

			exit(DATA_ENTRY_ERROR);
		}

		if (targetType == "SWITCH")
			i_targetType = T_SWITCH;
		else if (targetType == "TERMINAL")
			i_targetType = T_TERMINAL;
		else
		{
			Logger log;
			vector<string> output = { "Failed to evaluate string trigger type entry: ", targetType, "for trigger ", id };
			log.logLine(output);

			exit(DATA_ENTRY_ERROR);
		}

		triggers.push_back(Trigger(i_triggerType, i_targetType));

		bool assigned = bindTrigger(id, trigger, triggerType) && bindTarget(id, target, targetType);

		if (!assigned)
		{
			Logger log;
			vector<string> output = { "Failed to bind trigger ", id };
			log.logLine(output);

			exit(BINDING_ERROR);
		}
	}

	Logger log;
	vector<string> output = { "Loaded trigger on", currLevel };
	log.logLine(output);

	// Deconstructs the statement
	sqlite3_finalize(stm);
}

bool Level::bindTrigger(string id, string trigger, string triggerType)
{
	if (triggerType == "SWITCH")
	{
		for (unsigned int i = 0; i < switches.size(); i++)
		{
			if (switches[i].getID() == trigger)
			{
				Logger log;
				vector<string> output = { "Binding trigger ", id, " to trigger-switch", trigger };
				log.logLine(output);

				triggers[triggers.size() - 1].bindTrigger(&(switches[i]));

				return true;
			}
		}
	}

	else if (triggerType == "TERMINAL")
	{
		for (unsigned int i = 0; i < terminals.size(); i++)
		{
			if (terminals[i].getID() == trigger)
			{
				Logger log;
				vector<string> output = { "Binding trigger ", id, " to trigger-terminal", trigger };
				log.logLine(output);

				triggers[triggers.size() - 1].bindTrigger(&(terminals[i]));

				return true;
			}
		}
	}

	return false;
}

bool Level::bindTarget(string id, string target, string targetType)
{

	if (targetType == "SWITCH")
	{
		for (unsigned int i = 0; i < switches.size(); i++)
		{
			if (switches[i].getID() == target)
			{
				Logger log;
				vector<string> output = { "Binding trigger ", id, " to target-switch", target };
				log.logLine(output);

				triggers[triggers.size() - 1].bindTarget(&(switches[i]));

				return true;
			}
		}
	}

	else if (targetType == "TERMINAL")
	{
		for (unsigned int i = 0; i < terminals.size(); i++)
		{
			if (terminals[i].getID() == target)
			{
				Logger log;
				vector<string> output = { "Binding trigger ", id, " to target-terminal", target };
				log.logLine(output);

				triggers[triggers.size() - 1].bindTarget(&(terminals[i]));

				return true;
			}
		}
	}

	return false;
}

void Level::loadLevel(std::string levelName)
{
	Logger log;
	vector<string> output = { "Starting to load", levelName };
	log.logLine(output);

	if (quadratic == NULL)
	{
		quadratic = gluNewQuadric();
	}

	currLevel = levelName;

	// Connection to SQL database
	sqlite3 *db;
	// 1 if error with DB
	int connectErr = sqlite3_open("Data.db", &db);

	if (connectErr != SQLITE_OK)
	{
		Logger log;
		log.logLine("FATAL ERROR: Can't access database");

		exit(DATABASE_ERROR);
	}

	loadWalls(db);
	loadDoors(db);
	loadTerminals(db);

	// Loading switches must be after doors/terminals to properly bind
	loadSwitches(db);

	// Loading triggers must be done last to properly bind
	loadTriggers(db);

	// Closes the database
	sqlite3_close(db);

	output[0] = "Finished loading";
	log.logLine(output);

	// Get out of wall
	for (unsigned int i = 0; i < 3; i++)
	{
		Cam.moveForward(1);
	}
}

void Level::displayLevel()
{
	for (auto i : walls)
	{
		i.Display();
	}

	for (auto i : doors)
	{
		i.Display();
	}

	for (auto i : switches)
	{
		i.Display();
	}

	for (auto i : terminals)
	{
		i.Display();
	}
}
