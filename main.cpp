#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to hold Question data
struct Question {
    string questionText;
    vector<string> options;
    int correctAnswerIndex; // 0 for A, 1 for B, 2 for C, 3 for D
};

int main() {
    // 1. Setup the Quiz Questions
    vector<Question> quizBank = {
        {
            "Which of the following is the correct extension of a C++ source file?",
            {".c", ".cpp", ".obj", ".exe"},
            1
        },
        {
            "What does 'STL' stand for in C++?",
            {"Standard Template Library", "Simple Tool Library", "Static Type Language", "Source Tech Layer"},
            0
        },
        {
            "Which keyword is used to allocate memory dynamically in C++?",
            {"malloc", "alloc", "new", "create"},
            2
        },
        {
            "Who created the C++ programming language?",
            {"Dennis Ritchie", "Bjarne Stroustrup", "James Gosling", "Guido van Rossum"},
            1
        }
    };

    int score = 0;
    char charAnswers[] = {'A', 'B', 'C', 'D'};

    cout << "========================================" << endl;
    cout << "      WELCOME TO THE C++ QUIZ!          " << endl;
    cout << "========================================" << endl;
    cout << "Answer by entering A, B, C, or D.\n" << endl;

    // 2. Loop through each question
    for (size_t i = 0; i < quizBank.size(); ++i) {
        cout << "Question " << (i + 1) << ": " << quizBank[i].questionText << endl;

        // Print the multiple-choice options
        for (size_t j = 0; j < quizBank[i].options.size(); ++j) {
            cout << "  " << charAnswers[j] << ") " << quizBank[i].options[j] << endl;
        }

        // 3. Get and validate user input
        char userAnswer;
        bool validAnswer = false;
        int userChoiceIndex = -1;

        while (!validAnswer) {
            cout << "Your Answer: ";
            cin >> userAnswer;
            userAnswer = toupper(userAnswer); // Convert to uppercase to handle 'a' or 'A'

            if (userAnswer == 'A') { userChoiceIndex = 0; validAnswer = true; }
            else if (userAnswer == 'B') { userChoiceIndex = 1; validAnswer = true; }
            else if (userAnswer == 'C') { userChoiceIndex = 2; validAnswer = true; }
            else if (userAnswer == 'D') { userChoiceIndex = 3; validAnswer = true; }
            else {
                cout << "Invalid input. Please enter A, B, C, or D." << endl;
            }
        }

        // 4. Check if the answer is correct
        if (userChoiceIndex == quizBank[i].correctAnswerIndex) {
            cout << ">> Correct!\n" << endl;
            score++;
        } else {
            cout << ">> Wrong. The correct answer was "
                 << charAnswers[quizBank[i].correctAnswerIndex] << ".\n" << endl;
        }
    }

    // 5. Display final results
    cout << "========================================" << endl;
    cout << "              QUIZ OVER!                " << endl;
    cout << "========================================" << endl;
    cout << "Your Final Score: " << score << " / " << quizBank.size() << endl;

    double percentage = (double)score / quizBank.size() * 100;
    cout << "Percentage: " << percentage << "%" << endl;

    if (percentage >= 75) {
        cout << "Great job! You really know your C++." << endl;
    } else if (percentage >= 50) {
        cout << "Not bad, but a little review wouldn't hurt!" << endl;
    } else {
        cout << "Keep practicing and try again!" << endl;
    }

    return 0;
}
