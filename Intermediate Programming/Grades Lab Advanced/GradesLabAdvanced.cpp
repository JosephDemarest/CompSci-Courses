// take input from file (name of student)
// add to one d array
// take input from file (4 avg grades each)
// read into a second array (2d array)
// then based on the average, calculate a letter grade
// store this letter grade in a THIRD array
//  print name, avg, and grade 
// possible issue: array declaration is fixed at 5, which is the same as the input. could add varying array sized based on input. not required.
// possible issue: assuming grade average will be an integer every time. 

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void gradeCalc(char* studentLetter, double* studentAverage); // function declaration

int main()
{
	ifstream input;
	input.open("students.txt"); //open input stream

	string studentName[5]; // self-explanatory
	int studentGrades[5][5]; // self-explanatory (changed to 2d array)
	double studentAverage[5]; // grade average array
	char studentLetter[5]; // self-explanatory
	double sum = 0; // intialize sum to 0
	

	if (!input) // check for file
	{
		cerr << "Cannot locate 'students.txt'";
		exit(-1);
	}


	for (int i = 0; i < 5; i++) // main loop put info in arrays ( since 2d array this loop is for each student )
	{
		input >> studentName[i]; // input student name into string array
		sum = 0; // re initialize sum to 0 for each students loop
		for (int y = 0; y < 4; y++) // input grade for each student (row)
		{
			input >> studentGrades[i][y]; 
			sum += studentGrades[i][y]; // calc avg
			studentAverage[i] = (sum / 4); // put avg into array
		}
	}

	ofstream output;
	output.open("output.txt"); //open output stream

	if (!output) // check for file
	{
		cerr << "Cannot locate 'output.txt'";
		exit(-1);
	}
	
	gradeCalc(studentLetter, studentAverage); // function call

	output << "NAME" << "\t" << "Exam 1" << "\t" << "Exam 2" << "\t" << "Exam 3" << "\t" << "Exam 4" << "\t" << "Average" << "\t" << "Grade" << "\n"; // "header" line 

	for (int a = 0; a < 5; a++) // main loop print info to output file student by student
	{
		output << studentName[a] << "\t"; // print student a's name then tab
		for (int b = 0; b < 4; b++) // print all the grades in the array in row (student) a
		{
			output << studentGrades[a][b] << "\t"; 
		}
		output << studentAverage[a] << "\t" << studentLetter[a] << "\n"; // print the average and the letter grade calculated for row (student) a
	}
	
	input.close();
	cout << "The grades have been calculated!" << endl;
	return 0;
}

void gradeCalc(char* studentLetter, double* studentAverage) // function definition
{
	int length = sizeof(studentLetter) + 1; // get length of letter array to find out how many times to loop
	for (int i = 0; i < length; i++) // calculate student letter grade from average 
	{
		if (studentAverage[i] >= 95)
			studentLetter[i] = 'A';
		else if (studentAverage[i] < 95 && studentAverage[i] >= 85) // self explanatory
			studentLetter[i] = 'B';
		else if (studentAverage[i] < 85 && studentAverage[i] >= 75) // self explanatory
			studentLetter[i] = 'C';
		else if (studentAverage[i] < 75 && studentAverage[i] >= 65) // self explanatory
			studentLetter[i] = 'D';
		else if (studentAverage[i] < 65 && studentAverage[i] > 0) // self explanatory
			studentLetter[i] = 'F';
	}
}

