// ************************************************************ CODING CHALLENGE ******************************************************************//
// PROBLEM - Given a list of people with their birth and end years (all between 1900 and 2000), find the year with the most number of people alive
// SOLUTION - i) Create a hash table with year as key & birth, death count, max alive as value 
//			  ii) Loop through data and update the hash table birth and death count as well as maxalive count
//			  iii) Continue step 2 till all values are updated
//			   iv) Loop through the hash table and find highest number of people alive
//	WRITTEN BY - JESSICA JOHN 
//  DATE - 10/18/17 
// *************************************************************************************************************************************************//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
#include <fstream>
using namespace std;

class Person
{
public:
	int birthYear, deathYear;
	string nameOfThePerson;
};

class Year
{
public:
	int year;
	friend bool operator<(const Year &rhs, const Year &lhs)
	{
		return rhs.year < lhs.year;
	}
};

/* Find the year in which maximum number of poeple are alive*/
int maxNumOfPeopleAlive(vector<Person>person, int& count, vector<Person>& result)
{
	map<int, vector<Person>>aliveYear;
	map<int, vector<Person>>::iterator iter;
	aliveYear[1990];

	//Filling in bucket years
	for (int i = 1900; i < 2000; i++)
	{
		for each (Person p in person)
		{
			if (p.birthYear <= i && p.deathYear >= i)
			{
				iter = aliveYear.find(i);
				if (iter != aliveYear.end())
					aliveYear[i].push_back(p);
				else
					aliveYear[i].push_back(p);
			}
		}
	}

	iter = aliveYear.begin();
	int highestYear = iter->first, Maxcount = iter->second.size();
	iter++;

	//Checking which bucket has more people
	for (iter; iter != aliveYear.end(); iter++)
	{
		if (Maxcount < iter->second.size())
		{
			Maxcount = iter->second.size();
			highestYear = iter->first;
		}
	}
	count = Maxcount;
	result = aliveYear[highestYear];
	return highestYear;
}

int main()
{
	srand(time(NULL));

	vector<Person> person;
	int count = 0;
	vector<Person> result;

	/* Reading the text file containing person data */
	ifstream myFile("PersonData.txt");
	if (!myFile.is_open()) std::cout << "Error: File Open" << '\n';
	while (!myFile.eof())
	{
		string personName, birthDate, deathDate;
		getline(myFile, personName, ',');
		getline(myFile, birthDate, ',');
		getline(myFile, deathDate, '\n');
		int bDate, dDate;
		bDate = atof(birthDate.c_str());
		dDate = atof(deathDate.c_str());
		//std::cout << "Name: " << personName << '\n';
		//std::cout << "BirthDate: " << birthDate << '\n';
		//std::cout << "DeathDate: " << deathDate << '\n';
		Person personData;
		personData.nameOfThePerson = personName;
		personData.birthYear = bDate;
		personData.deathYear = dDate;

		person.push_back(personData);
	}
	myFile.close();

	/* Randomly seeding the years and number of people
	for (size_t i = 0; i < 20; i++)
	{
	Person p;
	p.birthYear = rand() % 100 + 1900;
	p.deathYear = rand() % 25 + p.birthYear;
	person.push_back(p);
	}*/

	int year = maxNumOfPeopleAlive(person, count, result);
	std::cout << "The year " << year << " is the year in which maximum number of people were alive!\n" << "And the maximum number of people alive are: " << count << endl;
	std::cout << "Name" << " " << "  Birth" << " " << "Death" << std::endl;
	for (size_t i = 0; i < result.size(); i++)
	{
		std::cout << result[i].nameOfThePerson << " " << result[i].birthYear << " " << result[i].deathYear << std::endl;
	}
	system("pause");
	return 0;
}

