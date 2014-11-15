#include "semester.h"

/*******************************************************************************
// Function   : Copy Constructor Semester
// Returns    : -
// Parameters : string id, bool isSummer
// Description: Inizialices the private atributes
//*****************************************************************************/
Semester::Semester(string id, bool isSummer)
		{
			_id = id;
			_isSummer = isSummer;
		}
/*******************************************************************************
// Function   : toStringVector
// Returns    : vector<string> sVector
// Parameters : -
// Description: This function pushes into a vector the header for the semester
//				and the class info for every class contained in the semester
//				using the display function that belongs to the class Course
//*****************************************************************************/
vector<string> Semester::toStringVector()
{
	vector<Course*> myclasses = this->getCourses();
	vector<string> sVector;
	string header= "-----------------------" +this->_id+ "-----------------------";

		sVector.push_back(header);
		for(int i = 0; i < myclasses.size(); i++)
		{
			string classLine = myclasses[i]->display();
			sVector.push_back(classLine);
		}
		
	return sVector;
}