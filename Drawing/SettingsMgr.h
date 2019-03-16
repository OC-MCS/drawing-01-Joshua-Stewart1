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

	//read function

	//write function
};
