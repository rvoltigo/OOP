#include <iostream>

using namespace std;

int len(int numbers[]) {
    int count = sizeof(numbers) / sizeof(int);

    return count;
}

int main() {

    //Переменные
    // int number = 0;
    
    // float float_number = 3.14;

    // double double_number = 3.14;

    // char c = 'c';

    // bool flag = false;

    // string name = "Alex";

    //Потоковый вывод информации
    // cout << "Hello, world!" << endl;
    // cout << "His name is: " << name << endl;

    //Условные операторы == <= >= !=
    // const int number = 15;
    // if (number == 20) {
    //     cout << "Number is equal: " << number << endl;
    // } else if (number >= 20) {
    //     cout << "Number >= 20"<< endl;
    // } else {
    //     cout << "Number < 20" << endl;
    // }

    // switch (number)
    // {
    // case 15:
    //     cout << "15" << endl;
    //     break;
    // case 20:
    //     cout << "20" << endl;
    //     break;
    // default:
    //     cout << "Your nubmer is:" << number << endl;
    //     break;
    // }

    int i = 0;

    while(i != 20) {
        i++;
    }

    // do {
    //     cout << i << endl;
    //     i++;
    // } while(i <= 20);

    // for(int i = 0; i < 20; i++) {
    //     cout << i << endl;
    // }

    int numbers[] = {1, 2, 3, 4, 5};

    int count = sizeof(numbers) / sizeof(int);

    for(int i = 0; i < count; i++) {
        cout << numbers[i] << endl;
    }


    return 0;
}