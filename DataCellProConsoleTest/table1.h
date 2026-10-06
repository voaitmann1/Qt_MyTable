#ifndef TABLE1_H
#define TABLE1_H

#include"datacellsetarray2d.h"

class TTableHeader1{
public:
    DataCell TableHeader, LinesGeneralHeader, ColumnsGeneralHeader;
    TTableHeader1();
};

class Table1
{
    DataCellArray2D content, LineOfColHeader, ColOfLineHeader;
    TTableHeader1*TableHeader;
    TTableInfo*TblInf;
public:
    Table1();
};

#endif // TABLE1_H
