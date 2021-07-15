#include "Filter.hpp"

class RGB
{
public:
	int red;
	int green;
	int blue;
};

// Constructor
Filter::Filter(std::string inputName, std::string outputName)
{
	inputImg.open(inputName.c_str());
	outputImg.open(outputName.c_str());
	width = 0;
	heigth = 0;
}

// Copy header function
void Filter::copyHeaders()
{
	std::string type;
	std::string colorRange;
	int w, h;

	if (inputImg.is_open())
	{
		inputImg >> type >> w >> h >> colorRange;
		this->width = w;
		this->heigth = h;
		outputImg << type << std::endl;
		outputImg << w << " " << h << std::endl;
		outputImg << colorRange << std::endl;
	}
	else
	{
		std::cout << "Failed to load image" << std::endl;
	}
}

// Filters
void Filter::blueFilter()
{
	copyHeaders();

	while (!inputImg.eof())
	{
		int rVal, gVal, bVal;
		std::string red, green, blue;
		inputImg >> red >> green >> blue;

		std::stringstream redStream(red);
		std::stringstream greenStream(green);
		std::stringstream blueStream(blue);

		redStream >> rVal;
		greenStream >> gVal;
		blueStream >> bVal;

		if (bVal + 50 >= 255)
			bVal = 255;
		else
			bVal += 50;

		outputImg << rVal << " " << gVal << " " << bVal << std::endl;
	}
	std::cout << "Blue Filter Applied" << std::endl;
	inputImg.close();
	outputImg.close();
	std::cout << "Finished" << std::endl;
}

void Filter::redFilter()
{
	copyHeaders();

	while (!inputImg.eof())
	{
		int rVal, gVal, bVal;
		std::string red, green, blue;
		inputImg >> red >> green >> blue;

		std::stringstream redStream(red);
		std::stringstream greenStream(green);
		std::stringstream blueStream(blue);

		redStream >> rVal;
		greenStream >> gVal;
		blueStream >> bVal;

		if (rVal + 50 >= 255)
			rVal = 255;
		else
			rVal += 50;

		outputImg << rVal << " " << gVal << " " << bVal << std::endl;
	}
	std::cout << "Red Filter Applied" << std::endl;
	inputImg.close();
	outputImg.close();
	std::cout << "Finished" << std::endl;
}

void Filter::greenFilter()
{
	copyHeaders();

	while (!inputImg.eof())
	{
		int rVal, gVal, bVal;
		std::string red, green, blue;
		inputImg >> red >> green >> blue;

		std::stringstream redStream(red);
		std::stringstream greenStream(green);
		std::stringstream blueStream(blue);

		redStream >> rVal;
		greenStream >> gVal;
		blueStream >> bVal;

		if (gVal + 50 >= 255)
			gVal = 255;
		else
			gVal += 50;

		outputImg << rVal << " " << gVal << " " << bVal << std::endl;
	}
	std::cout << "Green Filter Applied" << std::endl;
	inputImg.close();
	outputImg.close();
	std::cout << "Finished" << std::endl;
}

void Filter::thresholdFilter()
{
	copyHeaders();

	// Copying the RGB values from the image to a 2D array
	RGB arr[heigth][width];
	for (int x = 0; x < heigth; x++)
	{
		for (int y = 0; y < width; y++)
		{
			int rVal, gVal, bVal;
			std::string red, green, blue;
			inputImg >> red >> green >> blue;

			std::stringstream redStream(red);
			std::stringstream greenStream(green);
			std::stringstream blueStream(blue);

			redStream >> rVal;
			greenStream >> gVal;
			blueStream >> bVal;
			RGB color = {rVal, gVal, bVal};
			arr[x][y] = color;
		}
	}

	// Finding the average for each pixel
	for (int x = 0; x < heigth; x++)
	{
		for (int y = 0; y < width; y++)
		{
			// Flooring the color values
			if (arr[x][y].red > 125)
				arr[x][y].red = 255;
			else
				arr[x][y].red = 0;

			if (arr[x][y].green > 125)
				arr[x][y].green = 255;
			else
				arr[x][y].green = 0;

			if (arr[x][y].blue > 125)
				arr[x][y].blue = 255;
			else
				arr[x][y].blue = 0;

			outputImg << arr[x][y].red << " " << arr[x][y].green << " " << arr[x][y].blue << std::endl;
		}
	}
	std::cout << "Threshold Filter Applied" << std::endl;
	inputImg.close();
	outputImg.close();
	std::cout << "Finished" << std::endl;
}

// This filter is does not work perfectly, so some image viewer do have hard time opening it.
void Filter::blurFilter()
{
	copyHeaders();

	// Copying the RGB values from the image to a 2D array
	RGB arr[heigth][width] = {0};
	for (int x = 0; x < heigth; x++)
	{
		for (int y = 0; y < width; y++)
		{
			int rVal, gVal, bVal;
			std::string red, green, blue;
			inputImg >> red >> green >> blue;

			std::stringstream redStream(red);
			std::stringstream greenStream(green);
			std::stringstream blueStream(blue);

			redStream >> rVal;
			greenStream >> gVal;
			blueStream >> bVal;
			RGB color = {rVal, gVal, bVal};
			arr[x][y] = color;
		}
	}

	// Finding the average for each pixel
	for (int x = 1; x <= heigth; x++)
	{
		for (int y = 1; y <= width; y++)
		{
			if (x == heigth)
			{
				outputImg << 0 << " " << 0 << " " << 0 << std::endl;
				std::cout << "Blur Filter Applied" << std::endl;
				inputImg.close();
				outputImg.close();
				std::cout << "Finished" << std::endl;
				return;
			}
			arr[x][y].red = (int)((arr[x - 1][y].red + arr[x][y - 1].red + arr[x + 1][y].red + arr[x][y + 1].red + arr[x - 1][y - 1].red + arr[x - 1][y + 1].red + arr[x + 1][y - 1].red + arr[x + 1][y + 1].red) / 8);
			arr[x][y].green = (int)((arr[x - 1][y].green + arr[x][y - 1].green + arr[x + 1][y].green + arr[x][y + 1].green + arr[x - 1][y - 1].green + arr[x - 1][y + 1].green + arr[x + 1][y - 1].green + arr[x + 1][y + 1].green) / 8);
			arr[x][y].blue = (int)((arr[x - 1][y].blue + arr[x][y - 1].blue + arr[x + 1][y].blue + arr[x][y + 1].blue + arr[x - 1][y - 1].blue + arr[x - 1][y + 1].blue + arr[x + 1][y - 1].blue + arr[x + 1][y + 1].blue) / 8);

			outputImg << std::abs(arr[x][y].red % 255) << " " << std::abs(arr[x][y].green % 255) << " " << std::abs(arr[x][y].blue % 255) << std::endl;
		}
	}
}

void Filter::invertThresholdFilter()
{
	copyHeaders();

	// Copying the RGB values from the image to a 2D array
	RGB arr[heigth][width];
	for (int x = 0; x < heigth; x++)
	{
		for (int y = 0; y < width; y++)
		{
			int rVal, gVal, bVal;
			std::string red, green, blue;
			inputImg >> red >> green >> blue;

			std::stringstream redStream(red);
			std::stringstream greenStream(green);
			std::stringstream blueStream(blue);

			redStream >> rVal;
			greenStream >> gVal;
			blueStream >> bVal;
			RGB color = {rVal, gVal, bVal};
			arr[x][y] = color;
		}
	}

	// Finding the average for each pixel
	for (int x = 0; x < heigth; x++)
	{
		for (int y = 0; y < width; y++)
		{
			// Flooring the color values
			if (arr[x][y].red > 125)
				arr[x][y].red = 0;
			else
				arr[x][y].red = 255;

			if (arr[x][y].green > 125)
				arr[x][y].green = 0;
			else
				arr[x][y].green = 255;

			if (arr[x][y].blue > 125)
				arr[x][y].blue = 0;
			else
				arr[x][y].blue = 255;

			outputImg << arr[x][y].red << " " << arr[x][y].green << " " << arr[x][y].blue << std::endl;
		}
	}
	std::cout << "Inverted Threshold Filter Applied" << std::endl;
	inputImg.close();
	outputImg.close();
	std::cout << "Finished" << std::endl;
}
