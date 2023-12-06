#include <iostream>

using namespace std;

// Класс, реализующий паттерн "Одиночка"
class Singleton {
private:
    // Приватный статический указатель на единственный экземпляр класса
    static Singleton* instance;

    // Приватный конструктор, чтобы предотвратить создание объекта извне
    Singleton() {}

public:
    // Публичный метод для получения единственного экземпляра класса
    static Singleton* getInstance() {
        if (!instance) {
            instance = new Singleton();
        }
        return instance;
    }

    // Метод класса
    void showMessage() {
        std::cout << "Привет, я единственный экземпляр Одиночки!\n";
    }
};

// Инициализация статического члена класса (не во всех языках так нужно делать)
Singleton* Singleton::instance = nullptr;

// Main функция
int main() {
    Singleton* shared = Singleton::getInstance();
    
    shared->showMessage();
    
    return 0;
}
