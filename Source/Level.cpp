#include "Level.h"

#include <iostream>

#include "Rectangle.h"

#include "CollisionEngine.h"

using namespace std;

Quad makeQuad(float a, float b, float c, float d)
{
	Quad ret;
	ret.r = a;
	ret.g = b;
	ret.b = c;
	ret.a = d;

	return ret;
}

void Level::loadWalls(sqlite3 *db)
{
	// Prepared Statement
	sqlite3_stmt *stm;
	// SQL command
	char* cmd;
	// Connection Error Test
	int err;
	cmd = "SELECT * FROM walls WHERE LEVEL = \"LEVELZERO\"";

	err = sqlite3_prepare(db, cmd, -1, &stm, 0);

	if (err != SQLITE_OK)
	{
		exit(4);
	}

	// While we still get rows of output
	while (sqlite3_step(stm) == SQLITE_ROW)
	{
		double x1, x2, x3, x4,
			y1, y2, y3, y4,
			z1, z2, z3, z4,
			r, g, b, a;

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

		float verts[12] =
		{
			x1, y1, z1,
			x2, y2, z2,
			x3, y3, z3,
			x4, y4, z4
		};
		float colors[4] = { r, g, b, a };

		Rectangle rect(verts, colors);

		walls.push_back(rect);
	}

	// Deconstructs the statement
	sqlite3_finalize(stm);
}

void Level::loadDoors(sqlite3 *db)
{

	// Prepared Statement
	sqlite3_stmt *stm;
	// SQL command
	char* cmd;
	// Connection Error Test
	int err;
	cmd = "SELECT * FROM doors WHERE LEVEL = \"LEVELZERO\"";

	err = sqlite3_prepare(db, cmd, -1, &stm, 0);

	if (err != SQLITE_OK)
	{
		exit(4);
	}

	// While we still get rows of output
	while (sqlite3_step(stm) == SQLITE_ROW)
	{
		double x1, x2, x3, x4,
			y1, y2, y3, y4,
			z1, z2, z3, z4,
			r, g, b, a;

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

		float verts[12] =
		{
			x1, y1, z1,
			x2, y2, z2,
			x3, y3, z3,
			x4, y4, z4
		};
		float colors[4] = { r, g, b, a };

		Rectangle rect(verts, colors);

		doors.push_back(rect);
	}

	// Deconstructs the statement
	sqlite3_finalize(stm);
}

void Level::loadLevel(std::string levelName)
{
	if (quadratic == NULL)
	{
		quadratic = gluNewQuadric();
	}

	// Connection to SQL database
	sqlite3 *db;
	// 1 if error with DB
	int connectErr = sqlite3_open("Data.db", &db);

	if (connectErr != SQLITE_OK)
	{
		exit(3);
	}

	loadWalls(db);
	loadDoors(db);
	
	// Closes the database
	sqlite3_close(db);

}

void Level::displayLevel()
{
	vr::iterator it;

	//cout << walls.size() << endl;

	for (it = walls.begin(); it != walls.end(); it++)
	{
		it->Display();
	}

	for (it = doors.begin(); it != doors.end(); it++)
	{
		it->Display();
	}

	GLfloat lmodel_ambient[] = { 0.6, 0.6, 0.6, 1.0 };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}

bool Level::checkCollision()
{
	CollisionEngine col;

	return col.collide(walls);
}