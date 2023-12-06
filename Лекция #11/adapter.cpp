//
//  adapter.cpp
//  c_plus_plus
//
//  Created by Khusain on 05.12.2023.
//

#include <iostream>

using namespace std;

// Расписал максимально кратко работу адаптера, не добавляя лишний функционал, чтобы вы поняли. Суть адаптера в том, что мы можем заставить работать разные классы вместе.

// Абстрактный класс (интерфейс/протокол), который описывает птиц
class Bird {
public:
    virtual void sing() const = 0;
};

// Дочерний класс, в котором идет реализация функционала
class Dove: public Bird {
public:
    void sing() const override {
        cout << "Uhu - uhu" << endl;
    }
};

// Отдельный класс, который никак не взаимосвязан с абстрактным классом (интерфейсом/протоколом)
class Raven {
public:
    void voice() {
        cout << "Kar - kar" << endl;
    }
};

// Создание класса-адаптера, который подписан под наш абстрактный класс
// Вся магия происходит тут. Дело в том, что когда мы, своего рода, "переопределяем" работу класса, который нам нужно встроить в наш проект. Таким образом, мы можем использовать класс RavenAdapter, класс Dove и все классы, которые наследуются от Bird в одном интерфейсе.
class RavenAdapter: public Bird {
private:
    Raven* raven;
public:
    RavenAdapter(Raven* raven) {
        this->raven = raven;
    }
    
    void sing() const override {
        raven->voice();
    }
    
    ~RavenAdapter() {
        delete raven;
    }
};

// Наша "главная" функция, через которую нам нужно прогнать все классы, которые наследуются от абстрактного класса. Если бы не было класса-адаптера, то пришлось бы писать отдельный функционал для наших классов, не связанных с Bird
void birdVoiceTest(Bird* bird) {
    bird->sing();
}

// Прочитайте для чего используется данный паттерн (легаси код, создание классов-адаптеров для фреймворков и т.д.)

int main() {
    
    Dove* dove = new Dove();
    Raven* raven = new Raven();
    RavenAdapter* ravenAdapter = new RavenAdapter(raven);
    
    birdVoiceTest(dove);
    birdVoiceTest(ravenAdapter);
    
    return 0;
}
