#ifndef TABLE_H
#define TABLE_H

#include"tdatacellrow.h"

class TTableHeader{
public:
    DataCell TableHeader, LinesGeneralHeader, ColumnsGeneralHeader;
    TTableHeader();
};

class Table
{
    DataCell*LineOfColHeader, *ColOfLineHeader, *SpecCell;
    DataCell**Content;
    TTableHeader*TableHeader;
    TTableInfo*TblInf;
public:
    Table();
    Table(TTableInfo*TblInf, TDataCellRow_WithHeader* rows, bool ColumnsNotLines, TDataCellRow *RowsHeaders, TTableHeader*TableHeader, bool WriteInfo=true);
    ~Table();
    //
    Table(Table&obj);
    //
    void Construct();
    void Assign(Table&obj);
    void Set(TTableInfo*TblInf, TDataCellRow_WithHeader* rows, bool ColumnsNotLines, TDataCellRow *RowsHeaders, TTableHeader*TableHeader, bool WriteInfo=true);
    Table& operator=(Table&obj);
    //
    int GetQLines(TTableInfo*TblInfExt=NULL);
    int GetQColumns(TTableInfo*TblInfExt=NULL);
    bool GetIf_LC_not_CL(TTableInfo*TblInfExt=NULL);
    //
    DataCell* GetCell(int LineN, int ColN=1, TTableInfo*TblInfExt=NULL);
    DataCell* GetCell_LineOfColHeader(int ColN=1, TTableInfo*TblInfExt=NULL);
    DataCell* GetCell_ColOfLineHeader(int LineN=1, TTableInfo*TblInfExt=NULL);
    //
    DataCell* GetTableHeader();
    DataCell* GetLinesGeneralHeader();
    DataCell* GetColumnsGeneralHeader();
    DataCell* GetSpecCell();
    //
    TDataCellRow_WithHeader* GetLineN(int LineN, TTableInfo *TblInfExt);
    TDataCellRow_WithHeader* GetColumnN(int ColN, TTableInfo *TblInfExt);
    TDataCellRow* GetContentOfLineN(int LineN, TTableInfo *TblInfExt);
    TDataCellRow* GetContentOfColumnN(int ColN, TTableInfo *TblInfExt);
    //
    void AddLine(TDataCellRow_WithHeader* row, TTableInfo *TblInfExt);
    void InsLine(TDataCellRow_WithHeader* row, int N, TTableInfo *TblInfExt);
    void DelLine(int N, TTableInfo *TblInfExt);
    void AddColumn(TDataCellRow_WithHeader* row, TTableInfo *TblInfExt);
    void InsColumn(TDataCellRow_WithHeader* row, int N, TTableInfo *TblInfExt);
    void DelColumn(int N);
    //
    double GetDoubleVal(int LineN, int ColN=1, TTableInfo*TblInfExt=NULL);
    double GetDoubleVal_LineOfColHeader( int ColN=1, TTableInfo*TblInfExt=NULL);
    double GetDoubleVal_ColOfLineHeader( int ine=1, TTableInfo*TblInfExt=NULL);
    int GetIntVal(int LineN, int ColN=1, TTableInfo*TblInfExt=NULL);
    int GetIntVal_LineOfColHeader( int ColN=1, TTableInfo*TblInfExt=NULL);
    int GetIntVal_ColOfLineHeader( int ine=1, TTableInfo*TblInfExt=NULL);
    QString ToString(int LineN, int ColN=1, TTableInfo*TblInfExt=NULL);
    QString ToString_LineOfColHeader( int ColN=1, TTableInfo*TblInfExt=NULL);
    QString ToString_ColOfLineHeader( int ine=1, TTableInfo*TblInfExt=NULL);
    //
    QString GetContentLineN(int LineN, TTableInfo*TblInfExt=NULL);
    QString GetLineN_withHeader(int LineN, TTableInfo*TblInfExt=NULL);
    //
    void SetCellN(DataCell *cell, int LineN, int ColN, TTableInfo*TblInfExt=NULL);
    void SetCellN_LineOfColHeader(DataCell *cell, int ColN, TTableInfo*TblInfExt=NULL);
    void SetCellN_ColOfLineHeader(DataCell *cell, int LineN, TTableInfo*TblInfExt=NULL);
    //
    void DelContent(TTableInfo *TblInfExt=NULL);
    void CreateContent(TTableInfo *TblInfExt=NULL);
    //
    TTableInfo DefTableInfo(TTableInfo*TblInfExt);
    void WriteInfo(TTableInfo*TblInfExt);
    void DelInfo();
    //
    void Show(TValsShowHide*vsh);
};

#endif // TABLE_H
