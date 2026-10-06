#ifndef MATRICES_H
#define MATRICES_H

#include"myarraylib.h"
#include"mymathlib.h"


/*class Matrices
{
public:
    Matrices();
};*/

// TmpltArr/OwnInner P/V 2D/1D L/I L/C



const int Matrix_TmpltArr_P2L_ArrOfLines_TypeN=11211;
const int Matrix_TmpltArr_P2I_ArrOfLines_TypeN=11221;
const int Matrix_TmpltArr_V2L_ArrOfLines_TypeN=12211;
const int Matrix_TmpltArrr_V2I_ArrOfLines_TypeN=12221;
const int Matrix_OwnInner_P2L_ArrOfColumns_TypeN=21212;
const int Matrix_OwnInner_P2I_ArrOfColumns_TypeN=21222;
const int Matrix_OwnInner_V2L_ArrOfColumns_TypeN=22212;
const int Matrix_OwnInner_V2I_ArrOfColumns_TypeN=22222;
const int Matrix_TmpltArr_P1L_ArrOfLines_TypeN=11111;
const int Matrix_TmpltArr_P1I_ArrOfLines_TypeN=11121;
const int Matrix_TmpltArrr_V1L_ArrOfLines_TypeN=12111;
const int Matrix_TmpltArrr_V1I_ArrOfLines_TypeN=12121;
const int Matrix_OwnInner_P1L_ArrOfColumns_TypeN=21112;
const int Matrix_OwnInner_P1I_ArrOfColumns_TypeN=21122;
const int Matrix_OwnInner_V1L_ArrOfColumns_TypeN=22112;
const int Matrix_OwnInner_V1I_ArrOfColumns_TypeN=22122;

const int Matrix_TmpltArr2DShell_ArrOfLines_TypeN=11;
const int Matrix_TmpltArr2DShell_ArrOfColumns_TypeN=12;

/*class Matrix_Prototype{


    virtual ~Matrix_Prototype()=default;
    //
    virtual void SetNull()=0;
    virtual void construct()=0;
    virtual Matrix_Prototype* CreateArray() const=0;
    virtual Matrix_Prototype* clone()const=0;
    virtual int GetTypeN() const=0 ;
    //
    void SetOne(T*DfltVal=NULL);
    void SetOne(const T&DfltVal);
    //
    virtual void SetSize(const T& DfltValParam, const Array2DSize&size)=0;
    //
    void SetSize(const Array2DSize&size, T*DfltValParam=NULL);//virtual ob hin Sdo mut l'size data
    void SetSize(int QExtRows=1, int ExtRowsLength=1, T*DfltValParam=NULL);
    void SetSize(int QExtRows=1, int*ExtRowsLengthes=NULL, T*DfltValParam=NULL);//if Null => L=0
    void SetSize(std::vector<int>ExtRowsLengthes, T*DfltValParam=NULL);
    //
    void SetSize(const T& DfltValParam, int QExtRows=1, int ExtRowsLength=1);//virtual ob hin Sdo mut l'size data
    void SetSize(const T& DfltValParam, int QExtRows=1, int*ExtRowsLengthes=NULL);//if Null => L=0
    void SetSize(const T& DfltValParam, std::vector<int>Lengthes);
    //
    virtual int GetQExtRows() const=0;
    virtual int GetLength(int ExtRowN=1) const=0;
    virtual int GetMinLength() const=0;
    virtual int GetMaxLength() const=0;
    //
    virtual Array2DSize GetSize()const =0;
    //
    //bool LineNBelongsHere(int LineN) const;
    //bool ColNBelongsHere(int ColN) const;
    bool NsBelongHere(int ExtRowN, int IneRowN) const;
    //
    //std::vector<T> GetArrayOfExtRowN(int LineN);
    //std::vector<T> GetArrayOfIneRowN(int ColN);
    //std::vector<T> GetContentAsArray1D();
    //std::vector<std::vector<T>> GetContentAsArray2D();
    //
    std::vector<T> GetExtRowN_AsArray(int rowN) const;
    // T*GetExtRowN_AsPtr(int ExtRowN) const;
    std::vector<T> GetIneRowN_AsArray(int rowN) const;
    std::vector<T> GetIneRowN_AsArray(int IneRowN, const T& defaultVal,                         int ifNGTLmin_Ignore0_DefaultsForShorter1_NurProperL_AnyExtRow2_NurFromStartTillErstStop3=0) const;
    std::vector<T> GetIneRowN_AsArray(int IneRowN,                      T*DefaultValParam=NULL, int ifNGTLmin_Ignore0_DefaultsForShorter1_NurProperL_AnyExtRow2_NurFromStartTillErstStop3=0) const;
    std::vector<T> GetContent_AsArray1D() const;
    std::vector<std::vector<T>> GetContent_AsArray2D() const;
    //
    //
    virtual T GetComponent_AsVal(int LineN, int ColN) const=0;
    virtual T* GetComponent_AsPtr(int LineN, int ColN) const=0;
    //
    virtual void SetComponent(const T& val, int LineN, int ColN)=0;
    //
    void AddToExtRowN(int RowN, const T&val);
    void InsToExtRowN(int RowN, int PosN, const T&val);
    void DelFromExtRowN(int RowN, int PosN);
    //
    virtual void AddToExtRowN_Simply(int ExtRowN, const T&val)=0;
    virtual void InsToExtRowN_Simply(int ExtRowN, int PosN, const T&val)=0;
    virtual void DelFromExtRowN_Simply(int RowN, int IneRowPosN)=0;
    //
    // Ext row
    //
    ////template<typename T> void ArrayOf2DBy1D_SetExtRowN(T*&X, Array2DSize&size, int ExtRowN,       T DefaultVal, T*rowParam, int wholeRowL=0,                      TDataShiftParams*DataShiftParam=NULL, bool KeepIfRect=true, bool DefaultIsSpecNotOwn=true,      int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2){
    //virtual              void               SetExtRowN(                              int N, const T& defaultVal,  T*rowParam,      int rowL,    TDataShiftParams*DataShiftParams=NULL,                          bool DefaulsAreSpecNotOwnVals=true, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2)=0;
    void SetExtRowN(int N, const T& defaultVal, T*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true,                      int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2);
    void SetExtRowN(int N,                      T*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, T*DfltValParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2);
    //
    void SetExtRow_Simply(int N, T*rowParam)=0;
    void SetExtRow_Simply(int N, T*rowParam, int L)=0;
    //
    //template<typename T>void ArrayOf2DBy1D_AddExtRow(T*&X, Array2DSize&size, T DefaultVal, T*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL){
                          void               AddExtRow(                        T DefaultVal, T*rowParam, int wholeRowL=0,                         TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL);
    //template<typename T>void ArrayOf2DBy1D_AddExtRow(T*&X, Array2DSize&size, T*rowParam, int wholeRowL=0, T*DefaultValParam=NULL, TDataShiftParams*DataShiftParam=NULL,  int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL){
                          void               AddExtRow(                                      T*rowParam, int wholeRowL=0, T*DefaultValParam=NULL, TDataShiftParams*DataShiftParam=NULL,  int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL);
    //
    virtual void AddExtRow_Simply(T*rowParam)=0;
    virtual void AddExtRow_Simply(T*rowParam, int L)=0;
    //
    //template<typename T>void ArrayOf2DBy1D_InsExtRow(T*&X, Array2DSize&size, int ExtRowN, T DefaultVal, T*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL){
                          void               InsExtRow(                        int ExtRowN, T DefaultVal, T*rowParam, int wholeRowL=0,                      TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL);
    //template<typename T>void ArrayOf2DBy1D_InsExtRow(T*&X, Array2DSize&size, int ExtRowN, T*rowParam, int wholeRowL=0,  T*DfltValParam=NULL, TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL){
                          void               InsExtRow(                        int ExtRowN,               T*rowParam, int wholeRowL=0, T*DfltValParam=NULL, TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL);
    //
    virtual void InsExtRow_Simply(int N, T*rowParam)=0;
    virtual void InsExtRow_Simply(int N, T*rowParam, int L)=0;
    //
    void DelExtRowN(int N=-1);
    virtual void DelExtRowN_Simply(int N=-1)=0;
    //
    //Ine row
    //
    void SetIneRowN( int IneRowN, const T& defaultVal, T*rowParam=NULL, int rowL=0, TDataShiftParams*DataShiftParam=NULL,                         bool DefaulsAreSpecNotOwnVals=true, int arr2D_ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_AnyExtRow3_NurFromStartTillErstStop4=0, int arr1D_ifNurProperL_NsSame1_EltsWithNsOfShoeterExtRowsNeUsed2=1);
    void SetIneRowN( int IneRowN,                      T*rowParam=NULL, int rowL=0, TDataShiftParams*DataShiftParam=NULL, T*DefaultValParam=NULL, bool DefaulsAreSpecNotOwnVals=true, int arr2D_ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_AnyExtRow3_NurFromStartTillErstStop4=0, int arr1D_ifNurProperL_NsSame1_EltsWithNsOfShoeterExtRowsNeUsed2=1);
    //
    virtual void SetIneRowSimply(int IneRowN, T*rowParam)=0;
    //
    //template<typename T>void ArrayOf2DBy1D_AddIneRow(T*&X, Array2DSize& size, T DefaultVal, T*rowParam=NULL, int wholeRowL=0, TDataShiftParams*dataShiftParam=NULL,                         int ifNGTLmin_Ignore0AddToLast1StretchToMax2=0, bool RectIfPossible=true){
                         void               AddIneRow(                         T DefaultVal, T*rowParam=NULL, int wholeRowL=0, TDataShiftParams*dataShiftParam=NULL,                         int ifNGTLmin_Ignore0AddToLast1StretchToMax2=0, bool RectIfPossible=true)=0;
                         void               AddIneRow(                                       T*rowParam=NULL, int wholeRowL=0, TDataShiftParams*dataShiftParam=NULL, T*DefaultValParam=NULL, int ifNGTLmin_Ignore0AddToLast1StretchToMax2=0, bool RectIfPossible=true)=0;
    //
    virtual void AddIneRow_Simply(T*rowParam)=0;
    //
    //template<typename T>void ArrayOf2DBy1D_InsIneRowN(T*&X, Array2DSize& size, int IneRowN, T DefaultVal, T*rowParam=NULL, int wholeRowL=0,                         TDataShiftParams*DataShiftParam=NULL, int ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_ValForShorterIsMissedForNsFitKeeping3_NextNewValToNextProperL4=1){
                          void               InsIneRowN(                         int IneRowN, T DefaultVal, T*rowParam=NULL, int wholeRowL=0,                         TDataShiftParams*DataShiftParam=NULL, int arr2D_ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_AnyExtRow3_NurFromStartTillErstStop4=0, int arr1D_ifNurProperL_NsSame1_EltsWithNsOfShoeterExtRowsNeUsed2=1);
                          void               InsIneRowN(                         int IneRowN,               T*rowParam=NULL, int wholeRowL=0, T*DefaultValParam=NULL, TDataShiftParams*DataShiftParam=NULL, int arr2D_ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_AnyExtRow3_NurFromStartTillErstStop4=0, int arr1D_ifNurProperL_NsSame1_EltsWithNsOfShoeterExtRowsNeUsed2=1);
    //
    virtual void InsIneRow_Simply(int N, T*rowParam)=0;
    //
    void DelIneRowN(int N=-1, int ifNGTLmin_Ignore0_DelLast1_NurProperL_AnyExtRow3_NurFromStartTillFirstBreak4=0);
    virtual void DelIneRow_Simply(int N=-1)=0;
    //
    // Set Content
    //
    void Set(T**y, const Array2DSize& size,  bool WriteSize=true);
    void Set(T**y, std::vector<int>ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    void Set(T**y, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    void Set(T**y, int QExtRows, int ExtRowsLength=1, bool RectIfPossible=true, bool WriteSize=true);
    void Set(T*y, const Array2DSize& size, bool WriteSize=true);
    void Set(T*y, std::vector<int>ExtRowsLengthes, bool WriteSize=true);
    void Set(T*y, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true,  bool WriteSize=true);
    void Set(T*y, int QExtRows, int ExtRowsLength=1, bool RectIfPossible=true, bool sizeVaria=false, bool WriteSize=true);
    void Set(std::vector<std::vector<T>>y, bool RectIfPossible=true, bool WriteSize=true);
    void Set(std::vector<T>y, const Array2DSize& size, bool WriteSize=true);
    void Set(std::vector<T>y, std::vector<int>ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    void Set(std::vector<T>y, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    void Set(std::vector<T>y, int QExtRows, int ExtRowsLength=1, bool RectIfPossible=true, bool WriteSize=true);
    void Set(const T&val, const Array2DSize& size, bool WriteSize=true);
    void Set(const T&val, std::vector<int>ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    void Set(const T&val, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    void Set(const T&val, int QExtRows, int ExtRowsLength=1, bool RectIfPossible=true, bool WriteSize=true);
    //
    void SwapVals(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
    //
    void SwapExtRows(int N1, int N2);
    void SwapIneRows(int N1, int N2);
    //
    void ReverseExtRowN(int rowN);//wa virtual...=0, nu n'tak
    void ReverseIneRowN(int rowN);//wa virtual...=0, nu n'tak
    virtual void ReverseExtRowsSuccession()=0;
    virtual void ReverseIneRowsSuccession()=0;
    //
    bool ValIsAtPos(const T&val, int ExtRowN, int IneRowN) const;
    //swa S di n'fit prototype - obe s': alt IneRowN wa ExtRowN, so ExtRowN 2x, ce alt err
    //std::vector<std::vector<int>> SeekVal(const T&val) const;
    //std::vector<Int2DVectorOfSizeOrCoords> SeekVal(const T&val) const;
    TListOfNumberPairs SeekVal(const T&val) const;
    //so class name. Ma to vrns co std::vector ety di n'fit prototype
    bool ExtRowIsAtPos(T*row, int Q, int ExtRowN, int IneRowN) const;
    //std::vector<std::vector<int>> SeekExtRow(T*row, int L) const;
    //std::vector<Int2DVectorOfSizeOrCoords> SeekExtRow(T*row, int L) const;
    TListOfNumberPairs SeekExtRow(T*row, int L) const;
    bool IneRowIsAtPos(T*row, int Q, int ExtRowN, int IneRowN) const;
    //std::vector<std::vector<int>> SeekIneRow(T*row, int Q) const;
    //std::vector<Int2DVectorOfSizeOrCoords> SeekIneRow(T*row, int Q) const;
    TListOfNumberPairs SeekIneRow(T*row, int Q) const;

    bool Arr2DIsAtPos(std::vector<std::vector<T>>arr, int ExtRowN, int IneRowN, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    bool Arr2DIsAtPos(Matrix_Prototype*arr, int ExtRowN, int IneRowN, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;

    //std::vector<std::vector<int>> SeekArr2D(std::vector<std::vector<T>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //std::vector<Int2DVectorOfSizeOrCoords> SeekArr2D(std::vector<std::vector<T>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    TListOfNumberPairs SeekArr2D(std::vector<std::vector<T>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //std::vector<std::vector<int>> SeekArr2D(Array2D_Prototype*arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //std::vector<Int2DVectorOfSizeOrCoords> SeekArr2D(Array2D_Prototype*arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    TListOfNumberPairs SeekArr2D(Matrix_Prototype*obj, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //
    virtual void ConcatAdding(Matrix_Prototype*obj, T DefaultVal,int QShiftedCols=0,  TDataShiftParams*DataShiftParam=NULL, bool SetRect=true, int DfltRowL_00_11_Lmin2_Lmax3=1);
    virtual void ConcatAdding(Matrix_Prototype*obj, int QShiftedCols=0, TDataShiftParams*DataShiftParam=NULL, T*DefaultValParam=NULL, bool SetRect=true, int DfltRowL_00_11_Lmin2_Lmax3=1);
    //_ConcatStretching(T*X1, const Array2DSize& size1, T*X2, const Array2DSize& size2, T*&X3, Array2DSize& size3, T DefaultVal, int shiftQ=0, TDataShiftParams*DataShiftParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3, bool Stretch1ToMax=true, bool SetRect=true){
    virtual void ConcatStretching(Matrix_Prototype*obj, T DefaultVal, int QShiftedExtRowNs=0,  TDataShiftParams*DataShiftParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3, bool Stretch1ToMax=true, bool SetRect=true);
    virtual void ConcatStretching(Matrix_Prototype*obj, int QShiftedExtRowNs=0, TDataShiftParams*DataShiftParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3, bool Stretch1ToMax=true, bool SetRect=true, T*DefaultValParam=NULL);
    //
    virtual Matrix_Prototype*GetSubArray(int ExtRowN, int IneRowN, const Array2DSize& size, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const=0;
    //
    void ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(T val, int ExtRowN, int IneRowN, T DefaultVal, bool SetRect=true, int DfltRowL_00_11_Max2_Min3=2);
    void ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(T val, int ExtRowN, int IneRowN, bool SetRect=true, int DfltRowL_00_11_Max2_Min3=2, T*DefaultValParam=NULL);
    //
    void StdCout_ExtRowN(int ExtRowN, QString ElemsDelim="; ", bool UseBrackets=true)const;
    void StdCout_IneRowN(int IneRowN, QString ElemsDelim="; ", bool UseBrackets=true, bool Represent2DNot1D=false)const;
    void StdCout(QString ElemsDelim=", ", QString RowsDelim="; ", bool UseBrackets=true, bool Represent2DNot1D=true, bool ByExtRowsNotIneRows=true)const;
};*/


class Matrix_Prototype{
public:
    virtual ~Matrix_Prototype()=default;
    //
    virtual void SetNull()=0;
    virtual void construct()=0;
    virtual Matrix_Prototype* CreateMatrix() const=0;
    virtual Matrix_Prototype* clone()const=0;
    //virtual Matrix_Prototype* GetData()const=0;
    virtual int GetTypeN() const=0 ;
    //
    //void SetOne(T*DfltVal=NULL);
    //void SetOne(const T&DfltVal);
    void SetOne();
    //
     //virtual void SetSize(const T& DfltValParam, const Array2DSize&size)=0;
    //
    //void SetSize(const Array2DSize&size, T*DfltValParam=NULL);//virtual ob hin Sdo mut l'size data
    //void SetSize(int QExtRows=1, int ExtRowsLength=1, T*DfltValParam=NULL);
    //void SetSize(int QExtRows=1, int*ExtRowsLengthes=NULL, T*DfltValParam=NULL);//if Null => L=0
    //void SetSize(std::vector<int>ExtRowsLengthes, T*DfltValParam=NULL);
    //
    //void SetSize(const T& DfltValParam, int QExtRows=1, int ExtRowsLength=1);//virtual ob hin Sdo mut l'size data
    //void SetSize(const T& DfltValParam, int QExtRows=1, int*ExtRowsLengthes=NULL);//if Null => L=0
    //void SetSize(const T& DfltValParam, std::vector<int>Lengthes);
    //
    virtual void SetSize(int QExtRows=1, int ExtRowsLength=1)=0;
    //
    //virtual int GetQExtRows() const=0;
    //virtual int GetLength(int ExtRowN=1) const=0;
    //virtual int GetMinLength() const=0;
    //virtual int GetMaxLength() const=0;
    virtual int GetQLines()const=0 ;
    virtual int GetQColumns()const=0 ;
    //virtual Array2DSize GetSize()const =0;
    //
    //bool LineNBelongsHere(int LineN) const;
    //bool ColNBelongsHere(int ColN) const;
    bool NsBelongHere(int ExtRowN, int IneRowN) const;
    //
    //std::vector<T> GetArrayOfExtRowN(int LineN);
    //std::vector<T> GetArrayOfIneRowN(int ColN);
    //std::vector<T> GetContentAsArray1D();
    //std::vector<std::vector<T>> GetContentAsArray2D();
    //
    //std::vector<T> GetExtRowN_AsArray(int rowN) const;
    std::vector<double> GetLineN_AsArray(int rowN) const;
    // T*GetExtRowN_AsPtr(int ExtRowN) const;
    //std::vector<T> GetIneRowN_AsArray(int rowN) const;
    std::vector<double> GetColumnN_AsArray(int rowN) const;
    //std::vector<T> GetIneRowN_AsArray(int IneRowN, const T& defaultVal,                         int ifNGTLmin_Ignore0_DefaultsForShorter1_NurProperL_AnyExtRow2_NurFromStartTillErstStop3=0) const;
    //std::vector<T> GetIneRowN_AsArray(int IneRowN,                      T*DefaultValParam=NULL, int ifNGTLmin_Ignore0_DefaultsForShorter1_NurProperL_AnyExtRow2_NurFromStartTillErstStop3=0) const;
    //std::vector<T> GetContent_AsArray1D() const;
    //std::vector<std::vector<T>> GetContent_AsArray2D() const;
    std::vector<double> GetContent_AsArray1DOfLines() const;
    std::vector<double> GetContent_AsArray1DOfColumns() const;
    std::vector<std::vector<double>> GetContent_AsArray2DOfLines() const;
    std::vector<std::vector<double>> GetContent_AsArray2DOfColumns() const;
    //
    //
    //virtual T GetComponent_AsVal(int LineN, int ColN) const=0;
    //virtual T* GetComponent_AsPtr(int LineN, int ColN) const=0;
    virtual double GetComponent(int LineN, int ColN) const=0;
    //virtual double* GetComponent_AsPtr(int LineN, int ColN) const=0;
    //
    //virtual void SetComponent(const T& val, int LineN, int ColN)=0;
    virtual void SetComponent(double val, int LineN, int ColN)=0;
    //
    //void AddToExtRowN(int RowN, const T&val);
    //void InsToExtRowN(int RowN, int PosN, const T&val);
    //void DelFromExtRowN(int RowN, int PosN);
    //
    //virtual void AddToExtRowN_Simply(int ExtRowN, const T&val)=0;
    //virtual void InsToExtRowN_Simply(int ExtRowN, int PosN, const T&val)=0;
    //virtual void DelFromExtRowN_Simply(int RowN, int IneRowPosN)=0;
    //
    // Ext row
    //
    //template<typename T> void ArrayOf2DBy1D_SetExtRowN(T*&X, Array2DSize&size, int ExtRowN,       T DefaultVal, T*rowParam, int wholeRowL=0,                      TDataShiftParams*DataShiftParam=NULL, /*bool KeepIfRect=true,*/ bool DefaultIsSpecNotOwn=true,      int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2){
    //virtual              void               SetExtRowN(                              int N, const T& defaultVal,  T*rowParam,      int rowL,    TDataShiftParams*DataShiftParams=NULL,                          bool DefaulsAreSpecNotOwnVals=true, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2)=0;
    //void SetExtRowN(int N, const T& defaultVal, T*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true,                      int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2);
    //void SetExtRowN(int N,                      T*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, T*DfltValParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2);
    //
    //void SetExtRow_Simply(int N, T*rowParam)=0;
    //void SetExtRow_Simply(int N, T*rowParam, int L)=0;
    //
    virtual void SetLineN_OwnDataType(int N,      double*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1)=0;
    void SetLineN_Gen(int N,                      double*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1);
    virtual void SetLineN_Simply(int N, double*rowParam)=0;
    //
    //template<typename T>void ArrayOf2DBy1D_AddExtRow(T*&X, Array2DSize&size, T DefaultVal, T*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL){
    //                      void               AddExtRow(                        T DefaultVal, T*rowParam, int wholeRowL=0,                         TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL);
    //template<typename T>void ArrayOf2DBy1D_AddExtRow(T*&X, Array2DSize&size, T*rowParam, int wholeRowL=0, T*DefaultValParam=NULL, TDataShiftParams*DataShiftParam=NULL,  int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL){
    //                      void               AddExtRow(                                      T*rowParam, int wholeRowL=0, T*DefaultValParam=NULL, TDataShiftParams*DataShiftParam=NULL,  int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL);
    //
    //virtual void AddExtRow_Simply(T*rowParam)=0;
    //virtual void AddExtRow_Simply(T*rowParam, int L)=0;
    //
    virtual void AddLine_OwnDataType(double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL)=0;
    void AddLine_Gen(double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    virtual void AddLine_Simply(double*rowParam)=0;

    //template<typename T>void ArrayOf2DBy1D_InsExtRow(T*&X, Array2DSize&size, int ExtRowN, T DefaultVal, T*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL){
    //                      void               InsExtRow(                        int ExtRowN, T DefaultVal, T*rowParam, int wholeRowL=0,                      TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL);
    //template<typename T>void ArrayOf2DBy1D_InsExtRow(T*&X, Array2DSize&size, int ExtRowN, T*rowParam, int wholeRowL=0,  T*DfltValParam=NULL, TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL){
    //                      void               InsExtRow(                        int ExtRowN,               T*rowParam, int wholeRowL=0, T*DfltValParam=NULL, TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL);
    //
    //virtual void InsExtRow_Simply(int N, T*rowParam)=0;
    //virtual void InsExtRow_Simply(int N, T*rowParam, int L)=0;
    //
    virtual void InsLine_OwnDataType(int LineN, double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL)=0;
    void InsLine_Gen(int LineN, double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    //virtual void InsLine_Simply(int LineN, double*rowParam)=0;
    virtual void InsLine_Simply(int LineN, double*rowParam);
    //
    //void DelExtRowN(int N=-1);
    //virtual void DelExtRowN_Simply(int N=-1)=0;
    //
    //virtual void DelLineN_Simply(int N=-1)=0;
    virtual void DelLineN_Simply(int N=-1);
    void DelLineN_Gen(int N=-1);
    //
    //Ine row
    //
    //void SetIneRowN( int IneRowN, const T& defaultVal, T*rowParam=NULL, int rowL=0, TDataShiftParams*DataShiftParam=NULL,                         bool DefaulsAreSpecNotOwnVals=true, int arr2D_ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_AnyExtRow3_NurFromStartTillErstStop4=0, int arr1D_ifNurProperL_NsSame1_EltsWithNsOfShoeterExtRowsNeUsed2=1);
    //void SetIneRowN( int IneRowN,                      T*rowParam=NULL, int rowL=0, TDataShiftParams*DataShiftParam=NULL, T*DefaultValParam=NULL, bool DefaulsAreSpecNotOwnVals=true, int arr2D_ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_AnyExtRow3_NurFromStartTillErstStop4=0, int arr1D_ifNurProperL_NsSame1_EltsWithNsOfShoeterExtRowsNeUsed2=1);
    //
    //virtual void SetIneRowSimply(int IneRowN, T*rowParam)=0;
    //
    //
    virtual void SetColumnN_OwnDataType(int N,          double*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1)=0;
    void SetColumnN_Gen                (int N,          double*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1);
    virtual void SetColumnN_Simply(int N, double*rowParam)=0;
    //template<typename T>void ArrayOf2DBy1D_AddIneRow(T*&X, Array2DSize& size, T DefaultVal, T*rowParam=NULL, int wholeRowL=0, TDataShiftParams*dataShiftParam=NULL,                         int ifNGTLmin_Ignore0AddToLast1StretchToMax2=0, bool RectIfPossible=true){
    //                     void               AddIneRow(                         T DefaultVal, T*rowParam=NULL, int wholeRowL=0, TDataShiftParams*dataShiftParam=NULL,                         int ifNGTLmin_Ignore0AddToLast1StretchToMax2=0, bool RectIfPossible=true)=0;
    //                     void               AddIneRow(                                       T*rowParam=NULL, int wholeRowL=0, TDataShiftParams*dataShiftParam=NULL, T*DefaultValParam=NULL, int ifNGTLmin_Ignore0AddToLast1StretchToMax2=0, bool RectIfPossible=true)=0;
    //
    //virtual void AddIneRow_Simply(T*rowParam)=0;
    //
    //virtual void AddColumn_OwnDataType(double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL)=0;
    virtual void AddColumn_OwnDataType(double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    void AddColumn_Gen                (double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    virtual void  AddColumn_Simply(double*rowParam)=0;
    //
    //template<typename T>void ArrayOf2DBy1D_InsIneRowN(T*&X, Array2DSize& size, int IneRowN, T DefaultVal, T*rowParam=NULL, int wholeRowL=0,                         TDataShiftParams*DataShiftParam=NULL, int ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_ValForShorterIsMissedForNsFitKeeping3_NextNewValToNextProperL4=1){
    //                      void               InsIneRowN(                         int IneRowN, T DefaultVal, T*rowParam=NULL, int wholeRowL=0,                         TDataShiftParams*DataShiftParam=NULL, int arr2D_ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_AnyExtRow3_NurFromStartTillErstStop4=0, int arr1D_ifNurProperL_NsSame1_EltsWithNsOfShoeterExtRowsNeUsed2=1);
    //                      void               InsIneRowN(                         int IneRowN,               T*rowParam=NULL, int wholeRowL=0, T*DefaultValParam=NULL, TDataShiftParams*DataShiftParam=NULL, int arr2D_ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_AnyExtRow3_NurFromStartTillErstStop4=0, int arr1D_ifNurProperL_NsSame1_EltsWithNsOfShoeterExtRowsNeUsed2=1);
    //
    //virtual void InsIneRow_Simply(int N, T*rowParam)=0;
    //
    //virtual void InsColumn_OwnDataType(int ColN, double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL)=0;
    virtual void InsColumn_OwnDataType(int ColN, double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    void InsColumn_Gen                (int ColN, double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    //virtual void InsColumn_Simply(int ColN, double*rowParam)=0;
    virtual void InsColumn_Simply(int ColN, double*rowParam);
    //
    //void DelIneRowN(int N=-1, int ifNGTLmin_Ignore0_DelLast1_NurProperL_AnyExtRow3_NurFromStartTillFirstBreak4=0);
    //virtual void DelIneRow_Simply(int N=-1)=0;
    //
    //virtual void DelColumnN_Simply(int N=-1)=0;
    virtual void DelColumnN_Simply(int N=-1);
    void DelColumnN_Gen(int N=-1);
    //
    // Set Content
    //
    //void Set(T**y, const Array2DSize& size,  bool WriteSize=true);
    //void Set(T**y, std::vector<int>ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(T**y, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(T**y, int QExtRows, int ExtRowsLength=1, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(T*y, const Array2DSize& size, bool WriteSize=true);
    //void Set(T*y, std::vector<int>ExtRowsLengthes, bool WriteSize=true);
    //void Set(T*y, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true,  bool WriteSize=true);
    //void Set(T*y, int QExtRows, int ExtRowsLength=1, bool RectIfPossible=true, bool sizeVaria=false, bool WriteSize=true);
    //void Set(std::vector<std::vector<T>>y, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(std::vector<T>y, const Array2DSize& size, bool WriteSize=true);
    //void Set(std::vector<T>y, std::vector<int>ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(std::vector<T>y, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(std::vector<T>y, int QExtRows, int ExtRowsLength=1, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(const T&val, const Array2DSize& size, bool WriteSize=true);
    //void Set(const T&val, std::vector<int>ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(const T&val, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(const T&val, int QExtRows, int ExtRowsLength=1, bool RectIfPossible=true, bool WriteSize=true);
    //
    void Set_arrOfLines(double**y, int QLines=1, int QColumns=1);
    void Set_arrOfLines(double*y, int QLines=1, int QColumns=1);
    void Set_arrOfLines(std::vector<double>y, int QLines=1, int QColumns=1);
    void Set_arrOfLines(std::vector<std::vector<double>>y);
    void Set_arrOfColumns(double**y, int QLines=1, int QColumns=1);
    void Set_arrOfColumns(double*y, int QLines=1, int QColumns=1);
    void Set_arrOfColumns(std::vector<double>y, int QLines=1, int QColumns=1);
    void Set_arrOfColumns(std::vector<std::vector<double>>y);
    //
    //void SwapVals(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
    void SwapVals(int LineN1, int ColN1, int LineN2, int ColN2);
    //
    //void SwapExtRows(int N1, int N2);
    //void SwapIneRows(int N1, int N2);
    void SwapLines(int N1, int N2);
    void SwapColumns(int N1, int N2);
    //
    //void ReverseExtRowN(int rowN);
    //void ReverseIneRowN(int rowN);
    //void ReverseExtRowsSuccession();
    //void ReverseIneRowsSuccession();
    void ReverseLineN(int LineN);
    void ReverseColumnN(int ColumnN);
    void ReverseLinesSuccession();
    void ReverseColumnsSuccession();
    //
    //bool ValIsAtPos(const T&val, int ExtRowN, int IneRowN) const;
    bool ValIsAtPos(double val, int ExtRowN, int IneRowN) const;
    //swa S di n'fit prototype - obe s': alt IneRowN wa ExtRowN, so ExtRowN 2x, ce alt err
    //std::vector<std::vector<int>> SeekVal(const T&val) const;
    //std::vector<Int2DVectorOfSizeOrCoords> SeekVal(const T&val) const;
    //TListOfNumberPairs SeekVal(const T&val) const;
    TListOfNumberPairs SeekVal(double val) const;
    //so class name. Ma to vrns co std::vector ety di n'fit prototype
    //bool ExtRowIsAtPos(T*row, int Q, int ExtRowN, int IneRowN) const;
    bool LineIsAtPos(double*row, int Q, int ExtRowN, int IneRowN) const;
    //std::vector<std::vector<int>> SeekExtRow(T*row, int L) const;
    //std::vector<Int2DVectorOfSizeOrCoords> SeekExtRow(T*row, int L) const;
    //TListOfNumberPairs SeekExtRow(T*row, int L) const;
    TListOfNumberPairs SeekLine(double*row, int L) const;
    //bool IneRowIsAtPos(T*row, int Q, int ExtRowN, int IneRowN) const;
    bool ColumnIsAtPos(double*row, int Q, int ExtRowN, int IneRowN) const;
    //std::vector<std::vector<int>> SeekIneRow(T*row, int Q) const;
    //std::vector<Int2DVectorOfSizeOrCoords> SeekIneRow(T*row, int Q) const;
    //TListOfNumberPairs SeekIneRow(T*row, int Q) const;
    TListOfNumberPairs SeekColumn(double*row, int Q) const;

    //bool Arr2DIsAtPos(std::vector<std::vector<T>>arr, int ExtRowN, int IneRowN, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    bool Arr2DIsAtPos(std::vector<std::vector<double>>arr, int LineN, int ColN, bool ArrOfLinesNotColumns=true, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    bool Arr2DIsAtPos(Matrix_Prototype*obj, int LineN, int ColN, bool ArrOfLinesNotColumns, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;

    //std::vector<std::vector<int>> SeekArr2D(std::vector<std::vector<T>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //std::vector<Int2DVectorOfSizeOrCoords> SeekArr2D(std::vector<std::vector<T>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //TListOfNumberPairs SeekArr2D(std::vector<std::vector<T>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    TListOfNumberPairs SeekArr2D(std::vector<std::vector<double>>arr, bool ArrOfLinesNotColumns=true, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //std::vector<std::vector<int>> SeekArr2D(Array2D_Prototype*arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //std::vector<Int2DVectorOfSizeOrCoords> SeekArr2D(Array2D_Prototype*arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    TListOfNumberPairs SeekArr2D(Matrix_Prototype*obj, bool ArrOfLinesNotColumns=true, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //
    //virtual void ConcatAdding(Matrix_Prototype*obj, T DefaultVal,int QShiftedCols=0,  TDataShiftParams*DataShiftParam=NULL, bool SetRect=true, int DfltRowL_00_11_Lmin2_Lmax3=1);
    //virtual void ConcatAdding(Matrix_Prototype*obj, int QShiftedCols=0, TDataShiftParams*DataShiftParam=NULL, T*DefaultValParam=NULL, bool SetRect=true, int DfltRowL_00_11_Lmin2_Lmax3=1);
    //
    void ConcatAdding(Matrix_Prototype*obj, Matrix_Prototype*&R, int QShiftedCols=0,  TDataShiftParams*DataShiftParam=NULL);
    //_ConcatStretching(T*X1, const Array2DSize& size1, T*X2, const Array2DSize& size2, T*&X3, Array2DSize& size3, T DefaultVal, int shiftQ=0, TDataShiftParams*DataShiftParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3, bool Stretch1ToMax=true, bool SetRect=true){
    //virtual void ConcatStretching(Matrix_Prototype*obj, T DefaultVal, int QShiftedExtRowNs=0,  TDataShiftParams*DataShiftParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3, bool Stretch1ToMax=true, bool SetRect=true);
    //virtual void ConcatStretching(Matrix_Prototype*obj, int QShiftedExtRowNs=0, TDataShiftParams*DataShiftParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3, bool Stretch1ToMax=true, bool SetRect=true, T*DefaultValParam=NULL);
    void ConcatStretching(Matrix_Prototype*obj, Matrix_Prototype*&R,  int QShiftedCols=0,  TDataShiftParams*DataShiftParam=NULL);
    //
    virtual Matrix_Prototype*GetSubMatrix(int ExtRowN, int IneRowN, const Array2DSize& size, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const=0;
    virtual Matrix_Prototype*GetSubMatrix(TDataShiftParams*DataShiftParam=NULL) const=0;
    //
    //void ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(T val, int ExtRowN, int IneRowN, T DefaultVal, bool SetRect=true, int DfltRowL_00_11_Max2_Min3=2);
    //void ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(T val, int ExtRowN, int IneRowN, bool SetRect=true, int DfltRowL_00_11_Max2_Min3=2, T*DefaultValParam=NULL);
    void ValSetOrAddOrFillOrIgnore(double val, int LineN, int ColN);
    //
    //void StdCout_ExtRowN(int ExtRowN, QString ElemsDelim="; ", bool UseBrackets=true)const;
    //void StdCout_IneRowN(int IneRowN, QString ElemsDelim="; ", bool UseBrackets=true, bool Represent2DNot1D=false)const;
    //void StdCout(QString ElemsDelim=", ", QString RowsDelim="; ", bool UseBrackets=true, bool Represent2DNot1D=true, bool ByExtRowsNotIneRows=true)const;
    void StdCout_LineN(int ExtRowN, QString ElemsDelim="; ", bool UseBrackets=true)const;
    void StdCout_ColN(int IneRowN, QString ElemsDelim="; ", bool UseBrackets=true, bool Represent2DNot1D=false)const;
    void StdCout(QString ElemsDelim=", ", QString RowsDelim="; ", bool UseBrackets=true, bool Represent2DNot1D=true, bool ByExtRowsNotIneRows=true)const;
};//Matrix_Prototype



class Matrix_TmpltArr2DShell_ArrOfLines : public Matrix_Prototype{
    Array2D_shell<double> data;
public:
    Matrix_TmpltArr2DShell_ArrOfLines(int QLines=1, int QColumns=1);
    Matrix_TmpltArr2DShell_ArrOfLines(double val, int QLines=1, int QColumns=1);
    Matrix_TmpltArr2DShell_ArrOfLines(double*arrOfLines, int QLines=1, int QColumns=1);
    Matrix_TmpltArr2DShell_ArrOfLines(double**arr, int QLines=1, int QColumns=1);
    Matrix_TmpltArr2DShell_ArrOfLines(std::vector<double>arrOfLines, int QLines=1, int QColumns=1);
    Matrix_TmpltArr2DShell_ArrOfLines(std::vector<std::vector<double>>arrOfLines);
    //
    Matrix_TmpltArr2DShell_ArrOfLines(const Matrix_TmpltArr2DShell_ArrOfLines& obj);
    //
    virtual ~Matrix_TmpltArr2DShell_ArrOfLines();
    //
    //
    //virtual void SetNull()=0;
    virtual void SetNull();
    //virtual void construct()=0;
    virtual void construct();
    //virtual Matrix_Prototype* CreateArray() const=0;
    //virtual Matrix_TmpltArr2DShell_ArrOfLines* CreateArray() const;
    //virtual Matrix_Prototype* clone()const=0;
    //virtual Matrix_Prototype* clone()const;
    //virtual Matrix_Prototype* CreateMatrix() const=0;
    virtual Matrix_TmpltArr2DShell_ArrOfLines* CreateMatrix() const;
    //virtual Matrix_Prototype* clone()const=0;
    virtual Matrix_TmpltArr2DShell_ArrOfLines* clone()const;
    //virtual Matrix_Prototype* GetData()const=0;
    virtual Matrix_TmpltArr2DShell_ArrOfLines* GetData()const;
    //virtual int GetTypeN() const=0 ;
    virtual int GetTypeN() const;
    //
    //void SetOne(T*DfltVal=NULL);
    //void SetOne(const T&DfltVal);
    void SetOne();
    //
    ////virtual void SetSize(const T& DfltValParam, const Array2DSize&size)=0;
    //
    ////void SetSize(const Array2DSize&size, T*DfltValParam=NULL);//virtual ob hin Sdo mut l'size data
    ////void SetSize(int QExtRows=1, int ExtRowsLength=1, T*DfltValParam=NULL);
    ////void SetSize(int QExtRows=1, int*ExtRowsLengthes=NULL, T*DfltValParam=NULL);//if Null => L=0
    ////void SetSize(std::vector<int>ExtRowsLengthes, T*DfltValParam=NULL);
    //
    ////void SetSize(const T& DfltValParam, int QExtRows=1, int ExtRowsLength=1);//virtual ob hin Sdo mut l'size data
    ////void SetSize(const T& DfltValParam, int QExtRows=1, int*ExtRowsLengthes=NULL);//if Null => L=0
    ////void SetSize(const T& DfltValParam, std::vector<int>Lengthes);
    //
    //virtual void SetSize(int QExtRows=1, int ExtRowsLength=1)=0;
    virtual void SetSize(int QExtRows=1, int ExtRowsLength=1);
    //
    ////virtual int GetQExtRows() const=0;
    ////virtual int GetLength(int ExtRowN=1) const=0;
    ////virtual int GetMinLength() const=0;
    ////virtual int GetMaxLength() const=0;
    //virtual int GetQLines()=0;
    virtual int GetQLines() const;
    //virtual int GetQColumns()=0;
    virtual int GetQColumns() const;
    //virtual Array2DSize GetSize()const =0;
    //
    ////bool LineNBelongsHere(int LineN) const;
    ////bool ColNBelongsHere(int ColN) const;
    //bool NsBelongHere(int ExtRowN, int IneRowN) const;
    //
    ////std::vector<T> GetArrayOfExtRowN(int LineN);
    ////std::vector<T> GetArrayOfIneRowN(int ColN);
    ////std::vector<T> GetContentAsArray1D();
    ////std::vector<std::vector<T>> GetContentAsArray2D();
    //
    ////std::vector<T> GetExtRowN_AsArray(int rowN) const;
    //std::vector<double> GetLineN_AsArray(int rowN) const;
    //// T*GetExtRowN_AsPtr(int ExtRowN) const;
    ////std::vector<T> GetIneRowN_AsArray(int rowN) const;
    //std::vector<double> GetColumnN_AsArray(int rowN) const;
    ////std::vector<T> GetIneRowN_AsArray(int IneRowN, const T& defaultVal,                         int ifNGTLmin_Ignore0_DefaultsForShorter1_NurProperL_AnyExtRow2_NurFromStartTillErstStop3=0) const;
    ////std::vector<T> GetIneRowN_AsArray(int IneRowN,                      T*DefaultValParam=NULL, int ifNGTLmin_Ignore0_DefaultsForShorter1_NurProperL_AnyExtRow2_NurFromStartTillErstStop3=0) const;
    ////std::vector<T> GetContent_AsArray1D() const;
    ////std::vector<std::vector<T>> GetContent_AsArray2D() const;
    //std::vector<double> GetContent_AsArray1DOfLines() const;
    //std::vector<double> GetContent_AsArray1DOfColumns() const;
    //std::vector<std::vector<double>> GetContent_AsArray2DOfLines() const;
    //std::vector<std::vector<double>> GetContent_AsArray2DOfColumns() const;
    //
    //
    ////virtual T GetComponent_AsVal(int LineN, int ColN) const=0;
    ////virtual T* GetComponent_AsPtr(int LineN, int ColN) const=0;
    //virtual double GetComponent_AsVal(int LineN, int ColN) const=0;
    virtual double GetComponent(int LineN, int ColN) const;
    //virtual double* GetComponent_AsPtr(int LineN, int ColN) const=0;
    //virtual double* GetComponent_AsPtr(int LineN, int ColN) const;
    //
    ////virtual void SetComponent(const T& val, int LineN, int ColN)=0;
    //virtual void SetComponent(double val, int LineN, int ColN)=0;
    virtual void SetComponent(double val, int LineN, int ColN);
    //
    ////void AddToExtRowN(int RowN, const T&val);
    ////void InsToExtRowN(int RowN, int PosN, const T&val);
    ////void DelFromExtRowN(int RowN, int PosN);
    //
    ////virtual void AddToExtRowN_Simply(int ExtRowN, const T&val)=0;
    ////virtual void InsToExtRowN_Simply(int ExtRowN, int PosN, const T&val)=0;
    ////virtual void DelFromExtRowN_Simply(int RowN, int IneRowPosN)=0;
    //
    // Ext row
    //
    ////template<typename T> void ArrayOf2DBy1D_SetExtRowN(T*&X, Array2DSize&size, int ExtRowN,       T DefaultVal, T*rowParam, int wholeRowL=0,                      TDataShiftParams*DataShiftParam=NULL, /*bool KeepIfRect=true,*/ bool DefaultIsSpecNotOwn=true,      int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2){
    ////virtual              void               SetExtRowN(                              int N, const T& defaultVal,  T*rowParam,      int rowL,    TDataShiftParams*DataShiftParams=NULL,                          bool DefaulsAreSpecNotOwnVals=true, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2)=0;
    ////void SetExtRowN(int N, const T& defaultVal, T*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true,                      int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2);
    ////void SetExtRowN(int N,                      T*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, T*DfltValParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2);
    //
    ////void SetExtRow_Simply(int N, T*rowParam)=0;
    ////void SetExtRow_Simply(int N, T*rowParam, int L)=0;
    //
    //virtual void SetLineN_OwnDataType(int N,      double*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1)=0;
    virtual void SetLineN_OwnDataType(int N,      double*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1);
    //void SetLineN_Gen(int N,                      double*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1);
    //virtual void SetLineN_Simply(int N, double*rowParam)=0;
    virtual void SetLineN_Simply(int N, double*rowParam);
    //
    ////template<typename T>void ArrayOf2DBy1D_AddExtRow(T*&X, Array2DSize&size, T DefaultVal, T*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL){
    ////                      void               AddExtRow(                        T DefaultVal, T*rowParam, int wholeRowL=0,                         TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL);
    ////template<typename T>void ArrayOf2DBy1D_AddExtRow(T*&X, Array2DSize&size, T*rowParam, int wholeRowL=0, T*DefaultValParam=NULL, TDataShiftParams*DataShiftParam=NULL,  int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL){
    //                      void               AddExtRow(                                      T*rowParam, int wholeRowL=0, T*DefaultValParam=NULL, TDataShiftParams*DataShiftParam=NULL,  int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL);
    //
    ////virtual void AddExtRow_Simply(T*rowParam)=0;
    ////virtual void AddExtRow_Simply(T*rowParam, int L)=0;
    //
    //virtual void AddLine_OwnDataType(double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL)=0;
    virtual void AddLine_OwnDataType(double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    //void AddLine_Gen(double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    //virtual void AddLine_Simply(double*rowParam)=0;
    virtual void AddLine_Simply(double*rowParam);

    ////template<typename T>void ArrayOf2DBy1D_InsExtRow(T*&X, Array2DSize&size, int ExtRowN, T DefaultVal, T*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL){
    ////                      void               InsExtRow(                        int ExtRowN, T DefaultVal, T*rowParam, int wholeRowL=0,                      TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL);
    ////template<typename T>void ArrayOf2DBy1D_InsExtRow(T*&X, Array2DSize&size, int ExtRowN, T*rowParam, int wholeRowL=0,  T*DfltValParam=NULL, TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL){
    ////                      void               InsExtRow(                        int ExtRowN,               T*rowParam, int wholeRowL=0, T*DfltValParam=NULL, TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL);
    //
    ////virtual void InsExtRow_Simply(int N, T*rowParam)=0;
    ////virtual void InsExtRow_Simply(int N, T*rowParam, int L)=0;
    //
    //virtual void InsLine_OwnDataType(double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL)=0;
    virtual void InsLine_OwnDataType(int LineN, double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    //void InsLine_Gen(double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    //virtual void InsLine_Simply(double*rowParam)=0;
    virtual void InsLine_Simply(int LineN, double*rowParam);
    //
    ////void DelExtRowN(int N=-1);
    ////virtual void DelExtRowN_Simply(int N=-1)=0;
    //
    //virtual void DelLineN(int N=-1)=0;
    //virtual void DelLineN(int N=-1)=0;
    virtual void DelLineN(int N=-1);
    //void DelLineN_Gen(int N=-1);
    //
    //Ine row
    //
    //void SetIneRowN( int IneRowN, const T& defaultVal, T*rowParam=NULL, int rowL=0, TDataShiftParams*DataShiftParam=NULL,                         bool DefaulsAreSpecNotOwnVals=true, int arr2D_ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_AnyExtRow3_NurFromStartTillErstStop4=0, int arr1D_ifNurProperL_NsSame1_EltsWithNsOfShoeterExtRowsNeUsed2=1);
    //void SetIneRowN( int IneRowN,                      T*rowParam=NULL, int rowL=0, TDataShiftParams*DataShiftParam=NULL, T*DefaultValParam=NULL, bool DefaulsAreSpecNotOwnVals=true, int arr2D_ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_AnyExtRow3_NurFromStartTillErstStop4=0, int arr1D_ifNurProperL_NsSame1_EltsWithNsOfShoeterExtRowsNeUsed2=1);
    //
    //virtual void SetIneRowSimply(int IneRowN, T*rowParam)=0;
    //
    //virtual void SetColumnN_OwnDataType(int N,          double*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1)=0;
    virtual void SetColumnN_OwnDataType(int N,          double*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1);
    //void SetColumnN_Gen                (int N,          double*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1);
    //virtual void SetColumnN_Simply(int N, double*rowParam)=0;
    virtual void SetColumnN_Simply(int N, double*rowParam);
    //
    //template<typename T>void ArrayOf2DBy1D_AddIneRow(T*&X, Array2DSize& size, T DefaultVal, T*rowParam=NULL, int wholeRowL=0, TDataShiftParams*dataShiftParam=NULL,                         int ifNGTLmin_Ignore0AddToLast1StretchToMax2=0, bool RectIfPossible=true){
    //                     void               AddIneRow(                         T DefaultVal, T*rowParam=NULL, int wholeRowL=0, TDataShiftParams*dataShiftParam=NULL,                         int ifNGTLmin_Ignore0AddToLast1StretchToMax2=0, bool RectIfPossible=true)=0;
    //                     void               AddIneRow(                                       T*rowParam=NULL, int wholeRowL=0, TDataShiftParams*dataShiftParam=NULL, T*DefaultValParam=NULL, int ifNGTLmin_Ignore0AddToLast1StretchToMax2=0, bool RectIfPossible=true)=0;
    //
    //virtual void AddIneRow_Simply(T*rowParam)=0;
    //
    //virtual void AddColumn_OwnDataType(double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL)=0;
    virtual void AddColumn_OwnDataType(double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL);
    //void AddColumn_Gen                (double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    //virtual void  AddColumn_Simply(double*rowParam)=0;
    virtual void AddColumn_Simply(double*rowParam);
    //
    //template<typename T>void ArrayOf2DBy1D_InsIneRowN(T*&X, Array2DSize& size, int IneRowN, T DefaultVal, T*rowParam=NULL, int wholeRowL=0,                         TDataShiftParams*DataShiftParam=NULL, int ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_ValForShorterIsMissedForNsFitKeeping3_NextNewValToNextProperL4=1){
    //                      void               InsIneRowN(                         int IneRowN, T DefaultVal, T*rowParam=NULL, int wholeRowL=0,                         TDataShiftParams*DataShiftParam=NULL, int arr2D_ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_AnyExtRow3_NurFromStartTillErstStop4=0, int arr1D_ifNurProperL_NsSame1_EltsWithNsOfShoeterExtRowsNeUsed2=1);
    //                      void               InsIneRowN(                         int IneRowN,               T*rowParam=NULL, int wholeRowL=0, T*DefaultValParam=NULL, TDataShiftParams*DataShiftParam=NULL, int arr2D_ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_AnyExtRow3_NurFromStartTillErstStop4=0, int arr1D_ifNurProperL_NsSame1_EltsWithNsOfShoeterExtRowsNeUsed2=1);
    //
    //virtual void InsIneRow_Simply(int N, T*rowParam)=0;
    //
    //virtual void InsColumn_OwnDataType(int ColN, double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL)=0;
    virtual void InsColumn_OwnDataType(int ColN, double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL);
    //void InsColumn_Gen                (int ColN, double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    //virtual void InsColumn_Simply(int ColN, double*rowParam)=0;
    virtual void InsColumn_Simply(int ColN, double*rowParam);
    //
    //
    ////void DelIneRowN(int N=-1, int ifNGTLmin_Ignore0_DelLast1_NurProperL_AnyExtRow3_NurFromStartTillFirstBreak4=0);
    ////virtual void DelIneRow_Simply(int N=-1)=0;
    //
    //virtual void DelColumnN_Gen(int N=-1)=0;
    virtual void DelColumnN_Gen(int N=-1);
    //
    // Set Content
    //
    //void Set(T**y, const Array2DSize& size,  bool WriteSize=true);
    //void Set(T**y, std::vector<int>ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(T**y, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(T**y, int QExtRows, int ExtRowsLength=1, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(T*y, const Array2DSize& size, bool WriteSize=true);
    //void Set(T*y, std::vector<int>ExtRowsLengthes, bool WriteSize=true);
    //void Set(T*y, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true,  bool WriteSize=true);
    //void Set(T*y, int QExtRows, int ExtRowsLength=1, bool RectIfPossible=true, bool sizeVaria=false, bool WriteSize=true);
    //void Set(std::vector<std::vector<T>>y, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(std::vector<T>y, const Array2DSize& size, bool WriteSize=true);
    //void Set(std::vector<T>y, std::vector<int>ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(std::vector<T>y, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(std::vector<T>y, int QExtRows, int ExtRowsLength=1, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(const T&val, const Array2DSize& size, bool WriteSize=true);
    //void Set(const T&val, std::vector<int>ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(const T&val, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(const T&val, int QExtRows, int ExtRowsLength=1, bool RectIfPossible=true, bool WriteSize=true);
    //
    //void Set_arrOfLines(double**y, int QExtRows, int ExtRowsLength=1);
    //void Set_arrOfLines(double*y, int QExtRows, int ExtRowsLength=1);
    //void Set_arrOfLines(std::vector<double>y, int QExtRows, int ExtRowsLength=1);
    //void Set_arrOfLines(std::vector<std::vector<double>>y);
    //void Set_arrOfColumns(double**y, int QExtRows, int ExtRowsLength=1);
    //void Set_arrOfColumns(double*y, int QExtRows, int ExtRowsLength=1);
    //void Set_arrOfColumns(std::vector<double>y, int QExtRows, int ExtRowsLength=1);
    //void Set_arrOfColumns(std::vector<std::vector<double>>y);
    //
    //void SwapVals(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
    //void SwapExtRows(int N1, int N2);
    //void SwapIneRows(int N1, int N2);
    //void ReverseExtRowN(int rowN);
    //void ReverseIneRowN(int rowN);
    //void ReverseExtRowsSuccession()=0;
    //void ReverseExtRowsSuccession();
    //virtual void ReverseIneRowsSuccession()=0;
    //void ReverseIneRowsSuccession();
    //
    //void SwapVals(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
    //void SwapLines(int N1, int N2);
    //void SwapColumns(int N1, int N2);
    //void ReverseLineN(int rowN);
    //void ReverseColumnN(int rowN);
    //void ReverseLinesSuccession();
    //void ReverseColumnsSuccession();
    //
    ////bool ValIsAtPos(const T&val, int ExtRowN, int IneRowN) const;
    //bool ValIsAtPos(double val, int ExtRowN, int IneRowN) const;
    ////swa S di n'fit prototype - obe s': alt IneRowN wa ExtRowN, so ExtRowN 2x, ce alt err
    ////std::vector<std::vector<int>> SeekVal(const T&val) const;
    ////std::vector<Int2DVectorOfSizeOrCoords> SeekVal(const T&val) const;
    ////TListOfNumberPairs SeekVal(const T&val) const;
    //TListOfNumberPairs SeekVal(double val) const;
    ////so class name. Ma to vrns co std::vector ety di n'fit prototype
    ////bool ExtRowIsAtPos(T*row, int Q, int ExtRowN, int IneRowN) const;
    //bool LineIsAtPos(double*row, int Q, int ExtRowN, int IneRowN) const;
    ////std::vector<std::vector<int>> SeekExtRow(T*row, int L) const;
    ////std::vector<Int2DVectorOfSizeOrCoords> SeekExtRow(T*row, int L) const;
    ////TListOfNumberPairs SeekExtRow(T*row, int L) const;
    //TListOfNumberPairs SeekLine(double*row, int L) const;
    //bool IneRowIsAtPos(T*row, int Q, int ExtRowN, int IneRowN) const;
    //bool ColumnIsAtPos(double*row, int Q, int ExtRowN, int IneRowN) const;
    //std::vector<std::vector<int>> SeekIneRow(T*row, int Q) const;
    //std::vector<Int2DVectorOfSizeOrCoords> SeekIneRow(T*row, int Q) const;
    ////TListOfNumberPairs SeekIneRow(T*row, int Q) const;
    //TListOfNumberPairs SeekColumn(double*row, int Q) const;

    ////bool Arr2DIsAtPos(std::vector<std::vector<T>>arr, int ExtRowN, int IneRowN, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //bool Arr2DIsAtPos(std::vector<std::vector<double>>arr, int ExtRowN, int IneRowN, bool ArrOfLinesNotColumns=true, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //bool Arr2DIsAtPos(Matrix_Prototype*obj, int ExtRowN, int IneRowN, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;

    ////std::vector<std::vector<int>> SeekArr2D(std::vector<std::vector<T>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    ////std::vector<Int2DVectorOfSizeOrCoords> SeekArr2D(std::vector<std::vector<T>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    ////TListOfNumberPairs SeekArr2D(std::vector<std::vector<T>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //TListOfNumberPairs SeekArr2D(std::vector<std::vector<double>>arr, bool ArrOfLinesNotColumns=true, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    ////std::vector<std::vector<int>> SeekArr2D(Array2D_Prototype*arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    ////std::vector<Int2DVectorOfSizeOrCoords> SeekArr2D(Array2D_Prototype*arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //TListOfNumberPairs SeekArr2D(Matrix_Prototype*obj, bool ArrOfLinesNotColumns=true, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //
    ////virtual void ConcatAdding(Matrix_Prototype*obj, T DefaultVal,int QShiftedCols=0,  TDataShiftParams*DataShiftParam=NULL, bool SetRect=true, int DfltRowL_00_11_Lmin2_Lmax3=1);
    ////virtual void ConcatAdding(Matrix_Prototype*obj, int QShiftedCols=0, TDataShiftParams*DataShiftParam=NULL, T*DefaultValParam=NULL, bool SetRect=true, int DfltRowL_00_11_Lmin2_Lmax3=1);
    //
    //void ConcatAdding(Matrix_Prototype*obj, int QShiftedCols=0,  TDataShiftParams*DataShiftParam=NULL);
    ////_ConcatStretching(T*X1, const Array2DSize& size1, T*X2, const Array2DSize& size2, T*&X3, Array2DSize& size3, T DefaultVal, int shiftQ=0, TDataShiftParams*DataShiftParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3, bool Stretch1ToMax=true, bool SetRect=true){
    ////virtual void ConcatStretching(Matrix_Prototype*obj, T DefaultVal, int QShiftedExtRowNs=0,  TDataShiftParams*DataShiftParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3, bool Stretch1ToMax=true, bool SetRect=true);
    ////virtual void ConcatStretching(Matrix_Prototype*obj, int QShiftedExtRowNs=0, TDataShiftParams*DataShiftParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3, bool Stretch1ToMax=true, bool SetRect=true, T*DefaultValParam=NULL);
    //void ConcatStretching(Matrix_Prototype*obj, int QShiftedCols=0,  TDataShiftParams*DataShiftParam=NULL);
    //
    //virtual Matrix_Prototype*GetSubMatrix(int ExtRowN, int IneRowN, const Array2DSize& size, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const=0;
    virtual Matrix_TmpltArr2DShell_ArrOfLines*GetSubMatrix(int ExtRowN, int IneRowN, const Array2DSize& size, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //virtual Matrix_Prototype*GetSubMatrix(TDataShiftParams*DataShiftParam=NULL) const=0;
    virtual Matrix_TmpltArr2DShell_ArrOfLines*GetSubMatrix(TDataShiftParams*DataShiftParam=NULL) const;
    //
    ////void ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(T val, int ExtRowN, int IneRowN, T DefaultVal, bool SetRect=true, int DfltRowL_00_11_Max2_Min3=2);
    ////void ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(T val, int ExtRowN, int IneRowN, bool SetRect=true, int DfltRowL_00_11_Max2_Min3=2, T*DefaultValParam=NULL);
    //
    //void ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(int ExtRowN, int IneRowN);
    //void ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(int ExtRowN, int IneRowN);
    //
    //void StdCout_ExtRowN(int ExtRowN, QString ElemsDelim="; ", bool UseBrackets=true)const;
    //void StdCout_IneRowN(int IneRowN, QString ElemsDelim="; ", bool UseBrackets=true, bool Represent2DNot1D=false)const;
    //void StdCout(QString ElemsDelim=", ", QString RowsDelim="; ", bool UseBrackets=true, bool Represent2DNot1D=true, bool ByExtRowsNotIneRows=true)const;
};//Matrix_TmpltArrV1L_ArrOfLines


class Matrix_TmpltArr2DShell_ArrOfColumns : public Matrix_Prototype{
    Array2D_shell<double> data;
public:
    Matrix_TmpltArr2DShell_ArrOfColumns(int QLines=1, int QColumns=1);
    Matrix_TmpltArr2DShell_ArrOfColumns(double val, int QLines=1, int QColumns=1);
    Matrix_TmpltArr2DShell_ArrOfColumns(double*arrOfColumns, int QLines=1, int QColumns=1);
    Matrix_TmpltArr2DShell_ArrOfColumns(double**arr, int QLines=1, int QColumns=1);
    Matrix_TmpltArr2DShell_ArrOfColumns(std::vector<double>arrOfColumns, int QLines=1, int QColumns=1);
    Matrix_TmpltArr2DShell_ArrOfColumns(std::vector<std::vector<double>>arrOfColumns);
    //
    Matrix_TmpltArr2DShell_ArrOfColumns(const Matrix_TmpltArr2DShell_ArrOfColumns& obj);
    //
    virtual ~Matrix_TmpltArr2DShell_ArrOfColumns();
    //
    //virtual void SetNull()=0;
    virtual void SetNull();
    //virtual void construct()=0;
    virtual void construct();
    //virtual Matrix_Prototype* CreateArray() const=0;
    //virtual Matrix_TmpltArr2DShell_ArrOfColumns* CreateArray() const;
    //virtual Matrix_Prototype* clone()const=0;
    //virtual Matrix_TmpltArr2DShell_ArrOfColumns* clone()const;
    virtual Matrix_TmpltArr2DShell_ArrOfColumns* GetData()const;
    //virtual int GetTypeN() const=0 ;
    virtual int GetTypeN() const;
    //
    //void SetOne(T*DfltVal=NULL);
    //void SetOne(const T&DfltVal);
    void SetOne();
    //
    ////virtual void SetSize(const T& DfltValParam, const Array2DSize&size)=0;
    //
    ////void SetSize(const Array2DSize&size, T*DfltValParam=NULL);//virtual ob hin Sdo mut l'size data
    ////void SetSize(int QExtRows=1, int ExtRowsLength=1, T*DfltValParam=NULL);
    ////void SetSize(int QExtRows=1, int*ExtRowsLengthes=NULL, T*DfltValParam=NULL);//if Null => L=0
    ////void SetSize(std::vector<int>ExtRowsLengthes, T*DfltValParam=NULL);
    //
    ////void SetSize(const T& DfltValParam, int QExtRows=1, int ExtRowsLength=1);//virtual ob hin Sdo mut l'size data
    ////void SetSize(const T& DfltValParam, int QExtRows=1, int*ExtRowsLengthes=NULL);//if Null => L=0
    ////void SetSize(const T& DfltValParam, std::vector<int>Lengthes);
    //
    //virtual void SetSize(int QExtRows=1, int ExtRowsLength=1)=0;
    virtual void SetSize(int QExtRows=1, int ExtRowsLength=1);
    //
    ////virtual int GetQExtRows() const=0;
    ////virtual int GetLength(int ExtRowN=1) const=0;
    ////virtual int GetMinLength() const=0;
    ////virtual int GetMaxLength() const=0;
    //virtual int GetQLines()=0;
    virtual int GetQLines();
    //virtual int GetQColumns()=0;
    virtual int GetQColumns();
    //virtual Array2DSize GetSize()const =0;
    //
    ////bool LineNBelongsHere(int LineN) const;
    ////bool ColNBelongsHere(int ColN) const;
    //bool NsBelongHere(int ExtRowN, int IneRowN) const;
    //
    ////std::vector<T> GetArrayOfExtRowN(int LineN);
    ////std::vector<T> GetArrayOfIneRowN(int ColN);
    ////std::vector<T> GetContentAsArray1D();
    ////std::vector<std::vector<T>> GetContentAsArray2D();
    //
    ////std::vector<T> GetExtRowN_AsArray(int rowN) const;
    //std::vector<double> GetLineN_AsArray(int rowN) const;
    //// T*GetExtRowN_AsPtr(int ExtRowN) const;
    ////std::vector<T> GetIneRowN_AsArray(int rowN) const;
    //std::vector<double> GetColumnN_AsArray(int rowN) const;
    ////std::vector<T> GetIneRowN_AsArray(int IneRowN, const T& defaultVal,                         int ifNGTLmin_Ignore0_DefaultsForShorter1_NurProperL_AnyExtRow2_NurFromStartTillErstStop3=0) const;
    ////std::vector<T> GetIneRowN_AsArray(int IneRowN,                      T*DefaultValParam=NULL, int ifNGTLmin_Ignore0_DefaultsForShorter1_NurProperL_AnyExtRow2_NurFromStartTillErstStop3=0) const;
    ////std::vector<T> GetContent_AsArray1D() const;
    ////std::vector<std::vector<T>> GetContent_AsArray2D() const;
    //std::vector<double> GetContent_AsArray1DOfLines() const;
    //std::vector<double> GetContent_AsArray1DOfColumns() const;
    //std::vector<std::vector<double>> GetContent_AsArray2DOfLines() const;
    //std::vector<std::vector<double>> GetContent_AsArray2DOfColumns() const;
    //
    //
    ////virtual T GetComponent_AsVal(int LineN, int ColN) const=0;
    ////virtual T* GetComponent_AsPtr(int LineN, int ColN) const=0;
    //virtual double GetComponent_AsVal(int LineN, int ColN) const=0;
    virtual double GetComponent(int LineN, int ColN) const;
    //virtual double* GetComponent_AsPtr(int LineN, int ColN) const=0;
    //virtual double* GetComponent_AsPtr(int LineN, int ColN) const;
    //
    ////virtual void SetComponent(const T& val, int LineN, int ColN)=0;
    //virtual void SetComponent(double val, int LineN, int ColN)=0;
    virtual void SetComponent(double val, int LineN, int ColN);
    //
    ////void AddToExtRowN(int RowN, const T&val);
    ////void InsToExtRowN(int RowN, int PosN, const T&val);
    ////void DelFromExtRowN(int RowN, int PosN);
    //
    ////virtual void AddToExtRowN_Simply(int ExtRowN, const T&val)=0;
    ////virtual void InsToExtRowN_Simply(int ExtRowN, int PosN, const T&val)=0;
    ////virtual void DelFromExtRowN_Simply(int RowN, int IneRowPosN)=0;
    //
    // Ext row
    //
    ////template<typename T> void ArrayOf2DBy1D_SetExtRowN(T*&X, Array2DSize&size, int ExtRowN,       T DefaultVal, T*rowParam, int wholeRowL=0,                      TDataShiftParams*DataShiftParam=NULL, /*bool KeepIfRect=true,*/ bool DefaultIsSpecNotOwn=true,      int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2){
    ////virtual              void               SetExtRowN(                              int N, const T& defaultVal,  T*rowParam,      int rowL,    TDataShiftParams*DataShiftParams=NULL,                          bool DefaulsAreSpecNotOwnVals=true, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2)=0;
    ////void SetExtRowN(int N, const T& defaultVal, T*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true,                      int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2);
    ////void SetExtRowN(int N,                      T*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, T*DfltValParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2);
    //
    ////void SetExtRow_Simply(int N, T*rowParam)=0;
    ////void SetExtRow_Simply(int N, T*rowParam, int L)=0;
    //
    //virtual void SetLineN_OwnDataType(int N,  double*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1)=0;
    virtual void SetLineN_OwnDataType(int N,    double*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1);
    //void SetLineN_Gen(int N,                      double*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1);
    //virtual void SetLineN_Simply(int N, double*rowParam)=0;
    virtual void SetLineN_Simply(int N, double*rowParam);
    //
    ////template<typename T>void ArrayOf2DBy1D_AddExtRow(T*&X, Array2DSize&size, T DefaultVal, T*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL){
    ////                      void               AddExtRow(                        T DefaultVal, T*rowParam, int wholeRowL=0,                         TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL);
    ////template<typename T>void ArrayOf2DBy1D_AddExtRow(T*&X, Array2DSize&size, T*rowParam, int wholeRowL=0, T*DefaultValParam=NULL, TDataShiftParams*DataShiftParam=NULL,  int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL){
    //                      void               AddExtRow(                                      T*rowParam, int wholeRowL=0, T*DefaultValParam=NULL, TDataShiftParams*DataShiftParam=NULL,  int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL);
    //
    ////virtual void AddExtRow_Simply(T*rowParam)=0;
    ////virtual void AddExtRow_Simply(T*rowParam, int L)=0;
    //
    //virtual void AddLine_OwnDataType(double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL)=0;
    virtual void AddLine_OwnDataType(double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    //void AddLine_Gen(double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    //virtual void AddLine_Simply(double*rowParam)=0;
    virtual void AddLine_Simply(double*rowParam);

    ////template<typename T>void ArrayOf2DBy1D_InsExtRow(T*&X, Array2DSize&size, int ExtRowN, T DefaultVal, T*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL){
    ////                      void               InsExtRow(                        int ExtRowN, T DefaultVal, T*rowParam, int wholeRowL=0,                      TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL);
    ////template<typename T>void ArrayOf2DBy1D_InsExtRow(T*&X, Array2DSize&size, int ExtRowN, T*rowParam, int wholeRowL=0,  T*DfltValParam=NULL, TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL){
    ////                      void               InsExtRow(                        int ExtRowN,               T*rowParam, int wholeRowL=0, T*DfltValParam=NULL, TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL);
    //
    ////virtual void InsExtRow_Simply(int N, T*rowParam)=0;
    ////virtual void InsExtRow_Simply(int N, T*rowParam, int L)=0;
    //
    //virtual void InsLine_OwnDataType(double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL)=0;
    virtual void InsLine_OwnDataType(int LineN, double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    //void InsLine_Gen(double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    //virtual void InsLine_Simply(double*rowParam)=0;
    virtual void InsLine_Simply(int LineN, double*rowParam);
    //
    ////void DelExtRowN(int N=-1);
    ////virtual void DelExtRowN_Simply(int N=-1)=0;
    //
    //virtual void DelLineN(int N=-1)=0;
    //virtual void DelLineN_Simply(int N=-1)=0;
    //virtual void DelLineN(int N=-1)=0;
    void DelLineN_Gen(int N=-1);
    //
    //Ine row
    //
    //void SetIneRowN( int IneRowN, const T& defaultVal, T*rowParam=NULL, int rowL=0, TDataShiftParams*DataShiftParam=NULL,                         bool DefaulsAreSpecNotOwnVals=true, int arr2D_ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_AnyExtRow3_NurFromStartTillErstStop4=0, int arr1D_ifNurProperL_NsSame1_EltsWithNsOfShoeterExtRowsNeUsed2=1);
    //void SetIneRowN( int IneRowN,                      T*rowParam=NULL, int rowL=0, TDataShiftParams*DataShiftParam=NULL, T*DefaultValParam=NULL, bool DefaulsAreSpecNotOwnVals=true, int arr2D_ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_AnyExtRow3_NurFromStartTillErstStop4=0, int arr1D_ifNurProperL_NsSame1_EltsWithNsOfShoeterExtRowsNeUsed2=1);
    //
    //virtual void SetIneRowSimply(int IneRowN, T*rowParam)=0;
    //
    //virtual void SetColumnN_OwnDataType(int N,          double*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1)=0;
    virtual void SetColumnN_OwnDataType(int N,          double*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1);
    //void SetColumnN_Gen                (int N,          double*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1);
    //virtual void SetColumnN_Simply(int N, double*rowParam)=0;
    virtual void SetColumnN_Simply(int N, double*rowParam);
    //
    //template<typename T>void ArrayOf2DBy1D_AddIneRow(T*&X, Array2DSize& size, T DefaultVal, T*rowParam=NULL, int wholeRowL=0, TDataShiftParams*dataShiftParam=NULL,                         int ifNGTLmin_Ignore0AddToLast1StretchToMax2=0, bool RectIfPossible=true){
    //                     void               AddIneRow(                         T DefaultVal, T*rowParam=NULL, int wholeRowL=0, TDataShiftParams*dataShiftParam=NULL,                         int ifNGTLmin_Ignore0AddToLast1StretchToMax2=0, bool RectIfPossible=true)=0;
    //                     void               AddIneRow(                                       T*rowParam=NULL, int wholeRowL=0, TDataShiftParams*dataShiftParam=NULL, T*DefaultValParam=NULL, int ifNGTLmin_Ignore0AddToLast1StretchToMax2=0, bool RectIfPossible=true)=0;
    //
    //virtual void AddIneRow_Simply(T*rowParam)=0;
    //
    //virtual void AddColumn_OwnDataType(double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL)=0;
    virtual void AddColumn_OwnDataType(int LineN, double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    //void AddColumn_Gen                (double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    //virtual void  AddColumn_Simply(double*rowParam)=0;
    virtual void  AddColumn_Simply(int LineN, double*rowParam)=0;
    //
    //template<typename T>void ArrayOf2DBy1D_InsIneRowN(T*&X, Array2DSize& size, int IneRowN, T DefaultVal, T*rowParam=NULL, int wholeRowL=0,                         TDataShiftParams*DataShiftParam=NULL, int ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_ValForShorterIsMissedForNsFitKeeping3_NextNewValToNextProperL4=1){
    //                      void               InsIneRowN(                         int IneRowN, T DefaultVal, T*rowParam=NULL, int wholeRowL=0,                         TDataShiftParams*DataShiftParam=NULL, int arr2D_ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_AnyExtRow3_NurFromStartTillErstStop4=0, int arr1D_ifNurProperL_NsSame1_EltsWithNsOfShoeterExtRowsNeUsed2=1);
    //                      void               InsIneRowN(                         int IneRowN,               T*rowParam=NULL, int wholeRowL=0, T*DefaultValParam=NULL, TDataShiftParams*DataShiftParam=NULL, int arr2D_ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_AnyExtRow3_NurFromStartTillErstStop4=0, int arr1D_ifNurProperL_NsSame1_EltsWithNsOfShoeterExtRowsNeUsed2=1);
    //
    //virtual void InsIneRow_Simply(int N, T*rowParam)=0;
    //
    //virtual void InsColumn_OwnDataType(int ColN, double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL)=0;
    virtual void InsColumn_OwnDataType(int ColN, double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    //void InsColumn_Gen                (int ColN, double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    //virtual void InsColumn_Simply(int ColN, double*rowParam)=0;
    virtual void InsColumn_Simply(int ColN, double*rowParam);
    //
    //
    ////void DelIneRowN(int N=-1, int ifNGTLmin_Ignore0_DelLast1_NurProperL_AnyExtRow3_NurFromStartTillFirstBreak4=0);
    ////virtual void DelIneRow_Simply(int N=-1)=0;
    //
    //virtual void DelColumnN(int N=-1)=0;
    virtual void DelColumnN(int N=-1);
    //
    // Set Content
    //
    //void Set(T**y, const Array2DSize& size,  bool WriteSize=true);
    //void Set(T**y, std::vector<int>ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(T**y, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(T**y, int QExtRows, int ExtRowsLength=1, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(T*y, const Array2DSize& size, bool WriteSize=true);
    //void Set(T*y, std::vector<int>ExtRowsLengthes, bool WriteSize=true);
    //void Set(T*y, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true,  bool WriteSize=true);
    //void Set(T*y, int QExtRows, int ExtRowsLength=1, bool RectIfPossible=true, bool sizeVaria=false, bool WriteSize=true);
    //void Set(std::vector<std::vector<T>>y, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(std::vector<T>y, const Array2DSize& size, bool WriteSize=true);
    //void Set(std::vector<T>y, std::vector<int>ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(std::vector<T>y, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(std::vector<T>y, int QExtRows, int ExtRowsLength=1, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(const T&val, const Array2DSize& size, bool WriteSize=true);
    //void Set(const T&val, std::vector<int>ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(const T&val, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(const T&val, int QExtRows, int ExtRowsLength=1, bool RectIfPossible=true, bool WriteSize=true);
    //
    //void Set_arrOfLines(double**y, int QExtRows, int ExtRowsLength=1);
    //void Set_arrOfLines(double*y, int QExtRows, int ExtRowsLength=1);
    //void Set_arrOfLines(std::vector<double>y, int QExtRows, int ExtRowsLength=1);
    //void Set_arrOfLines(std::vector<std::vector<double>>y);
    //void Set_arrOfColumns(double**y, int QExtRows, int ExtRowsLength=1);
    //void Set_arrOfColumns(double*y, int QExtRows, int ExtRowsLength=1);
    //void Set_arrOfColumns(std::vector<double>y, int QExtRows, int ExtRowsLength=1);
    //void Set_arrOfColumns(std::vector<std::vector<double>>y);
    //
    //void SwapVals(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
    //void SwapExtRows(int N1, int N2);
    //void SwapIneRows(int N1, int N2);
    //void ReverseExtRowN(int rowN);
    //void ReverseIneRowN(int rowN);
    //void ReverseExtRowsSuccession()=0;
    //void ReverseExtRowsSuccession();
    //virtual void ReverseIneRowsSuccession()=0;
    //void ReverseIneRowsSuccession();
    //
    //void SwapVals(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
    //void SwapLines(int N1, int N2);
    //void SwapColumns(int N1, int N2);
    //void ReverseLineN(int rowN);
    //void ReverseColumnN(int rowN);
    //void ReverseLinesSuccession();
    //void ReverseColumnsSuccession();
    //
    ////bool ValIsAtPos(const T&val, int ExtRowN, int IneRowN) const;
    //bool ValIsAtPos(double val, int ExtRowN, int IneRowN) const;
    ////swa S di n'fit prototype - obe s': alt IneRowN wa ExtRowN, so ExtRowN 2x, ce alt err
    ////std::vector<std::vector<int>> SeekVal(const T&val) const;
    ////std::vector<Int2DVectorOfSizeOrCoords> SeekVal(const T&val) const;
    ////TListOfNumberPairs SeekVal(const T&val) const;
    //TListOfNumberPairs SeekVal(double val) const;
    ////so class name. Ma to vrns co std::vector ety di n'fit prototype
    ////bool ExtRowIsAtPos(T*row, int Q, int ExtRowN, int IneRowN) const;
    //bool LineIsAtPos(double*row, int Q, int ExtRowN, int IneRowN) const;
    ////std::vector<std::vector<int>> SeekExtRow(T*row, int L) const;
    ////std::vector<Int2DVectorOfSizeOrCoords> SeekExtRow(T*row, int L) const;
    ////TListOfNumberPairs SeekExtRow(T*row, int L) const;
    //TListOfNumberPairs SeekLine(double*row, int L) const;
    //bool IneRowIsAtPos(T*row, int Q, int ExtRowN, int IneRowN) const;
    //bool ColumnIsAtPos(double*row, int Q, int ExtRowN, int IneRowN) const;
    //std::vector<std::vector<int>> SeekIneRow(T*row, int Q) const;
    //std::vector<Int2DVectorOfSizeOrCoords> SeekIneRow(T*row, int Q) const;
    ////TListOfNumberPairs SeekIneRow(T*row, int Q) const;
    //TListOfNumberPairs SeekColumn(double*row, int Q) const;

    ////bool Arr2DIsAtPos(std::vector<std::vector<T>>arr, int ExtRowN, int IneRowN, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //bool Arr2DIsAtPos(std::vector<std::vector<double>>arr, int ExtRowN, int IneRowN, bool ArrOfLinesNotColumns=true, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //bool Arr2DIsAtPos(Matrix_Prototype*obj, int ExtRowN, int IneRowN, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;

    ////std::vector<std::vector<int>> SeekArr2D(std::vector<std::vector<T>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    ////std::vector<Int2DVectorOfSizeOrCoords> SeekArr2D(std::vector<std::vector<T>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    ////TListOfNumberPairs SeekArr2D(std::vector<std::vector<T>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //TListOfNumberPairs SeekArr2D(std::vector<std::vector<double>>arr, bool ArrOfLinesNotColumns=true, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    ////std::vector<std::vector<int>> SeekArr2D(Array2D_Prototype*arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    ////std::vector<Int2DVectorOfSizeOrCoords> SeekArr2D(Array2D_Prototype*arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //TListOfNumberPairs SeekArr2D(Matrix_Prototype*obj, bool ArrOfLinesNotColumns=true, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //
    ////virtual void ConcatAdding(Matrix_Prototype*obj, T DefaultVal,int QShiftedCols=0,  TDataShiftParams*DataShiftParam=NULL, bool SetRect=true, int DfltRowL_00_11_Lmin2_Lmax3=1);
    ////virtual void ConcatAdding(Matrix_Prototype*obj, int QShiftedCols=0, TDataShiftParams*DataShiftParam=NULL, T*DefaultValParam=NULL, bool SetRect=true, int DfltRowL_00_11_Lmin2_Lmax3=1);
    //
    //void ConcatAdding(Matrix_Prototype*obj, int QShiftedCols=0,  TDataShiftParams*DataShiftParam=NULL);
    ////_ConcatStretching(T*X1, const Array2DSize& size1, T*X2, const Array2DSize& size2, T*&X3, Array2DSize& size3, T DefaultVal, int shiftQ=0, TDataShiftParams*DataShiftParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3, bool Stretch1ToMax=true, bool SetRect=true){
    ////virtual void ConcatStretching(Matrix_Prototype*obj, T DefaultVal, int QShiftedExtRowNs=0,  TDataShiftParams*DataShiftParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3, bool Stretch1ToMax=true, bool SetRect=true);
    ////virtual void ConcatStretching(Matrix_Prototype*obj, int QShiftedExtRowNs=0, TDataShiftParams*DataShiftParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3, bool Stretch1ToMax=true, bool SetRect=true, T*DefaultValParam=NULL);
    //void ConcatStretching(Matrix_Prototype*obj, int QShiftedCols=0,  TDataShiftParams*DataShiftParam=NULL);
    //
    //virtual Matrix_Prototype*GetSubMatrix(int ExtRowN, int IneRowN, const Array2DSize& size, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const=0;
    virtual Matrix_TmpltArr2DShell_ArrOfColumns*GetSubMatrix(int ExtRowN, int IneRowN, const Array2DSize& size, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //virtual Matrix_Prototype*GetSubMatrix(TDataShiftParams*DataShiftParam=NULL) const=0;
    virtual Matrix_TmpltArr2DShell_ArrOfColumns*GetSubMatrix(TDataShiftParams*DataShiftParam=NULL) const;
    //
    ////void ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(T val, int ExtRowN, int IneRowN, T DefaultVal, bool SetRect=true, int DfltRowL_00_11_Max2_Min3=2);
    ////void ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(T val, int ExtRowN, int IneRowN, bool SetRect=true, int DfltRowL_00_11_Max2_Min3=2, T*DefaultValParam=NULL);
    //
    //void ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(int ExtRowN, int IneRowN);
    //void ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(int ExtRowN, int IneRowN);
    //
    //void StdCout_ExtRowN(int ExtRowN, QString ElemsDelim="; ", bool UseBrackets=true)const;
    //void StdCout_IneRowN(int IneRowN, QString ElemsDelim="; ", bool UseBrackets=true, bool Represent2DNot1D=false)const;
    //void StdCout(QString ElemsDelim=", ", QString RowsDelim="; ", bool UseBrackets=true, bool Represent2DNot1D=true, bool ByExtRowsNotIneRows=true)const;
};//Matrix_TmpltArr_V1L_ArrOfColumns





class Matrix{//Shell
    Matrix_Prototype* data;
public:
    Matrix(int QLines=1, int QColumns=1, int TypeN=Matrix_TmpltArrr_V1L_ArrOfLines_TypeN);
    Matrix(double val, int QLines=1, int QColumns=1, int TypeN=Matrix_TmpltArrr_V1L_ArrOfLines_TypeN);
    Matrix(double*arrOfLines, int QLines=1, int QColumns=1, int TypeN=Matrix_TmpltArrr_V1L_ArrOfLines_TypeN);
    Matrix(double**arr, int QLines=1, int QColumns=1, int TypeN=Matrix_TmpltArrr_V1L_ArrOfLines_TypeN);
    Matrix(std::vector<double>arrOfLines, int QLines=1, int QColumns=1, int TypeN=Matrix_TmpltArrr_V1L_ArrOfLines_TypeN);
    Matrix(std::vector<std::vector<double>>arrOfLines);
    //
    Matrix(const Matrix& obj);
    //
    ~Matrix();
    //
    //
    void SetNull();
    void construct(int TypeN);
    //virtual Matrix_Prototype* CreateArray() const=0;
    //virtual Matrix_Prototype* CreateArray() const=0;
    //virtual Matrix_Prototype* clone()const=0;
    Matrix clone()const;
    int GetTypeN() const ;
    //
    //void SetOne(T*DfltVal=NULL);
    //void SetOne(const T&DfltVal);
    void SetOne();
    //
    //virtual void SetSize(const T& DfltValParam, const Array2DSize&size)=0;
    //
    //void SetSize(const Array2DSize&size, T*DfltValParam=NULL);//virtual ob hin Sdo mut l'size data
    //void SetSize(int QExtRows=1, int ExtRowsLength=1, T*DfltValParam=NULL);
    //void SetSize(int QExtRows=1, int*ExtRowsLengthes=NULL, T*DfltValParam=NULL);//if Null => L=0
    //void SetSize(std::vector<int>ExtRowsLengthes, T*DfltValParam=NULL);
    //
    //void SetSize(const T& DfltValParam, int QExtRows=1, int ExtRowsLength=1);//virtual ob hin Sdo mut l'size data
    //void SetSize(const T& DfltValParam, int QExtRows=1, int*ExtRowsLengthes=NULL);//if Null => L=0
    //void SetSize(const T& DfltValParam, std::vector<int>Lengthes);
    //
    //virtual void SetSize(int QExtRows=1, int ExtRowsLength=1)=0;
    void SetSize(int QExtRows=1, int ExtRowsLength=1);
    //
    //virtual int GetQExtRows() const=0;
    //virtual int GetLength(int ExtRowN=1) const=0;
    //virtual int GetMinLength() const=0;
    //virtual int GetMaxLength() const=0;
    //virtual int GetQLines()=0;
    int GetQLines();
    //virtual int GetQColumns()=0;
    int GetQColumns();
    //virtual Array2DSize GetSize()const =0;
    //
    //bool LineNBelongsHere(int LineN) const;
    //bool ColNBelongsHere(int ColN) const;
    bool NsBelongHere(int ExtRowN, int IneRowN) const;
    //
    //std::vector<T> GetArrayOfExtRowN(int LineN);
    //std::vector<T> GetArrayOfIneRowN(int ColN);
    //std::vector<T> GetContentAsArray1D();
    //std::vector<std::vector<T>> GetContentAsArray2D();
    //
    //std::vector<T> GetExtRowN_AsArray(int rowN) const;
    std::vector<double> GetLineN_AsArray(int rowN) const;
    // T*GetExtRowN_AsPtr(int ExtRowN) const;
    //std::vector<T> GetIneRowN_AsArray(int rowN) const;
    std::vector<double> GetColumnN_AsArray(int rowN) const;
    //std::vector<T> GetIneRowN_AsArray(int IneRowN, const T& defaultVal,                         int ifNGTLmin_Ignore0_DefaultsForShorter1_NurProperL_AnyExtRow2_NurFromStartTillErstStop3=0) const;
    //std::vector<T> GetIneRowN_AsArray(int IneRowN,                      T*DefaultValParam=NULL, int ifNGTLmin_Ignore0_DefaultsForShorter1_NurProperL_AnyExtRow2_NurFromStartTillErstStop3=0) const;
    //std::vector<T> GetContent_AsArray1D() const;
    //std::vector<std::vector<T>> GetContent_AsArray2D() const;
    std::vector<double> GetContent_AsArray1DOfLines() const;
    std::vector<double> GetContent_AsArray1DOfColumns() const;
    std::vector<std::vector<double>> GetContent_AsArray2DOfLines() const;
    std::vector<std::vector<double>> GetContent_AsArray2DOfColumns() const;
    //
    //
    //virtual T GetComponent_AsVal(int LineN, int ColN) const=0;
    //virtual T* GetComponent_AsPtr(int LineN, int ColN) const=0;
    double GetComponent(int LineN, int ColN) const;
    //double* GetComponent_AsPtr(int LineN, int ColN) const;
    //
    //virtual void SetComponent(const T& val, int LineN, int ColN)=0;
    void SetComponent(double val, int LineN, int ColN);
    //
    //void AddToExtRowN(int RowN, const T&val);
    //void InsToExtRowN(int RowN, int PosN, const T&val);
    //void DelFromExtRowN(int RowN, int PosN);
    //
    //virtual void AddToExtRowN_Simply(int ExtRowN, const T&val)=0;
    //virtual void InsToExtRowN_Simply(int ExtRowN, int PosN, const T&val)=0;
    //virtual void DelFromExtRowN_Simply(int RowN, int IneRowPosN)=0;
    //
    // Ext row
    //
    //template<typename T> void ArrayOf2DBy1D_SetExtRowN(T*&X, Array2DSize&size, int ExtRowN,       T DefaultVal, T*rowParam, int wholeRowL=0,                      TDataShiftParams*DataShiftParam=NULL, /*bool KeepIfRect=true,*/ bool DefaultIsSpecNotOwn=true,      int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2){
    //virtual              void               SetExtRowN(                              int N, const T& defaultVal,  T*rowParam,      int rowL,    TDataShiftParams*DataShiftParams=NULL,                          bool DefaulsAreSpecNotOwnVals=true, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2)=0;
    //void SetExtRowN(int N, const T& defaultVal, T*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true,                      int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2);
    //void SetExtRowN(int N,                      T*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, T*DfltValParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2);
    //
    //void SetExtRow_Simply(int N, T*rowParam)=0;
    //void SetExtRow_Simply(int N, T*rowParam, int L)=0;
    //
    void SetLineN_OwnDataType(int N,      double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1);
    void SetLineN_Gen(        int N,      double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1);
    void             SetLineN(int N,      double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1);
    void SetLineN_Simply     (int N, double*rowParam);
    //
    //template<typename T>void ArrayOf2DBy1D_AddExtRow(T*&X, Array2DSize&size, T DefaultVal, T*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL){
    //                      void               AddExtRow(                        T DefaultVal, T*rowParam, int wholeRowL=0,                         TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL);
    //template<typename T>void ArrayOf2DBy1D_AddExtRow(T*&X, Array2DSize&size, T*rowParam, int wholeRowL=0, T*DefaultValParam=NULL, TDataShiftParams*DataShiftParam=NULL,  int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL){
    //                      void               AddExtRow(                                      T*rowParam, int wholeRowL=0, T*DefaultValParam=NULL, TDataShiftParams*DataShiftParam=NULL,  int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL);
    //
    //virtual void AddExtRow_Simply(T*rowParam)=0;
    //virtual void AddExtRow_Simply(T*rowParam, int L)=0;
    //
    void AddLine_OwnDataType(double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    void AddLine_Gen        (double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    void AddLine            (double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    void AddLine_Simply(double*rowParam);
    //
    //template<typename T>void ArrayOf2DBy1D_InsExtRow(T*&X, Array2DSize&size, int ExtRowN, T DefaultVal, T*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL){
    //                      void               InsExtRow(                        int ExtRowN, T DefaultVal, T*rowParam, int wholeRowL=0,                      TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL);
    //template<typename T>void ArrayOf2DBy1D_InsExtRow(T*&X, Array2DSize&size, int ExtRowN, T*rowParam, int wholeRowL=0,  T*DfltValParam=NULL, TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL){
    //                      void               InsExtRow(                        int ExtRowN,               T*rowParam, int wholeRowL=0, T*DfltValParam=NULL, TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL);
    //
    //virtual void InsExtRow_Simply(int N, T*rowParam)=0;
    //virtual void InsExtRow_Simply(int N, T*rowParam, int L)=0;
    //
    void InsLine_OwnDataType(int LineN, double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    void InsLine_Gen        (int LineN, double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    void InsLine            (int LineN, double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    void InsLine_Simply(double*rowParam);
    //
    //void DelExtRowN(int N=-1);
    //virtual void DelExtRowN_Simply(int N=-1)=0;
    //
    void DelLineN(int N=-1);
    //
    //Ine row
    //
    //void SetIneRowN( int IneRowN, const T& defaultVal, T*rowParam=NULL, int rowL=0, TDataShiftParams*DataShiftParam=NULL,                         bool DefaulsAreSpecNotOwnVals=true, int arr2D_ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_AnyExtRow3_NurFromStartTillErstStop4=0, int arr1D_ifNurProperL_NsSame1_EltsWithNsOfShoeterExtRowsNeUsed2=1);
    //void SetIneRowN( int IneRowN,                      T*rowParam=NULL, int rowL=0, TDataShiftParams*DataShiftParam=NULL, T*DefaultValParam=NULL, bool DefaulsAreSpecNotOwnVals=true, int arr2D_ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_AnyExtRow3_NurFromStartTillErstStop4=0, int arr1D_ifNurProperL_NsSame1_EltsWithNsOfShoeterExtRowsNeUsed2=1);
    //
    //virtual void SetIneRowSimply(int IneRowN, T*rowParam)=0;
    //
    //
    //void SetColumnN(int N,                      double*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1);
    void SetColumnN_OwnDataType(int N,            double*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1);
    void SetColumnN_Gen        (int N,            double*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1);
    //void SetColumnN          (int N,            double*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1);
    void SetColumnN_Simply(int N, double*rowParam);
    //template<typename T>void ArrayOf2DBy1D_AddIneRow(T*&X, Array2DSize& size, T DefaultVal, T*rowParam=NULL, int wholeRowL=0, TDataShiftParams*dataShiftParam=NULL,                         int ifNGTLmin_Ignore0AddToLast1StretchToMax2=0, bool RectIfPossible=true){
    //                     void               AddIneRow(                         T DefaultVal, T*rowParam=NULL, int wholeRowL=0, TDataShiftParams*dataShiftParam=NULL,                         int ifNGTLmin_Ignore0AddToLast1StretchToMax2=0, bool RectIfPossible=true)=0;
    //                     void               AddIneRow(                                       T*rowParam=NULL, int wholeRowL=0, TDataShiftParams*dataShiftParam=NULL, T*DefaultValParam=NULL, int ifNGTLmin_Ignore0AddToLast1StretchToMax2=0, bool RectIfPossible=true)=0;
    //
    //virtual void AddIneRow_Simply(T*rowParam)=0;
    //
    void AddColumn_OwnDataType(double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    void AddColumn_Gen        (double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    //void AddColumn          (double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    void  AddColumn_Simply(double*rowParam);
    //
    //template<typename T>void ArrayOf2DBy1D_InsIneRowN(T*&X, Array2DSize& size, int IneRowN, T DefaultVal, T*rowParam=NULL, int wholeRowL=0,                         TDataShiftParams*DataShiftParam=NULL, int ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_ValForShorterIsMissedForNsFitKeeping3_NextNewValToNextProperL4=1){
    //                      void               InsIneRowN(                         int IneRowN, T DefaultVal, T*rowParam=NULL, int wholeRowL=0,                         TDataShiftParams*DataShiftParam=NULL, int arr2D_ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_AnyExtRow3_NurFromStartTillErstStop4=0, int arr1D_ifNurProperL_NsSame1_EltsWithNsOfShoeterExtRowsNeUsed2=1);
    //                      void               InsIneRowN(                         int IneRowN,               T*rowParam=NULL, int wholeRowL=0, T*DefaultValParam=NULL, TDataShiftParams*DataShiftParam=NULL, int arr2D_ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_AnyExtRow3_NurFromStartTillErstStop4=0, int arr1D_ifNurProperL_NsSame1_EltsWithNsOfShoeterExtRowsNeUsed2=1);
    //
    //virtual void InsIneRow_Simply(int N, T*rowParam)=0;
    //
    void InsColumn_OwnDataType(int ColN, double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    void InsColumn_Gen        (int ColN, double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    //void InsColumn            (int ColN, double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    void InsColumn_Simply(int ColN, double*rowParam);
    //
    //void DelIneRowN(int N=-1, int ifNGTLmin_Ignore0_DelLast1_NurProperL_AnyExtRow3_NurFromStartTillFirstBreak4=0);
    //virtual void DelIneRow_Simply(int N=-1)=0;
    //
    void DelColumnN(int N=-1);
    //
    // Set Content
    //
    //void Set(T**y, const Array2DSize& size,  bool WriteSize=true);
    //void Set(T**y, std::vector<int>ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(T**y, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(T**y, int QExtRows, int ExtRowsLength=1, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(T*y, const Array2DSize& size, bool WriteSize=true);
    //void Set(T*y, std::vector<int>ExtRowsLengthes, bool WriteSize=true);
    //void Set(T*y, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true,  bool WriteSize=true);
    //void Set(T*y, int QExtRows, int ExtRowsLength=1, bool RectIfPossible=true, bool sizeVaria=false, bool WriteSize=true);
    //void Set(std::vector<std::vector<T>>y, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(std::vector<T>y, const Array2DSize& size, bool WriteSize=true);
    //void Set(std::vector<T>y, std::vector<int>ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(std::vector<T>y, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(std::vector<T>y, int QExtRows, int ExtRowsLength=1, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(const T&val, const Array2DSize& size, bool WriteSize=true);
    //void Set(const T&val, std::vector<int>ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(const T&val, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(const T&val, int QExtRows, int ExtRowsLength=1, bool RectIfPossible=true, bool WriteSize=true);
    //
    void Set_arrOfLines(double**y, int QExtRows, int ExtRowsLength=1);
    void Set_arrOfLines(double*y, int QExtRows, int ExtRowsLength=1);
    void Set_arrOfLines(std::vector<double>y, int QExtRows, int ExtRowsLength=1);
    void Set_arrOfLines(std::vector<std::vector<double>>y);
    void Set_arrOfColumns(double**y, int QExtRows, int ExtRowsLength=1);
    void Set_arrOfColumns(double*y, int QExtRows, int ExtRowsLength=1);
    void Set_arrOfColumns(std::vector<double>y, int QExtRows, int ExtRowsLength=1);
    void Set_arrOfColumns(std::vector<std::vector<double>>y);
    //
    //void SwapVals(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
    //void SwapExtRows(int N1, int N2);
    //void SwapIneRows(int N1, int N2);
    //void ReverseExtRowN(int rowN);
    //void ReverseIneRowN(int rowN);
    //void ReverseExtRowsSuccession();
    //void ReverseExtRowsSuccession();
    //void ReverseIneRowsSuccession();
    //void ReverseIneRowsSuccession();
    //
    void SwapVals(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
    void SwapLines(int N1, int N2);
    void SwapColumns(int N1, int N2);
    void ReverseLineN(int rowN);
    void ReverseColumnN(int rowN);
    void ReverseLinesSuccession();
    void ReverseColumnsSuccession();
    //
    //bool ValIsAtPos(const T&val, int ExtRowN, int IneRowN) const;
    bool ValIsAtPos(double val, int ExtRowN, int IneRowN) const;
    //swa S di n'fit prototype - obe s': alt IneRowN wa ExtRowN, so ExtRowN 2x, ce alt err
    //std::vector<std::vector<int>> SeekVal(const T&val) const;
    //std::vector<Int2DVectorOfSizeOrCoords> SeekVal(const T&val) const;
    //TListOfNumberPairs SeekVal(const T&val) const;
    TListOfNumberPairs SeekVal(double val) const;
    //so class name. Ma to vrns co std::vector ety di n'fit prototype
    //bool ExtRowIsAtPos(T*row, int Q, int ExtRowN, int IneRowN) const;
    bool ExtRowIsAtPos(double*row, int Q, int ExtRowN, int IneRowN) const;
    //std::vector<std::vector<int>> SeekExtRow(T*row, int L) const;
    //std::vector<Int2DVectorOfSizeOrCoords> SeekExtRow(T*row, int L) const;
    //TListOfNumberPairs SeekExtRow(T*row, int L) const;
    TListOfNumberPairs SeekExtRow(double*row, int L) const;
    //bool IneRowIsAtPos(T*row, int Q, int ExtRowN, int IneRowN) const;
    bool IneRowIsAtPos(double*row, int Q, int ExtRowN, int IneRowN) const;
    //std::vector<std::vector<int>> SeekIneRow(T*row, int Q) const;
    //std::vector<Int2DVectorOfSizeOrCoords> SeekIneRow(T*row, int Q) const;
    //TListOfNumberPairs SeekIneRow(T*row, int Q) const;
    TListOfNumberPairs SeekIneRow(double*row, int Q) const;

    //bool Arr2DIsAtPos(std::vector<std::vector<T>>arr, int ExtRowN, int IneRowN, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    bool Arr2DIsAtPos(std::vector<std::vector<double>>arr, int ExtRowN, int IneRowN, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    bool Arr2DIsAtPos(Matrix_Prototype*arr, int ExtRowN, int IneRowN, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;

    //std::vector<std::vector<int>> SeekArr2D(std::vector<std::vector<T>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //std::vector<Int2DVectorOfSizeOrCoords> SeekArr2D(std::vector<std::vector<T>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //TListOfNumberPairs SeekArr2D(std::vector<std::vector<T>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    TListOfNumberPairs SeekArr2D(std::vector<std::vector<double>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //std::vector<std::vector<int>> SeekArr2D(Array2D_Prototype*arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //std::vector<Int2DVectorOfSizeOrCoords> SeekArr2D(Array2D_Prototype*arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    TListOfNumberPairs SeekArr2D(Matrix_Prototype*obj, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //
    //virtual void ConcatAdding(Matrix_Prototype*obj, T DefaultVal,int QShiftedCols=0,  TDataShiftParams*DataShiftParam=NULL, bool SetRect=true, int DfltRowL_00_11_Lmin2_Lmax3=1);
    //virtual void ConcatAdding(Matrix_Prototype*obj, int QShiftedCols=0, TDataShiftParams*DataShiftParam=NULL, T*DefaultValParam=NULL, bool SetRect=true, int DfltRowL_00_11_Lmin2_Lmax3=1);
    //
    void ConcatAdding(Matrix_Prototype*obj, int QShiftedCols=0, TDataShiftParams*DataShiftParam=NULL);
    //_ConcatStretching(T*X1, const Array2DSize& size1, T*X2, const Array2DSize& size2, T*&X3, Array2DSize& size3, T DefaultVal, int shiftQ=0, TDataShiftParams*DataShiftParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3, bool Stretch1ToMax=true, bool SetRect=true){
    //virtual void ConcatStretching(Matrix_Prototype*obj, T DefaultVal, int QShiftedExtRowNs=0,  TDataShiftParams*DataShiftParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3, bool Stretch1ToMax=true, bool SetRect=true);
    //virtual void ConcatStretching(Matrix_Prototype*obj, int QShiftedExtRowNs=0, TDataShiftParams*DataShiftParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3, bool Stretch1ToMax=true, bool SetRect=true, T*DefaultValParam=NULL);
    void ConcatStretching(Matrix_Prototype*obj, int QShiftedCols=0, TDataShiftParams*DataShiftParam=NULL);
    //
    //virtual Matrix_Prototype*GetSubMatrix(int ExtRowN, int IneRowN, const Array2DSize& size, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const=0;
    Matrix GetSubMatrix(int ExtRowN, int IneRowN, const Array2DSize& size, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //virtual Matrix_Prototype*GetSubMatrix(TDataShiftParams*DataShiftParam=NULL) const=0;
    Matrix GetSubMatrix(TDataShiftParams*DataShiftParam=NULL) const;
    //
    //void ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(T val, int ExtRowN, int IneRowN, T DefaultVal, bool SetRect=true, int DfltRowL_00_11_Max2_Min3=2);
    //void ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(T val, int ExtRowN, int IneRowN, bool SetRect=true, int DfltRowL_00_11_Max2_Min3=2, T*DefaultValParam=NULL);
    //
    void ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(double val, int ExtRowN, int IneRowN);
    //
    void StdCout_ExtRowN(int ExtRowN, QString ElemsDelim="; ", bool UseBrackets=true) const;
    void StdCout_IneRowN(int IneRowN, QString ElemsDelim="; ", bool UseBrackets=true, bool Represent2DNot1D=false) const;
    void StdCout(QString ElemsDelim=", ", QString RowsDelim="; ", bool UseBrackets=true, bool Represent2DNot1D=true, bool ByExtRowsNotIneRows=true) const;
};//Matrix//Shell

Matrix operator + (const Matrix& M1, const Matrix& M2);
Matrix operator - (const Matrix& M1, const Matrix& M2);
Matrix operator * (const Matrix& M1, const Matrix& M2);
Matrix operator / (const Matrix& M1, const Matrix& M2);

Matrix operator * (const Matrix& M, double x);
Matrix operator * (double x, const Matrix& M);

Matrix operator + (const Matrix& M, double x);
Matrix operator + (double x, const Matrix& M);
Matrix operator - (const Matrix& M, double x);
Matrix operator - (double x, const Matrix& M);

bool operator ==(const Matrix& M1, const Matrix& M2);
bool operator !=(const Matrix& M1, const Matrix& M2);

Matrix fApproxSolveLinAlgEqsSysSeidel(const Matrix&M, const Matrix&V, Matrix X0, TItersPrecision Precision);

Matrix GivensRotationTransformMatrix(Matrix*M, int N1, int N2, Matrix*P, TValsShowHide*vsh=NULL);
void QRDecomposition(Matrix&Q, Matrix&R,  Matrix*P=NULL, TValsShowHide* vsh = NULL);

Matrix SolveLinearSys(const Matrix&A, const Matrix&F);
Matrix SolveLinearSysBySeidel(const Matrix&A, const Matrix&F, TItersPrecision Precision, Matrix*P=NULL);

Matrix CalcMatrixOfDirCossByEulersAngles(Matrix MEulerAngles);

Matrix CalcCoordsTransformFromOldCSToNew(Matrix*CoordsInOldCSParam, Matrix*EulerAnglesParam, Matrix*CSOriginOfNewCSInOldParam=NULL, TValsShowHide*vsh=NULL);
Matrix CalcCoordsTransformFromNewCSToOld(Matrix*CoordsInNewCSParam, Matrix*EulerAnglesParam, Matrix*CSOriginOfNewCSInOldParam=NULL, TValsShowHide*vsh=NULL);

Matrix ConcatAdding(const Matrix&M1, const Matrix&M2, int QShiftedCols=0, int FromN=1, int QAdded=0);
Matrix ConcatStretching(const Matrix&M1, const Matrix&M2, int QShiftedLines=0, int FromN=1, int QAdded=0);

#endif // MATRICES_H
