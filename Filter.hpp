#ifndef FILTER_HPP
#define FILTER_HPP
#include <fstream>
#include <iostream>
#include <sstream>

class Filter
{
	std::ifstream inputImg;
	std::ofstream outputImg;
	int width;
	int heigth;

	void copyHeaders();

public:
	// Constructor
	Filter(std::string inputName, std::string outputName);

	// Filters
	void blueFilter();
	void redFilter();
	void greenFilter();
	void blurFilter();
	void thresholdFilter();
	void invertThresholdFilter();
};

#endif