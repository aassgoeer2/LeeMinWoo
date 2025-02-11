#pragma once
#include <iostream>
using namespace std;

class View
{
public:
	virtual ~View() {}
	virtual void Render() = 0;
};

class MyView : public View
{
public:
	MyView();
	virtual ~MyView();
	virtual void Render();
};