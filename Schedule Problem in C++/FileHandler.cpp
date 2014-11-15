#include <string>
#include <iostream>
#include <fstream>
//#include "stdafx.h"

#include "filehandler.h"

using namespace std;
//Constructor
FileHandler::FileHandler()
{

}
//Function
//*******************************************************************************
//																				*
//NAME:				readFile													*
//DESCRIPTION:		Read from file and initializes Course Class Attributes		*
//RESPONSABILITIES:	Converts char from file into string or int respectively,	*
//					and creates a vector with many pre-Requesites as needed.	*
//RETURN:			Vector of Course classes with members initialized			*
//																				*
//*******************************************************************************
vector<Course> FileHandler::readFile()
{
    ifstream cisCourses;
    cisCourses.open("c.dat", ios::in);
    if (!cisCourses)
	{
		cout << "Error opening file. Program aborting.\n";
		system("PAUSE");
		exit(EXIT_FAILURE);
	}

	vector<Course> allCourses;

	int index = 0;
	string tempInfo = "";
    while(!cisCourses.eof())
    {
		
        Course course;

		
		getline(cisCourses,tempInfo,',');
		course.setCode(tempInfo);
		
		
		getline(cisCourses,tempInfo,',');
		course.setCDescription(tempInfo);
		
		
        getline(cisCourses,tempInfo,',');
		course.setSummer(atoi(tempInfo.c_str()));
		

        getline(cisCourses,tempInfo,',');
		course.setNumPrerequisites(atoi(tempInfo.c_str()));
	    

        getline(cisCourses,tempInfo,',');
		course.setCredit(tempInfo.c_str());
	    
		vector<string> preReqs;
		for(int preq = 0; preq < course.getNumPrerequisites(); preq++)
		{
;
			getline(cisCourses,tempInfo,',');
			preReqs.push_back(tempInfo);
		}
		course.setPrerequisits(preReqs);

		allCourses.push_back(course);
	}
    
    cisCourses.close();
    
	return allCourses;
}
//Destructor
FileHandler::~FileHandler()
{

}
