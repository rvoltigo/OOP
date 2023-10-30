#include <iostream>

using namespace std;

// MARK: - Создание структуры Person
struct Person {
    string name;
    int age;
    double height;
};


// MARK: - Создание функций
void display(Person person) {
    cout << person.name << endl;
    cout << person.age << endl;
    cout << person.height << endl;
}

void display(string name, int age, double height) {
    cout << name;
    cout << age;
    cout << height;
}

int main() {

    Person magomed;
    magomed.name = "Magomed";
    magomed.age = 24;
    magomed.height = 180;

    Person adam;
    adam.name = "Adam";
    adam.age = 30;
    adam.height = 170;

    string name = "Magomed";
    int age = 23;
    double height = 180;
    
    /*
    string name1 = "Adam";
    int age1 = 30;
    double height1 = 170;

    string name2 = "Haron";
    int age2 = 19;
    double height2 = 230;

    cout << name << endl;*/

    return 0;
}