/************************************************************************
						GPA Calculator

						 algorithm.cpp

			 by Zian Gu, Xufei Bai, Zhiyu Chen, jingwei Xu
						  08/12/2020
************************************************************************/

#include <iostream>
#include "algorithm.h"
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

/*****************   constructor function   ***************************/
basicData::basicData()
{
	//cout << "basic" << endl;
	scale = "NULL";
}

standardWeightedGPAScale::standardWeightedGPAScale()
{
	//cout << "standardWeightedGPAScale"<<endl;
	scale = "Standard Weighted GPA Scale";
}

standard4_0GPAScale::standard4_0GPAScale()
{
	//cout << "standard4_0GPAScale" << endl;
	scale = "Standard 4.0 GPA Scale ";
}

Canada4_3GPAScale::Canada4_3GPAScale()
{
	//cout << "Canada4_3GPAScale" << endl;
	scale = "Canada 4.3 GPA Scale";
}
SJTU4_3GPAScale::SJTU4_3GPAScale()
{
	//cout << "SJTU4_3GPAScale" << endl;
	scale= "Shanghai Jiao Tong University 4.3 GPA Scale";
}

/************************************************************************/

/********************************* Base *********************************/
int basicData::numCourses = 0;

int basicData::returnNumCourses()
{
	return numCourses;
}

void basicData::setScale(string scaleName)
{
	scale = scaleName;
}

void basicData::getData()
{
	cout << endl;
	cout << "Date(YYYYMMDD): ";
	cin >> date;
	cout << "The total of courses: ";
	cin >> numCourses;
	courseName = new string[numCourses];
	percentiles = new float[numCourses];
	points = new float[numCourses];
	cout << endl;
	cin.get();//吸收回车
	for (int i = 0; i < numCourses; i++)
	{
		cout << "Course #" << i + 1 << ": ";
		getline(cin, courseName[i]);
		cout << "Percentile #" << i + 1 << ": ";

		while (!(cin >> percentiles[i]) || percentiles[i] < 0 || percentiles[i]>100)
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "Out of range! Please check your input!" << endl
				<< "Percentile #" << i + 1 << ": ";
		}

		cout << "Points #" << i + 1 << ": ";
		while (!(cin >> points[i]) || points[i] < 0 || points[i]>5)
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "Wrong input! Please check your input!" << endl
				<< "Points #" << i + 1 << ": ";
		}
		cin.get();//吸收回车
		cout << endl;
	}

}
basicData::~basicData()
{
	delete[] courseName;
	delete[] percentiles;
	delete[] points;
	delete[] GPs;
}

void basicData::showData() const
{
	cout << "\n************************   Result   *************************\n\n";
	cout << "Scale: " << scale << endl << endl;
	cout << "Date: " << date << endl << endl;

	cout << setiosflags(ios::left)
		<< setw(20) << "-Courses-"
		<< setw(20) << "-Percentiles-" << endl;
	for (int i = 0; i < numCourses; i++)
	{
		cout << setiosflags(ios::left)
			<< setw(20) << courseName[i]
			<< setw(20) << percentiles[i] << endl;
	}

	cout << endl << setprecision(3)
		<< "GPA: " << GPAResult << endl;
	cout << "\n*************************************************************\n";
}

float basicData::calculateUnweightedGPAScale()
{
	float sumPoints = 0;
	float sumGPxPoints = 0;
	for (int i = 0; i < numCourses; i++)
	{
		sumPoints = sumPoints + points[i];
		sumGPxPoints = sumGPxPoints + points[i] * GPs[i];
	}
	GPAResult = sumGPxPoints / sumPoints;
	return GPAResult;
}

void basicData::saveFile(string fileName)
{
	ofstream outFile(fileName.c_str());
	outFile << "************************   Result   *************************\n\n";
	outFile << "Scale: " << scale << endl << endl;
	outFile << "Date: " << date << endl << endl;

	outFile << setiosflags(ios::left)
		<< setw(20) << "-Courses-"
		<< setw(20) << "-Percentiles-" << endl;
	for (int i = 0; i < numCourses; i++)
	{
		outFile << setiosflags(ios::left)
			<< setw(20) << courseName[i]
			<< setw(20) << percentiles[i] << endl;
	}

	outFile << endl << setprecision(3)
		<< "GPA: " << GPAResult << endl;
	outFile << "\n*************************************************************\n";
}
/************************************************************************/

float standardWeightedGPAScale::calculateStandardWeightedGPAScale()
{
	float sumPoints = 0;
	float sumPercentilexPoints = 0;
	for (int i = 0; i < numCourses; i++)
	{
		sumPoints = sumPoints + points[i];
		sumPercentilexPoints = sumPercentilexPoints + percentiles[i] * points[i];
	}
	GPAResult = (sumPercentilexPoints * 4) / (sumPoints * 100);
	return GPAResult;
}


/************************* Different Scales **************************/
float* standard4_0GPAScale::convertStandard4_0GPAScale()
{
	GPs = new float[numCourses];
	for (int i = 0; i < numCourses; i++)
	{
		if (percentiles[i] >= 0 && percentiles[i] < 60)
		{
			GPs[i] = 0;
		}
		else if (percentiles[i] >= 60 && percentiles[i] < 70)
		{
			GPs[i] = 1.0;
		}
		else if (percentiles[i] >= 70 && percentiles[i] < 80)
		{
			GPs[i] = 2.0;
		}
		else if (percentiles[i] >= 80 && percentiles[i] < 90)
		{
			GPs[i] = 3.0;
		}
		else if (percentiles[i] >= 90 && percentiles[i] <= 100)
		{
			GPs[i] = 4.0;
		}
	}
	return GPs;
}

float* Canada4_3GPAScale::convertCanada4_3GPAScale()
{
	GPs = new float[numCourses];
	for (int i = 0; i < numCourses; i++)
	{
		if (percentiles[i] >= 0 && percentiles[i] < 60)
		{
			GPs[i] = 0;
		}
		else if (percentiles[i] >= 60 && percentiles[i] < 65)
		{
			GPs[i] = 2.3;
		}
		else if (percentiles[i] >= 65 && percentiles[i] < 70)
		{
			GPs[i] = 2.7;
		}
		else if (percentiles[i] >= 70 && percentiles[i] < 75)
		{
			GPs[i] = 3.0;
		}
		else if (percentiles[i] >= 75 && percentiles[i] < 80)
		{
			GPs[i] = 3.3;
		}
		else if (percentiles[i] >= 80 && percentiles[i] < 85)
		{
			GPs[i] = 3.7;
		}
		else if (percentiles[i] >= 85 && percentiles[i] < 90)
		{
			GPs[i] = 4.0;
		}
		else if (percentiles[i] >= 90 && percentiles[i] <= 100)
		{
			GPs[i] = 4.3;
		}
	}
	return GPs;
}

float* SJTU4_3GPAScale::convertSJTU4_3GPAScale()
{
	GPs = new float[numCourses];
	for (int i = 0; i < numCourses; i++)
	{
		if (percentiles[i] >= 0 && percentiles[i] < 60)
		{
			GPs[i] = 0;
		}
		else if (percentiles[i] >= 60 && percentiles[i] < 62)
		{
			GPs[i] = 1.0;
		}
		else if (percentiles[i] >= 62 && percentiles[i] < 65)
		{
			GPs[i] = 1.7;
		}
		else if (percentiles[i] >= 65 && percentiles[i] < 67)
		{
			GPs[i] = 2.0;
		}
		else if (percentiles[i] >= 67 && percentiles[i] < 70)
		{
			GPs[i] = 2.3;
		}
		else if (percentiles[i] >= 70 && percentiles[i] < 75)
		{
			GPs[i] = 2.7;
		}
		else if (percentiles[i] >= 75 && percentiles[i] < 80)
		{
			GPs[i] = 3.0;
		}
		else if (percentiles[i] >= 80 && percentiles[i] < 85)
		{
			GPs[i] = 3.3;
		}
		else if (percentiles[i] >= 85 && percentiles[i] < 90)
		{
			GPs[i] = 3.7;
		}
		else if (percentiles[i] >= 90 && percentiles[i] < 95)
		{
			GPs[i] = 4.0;
		}
		else if (percentiles[i] >= 95 && percentiles[i] <= 100)
		{
			GPs[i] = 4.3;
		}
	}
	return GPs;
}

/************************************************************************/
