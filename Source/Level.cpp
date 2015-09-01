#include "Level.h"

#include <iostream>

// SQLite API
#include "sqlite3.h"

#include "Rectangle.h"

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

// Dunno really what this does at this point
static int callback(void *data, int argc, char **argv, char **azColName){
	int i;
	for (i = 0; i< 2; i++){
		cout <<  azColName[i] << argv[i] << argv[i] << endl;
	}
	return 0;
}

void Level::loadLevel(std::string levelName)
{
	// Connection to SQL database
	sqlite3 *db;
	// 1 if error with DB
	int connectErr = sqlite3_open("Data.db", &db);
	// SQL command
	char* cmd;
	// Prepared Statement
	sqlite3_stmt *stm;
	// ??
	char *zErrMsg = 0;


	if (connectErr != SQLITE_OK)
	{
		exit(3);
	}

	cmd = "SELECT * FROM OBJECTS WHERE LEVEL = \"LEVELZERO\" AND OBJTYPE = \"WALL\"";

	//connectErr = sqlite3_exec(db, cmd, callback, 0, &zErrMsg);

	connectErr = sqlite3_prepare(db, cmd, -1, &stm, 0);

	if (connectErr != SQLITE_OK)
	{
		exit(4);
	}

	int i = 0;

	// While we still get rows of output
	while (sqlite3_step(stm) == SQLITE_ROW)
	{
		double x1, x2, x3, x4,
			y1, y2, y3, y4,
			z1, z2, z3, z4,
			r, g, b, a;

		x1 = sqlite3_column_double(stm, 3);
		x2 = sqlite3_column_double(stm, 4);
		x3 = sqlite3_column_double(stm, 5);
		x4 = sqlite3_column_double(stm, 19);

		y1 = sqlite3_column_double(stm, 6);
		y2 = sqlite3_column_double(stm, 7);
		y3 = sqlite3_column_double(stm, 8);
		y4 = sqlite3_column_double(stm, 20);

		z1 = sqlite3_column_double(stm, 9);
		z2 = sqlite3_column_double(stm, 10);
		z3 = sqlite3_column_double(stm, 11);
		z4 = sqlite3_column_double(stm, 21);

		r = sqlite3_column_double(stm, 15);
		g = sqlite3_column_double(stm, 16);
		b = sqlite3_column_double(stm, 17);
		a = sqlite3_column_double(stm, 18);

		v1.push_back(makeTrip(x1, y1, z1));
		v2.push_back(makeTrip(x2, y2, z2));
		v3.push_back(makeTrip(x3, y3, z3));
		v4.push_back(makeTrip(x4, y4, z4));

		colors.push_back(makeQuad(r, g, b, a));

		cout << x1 << endl;

		i++;
	}

	// Deconstructs the statement
	sqlite3_finalize(stm);
	// Closes the database
	sqlite3_close(db);

}

void Level::displayLevel()
{
	for (int i = 0; i < v1.size(); i++)
	{
		float verts[12] =
		{ 
			v1[i].a, v1[i].b, v1[i].c,
			v2[i].a, v2[i].b, v2[i].c,
			v3[i].a, v3[i].b, v3[i].c,
			v4[i].a, v4[i].b, v4[i].c };
		
		float Wallcolors[4] =
		{
			colors[i].r, colors[i].g, colors[i].b, colors[i].a
		};

		Rectangle wall(verts, Wallcolors);
		wall.Display();
	}
}