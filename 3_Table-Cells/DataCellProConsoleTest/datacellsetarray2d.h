#ifndef DATACELLSETARRAY2D_H
#define DATACELLSETARRAY2D_H

#include"tdatacellrow.h"

class DataCellArray2D
{
    DataCell**cell;
    int QExtRowsLines, QIneRowsCols;
public:
    DataCellArray2D();
    DataCellArray2D(DataCell*cell, int Q);
    DataCellArray2D(DataCell**cell, int QExtRowsLines, int QIneRowsCols);
    DataCellArray2D(DataCellArray2D&obj);
    DataCellArray2D(TDataCellRow row);
    DataCellArray2D(TDataCellRow*rows, int QRows);
    ~DataCellArray2D();
    void Construct();
    void Assign(DataCellArray2D&obj);
    DataCellArray2D& operator =(DataCellArray2D&obj);
    void SetNull();
    void SetOneDflt();
    void Set(DataCell*cell, int Q);
    void Set(DataCell**cell, int QExtRowsLines, int QIneRowsCols);
    void Set(TDataCellRow row);
    void Set(TDataCellRow*rows, int QRows);
    int GetQExtRowsLines();
    int GetQIneRowsCols();
    bool CellNExists(int ExtRowLineN, int IneRowColN);
    DataCell* GetCell(int ExtRowLineN, int IneRowColN);
    TypeCell* GetCellType(int ExtRowLineN, int IneRowColN);
    TDataCellRow GetExtRowLineN(int N) const;
    TDataCellRow GetIneRowColN(int N) const;
    TDataCellRow GetRowN(int N, bool ExtLine_not_IneCol=true) const;
    void SetCell(DataCell*cell, int ExtRowLineN, int IneRowColN);
    void SetCellType(TypeCell*cell, int ExtRowLineN, int IneRowColN);
    void SetExtRowLineN(int N, TDataCellRow*row);
    void SetIneRowColN(int N, TDataCellRow*row);
    void SetRowN(int N, TDataCellRow*row, bool ExtLine_not_IneCol=true);
    void InsExtRowLineN(int N, TDataCellRow*row);
    void InsIneRowColN(int N, TDataCellRow*row);
    void InsN(int N, TDataCellRow*row, bool ExtLine_not_IneCol=true);
    void AddExtRowLineN(TDataCellRow*row);
    void AddIneRowColN(TDataCellRow*row);
    void AddN(TDataCellRow*row, bool ExtLine_not_IneCol=true);
    void DelExtRowLineN(int N);
    void DelIneRowColN(int N);
    void DelN(int N, bool ExtLine_not_IneCol=true);
};

#endif // DATACELLSETARRAY2D_H
