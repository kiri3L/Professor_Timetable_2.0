#pragma once

#include "data.hpp"
#include "ExcelReader.h"
#include <algorithm>
#include <string>
#include <cctype>

class Reader
{
private:
	int checker(std::string);
	void insLesson(Data*, std::string, std::string, std::string, std::string, int, std::string, int);
	void remSpaces(std::string*);

public:
	void startReading(ExcelReader*, Data*);
};
