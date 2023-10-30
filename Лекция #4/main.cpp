#include <iostream>

// MARK: - Приватные и публичные члены класса
class MyClass {
private:
    int privateData; // Приватное поле

public:
    void setPrivateData(int value) {
        privateData = value; // Публичный метод для установки значения privateData
    }

    int getPrivateData() {
        return privateData; // Публичный метод для получения значения privateData
    }
};

// MARK: - Использование геттеров и сеттеров
class Student {
private:
    std::string name;
    int age;

public:
    // Геттеры для доступа к приватным полям
    std::string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    // Сеттеры для установки значений приватных полей
    void setName(const std::string& newName) {
        name = newName;
    }

    void setAge(int newAge) {
        if (newAge >= 0) {
            age = newAge;
        }
    }
};

// MARK: - Использование конструкторов и деструкторов
class Book {
private:
    std::string title;
    int pageCount;

public:
    // Конструктор для инициализации объекта
    Book(std::string title, int pageCount) {
        this->title = title;
        this->pageCount = pageCount;
    }
    
    // Дефолтный конструктор
    Book() {
        title = "Empty title";
        pageCount = 0;
    }

    // Деструктор для очистки ресурсов (если необходимо)
    ~Book() {
        // Дополнительная логика по очистке ресурсов
    }

    // Геттеры для доступа к приватным полям
    std::string getTitle() {
        return title;
    }

    int getPageCount() {
        return pageCount;
    }
};
