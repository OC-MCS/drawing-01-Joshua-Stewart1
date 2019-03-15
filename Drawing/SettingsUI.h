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
public:
	SettingsUI(SettingsMgr *mgr)
	{
		currentMgr = mgr;
	}
	void handleMouseUp(Vector2f mouse)
	{
		//if over a button, modify currentMgr
	}

	void draw(RenderWindow& win)
	{
		//Draw labels
		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
			die("couldn't load font");

		Text drawingColor("Drawing Color", font, 25);
		drawingColor.setPosition(15, 5);
		win.draw(drawingColor);

		Text drawingShape("Drawing Shape", font, 25);
		drawingShape.setPosition(15, 355);
		win.draw(drawingShape);


		//Draw buttons
		Circle yellowBtn(Vector2f(75, 50), Color::Yellow);
		Circle greenBtn(Vector2f(75, 150), Color::Green);
		Circle blueBtn(Vector2f(75, 250), Color::Blue);

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

		Circle circleBtn(Vector2f(75, 400), Color::White);
		Square squareBtn(Vector2f(75, 500), Color::White);

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
