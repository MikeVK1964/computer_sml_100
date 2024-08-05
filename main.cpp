// ex7_17.cpp : 
//
#if 1
#include <iostream>
#include  <iomanip>  //
#include <fstream>

#include "SimpletronComp.h"

////#include <windows.h>
//////#include <locale>
using namespace std;
using namespace SimpletronCompNameSpace;
int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");
    SimpletronComp smtron;
    if (argc != 2) {
        ///      full_fname = QFileDialog::getOpenFileName(NULL,"Open File", "" );

        cout << "No input file: run <filename>" << endl;
        exit(1);
    }

   std::ifstream in(argv[1]);
    if (!in.is_open())
    {
       cout << "Не могу открыть файл" << "\0";
       return -2;
    }



//    FILE* pf;
//    pf = fopen( argv[1], "r");

//    if (pf == NULL)
//    {
//        std::cout << "can't open file";
//        return -1;
//    }


    
      smtron.read_file(pf);

    in.close();

     smtron.ExecProg();
  ///   int ch=std::getchar();
     system("pause");  // windows
///    fclose(pf);
}


