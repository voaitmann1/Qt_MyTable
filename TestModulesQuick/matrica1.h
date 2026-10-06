#ifndef MATRICA_H
#define MATRICA_H

#include"mymathlib.h"
#include<iostream>//ne wa, ma nu cout req't

const int Array2D_Rect_Simple_V1I_Lines_TypeN=1;
const int Array2D_Rect_Simple_Default_TypeN=Array2D_Rect_Simple_V1I_Lines_TypeN;

const int DataType_double_N=1;
const int DataType_float_N=2;
const int DataType_int_N=3;
const int DataType_bool_N=4;
const int DataType_QString_N=5;
const int DataType_StdString_N=6;

int GetPositionNInArray2DRectRealizedAs1D(int ExtRowN, int IneRowN, int QExtRows, int QIneRows);

template<class T>class TArray2D_Rect_Simple_Prototype{
  public:
    virtual ~TArray2D_Rect_Simple_Prototype()=default;
    void Assign(TArray2D_Rect_Simple_Prototype<T>*obj);
    //TArray2D_Rect_Simple_Prototype<T>& operator = (const TArray2D_Rect_Simple_Prototype<T>&obj);
    virtual void construct()=0;
    virtual void SetNull()=0;
    void SetOne(const T& val);
    virtual int GetTypeN()const=0;
    //int PosNOfEIR(int ExtRowN, int IneRowN)const;
    //virtual int PosNOf(int LineN, int ColN)const=0;
    virtual int GetQExtRows()const=0;
    virtual int GetQIneRows()const=0;
    virtual int GetQLines()const=0;
    virtual int GetQColumns()const=0;
    virtual void SetSize_EIR(int QExtRows, int QIneRows)=0;
    virtual void SetSize(int QLines, int QColumns)=0;
    void Set_EIR(std::vector<T>data, int QExtRows, int QIneRows);
    void Set_EIR(std::vector<std::vector<T>>data);
    void Set_EIR(const T&val, int QExtRows, int QIneRows);
    void Set(const T&val, int QLines, int QColumns);
    void Set_Lines(std::vector<T>data, int QLines, int QColumns);
    void Set_Lines(std::vector<std::vector<T>>data);
    //void Set_Lines(const T&val, int QLines, int QColumns);
    void Set_Columns(std::vector<T>data, int QLines, int QColumns);
    void Set_Columns(std::vector<std::vector<T>>data);
    //void Set_Columns(const T&val, int QLines, int QColumns);
    //void Set(const Matrix_V1S_Lines_Simple&obj);
    virtual void SetVal_EIR(const T&val, int ExtRowN, int IneRowN)=0;
    virtual void SetVal(const T&val, int LineN, int ColumnN)=0;
    //ComplexNum& GetVal_EIR(int ExtRowN, int IneRowN)const;
    virtual T GetVal_EIR(int ExtRowN, int IneRowN)const=0;
    //ComplexNum& GetVal(int LineN, int ColumnN)const;
    virtual T GetVal(int LineN, int ColumnN)const=0;
    std::vector<T> GetExtRowN(int N)const;
    std::vector<T> GetLineN(int N)const;
    std::vector<T> GetIneRowN(int N)const;
    std::vector<T> GetColumnN(int N)const;
    std::vector<T> GetContent_ExtRows()const;
    std::vector<T> GetContent_Lines()const;
    std::vector<T> GetContent_Columns()const;
    //
    //
    void SwapVals_EIR(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
    void SwapVals(int LineN1, int ColN1, int LineN2, int ColN2);
    void SwapExtRows(int ExtRowN1, int ExtRowN2);
    void SwapIneRows(int IneRowN1, int IneRowN2);
    virtual void SwapLines(int LineN1, int LineN2)=0;
    virtual void SwapColumns(int ColN1, int ColN2)=0;
    //
    //
    void SetExtRow_Simple(int N, T*row, int rowL=0, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4=1);
    virtual void SetLine_Simple(int N, T*row, int rowL=0, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4=1)=0;
    void SetIneRow_Simple(int N, T*row, int rowL=0, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4=1);
    virtual void SetColumn_Simple(int N, T*row, int rowL=0, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4=1)=0;
    //
    void AddExtRow_Simple(T*row, int rowL=0, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4=1);
    virtual void AddLine_Simple(T*row, int rowL=0, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4=1)=0;
    void AddIneRow_Simple(T*row, int rowL=0, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4=1);
    virtual void AddColumn_Simple(T*row, int rowL=0, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4=1)=0;
    //
    void InsExtRow_Simple(int N, T*row=NULL);
    virtual void InsLine_Simple(int N, T*row=NULL)=0;
    void InsIneRow_Simple(int N, T*row=NULL);
    virtual void InsColumn_Simple(int N, T*row=NULL)=0;
    //
    void DelExtRow_Simple(int N);
    virtual void DelLine_Simple(int N)=0;
    void DelIneRow_Simple(int N);
    virtual void DelColumn_Simple(int N)=0;
    //
    //
    //TArray2D_Rect_Simple_Prototype<T> SubMatrix_EIR(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
    //TArray2D_Rect_Simple_Prototype<T> SubMatrix(int LineN1, int ColumnN1, int LineN2, int ColumnN2);
    ////Matrix_V1S_Lines_Simple SubMatrix_EIR(int ExtRowN1, int QExtRows, int QEmptyExtRowsBefore);
    ////Matrix_V1S_Lines_Simple SubMatrix_Lines(int LineN1, int QLines, int QEmptyLinesBefore);
    ////Matrix_V1S_Lines_Simple SubMatrix_Columns(int ColN1, int QCols, int QEmptyColsBefore);
    //
    void StdCout_ExtRowN(int N, std::string delim="; ", bool showBrackets=true, bool RepresentVertNotHor=false);
    void StdCout_IneRowN(int N, std::string delim="; ", bool showBrackets=true, bool RepresentVertNotHor=true);
    void StdCout_LineN(int N, std::string delim="; ", bool showBrackets=true,  bool RepresentVertNotHor=false);
    void StdCout_ColN(int N, std::string delim="; ", bool showBrackets=true, bool Represent2DNot1D=true);
    void StdCout_EIR(std::string delimElem=", ", std::string delimRow="; ", bool showBrackets=true, bool Represent2DNot1D=true, bool HorExt=true);
    void StdCout(std::string delimElem=", ", std::string delimRow="; ", bool showBrackets=true, bool Represent2DNot1D=true);
};


//template<typename T> TArray2D_Rect_Simple_Prototype<T>::TArray2D_Rect_Simple_Prototype(){
//
//}
//template<typename T>TArray2D_Rect_Simple_Prototype<T>::TArray2D_Rect_Simple_Prototype(std::vector<T>data, int QLines, int QColumns){
//
//}
//template<typename T>TArray2D_Rect_Simple_Prototype<T>::TArray2D_Rect_Simple_Prototype(std::vector<std::vector<T>>data){
//
//}
//template<typename T>TArray2D_Rect_Simple_Prototype<T>::TArray2D_Rect_Simple_Prototype(const T&val, int QLines, int QColumns){
//
//}
//template<typename T>TArray2D_Rect_Simple_Prototype<T>::TArray2D_Rect_Simple_Prototype(std::vector<double>data, int QLines, int QColumns){
//
//}
//template<typename T>TArray2D_Rect_Simple_Prototype<T>::TArray2D_Rect_Simple_Prototype(std::vector<std::vector<double>>data){
//
//}
//template<typename T>TArray2D_Rect_Simple_Prototype<T>::TArray2D_Rect_Simple_Prototype(double val, int QLines, int QColumns){
//
//}
//template<typename T>TArray2D_Rect_Simple_Prototype<T>::TArray2D_Rect_Simple_Prototype(const TArray2D_Rect_Simple_Prototype&obj){
//
//}
//template<typename T>TArray2D_Rect_Simple_Prototype<T>::~TArray2D_Rect_Simple_Prototype(){
//
//}
//void TArray2D_Rect_Simple_Prototype<T>::Assign(const TArray2D_Rect_Simple_Prototype&obj){
//    T val;
//    int QExtRows=obj.GetQExtRows(), QIneRows=obj.GetQIneRows();
//    this->SetSize_EIR(QExtRows, QIneRows);
//    for(int i=1; i<=QExtRows; i++){
//        for(int j=1; j<=QIneRows; j++){
//            val=obj.GetVal_EIR(i, j);
//            this->SetVal_EIR(val, i, j);
//        }
//    }
//}
template<typename T>void TArray2D_Rect_Simple_Prototype<T>::Assign(TArray2D_Rect_Simple_Prototype<T>*obj){
    T val;
    int QExtRows=obj->GetQExtRows(), QIneRows=obj->GetQIneRows();
    this->SetSize_EIR(QExtRows, QIneRows);
    for(int i=1; i<=QExtRows; i++){
        for(int j=1; j<=QIneRows; j++){
            val=obj->GetVal_EIR(i, j);
            this->SetVal_EIR(val, i, j);
        }
    }
}
//TArray2D_Rect_Simple_Prototype& TArray2D_Rect_Simple_Prototype<T>::operator = (const TArray2D_Rect_Simple_Prototype&obj){
//
//}
//template<typename T>void TArray2D_Rect_Simple_Prototype<T>::construct(){
//    this->SetNull();
//}
//template<typename T>void TArray2D_Rect_Simple_Prototype<T>::SetNull(){
//    this->data.clear();
//    this->QLines=0;
//}
template<typename T>void TArray2D_Rect_Simple_Prototype<T>::SetOne(const T& val){
    this->SetNull();
    this->SetSize_EIR(1, 1);
    this->SetVal_EIR(val, 1, 1);
}
//template<typename T>int TArray2D_Rect_Simple_Prototype<T>::PosNOfEIR(int ExtRowN, int IneRowN)const{
//    int PosN=0, QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows(), L;//, QColumns=QIneRows, N, L;
//    if(ExtRowN>=1 && ExtRowN<=QExtRows && IneRowN>=1 && IneRowN<=QIneRows){
//        for(int i=1; i<=ExtRowN-1; i++){
//            L=QIneRows;
//            PosN+=L;
//        }
//        PosN+=IneRowN;
//    }
//    return PosN;
//}
//template<typename T>int TArray2D_Rect_Simple_Prototype<T>::PosNOf(int LineN, int ColN)const{
//    int ExtRowN=LineN, IneRowN=ColN, PosN=0;
//    PosN=this->PosNOfEIR(ExtRowN, IneRowN);
//    return PosN;
//}
//template<typename T> int TArray2D_Rect_Simple_Prototype<T>::GetQExtRows()const{
//    return this->QLines;
//}
//template<typename T> int TArray2D_Rect_Simple_Prototype<T>::GetQIneRows()const{
//    int QElements=this->data.size(), QExtRows=this->GetQExtRows();
//    int QIneRows=QElements/QExtRows;
//    return QIneRows;
//}
//template<typename T> int TArray2D_Rect_Simple_Prototype<T>::GetQLines()const{
//    return this->QLines;
//}
//template<typename T> int TArray2D_Rect_Simple_Prototype<T>::GetQColumns()const{
//    return this->GetQIneRows();
//}

//template<typename T> void TArray2D_Rect_Simple_Prototype<T>::SetSize_EIR(int QExtRows, int QIneRows){
//    T val;//(0, 0) by default
//    this->data.clear();
//    for(int i=1; i<=QExtRows; i++){
//        for(int j=1; j<=QIneRows; j++){
//            this->data.push_back(val);
//        }
//    }
//    this->QLines=QExtRows;
//}
//template<typename T> void TArray2D_Rect_Simple_Prototype<T>::SetSize(int QLines, int QColumns){
//    int QExtRows=QLines, QIneRows=QColumns;
//    this->SetSize_EIR(QExtRows, QIneRows);
//}
template<typename T> void TArray2D_Rect_Simple_Prototype<T>::Set_EIR(std::vector<T>data, int QExtRows, int QIneRows){
    int L, count, QElements=data.size();
    T defaultVal, curVal;//by default (0; 0)
    this->SetNull();
    this->SetSize_EIR(QExtRows, QIneRows);
    for(int i=1; i<=QExtRows; i++){
        L=QIneRows;
        for(int j=1; j<=L; j++){
            count++;
            if(count>QElements){
                this->SetVal_EIR(defaultVal, i, j);
            }else{
                curVal=data[count-1];
                this->SetVal_EIR(curVal, i, j);
            }
        }
    }
}
template<typename T> void TArray2D_Rect_Simple_Prototype<T>::Set_EIR(std::vector<std::vector<T>>data){
    int QExtRows=data.size(), curL, count, Lmin, Lmax;
    T curVal, dafaultVal;//by default (0, 0)
    for(int i=1; i<=QExtRows; i++){
        curL=data[i-1].size();
        if(i==1 && (i>1 && curL>Lmax)){
            Lmax=curL;
        }
    }
    this->SetSize_EIR(QExtRows, Lmax);
    for(int i=1; i<=QExtRows; i++){
        curL=data[i-1].size();
        for(int j=1; j<=curL; j++){
            curVal=data[i-1][j-1];
            this->SetVal_EIR(curVal, i, j);
        }
        for(int j=curL+1; j<=Lmax; j++){
            this->SetVal_EIR(dafaultVal, i, j);
        }
    }
}
template<typename T> void TArray2D_Rect_Simple_Prototype<T>::Set_EIR(const T&val, int QExtRows, int QIneRows){
    this->SetSize_EIR(QExtRows, QIneRows);
    for(int i=1; i<=QExtRows; i++){
        for(int j=1; j<=QExtRows; j++){
            this->SetVal_EIR(val, i, j);
        }
    }
}
template<typename T> void TArray2D_Rect_Simple_Prototype<T>::Set(const T&val, int QLines, int QColumns){
    this->SetSize(QLines, QColumns);
    for(int i=1; i<=QLines; i++){
        for(int j=1; j<=QColumns; j++){
            this->SetVal(val, i, j);
        }
    }
}

template<typename T> void TArray2D_Rect_Simple_Prototype<T>::Set_Lines(std::vector<T>data, int QLines, int QColumns){
    int PosN, LineN, ColN, L, QElements=data.size(), count=0, QElementsToSet=QLines*QColumns, QElementsGiven=data.size();
    T curVal, dfltVal;
    this->SetSize(QLines, QColumns);
    if(QElementsGiven>=QElementsToSet){
        for(LineN=1; LineN<=QLines; LineN++){
            L=QColumns;
            for(ColN=1; ColN<=L; ColN++){
                PosN=GetPositionNInArray2DRectRealizedAs1D(LineN, ColN, QLines, QColumns);
                curVal=data[PosN-1];
                this->SetVal(curVal, LineN, ColN);
            }
        }
    }else{
        for(LineN=1; LineN<=QLines; LineN++){
            L=QColumns;
            for(ColN=1; ColN<=L; ColN++){
                count++;
                PosN=GetPositionNInArray2DRectRealizedAs1D(LineN, ColN, QLines, QColumns);
                if(count<=QElementsGiven){
                    curVal=data[PosN-1];
                    this->SetVal(curVal, LineN, ColN);
                }else{
                    this->SetVal(dfltVal, LineN, ColN);
                }
            }
        }
    }
}
template<typename T> void TArray2D_Rect_Simple_Prototype<T>::Set_Lines(std::vector<std::vector<T>>data){
    int PosN, LineN, ColN, L, QLines=data.size(), QColumns, QElementsGiven=0, QElementsToSet=0, maxL, minL;
    T curVal, dfltVal;
    this->SetSize(QLines, QColumns);
    for(LineN=1; LineN<=QLines; LineN++){
        L=data[LineN-1].size();
        QElementsGiven+=L;
        if(LineN==1 || (LineN>1 && L>maxL)){
            maxL=L;
        }
        if(LineN==1 || (LineN>1 && L<minL)){
            minL=L;
        }
    }
    QColumns=maxL;
    QElementsToSet=QLines*QColumns;
    for(LineN=1; LineN<=QLines; LineN++){
        L=data[LineN-1].size();
        for(ColN=1; ColN<=L; ColN++){
            curVal=data[LineN-1][ColN-1];
            this->SetVal(curVal, LineN, ColN);
        }
        for(ColN=L+1; ColN<=maxL; ColN++){
            this->SetVal(dfltVal, LineN, ColN);
        }
    }
}
template<typename T> void TArray2D_Rect_Simple_Prototype<T>::Set_Columns(std::vector<T>data, int QLines, int QColumns){
    int PosN, LineN, ColN, L, QElements=data.size(), count, QElementsGiven=data.size(), QElementsToSet=QLines*QColumns;
    T curVal, dfltVal;
    this->SetSize(QLines, QColumns);
    if(QElementsGiven>=QElementsToSet){
        for(ColN=1; ColN<=QColumns; ColN++){
            L=QLines;
            for(LineN=1; LineN<=L; LineN++){
                PosN=GetPositionNInArray2DRectRealizedAs1D(ColN, LineN, QColumns, QLines);
                curVal=data[PosN-1];
                this->SetVal(curVal, LineN, ColN);
            }
        }
    }else{
        for(ColN=1; ColN<=QColumns; ColN++){
            L=QLines;
            for(LineN=1; LineN<=L; LineN++){
                count++;
                PosN=GetPositionNInArray2DRectRealizedAs1D(ColN, LineN, QColumns, QLines);
                if(count<=QElementsGiven){
                    curVal=data[PosN-1];
                    this->SetVal(curVal, LineN, ColN);
                }else{
                    this->SetVal(dfltVal, LineN, ColN);
                }
            }
        }
    }
}
template<typename T> void TArray2D_Rect_Simple_Prototype<T>::Set_Columns(std::vector<std::vector<T>>data){
    int PosN, LineN, ColN, L, QLines, QColumns=data.size(), QElementsGiven=0, QElementsToSet=0, maxL, minL;
    T curVal, dfltVal;
    this->SetSize(QLines, QColumns);
    for(ColN=1; ColN<=QColumns; ColN++){
        L=data[ColN-1].size();
        QElementsGiven+=L;
        if(ColN==1 || (ColN>1 && L>maxL)){
            maxL=L;
        }
        if(ColN==1 || (ColN>1 && L<minL)){
            minL=L;
        }
    }
    QLines=maxL;
    QElementsToSet=QLines*QColumns;
    for(ColN=1; ColN<=QColumns; ColN++){
        L=data[ColN-1].size();
        for(LineN=1; LineN<=L; LineN++){
            curVal=data[LineN-1][ColN-1];
            this->SetVal(curVal, LineN, ColN);
        }
        for(LineN=L+1; LineN<=maxL; LineN++){
            this->SetVal(dfltVal, LineN, ColN);
        }
    }
}
//template<typename T> void TArray2D_Rect_Simple_Prototype<T>::Set_Lines(const T&val, int QLines, int QColumns){
//    int QExtRows=QLines, QIneRows=QColumns;
//    this->Set_EIR(val, QExtRows, QIneRows);
//}
//template<typename T> void TArray2D_Rect_Simple_Prototype<T>::Set_Columns(std::vector<T>data, int QLines, int QColumns){
//    T curVal, dfltVal;
//    int count=0, PosN;
//    this->SetSize(QLines, QColumns);
//    //
//    for(int j=1; j<=QColumns; j++){
//        for(int i=1; i<=QLines; i++){
//            count++;
//            PosN=this->PosNOf(j, i);
//            curVal=data[PosN-1];//also possible
//            curVal=data[count-1];
//            this->SetVal(curVal, i, j);
//        }
//    }
//}
//template<typename T> void TArray2D_Rect_Simple_Prototype<T>::Set_Columns(std::vector<std::vector<T>>data){
//    T curVal, dfltVal;
//    int QColumns=data.size(), QLines, maxL, curL;
//    for(int i=1; i<=QColumns; i++){
//        curL=data[i-1].size();
//        if(i==1 || (i>1 && curL>maxL)){
//            maxL=curL;
//        }
//    }
//    QLines=maxL;
//    this->SetSize(QLines, QColumns);
//    for(int i=1; i<=QColumns; i++){
//        curL=data.size();
//        for(int j=1; j<=curL; j++){
//            curVal=data[i-1][j-1];
//            this->SetVal(curVal, j, i);
//        }
//        for(int j=curL+1; j<=QLines; j++){
//            this->SetVal(dfltVal, j, i);
//        }
//    }
//    this->QLines-QLines;
//}
//template<typename T> void TArray2D_Rect_Simple_Prototype<T>::Set_Columns(const T&val, int QLines, int QColumns){
//    //T curVal(val, 0);
//    this->SetSize(QLines, QColumns);
//    for(int i=1; i<=QLines; i++){
//        for(int j=1; j<=QColumns; j++){
//            this->SetVal(val, i, j);
//        }
//    }
//}
//void TArray2D_Rect_Simple_Prototype<T>::Set(const TArray2D_Rect_Simple_Prototype&obj){
//
//}
//template<typename T> void TArray2D_Rect_Simple_Prototype<T>::SetVal_EIR(const T&val, int ExtRowN, int IneRowN){
// os msb pure virtual fun!
//    int PosN=0;
//    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows();
    //PosN=this->PosNOfEIR(ExtRowN, IneRowN);
    //GetPositionNInArray2DRectRealizedAs1D(int ExtRowN, int IneRowN, int QExtRows, int QIneRows);
    //PosN=GetPositionNInArray2DRectRealizedAs1D(ExtRowN, IneRowN, QExtRows, QIneRows);
    //if(PosN!=0){
    //    this->data[PosN-1]=val;
    //}
//}
template<typename T> void TArray2D_Rect_Simple_Prototype<T>::SetVal(const T&val, int LineN, int ColumnN){
    int ExtRowN=LineN, IneRowN=ColumnN;
    this->SetVal_EIR(val, ExtRowN, IneRowN);
}
//T& TArray2D_Rect_Simple_Prototype<T>::GetVal_EIR(int ExtRowN, int IneRowN)const{
//template<typename T> T TArray2D_Rect_Simple_Prototype<T>::GetVal_EIR(int ExtRowN, int IneRowN)const{
//    // os msb pure virt'l fun!
//    int PosN=0;
//    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows();
//    //PosN=this->PosNOfEIR(ExtRowN, IneRowN);
//    PosN=GetPositionNInArray2DRectRealizedAs1D(ExtRowN, IneRowN, QExtRows, QIneRows);
//    if(PosN!=0){
//        return this->data[PosN-1];
//    }
//}
//T& TArray2D_Rect_Simple_Prototype<T>::GetVal(int LineN, int ColumnN)const{
template<typename T> T TArray2D_Rect_Simple_Prototype<T>::GetVal(int LineN, int ColumnN)const{
    int ExtRowN=LineN, IneRowN=ColumnN;
    return this->GetVal_EIR(ExtRowN, IneRowN);
}
template<typename T> std::vector<T> TArray2D_Rect_Simple_Prototype<T>::GetExtRowN(int N)const{
    std::vector<T> row;
    T val;
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows();
    if(N>=1 && N<=QExtRows){
        for(int i=1; i<=QIneRows; i++){
            val=this->GetVal_EIR(N, i);
            row.push_back(val);
        }
    }
    return row;
}
template<typename T> std::vector<T> TArray2D_Rect_Simple_Prototype<T>::GetLineN(int N)const{
    std::vector<T> row;
    T val;
    int QLines=this->GetQLines(), QColumns=this->GetQColumns();
    if(N>=1 && N<=QLines){
        for(int i=1; i<=QColumns; i++){
            val=this->GetVal(N, i);
            row.push_back(val);
        }
    }
    return row;
}
template<typename T> std::vector<T> TArray2D_Rect_Simple_Prototype<T>::GetIneRowN(int N)const{
    std::vector<T> row;
    T val;
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows();
    if(N>=1 && N<=QIneRows){
        for(int i=1; i<=QExtRows; i++){
            val=this->GetVal_EIR(i, N);
            row.push_back(val);
        }
    }
    return row;
}
template<typename T> std::vector<T> TArray2D_Rect_Simple_Prototype<T>::GetColumnN(int N)const{
    std::vector<T> row;
    T val;
    int QLines=this->GetQLines(), QColumns=this->GetQColumns();
    if(N>=1 && N<=QColumns){
        for(int i=1; i<=QLines; i++){
            val=this->GetVal(i, N);
            row.push_back(val);
        }
    }
    return row;
}
template<typename T> std::vector<T> TArray2D_Rect_Simple_Prototype<T>::GetContent_ExtRows()const{
    std::vector<T> row;
    T val;
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows();
    for(int i=1; i<=QExtRows; i++){
        for(int j=1; j<=QIneRows; j++){
            val=this->GetVal_EIR(i, j);
            row.push_back(val);
        }
    }
    return row;
}
template<typename T> std::vector<T> TArray2D_Rect_Simple_Prototype<T>::GetContent_Lines()const{
    std::vector<T> row;
    T val;
    int QLines=this->GetQLines(), QColumns=this->GetQColumns();
    for(int i=1; i<=QLines; i++){
        for(int j=1; j<=QColumns; j++){
            val=this->GetVal(i, j);
            row.push_back(val);
        }
    }
    return row;
}
template<typename T> std::vector<T> TArray2D_Rect_Simple_Prototype<T>::GetContent_Columns()const{
    std::vector<T> row;
    T val;
    int QLines=this->GetQLines(), QColumns=this->GetQColumns();
    for(int i=1; i<=QColumns; i++){
        for(int j=1; j<=QLines; j++){
            val=this->GetVal(i, j);
            row.push_back(val);
        }
    }
    return row;
}
//
//
template<typename T> void TArray2D_Rect_Simple_Prototype<T>::SwapVals_EIR(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2){
    T valBuf, val1, val2;
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows();
    if(  ExtRowN1>=1 && ExtRowN1<=QExtRows && IneRowN1>=1 && IneRowN1<=QIneRows
       &&ExtRowN2>=1 && ExtRowN2<=QExtRows && IneRowN2>=1 && IneRowN2<=QIneRows
      )
    {
          val1=this->GetVal_EIR(ExtRowN1, IneRowN1);
          val2=this->GetVal_EIR(ExtRowN2, IneRowN2);
          valBuf=val1;
          val1=val2;
          val2=valBuf;
          this->SetVal_EIR(val1, ExtRowN2, IneRowN2);
          this->SetVal_EIR(val2, ExtRowN1, IneRowN1);
    }
}
template<typename T> void TArray2D_Rect_Simple_Prototype<T>::SwapVals(int LineN1, int ColN1, int LineN2, int ColN2){
    int ExtRowN1, IneRowN1, ExtRowN2, IneRowN2;
    ExtRowN1=LineN1;
    IneRowN1=ColN1;
    ExtRowN2=LineN2;
    IneRowN2=ColN2;
    this->SwapVals_EIR(ExtRowN1, IneRowN1, ExtRowN2, IneRowN2);
}
template<typename T> void TArray2D_Rect_Simple_Prototype<T>::SwapExtRows(int ExtRowN1, int ExtRowN2){
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows();
    if(ExtRowN1>=1 && ExtRowN1<=QExtRows && ExtRowN2>=1 && ExtRowN2<=QExtRows){
        for(int i=1; i<=QIneRows; i++){
            this->SwapVals_EIR(ExtRowN1, i, ExtRowN2, i);
        }
    }
}
template<typename T> void TArray2D_Rect_Simple_Prototype<T>::SwapIneRows(int IneRowN1, int IneRowN2){
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows();
    if(IneRowN1>=1 && IneRowN1<=QIneRows && IneRowN2>=1 && IneRowN2<=QIneRows){
        for(int i=1; i<=QExtRows; i++){
            this->SwapVals_EIR(i, IneRowN1, i, IneRowN2);
        }
    }
}
template<typename T> void TArray2D_Rect_Simple_Prototype<T>::SwapLines(int LineN1, int LineN2){
    int ExtRowN1 = LineN1, ExtRowN2 = LineN2;
    this->SwapExtRows(ExtRowN1, ExtRowN2);
}
template<typename T> void TArray2D_Rect_Simple_Prototype<T>::SwapColumns(int ColN1, int ColN2){
    int IneRowN1 = ColN1, IneRowN2 = ColN2;
    this->SwapIneRows(IneRowN1, IneRowN2);
}
//
//
//template<typename T> void TArray2D_Rect_Simple_Prototype<T>::SetExtRow_Simple(T*row, int N){
//    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows(), curL;
//    T val;
//    if(N>=1 && N<=QExtRows){
//        if(row!=NULL){
//            for(int i=1; i<=QIneRows; i++){
//                val=row[i-1];
//                this->SetVal_EIR(val, N, i);
//            }
//        }else{
//            for(int i=1; i<=QIneRows; i++){
//                //val=row[i-1];
//                this->SetVal_EIR(val, N, i);
//            }
//        }
//    }
//}
//template<typename T> void TArray2D_Rect_Simple_Prototype<T>::SetLine_Simple(T*row, int LineN){
//    int ExtRowN=LineN;
//    this->SetExtRow_Simple(row, ExtRowN);
//}
//template<typename T> void TArray2D_Rect_Simple_Prototype<T>::SetIneRow_Simple(T*row, int N){
//    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows(), curL;
//    T val;
//    if(N>=1 && N<=QExtRows){
//        if(row!=NULL){
//            for(int i=1; i<=QExtRows; i++){
//                val=row[i-1];
//                this->SetVal_EIR(val, i, N);
//            }
//        }else{
//            for(int i=1; i<=QExtRows; i++){
//                //val=row[i-1];
//                this->SetVal_EIR(val, i, N);
//            }
//        }
//    }
//}
//template<typename T> void TArray2D_Rect_Simple_Prototype<T>::SetColumn_Simple(T*row, int ColN){
//    int IneRowN=ColN;
//    this->SetIneRow_Simple(row, IneRowN);
//}
//
//
template<typename T> void TArray2D_Rect_Simple_Prototype<T>::SetExtRow_Simple(int N, T*row, int rowL, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4){
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows(), factL=0, minL, maxL;
    T curVal, dfltVal;
    if(N<0){
        N+=(QExtRows+1);
    }
    if(QExtRows!=0 && QIneRows!=0 && rowL==0){
        rowL=QIneRows;
    }
    if(N>=1 && N<=QExtRows && QExtRows>0){
        minL =  rowL <= QIneRows ? rowL : QIneRows;
        maxL =  rowL >= QIneRows ? rowL : QIneRows;
        if(rowL==QIneRows){
            factL=QIneRows;
        }else{
            switch(IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4){
                case 0:
                    factL=0;
                break;
                case 1:
                    factL=QIneRows;
                    this->SetSize_EIR(QExtRows, factL);
                break;
                case 2:
                    factL=rowL;
                    this->SetSize_EIR(QExtRows, factL);
                break;
                case 3:
                    factL=maxL;
                    this->SetSize_EIR(QExtRows, factL);
                break;
                case 4:
                    factL=minL;
                    this->SetSize_EIR(QExtRows, factL);
               break;
            }
            //
            //this->SetSize_EIR(QExtRows, factL);
            //
            if(row!=NULL){
                for(int i=1; i<=minL; i++){
                    curVal=row[i-1];
                    this->SetVal(curVal, N, i);
                }
                for(int i=minL+1; i<=factL; i++){
                    this->SetVal(dfltVal, N, i);
                }
            }else{
                for(int i=1; i<=factL; i++){
                    this->SetVal(dfltVal, N, i);
                }
            }
        }
    }
}
template<typename T> void TArray2D_Rect_Simple_Prototype<T>::SetIneRow_Simple(int N, T*row, int rowL, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4){
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows(), factL=0, minL, maxL;
    T curVal, dfltVal;
    if(N<0){
        N+=(QIneRows+1);
    }
    if(QExtRows!=0 && QIneRows!=0 && rowL==0){
        rowL=QExtRows;
    }
    if(N>=1 && N<=QExtRows && QExtRows>0){
        minL = rowL <= QIneRows ? rowL : QIneRows;
        maxL = rowL >= QIneRows ? rowL : QIneRows;
        if(rowL==QIneRows){
            factL=QIneRows;
        }else{
            switch(IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4){
                case 0:
                    factL=0;
                break;
                case 1:
                    factL=QIneRows;
                break;
                case 2:
                    factL=rowL;
                    this->SetSize_EIR(QExtRows, factL);
                break;
                case 3:
                    factL=maxL;
                    this->SetSize_EIR(QExtRows, factL);
                break;
                case 4:
                    factL=minL;
                    this->SetSize_EIR(QExtRows, factL);
               break;
            }
            //
            //this->SetSize_EIR(QExtRows, factL);
            //
            if(row!=NULL){
                for(int i=1; i<=minL; i++){
                    curVal=row[i-1];
                    this->SetVal(curVal, i, N);
                }
                for(int i=minL+1; i<=factL; i++){
                    this->SetVal(dfltVal, i, N);
                }
            }else{
                for(int i=1; i<=factL; i++){
                    this->SetVal(dfltVal, i, N);
                }
            }
        }
    }
}

//template<typename T> virtual void SetLine_Simple(int N, T*row, int rowL, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4=1)=0;


//template<typename T> virtual void SetColumn_Simple(int N, T*row, int rowL, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4=1)=0;
//

//
//template<typename T> void TArray2D_Rect_Simple_Prototype<T>::AddExtRow_Simple(T*row){
//    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows();
//    if(QExtRows>0 && QIneRows>0){
//        this->SetSize_EIR(QExtRows+1, QIneRows);
//        this->SetExtRow_Simple(row, QExtRows+1);
//    }
//}
//template<typename T> void TArray2D_Rect_Simple_Prototype<T>::AddLine_Simple(T*row){
//    this->AddExtRow_Simple(row);
//}
//template<typename T> void TArray2D_Rect_Simple_Prototype<T>::AddIneRow_Simple(T*row){
//    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows();
//    if(QExtRows>0 && QIneRows>0){
//        this->SetSize_EIR(QExtRows, QIneRows+1);
//        this->SetIneRow_Simple(row, QIneRows+1);
//    }
//}
//template<typename T> void TArray2D_Rect_Simple_Prototype<T>::AddColumn_Simple(T*row){
//    this->AddIneRow_Simple(row);
//}
//
//
template<typename T> void TArray2D_Rect_Simple_Prototype<T>::AddExtRow_Simple(T*row, int rowL, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4){
    T curVal, dfltVal;
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows(), factL, minL, maxL;
    if(QIneRows>0 || rowL>0){
        this->SetSize(QExtRows+1, QIneRows);
        this->SetExtRow_Simple(QExtRows+1, row, rowL, IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4);
    }
}

//template<typename T> void TArray2D_Rect_Simple_Prototype<T>::AddLine_Simple(T*row, int rowL, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4){
//    T curVal, dfltVal;
//    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows(), factL, minL, maxL;
//    if(QExtRows>0 || rowL>0){
//        this->SetSize(QExtRows+1, QIneRows);
//        this->SetExtRow_Simple(QIneRows+1, row, rowL, IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4);
//    }
//}
template<typename T> void TArray2D_Rect_Simple_Prototype<T>::AddIneRow_Simple(T*row, int rowL, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4){
    T curVal, dfltVal;
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows(), factL, minL, maxL;
    if(QIneRows>0 || rowL>0){
        this->SetSize(QExtRows, QIneRows+1);
        this->SetIneRow_Simple(QIneRows+1, row, rowL, IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4);
    }
}
//template<typename T> void TArray2D_Rect_Simple_Prototype<T>::AddColumn_Simple(T*row, int rowL, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4){
//
//}
//
//
template<typename T> void TArray2D_Rect_Simple_Prototype<T>::InsExtRow_Simple(int N, T*row){
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows();
    if(N>=1 && N<=QExtRows){
        this->SetSize_EIR(QExtRows+1, QIneRows);
        for(int i=QExtRows+1; i>=N+1; i--){
            this->SwapExtRows(i-1, i);
        }
        this->SetExtRow_Simple(N, row);
    }
}
//template<typename T> void TArray2D_Rect_Simple_Prototype<T>::InsLine_Simple(int LineN, T*row){
//    int ExtRowN=LineN;
//    this->InsExtRow_Simple(row, ExtRowN);
//}
template<typename T> void TArray2D_Rect_Simple_Prototype<T>::InsIneRow_Simple(int N, T*row){
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows();
    if(N>=1 && N<=QExtRows){
        this->SetSize_EIR(QExtRows, QIneRows+1);
        for(int i=QIneRows+1; i>=N+1; i--){
            this->SwapIneRows(i-1, i);
        }
        this->SetIneRow_Simple(N, row);
    }
}
//template<typename T> void TArray2D_Rect_Simple_Prototype<T>::InsColumn_Simple(int ColN, T*row){
//    int IneRowN=ColN;
//    this->InsIneRow_Simple(row, IneRowN);
//}
//
template<typename T> void TArray2D_Rect_Simple_Prototype<T>::DelExtRow_Simple(int N){
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows();
    if(N>=1 && N<=QExtRows){
        for(int i=N+1; i<=QExtRows; i++){
            this->SwapExtRows(i-1, i);
        }
        this->SetSize_EIR(QExtRows-1, QIneRows);
    }
}
//template<typename T> void TArray2D_Rect_Simple_Prototype<T>::DelLine_Simple(int LineN){
//    int ExtRowN=LineN;
//    this->DelExtRow_Simple(ExtRowN);
//}
template<typename T> void TArray2D_Rect_Simple_Prototype<T>::DelIneRow_Simple(int N){
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows();
    if(N>=1 && N<=QIneRows){
        for(int i=N+1; i<=QIneRows; i++){
            this->SwapIneRows(i-1, i);
        }
        this->SetSize_EIR(QExtRows, QIneRows-1);
    }
}
//template<typename T> void TArray2D_Rect_Simple_Prototype<T>::DelColumn_Simple(int ColN){
//    int IneRowN=ColN;
//    this->DelIneRow_Simple(IneRowN);
//}
//
//
//template<typename T> TArray2D_Rect_Simple_Prototype<T> TArray2D_Rect_Simple_Prototype<T>::SubMatrix_EIR(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2){
//    int QExtRowsOwn=this->GetQExtRows(), QIneRowsOwn=this->GetQIneRows(), QExtRows, QIneRows;
//    int whereExtRowN, whatExtRowN, whereIneRowN, whatIneRowN;
//    TArray2D_Rect_Simple_Prototype R;
//    std::vector<T>row;
//    T val;
//    if(ExtRowN1<0){
//        ExtRowN1+=(QExtRowsOwn+1);
//    }
//    if(ExtRowN2<0){
//        ExtRowN2+=(QExtRowsOwn+1);
//    }
//    if(IneRowN1<0){
//        IneRowN1+=(QIneRowsOwn+1);
//    }
//    if(IneRowN2<0){
//        IneRowN2+=(QIneRowsOwn+1);
//    }
//    //
//    if(ExtRowN2>=ExtRowN1){
//        QExtRows=ExtRowN2-ExtRowN1;
//    }else{
//        QExtRows=ExtRowN1-ExtRowN2;
//    }
//    if(IneRowN2>=IneRowN1){
//        QIneRows=IneRowN2-IneRowN1;
//    }else{
//        QIneRows=IneRowN1-IneRowN2;
//    }
//    if((ExtRowN2<0 && ExtRowN1<0) || (IneRowN2<0 && IneRowN1<0) || (ExtRowN2>QExtRows && ExtRowN1>QExtRows) || (IneRowN2>QIneRows && IneRowN1>QIneRows)){
//        R.SetSize_EIR(QExtRows, QIneRows);
//        for(int i=1; i<=QExtRows; i++){
//            for(int j=1; j<=QIneRows; j++){
//                R.SetVal_EIR(val, i, j);//val dflt (0, 0)
//            }
//        }
//    }else if(ExtRowN1>=1 && ExtRowN1<=QExtRowsOwn && ExtRowN2>=1 && ExtRowN2<=QExtRowsOwn    &&    IneRowN1>=1 && ExtRowN1<=QIneRowsOwn && IneRowN2>=1 && IneRowN2<=QIneRowsOwn){
//        R.SetSize_EIR(QExtRows, QIneRows);
//        if(ExtRowN2>=ExtRowN1){
//            if(IneRowN2>=IneRowN1){
//                for(whereExtRowN=ExtRowN1; whereExtRowN<=ExtRowN2; whereExtRowN++){
//                    whatExtRowN=whereExtRowN-ExtRowN1+1;
//                    for(whereIneRowN=IneRowN1; whereIneRowN<=IneRowN2; whereIneRowN++){
//                        whatIneRowN=whereIneRowN-IneRowN1+1;
//                        val=this->GetVal_EIR(whereExtRowN, whereIneRowN);
//                        R.SetVal_EIR(val, whatExtRowN, whatIneRowN);
//                    }
//                }
//            }else{
//                for(whereExtRowN=ExtRowN1; whereExtRowN<=ExtRowN2; whereExtRowN++){
//                    whatExtRowN=whereExtRowN-ExtRowN1+1;
//                    for(whereIneRowN=IneRowN1; whereIneRowN>=IneRowN2; whereIneRowN--){
//                        whatIneRowN=whereIneRowN-IneRowN1+1;
//                        val=this->GetVal_EIR(whereExtRowN, whereIneRowN);
//                        R.SetVal_EIR(val, whatExtRowN, whatIneRowN);
//                    }
//                }
//            }
//        }else{
//            if(IneRowN2>=IneRowN1){
//                for(whereExtRowN=ExtRowN1; whereExtRowN>=ExtRowN2; whereExtRowN--){
//                    whatExtRowN=whereExtRowN-ExtRowN1+1;
//                    for(whereIneRowN=IneRowN1; whereIneRowN<=IneRowN2; whereIneRowN++){
//                        whatIneRowN=whereIneRowN-IneRowN1+1;
//                        val=this->GetVal_EIR(whereExtRowN, whereIneRowN);
//                        R.SetVal_EIR(val, whatExtRowN, whatIneRowN);
//                    }
//                }
//            }else{
//                for(whereExtRowN=ExtRowN1; whereExtRowN>=ExtRowN2; whereExtRowN--){
//                    whatExtRowN=whereExtRowN-ExtRowN1+1;
//                    for(whereIneRowN=IneRowN1; whereIneRowN>=IneRowN2; whereIneRowN--){
//                        whatIneRowN=whereIneRowN-IneRowN1+1;
//                        val=this->GetVal_EIR(whereExtRowN, whereIneRowN);
//                        R.SetVal_EIR(val, whatExtRowN, whatIneRowN);
//                    }
//                }
//            }
//        }
//        for(int i=1; i<=QExtRows; i++){
//            for(int j=1; j<=QIneRows; j++){
//                R.SetVal_EIR(val, i, j);//val dflt (0, 0)
//            }
//        }
//    }
//    //
//    return R;
//}
//template<typename T> TArray2D_Rect_Simple_Prototype<T> TArray2D_Rect_Simple_Prototype<T>::SubMatrix(int LineN1, int ColumnN1, int LineN2, int ColumnN2){
//    int ExtRowN1=LineN1, ExtRowN2=LineN2, IneRowN1=ColumnN1, IneRowN2=ColumnN2;
//    return this->SubMatrix_EIR(ExtRowN1, IneRowN1, ExtRowN2, IneRowN2);
//}
//
//
template<typename T> void TArray2D_Rect_Simple_Prototype<T>::StdCout_ExtRowN(int N, std::string delim, bool showBrackets, bool RepresentVertNotHor){
    T val;
    QString sn;
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows();
    if(N>=1 && N<=QExtRows){
        if(showBrackets){
            std::cout<<"[";
        }
        for(int i=1; i<=QIneRows-1; i++){
            val=this->GetVal_EIR(N, i);
            std::cout<<val;
            std::cout<<delim;
            if(RepresentVertNotHor){
                std::cout<<std::endl;
                if(showBrackets){
                     std::cout<<" ";
                }
            }
        }
        val=this->GetVal_EIR(N, QIneRows);
        std::cout<<val;
        if(showBrackets){
            std::cout<<"]";
        }
    }
}

template<typename T> void TArray2D_Rect_Simple_Prototype<T>::StdCout_IneRowN(int N, std::string delim, bool showBrackets, bool RepresentVertNotHor){
    T val;
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows();
    if(N>=1 && N<=QIneRows){
        if(showBrackets){
            std::cout<<"[";
        }
        for(int i=1; i<=QExtRows-1; i++){
            val=this->GetVal_EIR(i, N);
            std::cout<<val;
            std::cout<<delim;
            if(RepresentVertNotHor){
                std::cout<<std::endl;
                if(showBrackets){
                     std::cout<<" ";
                }
            }
        }
        val=this->GetVal_EIR(QExtRows, N);
        std::cout<<val;
        if(showBrackets){
            std::cout<<"]";
        }
    }
}
template<typename T> void TArray2D_Rect_Simple_Prototype<T>::StdCout_LineN(int LineN, std::string delim, bool showBrackets, bool RepresentVertNotHor){
    T val;
    int QLines=this->GetQLines(), QColumns=this->GetQColumns();
    if(LineN>=1 && LineN<=QLines){
        if(showBrackets){
            std::cout<<"[";
        }
        for(int i=1; i<=QColumns-1; i++){
            val=this->GetVal(LineN, i);
            std::cout<<val;
            std::cout<<delim;
            if(RepresentVertNotHor){
                std::cout<<std::endl;
                if(showBrackets){
                     std::cout<<" ";
                }
            }
        }
        val=this->GetVal(LineN, QColumns);
        std::cout<<val;
        if(showBrackets){
            std::cout<<"]";
        }
    }
}

template<typename T> void TArray2D_Rect_Simple_Prototype<T>::StdCout_ColN(int ColN, std::string delim, bool showBrackets, bool Represent2DNot1D){
    T val;
    int QLines=this->GetQLines(), QColumns=this->GetQColumns();
    if(ColN>=1 && ColN<=QColumns){
        if(showBrackets){
            std::cout<<"[";
        }
        for(int i=1; i<=QLines-1; i++){
            val=this->GetVal(i, ColN);
            std::cout<<val;
            std::cout<<delim;
            if(Represent2DNot1D){
                std::cout<<std::endl;
                if(showBrackets){
                     std::cout<<" ";
                }
            }
        }
        val=this->GetVal(QLines, ColN);
        std::cout<<val;
        if(showBrackets){
            std::cout<<"]";
        }
    }
}
template<typename T> void TArray2D_Rect_Simple_Prototype<T>::StdCout_EIR(std::string delimElem, std::string delimRow, bool showBrackets, bool Represent2DNot1D, bool HorExt){
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows();

    if(showBrackets){
        std::cout<<"[";
    }
    if(HorExt){
        for(int i=1; i<=QExtRows-1; i++){
            this->StdCout_ExtRowN(1, delimElem, showBrackets, false);
            std::cout<<delimRow;
            if(Represent2DNot1D){
                std::cout<<std::endl;
                if(showBrackets){
                     std::cout<<" ";
                }
            }
        }
        this->StdCout_ExtRowN(QExtRows, delimElem, showBrackets, false);
    }else{
        for(int i=1; i<=QIneRows-1; i++){
            this->StdCout_IneRowN(1, delimElem, showBrackets, false);
            std::cout<<delimRow;
            if(Represent2DNot1D){
                std::cout<<std::endl;
                if(showBrackets){
                     std::cout<<" ";
                }
            }
        }
        this->StdCout_IneRowN(QIneRows, delimElem, showBrackets, false);
    }
    if(showBrackets){
        std::cout<<"]";
    }
}

template<typename T> void TArray2D_Rect_Simple_Prototype<T>::StdCout(std::string delimElem, std::string delimRow, bool showBrackets, bool Represent2DNot1D){
    int QLines=this->GetQLines();
    if(showBrackets){
        std::cout<<"[";
    }
    for(int i=1; i<=QLines-1; i++){
        this->StdCout_LineN(1, delimElem, showBrackets, false);
        std::cout<<delimRow;
        if(Represent2DNot1D){
            std::cout<<std::endl;
            if(showBrackets){
                std::cout<<" ";
            }
        }
    }
    this->StdCout_LineN(QLines, delimElem, showBrackets, false);
    if(showBrackets){
        std::cout<<"]";
    }
}

//----------------------------------------------------------------------------------------------------------------

template<class T>class TArray2D_Rect_Simple_V1I_Lines : public TArray2D_Rect_Simple_Prototype<T>
{
    std::vector<T>data;
    int QLines;
public:
    TArray2D_Rect_Simple_V1I_Lines();
    TArray2D_Rect_Simple_V1I_Lines(std::vector<T>data, int QLines, int QColumns);
    TArray2D_Rect_Simple_V1I_Lines(std::vector<std::vector<T>>data);
    TArray2D_Rect_Simple_V1I_Lines(const T&val, int QLines, int QColumns);
    //TArray2D_Rect_Simple_V1I_Lines(const TArray2D_Rect_Simple_V1I_Lines<T>&obj);
    virtual ~TArray2D_Rect_Simple_V1I_Lines();
    //void Assign(TArray2D_Rect_Simple_Prototype<T>*obj);
    //TArray2D_Rect_Simple_Prototype<T>& operator = (const TArray2D_Rect_Simple_Prototype<T>&obj);
    virtual void construct();
    virtual void SetNull();
    //void SetOne(const T& val);
    virtual int GetTypeN()const;
    ////int PosNOfEIR(int ExtRowN, int IneRowN)const;
    //virtual int PosNOf(int LineN, int ColN)const;
    virtual int GetQExtRows()const;
    virtual int GetQIneRows()const;
    virtual int GetQLines()const;
    virtual int GetQColumns()const;
    virtual void SetSize_EIR(int QExtRows, int QIneRows);
    virtual void SetSize(int QLines, int QColumns);
    //void Set_EIR(std::vector<T>data, int QExtRows, int QIneRows);
    //void Set_EIR(std::vector<std::vector<T>>data);
    //void Set_EIR(const T&val, int QExtRows, int QIneRows);
    //void Set(const T&val, int QLines, int QColumns);
    //void Set_Lines(std::vector<T>data, int QLines, int QColumns);
    //void Set_Lines(std::vector<std::vector<T>>data);
    ////void Set_Lines(const T&val, int QLines, int QColumns);
    //void Set_Columns(std::vector<T>data, int QLines, int QColumns);
    //void Set_Columns(std::vector<std::vector<T>>data);
    ////void Set_Columns(const T&val, int QLines, int QColumns);
    ////void Set(const Matrix_V1S_Lines_Simple&obj);
    virtual void SetVal_EIR(const T&val, int ExtRowN, int IneRowN);
    virtual void SetVal(const T&val, int LineN, int ColumnN);
    virtual T GetVal_EIR(int ExtRowN, int IneRowN)const;
    virtual T GetVal(int LineN, int ColumnN)const;
    //std::vector<T> GetExtRowN(int N)const;
    //std::vector<T> GetLineN(int N)const;
    //std::vector<T> GetIneRowN(int N)const;
    //std::vector<T> GetColumnN(int N)const;
    //std::vector<T> GetContent_ExtRows()const;
    //std::vector<T> GetContent_Lines()const;
    //std::vector<T> GetContent_Columns()const;
    //
    //
    //void SwapVals_EIR(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
    //void SwapVals(int LineN1, int ColN1, int LineN2, int ColN2);
    //void SwapExtRows(int ExtRowN1, int ExtRowN2);
    //void SwapIneRows(int IneRowN1, int IneRowN2);
    virtual void SwapLines(int LineN1, int LineN2);
    virtual void SwapColumns(int ColN1, int ColN2);
    //
    //
    //void SetExtRow_Simple(int N, T*row, int rowL=0, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4=1);
    virtual void SetLine_Simple(int N, T*row, int rowL, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4);
    //void SetIneRow_Simple(int N, T*row, int rowL=0, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4=1);
    virtual void SetColumn_Simple(int N, T*row, int rowL, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4);
    //
    //void AddExtRow_Simple(T*row, int rowL=0, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4=1);
    virtual void AddLine_Simple(T*row, int rowL, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4);
    //void AddIneRow_Simple(T*row, int rowL=0, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4=1);
    virtual void AddColumn_Simple(T*row, int rowL, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4);
    //
    //void InsExtRow_Simple(int N, T*row=NULL);
    virtual void InsLine_Simple(int N, T*row);
    //void InsIneRow_Simple(int N, T*row=NULL);
    virtual void InsColumn_Simple(int N, T*row);
    //
    //void DelExtRow_Simple(int N);
    virtual void DelLine_Simple(int N);
    //void DelIneRow_Simple(int N);
    virtual void DelColumn_Simple(int N);
    //
    //
    //TArray2D_Rect_Simple_Prototype<T> SubMatrix_EIR(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
    //TArray2D_Rect_Simple_Prototype<T> SubMatrix(int LineN1, int ColumnN1, int LineN2, int ColumnN2);
    ////Matrix_V1S_Lines_Simple SubMatrix_EIR(int ExtRowN1, int QExtRows, int QEmptyExtRowsBefore);
    ////Matrix_V1S_Lines_Simple SubMatrix_Lines(int LineN1, int QLines, int QEmptyLinesBefore);
    ////Matrix_V1S_Lines_Simple SubMatrix_Columns(int ColN1, int QCols, int QEmptyColsBefore);
    //
    //void StdCout_ExtRowN(int N, std::string delim="; ", bool showBrackets=true, bool RepresentVertNotHor=false);
    //void StdCout_IneRowN(int N, std::string delim="; ", bool showBrackets=true, bool RepresentVertNotHor=true);
    //void StdCout_LineN(int N, std::string delim, bool showBrackets,  bool RepresentVertNotHor);
    // void StdCout_ColN(int N, std::string delim, bool showBrackets, bool Represent2DNot1D);
    //void StdCout_EIR_ExtHor(std::string delimElem=", ", std::string delimRow="; ", bool showBrackets=true, bool Represent2DNot1D=true);
    // void StdCout(std::string delimElem, std::string delimRow, bool showBrackets, bool Represent2DNot1D);
};


template<typename T> TArray2D_Rect_Simple_V1I_Lines<T>::TArray2D_Rect_Simple_V1I_Lines(){
    this->construct();
}
template<typename T>TArray2D_Rect_Simple_V1I_Lines<T>::TArray2D_Rect_Simple_V1I_Lines(std::vector<T>data, int QLines, int QColumns){
    this->construct();
    this->Set(data,  QLines, QColumns);
}
template<typename T>TArray2D_Rect_Simple_V1I_Lines<T>::TArray2D_Rect_Simple_V1I_Lines(std::vector<std::vector<T>>data){
    this->construct();
    this->Set(data);
}
template<typename T>TArray2D_Rect_Simple_V1I_Lines<T>::TArray2D_Rect_Simple_V1I_Lines(const T&val, int QLines, int QColumns){
    this->construct();
    this->Set(val,  QLines, QColumns);
}

//template<typename T>TArray2D_Rect_Simple_V1I_Lines<T>::TArray2D_Rect_Simple_V1I_Lines(const TArray2D_Rect_Simple_V1I_Lines&obj){
//
//}
template<typename T>TArray2D_Rect_Simple_V1I_Lines<T>::~TArray2D_Rect_Simple_V1I_Lines(){
    //delete this->data;
    //this->data.SetNull();
    this->SetNull();
}
//void TArray2D_Rect_Simple_V1I_Lines<T>::Assign(const TArray2D_Rect_Simple_V1I_Lines&obj){
//    T val;
//    int QExtRows=obj.GetQExtRows(), QIneRows=obj.GetQIneRows();
//    this->SetSize_EIR(QExtRows, QIneRows);
//    for(int i=1; i<=QExtRows; i++){
//        for(int j=1; j<=QIneRows; j++){
//            val=obj.GetVal_EIR(i, j);
//            this->SetVal_EIR(val, i, j);
//        }
//    }
//}
//                  void                                    Assign(TArray2D_Rect_Simple_Prototype<T>*&obj);
//template<typename T>void TArray2D_Rect_Simple_V1I_Lines<T>::Assign(TArray2D_Rect_Simple_Prototype<T>*obj){
//    T val;
//    int QExtRows=obj->GetQExtRows(), QIneRows=obj->GetQIneRows();
//    this->SetSize_EIR(QExtRows, QIneRows);
//    for(int i=1; i<=QExtRows; i++){
//        for(int j=1; j<=QIneRows; j++){
//            val=obj->GetVal_EIR(i, j);
//            this->SetVal_EIR(val, i, j);
//        }
//    }
//}
//TArray2D_Rect_Simple_V1I_Lines& TArray2D_Rect_Simple_V1I_Lines<T>::operator = (const TArray2D_Rect_Simple_V1I_Lines&obj){
//
//}
template<typename T>void TArray2D_Rect_Simple_V1I_Lines<T>::construct(){
    this->SetNull();//ob es QLines, ic ms'b assigned 0
}
template<typename T>void TArray2D_Rect_Simple_V1I_Lines<T>::SetNull(){
    this->data.clear();
    this->QLines=0;
}
//template<typename T>void TArray2D_Rect_Simple_V1I_Lines<T>::SetOne(const T& val){
//    this->SetNull();
//    this->SetSize_EIR(1, 1);
//    this->SetVal_EIR(val, 1, 1);
//}
//template<typename T>int TArray2D_Rect_Simple_V1I_Lines<T>::PosNOfEIR(int ExtRowN, int IneRowN)const{
//    int PosN=0, QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows(), L;//, QColumns=QIneRows, N, L;
//    if(ExtRowN>=1 && ExtRowN<=QExtRows && IneRowN>=1 && IneRowN<=QIneRows){
//        for(int i=1; i<=ExtRowN-1; i++){
//            L=QIneRows;
//            PosN+=L;
//        }
//        PosN+=IneRowN;
//    }
//    return PosN;
//}
//template<typename T>int TArray2D_Rect_Simple_V1I_Lines<T>::PosNOf(int LineN, int ColN)const{
//    return this->data.PosNOf(LineN, ColN);
//}
template<typename T> int TArray2D_Rect_Simple_V1I_Lines<T>::GetQExtRows()const{
    return this->QLines;
}
template<typename T> int TArray2D_Rect_Simple_V1I_Lines<T>::GetQIneRows()const{
    int QElements=this->data.size(), QExtRows=this->GetQExtRows();
    int QIneRows=QElements/QExtRows;
    return QIneRows;
}
template<typename T> int TArray2D_Rect_Simple_V1I_Lines<T>::GetQLines()const{
    return this->QLines;
}
template<typename T> int TArray2D_Rect_Simple_V1I_Lines<T>::GetQColumns()const{
    return this->GetQIneRows();
}
template<typename T> int TArray2D_Rect_Simple_V1I_Lines<T>::GetTypeN()const{
    return Array2D_Rect_Simple_V1I_Lines_TypeN;
}

template<typename T> void TArray2D_Rect_Simple_V1I_Lines<T>::SetSize_EIR(int QExtRows, int QIneRows){
    T val;//(0, 0) by default
    this->data.clear();
    for(int i=1; i<=QExtRows; i++){
        for(int j=1; j<=QIneRows; j++){
            this->data.push_back(val);
        }
    }
    this->QLines=QExtRows;
}
template<typename T> void TArray2D_Rect_Simple_V1I_Lines<T>::SetSize(int QLines, int QColumns){
    int QExtRows=QLines, QIneRows=QColumns;
    this->SetSize_EIR(QExtRows, QIneRows);
}
template<typename T> void TArray2D_Rect_Simple_V1I_Lines<T>::SetVal_EIR(const T&val, int ExtRowN, int IneRowN){
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows();
    int PosN=GetPositionNInArray2DRectRealizedAs1D(ExtRowN, IneRowN, QExtRows, QIneRows);
    this->data[PosN-1]=val;
}
template<typename T> void TArray2D_Rect_Simple_V1I_Lines<T>::SetVal(const T&val, int LineN, int ColumnN){
    int ExtRowN=LineN, IneRowN=ColumnN;
    this->SetVal_EIR(val, ExtRowN, IneRowN);
}
template<typename T> T TArray2D_Rect_Simple_V1I_Lines<T>::GetVal_EIR(int ExtRowN, int IneRowN)const{
    //T val;
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows();
    int PosN=GetPositionNInArray2DRectRealizedAs1D(ExtRowN, IneRowN, QExtRows, QIneRows);
    //val=this->data[PosN-1];
    //return val;
    return this->data[PosN-1];
}
template<typename T> T TArray2D_Rect_Simple_V1I_Lines<T>::GetVal(int LineN, int ColumnN)const{
    int ExtRowN=LineN, IneRowN=ColumnN;
    return this->GetVal_EIR(ExtRowN, IneRowN);
}
//std::vector<T> GetExtRowN(int N)const;
//std::vector<T> GetLineN(int N)const;
//std::vector<T> GetIneRowN(int N)const;
//std::vector<T> GetColumnN(int N)const;
//std::vector<T> GetContent_ExtRows()const;
//std::vector<T> GetContent_Lines()const;
//std::vector<T> GetContent_Columns()const;
//
//
//void SwapVals_EIR(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
//void SwapVals(int LineN1, int ColN1, int LineN2, int ColN2);
//void SwapExtRows(int ExtRowN1, int ExtRowN2);
//void SwapIneRows(int IneRowN1, int IneRowN2);
template<typename T> void TArray2D_Rect_Simple_V1I_Lines<T>::SwapLines(int LineN1, int LineN2){
    int ExtRowN1=LineN1, ExtRowN2=LineN2;
    this->SwapExtRows(ExtRowN1, ExtRowN2);
}
template<typename T> void TArray2D_Rect_Simple_V1I_Lines<T>::SwapColumns(int ColN1, int ColN2){
    int IneRowN1=ColN1, IneRowN2=ColN2;
    this->SwapIneRows(IneRowN1, IneRowN2);
}
//
//
//void SetExtRow_Simple(int N, T*row, int rowL=0, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4=1);
template<typename T> void TArray2D_Rect_Simple_V1I_Lines<T>::SetLine_Simple(int LineN, T*row, int rowL, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4){
    int ExtRowN=LineN;
    this->SetExtRow_Simple(ExtRowN, row, rowL, IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4);
}

//void SetIneRow_Simple(int N, T*row, int rowL=0, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4=1);
template<typename T> void TArray2D_Rect_Simple_V1I_Lines<T>::SetColumn_Simple(int ColN, T*row, int rowL, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4){
    int IneRowN=ColN;
    this->SetIneRow_Simple(IneRowN, row, rowL, IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4);
}
//
//void AddExtRow_Simple(T*row, int rowL=0, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4=1);
template<typename T> void TArray2D_Rect_Simple_V1I_Lines<T>::AddLine_Simple(T*row, int rowL, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4){
    this->AddExtRow_Simple(row, rowL, IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4);
}
//void AddIneRow_Simple(T*row, int rowL=0, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4=1);
template<typename T> void TArray2D_Rect_Simple_V1I_Lines<T>::AddColumn_Simple(T*row, int rowL, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4){
    //in base class sha:
    //void AddIneRow_Simple(T*row, int rowL=0, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4=1);
    this->AddIneRow_Simple(row, rowL, IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4);
}
//
//void InsExtRow_Simple(int N, T*row=NULL);
template<typename T> void TArray2D_Rect_Simple_V1I_Lines<T>::InsLine_Simple(int N, T*row){
    this->InsExtRow_Simple(N, row);
}

//void InsIneRow_Simple(int N, T*row=NULL);
template<typename T> void TArray2D_Rect_Simple_V1I_Lines<T>::InsColumn_Simple(int N, T*row){
    this->InsIneRow_Simple(N, row);
}
//
//void DelExtRow_Simple(int N);
template<typename T> void TArray2D_Rect_Simple_V1I_Lines<T>::DelLine_Simple(int N){
    this->DelExtRow_Simple(N);
}

//void DelIneRow_Simple(int N);
template<typename T> void TArray2D_Rect_Simple_V1I_Lines<T>::DelColumn_Simple(int N){
    this->DelIneRow_Simple(N);
}

//
//
//TArray2D_Rect_Simple_Prototype<T> SubMatrix_EIR(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
//TArray2D_Rect_Simple_Prototype<T> SubMatrix(int LineN1, int ColumnN1, int LineN2, int ColumnN2);
////Matrix_V1S_Lines_Simple SubMatrix_EIR(int ExtRowN1, int QExtRows, int QEmptyExtRowsBefore);
////Matrix_V1S_Lines_Simple SubMatrix_Lines(int LineN1, int QLines, int QEmptyLinesBefore);
////Matrix_V1S_Lines_Simple SubMatrix_Columns(int ColN1, int QCols, int QEmptyColsBefore);
//
//void StdCout_ExtRowN(int N, std::string delim="; ", bool showBrackets=true, bool RepresentVertNotHor=false);
//void StdCout_IneRowN(int N, std::string delim="; ", bool showBrackets=true, bool RepresentVertNotHor=true);
//template<typename T> void TArray2D_Rect_Simple_V1I_Lines<T>::StdCout_LineN(int N, std::string delim, bool showBrackets,  bool RepresentVertNotHor){
//
//}
//
//template<typename T> void TArray2D_Rect_Simple_V1I_Lines<T>::StdCout_ColN(int N, std::string delim, bool showBrackets, bool Represent2DNot1D){
//
//}
//
//void StdCout_EIR_ExtHor(std::string delimElem=", ", std::string delimRow="; ", bool showBrackets=true, bool Represent2DNot1D=true);
//virtual void StdCout(std::string delimElem, std::string delimRow, bool showBrackets, bool Represent2DNot1D);



template<class T>class TArray2D_Rect_Simple_Shell
        //add fns: GetTransposed, Concat: Adding, Stretching, Horisontally, Vertically
{
    TArray2D_Rect_Simple_Prototype<T>*data;
public:
    TArray2D_Rect_Simple_Shell(int TypeN=Array2D_Rect_Simple_Default_TypeN);
    TArray2D_Rect_Simple_Shell(std::vector<T>data, int QLines, int QColumns=1, int TypeN=Array2D_Rect_Simple_Default_TypeN);
    TArray2D_Rect_Simple_Shell(std::vector<std::vector<T>>data, int TypeN=Array2D_Rect_Simple_Default_TypeN);
    TArray2D_Rect_Simple_Shell(const T&val, int QLines, int QColumns=1, int TypeN=Array2D_Rect_Simple_Default_TypeN);
    TArray2D_Rect_Simple_Shell(const TArray2D_Rect_Simple_Shell<T>&obj);
    ~TArray2D_Rect_Simple_Shell();
    //void A(const TArray2D_Rect_Simple_Prototype<T>&obj);
    void Assign(TArray2D_Rect_Simple_Prototype<T>*obj);
    void Assign(const TArray2D_Rect_Simple_Shell<T>&obj);
    TArray2D_Rect_Simple_Shell<T>& operator = (const TArray2D_Rect_Simple_Shell<T>&obj);
    int GetTypeN()const;//new!
    void SetTypeN(int TypeN);//new!
    void construct(int TypeN);//new!
    //virtual void construct()=0; et ei atal...
    void SetNull();
    void SetOne(const T& val);
    int PosNOf(int LineN, int ColN)const;
    int GetQExtRows()const;
    int GetQIneRows()const;
    int GetQLines()const;
    int GetQColumns()const;
    void SetSize_EIR(int QExtRows, int QIneRows);
    void SetSize(int QLines, int QColumns);
    //
    void Set_EIR(std::vector<T>data, int QExtRows, int QIneRows, int TypeN=0);
    void Set_EIR(std::vector<std::vector<T>>data, int TypeN=0);
    void Set_EIR(const T&val, int QExtRows, int QIneRows, int TypeN=0);
    void Set(const T&val, int QLines, int QColumns, int TypeN=0);
    void Set_Lines(std::vector<T>data, int QLines, int QColumns, int TypeN=0);
    void Set_Lines(std::vector<std::vector<T>>data, int TypeN=0);
    //void Set_Lines(const T&val, int QLines, int QColumns);
    void Set_Columns(std::vector<T>data, int QLines, int QColumns, int TypeN=0);
    void Set_Columns(std::vector<std::vector<T>>data, int TypeN=0);
    //void Set_Columns(const T&val, int QLines, int QColumns);
    //void Set(const Matrix_V1S_Lines_Simple&obj);
    //
    void SetVal_EIR(const T&val, int ExtRowN, int IneRowN);
    void SetVal(const T&val, int LineN, int ColumnN);
    //ComplexNum& GetVal_EIR(int ExtRowN, int IneRowN)const;
    T GetVal_EIR(int ExtRowN, int IneRowN)const;
    //ComplexNum& GetVal(int LineN, int ColumnN)const;
    T GetVal(int LineN, int ColumnN)const;
    std::vector<T> GetExtRowN(int N)const;
    std::vector<T> GetLineN(int N)const;
    std::vector<T> GetIneRowN(int N)const;
    std::vector<T> GetColumnN(int N)const;
    std::vector<T> GetContent_ExtRows()const;
    std::vector<T> GetContent_Lines()const;
    std::vector<T> GetContent_Columns()const;
    //
    //
    void SwapVals_EIR(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
    void SwapVals(int LineN1, int ColN1, int LineN2, int ColN2);
    void SwapExtRows(int ExtRowN1, int ExtRowN2);
    void SwapIneRows(int IneRowN1, int IneRowN2);
    void SwapLines(int LineN1, int LineN2);
    void SwapColumns(int ColN1, int ColN2);
    //
    //
    void SetExtRow_Simple(int N, T*row, int rowL=0, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4=1);
    void SetLine_Simple(int N, T*row, int rowL=0, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4=1);
    void SetIneRow_Simple(int N, T*row, int rowL=0, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4=1);
    void SetColumn_Simple(int N, T*row, int rowL=0, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4=1);
    //
    void AddExtRow_Simple(T*row, int rowL=0, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4=1);
    void AddLine_Simple(T*row, int rowL=0, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4=1);
    void AddIneRow_Simple(T*row, int rowL=0, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4=1);
    void AddColumn_Simple(T*row, int rowL=0, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4=1);
    //
    void InsExtRow_Simple(int N, T*row=NULL);
    void InsLine_Simple(int N, T*row=NULL);
    void InsIneRow_Simple(int N, T*row=NULL);
    void InsColumn_Simple(int N, T*row=NULL);
    //
    void DelExtRow_Simple(int N);
    void DelLine_Simple(int N);
    void DelIneRow_Simple(int N);
    void DelColumn_Simple(int N);
    //
    //
    //TArray2D_Rect_Simple_Prototype<T> SubMatrix_EIR(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
    //TArray2D_Rect_Simple_Prototype<T> SubMatrix(int LineN1, int ColumnN1, int LineN2, int ColumnN2);
    ////Matrix_V1S_Lines_Simple SubMatrix_EIR(int ExtRowN1, int QExtRows, int QEmptyExtRowsBefore);
    ////Matrix_V1S_Lines_Simple SubMatrix_Lines(int LineN1, int QLines, int QEmptyLinesBefore);
    ////Matrix_V1S_Lines_Simple SubMatrix_Columns(int ColN1, int QCols, int QEmptyColsBefore);
    //
    //
    TArray2D_Rect_Simple_Shell<T> GetExtRowN_AsArray2DRect(int N)const;
    TArray2D_Rect_Simple_Shell<T> GetLineN_AsArray2DRect(int N)const;
    TArray2D_Rect_Simple_Shell<T> GetIneRowN_AsArray2DRect(int N)const;
    TArray2D_Rect_Simple_Shell<T> GetColumnN_AsArray2DRect(int N)const;
    //
    //
    TArray2D_Rect_Simple_Shell<T> SubMatrix_EIR(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
    TArray2D_Rect_Simple_Shell<T> SubMatrix(int LineN1, int ColumnN1, int LineN2, int ColumnN2);
    ////Matrix_V1S_Lines_Simple SubMatrix_EIR(int ExtRowN1, int QExtRows, int QEmptyExtRowsBefore);
    ////Matrix_V1S_Lines_Simple SubMatrix_Lines(int LineN1, int QLines, int QEmptyLinesBefore);
    ////Matrix_V1S_Lines_Simple SubMatrix_Columns(int ColN1, int QCols, int QEmptyColsBefore);
    //
    void StdCout_ExtRowN(int N, std::string delim="; ", bool showBrackets=true, bool RepresentVertNotHor=false);
    void StdCout_IneRowN(int N, std::string delim="; ", bool showBrackets=true, bool RepresentVertNotHor=true);
    void StdCout_LineN(int N, std::string delim="; ", bool showBrackets=true,  bool RepresentVertNotHor=false);
    void StdCout_ColN(int N, std::string delim="; ", bool showBrackets=true, bool Represent2DNot1D=true);
    void StdCout_EIR(std::string delimElem=", ", std::string delimRow="; ", bool showBrackets=true, bool Represent2DNot1D=true, bool HorExt=true);
    void StdCout(std::string delimElem=", ", std::string delimRow="; ", bool showBrackets=true, bool Represent2DNot1D=true);
};

//template<typename T> TArray2D_Rect_Simple_Prototype<T>::TArray2D_Rect_Simple_Prototype(){
//
//}

//template<class T>class TArray2D_Rect_Simple_Shell
//{
//    TArray2D_Rect_Simple_Prototype*data;
//public:
template<typename T> TArray2D_Rect_Simple_Shell<T>::TArray2D_Rect_Simple_Shell(int TypeN){
    this->construct(TypeN);
}
template<typename T> TArray2D_Rect_Simple_Shell<T>::TArray2D_Rect_Simple_Shell(std::vector<T>data, int QLines, int QColumns, int TypeN){
    this->construct(TypeN);
    this->Set(data, QLines, QColumns, TypeN);
}
template<typename T> TArray2D_Rect_Simple_Shell<T>::TArray2D_Rect_Simple_Shell(std::vector<std::vector<T>>data, int TypeN){
    this->construct(TypeN);
    this->Set(data, TypeN);
}
template<typename T> TArray2D_Rect_Simple_Shell<T>::~TArray2D_Rect_Simple_Shell(){
    delete this->data;
}
template<typename T> void TArray2D_Rect_Simple_Shell<T>::Assign(TArray2D_Rect_Simple_Prototype<T>*obj){
    //this->construct(obj->GetTypeN());
    this->data->Assign(obj);
}
template<typename T> void TArray2D_Rect_Simple_Shell<T>::Assign(const TArray2D_Rect_Simple_Shell<T>&obj){
    this->construct(obj.GetTypeN());
    this->Assign(obj);
}
template<typename T> TArray2D_Rect_Simple_Shell<T>& TArray2D_Rect_Simple_Shell<T>::operator = (const TArray2D_Rect_Simple_Shell<T>&obj){
    this->Assign(obj);
    return *this;
}
template<typename T> int TArray2D_Rect_Simple_Shell<T>::GetTypeN()const{//new!
    return this->data->GetTypeN();
}
template<typename T> void TArray2D_Rect_Simple_Shell<T>::SetTypeN(int TypeN){//new!
    std::vector<T>data=this->GetContent_ExtRows();
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows();
    int TypeNThis=this->GetTypeN();
    if(TypeNThis!=TypeN){
        this->construct(TypeN);
    }
    this->data->Set_EIR(data, QExtRows, QIneRows);
}
template<typename T> void TArray2D_Rect_Simple_Shell<T>::construct(int TypeN){//new!
    switch(TypeN){
        case 0:
            //NOp;
        break;
        case Array2D_Rect_Simple_V1I_Lines_TypeN:
                         //TArray2D_Rect_Simple_V1I_Lines();
            this->data=new TArray2D_Rect_Simple_V1I_Lines<T>();
        break;
    }
}
//virtual void construct()=0; et ei atal...
template<typename T> void TArray2D_Rect_Simple_Shell<T>::SetNull(){
    this->data->SetNull();
    delete this->data;
    this->data=NULL;
}

template<typename T> void TArray2D_Rect_Simple_Shell<T>::SetOne(const T& val){
    this->SetSize(1, 1);
    this->SetVal(val, 1, 1);
}

template<typename T> int TArray2D_Rect_Simple_Shell<T>::PosNOf(int LineN, int ColN)const{
    return this->data->PosNOf(LineN, ColN);
}
template<typename T> int TArray2D_Rect_Simple_Shell<T>::GetQExtRows()const{
    return this->data->GetQExtRows();
}
template<typename T> int TArray2D_Rect_Simple_Shell<T>::GetQIneRows()const{
    return this->data->GetQIneRows();
}
template<typename T> int TArray2D_Rect_Simple_Shell<T>::GetQLines()const{
    return this->data->GetQLines();
}
template<typename T> int TArray2D_Rect_Simple_Shell<T>::GetQColumns()const{
    return this->data->GetQColumns();
}
template<typename T> void TArray2D_Rect_Simple_Shell<T>::SetSize_EIR(int QExtRows, int QIneRows){
    this->data->SetSize_EIR(QExtRows, QIneRows);
}
template<typename T> void TArray2D_Rect_Simple_Shell<T>::SetSize(int QLines, int QColumns){
    this->data->SetSize(QLines, QColumns);
}
//
template<typename T> void TArray2D_Rect_Simple_Shell<T>::Set_EIR(std::vector<T>data, int QExtRows, int QIneRows, int TypeN){
    this->SetTypeN(TypeN);
    this->data->Set_EIR(data, QExtRows, QIneRows);
}
template<typename T> void TArray2D_Rect_Simple_Shell<T>::Set_EIR(std::vector<std::vector<T>>data, int TypeN){
    this->SetTypeN(TypeN);
    this->data->Set_EIR(data);
}
template<typename T> void TArray2D_Rect_Simple_Shell<T>::Set_EIR(const T&val, int QExtRows, int QIneRows, int TypeN){
    this->SetTypeN(TypeN);
    this->data->Set_EIR(val, QExtRows, QIneRows);
}
template<typename T> void TArray2D_Rect_Simple_Shell<T>::Set(const T&val, int QLines, int QColumns, int TypeN){
    this->SetTypeN(TypeN);
    this->data->Set(val, QLines, QColumns);
}
template<typename T> void TArray2D_Rect_Simple_Shell<T>::Set_Lines(std::vector<T>data, int QLines, int QColumns, int TypeN){
    this->SetTypeN(TypeN);
    this->data->Set_Lines(data, QLines, QColumns);
}
template<typename T> void TArray2D_Rect_Simple_Shell<T>::Set_Lines(std::vector<std::vector<T>>data, int TypeN){
    this->SetTypeN(TypeN);
    this->data->Set_Lines(data);
}
//void Set_Lines(const T&val, int QLines, int QColumns, int TypeN);
template<typename T> void TArray2D_Rect_Simple_Shell<T>::Set_Columns(std::vector<T>data, int QLines, int QColumns, int TypeN){
    this->SetTypeN(TypeN);
    this->data->Set_Columns(data, QLines, QColumns);
}
template<typename T> void TArray2D_Rect_Simple_Shell<T>::Set_Columns(std::vector<std::vector<T>>data, int TypeN){
    this->SetTypeN(TypeN);
    this->data->Set_Columns(data);
}
//void Set_Columns(const T&val, int QLines, int QColumns, int TypeN);
//void Set(const Matrix_V1S_Lines_Simple&obj, int TypeN);
//
template<typename T> void TArray2D_Rect_Simple_Shell<T>::SetVal_EIR(const T&val, int ExtRowN, int IneRowN){
    //this->SetTypeN(TypeN);
    this->data->Set_EIR(val, ExtRowN, IneRowN);
}
template<typename T> void TArray2D_Rect_Simple_Shell<T>::SetVal(const T&val, int LineN, int ColumnN){
    //this->SetTypeN(TypeN);
    this->data->SetVal(val, LineN, ColumnN);
}
//ComplexNum& GetVal_EIR(int ExtRowN, int IneRowN)const;
template<typename T> T TArray2D_Rect_Simple_Shell<T>::GetVal_EIR(int ExtRowN, int IneRowN)const{
    //return this->data->GetVal_EIR(ExtRowN, IneRowN);
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows();
    int PosN=GetPositionNInArray2DRectRealizedAs1D(ExtRowN, IneRowN, QExtRows, QIneRows);
    T val=this->data[PosN-1];
    return val;
}
//ComplexNum& GetVal(int LineN, int ColumnN)const;
template<typename T> T TArray2D_Rect_Simple_Shell<T>::GetVal(int LineN, int ColumnN)const{
    return this->data->GetVal(LineN, ColumnN);
}
template<typename T> std::vector<T> TArray2D_Rect_Simple_Shell<T>::GetExtRowN(int N)const{
    return this->data->GetExtRowN(N);
}
template<typename T> std::vector<T> TArray2D_Rect_Simple_Shell<T>::GetLineN(int N)const{
    return this->data->GetLineN(N);
}
template<typename T> std::vector<T> TArray2D_Rect_Simple_Shell<T>::GetIneRowN(int N)const{
    return this->data->GetIneRowN(N);
}
template<typename T> std::vector<T> TArray2D_Rect_Simple_Shell<T>::GetColumnN(int N)const{
    return this->data->GetColumnN(N);
}
template<typename T> std::vector<T> TArray2D_Rect_Simple_Shell<T>::GetContent_ExtRows()const{
    return this->data->GetContent_ExtRows();
}
template<typename T> std::vector<T> TArray2D_Rect_Simple_Shell<T>::GetContent_Lines()const{
    return this->data->GetContent_Lines();
}
template<typename T> std::vector<T> TArray2D_Rect_Simple_Shell<T>::GetContent_Columns()const{
    return this->data->GetContent_Columns();
}
//
//
template<typename T> void TArray2D_Rect_Simple_Shell<T>::SwapVals_EIR(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2){
    this->data->SwapVals_EIR(ExtRowN1, IneRowN1, ExtRowN2, IneRowN2);
}
template<typename T> void TArray2D_Rect_Simple_Shell<T>::SwapVals(int LineN1, int ColN1, int LineN2, int ColN2){
    this->data->SwapVals(LineN1, ColN1, LineN2, ColN2);
}
template<typename T> void TArray2D_Rect_Simple_Shell<T>::SwapExtRows(int ExtRowN1, int ExtRowN2){
    this->data->SwapExtRows(ExtRowN1, ExtRowN2);
}
template<typename T> void TArray2D_Rect_Simple_Shell<T>::SwapIneRows(int IneRowN1, int IneRowN2){
    this->data->SwapIneRows(IneRowN1, IneRowN2);
}
template<typename T> void TArray2D_Rect_Simple_Shell<T>::SwapLines(int LineN1, int LineN2){
    this->data->SwapLines(LineN1, LineN2);
}
template<typename T> void TArray2D_Rect_Simple_Shell<T>::SwapColumns(int ColN1, int ColN2){
    this->data->SwapColumns(ColN1, ColN2);
}
//
//
template<typename T> void TArray2D_Rect_Simple_Shell<T>::SetExtRow_Simple(int N, T*row, int rowL, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4){
    this->data->SetExtRow_Simple(N, row, rowL, IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4);
}
template<typename T> void TArray2D_Rect_Simple_Shell<T>::SetLine_Simple(int N, T*row, int rowL, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4){
    this->data->SetLine_Simple(N, row, rowL, IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4);
}
template<typename T> void TArray2D_Rect_Simple_Shell<T>::SetIneRow_Simple(int N, T*row, int rowL, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4){
    this->data->SetIneRow_Simple(N, row, rowL, IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4);
}
template<typename T> void TArray2D_Rect_Simple_Shell<T>::SetColumn_Simple(int N, T*row, int rowL, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4){
    this->data->SetColumn_Simple(N, row, rowL, IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4);
}
//
template<typename T> void TArray2D_Rect_Simple_Shell<T>::AddExtRow_Simple(T*row, int rowL, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4){
    this->data->AddExtRow_Simple(row, rowL, IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4);
}
template<typename T> void TArray2D_Rect_Simple_Shell<T>::AddLine_Simple(T*row, int rowL, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4){
    this->data->AddLine_Simple(row, rowL, IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4);
}
template<typename T> void TArray2D_Rect_Simple_Shell<T>::AddIneRow_Simple(T*row, int rowL, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4){
    this->data->AddIneRow_Simple(row, rowL, IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4);
}
template<typename T> void TArray2D_Rect_Simple_Shell<T>::AddColumn_Simple(T*row, int rowL, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4){
    this->data->AddColumn_Simple(row, rowL, IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4);
}
//
template<typename T> void TArray2D_Rect_Simple_Shell<T>::InsExtRow_Simple(int N, T*row){
    this->data->InsExtRow_Simple(N, row);
}
template<typename T> void TArray2D_Rect_Simple_Shell<T>::InsLine_Simple(int N, T*row){
    this->data->InsLine_Simple(N, row);
}
template<typename T> void TArray2D_Rect_Simple_Shell<T>::InsIneRow_Simple(int N, T*row){
    this->data->InsIneRow_Simple(N, row);
}
template<typename T> void TArray2D_Rect_Simple_Shell<T>::InsColumn_Simple(int N, T*row){
    this->data->InsColumn_Simple(N, row);
}
//
template<typename T> void TArray2D_Rect_Simple_Shell<T>::DelExtRow_Simple(int N){
    this->data->DelExtRow_Simple(N);
}
template<typename T> void TArray2D_Rect_Simple_Shell<T>::DelLine_Simple(int N){
    this->data->DelLine_Simple(N);
}
template<typename T> void TArray2D_Rect_Simple_Shell<T>::DelIneRow_Simple(int N){
    this->data->DelIneRow_Simple(N);
}
template<typename T> void TArray2D_Rect_Simple_Shell<T>::DelColumn_Simple(int N){
    this->data->DelColumn_Simple(N);
}
//
//
//TArray2D_Rect_Simple_Prototype<T> SubMatrix_EIR(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
//TArray2D_Rect_Simple_Prototype<T> SubMatrix(int LineN1, int ColumnN1, int LineN2, int ColumnN2);
////Matrix_V1S_Lines_Simple SubMatrix_EIR(int ExtRowN1, int QExtRows, int QEmptyExtRowsBefore);
////Matrix_V1S_Lines_Simple SubMatrix_Lines(int LineN1, int QLines, int QEmptyLinesBefore);
////Matrix_V1S_Lines_Simple SubMatrix_Columns(int ColN1, int QCols, int QEmptyColsBefore);
//
//
template<typename T> TArray2D_Rect_Simple_Shell<T> TArray2D_Rect_Simple_Shell<T>::GetExtRowN_AsArray2DRect(int N)const{
    std::vector<T>row=this->GetExtRowN(N);
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows(), QLines=this->GetQLines(), QColumns=this->GetQColumns();
    TArray2D_Rect_Simple_Shell Arr;
    Arr.AddExtRow_Simple(row.data(), row.size(), 2);
    return Arr;
}
template<typename T> TArray2D_Rect_Simple_Shell<T> TArray2D_Rect_Simple_Shell<T>::GetLineN_AsArray2DRect(int N)const{
    std::vector<T>row=this->GetLineN(N);
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows(), QLines=this->GetQLines(), QColumns=this->GetQColumns();
    TArray2D_Rect_Simple_Shell Arr;
    Arr.AddLine_Simple(row.data(), row.size(), 2);
    return Arr;
}
template<typename T> TArray2D_Rect_Simple_Shell<T> TArray2D_Rect_Simple_Shell<T>::GetIneRowN_AsArray2DRect(int N)const{
    std::vector<T>row=this->GetIneRowN(N);
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows(), QLines=this->GetQLines(), QColumns=this->GetQColumns();
    TArray2D_Rect_Simple_Shell Arr;
    Arr.AddIneRow_Simple(row.data(), row.size(), 2);
    return Arr;
}
template<typename T> TArray2D_Rect_Simple_Shell<T> TArray2D_Rect_Simple_Shell<T>::GetColumnN_AsArray2DRect(int N)const{
    std::vector<T>row=this->GetColumnN(N);
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows(), QLines=this->GetQLines(), QColumns=this->GetQColumns();
    TArray2D_Rect_Simple_Shell Arr;
    Arr.AddColumn_Simple(row.data(), row.size(), 2);
    return Arr;
}
//
//
template<typename T> TArray2D_Rect_Simple_Shell<T> TArray2D_Rect_Simple_Shell<T>::SubMatrix_EIR(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2){

}

template<typename T> TArray2D_Rect_Simple_Shell<T> TArray2D_Rect_Simple_Shell<T>::SubMatrix(int LineN1, int ColumnN1, int LineN2, int ColumnN2){

}

////Matrix_V1S_Lines_Simple SubMatrix_EIR(int ExtRowN1, int QExtRows, int QEmptyExtRowsBefore);
////Matrix_V1S_Lines_Simple SubMatrix_Lines(int LineN1, int QLines, int QEmptyLinesBefore);
////Matrix_V1S_Lines_Simple SubMatrix_Columns(int ColN1, int QCols, int QEmptyColsBefore);
//
template<typename T> void TArray2D_Rect_Simple_Shell<T>::StdCout_ExtRowN(int N, std::string delim, bool showBrackets, bool RepresentVertNotHor){
    this->StdCout_ExtRowN(N, delim, showBrackets, RepresentVertNotHor);
}
template<typename T> void TArray2D_Rect_Simple_Shell<T>::StdCout_IneRowN(int N, std::string delim, bool showBrackets, bool RepresentVertNotHor){
    this->StdCout_IneRowN(N, delim, showBrackets, RepresentVertNotHor);
}
template<typename T> void TArray2D_Rect_Simple_Shell<T>::StdCout_LineN(int N, std::string delim, bool showBrackets,  bool RepresentVertNotHor){
    this->StdCout_LineN(N, delim, showBrackets, RepresentVertNotHor);
}
template<typename T> void TArray2D_Rect_Simple_Shell<T>::StdCout_ColN(int N, std::string delim, bool showBrackets, bool Represent2DNot1D){
    this->StdCout_ColN(N, delim, showBrackets, Represent2DNot1D);
}
template<typename T> void TArray2D_Rect_Simple_Shell<T>::StdCout_EIR(std::string delimElem, std::string delimRow, bool showBrackets, bool Represent2DNot1D, bool HorExt){
    this->StdCout_EIR(delimElem, delimRow, showBrackets, Represent2DNot1D, HorExt);
}
template<typename T> void TArray2D_Rect_Simple_Shell<T>::StdCout(std::string delimElem, std::string delimRow, bool showBrackets, bool Represent2DNot1D){
    this->StdCout(delimElem, delimRow, showBrackets, Represent2DNot1D);
}
//};

//--

// Array2DRect_Test_Int_Simple

class Array2DRect_Test_Int_Simple{
     TArray2D_Rect_Simple_Shell<int>data;
public:
     Array2DRect_Test_Int_Simple();
     Array2DRect_Test_Int_Simple(std::vector<int>data, int QLines, int QColumns=1);
     Array2DRect_Test_Int_Simple(std::vector<std::vector<int>>data);
     Array2DRect_Test_Int_Simple(int val, int QLines, int QColumns=1);
     //Array2D_Test_Int_Simple(const TArray2D_Rect_Simple_Shell<int>&obj);
     Array2DRect_Test_Int_Simple(const Array2DRect_Test_Int_Simple&obj);
     ~Array2DRect_Test_Int_Simple();
     //void A(const TArray2D_Rect_Simple_Prototype<T>&obj);
     //void Assign(TArray2D_Rect_Simple_Prototype<T>*obj);
     void Assign(const Array2DRect_Test_Int_Simple&obj);
     Array2DRect_Test_Int_Simple& operator = (const Array2DRect_Test_Int_Simple&obj);
     int GetTypeN();//new!
     void SetTypeN(int TypeN);//new!
     void construct();//new!
     //virtual void construct()=0; et ei atal...
     void SetNull();
     void SetOne(int val=0);
     int PosNOf(int LineN, int ColN)const;
     int GetQExtRows()const;
     int GetQIneRows()const;
     int GetQLines()const;
     int GetQColumns()const;
     void SetSize_EIR(int QExtRows, int QIneRows);
     void SetSize(int QLines, int QColumns);
     //
     void Set_EIR(std::vector<int>data, int QExtRows, int QIneRows);
     void Set_EIR(std::vector<std::vector<int>>data);
     void Set_EIR(int QExtRows, int QIneRows, int val=0);
     void Set(int QLines, int QColumns, int val=0);
     void Set_Lines(std::vector<int>data, int QLines, int QColumns);
     void Set_Lines(std::vector<std::vector<int>>data);
     //void Set_Lines(const T&val, int QLines, int QColumns);
     void Set_Columns(std::vector<int>data, int QLines, int QColumns);
     void Set_Columns(std::vector<std::vector<int>>data);
     //void Set_Columns(const T&val, int QLines, int QColumns);
     //void Set(const Matrix_V1S_Lines_Simple&obj);
     //
     void SetVal_EIR(int ExtRowN, int IneRowN, int val=0);
     void SetVal(int LineN, int ColumnN, int val=0);
     //ComplexNum& GetVal_EIR(int ExtRowN, int IneRowN)const;
     int GetVal_EIR(int ExtRowN, int IneRowN)const;
     //ComplexNum& GetVal(int LineN, int ColumnN)const;
     int GetVal(int LineN, int ColumnN)const;
     std::vector<int> GetExtRowN(int N)const;
     std::vector<int> GetLineN(int N)const;
     std::vector<int> GetIneRowN(int N)const;
     std::vector<int> GetColumnN(int N)const;
     std::vector<int> GetContent_ExtRows()const;
     std::vector<int> GetContent_Lines()const;
     std::vector<int> GetContent_Columns()const;
     //
     //
     void SwapVals_EIR(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
     void SwapVals(int LineN1, int ColN1, int LineN2, int ColN2);
     void SwapExtRows(int ExtRowN1, int ExtRowN2);
     void SwapIneRows(int IneRowN1, int IneRowN2);
     void SwapLines(int LineN1, int LineN2);
     void SwapColumns(int ColN1, int ColN2);
     //
     //
     void SetExtRow_Simple(int N, int*row, int rowL=0, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4=1);
     void SetLine_Simple(int N, int*row, int rowL=0, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4=1);
     void SetIneRow_Simple(int N, int*row, int rowL=0, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4=1);
     void SetColumn_Simple(int N, int*row, int rowL=0, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4=1);
     //
     void AddExtRow_Simple(int*row, int rowL=0, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4=1);
     void AddLine_Simple(int*row, int rowL=0, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4=1);
     void AddIneRow_Simple(int*row, int rowL=0, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4=1);
     void AddColumn_Simple(int*row, int rowL=0, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4=1);
     //
     void InsExtRow_Simple(int N, int*row=NULL);
     void InsLine_Simple(int N, int*row=NULL);
     void InsIneRow_Simple(int N, int*row=NULL);
     void InsColumn_Simple(int N, int*row=NULL);
     //
     void DelExtRow_Simple(int N);
     void DelLine_Simple(int N);
     void DelIneRow_Simple(int N);
     void DelColumn_Simple(int N);
     //
     //
     //TArray2D_Rect_Simple_Prototype<T> SubMatrix_EIR(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
     //TArray2D_Rect_Simple_Prototype<T> SubMatrix(int LineN1, int ColumnN1, int LineN2, int ColumnN2);
     ////Matrix_V1S_Lines_Simple SubMatrix_EIR(int ExtRowN1, int QExtRows, int QEmptyExtRowsBefore);
     ////Matrix_V1S_Lines_Simple SubMatrix_Lines(int LineN1, int QLines, int QEmptyLinesBefore);
     ////Matrix_V1S_Lines_Simple SubMatrix_Columns(int ColN1, int QCols, int QEmptyColsBefore);
     //
     //
     Array2DRect_Test_Int_Simple GetExtRowN_AsArray2DRect(int N)const;
     Array2DRect_Test_Int_Simple GetLineN_AsArray2DRect(int N)const;
     Array2DRect_Test_Int_Simple GetIneRowN_AsArray2DRect(int N)const;
     Array2DRect_Test_Int_Simple GetColumnN_AsArray2DRect(int N)const;
     //
     //
     Array2DRect_Test_Int_Simple SubMatrix_EIR(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
     Array2DRect_Test_Int_Simple SubMatrix(int LineN1, int ColumnN1, int LineN2, int ColumnN2);
     ////Matrix_V1S_Lines_Simple SubMatrix_EIR(int ExtRowN1, int QExtRows, int QEmptyExtRowsBefore);
     ////Matrix_V1S_Lines_Simple SubMatrix_Lines(int LineN1, int QLines, int QEmptyLinesBefore);
     ////Matrix_V1S_Lines_Simple SubMatrix_Columns(int ColN1, int QCols, int QEmptyColsBefore);
     //
     void StdCout_ExtRowN(int N, std::string delim="; ", bool showBrackets=true, bool RepresentVertNotHor=false);
     void StdCout_IneRowN(int N, std::string delim="; ", bool showBrackets=true, bool RepresentVertNotHor=true);
     void StdCout_LineN(int N, std::string delim="; ", bool showBrackets=true,  bool RepresentVertNotHor=false);
     void StdCout_ColN(int N, std::string delim="; ", bool showBrackets=true, bool Represent2DNot1D=true);
     void StdCout_EIR(std::string delimElem=", ", std::string delimRow="; ", bool showBrackets=true, bool Represent2DNot1D=true, bool HorExt=true);
     void StdCout(std::string delimElem=", ", std::string delimRow="; ", bool showBrackets=true, bool Represent2DNot1D=true);
};

//================================================================================================================

//Matrix_Prototype_Simple
//tam nur double; Get/Set Re/Im, may avoid Complex

//Matrix_V1L_v1_Lines_Simple

//Matrix_Shell_Simple


class Matrix_V1S_Lines_Simple
{
    std::vector<ComplexNum>data;
    int QLines;
public:
    Matrix_V1S_Lines_Simple();
    Matrix_V1S_Lines_Simple(std::vector<ComplexNum>data, int QLines, int QColumns);
    Matrix_V1S_Lines_Simple(std::vector<std::vector<ComplexNum>>data);
    Matrix_V1S_Lines_Simple(const ComplexNum&val, int QLines, int QColumns);
    Matrix_V1S_Lines_Simple(std::vector<double>data, int QLines, int QColumns);
    Matrix_V1S_Lines_Simple(std::vector<std::vector<double>>data);
    Matrix_V1S_Lines_Simple(double val, int QLines, int QColumns);
    Matrix_V1S_Lines_Simple(const Matrix_V1S_Lines_Simple&obj);
    ~Matrix_V1S_Lines_Simple();
    void Assign(const Matrix_V1S_Lines_Simple&obj);
    Matrix_V1S_Lines_Simple& operator = (const Matrix_V1S_Lines_Simple&obj);
    void construct();
    void SetNull();
    void SetOne(double Re=0, double Im=0);
    int PosNOfEIR(int ExtRowN, int IneRowN)const;
    int PosNOf(int LineN, int ColN)const;
    int GetQExtRows()const;
    int GetQIneRows()const;
    int GetQLines()const;
    int GetQColumns()const;
    void SetSize_EIR(int QExtRows, int QIneRows);
    void SetSize(int QLines, int QColumns);
    void Set_EIR(std::vector<ComplexNum>data, int QExtRows, int QIneRows);
    void Set_EIR(std::vector<std::vector<ComplexNum>>data);
    void Set_EIR(const ComplexNum&val, int QExtRows, int QIneRows);
    void Set_EIR(std::vector<double>data, int QExtRows, int QIneRows);
    void Set_EIR(std::vector<std::vector<double>>data);
    void Set_EIR(double val, int QExtRows, int QIneRows);
    void Set_Lines(std::vector<ComplexNum>data, int QLines, int QColumns);
    void Set_Lines(std::vector<std::vector<ComplexNum>>data);
    void Set_Lines(const ComplexNum&val, int QLines, int QColumns);
    void Set_Lines(std::vector<double>data, int QLines, int QColumns);
    void Set_Lines(std::vector<std::vector<double>>data);
    void Set_Lines(double val, int QLines, int QColumns);
    void Set_Columns(std::vector<ComplexNum>data, int QLines, int QColumns);
    void Set_Columns(std::vector<std::vector<ComplexNum>>data);
    void Set_Columns(const ComplexNum&val, int QLines, int QColumns);
    void Set_Columns(std::vector<double>data, int QLines, int QColumns);
    void Set_Columns(std::vector<std::vector<double>>data);
    void Set_Columns(double val, int QLines, int QColumns);
    //void Set(const Matrix_V1S_Lines_Simple&obj);
    void SetVal_EIR(const ComplexNum&val, int ExtRowN, int IneRowN);
    void SetVal(const ComplexNum&val, int LineN, int ColumnN);
    //ComplexNum& GetVal_EIR(int ExtRowN, int IneRowN)const;
    ComplexNum GetVal_EIR(int ExtRowN, int IneRowN)const;
    //ComplexNum& GetVal(int LineN, int ColumnN)const;
    ComplexNum GetVal(int LineN, int ColumnN)const;
    double GetVal_Re_EIR(int ExtRowN, int IneRowN)const;
    double GetVal_Re(int LineN, int ColumnN)const;
    double GetVal_Im_EIR(int ExtRowN, int IneRowN)const;
    double GetVal_Im(int LineN, int ColumnN)const;
    std::vector<ComplexNum> GetExtRowN(int N)const;
    std::vector<ComplexNum> GetLineN(int N)const;
    std::vector<ComplexNum> GetIneRowN(int N)const;
    std::vector<ComplexNum> GetColumnN(int N)const;
    std::vector<ComplexNum> GetContent_ExtRows()const;
    std::vector<ComplexNum> GetContent_Lines()const;
    std::vector<ComplexNum> GetContent_Columns()const;
    //
    //
    void SwapVals_EIR(int ExtRowN1, int IneERowN1, int ExtRowN2, int IneRowN2);
    void SwapVals(int LineN1, int ColN1, int LineN2, int ColN2);
    void SwapExtRows(int ExtRowN1, int ExtRowN2);
    void SwapIneRows(int IneRowN1, int IneRowN2);
    void SwapLines(int LineN1, int LineN2);
    void SwapColumns(int ColN1, int ColN2);
    //
    //
    void SetExtRow_Simple(ComplexNum*row, int N);
    void SetLine_Simple(ComplexNum*row, int LineN);
    void SetIneRow_Simple(ComplexNum*row, int N);
    void SetColumn_Simple(ComplexNum*row, int ColN);
    //
    void SetExtRow_Simple(double*row, int N);
    void SetLine_Simple(double*row, int LineN);
    void SetIneRow_Simple(double*row, int N);
    void SetColumn_Simple(double*row, int ColN);
    //
    void AddExtRow_Simple(ComplexNum*row);
    void AddLine_Simple(ComplexNum*row);
    void AddIneRow_Simple(ComplexNum*row);
    void AddColumn_Simple(ComplexNum*row);
    //
    void InsExtRow_Simple(ComplexNum*row, int N);
    void InsLine_Simple(ComplexNum*row, int N);
    void InsIneRow_Simple(ComplexNum*row, int N);
    void InsColumn_Simple(ComplexNum*row, int N);
    //
    void DelExtRow_Simple(int N);
    void DelLine_Simple(int N);
    void DelIneRow_Simple(int N);
    void DelColumn_Simple(int N);
    //
    //
    Matrix_V1S_Lines_Simple SubMatrix_EIR(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
    Matrix_V1S_Lines_Simple SubMatrix(int LineN1, int ColumnN1, int LineN2, int ColumnN2);
    //Matrix_V1S_Lines_Simple SubMatrix_EIR(int ExtRowN1, int QExtRows, int QEmptyExtRowsBefore);
    //Matrix_V1S_Lines_Simple SubMatrix_Lines(int LineN1, int QLines, int QEmptyLinesBefore);
    //Matrix_V1S_Lines_Simple SubMatrix_Columns(int ColN1, int QCols, int QEmptyColsBefore);
    //
    void StdCout_ExtRowN(int N, std::string delim="; ", bool showBrackets=true, bool RepresentVertNotHor=false);
    void StdCout_IneRowN(int N, std::string delim="; ", bool showBrackets=true, bool RepresentVertNotHor=true);
    void StdCout_LineN(int N, std::string delim="; ", bool showBrackets=true,  bool RepresentVertNotHor=false);
    void StdCout_ColN(int N, std::string delim="; ", bool showBrackets=true, bool Represent2DNot1D=true);
    void StdCout_EIR_ExtHor(std::string delimElem=", ", std::string delimRow="; ", bool showBrackets=true, bool Represent2DNot1D=true);
    void StdCout(std::string delimElem=", ", std::string delimRow="; ", bool showBrackets=true, bool Represent2DNot1D=true);
};

#endif // MATRICA_H
