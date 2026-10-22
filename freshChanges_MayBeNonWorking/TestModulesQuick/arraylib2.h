#ifndef ARRAYLIB2_H
#define ARRAYLIB2_H

#include"math.h"
#include<QString>
#include<string>
#include<vector>
#include<iostream>//for cout

#include"aLibForArrays.h"

//class arraylib2
//{
//public:
//    arraylib2();
//};

//const bool UsualTypeOfEIRowOrderType_CL_not_LC=false;
const int TypeOfEIRowOrderType_CL=0;
const int TypeOfEIRowOrderType_LC=1;
const int TypeOfEIRowOrderType_Usual=TypeOfEIRowOrderType_CL;

template<class T> class Array2D_Prototype{
  public:
    virtual ~Array2D_Prototype()=0;
    //
    //
    virtual void construct()=0;
    virtual void SetNull()=0;
    virtual void SetNullIni()=0;
    void SetOne(const T& DefaultVal);
    void SetOne(T*dfltValParam=NULL);
    //
    //
    virtual T GetElement_EIR_asVal(int ExtRowN, int IneRowN)=0;
    //virtual T GetElement_LC_asVal(int LineN, int ColN)=0;
    virtual T*GetElement_EIR_asPtr(int ExtRowN, int IneRowN)=0;
    //virtual T*GetElement_LC_asPtr(int LineN, int ColN)=0;
    virtual void SetElement_EIR(T val, int ExtRowN, int IneRowN)=0;
    //virtual void SetElement_LC(T val, int LineN, int ColN)=0;
    //
    virtual int GetTypeN()=0;
    virtual int GetQElements()=0;
    virtual void Assign(Array2D_Prototype*obj)=0;
    //
    //
    virtual int GetQExtRows()=0;
    virtual int GetRowLength(int N=-1)=0;
    int GetRowLengthMin();
    int GetRowLengthMax();
    //virtual int GetQLines()=0;
    //virtual int GetQColumns()=0;
    virtual int GetFullLengthOfIneRowN_FromStartNoBreaks()=0;
    virtual std::vector<int>GetRowsLengthes()=0;
    //virtual int GetLineLength(int N=-1)=0;//new!!
    //virtual int GetColumnLength(int N=-1)=0;//new!!
    //
    bool IsForTranspose();
    //
    virtual Array2DSize_Shell GetSize()=0;
    virtual Array2DSize_Prototype*GetSize_asPtr()=0;
    virtual void SetSize_EIR(const Array2DSize_Shell&size)=0;
    void SetSize_EIR(int QExtRows, int*RowsL);//x
    void SetSize_EIR(int QExtRows, int RowsL);//x
    //virtual void SetSize_LC(const Array2DSize_Rectangular*size)=0;
    //void SetSize_LC(int QLines, int QColumns);//x
    //
    //
    std::vector<T> GetData_As1D_AsExtRowsSucc();//x;
    std::vector<T> GetData_As1D_AsLinesSucc();//x;
    std::vector<T> GetData_As1D_AsColumnsSucc();//x;
    std::vector<std::vector<T>> GetData_2DVect_EIR();//x
    //std::vector<std::vector<T>> GetData_2DVect_LC();
    //std::vector<std::vector<T>> GetData_2DVect_CL();
    //
    //
    void Set_IfGivenEIR(T**data, const Array2DSize_Shell&size);
    void Set_IfGivenEIR(T**data, int QExtRows, int*RowsL);//x
    void Set_IfGivenEIR(T**data, int QExtRows, int RowsL);//x
    //
    //virtual void Set_IfGivenLC(T**data, const Array2DSize_Shell&size)=0;
    //void Set_IfGivenLC(T**data, int QLines, int QColumns);//x
    //
    //virtual void Set_IfGivenCL(T**data, const Array2DSize_Shell&size)=0;
    //void Set_IfGivenCL(T**data, int QLines, int QColumns);//x
    //
    void Set_IfGivenEIR(T*data, const Array2DSize_Shell&size);//xx
    void Set_IfGivenEIR(T*data, int QExtRows, int*RowsL);//x
    void Set_IfGivenEIR(T*data, int QExtRows, int RowsL);//x
    //
    //virtual void Set_IfGivenLC(T*data, const Array2DSize_Shell&size)=0;
    //void Set_IfGivenLC(T*data, int QLines, int QColumns);//x
    //
    //virtual void Set_IfGivenCL(T*data, const Array2DSize_Shell&size)=0;
    //void Set_IfGivenCL(T*data, int QLines, int QColumns);//x
    //
    void Set_IfGivenEIR(std::vector<std::vector<T>>data, bool RectByTypeIfInFact=true);
    //void Set_IfGivenLC(std::vector<std::vector<T>>data, bool RectByTypeIfInFact=true);
    //void Set_IfGivenCL(std::vector<std::vector<T>>data, bool RectByTypeIfInFact=true);
    //
    //
    //virtual void Set_SelectedRare_EIR(int QVals, T*vals, Coords2DInt*coords, T*dfltVal=NULL, int SetSize_ByMaxOfGivenCoords=0)=0;
    //virtual void Set_SelectedRare_LC(int QVals, T*vals, Coords2DInt*coords, T*dfltVal=NULL, int SetSize_ByMaxOfGivenCoords=0)=0;
    //virtual void Set_SelectedRare_EIR(int QVals, T*vals, int*x, int*y, T*dfltVal=NULL, int SetSize_ByMaxOfGivenCoords=0)=0;
    //virtual void Set_SelectedRare_LC(int QVals, T*vals, int*x, int*y, T*dfltVal=NULL, int SetSize_ByMaxOfGivenCoords=0)=0;
    void Set_SelectedRare_EIR(std::vector<Array2DElement<T>>data, T DefaultVal, int SetFull0Append1=0);
    //void Set_SelectedRare_LC(std::vector<Array2DElement<T>>data, T DefaultVal, int SetFull0Append1=0);
    void Set_SelectedRare_EIR(std::vector<Array2DElement<T>>data, T*dfltVal=NULL/*, int SetFull0Append1=0*/);
    //void Set_SelectedRare_LC(std::vector<Array2DElement<T>>data, T*dfltVal=NULL, int SetFull0Append1=0);
    //
    //
    void SwapVals_EIR(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);//xx
    //void SwapVals_LC(int LineN1, int ColN1, int LineN2, int ColN2);//xx
    void ReverseExtRows();//xx
    void ReverseExtRowN(int ExtRowN);//xx
    void ReverseIneRows();//xx
    void ReverseIneRowN(int IneRowN);//xx
    //void ReverseLines();//xx
    //void ReverseLineN(int LineN);//xx
    //void ReverseColumns();//xx
    //void ReverseColumnN(int ColN);//xx
    //
    //
    virtual void SetExtRowN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    void SetExtRowN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);//xx
    virtual void SetIneRowN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    void SetIneRowN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);//xx
    //virtual void SetLineN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    //void SetLineN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);//xx
    //virtual void SetColumnN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    //void SetColumnN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);//xx
    //
    virtual void AddExtRowN(T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    void AddExtRowN(T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);//xx
    virtual void AddIneRowN(T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    void AddIneRowN(T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);//xx
    //virtual void AddLineN(T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    //void AddLineN(T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);//xx
    //virtual void AddColumnN( T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    //void AddColumnN(T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0,int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);//xx
    //
    virtual void InsExtRowN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    void InsExtRowN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);//xx;
    virtual void InstIneRowN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    void InsIneRowN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);//xx;
    //virtual void InsLineN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    //void InsLineN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);//xx;
    //virtual void InsColumnN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    //void InsColumnN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);//xx;
    //
    virtual void DelExtRowN(int N, T DefaultVal, const TDataShiftParams&DataShiftParams, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    virtual void DelExtRowN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL,  int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    virtual void DelIneRowN(int N, T DefaultVal, const TDataShiftParams&DataShiftParams,  int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    virtual void DelIneRowN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL,  int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    //virtual void DelLineN(int N, T DefaultVal, const TDataShiftParams&DataShiftParams,  int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    //virtual void DelLineN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL,  int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    //virtual void DelColumnN(int N, T DefaultVal, const TDataShiftParams&DataShiftParams,  int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    //virtual void DelColumnN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    //
    virtual std::vector<T> GetExtRowN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL)=0;
    virtual std::vector<T> GetIneRowN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL)=0;
    //virtual std::vector<T> GetLineN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL)=0;
    //virtual std::vector<T> GetColumnN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL)=0;
    //
    virtual void AddToExtRowN(int N, const T&val, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    virtual void InsToExtRowN(int ExtRowN, const T&val, int PosN, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    virtual void DelFromExtRowN(int ExtRowN, int PosN, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    //
    //
    virtual void Transpose()=0;
    //
    //
    virtual std::vector<std::vector<int>> SeekVal(const T&val)=0;
    //
    virtual bool ExtSubRowIsAtPos(T*row, int rowL, int ExtRowN, int IneRowN, bool isReversed=false)=0;
    virtual bool IneSubRowIsAtPos(T*row, int rowL, int ExtRowN, int IneRowN, bool isReversed=false)=0;
    //virtual bool ExtSubLineIsAtPos(T*row, int rowL, int LineN, int ColN, bool isReversed=false)=0;
    //virtual bool IneSubColIsAtPos(T*row, int rowL, int LineN, int ColN, bool isReversed=false)=0;
    virtual std::vector<std::vector<int>> SeekExtSubRow(T*row, int rowL, int ExtRowN, int IneRowN, bool isReversed=false)=0;
    virtual std::vector<std::vector<int>> SeekIneSubRow(T*row, int rowL, int ExtRowN, int IneRowN, bool isReversed=false)=0;
    //virtual std::vector<std::vector<int>> SeekSubLine(T*row, int rowL, int LineN, int ColN, bool isReversed=false)=0;
    //virtual std::vector<std::vector<int>> SeekSubCol(T*row, int rowL, int LineN, int ColN, bool isReversed=false)=0;
    //
    virtual bool SubArrIsAtPos_EIR(Array2D_Prototype*obj, int ExtRowN, int IneRowN, bool isTransposed=false, bool ExtRowsSuccIsReversed=false, bool EachExtRowIsReversed=false)=0;
    //virtual bool SubArrIsAtPos_LC(Array2D_EIR_Prototype*obj, int LineN, int ColN, bool isTransposed=false, bool ExtRowsSuccIsReversed=false, bool EachExtRowIsReversed=false)=0;
    virtual std::vector<std::vector<int>> SeekSubArr_EIR(Array2D_Prototype*obj, bool isTransposed=false, bool ExtRowsSuccIsReversed=false, bool EachExtRowIsReversed=false)=0;
    //virtual std::vector<std::vector<int>> SeekSubArr_LC(Array2D_EIR_Prototype*obj, bool isTransposed=false, bool ExtRowsSuccIsReversed=false, bool EachExtRowIsReversed=false)=0;
    //
    //
    virtual void ConcatAdding(Array2D_Prototype*obj, T DefaultVal, TDataShiftParams*dsp=NULL)=0;
    virtual void ConcatAdding(Array2D_Prototype*obj, TDataShiftParams*dsp=NULL, T*dfltVal=NULL)=0;
    virtual void ConcatStretching(Array2D_Prototype*obj, T DefaultVal, TDataShiftParams*dsp=NULL, int ifNotRect_Ignore0AddToLast1StretchToMax2=1)=0;
    virtual void ConcatStretching(Array2D_Prototype*obj, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int ifNotRect_Ignore0AddToLast1StretchToMax2=1)=0;
    //
    //
    void ShowToConsole(std::string delimElem=", ", std::string delimRow="; ", bool as2DNot1D=true, bool ShowBrackets=false);
};

template<typename T> void Array2D_Prototype<T>::SetOne(T*DfltValParam){
    this->SetSize(1, 1);
    T DefaultVal;
    if(DfltValParam!=NULL){
        DefaultVal=(*(DfltValParam));
    }
    this->SetComponent(DefaultVal, 1, 1);
}
template<typename T> void Array2D_Prototype<T>::SetOne(const T& DefaultVal){
    this->SetSize(1, 1);
    this->SetComponent(DefaultVal, 1, 1);
}
template<typename T> void Array2D_Prototype<T>::Assign(Array2D_Prototype<T>*obj){
    Array2DSize_Shell size=obj->GetSize();
    T val;
    int QExtRows=size.GetQExtRows(), curL;
    this->SetSize(size);
    for(int i=1; i<=QExtRows; i++){
        curL=size.GetRowLength(i);
        for(int j=1; j<=curL; j++){
            val=this->GetComponent_AsVal(i, j);
            this->SetComponent(val, i, j);
        }
    }
}

//template<typename T>bool Array2D_EIR_Prototype<T>::IsForTranspose();
//
//virtual Array2DSize_Shell GetSize()=0;
//virtual void SetSize_EIR(const Array2DSize_Shell&size)=0;
template<typename T>void Array2D_Prototype<T>::SetSize_EIR(int QExtRows, int*RowsL){
    Array2DSize_Shell size(QExtRows, RowsL);
    this->SetSize_EIR(size);
}

template<typename T>void Array2D_Prototype<T>::SetSize_EIR(int QExtRows, int RowsL){
    Array2DSize_Shell size(QExtRows, RowsL);
    this->SetSize_EIR(size);
}
//virtual void SetSize_LC(const Array2DSize_Rectangular*size)=0;
template<typename T>void Array2D_Prototype<T>::SetSize_LC(int QLines, int QColumns){
    Array2DSize_Shell size(QLines, QColumns);
    this->SetSize_EIR(size);
}
//
//
template<typename T>std::vector<T> Array2D_Prototype<T>::GetData_As1D_AsExtRowsSucc(){
    std::vector<T>R;
    T val;
    int QExtRows=this->GetQExtRows(), curL;
    std::vector<int>rowsLen=this->GetRowsLengthes();
    for(int ExtRowN=1; ExtRowN<=QExtRows; ExtRowN++){
        curL=rowsLen[ExtRowN-1];
        for(int IneRowN=1; IneRowN<=curL; IneRowN++){
            val=this->GetElement_EIR_asVal(ExtRowN, IneRowN);
            R.push_back(val);
        }
    }
    return R;
}
template<typename T>std::vector<T> Array2D_Prototype<T>::GetData_As1D_AsLinesSucc(){//Q'S'tak?
    std::vector<T> R;
    T val;
    int QLines=this->GetQLines(), QColumns=this->GetQColumns(), minL=this->GetRowLengthMin(), maxL=this->GetRowLengthMax();
    if(minL==maxL){
        for(int LineN=1; LineN<=QLines; LineN++){
            for(int ColN=1; ColN<=QColumns; ColN++){
                val=this->GetElement_LC_asVal(LineN, ColN);
                R.push_back(val);
            }
        }
    }//otherwise S'arb'ftc n'in prototype
    return R;
}
template<typename T>std::vector<T> Array2D_Prototype<T>::GetData_As1D_AsColumnsSucc(){//Q'S'tak?
    std::vector<T> R;
    T val;
    int QLines=this->GetQLines(), QColumns=this->GetQColumns(), minL=this->GetRowLengthMin(), maxL=this->GetRowLengthMax();
    if(minL==maxL){
        for(int ColN=1; ColN<=QColumns; ColN++){
            for(int LineN=1; LineN<=QLines; LineN++){
                val=this->GetElement_LC_asVal(LineN, ColN);
                R.push_back(val);
            }
        }
    }//otherwise S'arb'ftc n'in prototype
    return R;
}
template<typename T>std::vector<std::vector<T>> Array2D_Prototype<T>::GetData_2DVect_EIR(){
    std::vector<std::vector<T>>R;
    std::vector<T>row;
    T val;
    int QExtRows=this->GetQExtRows(), curL;
    for(int ExtRowN=1; ExtRowN<=QExtRows; ExtRowN++){
        curL=this->GetRowLength(ExtRowN);
        row.clear();
        for(int IneRowN=1; IneRowN<=curL; IneRowN++){
            val=this->GetElement_EIR_asVal(ExtRowN, IneRowN);
            row.push_back(val);
        }
        R.push_back(row);
    }
    return R;
}
template<typename T>std::vector<std::vector<T>> Array2D_Prototype<T>::GetData_2DVect_LC(){
    std::vector<std::vector<T>>R;
    std::vector<T>row;
    T val;
    int QExtRows=this->GetQExtRows(), curL, QLines=this->GetQLines(), QColumns=this->GetQColumns(), minL=this->GetRowLengthMin(), maxL=this->GetRowLengthMax();
    for(int LineN=1; LineN<=QLines; LineN++){
        row.clear();
        for(int ColN=1; ColN<=QColumns; ColN++){
            val=this->GetElement_LC_asVal(LineN, ColN);
            row.push_back(val);
        }
        R.push_back(row);
    }
    return R;
}
template<typename T>std::vector<std::vector<T>> Array2D_Prototype<T>::GetData_2DVect_CL(){
    std::vector<std::vector<T>>R;
    std::vector<T>row;
    T val;
    int QExtRows=this->GetQExtRows(), curL, QLines=this->GetQLines(), QColumns=this->GetQColumns(), minL=this->GetRowLengthMin(), maxL=this->GetRowLengthMax();
    for(int ColN=1; ColN<=QColumns; ColN++){
        for(int LineN=1; LineN<=QLines; LineN++){
            val=this->GetElement_LC_asVal(LineN, ColN);
            row.push_back(val);
        }
        R.push_back(row);
    }
    return R;
}
//
//
template<typename T> void Array2D_Prototype<T>::Set_IfGivenEIR(T**data, const Array2DSize_Shell&size){
    int QER, curL;
    this->SetSize_EIR(size);
    QER=size.GetQExtRows();
    if(QER>0){
        for(int ERN=1; ERN<=QER; ERN++){
            curL=size.GetRowLength(ERN);
            for(int IRN=1; IRN<=curL; IRN++){
                this->SetElement_EIR(data[ERN-1][IRN-1], ERN, IRN);
            }
        }
    }
}
template<typename T> void Array2D_Prototype<T>::Set_IfGivenEIR(T**data, int QExtRows, int*RowsL){
    Array2DSize_Shell size(QExtRows, RowsL);
    this->Set_IfGivenEIR(data, size);
}
template<typename T> void Array2D_Prototype<T>::Set_IfGivenEIR(T**data, int QExtRows, int RowsL){
    Array2DSize_Shell size(QExtRows, RowsL);
    this->Set_IfGivenEIR(data, size);
}
//
//virtual void Set_IfGivenLC(T**data, const Array2DSize_Shell&size)=0;
template<typename T> void Array2D_Prototype<T>::Set_IfGivenLC(T**data, int QLines, int QColumns){
    Array2DSize_Shell size(QLines, QColumns);
    this->Set_IfGivenLC(data, size);
}
//
//virtual void Set_IfGivenCL(T**data, const Array2DSize_Shell&size)=0;
template<typename T> void Array2D_Prototype<T>::Set_IfGivenCL(T**data, int QLines, int QColumns){
    Array2DSize_Shell size(QLines, QColumns);
    this->Set_IfGivenCL(data, size);
}
//
template<typename T> void Array2D_Prototype<T>::Set_IfGivenEIR(T*data, const Array2DSize_Shell&size){
    int QER, curL, posN;
    std::vector<int>Ls=size.GetLengthes();
    this->SetSize_EIR(size);
    QER=size.GetQExtRows();
    if(QER>0){
        for(int ERN=1; ERN<=QER; ERN++){
            curL=size.GetRowLength(ERN);
            for(int IRN=1; IRN<=curL; IRN++){
                posN=PosNInArr2DAs1D(QER, Ls.data(), ERN, IRN);
                this->SetElement_EIR(data[posN-1], ERN, IRN);
            }
        }
    }
}
template<typename T> void Array2D_Prototype<T>::Set_IfGivenEIR(T*data, int QExtRows, int*RowsL){
    Array2DSize_Shell size(QExtRows, RowsL);
    this->Set_IfGivenEIR(data, size);
}
template<typename T> void Array2D_Prototype<T>::Set_IfGivenEIR(T*data, int QExtRows, int RowsL){
    Array2DSize_Shell size(QExtRows, RowsL);
    this->Set_IfGivenEIR(data, size);
}
//
//virtual void Set_IfGivenLC(T*data, const Array2DSize_Shell&size)=0;
template<typename T> void Array2D_Prototype<T>::Set_IfGivenLC(T*data, int QLines, int QColumns){
    Array2DSize_Shell size(QLines, QColumns);
    this->Set_IfGivenLC(data, size);
}
//
//virtual void Set_IfGivenCL(T*data, const Array2DSize_Shell&size)=0;
template<typename T> void Array2D_Prototype<T>::Set_IfGivenCL(T*data, int QLines, int QColumns){
    Array2DSize_Shell size(QLines, QColumns);
    this->Set_IfGivenCL(data, size);
}
//
template<typename T> void Array2D_Prototype<T>::Set_IfGivenEIR(std::vector<std::vector<T>>data, bool RectByTypeIfInFact){
    Array2DSize_Shell size=GetSizeOfVector2D(data);
    std::vector<T>DataAs1D;
    int QER=size.GetQExtRows(), curL, minL=size.GetRowLengthMin(), maxL=size.GetRowLengthMax();
    for(int ERN=1; ERN<=QER; ERN++){
        for(int IRN=1; IRN<=curL; IRN++){
            DataAs1D.push_back(data[ERN-1][IRN-1]);
        }
    }
    if(minL=maxL && RectByTypeIfInFact){
        size.SetTypeN(Array2DSize_Rectangular_TypeN);
    }
    this->Set_IfGivenEIR(data, size);
}

template<typename T> void Array2D_Prototype<T>::Set_IfGivenLC(std::vector<std::vector<T>>data, bool RectByTypeIfInFact){
    Array2DSize_Shell size=GetSizeOfVector2D(data);
    std::vector<T>DataAs1D;
    int QER=size.GetQExtRows(), curL, minL=size.GetRowLengthMin(), maxL=size.GetRowLengthMax();
    for(int ERN=1; ERN<=QER; ERN++){
        for(int IRN=1; IRN<=curL; IRN++){
            DataAs1D.push_back(data[ERN-1][IRN-1]);
        }
    }
    if(minL=maxL && RectByTypeIfInFact){
        size.SetTypeN(Array2DSize_Rectangular_TypeN);
    }
    this->Set_IfGivenLC(data, size);
}

template<typename T> void Array2D_Prototype<T>::Set_IfGivenCL(std::vector<std::vector<T>>data, bool RectByTypeIfInFact){
    Array2DSize_Shell size=GetSizeOfVector2D(data);
    std::vector<T>DataAs1D;
    int QER=size.GetQExtRows(), curL, minL=size.GetRowLengthMin(), maxL=size.GetRowLengthMax();
    for(int ERN=1; ERN<=QER; ERN++){
        for(int IRN=1; IRN<=curL; IRN++){
            DataAs1D.push_back(data[ERN-1][IRN-1]);
        }
    }
    if(minL=maxL && RectByTypeIfInFact){
        size.SetTypeN(Array2DSize_Rectangular_TypeN);
    }
    this->Set_IfGivenCL(data, size);
}
//
template<typename T> void Array2D_Prototype<T>::Set_SelectedRare_EIR(std::vector<Array2DElement<T>>data, T DefaultVal/*, int SetFull0Append1*/){
    Array2DSize_Shell sizeNew;
    std::vector<Coords2DInt>coords;
    Coords2DInt coord;
    T val;
    QGiven=data.size();
    for(int i=1; i<=QGiven; i++){
        coord=data[i-1].coords;
        coords.push_back(coord);
    }
    sizeNew.SetByListOfCoords(coords);
    this->SetNull();
    this->SetOne(DefaultVal);
    this->SetSize_EIR(sizeNew);
    for(int i=1; i<=QGiven; i++){
        val=data[i-1].data;
        coord=data[i-1].coords;
        this->SetElement_EIR(val, coord.x, coord.y);
    }
}

//template<typename T> void Array2D_Prototype<T>::Set_SelectedRare_LC(std::vector<Array2DElement<T>>data, T DefaultVal, int SetFull0Append1){}
template<typename T> void Array2D_Prototype<T>::Set_SelectedRare_EIR(std::vector<Array2DElement<T>>data, T*dfltVal/*, int SetFull0Append1*/){
    T DefaultVal;
    if(dfltVal!=NULL){
        DefaultVal=(*(DefaultVal));
    }
    this->Set_SelectedRare_EIR(data, DefaultVal);
}
//template<typename T> void Array2D_Prototype<T>::Set_SelectedRare_LC(std::vector<Array2DElement<T>>data, T*dfltVal, int SetFull0Append1){}

//
//
template<typename T> int Array2D_Prototype<T>::GetRowLengthMin(){
    int minL, maxL, curL, QExtRows=this->GetQExtRows();
    for(int ExtRowN=1; ExtRowN<=QExtRows; ExtRowN++){
        curL=this->GetRowLength(ExtRowN);
        if(ExtRowN==1 || (ExtRowN>1 && curL<minL)){
            minL=curL;
        }
        if(ExtRowN==1 || (ExtRowN>1 && curL>maxL)){
            maxL=curL;
        }
    }
    return minL;
}
template<typename T> int Array2D_Prototype<T>::GetRowLengthMax(){
    int minL, maxL, curL, QExtRows=this->GetQExtRows();
    for(int ExtRowN=1; ExtRowN<=QExtRows; ExtRowN++){
        curL=this->GetRowLength(ExtRowN);
        if(ExtRowN==1 || (ExtRowN>1 && curL<minL)){
            minL=curL;
        }
        if(ExtRowN==1 || (ExtRowN>1 && curL>maxL)){
            maxL=curL;
        }
    }
    return maxL;
}

template<typename T> void Array2D_Prototype<T>::SwapVals_EIR(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2){
   T val1, val2;
   int QExtRows=this->GertQExtRows(), RowL1, RowL2;
   if(ExtRowN1>=1 && ExtRowN1<=QExtRows && ExtRowN2>=1 && ExtRowN2<=QExtRows){
       RowL1=this->GetRowLength(ExtRowN1);
       RowL2=this->GetRowLength(ExtRowN2);
       if(IneRowN1>=1 && IneRowN1<=RowL1 && IneRowN2>=1 && IneRowN2<=RowL2){
           val1=this->GetElement_EIR_asVal(ExtRowN1, IneRowN1);
           val2=this->GetElement_EIR_asVal(ExtRowN2, IneRowN2);
           this->SetElement_EIR(val2, ExtRowN1, IneRowN1);
           this->SetElement_EIR(val1, ExtRowN2, IneRowN2);
       }
   }
}
template<typename T> void Array2D_Prototype<T>::SwapVals_LC(int LineN1, int ColN1, int LineN2, int ColN2){
    T val1, val2;
    int QExtRows=this->GetQExtRows(), QLines=this->GetQLines(), QColumns=this->GetQColumns(), minL=this->GetRowLengthMin(), maxL=this->GetRowLengthMax(), RowL1, RowL2;
    if(minL==maxL){
        if(LineN1>=1 && LineN1<=QLines && LineN2>=1 && LineN2<=QLines &&
            ColN1>=1 && ColN1<=QColumns && ColN2>=1 && ColN2<=QColumns){
            //RowL1=this->GetRowLength(ExtRowN1);
            //RowL2=this->GetRowLength(ExtRowN2);
            val1=this->GetElement_LC_asVal(LineN1, ColN1);
            val1=this->GetElement_LC_asVal(LineN2, ColN2);
            this->SetElement_LC(val2, LineN1, ColN1);
            this->SetElement_LC(val1, LineN2, ColN2);
        }
    }
}
//template<typename T> Array2D_EIR_Prototype*GetData(){
//    return this->data;
//}


template<class T> class Array2D_P1D:public Array2D_Prototype<T>{
    T*x;
    Array2DSize_Prototype*size;
  public:
    //
    Array2D_P1D(T**data, const Array2DSize_Shell&size);
    Array2D_P1D(T**data, int QRows, int*RowsL);
    Array2D_P1D(T**data, int QRows, int RowsL);
    Array2D_P1D(T*data, const Array2DSize_Shell&size);
    Array2D_P1D(T*data, int QRows, int*RowsL);
    Array2D_P1D(T*data, int QRows, int RowsL);
    Array2D_P1D(std::vector<std::vector<T>>data, bool RectByTypeIfInFact=true);
    //
    ~Array2D_P1D();
    //
    //
    virtual void construct();
    virtual void SetNull();
    virtual void SetNullIni();
    //void SetOne(const T& DefaultVal);//in prototype
    //void SetOne(T*dfltValParam=NULL);//in prototype
    //
    //
    virtual T GetElement_EIR_asVal(int ExtRowN, int IneRowN);
    virtual T GetElement_LC_asVal(int LineN, int ColN, int LC0CL1=TypeOfEIRowOrderType_Usual);
    virtual T*GetElement_EIR_asPtr(int ExtRowN, int IneRowN);
    virtual T*GetElement_LC_asPtr(int LineN, int ColN, int LC0CL1=TypeOfEIRowOrderType_Usual);
    virtual void SetElement_EIR(T val, int ExtRowN, int IneRowN);
    virtual void SetElement_LC(T val, int LineN, int ColN, int LC0CL1=TypeOfEIRowOrderType_Usual);
    //
    virtual int GetTypeN();
    virtual int GetQElements();
    virtual void Assign(Array2D_Prototype<T>*obj);
    //
    //
    virtual int GetQExtRows();
    virtual int GetRowLength(int N=-1);
    //int GetRowLengthMin();
    // int GetRowLengthMax();
    virtual int GetQLines(int LC0CL1=TypeOfEIRowOrderType_Usual);
    virtual int GetQColumns(int LC0CL1=TypeOfEIRowOrderType_Usual);
    virtual int GetFullLengthOfIneRowN_FromStartNoBreaks();
    virtual std::vector<int>GetRowsLengthes();
    virtual int GetLineLength(int N=-1, int LC0CL1=TypeOfEIRowOrderType_Usual);
    virtual int GetColumnLength(int N=-1, int LC0CL1=TypeOfEIRowOrderType_Usual);
    //
    //virtual bool IsForTranspose();//in prototype
    //
    virtual Array2DSize_Shell GetSize();
    virtual Array2DSize_Prototype*GetSize_asPtr();
    virtual void SetSize_EIR(const Array2DSize_Shell&size);
    //virtual void SetSize_EIR(int QExtRows, int*RowsL);//in prototype
    //virtual void SetSize_EIR(int QExtRows, int RowsL);//in prototype
    void SetSize_LC(const Array2DSize_Rectangular*size, int LC0CL1=TypeOfEIRowOrderType_Usual);
    void SetSize_LC(int QLines, int QColumns, int LC0CL1=TypeOfEIRowOrderType_Usual);
    //
    //
    //std::vector<T> GetData_As1D_AsExtRowsSucc();//in prototype
    //std::vector<T> GetData_As1D_AsLinesSucc();//in prototype
    //std::vector<T> GetData_As1D_AsColumnsSucc();//in prototype
    //std::vector<std::vector<T>> GetData_2DVect_EIR();//in prototype
    std::vector<std::vector<T>> GetData_2DVect_LC(int LC0CL1=TypeOfEIRowOrderType_Usual);
    std::vector<std::vector<T>> GetData_2DVect_CL(int LC0CL1=TypeOfEIRowOrderType_Usual);
    //
    //void Set_IfGivenEIR(T**data, const Array2DSize_Shell&size);
    //void Set_IfGivenEIR(T**data, int QExtRows, int*RowsL);//in prototype
    //void Set_IfGivenEIR(T**data, int QExtRows, int RowsL);//in prototype
    //
    void Set_IfGivenLC(T**data, const Array2DSize_Shell&size, int LC0CL1=TypeOfEIRowOrderType_Usual);
    void Set_IfGivenLC(T**data, int QLines, int QColumns, int LC0CL1=TypeOfEIRowOrderType_Usual);
    //
    void Set_IfGivenCL(T**data, const Array2DSize_Shell&size, int LC0CL1=TypeOfEIRowOrderType_Usual);
    void Set_IfGivenCL(T**data, int QLines, int QColumns, int LC0CL1=TypeOfEIRowOrderType_Usual);
    //
    //void Set_IfGivenEIR(T*data, const Array2DSize_Shell&size);
    //void Set_IfGivenEIR(T*data, int QExtRows, int*RowsL);//in prototype
    //void Set_IfGivenEIR(T*data, int QExtRows, int RowsL);//in prototype
    //
    void Set_IfGivenLC(T*data, const Array2DSize_Shell&size, int LC0CL1=TypeOfEIRowOrderType_Usual);
    void Set_IfGivenLC(T*data, int QLines, int QColumns, int LC0CL1=TypeOfEIRowOrderType_Usual);
    //
    void Set_IfGivenCL(T*data, const Array2DSize_Shell&size, int LC0CL1=TypeOfEIRowOrderType_Usual);
    void Set_IfGivenCL(T*data, int QLines, int QColumns, int LC0CL1=TypeOfEIRowOrderType_Usual);
    //
    //void Set_IfGivenEIR(std::vector<std::vector<T>>data, bool RectByTypeIfInFact=true);
    void Set_IfGivenLC(std::vector<std::vector<T>>data, bool RectByTypeIfInFact=true, int LC0CL1=TypeOfEIRowOrderType_Usual);
    void Set_IfGivenCL(std::vector<std::vector<T>>data, bool RectByTypeIfInFact=true, int LC0CL1=TypeOfEIRowOrderType_Usual);
    //
    //
    virtual void Set_SelectedRare_EIR(int QVals, T*vals, Coords2DInt*coords, T*dfltVal=NULL, int SetSize_ByMaxOfGivenCoords=0);
    void Set_SelectedRare_LC(int QVals, T*vals, Coords2DInt*coords, T*dfltVal=NULL, int SetSize_ByMaxOfGivenCoords=0, int LC0CL1=TypeOfEIRowOrderType_Usual);
    virtual void Set_SelectedRare_EIR(int QVals, T*vals, int*x, int*y, T*dfltVal=NULL, int SetSize_ByMaxOfGivenCoords=0);
    void Set_SelectedRare_LC(int QVals, T*vals, int*x, int*y, T*dfltVal=NULL, int SetSize_ByMaxOfGivenCoords=0, int LC0CL1=TypeOfEIRowOrderType_Usual);
    //
    //
    virtual void SwapVals_EIR(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
    void SwapVals_LC(int LineN1, int ColN1, int LineN2, int ColN2, int LC0CL1=TypeOfEIRowOrderType_Usual);
    virtual void ReverseExtRows();
    virtual void ReverseExtRowN(int ExtRowN);
    virtual void ReverseIneRows();
    virtual void ReverseIneRowN(int IneRowN);
    void ReverseLines(int LC0CL1=TypeOfEIRowOrderType_Usual);
    void ReverseLineN(int LineN, int LC0CL1=TypeOfEIRowOrderType_Usual);
    void ReverseColumns(int LC0CL1=TypeOfEIRowOrderType_Usual);
    void ReverseColumnN(int ColN, int LC0CL1=TypeOfEIRowOrderType_Usual);
    //
    //
    virtual void SetExtRowN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void SetExtRowN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void SetIneRowN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void SetIneRowN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void SetLineN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void SetLineN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void SetColumnN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void SetColumnN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    //
    virtual void AddExtRowN(T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void AddExtRowN(T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void AddIneRowN(T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void AddIneRowN(T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void AddLineN(T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void AddLineN(T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void AddColumnN( T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void AddColumnN(T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0,int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    //
    virtual void InsExtRowN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void InsExtRowN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void InstIneRowN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void InsIneRowN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void InsLineN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void InsLineN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void InsColumnN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void InsColumnN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    //
    virtual void DelExtRowN(int N, T DefaultVal, const TDataShiftParams&DataShiftParams, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void DelExtRowN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL,  int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void DelIneRowN(int N, T DefaultVal, const TDataShiftParams&DataShiftParams,  int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void DelIneRowN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL,  int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void DelLineN(int N, T DefaultVal, const TDataShiftParams&DataShiftParams,  int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void DelLineN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL,  int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void DelColumnN(int N, T DefaultVal, const TDataShiftParams&DataShiftParams,  int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void DelColumnN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    //
    virtual std::vector<T> GetExtRowN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL);
    virtual std::vector<T> GetIneRowN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL);
    std::vector<T> GetLineN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int LC0CL1=TypeOfEIRowOrderType_Usual);
    std::vector<T> GetColumnN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int LC0CL1=TypeOfEIRowOrderType_Usual);
    //
    virtual void AddToExtRowN(int N, const T&val, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void InsToExtRowN(int ExtRowN, const T&val, int PosN, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void DelFromExtRowN(int ExtRowN, int PosN, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    //
    //
    virtual void Transpose();
    //
    //
    virtual std::vector<std::vector<int>> SeekVal(const T&val);
    //
    virtual bool ExtSubRowIsAtPos(T*row, int rowL, int ExtRowN, int IneRowN, bool isReversed=false);
    virtual bool IneSubRowIsAtPos(T*row, int rowL, int ExtRowN, int IneRowN, bool isReversed=false);
    bool ExtSubLineIsAtPos(T*row, int rowL, int LineN, int ColN, bool isReversed=false, int LC0CL1=TypeOfEIRowOrderType_Usual);
    bool IneSubColIsAtPos(T*row, int rowL, int LineN, int ColN, bool isReversed=false, int LC0CL1=TypeOfEIRowOrderType_Usual);
    virtual std::vector<std::vector<int>> SeekExtSubRow(T*row, int rowL, int ExtRowN, int IneRowN, bool isReversed=false);
    virtual std::vector<std::vector<int>> SeekIneSubRow(T*row, int rowL, int ExtRowN, int IneRowN, bool isReversed=false);
    std::vector<std::vector<int>> SeekSubLine(T*row, int rowL, int LineN, int ColN, bool isReversed=false, int LC0CL1=TypeOfEIRowOrderType_Usual);
    std::vector<std::vector<int>> SeekSubCol(T*row, int rowL, int LineN, int ColN, bool isReversed=false, int LC0CL1=TypeOfEIRowOrderType_Usual);
    //
    virtual bool SubArrIsAtPos_EIR(Array2D_Prototype<T>*obj, int ExtRowN, int IneRowN, bool isTransposed=false, bool ExtRowsSuccIsReversed=false, bool EachExtRowIsReversed=false);
    bool SubArrIsAtPos_LC(Array2D_Prototype<T>*obj, int LineN, int ColN, bool isTransposed=false, bool ExtRowsSuccIsReversed=false, bool EachExtRowIsReversed=false, int LC0CL1=TypeOfEIRowOrderType_Usual);
    virtual std::vector<std::vector<int>> SeekSubArr_EIR(Array2D_Prototype<T>*obj, bool isTransposed=false, bool ExtRowsSuccIsReversed=false, bool EachExtRowIsReversed=false);
    std::vector<std::vector<int>> SeekSubArr_LC(Array2D_Prototype<T>*obj, bool isTransposed=false, bool ExtRowsSuccIsReversed=false, bool EachExtRowIsReversed=false, int LC0CL1=TypeOfEIRowOrderType_Usual);
    //
    //
    virtual void ConcatAdding(Array2D_Prototype<T>*obj, T DefaultVal, TDataShiftParams*dsp=NULL);
    virtual void ConcatAdding(Array2D_Prototype<T>*obj, TDataShiftParams*dsp=NULL, T*dfltVal=NULL);
    virtual void ConcatStretching(Array2D_Prototype<T>*obj, T DefaultVal, TDataShiftParams*dsp=NULL, int ifNotRect_Ignore0AddToLast1StretchToMax2=1);
    virtual void ConcatStretching(Array2D_Prototype<T>*obj, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int ifNotRect_Ignore0AddToLast1StretchToMax2=1);

};

template<class T> class Array2D_Prototype_LC: public Array2D_Prototype{
  public:
    virtual ~Array2D_Prototype_LC()=0;
    //
    //
    //virtual void construct()=0;
    //virtual void SetNull()=0;
    //virtual void SetNullIni()=0;
    //void SetOne(const T& DefaultVal);
    //void SetOne(T*dfltValParam=NULL);
    //
    //
    //virtual T GetElement_EIR_asVal(int ExtRowN, int IneRowN)=0;
    virtual T GetElement_LC_asVal(int LineN, int ColN);
    //virtual T*GetElement_EIR_asPtr(int ExtRowN, int IneRowN)=0;
    virtual T*GetElement_LC_asPtr(int LineN, int ColN);
    //virtual void SetElement_EIR(T val, int ExtRowN, int IneRowN)=0;
    virtual void SetElement_LC(T val, int LineN, int ColN);
    //
    //virtual int GetTypeN()=0;
    //virtual int GetQElements()=0;
    //virtual void Assign(Array2D_Prototype_LC*obj)=0;
    //
    //
    //virtual int GetQExtRows()=0;
    //virtual int GetRowLength(int N=-1)=0;
    //int GetRowLengthMin();
    //int GetRowLengthMax();
    virtual int GetQLines()=0;
    virtual int GetQColumns()=0;
    //virtual int GetFullLengthOfIneRowN_FromStartNoBreaks()=0;
    //virtual std::vector<int>GetRowsLengthes()=0;
    virtual int GetLineLength(int N=-1);//new!!
    virtual int GetColumnLength(int N=-1);//new!!
    //
    //bool IsForTranspose();
    //
    //virtual Array2DSize_Shell GetSize()=0;
    //virtual Array2DSize_Prototype*GetSize_asPtr()=0;
    //virtual void SetSize_EIR(const Array2DSize_Shell&size)=0;
    //void SetSize_EIR(int QExtRows, int*RowsL);//x
    //void SetSize_EIR(int QExtRows, int RowsL);//x
    virtual void SetSize_LC(const Array2DSize_Rectangular*size)=0;
    virtual void SetSize_LC(int QLines, int QColumns);//x
    //
    //
    //std::vector<T> GetData_As1D_AsExtRowsSucc();//x;
    virtual std::vector<T> GetData_As1D_AsLinesSucc();//x;
    virtual std::vector<T> GetData_As1D_AsColumnsSucc();//x;
    //std::vector<std::vector<T>> GetData_2DVect_EIR();//x
    virtual std::vector<std::vector<T>> GetData_2DVect_LC();
    virtual std::vector<std::vector<T>> GetData_2DVect_CL();
    //
    //
    //void Set_IfGivenEIR(T**data, const Array2DSize_Shell&size);
    //void Set_IfGivenEIR(T**data, int QExtRows, int*RowsL);//x
    //void Set_IfGivenEIR(T**data, int QExtRows, int RowsL);//x
    //
    virtual void Set_IfGivenLC(T**data, int QLines, int QColumns)=0;
    virtual void Set_IfGivenLC(T**data, int QLines, int QColumns);//x
    //
    virtual void Set_IfGivenCL(T**data, const Array2DSize_Shell&size)=0;
    virtual void Set_IfGivenCL(T**data, int QLines, int QColumns);//x
    //
    //void Set_IfGivenEIR(T*data, const Array2DSize_Shell&size);//xx
    //void Set_IfGivenEIR(T*data, int QExtRows, int*RowsL);//x
    //void Set_IfGivenEIR(T*data, int QExtRows, int RowsL);//x
    //
    virtual void Set_IfGivenLC(T*data, const Array2DSize_Shell&size)=0;
    virtual void Set_IfGivenLC(T*data, int QLines, int QColumns);//x
    //
    virtual void Set_IfGivenCL(T*data, const Array2DSize_Shell&size)=0;
    virtual void Set_IfGivenCL(T*data, int QLines, int QColumns);//x
    //
    //void Set_IfGivenEIR(std::vector<std::vector<T>>data, bool RectByTypeIfInFact=true);
    virtual void Set_IfGivenLC(std::vector<std::vector<T>>data, bool RectByTypeIfInFact=true);
    virtual void Set_IfGivenCL(std::vector<std::vector<T>>data, bool RectByTypeIfInFact=true);
    //
    //
    //virtual void Set_SelectedRare_EIR(int QVals, T*vals, Coords2DInt*coords, T*dfltVal=NULL, int SetSize_ByMaxOfGivenCoords=0)=0;
    //virtual void Set_SelectedRare_LC(int QVals, T*vals, Coords2DInt*coords, T*dfltVal=NULL, int SetSize_ByMaxOfGivenCoords=0)=0;
    //virtual void Set_SelectedRare_EIR(int QVals, T*vals, int*x, int*y, T*dfltVal=NULL, int SetSize_ByMaxOfGivenCoords=0)=0;
    //virtual void Set_SelectedRare_LC(int QVals, T*vals, int*x, int*y, T*dfltVal=NULL, int SetSize_ByMaxOfGivenCoords=0)=0;
    //void Set_SelectedRare_EIR(std::vector<Array2DElement<T>>data, T DefaultVal, int SetFull0Append1=0);
    virtual void Set_SelectedRare_LC(std::vector<Array2DElement<T>>data, T DefaultVal, int SetFull0Append1=0);
    //void Set_SelectedRare_EIR(std::vector<Array2DElement<T>>data, T*dfltVal=NULL, int SetFull0Append1=0);
    virtual void Set_SelectedRare_LC(std::vector<Array2DElement<T>>data, T*dfltVal=NULL, int SetFull0Append1=0);
    //
    //
    //void SwapVals_EIR(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);//xx
    virtual void SwapVals_LC(int LineN1, int ColN1, int LineN2, int ColN2);//xx
    //void ReverseExtRows();//xx
    //void ReverseExtRowN(int ExtRowN);//xx
    //void ReverseIneRows();//xx
    //void ReverseIneRowN(int IneRowN);//xx
    virtual void ReverseLines();//xx
    virtual void ReverseLineN(int LineN);//xx
    virtual void ReverseColumns();//xx
    virtual void ReverseColumnN(int ColN);//xx
    //
    //
    //virtual void SetExtRowN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    //void SetExtRowN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);//xx
    //virtual void SetIneRowN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    //void SetIneRowN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);//xx
    virtual void SetLineN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    virtual void SetLineN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);//xx
    virtual void SetColumnN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    virtual void SetColumnN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);//xx
    //
    //virtual void AddExtRowN(T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    //void AddExtRowN(T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);//xx
    //virtual void AddIneRowN(T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    //void AddIneRowN(T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);//xx
    virtual void AddLineN(T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    virtual void AddLineN(T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);//xx
    virtual void AddColumnN( T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    virtual void AddColumnN(T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0,int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);//xx
    //
    //virtual void InsExtRowN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    //void InsExtRowN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);//xx;
    //virtual void InstIneRowN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    //void InsIneRowN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);//xx;
    virtual void InsLineN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    virtual void InsLineN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);//xx;
    virtual void InsColumnN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    virtual void InsColumnN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);//xx;
    //
    //virtual void DelExtRowN(int N, T DefaultVal, const TDataShiftParams&DataShiftParams, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    //virtual void DelExtRowN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL,  int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    //virtual void DelIneRowN(int N, T DefaultVal, const TDataShiftParams&DataShiftParams,  int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    //virtual void DelIneRowN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL,  int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    virtual void DelLineN(int N, T DefaultVal, const TDataShiftParams&DataShiftParams,  int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    virtual void DelLineN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL,  int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    virtual void DelColumnN(int N, T DefaultVal, const TDataShiftParams&DataShiftParams,  int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    virtual void DelColumnN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    //
    //virtual std::vector<T> GetExtRowN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL)=0;
    //virtual std::vector<T> GetIneRowN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL)=0;
    virtual std::vector<T> GetLineN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL)=0;
    virtual std::vector<T> GetColumnN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL)=0;
    //
    //virtual void AddToExtRowN(int N, const T&val, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    //virtual void InsToExtRowN(int ExtRowN, const T&val, int PosN, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    //virtual void DelFromExtRowN(int ExtRowN, int PosN, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1)=0;
    //
    //
    //virtual void Transpose()=0;
    //
    //
    //virtual std::vector<std::vector<int>> SeekVal(const T&val)=0;
    //
    //virtual bool ExtSubRowIsAtPos(T*row, int rowL, int ExtRowN, int IneRowN, bool isReversed=false)=0;
    //virtual bool IneSubRowIsAtPos(T*row, int rowL, int ExtRowN, int IneRowN, bool isReversed=false)=0;
    virtual bool ExtSubLineIsAtPos(T*row, int rowL, int LineN, int ColN, bool isReversed=false)=0;
    virtual bool IneSubColIsAtPos(T*row, int rowL, int LineN, int ColN, bool isReversed=false)=0;
    //virtual std::vector<std::vector<int>> SeekExtSubRow(T*row, int rowL, int ExtRowN, int IneRowN, bool isReversed=false)=0;
    //virtual std::vector<std::vector<int>> SeekIneSubRow(T*row, int rowL, int ExtRowN, int IneRowN, bool isReversed=false)=0;
    virtual std::vector<std::vector<int>> SeekSubLine(T*row, int rowL, int LineN, int ColN, bool isReversed=false)=0;
    virtual std::vector<std::vector<int>> SeekSubCol(T*row, int rowL, int LineN, int ColN, bool isReversed=false)=0;
    //
    //virtual bool SubArrIsAtPos_EIR(Array2D_Prototype_LC*obj, int ExtRowN, int IneRowN, bool isTransposed=false, bool ExtRowsSuccIsReversed=false, bool EachExtRowIsReversed=false)=0;
    virtual bool SubArrIsAtPos_LC(Array2D_Prototype_LC*obj, int LineN, int ColN, bool isTransposed=false, bool ExtRowsSuccIsReversed=false, bool EachExtRowIsReversed=false)=0;
    //virtual std::vector<std::vector<int>> SeekSubArr_EIR(Array2D_Prototype_LC*obj, bool isTransposed=false, bool ExtRowsSuccIsReversed=false, bool EachExtRowIsReversed=false)=0;
    virtual std::vector<std::vector<int>> SeekSubArr_LC(Array2D_Prototype_LC*obj, bool isTransposed=false, bool ExtRowsSuccIsReversed=false, bool EachExtRowIsReversed=false)=0;
    //
    //
    //virtual void ConcatAdding(Array2D_Prototype_LC*obj, T DefaultVal, TDataShiftParams*dsp=NULL)=0;
    //virtual void ConcatAdding(Array2D_Prototype_LC*obj, TDataShiftParams*dsp=NULL, T*dfltVal=NULL)=0;
    //virtual void ConcatStretching(Array2D_Prototype_LC*obj, T DefaultVal, TDataShiftParams*dsp=NULL, int ifNotRect_Ignore0AddToLast1StretchToMax2=1)=0;
    //virtual void ConcatStretching(Array2D_Prototype_LC*obj, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int ifNotRect_Ignore0AddToLast1StretchToMax2=1)=0;
    //
    //
    //void ShowToConsole(std::string delimElem=", ", std::string delimRow="; ", bool as2DNot1D=true, bool ShowBrackets=false);
};//Array2D_Prototype_LC



template<typename T> T Array2D_Prototype_LC<T>::GetElement_LC_asVal(int LineN, int ColN){
    T val;
    int ExtRowN, IneRowN;
    ExtRowN=LineN;
    IneRowN=ColN;
    val=this->GetElement_EIR_asVal(ExtRowN, IneRowN);
    return val;
}
template<typename T> T* Array2D_Prototype_LC<T>::GetElement_LC_asPtr(int LineN, int ColN){
    T* ptr;
    int ExtRowN, IneRowN;
    ExtRowN=LineN;
    IneRowN=ColN;
    ptr=this->GetElement_EIR_asPtr(ExtRowN, IneRowN);
    return ptr;
}
template<typename T> void Array2D_Prototype_LC<T>::SetElement_LC(T val, int LineN, int ColN){
    int ExtRowN=LineN, IneRowN=ColN;
    this->SetElement_EIR(val, ExtRowN, IneRowN);
}
template<typename T> int Array2D_Prototype_LC<T>::GetQLines(){
    return this->GetQExtRows();
}
template<typename T> int Array2D_Prototype_LC<T>::GetQColumns(){
    return this->GetQExtRows();
}

template<typename T> int Array2D_Prototype_LC<T>::GetLineLength(int N){
    int ERL=0, ERN=N;
    ERL=this->GetRowLength(ERN);
    return ERL;
}
template<typename T> int Array2D_Prototype_LC<T>::GetColumnLength(int N){
    int IRL=0, IRN=N;
    IRL=this->GetQExtRows();
    return IRL;
}
template<typename T> void Array2D_Prototype_LC<T>::SetSize_LC(const Array2DSize_Rectangular*size){
    Array2DSize_Shell size_LC;
    size_LC.Assign(size);
    this->SetSize_EIR(size_LC);
}
 void Array2D_Prototype_LC<T>::SetSize_LC(int QLines, int QColumns){
    int QExtRows=Qlines, ExtRowsL=QColumns;
    Array2DSize_Shell size_LC(ExtRowsL, QExtRows);
    size_LC.Set(extRowsL,QExtRows);//S'exnot ma n'irr
    this->SetSize_EIR(size_LC);
}
template<typename T> std::vector<T> Array2D_Prototype_LC<T>::GetData_As1D_AsLinesSucc(){
    return this->GetData_As1D_AsExtRowsSucc();
}
template<typename T> std::vector<T> Array2D_Prototype_LC<T>::GetData_As1D_AsColumnsSucc(){
    T val;
    int QColumns=this->GetQColumns(), curL;
    std::vector<T> R, Col;
    if(this->IsForTranspose()){
        for(int i=1; i<=QColumns; i++){
            Col=this->GetColumnN(N,dsp, dfltVal);
            curL=this->GetColumnLength(i);
            for(int j=1; j<=curL; j++){
                val=Col[j-1];
                R.push_back(val);
            }
        }
    }
    return R;//if !IsForTranspose() - returns empty Vector
}
template<typename T> std::vector<std::vector<T>> Array2D_Prototype_LC<T>::GetData_2DVect_LC(){
    return this-> GetData_2DVect_EIR();
}
template<typename T> std::vector<std::vector<T>> Array2D_Prototype_LC<T>::GetData_2DVect_CL(){
    std::vector<std::vector<T>>R;
    std::vector<T> Col;
    T val;
    int QColumns=this->GetQColumns(), curL;
    if(this->IsForTranspose()){
        for(int i=1; i<=QColumns; i++){
            Col=this->GetColumnN(N,dsp, dfltVal);
            curL=this->GetColumnLength(i);
            for(int j=1; j<=curL; j++){
                val=Col[j-1];
                R.push_back(Col);
            }
        }
    }
    return R;//if !IsForTranspose() - returns empty Vector
}




template<typename T> std::vector<T> Array2D_Prototype_LC<T>::GetColumnN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL){
     T val;
     int IneRowN=N;
     std::vector<T> Col;
     Col=this->GetIneRowN(IneRowN, dsp, dfltVal);
     return Col;
 }

template<typename T> void Array2D_Prototype_LC<T>::Set_IfGivenLC(T**data, const Array2DSize_Shell&size){
    this->Set_IfGivenEIR(data, size);
}
template<typename T> void Array2D_Prototype_LC<T>::Set_IfGivenLC(T**data, int QLines, int QColumns){
    Array2DSize_Shell size(QLines, QColumns);
    this->SSet_IfGivenLC(data, size);
}
template<typename T> void Array2D_Prototype_LC<T>::Set_IfGivenCL(T**data, const Array2DSize_Shell&size){
    T val;
    Array2DSize_Shell sizeThisNew=size;
    std::vector<T>Line, Col;
    int QLines, QColumns=size.GetQExtRows(), curL;
    if(size.IsForTranspose()){
        sizeThisNew.Transpose();
        this->SetSize_EIR(sizeThisNew);
        for(int i=1; i<=QColumns; i++){
            curL=size.GetRowLength(i);
            for(int j=1; j<=curL; j++){
                val=data[i-1][j-1];
                this->SetElement_EIR(val, j, i);
            }
        }
    }
}
template<typename T> void Array2D_Prototype_LC<T>::Set_IfGivenCL(T**data, const Array2DSize_Shell&size){
    Array2DSize_Shell size(QLines, QColumns);
    this->SSet_IfGivenCL(data, size);
}
//
template<typename T> void Array2D_Prototype_LC<T>::Set_IfGivenLC(T*data, const Array2DSize_Shell&size){
    this->Set_IfGivenEIR(data, size);
}
template<typename T> void Array2D_Prototype_LC<T>::Set_IfGivenLC(T*data, int QLines, int QColumns){
    Array2DSize_Shell size(QLines, QColumns);
    this->SSet_IfGivenLC(data, size);
}
template<typename T> void Array2D_Prototype_LC<T>::Set_IfGivenCL(T*data, const Array2DSize_Shell&size){
    int QExtRows=size.GetQExtRows(), curL, QColumns=QExtRows, n=0, PosN;
    T val;
    Array2DSize_Shell sizeThisNew=size;
    if(size.IsForTranspose()){
        sizeThisNew.Transpose();
        this->SetSize_EIR(sizeThisNew);
        for(int i=1; i<=QColuns; i++){
            curL=size.GetRowLength(i);
            for(int j=1; j<=curL; j++){
                PosN=n+j;
                val=data[PosN-1];
                this->SetElement_EIR(val, j, i);
            }
            n+=curL;
        }
    }
}
template<typename T> void Array2D_Prototype_LC<T>::Set_IfGivenCL(T*data, int QLines, int QColumns){
    Array2DSize_Shell size(QColumns, QLines), sizeThisNew(QLines, QColumns);
    this->Set_IfGivenCL(data, size);
}
template<typename T> void Array2D_Prototype_LC<T>::Set_IfGivenLC(std::vector<std::vector<T>>data, bool RectByTypeIfInFact){
    Array2DSize_Shell size= GetSizeOfVector2D(data);
    this->Set_IfGivenEIR(data, RectByTypeIfInFact);
}
template<typename T> void Array2D_Prototype_LC<T>::Set_IfGivenCL(std::vector<std::vector<T>>data, bool RectByTypeIfInFact){
    Array2DSize_Shell size1=GetSizeOfVector2D(data), size2;
    T val;
    int QExtRowsGiven=size1.GetQExtRows, QExtRowsReceived=size1.GetRowLength(1), curL;
    size1.Transpose();
    size2=size1;
    size1.Transpose();//back
    if(size1.IsForTranspose()){
        this->SetSize_EIR(size2);
        for(int ERN=1; ERN<=QExtRowsGiven; ERN++){
            curL=size1.GetRowLength(ERN);
            for(intIERN=1; IRN<=curL; IRN++){
                curL=size1.GetRowLength(ERN);
                val=data[ERN-1][IRN-1];
                this->SetElement_EIR(val, IRN, ERN);
           }
       }
   }
}
//
template<typename T> void Array2D_Prototype_LC<T>::Set_SelectedRare_LC(std::vector<Array2DElement<T>>data, T DefaultVal, int SetFull0Append1){
    std::vector<int>ERNs,IRNs;

}

//================================

template<class T> class Array2D_By1D_LC_Rare:Array2D_Prototype_LC<T>{
    //T*data;
    T*dflt;
    //Coords2DInt*coords;
    std::vector<Array2DElement<T>>data;
    Array2DSize_Prototype size;
  public:
    //
    Array2D_By1D_LC_Rare(T**data, const Array2DSize_Shell&size);
    Array2D_By1D_LC_Rare(T**data, int QRows, int*RowsL, int EIR1LC2CL3=1);
    Array2D_By1D_LC_Rare(T**data, int QRows, int RowsL, int EIR1LC2CL3=1);
    //
    Array2D_By1D_LC_Rare(std::vector<std::vector<T>>data, bool RectByTypeIfInFact=true, int EIR1LC2CL3=1);
    //
    ~Array2D_By1D_LC_Rare();
    //
    //
    virtual void construct();
    virtual void SetNull();
    virtual void SetNullIni();
    //void SetOne(const T& DefaultVal);//in prototype
    //void SetOne(T*dfltValParam=NULL);//in prototype
    //
    //
    virtual T GetElement_EIR_asVal(int ExtRowN, int IneRowN);
    virtual T GetElement_LC_asVal(int LineN, int ColN);
    virtual T*GetElement_EIR_asPtr(int ExtRowN, int IneRowN);
    virtual T*GetElement_LC_asPtr(int LineN, int ColN);
    virtual  void SetElement_EIR(T val, int ExtRowN, int IneRowN);
    virtual void SetElement_LC(T val, int LineN, int ColN);
    //
    virtual int GetTypeN();
    virtual int GetQElements();
    virtual void Assign(Array2D_Prototype_LC<T>*obj);
    //
    //
    virtual int GetQExtRows();
    virtual int GetRowLength(int N=-1);
    //int GetRowLengthMin();
    // int GetRowLengthMax();
    virtual int GetQLines();
    virtual int GetQColumns();
    virtual int GetFullLengthOfIneRowN_FromStartNoBreaks();
    virtual std::vector<int>GetRowsLengthes();
    //
    //virtual bool IsForTranspose();//in prototype
    //
    virtual Array2DSize_Shell GetSize();
    virtual Array2DSize_Prototype*GetSize_asPtr();
    virtual void SetSize_EIR(const Array2DSize_Shell&size);
    //virtual void SetSize_EIR(int QExtRows, int*RowsL);//in prototype
    //virtual void SetSize_EIR(int QExtRows, int RowsL);//in prototype
    virtual void SetSize_LC(const Array2DSize_Rectangular*size);
    //virtual void SetSize_LC(int QLines, int QColumns);//in prototype
    //
    //
    //std::vector<T> GetData_As1D_AsExtRowsSucc();//in prototype
    //std::vector<T> GetData_As1D_AsLinesSucc();//in prototype
    //std::vector<T> GetData_As1D_AsColumnsSucc();//in prototype
    //std::vector<std::vector<T>> GetData_2DVect_EIR();//in prototype
    //std::vector<std::vector<T>> GetData_2DVect_LC();//in prototype
    //std::vector<std::vector<T>> GetData_2DVect_CL();//in prototype
    //
    //void Set_IfGivenEIR(T**data, const Array2DSize_Shell&size);
    //void Set_IfGivenEIR(T**data, int QExtRows, int*RowsL);//in prototype
    //void Set_IfGivenEIR(T**data, int QExtRows, int RowsL);//in prototype
    //
    virtual void Set_IfGivenLC(T**data, const Array2DSize_Shell&size);
    //void Set_IfGivenLC(T**data, int QLines, int QColumns);//in prototype
    //
    virtual void Set_IfGivenCL(T**data, const Array2DSize_Shell&size);
    //void Set_IfGivenCL(T**data, int QLines, int QColumns);//in prototype
    //
    //void Set_IfGivenEIR(T*data, const Array2DSize_Shell&size);
    //void Set_IfGivenEIR(T*data, int QExtRows, int*RowsL);//in prototype
    //void Set_IfGivenEIR(T*data, int QExtRows, int RowsL);//in prototype
    //
    virtual void Set_IfGivenLC(T*data, const Array2DSize_Shell&size);
    //void Set_IfGivenLC(T*data, int QLines, int QColumns);//in prototype
    //
    virtual void Set_IfGivenCL(T*data, const Array2DSize_Shell&size);
    //void Set_IfGivenCL(T*data, int QLines, int QColumns);//in prototype
    //
    virtual void Set_IfGivenEIR(std::vector<std::vector<T>>data, bool RectByTypeIfInFact=true);
    virtual void Set_IfGivenLC(std::vector<std::vector<T>>data, bool RectByTypeIfInFact=true);
    virtual void Set_IfGivenCL(std::vector<std::vector<T>>data, bool RectByTypeIfInFact=true);
    //
    //
    virtual void Set_SelectedRare_EIR(int QVals, T*vals, Coords2DInt*coords, T*dfltVal=NULL, int SetSize_ByMaxOfGivenCoords=0);
    virtual void Set_SelectedRare_LC(int QVals, T*vals, Coords2DInt*coords, T*dfltVal=NULL, int SetSize_ByMaxOfGivenCoords=0);
    virtual void Set_SelectedRare_EIR(int QVals, T*vals, int*x, int*y, T*dfltVal=NULL, int SetSize_ByMaxOfGivenCoords=0);
    virtual void Set_SelectedRare_LC(int QVals, T*vals, int*x, int*y, T*dfltVal=NULL, int SetSize_ByMaxOfGivenCoords=0);
    //
    //
    virtual void SwapVals_EIR(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
    virtual void SwapVals_LC(int LineN1, int ColN1, int LineN2, int ColN2);
    virtual void ReverseExtRows();
    virtual void ReverseExtRowN(int ExtRowN);
    virtual void ReverseIneRows();
    virtual void ReverseIneRowN(int IneRowN);
    virtual void ReverseLines();
    virtual void ReverseLineN(int LineN);
    virtual void ReverseColumns();
    virtual void ReverseColumnN(int ColN);
    //
    //
    virtual void SetExtRowN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void SetExtRowN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void SetIneRowN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void SetIneRowN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void SetLineN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void SetLineN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void SetColumnN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void SetColumnN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    //
    virtual void AddExtRowN(T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void AddExtRowN(T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void AddIneRowN(T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void AddIneRowN(T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void AddLineN(T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void AddLineN(T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void AddColumnN( T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void AddColumnN(T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0,int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    //
    virtual void InsExtRowN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void InsExtRowN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void InstIneRowN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void InsIneRowN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void InsLineN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void InsLineN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void InsColumnN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void InsColumnN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    //
    virtual void DelExtRowN(int N, T DefaultVal, const TDataShiftParams&DataShiftParams, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void DelExtRowN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL,  int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void DelIneRowN(int N, T DefaultVal, const TDataShiftParams&DataShiftParams,  int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void DelIneRowN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL,  int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void DelLineN(int N, T DefaultVal, const TDataShiftParams&DataShiftParams,  int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void DelLineN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL,  int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void DelColumnN(int N, T DefaultVal, const TDataShiftParams&DataShiftParams,  int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void DelColumnN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    //
    virtual std::vector<T> GetExtRowN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL);
    virtual std::vector<T> GetIneRowN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL);
    virtual std::vector<T> GetLineN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL);
    virtual std::vector<T> GetColumnN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL);
    //
    virtual void AddToExtRowN(int N, const T&val, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void InsToExtRowN(int ExtRowN, const T&val, int PosN, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void DelFromExtRowN(int ExtRowN, int PosN, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    //
    //
    virtual void Transpose();
    //
    //
    virtual std::vector<std::vector<int>> SeekVal(const T&val);
    //
    virtual bool ExtSubRowIsAtPos(T*row, int rowL, int ExtRowN, int IneRowN, bool isReversed=false);
    virtual bool IneSubRowIsAtPos(T*row, int rowL, int ExtRowN, int IneRowN, bool isReversed=false);
    virtual bool ExtSubLineIsAtPos(T*row, int rowL, int LineN, int ColN, bool isReversed=false);
    virtual bool IneSubColIsAtPos(T*row, int rowL, int LineN, int ColN, bool isReversed=false);
    virtual std::vector<std::vector<int>> SeekExtSubRow(T*row, int rowL, int ExtRowN, int IneRowN, bool isReversed=false);
    virtual std::vector<std::vector<int>> SeekIneSubRow(T*row, int rowL, int ExtRowN, int IneRowN, bool isReversed=false);
    virtual std::vector<std::vector<int>> SeekSubLine(T*row, int rowL, int LineN, int ColN, bool isReversed=false);
    virtual std::vector<std::vector<int>> SeekSubCol(T*row, int rowL, int LineN, int ColN, bool isReversed=false);
    //
    virtual bool SubArrIsAtPos_EIR(Array2D_Prototype_LC<T>*obj, int ExtRowN, int IneRowN, bool isTransposed=false, bool ExtRowsSuccIsReversed=false, bool EachExtRowIsReversed=false);
    virtual bool SubArrIsAtPos_LC(Array2D_Prototype_LC<T>*obj, int LineN, int ColN, bool isTransposed=false, bool ExtRowsSuccIsReversed=false, bool EachExtRowIsReversed=false);
    virtual std::vector<std::vector<int>> SeekSubArr_EIR(Array2D_Prototype_LC<T>*obj, bool isTransposed=false, bool ExtRowsSuccIsReversed=false, bool EachExtRowIsReversed=false);
    virtual std::vector<std::vector<int>> SeekSubArr_LC(Array2D_Prototype_LC<T>*obj, bool isTransposed=false, bool ExtRowsSuccIsReversed=false, bool EachExtRowIsReversed=false);
    //
    //
    virtual void ConcatAdding(Array2D_Prototype_LC<T>*obj, T DefaultVal, TDataShiftParams*dsp=NULL);
    virtual void ConcatAdding(Array2D_Prototype_LC<T>*obj, TDataShiftParams*dsp=NULL, T*dfltVal=NULL);
    virtual void ConcatStretching(Array2D_Prototype_LC<T>*obj, T DefaultVal, TDataShiftParams*dsp=NULL, int ifNotRect_Ignore0AddToLast1StretchToMax2=1);
    virtual void ConcatStretching(Array2D_Prototype_LC<T>*obj, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int ifNotRect_Ignore0AddToLast1StretchToMax2=1);
};//Array2D_By1D_LC_Rare

template<class T> class Array2D_By1D_LC_stdVectSafe_Rect:Array2D_Prototype_LC<T>{
    std::vector<T>data;
    int QExtRows;
  public:
    //
    Array2D_By1D_LC_stdVectSafe_Rect(T**data, const Array2DSize_Shell&size);
    Array2D_By1D_LC_stdVectSafe_Rect(T**data, int QRows, int*RowsL, int EIR1LC2CL3=1);
    Array2D_By1D_LC_stdVectSafe_Rect(T**data, int QRows, int RowsL, int EIR1LC2CL3=1);
    Array2D_By1D_LC_stdVectSafe_Rect(T*data, const Array2DSize_Shell&size);
    Array2D_By1D_LC_stdVectSafe_Rect(T*data, int QRows, int*RowsL, int EIR1LC2CL3=1);
    Array2D_By1D_LC_stdVectSafe_Rect(T*data, int QRows, int RowsL, int EIR1LC2CL3=1);
    //
    Array2D_By1D_LC_stdVectSafe_Rect(std::vector<std::vector<T>>data, bool RectByTypeIfInFact=true, int EIR1LC2CL3=1);
    //
    //
    virtual T GetElement_EIR_asVal(int ExtRowN, int IneRowN);
    virtual T GetElement_LC_asVal(int LineN, int ColN);
    virtual T*GetElement_EIR_asPtr(int ExtRowN, int IneRowN);
    virtual T*GetElement_LC_asPtr(int LineN, int ColN);
    virtual  void SetElement_EIR(T val, int ExtRowN, int IneRowN);
    virtual void SetElement_LC(T val, int LineN, int ColN);
    //
    virtual int GetTypeN();
    virtual int GetQElements();
    virtual void Assign(Array2D_Prototype_LC<T>*obj);
    //
    //
    virtual int GetQExtRows();
    virtual int GetRowLength(int N=-1);
    virtual int GetRowLengthMin();
    virtual int GetRowLengthMax();
    virtual int GetQLines();
    virtual int GetQColumns();
    virtual int GetFullLengthOfIneRowN_FromStartNoBreaks();
    virtual std::vector<int>GetRowsLengthes();
    //
    virtual bool IsForTranspose();
    //
    virtual Array2DSize_Shell GetSize();
    virtual Array2DSize_Prototype*GetSize_asPtr();
    virtual void SetSize_EIR(const Array2DSize_Shell&size);
    virtual void SetSize_EIR(int QExtRows, int*RowsL);
    virtual void SetSize_EIR(int QExtRows, int RowsL);
    virtual void SetSize_LC(const Array2DSize_Rectangular*size);
    virtual void SetSize_LC(int QLines, int QColumns);
    //
    //
    virtual std::vector<T> GetData_As1D_AsExtRowsSucc();
    virtual std::vector<T> GetData_As1D_AsLinesSucc();
    virtual std::vector<T> GetData_As1D_AsColumnsSucc();
    virtual std::vector<std::vector<T>> GetData();
    //
    //void Set_IfGivenEIR(T**data, const Array2DSize_Shell&size);
    //void Set_IfGivenEIR(T**data, int QExtRows, int*RowsL);
    //void Set_IfGivenEIR(T**data, int QExtRows, int RowsL);
    //
    virtual void Set_IfGivenLC(T**data, const Array2DSize_Shell&size);
    /// void Set_IfGivenLC(T**data, int QLines, int QColumns);
    //
    virtual void Set_IfGivenCL(T**data, const Array2DSize_Shell&size);
    //void Set_IfGivenCL(T**data, int QLines, int QColumns);
    //
    //void Set_IfGivenEIR(T*data, const Array2DSize_Shell&size);
    //void Set_IfGivenEIR(T*data, int QExtRows, int*RowsL);
    //void Set_IfGivenEIR(T*data, int QExtRows, int RowsL);
    //
    virtual void Set_IfGivenLC(T*data, const Array2DSize_Shell&size);
    // void Set_IfGivenLC(T*data, int QLines, int QColumns);
    //
    virtual void Set_IfGivenCL(T*data, const Array2DSize_Shell&size);
    // void Set_IfGivenCL(T*data, int QLines, int QColumns);
    //
    virtual void Set_IfGivenEIR(std::vector<std::vector<T>>data, bool RectByTypeIfInFact=true);
    virtual void Set_IfGivenLC(std::vector<std::vector<T>>data, bool RectByTypeIfInFact=true);
    virtual void Set_IfGivenCL(std::vector<std::vector<T>>data, bool RectByTypeIfInFact=true);
    //
    //
    virtual void Set_SelectedRare_EIR(int QVals, T*vals, Coords2DInt*coords, T*dfltVal=NULL, int SetSize_ByMaxOfGivenCoords=0);
    virtual void Set_SelectedRare_LC(int QVals, T*vals, Coords2DInt*coords, T*dfltVal=NULL, int SetSize_ByMaxOfGivenCoords=0);
    virtual void Set_SelectedRare_EIR(int QVals, T*vals, int*x, int*y, T*dfltVal=NULL, int SetSize_ByMaxOfGivenCoords=0);
    virtual void Set_SelectedRare_LC(int QVals, T*vals, int*x, int*y, T*dfltVal=NULL, int SetSize_ByMaxOfGivenCoords=0);
    //
    //
    virtual void SwapVals_EIR(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
    virtual void SwapVals_LC(int LineN1, int ColN1, int LineN2, int ColN2);
    virtual void ReverseExtRows();
    virtual void ReverseExtRowN(int ExtRowN);
    virtual void ReverseIneRows();
    virtual void ReverseIneRowN(int IneRowN);
    virtual void ReverseLines();
    virtual void ReverseLineN(int LineN);
    virtual void ReverseColumns();
    virtual void ReverseColumnN(int ColN);
    //
    //
    virtual void SetExtRowN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void SetExtRowN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void SetIneRowN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void SetIneRowN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void SetLineN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void SetLineN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void SetColumnN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void SetColumnN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    //
    virtual void AddExtRowN(T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void AddExtRowN(T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void AddIneRowN(T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void AddIneRowN(T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void AddLineN(T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void AddLineN(T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void AddColumnN( T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void AddColumnN(T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0,int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    //
    virtual void InsExtRowN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void InsExtRowN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void InstIneRowN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void InsIneRowN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void InsLineN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void InsLineN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void InsColumnN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void InsColumnN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    //
    virtual void DelExtRowN(int N, T DefaultVal, const TDataShiftParams&DataShiftParams, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void DelExtRowN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL,  int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void DelIneRowN(int N, T DefaultVal, const TDataShiftParams&DataShiftParams,  int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void DelIneRowN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL,  int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void DelLineN(int N, T DefaultVal, const TDataShiftParams&DataShiftParams,  int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void DelLineN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL,  int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void DelColumnN(int N, T DefaultVal, const TDataShiftParams&DataShiftParams,  int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void DelColumnN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    //
    virtual std::vector<T> GetExtRowN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL);
    virtual std::vector<T> GetIneRowN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL);
    virtual std::vector<T> GetLineN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL);
    virtual std::vector<T> GetColumnN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL);
    //
    virtual void AddToExtRowN(int N, const T&val, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void InsToExtRowN(int ExtRowN, const T&val, int PosN, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    virtual void DelFromExtRowN(int ExtRowN, int PosN, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    //
    //
    virtual void Transpose();
    //
    //
    virtual std::vector<std::vector<int>> SeekVal(const T&val);
    //
    virtual bool ExtSubRowIsAtPos(T*row, int rowL, int ExtRowN, int IneRowN, bool isReversed=false);
    virtual bool IneSubRowIsAtPos(T*row, int rowL, int ExtRowN, int IneRowN, bool isReversed=false);
    virtual bool ExtSubLineIsAtPos(T*row, int rowL, int LineN, int ColN, bool isReversed=false);
    virtual bool IneSubColIsAtPos(T*row, int rowL, int LineN, int ColN, bool isReversed=false);
    virtual std::vector<std::vector<int>> SeekExtSubRow(T*row, int rowL, int ExtRowN, int IneRowN, bool isReversed=false);
    virtual std::vector<std::vector<int>> SeekIneSubRow(T*row, int rowL, int ExtRowN, int IneRowN, bool isReversed=false);
    virtual std::vector<std::vector<int>> SeekSubLine(T*row, int rowL, int LineN, int ColN, bool isReversed=false);
    virtual std::vector<std::vector<int>> SeekSubCol(T*row, int rowL, int LineN, int ColN, bool isReversed=false);
    //
    virtual bool SubArrIsAtPos_EIR(Array2D_Prototype_LC<T>*obj, int ExtRowN, int IneRowN, bool isTransposed=false, bool ExtRowsSuccIsReversed=false, bool EachExtRowIsReversed=false);
    virtual bool SubArrIsAtPos_LC(Array2D_Prototype_LC<T>*obj, int LineN, int ColN, bool isTransposed=false, bool ExtRowsSuccIsReversed=false, bool EachExtRowIsReversed=false);
    virtual std::vector<std::vector<int>> SeekSubArr_EIR(Array2D_Prototype_LC<T>*obj, bool isTransposed=false, bool ExtRowsSuccIsReversed=false, bool EachExtRowIsReversed=false);
    virtual std::vector<std::vector<int>> SeekSubArr_LC(Array2D_Prototype_LC<T>*obj, bool isTransposed=false, bool ExtRowsSuccIsReversed=false, bool EachExtRowIsReversed=false);
    //
    //
    virtual void ConcatAdding(Array2D_Prototype_LC<T>*obj, T DefaultVal, TDataShiftParams*dsp=NULL);
    virtual void ConcatAdding(Array2D_Prototype_LC<T>*obj, TDataShiftParams*dsp=NULL, T*dfltVal=NULL);
    virtual void ConcatStretching(Array2D_Prototype_LC<T>*obj, T DefaultVal, TDataShiftParams*dsp=NULL, int ifNotRect_Ignore0AddToLast1StretchToMax2=1);
    virtual void ConcatStretching(Array2D_Prototype_LC<T>*obj, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int ifNotRect_Ignore0AddToLast1StretchToMax2=1);
};//Array2D_By1D_LC_stdVectSafe_Rect

// ==========================================

template<class T> class Array2D_Shell{
    Array2D_Prototype<T>*data;
  public:
    Array2D_Shell(T**data, const Array2DSize_Shell&size);
    Array2D_Shell(T**data, int QRows, int*RowsL, int EIR1LC2CL3=1);
    Array2D_Shell(T**data, int QRows, int RowsL, int EIR1LC2CL3=1);
    //
    Array2D_By1D_LC_Ptr(std::vector<std::vector<T>>data, bool RectByTypeIfInFact=true, int EIR1LC2CL3=1);
    //
    Array2D_Shell(const Array2D_Shell&obj);
    //
    //
    T GetElement_EIR_asVal(int ExtRowN, int IneRowN);
    T GetElement_LC_asVal(int LineN, int ColN);
    T*GetElement_EIR_asPtr(int ExtRowN, int IneRowN);
    T*GetElement_LC_asPtr(int LineN, int ColN);
    void SetElement_EIR(T val, int ExtRowN, int IneRowN);
    void SetElement_LC(T val, int LineN, int ColN);
    //
    int GetTypeN();
    int GetQElements();
    void Assign(Array2D_Prototype<T>*obj);
    void Assign(const Array2D_Shell&obj);
    Array2D_Shell&operator = (const Array2D_Shell&obj);
    //
    //
    int GetQExtRows();
    int GetRowLength(int N=-1);
    int GetRowLengthMin();
    int GetRowLengthMax();
    int GetQLines();
    int GetQColumns();
    int GetFullLengthOfIneRowN_FromStartNoBreaks();
    std::vector<int> GetRowsLengthes();
    //
    bool IsForTranspose();
    //
    Array2DSize_Shell GetSize();
    Array2DSize_Prototype*GetSize_asPtr();
    void SetSize_EIR(const Array2DSize_Shell&size);
    void SetSize_EIR(int QExtRows, int*RowsL);
    void SetSize_EIR(int QExtRows, int RowsL);
    void SetSize_LC(const Array2DSize_Rectangular*size);
    void SetSize_LC(int QLines, int QColumns);
    //
    //
    std::vector<T> GetData_As1D_AsExtRowsSucc();
    std::vector<T> GetData_As1D_AsLinesSucc();
    std::vector<T> GetData_As1D_AsColumnsSucc();
    std::vector<std::vector<T>> GetData();
    //
    //
    void Set_IfGivenEIR(T**data, const Array2DSize_Shell&size);
    void Set_IfGivenEIR(T**data, int QExtRows, int*RowsL);
    void Set_IfGivenEIR(T**data, int QExtRows, int RowsL);
    //
    void Set_IfGivenLC(T**data, const Array2DSize_Shell&size);
    void Set_IfGivenLC(T**data, int QLines, int QColumns);
    //
    void Set_IfGivenCL(T**data, const Array2DSize_Shell&size);
    void Set_IfGivenCL(T**data, int QLines, int QColumns);
    //
    void Set_IfGivenEIR(T*data, const Array2DSize_Shell&size);
    void Set_IfGivenEIR(T*data, int QExtRows, int*RowsL);
    void Set_IfGivenEIR(T*data, int QExtRows, int RowsL);
    //
    void Set_IfGivenLC(T*data, const Array2DSize_Shell&size);
    void Set_IfGivenLC(T*data, int QLines, int QColumns);
    //
    void Set_IfGivenCL(T*data, const Array2DSize_Shell&size);
    void Set_IfGivenCL(T*data, int QLines, int QColumns);
    //
    void Set_IfGivenEIR(std::vector<std::vector<T>>data, bool RectByTypeIfInFact=true);
    void Set_IfGivenLC(std::vector<std::vector<T>>data, bool RectByTypeIfInFact=true);
    void Set_IfGivenCL(std::vector<std::vector<T>>data, bool RectByTypeIfInFact=true);
    //
    //
    void Set_SelectedRare_EIR(int QVals, T*vals, Coords2DInt*coords, T*dfltVal=NULL, int SetSize_ByMaxOfGivenCoords=0);
    void Set_SelectedRare_LC(int QVals, T*vals, Coords2DInt*coords, T*dfltVal=NULL, int SetSize_ByMaxOfGivenCoords=0);
    void Set_SelectedRare_EIR(int QVals, T*vals, int*x, int*y, T*dfltVal=NULL, int SetSize_ByMaxOfGivenCoords=0);
    void Set_SelectedRare_LC(int QVals, T*vals, int*x, int*y, T*dfltVal=NULL, int SetSize_ByMaxOfGivenCoords=0);
    //
    //
    void SwapVals_EIR(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
    void SwapVals_LC(int LineN1, int ColN1, int LineN2, int ColN2);
    void ReverseExtRows();
    void ReverseExtRowN(int ExtRowN);
    void ReverseIneRows();
    void ReverseIneRowN(int IneRowN);
    void ReverseLines();
    void ReverseLineN(int LineN);
    void ReverseColumns();
    void ReverseColumnN(int ColN);
    //
    //
    void SetExtRowN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void SetExtRowN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void SetIneRowN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void SetIneRowN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void SetLineN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void SetLineN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void SetColumnN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void SetColumnN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    //
    void AddExtRowN(T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void AddExtRowN(T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void AddIneRowN(T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void AddIneRowN(T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void AddLineN(T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void AddLineN(T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void AddColumnN( T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void AddColumnN(T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0,int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    //
    void InsExtRowN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void InsExtRowN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void InstIneRowN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void InsIneRowN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void InsLineN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void InsLineN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void InsColumnN(int N, T*x, T DefaultVal, const TDataShiftParams&DataShiftParams, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void InsColumnN(int N, T*x, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int newRowL=0, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    //
    void DelExtRowN(int N, T DefaultVal, const TDataShiftParams&DataShiftParams, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void DelExtRowN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL,  int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void DelIneRowN(int N, T DefaultVal, const TDataShiftParams&DataShiftParams,  int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void DelIneRowN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL,  int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void DelLineN(int N, T DefaultVal, const TDataShiftParams&DataShiftParams,  int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void DelLineN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL,  int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void DelColumnN(int N, T DefaultVal, const TDataShiftParams&DataShiftParams,  int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void DelColumnN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    //
    std::vector<T> GetExtRowN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL);
    std::vector<T> GetIneRowN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL);
    std::vector<T> GetLineN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL);
    std::vector<T> GetColumnN(int N, TDataShiftParams*dsp=NULL, T*dfltVal=NULL);
    //
    void AddToExtRowN(int N, const T&val, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void InsToExtRowN(int ExtRowN, const T&val, int PosN, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    void DelFromExtRowN(int ExtRowN, int PosN, int IfRectAndNotEqual_Ignore0_SetNeSizeBy_Old1New2Max3Min4=1);
    //
    //
    void Transpose();
    //
    //
    std::vector<std::vector<int>> SeekVal(const T&val);
    //
    bool ExtSubRowIsAtPos(T*row, int rowL, int ExtRowN, int IneRowN, bool isReversed=false);
    bool IneSubRowIsAtPos(T*row, int rowL, int ExtRowN, int IneRowN, bool isReversed=false);
    bool ExtSubLineIsAtPos(T*row, int rowL, int LineN, int ColN, bool isReversed=false);
    bool IneSubColIsAtPos(T*row, int rowL, int LineN, int ColN, bool isReversed=false);
    std::vector<std::vector<int>> SeekExtSubRow(T*row, int rowL, int ExtRowN, int IneRowN, bool isReversed=false);
    std::vector<std::vector<int>> SeekIneSubRow(T*row, int rowL, int ExtRowN, int IneRowN, bool isReversed=false);
    std::vector<std::vector<int>> SeekSubLine(T*row, int rowL, int LineN, int ColN, bool isReversed=false);
    std::vector<std::vector<int>> SeekSubCol(T*row, int rowL, int LineN, int ColN, bool isReversed=false);
    //
    bool SubArrIsAtPos_EIR(Array2D_Prototype<T>*obj, int ExtRowN, int IneRowN, bool isTransposed=false, bool ExtRowsSuccIsReversed=false, bool EachExtRowIsReversed=false);
    bool SubArrIsAtPos_LC(Array2D_Prototype<T>*obj, int LineN, int ColN, bool isTransposed=false, bool ExtRowsSuccIsReversed=false, bool EachExtRowIsReversed=false);
    std::vector<std::vector<int>> SeekSubArr_EIR(Array2D_Prototype<T>*obj, bool isTransposed=false, bool ExtRowsSuccIsReversed=false, bool EachExtRowIsReversed=false);
    std::vector<std::vector<int>> SeekSubArr_LC(Array2D_Prototype<T>*obj, bool isTransposed=false, bool ExtRowsSuccIsReversed=false, bool EachExtRowIsReversed=false);
    //
    bool SubArrIsAtPos_EIR(const Array2D_Shell<T>&obj, int ExtRowN, int IneRowN, bool isTransposed=false, bool ExtRowsSuccIsReversed=false, bool EachExtRowIsReversed=false);
    bool SubArrIsAtPos_LC(const Array2D_Shell<T>&obj, int LineN, int ColN, bool isTransposed=false, bool ExtRowsSuccIsReversed=false, bool EachExtRowIsReversed=false);
    std::vector<std::vector<int>> SeekSubArr_EIR(const Array2D_Shell<T>&obj, bool isTransposed=false, bool ExtRowsSuccIsReversed=false, bool EachExtRowIsReversed=false);
    std::vector<std::vector<int>> SeekSubArr_LC(const Array2D_Shell<T>&obj, bool isTransposed=false, bool ExtRowsSuccIsReversed=false, bool EachExtRowIsReversed=false);
    //
    //
    void ConcatAdding(Array2D_Prototype<T>*obj, T DefaultVal, TDataShiftParams*dsp=NULL);
    void ConcatAdding(Array2D_Prototype<T>*obj, TDataShiftParams*dsp=NULL, T*dfltVal=NULL);
    void ConcatStretching(Array2D_Prototype<T>*obj, T DefaultVal, TDataShiftParams*dsp=NULL, int ifNotRect_Ignore0AddToLast1StretchToMax2=1);
    void ConcatStretching(Array2D_Prototype<T>*obj, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int ifNotRect_Ignore0AddToLast1StretchToMax2=1);
    //
    void ConcatAdding(const Array2D_Shell<T>&obj, T DefaultVal, TDataShiftParams*dsp=NULL);
    void ConcatAdding(const Array2D_Shell<T>&obj, TDataShiftParams*dsp=NULL, T*dfltVal=NULL);
    void ConcatStretching(const Array2D_Shell<T>&obj, T DefaultVal, TDataShiftParams*dsp=NULL, int ifNotRect_Ignore0AddToLast1StretchToMax2=1);
    void ConcatStretching(const Array2D_Shell<T>&obj, TDataShiftParams*dsp=NULL, T*dfltVal=NULL, int ifNotRect_Ignore0AddToLast1StretchToMax2=1);
};


//=== End =================================================================================

#endif // ARRAYLIB2_H
