
#include "SimpletronComp.h"
#include <fstream>

using namespace SimpletronCompNameSpace;

SimpletronComp::SimpletronComp()
{
    for (auto i = 0; i < MemoryLenth; i++) memory[i] = 0;
}

void SimpletronComp::read_file(std::ifstream& in)
{

     int i,memory_value;
     in >> i >> memory_value;

      while (in.good()) {
        memory[i] = memory_value; 
///        std::cout << par1<< " " << par2 << endl;
//        in >> par1 >> par2;
         in >> i >> memory_value;

      }

}

#if 0
void SimpletronComp::read_file(FILE* pf) {
    int account;
    int i = 0;
    do {
//        fscanf_s(pf, "%d%d",&i, &account);
        fscanf(pf, "%d%d",&i, &account);

        if (!feof(pf)) memory[i] = account; 	   // printf("%-10d\n", account);

    } while (!feof(pf));
    fclose(pf);

}
#endif

void SimpletronComp::Hellowold() {
    std::cout << "**Симплетрон приветстует вас" << endl;
    std::cout << "**Пожалуйста,  введите вашу программу, по одной команде\n";
    std::cout << "** (или слову данных) за раз. Я буду выводить в качестве " << endl;
    std::cout << "**подсказки текущий адрес и знак вопроса(?)" << endl;
    std::cout << "**Для прекращения ввода программы введите -99999" << endl;

}
