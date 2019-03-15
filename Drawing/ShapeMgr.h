#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"

using namespace std;
using namespace sf;

// finish the ShapeMgr class.

class ShapeMgr
{
private:
	vector<DrawingShape*> myCanvas;
public:
	ShapeMgr()
	{
		
	}

	void addShape(Vector2f pos, ShapeEnum whichShape, Color color)
	{
		if (whichShape == CIRCLE)
		{
			myCanvas.push_back(new Circle(pos, color));
		}
		else
		{
			myCanvas.push_back(new Square(pos, color));
		}
		
	}

	//read function

	//write function
};
