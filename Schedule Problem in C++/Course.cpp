#include <string>
#include <iostream>
#include <fstream>
#include "course.h"

using namespace std;
/*********************
* default constructor
* @param none
* @return void
*/
Course::Course()
{}
/****************
* My constructor
* @param string code
* @param string description
* @param int summer
* @param int credit
* @param int num of prerequisits
* @string of vectors prerequisit code
*/
Course::Course(string code, string description, int summer, string credit, int numPrerequisits, vector<string> preRequisits)
{   
    this->code = code;
    this->description = description;
    this->summer = summer;
    this->credit = credit;
	this->numPrerequisits = numPrerequisits;
	this->preRequisits=preRequisits;
}

//Setters
/**************************************
* this holds the priorty of the class
* @param int
* @return void
*/
void Course::setPriority(int priority)
{
	this->priority = priority;
}

/*********************
* set the course code 
* @param string
* @return void
*/
void Course::setCode(string code)
{
    this->code = code;
}

/*****************************
* set the course description
* @param string
* @return void
*/
void Course::setCDescription(string description)
{
    this->description = description;
}

/**************************************
* set if it can be taken in the summer
* @param int use for true or false
* @return void
*/
void Course::setSummer(int summer)
{
     this->summer = summer;
}

/**********************************
* sets the credits for each class
* @param string
* @return void
*/
void Course::setCredit(string credit)
{
    this->credit = credit;
}

/*****************************
* set the prerequisit number
* @param int 
* @return void
*/
void Course::setNumPrerequisites(int numPre)
{
	this->numPrerequisits = numPre;
}
/***
* set the code as the prerequisite
* @param vector<string>
* @return void
*/
void Course::setPrerequisits(vector<string> preRequisits)
{
	this->preRequisits = preRequisits;
}

/********************
* returns the code
* @param none
* @return void
*/
string Course::getCode()
{
	return code;
}

/********************************
* returns the course description
* @param none
* @return void
*/
string Course::getCDescription()
{
	return description;
}

/*********************************************************
* returns 1 or 0 if the class can be taken or not in the summer
* @param none
* @return int
*/
int Course::getSummer()
{
	return summer;
}

/********************************************
* returns 1 or 0 if there is a prerequisit
* @param none
* @return void
*/
int Course::getNumPrerequisites()
{
	return numPrerequisits;
}

/********************************
* returns the number of credits
* @param none	
* @return string
*/
string Course::getCredit()
{
	return credit;
}

/**********************************************
* returns the course code of the prerequisite
* @param none
* @return vector<string>
*/
vector<string> Course::getPrerequisits()
{
	return preRequisits;
}

/**************************
* gets priority
* @param none
* @return int
*/
int Course::getPriority()
{
	return priority;
}

/**********************************
* displays the course information
* @param none
* @return string concatanated*/

string Course::display()
{

	string course;
	
	course=  getCredit()+"   " + getCode()+ "   " + getCDescription(); 
						
	return course;
	
}
/*******************
*  destructor
* @param none
*/
Course::~Course()
{
                
}