#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

const int RADIUS = 25;
const int SIZE = 50;

struct ShapeStruct
{
	Vector2f location; //The location of the given shape
	Color color; //The color of the given shape
	ShapeEnum whichShape; //The shape of the given shape
};

class DrawingShape 
{
public:
	virtual ShapeStruct getFileRecord() = 0;
	virtual bool checkMouse(Vector2f mouse) = 0;
	virtual void draw(RenderWindow& win, bool filledShape) = 0;
};


class Circle : public DrawingShape
{
private:
	CircleShape thisCircle; //The current circle being drawn
	Vector2f location; //The location of the circle
	Color color; //The color of the circle
public:
	
	//Constructor
	Circle(Vector2f loc, Color col)
	{
		location = loc;
		color = col;
	}
	
	// draw: creates and draws onto the window
	// parameters: 
	//  win: the window to draw the shapes to
	//  filledShape: determines if the shape filled or not
	// return type: void
	void draw(RenderWindow& win, bool filledShape)
	{
		thisCircle.setPosition(location);
		thisCircle.setRadius(RADIUS);
		thisCircle.setOutlineThickness(2);
		thisCircle.setOutlineColor(color);

		if (filledShape)
		{
			thisCircle.setFillColor(color);
		}
		else
		{
			thisCircle.setFillColor(Color::Transparent);
		}

		win.draw(thisCircle);
	}

	// getFileRecord: returns a record of the shape
	// parameters: none
	// return type: ShapeStruct
	ShapeStruct getFileRecord()
	{
		ShapeStruct myShape = {location, color, CIRCLE}; //The record of the current shape
		return myShape;
	}

	// checkMouse: checks if the mouse is colliding with the current object
	// parameters: 
	//  mouse: the position of the mouse
	// return type: bool
	bool checkMouse(Vector2f mouse)
	{
		return thisCircle.getGlobalBounds().contains(mouse);
	}
};


class Square : public DrawingShape
{
private:
	RectangleShape thisSquare; //The current square being drawn
	Vector2f location; //The location of the square
	Color color; //The color of the square
public:
	
	//Constructor
	Square(Vector2f loc, Color col)
	{
		location = loc;
		color = col;
	}

	// draw: creates and draws onto the window
	// parameters: 
	//  win: the window to draw the shapes to
	//  filledShape: determines if the shape filled or not
	// return type: void
	void draw(RenderWindow& win, bool filledShape)
	{
		thisSquare.setPosition(location);
		thisSquare.setSize(Vector2f(SIZE, SIZE));
		thisSquare.setOutlineThickness(2);
		thisSquare.setOutlineColor(color);

		if (filledShape)
		{
			thisSquare.setFillColor(color);
		}
		else
		{
			thisSquare.setFillColor(Color::Transparent);
		}

		win.draw(thisSquare);
	}

	// getFileRecord: returns a record of the shape
	// parameters: none
	// return type: ShapeStruct
	ShapeStruct getFileRecord()
	{
		ShapeStruct myShape = { location, color, SQUARE }; //The record of the current shape
		return myShape;
	}

	// checkMouse: checks if the mouse is colliding with the current object
	// parameters: 
	//  mouse: the position of the mouse
	// return type: bool
	bool checkMouse(Vector2f mouse)
	{
		return thisSquare.getGlobalBounds().contains(mouse);
	}
};