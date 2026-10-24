#ifndef MYLIB_H
#define MYLIB_H

#include<iostream>
#include<QString>
#include"math.h"
#include<typeinfo>
#include"array2dlib.h"
#include"tvalsshowhide.h"
//#include <qtextbrowser.h>//QTextBrowser
//class MyLib
//{
//public:
//    MyLib();
//};

const bool BoolValByDefault=true;
const int MaxInt=65000;

int BoolToInt(bool x);
int IntOfBool(bool x);
bool IntToBool(int x);
bool BoolOfInt(int x);

QString FloatToStr(float x);
QString FloatToStr(double x);
QString IntToStr(int x);

bool IsTrueWord(QString word);
bool IsFalseWord(QString word);

int IsMathFunction(QString word);

/*class TValsShowHide; //forward decl
*/

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

/*void writeln(TValsShowHide *VSH, char*s);
void writeln(TValsShowHide *VSH, QString str);*/
//void writeln(TValsShowHide *VSH, char*s);
//void writeln(TValsShowHide *VSH, QString str);

template<typename T>QString ToString(T x){
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


template <typename T>void VectorSetSize(T*&x, int QOld, int QNew, T*DfltVal=NULL, int PreserveVals=true){
    T*y=NULL;
    T z;
    int minL;
    if(x!=NULL && QOld!=QNew && QOld>0 && QNew>=0){
        if(QNew=0){
            delete[]x;
        }else{
            y=new T[QNew];
            minL=QOld<QNew?QOld:QNew;
            if(PreserveVals){
                if(DfltVal!=NULL){
                    z=(*(DfltVal));
                }
                for(int i=1; i<=minL; i++){
                    y[i-1]=x[i-1];
                }
                for(int i=minL+1; i<=QNew; i++){
                    y[i-1]=z;
                }
                //
                delete[]x;
                x=y;
            }//if preserve vals
        }//if to start
    }//if to act
}//fn

template <typename T> bool Equal_Simply(const T& x1, const T& x2, int param=0){
    return (x1==x2);
}

template <typename T>void VectorReSize(T*&x, int&Q, int dQ, T*DfltVal=NULL, int PreserveVals=true){
    int QOld=Q;
    Q+=dQ;
    VectorSetSize(x, QOld, Q, DfltVal, PreserveVals);
}

template <typename T>void VectorAddElement(T*&x, int&Q, T z){//new considers vrn x=NULL
    T*y=NULL;
    T buf;
    if(x==NULL) Q=0;
    y=new T[Q+1];
    if(x!=NULL){
        for(int i=1; i<=Q; i++){
            //y[i-1]=x[i-1];
            buf=x[i-1];
            y[i-1]=buf;
        }
    }
    y[Q+1-1]=z;
    delete[]x;
    x=y;
    Q++;
}
template <typename T>void VectorInsElementToN(T*&x, int&Q, int N, T z, TValsShowHide*vsh=NULL/*, int PreserveVals=true*/){
    T*y;
   // int OldN, NewN;
    writeln(vsh,"VectorInsElementToN starts working");
    if(N>=1 && N<=Q){
        writeln(vsh,"N is within range of arrays size");
        y=new T[Q+1];
       // if(PreserveVals){
        for(int i=1; i<=Q+1; i++){
            writeln(vsh," i="+IntToStr(i)+" N="+IntToStr(N)+" Q="+IntToStr(Q));
            if(i<N){
                //oldN=i;
                //newN=i;
                y[i-1]=x[i-1];
                writeln(vsh,IntToStr(i)+" -> "+IntToStr(i));
            } else if(i>N){
                //oldN=i;
                //newN=i-1;
                y[i-1]=x[i-1-1];
                writeln(vsh,IntToStr(i)+" -> "+IntToStr(i-1));
            }else{
                writeln(vsh,IntToStr(i)+" =N! ");
            }
        }
        y[N-1]=z;
        delete[]x;
        x=y;
        Q++;
    }
    writeln(vsh,"VectorInsElementToN finishes working");
}
template <typename T>void VectorDelElementFromN(T*&x, int&Q, int N){
    T*y=new T[Q-1];
    for(int i=1; i<=Q; i++){
        if(i<N)y[i-1]=x[i-1];
        else if(i>N) y[i-1-1]=x[i-1];
    }
    //}
    delete[]x;
    x=y;
    Q--;
}
//
template <typename T>void VectorSwapElements(T*&x, int Q, int N1, int N2){
    T buf;
    if(N1>=1 && N1<=Q && N2>=1 && N2<=Q){
        buf=x[N1-1];
        x[N1-1]=x[N2-1];
        x[N2-1]=buf;
    }
}
template <typename T>void VectorReverse(T*&x, int Q){
    int N, N1, N2;
    if(Q%2==0){
        N=Q/2;
    }else{
        N=(Q-1)/2;
    }
    for(int i=1; i<=N; i++){
        N1=i;
        N2=Q-i+1;
        VectorSwapElements(x, Q, N1, N2);
    }
}
template <typename T> std::vector<T> GetAsStdVector(T*data, int curL, int N1=1, int N2=0, T*DfltVal=NULL){
    T x;
    std::vector<T>arr;
    T dflt;
    if(DfltVal!=NULL){
        dflt=(*(DfltVal));
    }
    if(N2==0){
        N2=curL;
    }
    if(N1>N2){
        N1=N2;
    }
    if(N1<1){
        N1=1;
    }
    int minL=N2<curL?N2:curL;
    for(int i=1; i<=minL; i++){
        x=data[i-1];
        arr.push_back(x);
    }
    for(int i=minL+1; i<=N2; i++){
        arr.push_back(dflt);
    }
    return arr;
}
template <typename T> std::vector<int>Seek(T*data, T val, int curL, bool(*Equals)(const T& x1, const T& x2, int params)=EqualSimple, int FromN=1, int ToN=0){
    std::vector<int> Ns;
    int Q=curL;
    if(Q>0){
        if(ToN<1){
            ToN=Q;
            if(FromN>ToN){
                FromN=ToN;
            }
            if(FromN<1){
                FromN=1;
            }
            for(int i=FromN; i<=ToN; i++){
                 //if(data[i-1]==val){
                 if(Equals(data[i-1],val)){
                    Ns.push_back(i);
                }
            }
        }
    }
    return Ns;
}//fn
template <typename T> bool SuccIsAtPos(T*data, T*succ, int L, int PosN, int succL, bool(*Equals)(const T& x1, const T& x2, int param)=EqualSimple, TValsShowHide*vsh=NULL){
    bool verdict;
    int ChkN;
    writeln(vsh,"SuccIsAtPos starts working");
    writeln(vsh,"Search: in Length: "+IntToStr(L)+" at PosN="+IntToStr(PosN)+" Length to seek: "+IntToStr(succL));
    verdict=(PosN+succL-1<=L); //check if it can contain so long part
    if(verdict) writeln(vsh,"check passed/ It can contain so long part");
    else  writeln(vsh,"check done/ It can NOT contain so long part");
    if(verdict){
        for(int i=1; i<=succL; i++){
            ChkN=PosN+i-1;
            //if(!(succ[i-1]==data[ChkN-1])){
            //if(Equals(succ[i-1], data[ChkN-1], 0)==false){
            //    verdict=false;
            //}
            if(Equals(succ[i-1], data[ChkN-1], 0)==false){
                verdict=false;
            }
        }
    }
    writeln(vsh,"SuccIsAtPos finishes working");
    return verdict;
}
template <typename T> std::vector<int>Seek(T*data, T*succ, int succL, int curL, bool (*Equals)(const T& x1, const T& x2, int params)=EqualSimple, int FromN=1, int ToN=0, TValsShowHide*vsh=NULL){
    std::vector<int> Ns;
    int Q=curL;
    writeln(vsh, "MyLib.Seek(1D in 1D) starts working");
    if(Q>0){
        if(ToN<1){
            ToN=Q;
            if(FromN>ToN){
                FromN=ToN;
            }
            if(FromN<1){
                FromN=1;
            }
            writeln(vsh,"Length to seek in: "+IntToStr(Q)+" Length to seek: "+IntToStr(succL));
            for(int i=FromN; i<=ToN; i++){
                writeln(vsh,"PosNn: "+IntToStr(i)+"checking... ");
                if(SuccIsAtPos(data, succ, curL, i, succL, Equals, vsh)){
                    Ns.push_back(i);
                     writeln(vsh,"Found!");
                }else  writeln(vsh,"NOT found");
            }
        }
    }
    writeln(vsh, "MyLib.Seek(1D in 1D) finishes working");
    return Ns;
}
template <typename T> int SeekFirst(T*data, T val, int curL, bool (*Equals)(const T& x1, const T& x2, int params)=EqualSimple, int FromN=1, int ToN=0){
    int N=0;
    std::vector<int> Ns=Seek(data, val, curL, Equals, FromN, ToN);
    if(Ns.size()>0){
        N=Ns[1-1];
    }
    return N;
}
template <typename T> int SeekLast(T*data, T val, int curL, bool (*Equals)(const T& x1, const T& x2, int params)=EqualSimple, int FromN=1, int ToN=0){
    int N=0;
    std::vector<int> Ns=Seek(data, val, curL, Equals, FromN, ToN);
    int count=Ns.size();
    if(count>0){
        N=Ns[count-1];
    }
    return N;
}
template <typename T> int SeekFirst(T*data, T*succ, int succL, int curL, bool (*Equals)(const T& x1, const T& x2, int params)=EqualSimple, int FromN=1, int ToN=0){
    int N=0;
    std::vector<int> Ns=Seek(data, succ, succL,curL, Equals, FromN, ToN);
    if(Ns.size()>0){
        N=Ns[1-1];
    }
    return N;
}
template <typename T> int SeekLast(T*data, T*succ, int succL, int curL, bool (*Equals)(const T& x1, const T& x2, int params)=EqualSimple, int FromN=1, int ToN=0){
    int N=0;
    std::vector<int>  Ns=Seek(data, succ, succL,curL, Equals,  FromN, ToN);
    int count=Ns.size();
    if(count>0){
        N=Ns[count-1];
    }
    return N;
}

template <typename T> void Print1DArray(T*x, int L, char* delim=" \0"){
    for(int i=1; i<=L; i++){
        std::cout<<x[i-1];
        std::cout<<delim;
    }
    std::cout<<std::endl;
}
template <typename T> void Print2DArray(T**x, int Q, int *Ls, char* delim=" \0"){
    for(int i=1; i<=Q; i++){
        Print1DArray(x[i-1], Ls[i-1], delim);
    }
}

//class TValsShowHide; //forward declaration! //now no need deleted what was between


//

/*
class TValsShowHide{
  public:
    int Show1Hide0;
    bool ConsoleInterface;
 //   QTextBrowser*TxtFld;
    FILE*f;
    //
    TValsShowHide();
    void EnableWriting();
    void DisableWriting();
    void write(char*s);
    void write(QString str);
    void writeln(char*s);
    void writeln(QString str);
};
*/
//


#endif // MYLIB_H
