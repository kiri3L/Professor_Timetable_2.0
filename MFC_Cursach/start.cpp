#include "stdafx.h"
#include "start.hpp"

Start::Start()
{

}

Start::Start(std::vector<std::string> nameProfs)
{
	int all = nameProfs.size();
	for (int i = 0; i < all; i++)
	{
		listProfs.push_back(nameProfs[i]);
	}
}

void Start::start(CString way, Data* data, Excel::_ApplicationPtr pApp)
{
	ExcelReader* excel = new ExcelReader(way, pApp);
	if (excel->getFlag() == 0)
	{
		Reader* reader = new Reader();
		reader->startReading(excel, data);
		delete reader;
	}
	else
	{
		CString namefile;
		namefile = "Не удалось открыть файл";
		namefile += way;
		MessageBox(NULL,namefile, L"Ошибка", MB_OK | MB_ICONERROR);
	}
	delete excel;
}

void Start::uniteSt(Data* data, std::vector<std::string> mergeProfs, CString newName)
{
	CT2CA tmp(newName);
	std::string name(tmp);
	name = (name.c_str());

	Calculate* calc = new Calculate;
	calc->uniteProfessors(data, mergeProfs, name );
	delete calc;
}

void Start::end(Data * data, Excel::_ApplicationPtr pApp, std::string way)
{
	ExcelWriter* write = new ExcelWriter(way,pApp); //это путь по умолчанию
	int all = listProfs.size();
	std::vector<Cell*> schedule;
	int prof_koord_y = 6;
	write->shablon(all);
	for (int i = 0; i < all; i++)
	{
		Calculate* calc = new Calculate;
		schedule = calc->generateSchedule(listProfs[i], data, prof_koord_y);
		prof_koord_y += 5;
		for (int i = 0; i < schedule.size(); i++)
			write->writeCell(schedule[i]->getKoord_x(), schedule[i]->getKoord_y(), schedule[i]->getText(), schedule[i]->getColor());
		delete calc;
	}
	delete write;
}

Start::~Start()
{
	int all = listProfs.size();
	for (int i = 0; i < all; i++)
		listProfs[i].pop_back(); 
}
