#include "schedule.h"
#include <vector>

/*******************************************************************************
// Function   : Coppy constructor Schedule
// Returns    : -
// Parameters : int maxFallClasses, int maxSummerClasses, FileHandler * f
// Description: This function initializes the private atributes of Schedule class
//*****************************************************************************/
Schedule::Schedule(int maxFallClasses, int maxSummerClasses, FileHandler * f)
{
	_maxFallClasses = maxFallClasses;
	_maxSummerClasses = maxSummerClasses;
	_handler = f;
}

/*******************************************************************************
// Function   : contains
// Returns    : bool
// Parameters : vector<string> prereqs, string aCourse
// Description: This function determines if the strings corresponding to the 
//				vector<string> prereqs is equal to the string corrresponding to
//				the classes atribute code EX: prerequisit CGS1060 = class code COP1332
//*****************************************************************************/
bool Schedule::contains(vector<string> prereqs, string aCourse)
{
	for(int i = 0; i < prereqs.size(); i++)
	{
		if(prereqs[i].compare(aCourse) == 0)
			return true;
	}

	return false;
}

/*******************************************************************************
// Function   : makeSchedule
// Returns    : void
// Parameters : 
// Description: This function creates a 2 dimensional array, populates the array
//				checking where a class is a prerequisite of other and puts a 1
//				there. Then extracts the classes with less prerequsites assigning
//				a priority level and finally sort them by the priority level
//*****************************************************************************/
void Schedule::makeSchedule()
{
	//creates a catalogue containing all the classes in the file
	this->catalog = this->getFileHandler()->readFile();

	//gets size of the catalogue
	int numCourses = this->catalog.size();

	//make adjacency matrix
	vector<vector<int>> adjMatrix;
	for(int i = 0; i < numCourses; i++)
	{
		vector<int> vec(numCourses, 0);
		adjMatrix.push_back(vec);
	}

	//populate adj matrix
	for(int i = 0; i < numCourses; i++)
	{
		int numPreq = catalog[i].getNumPrerequisites();
		for(int j = 0; j < numCourses && numPreq > 0; j++)
		{
			if( contains(catalog[i].getPrerequisits(), catalog[j].getCode()))
			{
				//add connection in adj matrix
				adjMatrix[i][j] = 1;//j is a prereq of i
				adjMatrix[i][i]++;// i has one more prereq
				numPreq--;
			}
		}
	}

	//Adjacency matrix is done now!
	
	//Set priorities
	int numCoursesScheduled = 0;
	int priority = 1;

	vector<vector<int>> cpyAdjMatrix = adjMatrix;

	while(numCoursesScheduled < this->catalog.size())
	{
		for(int i = 0; i < numCourses; i++)
		{
			if(adjMatrix[i][i] == 0)
			{
				this->catalog[i].setPriority(priority);
				cpyAdjMatrix[i][i]--;
				numCoursesScheduled++;

				for(int j = 0; j < numCourses; j++)
				{
					if(adjMatrix[j][i] > 0)
					{
						cpyAdjMatrix[j][j]--;
					}
				}
			}
		}

		priority++;
		adjMatrix = cpyAdjMatrix;
	}

    //Sorting: for some reason the c++ sorting algorithm was giving me a hard time
	//so I use this sorting
	int pivot = 0;

	while(pivot < this->catalog.size())
	{
		int min = catalog.size();
		int minIndex = 0;
		for(int i = pivot; i < this->catalog.size(); i++)
		{
			if(this->catalog[i].getPriority() < min)
			{
				min = this->catalog[i].getPriority();
				minIndex = i;
			}
		}

		Course temp = this->catalog[minIndex];
		this->catalog[minIndex] = this->catalog[pivot];
		this->catalog[pivot] = temp;
		pivot++;
	}
	
	//make semesters
	makeSemesters();
}

/*******************************************************************************
// Function   : makeSemesters
// Returns    : void
// Parameters : 
// Description: This function creates the semesters and adds the corresponding 
//				courses to the semesters. Also handles that a class can not be
//				printed in summer
//*****************************************************************************/
void Schedule::makeSemesters()
{
	Semester * fallA = new Semester("FALL A", false);
	Semester * springA = new Semester("SPRING A", false);
	Semester * summerA = new Semester("SUMMER A", true);
	Semester * fallB = new Semester("FALL B", false);
	Semester * springB = new Semester("SPRING B", false);
	Semester * summerB = new Semester("SUMMER B", true);

	
	this->_schedule.push_back(fallA);
	this->_schedule.push_back(springA);
	this->_schedule.push_back(summerA);
	this->_schedule.push_back(fallB);
	this->_schedule.push_back(springB);
	this->_schedule.push_back(summerB);

	int count = 0;
	int index = 0;
	
	while(count < this->getFallClasses())
	{
		fallA->AddCourse(&(this->catalog[index]));
		count++;
		index++;
		if(index >= this->catalog.size())
			return;
	}

	count = 0;
	while(count < this->getFallClasses())
	{
		springA->AddCourse(&(this->catalog[index]));
		count++;
		index++;

		if(index >= this->catalog.size())
			return;
	}

	count = 0;
	while(count < this->getSummerClasses())
	{
		
		if((this->catalog[index].getSummer())==0&&(this->catalog[index++].getSummer())!=0)
		{
			int increment =	index++;	
			summerA->AddCourse(&(this->catalog[increment]));
			swap( (this->catalog[index]), (this->catalog[increment]) );
			
			index = (increment--);	
			count++;
			index++;
			
			if (index >= this->catalog.size())
			return;
		}
		else 
		{
			summerA->AddCourse(&(this->catalog[index]));
			count++;
			index++;

			if(index >= this->catalog.size())
				return;
		}
	}

	count = 0;
	while(count < this->getFallClasses())
	{
		fallB->AddCourse(&(this->catalog[index]));
		count++;
		index++;

		if(index >= this->catalog.size())
			return;
	}

	count = 0;
	while(count < this->getFallClasses())
	{
		springB->AddCourse(&(this->catalog[index]));
		count++;
		index++;

		if(index >= this->catalog.size())
			return;
	}

	count = 0;
	while(count < this->getSummerClasses())
	{		
			if((this->catalog[index].getSummer())==0&&(this->catalog[index++].getSummer())!=0)
		{
			int increment =	index++;	
			summerB->AddCourse(&(this->catalog[increment]));
			swap( (this->catalog[index]), (this->catalog[increment]) );
			
			index = (increment--);	
			count++;
			index++;
			
			if (index >= this->catalog.size())
			return;
		}
		else 
		{
			summerB->AddCourse(&(this->catalog[index]));
			count++;
			index++;

			if(index >= this->catalog.size())
				return;
		}
		
	}
	
}

/*******************************************************************************
// Function   : toStringVector
// Returns    : vector<string> schInfo
// Parameters : 
// Description: This function prints the suggested schedule calling the toString
//				method from Semester
//*****************************************************************************/
vector<string> Schedule::toStringVector()
{
		vector<Semester*> sch = this->getSchedule();
		vector<string> schInfo;

		string headerStr = "-------------SUGGESTED SCHEDULE--------------";

		schInfo.push_back(headerStr);

		for(int i = 0; i < sch.size(); i++)
		{
			vector<string> semesterLines = sch[i]->toStringVector();
			
			for(int j = 0; j < semesterLines.size(); j++)
			{
				schInfo.push_back(semesterLines[j]);
			}
		}

		return schInfo;
}

/*******************************************************************************
// Function   : destructor ~Schedule
// Returns    : void
// Parameters : -
// Description: Deletes all dinamically allocated memory
//*****************************************************************************/
Schedule::~Schedule()
{
	
}