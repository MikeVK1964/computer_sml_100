// ex7_17.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.
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
////    setlocale(LC_ALL, "ru_RU.UTF-8"); // ��� �� QT ���������� ���������� �++
    setlocale(LC_ALL, "Russian");
    SimpletronComp smtron;
    if (argc != 2) {
        ///      full_fname = QFileDialog::getOpenFileName(NULL,"Open File", "" );

        cout << "����������� ������: run <filename>" << endl;
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
    wchar_t name[20]; //��� wstring name;
    wcout << "����� ���:" << endl;
    wcin >> name;
    wcout << "���� �����, " << name << ", ��� ��� ����" << endl;
    _getch();
    return 0;
}
#endif

// ������ ���������: CTRL+F5 ��� ���� "�������" > "������ ��� �������"
// ������� ���������: F5 ��� ���� "�������" > "��������� �������"

// ������ �� ������ ������ 
//   1. � ���� ������������ ������� ����� ��������� ����� � ��������� ���.
//   2. � ���� Team Explorer ����� ������������ � ������� ���������� ��������.
//   3. � ���� "�������� ������" ����� ������������� �������� ������ ������ � ������ ���������.
//   4. � ���� "������ ������" ����� ������������� ������.
//   5. ��������������� �������� ������ ���� "������" > "�������� ����� �������", ����� ������� ����� ����, ��� "������" > "�������� ������������ �������", ����� �������� � ������ ������������ ����� ����.
//   6. ����� ����� ������� ���� ������ �����, �������� ������ ���� "����" > "�������" > "������" � �������� SLN-����.
