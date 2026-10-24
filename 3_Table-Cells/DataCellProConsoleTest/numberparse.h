#ifndef NUMBERPARSE_H
#define NUMBERPARSE_H

#include"MyLib.h"
#include<qstring.h>
#include"mymathlib.h"
/*
struct TNumberParts{                               // 1234.5678E+2 // 1234.5678E-2 //1234.5678
    int IntPartAsWritten;                          // 1234         // 1234         //1234
    double FracPartAsWritten,                      // .5678        // .5678        // .5678
           MantissaAsWritten;                      // 1234.5678    // 1234.5678    //1234.5678
    int OrderAsWritten;                            //  2           // 2            // 0
    //
    int IntPartAsMathRules;                        // 1            // 1            // 1
    double FracPartAsMathRules,                    // 0.2345678    // 0.2345678    // 0.2345678
           MantissaAsMathRules;                    // 1.2345678    // 1.2345678    // 1.2345678
    //
    int Order;                                     // 6-1=5        // 2-1=1         // 4-1=3
    //
    int IntPartWhole;                              // 123456       // 12            // 1234
    double FracPartWhole,                          // 0.78         // 0.345678      // 0.5678
           MantissaWhole;                          // 123465.78    // 12.345678     // 1234.5678
    //
    bool NumberHasPositiveSign, OrderHasPositiveSign;   //it is clear
    //
    //int OrderOfIntPart, OrderOfFracPart;   //cmnted 2021-03-24
    // alr present, see above
    // bool SignOfMantissaIsPositive, SignOfOrderIsPositive;
};
void SetNumberDataNull(TNumberParts&data);
void WriteNumberParts(TNumberParts data, TValsShowHide*vsh=NULL);
*/

class TNumberParts{                               // 1234.5678E+2 // 1234.5678E-2 //1234.5678
    public:
    int IntPartAsWritten;                          // 1234         // 1234         //1234
    double FracPartAsWritten,                      // .5678        // .5678        // .5678
           MantissaAsWritten;                      // 1234.5678    // 1234.5678    //1234.5678
    int OrderAsWritten;                            //  2           // 2            // 0
    //
    int IntPartAsMathRules;                        // 1            // 1            // 1
    double FracPartAsMathRules,                    // 0.2345678    // 0.2345678    // 0.2345678
           MantissaAsMathRules;                    // 1.2345678    // 1.2345678    // 1.2345678
    //
    int Order;                                     // 6-1=5        // 2-1=1         // 4-1=3
    //
    int IntPartWhole;                              // 123456       // 12            // 1234
    double FracPartWhole,                          // 0.78         // 0.345678      // 0.5678
           MantissaWhole;                          // 123465.78    // 12.345678     // 1234.5678
    //
    bool NumberHasPositiveSign, OrderHasPositiveSign;   //it is clear
    //
    //int OrderOfIntPart, OrderOfFracPart;   //cmnted 2021-03-24
    // alr present, see above
    // bool SignOfMantissaIsPositive, SignOfOrderIsPositive;
    //
    TNumberParts();
    //TNumberParts(int x);
    //TNumberParts(double x);
    void SetNull();
    void ShowText(TValsShowHide*vsh);
};
//
int DigitOf(QString s, int baseDec=10);
bool IsDigit(QString s, int baseDec=10);
void IntPartDet(double x, int&ip, double&IntPartFP);
int IntPart(double x);
TNumberParts SeparateNum(double x, TValsShowHide*vsh=NULL, int BaseDec=10);
void SeparateNum(double x, int&IntPartOfNum, double&FracPartOfNum, int&IntPartOfMant, double&FracPartOfMant, int&Order, int&Sgn, int&OrdSgn, int BaseDec=10);
void IntToDigits(int x, int&Order, int digit[], int BaseDec=10, bool SortNatural=true);
void RealToDigits_UsualMantAndOrd(double x, int&Order, int&OrderLength, int mant_digit[], int ord_digit[], int QAftComma=6, int BaseDec=10, bool SortNatural=true);
void RealToDigits_IntAndFracSepar(double x, int&Order, int int_digit[], int frac_digit[], int QAftComma=6, int BaseDec=10, bool SortNatural=true);
QString IntToStringSimple(int x, int BaseDec=10);
QString RealToString(double x, int Repr_IntAndFrac0_ExpAfOrderLim1_ExpAnyhow2=0,  int QAftComma=6, int OrdAfWhichExp=6, int BaseDec=10);
//void NumToChars(double x, int BaseDec, int QCharsAftCommaRequired, int&len, char UsualNum[], char MantOrd[]);
//
char DigitSignCh(int digit, int baseDec=10);
QString DigitSign(int digit, int baseDec=10);
QString ExcelColumnByN(int N);
int ExcelColN(QString Col);
void ExcelCellCoordsFromAddress(QString CellSign, int&LineN, int&ColN);
//
bool IsComma(QString x);
bool IsOrderMark(QString x);
bool IsOrderMark(QString x, int BaseDecDec=10);
//double NumberParse(QStringx, int FracPartLenReq, int baseDec, bool ZeroForFracNecessary, int&IntPart,  double&FracPart, int&NeededFrac, int&Order, bool&Sign, int&ErstError){
TNumberParts StrNumberParse(QString x, TValsShowHide*vsh=NULL, int BaseDecDec=10);
double StrToReal(QString s, TValsShowHide*vsh=NULL, int BaseDec=10);
int StrToInt(QString s,  TValsShowHide*vsh=NULL, int BaseDec=10);

#endif // NUMBERPARSE_H
