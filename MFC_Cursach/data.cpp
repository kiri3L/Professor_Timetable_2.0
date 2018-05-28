#include "stdafx.h"
#include "data.hpp"

void Data::addProfessor(std::string name)
{
	Professor* prof = new Professor(name);
	professors.push_back(prof);
}


void Data::addLesson(std::string name, std::string auditory, std::string group, std::string type, int koord, Professor* professor, int students)
{
	Lesson* lesson = new Lesson(name, auditory, group, type, koord, professor, students);
	lessons.push_back(lesson);
}
Data::~Data()
{
	for(int i = 0;i < professors.size();++i)
		delete professors[i];
	for(int i = 0;i < lessons.size();++i)
		delete lessons[i];

}
