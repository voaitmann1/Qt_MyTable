#include "ttable.h"

//TTable::TTable()
//{
//
//}
//class TTable
//{
//    std::vector<TDataCellRow>Content;
//    TDataCellRow LineOfColHeader, ColOfLineHeader;
//    DataCell TableHeader, LinesGeneralHeader, ColumnsGeneralHeader, SpecCell;
//    TTableInfo*TblInf;
//public:
    TTable::TTable(){

    }
    void TTable::AddRow4(TDataCellRow *row){
    //  this->Content.push_back(*row); //passing const TTab;leContent {aka std::vecto<DataCellRow>} as this argument discards qualifiers[-fpermissive]
    }
    void TTable::AddRow3(TDataCellRow& row){
    //  this->Content.push_back( row); //passing const TTab;leContent {aka std::vecto<DataCellRow>} as this argument discards qualifiers[-fpermissive]
    }
    void TTable::AddRow2(TDataCellRow row){
    //    /*this->*/Content.push_back(row); //passing const TTab;leContent {aka std::vecto<DataCellRow>} as this argument discards qualifiers[-fpermissive]
    }
    void TTable::AddRow1(const TDataCellRow& row) {
    //    this->Content.push_back(row);
    }
    void TTable::AddRow(const TDataCellRow& row) const{
    //    /*this->*/Content.push_back(row); //passing const TTab;leContent {aka std::vecto<DataCellRow>} as this argument discards qualifiers[-fpermissive]
    }
    void TTable::AddRow0(const TDataCellRow& row) const{
       const  TTableContent content;
    //    /*this->*/Content.push_back(row); //passing const TTab;leContent {aka std::vecto<DataCellRow>} as this argument discards qualifiers[-fpermissive]
       /*
       content=this->Content;
       content.push_back(row);
       this->Content=content;
       */
    }


    TDataCellRow TTable::GetContentRow(int N){
        return this->Content.at(N-1);
    }
//};
