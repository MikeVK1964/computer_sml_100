#pragma once
#include <iostream>
#include  <iomanip>  //
#include <math.h>
////#include <windows.h>
//////#include <locale>
using namespace std;

namespace SimpletronCompNameSpace {
    const int MemoryLenth = 1000;  // число элементов пам ти 1000
    enum simplOperation {
        READ = 10,   // Ввод с терминала в пам ть
        WRITE = 11,
        LOAD = 20,   // Загрузка в аккумул тор из определенного адреса пам ти
        STORE = 21,  // Выгрузка из аккумул тора в заданный адрес пам ти
        ADD = 30, // Сложение слова в аккумул торе и слова в пам ти (результат сохран етс  в аккумул торе)
        SUBTRACT = 31, // Вычитание из слова в аккумул торе слова по указанному адресу пам ти(результат сохран етс  в аккумул торе)
        DIVIDE = 32, // Деление слова в аккумул торе на слово в пам ти по указанному адресу пам ти(результат сохран етс  в аккумул торе) 
        MULTIPLY = 33, // умножение слова в аккумул торе на слово в пам ти по указанному адресу пам ти(результат сохран етс  в аккумул торе)
        DIV_MODULE = 34, // деление по модулю
        POW = 35, // возведение числа в аккумул торе в степень , котора  хранитьс  по адресу(результат сохран етс  в аккумул торе)
        BRANCH = 40, // Переход по адресу
        BRANCHNEG = 41, //Переход по адресу, если в аккумул торе находитс  отрицательное число 
        BRANCHZERO = 42, // Переход по адресу, если в аккумул торе находитс  0
        HALT = 43
    };

    class SimpletronComp {
    private:
        int instructionRegister = 0; // текуща  команда

    public:
        SimpletronComp();
        //void Hellowold() {
        //    std::cout << "**Симплетрон приветстует вас" << endl;
        //    std::cout << "**Пожалуйста,  введите вашу программу, по одной команде\n";
        //    std::cout << "** (или слову данных) за раз. Я буду выводить в качестве " << endl;
        //    std::cout << "**подсказки текущий адрес и знак вопроса(?)" << endl;
        //    std::cout << "**Дл  прекращени  ввода программы введите -99999" << endl;

        //}

        void Hellowold();
        void input_prog_console() {
            int i = 0;
            string str;
            int value = 0;
            while (i != 100 && value != -99999)
            {
                cout << setfill('0') << setw(2) << i << "?";
                std::cin >> value;
                memory[i] = value;
                cout << setfill('0') << setw(2) << i << "?" << value << endl;
                i++;
            }
            std::cout << "**Загрузка программы завершена" << endl;
            std::cout << "**Начинаю выполнение программы" << endl;

        }

        // -3 - ошибочна  команда( отрицательна )
        // -2 -команда останов
        // -1 - команда дл   чейки 99 не равна останов
        // 0  - программа продолжаетс 
        int ExecComand() {
            instructionRegister = memory[instructionCounter];
            if (instructionRegister < 0) return -3;

            operationCode = instructionRegister / MemoryLenth;
            operand = instructionRegister % MemoryLenth;
            instructionCounter++;

            //      if ((instructionCounter == 99) && !((operationCode == BRANCH)||(operationCode == BRANCHNEG) || (operationCode == BRANCHZERO)) ) return -1;
            if ((instructionCounter == MemoryLenth - 1) && !(operationCode == HALT)) return -1;

            switch (operationCode) {
            case READ: // 
                cout << "Ввод в адрес" << setfill('0') << setw(3) << operand << " "; cin >> memory[operand];
                return 0;
            case WRITE:
                cout << "WRITE " << memory[operand] << endl;
                return 0;
            case LOAD:
                accumulator = memory[operand];
                return 0;
            case STORE:
                memory[operand] = accumulator;
                return 0;
            case ADD:
                accumulator += memory[operand];
                return 0;
            case SUBTRACT:
                accumulator -= memory[operand];
                return 0;
            case DIVIDE:
                accumulator /= memory[operand];
                return 0;
            case MULTIPLY:
                accumulator *= memory[operand];
                return 0;
            case DIV_MODULE:  // деление по модулю
                accumulator %= memory[operand];
                return 0;
            case POW:
                accumulator = (int)std::pow(accumulator, memory[operand]);
                return 0;
            case BRANCH:
                instructionCounter = operand;
                return 0;
            case BRANCHNEG:
                if (accumulator < 0) instructionCounter = operand;
                return 0;
            case BRANCHZERO:
                if (accumulator == 0) instructionCounter = operand;
                return 0;
            case HALT: return -2;
            }
            return -3;
        }
        void ExecProg() {
            int rc = ExecComand();
            while (rc == 0)
            {
                rc = ExecComand();
            }
        }
        void input_prog_const() {
            //memory[0] = 1003;  // ввод в  чейку 3
            //memory[1] = 1103;  // вывод  чейки 3 на консоль
            //memory[2] = 4300;  // останов
            // Пример программы, котора  вводит два числа и выводит их сумму.
            memory[0] = +10007; // Ввод A
            memory[1] = +10008; // Ввод В
            memory[2] = +20007; // ввод в аккумул тор А
            memory[3] = +35008; // возведение в степень В  
            memory[4] = +21009; // выгрузка аккумул тора в С
            memory[5] = +11009; // Вывод С на терминал
            memory[6] = +43000; // Останов
            memory[7] = 1;  // A
            memory[8] = 2;  // В
            memory[9] = 3333;  // С

        }
        void read_file(FILE* pf);
 
    private:
        int memory[MemoryLenth];
        int accumulator = 0; // аккумул тор  -xxxx
        int instructionCounter = 0; // адрес следующей команды  xx
        int operationCode = 0; // код текущей операции
        int operand = 0;
    };
}
