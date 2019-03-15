#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"

void die(string msg);
// finish this code; add functions, data as needed

class SettingsUI
{
private:
	SettingsMgr *currentMgr;
	Circle yellowBtn = Circle(Vector2f(75, 70), Color::Yellow);
	Circle greenBtn = Circle(Vector2f(75, 170), Color::Green);
	Circle blueBtn = Circle(Vector2f(75, 270), Color::Blue);
	Circle circleBtn = Circle(Vector2f(75, 400), Color::White);
	Square squareBtn = Square(Vector2f(75, 500), Color::White);
public:
	SettingsUI(SettingsMgr *mgr)
	{
		currentMgr = mgr;
	}
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

	void draw(RenderWindow& win)
	{
		//Draw labels
		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
			die("couldn't load font");

		Text drawingColor("Drawing Color", font, 25);
		drawingColor.setPosition(15, 25);
		win.draw(drawingColor);

		Text drawingShape("Drawing Shape", font, 25);
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

void die(string msg)
{
	cout << msg << endl;
	exit(-1);
}
