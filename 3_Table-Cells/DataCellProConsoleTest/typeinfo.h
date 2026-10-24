#ifndef TYPEINFO_H
#define TYPEINFO_H

#include<vector>
#include<QString>
#include "tableinfo.h"

class TypeCell
{
    int TypeN, Length;
public:
    TypeCell();
    TypeCell(int TypeN, int length=2);
    int GetTypeN();
    int GetLength();
    void Get(int&TypeN, int&length);
    void SetTypeN(int TypeN);
    void SetLength(int length);
    void Set(int TypeN, int length=2);
};

class TypeCellRow
{
    int Q;
    std::vector<TypeCell>data;
public:
    TypeCellRow();
    TypeCellRow(TypeCell*cells, int Q);
    TypeCellRow(TypeCell cell);
    TypeCellRow(int*types, int*lengths, int Q);
    //
    void SetSize(int Q);
    TypeCell GetCellN(int CellN);
    void SetCellN(TypeCell cell, int CellN);
    //
    int GetTypeN_CellN(int CellN);
    int GetLength_CellN(int CellN);
    void Get_CellN(int&TypeN, int&length, int CellN);
    void SetTypeN_CellN(int TypeN, int CellN);
    void SetLength_CellN(int TypeN, int CellN);
    void Set_CellN(int TypeN, int length, int CellN);
};
//class TypeInfo
//{
//public:
//    TypeInfo();
//};

#endif // TYPEINFO_H
