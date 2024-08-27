#pragma once
#include <iostream>
#include  <iomanip>  //
#include <math.h>
////#include <windows.h>
//////#include <locale>
using namespace std;

namespace SimpletronCompNameSpace {
    const int MemoryLenth = 1000;  // число ячеек 1000
    enum simplOperation {
        READ = 10,   // ввод данных в ячейку с клавиатуру
        WRITE = 11,  
        LOAD = 20,   // 
        STORE = 21,  // Âûãðóçêà èç àêêóìóë òîðà â çàäàííûé àäðåñ ïàì òè
        ADD = 30, // Ñëîæåíèå ñëîâà â àêêóìóë òîðå è ñëîâà â ïàì òè (ðåçóëüòàò ñîõðàí åòñ  â àêêóìóë òîðå)
        SUBTRACT = 31, // Âû÷èòàíèå èç ñëîâà â àêêóìóë òîðå ñëîâà ïî óêàçàííîìó àäðåñó ïàì òè(ðåçóëüòàò ñîõðàí åòñ  â àêêóìóë òîðå)
        DIVIDE = 32, // Äåëåíèå ñëîâà â àêêóìóë òîðå íà ñëîâî â ïàì òè ïî óêàçàííîìó àäðåñó ïàì òè(ðåçóëüòàò ñîõðàí åòñ  â àêêóìóë òîðå) 
        MULTIPLY = 33, // óìíîæåíèå ñëîâà â àêêóìóë òîðå íà ñëîâî â ïàì òè ïî óêàçàííîìó àäðåñó ïàì òè(ðåçóëüòàò ñîõðàí åòñ  â àêêóìóë òîðå)
        DIV_MODULE = 34, // äåëåíèå ïî ìîäóëþ
        POW = 35, // âîçâåäåíèå ÷èñëà â àêêóìóë òîðå â ñòåïåíü , êîòîðà  õðàíèòüñ  ïî àäðåñó(ðåçóëüòàò ñîõðàí åòñ  â àêêóìóë òîðå)
        BRANCH = 40, // Ïåðåõîä ïî àäðåñó
        BRANCHNEG = 41, //Ïåðåõîä ïî àäðåñó, åñëè â àêêóìóë òîðå íàõîäèòñ  îòðèöàòåëüíîå ÷èñëî 
        BRANCHZERO = 42, // Ïåðåõîä ïî àäðåñó, åñëè â àêêóìóë òîðå íàõîäèòñ  0
        HALT = 43
    };
    enum  class ComputerMemoryLenthType:size_t {
     MemoryLenth100=100, MemoryLenth1000=1000 
    };  

    class SimpletronComp {
    private:
        int instructionRegister = 0; // òåêóùà  êîìàíäà
//        int MemoryLenth  = 1000;  // число ячеек памяти 1000
//        int memory[MemoryLenth];
        array<int,MemoryLenth> memory; 
    public:
        SimpletronComp();
   ///     ~SimpletronComp(){delete [] memory;};
        //void Hellowold() {
        //    std::cout << "**Ñèìïëåòðîí ïðèâåòñòóåò âàñ" << endl;
        //    std::cout << "**Ïîæàëóéñòà,  ââåäèòå âàøó ïðîãðàììó, ïî îäíîé êîìàíäå\n";
        //    std::cout << "** (èëè ñëîâó äàííûõ) çà ðàç. ß áóäó âûâîäèòü â êà÷åñòâå " << endl;
        //    std::cout << "**ïîäñêàçêè òåêóùèé àäðåñ è çíàê âîïðîñà(?)" << endl;
        //    std::cout << "**Äë  ïðåêðàùåíè  ââîäà ïðîãðàììû ââåäèòå -99999" << endl;

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
            std::cout << "**Çàãðóçêà ïðîãðàììû çàâåðøåíà" << endl;
            std::cout << "**Íà÷èíàþ âûïîëíåíèå ïðîãðàììû" << endl;

        }

        // -3 - îøèáî÷íà  êîìàíäà( îòðèöàòåëüíà )
        // -2 -êîìàíäà îñòàíîâ
        // -1 - êîìàíäà äë   ÷åéêè 99 íå ðàâíà îñòàíîâ
        // 0  - ïðîãðàììà ïðîäîëæàåòñ 
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
                cout << "введите значение в ячейку" << setfill('0') << setw(3) << operand << " "; cin >> memory[operand];
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
            case DIV_MODULE:  // äåëåíèå ïî ìîäóëþ
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
            //memory[0] = 1003;  // ââîä â  ÷åéêó 3
            //memory[1] = 1103;  // âûâîä  ÷åéêè 3 íà êîíñîëü
            //memory[2] = 4300;  // îñòàíîâ
            // Ïðèìåð ïðîãðàììû, êîòîðà  ââîäèò äâà ÷èñëà è âûâîäèò èõ ñóììó.
            memory[0] = +10007; // Ââîä A
            memory[1] = +10008; // Ââîä Â
            memory[2] = +20007; // ââîä â àêêóìóë òîð À
            memory[3] = +35008; // âîçâåäåíèå â ñòåïåíü Â  
            memory[4] = +21009; // âûãðóçêà àêêóìóë òîðà â Ñ
            memory[5] = +11009; // Âûâîä Ñ íà òåðìèíàë
            memory[6] = +43000; // Îñòàíîâ
            memory[7] = 1;  // A
            memory[8] = 2;  // Â
            memory[9] = 3333;  // Ñ

        }
        void read_file(std::ifstream& in);
    private:
//       int*  memory;
//        int memory[MemoryLenth];
        int accumulator = 0; // àêêóìóë òîð  -xxxx
        int instructionCounter = 0; // àäðåñ ñëåäóþùåé êîìàíäû  xx
        int operationCode = 0; // êîä òåêóùåé îïåðàöèè
        int operand = 0;
    };
}
