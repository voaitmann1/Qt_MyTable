#ifndef MYLIB_H
#define MYLIB_H


#include<iostream>
#include<QString>
//#include<string>//S int std::string et ac ce
#include"math.h"
#include<typeinfo>
#include<conio.h>//for getch
//#include"array2dsize.h"//!
#include <QTextStream>//f' borrowed fns f'
//#include <qtextbrowser.h>//QTextBrowser
//class MyLib
//{
//public:
//    MyLib();
//};

//template <typename T> void Array1DShowConsole(T*x, int Q, std::string delim="; ", bool LineNotCol=true){

//}

const bool BoolValByDefault=true;
const int MaxInt=65000;

int BoolToInt(bool x);
int IntOfBool(bool x);
bool IntToBool(int x);
bool BoolOfInt(int x);

template<typename T> T GetDefaultVal(T*param=NULL);

template <class T> class TValuesPair{
T val1, val2;
public:
    TValuesPair();
    TValuesPair(const T&val1, const T&val2);
    TValuesPair(const T&val);
    //TValuesPair(const TValuesPair&obj);// no need: no dyn objs
    ~TValuesPair();
    //void construct();
    //TValuesPair<T>*Create();
    TValuesPair<T>*Clone();
    TValuesPair<T>& operator = (const TValuesPair&obj);
    bool operator == (const TValuesPair&obj);
    void SetVals(const T&val1, const T&val2);
    void GetVals(T&val1, T&val2);
    T GetVal1();
    T GetVal2();
    T*GetPointerToValN(int N);
    void SetValN(const T&val, int N);
    void SetVal1(const T&val);
    void SetVal2(const T&val);
    void SetVals(const T&val);
    void SwapVals();
    //int GetSize();
};

template<typename T> TValuesPair<T>::TValuesPair(){
    //construct();
    //NOP
}
template<typename T> TValuesPair<T>::TValuesPair(const T&val1, const T&val2){
    //construct();
    this->Set(val1, val2);
}
template<typename T> TValuesPair<T>::TValuesPair(const T&val){
    //construct();
    this->SetVals(val);
}
//template<typename T> TValuesPair<T>::TValuesPair(const TValuesPair&obj){
//    T val1=obj.GetVal1(), val2=obj.GetVal2();
//    this->Set(val1, val2);
//    //this->Set(obj.GetVal1(), obj.GetVal2());
//}
template<typename T> TValuesPair<T>::~TValuesPair(){
    //NOP
}
//template<typename T> TValuesPair<T>* TValuesPair<T>::Create(){
//    return new TValuesPair<T>();
//}
template<typename T> TValuesPair<T>* TValuesPair<T>::Clone(){
    return this;
}
//template<typename T> void TValuesPair<T>::construct(){
//    //NOP;
//}
template<typename T> TValuesPair<T>&  TValuesPair<T>::operator = (const TValuesPair&obj){
    this->SetVals(obj.GetVal1(), obj.GetVal2());
    return *this;
}

template<typename T> bool  TValuesPair<T>::operator == (const TValuesPair&obj){
    return ((this->GetVal1() == obj.GetVal1()) && (this->GetVal2() == obj.GetVal2()));
}

template<typename T>T TValuesPair<T>::GetVal1(){
    return this->val1;
}
template<typename T>T TValuesPair<T>::GetVal2(){
    return this->val2;
}
template<typename T> T* TValuesPair<T>::GetPointerToValN(int N){
    T*ptr=NULL;
    if(N==1 || N==-2){
        ptr=val1;
    }else if(N==2 || N==-1){
        ptr=val2;
    }
    return ptr;
}
template<typename T> void TValuesPair<T>::SetValN(const T&val, int N){
    if(N==1 || N==-2){
        this->SetVal1(val);
    }else if(N==2 || N==-1){
        this->SetVal2(val);
    }
}
template<typename T>void TValuesPair<T>::SetVal1(const T&val){
    this->val1=val;
}
template<typename T>void TValuesPair<T>::SetVal2(const T&val){
    this->val2=val;
}
template<typename T>void TValuesPair<T>::SetVals(const T&val1, const T&val2){
    this->SetVal1(val1);
    this->SetVal2(val2);
}
template<typename T>void TValuesPair<T>::SetVals(const T&val){
    this->SetVals(val, val);
}
template<typename T>void TValuesPair<T>::GetVals(T&val1, T&val2){
    val1=this->GetVal1();
    val2=this->GetVal2();
}
template<typename T>void TValuesPair<T>::SwapVals(){
    T buf;
    buf=val1;
    val1=val2;
    val2=buf;
}
//template<typename T> int TValuesPair<T>::GetSize(){
//    return 2;
//}



QString FloatToStr(float x);
QString FloatToStr(double x);
QString IntToStr(int x);

QString UniqueStrValGenerator(std::vector<QString>vals, QString proposedVal, int N, QString bef="", QString aft="");

void Calc_Array1DSubArray_byLs_MarkupNs_vFmls(int&LreqCalcd, int&preN1_, int&preN2_, int&ownN1_, int&ownN2, int&ForOwnN1_, int&ForOwnN2, int&postN1, int&postN2_, int Lini, int LreqGiven=0, int whatFromN=1, int QDefaultValuesBefore=0);
int CalcLreq_Array1DSubArray_byLs_MarkupNs_vFmls(int Lini, int whatFromN=1, int QDefaultValuesBefore=0, int LreqGiven=0);
void Calc_Array1DSubArray_byLs_MarkupNs_vCycls(int&LreqCalcd, int&preN1_, int&preN2_, int&ownN1_, int&ownN2, int&ForOwnN1_, int&ForOwnN2, int&postN1, int&postN2_, int Lini, int LreqGiven=0, int whatFromN=1, int QDefaultValuesBefore=0);
int CalcLreq_Array1DSubArray_byLs_MarkupNs_vCycls(int Lini, int whatFromN=1, int QDefaultValuesBefore=0, int LreqGiven=0);

void Calc_Array1DSubArray_byLs_MarkupNs_vFml_FixedDfltsAfter(int&LreqCalcd, int&preN1, int&preN2, int&ownN1, int&ownN2, int&ForOwnN1, int&ForOwnN2, int&postN1, int&postN2, int Lini, int LreqGiven=0, int whatFromN=1, int QDefaultValuesAfter=0);

void CalcNsOfSubArray(int whereL, int whatL, int&FromN1, int&ToN1, int FromN0=1, int ToN0=0);

//std::vector<double> GetNumericSubarray_byLs(std::vector<double> x, int FromN=1, int QDefaultValuesBefore=0, int LreqGiven=0, std::vector<double>*ArrOfDfltVals=NULL);
//std::vector<double> GetNumericSubarray_byLs(std::vector<double> x, int FromN=1, int QDefaultValuesBefore=0, int LreqGiven=0);
//std::vector<double> GetNumericSubarray_byLs(std::vector<double> x, std::vector<double> ArrOfDfltVals, int FromN=1, int QDefaultValuesBefore=0, int LreqGiven=0);
class TParamsOfDataShift;//forward declaration
QString MySubString_byNs(QString where, int N1, int N2);
//QString MySubString_byLs(QString where, int N1, int L);
//QString MySubString_byLs_Formatting(QString where, int N1, int L, QString defaultVal=" ");
QString MySubString_L1(QString where, int N1);
QString MySubString_byLs_Formatting_PreMark(QString Sini, int LreqGiven=0, int FromN=1, int QDefaultBefore=0, QString Default=" ");QString MySubString_byLs_Formatting_PreMark(QString Sini, TParamsOfDataShift DataShiftParams, QString Default, int PgN);

QString ToLowerCase(QString str);
QString ToUpperCase(QString str);
bool SubstringIsAtPos(QString where, QString what, int N, bool MatchCase=true, bool direct=true);
std::vector<int>SeekSubstring(QString where, QString what, int FromN=1, int ToN=0, bool MatchCase=true);

bool IsTrueWord(QString word);

bool IsFalseWord(QString word);

int IsMathFunction(QString word);

class TValsShowHide; //forward decl

char*ReadLine(FILE*f);
//char*ReadLine(FILE*f, int Show1Hide0, bool ConsoleInterface, TMemo*M);
int CharPtrToArr(char*ptr, char Arr[]);

double ReadLineAsDouble(FILE*f);
float ReadLineAsFloat(FILE*f);
float ReadLineAsInt(FILE*f);

//typedef std::vector<DataCell>TVectorOfCells;
//typedef std::vector<double>TDoubleVector;
//typedef std::vector<float>TFloatVector;
//typedef std::vector<int>TIntVector;
//typedef std::vector<bool>TBoolVector;
//typedef std::vector<QString>TStringVector;
//typedef std::vector<std::string>TStdStringVector;

void writeln(TValsShowHide *VSH, char*s);
void writeln(TValsShowHide *VSH, QString str);
//void writeln(TValsShowHide *VSH, char*s);
void writeln(TValsShowHide *VSH, std::string str);




//template <typename T> void Array1DShowConsole(T*x, int Q, std::string delim="; ", bool LineNotCol=true){}
//template <typename T> void Array1DShowConsole(T*x, int Q, std::string delim="; ", bool LineNotCol=true){
//
//}

template<typename T> QString ToString(const T& x){
    QString s;
    std::string ss;
    int ix;
    if(typeid(T)==typeid(float) || typeid(T)==typeid(double) || typeid(T)==typeid(int)){
        s.setNum(x);
    }else if(typeid(T)==typeid(bool)){
        ix=BoolToInt(x);
        s.setNum(x);
    }else if(typeid(T)==typeid(QString)){
        s=x;
    }else if(typeid(T)==typeid(std::string)){
        ss=x;
        s=QString(ss.c_str());
    }else if(typeid(T)==typeid(char*)){
        s=QString(x);
    }else{
        s="";
    }
    return s;
}

template<typename T>bool EqualSimple(const T& x1, const T& x2, int param=0){
    return (x1==x2);
}
//
//
template <typename T>void VectorSetSize(T*&x, int QOld, int QNew, T DefaultVal, int PreserveVals=true){
    T*y=NULL;
    //T z=DefaultVal;
    int minL;
    if(x!=NULL && QOld!=QNew && QOld>0 && QNew>=0){
        if(QNew=0){
            delete[]x;
        }else{
            y=new T[QNew];
            minL=QOld<QNew?QOld:QNew;
            if(PreserveVals){
                //if(DfltVal!=NULL){
                //    z=(*(DfltVal));
                //}
                for(int i=1; i<=minL; i++){
                    y[i-1]=x[i-1];
                }
                for(int i=minL+1; i<=QNew; i++){
                    y[i-1]=DefaultVal;
                }
                //
                delete[]x;
                x=y;
            }//if preserve vals
        }//if to start
    }//if to act
}//fn
template <typename T>void VectorSetSize(T*&x, int QOld, int QNew, T*DefaultValParam=NULL, int PreserveVals=true){
    T DefaultVal;
    if(DefaultValParam!=NULL){
        DefaultVal=*DefaultValParam;
    }
    VectorSetSize(x, QOld, QNew, DefaultVal, PreserveVals);
}
template <typename T>void VectorSetSize(std::vector<T>&x, int QNew, const T& DefaultVal){
    int minL;
    int QOld=x.size();
    if(x!=NULL && QOld!=QNew && QOld>0 && QNew>=0){
        if(QOld<QNew){
            for(int i=QOld; i<=QNew; i++){
                x.push_back(DefaultVal);
            }
        }else if(QOld>QNew){
            for(int i=QNew; i<=QOld; i++){
                x.erace(x.begin()+QNew-1);
            }
        }
    }//if to act
}//fn
template <typename T>void VectorSetSize(std::vector<T>&x, int QNew, T*DefaultValParam=NULL){
    T DefaultVal;
    if(DefaultValParam!=NULL){
        DefaultVal=*DefaultValParam;
    }
    VectorSetSize(x, QNew, DefaultVal);
}
//
template <typename T>void VectorAddVal(T*&x, int&Q, const T& val){
    T*y=NULL;
    y=new T[Q+1];
    if(x!=NULL){
        for(int i=1; i<=Q; i++){
            y[i-1]=x[i-1];
        }
    }
    y[Q-1]=val;
    if(x!=NULL){
        delete[]x;
    }
    x=y;
    Q++;
}
template <typename T>void VectorAddVal(std::vector<T>&x,  const T& val){
    x.push_back(val);
}
//
template <typename T>void VectorInsVal(T*&x, int&Q, int N, const T& val){
    T*y=NULL;
    y=new T[Q+1];
    if(x!=NULL && N>=1 && N<=Q){
        for(int i=1; i<=N-1; i++){
            y[i-1]=x[i-1];
        }
        for(int i=N+1; i<=Q+1; i++){
            y[i-1]=x[i-1-1];
        }
    }
    y[N-1]=val;
    if(x!=NULL){
        delete[]x;
    }
    x=y;
    Q++;
}
template <typename T>void VectorInsVal(std::vector<T>&x, int N, const T& val){
    int Q=x.size();
    if(x!=NULL && N>=1 && N<=Q){
        x.insert(x.begin()+N-1, val);
    }
}
//
template <typename T>void VectorDelVal(T*&x, int&Q, int N){
    T*y=NULL;
    if(Q>1){
        y=new T[Q-1];
        for(int i=1; i<=N-1; i++){
            y[i-1]=x[i-1];
        }
        for(int i=N; i<=Q-1; i++){
            y[i-1]=x[i-1+1];
        }
        Q--;
    }else if(Q==1){
        delete[]x;
        x=NULL;
        Q--;
    }
}
template <typename T>void VectorDelVal(std::vector<T>&x, int N){
    x.erase(x.begin()+N-1);
}
template <typename T>std::vector<int> VectorSeekVal(T*x, int Q, const T& valParam){
    std::vector<int>Ns;
    int N;
    T valInner;
    for(N=1; N<=Q; N++){
        valInner=x[N-1];
        if(valInner==valParam){
            Ns.push_back(N);
        }
    }
    return Ns;
}
template <typename T>std::vector<int> VectorSeekVal(std::vector<T>x, const T& valParam){
    std::vector<int>Ns;
    int Q=x.size(), N;
    T valInner;
    for(N=1; N<=Q; N++){
        valInner=x[N-1];
        if(valInner==valParam){
            Ns.push_back(N);
        }
    }
    return Ns;
}
template <typename T> T* VectorGetPtrToElementN(T*x, int Q, int N){
    T*ptr=NULL;
    if(N<0){
        N+=(Q+1);
    }
    if(x!=NULL && Q>0 && N>=1 && N<=Q){
        ptr=x[N-1];
    }
    return ptr;
}
template <typename T>T* VectorPointToValByName(T*x, int Q, QString name, std::vector<QString>names){
    T*ptr=NULL;
    std::vector<int>Ns=VectorSeekVal(names, name);
    if(Ns.size()==1){
        ptr=VectorGetPtrToElementN(x, Q, Ns[1-1]);
    }
    return Ns;
}

template <typename T> void VectorStdCout(T*x, int Q, std::string delim="; ", bool represent2DNot1D=false){
    T val;
    if(represent2DNot1D){
        for(int i=1; i<=Q-1; i++){
            val=x[i-1];
            std::cout<<val;
            std::cout<<delim;
            std::cout<<std::endl;
        }
    }else{
        for(int i=1; i<=Q-1; i++){
            val=x[i-1];
            std::cout<<val;
            std::cout<<delim;
            //std::cout<<std::endl;
        }
    }
    val=x[Q-1];
    std::cout<<val;
}
template <typename T> void VectorStdCout(std::vector<T>x, std::string delim="; ", bool represent2DNot1D=false){
    int Q=x.size();
    T val;
    if(represent2DNot1D){
        for(int i=1; i<=Q-1; i++){
            val=x[i-1];
            std::cout<<val;
            std::cout<<delim;
            std::cout<<std::endl;
        }
    }else{
        for(int i=1; i<=Q-1; i++){
            val=x[i-1];
            std::cout<<val;
            std::cout<<delim;
            //std::cout<<std::endl;
        }
    }
    val=x[Q-1];
    std::cout<<val;
}

//
void GetSubArrayNs(int Q, int&QReqCalcd, int&preN1, int&preN2, int&ownN1, int&ownN2, int&ForOwnN1, int&ForOwnN2, int&postN1, int&postN2, int FromN=1, int QReqGiven=0, int QDefaultsBefore=0, bool IfZuManyBeforeCutEmEtGiMoreOwnVals=false);
//void GetSubArrayNs(int Q, int&QReqCalcd, int&preN1, int&preN2, int&ownN1, int&ownN2, int&ForOwnN1, int&ForOwnN2, int&postN1, int&postN2, int FromN=1, int QReqGiven=0, int QDefaultsBefore=0);
//void GetSubArrayNs(int Q, int&QReqCalcd, int&preN1, int&preN2, int&ownN1, int&ownN2, int&ForOwnN1, int&ForOwnN2, int&postN1, int&postN2, int FromN=1, int QReqGiven=0, int QDefaultsBefore=0);
//
struct TParamsOfDataShiftFin{
    int QReqCalcd, preN1, preN2, ownN1, ownN2, ForOwnN1, ForOwnN2, postN1, postN2;
};

class TParamsOfDataShift{
    public:
    int QDefaultsBefore, FromN, QReq;
    TParamsOfDataShift(int QReq=0, int FromN=1, int QDefaultsBefore=0);
    int CalcQ(int QGiven);
    TParamsOfDataShiftFin CalcParams(int QGiven);
    QString ToString();
};
//
//QString MySubString_byLs_Formatting_PreMark(QString Sini, int LreqGiven=0, int FromN=1, int QDefaultBefore=0, QString Default=" ");QString MySubString_byLs_Formatting_PreMark(QString Sini, TParamsOfDataShift DataShiftParams, QString Default, int PgN);
//
template <typename T> std::vector<T>GetSubVector(T*X, int Q, T DefaultVal, TParamsOfDataShift*DataShiftParam){
    TParamsOfDataShift DataShift;
    int FromN, QReqGiven, QDefaultsBefore;
    std::vector<T>Y;
    T val;
    int preN1=0, preN2=0, ownN1=0, ownN2=0, ForOwnN1=0, ForOwnN2=0, postN1=0, postN2=0;
    int QReqCalcd;
    if(DataShiftParam!=NULL){
        DataShift=*DataShiftParam;
        FromN=DataShift.FromN;
        QReqGiven=DataShift.QReq;
        QDefaultsBefore=DataShift.QDefaultsBefore;
    }else{
        FromN=1;
        QReqGiven=0;
        QDefaultsBefore=0;
    }
        //void GetSubArrayNs(int Q, int&QReqCalcd, int&preN1, int&preN2, int&ownN1, int&ownN2, int&ForOwnN1, int&ForOwnN2, int&postN1, int&postN2, int FromN=1, int QReqGiven=0, int QDefaultsBefore=0){
          GetSubArrayNs(     Q,     QReqCalcd,     preN1,     preN2,     ownN1,     ownN2,     ForOwnN1,     ForOwnN2,     postN1,     postN2,     FromN,       QReqGiven,       QDefaultsBefore);
    if(preN2>0){
       for(int i=preN1; i<=preN2; i++){
           Y.push_back(DefaultVal);
       }
    }
    if(ownN2>0){
        for(int i=preN1; i<=preN2; i++){
            val=X[i-1];
            Y.push_back(val);
        }
    }
    if(postN2>0){
       for(int i=postN1; i<=postN2; i++){
           Y.push_back(DefaultVal);
       }
    }
    return Y;
}
template <typename T> std::vector<T>GetSubVector(T*X, int Q,  TParamsOfDataShift*DataShiftParam, T*DefaultValParam=NULL){
    T DefaultVal;
    std::vector<T>R;
    if(DefaultValParam!=NULL){
        DefaultVal=*DefaultValParam;
    }
    R=GetSubVector(X, Q, DefaultVal, DataShiftParam);
    return R;
}

template <typename T> std::vector<T>GetSubVector(T*X, int Q, T*X2, int Q2, T DefaultVal, TParamsOfDataShift*DataShiftParam){
    TParamsOfDataShift DataShift;
    int FromN, QReqGiven, QDefaultsBefore;
    std::vector<T>Y;
    T val;
    int preN1=0, preN2=0, ownN1=0, ownN2=0, ForOwnN1=0, ForOwnN2=0, postN1=0, postN2=0;
    int QReqCalcd;
    int minN;
    if(DataShiftParam!=NULL){
        DataShift=*DataShiftParam;
        FromN=DataShift.FromN;
        QReqGiven=DataShift.QReq;
        QDefaultsBefore=DataShift.QDefaultsBefore;
    }else{
        FromN=1;
        QReqGiven=0;
        QDefaultsBefore=0;
    }
    //void GetSubArrayNs(int Q, int&QReqCalcd, int&preN1, int&preN2, int&ownN1, int&ownN2, int&ForOwnN1, int&ForOwnN2, int&postN1, int&postN2, int FromN=1, int QReqGiven=0, int QDefaultsBefore=0){
          GetSubArrayNs(     Q,     QReqCalcd,     preN1,     preN2,     ownN1,     ownN2,     ForOwnN1,     ForOwnN2,     postN1,     postN2,     FromN,       QReqGiven,       QDefaultsBefore);
    if(preN2>0){
       minN = preN2>Q2 ? preN2 : Q2;
       for(int i=preN1; i<=minN; i++){
           val=X2[i-1];
           Y.push_back(val);
       }
       for(int i=minN+1; i<=preN2; i++){
           Y.push_back(DefaultVal);
       }
    }
    if(ownN2>0){
        for(int i=preN1; i<=preN2; i++){
            val=X[i-1];
            Y.push_back(val);
        }
    }
    if(postN2>0){
        if(Q2<postN1){
            for(int i=postN1; i<=postN2; i++){
                Y.push_back(DefaultVal);
            }
        }else{
            minN = postN2 >= Q2 ? postN2 : Q2;
            for(int i=postN1; i<=minN; i++){
                val=X[i-1];
                Y.push_back(val);
            }
            for(int i=minN+1; i<=postN2; i++){
                 Y.push_back(DefaultVal);
            }
        }
    }
    return Y;
}
template <typename T> std::vector<T>GetSubVector(T*X, int Q, T*X2, int Q2, TParamsOfDataShift*DataShiftParam=NULL, T*DefaultValParam=NULL){
    T DefaultVal;
    std::vector<T>R;
    if(DefaultValParam!=NULL){
        DefaultVal=*DefaultValParam;
    }
    R=GetSubVector(X, Q, X2, Q2, DefaultVal, DataShiftParam);
    return R;
}

//
//
template <typename T> bool Equal_Simply(const T& x1, const T& x2, int param=0){
    return (x1==x2);
}

template <typename T> void Print2DArray(T**x, int Q, int *Ls, char* delim=" \0"){
    for(int i=1; i<=Q; i++){
        Print1DArray(x[i-1], Ls[i-1], delim);
    }
}

//void GetSubArrayNs(int Q, int&QReqCalcd, int&preN1, int&preN2, int&ownN1, int&ownN2, int&ForOwnN1, int&ForOwnN2, int&postN1, int&postN2, int FromN=1, int QReqGiven=0, int QDefaultsBefore=0);
//void GetSubArrayNs(int Q, int&QReqCalcd, int&preN1, int&preN2, int&ownN1, int&ownN2, int&ForOwnN1, int&ForOwnN2, int&postN1, int&postN2, int FromN=1, int QReqGiven=0, int QDefaultsBefore=0);

int GetPositionInArrayOf2DRealizedBy1D(std::vector<int>Ls, int ExtRowN, int IneRowPosN);
int GetPositionInArrayOf2DRealizedBy1D(int QExtRows, int ExtRowsLength, int ExtRowN, int IneRowPosN);

class TValsShowHide; //forward declaration!

//

class TValsShowHide{
  public:
    int Show1Hide0;
    bool ConsoleInterface;
 //   QTextBrowser*TxtFld;
    FILE*f;
    //
    TValsShowHide();
    ~TValsShowHide();
    void Assign(const TValsShowHide&obj);
    void EnableWriting();
    void DisableWriting();
    void SetShow1Hide0(int Show1Hide0);
    void write(char*s);
    void write(QString str);
    void writeln(char*s);
    void writeln(QString str);
};
//


/*int Array2DSizeBasedOn1D_PosByCoords(int ExtRowN, int IneRowN, int QExtRows, int*Ls);
int Array2DSizeBasedOn1D_PosByCoords(int ExtRowN, int IneRowN, std::vector<int>Ls);
void Array2DSizeBasedOn1D_CoordsByPos(int PosN, int*Ls, int&ExtRowN, int&IneRowN);
void Array2DSizeBasedOn1D_CoordsByPos(int PosN, std::vector<int>Ls, int&ExtRowN, int&IneRowN);
int Array2DSizeBasedOn1D_ExtRowNByPos(int PosN, int QExtRows, int*Ls);
int Array2DSizeBasedOn1D_ExtRowNByPos(int PosN, std::vector<int>Ls);
int Array2DSizeBasedOn1D_IneRowNByPos(int PosN, int QExtRows, int*Ls);
int Array2DSizeBasedOn1D_IneRowNByPos(int PosN, std::vector<int>Ls);*/

void PrintArray1DInt(int*x, int Q);
void PrintArray1DFloat(int*x, int Q);
void PrintArray1DDouble(int*x, int Q);
void PrintArray1DInt(int**x,int Q, int*Ls);// const Array2DSize&size);

class Int2DVectorOfSizeOrCoords{
public:
    int d1, d2;
    Int2DVectorOfSizeOrCoords(int d1=0, int d2=0);

};

Int2DVectorOfSizeOrCoords Array2DCoordsTransform(Int2DVectorOfSizeOrCoords CoordsWhereFrom, Int2DVectorOfSizeOrCoords CoordsInWhat, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachRowIsNotReversed=true);

std::vector<QString> ReadCsvLine2(QString line, std::vector<QString>delims, int MoreThanOneDelim_Empty0_SingleDelim1=0, TValsShowHide*vsh=NULL);
//std::vector<std::string>ReadFileLines(std::string fName);
std::vector<std::string>ReadFileLines(const char* fName);//now n'work
std::vector<std::wstring>ReadFileLinesW(const wchar_t*fName, int amode);
//
//
//
bool f_find_str(QTextStream *in, QString searchString, QString &findStr );
bool f_find_int(QTextStream *in, QString searchString, int &findI);
bool f_find_bool(QTextStream *in, QString searchString, bool &findB);
bool f_find_float(QTextStream *in, QString searchString, float &findF);
bool f_find_2float(QTextStream *in, QString searchString, float &findF1, float &findF2);
bool f_find_3float( QTextStream *in, QString searchString, float &findF1, float &findF2, float &findF3);
bool f_find_vectorInt(QTextStream *in, QString searchString, std::vector<int> &vi);
bool f_find_vectorFloat(QTextStream *in, QString searchString, std::vector<float> &vf);

QString MyFormatString(QString str, int Lin, QString DefaultRight=".", QString DefaultLeft=" ",  int AlignLeft1Right2CenterLeft3CenterRight4=1);

//int NInArrIfNegative(int N, int Q);

int Arr2DBy1D_PosNByCoords(int ExtRowN, int IneRowN, std::vector<int>Ls);
int Arr2DBy1D_PosNByCoords(int ExtRowN, int IneRowN, int QExtRows, int*Ls);
int Arr2DBy1D_PosNByCoords(int ExtRowN, int IneRowN, int QExtRows, int rowL);
Int2DVectorOfSizeOrCoords Arr2DBy1D_CoordsByPosN(int PosN, int QExtRows, int*Ls);
Int2DVectorOfSizeOrCoords Arr2DBy1D_CoordsByPosN(int PosN, std::vector<int>Ls);

bool IsTransposable(int QRows, int*rowLs);

#endif // MYLIB_H
