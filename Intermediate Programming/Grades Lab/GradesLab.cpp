// take input from file (name of student)
// add to one d array
// take input from file (avg grade)
// read into a second array
// then based on the average, calculate a letter grade
// store this letter grade in a THIRD array
//  print name, avg, and grade 
// possible issue: array declaration is fixed at 5, which is the same as the input. could add varying array sized based on input. not required.
// possible issue: assuming grade average will be an integer every time. 

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void gradeCalc(char* studentGrade, int* studentAverage); // function declaration

int main()
{
	ifstream input;
	input.open("students.txt"); //open input stream

	string studentName[5]; // self-explanatory
	int studentAverage[5]; // self-explanatory
	char studentGrade[5]; // self-explanatory

	if (!input) // check for file
	{
		cerr << "Cannot locate 'students.txt'";
		exit(-1);
	}

	
	for (int i = 0; i < 5; i++) // main loop put info in arrays
	{
		input >> studentName[i] >> studentAverage[i];
	}

	ofstream output;
	output.open("output.txt"); //open output stream

	if (!output) // check for file
	{
		cerr << "Cannot locate 'output.txt'";
		exit(-1);
	}

	gradeCalc(studentGrade, studentAverage); // function call

	output << "NAME"  << "\t" << "AVERAGE" << "\t" << "GRADE" << "\n"; // "header" line 

	for (int i = 0; i < 5; i++) // main loop print info to output file
	{
		output << studentName[i] << "\t" << studentAverage[i] << "\t" << studentGrade[i] << "\n";
	}

	input.close();
	return 0;
}

void gradeCalc(char* studentGrade, int* studentAverage) // function definition
{
	int length = sizeof(studentGrade) + 1;
	for (int i = 0; i < length; i++)
	{
		if (studentAverage[i] >= 95)
			studentGrade[i] = 'A';
		else if (studentAverage[i] < 95 && studentAverage[i] >= 85)
			studentGrade[i] = 'B';
		else if (studentAverage[i] < 85 && studentAverage[i] >= 75)
			studentGrade[i] = 'C';
		else if (studentAverage[i] < 75 && studentAverage[i] >= 65)
			studentGrade[i] = 'D';
		else if (studentAverage[i] < 65 && studentAverage[i] > 0)
			studentGrade[i] = 'F';
	}
}



