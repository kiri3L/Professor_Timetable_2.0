#pragma once

#include <vector>
#include "professor.hpp"
#include "lesson.hpp"

class Data
{
private:


public:
	std::vector<Professor*> professors;
	std::vector<Lesson*> lessons;

	void addProfessor(std::string);
	void addLesson(std::string, std::string, std::string, std::string, int, Professor*, int);

	~Data();
};
