#include <cstring>
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include "FileHandler.h"
#include "schedule.h"
#include "stdafx.h"
using namespace std;

void Test();
bool TestCourse();
bool TestFileHandlerReadsAtLeastACourse();
bool TestFileHandlerReads_COP1332();
bool TestSchedule();
bool TestMakeSchedule();
bool TestMySchedule();

int main(int argc, char *argv[])
{

    //Test();
	TestMySchedule();
	system("PAUSE");
    return EXIT_SUCCESS;
}


bool TestMySchedule()
{
	FileHandler * f = new FileHandler();
	Schedule * sch = new Schedule(5, 4, f);
	
	sch->makeSchedule();
	sch->display();
	return true;
}