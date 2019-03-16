#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

enum ShapeEnum { CIRCLE, SQUARE };

class SettingsMgr
{
private:
	Color currentColor; //The current color to draw with
	ShapeEnum currentShape; //The current shape to draw with
public:

	//Constructor
	SettingsMgr(Color startingColor, ShapeEnum startingShape )
	{
		currentColor = startingColor;
		currentShape = startingShape;
	}

	// getCurColor: returns the current color
	// parameters: none
	// return type: Color
	Color getCurColor() const
	{
		return currentColor;
	}

	// getCurShape: returns the current shape
	// parameters: none
	// return type: ShapeEnum
	ShapeEnum getCurShape() const
	{
		return currentShape;
	}

	// setCurColor: changes the currentColor
	// parameters: 
	//  color: the color to change to
	// return type: void
	void setCurColor(Color color)
	{
		currentColor = color;
	}

	// setCurShape: changes the currentShape
	// parameters: 
	//  shpae: the shape to change to
	// return type: void
	void setCurShape(ShapeEnum shape)
	{
		currentShape = shape;
	}

	// read: load settings from a file
	// parameters: 
	//  myFile: the file to load form
	// return type: void
	void read(fstream& myFile)
	{
		int tempColor, tempShape; //temporary holders for settings data

		myFile.read(reinterpret_cast<char *>(&tempColor), sizeof(tempColor));
		myFile.read(reinterpret_cast<char *>(&tempShape), sizeof(tempShape));

		currentColor = Color(tempColor);
		currentShape = static_cast<ShapeEnum>(tempShape);
	}

	// write: write settings to a file
	// parameters: 
	//  myFile: the file to write to
	// return type: void
	void write(fstream& myFile)
	{
		unsigned tempColor = currentColor.toInteger();

		myFile.write(reinterpret_cast<char *>(&tempColor), sizeof(tempColor));
		myFile.write(reinterpret_cast<char *>(&currentShape), sizeof(currentShape));
	}
};
