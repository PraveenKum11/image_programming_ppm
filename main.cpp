#include "Patterns.hpp"
#include "Filter.hpp"
using namespace std;

int main()
{
	// This for random naming of the output files from pattern generation
	srand(time(0));

	/* NOTE
	One object can have only one filter at a time due the way they are written.
	Trying to apply more than one filter at a time will only apply the first filter and the
	second one will simply fail to load the image.

	If you want to apply more than one filter to an image you can pass the output of the previous
	run as an input in a new object. */

	// To apply a filter to a ppm image pass it as the first argument in constructor and the
	// second argument wil be you ouput file name, if the output is a sub-directory make sure it exists.

	Filter f1("input/mikasa.ppm", "output/output1.ppm");
	Filter f2("input/mikasa.ppm", "output/output2.ppm");
	Filter f3("input/mikasa.ppm", "output/output3.ppm");
	Filter f4("input/mikasa.ppm", "output/output4.ppm");
	Filter f5("input/mikasa.ppm", "output/output5.ppm");
	Filter f6("input/mikasa.ppm", "output/output6.ppm");

	f1.blueFilter();
	f2.greenFilter();
	f3.redFilter();
// 	This filter is does not work perfectly, so some image viewer do have hard time opening it.
	f4.blurFilter();
	f5.thresholdFilter();
	f6.invertThresholdFilter();


	// To generate random pattern you just need to call one of these functions and you will get your
	// output in the data folder.

	/* These define the dimensions for the output from pattern genration */
	// int width = 250;
	// int height = 250;

	/* Functions to create random patterns */
	// bwA(width, height);
	// bwB(width, height);
	// rgbA(width, height);
	// rgbB(width, height);
	// rgbC(width, height);
	// rgbD(width, height);
	// mathA(width, height);
	// mathB(width, height);
	// mathC(width, height);
	// noise(width, height);
}