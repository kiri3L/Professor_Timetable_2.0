#pragma once

#include "stdafx.h"
#include "ExcelReader.h"
#include "ExcelWriter.h"
#include "data.hpp"
#include "reader.hpp"
#include "calculate.hpp"
#include "professor.hpp"

class Start
{
	
public:
	std::vector <std::string> listProfs;

	Start();
	Start( std::vector<std::string> );
	void start(CString, Data*, Excel::_ApplicationPtr);
	void uniteSt(Data*, std::vector<std::string> , CString );
	void end(Data*,Excel::_ApplicationPtr, std::string);
	~Start();
};

