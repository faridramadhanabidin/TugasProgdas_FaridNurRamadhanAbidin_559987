#include <iostream>
#include <string>
using namespace std;

const int NUM = 20;

struct studentType {
    string firstName;
    string lastName;
    int testScore;
    char grade;
};

void getData(studentType s[], int n);
void assignGrade(studentType s[], int n);
int findHighest(studentType s[], int n);
void printHighest(studentType s[], int n, int high);

int main() {
    studentType students[NUM];
    getData(students, NUM);
    assignGrade(students, NUM);

    cout << "\nData Mahasiswa:\n";
    for (int i = 0; i < NUM; i++) {
        cout << students[i].lastName << ", " << students[i].firstName
             << "  Nilai: " << students[i].testScore
             << "  Grade: " << students[i].grade << endl;
    }

    int highest = findHighest(students, NUM);
    cout << "\nNilai tertinggi: " << highest << endl;
    cout << "Mahasiswa dengan nilai tertinggi:\n";
    printHighest(students, NUM, highest);

    return 0;
}

void getData(studentType s[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Masukkan nama depan, nama belakang, dan nilai ke-" << i + 1 << ": ";
        cin >> s[i].firstName >> s[i].lastName >> s[i].testScore;
    }
}

void assignGrade(studentType s[], int n) {
    for (int i = 0; i < n; i++) {
        int score = s[i].testScore;
        if (score >= 80) s[i].grade = 'A';
        else if (score >= 70) s[i].grade = 'B';
        else if (score >= 60) s[i].grade = 'C';
        else if (score >= 40) s[i].grade = 'D';
        else s[i].grade = 'F';
    }
}

int findHighest(studentType s[], int n) {
    int maxScore = s[0].testScore;
    for (int i = 1; i < n; i++)
        if (s[i].testScore > maxScore)
            maxScore = s[i].testScore;
    return maxScore;
}

void printHighest(studentType s[], int n, int high) {
    for (int i = 0; i < n; i++) {
        if (s[i].testScore == high)
            cout << s[i].lastName << ", " << s[i].firstName
                 << " (" << s[i].testScore << ")\n";
    }
}
