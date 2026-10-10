#include <iostream>
#include <string>

using namespace std;

class Student {
    private:
        string name;
        int mark;

public:
    static int total;

    Student(string n, int m) {
        name = n;
        mark = m;
        total++;
    }

    string getName() {
        return name;
    }

    char getGrade() const {
        if (mark >= 75)
            return 'A';
        else if (mark >= 60)
            return 'B';
        else if (mark >= 50)
            return 'C';
        else
            return 'F';
    }
};

int Student::total = 0;

int main() {
    Student s1("Zinhle", 82);
    Student s2("Peter", 55);
    Student s3("Amara", 40);

    cout << s1.getName() << ": " << s1.getGrade() << endl;
    cout << s2.getName() << ": " << s2.getGrade() << endl;
    cout << s2.getName() << ": " << s3.getGrade() << endl;

    cout << "Students: " << Student::total << endl;

    return 0;
}
