
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
    std::cout << "**���������� ����������� ���" << endl;
    std::cout << "**����������,  ������� ���� ���������, �� ����� �������\n";
    std::cout << "** (��� ����� ������) �� ���. � ���� �������� � �������� " << endl;
    std::cout << "**��������� ������� ����� � ���� �������(?)" << endl;
    std::cout << "**��� ����������� ����� ��������� ������� -99999" << endl;

}
