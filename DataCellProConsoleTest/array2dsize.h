#ifndef ARRAY2DSIZE_H
#define ARRAY2DSIZE_H

#include "mylib.h"
#include"array1dlib.h"

class Int2DVectorOfSizeOrCoords{
public:
    int d1, d2;
    Int2DVectorOfSizeOrCoords(int d1=0, int d2=0);

};

class Array2DPositions{
    std::vector<Int2DVectorOfSizeOrCoords>data;
public:
    Array2DPositions();
    Array2DPositions(std::vector<Int2DVectorOfSizeOrCoords>data);
    int GetQuantity();
    std::vector<Int2DVectorOfSizeOrCoords>Get();
    void clear();
    void Set(std::vector<Int2DVectorOfSizeOrCoords>data);
    void Add(const Int2DVectorOfSizeOrCoords&data);
    void Ins(const Int2DVectorOfSizeOrCoords&data, int N);
    void Add(int ExtRowN, int IneRowN);
    void Ins(int ExtRowN, int IneRowN, int N);
    void Del(int N);
    Int2DVectorOfSizeOrCoords GetElementN(int N);
    void GetN(int N, int&ExtRowN, int&IneRowN);
    void SetN(const Int2DVectorOfSizeOrCoords&data, int N);
    void SetN(int ExtRowN, int IneRowN, int N);
    int GetExtRowN(int N);
    int GetIneRowN(int N);
    void SetExtRowN(int N, int val);
    void SetIneRowN(int N, int val);
};

class Array2DSize
{
    int*Ls;
    int QExtRows, IneRowsLength;
public:
    Array2DSize();
    Array2DSize(const Array2DSize&obj);
    Array2DSize(int QExtRows, int  IneRowsLength, bool isNotVaria=true);
    Array2DSize(int QExtRows, int*Ls);//, int isNotVariaAndSetByMin1Max2=1);
    Array2DSize operator =(const Array2DSize&obj);
    ~Array2DSize();
    void Assign(const Array2DSize&obj);
    void Construct();
    void SetNull();
    void SetOne(bool isVaria=false);
    bool ExtRowNBelongsTo(int extRowN)const;
    bool PosBelongsTo(int extRowN, int ineRowN);
    void Set(int QExtRows, int IneRowsLength, bool preserveType=false);
    void Set(int QExtRows,int*Ls);
    void Set1ExtRowVaria(int L);
    void SetVaria(int QExtRows, int IneRowsLength);
    void ConvertToRectIfAllLengthesAreEqual();
    //void Add(int L, int ifConstAndNotEqual_Ignore0AddExisting1SetAll2=2);
    //void Ins(int N, int L);
    void AddExt(int L=0);
    void InsExt(int N=0, int L=0);
    void DelExt(int N);
    void DelIneRow();
    void AddOrInsIneRow();
    //void AddOrInsTo(int L=0, int N_0ToAllPreserveType_GTT0AndMakeVaria=0);
    //void DelFrom(int L, int N_0ToAllPreserveType_GTT0AndMakeVaria=0);
    void AddOrInsTo(int N, int L);
    void DelFrom(int N, int L);
    int GetQExtRows() const;
    bool GetIfIsVariaLength()const;
    bool isVariaLength();
    bool isRectangular();
    int GetLength(int N=0) const;
    int GetMinLength()const;
    int GetMaxLength()const;
    void SwapExtRows(int N1, int N2);
    void Reverse();
    void SetQExtRows(int N);
    void SetIneRowsLength(int L_Minus1MinMinus2Max=-1, bool preserveTypeIfVaria=false);
    //void SetLength(int L, int N_0ToAllPreserveType_GTT0AndMakeVaria_Minus1ToAllMakeNotVaria=0);
    void SetLength(int L, int N=0);
    QString GetAsQString(QString delim=", ")const;
    std::string GetAsStdString(std::string delim=", ") const;
    void ShowToConsole() const;
    bool isSame(const Array2DSize&obj)const;
    int GetIneRowsLength(bool EvenIfVarButAllEqual=false)const;
    void Transpose();
    bool IsForTranspose() const;
    int LengthFullOfIneRowN(int N) const;//from start to 1st stop
};

template<typename T> Array2DSize GetSizeOf2DVector(std::vector<std::vector<T>>X, bool VarIfAllEqual=false){
    Array2DSize size;
    int Q, L, Lcur;
    int *Ls=NULL;
    bool equal=true;
    Q=X.size();
    if(Q==0){
        L=0;
        size.Set(Q, L);
    }else{
        L=X[1-1].size();
        Ls=new int[Q];
        for(int i=1; i<=Q; i++){
            Lcur=X[i-1].size();
            Ls[i-1]=Lcur;
            //Ls[i-1]=X[i-1].size();
            if(Ls[i-1]!=L) equal=false;
        }
     if(equal && !VarIfAllEqual){
            size.Set(Q, L);
        }else{
            size.Set(Q,Ls);
        }
        delete[]Ls;
    }
    return size;
}
template<typename T> int GetMinLengthOfVector2DExtRows(std::vector<std::vector<T>>X){
    int Q=X.size();
    int L, mn, mx;
    for(int i=1; i<=Q; i++){
        L=X[i-1].size();
        if(i==1 || (i>1 && L<mn)) mn=L;
        if(i==1 || (i>1 && L>mx)) mx=L;
    }
    return mn;
}
template<typename T> int GetMaxLengthOfVector2DExtRows(std::vector<std::vector<T>>X){
    int Q=X.size();
    int L, mn, mx;
    for(int i=1; i<=Q; i++){
        L=X[i-1].size();
        if(i==1 || (i>1 && L<mn)) mn=L;
        if(i==1 || (i>1 && L>mx)) mx=L;
    }
    return mx;
}
template<typename T> int GetLengthFullOfIneRowOfVector2D(std::vector<std::vector<T>>X, int N){
    int Q=X.size(), Lmax=GetMaxLengthOfVector2DExtRows(X), Lmin=GetMinLengthOfVector2DExtRows(X), Lcur, RowL=0;
    if(Q>0){
        for(int i=1; i<=Q; i++){
            Lcur=X[i-1].size();
            if(Lcur<=N){
                RowL++;
            }
        }
    }
    return RowL;
}
template<typename T> bool Vector2DIsForTranspose(std::vector<std::vector<T>>X) {
    int Q=X.size(), Lmax=GetMaxLengthOfVector2DExtRows(X), Lmin=GetMinLengthOfVector2DExtRows(X);
    int L1, L2;
    bool b=true;
    if(Q>0){
        L1=GetLengthFullOfIneRowOfVector2D(X, 1);
        for(int j=2; j<=Lmax; j++){
            L2=GetLengthFullOfIneRowOfVector2D(X, j);
            if(L2>L1){
                b=false;
            }
            L1=L2;
        }
    }
    return b;
}



int CalcElementNIfNegativeOf(int N, int Q);

#endif // ARRAY2DSIZE_H
