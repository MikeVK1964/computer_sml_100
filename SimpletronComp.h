#pragma once
#include <iostream>
#include  <iomanip>  //
#include <math.h>
////#include <windows.h>
//////#include <locale>
using namespace std;

namespace SimpletronCompNameSpace {
    const int MemoryLenth = 1000;  // ����� ��������� ��� �� 1000
    enum simplOperation {
        READ = 10,   // ���� � ��������� � ��� ��
        WRITE = 11,
        LOAD = 20,   // �������� � ������� ��� �� ������������� ������ ��� ��
        STORE = 21,  // �������� �� ������� ���� � �������� ����� ��� ��
        ADD = 30, // �������� ����� � ������� ���� � ����� � ��� �� (��������� ������ ���  � ������� ����)
        SUBTRACT = 31, // ��������� �� ����� � ������� ���� ����� �� ���������� ������ ��� ��(��������� ������ ���  � ������� ����)
        DIVIDE = 32, // ������� ����� � ������� ���� �� ����� � ��� �� �� ���������� ������ ��� ��(��������� ������ ���  � ������� ����) 
        MULTIPLY = 33, // ��������� ����� � ������� ���� �� ����� � ��� �� �� ���������� ������ ��� ��(��������� ������ ���  � ������� ����)
        DIV_MODULE = 34, // ������� �� ������
        POW = 35, // ���������� ����� � ������� ���� � ������� , ������  ��������  �� ������(��������� ������ ���  � ������� ����)
        BRANCH = 40, // ������� �� ������
        BRANCHNEG = 41, //������� �� ������, ���� � ������� ���� ��������  ������������� ����� 
        BRANCHZERO = 42, // ������� �� ������, ���� � ������� ���� ��������  0
        HALT = 43
    };

    class SimpletronComp {
    private:
        int instructionRegister = 0; // ������  �������

    public:
        SimpletronComp();
        //void Hellowold() {
        //    std::cout << "**���������� ����������� ���" << endl;
        //    std::cout << "**����������,  ������� ���� ���������, �� ����� �������\n";
        //    std::cout << "** (��� ����� ������) �� ���. � ���� �������� � �������� " << endl;
        //    std::cout << "**��������� ������� ����� � ���� �������(?)" << endl;
        //    std::cout << "**��  ����������  ����� ��������� ������� -99999" << endl;

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
            std::cout << "**�������� ��������� ���������" << endl;
            std::cout << "**������� ���������� ���������" << endl;

        }

        // -3 - ��������  �������( ������������ )
        // -2 -������� �������
        // -1 - ������� ��   ����� 99 �� ����� �������
        // 0  - ��������� ����������� 
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
                cout << "���� � �����" << setfill('0') << setw(3) << operand << " "; cin >> memory[operand];
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
            case DIV_MODULE:  // ������� �� ������
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
            //memory[0] = 1003;  // ���� �  ����� 3
            //memory[1] = 1103;  // �����  ����� 3 �� �������
            //memory[2] = 4300;  // �������
            // ������ ���������, ������  ������ ��� ����� � ������� �� �����.
            memory[0] = +10007; // ���� A
            memory[1] = +10008; // ���� �
            memory[2] = +20007; // ���� � ������� ��� �
            memory[3] = +35008; // ���������� � ������� �  
            memory[4] = +21009; // �������� ������� ���� � �
            memory[5] = +11009; // ����� � �� ��������
            memory[6] = +43000; // �������
            memory[7] = 1;  // A
            memory[8] = 2;  // �
            memory[9] = 3333;  // �

        }
        void read_file(FILE* pf);
 
    private:
        int memory[MemoryLenth];
        int accumulator = 0; // ������� ���  -xxxx
        int instructionCounter = 0; // ����� ��������� �������  xx
        int operationCode = 0; // ��� ������� ��������
        int operand = 0;
    };
}
