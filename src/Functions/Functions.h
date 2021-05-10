#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "../Format/CBitmap.h"
#include "../Shapes/CDrawing.h"

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

void Draw(CDrawing *Drawing);

void Info(CDrawing *Drawing);

void Help();

string newShapeCommand(CDrawing *Drawing);

string ParameterCommand(string parameter);

bool check_Xlocation(int x,  CDrawing* Drawing);
bool check_Ylocation(int y,  CDrawing* Drawing);
bool check_width(int width, int x_pos,  CDrawing* Drawing);
bool check_height(int width, int y_pos,  CDrawing* Drawing);
bool check_radius(int radius, int x_pos, int y_pos,  CDrawing* Drawing);
#endif/*FUNCTIONS_H_*/
