#include <iostream>
#include <vector>

using namespace std;

// Абстрактный класс (или интерфейс в других ЯП)
class Training {
protected:
    string name;
    string type;
public:
    virtual void startTraining() const = 0;
    virtual void stopTraining() const = 0;
    virtual ~Training() {}
    
};

// Дочерний класс Jump для конкретной реализации от абстрактного класса
class Jump: public Training {
public:
    Jump() {
        name = "Прыжки";
        type = "На ноги";
    }
    
    void startTraining() const override {
        cout << "Начало прыжков" << endl;
    }
    
    void stopTraining() const override {
        cout << "Конец прыжков" << endl;
    }
    
    ~Jump() {}
};

// Дочерний класс Swim для конкретной реализации от абстрактного класса
class Swim: public Training {
public:
    Swim() {
        name = "Плавание";
        type = "На все тело";
    }
    
    void startTraining() const override {
        cout << "Начало плавания" << endl;
    }
    
    void stopTraining() const override {
        cout << "Конец плавания" << endl;
    }
    
    ~Swim() {}
};

// Перечисление с существующими видами тренировок
enum Trainings {
    JUMP,
    SWIM
};

// Класс, в котором реализуется паттерн "Фабричный метод"
class Factory {
public:
    // Статическая функция для создания новых объектов, исходя из перечисления
    static Training* createTraining(Trainings name) {
        switch (name) {
            case JUMP:
                return new Jump();
            case SWIM:
                return new Swim();
        }
    }
};

/*
Добавление нового вида тренировок происходит по следующему алгоритму:
 1. Необходимо создать дочерний класс от Training (то есть класс, в котором реализуется новый вид тренировок). Например:
        
    class Run: public Training {
        реализация класса
    }
 
 2. Следующим шагом нужно добавить новый вид тренировок в перечисление.
    
     enum Trainings {
         JUMP,
         SWIM,
         RUN
     };
 
 3. И финальный шаг - добавление в метод createTraining класса Factory возможность создать новый объект.
 
 class Factory {
    ....
     switch (name) {
         case JUMP:
             return new Jump();
         case SWIM:
             return new Swim();
         case RUN:
             return new Run();
     }
    ....
 }
 
 Таким образом, когда нужно добавить новый функционал, не изменяя код, а добавляя новый - на помощь приходит Фабричный метод
*/

// Main функция
int main() {
    Factory factory;
//
//    vector<Training*> trainings;
//    trainings.push_back(factory.createTraining(JUMP));
//    trainings.push_back(factory.createTraining(SWIM));
//    trainings.push_back(factory.createTraining(SWIM));

    Training* jumpTraining = factory.createTraining(JUMP);
    Training* swimTraining = factory.createTraining(SWIM);

    jumpTraining->startTraining();
    jumpTraining->stopTraining();

    swimTraining->startTraining();
    swimTraining->stopTraining();
    
//    for (auto training : trainings) {
//        training->startTraining();
//        training->stopTraining();
//        delete training;
//    }

    
    return 0;
}
