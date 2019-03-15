#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "ShapeMgr.h"

const int CANVAS_WIDTH = 550;
const int CANVAS_HEIGHT = 500;

// finish this code; add functions, data as needed

class DrawingUI
{
private:
	Vector2f position;
public:
	DrawingUI(Vector2f p)
	{
		position = p;
	}

	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		//Draw canvas
		RectangleShape canvas;
		canvas.setPosition(position);
		canvas.setSize(Vector2f(CANVAS_WIDTH, CANVAS_HEIGHT));
		canvas.setOutlineThickness(2);
		canvas.setOutlineColor(Color::White);
		canvas.setFillColor(Color::Transparent);
		win.draw(canvas);

		//draw the existing shapes onto the canvas
	}
	
	bool isMouseInCanvas(Vector2f mousePos)
	{
		return false; // just to make it compile
	}

};

