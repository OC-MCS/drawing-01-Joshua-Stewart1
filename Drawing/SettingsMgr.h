#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

enum ShapeEnum { CIRCLE, SQUARE };

// finish this code; add functions, data as needed

class SettingsMgr
{
private:
	Color currentColor;
	ShapeEnum currentShape;
public:
	SettingsMgr(Color startingColor, ShapeEnum startingShape )
	{
		currentColor = startingColor;
		currentShape = startingShape;
	}

	Color getCurColor() const
	{
		return currentColor;
	}

	ShapeEnum getCurShape() const
	{
		return currentShape;
	}

	void setCurColor(Color color)
	{
		currentColor = color;
	}

	void setCurShape(ShapeEnum shape)
	{
		currentShape = shape;
	}

	//read function

	//write function
};
