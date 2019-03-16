#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"

void die(string msg);

class SettingsUI
{
private:
	SettingsMgr *currentMgr; //Holds the currently selected shape and color
	Circle yellowBtn = Circle(Vector2f(75, 70), Color::Yellow); //The yellow color button
	Circle greenBtn = Circle(Vector2f(75, 170), Color::Green); //The green color button
	Circle blueBtn = Circle(Vector2f(75, 270), Color::Blue); //The blue color button
	Circle circleBtn = Circle(Vector2f(75, 400), Color::White); //The circle shape button
	Square squareBtn = Square(Vector2f(75, 500), Color::White); //The square shape button
public:
	
	//Constructor
	SettingsUI(SettingsMgr *mgr)
	{
		currentMgr = mgr;
	}

	// handleMouseUp: determines if one of the buttons is pressed
	// parameters: 
	//  mouse: the current position of the mouse
	// return type: void
	void handleMouseUp(Vector2f mouse)
	{
		if (squareBtn.checkMouse(mouse))
		{
			currentMgr->setCurShape(SQUARE);
		}
		else if (circleBtn.checkMouse(mouse))
		{
			currentMgr->setCurShape(CIRCLE);
		}
		else if (yellowBtn.checkMouse(mouse))
		{
			currentMgr->setCurColor(Color::Yellow);
		}
		else if (greenBtn.checkMouse(mouse))
		{
			currentMgr->setCurColor(Color::Green);
		}
		else if (blueBtn.checkMouse(mouse))
		{
			currentMgr->setCurColor(Color::Blue);
		}
	}

	// draw: draws the labels and buttons onto the window
	// parameters: 
	//  win: the window to draw the shapes to
	// return type: void
	void draw(RenderWindow& win)
	{
		//Draw labels
		Font font; //The font for the labels
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
			die("couldn't load font");

		Text drawingColor("Drawing Color", font, 25); //The label for the color
		drawingColor.setPosition(15, 25);
		win.draw(drawingColor);

		Text drawingShape("Drawing Shape", font, 25); //The label for the shape
		drawingShape.setPosition(15, 355);
		win.draw(drawingShape);


		//Draw buttons
		if (currentMgr->getCurColor() == Color::Yellow)
		{
			yellowBtn.draw(win, true);
			greenBtn.draw(win, false);
			blueBtn.draw(win, false);
		}
		else if (currentMgr->getCurColor() == Color::Green)
		{
			yellowBtn.draw(win, false);
			greenBtn.draw(win, true);
			blueBtn.draw(win, false);
		}
		else
		{
			yellowBtn.draw(win, false);
			greenBtn.draw(win, false);
			blueBtn.draw(win, true);
		}

		if (currentMgr->getCurShape() == CIRCLE)
		{
			circleBtn.draw(win, true);
			squareBtn.draw(win, false);
		}
		else
		{
			circleBtn.draw(win, false);
			squareBtn.draw(win, true);
		}
	}

};

// die: kill the program and display an error message
// parameters: 
//  msg: the message to display if the program fails
// return type: void
void die(string msg)
{
	cout << msg << endl;
	exit(-1);
}
