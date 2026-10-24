#include "datacellsetarray2d.h"

//class DataCellArray2D
//{
//    DataCell**cell;
//    int QExRowsLines, QIneRowsCols;
//public:
    DataCellArray2D::DataCellArray2D(){}
    DataCellArray2D::DataCellArray2D(DataCell*cell, int Q){}
    DataCellArray2D::DataCellArray2D(DataCell**cell, int QExtRowsLines, int QIneRowsCols){}
    DataCellArray2D::DataCellArray2D(DataCellArray2D&obj){}
    DataCellArray2D::DataCellArray2D(TDataCellRow row){}
    DataCellArray2D::DataCellArray2D(TDataCellRow*rows, int QRows){}
    DataCellArray2D::~DataCellArray2D(){}
    void DataCellArray2D::Construct(){
        this->cell=NULL;
        this->QExtRowsLines=0;
        this->QIneRowsCols=0;
    }
    void DataCellArray2D::Assign(DataCellArray2D&obj){}
    DataCellArray2D& DataCellArray2D::operator =(DataCellArray2D&obj){}
    void DataCellArray2D::SetNull(){
        if(this->cell!=NULL){
            for(int i=1; i<=this->QExtRowsLines; i++){
                delete[]cell[i-1];
            }
            delete[]cell;
            cell=NULL;
        }
    }
    void DataCellArray2D::SetOneDflt(){
        SetNull();
        this->QExtRowsLines=1;
        this->QIneRowsCols=1;
        this->cell=new DataCell*[QExtRowsLines];
        for(int i=1; i<=this->QExtRowsLines; i++){
            this->cell[i-1]=new DataCell[this->QIneRowsCols];
        }
    }
    void DataCellArray2D::Set(DataCell*cell, int Q){
        this->SetNull();
        this->QIneRowsCols=1;
        this->QExtRowsLines=Q;
        this->cell=new DataCell*[this->QExtRowsLines];
        for(int i=1; i<=this->QExtRowsLines; i++){
            this->cell[i-1]=new DataCell[this->QIneRowsCols];
        }
        if(cell!=NULL){
            for(int i=1; i<=this->QExtRowsLines; i++){
                for(int j=1; j<=this->QIneRowsCols; j++){
                    this->cell[i-1][j-1]=cell[i-1];
                }
            }
        }
    }
    void DataCellArray2D::Set(DataCell**cell, int QExtRowsLines, int QIneRowsCols){
        this->SetNull();
        this->QIneRowsCols=QIneRowsCols;
        this->QExtRowsLines=QExtRowsLines;
        this->cell=new DataCell*[this->QExtRowsLines];
        for(int i=1; i<=this->QExtRowsLines; i++){
            this->cell[i-1]=new DataCell[this->QIneRowsCols];
        }
        if(cell!=NULL){
            for(int i=1; i<=this->QExtRowsLines; i++){
                for(int j=1; j<=this->QIneRowsCols; j++){
                    this->cell[i-1][j-1]=cell[i-1][j-1];
                }
            }
        }
    }
    void DataCellArray2D::Set(TDataCellRow row){
        //DataCell*cell=NULL;
        //int Q=row.GetSize();
        //if(Q>0){
        //    cell=new DataCell[Q];
        //    for(int i=1; i<=Q; i++){
        //        cell[i-1]=(*(row.GetCellN(i)));
        //    }
        //    Set(cell, Q);
        //    delete[]cell;
        //    this->QExRowsLines=row.GetSize();
        //    this->QIneRowsCols=1;
        //}
        //also possible
        //
        this->SetNull();
        this->QIneRowsCols=1;
        this->QExtRowsLines=row.GetSize();
        if(this->QIneRowsCols>0 && this->QExtRowsLines>0){
            this->cell=new DataCell*[this->QExtRowsLines];
            for(int i=1; i<=this->QExtRowsLines; i++){
                this->cell[i-1]=new DataCell[this->QIneRowsCols];
            }
            if(cell!=NULL){
                for(int i=1; i<=this->QExtRowsLines; i++){
                    for(int j=1; j<=this->QIneRowsCols; j++){
                        this->cell[i-1][j-1]=(*(row.GetCellN(i)));
                    }
                }
            }
        }
    }
    void DataCellArray2D::Set(TDataCellRow*rows, int QRows){
        //DataCell**cell=NULL;
        if(rows!=NULL){
            SetNull();
            this->QIneRowsCols =rows[1-1].GetSize();
            this->QExtRowsLines=QRows;
            if(this->QIneRowsCols>0 && this->QExtRowsLines>0 && rows!=NULL){
                this->cell=new DataCell*[this->QExtRowsLines];
                for(int i=1; i<=this->QExtRowsLines; i++){
                    this->cell[i-1]=new DataCell[this->QIneRowsCols];
                }
            }
        }
    }
    int DataCellArray2D::GetQExtRowsLines(){ return this->QExtRowsLines;}
    int DataCellArray2D::GetQIneRowsCols(){ return this->QIneRowsCols;}
    bool DataCellArray2D::CellNExists(int ExtRowLineN, int IneRowColN){
        return(ExtRowLineN>0 && ExtRowLineN<=this->QExtRowsLines && IneRowColN>0 && IneRowColN<=this->QIneRowsCols);
    }
    DataCell* DataCellArray2D::GetCell(int ExtRowLineN, int IneRowColN){
        DataCell*ptr=NULL;
        if(ExtRowLineN>0 && ExtRowLineN<=this->QExtRowsLines && IneRowColN>0 && IneRowColN<=this->QIneRowsCols){
            ptr=&(this->cell[ExtRowLineN-1][IneRowColN-1]);
        }
        return ptr;
    }
    TypeCell* DataCellArray2D::GetCellType(int ExtRowLineN, int IneRowColN){
        DataCell*CellPtr=GetCell(ExtRowLineN, IneRowColN);
        TypeCell*TypePtr=NULL;
        if(CellPtr!=NULL){
            TypePtr=CellPtr->GetTypeInfo();
        }
        return TypePtr;
    }
    TDataCellRow DataCellArray2D::GetExtRowLineN(int N) const{
        TDataCellRow row;
        DataCell *cell;
        if(N>0 && N<=this->QExtRowsLines && this->cell!=NULL){
            for(int i=1; i<=this->QIneRowsCols; i++){
                cell=this->GetCell(N, i); //this discards qualifiers (const)
                row.Add(cell);
            }
        }
        return row;
    }

    TDataCellRow DataCellArray2D::GetIneRowColN(int N) const{
        TDataCellRow row;
        DataCell *cell;
        if(N>0 && N<=this->QIneRowsCols && this->cell!=NULL){
            for(int i=1; i<=this->QExtRowsLines; i++){
                cell=this->GetCell(i, N);  //this discards qualifiers (const) Hey, it is pointer!
                row.Add(cell);
            }
        }
        return row;
    }
    TDataCellRow DataCellArray2D::GetRowN(int N, bool ExtLine_not_IneCol) const{
        TDataCellRow row;
        if(ExtLine_not_IneCol) row=GetExtRowLineN(N); //invalid initialization of non-const reference from an rvalue of type TDataCellRow
        else row=GetIneRowColN(N);                    //invalid initialization of non-const reference from an rvalue of type TDataCellRow
        return row;
    }
    void DataCellArray2D::SetCell(DataCell*cell, int ExtRowLineN, int IneRowColN){
        if(this->CellNExists(ExtRowLineN, IneRowColN)){
            if(cell!=NULL){
                this->cell[ExtRowLineN-1][IneRowColN-1]=(*(cell));
            }
        }
    }
    void DataCellArray2D::SetCellType(TypeCell*cell, int ExtRowLineN, int IneRowColN){
        if(this->CellNExists(ExtRowLineN, IneRowColN)){
            this->cell[ExtRowLineN-1][IneRowColN-1].SetType(cell);
        }
    }
    void DataCellArray2D::SetExtRowLineN(int N, TDataCellRow*row){
        DataCell *cell;
        if(N>0 && N<=this->QExtRowsLines && row!=NULL){
            for(int i=1; i<=this->QExtRowsLines; i++){
                for(int j=1; j<=this->QIneRowsCols; j++){
                    cell=row->GetCellN(j);
                    this->cell[i-1][j-1]=(*(cell));
                }
            }
        }
    }
    void DataCellArray2D::SetIneRowColN(int N, TDataCellRow*row){
        DataCell *cell;
        if(N>0 && N<=this->QIneRowsCols && row!=NULL){
            for(int i=1; i<=this->QExtRowsLines; i++){
                for(int j=1; j<=this->QIneRowsCols; j++){
                    cell=row->GetCellN(i);
                    this->cell[i-1][j-1]=(*(cell));
                }
            }
        }
    }
    void DataCellArray2D::SetRowN(int N, TDataCellRow*row, bool ExtLine_not_IneCol){
        if(ExtLine_not_IneCol) this->SetExtRowLineN(N, row);
        else this->SetIneRowColN(N, row);
    }
    void DataCellArray2D::InsExtRowLineN(int N, TDataCellRow*row){
        DataCell *CurCell, **x;
        if(N>0 && N<=this->QExtRowsLines && row!=NULL){
           //create buffer
            x=new DataCell*[this->QExtRowsLines+1];
            for(int i=1; i<=this->QExtRowsLines+1; i++){
                x[i-1]=new DataCell[this->QIneRowsCols];
            }
            //copy to buffer
            for(int i=1; i<=this->QExtRowsLines; i++){
                for(int j=1; j<=this->QIneRowsCols; j++){
                    if(i<N){
                        CurCell=this->GetCell(i,j);
                        x[i-1][j-1]=(*(CurCell));
                    }else if(i>N){
                        CurCell=this->GetCell(i,j);
                        x[i+1-1][j-1]=(*(CurCell));
                    }else{
                        CurCell=row->GetCellN(i);
                        x[i-1][j-1]=(*(CurCell));
                    }
                }
            }
            //delete old
            SetNull();
            //point with old to created data
            this->cell=x;
            //
        }//if possible where to ins
    }//fn
    void DataCellArray2D::InsIneRowColN(int N, TDataCellRow*row){
        DataCell *CurCell, **x;
        if(N>0 && N<=this->QIneRowsCols && row!=NULL){
           //create buffer
            x=new DataCell*[this->QExtRowsLines];
            for(int i=1; i<=this->QExtRowsLines; i++){
                x[i-1]=new DataCell[this->QIneRowsCols+1];
            }
            //copy to buffer
            for(int i=1; i<=this->QExtRowsLines; i++){
                for(int j=1; j<=this->QIneRowsCols; j++){
                    if(j<N){
                        CurCell=this->GetCell(i,j);
                        x[i-1][j-1]=(*(CurCell));
                    }else if(j>N){
                        CurCell=this->GetCell(i,j);
                        x[i-1][j+1-1]=(*(CurCell));
                    }else{
                        CurCell=row->GetCellN(j);
                        x[i-1][j-1]=(*(CurCell));
                    }
                }
            }
            //delete old
            SetNull();
            //point with old to created data
            this->cell=x;
            //
        }//if possible where to ins
    }//fn
    void DataCellArray2D::InsN(int N, TDataCellRow*row, bool ExtLine_not_IneCol){
        if(ExtLine_not_IneCol) this->InsExtRowLineN(N, row);
        else this->InsIneRowColN(N, row);
    }
    void DataCellArray2D::AddExtRowLineN(TDataCellRow*row){
        DataCell *CurCell, **x;
        //if(N>0 && N<=this->QExtRowsLines && row!=NULL){
        //create buffer
        x=new DataCell*[this->QExtRowsLines+1];
        for(int i=1; i<=this->QExtRowsLines+1; i++){
            x[i-1]=new DataCell[this->QIneRowsCols];
         }
         //copy to buffer
         for(int i=1; i<=this->QExtRowsLines; i++){
             for(int j=1; j<=this->QIneRowsCols; j++){
                 CurCell=this->GetCell(i,j);
                 x[i-1][j-1]=(*(CurCell));
             }
         }
         for(int j=1; j<=this->QIneRowsCols; j++){
             CurCell=row->GetCellN(j);
             x[this->QExtRowsLines+1-1][j-1]=(*(CurCell));
         }
         //delete old
         SetNull();
         //point with old to created data
         this->cell=x;
         //
        //}//if possible where to ins
    }//fn
    void DataCellArray2D::AddIneRowColN(TDataCellRow*row){
        DataCell *CurCell, **x;
        //if(N>0 && N<=this->QExtRowsLines && row!=NULL){
        //create buffer
        x=new DataCell*[this->QExtRowsLines];
        for(int i=1; i<=this->QExtRowsLines; i++){
            x[i-1]=new DataCell[this->QIneRowsCols+1];
         }
         //copy to buffer
         for(int i=1; i<=this->QExtRowsLines; i++){
             for(int j=1; j<=this->QIneRowsCols; j++){
                 CurCell=this->GetCell(i,j);
                 x[i-1][j-1]=(*(CurCell));
             }
         }
         for(int i=1; i<=this->QExtRowsLines; i++){
             CurCell=row->GetCellN(i);
             x[i-1][this->QIneRowsCols+1-1]=(*(CurCell));
         }
         //delete old
         SetNull();
         //point with old to created data
         this->cell=x;
         //
        //}//if possible where to ins
    }//fn
    void DataCellArray2D::AddN(TDataCellRow*row, bool ExtLine_not_IneCol){
        if(ExtLine_not_IneCol) this->AddExtRowLineN(row);
        else this->AddIneRowColN(row);
    }
    void DataCellArray2D::DelExtRowLineN(int N){
        DataCell *CurCell, **x;
        if(N>0 && N<=this->QExtRowsLines){
           //create buffer
            x=new DataCell*[this->QExtRowsLines-1];
            for(int i=1; i<=this->QExtRowsLines-1; i++){
                x[i-1]=new DataCell[this->QIneRowsCols];
            }
            //copy to buffer
            for(int i=1; i<=this->QExtRowsLines; i++){
                for(int j=1; j<=this->QIneRowsCols; j++){
                    if(i<N){
                        CurCell=this->GetCell(i,j);
                        x[i-1][j-1]=(*(CurCell));
                    }else if(i>N){
                        CurCell=this->GetCell(i,j);
                        x[i-1-1][j-1]=(*(CurCell));
                    }else{
                        //NOp, ce wi del'd
                    }
                }
            }
            //delete old
            SetNull();
            //point with old to created data
            this->cell=x;
            //
        }//if possible where to ins
    }//fn
    void DataCellArray2D::DelIneRowColN(int N){
        DataCell *CurCell, **x;
        if(N>0 && N<=this->QExtRowsLines){
           //create buffer
            x=new DataCell*[this->QExtRowsLines];
            for(int i=1; i<=this->QExtRowsLines; i++){
                x[i-1]=new DataCell[this->QIneRowsCols-1];
            }
            //copy to buffer
            for(int i=1; i<=this->QExtRowsLines; i++){
                for(int j=1; j<=this->QIneRowsCols; j++){
                    if(j<N){
                        CurCell=this->GetCell(i,j);
                        x[i-1][j-1]=(*(CurCell));
                    }else if(j>N){
                        CurCell=this->GetCell(i,j);
                        x[i-1][j-1-1]=(*(CurCell));
                    }else{
                        //NOp, ce wi del'd
                    }
                }
            }
            //delete old
            SetNull();
            //point with old to created data
            this->cell=x;
            //
        }//if possible where to ins
    }//fn
    void DataCellArray2D::DelN(int N, bool ExtLine_not_IneCol){
        if(ExtLine_not_IneCol) this->DelExtRowLineN(N);
        else this->DelIneRowColN(N);
    }
//};
