#ifndef TDATACELLROW_H
#define TDATACELLROW_H

#include<vector>
#include"datacell.h"


//
typedef std::vector<DataCell>TVectorOfCells;

class TDataCellRow
{
    TVectorOfCells row;
public:
    TDataCellRow();
    TDataCellRow(TDataCellRow&obj);
    TDataCellRow(TVectorOfCells cells);
    TDataCellRow(DataCell* cells, int Q);
    TDataCellRow(double*arr, int Q);
    TDataCellRow(float*arr, int Q);
    TDataCellRow(int*arr, int Q);
    TDataCellRow(bool*arr, int Q);
    TDataCellRow(QString*arr, int Q);
    TDataCellRow(std::vector<double> arr);
    TDataCellRow(std::vector<float> arr arr);
    TDataCellRow(std::vector<int> arr arr);
    TDataCellRow(std::vector<bool> arr arr);
    TDataCellRow(std::vector<QString> arr arr);
    TDataCellRow(std::vector<std::string> arr);
    //
    //
    void Assign(TDataCellRow&obj);
    TDataCellRow& operator=(TDataCellRow&obj);
    //
    int GetSize();
    //
    int GetTypeN(int N);
    int GetLengthN(int N);
    TypeCell* GetTypeInfoN(int N);
    //
    DataCell* GetCellN(int N);
    //
    void Set(TVectorOfCells cells);
    void Set(DataCell* cells, int Q);
    void Set(double*arr, int Q);
    void Set(float*arr, int Q);
    void Set(int*arr, int Q);
    void Set(bool*arr, int Q);
    void Set(QString*arr, int Q);
    //
    void Set(TDoubleVector arr);
    void Set(TFloatVector arr);
    void Set(TIntVector arr);
    void Set(TBoolVector arr);
    void Set(TStringVector arr);
    void Set(TStdStringVector arr);
    //
    void SetValAndTypeDoubleN(double val, int N);
    void SetValAndTypeFloatN(float val, int N);
    void SetValAndTypeIntN(int val, int N);
    void SetValAndTypeBoolN(bool val, int N);
    void SetValAndTypeStringN(QString val, int N);
    //
    void SetArrAndTypeDoubleN(double* arr, int Q, int N);
    void SetArrAndTypeFloatN(float *arr,  int Q,int N);
    void SetArrAndTypeIntN(int *arr,  int Q,int N);
    void SetArrAndTypeBoolN(bool *arr,  int Q,int N);
    void SetArrAndTypeStringN(QString *arr,  int Q,int N);
    //
    void SetByValDoubleN(double val, int N);
    void SetByValFloatN(float val, int N);
    void SetByValIntN(int val, int N);
    void SetByValBoolN(bool val, int N);
    void SetByValStringN(QString val, int N);
    //
    void SetBy(TDoubleVector x);
    void SetBy(TFloatVector x);
    void SetBy(TIntVector x);
    void SetBy(TBoolVector x);
    void SetBy(TStringVector x);
    void SetBy(TStdStringVector x);
    //
    void SetByArrDoubleN(double* arr, int Q, int N);
    void SetByArrFloatN(float *arr,  int Q,int N);
    void SetByArrIntN(int *arr, int Q,int N);
    void SetByArrBoolN(bool *arr, int Q,int N);
    void SetByArrStringN(QString *arr, int Q,int N);
    //
    double GetDoubleValN(int CellN);
    float GetFloatValN(int CellN);
    int GetIntValN(int CellN);
    bool GetBoolValN(int CellN);
    QString ToStringN(int CellN);
    //
    double GetDoubleValNN(int CellN, int ValN=1);
    float GetFloatValNN(int CellN, int ValN=1);
    int GetIntValNN(int CellN, int ValN=1);
    bool GetBoolValNN(int CellN, int ValN=1);
    QString ToStringNN(int CellN, int ValN=1);
    //
    void GetDoubleArrN(double*&arr, int&Length, int N);
    void GetFloatArrN(float*&arr, int&Length, int N);
    void GetIntArrN(int*&arr, int&Length, int N);
    void GetBoolArrN(bool*&arr, int&Length, int N);
    void GetStringArrN(QString*&arr, int&Length, int N);
    //
    void ReturnAsDoubleArrByActiveValsOfCells(double arr[], int&QCells);//(double*&arr, int&QCells);
    void ReturnAsFloatArrByActiveValsOfCells(float arr[], int&QCells);//(float*&arr, int&QCells);
    void ReturnAsIntArrByActiveValsOfCells(int arr[], int&QCells);//(int*&arr, int&QCells);
    void ReturnAsBoolArrByActiveValsOfCells(bool arr[], int&QCells);//(bool*&arr, int&QCells);
    void ReturnAsStringArrByActiveValsOfCells(QString arr[], int&QCells);//(QString*&arr, int&QCells);
    //
    void SetN(DataCell*cell, int N);
    void Add(DataCell*cell);
    void Ins(DataCell*cell, int N);
    void Del(int N);
    //
    TDoubleVector GetAsDoubleVector();
    TFloatVector GetAsFloatVector();
    TIntVector GetAsIntVector();
    TBoolVector GetAsBoolVector();
    TStringVector GetAsStringVector();
    //TStdStringVector GetAsЫевStringVector();
    TVectorOfCells GetCells();
    //
    void SetNull();
    //
    QString GetAsStringSimple(QString Separator="; ");
};
//
//
class TDataCellRow_WithHeader
{
    DataCell Header;
    TVectorOfCells row;
public:
    TDataCellRow_WithHeader();
    TDataCellRow_WithHeader(TDataCellRow_WithHeader&obj);
    TDataCellRow_WithHeader(DataCell* Hdr, TDataCellRow row);
    TDataCellRow_WithHeader(DataCell* Hdr, TVectorOfCells cells);
    TDataCellRow_WithHeader(DataCell* Hdr, DataCell* cells, int Q);
    TDataCellRow_WithHeader(DataCell* Hdr, double*arr, int Q);
    TDataCellRow_WithHeader(DataCell* Hdr, float*arr, int Q);
    TDataCellRow_WithHeader(DataCell* Hdr, int*arr, int Q);
    TDataCellRow_WithHeader(DataCell* Hdr, bool*arr, int Q);
    TDataCellRow_WithHeader(DataCell* Hdr, QString*arr, int Q);
    TDataCellRow_WithHeader(DataCell* Hdr, TDoubleVector arr);
    TDataCellRow_WithHeader(DataCell* Hdr, TFloatVector arr);
    TDataCellRow_WithHeader(DataCell* Hdr, TIntVector arr);
    TDataCellRow_WithHeader(DataCell* Hdr, TBoolVector arr);
    TDataCellRow_WithHeader(DataCell* Hdr, TStringVector arr);
    TDataCellRow_WithHeader(DataCell* Hdr, TStdStringVector arr);
    //
    //
    void Assign(TDataCellRow_WithHeader&obj);
    TDataCellRow_WithHeader& operator=(TDataCellRow_WithHeader&obj);
    //
    int GetSize();
    //
    int GetTypeN(int N);
    int GetLengthN(int N);
    TypeCell* GetTypeInfoN(int N);
    //
    DataCell* GetContentCellN(int N);
    DataCell* GetHeader();
    TDataCellRow* GetContent();
    //
    void SetHeader(DataCell* Hdr);
    //
    void Set(TVectorOfCells cell, DataCell* Hdr);
    void Set(DataCell* cells, int Qs, DataCell* Hdr);
    void Set(double*arr, int Qs, DataCell* Hdr);
    void Set(float*arr, int Qs, DataCell* Hdr);
    void Set(int*arr, int Qs, DataCell* Hdr);
    void Set(bool*arr, int Qs, DataCell* Hdr);
    void Set(QString*arr, int Qs, DataCell* Hdr);
    //
    void Set(TDoubleVector arrs, DataCell* Hdr);
    void Set(TFloatVector arrs, DataCell* Hdr);
    void Set(TIntVector arrs, DataCell* Hdr);
    void Set(TBoolVector arrs, DataCell* Hdr);
    void Set(TStringVector arrs, DataCell* Hdr);
    void Set(TStdStringVector arrs, DataCell* Hdr);
    //
    void SetValAndTypeDoubleN(double val, int N);
    void SetValAndTypeFloatN(float val, int N);
    void SetValAndTypeIntN(int val, int N);
    void SetValAndTypeBoolN(bool val, int N);
    void SetValAndTypeStringN(QString val, int N);
    //
    void SetArrAndTypeDoubleN(double* arr, int Q, int N);
    void SetArrAndTypeFloatN(float *arr,  int Q,int N);
    void SetArrAndTypeIntN(int *arr,  int Q,int N);
    void SetArrAndTypeBoolN(bool *arr,  int Q,int N);
    void SetArrAndTypeStringN(QString *arr,  int Q,int N);
    //
    void SetByValDoubleN(double val, int N);
    void SetByValFloatN(float val, int N);
    void SetByValIntN(int val, int N);
    void SetByValBoolN(bool val, int N);
    void SetByValStringN(QString val, int N);
    //
    void SetBy(TDoubleVector x);
    void SetBy(TFloatVector x);
    void SetBy(TIntVector x);
    void SetBy(TBoolVector x);
    void SetBy(TStringVector x);
    void SetBy(TStdStringVector x);
    //
    void SetByArrDoubleN(double* arr, int Q, int N);
    void SetByArrFloatN(float *arr,  int Q,int N);
    void SetByArrIntN(int *arr, int Q,int N);
    void SetByArrBoolN(bool *arr, int Q,int N);
    void SetByArrStringN(QString *arr, int Q,int N);
    //
    double GetDoubleValN(int CellN);
    float GetFloatValN(int CellN);
    int GetIntValN(int CellN);
    bool GetBoolValN(int CellN);
    QString ToStringN(int CellN);
    //
    double GetDoubleValNN(int CellN, int ValN=1);
    float GetFloatValNN(int CellN, int ValN=1);
    int GetIntValNN(int CellN, int ValN=1);
    bool GetBoolValNN(int CellN, int ValN=1);
    QString ToStringNN(int CellN, int ValN=1);
    //
    void GetDoubleArrN(double*&arr, int&Length, int N);
    void GetFloatArrN(float*&arr, int&Length, int N);
    void GetIntArrN(int*&arr, int&Length, int N);
    void GetBoolArrN(bool*&arr, int&Length, int N);
    void GetStringArrN(QString*&arr, int&Length, int N);
    //
    void ReturnAsDoubleArrByActiveValsOfCells(double arr[], int&QCells);//(double*&arr, int&QCells);
    void ReturnAsFloatArrByActiveValsOfCells(float arr[], int&QCells);//(float*&arr, int&QCells);
    void ReturnAsIntArrByActiveValsOfCells(int arr[], int&QCells);//(int*&arr, int&QCells);
    void ReturnAsBoolArrByActiveValsOfCells(bool arr[], int&QCells);//(bool*&arr, int&QCells);
    void ReturnAsStringArrByActiveValsOfCells(QString arr[], int&QCells);//(QString*&arr, int&QCells);
    //
    void SetN(DataCell*cell, int N);
    void Add(DataCell*cell);
    void Ins(DataCell*cell, int N);
    void Del(int N);
    //
    TDoubleVector GetAsDoubleVector();
    TFloatVector GetAsFloatVector();
    TIntVector GetAsIntVector();
    TBoolVector GetAsBoolVector();
    TStringVector GetAsStringVector();
    //TStdStringVector GetAsЫевStringVector();

    //
    void SetNull();
    //
    QString GetAsStringSimple(QString SeparatorOfContents="; ", QString SeparatorBetweenHdrAndCnt=": ");
};

#endif // TDATACELLROW_H
