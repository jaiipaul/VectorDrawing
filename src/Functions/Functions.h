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

string newShapeCommand();

string ParameterCommand(string parameter);

#endif/*FUNCTIONS_H_*/
