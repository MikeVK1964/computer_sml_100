// ex7_17.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#if 1
#include <iostream>
#include  <iomanip>  //
#include "SimpletronComp.h"

////#include <windows.h>
//////#include <locale>
using namespace std;
using namespace SimpletronCompNameSpace;
int main(int argc, char* argv[])
{
////    setlocale(LC_ALL, "ru_RU.UTF-8"); // для не QT консольных приложений С++
    setlocale(LC_ALL, "Russian");
    SimpletronComp smtron;
    if (argc != 2) {
        ///      full_fname = QFileDialog::getOpenFileName(NULL,"Open File", "" );

        cout << "Используйте формат: run <filename>" << endl;
        exit(1);
    }
    FILE* pf;
///    errno_t err = fopen_s(&pf, "prog.txt", "r");
    pf = fopen( argv[1], "r");
//    pf = fopen( "prog.txt", "r");

    if (pf == NULL)
    {
        std::cout << "can't open file";
        return -1;
    }
///    smtron.Hellowold();
//    smtron.input_prog_console();
///    smtron.input_prog_const();
    
    smtron.read_file(pf);

     smtron.ExecProg();
  ///   int ch=std::getchar();
     system("pause");  // windows
///    fclose(pf);
}
#else
///#include <stdafx.h>
#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    wcout.imbue(locale(".1251"));
    wcin.imbue(locale(".866"));
    wchar_t name[20]; //или wstring name;
    wcout << "Введи имя:" << endl;
    wcin >> name;
    wcout << "Тебя зовут, " << name << ", или тип того" << endl;
    _getch();
    return 0;
}
#endif

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
