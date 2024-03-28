#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

enum Specialization { COMPUTER_SCIENCE, INFORMATICS, MATH_ECONOMICS, PHYSICS_INFORMATICS, LABOR_TRAINING };

union Grade {
    int programming;
    int numerical_methods;
    int pedagogy;
};

struct Student {
    string surname;
    int course;
    Specialization specialization;
    int physics_grade;
    int math_grade;
    Grade additional_grade;
};

void CreateStudents(Student* students, const int N);
int CalculateAmount(const Student* students, const int N);
void PrintStudents(const Student* students, const int N);

int main() {
    int N;
    cout << "Enter the number of students: ";
    cin >> N;

    Student* students = new Student[N];
    CreateStudents(students, N);

    cout << "\nStudents' table:\n";
    PrintStudents(students, N);

    // Task 1: Calculate count each of grades
    int N3 = 0;
    int N4 = 0;
    int N5 = 0;
    for (int i = 0; i < N; ++i) {
        if (students[i].physics_grade == 3)
            N3++;
        if (students[i].physics_grade == 4)
            N4++;
        if (students[i].physics_grade == 5)
            N5++;
    }
    cout << "The number of 3 in physics : " << N3 << endl;
    cout << "The number of 4 in physics : " << N4 << endl;
    cout << "The number of 5 in physics : " << N5 << endl;

    // Task 2: Calculate number of students who got 4-5 in physics and mathematics
    int Count = CalculateAmount(students, N);
    cout << "Number of students who got 4-5 in physics and mathematics: " << Count << endl;

    delete[] students;
    return 0;
}

void CreateStudents(Student* students, const int N) {
    for (int i = 0; i < N; i++) {
        cout << "Student #" << i + 1 << ":\n";
        cout << "Surname: ";
        cin >> students[i].surname;
        cout << "Course: ";
        cin >> students[i].course;
        cout << "Specialization (0 - Computer Science, 1 - Informatics, 2 - Math and Economics, 3 - Physics and Informatics, 4 - Labor Training): ";
        int specialization;
        cin >> specialization;
        students[i].specialization = static_cast<Specialization>(specialization);
        cout << "Grade in Physics: ";
        cin >> students[i].physics_grade;
        cout << "Grade in Mathematics: ";
        cin >> students[i].math_grade;

        switch (students[i].specialization) {
        case COMPUTER_SCIENCE:
            cout << "Programming grade: ";
            cin >> students[i].additional_grade.programming;
            break;
        case INFORMATICS:
            cout << "Numerical methods grade: ";
            cin >> students[i].additional_grade.numerical_methods;
            break;
        default:
            cout << "Pedagogy grade: ";
            cin >> students[i].additional_grade.pedagogy;
            break;
        }
        cout << endl;
    }
}

int CalculateAmount(const Student* students, const int N) {
    int count = 0;
    for (int i = 1; i <= N; i++)
        if (students[i].physics_grade == 4 || students[i].physics_grade == 5 && students[i].math_grade == 4 || students[i].math_grade == 5)
            count++;
    return count;
}

void PrintStudents(const Student* students, const int N) {
    cout << "========================================================================================================" << endl;
    cout << "| # | Surname       | Course | Specialization               | Physics | Mathematics | Additional Grade |" << endl;
    cout << "--------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 1; i <= N; i++) {
        cout << "| " << setw(1) << right << i << " | ";
        cout << setw(13) << left << students[i].surname << " | ";
        cout << setw(6) << right << students[i].course << " | ";

        switch (students[i].specialization) {
        case COMPUTER_SCIENCE:
            cout << setw(28) << left << "Computer Science" << " | ";
            cout << setw(7) << right << students[i].physics_grade << " | ";
            cout << setw(11) << right << students[i].math_grade << " | ";
            cout << setw(16) << right << students[i].additional_grade.programming << " |" << endl;
            break;
        case INFORMATICS:
            cout << setw(28) << left << "Informatics" << " | ";
            cout << setw(7) << right << students[i].physics_grade << " | ";
            cout << setw(11) << right << students[i].math_grade << " | ";
            cout << setw(16) << right << students[i].additional_grade.numerical_methods << " |" << endl;
            break;
        case MATH_ECONOMICS:
            cout << setw(28) << left << "Math and Economics" << " | ";
            cout << setw(7) << right << students[i].physics_grade << " | ";
            cout << setw(11) << right << students[i].math_grade << " | ";
            cout << setw(16) << right << students[i].additional_grade.pedagogy << " |" << endl;
            break;
        case PHYSICS_INFORMATICS:
            cout << setw(28) << left << "Physics and Informatics" << " | ";
            cout << setw(7) << right << students[i].physics_grade << " | ";
            cout << setw(11) << right << students[i].math_grade << " | ";
            cout << setw(16) << right << students[i].additional_grade.numerical_methods << " |" << endl;
            break;
        case LABOR_TRAINING:
            cout << setw(28) << left << "Labor Training" << " | ";
            cout << setw(7) << right << students[i].physics_grade << " | ";
            cout << setw(11) << right << students[i].math_grade << " | ";
            cout << setw(16) << right << students[i].additional_grade.pedagogy << " |" << endl;
            break;
        }
    }
    cout << "========================================================================================================" << endl;
}