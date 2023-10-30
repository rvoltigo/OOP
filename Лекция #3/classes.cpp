#include <iostream>

using namespace std;


class Person {
public:
    // свойства класса Person
    string name;
    int age;
    float height;
    const int dnk;
    int *numbers;

    // инициализаторы
    Person(string name, int age, float height) : dnk(50) /* инициализация константных членов класса */ {
        this->name = name;
        this->age = age;
        this->height = height;

        numbers = new int[10];
    }

    Person() : dnk(50) /* инициализация константных членов класса */ {
        name = "Person";
        age = 25;
        height = 180.65;
        numbers = new int[10];
    }

    // деструктор
    ~Person() {
        delete[] numbers;
        cout << "Объект " << name << " уничтожен" << endl;
    }

};

//new - выделить память
//delete - освободить память

struct Human {
    // Свойства структуры Human
    string name;
    int age;
    float height;

    // Инициализаторы
    Human(string name, int age, float height) {
        this->name = name;
        this->age = age;
        this->height = height;
    }

    Human() {
        name = "Human";
        age = 0;
        height = 50;
    }

    Human(string name) {
        this->name = name;
        age = 0;
        height = 50;
    }

};

// MARK: - работа с массивами
void print_array(int array[], int size) {
    for(int i = 0; i <= size; i++) {
        cout << array[i] << " ";
    }
}

void addElement(int*& arr, int& size, int element) {
    int newSize = size + 1;
    int* newArr = new int[newSize];

    // Копируем существующие элементы из старого массива в новый
    for (int i = 0; i <= size; i++) {
        newArr[i] = arr[i];
    }

    // Обновляем размер
    size = newSize;

    // Добавляем новый элемент
    newArr[size] = element;

    // Освобождаем старый массив
    delete[] arr;

    // Указываем указатель на новый массив
    arr = newArr;
}

void dynamic_array() {
    // Выделяем размер для 5 элементов
    int size = 5;
    // Выделяем память для массива
    int *numbers = new int[size];

    // Заполняем массив
    for(int i = 0; i <= size; i++) {
        numbers[i] = i;
    }

    // Выводим на экран
    print_array(numbers, size);
    cout << endl;
    // Вызов функции для добавления элемента
    addElement(numbers, size, 6);
    // Выводим на экран
    print_array(numbers, size);
}

// MARK: - работа с векторами (динамическими массивами) юзать это, желательно юзать это, когда пользуетесь массивами на С++
void vector_func() {
    vector<int> numbers = {1, 2, 3, 4, 5};

    for(int number : numbers) {
        cout << number << " ";
    }

    numbers.push_back(6);

    cout << endl;
    for(int number : numbers) {
        cout << number << " ";
    }

    numbers.pop_back();
}

void memory_leak() {
    Person alex("Alex", 25, 180.85);
    cout << alex.name << endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    while(1) {
        memory_leak();
    }

    /*
    // Дефолтный инициализатор
    Human human;

    // Вызов инициализатора с 3 параметрами
    Human maxim("Maxim", 25, 170);

    // Вызов инициализатора с 1 параметром
    Human alex("Alex");
    cout << alex.name << endl;
    */

    // dynamic_array();

    // vector_func();

    // Person person("Alex", 30);
    // {
    //     Person person_two("John", 25);
    // };
    // cout << person.age << endl;
    return 0;
}
