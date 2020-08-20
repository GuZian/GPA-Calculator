/************************************************************************
 *					GPA Calculator
 *
 *					   main.cpp
 *
 *
 *
 * This program can be used for calculating GPA in 4 algorithms. Including "Standard Weighted GPA Scale", "Standard 4.0 GPA Scale", "Canada 4.3 GPA Scale" and  "Shanghai Jiao Tong University 4.3 GPA Scale". Users only need to choose a GPA scale, and then input their scores in percentile and points accordingly. The program will calculate the GPA. Users can also save the report as txt format by input Y/y in the last question. Thank you for your use.
 * The program is used for the final homework of C++ in SNNU.
 *
 *              Instructor: Honghong Yang
 *		 by Zian Gu, Xufei Bai, Zhiyu Chen, Jingwei Xu
 *
 *         https://github.com/GuZian/GPA-Calculator
 *					  08/12/2020
************************************************************************/

#include <iostream>
#include<string>
#include "declaration.h"
#include "algorithm.h"

using namespace std;

int main()
{
	char option;
	standardWeightedGPAScale swgs;
	standard4_0GPAScale s4_0gs;
	Canada4_3GPAScale c4_3gs;
	SJTU4_3GPAScale s4_3gs;
	basicData* basic = NULL;
	cout << "Confirmed your option: " << (option = guider()) << endl;
	switch (option)
	{
	case 'Q':
	case 'q':
	{
		cout << "\nThank you for your use!";
		cin.get();
		exit(0);
	} break;//Quit
	case '1':				//Standard Weighted GPA Scale (Use percentile)
	{
		swgs.getData();
		swgs.calculateStandardWeightedGPAScale();
		//swgs.setScale("Standard Weighted GPA Scale (Use percentile)");
		swgs.showData();
		basic = &swgs;
	}break;
	case '2':				//Standard 4.0 GPA Scale
	{
		s4_0gs.getData();
		s4_0gs.convertStandard4_0GPAScale();
		s4_0gs.calculateUnweightedGPAScale();
		//s4_0gs.setScale("Standard 4.0 GPA Scale");
		s4_0gs.showData();
		basic = &s4_0gs;
	}break;
	case '3':				//Canada 4.3 GPA Scale
	{
		c4_3gs.getData();
		c4_3gs.convertCanada4_3GPAScale();
		c4_3gs.calculateUnweightedGPAScale();
		//c4_3gs.setScale("Canada 4.3 GPA Scale");
		c4_3gs.showData();
		basic = &c4_3gs;
	}break;
	case '4':				//Shanghai Jiao Tong University 4.3 GPA Scale
	{
		s4_3gs.getData();
		s4_3gs.convertSJTU4_3GPAScale();
		s4_3gs.calculateUnweightedGPAScale();
		//s4_3gs.setScale("Shanghai Jiao Tong University 4.3 GPA Scale");
		s4_3gs.showData();
		basic = &s4_3gs;
	}break;
	default:break;
	}

	cout << "\nDo you want to save the data?[Y/N]: ";
	if (cin.get() == 'Y' || cin.get() == 'y')
	{
		string fileName;
		cout << "File Name: ";
		cin >> fileName;
		basic->saveFile(fileName);
		cout << "\nThe data have been saved successfully! " << endl;
	}
	else//只要不是Y/y，一律不保存
	{
		cout << "\nThank you for your use!" << endl;
		cin.get();
		exit(0);
	}

	return 0;
}