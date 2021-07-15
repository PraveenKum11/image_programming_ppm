#include "Patterns.hpp"

// Creates a output file with (x, y) dimensions
std::ofstream createImage()
{
	std::ofstream newImage;
	std::string fileName = "data/image";
	fileName += std::to_string(rand() % 100);
	newImage.open(fileName.c_str());
	if (newImage.is_open())
		std::cout << "Image opened" << std::endl;
	else
		std::cout << "Failed to open the Image" << std::endl;
	return newImage;
}

void getHeader(std::ofstream &newImage, int x, int y)
{
	newImage << "P3" << std::endl;
	newImage << x << " " << y << std::endl;
	newImage << "255" << std::endl;
	return;
}

// Creates a pattern in image object with (x,y) dimensions
void bwA(int x, int y)
{
	std::ofstream newImage = createImage();
	getHeader(newImage, x, y);

	// Pattern
	int rVal, gVal, bVal;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			rVal = i % 255;
			gVal = i % 255;
			bVal = i % 255;
			newImage << rVal << " " << gVal << " " << bVal << std::endl;
		}
	}
	newImage.close();
}

void bwB(int x, int y)
{
	std::ofstream newImage = createImage();
	getHeader(newImage, x, y);

	// Pattern
	int rVal, gVal, bVal;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			rVal = j % 255;
			gVal = j % 255;
			bVal = j % 255;
			newImage << rVal << " " << gVal << " " << bVal << std::endl;
		}
	}
	newImage.close();
}

void rgbA(int x, int y)
{
	std::ofstream newImage = createImage();
	getHeader(newImage, x, y);

	// Pattern
	int rVal, gVal, bVal;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			rVal = (i * j) % 255;
			gVal = j % 255;
			bVal = j % 255;
			newImage << rVal << " " << gVal << " " << bVal << std::endl;
		}
	}
	newImage.close();
}

void rgbB(int x, int y)
{
	std::ofstream newImage = createImage();
	getHeader(newImage, x, y);

	// Pattern
	int rVal, gVal, bVal;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			rVal = j % 255;
			gVal = (i * j) % 255;
			bVal = j % 255;
			newImage << rVal << " " << gVal << " " << bVal << std::endl;
		}
	}
	newImage.close();
}

void rgbC(int x, int y)
{
	std::ofstream newImage = createImage();
	getHeader(newImage, x, y);

	// Pattern
	int rVal, gVal, bVal;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			rVal = j % 255;
			gVal = j % 255;
			bVal = (i * j) % 255;
			newImage << rVal << " " << gVal << " " << bVal << std::endl;
		}
	}
	newImage.close();
}

void rgbD(int x, int y)
{
	std::ofstream newImage = createImage();
	getHeader(newImage, x, y);

	// Pattern
	int rVal, gVal, bVal;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			rVal = (i * j) % 255;
			gVal = (i * j) % 255;
			bVal = (i * j) % 255;
			newImage << rVal << " " << gVal << " " << bVal << std::endl;
		}
	}
	newImage.close();
}

void mathA(int x, int y)
{
	std::ofstream newImage = createImage();
	getHeader(newImage, x, y);

	// Pattern
	int rVal, gVal, bVal;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			rVal = (int)(std::abs(std::sin(j)) * i) % 255;
			gVal = (int)(std::abs(std::cos(i)) * j) % 255;
			bVal = j;
			newImage << rVal << " " << gVal << " " << bVal << std::endl;
		}
	}
	newImage.close();
}

void mathB(int x, int y)
{
	std::ofstream newImage = createImage();
	getHeader(newImage, x, y);

	// Pattern
	int rVal, gVal, bVal;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			rVal = (int)(std::abs(std::tan(j)) * i) % 255;
			gVal = (int)(std::abs(std::cos(i)) * j) % 255;
			bVal = (int)(std::abs(std::sin(j)) * i) % 255;
			newImage << rVal << " " << gVal << " " << bVal << std::endl;
		}
	}
	newImage.close();
}

void mathC(int x, int y)
{
	std::ofstream newImage = createImage();
	getHeader(newImage, x, y);

	// Pattern
	int rVal, gVal, bVal;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			rVal = (int)(std::abs(std::tan(j)) * i) % 255;
			gVal = (int)std::floor(1 / (std::abs(std::cos(i)) * j)) % 255;
			bVal = (int)(std::abs(1 / std::sin(j)) * i) % 255;
			newImage << rVal << " " << gVal << " " << bVal << std::endl;
		}
	}
	newImage.close();
}

void noise(int x, int y)
{
	std::ofstream newImage = createImage();
	getHeader(newImage, x, y);

	// Pattern
	int rVal, gVal, bVal;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			rVal = rand() % 255;
			gVal = rand() % 255;
			bVal = rand() % 255;
			newImage << rVal << " " << gVal << " " << bVal << std::endl;
		}
	}
	newImage.close();
}