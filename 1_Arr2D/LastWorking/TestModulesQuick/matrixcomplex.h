#ifndef MATRIXCOMPLEX_H
#define MATRIXCOMPLEX_H

#include"array2dlib.h"
#include"mymathlib.h"

class MatrixComplex
{
    Array2D_EIR<ComplexNum>data;
  public:
    MatrixComplex();
    MatrixComplex(Array2D_EIR<ComplexNum>data);
    MatrixComplex(Array2D_EIR<double>data);
    MatrixComplex(ComplexNum**data, int QLines, int QColumns);
    MatrixComplex(double**data, int QLines, int QColumns);
    MatrixComplex(ComplexNum*data, int QLines, int QColumns);
    MatrixComplex(double*data, int QLines, int QColumns);
    MatrixComplex(std::vector<ComplexNum>data, int QLines, int QColumns);
    MatrixComplex(std::vector<double>data, int QLines, int QColumns);
    MatrixComplex(const ComplexNum&data, int QLines, int QColumns);
    MatrixComplex(double data, int QLines, int QColumns);
    MatrixComplex(const MatrixComplex&obj);
    ~MatrixComplex();
    void construct();
    void SetNull();
    void SetOne(const ComplexNum&val);
    void SetOne(double Re=0, double Im=0);
    void Assign(const MatrixComplex&obj);
    MatrixComplex operator =(const MatrixComplex&obj);
    Array2D_EIR<ComplexNum>GetData();
    int GetQLines();
    int GetQColumns();
    ComplexNum GetElement(int LineN, int ColumnN=1);
    double GetElementRe(int LineN, int ColumnN=1);
    double GetElementIm(int LineN, int ColumnN=1);
    void SetElement(const ComplexNum& val, int LineN, int ColumnN=1);
    void SetElementRe(double ReVal, int LineN, int ColumnN=1);
    void SetElementIm(double ImVal, int LineN, int ColumnN=1);
    std::vector<ComplexNum>GetLineN(int N=-1);
    std::vector<ComplexNum>GetColumnN(int N=-1);
    void SetSize(int QLines, int QColumns=1);
    void Set(Array2D_EIR<ComplexNum>data);
    void Set(Array2D_EIR<double>data);
    void Set(ComplexNum**data, int QLines, int QColumns=1);
    void Set(double**data, int QLines, int QColumns=1);
    void Set(std::vector<std::vector<ComplexNum>>data, int QLines, int QColumns=1);
    void Set(std::vector<std::vector<double>>data, int QLines, int QColumns=1);
    void Set(ComplexNum*data, int QLines, int QColumns=1);
    void Set(double*data, int QLines, int QColumns=1);
    void Set(std::vector<ComplexNum>data, int QLines, int QColumns=1);
    void Set(std::vector<double>data, int QLines, int QColumns=1);
    void Set(const ComplexNum&data, int QLines, int QColumns=1);
    void Set(double data, int QLines, int QColumns=1);
    //
    //data
    //
    //math
    //
    QString GetElement_asStr(int LineN, int ColumnN=1);
    QString GetElementRe_asStr(int LineN, int ColumnN=1);
    QString GetElementIm_asStr(int LineN, int ColumnN=1);
    QString GetLine_AsString(int LineN=-1, QString ElementDelim=", ", bool ShowBrackets=true);
    QString GetColumn_AsString(int ColumnN=-1, QString ElementDelim=", ", bool ShowBrackets=true);
    QString GetMatrix_AsString(QString ElementDelim=", ", QString RowDelim="; ", bool ShowBrackets=true);
    void ShowToConsole_Line(int LineN=-1, QString ElementDelim=", ", bool ShowBrackets=true);
    void ShowToConsole_Column(int ColumnN=-1, QString ElementDelim=", ", bool ShowBrackets=true);
    void ShowToConsole(QString ElementDelim=", ", bool ShowBrackets=true, bool Repr2DNot1D=true);
};

#endif // MATRIXCOMPLEX_H
