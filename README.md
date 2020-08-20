
**********************************************************************************************************************
 #				        GPA Calculator v1.0
 *
 *				             main.cpp
 *
 *
 *
 * This program can be used for calculating GPA in 4 algorithms. Including "Standard Weighted GPA Scale", 
 * "Standard 4.0 GPA Scale", "Canada 4.3 GPA Scale" and  "Shanghai Jiao Tong University 4.3 GPA Scale". Users 
 * only need to choose a GPA scale, and then input their scores in percentile and points accordingly. The 
 * program will calculate the GPA. Users can also save the report as txt format by input Y/y in the last question. 
 * Thank you for your use.
 * The program is used for the final homework of C++ in SNNU.
 *
 * IDE：Visual Studio 2019
 *
 * If you want to experience the program, please double click the executive file in the same directory which is named: GPA Calculator.exe
 * Enjoy now !  
 *                                                          Instructor: Honghong Yang 
 *		            by Zian Gu, Xufei Bai, Zhiyu Chen, Jingwei Xu
 *
 *                                           https://github.com/GuZian/GPA-Calculator
 *			   	         08/12/2020
**********************************************************************************************************************

#GPA Calculator
对于广大要出国留学的学生而言，GPA对于升学是一个非常重要的指标。此外在上海的大学中，期末考试成绩通常直接给出各科绩点和GPA。
本人作为上海生源的学生，也作为准备出国留学的学生，大多数朋友都在上海读大学，在期末分享成绩时由于我校教务系统给出的是百分制成绩，
并非绩点或GPA，也没有在页面换算，因此造成了诸多不便。趁大作业的机会，编写了这个GPA 计算器。
这个计算器有4种算法可以选择，包括标准加权算法、标准4.0算法、加拿大4.3算法、上海交大4.3算法。若无特殊要求，建议选择标准加权算法。
用户只需选择算法，然后输入课程名、百分制成绩和对应学分，程序将自动将百分制成绩换算为单科绩点并计算GPA。

若要运行，请双击同目录下的可执行文件GPA Calculator.exe

运行结果示例：

************    Welcome to GPA calculator!      *************


        [1]: Standard Weighted GPA Scale (Use percentile)

        [2]: Standard 4.0 GPA Scale

        [3]: Canada 4.3 GPA Scale

        [4]: Shanghai Jiao Tong University 4.3 GPA Scale

        [Q/q]: Quit


*************************************************************

Your option: 3
Confirmed your option: 3

The total of courses: 3

Course #1: English
Percentile #1: 92
Credits #1: 3

Course #2: Chinese
Percentile #2: 87
Credits #2: 3

Course #3: C++
Percentile #3: 95
Credits #3: 4


************************   Result   *************************

Scale: Canada 4.3 GPA Scale

Time: 0:14:25, 8/21/2020

-Courses-           -Percentiles-       -Credits-
English               92                       3
Chinese              87                       3
C++                   95                       4

GPA: 4.21

*************************************************************

Do you want to save the data?[Y/N]: Y
File Name: 1.txt

The data have been saved successfully!