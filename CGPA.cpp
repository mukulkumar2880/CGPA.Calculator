#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept> // for std::invalid_argument

using namespace std;

// Define named constants for grade points
const double GRADE_A = 4.0;
const double GRADE_A_MINUS = 3.7;
const double GRADE_B_PLUS = 3.3;
const double GRADE_B = 3.0;
const double GRADE_B_MINUS = 2.7;
const double GRADE_C_PLUS = 2.3;
const double GRADE_C = 2.0;
const double GRADE_C_MINUS = 1.7;
const double GRADE_D = 1.0;
const double GRADE_F = 0.0;

// Function to convert letter grade to grade point
double gradeToPoint(const string& grade) {
    if (grade == "A" || grade == "a") return GRADE_A;
    else if (grade == "A-") return GRADE_A_MINUS;
    else if (grade == "B+") return GRADE_B_PLUS;
    else if (grade == "B" || grade == "b") return GRADE_B;
    else if (grade == "B-") return GRADE_B_MINUS;
    else if (grade == "C+") return GRADE_C_PLUS;
    else if (grade == "C" || grade == "c") return GRADE_C;
    else if (grade == "C-") return GRADE_C_MINUS;
    else if (grade == "D") return GRADE_D;
    else return GRADE_F; // F or invalid input
}

// Function to get and validate user input
int getValidInput(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            if (value >= 0) {
                return value;
            } else {
                cout << "Please enter a non-negative value.\n";
            }
        } else {
            cout << "Invalid input. Please enter an integer value.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}

// Function to display individual courses
void displayCourses(const vector<string>& courses, const vector<string>& grades, const vector<int>& creditHours) {
    cout << "\n-------------------------------\n";
    cout << "Course Results:\n";
    cout << "-------------------------------\n";
    for (size_t i = 0; i < courses.size(); ++i) {
        cout << courses[i] << " | Grade: " << grades[i] << " | Credit Hours: " << creditHours[i] << endl;
    }
}

int main() {
    int numCourses = getValidInput("Enter number of courses: ");
    vector<string> courses(numCourses);
    vector<string> grades(numCourses);
    vector<int> creditHours(numCourses);
    double totalGradePoints = 0.0, totalCredits = 0.0;

    // Input for each course
    for (int i = 0; i < numCourses; ++i) {
        cout << "\nEnter name of course " << i + 1 << ": ";
        cin.ignore(); // ignore newline character left in input buffer
        getline(cin, courses[i]);
        cout << "Enter grade (A, B+, C, etc): ";
        cin >> grades[i];
        creditHours[i] = getValidInput("Enter credit hours: ");
        double gpa = gradeToPoint(grades[i]);
        totalGradePoints += gpa * creditHours[i];
        totalCredits += creditHours[i];
    }

    // Display individual courses
    displayCourses(courses, grades, creditHours);

    // Calculate final CGPA
    cout << "\n-------------------------------\n";
    if (totalCredits > 0);

}