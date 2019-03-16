#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "ShapeMgr.h"

const int CANVAS_WIDTH = 550; //The width of the drawing area
const int CANVAS_HEIGHT = 500; //The height of the drawing area

class DrawingUI
{
private:
	Vector2f position; //The position of the drawing canvas
public:
	
	//Constructor
	DrawingUI(Vector2f p)
	{
		position = p;
	}

	// draw: draws the canvas and shapes on the canvas onto the window
	// parameters: 
	//  win: the window to draw the shapes to
	//  mgr: holds the data for the shapes to draw on the canvas
	// return type: void
	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		//Draw canvas
		RectangleShape canvas; //The drawing area
		canvas.setPosition(position);
		canvas.setSize(Vector2f(CANVAS_WIDTH, CANVAS_HEIGHT));
		canvas.setOutlineThickness(2);
		canvas.setOutlineColor(Color::White);
		canvas.setFillColor(Color::Transparent);
		win.draw(canvas);

		//Draw the existing shapes onto the canvas
		for (int i = 0; i < mgr->getCanvas().size(); i++)
		{
			mgr->getCanvas()[i]->draw(win, true);
		}
	}

	// isMouseInCanvas: checks if the mouse is over the drawable region
	// parameters: 
	//  mousePos: the current position of the mouse
	// return type: bool
	bool isMouseInCanvas(Vector2f mousePos)
	{
		bool onCanvas; //Holds if the mouse is in the drawable region
		
		if (mousePos.x > position.x + RADIUS && mousePos.x < position.x + CANVAS_WIDTH - RADIUS
			&& mousePos.y > position.y + RADIUS && mousePos.y < position.y + CANVAS_HEIGHT - RADIUS)
		{
			onCanvas = true;
		}
		else
		{
			onCanvas = false;
		}

		return onCanvas;
	}

};

