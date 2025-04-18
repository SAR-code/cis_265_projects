/*
* SCRIPT: StructsEnums.c
* PURPOSE: This program is designed to work with structures
*	   and enumerations in C. The project utilizes the
*          CSV file "student database.txt"
* AUTHOR: D.M
* DATE: 17APR25
*
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 100
#define MAJOR_LENGTH 100
#define FILE_NAME "student database.txt"

// Define structs to enumerate the campuses
typedef enum {
	DOWNTOWN,
	EAST,
	WEST,
	NOT_LISTED
} Campus;


// Define structs to hold student information
typedef struct {
	int id;
	char name[MAX_NAME_LENGTH];
	char major[MAJOR_LENGTH];
	Campus campus;
} Student;


// Function prototypes
void startProgram();
int readStudentsFromFile(const char* filename, Student students[]);
void displayStudents(const Student students[], int numStudents);
void searchStudentId(const Student students[], int numStudents, int searchId);
void countStudentsPerCampus(const Student students[], int numStudents);
Campus parseCampus(const char* campusStr);
const char* getCampusLocation(Campus campus);

int main()
{
	// starts the program
	startProgram();
}


/**********************************************************************************
*										  *
* void startProgram()							          *
* Purpose: This function starts the program by reading the data from the file and *
*          prompts the user to make a selection to manipulate the data utilizing  *
*          loops and switch cases.                                                *
**********************************************************************************/

void startProgram()
{
	// Declare an array of students
	Student students[MAX_STUDENTS];

	// Read the student data from the file
	int numStudents = readStudentsFromFile("student database.txt", students);

	// Ensure the data was read successfully
	if (numStudents == -1) {
		printf("Error reading student data from file.\n");
		return;
	}
	
	// Prompt the user for a selection

	char selection;

	// do while loop to prompt the user for a selection

	do {
		printf("\nStudent Database Menu:\n");
		printf("Press (D) to display all students records information\n");
		printf("Press (S) to search and display a student information by student ID\n");
		printf("Press (C) to count the number of students per campus\n");
		printf("Press (Q) to quit\n");
		printf("Enter your selection: ");
		scanf(" %c", &selection);
		selection = toupper(selection);

		switch (selection) {
			case 'D':

				// Display all students
				displayStudents(students, numStudents);
				break;
			case 'S': {

				// Search for student by ID
				int searchId;
				printf("Enter student ID: ");
				scanf("%d", &searchId);

				// invoke function to search for student by ID
				searchStudentId(students, numStudents, searchId);
				break;
			}
			case 'C':

				// Count the number of students per campus
				countStudentsPerCampus(students, numStudents);
				break;

			case 'Q':

				// Exit the program
				printf("Exiting the program.\n");
				break;
			default:

				// Checks for invalid selection
				printf("Invalid selection. Please try again.\n");
				break;
		}

	} while (selection != 'Q');

	return 0;
}


/**********************************************************************************
*										  *
* int readStudentsFromFile(const char* filename, Student students[])		  *
* Purpose: This function reads the student data from the student database.txt     *
*          file and populates the students array.                                 *
**********************************************************************************/

int readStudentsFromFile(const char* filename, Student students[])
{
	// Opens the file for reading
	FILE* file = fopen(filename, "r");

	if (file == NULL) {
		return -1;
	}

	// Declare variables to track the lines and read the data
	int count = 0;
	char line[256];

	// While loop to read each line from the file
	while (fgets(line, sizeof(line), file) && count < MAX_STUDENTS)
	{
		// Parse student ID
		char* token = strtok(line, ",");
		if (!token) continue;
		students[count].id = atoi(token);

		// Parse student name
		token = strtok(NULL, ",");
		if (!token) continue;
		strncpy(students[count].name, token, MAX_NAME_LENGTH);

		// Parse student major
		token = strtok(NULL, ",");
		if (!token) continue;
		strncpy(students[count].major, token, MAJOR_LENGTH);

		// Parse student campus
		token = strtok(NULL, ",");
		if (!token) continue;
		students[count].campus = parseCampus(token);

		// Increment the student count
		count++;
	}

	// Closes the file
	fclose(file);
	return count;
}


/***********************************************************************************
* 										   *
* void displayStudents(const Student students[], int numStudents)		   *
* Purpose: This function displays all the students' information in the database.   *
* *********************************************************************************/

void displayStudents(const Student students[], int numStudents)
{
	// Display the student information
	printf("\n%-10s %-25s %-25s %-15s\n", "ID", "Name", "Major", "Campus");
	for (int i = 0; i < numStudents; i++) {
		printf("%-10d %-25s %-25s %-15s\n",
			students[i].id,
			students[i].name,
			students[i].major,
			getCampusLocation(students[i].campus));
	}
}


/***************************************************************************************
* 										       *
* void searchStudentId(const Student students[], int numStudents, int searchId)        *
* Purpose: This function searches for a student by ID and displays their information.  *
* *************************************************************************************/

void searchStudentId(const Student students[], int numStudents, int searchId)
{
	// Search for the student by ID
	for (int i = 0; i < numStudents; i++) {
		if (students[i].id == searchId) {
			printf("\nStudent ID: %d\n", students[i].id);
			printf("Name: %s\n", students[i].name);
			printf("Major: %s\n", students[i].major);
			printf("Campus: %s\n", getCampusLocation(students[i].campus));
			return;
		}
	}
	// If the student is not found
	printf("Student with ID %d not found.\n", searchId);
}


/***************************************************************************************
* 										       *
* void countStudentsPerCampus(const Student students[], int numStudents)               *
* Purpose: This function counts the number of students per campus and displays the     *
* 	   results.                                                                    *
* *************************************************************************************/

void countStudentsPerCampus(const Student students[], int numStudents)
{
	// Declare variables to count the number of students per campus
	int downtown = 0;
	int east = 0;
	int west = 0;

	// Loop to count the number of students per campus
	for (int idx = 0; idx < numStudents; idx++)
	{
		switch (students[idx].campus) {
		case DOWNTOWN:
			downtown++;
			break;
		case EAST:
			east++;
			break;
		case WEST:
			west++;
			break;
		default:
			break;
		}
	}

	// Display the results
	printf("\nNumber of students per campus:\n");
	printf("East Campus: %d students\n", east);
	printf("West Campus: %d students\n", west);
	printf("Downtown Campus: %d students\n", downtown);
}


/***************************************************************************************
* 										       *
* Campus parseCampus(const char* campusStr)                                            *
* Purpose: This function parses the campus string and returns the corresponding enum.  *
* *************************************************************************************/

Campus parseCampus(const char* campusStr)
{

	// Compares the campus string to the enum values
	if (strstr(campusStr, "Downtown") != NULL) {
		return DOWNTOWN;
	}
	else if (strstr(campusStr, "East") != NULL) {
		return EAST;
	}
	else if (strstr(campusStr, "West") != NULL) {
		return WEST;
	}
	else {
		return NOT_LISTED;
	}
}


/***************************************************************************************
* 										       *
* const char* getCampusLocation(Campus campus)                                         *
* Purpose: This function returns the campus location as a string.		       *
* *************************************************************************************/

const char* getCampusLocation(Campus campus)
{
	// Returns the campus location as a string
	switch (campus) {
	case DOWNTOWN:
		return "Downtown";
	case EAST:
		return "East";
	case WEST:
		return "West";
	default:
		return "Not Listed";
	}
}

