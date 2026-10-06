#ifndef MATRICES1_H
#define MATRICES1_H

#include"mylib.h"
#include"mymathlib.h"

//mab in preproc

//class Matrices1
//{
//public:
//    Matrices1();
//};

const int MatrixTypeN_P2L=121;
const int MatrixTypeN_P2I=122;
const int MatrixTypeN_P2A=123;
const int MatrixTypeN_V2L=221;
const int MatrixTypeN_V2I=222;
const int MatrixTypeN_V2A=223;
const int MatrixTypeN_P1L=111;
const int MatrixTypeN_P1I=112;
const int MatrixTypeN_P1A=113;
const int MatrixTypeN_V1L=211;
const int MatrixTypeN_V1I=212;
const int MatrixTypeN_V1A=213;
const int MatrixTypeN_Default=MatrixTypeN_V1I;

class Matrix_Prototype{
public:
    //
    virtual ~Matrix_Prototype()=default;
    //
    virtual void SetNull()=0;
    virtual void construct()=0;
    //virtual Matrix_Prototype* CreateArray() const=0;
    virtual Matrix_Prototype* CreateMatrix() const=0;
    virtual Matrix_Prototype* clone()const=0;
    virtual int GetTypeN() const=0 ;
    virtual void Assign(Matrix_Prototype* obj)=0;
    //
    //void SetOne(double*DfltVal=NULL);
    //void SetOne(double DfltVal);
    void SetOne(double DfltVal=0);
    //
    //virtual void SetLengthOfExtRowN(int ExtRowN, int newL, double DefaultVal=0)=0;//es SetSize f'ce
    //virtual void SetLengthOfExtRowN(int ExtRowN, int newL,double*DefaultValParam=NULL)=0;
    //
    //virtual void SetSize(double DfltValParam, const Array2DSize&size)=0;
    virtual void SetSize_Array(int QExtRows=1, int QIneRows=1, double DefaultVal=0.0)=0;
    virtual void SetSize_Matrix(int QLines=1, int QColumns=1, double DefaultVal=0.0)=0;
    //
    //void SetSize(const Array2DSize&size,double*DfltValParam=NULL);//virtual ob hin Sdo mut l'size data
    //void SetSize(int QExtRows, int ExtRowsLength,double*DfltValParam=NULL);
    //void SetSize(int QExtRows=1, int*ExtRowsLengthes=NULL,double*DfltValParam=NULL);//if Null => L=0
    //void SetSize(std::vector<int>ExtRowsLengthes,double*DfltValParam=NULL);
    //
    //void SetSize(double DfltValParam, int QExtRows, int ExtRowsLength);//virtual ob hin Sdo mut l'size data
    //void SetSize(double DfltValParam, int QExtRows=1, int*ExtRowsLengthes=NULL);//if Null => L=0
    //void SetSize(double DfltValParam, std::vector<int>Lengthes);
    //
    //virtual int GetQExtRows() const=0;
    //virtual int GetLength(int ExtRowN=1) const=0;
    //virtual int GetMinLength() const=0;
    //virtual int GetMaxLength() const=0;
    virtual int GetQExtRows() const=0;
    virtual int GetLength() const=0;
    virtual int GetQLines() const=0;
    virtual int GetQColumns() const=0;
    //
    //virtual Array2DSize GetSize()const =0;
    //
    //bool LineNBelongsHere(int LineN) const;
    //bool ColNBelongsHere(int ColN) const;
    bool NsBelongHere_byEI(int ExtRowN, int IneRowN) const;
    bool NsBelongHere_byLC(int LineN, int ColN) const;
    //
    //std::vector<double> GetArrayOfExtRowN(int LineN);
    //std::vector<double> GetArrayOfIneRowN(int ColN);
    //std::vector<double> GetContentAsArray1D();
    //std::vector<std::vector<double>> GetContentAsArray2D();
    //
    std::vector<double> GetExtRowN_AsArray(int rowN) const;
    //double*GetExtRowN_AsPtr(int ExtRowN) const;
    std::vector<double> GetIneRowN_AsArray(int rowN) const;
    //std::vector<double> GetIneRowN_AsArray(int IneRowN, double defaultVal,                               int ifNGTLmin_Ignore0_DefaultsForShorter1_NurProperL_AnyExtRow2_NurFromStartTillErstStop3=0) const;
    //std::vector<double> GetIneRowN_AsArray(int IneRowN,                     double*DefaultValParam=NULL, int ifNGTLmin_Ignore0_DefaultsForShorter1_NurProperL_AnyExtRow2_NurFromStartTillErstStop3=0) const;
    //std::vector<double> GetContent_AsArray1D() const;
    //std::vector<std::vector<double>> GetContent_AsArray2D() const;
    std::vector<double> GetLineN_AsArray(int N) const;
    std::vector<double> GetColumnN_AsArray(int N) const;
    std::vector<double> GetContent_AsArray1D_ExtRows() const;
    std::vector<std::vector<double>> GetContent_AsArray2D_ExtRows() const;
    std::vector<double> GetContent_AsArray1D_Lines() const;
    std::vector<std::vector<double>> GetContent_AsArray2D_Lines() const;
    //
    //
    //virtual double GetComponent_AsVal(int LineN, int ColN) const=0;
    virtual double GetComponent_AsVal_byEI(int LineN, int ColN) const=0;
    virtual double GetComponent(int LineN, int ColN) const=0;
    //virtual double* GetComponent_AsPtr(int LineN, int ColN) const=0;
    //virtual double* GetComponent_AsPtr(int LineN, int ColN) const;
    //
    virtual void SetComponent_byEI(double val, int ExtRowN, int IneRowN)=0;
    virtual void SetComponent(double val, int LineN, int ColN)=0;
    //
    //void AddToExtRowN(int RowN, doubleval);
    //void InsToExtRowN(int RowN, int PosN, doubleval);
    //void DelFromExtRowN(int RowN, int PosN);
    //
    //virtual void AddToExtRowN_Simply(int ExtRowN, doubleval)=0;
    //virtual void InsToExtRowN_Simply(int ExtRowN, int PosN, doubleval)=0;
    //virtual void DelFromExtRowN_Simply(int RowN, int IneRowPosN)=0;
    //
    // Ext row
    //
    // void ArrayOf2DBy1D_SetExtRowN(double*&X, Array2DSize&size, int ExtRowN,       double DefaultVal,double*rowParam, int wholeRowL=0,                      TParamsOfDataShift*DataShiftParam=NULL, /*bool KeepIfRect=true,*/ bool DefaultIsSpecNotOwn=true,      int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2){
    //virtual              void               SetExtRowN(                              int N, double defaultVal, double*rowParam,      int rowL,    TParamsOfDataShift*DataShiftParams=NULL,                          bool DefaulsAreSpecNotOwnVals=true, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2)=0;
    //
    void SetExtRowN(int N, double*rowParam=NULL, int rowL=0, double defaultVal=0.0, TParamsOfDataShift*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int ifNLNE_ByM1ByNewRow2ByMax3=1);
    //
    void SetExtRow_Simply(int N,double*rowParam);
    //virtual void SetExtRow_Simply_OwnType(int N,double*rowParam);
    //
    void SetLineN  (                    int     N, double*rowParam, int rowL,        double defaultVal=0.0,TParamsOfDataShift*DataShiftParams=NULL,  bool DefaulsAreSpecNotOwnVals=true, int ifNLNE_ByM1ByNewRow2ByMax3=1);
    //void Matrix_Prototype::SetLineN  (int LineN, double*rowParam, int rowL,        double defaultVal,    TParamsOfDataShift*DataShiftParams,       bool DefaulsAreSpecNotOwnVals,      int ifNLNE_ByM1ByNewRow2ByMax3)
    //
    //virtual void SetLine_Simply_OwnType(int N, double*rowParam)=0;
    void SetLine_Simply(int N, double*rowParam);


    //virtual void SetLine_Simply_OwnType(int N, double*rowParam)=0;
    //
    //void ArrayOf2DBy1D_AddExtRow(double*&X, Array2DSize&size, double DefaultVal,double*rowParam, int wholeRowL=0,                             TParamsOfDataShift*DataShiftParam=NULL,                           int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL){
    //void ArrayOf2DBy1D_AddExtRow(double*&X, Array2DSize&size,                   double*rowParam, int wholeRowL=0,double*DefaultValParam=NULL, TParamsOfDataShift*DataShiftParam=NULL,                           int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL){
    //void  Matrix_Prototype::               AddLine(                             double*rowParam, int wholeRowL,                               TParamsOfDataShift*DataShiftParam,        double DefaultVal,      int ifNLNE_ByM1ByNewRow2ByMax3,                                                           TValsShowHide*vsh){
                          void             AddExtRow(                             double*rowParam, int wholeRowL=0,                             TParamsOfDataShift*DataShiftParam=NULL,   double DefaultVal=0.0,  int ifNLNE_ByM1ByNewRow2ByMax3=1,                                                         TValsShowHide*vsh=NULL);
                          //
                          void               AddLine(                             double*rowParam, int wholeRowL=0,                             TParamsOfDataShift*DataShiftParam=NULL,   double DefaultVal=0.0,  int ifNLNE_ByM1ByNewRow2ByMax3=1,                                                         TValsShowHide*vsh=NULL);
                          //
    virtual              void     AddExtRow_OwnType(                             double*rowParam, int wholeRowL=0,                             TParamsOfDataShift*DataShiftParam=NULL,   double DefaultVal=0.0,  int ifNLNE_ByM1ByNewRow2ByMax3=1,                                                         TValsShowHide*vsh=NULL)=0;
    virtual              void       AddLine_OwnType(                             double*rowParam, int wholeRowL=0,                             TParamsOfDataShift*DataShiftParam=NULL,   double DefaultVal=0.0,  int ifNLNE_ByM1ByNewRow2ByMax3=1,                                                         TValsShowHide*vsh=NULL)=0;
    //virtual void AddExtRow_Simply(double*rowParam)=0;
    //void AddExtRow_Simply(double*rowParam);
    virtual void AddExtRow_Simply_OwnType(double*rowParam)=0;
    //
    virtual void   AddLine_Simply_OwnType(double*rowParam)=0;
    void AddLine_Simply(double*rowParam);
    //
    ////void ArrayOf2DBy1D_InsExtRow(double*&X, Array2DSize&size, int ExtRowN, double DefaultVal, double*rowParam=NULL, int wholeRowL=0,                           TParamsOfDataShift*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL){
    ////void ArrayOf2DBy1D_InsExtRow(double*&X, Array2DSize&size, int ExtRowN,                    double*rowParam=NULL, int wholeRowL=0, double*DfltValParam=NULL, TParamsOfDataShift*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL){
    //
    //                     void               InsExtRow(         int ExtRowN,                    double*rowParam=NULL, int wholeRowL=0,   double DefaultVal=0.0,  TParamsOfDataShift*DataShiftParam=NULL, int ifNLNE_ByM1ByNewRow2ByMax3=1,                                                        TValsShowHide*vsh=NULL);
                          //
    //                     void                 InsLine(         int ExtRowN,                    double*rowParam=NULL, int wholeRowL=0,   double DefaultVal=0.0,  TParamsOfDataShift*DataShiftParam=NULL, int ifNLNE_ByM1ByNewRow2ByMax3=1,                                                        TValsShowHide*vsh=NULL);
    //
                          void               InsExtRowN(         int ExtRowN,                    double*rowParam=NULL, int wholeRowL=0,    TParamsOfDataShift*DataShiftParam=NULL,   double DefaultVal=0.0, int ifNLNE_ByM1ByNewRow2ByMax3=1,                                   TValsShowHide*vsh=NULL);
                          void                 InsLineN(         int LineN,                      double*rowParam=NULL, int wholeRowL=0,    TParamsOfDataShift*DataShiftParam=NULL,   double DefaultVal=0.0, int ifNLNE_ByM1ByNewRow2ByMax3=1,                                   TValsShowHide*vsh=NULL);
    virtual               void               InsExtRowN_OwnType( int ExtRowN,                    double*rowParam=NULL, int wholeRowL=0,    TParamsOfDataShift*DataShiftParam=NULL,   double DefaultVal=0.0, int ifNLNE_ByM1ByNewRow2ByMax3=1,                                   TValsShowHide*vsh=NULL)=0;
    virtual               void                 InsLineN_OwnType( int LineN,                      double*rowParam=NULL, int wholeRowL=0,    TParamsOfDataShift*DataShiftParam=NULL,   double DefaultVal=0.0, int ifNLNE_ByM1ByNewRow2ByMax3=1,                                   TValsShowHide*vsh=NULL)=0;
    void InsExtRow_Simply(int N, double*rowParam);
    virtual void InsExtRow_Simply_OwnType(int N, double*rowParam)=0;
    //virtual void InsExtRow_Simply(int N,double*rowParam, int L)=0;
    //
    //virtual void InsLine_Simply(int N,double*rowParam)=0;
    void InsLine_Simply(int N,double*rowParam);
    virtual void InsLine_Simply_OwnType(int N,double*rowParam)=0;
    //
    void DelExtRowN(int N=-1);
    void DelLineN(int N=-1);
    virtual void DelExtRowN_Simply(int N=-1)=0;//OwnType
     virtual void DelLineN_Simply(int N=-1)=0;//OwnType
    //
    //Ine row
    //
    //// void ArrayOf2DBy1D_SetIneRowN(double*&X, Array2DSize& size, int IneRowN, double DefaultVal,double*rowParam=NULL, int wholeRowL=0,                        TParamsOfDataShift*DataShiftParam=NULL,                       bool DefaulsAreSpecNotOwnVals=true,  int if_LsNE_Ignore0_Resize_NewByOld_QERAndStretchIfShorter2_QEROrIRL_FromStartTillBreak3_All_NsBy2D4_NsByLongEnoughRows5_ByMaxQERAndStretchOrIRL6_OldByNew_FromStartAndStretchIfShorterAndTrimOrAddExt7=2, bool SetRectAnyway=true){
    //
    //                       void               SetIneRowN(          int IneRowN,                   double*rowParam=NULL, int wholeRowL=0, double DefaultVal=0.0, TParamsOfDataShift*DataShiftParam=NULL,                       bool DefaulsAreSpecNotOwnVals=true,  int ifNLNE_ByM1ByNewRow2ByMax3=1);
    //
    //                       void               SetColumn (          int    ColN,                   double*rowParam=NULL, int wholeRowL=0, double DefaultVal=0.0, TParamsOfDataShift*DataShiftParam=NULL,                       bool DefaulsAreSpecNotOwnVals=true,  int ifNLNE_ByM1ByNewRow2ByMax3=1);
    //
                             void               SetIneRowN(          int IneRowN,                   double*rowParam=NULL, int wholeRowL=0,                        TParamsOfDataShift*DataShiftParam=NULL, double DefaultVal=0.0, bool DafaultsAreSpecNotOwnVals=true, int ifNLNE_ByM1ByNewRow2ByMax3=1,                                   TValsShowHide*vsh=NULL);
                             void               SetColumnN(          int ColumnN,                   double*rowParam=NULL, int wholeRowL=0,                        TParamsOfDataShift*DataShiftParam=NULL, double DefaultVal=0.0, bool DafaultsAreSpecNotOwnVals=true, int ifNLNE_ByM1ByNewRow2ByMax3=1,                                   TValsShowHide*vsh=NULL);
    //virtual void SetIneRowSimply(int IneRowN,double*rowParam)=0;
    //virtual void SetColumnSimply(int IneRowN,double*rowParam)=0;
    void SetIneRowSimply(int IneRowN,double*rowParam);
    void SetColumnSimply(int IneRowN,double*rowParam);
    //
    virtual void  SetIneRow_OwnType(         int IneRowN,                                        double*rowParam, int wholeRowL=0, TParamsOfDataShift*dataShiftParam=NULL, bool DefaultsAreSpecNotOwnVals=true,  double DefaultVal=0.0,  int ifNLNE_ByM1ByNewRow2ByMax3=1)=0;
    virtual void  SetColumn_OwnType(         int ColumnN,                                        double*rowParam, int wholeRowL=0, TParamsOfDataShift*dataShiftParam=NULL, bool DefaultsAreSpecNotOwnVals=true,  double DefaultVal=0.0,  int ifNLNE_ByM1ByNewRow2ByMax3=1)=0;
    virtual void SetIneRowSimply_OwnType(int IneRowN,double*rowParam)=0;
    virtual void SetColumnSimply_OwnType(int IneRowN,double*rowParam)=0;
    //
    //void ArrayOf2DBy1D_AddIneRow(double*&X, Array2DSize& size, double DefaultVal, double*rowParam=NULL, int wholeRowL=0,                        TParamsOfDataShift*dataShiftParam=NULL,                              int ifNGTLmin_Ignore0AddToLast1StretchToMax2=0, int if_RowLNEQER_By2D2_ByMax3=2, bool SetRect=true){
                //void   AddIneRow(                              double DefaultVal, double*rowParam=NULL, int wholeRowL=0,                        TParamsOfDataShift*dataShiftParam=NULL,                              int ifNGTLmin_Ignore0AddToLast1StretchToMax2=0, int if_RowLNEQER_By2D2_ByMax3=2, bool SetRect=true);
                //void   AddIneRow(                                                 double*rowParam=NULL, int wholeRowL=0,                        TParamsOfDataShift*dataShiftParam=NULL, double*DefaultValParam=NULL, int ifNGTLmin_Ignore0AddToLast1StretchToMax2=0, int if_RowLNEQER_By2D2_ByMax3=2, bool SetRect=true);
                // void   AddIneRow(                                                 double*rowParam=NULL, int wholeRowL=0, double DefaultVal=0.0, TParamsOfDataShift*dataShiftParam=NULL,                             int ifNLNE_ByM1ByNewRow2ByMax3=1);
                  void   AddIneRow(                                                 double*rowParam=NULL, int wholeRowL=0,                         TParamsOfDataShift*dataShiftParam=NULL, double DefaultVal=0.0,      int ifNLNE_ByM1ByNewRow2ByMax3=1);
                //
                // void   AddColumn(                                                 double*rowParam=NULL, int wholeRowL=0, double DefaultVal=0.0, TParamsOfDataShift*dataShiftParam=NULL,                              int ifNLNE_ByM1ByNewRow2ByMax3=1);
                   void   AddColumn(                                                 double*rowParam=NULL, int wholeRowL=0,                        TParamsOfDataShift*dataShiftParam=NULL, double DefaultVal=0.0,       int ifNLNE_ByM1ByNewRow2ByMax3=1);
    //
    virtual void  AddIneRow_OwnType(double*rowParam=NULL, int wholeRowL=0, TParamsOfDataShift*dataShiftParam=NULL, double DefaultVal=0.0, int ifNLNE_ByM1ByNewRow2ByMax3=1)=0;
    virtual void  AddColumn_OwnType(double*rowParam=NULL, int wholeRowL=0, TParamsOfDataShift*dataShiftParam=NULL, double DefaultVal=0.0, int ifNLNE_ByM1ByNewRow2ByMax3=1)=0;
    //
    void AddIneRow_Simply(double*rowParam);
    //
    void AddColumn_Simply(double*rowParam);
    //
    virtual void AddIneRow_Simply_OwnType(double*rowParam)=0;
    //
    virtual void AddColumn_Simply_OwnType(double*rowParam)=0;
    //
    //void ArrayOf2DBy1D_InsIneRowN(double*&X, Array2DSize& size, int IneRowN, double DefaultVal,double*rowParam=NULL, int wholeRowL=0,                                     TParamsOfDataShift*DataShiftParam=NULL, bool DefaulsAreSpecNotOwnVals=true, int if_LsNE_Ignore0_Resize_NewByOld_QERAndStretchIfShorter2_QEROrIRL_FromStartTillBreak3_All_NsBy2D4_NsByLongEnoughRows5_ByMaxQERAndStretchOrIRL6_OldByNew_FromStartAndStretchIfShorterAndTrimOrAddExt7=2, bool SetRectAnyway=true){
    //                     void               InsIneRowN(                         int IneRowN, double DefaultVal,double*rowParam=NULL, int wholeRowL=0,                      TParamsOfDataShift*DataShiftParam=NULL, bool DefaulsAreSpecNotOwnVals=true,                         int if_LsNE_Ignore0_Resize_NewByOld_QERAndStretchIfShorter2_QEROrIRL_FromStartTillBreak3_All_NsBy2D4_NsByLongEnoughRows5_ByMaxQERAndStretchOrIRL6_OldByNew_FromStartAndStretchIfShorterAndTrimOrAddExt7=2, bool SetRectAnyway=true);
    //                    void               InsIneRowN(                         int IneRowN,                     double*rowParam=NULL, int wholeRowL=0,                    TParamsOfDataShift*DataShiftParam=NULL, bool DefaulsAreSpecNotOwnVals=true,double*DefaultValParam=NULL, int if_LsNE_Ignore0_Resize_NewByOld_QERAndStretchIfShorter2_QEROrIRL_FromStartTillBreak3_All_NsBy2D4_NsByLongEnoughRows5_ByMaxQERAndStretchOrIRL6_OldByNew_FromStartAndStretchIfShorterAndTrimOrAddExt7=2, bool SetRectAnyway=true);
    //
                         void               InsIneRowN(                         int IneRowN, double*rowParam=NULL, int wholeRowL=0, TParamsOfDataShift*DataShiftParam=NULL, double DefaultVal=0.0,                         int ifNLNE_ByM1ByNewRow2ByMax3=1);
                         //
                         void               InsColumnN(                         int ColumnN, double*rowParam=NULL, int wholeRowL=0, TParamsOfDataShift*DataShiftParam=NULL, double DefaultVal=0.0,                         int ifNLNE_ByM1ByNewRow2ByMax3=1);
    //
    virtual void InsIneRowN_OwnType(int IneRowN, double*rowParam, int wholeRowL=0, double DefaultVal=0.0,TParamsOfDataShift*DataShiftParam=NULL,                          int ifNLNE_ByM1ByNewRow2ByMax3=1)=0;
    virtual void InsColumnN_OwnType(int IneRowN, double*rowParam, int wholeRowL=0, double DefaultVal=0.0,TParamsOfDataShift*DataShiftParam=NULL,                           int ifNLNE_ByM1ByNewRow2ByMax3=1)=0;
                         //
    //virtual void InsIneRow_Simply(int N, double*rowParam)=0;
    //virtual void InsColumn_Simply(int N, double*rowParam)=0;
    void InsIneRow_Simply(int N, double*rowParam);
    void InsColumn_Simply(int N, double*rowParam);
    //
    virtual void InsIneRow_Simply_OwnType(int IneRowN, double*rowParam)=0;
    virtual void InsColumn_Simply_OwnType(int ColumnN, double*rowParam)=0;
    //
    //void DelIneRowN(int N=-1, int ifNGTLmin_Ignore0_DelLast1_NurProperL_AnyExtRow3_NurFromStartTillFirstBreak4=0);
    void DelIneRowN(int N=-1);
    void DelColumnN(int N=-1);
    virtual void DelIneRow_Simply(int N=-1)=0;
    virtual void DelColumn_Simply(int N=-1)=0;
    //
    // Set Content
    //
    //void Set(double**y, const Array2DSize& size,  bool WriteSize=true);
    //void Set(double**y, std::vector<int>ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    ////void Set(double**y, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(double**y, int QExtRows, int ExtRowsLength=1, /* bool RectIfPossible=true,*/ bool sizeVaria=false, bool WriteSize=true);
    //
    //void Set(double*y, const Array2DSize& size, bool WriteSize=true);
    //void Set(double*y, std::vector<int>ExtRowsLengthes, bool WriteSize=true);
    //void Set(double*y, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true,  bool WriteSize=true);
    //void Set(double*y, int QExtRows, int ExtRowsLength=1,/* bool RectIfPossible=true,*/ bool sizeVaria=false, bool WriteSize=true);
    //
    //void Set(std::vector<std::vector<double>>y, bool RectIfPossible=true, bool WriteSize=true);
    //
    //void Set(std::vector<double>y, const Array2DSize& size, bool WriteSize=true);
    //void Set(std::vector<double>y, std::vector<int>ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //
    //void Set(std::vector<double>y, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(std::vector<double>y, int QExtRows, int ExtRowsLength=1, /* bool RectIfPossible=true,*/ bool sizeVaria=false, bool WriteSize=true);
    //void Set(doubleval, const Array2DSize& size, bool WriteSize=true);
    //void Set(doubleval, std::vector<int>ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(doubleval, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(double val, int QExtRows, int ExtRowsLength=1, /* bool RectIfPossible=true,*/ bool sizeVaria=false, bool WriteSize=true);
    void Set_byEI(double**y, int QExtRows=1, int QIneRows=1);
    void Set_byLC(double**y, int QLines=1, int QColumns=1);//by LC s'om param, ne om Matrix. F'Matrix s'SetComponent. Ors os ablb by EI, LC (zug o'Lines) et CL (zug o'Cols), ma nout CL, if LC s'Matrix order, f'Matrices' CL s'EI
    void Set_byCL(double**y, int QLines=1, int QColumns=1);//CL sdi y s'zug o'cols
    void Set_byEI(double*y, int QExtRows=1, int QIneRows=1);
    void Set_byLC(double*y, int QLines=1, int QColumns=1);//by LC s'om param, ne om Matrix. F'Matrix s'SetComponent. Ors os ablb by EI, LC (zug o'Lines) et CL (zug o'Cols), ma nout CL, if LC s'Matrix order, f'Matrices' CL s'EI
    void Set_byCL(double*y, int QLines=1, int QColumns=1);//CL=>-param s'zug o'cols
    void Set_byEI(double val, int QExtRows=1, int ExtRowsLength=1);
    void Set_byLC(double val, int QLines=1, int QColumns=1);
    void Set_byEIR(std::vector<double>arr, int QExtRows);
    void Set_byLC(std::vector<double>arr, int QLines);
    void Set_byCL(std::vector<double>arr, int QColumns);
    void Set_byEIR(std::vector<std::vector<double>>arr, int ifLNE_ExtRows_By_Max3Min4=4);
    void Set_byLC(std::vector<std::vector<double>>arr, int ifLNE_Lines_By_Max3Min4=4);
    void Set_byCL(std::vector<std::vector<double>>arr, int ifLNE_Lines_By_Max3Min4=4);
    //
    void SwapVals_byEI(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
    void SwapVals_byLC(int LineN1, int ColN1, int LineN2, int ColN2);
    //
    void SwapExtRows(int N1, int N2);
    //
    void SwapLines(int N1, int N2);
    //
    void SwapIneRows(int N1, int N2);
    //
    void SwapColumns(int N1, int N2);
    //
    //
    void ReverseExtRowN(int rowN);
    void ReverseLineN(int rowN);
    void ReverseIneRowN(int rowN);
    void ReverseColumnN(int rowN);
    void ReverseExtRowsSuccession();
    void ReverseLinesSuccession();
    void ReverseIneRowsSuccession();
    void ReverseColumnsSuccession();
    //
    bool ValIsAtPos_byEI(double val, int ExtRowN, int IneRowN) const;
    bool ValIsAtPos_byLC(double val, int LineN, int ColN) const;
    //swa S di n'fit prototype - obe s': alt IneRowN wa ExtRowN, so ExtRowN 2x, ce alt err
    //std::vector<std::vector<int>> SeekVal(doubleval) const;
    //std::vector<Int2DVectorOfSizeOrCoords> SeekVal(double val) const;
    TListOfNumberPairs SeekVal_ByEI(double val) const;
    TListOfNumberPairs SeekVal(double val) const;
    //so class name. Ma to vrns co std::vector ety di n'fit prototype
    bool ExtRowIsAtPos(double*row, int Q, int ExtRowN, int IneRowN) const;
    bool LineIsAtPos(double*row, int Q, int LineN,   int ColN) const;
    //std::vector<std::vector<int>> SeekExtRow(double*row, int L) const;
    //std::vector<Int2DVectorOfSizeOrCoords> SeekExtRow(double*row, int L) const;
    TListOfNumberPairs SeekExtRow(double*row, int L) const;
    TListOfNumberPairs SeekLine(double*row, int L) const;
    bool IneRowIsAtPos(double*row, int Q, int ExtRowN, int IneRowN) const;
    bool ColumnIsAtPos(double*row, int Q, int LineN, int ColN) const;
    //std::vector<std::vector<int>> SeekIneRow(double*row, int Q) const;
    //std::vector<Int2DVectorOfSizeOrCoords> SeekIneRow(double*row, int Q) const;
    TListOfNumberPairs SeekIneRow(double*row, int Q) const;
    TListOfNumberPairs SeekColumn(double*row, int Q) const;

    bool Arr2DIsAtPos_byEI(std::vector<std::vector<double>>arr,             int ExtRowN, int IneRowN, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    bool Arr2DIsAtPos_byLC(std::vector<std::vector<double>>arr,             int LineN,   int ColN,    bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //bool Arr2DIsAtPos(std::vector<double>arr, const Array2DSize& size, int ExtRowN, int IneRowN, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //bool Arr2DIsAtPos(Matrix_Prototype*M,                      int ExtRowN, int IneRowN, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;

    TListOfNumberPairs SeekArr2D_byEI(std::vector<std::vector<double>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    TListOfNumberPairs SeekArr2D_byLC(std::vector<std::vector<double>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;

    ////std::vector<std::vector<int>> SeekArr2D(std::vector<std::vector<double>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    ////std::vector<Int2DVectorOfSizeOrCoords> SeekArr2D(std::vector<std::vector<double>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //TListOfNumberPairs SeekArr2D(std::vector<std::vector<double>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    ////std::vector<std::vector<int>> SeekArr2D(Matrix_Prototype*arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    ////std::vector<Int2DVectorOfSizeOrCoords> SeekArr2D(Matrix_Prototype*arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //TListOfNumberPairs SeekArr2D(Matrix_Prototype*obj, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //
    //
    ////void GetSubArray_As1DArr(double*&data,     int ExtRowN, int IneRowN, const Array2DSize& size, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    ////std::vector<double> GetSubArray_As1DArr(   int ExtRowN, int IneRowN, const Array2DSize& size, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //std::vector<double> GetSubArray_As1DArr_byEI(int ExtRowN, int IneRowN, std::vector<int>Ls,         bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //std::vector<double> GetSubArray_As1DArr_byEI(int ExtRowN, int IneRowN, int QExtRows, int QIneRows, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //std::vector<double> GetSubArray_As1DArr_byLC(int LineN,   int ColumnN, std::vector<int>Ls,         bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //std::vector<double> GetSubArray_As1DArr_byLC(int LineN,   int ColumnN, int QExtRows, int QIneRows, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    ////std::vector<double> GetSubArray_As1DArr(int LineN, int IneRowN, const Array2DSize& size, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;

    ////virtual Matrix_Prototype*GetSubArray(int ExtRowN, int IneRowN, const Array2DSize& size, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const=0;
    //virtual Matrix_Prototype*   GetSubArray_byEI(int ExtRowN, int IneRowN, std::vector<int>Ls,         bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const=0;
    //virtual Matrix_Prototype*   GetSubArray_byEI(int ExtRowN, int IneRowN, int QExtRows, int QIneRows, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const=0;
    //virtual Matrix_Prototype*   GetSubArray_byLC(int LineN,   int ColumnN, std::vector<int>Ls,         bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const=0;
    //virtual Matrix_Prototype*   GetSubArray_byLC(int LineN,   int ColumnN, int QExtRows, int QIneRows, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const=0;
    //
    ////void GetSubArray_AsSuccOfExtRows_As1DArr(double*&XR, Array2DSize& sizeR, double DefaultVal, TParamsOfDataShift*DataShiftParam=NULL,                          int DfltRowL_00_11_Lmin2_Lmax3=3) const;
    ////void GetSubArray_AsSuccOfExtRows_As1DArr(double*&XR, Array2DSize& sizeR,               TParamsOfDataShift*DataShiftParam=NULL,double*DefaultValParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3) const;
    //std::vector<double> GetSubArray_AsSuccOfExtRows_As1DArr_byEI(                                 TParamsOfDataShift*DataShiftParam=NULL,                          double DefaultVal=0.0) const;
    //std::vector<double> GetSubArray_AsSuccOfExtRows_As1DArr_byLC(                                 TParamsOfDataShift*DataShiftParam=NULL,                          double DefaultVal=0.0) const;
    //std::vector<double> GetSubArray_AsSuccOfExtRows_As1DArr(Array2DSize& sizeR, double DefaultVal, DataShiftParams*DataShiftParam=NULL,                          int DfltRowL_00_11_Lmin2_Lmax3=3);
    //std::vector<double> GetSubArray_AsSuccOfExtRows_As1DArr(Array2DSize& sizeR,               TParamsOfDataShift*DataShiftParam=NULL,double*DefaultValParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3);
    //virtual Matrix_Prototype*GetSubArray_AsSuccOfExtRows(double DefaultVal, TParamsOfDataShift*DataShiftParam=NULL,                         int DfltRowL_00_11_Lmin2_Lmax3=3)=0;
    //virtual Matrix_Prototype*GetSubArray_AsSuccOfExtRows(              TParamsOfDataShift*DataShiftParam=NULL, double*DefaultValParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3)=0;
    //virtual   Matrix_Prototype*GetSubArray_AsSuccOfExtRows_byEI(              TParamsOfDataShift*DataShiftParam=NULL, double DefaultVal=0)=0;
    //virtual   Matrix_Prototype*GetSubArray_AsSuccOfExtRows_byLC(              TParamsOfDataShift*DataShiftParam=NULL, double DefaultVal=0)=0;
    //
    std::vector<double> SubMatrix_As1DArr_ByEINs_NurBelonging(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
    std::vector<double> SubMatrix_As1DArr_ByLCNs_NurBelonging(int LineN1, int ColN1, int LineN2, int ColN2);
    std::vector<double> SubMatrix_As1DArr_ByCLNs_NurBelonging(int LineN1, int ColN1, int LineN2, int ColN2);
    std::vector<std::vector<double>> SubMatrix_As2DArr_ByEINs_NurBelonging(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
    std::vector<std::vector<double>> SubMatrix_As2DArr_ByLCNs_NurBelonging(int LineN1, int ColN1, int LineN2, int ColN2);
    std::vector<std::vector<double>> SubMatrix_As2DArr_ByCLNs_NurBelonging(int LineN1, int ColN1, int LineN2, int ColN2);

    std::vector<std::vector<double>> SubMatrixAsSuccOfRows_AsArr2D_byEI(TParamsOfDataShift ShiftParams);
    std::vector<std::vector<double>> SubMatrixAsSuccOfRows_AsArr2D_byEI(int QReq=0, int FromN=1, int QDefaultsBefore=0);

    std::vector<std::vector<double>> SubMatrixAsSuccOfRows_AsArr2D_byLC(TParamsOfDataShift ShiftParams);
    std::vector<std::vector<double>> SubMatrixAsSuccOfRows_AsArr2D_byLC(int QReq=0, int FromN=1, int QDefaultsBefore=0);
    std::vector<std::vector<double>> SubMatrixAsSuccOfRows_AsArr2D_byCL(TParamsOfDataShift ShiftParams);
    std::vector<std::vector<double>> SubMatrixAsSuccOfRows_AsArr2D_byCL(int QReq=0, int FromN=1, int QDefaultsBefore=0);

    //
    //void ConcatAdding(Matrix_Prototype*obj, double DefaultVal,int QShiftedCols=0,  TParamsOfDataShift*DataShiftParam=NULL, bool SetRect=true, int DfltRowL_00_11_Lmin2_Lmax3=1);
    //void ConcatAdding(Matrix_Prototype*obj, int QShiftedCols=0, TParamsOfDataShift*DataShiftParam=NULL,double*DefaultValParam=NULL, bool SetRect=true, int DfltRowL_00_11_Lmin2_Lmax3=1);
    void ConcatAdding_byEI(Matrix_Prototype*obj,int QShiftedCols=0, TParamsOfDataShift*DataShiftParam=NULL, double DefaultVal=0);
    void ConcatAdding_byLC(Matrix_Prototype*obj,int QShiftedCols=0, TParamsOfDataShift*DataShiftParam=NULL, double DefaultVal=0);
    //_ConcatStretching(double*X1, const Array2DSize& size1,double*X2, const Array2DSize& size2,double*&X3, Array2DSize& size3, double DefaultVal, int shiftQ=0, TParamsOfDataShift*DataShiftParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3, bool Stretch1ToMax=true, bool SetRect=true){
    //void ConcatStretching(Matrix_Prototype*obj, double DefaultVal, int QShiftedExtRowNs=0,  TParamsOfDataShift*DataShiftParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3, bool Stretch1ToMax=true, bool SetRect=true);
    //void ConcatStretching(Matrix_Prototype*obj, int QShiftedExtRowNs=0, TParamsOfDataShift*DataShiftParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3, bool Stretch1ToMax=true, bool SetRect=true,double*DefaultValParam=NULL);
    void ConcatStretching_byEI(Matrix_Prototype*obj,  int QShiftedLinesNs=0,  TParamsOfDataShift*DataShiftParam=NULL);//, double DefaultVal=0);
    void ConcatStretching_byLC(Matrix_Prototype*obj,  int QShiftedLinesNs=0,  TParamsOfDataShift*DataShiftParam=NULL);//, double DefaultVal=0);
    //
    //
    //void ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(double val, int ExtRowN, int IneRowN, double DefaultVal, bool SetRect=true, int DfltRowL_00_11_Max2_Min3=2);
    //void ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(double val, int ExtRowN, int IneRowN, bool SetRect=true, int DfltRowL_00_11_Max2_Min3=2,double*DefaultValParam=NULL);
    void ValSetOrAddOrFillOrIgnore_byEI(double val, int ExtRowN, int ColN);
    void ValSetOrAddOrFillOrIgnore(double val, int LineN, int ColN);
    //
    void StdCout_ExtRowN(int ExtRowN, QString ElemsDelim="; ", bool UseBrackets=true)const;
    void StdCout_IneRowN(int IneRowN, QString ElemsDelim="; ", bool UseBrackets=true, bool Represent2DNot1D=false)const;
    void StdCout_LineN(int LineN, QString ElemsDelim="; ", bool UseBrackets=true)const;
    void StdCout_ColumnN(int ColumnN, QString ElemsDelim="; ", bool UseBrackets=true, bool Represent2DNot1D=false)const;
    void StdCout(QString ElemsDelim=", ", QString RowsDelim="; ", bool UseBrackets=true, bool Represent2DNot1D=true, bool ByExtRowsNotIneRows=true)const;
    //
    void FillByNs();
    void SetDataOfVect3D(double x, double y, double z);
    void MakeVect3D(double x, double y, double z);
    void SetX(double val);
    void SetY(double val);
    void SetZ(double val);
    double GetX();
    double GetY();
    double GetZ();
};





class Matrix_V1I_ArrOfLines : public Matrix_Prototype{
    std::vector<double>data;
    //Array2DSize size;
    int QLines;
public:
    //
    Matrix_V1I_ArrOfLines();
    //Matrix_V1I_ArrOfLines(double DefaultVal, const Array2DSize& size);
    Matrix_V1I_ArrOfLines(double DefaultVal, int QLines=1, int QColumns=1);
    //Matrix_V1I_ArrOfLines(double DefaultVal, int QExtRows=1, int*Ls=NULL, bool RectIfPossible=true);
    //Matrix_V1I_ArrOfLines(double DefaultVal, std::vector<int>Ls, bool RectIfPossible=true);
    //Matrix_V1I_ArrOfLines(double*data, const Array2DSize& size);
    Matrix_V1I_ArrOfLines(double*data, int QLines=1, int QColumns=1);
    //Matrix_V1I_ArrOfLines(double*data, int QExtRows=1, int*Ls=NULL, bool RectIfPossible=true);
    //Matrix_V1I_ArrOfLines(double*data, std::vector<int>Ls, bool RectIfPossible=true);
    //Matrix_V1I_ArrOfLines(std::vector<double>data, const Array2DSize& size);
    Matrix_V1I_ArrOfLines(std::vector<double>data, int QLines=1, int QColumns=1);
    //Matrix_V1I_ArrOfLines(std::vector<double>data, int QExtRows=1, int*Ls=NULL, bool RectIfPossible=true);
    //Matrix_V1I_ArrOfLines(std::vector<double>data, std::vector<int>Ls, bool RectIfPossible=true);
    Matrix_V1I_ArrOfLines(std::vector<std::vector<double>>data);//cpp n'fit: bools alt
    //Matrix_V1I_ArrOfLines(std::vector<std::vector<double>>data, bool RectIfPossible=true);
    Matrix_V1I_ArrOfLines(std::vector<std::vector<double>>data, int ifLNE_Lines_By_Max3Min4=3);
    //Matrix_V1I_ArrOfLines(double**data, const Array2DSize& size);
    Matrix_V1I_ArrOfLines(double**data, int QLines=1, int QColumns=1);
    //Matrix_V1I_ArrOfLines(double**data, int QExtRows=1, int*Ls=NULL, bool RectIfPossible=true);
    //Matrix_V1I_ArrOfLines(double**data, std::vector<int>Ls, bool RectIfPossible=true);
    //
    Matrix_V1I_ArrOfLines(const Matrix_V1I_ArrOfLines& obj);
    //
    //virtual ~Array2D_Prototype()=default;
    virtual ~Matrix_V1I_ArrOfLines();
    //virtual void SetNull()=0;
    //virtual void construct()=0;
    virtual void SetNull();
    virtual void construct();

    //virtual Matrix_Prototype* CreateMatrix() const=0;
    virtual Matrix_Prototype* CreateMatrix() const;
    //virtual Matrix_Prototype* clone()const=0;
    virtual Matrix_Prototype* clone()const;
    virtual int GetTypeN() const;
    virtual void Assign(Matrix_Prototype* obj);

    //
    //void SetOne(double*DfltVal=NULL);
    //void SetOne(double DfltVal);
    //void SetOne(double DfltVal=0.0);
    //
    //virtual void SetLengthOfExtRowN(int ExtRowN, int newL, double DefaultVal=0)=0;//es SetSize f'ce
    //virtual void SetLengthOfExtRowN(int ExtRowN, int newL,double*DefaultValParam=NULL)=0;
    //
    ////virtual void SetSize(double DfltValParam, const Array2DSize&size)=0;
    //virtual void SetSize_Array(int QExtRows=1, int QIneRows=1, double DefaultVal=0.0)=0;
    //virtual void SetSize_Matrix(int QLines=1, int QColumns=1, double DefaultVal=0.0)=0;
    virtual void SetSize_Array(int QExtRows=1, int QIneRows=1, double DefaultVal=0.0);
    virtual void SetSize_Matrix(int QLines=1, int QColumns=1, double DefaultVal=0.0);
    //
    ////void SetSize(const Array2DSize&size,double*DfltValParam=NULL);//virtual ob hin Sdo mut l'size data
    ////void SetSize(int QExtRows, int ExtRowsLength,double*DfltValParam=NULL);
    ////void SetSize(int QExtRows=1, int*ExtRowsLengthes=NULL,double*DfltValParam=NULL);//if Null => L=0
    ////void SetSize(std::vector<int>ExtRowsLengthes,double*DfltValParam=NULL);
    //
    ////void SetSize(double DfltValParam, int QExtRows, int ExtRowsLength);//virtual ob hin Sdo mut l'size data
    ////void SetSize(double DfltValParam, int QExtRows=1, int*ExtRowsLengthes=NULL);//if Null => L=0
    ////void SetSize(double DfltValParam, std::vector<int>Lengthes);
    //
    ////virtual int GetQExtRows() const=0;
    ////virtual int GetLength(int ExtRowN=1) const=0;
    ////virtual int GetMinLength() const=0;
    ////virtual int GetMaxLength() const=0;
    //virtual int GetQExtRows() const=0;
    //virtual int GetLength() const=0;
    //virtual int GetQLines() const=0;
    //virtual int GetQColumns() const=0;
    virtual int GetQExtRows() const;
    virtual int GetLength() const;
    virtual int GetQLines() const;
    virtual int GetQColumns() const;
    //
    ////virtual Array2DSize GetSize()const =0;
    //
    ////bool LineNBelongsHere(int LineN) const;
    ///bool ColNBelongsHere(int ColN) const;
    //bool NsBelongHere_byEI(int ExtRowN, int IneRowN) const;
    //bool NsBelongHere_byLC(int LineN, int ColN) const;
    //
    ////std::vector<double> GetArrayOfExtRowN(int LineN);
    ////std::vector<double> GetArrayOfIneRowN(int ColN);
    ////std::vector<double> GetContentAsArray1D();
    ////std::vector<std::vector<double>> GetContentAsArray2D();
    //
    //std::vector<double> GetExtRowN_AsArray(int rowN) const;
    ////double*GetExtRowN_AsPtr(int ExtRowN) const;
    //std::vector<double> GetIneRowN_AsArray(int rowN) const;
    ////std::vector<double> GetIneRowN_AsArray(int IneRowN, double defaultVal,                               int ifNGTLmin_Ignore0_DefaultsForShorter1_NurProperL_AnyExtRow2_NurFromStartTillErstStop3=0) const;
    ////std::vector<double> GetIneRowN_AsArray(int IneRowN,                     double*DefaultValParam=NULL, int ifNGTLmin_Ignore0_DefaultsForShorter1_NurProperL_AnyExtRow2_NurFromStartTillErstStop3=0) const;
    ////std::vector<double> GetContent_AsArray1D() const;
    ////std::vector<std::vector<double>> GetContent_AsArray2D() const;
    //std::vector<double> GetLineN_AsArray(int N) const;
    //std::vector<double> GetColumnN_AsArray(int N) const;
    //std::vector<double> GetContent_AsArray1D_ExtRows() const;
    //std::vector<std::vector<double>> GetContent_AsArray2D_ExtRows() const;
    //std::vector<double> GetContent_AsArray1D_Lines() const;
    //std::vector<std::vector<double>> GetContent_AsArray2D_Lines() const;
    //
    //
    //virtual double GetComponent_AsVal(int LineN, int ColN) const=0;
    //virtual double GetComponent_AsVal_byEI(int LineN, int ColN) const=0;
    //virtual double GetComponent(int LineN, int ColN) const=0;
    virtual double GetComponent_AsVal_byEI(int LineN, int ColN) const;
    virtual double GetComponent(int LineN, int ColN) const;
    //virtual double* GetComponent_AsPtr(int LineN, int ColN) const=0;
    //virtual double* GetComponent_AsPtr(int LineN, int ColN) const;
    //
    //virtual void SetComponent_byEI(double val, int ExtRowN, int IneRowN)=0;
    //virtual void SetComponent(double val, int LineN, int ColN)=0;
    virtual void SetComponent_byEI(double val, int ExtRowN, int IneRowN);
    virtual void SetComponent(double val, int LineN, int ColN);
    //
    ////void AddToExtRowN(int RowN, doubleval);
    ////void InsToExtRowN(int RowN, int PosN, doubleval);
    ////void DelFromExtRowN(int RowN, int PosN);
    //
    ////virtual void AddToExtRowN_Simply(int ExtRowN, doubleval)=0;
    ////virtual void InsToExtRowN_Simply(int ExtRowN, int PosN, doubleval)=0;
    ////virtual void DelFromExtRowN_Simply(int RowN, int IneRowPosN)=0;
    //
    // Ext row
    //
    //// void ArrayOf2DBy1D_SetExtRowN(double*&X, Array2DSize&size, int ExtRowN,       double DefaultVal,double*rowParam, int wholeRowL=0,                      TParamsOfDataShift*DataShiftParam=NULL, /*bool KeepIfRect=true,*/ bool DefaultIsSpecNotOwn=true,      int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2){
    ////virtual              void               SetExtRowN(                              int N, double defaultVal, double*rowParam,      int rowL,    TParamsOfDataShift*DataShiftParams=NULL,                          bool DefaulsAreSpecNotOwnVals=true, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2)=0;
    //
    //void SetExtRowN(int N, double*rowParam=NULL, int rowL=0, double defaultVal=0.0, TParamsOfDataShift*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int ifNLNE_ByM1ByNewRow2ByMax3=1);
    //
    //void SetExtRow_Simply(int N,double*rowParam);
    ////virtual void SetExtRow_Simply_OwnType(int N,double*rowParam);
    //
    //void SetLineN  (int N, double*rowParam, int rowL,        double defaultVal=0.0,ParamsOfDataShift*DataShiftParams=NULL,  bool DefaulsAreSpecNotOwnVals=true, int ifNLNE_ByM1ByNewRow2ByMax3=1);
    //
    ////virtual void SetLine_Simply_OwnType(int N, double*rowParam)=0;
    //void SetLine_Simply(int N, double*rowParam);


    ////virtual void SetLine_Simply_OwnType(int N, double*rowParam)=0;
    //
    ////void ArrayOf2DBy1D_AddExtRow(double*&X, Array2DSize&size, double DefaultVal,double*rowParam, int wholeRowL=0,                             TParamsOfDataShift*DataShiftParam=NULL,                           int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL){
    ////void ArrayOf2DBy1D_AddExtRow(double*&X, Array2DSize&size,                   double*rowParam, int wholeRowL=0,double*DefaultValParam=NULL, TParamsOfDataShift*DataShiftParam=NULL,                           int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL){
    ////void  Matrix_Prototype::               AddLine(                             double*rowParam, int wholeRowL,                               TParamsOfDataShift*DataShiftParam,        double DefaultVal,      int ifNLNE_ByM1ByNewRow2ByMax3,                                                           TValsShowHide*vsh){
    //                     void             AddExtRow(                             double*rowParam, int wholeRowL=0,                             TParamsOfDataShift*DataShiftParam=NULL,   double DefaultVal=0.0,  int ifNLNE_ByM1ByNewRow2ByMax3=1,                                                         TValsShowHide*vsh=NULL);
                          //
    //                    void               AddLine(                             double*rowParam, int wholeRowL=0,                             TParamsOfDataShift*DataShiftParam=NULL,   double DefaultVal=0.0,  int ifNLNE_ByM1ByNewRow2ByMax3=1,                                                         TValsShowHide*vsh=NULL);
                          //
    virtual              void     AddExtRow_OwnType(                             double*rowParam, int wholeRowL=0,                             TParamsOfDataShift*DataShiftParam=NULL,   double DefaultVal=0.0,  int ifNLNE_ByM1ByNewRow2ByMax3=1,                                                         TValsShowHide*vsh=NULL);
    virtual              void       AddLine_OwnType(                             double*rowParam, int wholeRowL=0,                             TParamsOfDataShift*DataShiftParam=NULL,   double DefaultVal=0.0,  int ifNLNE_ByM1ByNewRow2ByMax3=1,                                                         TValsShowHide*vsh=NULL);
    //virtual void AddExtRow_Simply(double*rowParam)=0;
    //void AddExtRow_Simply(double*rowParam);
    //virtual void AddExtRow_Simply_OwnType(double*rowParam, int L)=0;
    virtual void AddExtRow_Simply_OwnType(double*rowParam);
    //
    //virtual void   AddLine_Simply_OwnType(double*rowParam)=0;
    virtual void   AddLine_Simply_OwnType(double*rowParam);
    //void AddLine_Simply(double*rowParam);
    //
    ////void ArrayOf2DBy1D_InsExtRow(double*&X, Array2DSize&size, int ExtRowN, double DefaultVal, double*rowParam=NULL, int wholeRowL=0,                           TParamsOfDataShift*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL){
    ////void ArrayOf2DBy1D_InsExtRow(double*&X, Array2DSize&size, int ExtRowN,                    double*rowParam=NULL, int wholeRowL=0, double*DfltValParam=NULL, TParamsOfDataShift*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL){
    //
    ////                     void               InsExtRow(         int ExtRowN,                    double*rowParam=NULL, int wholeRowL=0,   double DefaultVal=0.0,  TParamsOfDataShift*DataShiftParam=NULL, int ifNLNE_ByM1ByNewRow2ByMax3=1,                                                        TValsShowHide*vsh=NULL);
                          //
    ////                     void                 InsLine(         int ExtRowN,                    double*rowParam=NULL, int wholeRowL=0,   double DefaultVal=0.0,  TParamsOfDataShift*DataShiftParam=NULL, int ifNLNE_ByM1ByNewRow2ByMax3=1,                                                        TValsShowHide*vsh=NULL);
    //
    //                      void               InsExtRowN(         int ExtRowN,                    double*rowParam=NULL, int wholeRowL=0,    TParamsOfDataShift*DataShiftParam=NULL,   double DefaultVal=0.0, int ifNLNE_ByM1ByNewRow2ByMax3=1,                                   TValsShowHide*vsh=NULL);
    //                      void                 InsLineN(         int LineN,                      double*rowParam=NULL, int wholeRowL=0,    TParamsOfDataShift*DataShiftParam=NULL,   double DefaultVal=0.0, int ifNLNE_ByM1ByNewRow2ByMax3=1,                                   TValsShowHide*vsh=NULL);
    //virtual               void               InsExtRowN_OwnType( int ExtRowN,                    double*rowParam=NULL, int wholeRowL=0,    TParamsOfDataShift*DataShiftParam=NULL,   double DefaultVal=0.0, int ifNLNE_ByM1ByNewRow2ByMax3=1,                                   TValsShowHide*vsh=NULL)=0;
    //virtual               void                 InsLineN_OwnType( int LineN,                      double*rowParam=NULL, int wholeRowL=0,    TParamsOfDataShift*DataShiftParam=NULL,   double DefaultVal=0.0, int ifNLNE_ByM1ByNewRow2ByMax3=1,                                   TValsShowHide*vsh=NULL)=0;
    virtual               void               InsExtRowN_OwnType( int ExtRowN,                    double*rowParam=NULL, int wholeRowL=0,    TParamsOfDataShift*DataShiftParam=NULL,   double DefaultVal=0.0, int ifNLNE_ByM1ByNewRow2ByMax3=1,                                   TValsShowHide*vsh=NULL);
    virtual               void                 InsLineN_OwnType( int LineN,                      double*rowParam=NULL, int wholeRowL=0,    TParamsOfDataShift*DataShiftParam=NULL,   double DefaultVal=0.0, int ifNLNE_ByM1ByNewRow2ByMax3=1,                                   TValsShowHide*vsh=NULL);
                          //void InsExtRow_Simply(int N, double*rowParam);
    //virtual void InsExtRow_Simply_OwnType(int N, double*rowParam)=0;
    virtual void InsExtRow_Simply_OwnType(int N, double*rowParam);
    ////virtual void InsExtRow_Simply(int N,double*rowParam, int L)=0;
    //
    ////virtual void InsLine_Simply(int N,double*rowParam)=0;
    //void InsLine_Simply(int N,double*rowParam)=0;
    //virtual void InsLine_Simply_OwnType(int N,double*rowParam)=0;
    virtual void InsLine_Simply_OwnType(int N,double*rowParam);
    //
    //void DelExtRowN(int N=-1);
    //virtual void DelExtRowN_Simply(int N=-1)=0;//OwnType
    virtual void DelExtRowN_Simply(int N=-1);//OwnType
    virtual void DelLineN_Simply(int N=-1);//OwnType
    //
    //Ine row
    //
    //// void ArrayOf2DBy1D_SetIneRowN(double*&X, Array2DSize& size, int IneRowN, double DefaultVal,double*rowParam=NULL, int wholeRowL=0,                        TParamsOfDataShift*DataShiftParam=NULL,                       bool DefaulsAreSpecNotOwnVals=true,  int if_LsNE_Ignore0_Resize_NewByOld_QERAndStretchIfShorter2_QEROrIRL_FromStartTillBreak3_All_NsBy2D4_NsByLongEnoughRows5_ByMaxQERAndStretchOrIRL6_OldByNew_FromStartAndStretchIfShorterAndTrimOrAddExt7=2, bool SetRectAnyway=true){
    //
    //                       void               SetIneRowN(          int IneRowN,                   double*rowParam=NULL, int wholeRowL=0, double DefaultVal=0.0, TParamsOfDataShift*DataShiftParam=NULL,                       bool DefaulsAreSpecNotOwnVals=true,  int ifNLNE_ByM1ByNewRow2ByMax3=1);
    //
    //                       void               SetColumn (          int    ColN,                   double*rowParam=NULL, int wholeRowL=0, double DefaultVal=0.0, TParamsOfDataShift*DataShiftParam=NULL,                       bool DefaulsAreSpecNotOwnVals=true,  int ifNLNE_ByM1ByNewRow2ByMax3=1);
    //
    //                         void               SetIneRowN(          int IneRowN,                   double*rowParam=NULL, int wholeRowL=0,                        TParamsOfDataShift*DataShiftParam=NULL, double DefaultVal=0.0, bool DafaultsAreSpecNotOwnVals=true, int ifNLNE_ByM1ByNewRow2ByMax3,                                   TValsShowHide*vsh);
    //                         void               SetColumnN(          int ColumnN,                   double*rowParam=NULL, int wholeRowL=0,                        TParamsOfDataShift*DataShiftParam=NULL, double DefaultVal=0.0, bool DafaultsAreSpecNotOwnVals=true, int ifNLNE_ByM1ByNewRow2ByMax3,                                   TValsShowHide*vsh);
    //virtual void SetIneRowSimply(int IneRowN,double*rowParam)=0;
    //virtual void SetColumnSimply(int IneRowN,double*rowParam)=0;
    //void SetIneRowSimply(int IneRowN,double*rowParam);
    //void SetColumnSimply(int IneRowN,double*rowParam);
    //
    //virtual void  SetIneRow_OwnType(         int IneRowN,                                        double*rowParam, int wholeRowL=0, TParamsOfDataShift*dataShiftParam=NULL, bool DefaultsAreSpecNotOwnVals=true,  double DefaultVal=0.0,  int ifNLNE_ByM1ByNewRow2ByMax3=1)=0;
    //virtual void  SetColumn_OwnType(         int ColumnN,                                        double*rowParam, int wholeRowL=0, TParamsOfDataShift*dataShiftParam=NULL, bool DefaultsAreSpecNotOwnVals=true,  double DefaultVal=0.0,  int ifNLNE_ByM1ByNewRow2ByMax3=1)=0;
    //virtual void SetIneRowSimply_OwnType(int IneRowN,double*rowParam)=0;
    //virtual void SetColumnSimply_OwnType(int IneRowN,double*rowParam)=0;
    virtual void SetIneRow_OwnType(         int IneRowN,                                        double*rowParam, int wholeRowL=0, TParamsOfDataShift*dataShiftParam=NULL, bool DefaultsAreSpecNotOwnVals=true,  double DefaultVal=0.0,  int ifNLNE_ByM1ByNewRow2ByMax3=1);
    virtual void SetColumn_OwnType(         int ColumnN,                                        double*rowParam, int wholeRowL=0, TParamsOfDataShift*dataShiftParam=NULL, bool DefaultsAreSpecNotOwnVals=true,  double DefaultVal=0.0,  int ifNLNE_ByM1ByNewRow2ByMax3=1);
    virtual void SetIneRowSimply_OwnType(int IneRowN,double*rowParam);
    virtual void SetColumnSimply_OwnType(int IneRowN,double*rowParam);
    //
    //void ArrayOf2DBy1D_AddIneRow(double*&X, Array2DSize& size, double DefaultVal, double*rowParam=NULL, int wholeRowL=0,                        TParamsOfDataShift*dataShiftParam=NULL,                              int ifNGTLmin_Ignore0AddToLast1StretchToMax2=0, int if_RowLNEQER_By2D2_ByMax3=2, bool SetRect=true){
                //void   AddIneRow(                              double DefaultVal, double*rowParam=NULL, int wholeRowL=0,                        TParamsOfDataShift*dataShiftParam=NULL,                              int ifNGTLmin_Ignore0AddToLast1StretchToMax2=0, int if_RowLNEQER_By2D2_ByMax3=2, bool SetRect=true);
                //void   AddIneRow(                                                 double*rowParam=NULL, int wholeRowL=0,                        TParamsOfDataShift*dataShiftParam=NULL, double*DefaultValParam=NULL, int ifNGTLmin_Ignore0AddToLast1StretchToMax2=0, int if_RowLNEQER_By2D2_ByMax3=2, bool SetRect=true);
                  void   AddIneRow(                                                 double*rowParam=NULL, int wholeRowL=0, double DefaultVal=0.0, TParamsOfDataShift*dataShiftParam=NULL,                              int ifNLNE_ByM1ByNewRow2ByMax3=1);
                //
                  void   AddColumn(                                                 double*rowParam=NULL, int wholeRowL=0, double DefaultVal=0.0, TParamsOfDataShift*dataShiftParam=NULL,                              int ifNLNE_ByM1ByNewRow2ByMax3=1);
    //
    //virtual void  AddIneRow_OwnType(double*rowParam=NULL, int wholeRowL=0, TParamsOfDataShift*dataShiftParam=NULL, double DefaultVal=0.0, int ifNLNE_ByM1ByNewRow2ByMax3=1)=0;
    //virtual void  AddColumn_OwnType(double*rowParam=NULL, int wholeRowL=0, TParamsOfDataShift*dataShiftParam=NULL, double DefaultVal=0.0, int ifNLNE_ByM1ByNewRow2ByMax3=1)=0;
    virtual void AddIneRow_OwnType(double*rowParam=NULL, int wholeRowL=0, TParamsOfDataShift*dataShiftParam=NULL, double DefaultVal=0.0, int ifNLNE_ByM1ByNewRow2ByMax3=1);
    virtual void AddColumn_OwnType(double*rowParam=NULL, int wholeRowL=0, TParamsOfDataShift*dataShiftParam=NULL, double DefaultVal=0.0, int ifNLNE_ByM1ByNewRow2ByMax3=1);
    //
    //void AddIneRow_Simply(double*rowParam);
    //void AddColumn_Simply(double*rowParam);
    //
    //virtual void AddIneRow_Simply_OwnType(double*rowParam)=0;
    virtual void AddIneRow_Simply_OwnType(double*rowParam);
    //
    //virtual void AddColumn_Simply_OwnType(double*rowParam)=0;
    virtual void AddColumn_Simply_OwnType(double*rowParam);
    //
    ////void ArrayOf2DBy1D_InsIneRowN(double*&X, Array2DSize& size, int IneRowN, double DefaultVal,double*rowParam=NULL, int wholeRowL=0,                                     TParamsOfDataShift*DataShiftParam=NULL, bool DefaulsAreSpecNotOwnVals=true, int if_LsNE_Ignore0_Resize_NewByOld_QERAndStretchIfShorter2_QEROrIRL_FromStartTillBreak3_All_NsBy2D4_NsByLongEnoughRows5_ByMaxQERAndStretchOrIRL6_OldByNew_FromStartAndStretchIfShorterAndTrimOrAddExt7=2, bool SetRectAnyway=true){
    ////                     void               InsIneRowN(                         int IneRowN, double DefaultVal,double*rowParam=NULL, int wholeRowL=0,                      TParamsOfDataShift*DataShiftParam=NULL, bool DefaulsAreSpecNotOwnVals=true,                         int if_LsNE_Ignore0_Resize_NewByOld_QERAndStretchIfShorter2_QEROrIRL_FromStartTillBreak3_All_NsBy2D4_NsByLongEnoughRows5_ByMaxQERAndStretchOrIRL6_OldByNew_FromStartAndStretchIfShorterAndTrimOrAddExt7=2, bool SetRectAnyway=true);
    ////                    void               InsIneRowN(                         int IneRowN,                     double*rowParam=NULL, int wholeRowL=0,                    TParamsOfDataShift*DataShiftParam=NULL, bool DefaulsAreSpecNotOwnVals=true,double*DefaultValParam=NULL, int if_LsNE_Ignore0_Resize_NewByOld_QERAndStretchIfShorter2_QEROrIRL_FromStartTillBreak3_All_NsBy2D4_NsByLongEnoughRows5_ByMaxQERAndStretchOrIRL6_OldByNew_FromStartAndStretchIfShorterAndTrimOrAddExt7=2, bool SetRectAnyway=true);
    //
    //                   void               InsIneRowN(                         int IneRowN, double DefaultVal,double*rowParam=NULL, int wholeRowL=0, double DefaultVal=0.0,TParamsOfDataShift*DataShiftParam=NULL, bool DefaulsAreSpecNotOwnVals=true,                          int ifNLNE_ByM1ByNewRow2ByMax3=1);
                         //
    //                   void                InsColumn(                         int IneRowN, double DefaultVal,double*rowParam=NULL, int wholeRowL=0, double DefaultVal=0.0,TParamsOfDataShift*DataShiftParam=NULL, bool DefaulsAreSpecNotOwnVals=true,                          int ifNLNE_ByM1ByNewRow2ByMax3=1);
    //
    virtual void InsIneRowN_OwnType(int IneRowN, double*rowParam, int wholeRowL=0, double DefaultVal=0.0,TParamsOfDataShift*DataShiftParam=NULL,                          int ifNLNE_ByM1ByNewRow2ByMax3=1);
    virtual void InsColumnN_OwnType(int IneRowN, double*rowParam, int wholeRowL=0, double DefaultVal=0.0,TParamsOfDataShift*DataShiftParam=NULL,                           int ifNLNE_ByM1ByNewRow2ByMax3=1);
                         //
    ////virtual void InsIneRow_Simply(int N, double*rowParam)=0;
    ////virtual void InsColumn_Simply(int N, double*rowParam)=0;
    //void InsIneRow_Simply(int N, double*rowParam);
    //void InsColumn_Simply(int N, double*rowParam);
    //
    //virtual void InsIneRow_Simply_OwnType(double*rowParam)=0;
    //virtual void InsIneRow_Simply_OwnType(double*rowParam)=0;
    virtual void InsIneRow_Simply_OwnType(int IneRowN, double*rowParam);
    virtual void InsColumn_Simply_OwnType(int ColN, double*rowParam);
    //
    ////void DelIneRowN(int N=-1, int ifNGTLmin_Ignore0_DelLast1_NurProperL_AnyExtRow3_NurFromStartTillFirstBreak4=0);
    //void DelIneRowN(int N=-1);
    //void DelColumn(int N=-1);
    //virtual void DelIneRow_Simply(int N=-1)=0;
    //virtual void DelColumn_Simply(int N=-1)=0;
    virtual void DelIneRow_Simply(int N=-1);
    virtual void DelColumn_Simply(int N=-1);
    //
    // Set Content
    //
    ////void Set(double**y, const Array2DSize& size,  bool WriteSize=true);
    ////void Set(double**y, std::vector<int>ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //////void Set(double**y, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    ////void Set(double**y, int QExtRows, int ExtRowsLength=1, bool sizeVaria=false, bool WriteSize=true);//SetSizeVaria-no need
    //
    ////void Set(double*y, const Array2DSize& size, bool WriteSize=true);
    ////void Set(double*y, std::vector<int>ExtRowsLengthes, bool WriteSize=true);
    ////void Set(double*y, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true,  bool WriteSize=true);
    ////void Set(double*y, int QExtRows, int ExtRowsLength=1,/* bool RectIfPossible=true,*/ bool sizeVaria=false, bool WriteSize=true);
    //
    ////void Set(std::vector<std::vector<double>>y, bool RectIfPossible=true, bool WriteSize=true);
    //
    ////void Set(std::vector<double>y, const Array2DSize& size, bool WriteSize=true);
    ////void Set(std::vector<double>y, std::vector<int>ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //
    ////void Set(std::vector<double>y, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    ////void Set(std::vector<double>y, int QExtRows, int ExtRowsLength=1,  bool sizeVaria=false, bool WriteSize=true);
    ////void Set(doubleval, const Array2DSize& size, bool WriteSize=true);
    ////void Set(doubleval, std::vector<int>ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    ////void Set(doubleval, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    ////void Set(double val, int QExtRows, int ExtRowsLength=1,  bool sizeVaria=false, bool WriteSize=true);
    //void Set_byEI(double**y, int QExtRows=1, int QIneRows=1);
    //void Set_byLC(double**y, int QLines=1, int QColumns=1);//by LC s'om param, ne om Matrix. F'Matrix s'SetComponent. Ors os ablb by EI, LC (zug o'Lines) et CL (zug o'Cols), ma nout CL, if LC s'Matrix order, f'Matrices' CL s'EI
    //void Set_byCL(double**y, int QLines=1, int QColumns=1);//CL sdi y s'zug o'cols
    //void Set_byEI(double*y, int QExtRows=1, int QIneRows=1);
    //void Set_byLC(double*y, int QLines=1, int QColumns=1);//by LC s'om param, ne om Matrix. F'Matrix s'SetComponent. Ors os ablb by EI, LC (zug o'Lines) et CL (zug o'Cols), ma nout CL, if LC s'Matrix order, f'Matrices' CL s'EI
    //void Set_byCL(double*y, int QLines=1, int QColumns=1);//CL=>-param s'zug o'cols
    //void Set_byEI(double val, int QExtRows=1, int ExtRowsLength=1);
    //void Set_byLC(double val, int QLines=1, int QColumns=1);
    //
    //void SwapVals_byEI(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
    //void SwapVals_byLC(int LineN1, int ColN1, int LineN2, int ColN2);
    //
    //void SwapExtRows(int N1, int N2);
    //
    //void SwapLines(int N1, int N2);
    //
    //void SwapIneRows(int N1, int N2);
    //
    //void SwapColumns(int N1, int N2);
    //
    //
    //void ReverseExtRowN(int rowN);
    //void ReverseLineN(int rowN);
    //void ReverseIneRowN(int rowN);
    //void ReverseColumnN(int rowN);
    //void ReverseExtRowsSuccession();
    //void ReverseLinesSuccession();
    //void ReverseIneRowsSuccession();
    //void ReverseColumnsSuccession();
    //
    //bool ValIsAtPos_byEI(double val, int ExtRowN, int IneRowN) const;
    //bool ValIsAtPos_byLC(double val, int LineN, int ColN) const;
    //swa S di n'fit prototype - obe s': alt IneRowN wa ExtRowN, so ExtRowN 2x, ce alt err
    ////std::vector<std::vector<int>> SeekVal(doubleval) const;
    ////std::vector<Int2DVectorOfSizeOrCoords> SeekVal(double val) const;
    //TListOfNumberPairs SeekVal_ByEI(double val) const;
    //TListOfNumberPairs SeekVal(double val) const;
    //so class name. Ma to vrns co std::vector ety di n'fit prototype
    //bool ExtRowIsAtPos(double*row, int Q, int ExtRowN, int IneRowN) const;
    //bool LineIsAtPos(double*row, int Q, int LineN,   int ColN) const;
    ////std::vector<std::vector<int>> SeekExtRow(double*row, int L) const;
    ////std::vector<Int2DVectorOfSizeOrCoords> SeekExtRow(double*row, int L) const;
    //TListOfNumberPairs SeekExtRow(double*row, int L) const;
    //TListOfNumberPairs SeekLine(double*row, int L) const;
    //bool IneRowIsAtPos(double*row, int Q, int ExtRowN, int IneRowN) const;
    //bool ColumnIsAtPos(double*row, int Q, int LineN, int ColN) const;
    ////std::vector<std::vector<int>> SeekIneRow(double*row, int Q) const;
    ////std::vector<Int2DVectorOfSizeOrCoords> SeekIneRow(double*row, int Q) const;
    //TListOfNumberPairs SeekIneRow(double*row, int Q) const;
    //TListOfNumberPairs SeekColumn(double*row, int Q) const;

    //bool Arr2DIsAtPos_byEI(std::vector<std::vector<double>>arr,             int ExtRowN, int IneRowN, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //bool Arr2DIsAtPos_byLC(std::vector<std::vector<double>>arr,             int LineN,   int ColN,    bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    ////bool Arr2DIsAtPos(std::vector<double>arr, const Array2DSize& size, int ExtRowN, int IneRowN, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    ////bool Arr2DIsAtPos(Matrix_Prototype*M,                      int ExtRowN, int IneRowN, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;

    //TListOfNumberPairs SeekArr2D_byEI(std::vector<std::vector<double>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
   // TListOfNumberPairs SeekArr2D_byLC(std::vector<std::vector<double>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;

    //std::vector<std::vector<int>> SeekArr2D(std::vector<std::vector<double>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //std::vector<Int2DVectorOfSizeOrCoords> SeekArr2D(std::vector<std::vector<double>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //TListOfNumberPairs SeekArr2D(std::vector<std::vector<double>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    ////std::vector<std::vector<int>> SeekArr2D(Matrix_Prototype*arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    ////std::vector<Int2DVectorOfSizeOrCoords> SeekArr2D(Matrix_Prototype*arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //TListOfNumberPairs SeekArr2D(Matrix_Prototype*obj, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //
    //
    //////void GetSubArray_As1DArr(double*&data,     int ExtRowN, int IneRowN, const Array2DSize& size, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //////std::vector<double> GetSubArray_As1DArr(   int ExtRowN, int IneRowN, const Array2DSize& size, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    ////std::vector<double> GetSubArray_As1DArr_byEI(int ExtRowN, int IneRowN, std::vector<int>Ls,         bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    ////std::vector<double> GetSubArray_As1DArr_byEI(int ExtRowN, int IneRowN, int QExtRows, int QIneRows, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    ////std::vector<double> GetSubArray_As1DArr_byLC(int LineN,   int ColumnN, std::vector<int>Ls,         bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    ////std::vector<double> GetSubArray_As1DArr_byLC(int LineN,   int ColumnN, int QExtRows, int QIneRows, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //////std::vector<double> GetSubArray_As1DArr(int LineN, int IneRowN, const Array2DSize& size, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;

    //////virtual Matrix_Prototype*GetSubArray(int ExtRowN, int IneRowN, const Array2DSize& size, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const=0;
    ////virtual Matrix_Prototype*   GetSubArray_byEI(int ExtRowN, int IneRowN, std::vector<int>Ls,         bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const=0;
    ////virtual Matrix_Prototype*   GetSubArray_byEI(int ExtRowN, int IneRowN, int QExtRows, int QIneRows, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const=0;
    ////virtual Matrix_Prototype*   GetSubArray_byLC(int LineN,   int ColumnN, std::vector<int>Ls,         bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const=0;
    ////virtual Matrix_Prototype*   GetSubArray_byLC(int LineN,   int ColumnN, int QExtRows, int QIneRows, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const=0;
    //
    //////void GetSubArray_AsSuccOfExtRows_As1DArr(double*&XR, Array2DSize& sizeR, double DefaultVal, TParamsOfDataShift*DataShiftParam=NULL,                          int DfltRowL_00_11_Lmin2_Lmax3=3) const;
    ////void GetSubArray_AsSuccOfExtRows_As1DArr(double*&XR, Array2DSize& sizeR,               TParamsOfDataShift*DataShiftParam=NULL,double*DefaultValParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3) const;
    ////std::vector<double> GetSubArray_AsSuccOfExtRows_As1DArr_byEI(                                 TParamsOfDataShift*DataShiftParam=NULL,                          double DefaultVal=0.0) const;
    ////std::vector<double> GetSubArray_AsSuccOfExtRows_As1DArr_byLC(                                 TParamsOfDataShift*DataShiftParam=NULL,                          double DefaultVal=0.0) const;
    ////std::vector<double> GetSubArray_AsSuccOfExtRows_As1DArr(Array2DSize& sizeR, double DefaultVal, DataShiftParams*DataShiftParam=NULL,                          int DfltRowL_00_11_Lmin2_Lmax3=3);
    ////std::vector<double> GetSubArray_AsSuccOfExtRows_As1DArr(Array2DSize& sizeR,               TParamsOfDataShift*DataShiftParam=NULL,double*DefaultValParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3);
    ////virtual Matrix_Prototype*GetSubArray_AsSuccOfExtRows(double DefaultVal, TParamsOfDataShift*DataShiftParam=NULL,                         int DfltRowL_00_11_Lmin2_Lmax3=3)=0;
    ////virtual Matrix_Prototype*GetSubArray_AsSuccOfExtRows(              TParamsOfDataShift*DataShiftParam=NULL, double*DefaultValParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3)=0;
    ////virtual   Matrix_Prototype*GetSubArray_AsSuccOfExtRows_byEI(              TParamsOfDataShift*DataShiftParam=NULL, double DefaultVal=0)=0;
    ////virtual   Matrix_Prototype*GetSubArray_AsSuccOfExtRows_byLC(              TParamsOfDataShift*DataShiftParam=NULL, double DefaultVal=0)=0;
    //
    //std::vector<double> SubMatrix_As1DArr_ByEINs_NurBelonging(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
    //std::vector<double> SubMatrix_As1DArr_ByLCNs_NurBelonging(int LineN1, int ColN1, int LineN2, int ColN2);
    //std::vector<double> SubMatrix_As1DArr_ByCLNs_NurBelonging(int LineN1, int ColN1, int LineN2, int ColN2);
    //std::vector<std::vector<double>> SubMatrix_As2DArr_ByEINs_NurBelonging(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
    //std::vector<std::vector<double>> SubMatrix_As2DArr_ByLCNs_NurBelonging(int LineN1, int ColN1, int LineN2, int ColN2);
    //std::vector<std::vector<double>> SubMatrix_As2DArr_ByCLNs_NurBelonging(int LineN1, int ColN1, int LineN2, int ColN2);

    //std::vector<std::vector<double>> SubMatrixAsSuccOfRows_AsArr2D_byEI(TParamsOfDataShift ShiftParams);
    //std::vector<std::vector<double>> SubMatrixAsSuccOfRows_AsArr2D_byEI(int QReq=0, int FromN=1, int QDefaultsBefore=0);

    //std::vector<std::vector<double>> SubMatrixAsSuccOfRows_AsArr2D_byLC(TParamsOfDataShift ShiftParams);
    //std::vector<std::vector<double>> SubMatrixAsSuccOfRows_AsArr2D_byLC(int QReq=0, int FromN=1, int QDefaultsBefore=0);
    //std::vector<std::vector<double>> SubMatrixAsSuccOfRows_AsArr2D_byCL(TParamsOfDataShift ShiftParams);
    //std::vector<std::vector<double>> SubMatrixAsSuccOfRows_AsArr2D_byCL(int QReq=0, int FromN=1, int QDefaultsBefore=0);

    //
    ////void ConcatAdding(Matrix_Prototype*obj, double DefaultVal,int QShiftedCols=0,  TParamsOfDataShift*DataShiftParam=NULL, bool SetRect=true, int DfltRowL_00_11_Lmin2_Lmax3=1);
    ////void ConcatAdding(Matrix_Prototype*obj, int QShiftedCols=0, TParamsOfDataShift*DataShiftParam=NULL,double*DefaultValParam=NULL, bool SetRect=true, int DfltRowL_00_11_Lmin2_Lmax3=1);
    //void ConcatAdding_byEI(Matrix_Prototype*obj,int QShiftedCols=0, TParamsOfDataShift*DataShiftParam=NULL, double DefaultVal=0);
    //void ConcatAdding_byLC(Matrix_Prototype*obj,int QShiftedCols=0, TParamsOfDataShift*DataShiftParam=NULL, double DefaultVal=0);
    ////_ConcatStretching(double*X1, const Array2DSize& size1,double*X2, const Array2DSize& size2,double*&X3, Array2DSize& size3, double DefaultVal, int shiftQ=0, TParamsOfDataShift*DataShiftParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3, bool Stretch1ToMax=true, bool SetRect=true){
    ////void ConcatStretching(Matrix_Prototype*obj, double DefaultVal, int QShiftedExtRowNs=0,  TParamsOfDataShift*DataShiftParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3, bool Stretch1ToMax=true, bool SetRect=true);
    ////void ConcatStretching(Matrix_Prototype*obj, int QShiftedExtRowNs=0, TParamsOfDataShift*DataShiftParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3, bool Stretch1ToMax=true, bool SetRect=true,double*DefaultValParam=NULL);
    //void ConcatStretching_byEI(Matrix_Prototype*obj,  int QShiftedLinesNs=0,  TParamsOfDataShift*DataShiftParam=NULL);//, double DefaultVal=0);
    //void ConcatStretching_byLC(Matrix_Prototype*obj,  int QShiftedLinesNs=0,  TParamsOfDataShift*DataShiftParam=NULL);//, double DefaultVal=0);
    //
    //
    ////void ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(double val, int ExtRowN, int IneRowN, double DefaultVal, bool SetRect=true, int DfltRowL_00_11_Max2_Min3=2);
    ////void ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(double val, int ExtRowN, int IneRowN, bool SetRect=true, int DfltRowL_00_11_Max2_Min3=2,double*DefaultValParam=NULL);
    //void ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore_byEI(double val, int ExtRowN, int ColN, double DefaultVal=0);
    //void ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(double val, int LineN, int ColN, double DefaultVal=0);
    //
    //void StdCout_ExtRowN(int ExtRowN, QString ElemsDelim="; ", bool UseBrackets=true)const;
    //void StdCout_IneRowN(int IneRowN, QString ElemsDelim="; ", bool UseBrackets=true, bool Represent2DNot1D=false)const;
    //void StdCout_LineN(int LineN, QString ElemsDelim="; ", bool UseBrackets=true)const;
    //void StdCout_ColumnN(int ColumnN, QString ElemsDelim="; ", bool UseBrackets=true, bool Represent2DNot1D=false)const;
    //void StdCout(QString ElemsDelim=", ", QString RowsDelim="; ", bool UseBrackets=true, bool Represent2DNot1D=true, bool ByExtRowsNotIneRows=true)const;
};



class Matrix{
    Matrix_Prototype*data;
public:
    //
    // Data functions
    //
    Matrix(int QLines=1, int QColumns=1, double data=0, int TypeN=MatrixTypeN_Default);
    Matrix(double*data, int QLines=1, int QColumns=1, int TypeN=MatrixTypeN_Default);
    Matrix(std::vector<double>data, int QLines=1,  int TypeN=MatrixTypeN_Default);
    Matrix(double**data, int QLines=1, int QColumns=1, int TypeN=MatrixTypeN_Default);
    Matrix(std::vector<std::vector<double>>data, int ifLNE_Lines_By_Max3Min4=4, int TypeN=MatrixTypeN_Default);
    Matrix(const Matrix&obj);
    Matrix(Matrix_Prototype*obj);
    ~Matrix();
    //
    void Assign(const Matrix&obj);
    void Assign(Matrix_Prototype*obj);
    //
    Matrix& operator = (const Matrix&obj);
    Matrix& operator = (Matrix_Prototype*obj);
    //
    Matrix_Prototype*GetData();
    //
    void SetNull();
    void construct(int TypeN=MatrixTypeN_Default);
    //virtual Matrix_Prototype* CreateArray() const=0;
    Matrix_Prototype* CreateMatrix() const;
    Matrix_Prototype* clone()const;
    int GetTypeN() const;
    //
    void SetTypeN(int TypeN);
    //
    void SetOne(double DfltVal=0);
    //
    ////virtual void SetLengthOfExtRowN(int ExtRowN, int newL, double DefaultVal=0)=0;//es SetSize f'ce
    ////virtual void SetLengthOfExtRowN(int ExtRowN, int newL,double*DefaultValParam=NULL)=0;
    //
    //virtual void SetSize(double DfltValParam, const Array2DSize&size)=0;
    //virtual void SetSize_Array(int QExtRows=1, int QIneRows=1, double DefaultVal=0.0)=0;
    //virtual void SetSize_Matrix(int QLines=1, int QColumns=1, double DefaultVal=0.0)=0;
    void SetSize_Array(int QExtRows=1, int QIneRows=1, double DefaultVal=0.0);
    void SetSize_Matrix(int QLines=1, int QColumns=1, double DefaultVal=0.0);
    //
    ////void SetSize(const Array2DSize&size,double*DfltValParam=NULL);//virtual ob hin Sdo mut l'size data
    ////void SetSize(int QExtRows, int ExtRowsLength,double*DfltValParam=NULL);
    ////void SetSize(int QExtRows=1, int*ExtRowsLengthes=NULL,double*DfltValParam=NULL);//if Null => L=0
    ////void SetSize(std::vector<int>ExtRowsLengthes,double*DfltValParam=NULL);
    //
    ////void SetSize(double DfltValParam, int QExtRows, int ExtRowsLength);//virtual ob hin Sdo mut l'size data
    ////void SetSize(double DfltValParam, int QExtRows=1, int*ExtRowsLengthes=NULL);//if Null => L=0
    ////void SetSize(double DfltValParam, std::vector<int>Lengthes);
    //
    ////virtual int GetQExtRows() const=0;
    ////virtual int GetLength(int ExtRowN=1) const=0;
    ////virtual int GetMinLength() const=0;
    ////virtual int GetMaxLength() const=0;
    //virtual int GetQExtRows() const=0;
    //virtual int GetLength() const=0;
    //virtual int GetQLines() const=0;
    //virtual int GetQColumns() const=0;
    int GetQExtRows() const;
    int GetLength() const;
    int GetQLines() const;
    int GetQColumns() const;
    //
    ////virtual Array2DSize GetSize()const =0;
    //
    ////bool LineNBelongsHere(int LineN) const;
    ////bool ColNBelongsHere(int ColN) const;
    bool NsBelongHere_byEI(int ExtRowN, int IneRowN) const;
    bool NsBelongHere_byLC(int LineN, int ColN) const;
    //
    ////std::vector<double> GetArrayOfExtRowN(int LineN);
    ////std::vector<double> GetArrayOfIneRowN(int ColN);
    ////std::vector<double> GetContentAsArray1D();
    ////std::vector<std::vector<double>> GetContentAsArray2D();
    //
    std::vector<double> GetExtRowN_AsArray(int rowN) const;
    ////double*GetExtRowN_AsPtr(int ExtRowN) const;
    std::vector<double> GetIneRowN_AsArray(int rowN) const;
    ////std::vector<double> GetIneRowN_AsArray(int IneRowN, double defaultVal,                               int ifNGTLmin_Ignore0_DefaultsForShorter1_NurProperL_AnyExtRow2_NurFromStartTillErstStop3=0) const;
    ////std::vector<double> GetIneRowN_AsArray(int IneRowN,                     double*DefaultValParam=NULL, int ifNGTLmin_Ignore0_DefaultsForShorter1_NurProperL_AnyExtRow2_NurFromStartTillErstStop3=0) const;
    ////std::vector<double> GetContent_AsArray1D() const;
    ////std::vector<std::vector<double>> GetContent_AsArray2D() const;
    std::vector<double> GetLineN_AsArray(int N) const;
    std::vector<double> GetColumnN_AsArray(int N) const;
    std::vector<double> GetContent_AsArray1D_ExtRows() const;
    std::vector<std::vector<double>> GetContent_AsArray2D_ExtRows() const;
    std::vector<double> GetContent_AsArray1D_Lines() const;
    std::vector<std::vector<double>> GetContent_AsArray2D_Lines() const;
    //
    //
    ////virtual double GetComponent_AsVal(int LineN, int ColN) const=0;
    //virtual double GetComponent_AsVal_byEI(int LineN, int ColN) const=0;
    //virtual double GetComponent(int LineN, int ColN) const=0;
    double GetComponent_AsVal_byEI(int LineN, int ColN) const;
    double GetComponent(int LineN, int ColN) const;
    ////virtual double* GetComponent_AsPtr(int LineN, int ColN) const=0;
    ////virtual double* GetComponent_AsPtr(int LineN, int ColN) const;
    //
    //virtual void SetComponent_byEI(double val, int ExtRowN, int IneRowN)=0;
    //virtual void SetComponent(double val, int LineN, int ColN)=0;
    void SetComponent_byEI(double val, int ExtRowN, int IneRowN);
    void SetComponent(double val, int LineN, int ColN);
    //
    ////void AddToExtRowN(int RowN, doubleval);
    ////void InsToExtRowN(int RowN, int PosN, doubleval);
    ////void DelFromExtRowN(int RowN, int PosN);
    //
    ////virtual void AddToExtRowN_Simply(int ExtRowN, doubleval)=0;
    ////virtual void InsToExtRowN_Simply(int ExtRowN, int PosN, doubleval)=0;
    ////virtual void DelFromExtRowN_Simply(int RowN, int IneRowPosN)=0;
    //
    // Ext row
    //
    //// void ArrayOf2DBy1D_SetExtRowN(double*&X, Array2DSize&size, int ExtRowN,       double DefaultVal,double*rowParam, int wholeRowL=0,                      TParamsOfDataShift*DataShiftParam=NULL, /*bool KeepIfRect=true,*/ bool DefaultIsSpecNotOwn=true,      int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2){
    ////virtual              void               SetExtRowN(                              int N, double defaultVal, double*rowParam,      int rowL,    TParamsOfDataShift*DataShiftParams=NULL,                          bool DefaulsAreSpecNotOwnVals=true, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2)=0;
    //
    void SetExtRowN(int N, double*rowParam=NULL, int rowL=0, double defaultVal=0.0, TParamsOfDataShift*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int ifNLNE_ByM1ByNewRow2ByMax3=1);
    //
    void SetExtRow_Simply(int N,double*rowParam);
    ////virtual void SetExtRow_Simply_OwnType(int N,double*rowParam);
    //
    void SetLineN  (                    int     N, double*rowParam, int rowL,        double defaultVal=0.0,TParamsOfDataShift*DataShiftParams=NULL,  bool DefaulsAreSpecNotOwnVals=true, int ifNLNE_ByM1ByNewRow2ByMax3=1);
    ////void Matrix_Prototype::SetLineN  (int LineN, double*rowParam, int rowL,        double defaultVal,    TParamsOfDataShift*DataShiftParams,       bool DefaulsAreSpecNotOwnVals,      int ifNLNE_ByM1ByNewRow2ByMax3)
    //
    ////virtual void SetLine_Simply_OwnType(int N, double*rowParam)=0;
    void SetLine_Simply(int N, double*rowParam);


    ////virtual void SetLine_Simply_OwnType(int N, double*rowParam)=0;
    //
    ////void ArrayOf2DBy1D_AddExtRow(double*&X, Array2DSize&size, double DefaultVal,double*rowParam, int wholeRowL=0,                             TParamsOfDataShift*DataShiftParam=NULL,                           int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL){
    ////void ArrayOf2DBy1D_AddExtRow(double*&X, Array2DSize&size,                   double*rowParam, int wholeRowL=0,double*DefaultValParam=NULL, TParamsOfDataShift*DataShiftParam=NULL,                           int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL){
    ////void  Matrix_Prototype::               AddLine(                             double*rowParam, int wholeRowL,                               TParamsOfDataShift*DataShiftParam,        double DefaultVal,      int ifNLNE_ByM1ByNewRow2ByMax3,                                                           TValsShowHide*vsh){
                          void             AddExtRow(                             double*rowParam, int wholeRowL=0,                             TParamsOfDataShift*DataShiftParam=NULL,   double DefaultVal=0.0,  int ifNLNE_ByM1ByNewRow2ByMax3=1,                                                         TValsShowHide*vsh=NULL);
                          //
                          void               AddLine(                             double*rowParam, int wholeRowL=0,                             TParamsOfDataShift*DataShiftParam=NULL,   double DefaultVal=0.0,  int ifNLNE_ByM1ByNewRow2ByMax3=1,                                                         TValsShowHide*vsh=NULL);
                          //
    //virtual              void     AddExtRow_OwnType(                             double*rowParam, int wholeRowL=0,                             TParamsOfDataShift*DataShiftParam=NULL,   double DefaultVal=0.0,  int ifNLNE_ByM1ByNewRow2ByMax3=1,                                                         TValsShowHide*vsh=NULL)=0;
    //virtual              void       AddLine_OwnType(                             double*rowParam, int wholeRowL=0,                             TParamsOfDataShift*DataShiftParam=NULL,   double DefaultVal=0.0,  int ifNLNE_ByM1ByNewRow2ByMax3=1,                                                         TValsShowHide*vsh=NULL)=0;
                          //
                          void     AddExtRow_OwnType(                             double*rowParam, int wholeRowL=0,                             TParamsOfDataShift*DataShiftParam=NULL,   double DefaultVal=0.0,  int ifNLNE_ByM1ByNewRow2ByMax3=1,                                                         TValsShowHide*vsh=NULL);
                          void       AddLine_OwnType(                             double*rowParam, int wholeRowL=0,                             TParamsOfDataShift*DataShiftParam=NULL,   double DefaultVal=0.0,  int ifNLNE_ByM1ByNewRow2ByMax3=1,                                                         TValsShowHide*vsh=NULL);
    ///virtual void AddExtRow_Simply(double*rowParam)=0;
    ////void AddExtRow_Simply(double*rowParam);
    //virtual void AddExtRow_Simply_OwnType(double*rowParam)=0;
    void AddExtRow_Simply_OwnType(double*rowParam);
    //
    //virtual void AddLine_Simply_OwnType(double*rowParam)=0;
    void AddLine_Simply_OwnType(double*rowParam);
    void AddLine_Simply(double*rowParam);
    //
    ////void ArrayOf2DBy1D_InsExtRow(double*&X, Array2DSize&size, int ExtRowN, double DefaultVal, double*rowParam=NULL, int wholeRowL=0,                           TParamsOfDataShift*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL){
    ////void ArrayOf2DBy1D_InsExtRow(double*&X, Array2DSize&size, int ExtRowN,                    double*rowParam=NULL, int wholeRowL=0, double*DfltValParam=NULL, TParamsOfDataShift*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL){
    //
    //                     void               InsExtRow(         int ExtRowN,                    double*rowParam=NULL, int wholeRowL=0,   double DefaultVal=0.0,  TParamsOfDataShift*DataShiftParam=NULL, int ifNLNE_ByM1ByNewRow2ByMax3=1,                                                        TValsShowHide*vsh=NULL);
                          //
    //                     void                 InsLine(         int ExtRowN,                    double*rowParam=NULL, int wholeRowL=0,   double DefaultVal=0.0,  TParamsOfDataShift*DataShiftParam=NULL, int ifNLNE_ByM1ByNewRow2ByMax3=1,                                                        TValsShowHide*vsh=NULL);
    //
                          void               InsExtRowN(         int ExtRowN,                    double*rowParam=NULL, int wholeRowL=0,    TParamsOfDataShift*DataShiftParam=NULL,   double DefaultVal=0.0, int ifNLNE_ByM1ByNewRow2ByMax3=1,                                   TValsShowHide*vsh=NULL);
                          void                 InsLineN(         int LineN,                      double*rowParam=NULL, int wholeRowL=0,    TParamsOfDataShift*DataShiftParam=NULL,   double DefaultVal=0.0, int ifNLNE_ByM1ByNewRow2ByMax3=1,                                   TValsShowHide*vsh=NULL);
    //virtual             void               InsExtRowN_OwnType( int ExtRowN,                    double*rowParam=NULL, int wholeRowL=0,    TParamsOfDataShift*DataShiftParam=NULL,   double DefaultVal=0.0, int ifNLNE_ByM1ByNewRow2ByMax3=1,                                   TValsShowHide*vsh=NULL)=0;
    //virtual             void                 InsLineN_OwnType( int LineN,                      double*rowParam=NULL, int wholeRowL=0,    TParamsOfDataShift*DataShiftParam=NULL,   double DefaultVal=0.0, int ifNLNE_ByM1ByNewRow2ByMax3=1,                                   TValsShowHide*vsh=NULL)=0;
                          void               InsExtRowN_OwnType( int ExtRowN,                    double*rowParam=NULL, int wholeRowL=0,    TParamsOfDataShift*DataShiftParam=NULL,   double DefaultVal=0.0, int ifNLNE_ByM1ByNewRow2ByMax3=1,                                   TValsShowHide*vsh=NULL);
                          void                 InsLineN_OwnType( int LineN,                      double*rowParam=NULL, int wholeRowL=0,    TParamsOfDataShift*DataShiftParam=NULL,   double DefaultVal=0.0, int ifNLNE_ByM1ByNewRow2ByMax3=1,                                   TValsShowHide*vsh=NULL);
    void InsExtRow_Simply(int N, double*rowParam);
    ////virtual void InsExtRow_Simply(int N,double*rowParam, int L)=0;
    //virtual void InsExtRow_Simply_OwnType(int N, double*rowParam)=0;
    void InsExtRow_Simply_OwnType(int N, double*rowParam);
    //
    ////virtual void InsLine_Simply(int N,double*rowParam)=0;
    void InsLine_Simply(int N,double*rowParam);
    ////virtual void InsLine_Simply_OwnType(int N,double*rowParam)=0;
    void InsLine_Simply_OwnType(int N,double*rowParam);
    //
    void DelExtRowN(int N=-1);
    void DelLineN(int N=-1);
    //virtual void DelExtRowN_Simply(int N=-1)=0;//OwnType
    void DelExtRowN_Simply(int N=-1);//OwnType
    //virtual void DelLineN_Simply(int N=-1)=0;//OwnType
    void DelLineN_Simply(int N=-1);//OwnType
    //
    //Ine row
    //
    //// void ArrayOf2DBy1D_SetIneRowN(double*&X, Array2DSize& size, int IneRowN, double DefaultVal,double*rowParam=NULL, int wholeRowL=0,                        TParamsOfDataShift*DataShiftParam=NULL,                       bool DefaulsAreSpecNotOwnVals=true,  int if_LsNE_Ignore0_Resize_NewByOld_QERAndStretchIfShorter2_QEROrIRL_FromStartTillBreak3_All_NsBy2D4_NsByLongEnoughRows5_ByMaxQERAndStretchOrIRL6_OldByNew_FromStartAndStretchIfShorterAndTrimOrAddExt7=2, bool SetRectAnyway=true){
    //
    //                       void               SetIneRowN(          int IneRowN,                   double*rowParam=NULL, int wholeRowL=0, double DefaultVal=0.0, TParamsOfDataShift*DataShiftParam=NULL,                       bool DefaulsAreSpecNotOwnVals=true,  int ifNLNE_ByM1ByNewRow2ByMax3=1);
    //
    //                       void               SetColumn (          int    ColN,                   double*rowParam=NULL, int wholeRowL=0, double DefaultVal=0.0, TParamsOfDataShift*DataShiftParam=NULL,                       bool DefaulsAreSpecNotOwnVals=true,  int ifNLNE_ByM1ByNewRow2ByMax3=1);
    //
                             void               SetIneRowN(          int IneRowN,                   double*rowParam=NULL, int wholeRowL=0,                        TParamsOfDataShift*DataShiftParam=NULL, double DefaultVal=0.0, bool DafaultsAreSpecNotOwnVals=true, int ifNLNE_ByM1ByNewRow2ByMax3=1,                                   TValsShowHide*vsh=NULL);
                             void               SetColumnN(          int ColumnN,                   double*rowParam=NULL, int wholeRowL=0,                        TParamsOfDataShift*DataShiftParam=NULL, double DefaultVal=0.0, bool DafaultsAreSpecNotOwnVals=true, int ifNLNE_ByM1ByNewRow2ByMax3=1,                                   TValsShowHide*vsh=NULL);
    ////virtual void SetIneRowSimply(int IneRowN,double*rowParam)=0;
    ////virtual void SetColumnSimply(int IneRowN,double*rowParam)=0;
    void SetIneRowSimply(int IneRowN,double*rowParam);
    void SetColumnSimply(int IneRowN,double*rowParam);
    //
    //virtual void  SetIneRow_OwnType(         int IneRowN,                                        double*rowParam, int wholeRowL=0, TParamsOfDataShift*dataShiftParam=NULL, bool DefaultsAreSpecNotOwnVals=true,  double DefaultVal=0.0,  int ifNLNE_ByM1ByNewRow2ByMax3=1)=0;
    //virtual void  SetColumn_OwnType(         int ColumnN,                                        double*rowParam, int wholeRowL=0, TParamsOfDataShift*dataShiftParam=NULL, bool DefaultsAreSpecNotOwnVals=true,  double DefaultVal=0.0,  int ifNLNE_ByM1ByNewRow2ByMax3=1)=0;
    //virtual void SetIneRowSimply_OwnType(int IneRowN,double*rowParam)=0;
    //virtual void SetColumnSimply_OwnType(int IneRowN,double*rowParam)=0;
    void  SetIneRow_OwnType(         int IneRowN,                                        double*rowParam, int wholeRowL=0, TParamsOfDataShift*dataShiftParam=NULL, bool DefaultsAreSpecNotOwnVals=true,  double DefaultVal=0.0,  int ifNLNE_ByM1ByNewRow2ByMax3=1);
    void  SetColumn_OwnType(         int ColumnN,                                        double*rowParam, int wholeRowL=0, TParamsOfDataShift*dataShiftParam=NULL, bool DefaultsAreSpecNotOwnVals=true,  double DefaultVal=0.0,  int ifNLNE_ByM1ByNewRow2ByMax3=1);
    void SetIneRowSimply_OwnType(int IneRowN,double*rowParam);
    void SetColumnSimply_OwnType(int IneRowN,double*rowParam);
    //
    ////void ArrayOf2DBy1D_AddIneRow(double*&X, Array2DSize& size, double DefaultVal, double*rowParam=NULL, int wholeRowL=0,                        TParamsOfDataShift*dataShiftParam=NULL,                              int ifNGTLmin_Ignore0AddToLast1StretchToMax2=0, int if_RowLNEQER_By2D2_ByMax3=2, bool SetRect=true){
              ////void   AddIneRow(                              double DefaultVal, double*rowParam=NULL, int wholeRowL=0,                        TParamsOfDataShift*dataShiftParam=NULL,                              int ifNGTLmin_Ignore0AddToLast1StretchToMax2=0, int if_RowLNEQER_By2D2_ByMax3=2, bool SetRect=true);
              ////void   AddIneRow(                                                 double*rowParam=NULL, int wholeRowL=0,                        TParamsOfDataShift*dataShiftParam=NULL, double*DefaultValParam=NULL, int ifNGTLmin_Ignore0AddToLast1StretchToMax2=0, int if_RowLNEQER_By2D2_ByMax3=2, bool SetRect=true);
              //// void   AddIneRow(                                                 double*rowParam=NULL, int wholeRowL=0, double DefaultVal=0.0, TParamsOfDataShift*dataShiftParam=NULL,                             int ifNLNE_ByM1ByNewRow2ByMax3=1);
                   void   AddIneRow(                                                 double*rowParam=NULL, int wholeRowL=0,                         TParamsOfDataShift*dataShiftParam=NULL, double DefaultVal=0.0,      int ifNLNE_ByM1ByNewRow2ByMax3=1);
                //
              //// void   AddColumn(                                                 double*rowParam=NULL, int wholeRowL=0, double DefaultVal=0.0, TParamsOfDataShift*dataShiftParam=NULL,                              int ifNLNE_ByM1ByNewRow2ByMax3=1);
                   void   AddColumn(                                                 double*rowParam=NULL, int wholeRowL=0,                        TParamsOfDataShift*dataShiftParam=NULL, double DefaultVal=0.0,       int ifNLNE_ByM1ByNewRow2ByMax3=1);
    //
    //virtual void  AddIneRow_OwnType(double*rowParam=NULL, int wholeRowL=0, TParamsOfDataShift*dataShiftParam=NULL, double DefaultVal=0.0, int ifNLNE_ByM1ByNewRow2ByMax3=1)=0;
    //virtual void  AddColumn_OwnType(double*rowParam=NULL, int wholeRowL=0, TParamsOfDataShift*dataShiftParam=NULL, double DefaultVal=0.0, int ifNLNE_ByM1ByNewRow2ByMax3=1)=0;
    void  AddIneRow_OwnType(double*rowParam=NULL, int wholeRowL=0, TParamsOfDataShift*dataShiftParam=NULL, double DefaultVal=0.0, int ifNLNE_ByM1ByNewRow2ByMax3=1);
    void  AddColumn_OwnType(double*rowParam=NULL, int wholeRowL=0, TParamsOfDataShift*dataShiftParam=NULL, double DefaultVal=0.0, int ifNLNE_ByM1ByNewRow2ByMax3=1);
    //
    void AddIneRow_Simply(double*rowParam);
    //
    void AddColumn_Simply(double*rowParam);
    //
    //virtual void AddIneRow_Simply_OwnType(double*rowParam)=0;
    void AddIneRow_Simply_OwnType(double*rowParam);
    //
    //virtual void AddColumn_Simply_OwnType(double*rowParam)=0;
    void AddColumn_Simply_OwnType(double*rowParam);
    //
    //void ArrayOf2DBy1D_InsIneRowN(double*&X, Array2DSize& size, int IneRowN, double DefaultVal,double*rowParam=NULL, int wholeRowL=0,                                     TParamsOfDataShift*DataShiftParam=NULL, bool DefaulsAreSpecNotOwnVals=true, int if_LsNE_Ignore0_Resize_NewByOld_QERAndStretchIfShorter2_QEROrIRL_FromStartTillBreak3_All_NsBy2D4_NsByLongEnoughRows5_ByMaxQERAndStretchOrIRL6_OldByNew_FromStartAndStretchIfShorterAndTrimOrAddExt7=2, bool SetRectAnyway=true){
    //                     void               InsIneRowN(                         int IneRowN, double DefaultVal,double*rowParam=NULL, int wholeRowL=0,                      TParamsOfDataShift*DataShiftParam=NULL, bool DefaulsAreSpecNotOwnVals=true,                         int if_LsNE_Ignore0_Resize_NewByOld_QERAndStretchIfShorter2_QEROrIRL_FromStartTillBreak3_All_NsBy2D4_NsByLongEnoughRows5_ByMaxQERAndStretchOrIRL6_OldByNew_FromStartAndStretchIfShorterAndTrimOrAddExt7=2, bool SetRectAnyway=true);
    //                    void               InsIneRowN(                         int IneRowN,                     double*rowParam=NULL, int wholeRowL=0,                    TParamsOfDataShift*DataShiftParam=NULL, bool DefaulsAreSpecNotOwnVals=true,double*DefaultValParam=NULL, int if_LsNE_Ignore0_Resize_NewByOld_QERAndStretchIfShorter2_QEROrIRL_FromStartTillBreak3_All_NsBy2D4_NsByLongEnoughRows5_ByMaxQERAndStretchOrIRL6_OldByNew_FromStartAndStretchIfShorterAndTrimOrAddExt7=2, bool SetRectAnyway=true);
    //
                         void               InsIneRowN(                         int IneRowN, double*rowParam=NULL, int wholeRowL=0, TParamsOfDataShift*DataShiftParam=NULL, double DefaultVal=0.0,                         int ifNLNE_ByM1ByNewRow2ByMax3=1);
                         //
                         void               InsColumnN(                         int ColumnN, double*rowParam=NULL, int wholeRowL=0, TParamsOfDataShift*DataShiftParam=NULL, double DefaultVal=0.0,                         int ifNLNE_ByM1ByNewRow2ByMax3=1);
    //
    //virtual void InsIneRowN_OwnType(int IneRowN, double*rowParam, int wholeRowL=0, double DefaultVal=0.0,TParamsOfDataShift*DataShiftParam=NULL,                          int ifNLNE_ByM1ByNewRow2ByMax3=1)=0;
    //virtual void InsColumnN_OwnType(int IneRowN, double*rowParam, int wholeRowL=0, double DefaultVal=0.0,TParamsOfDataShift*DataShiftParam=NULL,                           int ifNLNE_ByM1ByNewRow2ByMax3=1)=0;
    void InsIneRowN_OwnType(int IneRowN, double*rowParam, int wholeRowL=0, double DefaultVal=0.0,TParamsOfDataShift*DataShiftParam=NULL,                          int ifNLNE_ByM1ByNewRow2ByMax3=1);
    void InsColumnN_OwnType(int IneRowN, double*rowParam, int wholeRowL=0, double DefaultVal=0.0,TParamsOfDataShift*DataShiftParam=NULL,                           int ifNLNE_ByM1ByNewRow2ByMax3=1);
                                              //
    //virtual void InsIneRow_Simply(int N, double*rowParam)=0;
    //virtual void InsColumn_Simply(int N, double*rowParam)=0;
    void InsIneRow_Simply(int N, double*rowParam);
    void InsColumn_Simply(int N, double*rowParam);
    //
    //virtual void InsIneRow_Simply_OwnType(int IneRowN, double*rowParam)=0;
    //virtual void InsColumn_Simply_OwnType(int ColumnN, double*rowParam)=0;
    virtual void InsIneRow_Simply_OwnType(int IneRowN, double*rowParam);
    virtual void InsColumn_Simply_OwnType(int ColumnN, double*rowParam);
    //
    //void DelIneRowN(int N=-1, int ifNGTLmin_Ignore0_DelLast1_NurProperL_AnyExtRow3_NurFromStartTillFirstBreak4=0);
    void DelIneRowN(int N=-1);
    void DelColumnN(int N=-1);
    //virtual void DelIneRow_Simply(int N=-1)=0;
    //virtual void DelColumn_Simply(int N=-1)=0;
    void DelIneRow_Simply(int N=-1);
    void DelColumn_Simply(int N=-1);
    //
    // Set Content
    //
    ////void Set(double**y, const Array2DSize& size,  bool WriteSize=true);
    ////void Set(double**y, std::vector<int>ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //////void Set(double**y, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    ////void Set(double**y, int QExtRows, int ExtRowsLength=1, /* bool RectIfPossible=true,*/ bool sizeVaria=false, bool WriteSize=true);
    //
    ////void Set(double*y, const Array2DSize& size, bool WriteSize=true);
    ////void Set(double*y, std::vector<int>ExtRowsLengthes, bool WriteSize=true);
    ////void Set(double*y, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true,  bool WriteSize=true);
    ////void Set(double*y, int QExtRows, int ExtRowsLength=1,/* bool RectIfPossible=true,*/ bool sizeVaria=false, bool WriteSize=true);
    //
    ////void Set(std::vector<std::vector<double>>y, bool RectIfPossible=true, bool WriteSize=true);
    //
    ////void Set(std::vector<double>y, const Array2DSize& size, bool WriteSize=true);
    //void Set(std::vector<double>y, std::vector<int>ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //
    ////void Set(std::vector<double>y, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    ////void Set(std::vector<double>y, int QExtRows, int ExtRowsLength=1, /* bool RectIfPossible=true,*/ bool sizeVaria=false, bool WriteSize=true);
    ////void Set(doubleval, const Array2DSize& size, bool WriteSize=true);
    ////void Set(doubleval, std::vector<int>ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    ////void Set(doubleval, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    ////void Set(double val, int QExtRows, int ExtRowsLength=1, /* bool RectIfPossible=true,*/ bool sizeVaria=false, bool WriteSize=true);
    void Set_byEI(double**y, int QExtRows=1, int QIneRows=1, int TypeN=MatrixTypeN_Default);
    void Set_byLC(double**y, int QLines=1, int QColumns=1, int TypeN=MatrixTypeN_Default);//by LC s'om param, ne om Matrix. F'Matrix s'SetComponent. Ors os ablb by EI, LC (zug o'Lines) et CL (zug o'Cols), ma nout CL, if LC s'Matrix order, f'Matrices' CL s'EI
    void Set_byCL(double**y, int QLines=1, int QColumns=1, int TypeN=MatrixTypeN_Default);//CL sdi y s'zug o'cols
    void Set_byEI(double*y, int QExtRows=1, int QIneRows=1, int TypeN=MatrixTypeN_Default);
    void Set_byLC(double*y, int QLines=1, int QColumns=1, int TypeN=MatrixTypeN_Default);//by LC s'om param, ne om Matrix. F'Matrix s'SetComponent. Ors os ablb by EI, LC (zug o'Lines) et CL (zug o'Cols), ma nout CL, if LC s'Matrix order, f'Matrices' CL s'EI
    void Set_byCL(double*y, int QLines=1, int QColumns=1, int TypeN=MatrixTypeN_Default);//CL=>-param s'zug o'cols
    void Set_byEI(double val, int QExtRows=1, int ExtRowsLength=1, int MatrixTypeN_Default=MatrixTypeN_V1I);
    void Set_byLC(double val, int QLines=1, int QColumns=1, int TypeN=MatrixTypeN_Default);
    void Set_byEIR(std::vector<double>arr, int QExtRows, int TypeN=MatrixTypeN_Default);
    void Set_byLC(std::vector<double>arr, int QLines, int TypeN=MatrixTypeN_Default);
    void Set_byCL(std::vector<double>arr, int QColumns, int TypeN=MatrixTypeN_V1I);
    void Set_byEIR(std::vector<std::vector<double>>arr, int ifLNE_ExtRows_By_Max3Min4=4, int TypeN=MatrixTypeN_Default);
    void Set_byLC(std::vector<std::vector<double>>arr, int ifLNE_Lines_By_Max3Min4=4, int TypeN=MatrixTypeN_Default);
    void Set_byCL(std::vector<std::vector<double>>arr, int ifLNE_Lines_By_Max3Min4=4, int TypeN=MatrixTypeN_Default);
    //
    void SwapVals_byEI(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
    void SwapVals_byLC(int LineN1, int ColN1, int LineN2, int ColN2);
    //
    void SwapExtRows(int N1, int N2);
    //
    void SwapLines(int N1, int N2);
    //
    void SwapIneRows(int N1, int N2);
    //
    void SwapColumns(int N1, int N2);
    //
    //
    void ReverseExtRowN(int rowN);
    void ReverseLineN(int rowN);
    void ReverseIneRowN(int rowN);
    void ReverseColumnN(int rowN);
    void ReverseExtRowsSuccession();
    void ReverseLinesSuccession();
    void ReverseIneRowsSuccession();
    void ReverseColumnsSuccession();
    //
    bool ValIsAtPos_byEI(double val, int ExtRowN, int IneRowN) const;
    bool ValIsAtPos_byLC(double val, int LineN, int ColN) const;
    //swa S di n'fit prototype - obe s': alt IneRowN wa ExtRowN, so ExtRowN 2x, ce alt err
    ////std::vector<std::vector<int>> SeekVal(doubleval) const;
    ////std::vector<Int2DVectorOfSizeOrCoords> SeekVal(double val) const;
    TListOfNumberPairs SeekVal_ByEI(double val) const;
    TListOfNumberPairs SeekVal(double val) const;
    //so class name. Ma to vrns co std::vector ety di n'fit prototype
    bool ExtRowIsAtPos(double*row, int Q, int ExtRowN, int IneRowN) const;
    bool LineIsAtPos(double*row, int Q, int LineN,   int ColN) const;
    ////std::vector<std::vector<int>> SeekExtRow(double*row, int L) const;
    ////std::vector<Int2DVectorOfSizeOrCoords> SeekExtRow(double*row, int L) const;
    TListOfNumberPairs SeekExtRow(double*row, int L) const;
    TListOfNumberPairs SeekLine(double*row, int L) const;
    bool IneRowIsAtPos(double*row, int Q, int ExtRowN, int IneRowN) const;
    bool ColumnIsAtPos(double*row, int Q, int LineN, int ColN) const;
    ////std::vector<std::vector<int>> SeekIneRow(double*row, int Q) const;
    ////std::vector<Int2DVectorOfSizeOrCoords> SeekIneRow(double*row, int Q) const;
    TListOfNumberPairs SeekIneRow(double*row, int Q) const;
    TListOfNumberPairs SeekColumn(double*row, int Q) const;

    bool Arr2DIsAtPos_byEI(std::vector<std::vector<double>>arr,             int ExtRowN, int IneRowN, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    bool Arr2DIsAtPos_byLC(std::vector<std::vector<double>>arr,             int LineN,   int ColN,    bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    ////bool Arr2DIsAtPos(std::vector<double>arr, const Array2DSize& size, int ExtRowN, int IneRowN, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    ////bool Arr2DIsAtPos(Matrix_Prototype*M,                      int ExtRowN, int IneRowN, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;

    TListOfNumberPairs SeekArr2D_byEI(std::vector<std::vector<double>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    TListOfNumberPairs SeekArr2D_byLC(std::vector<std::vector<double>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;

    ////std::vector<std::vector<int>> SeekArr2D(std::vector<std::vector<double>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    ////std::vector<Int2DVectorOfSizeOrCoords> SeekArr2D(std::vector<std::vector<double>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //TListOfNumberPairs SeekArr2D(std::vector<std::vector<double>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    ////std::vector<std::vector<int>> SeekArr2D(Matrix_Prototype*arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    ////std::vector<Int2DVectorOfSizeOrCoords> SeekArr2D(Matrix_Prototype*arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //TListOfNumberPairs SeekArr2D(Matrix_Prototype*obj, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //
    //
    //////void GetSubArray_As1DArr(double*&data,     int ExtRowN, int IneRowN, const Array2DSize& size, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //////std::vector<double> GetSubArray_As1DArr(   int ExtRowN, int IneRowN, const Array2DSize& size, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    ////std::vector<double> GetSubArray_As1DArr_byEI(int ExtRowN, int IneRowN, std::vector<int>Ls,         bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    ////std::vector<double> GetSubArray_As1DArr_byEI(int ExtRowN, int IneRowN, int QExtRows, int QIneRows, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    ////std::vector<double> GetSubArray_As1DArr_byLC(int LineN,   int ColumnN, std::vector<int>Ls,         bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    ////std::vector<double> GetSubArray_As1DArr_byLC(int LineN,   int ColumnN, int QExtRows, int QIneRows, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //////std::vector<double> GetSubArray_As1DArr(int LineN, int IneRowN, const Array2DSize& size, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;

    //////virtual Matrix_Prototype*GetSubArray(int ExtRowN, int IneRowN, const Array2DSize& size, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const=0;
    ////virtual Matrix_Prototype*   GetSubArray_byEI(int ExtRowN, int IneRowN, std::vector<int>Ls,         bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const=0;
    ////virtual Matrix_Prototype*   GetSubArray_byEI(int ExtRowN, int IneRowN, int QExtRows, int QIneRows, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const=0;
    ////virtual Matrix_Prototype*   GetSubArray_byLC(int LineN,   int ColumnN, std::vector<int>Ls,         bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const=0;
    ////virtual Matrix_Prototype*   GetSubArray_byLC(int LineN,   int ColumnN, int QExtRows, int QIneRows, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const=0;
    //
    //////void GetSubArray_AsSuccOfExtRows_As1DArr(double*&XR, Array2DSize& sizeR, double DefaultVal, TParamsOfDataShift*DataShiftParam=NULL,                          int DfltRowL_00_11_Lmin2_Lmax3=3) const;
    //////void GetSubArray_AsSuccOfExtRows_As1DArr(double*&XR, Array2DSize& sizeR,               TParamsOfDataShift*DataShiftParam=NULL,double*DefaultValParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3) const;
    ////std::vector<double> GetSubArray_AsSuccOfExtRows_As1DArr_byEI(                                 TParamsOfDataShift*DataShiftParam=NULL,                          double DefaultVal=0.0) const;
    ////std::vector<double> GetSubArray_AsSuccOfExtRows_As1DArr_byLC(                                 TParamsOfDataShift*DataShiftParam=NULL,                          double DefaultVal=0.0) const;
    ////std::vector<double> GetSubArray_AsSuccOfExtRows_As1DArr(Array2DSize& sizeR, double DefaultVal, DataShiftParams*DataShiftParam=NULL,                          int DfltRowL_00_11_Lmin2_Lmax3=3);
    ////std::vector<double> GetSubArray_AsSuccOfExtRows_As1DArr(Array2DSize& sizeR,               TParamsOfDataShift*DataShiftParam=NULL,double*DefaultValParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3);
    ////virtual Matrix_Prototype*GetSubArray_AsSuccOfExtRows(double DefaultVal, TParamsOfDataShift*DataShiftParam=NULL,                         int DfltRowL_00_11_Lmin2_Lmax3=3)=0;
    ////virtual Matrix_Prototype*GetSubArray_AsSuccOfExtRows(              TParamsOfDataShift*DataShiftParam=NULL, double*DefaultValParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3)=0;
    ////virtual   Matrix_Prototype*GetSubArray_AsSuccOfExtRows_byEI(              TParamsOfDataShift*DataShiftParam=NULL, double DefaultVal=0)=0;
    ////virtual   Matrix_Prototype*GetSubArray_AsSuccOfExtRows_byLC(              TParamsOfDataShift*DataShiftParam=NULL, double DefaultVal=0)=0;
    //
    std::vector<double> SubMatrix_As1DArr_ByEINs_NurBelonging(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
    std::vector<double> SubMatrix_As1DArr_ByLCNs_NurBelonging(int LineN1, int ColN1, int LineN2, int ColN2);
    std::vector<double> SubMatrix_As1DArr_ByCLNs_NurBelonging(int LineN1, int ColN1, int LineN2, int ColN2);
    std::vector<std::vector<double>> SubMatrix_As2DArr_ByEINs_NurBelonging(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
    std::vector<std::vector<double>> SubMatrix_As2DArr_ByLCNs_NurBelonging(int LineN1, int ColN1, int LineN2, int ColN2);
    std::vector<std::vector<double>> SubMatrix_As2DArr_ByCLNs_NurBelonging(int LineN1, int ColN1, int LineN2, int ColN2);

    std::vector<std::vector<double>> SubMatrixAsSuccOfRows_AsArr2D_byEI(TParamsOfDataShift ShiftParams);
    std::vector<std::vector<double>> SubMatrixAsSuccOfRows_AsArr2D_byEI(int QReq=0, int FromN=1, int QDefaultsBefore=0);

    std::vector<std::vector<double>> SubMatrixAsSuccOfRows_AsArr2D_byLC(TParamsOfDataShift ShiftParams);
    std::vector<std::vector<double>> SubMatrixAsSuccOfRows_AsArr2D_byLC(int QReq=0, int FromN=1, int QDefaultsBefore=0);
    std::vector<std::vector<double>> SubMatrixAsSuccOfRows_AsArr2D_byCL(TParamsOfDataShift ShiftParams);
    std::vector<std::vector<double>> SubMatrixAsSuccOfRows_AsArr2D_byCL(int QReq=0, int FromN=1, int QDefaultsBefore=0);

    //
    ////void ConcatAdding(Matrix_Prototype*obj, double DefaultVal,int QShiftedCols=0,  TParamsOfDataShift*DataShiftParam=NULL, bool SetRect=true, int DfltRowL_00_11_Lmin2_Lmax3=1);
    ////void ConcatAdding(Matrix_Prototype*obj, int QShiftedCols=0, TParamsOfDataShift*DataShiftParam=NULL,double*DefaultValParam=NULL, bool SetRect=true, int DfltRowL_00_11_Lmin2_Lmax3=1);
    void ConcatAdding_byEI(Matrix_Prototype*obj,int QShiftedCols=0, TParamsOfDataShift*DataShiftParam=NULL, double DefaultVal=0);
    void ConcatAdding_byLC(Matrix_Prototype*obj,int QShiftedCols=0, TParamsOfDataShift*DataShiftParam=NULL, double DefaultVal=0);
    ////_ConcatStretching(double*X1, const Array2DSize& size1,double*X2, const Array2DSize& size2,double*&X3, Array2DSize& size3, double DefaultVal, int shiftQ=0, TParamsOfDataShift*DataShiftParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3, bool Stretch1ToMax=true, bool SetRect=true){
    ////void ConcatStretching(Matrix_Prototype*obj, double DefaultVal, int QShiftedExtRowNs=0,  TParamsOfDataShift*DataShiftParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3, bool Stretch1ToMax=true, bool SetRect=true);
    ////void ConcatStretching(Matrix_Prototype*obj, int QShiftedExtRowNs=0, TParamsOfDataShift*DataShiftParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3, bool Stretch1ToMax=true, bool SetRect=true,double*DefaultValParam=NULL);
    void ConcatStretching_byEI(Matrix_Prototype*obj,  int QShiftedLinesNs=0,  TParamsOfDataShift*DataShiftParam=NULL);//, double DefaultVal=0);
    void ConcatStretching_byLC(Matrix_Prototype*obj,  int QShiftedLinesNs=0,  TParamsOfDataShift*DataShiftParam=NULL);//, double DefaultVal=0);
    //
    //
    ////void ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(double val, int ExtRowN, int IneRowN, double DefaultVal, bool SetRect=true, int DfltRowL_00_11_Max2_Min3=2);
    ////void ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(double val, int ExtRowN, int IneRowN, bool SetRect=true, int DfltRowL_00_11_Max2_Min3=2,double*DefaultValParam=NULL);
    void ValSetOrAddOrFillOrIgnore_byEI(double val, int ExtRowN, int ColN);
    void ValSetOrAddOrFillOrIgnore(double val, int LineN, int ColN);
    //
    void StdCout_ExtRowN(int ExtRowN, QString ElemsDelim="; ", bool UseBrackets=true)const;
    void StdCout_IneRowN(int IneRowN, QString ElemsDelim="; ", bool UseBrackets=true, bool Represent2DNot1D=false)const;
    void StdCout_LineN(int LineN, QString ElemsDelim="; ", bool UseBrackets=true)const;
    void StdCout_ColumnN(int ColumnN, QString ElemsDelim="; ", bool UseBrackets=true, bool Represent2DNot1D=false)const;
    void StdCout(QString ElemsDelim=", ", QString RowsDelim="; ", bool UseBrackets=true, bool Represent2DNot1D=true, bool ByExtRowsNotIneRows=true)const;
    //
    //
    //
    void FillByNs();
    void SetDataOfVect3D(double x, double y, double z);
    void MakeVect3D(double x, double y, double z);
    void SetX(double val);
    void SetY(double val);
    void SetZ(double val);
    double GetX() const;
    double GetY() const;
    double GetZ() const;
    //
    // Mathematical functions
    //
    Matrix MinorTo(Matrix M, int LineN, int ColN);
    Matrix MinorTo(int LineN, int ColN);
    void Minor(int LineN, int ColumnN);
    double AlgSuppl(int LineN, int ColumnN) const;
    double Determinant() const;
    void MakeUnionMatrix();
    void Invert();
    Matrix CalcUnionMatrix() const;
    Matrix CalcInverted() const;

    Matrix CalcGivensRotationTransform(int N1, int N2, TValsShowHide*vsh=NULL);
    void QRDecomposition(Matrix&Q, Matrix&R, Matrix*M=NULL, TValsShowHide*vsh = NULL);
};

Matrix& operator + (const Matrix&M1, const Matrix&M2);
Matrix& operator - (const Matrix&M1, const Matrix&M2);
Matrix& operator * (const Matrix&M1, const Matrix&M2);
Matrix& operator * (const Matrix&M1, double k);
Matrix& operator * (double k, const Matrix&M2);
Matrix& operator / (const Matrix&M1, const Matrix&M2);

Matrix CalcMatrixOfDirCossByEulersAngles(double gamma, double psi, double theta);
Matrix CalcMatrixOfDirCossByEulersAnglesDeg(double gammaDeg, double psiDeg, double thetaDeg);
Matrix CalcMatrixOfDirCossByEulersAngles(const Matrix&MOfEulerAngles);
Matrix CalcMatrixOfDirCossByEulersAnglesDeg(const Matrix&MOfEulerAnglesDeg);

std::vector<int>LinesLinDepToDel(Matrix M, double eps=1E-6);

Matrix TransformCoordsFromGlobalToLocalCS(const Matrix&VectOfCoordsInLocalCS,  const Matrix&VectOfEulerAngles, Matrix*LocalCSOriginInGlobalCS=NULL);
Matrix TransformCoordsFromLocalToGlobalCS(const Matrix&VectOfCoordsInGlobalCS, const Matrix&VectOfEulerAngles, Matrix*LocalCSOriginInGlobalCS=NULL);


#endif // MATRICES1_H

