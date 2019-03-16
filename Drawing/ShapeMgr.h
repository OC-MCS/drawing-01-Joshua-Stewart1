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
		Vector2f shapePosition(pos.x - (SIZE/2), pos.y - (SIZE / 2));
		
		if (whichShape == CIRCLE)
		{
			myCanvas.push_back(new Circle(shapePosition, color));
		}
		else
		{
			myCanvas.push_back(new Square(shapePosition, color));
		}
		
	}


	void read()
	{
		
		//while()
	}

	//write function
};
