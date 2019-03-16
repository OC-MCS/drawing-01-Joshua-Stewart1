#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"

using namespace std;
using namespace sf;

class ShapeMgr
{
private:
	vector<DrawingShape*> myCanvas; //The list of all shapes on the canvas
public:
	
	//Default Constructor
	ShapeMgr()
	{
		
	}

	// getCanvas: creates and draws onto the window
	// parameters: none
	// return type: vector<DrawingShape*>
	vector<DrawingShape*> getCanvas() const
	{
		return myCanvas;
	}

	// addShape: adds a shape to the list
	// parameters: 
	//  pos: the position of the shape to add
	//  whichShape: the shape of the shape to add
	//  color: The color of the shape to add
	// return type: void
	void addShape(Vector2f pos, ShapeEnum whichShape, Color color)
	{
		Vector2f shapePosition(pos.x, pos.y);
		
		if (whichShape == CIRCLE)
		{
			myCanvas.push_back(new Circle(shapePosition, color));
		}
		else
		{
			myCanvas.push_back(new Square(shapePosition, color));
		}
		
	}

	// read: load shapes from a file
	// parameters: 
	//  myFile: the file to load form
	// return type: void
	void read(fstream& myFile)
	{
		int tempX, tempY, tempColor, tempShape; //temporary holders for shape data

		while (myFile.read(reinterpret_cast<char *>(&tempX), sizeof(tempX)))
		{
			myFile.read(reinterpret_cast<char *>(&tempY), sizeof(tempY));
			myFile.read(reinterpret_cast<char *>(&tempColor), sizeof(tempColor));
			myFile.read(reinterpret_cast<char *>(&tempShape), sizeof(tempShape));

			addShape(Vector2f(tempX, tempY), static_cast<ShapeEnum>(tempShape), Color(tempColor));
		}
	}

	// write: write shapes to a file
	// parameters: 
	//  myFile: the file to write to
	// return type: void
	void write(fstream& myFile)
	{
		for (int i = 0; i < myCanvas.size(); i++)
		{
			ShapeStruct record = myCanvas[i]->getFileRecord(); //The current record being referenced
			myFile.write(reinterpret_cast<char *>(&record), sizeof(record));
		}
	}
};
