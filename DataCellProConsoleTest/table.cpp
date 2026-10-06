#include "table.h"

//Table::Table()
//{
//
//}
//class Table
//{
//    DataCell*LineOfColHeader, *ColOfLineHeader, *SpecCell;
//    DataCell**Content;
//    TTableHeader*TableHeader;
//    TTableInfo*TblInf;
//public:

/*

    Table::Table(){Construct();}
    Table::Table(TTableInfo*TblInf, TDataCellRow_WithHeader* rows, bool ColumnsNotLines, TDataCellRow *RowsHeaders, TTableHeader*TableHeader, bool WriteInfo){
        Construct();
        Set(TblInf, rows, ColumnsNotLines, RowsHeaders, TableHeader, WriteInfo);
    }

    Table::~Table(){
        int QLines, QColumns, QLinesOfColHeaders, QColsOfLineHeaders;
        bool LC_Not_CL;
        TTableInfo TblInf;
        if(this->TblInf!=NULL) TblInf=(*(this->TblInf));
        //
        LC_Not_CL=TblInf.GetIf_LC_not_CL();
        QLines=TblInf.GetQLines();
        QColumns=TblInf.GetQColumns();
        QLinesOfColHeaders=TblInf.GetQColumnHeaderLines();
        QColsOfLineHeaders=TblInf.GetQLineHeaderColumns();
        //
        this->DelContent(&TblInf);
        //
        if(this->LineOfColHeader!=NULL) delete[]this->LineOfColHeader;
        if(this->ColOfLineHeader!=NULL) delete[]this->ColOfLineHeader;
        if(this->TableHeader!=NULL)delete this->TableHeader;
        if(this->TblInf!=NULL)delete this->TblInf;
        if(this->SpecCell!=NULL)delete this->SpecCell;
        //
    }
    //
    Table::Table(Table&obj){
        Construct();
        Assign(obj);
    }
    //
    void Table::Construct(){
        TTableInfo TblInf;
        int QLines, QColumns, QLinesOfColHeaders, QColsOfLineHeaders;
        bool LC_Not_CL;
        //
        LC_Not_CL=TblInf.GetIf_LC_not_CL();
        QLines=TblInf.GetQLines();
        QColumns=TblInf.GetQColumns();
        QLinesOfColHeaders=TblInf.GetQColumnHeaderLines();
        QColsOfLineHeaders=TblInf.GetQLineHeaderColumns();
        //
        if(LC_Not_CL){
            this->Content=new DataCell*[QLines];
            for(int i=1; i<=QLines; i++){
                this->Content[i-1]=new DataCell[QColumns];
            }
        }else{
            this->Content=new DataCell*[QColumns];
            for(int i=1; i<=QColumns; i++){
                this->Content[i-1]=new DataCell[QLines];
            }
        }
        if(QLinesOfColHeaders!=0)this->LineOfColHeader=new DataCell[QColumns];
        if(QColsOfLineHeaders!=0)this->ColOfLineHeader=new DataCell[QLines];
        //
        this->TableHeader=NULL;
        //
        this->SpecCell=NULL;
        //
        this->TblInf=NULL;
        //
        //this->TblInf=new TTableInfo();
        //this->TblInf->SetSize(Qlines, QColumns);
        //this->TblInf->SetHeaderRowsExistance(QLinesOfColHeaders, QColsOfLineHeaders);
        //this->TblInf->SetIf_LC_not_CL(LC_Not_CL);
    }
    void Table::Set(TTableInfo*TblInfExt, TDataCellRow_WithHeader* rows, bool ColumnsNotLines, TDataCellRow *RowsHeaders, TTableHeader*TableHeader, bool WriteInfo){
        DataCell* cell=NULL;
        TTableInfo TblInf=DefTableInfo(TblInfExt);
        int QLines, QColumns, QLinesOfColHeaders, QColsOfLineHeaders;
        bool LC_Not_CL;
        //
        LC_Not_CL=TblInf.GetIf_LC_not_CL();
        QLines=TblInf.GetQLines();
        QColumns=TblInf.GetQColumns();
        QLinesOfColHeaders=TblInf.GetQColumnHeaderLines();
        QColsOfLineHeaders=TblInf.GetQLineHeaderColumns();
        //
        this->DelContent(&TblInf);
        this->CreateContent(&TblInf);
        //
        if(this->ColOfLineHeader!=NULL) delete[] this->ColOfLineHeader;
        if(QColsOfLineHeaders!=0)this->ColOfLineHeader=new DataCell[QLines];
        //
        if(this->LineOfColHeader!=NULL) delete[] this->LineOfColHeader;
        if(QLinesOfColHeaders!=0)this->LineOfColHeader=new DataCell[QColumns];
        //
        if(!ColumnsNotLines){//Lines
            if(LC_Not_CL){
                for(int i=1; i<=QLines; i+){
                    for(int j=1; j<=QColumns; j+){
                        cell=rows[i-1]->GetContentCellN(j);
                        this->SetCellN(cell, i, j, TblInf);
                    }
                }
            }else{
                for(int i=1; i<=QLines; i+){
                    for(int j=1; j<=QColumns; j+){
                        cell=rows[i-1]->GetContentCellN(j);
                        this->SetCellN(cell, j, i, TblInf);
                    }
                }
            }
            if(QColsOfLineHeaders!=0){
                for(int i=1; i<=QLines; i+){
                    cell=rows[i-1].GetHeader();
                    if(cell!=NULL)this->ColOfLineHeader[i-1]=(*(cell));
                }
            }
        }else{//Columns
            if(LC_Not_CL){
                for(int i=1; i<=QColumns; i+){
                    for(int j=1; j<=QLines; j+){
                        cell=rows[i-1]->GetContentCellN(j);
                        this->SetCellN(cell, j, i, TblInf);
                    }
                }
            }else{
                for(int i=1; i<=QColumns; i+){
                    for(int j=1; j<=QLines; j+){
                        cell=rows[i-1]->GetContentCellN(j);
                        this->SetCellN(cell, i, j, TblInf);
                    }
                }
            }
            if(QLinesOfColHeaders!=0){
                for(int i=1; i<=QLines; i+){
                    cell=rows[i-1].GetHeader();
                    if(cell!=NULL)this->LineOfColHeader[i-1]=(*(cell));
                }
            }
        }
        //rows, 2 erst args, now are used
        //RowsHraders
        if(RowsHeaders!=NULL){
            if(ColumnsNotLines){//Lines, ob RowsHeaders is ne rows
                if(QColsOfLineHeaders!=0){
                    for(int i=1; i<=QLines; i++){
                        this->ColOfLineHeader[i-1]=(*(RowsHeaders->GetCellN(i)));
                    }
                }
            }else{//Cols,  ob RowsHeaders is ne rows
                if(QLinesOfColHeaders!=0){
                    for(int i=1; i<=QColumns; i++){
                        this->LineOfColHeader[i-1]=(*(RowsHeaders->GetCellN(i)));
                    }
                }
            }
        }
        //3 erst args used
        if(TableHeader!=NULL){
            (*(this->TableHeader))=(*(TableHeader));
        }
        //4 erst args used
        if(WriteInfo){
            this->WriteInfo(&TblInf);
        }
    }

    void Table::Assign(Table&obj){
        this->Set();
    }
    Table& Table::operator=(Table&obj){
        Assign(obj);
        return*this;
    }
    //    int Table::GetQLines(TTableInfo*TblInfExt);
    int Table::GetQColumns(TTableInfo*TblInfExt);
    bool Table::GetIf_LC_not_CL(TTableInfo*TblInfExt);
    DataCell* Table::GetCell(int LineN, int ColN=1, TTableInfo*TblInfExt);
    DataCell* Table::GetCell_LineOfColHeader(int ColN=1, TTableInfo*TblInfExt);
    DataCell* Table::GetCell_ColOfLineHeader(int LineN=1, TTableInfo*TblInfExt);
    //
    DataCell* Table::GetTableHeader();
    DataCell* Table::GetLinesGeneralHeader();
    DataCell* Table::GetColumnsGeneralHeader();
    DataCell* Table::GetSpecCell();
    //
    TDataCellRow_WithHeader* Table::GetLineN(int LineN, TTableInfo*TblInfExt){
        TDataCellRow_WithHeader BigRow, *PBigRow;
        TDataCellRow row;
        DataCell*cell;
        TTableInfo TblInf=this->DefTableInfo(TblInfExt);
        int QLines=TblInf.GetQLines(), QColumns=TblInf.GetQColumns();
        for(int j=1; j<=QColumns; j++){
            cell=this->GetCell(LineN, j, &TblInf);
            row.Add(cell);
        }
        cell=this->GetCell_ColOfLineHeader(LineN, TblInfExt);
        BigRow.Set(row.GetCells(), cell);
        PBigRow=&BigRow;
        return PBigRow;
    }
    TDataCellRow_WithHeader* Table::GetColumnN(int ColN, TTableInfo *TblInfExt){
        TDataCellRow_WithHeader BigRow, *PBigRow;
        TDataCellRow row;
        DataCell*cell;
        TTableInfo TblInf=this->DefTableInfo(TblInfExt);
        int QLines=TblInf.GetQLines(), QColumns=TblInf.GetQColumns();
        for(int i=1; i<=QColumns; i++){
            cell=this->GetCell(i, ColN, &TblInf);
            row.Add(cell);
        }
        cell=this->GetCell_LineOfColHeader(ColN, TblInfExt);
        BigRow.Set(row.GetCells(), cell);
        PBigRow=&BigRow;
        return PBigRow;
    }
    TDataCellRow* Table::GetContentOfLineN(int LineN, TTableInfo *TblInfExt){
        TDataCellRow_WithHeader* BigRow=this->GetLineN(LineN, TblInfExt);
        TDataCellRow *row=BigRow->GetContent();
        return row;
    }

    TDataCellRow* Table::GetContentOfColumnN(int ColN, TTableInfo *TblInfExt){
        TDataCellRow_WithHeader* BigRow=this->GetColumnN(ColN, TblInfExt);
        TDataCellRow *row=BigRow->GetContent();
        return row;
    }
    //
    void Table::AddLine(TDataCellRow_WithHeader* row, TTableInfo *TblInfExt);
    void Table::InsLine(TDataCellRow_WithHeader* row, int N, TTableInfo *TblInfExt);
    void Table::DelLine(int N);
    void Table::AddColumn(TDataCellRow_WithHeader* row, TTableInfo *TblInfExt);
    void Table::InsColumn(TDataCellRow_WithHeader* row, int N, TTableInfo *TblInfExt);
    void Table::DelColumn(int N, TTableInfo *TblInfExt);
    //
    double Table::GetDoubleVal(int LineN, int ColN=1, TTableInfo*TblInfExt);
    double Table::GetDoubleVal_LineOfColHeader( int ColN=1, TTableInfo*TblInfExt);
    double Table::GetDoubleVal_ColOfLineHeader( int ine=1, TTableInfo*TblInfExt);
    int Table::GetIntVal(int LineN, int ColN=1, TTableInfo*TblInfExt);
    int Table::GetIntVal_LineOfColHeader( int ColN=1, TTableInfo*TblInfExtL);
    int Table::GetIntVal_ColOfLineHeader( int ine=1, TTableInfo*TblInfExtL);
    QString Table::ToString(int LineN, int ColN=1, TTableInfo*TblInfExt);
    QString Table::ToString_LineOfColHeader( int ColN=1, TTableInfo*TblInfExt);
    QString Table::ToString_ColOfLineHeader( int ine=1, TTableInfo*TblInfExt);
    //
    QString Table::GetContentLineN(int LineN, TTableInfo*TblInfExt);
    QString Table::GetLineN_withHeader(int LineN, TTableInfo*TblInfExt);
    //
    void Table::SetCellN(DataCell *cell, int LineN, int ColN, TTableInfo*TblInfExt){
        TTableInfo TblInf=DefTableInfo(TblInfExt);
        int QLines, QColumns;//, QLinesOfColHeaders, QColsOfLineHeaders;
        bool LC_Not_CL;
        //
        LC_Not_CL=TblInf.GetIf_LC_not_CL();
        QLines=TblInf.GetQLines();
        QColumns=TblInf.GetQColumns();
        //
        if(LC_not_CL){
            (*(this->Content[LineN-1][ColN-1]))=(*(cell));
        }else{
            (*(this->Content[ColN-1][LineN-1]))=(*(cell));
        }
    }

    void Table::SetCellN_LineOfColHeader(DataCell *cell, int ColN, TTableInfo*TblInfExt);
    void Table::SetCellN_ColOfLineHeader(DataCell *cell, int LineN, TTableInfo*TblInfExt);
    //
    void Table::CreateContent(TTableInfo *TblInfExt){
        TTableInfo TblInf=DefTableInfo(TblInfExt);
        int QLines, QColumns;//, QLinesOfColHeaders, QColsOfLineHeaders;
        bool LC_Not_CL;
        //
        LC_Not_CL=TblInf.GetIf_LC_not_CL();
        QLines=TblInf.GetQLines();
        QColumns=TblInf.GetQColumns();
        //QLinesOfColHeaders=TblInf.GetQColumnHeaderLines();
        //QColsOfLineHeaders=TblInf.GetQLineHeaderColumns();
        //
        if(LC_Not_CL){
            this->Content=new DataCell*[QLines];
            for(int i=1; i<=QLines; i++){
                 this->Content[i-1]=new DataCell[QColumns];
            }
        }else{
            this->Content=new DataCell*[QColumns];
            for(int i=1; i<=QColumns; i++){
                 this->Content[i-1]=new DataCell[QLines];
            }
        }
    }
    void Table::DelContent(TTableInfo*TblInfExt){
        TTableInfo TblInf=DefTableInfo(TblInfExt);
        int QLines, QColumns;//, QLinesOfColHeaders, QColsOfLineHeaders;
        bool LC_Not_CL;
        //
        LC_Not_CL=TblInf.GetIf_LC_not_CL();
        QLines=TblInf.GetQLines();
        QColumns=TblInf.GetQColumns();
        //QLinesOfColHeaders=TblInf.GetQColumnHeaderLines();
        //QColsOfLineHeaders=TblInf.GetQLineHeaderColumns();
        //
        if(LC_Not_CL){
            for(int i=1; i<=QLines; i++) delete[]this->Content[i-1];
            delete[]this->Content;
        }else{
            for(int i=1; i<=QColumns; i++) delete[]this->Content[i-1];
            delete[]this->Content;
        }
    }
    //
    TTableInfo Table::DefTableInfo(TTableInfo*TblInfExt){
        TTableInfo TblInf;
        if(TblInfExt!=NULL) TblInf=(*(TblInfExt));
        else if(this->TblInf!=NULL) TblInf=(*(this->TblInf));
        //else NOp: default constr
        return TblInf;
    }
    void Table::WriteInfo(TTableInfo*TblInfExt){
        TTableInfo TblInf=DefTableInfo(TblInfExt);
        if(this->TblInf==NULL) this->TblInf=new TTableInfo();
        (*(this->TblInf))=TblInf;
    }
    void Table::DelInfo(){
        if(this->TblInf!=NULL) delete this->TblInf;
        this->TblInf=NULL;
    }
    //
    void Table::Show(TValsShowHide*vsh);

    */

//};
