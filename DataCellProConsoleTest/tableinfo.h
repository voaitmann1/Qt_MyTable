#ifndef TABLEINFO_H
#define TABLEINFO_H

#include"mylib.h"

//class TableInfo
//{
//public:
//    TableInfo();
//};
    //
    const int DoubleTypeN = 1;
    const int FloatTypeN = 2;
    const int IntTypeN = 3;
    const int BoolTypeN = 4;
    const int StringTypeN = 5;
    //
    const int DoubleArrayTypeN = 11;
    const int FloatArrayTypeN = 12;
    const int IntArrayTypeN = 13;
    const int BoolArrayTypeN = 14;
    const int StringArrayTypeN = 15;
    //
    const int UniqueIntValKeeperTypeN = 23;
    //
    //const int TDBCOlHeader_Items_Double_TypeN=31;
    //const int TDBCOlHeader_Items_Int_TypeN=33;
    //const int TDBCOlHeader_Items_String_TypeN=33;
    //
    const int DoubleItemsDBFieldHeaderCellTypeN = 31;
    const int IntItemsDBFieldHeaderCellTypeN = 33;
    const int StringItemsDBFieldHeaderCellTypeN = 35;
    //
    const int DefaultAnyCellTypeN = StringTypeN;
    const int DefaultContentCellTypeN = DoubleTypeN;
    const int DefaultColOfLineHeaderCellTypeN = IntTypeN;
    const int DefaultLineOfColHeaderCellTypeN = DefaultAnyCellTypeN;
    //
    const int DefaultArrayLength=1;
    //
    const std::string TableDataComponent_ContentCell = "Content cell";
    const std::string TableDataComponent_LineOfColHeaderCell = "Line of Col Hdr";
    const std::string TableDataComponent_ColOfLineHeaderCell = "Col of Line Hdr";
    const std::string TableDataComponent_LinesGenName = "Lines Gen Name";
    const std::string TableDataComponent_ColsGenName = "Cols Gen Name";
    const std::string TableDataComponent_TableName = "Table Name";
    const std::string TableDataComponent_LinesGenName_Scnd = "Lines Gen Name Scnd";
    const std::string TableDataComponent_ColsGenName_Scnd = "Cols Gen Name Scnd";
    const std::string TableDataComponent_TableName_Scnd = "Table Name Scnd";
    const std::string TableDataComponent_LineOfColHeaderCell_Scnd = "Line of Col Hdr Scnd";
    const std::string TableDataComponent_ColOfLineHeaderCell_Scnd = "Col of Line Hdr Scnd";
    //
    const std::string TrueWord = "true";
    const std::string FalseWord = "false";
    //
    //
    bool TypeNIsCorrectArrayTypeN(int TypeN);
    bool TypeNIsCorrectNumberTypeN(int TypeN);
    bool TypeNIsDBFieldHeaderForChoiceTypeN(int TypeN);
    bool TypeNIsCorrect(int TypeN);
    //
    //


    //
#endif // TABLEINFO_H
