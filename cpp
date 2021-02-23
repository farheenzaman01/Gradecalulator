
// endofyear.cpp : This file contains the 'main' function. Program execution begins and ends
there.
//
#include "pch.h"
// farheenzamancapstone.cpp : Defines the entry point for the console application.
//
// Capstone project - FarheenZaman.cpp : This file contains the 'main' function. Program
execution begins and ends there
#include <iostream>
#include <string>
#include "pch.h"
#include <fstream>
#include <iomanip>
using namespace std;
// decalre the prototypes//
double calcavg(int grade1, int grade2, int grade3);
void calcmin(int grade1, int grade2, int grade3);
void calcmax(int& max, int grade1, int grade2, int grade3);
int main()
{// decalre all the variable that would be used during the whole programme
int choice;
int studentid;
int grade1;
int grade2;
int grade3;
// initiate a do while loop to keep repeating the menu choice //
do
{// set up the menu for the user to choose //
cout << "MAIN MENU" << endl;
cout << "__________" << endl;
cout << "1. Input a student grade " << endl;
cout << "2. Display all grades " << endl;
cout << "3. Display a Student’s exam statistics" << endl;
cout << "4. Display an Exam’s statistics" << endl;
cout << "5.Exit\n" << endl;
cout << "Enter your choice (1-5) " << endl;
cin >> choice;
// choice one//
if (choice == 1)
{
// declare ofstream variable to open the text file with the users input//
ofstream outfile;
outfile.open("grade.txt");
/// ask the user to enter the student id with the input validation where the id should be in
between 0 to 9999//
cout << "Enter the student id" << endl;
cin >> studentid;
while (studentid < 0 || studentid >= 9999)
{
cout << " id must be between 0 to 9999 , re enter: ";
cin >> studentid;
}
// prompt the user to enter student grades from exam 1 2 and 3//
cout << "Enter grade for exam 1 : " << endl;
cin >> grade1;
while (grade1 < 0 || grade1 >= 100)
{
cout << " grade must be between 0 to 100 , re enter: ";
cin >> grade1;
}
cout << "Enter grade for exam 2 : " << endl;
cin >> grade2;
while (grade2 < 0 || grade2 >= 100)
{
cout << " grade must be between 0 to 100 , re enter: ";
cin >> grade2;
}
cout << "Enter grade for exam 3 : " << endl;
cin >> grade3;
while (grade3 < 0 || grade3 >= 100)
{
cout << " grade must be between 0 to 100 , re enter: ";
cin >> grade3;
}
//this s/ection will print out the user input in to the file//
outfile << "studentid" << " " << "exam1" << " " << "exam2" << " "
<< "exam3" << endl;
outfile << studentid << " " << grade1 << " " << grade2 << " " <<
grade3 << endl;
outfile.close();
system("pause");
}
//choice 2//
if (choice == 2)
{
ifstream inputfile;
string header;
inputfile.open("grade.txt");
// we open the same file that was created on choice 1 and view all the
entered data on the programme screen//
if (inputfile)
{
inputfile >> header >> header >> header >> header;
inputfile >> studentid >> grade1 >> grade2 >> grade3;
cout << left << setw(12) << "studentid" << setw(8) << "exam1" <<
setw(8) << "exam2" << setw(8) << "exam3" << endl;
cout << setw(12) << studentid << setw(8) << grade1 << setw(8)
<< grade2 << setw(8) << grade3;
}
else
{
cout << "Error, text file cannot be opened" << endl;
}
inputfile.close();
system("pause");
}
///In choice 3 prompt the user to search the id in the text file and show the data
entered for it//
//also calculate the average//
if (choice == 3)
{
ifstream inputfile;
int searchid;
double average;
inputfile.open("grade.txt");
cout << "Enter the student id" << endl;
cin >> searchid;
while (inputfile)
{
inputfile >> studentid;
if (studentid == searchid)
{
inputfile.ignore();
inputfile.ignore();
inputfile.ignore();
inputfile.ignore();
inputfile >> studentid >> grade1 >> grade2 >> grade3;
cout << "The grades for the student " << studentid << " are
below:" << endl;
cout << "exam1 :" << grade1 << endl;
cout << "exam2 :" << grade2 << endl;
cout << "exam3 :" << grade3 << endl;
average = (grade1 + grade2 + grade3) / 3.00;
cout << "The average of the students grade is :" <<
average << endl;
}
else {
cout << "search not found" << endl;
}
}
inputfile.close();
}
// In this option you prompt the user to enter the exam to show the data for//
if (choice == 4)
{
int max;
int examnumb;
cout << "Enter the exam number " << endl;
cin >> examnumb;
while (examnumb <= 0 || examnumb > 3)
{
cout << "Enter a number in between 1 to 3" << endl;
cin >> examnumb;
}
if (examnumb = 1)
{
cout << "grade for exam 1 is :" << grade1 << endl;
}
if (examnumb = 2)
{
cout << "grade for exam 2 is :" << grade2 << endl;
}
if (examnumb = 3)
{
cout << "grade for exam 3 is :" << grade3 << endl;
}
else {
cout << "search not found" << endl;
}
//call all the functions written to display the average, minimum and
maximum for the data in the text file//
calcavg(grade1, grade2, grade3);
calcmin(grade1, grade2, grade3);
calcmax(max, grade1, grade2, grade3);
cout << "The maximum exam grade is:" << max << endl;
}
} while (choice != 5);
if (choice == 5)
{
cout << "\nGood Bye!\n";
}
else
{
cout << "\nYou may only enter choice from 1, 2, 3, 4,or 5 from the main
menue.\n";
}
system("pause");
return 0;
}
/// this function calculates the average of all the grades and returns the value//
double calcavg(int grade1, int grade2, int grade3)
{
double average;
average = (grade1 + grade2 + grade2) / 3.00;
cout << "The average of the students grade is :" << average << endl;
return average;
}
//this funtion calculates the minimum of all the grades and is printed back on choice 4//
void calcmin(int grade1, int grade2, int grade3)
{
int min = grade1;
if (grade1 > grade2)
{
min = grade2;
if (grade2 > grade3)
{
min = grade3;
}
}
if (grade1 > grade3)
{
min = grade3;
}
cout << "The minimum exam grade is:" << min << endl;
}
// this function calculates the maximum grade and prints it on choice 4//
void calcmax(int& max, int grade1, int grade2, int grade3)
{
max = grade1;
if (grade1 < grade2)
{
max = grade2;
if (grade2 < grade3)
{
max = grade3;
}
}
if (grade1 < grade3)
{
max = grade3;
}
}
Final Output
