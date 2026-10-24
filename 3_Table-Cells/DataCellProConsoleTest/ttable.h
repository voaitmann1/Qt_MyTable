#ifndef TTABLE_H
#define TTABLE_H
#include<vector>
#include"tdatacellrow.h"
#include"tableinfo.h"

typedef std::vector<TDataCellRow> TTableContent;

class TTable
{
    //std::vector<TDataCellRow>Content;//passing const std::vector<TDataCellRow as 'this' argument discards qualifiers [-fpermussive]
     TTableContent Content;
    //const TTableContent Content;
   // TDataCellRow LineOfColHeader, ColOfLineHeader;
    //DataCell TableHeader, LinesGeneralHeader, ColumnsGeneralHeader, SpecCell;
    ////TTableInfo*TblInf;
public:
    TTable();
    void AddRow(const TDataCellRow& row) const;
    void AddRow0(const TDataCellRow& row) const;
    void AddRow1(const TDataCellRow& row) ;
    void AddRow2(TDataCellRow row) ;
    void AddRow3(TDataCellRow& row);
    void AddRow4(TDataCellRow *row);
    //void AddRow5(const TDataCellRow row){ this->Content.push_back(row);}
    //void AddRow(TDataCellRow row){ //copied from working project
    //    Content.push_back(row);
    //}
    TDataCellRow GetContentRow(int N);
};

#endif // TTABLE_H
