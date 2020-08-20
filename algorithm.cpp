/************************************************************************
						GPA Calculator

						 algorithm.cpp

				   Instructor: Honghong Yang
			 by Zian Gu, Xufei Bai, Zhiyu Chen, Jingwei Xu

			  https://github.com/GuZian/GPA-Calculator
						  08/12/2020
************************************************************************/

#include <iostream>
#include "algorithm.h"
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <ctime>
#pragma warning (disable:4996)

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
	scale = "Shanghai Jiao Tong University 4.3 GPA Scale";
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
	cout << "The total of courses: ";
	cin >> numCourses;
	courseName = new string[numCourses];
	percentiles = new float[numCourses];
	credits = new float[numCourses];
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

		cout << "Credits #" << i + 1 << ": ";
		while (!(cin >> credits[i]) || credits[i] < 0 || credits[i]>5)
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "Wrong input! Please check your input!" << endl
				<< "credits #" << i + 1 << ": ";
		}
		cin.get();//吸收回车
		cout << endl;
	}

}
basicData::~basicData()
{
	delete[] courseName;
	delete[] percentiles;
	delete[] credits;
	delete[] points;
}

void basicData::showData() const
{
	time_t now = time(0);
	tm* ltm = localtime(&now);
	cout << "\n************************   Result   *************************\n\n";
	cout << "Scale: " << scale << endl << endl;
	cout << "Time: " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << ", "
		<< 1 + ltm->tm_mon << "/" << ltm->tm_mday << "/" << 1900 + ltm->tm_year << endl << endl;
	cout << setiosflags(ios::left)
		<< setw(20) << "-Courses-"
		<< setw(20) << "-Percentiles-"
		<< setw(20) << "-Credits-" << endl;

	for (int i = 0; i < numCourses; i++)
	{
		cout << setiosflags(ios::left)
			<< setw(20) << courseName[i]
			<< setw(20) << percentiles[i]
			<< setw(20) << credits[i] << endl;
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
		sumPoints = sumPoints + credits[i];
		sumGPxPoints = sumGPxPoints + credits[i] * points[i];
	}
	GPAResult = sumGPxPoints / sumPoints;
	return GPAResult;
}

void basicData::saveFile(string fileName)
{
	time_t now = time(0);
	tm* ltm = localtime(&now);
	ofstream outFile(fileName.c_str());
	outFile << "************************   Result   *************************\n\n";
	outFile << "Scale: " << scale << endl << endl;
	outFile << "Time: " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << ", "
		<< 1 + ltm->tm_mon << "/" << ltm->tm_mday << "/" << 1900 + ltm->tm_year << endl << endl;
	outFile << setiosflags(ios::left)
		<< setw(20) << "-Courses-"
		<< setw(20) << "-Percentiles-"
		<< setw(20) << "-Credits-" << endl;
	for (int i = 0; i < numCourses; i++)
	{
		outFile << setiosflags(ios::left)
			<< setw(20) << courseName[i]
			<< setw(20) << percentiles[i]
			<< setw(20) << credits[i] << endl;
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
		sumPoints = sumPoints + credits[i];
		sumPercentilexPoints = sumPercentilexPoints + percentiles[i] * credits[i];
	}
	GPAResult = (sumPercentilexPoints * 4) / (sumPoints * 100);
	return GPAResult;
}


/************************* Different Scales **************************/
float* standard4_0GPAScale::convertStandard4_0GPAScale()
{
	points = new float[numCourses];
	for (int i = 0; i < numCourses; i++)
	{
		if (percentiles[i] >= 0 && percentiles[i] < 60)
		{
			points[i] = 0;
		}
		else if (percentiles[i] >= 60 && percentiles[i] < 70)
		{
			points[i] = 1.0;
		}
		else if (percentiles[i] >= 70 && percentiles[i] < 80)
		{
			points[i] = 2.0;
		}
		else if (percentiles[i] >= 80 && percentiles[i] < 90)
		{
			points[i] = 3.0;
		}
		else if (percentiles[i] >= 90 && percentiles[i] <= 100)
		{
			points[i] = 4.0;
		}
	}
	return points;
}

float* Canada4_3GPAScale::convertCanada4_3GPAScale()
{
	points = new float[numCourses];
	for (int i = 0; i < numCourses; i++)
	{
		if (percentiles[i] >= 0 && percentiles[i] < 60)
		{
			points[i] = 0;
		}
		else if (percentiles[i] >= 60 && percentiles[i] < 65)
		{
			points[i] = 2.3;
		}
		else if (percentiles[i] >= 65 && percentiles[i] < 70)
		{
			points[i] = 2.7;
		}
		else if (percentiles[i] >= 70 && percentiles[i] < 75)
		{
			points[i] = 3.0;
		}
		else if (percentiles[i] >= 75 && percentiles[i] < 80)
		{
			points[i] = 3.3;
		}
		else if (percentiles[i] >= 80 && percentiles[i] < 85)
		{
			points[i] = 3.7;
		}
		else if (percentiles[i] >= 85 && percentiles[i] < 90)
		{
			points[i] = 4.0;
		}
		else if (percentiles[i] >= 90 && percentiles[i] <= 100)
		{
			points[i] = 4.3;
		}
	}
	return points;
}

float* SJTU4_3GPAScale::convertSJTU4_3GPAScale()
{
	points = new float[numCourses];
	for (int i = 0; i < numCourses; i++)
	{
		if (percentiles[i] >= 0 && percentiles[i] < 60)
		{
			points[i] = 0;
		}
		else if (percentiles[i] >= 60 && percentiles[i] < 62)
		{
			points[i] = 1.0;
		}
		else if (percentiles[i] >= 62 && percentiles[i] < 65)
		{
			points[i] = 1.7;
		}
		else if (percentiles[i] >= 65 && percentiles[i] < 67)
		{
			points[i] = 2.0;
		}
		else if (percentiles[i] >= 67 && percentiles[i] < 70)
		{
			points[i] = 2.3;
		}
		else if (percentiles[i] >= 70 && percentiles[i] < 75)
		{
			points[i] = 2.7;
		}
		else if (percentiles[i] >= 75 && percentiles[i] < 80)
		{
			points[i] = 3.0;
		}
		else if (percentiles[i] >= 80 && percentiles[i] < 85)
		{
			points[i] = 3.3;
		}
		else if (percentiles[i] >= 85 && percentiles[i] < 90)
		{
			points[i] = 3.7;
		}
		else if (percentiles[i] >= 90 && percentiles[i] < 95)
		{
			points[i] = 4.0;
		}
		else if (percentiles[i] >= 95 && percentiles[i] <= 100)
		{
			points[i] = 4.3;
		}
	}
	return points;
}

/************************************************************************/
