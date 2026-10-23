#ifndef TESTS1_H
#define TESTS1_H

#include"mylib.h"
#include"mymathlib.h"
#include"fluttermodels.h"
//#include"array1d_size2D_elem2d_1.h"//es in afn
#include "array2dlib.h"
//#include"arraylib3.h"

//class tests1
//{
//public:
//    tests1();
//};



double fRungeTest1RPE1(int n, double t, const double*y);
double fRungeTest1RPE2(int n, double t, const double*y);
double fRungeTest1RPE3(int n, double t, const double*y);
double fRungeTest1RPE4(int n, double t, const double*y);


void TestRungeSimple();
void TestRungeClass();
void TestRungeClass_vVoid();
void TestPolynomialEqsPowerFrom2To4();
void TestPolynomialEqsPowerFrom2To4_AsClass();
void TestPolynomialEqsPowerFrom2To4_AsClass_complex();
void TestComplexNum();
////void TestFlutterModel_SingleIsolatedBladeNoFriction_v1();
//void TestFlutterModel_SingleIsolatedBladeNoFriction_v2();
void TestReadCSVLine();
void TestReadingTextFileLineByLine();
void TestReadingTextFileByKeyWordsSearch();
void Test1DArrPtr_SubArrayByLs();
void Test1DArraysPtr_1();

void TestArr2DInitio();

#endif // TESTS1_H
