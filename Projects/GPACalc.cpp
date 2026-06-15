#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

int main()
{
    //varibles where we will store data received from the user
    int numberofcredits = 0;
    double totalpoints = 0.0;
    int classestaken = 0;

    //allows the program to ask if the wants to add more courses or not
    char choice = 'Y';

    while (choice == 'Y' || choice == 'y')
    {
        std::string input;

        std::cout << "Enter course: (Example: 2A-, 4B. The number: is the amount of credits the class is worth. The letter: is the grade you received): ";
        std::cin >> input;

        int credits = input[0] - '0';
        std::string grade = input.substr(1);

        // converts grade to uppercase
        for (int i = 0; i < grade.length(); i++)
        {
            grade[i] = toupper(grade[i]);
        }

        // converts the letter grade entered into a numerical value
        double gradepoints = -1;

        if (grade == "A+" || grade == "A")
        {
            gradepoints = 4.0;
        }
        else if (grade == "A-")
        {
            gradepoints = 3.7;
        }
        else if (grade == "B+")
        {
            gradepoints = 3.3;
        }
        else if (grade == "B")
        {
            gradepoints = 3.0;
        }
        else if (grade == "B-")
        {
            gradepoints = 2.7;
        }
        else if (grade == "C+")
        {
            gradepoints = 2.3;
        }
        else if (grade == "C")
        {
            gradepoints = 2.0;
        }
        else if (grade == "D")
        {
            gradepoints = 1.0;
        }
        else if (grade == "F" || grade == "WU" ||
                 grade == "FIN" || grade == "FAB")
        {
            gradepoints = 0.0;
        }

        //checks to see if input for the amount of credits is valid or not
        if (credits < 1 || credits > 9)
        {
            std::cout << "Invalid number of credits." << std::endl;
        }
        else if (gradepoints == -1)
        {
            std::cout << "Invalid grade entered." << std::endl;
        }
        else
        {
            //formula for the gpa calculation
            numberofcredits += credits;
            totalpoints += credits * gradepoints;
         classestaken++;

            double gpa = totalpoints / numberofcredits;

            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Classes taken: "
                      << classestaken
                      << ", Semester GPA: "
                      << gpa
                      << std::endl;
        }

        std::cout << "Enter another class? (Y/N): ";
        std::cin >> choice;
        std::cout << std::endl;
    }

    if  (classestaken > 0)
    {
        std::cout << std::fixed << std::setprecision(2);

        std::cout << "Final Results" << std::endl;
        std::cout << "Classes taken: "
                  << classestaken
                  << std::endl;
        std::cout << "Semester GPA: "
                  << totalpoints / numberofcredits
                  << std::endl;
    }

    return 0;
}