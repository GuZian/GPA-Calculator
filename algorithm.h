/************************************************************************
/						 GPA Calculator
/
/						   algorithm.h
/
/		  				   by Zian Gu
/           https://github.com/GuZian/GPA-Calculator
/					       08/12/2020
************************************************************************/
#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <string>

/********************************* Base *********************************/
class basicData
{
public:
	basicData();
	void getData();
	void showData() const;
	static int returnNumCourses();
	float calculateUnweightedGPAScale();
	void saveFile(std::string fileName);
	void setScale(std::string scaleName);
	~basicData();
protected:
	unsigned long date;
	static int numCourses;
	float* percentiles;
	float* credits;
	float* points;
	std::string* courseName;
	float GPAResult;
	std::string scale;
};

/************************************************************************/


/********************* Standard Weighted GPA Scale **********************/
class standardWeightedGPAScale :public basicData
{
public:
	standardWeightedGPAScale();
	float calculateStandardWeightedGPAScale();
};


/************************************************************************/

/************************ Standard 4.0 GPA Scale ************************/
class standard4_0GPAScale :public basicData
{
public:
	standard4_0GPAScale();
	float* convertStandard4_0GPAScale();

};

/************************************************************************/

/************************ Canada 4.3 GPA Scale **************************/
class Canada4_3GPAScale :public basicData
{
public:
	Canada4_3GPAScale();
	float* convertCanada4_3GPAScale();
};

/************************************************************************/


/************** Shanghai Jiao Tong University 4.3 GPA Scale *************/
class SJTU4_3GPAScale :public basicData
{
public:
	SJTU4_3GPAScale();
	float* convertSJTU4_3GPAScale();
};

/************************************************************************/

#endif // !ALGORITHM_H