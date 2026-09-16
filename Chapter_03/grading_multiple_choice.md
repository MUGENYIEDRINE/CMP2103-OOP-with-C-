# Student Answer Grading Program

## Description

This C++ program grades the answers of **8 students** who answered **10 multiple-choice questions**.

It compares each student's answers with the correct answer key and displays the number of correct answers for every student.

## C++ Code

```cpp
#include <iostream>
using namespace std;

int main() {
    const int NUMBER_OF_STUDENTS = 8;
    const int NUMBER_OF_QUESTIONS = 10;

    // Two-dimensional array storing students' answers
    char answers[NUMBER_OF_STUDENTS][NUMBER_OF_QUESTIONS] = {
        {'A', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'D', 'B', 'A', 'B', 'C', 'A', 'E', 'E', 'A', 'D'},
        {'E', 'D', 'D', 'A', 'C', 'B', 'E', 'E', 'A', 'D'},
        {'C', 'B', 'A', 'E', 'D', 'C', 'E', 'E', 'A', 'D'},
        {'A', 'B', 'D', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'B', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'B', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'E', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}
    };

    // One-dimensional array storing the correct answer key
    char key[NUMBER_OF_QUESTIONS] =
        {'D', 'B', 'D', 'C', 'C', 'D', 'A', 'E', 'A', 'D'};

    // Grade all answers
    for (int i = 0; i < NUMBER_OF_STUDENTS; i++) {
        int correctCount = 0;

        for (int j = 0; j < NUMBER_OF_QUESTIONS; j++) {
            if (answers[i][j] == key[j]) {
                correctCount++;
            }
        }

        cout << "Student " << i + 1
             << "'s correct count is "
             << correctCount << endl;
    }

    return 0;
}
```

## Expected Output

```text
Student 1's correct count is 6
Student 2's correct count is 7
Student 3's correct count is 5
Student 4's correct count is 5
Student 5's correct count is 8
Student 6's correct count is 7
Student 7's correct count is 8
Student 8's correct count is 6
```

## How the Program Works

### 1. Constants

```cpp
const int NUMBER_OF_STUDENTS = 8;
const int NUMBER_OF_QUESTIONS = 10;
```

These constants specify that there are 8 students and 10 questions.

### 2. Two-dimensional array

```cpp
char answers[NUMBER_OF_STUDENTS][NUMBER_OF_QUESTIONS];
```

The array stores the answers of all students.

- Each **row** represents one student.
- Each **column** represents one question.

For example:

```text
answers[0][0]
```

represents Student 1's answer to Question 1.

### 3. Answer key

```cpp
char key[NUMBER_OF_QUESTIONS] =
    {'D', 'B', 'D', 'C', 'C', 'D', 'A', 'E', 'A', 'D'};
```

This one-dimensional array stores the correct answer for each question.

### 4. Outer loop

```cpp
for (int i = 0; i < NUMBER_OF_STUDENTS; i++)
```

The outer loop moves from Student 1 to Student 8.

### 5. Inner loop

```cpp
for (int j = 0; j < NUMBER_OF_QUESTIONS; j++)
```

The inner loop checks all 10 questions for the current student.

### 6. Comparing answers

```cpp
if (answers[i][j] == key[j])
```

The student's answer is compared with the corresponding answer in the key.

If they are equal:

```cpp
correctCount++;
```

the student's correct-answer count increases by 1.

### 7. Displaying the result

```cpp
cout << "Student " << i + 1
     << "'s correct count is "
     << correctCount << endl;
```

The program displays the number of questions answered correctly by each student.

## Important Concepts Used

- C++ arrays
- Two-dimensional arrays
- One-dimensional arrays
- `for` loops
- Nested loops
- `if` statements
- Character data type (`char`)
- Constants
- Array indexing
- Comparing values
