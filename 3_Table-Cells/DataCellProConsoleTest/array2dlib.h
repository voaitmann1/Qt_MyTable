#ifndef ARRAY2DLIB_H
#define ARRAY2DLIB_H

#include"mylib.h"
#include"array1dlib.h"
#include"array2dsize.h"


template<typename T> void Array2DSetSize(T**&X, const Array2DSize&size1, const Array2DSize&size2, T*DfltValParam=NULL, bool PreserveVals=true){//16
    T**Y=NULL;
    //T DefaultVal=GetDefaultVal(DfltValParam);
    T DefaultVal;
    int Q1=size1.GetQExtRows(), Q2=size2.GetQExtRows(),  minL, L1, L2, minQ=Q1<=Q2?Q1:Q2;
    if(DfltValParam!=NULL){
        DefaultVal=(*(DfltValParam));
    }
    if(size1.isSame(size2)==false){
        //1 set size
        Y=new T*[Q2];
        for(int i=1; i<=Q2; i++){
           L2=size2.GetLength(i);
           Y[i-1]=new T[L2];
        }
        //2 assign, preserving vals
        if(X!=NULL && PreserveVals){
            for(int i=1; i<=minQ; i++){
                L1=size1.GetLength(i);
                L2=size2.GetLength(i);//hin wa size1 et err - acc viol
                minL=L1<=L2?L1:L2;
                for(int j=1; j<=minL; j++){
                    Y[i-1][j-1]=X[i-1][j-1];
                }
                if(minL==L1){
                    for(int j=1; j<=minL; j++){
                        Y[i-1][j-1]=X[i-1][j-1];
                    }
                }else{
                    for(int j=minL+1; j<=L2; j++){
                        Y[i-1][j-1]=DefaultVal;
                    }
                }
            }
            if(minQ==Q1){
                for(int i=minQ+1; i<=Q2; i++){
                    for(int j=1; j<=size2.GetLength(i); j++){
                         Y[i-1][j-1]==X[i-1][j-1];
                    }
                 }
            }else{
                for(int i=minQ+1; i<=Q2; i++){
                     for(int j=1; j<=size2.GetLength(i); j++){
                         Y[i-1][j-1]=DefaultVal;
                    }
                 }
            }
        }else if(DfltValParam!=NULL){
            for(int i=1; i<=Q2; i++){
                L2=size2.GetLength(i);
                for(int j=1; j<=L2; j++){
                    Y[i-1][j-1]=DefaultVal;
                }
            }
        }
        //3 del old
        if(X!=NULL){
            for(int i=1; i<=Q1; i++){
                delete[]X[i-1];
            }
            delete[]X;
        }
        //4 set new
        X=Y;
    }
}
template<typename T> void Array2DSetSize(T**&X, const Array2DSize&size1, int Q, int*Ls, T*DfltValParam=NULL, bool PreserveVals=true){//16
    Array2DSize size2;
    size2.Set(Q, Ls);
    Array2DSetSize(X, size1, size2, DfltValParam, PreserveVals);
}
template<typename T> void Array2DSetSize(T**&X, const Array2DSize&size1, int Q, int IneRowslength, T*DfltValParam=NULL, bool PreserveVals=true){//16
    Array2DSize size2;
    size2.Set(Q, IneRowslength);
    Array2DSetSize(X, size1, size2, DfltValParam, PreserveVals);
}
template<typename T> void Array2DSetSize(std::vector<std::vector<T>>&X, const Array2DSize&size, T*DfltValParam=NULL){//16
    int Q1=X.size(), Q2=size.GetQExtRows(), L1, L2, QMin=Q1<=Q2?Q1:Q2, Lmin;
    T DefaultVal;//=GetDefaultVal(DfltValParam);
    if(DfltValParam!=NULL)DefaultVal=(*(DfltValParam));
    Array2DSize sizeOld=GetSizeOf2DVector(X);
    X.resize(Q2);
    for(int i=1; i<=Q2; i++){
        L2=size.GetLength(i);
        X[i-1].resize(L2);
    }
    if(DfltValParam!=NULL){
        for(int i=1; i<=QMin; i++){
            L1=sizeOld.GetLength(i);
            L2=size.GetLength(i);
            Lmin=L1<=L2?L1:L2;
            for(int j=Lmin+1; j<=L2; j++){
                X[i-1][j-1]=DefaultVal;
            }
        }
        for(int i=QMin+1; i<=Q2; i++){
            L2=size.GetLength(i);
            for(int j=1; j<=L2; j++){
                X[i-1][j-1]=DefaultVal;
            }
        }
    }
}
template<typename T> void Array2DSetSize(std::vector<std::vector<T>>&X, int Q, int*Ls, T*DfltValParam=NULL){//16
     Array2DSize size;
     size.Set(Q, Ls);
     Array2DSetSize(X, size, DfltValParam);
}
template<typename T> void Array2DSetSize(std::vector<std::vector<T>>&X, int Q, int IneRowslength, T*DfltValParam=NULL){//16
     Array2DSize size;
     int QOld=X.size(), LcurOld, LcurNew;
     size.Set(Q, IneRowslength);
     Array2DSetSize(X, size, DfltValParam);
}
/*
template<typename T> void Array2DSetQExt(T**X, Array2DSize&size, int QExt, T*DfltVal=NULL){
    Array2DSize size1=size;
    size1.SetQExtRows(QExt);
    SetSize(X, size, size1, DfltVal);
}//17
template<typename T> void Array2DSetQExt(std::vector<std::vector<T>>&X, int QExt, T*DfltVal=NULL){
    Array2DSize size1=Array2DGetSizeOf2DVector(X), size2=size1;
    size1.SetQExtRows(QExt);
    SetSize(X, size2, DfltVal);
}
template<typename T> void Array2DSetLengthN(T**X, const Array2DSize&size, int L, int N=-1, T*DfltVal=NULL){
    Array2DSize size1=size;
    if(size1.GetIfIsVariaLength()==false){
        size1.SetIneRowsLength(L);
    }else{
        if(N==0){
            size1.SetLength(L, 0);
        }else{
            if(N<0){
                N=size1.GetQExtRows()+N;
            }
            if(size1.ExtRowNBelongsTo(N)){
                size1.SetLength(L, N);
            }
        }
    }
    if(size.isSame(size1)==false){
        SetSize(X, size, size1, DfltVal);
    }
}//19

template<typename T> void Array2DSetLengthN(std::vector<std::vector<T>>&X, int L, int N=-1, T*DfltVal=NULL){//19
    int size=X.size();
    if(N<0) N=size+N;
    if(N>=1&& N<=size){
        X[N-1].resize(L);
    }
}
*/
//Set ext row
template<typename T> void Array2DSetExtRowN(T**&X, const Array2DSize&size, int ExtRowN, int wholeRowL=0, T*rowParam=NULL, T*DefaultValParam=NULL, int FromN=1, int DefaultValuesBefore=0, bool KeepIfRect=false){//, int ifDiff_ByArr0ByNew1Min2Max3=0){
   std::vector<T>rowVect;
   T DfltVal;
   int Lnew, L=0;
   if(DefaultValParam!=NULL){
       DfltVal=(*(DefaultValParam));
   }
   if(size.GetQExtRows()>0 && size.GetIneRowsLength(true)>0){
       if(wholeRowL==0){
           wholeRowL=size.GetIneRowsLength();
       }
   }
   if(wholeRowL>0 && ExtRowN>=1 && ExtRowN<=size.GetQExtRows()){
       if(size.GetIfIsVariaLength()==false && KeepIfRect==true){
           Lnew=size.GetIneRowsLength();
       }else{
           Lnew=wholeRowL+DefaultValuesBefore-(FromN-1);//FromN-1 ob FromN s'inq Lnew
       }
       rowVect = Array1DGetSubArray(rowParam, wholeRowL, Lnew, FromN, DefaultValuesBefore, DfltVal);
       L=size.GetLength(ExtRowN);
       if(X[ExtRowN-1]!=NULL){
           delete[] X[ExtRowN-1];
           X[ExtRowN-1]=NULL;
       }
       //
       //vrn 1
       //for(int i=1; i<=Lnew; i++){
       //    Array1DAddElement(X[ExtRowN-1], L, rowVect[i-1]) ;
       //}
       //vrn 2
       Array1DAssign(X[ExtRowN-1], L, rowVect);
   }
}
template<typename T> void Array2DSetExtRowN(T**&X, const Array2DSize&size, int ExtRowN, std::vector<T>rowParam, T*DefaultValParam=NULL, int FromN=1, int DefaultValuesBefore=0, bool KeepIfRect=false){//, int ifDiff_ByArr0ByNew1Min2Max3=0){
    Array2DSetExtRowN(X, size, ExtRowN, rowParam.size(), rowParam.data(), DefaultValParam, FromN, DefaultValuesBefore, KeepIfRect);

}
template<typename T> void Array2DSetExtRowN(std::vector<std::vector<T>>X, int ExtRowN, std::vector<T>rowParam, T*DefaultValParam=NULL, int FromN=1, int DefaultValuesBefore=0, bool KeepIfRect=false){//, int ifDiff_ByArr0ByNew1Min2Max3=0){
   std::vector<T>rowVect;
   T DfltVal;
   int Lnew, Q=X.size(),  Lmin=GetMinLengthOfVector2DExtRows(X), Lmax=GetMaxLengthOfVector2DExtRows(X);
   if(DefaultValParam!=NULL){
       DfltVal=(*(DefaultValParam));
   }
   int wholeRowL=rowParam.size();
   if(wholeRowL>0 && ExtRowN>=1 && ExtRowN<=Q){
       if(Lmin==Lmax && KeepIfRect==true){
           Lnew=Lmin;
       }else{
           Lnew=wholeRowL+DefaultValuesBefore-(FromN-1);//FromN-1 ob FromN s'inq Lnew
       }
       rowVect = Array1DGetSubArray(rowParam, wholeRowL, Lnew, FromN, DefaultValuesBefore, DfltVal);
       X[ExtRowN-1].clear();
       for(int i=1; i<=Lnew; i++){
           Array1DAddElement(X[ExtRowN-1], rowVect[i-1]) ;
       }
   }
}
/*
//Add ext Row
template<typename T> void Array2DAddExtRow(T**&X, const Array2DSize&size, int wholeRowL=0, T*rowParam=NULL, T*DefaultValParam=NULL, int FromN=1, int DefaultValuesBefore=0, bool KeepIfRect=false){//, int ifDiff_ByArr0ByNew1Min2Max3=0){
    int ExtRowN, Q=size.GetQExtRows();
    std::vector<T>rowToAddOrIns=Array1DGetSubArray(rowParam, wholeRowL, 0, FromN, DefaultValuesBefore, DefaultValParam);
    Array1DAddElement(X, Q, rowToAddOrIns.data());
}
template<typename T> void Array2DAddExtRow(T**&X, const Array2DSize&size, std::vector<T>rowParam, T*DefaultValParam=NULL, int FromN=1, int DefaultValuesBefore=0, bool KeepIfRect=false){
    int ExtRowN, Q=size.GetQExtRows(), wholeRowL=rowParam.size();
    std::vector<T>rowToAddOrIns=Array1DGetSubArray(rowParam, 0, FromN, DefaultValuesBefore, DefaultValParam);
    Array1DAddElement(X, Q, rowToAddOrIns.data());
}
template<typename T> void Array2DAddExtRow(std::vector<std::vector<T>>X, std::vector<T>rowParam, T*DefaultValParam=NULL, int FromN=1, int DefaultValuesBefore=0, bool KeepIfRect=false){//, int ifDiff_ByArr0ByNew1Min2Max3=0){
    int ExtRowN, Q=X.size(), Lcur, Lmin=GetMinLengthOfVector2DExtRows(X), Lmax=GetMaxLengthOfVector2DExtRows(X), wholeRowL=rowParam.size(), Lnew;
    if(Lmin==Lmax && KeepIfRect==true){
        Lnew=Lmin;
    }else{
        Lnew=wholeRowL+DefaultValuesBefore-(FromN-1);//FromN-1 ob FromN s'inq Lnew
    }
    std::vector<T>rowToAddOrIns=Array1DGetSubArray(rowParam,  Lnew, FromN, DefaultValuesBefore, DefaultValParam);
    Array1DAddElement(X, rowToAddOrIns);
}
*/
//AddExtRow
template<typename T>void Array2DAddExtRow(T**&X, Array2DSize&size, T*rowParam, int wholeRowL=0, int whereFromN=1, int whatFromN=1, bool RectNotVar=false, T*DfltValParam=NULL, TValsShowHide*vsh=NULL){//44 //better but not checked
    // writeln(vsh,"Array2DAddExtRow starts working");
    int Qwhere=size.GetQExtRows(), Qnew=Qwhere+1, Q, whereCurN, whatCurN, Lcur, L, Lmin=size.GetMinLength(), Lmax=size.GetMaxLength();
    T*rowToAdd=NULL;
    T buf;
    T DfltVal;
    bool contin;
    if(DfltValParam!=NULL){
        DfltVal=(*(DfltValParam));
    }
    //
    if(Qwhere>0 && size.GetIneRowsLength()>0 && RectNotVar){
        //L=size.GetIfIsVariaLength();
        L=size.GetIneRowsLength();
        if(wholeRowL==0){// && whereFromN==1 && whatFromN==1){
            wholeRowL=L;
        }
    }else{
        L=wholeRowL+whereFromN-whatFromN;
    }
    if(L>0){
        rowToAdd=new T[L];
        for(whereCurN=1; whereCurN<=whereFromN-1; whereCurN++){
            rowToAdd[whereCurN-1]=DfltVal;
        }
        if(rowParam!=NULL){
            contin=true;
            whereCurN=whereFromN-1;//already
            whatCurN=whatFromN-1;
            while(contin){
                whereCurN++;
                whatCurN++;
                rowToAdd[whereCurN-1]=rowParam[whatCurN-1];
                if(whereCurN==L){
                    contin=false;
                }
                if(whatCurN==wholeRowL){
                    contin=false;
                }
            }
            if(whatCurN<L){
                for(int i=whatCurN+1; i<=L; i++){
                    rowToAdd[i-1]=DfltVal;
                }
            }
        }else{
            for(whereCurN=1; whereCurN<=L; whereCurN++){
               rowToAdd[whereCurN-1]=DfltVal;
            }
        }
    }
    //
    Qnew--;
    Array1DAddElement(X, Qnew, rowToAdd);
    //
    if(Qwhere==0){
        if(RectNotVar){
            size.Set(1, L);
        }else{
           size.SetVaria(1, L);
        }
    }else{
        if(RectNotVar){
            size.AddExt();
        }else{
            size.AddExt( L);
        }
    }
}
template<typename T>void Array2DAddExtRow(T**&X, Array2DSize&size, std::vector<T>rowParam, int whereFromN=1, int whatFromN=1, bool RectNotVar=false, T*DfltValParam=NULL, TValsShowHide*vsh=NULL){
    Array2DAddExtRow(X, size, rowParam.data(), rowParam.size(), whereFromN, whatFromN, RectNotVar, DfltValParam, vsh);
}
template<typename T>void Array2DAddExtRow(std::vector<std::vector<T>>X, std::vector<T>rowParam, int whereFromN=1, int whatFromN=1, bool RectNotVar=false, T*DfltValParam=NULL, TValsShowHide*vsh=NULL){//44 //better but not checked
    // writeln(vsh,"Array2DAddExtRow starts working");
    int Qwhere=X.size(), Qnew=Qwhere+1, wholeRowL=rowParam.size(), Q, whereCurN, whatCurN, Lcur, L, Lmin=GetMinLengthOfVector2DExtRows(X), Lmax=GetMaxLengthOfVector2DExtRows(X);
    std::vector<T>rowToAdd;
    T buf;
    T DfltVal;
    bool contin;
    if(DfltValParam!=NULL){
        DfltVal=(*(DfltValParam));
    }
    //
    //if(wholeRowL>0){
    if(Qwhere>0 && Lmin==Lmax && RectNotVar){
        L=Lmin;
    }else{
        L=wholeRowL+whereFromN-whatFromN;
    }
    if(L>0){
        //rowToAdd=new T[L];
        for(whereCurN=1; whereCurN<=whereFromN-1; whereCurN++){
            rowToAdd.push_back(DfltVal);
        }
        if(rowParam.size()>0){
            contin=true;
            whereCurN=whereFromN-1;//already
            whatCurN=whatFromN-1;
            while(contin){
                whereCurN++;
                whatCurN++;
                rowToAdd.push_back(rowParam[whatCurN-1]);
                if(whereCurN==L){
                    contin=false;
                }
                if(whatCurN==wholeRowL){
                    contin=false;
                }
            }
            if(whatCurN<L){
                for(int i=whatCurN+1; i<=L; i++){
                    rowToAdd.push_back(DfltVal);
                }
            }
        }else{
            for(whereCurN=1; whereCurN<=L; whereCurN++){
                rowToAdd.push_back(DfltVal);
            }
        }
    }
    //
    Qnew--;
    Array1DAddElement(X, rowToAdd);
   //}//if possible
}
//DelExtRow
template<typename T>void Array2DDelExtRow(T**&X, Array2DSize&size, int N){//42
    int Q=size.GetQExtRows();
    if(N>=1 && N<=Q){
        Array1DDelElementFromN(X, Q, N);
        size.DelExt(N);
    }
}
template<typename T>void Array2DDelExtRow(std::vector<std::vector<T>>&X, int N){
    if(N>=1 && N<=X.size()){
        Array1DDelElementFromN(X, N);//if cany overload
        //X.erase(x.begin()+N-1);
    }
}
//Ins ext row
template<typename T> void Array2DInsExtRowToN(T**&X, const Array2DSize&size, int ExtRowN, int wholeRowL=0, T*rowParam=NULL, T*DefaultValParam=NULL, int FromN=1, int DefaultValuesBefore=0, bool KeepIfRect=false){//, int ifDiff_ByArr0ByNew1Min2Max3=0){
    int Q=size.GetQExtRows(), Lcur, Lmin=size.GetMinLength(), Lmax=size.GetMaxLength(), Lnew;
    if(size.GetQExtRows()>0 && size.GetIneRowsLength(true)>0){
        if(wholeRowL==0){
            wholeRowL=size.GetIneRowsLength();
        }
    }
    if(Lmin==Lmax && KeepIfRect==true){
        Lnew=Lmin;
    }else{
        Lnew=wholeRowL+DefaultValuesBefore-(FromN-1);//FromN-1 ob FromN s'inq Lnew
    }
    if(ExtRowN>=1 && ExtRowN<=Q){
        std::vector<T>rowToAddOrIns=Array1DGetSubArray_byLs(rowParam, wholeRowL, Lnew, FromN, DefaultValuesBefore, DefaultValParam);
        Array1DInsElementToN(X, Q, ExtRowN, rowToAddOrIns.data());
    }
}
template<typename T> void Array2DInsExtRowToN(T**&X, const Array2DSize&size, int ExtRowN, std::vector<T>rowParam, T*DefaultValParam=NULL, int FromN=1, int DefaultValuesBefore=0, bool KeepIfRect=false){//, int ifDiff_ByArr0ByNew1Min2Max3=0){
    Array2DInsExtRowToN(X, size, ExtRowN, rowParam.size(), rowParam.data(), DefaultValParam, FromN, DefaultValuesBefore, KeepIfRect);
}
template<typename T> void Array2DInsExtRowToN(std::vector<std::vector<T>>X, int ExtRowN, std::vector<T>rowParam, T*DefaultValParam=NULL, int FromN=1, int DefaultValuesBefore=0, bool KeepIfRect=false){//, int ifDiff_ByArr0ByNew1Min2Max3=0){
    int Q=X.size(), Lcur, Lmin=GetMinLengthOfVector2DExtRows(X), Lmax=GetMaxLengthOfVector2DExtRows(X), wholeRowL=rowParam.size(), Lnew;
    if(ExtRowN>=1 && ExtRowN<=Q){
        if(Q>0 && Lmax==Lmin){
            if(wholeRowL==0){
                wholeRowL=Lmin;
            }
        }
        if(Lmin==Lmax && KeepIfRect==true){
            Lnew=Lmin;
        }else{
            Lnew=wholeRowL+DefaultValuesBefore-(FromN-1);//FromN-1 ob FromN s'inq Lnew
        }
        std::vector<T>rowToAddOrIns=Array1DGetSubArray_byLs(rowParam, Lnew, FromN, DefaultValuesBefore, DefaultValParam);
        Array1DInsElementToN(X, ExtRowN, rowToAddOrIns);
    }
}
/*
template<typename T>void Array2DInsExtRow(T**&X, Array2DSize&size, std::vector<T>rowParam, int N, T*DfltValParam=NULL, int whereFromN=1, int whatFromN=1, bool KeepIfRect=false) {
    Array2DInsExtRow(X, size, rowParam.data(), rowParam.size(), N, DfltValParam, whereFromN, whatFromN, KeepIfRect);
}
template<typename T>void Array2DInsExtRow(std::vector<std::vector<T>>X,  std::vector<T>rowParam,  int N, T*DfltValParam=NULL, int whereFromN=1, int whatFromN=1, bool KeepIfRect=false) {  //46
*/
    //IfNGTLmin_Ignore0DoNil1Add2Srtetch3=3 for  add or insm, for set -
//Set ine row
template<typename T> void Array2DSetIneRowN(T**&X, Array2DSize&size, int IneRowN, int wholeRowL=0, T*rowParam=NULL, T*DefaultValParam=NULL, int FromN=1, int DefaultValuesBefore=0, int IfNGTLmin_Ignore0DoNil1Add2Srtetch3=1){//if >min - stretch by separ oper!
    int Q=size.GetQExtRows(), Lnew=Q, Lmin=size.GetMinLength(), Lmax=size.GetMaxLength(), Lcur;
    std::vector<T> rowToAddOrIns=Array1DGetSubArray_byLs(rowParam, wholeRowL, Lnew, FromN, DefaultValuesBefore, DefaultValParam);
    T DfltVal;
    if(DefaultValParam!=NULL){
        DfltVal=(*(DefaultValParam));
    }
    if(IneRowN>=1){
        if(IneRowN<=size.GetMinLength()){//if > min - stretch by separ oper Array2DSetRect!
            for(int i=1; i<=Q; i++){
                X[i-1][IneRowN-1]=rowToAddOrIns[i-1];
            }
        }
        //else{
        //    switch(IfNGTLmin_Ignore0DoNil1Add2Srtetch3==1){
        //        case 1:
        //            for(int i=1; i<=Q; i++){
        //                Lcur=size.GetLength(i);
        //                if(Lcur>=Lmin){
        //                    X[i-1][IneRowN-1]=rowToAddOrIns[i-1];
        //                }//else NOp
        //            }
        //        break;
        //        case 2:
        //            for(int i=1; i<=Q; i++){
        //                Lcur=size.GetLength(i);
        //              if(Lcur>=Lmin){
        //                    X[i-1][IneRowN-1]=rowToAddOrIns[i-1];
        //                }else{
        //                    Array1DAddElement(X[i-1], Lcur, rowToAddOrIns[i-1]);
        //                    size.SetLength(Lcur, i);
        //                }
        //            }
        //        break;
        //        case 3:
        //            for(int i=1; i<=Q; i++){
        //                Lcur=size.GetLength(i);
        //                if(Lcur>=Lmin){
        //                    X[i-1][IneRowN-1]=rowToAddOrIns[i-1];
        //                }else{
        //                    for(int j=Lcur+1; j<=IneRowN-1; j++){
        //                        Array1DAddElement(X[i-1], Lcur, DfltVal);
        //                    }
        //                    Array1DAddElement(X[i-1], Lcur, rowToAddOrIns[i-1]);
        //                    size.SetLength(Lcur, i);
        //                }
        //            }
        //        break;
        //    }//switch
        //}
    }
}
template<typename T> void Array2DSetIneRowN(T**&X, Array2DSize&size, int IneRowN, std::vector<T>rowParam, T*DefaultValExt=NULL, int FromN=1, int DefaultValuesBefore=0, int IfNGTLmin_Ignore0DoNil1Add2Srtetch3=1){//if >min - stretch by separ oper!
    Array2DSetIneRowN(X, size, IneRowN, rowParam.size(), rowParam.data(), DefaultValExt, FromN, DefaultValuesBefore, IfNGTLmin_Ignore0DoNil1Add2Srtetch3);
}
template<typename T> void Array2DSetIneRowN(std::vector<std::vector<T>>&X, std::vector<T>rowParam, int IneRowN, T*DefaultValExt=NULL, int FromN=1, int DefaultValuesBefore=0, int IfNGTLmin_Ignore0DoNil1Add2Srtetch3=1){
    int Q=X.size(), Lmin=GetMinLengthOfVector2DExtRows(X), Lnew=Q;
    std::vector<T> rowToAddOrIns=Array1DGetSubArray(rowParam, Lnew, FromN, DefaultValuesBefore, DefaultValExt);
    if(IneRowN>=1){
        if(IneRowN<=Lmin){//if > min - stretch by separ oper Array2DSetRect!
            for(int i=1; i<=Q; i++){
                X[i-1][IneRowN-1]=rowToAddOrIns[i-1];
            }
        }
        //else{
        //    switch(IfNGTLmin_Ignore0DoNil1Add2Srtetch3==1){
        //        case 1:
        //            for(int i=1; i<=Q; i++){
        //                Lcur=size.GetLength(i);
        //                if(Lcur>=Lmin){
        //                    X[i-1][IneRowN-1]=rowToAddOrIns[i-1];
        //                }//else NOp
        //            }
        //        break;
        //        case 2:
        //            for(int i=1; i<=Q; i++){
        //                Lcur=size.GetLength(i);
        //              if(Lcur>=Lmin){
        //                    X[i-1][IneRowN-1]=rowToAddOrIns[i-1];
        //                }else{
        //                    Array1DAddElement(X[i-1],rowToAddOrIns[i-1]);
        //                    size.SetLength(Lcur, i);
        //                }
        //            }
        //        break;
        //        case 3:
        //            for(int i=1; i<=Q; i++){
        //                Lcur=size.GetLength(i);
        //                if(Lcur>=Lmin){
        //                    X[i-1][IneRowN-1]=rowToAddOrIns[i-1];
        //                }else{
        //                    for(int j=Lcur+1; j<=IneRowN-1; j++){
        //                        Array1DAddElement(X[i-1], rowToAddOrIns[i-1]);
        //                    }
        //                    Array1DAddElement(X[i-1], Lcur, rowToAddOrIns[i-1]);
        //                    size.SetLength(Lcur, i);
        //                }
        //            }
        //        break;
        //    }//switch
        //}
    }
}
//get val
template<typename T> T Array2DGetVal(T**X, const Array2DSize&size, int extRowN, int ineRowN){//40
    T y;
    if(extRowN>=1 && extRowN<=size.GetQExtRows() && ineRowN>=1 && ineRowN<=size.GetLength(extRowN)){
       y=X[extRowN][ineRowN];
    }
    return y;
}
template<typename T> T* Array2DGetVal_AsPtr(T**X, const Array2DSize&size, int extRowN, int ineRowN){//40
    T y;
    if(extRowN>=1 && extRowN<=size.GetQExtRows() && ineRowN>=1 && ineRowN<=size.GetLength(extRowN)){
       y=X[extRowN][ineRowN];
    }
    return y;
}
template<typename T> T Array2DGetVal(std::vector<std::vector<T>>X, int extRowN, int ineRowN){//40
    T y;
    if(extRowN>=1 && extRowN<=X.size() && ineRowN>=1 && ineRowN<=X[extRowN-1].size){
       y=X[extRowN][ineRowN];
    }
    return y;
}
template<typename T> T* Array2DGetVal_AsPtr(std::vector<std::vector<T>>X, int extRowN, int ineRowN){//40
    T*y=NULL;
    if(extRowN>=1 && extRowN<=X.size() && ineRowN>=1 && ineRowN<=X[extRowN-1].size()){
       y=X[extRowN][ineRowN];
    }
    return y;
}
//template<typename T> T* GetVal_AsPtr(std::vector<std::vector<T>>&X, int extRowN, int ineRowN);//40
//Get ext row
template<typename T> std::vector<T> Array2DGetExtRowN_AsVals(T**X, int ExtRowN){//30
    std::vector<T>y;
    int L;
    if(ExtRowN>=1 && ExtRowN<=X.size()){
        L=X[ExtRowN-1].size();
        for(int i=1; i<=L; i++){
            y.push_back(X[ExtRowN-1][i-1]);
        }
    }
    return y;
}
template<typename T> T* Array2DGetExtRowN_AsPtr(T**X, const Array2DSize&size, int ExtRowN){//30
    T*y=NULL;
    if(size.ExtRowNBelongsTo(ExtRowN)){
        y=X[ExtRowN-1];
    }
    return y;
}
template<typename T> std::vector<T> Array2DGetExtRowN(std::vector<std::vector<T>>X, int ExtRowN){//30
    std::vector<T>y;
    if(ExtRowN>=1 && ExtRowN<=X.size()){
        y=X[ExtRowN-1];
    }
    return y;
}
//Get ine row
template<typename T> std::vector<T> Array2DGetIneRowN(T**X, const Array2DSize&size, int IneRowN){//31
    std::vector<T>y;
    int Q=size.GetQExtRows(), Lmin=size.GetMinLength(), Lmax=size.GetMaxLength();
    if(IneRowN>=1 && IneRowN<=Lmin){
        for(int i=1; i<=Q; i++){
            y.push_back(X[i-1][IneRowN-1]);
        }
    }
    return y;
}
template<typename T> std::vector<T> Array2DGetIneRowN(std::vector<std::vector<T>>X, int IneRowN){//31
    std::vector<T>y;
    int Q=X.size(), Lmin=GetMinLengthOfVector2DExtRows(X), Lmax=GetMaxLengthOfVector2DExtRows(X);
    if(IneRowN>=1 && IneRowN<=Lmin){
        for(int i=1; i<=Q; i++){
            y.push_back(X[i-1][IneRowN-1]);
        }
    }
    return y;
}
template<typename T> T* Array2DGetIneRowN_AsPtr(T**X, const Array2DSize&size, int IneRowN){
    std::vector<T>vec=Array2DGetIneRowN(X, size, IneRowN);
    return vec.data();
}
template<typename T> T* Array2DGetIneRowN_AsPtr(std::vector<std::vector<T>>X, int IneRowN){
    std::vector<T>vec=Array2DGetIneRowN(X, IneRowN);
    return vec.data();
}
//swap and reverse rows
template<typename T> void Array2DSwapVals(T**&X, const Array2DSize&size, int Val1ExtRowN, int Val1IneRowN, int Val2ExtRowN, int Val2IneRowN){//34
    T buf;
    buf=X[Val1ExtRowN-1][Val1IneRowN-1];
    X[Val1ExtRowN-1][Val1IneRowN-1]=X[Val2ExtRowN-1][Val2IneRowN-1];
    X[Val2ExtRowN-1][Val2IneRowN-1]=buf;
}
template<typename T> void Array2DSwapVals(std::vector<std::vector<T>>&X, int Val1ExtRowN, int Val1IneRowN, int Val2ExtRowN, int Val2IneRowN){//34
    T buf;
    buf=X[Val1ExtRowN-1][Val1IneRowN-1];
    X[Val1ExtRowN-1][Val1IneRowN-1]=X[Val2ExtRowN-1][Val2IneRowN-1];
    X[Val2ExtRowN-1][Val2IneRowN-1]=buf;
}
template<typename T> void Array2DSwapExtRows(T**X, const Array2DSize&size, int ExtRow1N, int ExtRow2N){//35
    Array1DSwapElements(X, size.GetQExtRows(), ExtRow1N, ExtRow2N);
}
template<typename T> void Array2DSwapExtRows(std::vector<std::vector<T>>&X, const Array2DSize&size, int ExtRow1N, int ExtRow2N){//35
    Array1DSwapElements(X, ExtRow1N, ExtRow2N);
}
template<typename T> void Array2DSwapIneRows(T**X, Array2DSize&size, int IneRow1N, int IneRow2N){//36 //size not const
    int Q=size.GetQExtRows(), Lmin=size.GetMinLength(), Lcur;
    if(IneRow1N>=1 && IneRow2N>=1 && IneRow1N<=Lmin && IneRow2N<=Lmin){
        for(int i=1; i<=Q; i++){
            Lcur=size.GetLength(i);
            Array1DSwapElements(X[i-1], Lcur, IneRow1N, IneRow2N);
        }
        size.SwapExtRows(IneRow1N, IneRow2N);
    }
}
template<typename T> void Array2DSwapIneRows(std::vector<std::vector<T>>&X, int IneRow1N, int IneRow2N){//36
    int Q=X.size(), Lmin=Array2DGetMinLengthOf2DVector(X), Lcur;
    if(IneRow1N>=1 && IneRow2N>=1 && IneRow1N<=Lmin && IneRow2N<=Lmin){
        for(int i=1; i<=Q; i++){
            Lcur=X[i-1].size();
            Array1DSwapElements(X[i-1],  IneRow1N, IneRow2N);
        }
    }
}
template<typename T> void Array2DReverseExtRows(T**X, Array2DSize&size){//37 //size not const
    int Q=size.GetQExtRows();
    Array1DReverse(X, Q);
    size.Reverse();
}
template<typename T> void Array2DReverseExtRows(std::vector<std::vector<T>>&X){//37
    Array1DReverse(X);
}
template<typename T> void Array2DReverseIneRows(T**X, const Array2DSize&size){//38
    int L=size.GetMaxLength(), Q=size.GetQExtRows();
    if(size.GetMinLength()==L){
        for(int i=1; i<=Q; i++){
            Array1DReverse(X[i-1], L);
        }
    }
}
template<typename T> void Array2DReverseIneRows(std::vector<std::vector<T>>&X){//38
    int L=Array2DGetMaxLengthOf2DVector(X), Q=X.size();
    if(Array2DGetMinLengthOf2DVector(X)==L){
        for(int i=1; i<=Q; i++){
            Array1DReverse(X[i-1]);
        }
    }
}
//swap and reverse in rows N
template<typename T> void Array2DReverseExtRowN(T**X, const Array2DSize&size, int N){//39
    int L;
    if(N>=1 && N<=size.GetQExtRows()){
        L=size.GetLength(N) ;
        Array1DReverse(X[N-1]);
    }
}
template<typename T> void Array2DReverseExtRowN(std::vector<std::vector<T>>&X, int N){//39
    if(N>=1 && N<=X.size()){
        Array1DReverse(X[N-1]);
    }
}
template<typename T> void Array2DReverseIneRowN(T**X, const Array2DSize&size, int N){//40
    int L=size.GetMinLength(), Q=size.GetQExtRows();
    T*y=new T[Q];
    if(N>=1 && N<=Q){
        for(int i=1; i<=Q; i++){
            y[i-1]=X[i-1][N-1];
        }
    }
    Array1DReverse(y, Q);
    //void Array2DSetIneRowN(T**X, const Array2DSize&size, int IneRowN, T*row=NULL, int rowL=0, T*DefaultValExt=NULL, int FromN=1)
    Array2DSetIneRowN(X, size, N, y, Q);
    delete[]y;
    y=NULL;
}
template<typename T> void Array2DReverseIneRowN(std::vector<std::vector<T>>&X, int N){//40
    std::vector<T>y;
    int Q=X.size();
    if(N>=1 && N<=Q){
        for(int i=1; i<=Q; i++){
            y.push_back(X[i-1][N-1]);
        }
        Array2DSetIneRowN(X, y, N);
    }
}
//transpose
template<typename T>void Array2DTranspose(T**&X, Array2DSize&size){//
    T**Y=NULL;
    int Q=size.GetQExtRows(), Lmax=size.GetMaxLength(), Lmin=size.GetMinLength(), Lcur;
    //if(X!=NULL && Q>0 && L>0 && size.GetMinLength()==L){
    bool isForTranspose=size.IsForTranspose();
    if(Q>0 && Lmax>0 && Lmin>0 && isForTranspose){
    //LengthFullOfIneRowN(int N){//from start to 1st stop
        Y=new T*[Lmax];
        for(int i=1; i<=Lmax; i++){
            Lcur=size.LengthFullOfIneRowN(i);
            Y[i-1]=new T[Lcur];
        }
        //
        for(int i=1; i<=Lmax; i++){
            Lcur=size.LengthFullOfIneRowN(i);
            for(int j=1; j<=Lcur; j++){
                Y[i-1][j-1]=X[j-1][i-1];
            }
        }
        //
        for(int i=1; i<=Q; i++){
            delete[]X[i-1];
        }
        delete[]X;
        //
        X=Y;
        //
        size.Transpose();
    }
}
template<typename T>void Array2DTranspose(std::vector<std::vector<T>>&X){//rect only
    std::vector<std::vector<T>>Y;
    std::vector<T>Z;
    int Q=X.size(), L=X[1-1].size();
    for(int i=1; i<=L; i++){
        Z.clear();
        for(int j=1; j<=Q; j++){
           Z.push_back(X[j-1][i-1]);
       }
       Y.push_back(Z);
    }
    X=Y;
 }
template<typename T>std::vector<std::vector<T>> Array2DTransposeTo(T**X, const Array2DSize&size){//
    std::vector<std::vector<T>>Y;
    std::vector<T>Z;
    ///if(size.GetMaxLength()==L){
    //    for(int i=1; i<=L; i++){
    //        Z.clear();
    //        for(int j=1; j<=Q; j++){
    //            Z.push_back(X[j-1][i-1]);
    //        }
    //        Y.push_back(Z);
    //    }
    //}
    int Q=size.GetQExtRows(), Lmax=size.GetMaxLength(), Lmin=size.GetMinLength(), Lcur;
    bool isForTranspose=size.IsForTranspose();
    if(Q>0 && Lmax>0 && Lmin>0 && isForTranspose){
        for(int i=1; i<=Lmax; i++){
            Z.clear();
            Lcur=size.LengthFullOfIneRowN(i);
            for(int j=1; j<=Lcur; j++){
               Z.push_back(X[j-1][i-1]);
            }
            Y.push_back(Z);
        }
    }
    return Y;
}
template<typename T>std::vector<std::vector<T>> Array2DTransposeTo(std::vector<std::vector<T>>X){//rect only
    std::vector<std::vector<T>>Y;
    std::vector<T>Z;
    int Q=X.size(), L=X[1-1].size();
    for(int i=1; i<=L; i++){
        Z.clear();
        for(int j=1; j<=Q; j++){
           Z.push_back(X[j-1][i-1]);
       }
       Y.push_back(Z);
    }
    return Y;
}
//transose struct // not tested
template<typename T>std::vector<std::vector<T>> Array2DTransposeStructTo(T**&X, Array2DSize&size){
    std::vector<std::vector<T>>Y;
    std::vector<T> rowCur;
    int Q=size.GetQExtRows, Lmin=size.GetMinLength(), Lmax=size.GetMaxLength(), Lcur, LIneCur, L1=size.GetLength(1);
    if (size.IsForTranspose()){
        for(int i=1; i<=L1; i++){
            LIneCur=size.LengthFullOfIneRowN(i);
            rowCur.clear();
            rowCur=Array2DGetIneRowN(X, i);
            Y.push_back(rowCur);
        }
    }
    return Y;
}
template<typename T>void Array2DTransposeStruct(T**&X, Array2DSize&size){
    T**Y=NULL;
    std::vector<T> rowCur;
    int Q=size.GetQExtRows, Lmin=size.GetMinLength(), Lmax=size.GetMaxLength(), Lcur, LIneCur, L1=size.GetLength(1);
    if (size.IsForTranspose()){
        //create
        Y=new T*[L1];
        for(int i=1; i<=L1; i++){
            LIneCur=size.LengthFullOfIneRowN(i);
            Y[i-1]=new T[LIneCur];
        }
        //copy
        for(int i=1; i<=L1; i++){
            LIneCur=size.LengthFullOfIneRowN(i);
            rowCur.clear();
            rowCur=Array2DGetIneRowN(X, i);
            for(int j=1; j<=LIneCur; j++){
                Y[i-1][j-1]=X[j-1][i-1];
            }
        }
        //del
        for(int i=1; i<=Q; i++){
            delete[]X[i-1];
        }
        delete[]X;
        //assign
        X=Y;
    }
    return Y;
}
template<typename T>std::vector<std::vector<T>> Array2DTransposeStructTo(std::vector<std::vector<T>>X){
    Array2DSize size=GetSizeOf2DVector(X);
    std::vector<std::vector<T>>Y;
    std::vector<T> rowCur;
    int Q=size.GetQExtRows, Lmin=size.GetMinLength(), Lmax=size.GetMaxLength(), Lcur, LIneCur, L1=size.GetLength(1);
    if (size.IsForTranspose()){
        for(int i=1; i<=L1; i++){
            LIneCur=size.LengthFullOfIneRowN(i);
            rowCur.clear();
            rowCur=Array2DGetIneRowN(X, i);
            Y.push_back(rowCur);
        }
    }
    return Y;
}
template<typename T>void Array2DTransposeStructTo(std::vector<std::vector<T>>&X){
    Array2DSize size=GetSizeOf2DVector(X);
    std::vector<std::vector<T>>Y;
    std::vector<T> rowCur;
    int Q=size.GetQExtRows, Lmin=size.GetMinLength(), Lmax=size.GetMaxLength(), Lcur, LIneCur, L1=size.GetLength(1);
    if (size.IsForTranspose()){
        for(int i=1; i<=L1; i++){
            LIneCur=size.LengthFullOfIneRowN(i);
            rowCur.clear();
            rowCur=Array2DGetIneRowN(X, i);
            Y.push_back(rowCur);
        }
    }
    X=Y;
}
//del ine row
template<typename T>void Array2DDelIneRow(T**&X, Array2DSize&size, int N){//43
    int Q=size.GetQExtRows(), Lmin=size.GetMinLength(), lcur;
    if(N<1) N=Lmin+N;//N=CalcElementNIfNegativeOf(int N, int Lmin);
    if(Q>0 && N>=1 && N<=Lmin){
        for(int i=1; i<=Q; i++){
            lcur=size.GetLength(i);
            Array1DDelElementFromN(X[i-1], lcur, N);
        }
        size.DelIneRow();
    }
}
template<typename T>void Array2DDelIneRow(std::vector<std::vector<T>>&X, int N){//43
    int curL, minL=GetMinLengthOfVector2DExtRows(X), maxL=GetMaxLengthOfVector2DExtRows(X), Q=X.size();

    N=CalcElementNIfNegativeOf(N, minL);
    if(N>=1 && N<=minL){
        for(int i=1; i<=Q; i++){
            Array1DDelElementFromN(X[i-1], N);
        }
    }
}
/*
template<typename T>void Array2DAddIneRow(T**&X,  Array2DSize&size, T*Row, int wholeRowL=0, T*DfltValParam=NULL,  bool AddToEachNotStretchToMax=true, int whatFromN=1, int whereFromN=1){//45 //<gut r'nxt,ma qvi'd
    T DefaultVal;
    //=GetDefaultVal(DfltValParam);
    if(DfltValParam!=NULL)DefaultVal=(*(DfltValParam));
    if(wholeRowL==0)wholeRowL=size.GetQExtRows()+whatFromN-whereFromN;
    int Q=size.GetQExtRows(), Lcur, Lmin=size.GetMinLength(), Lmax=size.GetMaxLength(),  n, curWhereN, curWhatN;
    //int LastNToAddWhere1, LastNToAddWhere2, LastNToAddWhat1, LastNToAddWhat2;
    bool contin;
    if((wholeRowL==0 || wholeRowL==Q) && whatFromN==1 && whereFromN==1){//simple
        if(AddToEachNotStretchToMax){
            if( Row!=NULL){
                for(int i=1; i<=Q; i++){
                    Lcur=size.GetLength(i);
                    Array1DAddElement(X[i-1], Lcur, Row[i-1]);
                    //Lcur -> ++;
                    size.SetLength(Lcur, i);
                }
            }else{
                for(int i=1; i<=Q; i++){
                    Lcur=size.GetLength(i);
                    Array1DAddElement(X[i-1], Lcur, DefaultVal);
                    //Lcur -> ++;
                    size.SetLength(Lcur, i);
                }
            }
        }else{
            if(Row!=NULL){
                for(int i=1; i<=Q; i++){
                    Lcur=size.GetLength(i);
                    n=Lcur;
                    for(int j=Lcur+1; j<=Lmax; j++){
                        Array1DAddElement(X[i-1], n, DefaultVal);
                    }
                    Array1DAddElement(X[i-1], n, Row[i-1]);
                    size.SetLength(Lmax+1, i);
                }
            }else{
                for(int i=1; i<=Q; i++){
                    Lcur=size.GetLength(i);
                    n=Lcur;
                    for(int j=Lcur+1; j<=Lmax; j++){
                        Array1DAddElement(X[i-1], n, DefaultVal);
                    }
                    Array1DAddElement(X[i-1], n, DefaultVal);
                    size.SetLength(Lmax+1, i);
                }
            }
        }
    }else{//not simple with Ns
        if(whatFromN<wholeRowL && whereFromN<Q && wholeRowL+whatFromN-whereFromN>0){//if possible
            curWhereN=0;
            if(AddToEachNotStretchToMax){
                for(int i=1; i<=whereFromN-1; i++){
                    Lcur=size.GetLength(i);
                    Array1DAddElement(X[i-1], Lcur, DefaultVal);
                    size.SetLength(Lcur, i);
                }
                curWhatN=whatFromN-1;
                curWhereN=whereFromN-1;
                contin=true;
                if(Row!=NULL){
                    while(contin){
                        curWhatN++;
                        curWhereN++;
                        Lcur=size.GetLength(curWhereN);
                        Array1DAddElement(X[curWhereN-1], Lcur, Row[curWhatN-1]);
                        size.SetLength(Lcur, curWhereN);
                        if(curWhatN==wholeRowL){
                            contin=false;
                        }
                        if(curWhereN==Q){
                            contin=false;
                        }
                    }
                    if(curWhatN==wholeRowL && curWhereN<Q){
                        contin=true;
                        while(contin){
                            curWhatN++;
                            curWhereN++;
                            Lcur=size.GetLength(curWhereN);
                            Array1DAddElement(X[curWhereN-1], Lcur, DefaultVal);
                            size.SetLength(Lcur, curWhereN);
                            if(curWhereN==Q){
                                contin=false;
                            }
                        }
                    }
                }else{
                    for(int i=1; i<=Q; i++){
                        Lcur=size.GetLength(curWhereN);
                        Array1DAddElement(X[curWhereN-1], Lcur, DefaultVal);
                        size.SetLength(Lcur, curWhereN);
                    }
                }
            }else{//AddToEachNotStretchToMax==false
                for(int i=1; i<=whereFromN-1; i++){
                    Lcur=size.GetLength(i);
                    n=Lcur;
                    for(int j=Lcur+1; j<=Lmax; j++){
                        Array1DAddElement(X[i-1], n, DefaultVal);
                    }
                    Array1DAddElement(X[i-1], n, DefaultVal);
                    size.SetLength(Lmax+1, i);
                }
                curWhatN=whatFromN-1;
                curWhereN=whereFromN-1;
                contin=true;
                if(Row!=NULL){
                    while(contin){
                        curWhatN++;
                        curWhereN++;
                        Lcur=size.GetLength(curWhereN);
                        n=Lcur;
                        for(int j=Lcur+1; j<=Lmax; j++){
                            Array1DAddElement(X[curWhereN-1], n, DefaultVal);
                        }
                        Array1DAddElement(X[curWhereN-1], n, Row[curWhatN-1]);
                        size.SetLength(Lmax+1, curWhereN);
                        if(curWhatN==wholeRowL){
                            contin=false;
                        }
                        if(curWhereN==Q){
                            contin=false;
                        }
                    }
                    if(curWhatN==wholeRowL && curWhereN<Q){
                        contin=true;
                        while(contin){
                            curWhatN++;
                            curWhereN++;
                            Lcur=size.GetLength(curWhereN);
                            Array1DAddElement(X[curWhereN-1], Lcur, DefaultVal);
                            size.SetLength(Lcur, curWhereN);
                            if(curWhereN==Q){
                                contin=false;
                            }
                        }
                    }
                }else{
                    for(int i=1; i<=Q; i++){
                        Lcur=size.GetLength(curWhereN);
                        Lcur=size.GetLength(curWhereN);
                        n=Lcur;
                        for(int j=Lcur+1; j<=Lmax; j++){
                            Array1DAddElement(X[i-1], n, DefaultVal);
                        }
                        Array1DAddElement(X[i-1], n, DefaultVal);
                        size.SetLength(Lmax+1, i);
                    }
                }
            }//if AddToEachNotStretchToMax
        }//if possible
    }//if simple or not
}//fn

template<typename T>void Array2DAddIneRow(T**&X,  Array2DSize&size, std::vector<T>RowParam, T*DfltValParam=NULL,  bool AddToEachNotStretchToMax=true, int whatFromN=1, int whereFromN=1){//45 //<gut r'nxt,ma qvi'd
    Array2DAddIneRow(X,  size, RowParam.data(),  RowParam.size(), DfltValParam,  AddToEachNotStretchToMax, whatFromN, whereFromN);
}
template<typename T>void Array2DAddIneRow(T**&X, Array2DSize&size, T*rowParam, int wholeRowL=0, T*DfltValParam=NULL, bool AddToEachEndNotStretchToMax=true, int whereFromN=1, int whatFromN=1, bool RectIfPossible=false) {//>gut r'prv,ma n'qvi'd
    int Qwhere=size.GetQExtRows(), Lcur, Lmin=size.GetMinLength(), Lmax=size.GetMaxLength(), whereCurN, whatCurN, Q;
    T DfltVal;
    T*rowToAdd=NULL;
    bool contin;
    if(DfltValParam!=NULL){
        DfltVal=(*(DfltValParam));
    }
    if(wholeRowL==0){
        wholeRowL=size.GetQExtRows();
    }
    if(Qwhere>0 && wholeRowL>0){
        if(Qwhere>0){
            Q=Qwhere;
        }else{
            Q=wholeRowL;
        }
        rowToAdd=new T[Q];
        //forming RowToAdd
        for(whereCurN=1; whereCurN<=whatFromN-1; whereCurN++){
            rowToAdd[whereCurN-1]=DfltVal;
        }
        if(rowParam!=NULL){
            whatCurN=whatFromN-1;
            whereCurN=whereFromN-1;
            contin=true;
            while(contin){
                whatCurN++;
                whereCurN++;
                rowToAdd[whereCurN-1]=rowParam[whatCurN-1];
                if(whereCurN==Q){
                    contin=false;
                }
                if(whatCurN==wholeRowL){
                    contin=false;
                }
            }
            if(whereCurN<Q){
                for(int i=whereCurN+1; i<=Q; i++){
                    rowToAdd[i-1]=DfltVal;
                }
            }
        }else{
            for(whereCurN=1; whereCurN<=Q; whereCurN++){
                rowToAdd[whereCurN-1]=DfltVal;
            }
        }
        //Adding Formed row, forming size
        if(Qwhere==0){
            X=new T*[Q];
            for(int i=1; i<=Q; i++){
                X[i-1]=new T[1];
            }
            for(int i=1; i<=Q; i++){
                for(int j=1; j<=1; j++){
                    X[i-1][j-1]=rowToAdd[i-1];
                }
            }
            if(RectIfPossible){
                size.Set(Q, 1);
            }else{
                size.SetVaria(Q, 1);
            }
        }else{//Qwhere>0
            if(Lmin!=Lmax){
                if(AddToEachEndNotStretchToMax){
                    //if(RectIfPossible)
                    for(whereCurN=1; whereCurN<=Q; whereCurN++){
                        Lcur=size.GetLength(whereCurN);
                        Array1DAddElement(X[whereCurN-1], Lcur, rowToAdd[whereCurN-1]);
                        //size.SetLength(Lcur, whereCurN);
                    }
                    size.AddOrInsIneRow();
                }else{//AddToEachEndNotStretchToMax=false, stetch to max
                    for(int i=1; i<=Q; i++){
                        Lcur=size.GetLength(i);
                        for(int j=Lcur+1; j<=Lmax; j++){
                            Array1DAddElement(X[i-1], Lcur, DfltVal);
                        }
                        size.SetLength(Lcur, i);
                    }
                    if(!RectIfPossible){
                        for(int i=1; i<=Q; i++){
                            Lcur=size.GetLength(i);
                            Array1DAddElement(X[i-1], Lcur, rowToAdd[i-1]);
                            size.SetLength(Lcur, i);
                        }
                    }else{//RectIfPossible
                        for(int i=1; i<=Q; i++){
                            Lcur=size.GetLength(i);
                            Array1DAddElement(X[i-1], Lcur, rowToAdd[i-1]);
                        }
                        size.SetIneRowsLength(Lcur);
                    }
                }
            }else{//Lmin==Lmax
                for(whereCurN=1; whereCurN<=Q; whereCurN++){
                    Lcur=size.GetLength(whereCurN);
                    Array1DAddElement(X[whereCurN-1], Lcur, rowToAdd[whereCurN-1]);
                }
                size.SetIneRowsLength(size.GetIneRowsLength()+1);
            }
        }
        //
        delete[]rowToAdd;
        //
    }//if possible
}//fn
*/
/*
template<typename T>void Array2DAddIneRow(T**&X, Array2DSize&size, std::vector<T>rowParam, T*DfltValParam=NULL, int whereFromN=1, int whatFromN=1, bool RectIfPossible=false, bool AddToEachNotStretchToMax=true) {
     Array2DAddIneRow(X, size, rowParam.data(), rowParam.size(), DfltValParam, whereFromN, whatFromN, RectIfPossible, AddToEachNotStretchToMax);
}
template<typename T>void Array2DAddIneRow(std::vector<std::vector<T>>X,  std::vector<T>rowParam, T*DfltValParam=NULL, bool AddToEachEndNotStretchToMax=true, int whereFromN=1, int whatFromN=1, bool RectIfPossible=false) {//>gut r'prv,ma n'qvi'd
    int Qwhere=X.size(), Lcur, Lmin=GetMinLengthOfVector2DExtRows(X), Lmax=GetMaxLengthOfVector2DExtRows(X), whereCurN, whatCurN, Q, wholeRowL=rowParam.size();
    T DfltVal;
    std::vector<T>rowOfValsToAdd, rowToAddDirectly;
    bool contin;
    if(DfltValParam!=NULL){
        DfltVal=(*(DfltValParam));
    }
    //if(wholeRowL==0){
    //    wholeRowL=size.GetQExtRows();
    //}
    if(Qwhere>0 && wholeRowL>0){
        if(Qwhere>0){
            Q=Qwhere;
        }else{
            Q=wholeRowL;
        }
        //rowOfValsToAdd=new T[Q];
        //forming RowToAdd
        for(whereCurN=1; whereCurN<=whatFromN-1; whereCurN++){
            rowOfValsToAdd.push_back(DfltVal);
        }
        if(rowParam.size()!=0){
            whatCurN=whatFromN-1;
            whereCurN=whereFromN-1;
            contin=true;
            while(contin){
                whatCurN++;
                whereCurN++;
                rowOfValsToAdd.push_back(rowParam[whatCurN-1]);
                if(whereCurN==Q){
                    contin=false;
                }
                if(whatCurN==wholeRowL){
                    contin=false;
                }
            }
            if(whereCurN<Q){
                for(int i=whereCurN+1; i<=Q; i++){
                    rowOfValsToAdd.push_back(DfltVal);
                }
            }
        }else{
            for(whereCurN=1; whereCurN<=Q; whereCurN++){
                rowOfValsToAdd.push_back(DfltVal);
            }
        }
        //Adding Formed row, forming size
        if(Qwhere==0){
            for(int i=1; i<=Q; i++){
                rowToAddDirectly.clear();
                rowToAddDirectly.push_back(rowOfValsToAdd[i-1]);
                X.push_back(rowToAddDirectly);
            }
        }else{//Qwhere>0
            if(Lmin!=Lmax){
                if(AddToEachEndNotStretchToMax){
                    //if(RectIfPossible)
                    for(whereCurN=1; whereCurN<=Q; whereCurN++){
                        Lcur=X[whereCurN-1].size();
                        Array1DAddElement(X[whereCurN-1], Lcur, rowOfValsToAdd, rowToAddDirectly[whereCurN-1]);
                        //size.SetLength(Lcur, whereCurN);
                    }
                    //size.AddOrInsIneRow();
                }else{//AddToEachEndNotStretchToMax=false, stetch to max
                    for(int i=1; i<=Q; i++){
                        Lcur=X[i-1].size();
                        for(int j=Lcur+1; j<=Lmax; j++){
                            Array1DAddElement(X[i-1], Lcur, DfltVal);
                        }
                        //size.SetLength(Lcur, i);
                    }
                    if(!RectIfPossible){
                        for(int i=1; i<=Q; i++){
                            Lcur=X[i-1].size();
                            Array1DAddElement(X[i-1], Lcur, rowOfValsToAdd, rowToAddDirectly[i-1]);
                            //size.SetLength(Lcur, i);
                        }
                    }else{//RectIfPossible
                        for(int i=1; i<=Q; i++){
                            Lcur=X[i-1].size();
                            Array1DAddElement(X[i-1], Lcur, rowOfValsToAdd, rowToAddDirectly[i-1]);
                        }
                        //size.SetIneRowsLength(Lcur);
                    }
                }
            }else{//Lmin==Lmax
                for(whereCurN=1; whereCurN<=Q; whereCurN++){
                    Lcur=X[whereCurN-1].size();
                    Array1DAddElement(X[whereCurN-1], Lcur, rowOfValsToAdd, rowToAddDirectly[whereCurN-1]);
                }
                //size.SetIneRowsLength(size.GetIneRowsLength()+1);
            }
        }
        //
        //delete[]rowOfValsToAdd, rowToAddDirectly;
        //
    }//if possible
}//fn
*/
//add ine row
template<typename T>void Array2DAddIneRow(T**&X, Array2DSize&size, T*rowParam, int wholeRowL=0, T*DfltValParam=NULL, bool AddToEachNotStretchToMax=true, int whatFromN=1, int whereFromN=1){
    int Q=size.GetQExtRows(), Lmin=size.GetMinLength(), Lmax=size.GetMaxLength(), Lcur, n;
    std::vector<T>rowToAddOrIns;//=Array1DGetSubArray(rowParam, Q, whatFromN, whereFromN, DfltValParam);
    T DfltVal;
    if(DfltValParam!=NULL){
        DfltVal=(*(DfltValParam));
    }
    if(wholeRowL==0 && rowParam!=NULL){
        wholeRowL=Q;
    }
    if(X==NULL && wholeRowL>0){
        X=new T*[wholeRowL];
        for(int i=1; i<=wholeRowL; i++){
            X[i-1]=new T[1];
        }
        for(int i=1; i<=wholeRowL; i++){
            X[i-1][1-1]=rowParam[i-1];
        }
        size.Set(wholeRowL, 1);
    }else{
        //template <typename T>std::vector<T> Array1DGetSubArray_byLs(T*x, int Lold, int Lnew=0, int FromN=1, int FirstDefaultValues=0, T*DfltValParam=NULL)
        rowToAddOrIns=Array1DGetSubArray_byLs(rowParam, wholeRowL, Q, whatFromN, whereFromN, DfltValParam);
        if(AddToEachNotStretchToMax && Lmin!=Lmax){
            for(int i=1; i<=Q; i++){
                Lcur=size.GetLength(i);
                if(Lcur==Lmax || AddToEachNotStretchToMax==false){
                    Array1DAddElement(X[i-1], Lcur, rowParam[i-1]);
                }else{
                    n=Lcur;
                    for(int i=Lcur+1; i<=Lmax; i++){
                        Array1DAddElement(X[i-1], n, rowParam[i-1]);
                    }
                    Lcur=n;
                    Array1DAddElement(X[i-1], Lcur, rowParam[i-1]);
                }
                size.SetLength(i);
            }
        }else{
            if(size.GetIfIsVariaLength()){
                Lcur=size.GetIneRowsLength();
                for(int i=1; i<=Q; i++){
                    Array1DAddElement(X[i-1], Lcur, rowParam[i-1]);
                }
            }else{
                for(int i=1; i<=Q; i++){
                    Lcur=size.GetLength(i);
                    if(Lcur==Lmax || AddToEachNotStretchToMax==false){
                        Array1DAddElement(X[i-1], Lcur, rowParam[i-1]);
                    }else{
                        n=Lcur;
                        for(int j=Lcur+1; j<=Lmax; j++){
                            Array1DAddElement(X[i-1], n, rowParam[i-1]);
                        }
                        Lcur=n;
                        Array1DAddElement(X[i-1], Lcur, rowParam[i-1]);
                    }

                }
                size.AddOrInsIneRow();
            }//if varia struct even if same length
        }//if varia
    }//if add to existing or create
}
template<typename T>void Array2DAddIneRow(T**&X, const Array2DSize&size, std::vector<T>rowParam, T*DfltValParam=NULL, bool AddToEachNotStretchToMax=true, int whatFromN=1, int whereFromN=1){//45
    Array2DAddIneRow(X,  size, rowParam.data(), rowParam.size(), DfltValParam,  AddToEachNotStretchToMax, whatFromN, whereFromN);
}
/*
template<typename T>void Array2DAddIneRow(std::vector<std::vector<T>>&X, std::vector<T>rowParam, bool AddToEachNotStretchToMax=true, T*DfltValParam=NULL, int whatFromN=1, int whereFromN=1){//45
    int Qwhere=X.size(), Qwhat=rowParam.size(), Lmin=GetMinLengthOfVector2DExtRows(X), Lmax=GetMaxLengthOfVector2DExtRows(X), Lcur, Q, whereCurN, whatCurN;
    std::vector<T>rowExt,rowToAdd;
    T DfltVal;
    bool contin;
    //
    Q = Qwhere==0 ? Qwhat-whatFromN+whereFromN : Qwhere;
    if(Q>0){
        if(DfltValParam!=NULL){
            DfltVal=(*(DfltValParam));
        }
        //forming row
        for(whereCurN=1; whereCurN<=whereFromN-1; whereCurN++){
            rowToAdd.push_back(DfltVal);
        }
        contin=((whatCurN+1)<=Qwhat);
        whereCurN=whereFromN-1;//already
        whatCurN=whatFromN-1;
        while(contin){
            whereCurN++;
            whatCurN++;
            rowToAdd.push_back(rowParam[whatCurN-1]);
            if(whatCurN==Qwhat){
                contin=false;
            }
            if(whereCurN==Lmax){
                contin=false;
            }
        }
        for(int i=whereCurN+1; i<=Q; i++){
            rowToAdd.push_back(DfltVal);
        }
        //adding formed row
        if(Qwhere==0){
            rowParam.push_back(rowParam[1-1]);
            X.push_back(rowToAdd[1-1]);
            for(int i=2; i<=Q; i++){
                rowExt[1-1]=rowToAdd[i-1];
                X.push_back(rowExt);
            }
        }else{//Qwhere>0
            if(AddToEachNotStretchToMax || Lmin==Lmax){
                for(int i=1; i<=Qwhere; i++){
                   X[i-1].push_back(rowToAdd[i-1]);
                }
            }else{
                for(int i=1; i<=Qwhere; i++){
                   Lcur=X[i-1].size();
                   for(int j=Lcur+1; j<=Lmax; j++){
                       X[i-1].push_back(DfltVal);
                   }
                   X[i-1].push_back(rowParam[i-1]);
                }
            }
        }
    }
}//fn
*/
template<typename T>void Array2DAddIneRow(std::vector<std::vector<T>>&X, std::vector<T>rowParam, bool AddToEachNotStretchToMax=true, T*DfltValParam=NULL, int whatFromN=1, int whereFromN=1){
    int Q=X.size(), wholeRowL=rowParam.size(), Lmin=GetMinLengthOfVector2DExtRows(X), Lmax=GetMaxLengthOfVector2DExtRows(X), Lcur;
    std::vector<T>rowToAddOrIns;//=Array1DGetSubArray(rowParam, Q, whatFromN, whereFromN, DfltValParam);
    T DfltVal;
    if(DfltValParam!=NULL){
        DfltVal=(*(DfltValParam));
    }
    if(Q==0 && wholeRowL>0){
        for(int i=1; i<=wholeRowL; i++){
            rowToAddOrIns.clear();
            rowToAddOrIns.push_back(rowParam[i-1]);
            X.push_back(rowToAddOrIns);
        }
    }else{
        rowToAddOrIns=Array1DGetSubArray_byLs(rowParam, Q, whatFromN, whereFromN, DfltValParam);
        if(Lmin!=Lmax && AddToEachNotStretchToMax==false){
            for(int i=1; i<=Q; i++){
                Array1DAddElement(X[i-1], rowToAddOrIns[i-1]);
            }
        }else{
            for(int i=1; i<=Q; i++){
                Lcur=X[i-1].size();
                if(Lcur<Lmax){
                    for(int j=Lcur+1; j<=Lmax; j++){
                        Array1DAddElement(X[i-1], DfltVal);
                    }
                }
                Array1DAddElement(X[i-1], rowToAddOrIns[i-1]);
            }
        }
    }
}
//ins ine row
/*
template<typename T>void Array2DInsIneRow(T**&X, Array2DSize&size, T*row, int wholeRowL, int N, T*DfltValParam=NULL, int whereFromN=1, int whatFromN=1) {
    int Q=size.GetQExtRows(), Lcur, Lmin=size.GetMinLength(), Lmax=size.GetMaxLength(), whereCurN, whatCurN;
    T DfltVal;
    T*rowToIns=NULL;
    bool contin;
    if(DfltValParam!=NULL){
        DfltVal=(*(DfltValParam));
    }
    if(N>=1 && N<=Lmin && whatFromN<=wholeRowL && whereFromN>0 && whatFromN>0){
        rowToIns=new T[Q];
        //forming RowToIns
        for(whereCurN=1; whereCurN<=whatFromN; whereCurN++){
            rowToIns[whereCurN-1]=DfltVal;
        }
        if(row!=NULL){
            whatCurN=whatFromN-1;
            whereCurN=whatFromN-1;
            contin=true;
            while(contin){
                whatCurN++;
                whereCurN++;
                rowToIns[whereCurN-1]=row[whatCurN];
                if(whereCurN==Q){
                    contin=false;
                }
                if(whatCurN==wholeRowL){
                    contin=false;
                }
            }
            if(whereCurN<Q){
                for(int i=whereCurN+1; i<=Q; i++){
                    rowToIns[i-1]=DfltVal;
                }
            }
        }else{
            for(whereCurN=1; whereCurN<=Q; whereCurN++){
                rowToIns[whereCurN-1]=DfltVal;
            }
        }
        //inserting Formed row, forming size
        if(Lmin!=Lmax){
            for(whereCurN=1; whereCurN<=Q; whereCurN++){
                Lcur=size.GetLength(whereCurN);
                Array1DInsElementToN(X[whereCurN-1], Lcur, N, rowToIns[whereCurN-1]);
                size.SetLength(Lcur, N);
            }
        }else{
            for(whereCurN=1; whereCurN<=Q; whereCurN++){
                Lcur=size.GetLength(whereCurN);
                Array1DInsElementToN(X[whereCurN-1], Lcur, N, rowToIns[whereCurN-1]);
            }
            size.SetIneRowsLength(size.GetIneRowsLength()+1);
        }
        //
        delete[]rowToIns;
    }//if possible
}

template<typename T>void Array2DInsIneRow(T**&X, Array2DSize&size, int ineRowN, T*rowParam, int wholeRowL=0, T*DfltValParam=NULL, int ifL_LT_N_IgnoreAll0Add1IgnoreExtRow2Stretch3=0, int whatFromN=1, int whereFromN=1){//45
    int Q=size.GetQExtRows(),  Lmin, Lmax, Lcur, n;
    std::vector<T>rowToAddOrIns;//=Array1DGetSubArray(rowParam, Q, whatFromN, whereFromN, DfltValParam);
    T DfltVal;
    if(DfltValParam!=NULL){
        DfltVal=(*(DfltValParam));
    }
    if(wholeRowL==0 && rowParam!=NULL){
        wholeRowL=Q;
    }
    if(X==NULL && wholeRowL>0){
        X=new T*[wholeRowL] ;
        for(int i=1; i<=wholeRowL; i++){
            X[i-1]=new T[1];
        }
        for(int i=1; i<=wholeRowL; i++){
            X[i-1][1-1]=rowParam[i-1];
        }
    }else{
        rowToAddOrIns=Array1DGetSubArray(rowParam, Q, whatFromN, whereFromN, DfltValParam);
        Lmin=size.GetMinLength();
        Lmax=size.GetMaxLength();
        if(ineRowN>=1 && ineRowN<=Lmax && !(Lmin<ineRowN && ifL_LT_N_IgnoreAll0Add1IgnoreExtRow2Stretch3==0)){
            if(!(Lmin<ineRowN && ifL_LT_N_IgnoreAll0Add1IgnoreExtRow2Stretch3==2)){
                for(int i=1; i<=Q; i++){
                    Lcur=size.GetLength(i);
                    if(Lcur>=ineRowN){
                        Array1DInsElementToN(X[i-1], Lcur, ineRowN, rowToAddOrIns[i-1]);
                    }else{
                        if(ifL_LT_N_IgnoreAll0Add1IgnoreExtRow2Stretch3!=2){
                            if(ifL_LT_N_IgnoreAll0Add1IgnoreExtRow2Stretch3==1){
                                Array1DAddElement(X[i-1], Lcur, rowToAddOrIns[i-1]);
                            }else if(ifL_LT_N_IgnoreAll0Add1IgnoreExtRow2Stretch3==3){
                                for(int j=Lcur+1; j<=ineRowN-1; j++){
                                    Array1DAddElement(X[i-1], Lcur, DfltVal);
                                }
                                Array1DAddElement(X[i-1], Lcur, rowToAddOrIns[i-1]);
                            }
                        }
                    }
                }
                size.AddOrInsIneRow();
            }else{
                for(int i=1; i<=Q; i++){
                    Lcur=size.GetLength(i);
                    if(Lcur>=ineRowN){
                        Array1DInsElementToN(X[i-1], Lcur, ineRowN, rowToAddOrIns[i-1]);
                    }else{
                        if(ifL_LT_N_IgnoreAll0Add1IgnoreExtRow2Stretch3!=2){
                            if(ifL_LT_N_IgnoreAll0Add1IgnoreExtRow2Stretch3==1){
                                Array1DAddElement(X[i-1], Lcur, rowToAddOrIns[i-1]);
                            }else if(ifL_LT_N_IgnoreAll0Add1IgnoreExtRow2Stretch3==3){
                                n=Lcur;
                                for(int j=Lcur+1; j<=ineRowN-1; j++){
                                    Array1DAddElement(X[i-1], n, DfltVal);
                                }
                                Lcur=n;
                                Array1DAddElement(X[i-1], Lcur, rowToAddOrIns[i-1]);
                            }
                        }
                    }
                    size.SetLength(Lcur, i);
                }//for
            }//if not 2
        }//if possible
    }//case add from 0 or what
}
template<typename T>void Array2DInsExtRow(T**&X, Array2DSize&size, T*row, int wholeRowL, int N, T*DfltValParam=NULL, int whereFromN=1, int whatFromN=1, bool KeepIfRect=false) {  //46
    T**Y, *rowToIns;
    T DfltVal;
    int Qold=size.GetQExtRows(),Qnew=Qold+1,  Lcur, L, whereCurN, whatCurN;
    bool contin;
    if(DfltValParam!=NULL)DfltVal=(*(DfltValParam));
    if(N>=1 && N<=Qold    &&   whatFromN<=wholeRowL && !( size.GetIneRowsLength()>0 && KeepIfRect==true && whatFromN>=size.GetIneRowsLength() ) ) {
        L=wholeRowL;
        if(whereFromN==1 && whatFromN==1){//simple with Ns
            rowToIns=new T[L];
            if(row!=NULL){
                for(int i=1; i<=L; i++){
                    rowToIns[i-1]=row[i-1];
                }
            }else{
                for(int i=1; i<=L; i++){
                    rowToIns[i-1]=DfltVal;
                }
            }
            //void Array1DInsElementToN(T*&x, int&Q, int N, T z, TValsShowHide*vsh=NULL
            Qnew--;
            Array1DInsElementToN(X, Qnew, N, rowToIns);
            //
            size.InsExt(N, L);
        }else{//not simple
            if(!KeepIfRect){
                L=wholeRowL-whereFromN+whatFromN;//+/-1?
                rowToIns=new T[L];
                for(whereCurN=1; whereCurN<=whereFromN-1; whereCurN++){
                    rowToIns[whereCurN-1]=DfltVal;
                }
                if(row!=NULL){
                    whatCurN=whatFromN-1;
                    contin=true;
                    while(contin){
                        whereCurN++;
                        whatCurN++;
                        rowToIns[whereCurN-1]=row[whatCurN-1];
                        if(whatCurN==wholeRowL){
                            contin=false;
                        }
                    }
                }
                //
                Qnew--;
                Array1DInsElementToN(X, Qnew, N, rowToIns);
                size.InsExt(N, L);
            }else{//Keep if Rect
                L=size.GetIneRowsLength();
                rowToIns=new T[L];
                for(whereCurN=1; whereCurN<=whereFromN-1; whereCurN++){
                    rowToIns[whereCurN-1]=DfltVal;
                }
                whereCurN=whereFromN-1;
                whatCurN=whatFromN-1;
                if(row!=NULL){
                    contin=true;
                    while(contin){
                       whereCurN++;
                       whatCurN++;
                       rowToIns[whereCurN-1]=row[whatCurN-1];
                       if(whatCurN==wholeRowL){
                           contin=false;
                       }
                       if(whereCurN==L){
                           contin=false;
                       }
                    }
                    if(whatCurN<L){
                        for(int i=whatCurN+1; i<=L; i++){
                            whereCurN++;
                            rowToIns[whereCurN-1]=DfltVal;
                       }
                    }
                }else{
                    for(whereCurN=whereFromN; whereCurN<=L; whereCurN++){
                        rowToIns[whereCurN-1]=DfltVal;
                    }
                }
                //
                Qnew--;
                Array1DInsElementToN(X, Qnew, N, rowToIns);
                size.InsExt(N);
                //
                delete[]rowToIns;
            }//if KeepIfRect
        }//if simple
    }//if possible
}
*/

//
template<typename T>void Array2DInsIneRow(T**&X,  Array2DSize&size, int N, T*rowParam, int wholeRowL=0, T*DfltValParam=NULL, int whatFromN=1, int whereFromN=1){//47
    int Q=size.GetQExtRows(), Lmin=size.GetMinLength(), Lmax=size.GetMaxLength(), Lcur;
    std::vector<T>rowToAddOrIns=Array1DGetSubArray_byLs(rowParam, wholeRowL, Q, whatFromN, whereFromN, DfltValParam);
    if(N>=1 && N<=Lmin && Q>0){
        for(int i=1; i<=Q; i++){
            Lcur=size.GetLength(i);
            Array1DInsElementToN(X[i-1], Lcur, N, rowToAddOrIns[i-1]);
        }
        size.AddOrInsIneRow();
    }
}
template<typename T>void Array2DInsIneRow(T**&X,  Array2DSize&size, int N, std::vector<T>rowParam, T*DfltValParam=NULL, int whatFromN=1, int whereFromN=1){
    Array2DInsIneRow(X,  size, N, rowParam.data(), rowParam.size(), DfltValParam, whatFromN, whereFromN);
}
template<typename T>void Array2DInsIneRow(std::vector<std::vector<T>>&X, std::vector<T>rowParam, int N, T*DfltValParam=NULL, int whatFromN=1, int whereFromN=1){//47
    int Q=X.size(), Lmin=GetMinLengthOfVector2DExtRows(X), Lmax=GetMaxLengthOfVector2DExtRows(X), wholeRowL=rowParam.size(), Lcur;
    std::vector<T>rowToAddOrIns=Array1DGetSubArray_byLs(rowParam,  Q, whatFromN, whereFromN, DfltValParam);
    if(N>=1 && N<=Lmin && Q>0){
        for(int i=1; i<=Q; i++){
            Array1DInsElementToN(X[i-1],  N, rowToAddOrIns[i-1]);
        }
    }
}
//
template<typename T>void Array2DDelInExtRowN(T**&X, Array2DSize&size, int rowN, int ElementN){//48
    int Q=size.GetQExtRows(), L=size.GetLength(rowN);
    T DfltVal;
    if(rowN<0)rowN=Q+rowN;
    if(ElementN<0)ElementN=L+ElementN;
    if(rowN>=1 && rowN<=Q && ElementN>=1 && ElementN<=L){
        //if(DfltValParam!=NULL)DfltVal=(*(DfltValParam));
        Array1DDelElementFromN(X[rowN-1], L, ElementN);
        size.SetLength(L, rowN);
    }
}
template<typename T>void Array2DDelInExtRowN(std::vector<std::vector<T>>&X, int rowN, int ElementN){//48
      Array1DDelElementFromN(X[rowN-1], ElementN);
}
//
template<typename T>void Array2DAddToExtRowN(T**&X, Array2DSize&size, int rowN, const T&val, int InsDefaultValsBefore=0, T*DfltValParam=NULL){//49
    int Q=size.GetQExtRows(), L=size.GetLength(rowN);
    T DfltVal;
    //int Q=size.GetQExtRows(), Lmin=size.GetMinLength(), Lmax=size.GetMaxLength(), lcur, whereCurN, whatCurN, iL;
    //T*rowToIns=new T[Q];
    //bool contin;
    if(DfltValParam!=NULL)DfltVal=(*(DfltValParam));
    if(rowN<0)rowN=Q+rowN;
    if(rowN>=1 && rowN<=Q && Q>0){
        for(int i=1; i<=InsDefaultValsBefore; i++){
            Array1DAddElement(X[rowN-1], L, DfltVal);
        }
        Array1DAddElement(X[rowN-1], L, val);
        //
        size.SetLength(L, rowN);
    }
}
template<typename T>void Array2DAddToExtRowN(std::vector<std::vector<T>>&X, int rowN, const T&val, int InsDefaultValsBefore=0, T*DfltValParam=NULL){
    T DfltVal;
    if(rowN>=1 && rowN<=X.size()){
        if(DfltValParam!=NULL)DfltVal=(*(DfltValParam));
        for(int i=1; i<=InsDefaultValsBefore; i++){
            Array1DAddElement(X[rowN-1], DfltVal);
        }
        Array1DAddElement(X[rowN-1], val);
    }
}
template<typename T>void Array2DAddToExtRowN(T**&X, Array2DSize&size, int rowN, T*rowParam, int wholeRowL, int whatFromN=1, int InsDefaultValsBefore=0, T*DfltValParam=NULL){//49
    int Q=size.GetQExtRows(), L=size.GetLength(rowN), whatCurN;;
    T DfltVal, val;
    if(DfltValParam!=NULL)DfltVal=(*(DfltValParam));
    if(rowN>=1 && rowN<=Q && Q>0 && wholeRowL>0){
        for(int i=1; i<=InsDefaultValsBefore; i++){
            Array1DAddElement(X[rowN-1], L, DfltVal);
        }
        whatCurN=whatFromN+1;
        if(rowParam!=NULL){
            for(int i=whatCurN; i<=wholeRowL; i++){
                val=rowParam[i-1];
                Array1DAddElement(X[rowN-1], L, val);
            }
        }else{
            for(int i=whatCurN; i<=wholeRowL; i++){
                Array1DAddElement(X[rowN-1], L, DfltVal);
            }
        }
        //
        size.SetLength(L, rowN);
    }
}
template<typename T>void Array2DAddToExtRowN(T**&X, Array2DSize&size, int rowN, std::vector<T>rowParam, int whatFromN=1, int InsDefaultValsBefore=0, T*DfltValParam=NULL){
    Array2DAddToExtRowN(X, size, rowN, rowParam.data(), rowParam.size(), whatFromN, InsDefaultValsBefore, DfltValParam);
}
template<typename T>void Array2DAddToExtRowN(std::vector<std::vector<T>>X, int rowN, std::vector<T>rowParam, int whatFromN=1, int InsDefaultValsBefore=0, T*DfltValParam=NULL){
    T DfltVal;
    int wholeRowL=rowParam.size();
    if(DfltValParam!=NULL)DfltVal=(*(DfltValParam));
    if(rowN>=1 && rowN<=X.size()){
        for(int i=1; i<=InsDefaultValsBefore; i++){
            Array1DAddElement(X[rowN-1], DfltVal);
        }
        for(int i=whatFromN; i<=wholeRowL; i++){
            Array1DAddElement(X[rowN-1], rowParam[i-1]);
        }
    }
}
//
template<typename T>void Array2DInsToExtRowN(T**&X, Array2DSize&size, const T&val, int rowN, int ElementN){//, T*DfltValParam=NULL){//50
    int Q=size.GetQExtRows(), L=size.GetLength(rowN);
    T DfltVal;
    //if(DfltValParam!=NULL)DfltVal=(*(DfltValParam));
    if(rowN<0) rowN=Q+rowN;
    if(ElementN<0)ElementN=L+ElementN;
    if(rowN>=1 && rowN<=Q && ElementN>=1 && ElementN<=L){
        //if(DfltValParam!=NULL)DfltVal=(*(DfltValParam));
        Array1DInsElementToN(X[rowN-1], L, ElementN, val);
        size.SetLength(L, rowN);
    }
}
template<typename T>void Array2DInsToExtRowN(std::vector<std::vector<T>>&X,const T&val, int rowN, int ElementN){
    if(rowN>=1 && rowN<=X.size()){
        Array1DInsElementToN(X[rowN-1], ElementN, val);
    }
}
//
template<typename T>bool Array2DArr2DIsAtPos(T**where, const Array2DSize&sizeWhere, T**what, const Array2DSize&sizeWhat, int ExtRowN, int IneRowN, bool TransposedAndReversedExtRowsSucc=false, TValsShowHide*vsh=NULL){//57
    bool verdict = true, b;
    int whereCurL, whatCurL, whereQ=sizeWhere.GetQExtRows(), whatQ=sizeWhat.GetQExtRows(), whereExtCurN, whereIneCurN, whatCurExtN,  whatCurIneN, whatL1=sizeWhat.GetLength(1);//whatMinL=sizeWhat.GetMinLength();
    QString msg;
    msg="Array2DArr2DIsAtPos starts working";
   // writeln(vsh, msg.toStdString().c_str());
    writeln(vsh, msg);
    msg="ExtRowN="+IntToStr(ExtRowN)+" IneRowN="+IntToStr(IneRowN);
    writeln(vsh, msg);
    msg="whereQ="+IntToStr(whereQ)+" whatQ="+IntToStr(whatQ)+" whatL1="+IntToStr(whatL1);
    writeln(vsh, msg);
    if(TransposedAndReversedExtRowsSucc==false){
        msg="TransposedAndReversedExtRowsSucc==false";
        writeln(vsh, msg);
        //checking room only
        msg="checking room only";
        writeln(vsh, msg);
        if(whereQ<ExtRowN-1+whatQ){
            verdict=false;
            //
            msg="whereQ<ExtRowN-1+whatQ";
            writeln(vsh, msg);
        }else{
            for(whatCurExtN=1; whatCurExtN<=whatQ; whatCurExtN++){
                //whatCurExtN=i;
                whatCurL=sizeWhat.GetLength(whatCurExtN);
                whereExtCurN=ExtRowN+whatCurExtN-1;
                whereCurL=sizeWhere.GetLength(whereExtCurN);
                //
                msg="whatCurExtN="+IntToStr(whatCurExtN)+" whatCurExtN="+IntToStr(whatCurExtN)+" whereExtCurN="+IntToStr(whereExtCurN);
                writeln(vsh, msg);
                //
                if(whereCurL<IneRowN-1+whatCurL){
                    verdict=false;
                    //
                    msg="whereCurL<IneRowN-1+whatCurL";
                    writeln(vsh, msg);
                }
            }
            //checking concr vals
            msg="Checking concr vals. Here we can compare by whole rows (of what)";
            writeln(vsh, msg);
            if(verdict==true){
                for(whatCurExtN=1; whatCurExtN<=whatQ; whatCurExtN++){
                    //whatCurExtN=i;
                    whatCurL=sizeWhat.GetLength(whatCurExtN);
                    whereExtCurN=ExtRowN+whatCurExtN-1;
                    whereCurL=sizeWhere.GetLength(whereExtCurN);
                    //
                    msg=" whatCurN="+IntToStr(whatCurExtN)+" whereExtCurN="+IntToStr(whereExtCurN);
                    writeln(vsh, msg);
                    //
                    // bool Array1DSuccIsAtPosSimply(T*data, T*succ, int L, int succL, int PosN, int param=0, TValsShowHide*vsh=NULL)
                    b= Array1DSuccIsAtPosSimply(where[whereExtCurN-1], what[whatCurExtN-1], whereCurL, whatCurL, IneRowN);//, int param=0, TValsShowHide*vsh=NULL)
                    if(b==false){
                        verdict=false;
                        //
                        msg="Not equal elements!";
                        writeln(vsh, msg);
                    }
                    if(verdict==false)break;
                }
            }
            if(verdict==true){
                msg="all correspondibg elements are equal. Yesa, the sub-array is situated at this position";
                writeln(vsh, msg);
            }
        }
    }else{
        msg="TransposedAndReversedExtRowsSucc==true - =sub-arr is transposed and reversed";
        writeln(vsh, msg);
        //checking room only
        msg="checking room only";
        writeln(vsh, msg);
        if(whereQ<ExtRowN-1+sizeWhat.GetMaxLength()){
            verdict=false;
            //
            msg="whereQ<ExtRowN-1+sizeWhat.GetMaxLength()";
            writeln(vsh, msg);
        }else{
            msg="where aerray seem to have enough ext rows to contain whast arr at this pos/ Let us see further...";
           writeln(vsh, msg);
        }
        //ext rows length
        if(verdict==true){
            for(whatCurIneN=1; whatCurIneN<=sizeWhat.GetLength(1); whatCurIneN++){
                whereExtCurN=ExtRowN-1+whatCurIneN;
                whereIneCurN=IneRowN-1+1;
                //
                msg="whatCurExtNi= 1, whatCurIneN="+IntToStr(whatCurIneN)+" whatCurIneN="+IntToStr(whatCurIneN)+" whereExtCurN="+IntToStr(whereExtCurN)+" whereIneCurN="+IntToStr(whereIneCurN);
                writeln(vsh, msg);
                //
                if(whereExtCurN>whereQ ){
                    verdict=false;
                    //
                    msg="whereExtCurN>whereQ";
                    writeln(vsh, msg);
                }
                if(whereIneCurN>sizeWhere.GetLength(whereExtCurN) ){
                    verdict=false;
                    //
                    msg="whereIneCurN<sizeWhere.GetLength(whereExtCurN)";
                    writeln(vsh, msg);
                }
            }
            for(int i=2; i<=whatQ; i++){
                for(int j=whatL1; j<=sizeWhat.GetLength(i); j++){
                    whereExtCurN=ExtRowN-1+j;
                    whereIneCurN=IneRowN-1+i;
                    //
                    msg="i="+IntToStr(i)+" whereExtCurN="+IntToStr(whereExtCurN)+" whereIneCurN="+IntToStr(whereIneCurN);
                    writeln(vsh, msg);
                    //
                    if(whereExtCurN<whereQ ){
                        verdict=false;
                        //
                        msg="whereExtCurN<whereQ";
                        writeln(vsh, msg);
                    }
                    if(whereIneCurN<sizeWhere.GetLength(whereExtCurN) ){
                        verdict=false;
                        //
                        msg="whereIneCurN<sizeWhere.GetLength(whereExtCurN)";
                        writeln(vsh, msg);
                    }
                    if(verdict==false){
                        break;
                        //
                        msg="Stopping search among inner rows";
                        writeln(vsh, msg);
                    }
                }
                if(verdict==false){
                    break;
                    //
                    msg="Stopping search among ext rows";
                    writeln(vsh, msg);
                };
             }
             //checking concrete vals
             if(verdict){
                 for(whatCurExtN=1; whatCurExtN<=whatQ; whatCurExtN++){
                     for(whatCurIneN=1; whatCurIneN<=sizeWhat.GetLength(whatCurExtN); whatCurIneN++){
                         whereExtCurN=ExtRowN-1+whatCurIneN;
                         whereIneCurN=IneRowN-1+whatCurExtN;
                         //
                         msg="whatCurExtN="+IntToStr(whatCurExtN)+" whatCurIneN="+IntToStr(whatCurIneN)+" whereExtCurN="+IntToStr(whereExtCurN)+" whereIneCurN="+IntToStr(whereIneCurN);
                         writeln(vsh, msg);
                         //
                         msg="where["+IntToStr(whereExtCurN)+"]["+IntToStr(whereIneCurN)+"]="+IntToStr(where[whereExtCurN-1][whereIneCurN-1]);
                         writeln(vsh, msg);
                         msg="what["+IntToStr(whereExtCurN)+"]["+IntToStr(whereIneCurN)+"]="+IntToStr(what[whatCurExtN-1][whatCurIneN-1]);
                         writeln(vsh, msg);
                         if(where[whereExtCurN-1][whereIneCurN-1]!=what[whatCurExtN-1][whatCurIneN-1]){
                             verdict=false;
                             //
                             msg="where[whereExtCurN-1][whereIneCurN-1]!=what[i-1][j-1]";
                             writeln(vsh, msg);
                         }else{
                             msg="equal";
                             writeln(vsh, msg);
                         }
                     }//for j
                }//for i
            }//if need to check vals-2
        }//if need to check vals-2
    }//if transposed
    return verdict;
}//Array2DArr2DIsAtPos ptr

template<typename T>bool Array2DArr2DIsAtPos(std::vector<std::vector<T>>where,  std::vector<std::vector<T>>what, int ExtRowN, int IneRowN, bool TransposedAndReversedExtRowsSucc=false, TValsShowHide*vsh=NULL){//57
    bool verdict = true, b;
    Array2DSize sizeWhere=GetSizeOf2DVector(where), sizeWhat=GetSizeOf2DVector(what);
    QString msg;
    msg="Array2DArr2DIsAtPos starts working";
    int whereCurL, whatCurL, whereQ=sizeWhere.GetQExtRows(), whatQ=sizeWhat.GetQExtRows(), whereExtCurN, whereIneCurN, whatCurExtN,  whatCurIneN, whatL1=sizeWhat.GetLength(1);//whatMinL=sizeWhat.GetMinLength();
    T curValWhere, curValWhat;
    // writeln(vsh, msg.toStdString().c_str());
    writeln(vsh, msg);
    msg="ExtRowN="+IntToStr(ExtRowN)+" IneRowN="+IntToStr(IneRowN);
    writeln(vsh, msg);
    msg="whereQ="+IntToStr(whereQ)+" whatQ="+IntToStr(whatQ)+" whatL1="+IntToStr(whatL1);
    writeln(vsh, msg);
    if(TransposedAndReversedExtRowsSucc==false){
        msg="TransposedAndReversedExtRowsSucc==false";
        writeln(vsh, msg);
        //checking room only
        msg="checking room only";
        writeln(vsh, msg);
        if(whereQ<ExtRowN-1+whatQ){
            verdict=false;
            //
            msg="whereQ<ExtRowN-1+whatQ";
            writeln(vsh, msg);
        }else{
            for(whatCurExtN=1; whatCurExtN<=whatQ; whatCurExtN++){
                //whatCurExtN=i;
                whatCurL=sizeWhat.GetLength(whatCurExtN);
                whereExtCurN=ExtRowN+whatCurExtN-1;
                whereCurL=sizeWhere.GetLength(whereExtCurN);
                //
                msg="whatCurExtN="+IntToStr(whatCurExtN)+" whatCurExtN="+IntToStr(whatCurExtN)+" whereExtCurN="+IntToStr(whereExtCurN);
                writeln(vsh, msg);
                //
                if(whereCurL<IneRowN-1+whatCurL){
                    verdict=false;
                    //
                    msg="whereCurL<IneRowN-1+whatCurL";
                    writeln(vsh, msg);
                }
            }
            //checking concr vals
            msg="Checking concr vals. Here we can compare by whole rows (of what)";
            writeln(vsh, msg);
            if(verdict==true){
                for(whatCurExtN=1; whatCurExtN<=whatQ; whatCurExtN++){
                    //whatCurExtN=i;
                    whatCurL=sizeWhat.GetLength(whatCurExtN);
                    whereExtCurN=ExtRowN+whatCurExtN-1;
                    whereCurL=sizeWhere.GetLength(whereExtCurN);
                    //
                    msg=" whatCurN="+IntToStr(whatCurExtN)+" whereExtCurN="+IntToStr(whereExtCurN);
                    writeln(vsh, msg);
                    //
                    // bool Array1DSuccIsAtPosSimply(T*data, T*succ, int L, int succL, int PosN, int param=0, TValsShowHide*vsh=NULL)
                    //template <typename T> bool Array1DSuccIsAtPosSimply(std::vector<T>data, std::vector<T>succ, int PosN, int param=0, TValsShowHide*vsh=NULL)
                    b= Array1DSuccIsAtPosSimply(where[whereExtCurN-1], what[whatCurExtN-1], IneRowN);//, int param=0, TValsShowHide*vsh=NULL)
                    if(b==false){
                        verdict=false;
                        //
                        msg="Not equal elements!";
                        writeln(vsh, msg);
                    }
                    if(verdict==false)break;
                }
            }
            if(verdict==true){
                msg="all correspondibg elements are equal. Yesa, the sub-array is situated at this position";
                writeln(vsh, msg);
            }
        }
    }else{
        msg="TransposedAndReversedExtRowsSucc==true - =sub-arr is transposed and reversed";
        writeln(vsh, msg);
        //checking room only
        msg="checking room only";
        writeln(vsh, msg);
        if(whereQ<ExtRowN-1+sizeWhat.GetMaxLength()){
            verdict=false;
            //
            msg="whereQ<ExtRowN-1+sizeWhat.GetMaxLength()";
            writeln(vsh, msg);
        }else{
            msg="where aerray seem to have enough ext rows to contain whast arr at this pos/ Let us see further...";
           writeln(vsh, msg);
        }
        //ext rows length
        if(verdict==true){
            for(whatCurIneN=1; whatCurIneN<=sizeWhat.GetLength(1); whatCurIneN++){
                whereExtCurN=ExtRowN-1+whatCurIneN;
                whereIneCurN=IneRowN-1+1;
                //
                msg="whatCurExtNi= 1, whatCurIneN="+IntToStr(whatCurIneN)+" whatCurIneN="+IntToStr(whatCurIneN)+" whereExtCurN="+IntToStr(whereExtCurN)+" whereIneCurN="+IntToStr(whereIneCurN);
                writeln(vsh, msg);
                //
                if(whereExtCurN>whereQ ){
                    verdict=false;
                    //
                    msg="whereExtCurN>whereQ";
                    writeln(vsh, msg);
                }
                if(whereIneCurN>sizeWhere.GetLength(whereExtCurN) ){
                    verdict=false;
                    //
                    msg="whereIneCurN<sizeWhere.GetLength(whereExtCurN)";
                    writeln(vsh, msg);
                }
            }
            for(int i=2; i<=whatQ; i++){
                for(int j=whatL1; j<=sizeWhat.GetLength(i); j++){
                    whereExtCurN=ExtRowN-1+j;
                    whereIneCurN=IneRowN-1+i;
                    //
                    msg="i="+IntToStr(i)+" whereExtCurN="+IntToStr(whereExtCurN)+" whereIneCurN="+IntToStr(whereIneCurN);
                    writeln(vsh, msg);
                    //
                    if(whereExtCurN<whereQ ){
                        verdict=false;
                        //
                        msg="whereExtCurN<whereQ";
                        writeln(vsh, msg);
                    }
                    if(whereIneCurN<sizeWhere.GetLength(whereExtCurN) ){
                        verdict=false;
                        //
                        msg="whereIneCurN<sizeWhere.GetLength(whereExtCurN)";
                        writeln(vsh, msg);
                    }
                    if(verdict==false){
                        break;
                        //
                        msg="Stopping search among inner rows";
                        writeln(vsh, msg);
                    }
                }
                if(verdict==false){
                    break;
                    //
                    msg="Stopping search among ext rows";
                    writeln(vsh, msg);
                };
             }
             //checking concrete vals
             if(verdict){
                 for(whatCurExtN=1; whatCurExtN<=whatQ; whatCurExtN++){
                     for(whatCurIneN=1; whatCurIneN<=sizeWhat.GetLength(whatCurExtN); whatCurIneN++){
                         whereExtCurN=ExtRowN-1+whatCurIneN;
                         whereIneCurN=IneRowN-1+whatCurExtN;
                         //
                         msg="whatCurExtN="+IntToStr(whatCurExtN)+" whatCurIneN="+IntToStr(whatCurIneN)+" whereExtCurN="+IntToStr(whereExtCurN)+" whereIneCurN="+IntToStr(whereIneCurN);
                         writeln(vsh, msg);
                         //
                         msg="where["+IntToStr(whereExtCurN)+"]["+IntToStr(whereIneCurN)+"]="+IntToStr(where[whereExtCurN-1][whereIneCurN-1]);
                         writeln(vsh, msg);
                         msg="what["+IntToStr(whereExtCurN)+"]["+IntToStr(whereIneCurN)+"]="+IntToStr(what[whatCurExtN-1][whatCurIneN-1]);
                         writeln(vsh, msg);
                         curValWhere=where[whereExtCurN-1][whereIneCurN-1];
                         curValWhat=what[whatCurExtN-1][whatCurIneN-1];
                         //if(where[whereExtCurN-1][whereIneCurN-1]!=what[whatCurExtN-1][whatCurIneN-1]){
                         if(curValWhere!=curValWhat){
                             verdict=false;
                             //
                             msg="where[whereExtCurN-1][whereIneCurN-1]!=what[i-1][j-1]";
                             writeln(vsh, msg);
                         }else{
                             msg="equal";
                             writeln(vsh, msg);
                         }
                     }//for j
                }//for i
            }//if need to check vals-2
        }//if need to check vals-2
    }//if transposed
    return verdict;
}//Array2DArr2DIsAtPos vec


template<typename T>bool Array2DArr1DExtIsAtPos(T**where, const Array2DSize&sizeWhere, T*rowParam, int wholeRowL, int ExtRowN, int IneRowN, bool TransposedAndReversedExtRowsSucc=false, TValsShowHide*vsh=NULL){
    Array2DSize sizeWhat;
    T**what;
    int QWhat, LWhat;
    bool verdict=false;
    if(rowParam!=NULL && wholeRowL>0){
        sizeWhat.Set(1, wholeRowL);
        QWhat=sizeWhat.GetQExtRows();
        LWhat=sizeWhat.GetLength(1);//1
        what=new T*[QWhat];
        for(int i=1; i<=QWhat; i++){
            LWhat=sizeWhat.GetLength(i);
            what[i-1]=new T[LWhat];
        }
        for(int i=1; i<=QWhat; i++){
            LWhat=sizeWhat.GetLength(i);
            for(int j=1; j<=LWhat; j++){
                what[i-1][j-1]=rowParam[j-1];//j!
            }
        }
        verdict=Array2DArr2DIsAtPos(where, sizeWhere, what, sizeWhat, ExtRowN, IneRowN,  TransposedAndReversedExtRowsSucc,vsh);
    }
    return verdict;
}
template<typename T>bool Array2DArr1DExtIsAtPos(T**where, const Array2DSize&sizeWhere, std::vector<T>rowParam, int ExtRowN, int IneRowN, bool TransposedAndReversedExtRowsSucc=false, TValsShowHide*vsh=NULL){
    return Array2DArr1DExtIsAtPos(where, sizeWhere, rowParam.data(), rowParam.size(), ExtRowN,  IneRowN,  TransposedAndReversedExtRowsSucc, vsh);
}

template<typename T>bool Array2DArr1DExtIsAtPos(std::vector<std::vector<T>>where,  std::vector<T>rowParam, int ExtRowN, int IneRowN, bool TransposedAndReversedExtRowsSucc=false, TValsShowHide*vsh=NULL){
    Array2DSize sizeWhat, sizeWhere=GetSizeOf2DVector(where);
    std::vector<std::vector<T>>what;
    std::vector<T>curRow;
    T val;
    int QWhat, LWhat, wholeRowL=rowParam.size();
    bool verdict=false;
    if(rowParam!=NULL && wholeRowL>0){
        sizeWhat.Set(1, wholeRowL);
        QWhat=sizeWhat.GetQExtRows();
        LWhat=sizeWhat.GetLength(1);//1
        //what=new T*[QWhat];
        //for(int i=1; i<=QWhat; i++){
        //    LWhat=sizeWhat.GetLength(i);
        //    what[i-1]=new T[LWhat];
        //}
        for(int i=1; i<=QWhat; i++){
            LWhat=sizeWhat.GetLength(i);
            curRow.clear();
            for(int j=1; j<=LWhat; j++){
                //what[i-1][j-1]=rowParam[j-1];//j!
                val=rowParam[j-1];
                curRow.push_back(val);
            }
            what.push_back(curRow);
        }
        verdict=Array2DArr2DIsAtPos(where,  what,  ExtRowN, IneRowN,  TransposedAndReversedExtRowsSucc,vsh);
    }
    return verdict;
}

template<typename T>bool Array2DArr1DIneIsAtPos(T**where, const Array2DSize&sizeWhere, T*rowParam, int wholeRowL, int ExtRowN, int IneRowN, bool TransposedAndReversedExtRowsSucc=false, TValsShowHide*vsh=NULL){
    Array2DSize sizeWhat;
    T**what;
    int QWhat, LWhat;
    bool verdict=false;
    if(rowParam!=NULL && wholeRowL>0){
        sizeWhat.Set(wholeRowL, 1);
        QWhat=sizeWhat.GetQExtRows();
        LWhat=sizeWhat.GetLength(1);//1
        what=new T*[QWhat];
        for(int i=1; i<=QWhat; i++){
            LWhat=sizeWhat.GetLength(i);
            what[i-1]=new T[LWhat];
        }
        for(int i=1; i<=QWhat; i++){
            LWhat=sizeWhat.GetLength(i);
            for(int j=1; j<=LWhat; j++){
                what[i-1][j-1]=rowParam[i-1];//i!
            }
        }
        verdict=Array2DArr2DIsAtPos(where, sizeWhere,what, sizeWhat, ExtRowN, IneRowN,  TransposedAndReversedExtRowsSucc,vsh);
    }
    return verdict;
}
template<typename T>bool Array2DArr1DIneIsAtPos(T**where, const Array2DSize&sizeWhere, std::vector<T>rowParam, int ExtRowN, int IneRowN, bool TransposedAndReversedExtRowsSucc=false, TValsShowHide*vsh=NULL){
    return Array2DArr1DIneIsAtPos(where, sizeWhere, rowParam.data(), rowParam.size(), ExtRowN, IneRowN, TransposedAndReversedExtRowsSucc, vsh);
}

template<typename T>bool Array2DArr1DIneIsAtPos(std::vector<std::vector<T>>where,  std::vector<T> rowParam, int wholeRowL, int ExtRowN, int IneRowN, bool TransposedAndReversedExtRowsSucc=false, TValsShowHide*vsh=NULL){
    Array2DSize sizeWhat,sizeWhere=GetSizeOf2DVector(where);
    std::vector<std::vector<T>>what;
    std::vector<T>curRow;
     T val;
    int QWhat, LWhat;
    bool verdict=false;
    if(rowParam!=NULL && wholeRowL>0){
        sizeWhat.Set(wholeRowL, 1);
        QWhat=sizeWhat.GetQExtRows();
        LWhat=sizeWhat.GetLength(1);//1
        //what=new T*[QWhat];
        //for(int i=1; i<=QWhat; i++){
        //    LWhat=sizeWhat.GetLength(i);
        //    what[i-1]=new T[LWhat];
        //}
        for(int i=1; i<=QWhat; i++){
            curRow.clear();
            LWhat=sizeWhat.GetLength(i);
            for(int j=1; j<=LWhat; j++){
                //what[i-1][j-1]=rowParam[i-1];//i!
                val=rowParam[i-1];
                curRow.push_back(val);
                //curRow.push_back(rowParam[i-1]);
            }
        }
        verdict=Array2DArr2DIsAtPos(where, what,  ExtRowN, IneRowN,  TransposedAndReversedExtRowsSucc,vsh);
    }
    return verdict;
}


template<typename T>bool Array2DValIsAtPos(T**where, const Array2DSize&sizeWhere, const T&val, int ExtRowN, int IneRowN, bool TransposedAndReversedExtRowsSucc=false, TValsShowHide*vsh=NULL){
    Array2DSize sizeWhat;
    T**what;
    int QWhat, LWhat;
    bool verdict=false;
    //if(rowParam!=NULL && wholeRowL>0){
    sizeWhat.Set(1, 1);
    QWhat=sizeWhat.GetQExtRows();
    LWhat=sizeWhat.GetLength(1);//1
    what=new T*[QWhat];
    for(int i=1; i<=QWhat; i++){
        LWhat=sizeWhat.GetLength(i);
        what[i-1]=new T[LWhat];
    }
    for(int i=1; i<=QWhat; i++){
        LWhat=sizeWhat.GetLength(i);
        for(int j=1; j<=LWhat; j++){
            what[i-1][j-1]=val;//i=1, j=1
        }
    }
    verdict=Array2DArr2DIsAtPos(where, sizeWhere,what, sizeWhat, ExtRowN, IneRowN,  TransposedAndReversedExtRowsSucc,vsh);
    //}
    return verdict;
}

template<typename T>bool Array2DValIsAtPos(std::vector<std::vector<T>>where, const T&val, int ExtRowN, int IneRowN, bool TransposedAndReversedExtRowsSucc=false, TValsShowHide*vsh=NULL){
    Array2DSize sizeWhat, sizeWhere=GetSizeOf2DVector(where);
    std::vector<std::vector<T>>what;
    std::vector<T>row;
    int QWhat, LWhat;
    bool verdict=false;
    //if(rowParam!=NULL && wholeRowL>0){
    sizeWhat.Set(1, 1);
    QWhat=sizeWhat.GetQExtRows();
    LWhat=sizeWhat.GetLength(1);//1
    //what=new T*[QWhat];
    //for(int i=1; i<=QWhat; i++){
    //    LWhat=sizeWhat.GetLength(i);
    //    what[i-1]=new T[LWhat];
    //}
    for(int i=1; i<=QWhat; i++){
        row.clear();
        LWhat=sizeWhat.GetLength(i);
        for(int j=1; j<=LWhat; j++){
            row.push_back(val);
            //what[i-1][j-1]=val;//i=1, j=1
        }
        what.push_back(row);
    }
    verdict=Array2DArr2DIsAtPos(where, what, ExtRowN, IneRowN,  TransposedAndReversedExtRowsSucc,vsh);    //}
    return verdict;
}

template<typename T>std::vector<Int2DVectorOfSizeOrCoords>Array2DSeekSubArr2D(T**where, const Array2DSize&sizeWhere, T**what, const Array2DSize&sizeWhat, bool TransposedAndRFeversedExtRowsSucc=false, TValsShowHide*vsh=NULL){//57
    std::vector<Int2DVectorOfSizeOrCoords> Ns;
    Int2DVectorOfSizeOrCoords pair;
    bool foundAtPos;
    int Q, Lcur, extRowN, ineRowN;
    for(extRowN=1;extRowN<=Q; extRowN++){
        Lcur=sizeWhere.GetLength(extRowN);
        for(ineRowN=1; ineRowN<=Lcur; ineRowN++){
            foundAtPos = Array2DArr2DIsAtPos(where, sizeWhere, what, sizeWhat, extRowN, ineRowN);
            if(foundAtPos){
                pair.d1=extRowN;
                pair.d2=ineRowN;
                Ns.push_back(pair);
            }
        }
    }
    return Ns;
}
template<typename T>std::vector<Int2DVectorOfSizeOrCoords>Array2DSeekSubArr2D(std::vector<std::vector<T>>where, std::vector<std::vector<T>>what, bool TransposedAndRFeversedExtRowsSucc=false, TValsShowHide*vsh=NULL){//57
    std::vector<Int2DVectorOfSizeOrCoords> Ns;
    Int2DVectorOfSizeOrCoords pair;
    Array2DSize sizeWhere=GetSizeOf2DVector(where), sizeWhat=GetSizeOf2DVector(what);
    bool foundAtPos;
    int Q, Lcur, extRowN, ineRowN;
    for(extRowN=1;extRowN<=Q; extRowN++){
        Lcur=sizeWhere.GetLength(extRowN);
        for(ineRowN=1; ineRowN<=Lcur; ineRowN++){
            foundAtPos = Array2DArr2DIsAtPos(where, sizeWhere, what, sizeWhat, extRowN, ineRowN);
            if(foundAtPos){
                pair.d1=extRowN;
                pair.d2=ineRowN;
                Ns.push_back(pair);
            }
        }
    }
    return Ns;
}

template<typename T>Array2DPositions Array2DSeekSubArr2D_v1(T**where, const Array2DSize&sizeWhere, T**what, const Array2DSize&sizeWhat, bool TransposedAndRFeversedExtRowsSucc=false, TValsShowHide*vsh=NULL){//57
    Array2DPositions Ns;
    bool foundAtPos;
    int Q=sizeWhere.GetQExtRows(), Lcur, extRowN, ineRowN, Lmax;
    for(extRowN=1;extRowN<=Q; extRowN++){
        Lcur=sizeWhere.GetLength(extRowN);
        for(ineRowN=1; ineRowN<=Lcur; ineRowN++){
            foundAtPos = Array2DArr2DIsAtPos(where, sizeWhere, what, sizeWhat, extRowN, ineRowN, TransposedAndRFeversedExtRowsSucc, vsh);
            if(foundAtPos){
                Ns.Add(extRowN, ineRowN);
            }
        }
    }
    return Ns;
}
template<typename T>Array2DPositions Array2DSeekSubArr2D_v1(std::vector<std::vector<T>>where, std::vector<std::vector<T>>what, bool TransposedAndRFeversedExtRowsSucc=false, TValsShowHide*vsh=NULL){//57
    Array2DPositions Ns;
    Array2DSize sizeWhere=GetSizeOf2DVector(where), sizeWhat=GetSizeOf2DVector(what);
    bool foundAtPos;
    int Q=sizeWhere.GetQExtRows(), Lcur, extRowN, ineRowN, Lmax;
    for(extRowN=1;extRowN<=Q; extRowN++){
        Lcur=sizeWhere.GetLength(extRowN);
        for(ineRowN=1; ineRowN<=Lcur; ineRowN++){
            foundAtPos = Array2DArr2DIsAtPos(where,  what, extRowN, ineRowN, TransposedAndRFeversedExtRowsSucc, vsh);
            if(foundAtPos){
                Ns.Add(extRowN, ineRowN);
            }
        }
    }
    return Ns;
}

//template<typename T>std::vector<Int2DSizeOrCoords> Array2DSeekSubArr2D(std::vector<std::vector<T>>X, std::vector<std::vector<T>>arr, int ExtRowN, int IneRowN);//57
//
//ins, add, del ext and ine row, simple arrays and vector-based
//ins, add, del to ext row, simple arrays and vector-based
//seek
//copy row to row
//ReturnCloneOrPart
//concat

//template <typename T> void Array2DShowConsole(T**X, const Array2DSize& size, std::string elementsDelim="; "){//works well
//    int Q=size.GetQExtRows(), Lcur, extRowN, ineRowN, Lmin, Lmax;
//    for(int i=1; i<=Q; i++){
//        Lcur=size.GetLength(i);
//        //for(int j=1; j<=Lcur; j++){
//        //    std::cout<<X[i-1][j-1];
//        //    std::cout<<elementsDelim;
//        //}
//        for(int j=1; j<=Lcur-1; j++){
//            std::cout<<X[i-1][j-1];
//            std::cout<<elementsDelim;
//        }
//        std::cout<<X[i-1][Lcur-1];
//        std::cout<<std::endl;
//    }
//    std::cout<<std::endl;
//}
//Array2DShowFragmentToConsole
template <typename T> void Array2DShowConsole(T**X, const Array2DSize& size, std::string elementsDelim="; ", Array2DSize*FragmentSize=NULL, int extRowN=1, int ineRowN=1, bool transposed=false){
    Array2DSize size2;
    std::cout<<"Size Where: "<<size.GetAsQString().toStdString()<<std::endl;
    if(FragmentSize!=NULL){
        size2.Assign(*(FragmentSize));
        std::cout<<"Size What: "<<size2.GetAsQString().toStdString()<<std::endl;
    }else{
        size2.Assign(size);
    }
    int Lcur1, Lcur2, extRowN1, ineRowN1, extRowN2, ineRowN2, Q1=size.GetQExtRows(), Q2=size2.GetQExtRows();
    if(!transposed){
        for(extRowN2=1; extRowN2<=Q2;extRowN2++){
            Lcur2=size2.GetLength(extRowN2);
            extRowN1=extRowN+extRowN2-1;
            //std::cout<<"Row where: ExtRowN1="<<extRowN1<<" IneRowN1="<<ineRowN1<<". Row what: ExtRowN2="<<extRowN2<<" IneRowN2="<<ineRowN2<<std::endl;
            if(extRowN1<=Q1){
                Lcur1=size.GetLength(extRowN1);
                for(ineRowN2=1; ineRowN2<=Lcur2; ineRowN2++){
                    ineRowN1=ineRowN+ineRowN2-1;
                    if(ineRowN1<=Lcur1){
                        //std::cout<<"val(what)["<<extRowN1<<"]["<<ineRowN1<<"]="<<X[extRowN1-1][ineRowN1-1]<<std::endl;
                        //std::cout<<"val(what)["<<extRowN1<<"]["<<ineRowN1<<"]="<<X[extRowN1-1][ineRowN1-1];//<<std::endl;
                        std::cout<<X[extRowN1-1][ineRowN1-1];//<<std::endl;
                        std::cout<<elementsDelim;
                    }else{
                       std::cout<<std::endl<<"val(where)["<<extRowN1<<"]["<<ineRowN1<<"]: No such Element in Where Row"<<std::endl;
                    }
                }
            }else{
                std::cout<<"No such ext row in Where Row: "<<extRowN1<<std::endl;
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
    }else{
        for(extRowN2=1; extRowN2<=Q2; extRowN2++){
            Lcur2=size2.GetLength(extRowN2);
            for(ineRowN2=1; ineRowN2<=Lcur2; ineRowN2++){
                extRowN1=extRowN+ineRowN2-1;
                if(extRowN1<=Q1){
                    Lcur1= size.GetLength(extRowN1);
                    ineRowN1=ineRowN+extRowN2-1;
                    std::cout<<" extRowN1="<<extRowN1<<" ineRowN1="<<ineRowN1<<" extRowN2="<<extRowN2<<" ineRowN2="<<ineRowN2<<std::endl;
                    if(ineRowN1<=Lcur1 && extRowN1<=Q1){
                        std::cout<<"val["<<extRowN1<<"]["<<ineRowN1<<"]="<<X[extRowN1-1][ineRowN1-1]<<std::endl;
                    }else{
                        std::cout<<std::endl<<"val(where)["<<extRowN1<<"]["<<ineRowN1<<"]: No such Element in Where Row"<<std::endl;
                    }
                }else{
                   std::cout<<"No such ext row in Where Row: "<<extRowN1<<std::endl;
                }
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
    }
}

template <typename T> void Array2DShowConsole(std::vector<std::vector<T>>X, std::string elementsDelim="; ", Array2DSize*FragmentSize=NULL, int extRowN=1, int ineRowN=1, bool transposed=false){
    Array2DSize size, size2;
    size=GetSizeOf2DVector(X);
    std::cout<<"Size Where: "<<size.GetAsQString().toStdString()<<std::endl;
    if(FragmentSize!=NULL){
        size2.Assign(*(FragmentSize));
        std::cout<<"Size What: "<<size2.GetAsQString().toStdString()<<std::endl;
    }else{
        size2.Assign(size);
    }
    int Lcur1, Lcur2, extRowN1, ineRowN1, extRowN2, ineRowN2, Q1=size.GetQExtRows(), Q2=size2.GetQExtRows();
    if(!transposed){
        for(extRowN2=1; extRowN2<=Q2;extRowN2++){
            Lcur2=size2.GetLength(extRowN2);
            extRowN1=extRowN+extRowN2-1;
            //std::cout<<"Row where: ExtRowN1="<<extRowN1<<" IneRowN1="<<ineRowN1<<". Row what: ExtRowN2="<<extRowN2<<" IneRowN2="<<ineRowN2<<std::endl;
            if(extRowN1<=Q1){
                Lcur1=X[extRowN1-1].size();
                for(ineRowN2=1; ineRowN2<=Lcur2; ineRowN2++){
                    ineRowN1=ineRowN+ineRowN2-1;
                    if(ineRowN1<=Lcur1){
                        //std::cout<<"val(what)["<<extRowN1<<"]["<<ineRowN1<<"]="<<X[extRowN1-1][ineRowN1-1]<<std::endl;
                        //std::cout<<"val(what)["<<extRowN1<<"]["<<ineRowN1<<"]="<<X[extRowN1-1][ineRowN1-1];//<<std::endl;
                        std::cout<<X[extRowN1-1][ineRowN1-1];//<<std::endl;
                        std::cout<<elementsDelim;
                    }else{
                       std::cout<<std::endl<<"val(where)["<<extRowN1<<"]["<<ineRowN1<<"]: No such Element in Where Row"<<std::endl;
                    }
                }
            }else{
                std::cout<<"No such ext row in Where Row: "<<extRowN1<<std::endl;
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
    }else{
        for(extRowN2=1; extRowN2<=Q2; extRowN2++){
            Lcur2=size2.GetLength(extRowN2);
            for(ineRowN2=1; ineRowN2<=Lcur2; ineRowN2++){
                extRowN1=extRowN+ineRowN2-1;
                if(extRowN1<=Q1){
                    Lcur1= size.GetLength(extRowN1);
                    ineRowN1=ineRowN+extRowN2-1;
                    std::cout<<" extRowN1="<<extRowN1<<" ineRowN1="<<ineRowN1<<" extRowN2="<<extRowN2<<" ineRowN2="<<ineRowN2<<std::endl;
                    if(ineRowN1<=Lcur1 && extRowN1<=Q1){
                        std::cout<<"val["<<extRowN1<<"]["<<ineRowN1<<"]="<<X[extRowN1-1][ineRowN1-1]<<std::endl;
                    }else{
                        std::cout<<std::endl<<"val(where)["<<extRowN1<<"]["<<ineRowN1<<"]: No such Element in Where Row"<<std::endl;
                    }
                }else{
                   std::cout<<"No such ext row in Where Row: "<<extRowN1<<std::endl;
                }
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
    }
}


#endif // ARRAY2DLIB_H



