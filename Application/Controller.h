#pragma once
#include "Subject.h"
#include "Image.h"

class Controller : public Subject
{
private:
	//ID of the current screnn to display
	int currentScreen;

	cv::Mat img;

public:
	/**
	 * Constructor
	 */
	Controller();

	/**
	 * Defines the new screen to display
	 * @param value : id of the new screen to display
	 */
	void setScreen(const int& value);

	/**
	 * Returns the id of the current displayed screen
	 */
	int getCurrentScreen();

	//Fonction Image:
	void setAddress(std::string _address);

	int testAddress(std::string _address);

	void updateImage(std::string _namedWindow);
};