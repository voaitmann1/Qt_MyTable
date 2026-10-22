#include <QCoreApplication>

#include"tests1.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //
    /*
    TestFlutterModel_SingleIsolatedBladeNoFriction_v1();
    */
    std::cout<<std::endl;
    TestRungeSimple();
    std::cout<<std::endl;
    TestRungeClass();
    TestRungeClass_vVoid();
    ////TestPolynomialEqsPowerFrom2To4();
    ////TestPolynomialEqsPowerFrom2To4_AsClass();
    TestPolynomialEqsPowerFrom2To4_AsClass_complex();
    ////TestComplexNum();
    //TestFlutterModel_SingleIsolatedBladeNoFriction_v2();
    TestReadCSVLine();
    ////TestReadingTextFileLineByLine();
    TestReadingTextFileByKeyWordsSearch();
    Test1DArrPtr_SubArrayByLs();
    Test1DArraysPtr_1();
    //
    std::cout<<"\nMain.cpp: All functions are tested successfully"<<std::endl;
    //
    return a.exec();
}
