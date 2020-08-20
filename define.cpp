/************************************************************************
/						 GPA Calculator
/
/						   define.cpp
/
/		  		by Zian Gu, Xufei Bai, Zhiyu Chen, jingwei Xu
/					       08/12/2020
************************************************************************/

#include <iostream>
#include "declaration.h"

using namespace std;

/*************************** Guider *************************************/
char guider()
{
	char option;
	cout << "\n************\tWelcome to GPA calculator!\t*************\n\n" << endl
		<< "\t[1]: Standard Weighted GPA Scale (Use percentile)\n" << endl
		<< "\t[2]: Standard 4.0 GPA Scale\n" << endl
		<< "\t[3]: Canada 4.3 GPA Scale\n" << endl
		<< "\t[4]: Shanghai Jiao Tong University 4.3 GPA Scale\n" << endl
		<< "\t[Q/q]: Quit\n" << endl
		<< "\n*************************************************************\n"
		<< "\nYour option: ";

	option = cin.get();
	while (cin.get() != '\n')//ֻȡ����ĵ�һ���ַ�������ն�������
	{
		cin.clear();
		continue;
	}
	while (option != '1' && option != '2' && option != '3' && option != '4' && option != 'Q' && option != 'q')//��Ϊѡ���������Ϊ�Ƿ�����
	{
		cout << "Wrong input! Please check your input." << endl
			<< "Your option: ";
		option = cin.get();
		while (cin.get() != '\n')//ֻȡ����ĵ�һ���ַ�������ն�������
		{
			cin.clear();
			continue;
		}
	}
	return option;
}
/************************************************************************/


