//---------------------------------------------------------------------------------------------------------------------------------------------
//  College:                            Delaware Techincal Community College
//  Course:                             CSC 114: Intro to Computer Science
//  Instructor:                         Instructor Mike (Thompson)
//  Author:                             Alejandro Pantoja-Zurita
//  Deliverables:                       Final Project
//  Date:                               04/12/2025
//  Attributions:                       Program used to provide a letter grade to students based on input files provided. 
//  CSC114-Final Project.cpp:			This file contains multiple functions. Program executions beings and ends within the main function.
//---------------------------------------------------------------------------------------------------------------------------------------------
//	Code used to obtain & seperate information from 'scores.txt' file was provided in 'read_csv_sample.cpp' file from 'Exam4.zip'. Code is used
//	to read information correctly (seperate information and remove comma's) inside of file to interpret correctly inside this program.
//---------------------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

// Constant values provided by assignment for program
const int students = 10;
const int courses = 5;

// Declare Function prototypes
void programBanner();
bool inputStudentNames(string [students]);
bool inputStudentScores(int[students][courses]);
void gradeCalculations(char[students],char[students][courses], float[students], int[students][courses]);
void exportGrades(string[students], char[students], char[students][courses], float[students], int[students][courses]);


int main()
{
	string studentNames[students];
	int courseScores[students][courses];
	char courseGrade[students][courses];
	float finalNumberGrade[students];
	char finalLetterGrade[students];

	bool endprogram = false;

	int i;
	int j;

	programBanner();

	// Obtain student names from 'studentNames.txt' file
	endprogram = inputStudentNames(studentNames);

	// test to ensure studentNames are imported successfully.
	if (endprogram == 1)
		return 0;
	
	// Obtain student scores from 'score.txt' file
	endprogram = inputStudentScores(courseScores);

	// test to ensure student scores were imported successfully.
	if (endprogram == 1)
		return 0;

	// Calculate student final grades.
	gradeCalculations(finalLetterGrade, courseGrade, finalNumberGrade, courseScores);
	
	// Confirm student names imported succesffully [for testing purposes]
	//cout << "Dispalying student information below for confirmation:\n\n";
	//cout << "------------------------------------------------------------------------------------------------------\n\n";
	//for (i = 0; i < students; i++)
	//{
	//	cout << "STUDENT #" << i + 1 << ": " << studentNames[i] << "\n\n";
	//	cout << "AVERAGE GRADE: " << finalLetterGrade[i] << " - AVERAGE SCORE: " << fixed << setprecision(2) << finalNumberGrade[i] << "\n\n";
	//	for (j = 0; j < courses; j++)
	//	{
	//		cout << "Course #" << j + 1 << " Grade: " << courseGrade[i][j] << " - Score: " << courseScores[i][j] << "\n";
	//	}
	//	cout << "\n------------------------------------------------------------------------------------------------------\n";
	//}
	//cout << "\n";

	exportGrades(studentNames, finalLetterGrade, courseGrade, finalNumberGrade, courseScores);

	return 0;
}

// Function for program banner.
void programBanner()
{
	cout << "Delaware Technical Community College\n";
	cout << "CSC 114: Final Project\n";
	cout << "Name: Alejandro Pantoja Zurita\n";
	cout << "Instructor: Mike Thompson\n";
	cout << "------------------------------------------------------------------------------------------------------\n";
	cout << "                                         -- Student Grades --                                         \n";
	cout << "------------------------------------------------------------------------------------------------------\n";
	cout << "This program is used to calculate student grades for the semester. 'studentNames.txt' & 'scores.txt'\n";
	cout << "files must be used in order to calculate the correct letter grade for each student.\n\n";
	cout << "Grade calculations are based on Delaware Technical Community College's grading policy.\n";
	cout << "------------------------------------------------------------------------------------------------------\n\n";
}

// Function used to obtain student names from 'studentNames.txt'.
bool inputStudentNames(string name[students])
{
	fstream nameFile("studentNames.txt");
	int i;

	// Display # inside input.txt file to confirm with user correct numbers.
	if (nameFile.is_open())
	{
		cout << "'studentNames.txt' file opened successfully...\n\n";

		for (i = 0; i < students; i++)
		{
			nameFile >> name[i];
		}

		nameFile.close();
		cout << "------------------------------------------------------------------------------------------------------\n\n";
		return 0;
	}
	else
	{
		cout << "Error! unable to open 'studentNames.txt' file.\n\n";
		cout << "Please ensure file is avaialable with student names for program to operate correctly.\n\n";
		cout << "------------------------------------------------------------------------------------------------------\n\n";
		return 1;
	}
}

// Function used to obtain student scores from 'scores.txt'.
bool inputStudentScores(int scores[students][courses])
{
	string line;
	string word;

	fstream scoresFile("scores.txt");

	// Display # inside input.txt file to confirm with user correct numbers.
	if (scoresFile.is_open())
	{
		cout << "'scores.txt' file opened successfully...\n\n";

		int rw = 0;
		while (getline(scoresFile,line))
		{
			int cl = 0;
			stringstream str(line);

			while (getline(str, word, ','))
			{
				scores[rw][cl++] = stoi(word);
			}

			rw++;
		}

		scoresFile.close();
		cout << "------------------------------------------------------------------------------------------------------\n\n";
		return 0;
	}
	else
	{
		cout << "Error! unable to open 'scores.txt' file.\n\n";
		cout << "Please ensure file is avaialable with student names for program to operate correctly.\n\n";
		cout << "------------------------------------------------------------------------------------------------------\n\n";
		return 1;
	}
}

// Function used to calculate student grades.
void gradeCalculations(char letterGrade[students], char letterScores[students][courses], float numberGrade[students], int numberScores[students][courses])
{
	int i;
	int j;

	for (i = 0; i < students; i++)
	{
		numberGrade[i] = 0;

		for (j = 0; j < courses; j++)
		{
			numberGrade[i] = numberGrade[i] + numberScores[i][j];

			if (numberScores[i][j] > 89)
			{
				letterScores[i][j] = 'A';
			}
			else if (numberScores[i][j] > 79)
			{
				letterScores[i][j] = 'B';
			}
			else if (numberScores[i][j] > 69)
			{
				letterScores[i][j] = 'C';
			}
			else
			{
				letterScores[i][j] = 'F';
			}
		}

		numberGrade[i] = numberGrade[i] / 5;

		if (numberGrade[i] > 89)
		{
			letterGrade[i] = 'A';
		}
		else if (numberGrade[i] > 79)
		{
			letterGrade[i] = 'B';
		}
		else if (numberGrade[i] > 69)
		{
			letterGrade[i] = 'C';
		}
		else
		{
			letterGrade[i] = 'F';
		}
	}
}

// Function used to export student grades information to 'grades.txt' file.
void exportGrades(string name[students], char finalLetterGrade[courses], char courseGrade[students][courses], float finalNumberGrade[students], int courseScore[students][courses])
{
	// Export estimate to file.
	ofstream programFile("grades.txt");

	if (programFile.is_open())
	{
		int i;
		int j;

		cout << "'grades.txt' file created successfully...\n\n";
		cout << "------------------------------------------------------------------------------------------------------\n\n";

		programFile << "Delaware Technical Community College\n";
		programFile << "CSC 114: Final Project\n";
		programFile << "Name: Alejandro Pantoja Zurita\n";
		programFile << "Instructor: Mike Thompson\n";
		programFile << "------------------------------------------------------------------------------------------------------\n";
		programFile << "                                         -- Student Grades --                                         \n";
		programFile << "------------------------------------------------------------------------------------------------------\n";
		programFile << "This file was created store student's final grades for the semester. 'studentNames.txt' & 'scores.txt'\n";
		programFile << "files were used in order to calculate the correct letter grade for each student inside the program.\n\n";
		programFile << "Grade calculations are based on Delaware Technical Community College's grading policy.\n";
		programFile << "------------------------------------------------------------------------------------------------------\n\n";

		for (i = 0; i < students; i++)
		{
			programFile << "STUDENT #" << i + 1 << ": " << name[i] << "\n\n";
			programFile << "AVERAGE GRADE: " << finalLetterGrade[i] << " - AVERAGE SCORE: " << fixed << setprecision(2) << finalNumberGrade[i] << "\n\n";
			for (j = 0; j < courses; j++)
			{
				programFile << "Course #" << j + 1 << " Grade: " << courseGrade[i][j] << " - Score: " << courseScore[i][j] << "\n";
			}
			programFile << "\n------------------------------------------------------------------------------------------------------\n";
		}
		programFile << "\n";

		programFile.close();

		cout << "See 'grade.txt' file for finalized student grades.\n\n";
		cout << "------------------------------------------------------------------------------------------------------\n\n";
	}
	else
	{
		cout << "Error! unable to create 'grades.txt' file\n\n";
		cout << "------------------------------------------------------------------------------------------------------\n\n";
	}
}
