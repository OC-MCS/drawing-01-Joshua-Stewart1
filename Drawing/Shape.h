#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

// finish this code; add functions, classes, data as needed

const int RADIUS = 25;
const int SIZE = 50;

struct ShapeStruct
{
	Vector2f location;
	Color color;
	ShapeEnum whichShape;
};

// DrawingShape should be an abstract base class 
// for Circle and Square
class DrawingShape 
{
private:
	ShapeStruct myShape;
public:
	DrawingShape(Vector2f loc, Color col)
	{
		myShape.location = loc;
		myShape.color = col;
	}

	Vector2f getLocation() const
	{
		return myShape.location;
	}

	Color getColor() const
	{
		return myShape.color;
	}

	ShapeEnum getShape() const
	{
		return myShape.whichShape;
	}

	void setLocation(Vector2f loc)
	{
		myShape.location = loc;
	}

	void setColor(Color col)
	{
		myShape.color = col;
	}

	void setShape(ShapeEnum shape)
	{
		myShape.whichShape = shape;
	}

	/*void getRecordInfo(Vector2f& loc, Color& col, ShapeEnum& shape)
	{
		loc = myShape.location;
		col = myShape.color;
	}*/

	virtual void draw(RenderWindow& win, bool filledShape) = 0;
	
};

// add Circle, Square classes below. These are derived from DrawingShape

class Circle : public DrawingShape
{
private:

public:
	Circle(Vector2f loc, Color col) : DrawingShape(loc, col)
	{
		setShape(CIRCLE);
	}
	
	void draw(RenderWindow& win, bool filledShape)
	{
		CircleShape thisCircle;
		thisCircle.setPosition(getLocation());
		thisCircle.setRadius(RADIUS);
		thisCircle.setOutlineThickness(2);
		thisCircle.setOutlineColor(getColor());

		if (filledShape)
		{
			thisCircle.setFillColor(getColor());
		}
		else
		{
			thisCircle.setFillColor(Color::Transparent);
		}

		win.draw(thisCircle);
	}
};

class Square : public DrawingShape
{
private:

public:
	Square(Vector2f loc, Color col) : DrawingShape(loc, col)
	{
		setShape(SQUARE);
	}

	void draw(RenderWindow& win, bool filledShape)
	{
		RectangleShape thisRectangle;
		thisRectangle.setPosition(getLocation());
		thisRectangle.setSize(Vector2f(SIZE, SIZE));
		thisRectangle.setOutlineThickness(2);
		thisRectangle.setOutlineColor(getColor());

		if (filledShape)
		{
			thisRectangle.setFillColor(getColor());
		}
		else
		{
			thisRectangle.setFillColor(Color::Transparent);
		}

		win.draw(thisRectangle);
	}
};