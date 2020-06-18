#include "PathHelper.h"

wchar_t *PathHelper::corePath;
wchar_t *PathHelper::path;
int PathHelper::lastChar = 0;
std::wstring* PathHelper::pathString;

void PathHelper::init(bool isDebug)
{
	corePath = new wchar_t[1024];
	GetModuleFileName(NULL, corePath, 1024);
	wcout << "Exe path: " << corePath << endl;

	int lastSlash = 0, prevSlash = 0;

	for (int i = 0; i < 1024; i++)
	{
		if (corePath[i] == '\0')
			break;
		else if (corePath[i] == '\\')
		{
			if (lastSlash == 0)
				lastSlash = i;
			else
			{
				prevSlash = lastSlash;
				lastSlash = i;
			}
		}
	}

	if (isDebug)
		lastChar = prevSlash;
	else
		lastChar = lastSlash;

	path = new wchar_t[lastChar + 1];

	for (int i = 0; i < lastChar; i++)
		path[i] = corePath[i];
	path[lastChar] = '\0';

	delete[] corePath;

	pathString = new wstring(path);

	wcout << "Game path: " << path << endl;
}