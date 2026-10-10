
#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string name;

public:
    Animal(string n) : name(n) {}

    virtual string speak() const = 0;

    void intro() const {
        cout << name << " says " << speak() << endl;
    }

    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {}

    string speak() const override {
        return "Woof";
    }
};

class Cat : public Animal {
public:
    Cat(string n) : Animal(n) {}

    string speak() const override {
        return "Meow";
    }
};

int main() {
    Dog dog("Buddy");
    Cat cat("Whiskers");

    dog.intro();
    cat.intro();

    return 0;
}
