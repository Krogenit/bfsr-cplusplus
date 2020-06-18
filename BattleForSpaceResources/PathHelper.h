//#ifndef INCLUDED_PATHHELPER
//#define INCLUDED_PATHHELPER

#include <IL\ilut.h>
#include <iostream>

using namespace std;

#pragma once
class PathHelper
{
public:
	static int lastChar;
	static wchar_t* corePath;
	static wchar_t* path;
	static wstring* pathString;
	static void init(bool isDebug);
};

//#endif