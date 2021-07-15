#ifndef PATTERNS_HPP

#define PATTERNS_HPP
#include <fstream>
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

// Image Creation
// x->width | y->height
std::ofstream createImage(int x, int y);

// Simple B/W Patterns
void bwA(int x, int y);
void bwB(int x, int y);

// Simple RGB Patterns
void rgbA(int x, int y);
void rgbB(int x, int y);
void rgbC(int x, int y);
void rgbD(int x, int y);

// Mathematical Patterns
void mathA(int x, int y);
void mathB(int x, int y);
void mathC(int x, int y);

// Noise Pattern
void noise(int x, int y);

#endif