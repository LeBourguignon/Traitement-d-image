#pragma once
#include "Observer.h"
#include "View.h"
#include "Controller.h"

class ViewMenuImage: public View
{
private:
	// Controller of the application
	Controller& controller;
public:
	/**
	 * Constructor
	 * @param _controller Application controller
	 */
	ViewMenuImage(Controller& _controller);

	/**
	 * Notification function of the view
	 */
	virtual void notify();

	/**
	 * Displays the view
	 */
	virtual void display();
};