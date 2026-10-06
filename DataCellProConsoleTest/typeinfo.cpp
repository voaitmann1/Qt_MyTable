#include "typeinfo.h"

TypeCell::TypeCell(){
    TypeN=DefaultAnyCellTypeN;
    Length=DefaultArrayLength;
}
TypeCell::TypeCell(int TypeN, int length){
    SetTypeN(TypeN);
    SetLength(length);
}

int TypeCell::GetTypeN(){return TypeN;}
int TypeCell::GetLength(){return Length;}
void TypeCell::Get(int&TypeN, int&length){}
void TypeCell::SetTypeN(int TypeN){
    if(TypeNIsCorrect(TypeN)) this->TypeN=TypeN;
    else this->TypeN=DefaultAnyCellTypeN;
}
void TypeCell::SetLength(int length){
    if(length>0 & length<MaxInt) this->Length=length;
    else this->Length=DefaultArrayLength;
}
void TypeCell::Set(int TypeN, int length){
    SetTypeN(TypeN);
    SetLength(length);
}


TypeCellRow::TypeCellRow(){
    data.clear();
    TypeCell DfltCell;
    data.at(1-1)=DfltCell;
}
TypeCellRow::TypeCellRow(TypeCell*cells, int Q){
    data.clear();
    TypeCell CurCell;
    if(cells!=NULL){
        if(Q>0 && Q<=MaxInt){
            for(int i=1; i<Q; i++){
                CurCell=cells[i-1];
                data.push_back(CurCell);
                this->Q++;
            }
        }else{
            Q=1;
            CurCell=cells[1-1];
            data.push_back(CurCell);
            this->Q--;
        }
    }else{
        if(Q>0 && Q<=MaxInt){
            for(int i=1; i<Q; i++){
                //CurCell=cells[i-1];
                data.push_back(CurCell);
                this->Q++;
            }
        }else{
            Q=1;
            //CurCell=cells[1-1];
            data.push_back(CurCell);
            this->Q--;
        }
    }
    data.at(1-1)=CurCell;
}
TypeCellRow::TypeCellRow(TypeCell cell){
    this->Q=1;
    data.clear();
    data.push_back(cell);
}
TypeCellRow::TypeCellRow(int*types, int*lengths, int Q){
    data.clear();
    TypeCell CurType;
    int TypeN, Length;
    if(Q>0 && Q<MaxInt) this->Q=Q; else Q=1;
    for(int i=1; i<=this->Q; i++){
        if(types!=NULL && TypeNIsCorrect(types[i-1]))  TypeN=types[i-1]; else TypeN=DefaultAnyCellTypeN;
        if(lengths!=NULL && lengths[i-1]>0 && lengths[i-1]<MaxInt) Length=lengths[i-1]; else Length=1;
        CurType.Set(TypeN, Length);
        data.push_back(CurType);
    }
}
//
void TypeCellRow::SetSize(int Q){
    int dL=abs(Q-this->Q);
    TypeCell DfltCell;
    if(Q>0 && Q<MaxInt){
        if(Q>this->Q){
            for(int i=1; i<=dL; i++){
                data.push_back(DfltCell);
            }
        }else if(Q<this->Q){
            for(int i=1; i<=dL; i++){
                data.pop_back();
            }
        }
    }else Q=1;
}
//
TypeCell TypeCellRow::GetCellN(int CellN){
    TypeCell R;
    if(CellN>0 && CellN<this->Q) R=data.at(CellN-1);
    return R;
}
void TypeCellRow::SetCellN(TypeCell cell, int CellN){
    if(CellN>0 && CellN<this->Q) data.at(CellN-1)=cell;
}
//
int TypeCellRow::GetTypeN_CellN(int CellN){
    //TypeCell cell;
    int TypeN=DefaultAnyCellTypeN;
    if(CellN>0 && CellN<=this->Q) TypeN=(data.at(CellN-1)).GetTypeN();
    return TypeN;
}
int TypeCellRow::GetLength_CellN(int CellN){
    int Length=DefaultArrayLength;
    if(CellN>0 && CellN<=this->Q) Length=(data.at(CellN-1)).GetLength();
    return Length;
}
void TypeCellRow::Get_CellN(int&TypeN, int&length, int CellN){
    TypeN=GetTypeN_CellN(CellN);
    length=GetLength_CellN(CellN);
}
void TypeCellRow::SetTypeN_CellN(int TypeN, int CellN){
    if(CellN>0 & CellN<=this->Q) data.at(CellN-1).SetTypeN(TypeN) ;
}
void TypeCellRow::SetLength_CellN(int Length, int CellN){
    if(CellN>0 && CellN<=this->Q) (data.at(CellN-1)).SetLength(Length);
}
void TypeCellRow::Set_CellN(int TypeN, int length, int CellN){
    if(CellN>0 && CellN<=this->Q) (data.at(CellN-1)).Set(TypeN, length);
}

//TypeInfo::TypeInfo()
//{

//}
