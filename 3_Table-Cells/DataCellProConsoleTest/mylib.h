#ifndef MYLIB_H
#define MYLIB_H


#include<iostream>
#include<QString>
#include"math.h"
#include<typeinfo>
//#include"array2dsize.h"//!
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

template<typename T> T GetDefaultVal(T*param=NULL);

QString FloatToStr(float x);
QString FloatToStr(double x);
QString IntToStr(int x);

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

template <typename T> void Print2DArray(T**x, int Q, int *Ls, char* delim=" \0"){
    for(int i=1; i<=Q; i++){
        Print1DArray(x[i-1], Ls[i-1], delim);
    }
}

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

void PrintArray1DInt(int*x, int Q);
void PrintArray1DFloat(int*x, int Q);
void PrintArray1DDouble(int*x, int Q);
void PrintArray1DInt(int**x,int Q, int*Ls);// const Array2DSize&size);

#endif // MYLIB_H
