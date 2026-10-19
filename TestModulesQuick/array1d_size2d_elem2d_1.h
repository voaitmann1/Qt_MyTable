#ifndef ARRAY1D_SIZE2D_ELEM2D_1_H
#define ARRAY1D_SIZE2D_ELEM2D_1_H

#include"mylib.h"
//#include "array1d_size2d_elem2d_1.h"

//class array1d_size2D_elem2D_1
//{
//public:
//    array1d_size2D_elem2D_1();
//};

// === Arr1D Info ==================================================



class Coords2DInt{
public:
    int x, y;
    Coords2DInt(int x=0, int y=0);
    void set(int x, int y);
    int GetSize() const;
    int GetX1() const;
    int GetX2() const;
    int GetX3() const;
    int GetX() const;
    int GetY() const;
    int GetZ() const;
    void SetX1(int val);
    void SetX2(int val);
    void SetX3(int val);
    void SetX(int val);
    void SetY(int val);
    void SetZ(int val);
    bool IsNull();
    //Coords2DInt& operator = (const Coords2DInt& obj);// n'nod ob no dyn objs
};//Coords2DInt



class TDataShiftResults{
public:
    int PreN1, PreN2, PostN1, PostN2, OwnN1, OwnN2, ForOwnN1, ForOwnN2, Lcalc;
    TDataShiftResults();
    //void SetByCalc();
    QString ToString();
};

class TDataShiftParams{
public:
    int QDefaultsBefore, FirstN, Lreq;
    TDataShiftParams(int FirstN=1, int QDefaultsBefore=0, int Lreq=0);
    //TDataShiftResults Calc0(int Lown, int vsh=0);
    TDataShiftResults Calc(int Lown, int vsh=0);
    //void TDataShiftParams::Set(int FirstN, int QDefaultsBefore, int Lreq)
    void Set(int FirstN=1, int QDefaultsBefore=0, int Lreq=0);
    //void SetDefault();
    QString ToString();
    int ArrayElementNToSubArrayElementN(int N, int Lown);
    int SubArrayElementNToArrayElementN(int N, int Lown);
};



int NInArrIfNegative(int N, int Q);

int Arr1DSubArrElementPosN(int whereQ, int whatQ, int whatN, int PosN, bool IsReversed=false);

//=== wa Arr1D info, wi: Arr1D fns ==========================================

template<typename T> void Arr1D_ShowToConsole(T*&x, int Q, std::string delim="; ", bool as2DNot1D=true, bool ShowBrackets=false){
    if(ShowBrackets){
        std::cout<<"[";
    }
    if(as2DNot1D){
        if(ShowBrackets){
            std::cout<<x[1-1];
            //cout<<delim;
            std::cout<<std::endl;
            for(int N=2; N<=Q-1; N++){
                std::cout<<" ";
                std::cout<<x[N-1];
                //cout<<delim;
                std::cout<<std::endl;
           }
        }else{
            for(int N=1; N<=Q-1; N++){
                //std::cout<<" ";
                std::cout<<x[N-1];
                //cout<<delim;
                std::cout<<std::endl;
            }
        }
    }else{
        for(int N=1; N<=Q-1; N++){
            std::cout<<x[N-1];
            std::cout<<delim;
        }
    }
    if(ShowBrackets){
        std::cout<<" ";
    }
    std::cout<<x[Q-1];
    if(ShowBrackets){
        std::cout<<"]";
    }
}
//
template<typename T> void Arr1D_SetVal_OrFill(T*&x, int Q, const T&val, int N_AllIf0){
    if(Q==0){
        if(x!=NULL){
            delete[]x;
        }
        if(N_AllIf0>0){
            x=new T[N_AllIf0];
            for(int i=1; i<=N_AllIf0; i++){
                x[i-1]=val;
            }
        }
    }else if(N_AllIf0<=Q){
        if(N_AllIf0==0){
            for(int i=1; i<=Q; i++){
                x[i-1]=val;
            }
        }else{
            //N_AllIf0=NInArrIfNegative(N_AllIf0, Q);
            if(N_AllIf0<0){
                N_AllIf0+=(Q+1);
            }
            if(N_AllIf0!=0){
                x[N_AllIf0-1]=val;
            }
        }
    }
}
template<typename T> void Arr1D_SetVal_OrFill(std::vector<T>&x, const T&val, int N_AllIf0){
    int Q=x.size();
    if(Q==0){
        if(N_AllIf0>0){
            for(int i=1; i<=N_AllIf0; i++){
                x.push_back(val);
            }
        }
    }else{
        if(N_AllIf0==0){
            for(int i=1; i<=Q; i++){
                x[i-1]=val;
            }
        }else if(N_AllIf0>0){
            N_AllIf0=NInArrIfNegative(N_AllIf0, Q);
            if(N_AllIf0!=0){
                x[N_AllIf0-1]=val;
            }
        }
    }
}
//
template<typename T> void Arr1D_SetSize(T*&x, int Q1, int Q2, T DefaultVal, int vsh=0){
    T*Y=NULL;
    int N, Qmin=Q1<=Q2 ? Q1 : Q2;
    if(vsh==1){
        std::cout<<"Arr1D_SetSize sterts working Q1="<<Q1<<" Q2= "<<Q2<<std::endl;
    }
    if(Q1>0 && Q2>0 && Q1!=Q2){
        Y=new T[Q2];
        if(x!=NULL){
            if(vsh==1){
                std::cout<<"Copying x"<<std::endl;
            }
            for(N=1; N<=Qmin; N++){
                Y[N-1]=x[N-1];
                if(vsh==1){
                    std::cout<<"Y["<<N<<"]="<<Y[N-1]<<std::endl;
                }
            }
            //
            delete[]x;
            x=NULL;
        }else{
            if(vsh==1){
                std::cout<<"x=NULL, No x data to copy"<<std::endl;
            }
            for(N=1; N<=Qmin; N++){
                Y[N-1]=DefaultVal;
                if(vsh==1){
                    std::cout<<"Y["<<N<<"]="<<Y[N-1]<<std::endl;
                }
            }
        }
        if(vsh==1){
            std::cout<<"Now rest"<<std::endl;
        }
        for(N=Qmin+1; N<=Q2; N++){//if Qmin==Q2, ce n'arb
            Y[N-1]=DefaultVal;
            if(vsh==1){
                std::cout<<"Y["<<N<<"]="<<Y[N-1]<<std::endl;
            }
        }
        //
        x=Y;
        //
    }else{
        if(vsh==1){
            std::cout<<"No need to change structure: Q1=Q2 or =0"<<std::endl;
        }
    }
    if(vsh==1){
        std::cout<<"Arr1D_SetSize finishes working Q1="<<Q1<<" Q2= "<<Q2<<std::endl;
    }
}
template<typename T> void Arr1D_SetSize(std::vector<T>&x, int Q2, T DefaultVal){
    int Q1=size(x);
    if(Q1>Q2){
        for(int i=Q2; i<=Q1; i++){
            x.pop_back();
        }
    }else if(Q2>Q1){
        for(int i=Q1; i<=Q2; i++){
            x.push_back(DefaultVal);
        }
    }
}

template<typename T> void Arr1D_SetSize(T*&x, int Q1, int Q2, T*dfltVal=NULL){
    T DefaultVal;
    if(dfltVal!=NULL){
        DefaultVal=(*(dfltVal));
    }
    Arr1D_SetSize(x, Q1, Q2, DefaultVal);
}
template<typename T> void Arr1D_SetSize(std::vector<T>&x, int Q2, T*dfltVal=NULL){
    T DefaultVal;
    int Q1=x.size();
    if(dfltVal!=NULL){
        DefaultVal=(*(dfltVal));
    }
    Arr1D_SetSize(x, Q2, DefaultVal);
}
template<typename T> void Arr1D_Resize(T*&x, int& Q, int dQ, T DefaultVal){
    int Q2=Q+dQ;
    Arr1D_SetSize(x, Q, Q2, DefaultVal);
    Q=Q2;
}
template<typename T> void Arr1D_Resize(std::vector<T>&x, int dQ, T DefaultVal){
    int Q=x.size();
    int Q2=Q+dQ;
    Arr1D_SetSize(x, Q2, DefaultVal);
}
template<typename T> void Arr1D_Resize(T*&x, int& Q, int dQ, T*dfltVal=NULL){
    int Q2=Q+dQ;
    T DefaultVal;
    if(dfltVal!=NULL){
        DefaultVal=(*(dfltVal));
    }
    Arr1D_Resize(x, Q, dQ, DefaultVal);
    Q=Q2;
}
template<typename T> void Arr1D_Resize(std::vector<T>&x, int dQ, T*dfltVal=NULL){
    int Q=x.size();
    int Q2=Q+dQ;
    T DefaultVal;
    if(dfltVal!=NULL){
        DefaultVal=(*(dfltVal));
    }
    Arr1D_Resize(x, dQ, DefaultVal);
}
//
//
template<typename T> std::vector<int> Arr1D_SeekVal(T*where, int whereQ, const T&what){
    std::vector<int> Ns;
    for(int N=1; N<=whereQ; N++){
        if(where[N-1]==what){
            Ns.push_back(N);
        }
    }
    return Ns;
}
template<typename T> std::vector<int> Arr1D_SeekVal(std::vector<T>where, int whereQ, const T&what){
    return Arr1D_SeekVal(where.data(), where.size(), what);
}

template<typename T> bool Arr1D_SubArrIsAtPosN(T*where, int whereQ, T*what, int whatQ, int posN, bool IsReversed=false){
    bool R=true;
    T whereCur, whatCur;
    int whereN;
    if(IsReversed==false){
        if(posN+whatQ-1>whereQ){
            R=false;
        }else{
            for(int whatN=1; whatN<=whatQ; whatN++){
                whereN=posN+whatN-1;
                whereCur=where[whereN-1];
                whatCur=what[whatN-1];
                if(where[whereN-1]!=what[whatN-1]){
                    R=false;
                    break;
                }
            }
        }
    }else{
        if(posN-whatQ+1<1){
            R=false;
        }else{
            for(int whatN=1; whatN<=whatQ; whatN++){
                whereN=posN-whatN+1;
                whereCur=where[whereN-1];
                whatCur=what[whatN-1];
                if(where[whereN-1]!=what[whatN-1]){
                    R=false;
                    break;
                }
            }
        }
    }
    return R;
}

template<typename T> std::vector<int> Arr1D_SeekSubArr(T*where, int whereQ, T*what, int whatQ, bool IsReversed=false){//no vector specific
    std::vector<int> Ns;
    for(int N=1; N<=whereQ; N++){
        if(Arr1D_SubArrIsAtPosN(where, whereQ, what, whatQ, N, IsReversed)){
            Ns.push_back(N);
        }
    }
    return Ns;
}
//
//
template<typename T> void Arr1D_SwapVals(T*&x, int Q, int N1, int N2){//no vector specific
    T buf;
    N1=NInArrIfNegative(N1, Q);
    N2=NInArrIfNegative(N2, Q);
    if(N1!=0 && N2!=0 && N1<=Q && N2<=Q){
        buf=x[N1-1];
        x[N1-1]=x[N2-1];
        x[N2-1]=buf;
    }
}
template<typename T> void Arr1D_Reverse(T*&x, int Q){//no vector specific
    int N1, N2, Nmed;
    if(Q%2==0){
        Nmed=Q/2;
    }else{
        Nmed=(Q-1)/2;
    }
    for(N1=1; N1<=Nmed; N1++){
        N2=Q-N1+1;
        Arr1D_SwapVals(x, Q, N1, N2);
    }
}
template<typename T> void Arr1D_ShiftCyclelyToBegin(T*&x, int Q){
    T buf=x[1-1];
    for(int N=2; N<=Q; N++){
        Arr1D_SwapVals(x, Q, N-1, N);
    }
    //x[Q-1]=buf;//Q'utz?
}
template<typename T> void Arr1D_ShiftCyclelyToEnd(T*&x, int Q){
    T buf=x[Q-1];
    for(int N=Q; N>=2; N--){
        Arr1D_SwapVals(x, Q, N-1, N);
    }
    //x[1-1]=buf;//Q'utz?
}
//
//
template<typename T> void Arr1D_Add(T*&x, int&Q, const T&val){//sep uz vect et ptr
    Arr1D_Resize(x, Q, 1);
    x[Q-1]=val;
}
template<typename T> void Arr1D_Add(std::vector<T>&x, const T&val){//vrn uz vect
    x.push_back(val);
}
template<typename T> void Arr1D_InsToN_v1(T*&x, int&Q, int N, const T&val, int vsh=0){//sep uz vect et ptr
    if(vsh==1){
        printf("Arr1D_InsToN_v1 starts working\n");
        printf("Ini arr\n");
        for(int i=1; i<=Q; i++){
            std::cout<<"x["<<i<<"]="<<x[i-1]<<"; ";
        }
        std::cout<<std::endl;
    }
    N=NInArrIfNegative(N, Q);
    if(vsh==1){
        printf("N=%d\n", N);
    }
    if(N>=0 & N<=Q){
        Arr1D_Add(x, Q, val);
        if(vsh==1){
            printf("Array after adding\n");
            for(int i=1; i<=Q; i++){
                std::cout<<"x["<<i<<"]="<<x[i-1]<<"; ";
            }
            std::cout<<std::endl;
        }
        for(int i=Q; i>=N+1; i--){
            Arr1D_SwapVals(x, Q, i-1, i);
            if(vsh==1){
                std::cout<<"Array afrer aswapping melements: x["<<i<<"]="<<x[i-1]<<"and x["<<i-1<<"]="<<x[i-1-1]<<std::endl;
                for(int j=1; j<=Q; j++){
                    std::cout<<"x["<<j<<"]="<<x[j-1]<<"; ";
                }
                std::cout<<std::endl;
            }
        }
    }
    if(vsh==1){
        printf("Arr1D_InsToN_v1 finishes working\n");
    }
}
template<typename T> void Arr1D_InsToN_v2(T*&x, int&Q, int N, const T&y){//sep uz vect et ptr
    N=NInArrIfNegative(N, Q);
    if(N!=0){
        Arr1D_Resize(x, Q, 1);
        //
        for(int i=Q; i>=N+1; i--){
            x[i+1-1]=x[i-1];
        }
        x[N-1]=y;
    }
}
template<typename T> void Arr1D_InsToN(std::vector<T>&x, int N, const T&y){//vrn uz vect
    x.insert(x.begin()+N-1, y);
}

template<typename T> void Arr1D_DelN(T*&x, int&Q, int N){//sep uz vect et ptr
    for(int i=N; i<=Q-1; i++){
        x[i-1]=x[i-1+1];
    }
    Arr1D_Resize(x, Q, -1);
}
template<typename T> void Arr1D_DelN(std::vector<T>&x, int N){//vrn uz vect
    x.erase(x.begin()+N-1);
}
//
//
template<typename T> std::vector<T> Arr1D_GetSubArr_ByNs(T*x, int Q, T DefaultVal, int N1=1, int N2=-1){//no vector specific
    std::vector<T> Y;
    if(N1<0){
        N1+=(Q+1);
    }
    if(N2<0){
        N2+=(Q+1);
    }
    if(N2>=N1){
        if(N1>=1){
            if(N2<=Q){
                for(int i=1; i<=N2; i++){
                    Y.push_back(x[i-1]);
                }
            }else{
                for(int i=1; i<=Q; i++){
                    Y.push_back(x[i-1]);
                }
                for(int i=Q+1; i<=N2; i++){
                    Y.push_back(DefaultVal);
                }
            }
        }
        else if(N1<0)
        {
            if(N2<0){
                for(int i=N1; i<=N2; i++){
                    Y.push_back(DefaultVal);
                }

            }else{
                for(int i=N1; i<=0; i++){
                    Y.push_back(DefaultVal);
                }
                if(N2<=Q){
                    for(int i=1; i<=N2; i++){
                        Y.push_back(x[i-1]);
                    }
                }else{
                    for(int i=1; i<=Q; i++){
                        Y.push_back(x[i-1]);
                    }
                    for(int i=Q+1; i<=N2; i++){
                        Y.push_back(DefaultVal);
                    }
                }
            }
        }
    }else{//N2<N1, N1>N2, => order visa versa simply
        if(N1>=1 && N1<=Q && N2>=1 && N2<=Q){
            for(int i=N1; i>=N2; i--){
                Y.push_back(x[i-1]);
            }
        }
    }
    return Y;
}
template<typename T> std::vector<T> Arr1D_GetSubArr_ByNs(T*x, int Q, int N1=1, int N2=-1, T*dfltVal=NULL){//no vector specific
    T DefaultVal;
    if(dfltVal!=NULL){
        DefaultVal=(*(dfltVal));
    }
    return Arr1D_GetSubArr_ByNs(x, Q, DefaultVal, N1, N2);
}
template<typename T> std::vector<T> Arr1D_GetSubArr_ByNs_Simple(T*x, int Q, int N1=1, int N2=-1){//no vector specific
    std::vector<T> Y;
    if(N1<0){
        N1+=(Q+1);
    }
    if(N2<0){
        N2+=(Q+1);
    }
    if(N1>=1 && N1<=Q && N2>=1 && N2<=Q&& x!=NULL && Q>0){
        if(N2>=N1){
            for(int i=1; i<=N2; i++){
                Y.push_back(x[i-1]);
            }
        }else{//N2<N1, N1>N2, => order visa versa simply
            for(int i=N1; i>=N2; i--){
                Y.push_back(x[i-1]);
            }
        }
    }
    return Y;
}
//
template<typename T> std::vector<T> Arr1D_GetSubArr_ByLs(const T*x, int Q, T DefaultVal, int FirstN=1, int Qreq=0, int QDfltsBefore=0, int vsh=0){//no vector specific
    std::vector<T> Y;
    TDataShiftParams DataShiftParams(FirstN, QDfltsBefore, Qreq);
    //TDataShiftResults dsr=DataShiftParams.Calc0(Q);
    TDataShiftResults dsr=DataShiftParams.Calc(Q);
    if(vsh!=0){
        printf("Arr1D_GetSubArr_ByLs starts working\n");
        printf("dsr: %s\n",dsr.ToString().toStdString().c_str());
        printf("shft: %s\n",DataShiftParams.ToString().toStdString().c_str());
    }
    if(dsr.PreN2>0){
        if(vsh!=0)printf("PreN2>0==%d\n", dsr.PreN2);
        for(int i=1; i<=dsr.PreN2; i++){
            Y.push_back(DefaultVal);
        }
    }
    if(dsr.OwnN2>0){
        if(vsh!=0)printf("OwnN2>0==%d\n", dsr.OwnN2);
        for(int i=dsr.OwnN1; i<=dsr.OwnN2; i++){
            Y.push_back(x[i-1]);
        }
    }
    if(dsr.PostN2>0){
        if(vsh!=0)printf("PostN2>0==%d\n", dsr.PostN2);
        for(int i=dsr.PostN1; i<=dsr.PostN2; i++){
            Y.push_back(DefaultVal);
        }
    }
    if(vsh!=0)printf("Arr1D_GetSubArr_ByLs finishes working\n");
    return Y;
}
template<typename T> std::vector<T> Arr1D_GetSubArr_ByLs(const T*x, int Q,int FirstN=1, int Qreq=0, int QDfltsBefore=0, T*dfltVal=NULL){//no vector specific
    T DefaultVal;
    if(dfltVal!=NULL){
        DefaultVal=(*(dfltVal));
    }
    return  Arr1D_GetSubArr_ByLs(x, Q, DefaultVal, FirstN, Qreq, QDfltsBefore);
}
template<typename T> std::vector<T> Arr1D_GetSubArr_ByLs(const T*x, int Q, T DefaultVal, const TDataShiftParams&dsp){//no vector specific
    return Arr1D_GetSubArr_ByLs(x, Q, DefaultVal, dsp.FirstN, dsp.Lreq, dsp.QDefaultsBefore);
}
template<typename T> std::vector<T> Arr1D_GetSubArr_ByLs(const T*x, int Q, TDataShiftParams*DataShiftParams, T*dfltVal=NULL){//no vector specific
    T DefaultVal;
    TDataShiftParams DataShiftParam;
    if(DataShiftParams!=NULL){
        DataShiftParam=(*(DataShiftParams));
    }
    if(dfltVal!=NULL){
        DefaultVal=(*(dfltVal));
    }
    return  Arr1D_GetSubArr_ByLs(x, Q, DefaultVal, *DataShiftParams);
}
//
template<typename T> std::vector<T> Arr1D_GetSubArr_ByLs(const T*x, int Q, T*x2, int Q2, T DefaultVal, int FirstN=1, int Qreq=0, int QDfltsBefore=0, int vsh=1){//no nector specific
    std::vector<T> Y;
    TDataShiftParams DataShiftParams(FirstN, QDfltsBefore, Qreq);
    TDataShiftResults dsr=DataShiftParams.Calc(Q);
    if(vsh!=0){
        printf("Arr1D_GetSubArr_ByLs (2 arrs) starts working\n");
        printf("dsr: %s\n",dsr.ToString().toStdString().c_str());
        printf("shft: %s\n",DataShiftParams.ToString().toStdString().c_str());
    }
    if(dsr.PreN2>0){
        if(Q2>=dsr.PreN2>0){
            for(int i=1; i<=dsr.PreN2; i++){
                Y.push_back(x2[i-1]);
            }
            if(vsh!=0){
                printf("Q2>=dsr.PreN2 - all  pre-data is from array 2\n");
            }
        }
        else{
            for(int i=1; i<=Q2; i++){
                Y.push_back(x2[i-1]);
            }
            for(int i=Q2+1; i<=dsr.PostN2; i++){
                Y.push_back(DefaultVal);
            }
            if(vsh!=0){
                printf("part (%d) of pre-data is from array 2, rest (%d)- default vals\n", Q2, dsr.PreN2-Q2 );
            }
        }
    }else{
        if(vsh!=0){
            printf(" No spec chars before\n");
        }
    }
    if(dsr.OwnN2>0){
        for(int i=dsr.OwnN1; i<=dsr.OwnN2; i++){
            Y.push_back(x[i-1]);
        }
    }else{
        if(vsh!=0){
            printf(" No data \n");
        }
    }
    if(dsr.PostN2>0){
        if(Q2>=dsr.PostN1){
            if(Q2>=dsr.PostN2){
                for(int i=dsr.PostN1; i<=dsr.PostN2; i++){
                    Y.push_back(x2[i-1]);
                }
                if(vsh!=0){
                    printf("whole amount (%d) of post-data is from array 2\n", dsr.PostN2-dsr.PostN1+1);
                }
            }else{
                for(int i=dsr.PostN1; i<=Q2; i++){
                    Y.push_back(x2[i-1]);
                }
                for(int i=Q2+1; i<=dsr.PostN2; i++){
                    Y.push_back(DefaultVal);
                }
                if(vsh!=0){
                    printf("part (%d) of post-data is from array 2, rest (%d) - default vals\n", Q2-dsr.PostN1, dsr.PostN2-Q2);
                }
            }
        }else{
            for(int i=dsr.PostN1; i<=dsr.PostN2; i++){
                Y.push_back(DefaultVal);
            }
            if(vsh!=0){
                printf("whole amount (%d) of  post-data is default vals\n", dsr.PostN2-dsr.PostN1+1);
            }
        }
    }else{
        if(vsh!=0){
            printf(" No spec chars after\n");
        }
    }
    if(vsh!=0){
        printf("Arr1D_GetSubArr_ByLs finishes working\n");
    }
    return Y;
}
template<typename T> std::vector<T> Arr1D_GetSubArr_ByLs(const T*x, int Q, T*x2, int Q2, int FirstN=1, int Qreq=0, int QDfltsBefore=0, T*dfltVal=NULL){//no vector specific
    T DefaultVal;
    if(dfltVal!=NULL){
        DefaultVal=(*(dfltVal));
    }
    return Arr1D_GetSubArr_ByLs(x, Q, x2, Q2, DefaultVal, FirstN, Qreq, QDfltsBefore);
}
template<typename T> std::vector<T> Arr1D_GetSubArr_ByLs(const T*x, int Q, T*x2, int Q2, T DefaultVal, const TDataShiftParams&dsp){//no vector specific
    //     Arr1D_GetSubArr_ByLs(T*x, int Q, T*x2, int Q2, T DefaultVal, int FirstN=1, int Qreq=0, int QDfltsBefore=0)
    return Arr1D_GetSubArr_ByLs(x,       Q,   x2,     Q2,   DefaultVal, dsp.FirstN,   dsp.Lreq, dsp.QDefaultsBefore);
}
template<typename T> std::vector<T> Arr1D_GetSubArr_ByLs(T*x, int Q, T*x2, int Q2, const TDataShiftParams&DataShiftParams, T*dfltVal=NULL){//no vector specific
    T DefaultVal;
    if(dfltVal!=NULL){
        DefaultVal=(*(dfltVal));
    }
    return Arr1D_GetSubArr_ByLs(x, Q, x2, Q2, DefaultVal, DataShiftParams);
}
//
//
template<typename T> std::vector<T> Arr1D_Concat(T*x1, int Q1, T*x2, int Q2, T DefaultVal, TDataShiftParams*DataShiftParams=NULL){//no vector specific
    std::vector<T>Y, Z;
    int N, Q3;
    TDataShiftParams ShiftData;
    if(DataShiftParams!=NULL)ShiftData=(*(DataShiftParams));
    Z= Arr1D_GetSubArr_ByLs(x2, Q2, DefaultVal, ShiftData);
    for(N=1; N<=Q1; N++){
        Y.push_back(x1[N-1]);
    }
    Q3=Z.size();
    for(N=1; N<=Q3; N++){
        Y.push_back(Z[N-1]);
    }
    return Y;
}
template<typename T> std::vector<T> Arr1D_Concat(T*x1, int Q1, T*x2, int Q2, TDataShiftParams*dsp=NULL, T*dfltVal=NULL){//no vector specific
    T DefaultVal;
    if(dfltVal!=NULL){
        DefaultVal=(*(dfltVal));
    }
    TDataShiftParams DataShiftParams;
    if(dsp!=NULL){
        DataShiftParams=(*(dsp));
    }
    return Arr1D_Concat(x1, Q1, x2, Q2, DefaultVal, DataShiftParams);
}
template<typename T> void Arr1D_ConcatAdding(T*&x1, int& Q1, T*x2, int Q2, T DefaultVal, TDataShiftParams*DataShiftParam=NULL, int vsh=0){//separately for vect and ptr, but for row 1 only, for row 2 - no vector specific
    T*x1nw=NULL;
    int N, Q3,QS;
    std::vector<T>Z;//= Arr1D_GetSubArr_ByLs(x2, Q2, DefaultVal, DataShiftParams);
    TDataShiftParams ShiftData;
    if(vsh==1){
        printf("Arr1D_ConcatAdding starts working\nGiven:\n");
        printf("Array1 (Q1=%d):\n",Q1);
        if(x1!=NULL && Q1>0){
            for(int i=1; i<=Q1; i++){
                std::cout<<"x["<<i<<"]="<<x1[i-1]<<"; ";
            }
            std::cout<<std::endl;
        }
        printf("Array2 (Q2=%d):\n", Q2);
        if(x2!=NULL && Q2>0){
            for(int i=1; i<=Q2; i++){
                std::cout<<"x["<<i<<"]="<<x2[i-1]<<"; ";
            }
            std::cout<<std::endl;
        }
    }
    if(DataShiftParam!=NULL)ShiftData=(*(DataShiftParam));
    Z= Arr1D_GetSubArr_ByLs(x2, Q2, DefaultVal, ShiftData);
    Q3=Z.size();
    QS=Q1+Q3;
    if(vsh==1){
        printf("new array 2 to concat:\n");
        //if(x1!=NULL && Q1>0){
        for(int i=1; i<=Q3; i++){
            std::cout<<"x["<<i<<"]="<<Z[i-1]<<"; ";
        }
        std::cout<<std::endl;
        //}
        printf("Q3=%d, QS=%d:\n", Q3, QS);
    }
    x1nw=new T[QS];
    if(x1!=NULL){
        for(N=1; N<=Q1; N++){
            x1nw[N-1]=x1[N-1];
        }
        //
        delete[]x1;
        x1=NULL;
    }else if(Q1>0){
        for(N=1; N<=Q1; N++){
            x1nw[N-1]=DefaultVal;
        }
    }
    for(N=1; N<=Q3; N++){
        x1nw[Q1+N-1]=Z[N-1];
    }
    //
    x1=x1nw;
    //
    Q1=QS;
    if(vsh==1){
        printf("Result:\n");
        if(x1!=NULL && Q1>0){
            for(int i=1; i<=Q1; i++){
                std::cout<<"x["<<i<<"]="<<x1[i-1]<<"; ";
            }
            std::cout<<std::endl;
        }
        printf("Arr1D_ConcatAdding finishes working\n");
    }
}
template<typename T> void Arr1D_ConcatAdding(std::vector<T>&x1,  T*x2, int Q2, T DefaultVal, const TDataShiftParams&DataShiftParams){//vrn for vect
    std::vector<T> Z= Arr1D_GetSubArr_ByLs(x2, Q2, DefaultVal, DataShiftParams);
    int Q3=Z.size();
    for(int i=1; i<=Q3; i++){
        x1.push_back(Z[i-1]);
    }
}

template<typename T> std::vector<T> Arr1D_ConcatAdding(T*&x1, int& Q1, T*x2, int Q2, TDataShiftParams*dsp=NULL, T*dfltVal=NULL){//separately for vect and ptr, but for row 1 only, for row 2 - no vector specific
    T DefaultVal;
    if(dfltVal!=NULL){
        DefaultVal=(*(dfltVal));
    }
    TDataShiftParams DataShiftParams;
    if(dsp!=NULL){
        DataShiftParams=(*(dsp));
    }
    Arr1D_ConcatAdding(x1, Q1, x2, Q2, DefaultVal, DataShiftParams);
}

//=== wa Arr1D, wi: Arr2D info =================================

const int DEFAULT_SIZE=0;//1;

const int Arr2DSize_Rect_TypeN=10;
const int Arr2DSize_VarLens_V_TypeN=21;
const int Arr2DSize_VarLens_P_TypeN=22;
//
const int Arr2DSize_Default=Arr2DSize_VarLens_V_TypeN;//Arr2DSize_Rect_TypeN;
//
//
const int ELEMENT_TYPE_N_OLD_2D_ARRAY_VAL=1;
const int ELEMENT_TYPE_N_NEW_ROW_GIVEN_VAL=2;
const int ELEMENT_TYPE_N_DEFAULT_VAL=3;
const int ELEMENT_TYPE_N_INCORRECT=0;
//
const int ARR2D_ACTION_TYPE_N_SET_EXT_ROW=1;
const int ARR2D_ACTION_TYPE_N_ADD_EXT_ROW=2;
const int ARR2D_ACTION_TYPE_N_INS_EXT_ROW=3;
const int ARR2D_ACTION_TYPE_N_DEL_EXT_ROW=4;
const int ARR2D_ACTION_TYPE_N_SET_INE_ROW=5;
const int ARR2D_ACTION_TYPE_N_ADD_INE_ROW=6;
const int ARR2D_ACTION_TYPE_N_INS_INE_ROW=7;
const int ARR2D_ACTION_TYPE_N_DEL_INE_ROW=8;
//
const int Arr2D_DataType_Arr2DOldData=-1;
const int Arr2D_DataType_GivenNewData=-2;
const int Arr2D_DataType_DefaultVals=-3;
const int Arr2D_DataType_IncorrectCase=-4;
//
const int Arr2D_Resize_Ext_Row_IfWasRectAndNewValMakesNotRect_NonRect=0;
const int Arr2D_Resize_Ext_Row_IfWasRectAndNewValMakesNotRect_RectBy_New_ValAllRows=1;
const int Arr2D_Resize_Ext_Row_IfWasRectAndNewValMakesNotRect_RectBy_Old_ValRemains=2;
const int Arr2D_Resize_Ext_Row_IfWasRectAndNewValMakesNotRect_RectBy_Max_ValOfOldAndNew=3;
const int Arr2D_Resize_Ext_Row_IfWasRectAndNewValMakesNotRect_RectBy_Min_ValOfOldAndNew=4;
//
const int SizeChoiceCase_New=1;
const int SizeChoiceCase_Old=2;
const int SizeChoiceCase_Max=3;
const int SizeChoiceCase_Min=4;
//
//
class Arr2D_Position{
public:
    bool IsNotTransposed;
    bool EachExtRowIsNotInverted;
    bool ExtRowsSuccessionIsNotInverted;
    Arr2D_Position();
    ~Arr2D_Position();
    QString ToString();
};

class Arr2D_ResizeParams{
    int DataType_Arr2DOldData=-1;
    int DataType_GivenNewData=-2;
    int DataType_DefaultVals=-3;
    int DataType_IncorrectCase=-4;
    //
    int Lmax, Lmin, QExtRows;
    int*ptr;
public:
    Arr2D_ResizeParams();
    Arr2D_ResizeParams(int QExtRows, int Lmax, int Lmin=0, int*Ls=NULL);
    ~Arr2D_ResizeParams();
    void construct();
    void Set(int QExtRows, int Lmax, int Lmin=0, int*Ls=NULL);
    int* GetLs();
    int GetLmax();
    int GetLmin();
    int GetQExtRows();
    void Get(int&QExtRows, int&Lmax, int&Lmin, int*&Ls);
    int GetDataTypeOldVals();
    int GetDataTypeGivenVals();
    int GetDataTypeDefault();
    int GetDataTypeIncorrect();
};
class Arr2D_ResizeParamsSafe{
    int DataType_Arr2DOldData=-1;
    int DataType_GivenNewData=-2;
    int DataType_DefaultVals=-3;
    int DataType_IncorrectCase=-4;
    //
    int Lmax, Lmin, QExtRows;
    std::vector<int>Ls;
public:
    Arr2D_ResizeParamsSafe();
    Arr2D_ResizeParamsSafe(int QExtRows, int Lmax, int Lmin=0, int* Ls=NULL);
    ~Arr2D_ResizeParamsSafe();
    void construct();
    void Set(int QExtRows, int Lmax, int Lmin=0, int*Ls=NULL);
    int* GetLsAsPtr();
    std::vector<int> GetLsAsSV();
    int GetLmax();
    int GetLmin();
    int GetQExtRows();
    void Get(int&QExtRows, int&Lmax, int&Lmin, int*&Ls);
    int GetDataTypeOldVals();
    int GetDataTypeGivenVals();
    int GetDataTypeDefault();
    int GetDataTypeIncorrect();
};

//
//
class Array2DSize_Prototype{
  public:
    virtual ~Array2DSize_Prototype();
    //
    std::vector<int> GetAsArrayOfExtRowsLengthes()const;  //new
    //
    void construct();//SeNullIni is called
    virtual void SetNull()=0;
    virtual void SetNullIni()=0;
    virtual void SetOne()=0;
    //
    virtual int GetTypeN()const=0;
    //
    virtual void Assign(Array2DSize_Prototype*obj)=0;
    //
    virtual void Set(int* extRowsLengthes, int QExtRows=0, int ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2=0)=0;
    virtual void Set(int QExtRows, int extRowsLength);
    void Set(std::vector<int>Ls, int ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2=0);
    //
    virtual int GetQExtRows() const =0;
    virtual int GetRowLength(int N=-1) const =0;
    virtual int GetRowLengthMin() const ;
    virtual int GetRowLengthMax() const ;
    std::vector<int>GetLengthes() const;
    std::vector<int>GetMinLengthRowNs() const;
    std::vector<int>GetMaxLengthRowNs() const;
    int GetQElements() const;
    //virtual Array2DSize_Prototype*GetSize_asPtr() const =0;
    //
    int Arr2DBy1D_PosNByCoords(int ExtRowN, int IneRowN) const;
    Coords2DInt Arr2DBy1D_CoordsByPosN(int PosN) const;
    //int Arr2DBy1D_ExtRowNByPosN(int PosN) const;
    //int Arr2DBy1D_IneRowNByPosN(int PosN) const;
    //
    bool IsRectangularByType() const;
    bool IsRectangularInFact() const;
    //virtual bool IsEmpty() const;
    bool IsEmpty() const;
    //
    int GetIneRowLength_NoBreaks(int N=-1, bool countWhole=false) const;
    bool isTransposable();
    //
    //
    virtual void setExtRow_simplyAsDataGiven(int N=-1, int L=0, int ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4=0)=0;
    virtual void addExtRow_simplyAsDataGiven(          int L=0, int ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4=0)=0;
    virtual void insExtRow_simplyAsDataGiven(int N=-1, int L=0, int ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4=0)=0;
    virtual void delExtRow_simplyAsDataGiven(int N=-1)=0;
    virtual void set_or_ins_IneRow_simplyAsDataGiven(int Action_Set1_Ins2, int N=-1, int L=0, int ifL_NE_QER_Ignore0_MakeRactChangingBy_New1Old2Max3Min4=0, int ifLminLTN_ifAdd_N1_Lmax2_LmaxRest3_MakeRectAnyway_Lmax4_LmaxRest5=4)=0;
    virtual void addIneRow_simplyAsDataGiven(int L=0, int ifL_NE_QER_Ignore0_MakeRactChangingBy_New1Old2Max3Min4=0, int ifNonRect_Ignore0AddToLast1StretchToMax2=0 )=0;
    virtual void delIneRow_simplyAsDataGiven(int N=-1,     int ifNGTLminIgnore0ShortenNurLongRows1=0)=0;
    //
    // ---------------------------------------------------------------------------------------------------

    void set_or_ins_ExtRow_simplyAsDataGiven_HilfsFun(int Action_Set1_Ins3, int ERNNGiven_0IfAll, const Coords2DInt&CoordsNew, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn, int&ERLNew, int&QExtRowsNew, int&DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0, int&InGivenRowPosN, Coords2DInt&CoordsOld);

    int set_or_ins_ExtRow_simplyAsDataGiven_QExtRowsNew(int Action_Set1_Ins3, int ERNNGiven_0IfAll, const Coords2DInt&CoordsNew, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn);
    int set_or_ins_ExtRow_simplyAsDataGiven_ExtRowLengthNew(int Action_Set1_Ins3, int ERNNGiven_0IfAll, const Coords2DInt&CoordsNew, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn);
    int set_or_ins_ExtRow_simplyAsDataGiven_DataTypeN(int Action_Set1_Ins3, int ERNNGiven_0IfAll, const Coords2DInt&CoordsNew, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn);
    int set_or_ins_ExtRow_simplyAsDataGiven_InGivenRowPosN(int Action_Set1_Ins3, int ERNNGiven_0IfAll, const Coords2DInt&CoordsNew, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn);
    Coords2DInt set_or_ins_ExtRow_simplyAsDataGiven_Arr2DNewToOldPosN(int Action_Set1_Ins3, int ERNNGiven_0IfAll, const Coords2DInt&CoordsNew, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn);

    void set_or_ins_ExtRow_simplyAsDataGiven_HilfsFun_v1(std::vector<int>&RowsLs, std::vector<Coords2DInt>&DataSources, int Action_Set1_Ins3, int ERNNGiven_0IfAll, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn);

    Arr2D_ResizeParams set_or_ins_ExtRow_simplyAsDataGiven_NewReSize(int Action_Set1_Ins3, int ERNNGiven_0IfAll, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn);

    //--------------------------------------------------------------------------------------------------

    void addExtRow_simplyAsDataGiven_HilfsFun(const Coords2DInt&CoordsNew, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn, int&ERLNew, int&QExtRowsNew, int&DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0, int&InGivenRowPosN, Coords2DInt&CoordsOld);

    int addExtRow_simplyAsDataGiven_QExtRowsNew(const Coords2DInt&CoordsNew, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn);
    int addExtRow_simplyAsDataGiven_ExtRowLengthNew(const Coords2DInt&CoordsNew, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn);
    int addExtRow_simplyAsDataGiven_DataType(const Coords2DInt&CoordsNew, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn);
    int addExtRow_simplyAsDataGiven_InGivenRowPosNN(const Coords2DInt&CoordsNew, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn);
    Coords2DInt addExtRow_simplyAsDataGiven_Arr2DCoordsNewToOld(const Coords2DInt&CoordsNew, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn);

    void addExtRow_simplyAsDataGiven_HilfsFun_v1(std::vector<int>Ls, std::vector<Coords2DInt>&DataSources, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn);

    Arr2D_ResizeParams addExtRow_simplyAsDataGiven_NewReSize(int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn);

    //--------------------------------------------------------------------------------------------------

    void delExtRow_HilfsFun(const Coords2DInt&CoordsNew, int ExtRowToDelNN, int&ERLNew, int&QExtRowsNew,  Coords2DInt&CoordsOld);

    int delExtRow_ExtRowNewLengthNew(const Coords2DInt&CoordsNew, int ExtRowToDelNN);
    int delExtRow_QExtRowsNew(const Coords2DInt&CoordsNew, int ExtRowToDelNN);
    Coords2DInt delExtRow_Arr2DCoordsNewToOld(const Coords2DInt&CoordsNew, int ExtRowToDelNN);

    void delExtRow_HilfsFun_v1(std::vector<int>Ls, std::vector<Coords2DInt>&DataSources, int ExtRowToDelNN);

    Arr2D_ResizeParams delExtRow_NewReSize(int ExtRowToDelNN);

    //--------------------------------------------------------------------------------------------------

    void delIneRow_HilfsFun(const Coords2DInt&CoordsNew, int IneRowToDelNN, int ifN_GT_Lmin_CutLongOnly1_Ignore0, int&QExtRowsNew, int&ERLNew, Coords2DInt&CoordsOld);

    int delIneRow_ExtRowNewLength(const Coords2DInt&CoordsNew, int IneRowToDelNN, int ifN_GT_Lmin_CutLongOnly1_Ignore0);
    int delIneRow_QExtRowsNew(const Coords2DInt&CoordsNew, int IneRowToDelNN, int ifN_GT_Lmin_CutLongOnly1_Ignore0);
    Coords2DInt delIneRow_Arr2DCoordsNewToOld(const Coords2DInt&CoordsNew, int IneRowToDelNN, int ifN_GT_Lmin_CutLongOnly1_Ignore0);

    void delIneRow_HilfsFun_v1(std::vector<int>Ls, std::vector<Coords2DInt>&DataSources, const Coords2DInt&CoordsNew, int IneRowToDelNN, int ifN_GT_Lmin_CutLongOnly1_Ignore0);

    Arr2D_ResizeParams delIneRow_NewReSize( int IneRowToDelNN, int ifN_GT_Lmin_CutLongOnly1_Ignore0);

    //--------------------------------------------------------------------------------------------------

    void addIneRow_simplyAsDataGiven_HilfsFun(const Coords2DInt&CoordsNew, int givenL, int ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4, int ifNonRect_AddToLast1StretchToMax2Ignore0, int&DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0, int&QExtRowsNew, int&ERLNew, int&InGivenRowPosN,Coords2DInt&CoordsOld);

    int addIneRow_simplyAsDataGiven_NewExtRowLength(const Coords2DInt&CoordsNew, int givenL, int ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4, int ifNonRect_AddToLast1StretchToMax2Ignore0);
    int addIneRow_simplyAsDataGiven_QExtRowsNew(const Coords2DInt&CoordsNew, int givenL, int ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4, int ifNonRect_AddToLast1StretchToMax2Ignore0);
    int addIneRow_simplyAsDataGiven_DataTypeN(const Coords2DInt&CoordsNew, int givenL, int ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4, int ifNonRect_AddToLast1StretchToMax2Ignore0);
    Coords2DInt addIneRow_simplyAsDataGiven_Arr2DCoordsNewToOld(const Coords2DInt&CoordsNew, int givenL, int ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4, int ifNonRect_AddToLast1StretchToMax2Ignore0);

    void addIneRow_simplyAsDataGiven_HilfsFun_v1(std::vector<int>Ls, std::vector<Coords2DInt>&DataSources, int givenL, int ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4, int ifNonRect_AddToLast1StretchToMax2Ignore0);

    Arr2D_ResizeParams addIneRow_simplyAsDataGiven_NewReSize(int givenL, int ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4, int ifNonRect_AddToLast1StretchToMax2Ignore0);

    //--------------------------------------------------------------------------------------------------

    void set_or_ins_IneRow_simplyAsDataGiven_HilfsFun(int Action_Set1_Ins3, const Coords2DInt&CoordsNew, int ToOperateIneRowNN_0ifAll, int givenL, int ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4, int if_Lmin_LT_N_Ignore0_ModifyLongOnly1_StretchTo_N2_Max3, int&DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0, int&QExtRowsNew, int&ERLNew, int&InGivenRowPosN,Coords2DInt&CoordsOld);

    int set_or_ins_IneRow_simplyAsDataGiven_QExtRows(int Action_Set1_Ins3, const Coords2DInt&CoordsNew, int ToOperateIneRowNN_0ifAll, int givenL, int ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4, int if_Lmin_LT_N_Ignore0_ModifyLongOnly1_StretchTo_N2_Max3);
    int set_or_ins_IneRow_simplyAsDataGiven_ExtRowL(int Action_Set1_Ins3, int InquiredExtRowNN, int ToOperateIneRowNN_0ifAll, int givenL, int ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4, int if_Lmin_LT_N_Ignore0_ModifyLongOnly1_StretchTo_N2_Max3);
    int set_or_ins_IneRow_simplyAsDataGiven_Arr2DNewCoordsToDataTypeN(int Action_Set1_Ins3, const Coords2DInt&CoordsNew, int ToOperateIneRowNN_0ifAll, int givenL, int ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4, int if_Lmin_LT_N_Ignore0_ModifyLongOnly1_StretchTo_N2_Max3);
    Coords2DInt set_or_ins_IneRow_simplyAsDataGiven_Arr2DNewCoordsNewToOld(int Action_Set1_Ins3, const Coords2DInt&CoordsNew, int ToOperateIneRowNN_0ifAll, int givenL, int ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4, int if_Lmin_LT_N_Ignore0_ModifyLongOnly1_StretchTo_N2_Max3);

    void set_or_ins_IneRow_simplyAsDataGiven_HilfsFun_v1(std::vector<int>Ls, std::vector<Coords2DInt>&DataSources, int Action_Set1_Ins3, int ToOperateIneRowNN_0ifAll, int givenL, int ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4, int if_Lmin_LT_N_Ignore0_ModifyLongOnly1_StretchTo_N2_Max3);

    Arr2D_ResizeParams set_or_ins_IneRow_simplyAsDataGiven_NewReSize(int Action_Set1_Ins3, int ToOperateIneRowNN_0ifAll, int givenL, int ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4, int if_Lmin_LT_N_Ignore0_ModifyLongOnly1_StretchTo_N2_Max3);
    //
    //------------------------------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------------------------

    void Set_simplyAsDataGiven_HilfsFun2(int&QExtRowsNew, int&ERLNew, int&DataTypeN_Arr2DVals1_GivenVals2_Default3_Incorrect0, Coords2DInt&CoordsOld, int* extRowsLengthes, int QExtRowsGiven, int ifNotRect_NonRect0_MakeRectBy_Min1Max2MinOfMax3MaxOfMax4, bool IfNotValsOfGivenRow_DefaultNotOwn);


    int Set_simplyAsDataGiven_QExtRows2(int* extRowsLengthes, int QExtRowsGiven, int ifNotRect_NonRect0_MakeRectBy_Min1Max2MinOfMax3MaxOfMax4, bool IfNotValsOfGivenRow_DefaultNotOwn);
    int Set_simplyAsDataGiven_ExtRowNewLength2(int ExtRowNewNN,  int* extRowsLengthes, int QExtRowsGiven, int ifNotRect_NonRect0_MakeRectBy_Min1Max2MinOfMax3MaxOfMax4, bool IfNotValsOfGivenRow_DefaultNotOwn);
    int Set_simplyAsDataGiven_Arr2DCoordsNewToDataTypeN2(const Coords2DInt&CoordsNew, int* extRowsLengthes, int QExtRowsGiven, int ifNotRect_NonRect0_MakeRectBy_Min1Max2MinOfMax3MaxOfMax4, bool IfNotValsOfGivenRow_DefaultNotOwn);
    Coords2DInt Set_simplyAsDataGiven_Arr2DCoordsNewToOld2(const Coords2DInt&CoordsNew, int* extRowsLengthes, int QExtRowsGiven, int ifNotRect_NonRect0_MakeRectBy_Min1Max2MinOfMax3MaxOfMax4, bool IfNotValsOfGivenRow_DefaultNotOwn);

    void Set_simplyAsDataGiven_HilfsFun_v12(std::vector<int>&RowsLs, std::vector<Coords2DInt>&DataSources, int* extRowsLengthes, int QExtRows, int ifNotRect_NonRect0_MakeRectBy_Min1Max2, bool IfNotValsOfGivenRow_DefaultNotOwn);

    Arr2D_ResizeParams Set_simplyAsDataGiven_NewReSize2(int* extRowsLengthes, int QExtRows, int ifNotRect_NonRect0_MakeRectBy_Min1Max2, bool IfNotValsOfGivenRow_DefaultNotOwn);


    void Set_simplyAsDataGiven_HilfsFun(int&QExtRowsNew, int&ERLNew, int&DataTypeN_Arr2DVals1_GivenVals2_Default3_Incorrect0, Coords2DInt&CoordsOld, const Coords2DInt&CoordsNew, int* extRowsLengthes, int QExtRowsGiven, int ifNotRect_NonRect0_MakeRectBy_Min1Max2);

    int Set_simplyAsDataGiven_QExtRows(int* extRowsLengthes, int QExtRowsGiven, int ifNotRect_NonRect0_MakeRectBy_Min1Max2);
    int Set_simplyAsDataGiven_ExtRowNewLength(int ExtRowNewNN,  int* extRowsLengthes, int QExtRowsGiven, int ifNotRect_NonRect0_MakeRectBy_Min1Max2);
    int Set_simplyAsDataGiven_Arr2DCoordsNewToDataTypeN(const Coords2DInt&CoordsNew, int* extRowsLengthes, int QExtRowsGiven, int ifNotRect_NonRect0_MakeRectBy_Min1Max2);
    Coords2DInt Set_simplyAsDataGiven_Arr2DCoordsNewToOld(const Coords2DInt&CoordsNew, int* extRowsLengthes, int QExtRowsGiven, int ifNotRect_NonRect0_MakeRectBy_Min1Max2);
    Arr2D_ResizeParams Set_simplyAsDataGiven_NewReSize(int* extRowsLengthes, int QExtRows, int ifNotRect_NonRect0_MakeRectBy_Min1Max2);


    // ===========================================================================================================
    //
    TDataShiftResults  ExtRow_SetAddInsDel_dataNs(int Action_Set1_Add2_Ins3_Del4_Dflt0, int givenRowL=0, /*int inquiredRowNN=-1,*/ int ChangedRowNN_0ifAll=-1, TDataShiftParams*DataShiftParam=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0, bool suiValsInsteadOfDefaultValsWherePossible=true);
    int ExtRow_SetAddInsDel_ThatCorrectedByNewData_NewLength(int Action_Set1_Add2_Ins3_Del4_Dflt0, int givenRowL=0, int ExtRowNN_0ifAll=-1, TDataShiftParams*DataShiftParam=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0, bool suiValsInsteadOfDefaultValsWherePossible=true);

    int ExtRow_SetAddInsDel_ThatCorrectedByNewData_PosInRowToDataTypeN(int Action_Set1_Add2_Ins3_Del4_Dflt0, int InRowPosNN, int givenRowL=0, int ExtRowNN_0ifAll=-1, TDataShiftParams*DataShiftParam=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0, bool suiValsInsteadOfDefaultValsWherePossible=true);
    int ExtRow_SetAddInsDel_OldLengthOfExtRowN(int Action_Set1_Add2_Ins3_Del4_Dflt0, int inquiredRowNN, int ExtRowNN_0ifAll=-1, int givenRowL=0, TDataShiftParams*ShiftData=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0, bool suiValsInsteadOfDefaultValsWherePossible=true);
    int ExtRow_SetAddInsDel_NewLengthOfExtRowN(int Action_Set1_Add2_Ins3_Del4_Dflt0, int inquiredRowNN, int ExtRowNN_0ifAll=-1, int givenRowL=0, TDataShiftParams*ShiftData=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0,  bool suiValsInsteadOfDefaultValsWherePossible=true);
    //
    int ExtRow_SetAddInsDel_Arr2DNewCoordsToDataTypeN(int Action_Set1_Add2_Ins3_Del4_Dflt0, const Coords2DInt&coords, int ExtRowNN_0ifAll=-1, int givenRowL=0, TDataShiftParams*ShiftData=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0, bool suiValsInsteadOfDefaultValsWherePossible=true);
    //
    //
    int ExtRow_SetAddInsDel_ThatCorrectedByNewData_FromArr2dNewToGivenRowPosN(int Action_Set1_Add2_Ins3_Del4_Dflt0, int InRowPosNN, int givenRowL=0, int ChangedRowNN_0ifAll=-1, TDataShiftParams*DataShiftParam=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0, bool suiValsInsteadOfDefaultValsWherePossible=true);

    int ExtRow_SetAddInsDel_ThatCorrectedByNewData_FromArr2dNewToOldRowPosN(int Action_Set1_Add2_Ins3_Del4_Dflt0, int InRowNN, /*const Coords2DInt&coords,*/ int givenRowL=0, int ExtRowNN_0ifAll=-1, TDataShiftParams*DataShiftParam=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0, bool suiValsInsteadOfDefaultValsWherePossible=true);

    Coords2DInt ExtRow_SetAddInsDel_ThatCorrectedByNewData_CoordsFromArr2dNewToOld(int Action_Set1_Add2_Ins3_Del4_Dflt0, const Coords2DInt&coords, int givenRowL=0, int ExtRowNN_0ifAll=-1, TDataShiftParams*DataShiftParam=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0, bool suiValsInsteadOfDefaultValsWherePossible=true);

    //
    //
    //virtual void Set(int* extRowsLengthes, int QExtRows=1, int ifNotRect_NonRect0_MakeRectBy_Min1Max2MinOfMax3MaxOfMax4=0, bool IfNotValsOfGivenRow_DefaultNotOwn=true)=0;
    void Set_HilfsFun(int&QExtRowsNew, int&ERLNew, int&DataTypeN_Arr2DVals1_GivenVals2_Default3_Incorrect0, Coords2DInt&CoordsOld, int* extRowsLengthes, int QExtRows=1, int ifNotRect_NonRect0_MakeRectBy_Min1Max2MinOfMax3MaxOfMax4=0, bool IfNotValsOfGivenRow_DefaultNotOwn=true);
    //int Set_GetExtNewRowLength(int* extRowsLengthes, int QExtRows, int ifNotRect_NonRect0_MakeRectBy_Min1Max2=0);//no need - 4 tgos: Lcur, Lold, Lmin, Lmax
    int Set_Arr2DNewCoordsToDataTypeN(const Coords2DInt&coords, int* extRowsLengthes, int QExtRows=1, int ifNotRect_NonRect0_MakeRectBy_Min1Max2=0, bool IfNotValsOfGivenRow_DefaultNotOwn=true);
    Coords2DInt Set_Arr2DNewToOldCoords(const Coords2DInt&coords, int* extRowsLengthes, int QExtRows=1, int ifNotRect_NonRect0_MakeRectBy_Min1Max2=0);
    void Set_HilfsFun_v1(std::vector<int>&RowsLs, std::vector<Coords2DInt>&DataSources, int* extRowsLengthes, int QExtRows, int ifNotRect_NonRect0_MakeRectBy_Min1Max2, bool IfNotValsOfGivenRow_DefaultNotOwn);

    QString GetAsString();
};

class Array2DSize_Rectangular: public Array2DSize_Prototype{
    int QExtRows;
    int ExtRowsLength;
    //
  public:
    Array2DSize_Rectangular();
    Array2DSize_Rectangular(int QExtRows, int*RowsLs, int ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2=0);
    Array2DSize_Rectangular(int QExtRows, int RowsLs);
    Array2DSize_Rectangular(std::vector<int>Ls, int ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2=0);
    //virtual ~Array2DSize_Prototype();
    ~Array2DSize_Rectangular();
    //
    //std::vector<int> GetAsArrayOfExtRowsLengthes()const;  //new
    //
    //void construct();//SeNullIni is called
    virtual void SetNull();
    virtual void SetNullIni();
    virtual void SetOne();
    //
    virtual int GetTypeN()const;
    //
    virtual void Assign(Array2DSize_Prototype*obj);
    //
    virtual void Set(int* extRowsLengthes, int QExtRows=0, int ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2=0);
    virtual void Set(int QExtRows, int extRowsLength, int ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2=0);
    //void Set(std::vector<int>Ls, int ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2=0);
    //
    virtual int GetQExtRows() const ;
    virtual int GetRowLength(int N=-1) const ;
    virtual int GetRowLengthMin() const ;
    virtual int GetRowLengthMax() const ;
    //std::vector<int>GetLengthes() const;
    //std::vector<int>GetMinLengthRowNs() const;
    //std::vector<int>GetMaxLengthRowNs() const;
    //int GetQElements() const;
    //virtual Array2DSize_Prototype*GetSize_asPtr() const =0;
    //
    //int Arr2DBy1D_PosNByCoords(int ExtRowN, int IneRowN) const;
    //Coords2DInt Arr2DBy1D_CoordsByPosN(int PosN) const;
    ////int Arr2DBy1D_ExtRowNByPosN(int PosN) const;
    ////int Arr2DBy1D_IneRowNByPosN(int PosN) const;
    //
    //bool IsRectangularByType() const;
    //bool IsRectangularInFact() const;
    ////virtual bool IsEmpty() const;
    //bool IsEmpty() const;

    //
    //
    virtual void setExtRow_simplyAsDataGiven(int N=-1, int L=0, int ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4=0);
    virtual void addExtRow_simplyAsDataGiven(int L=0,           int ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4=0);
    virtual void insExtRow_simplyAsDataGiven(int N=-1, int L=0, int ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4=0);
    virtual void delExtRow_simplyAsDataGiven(int N=-1);
    virtual void set_or_ins_IneRow_simplyAsDataGiven(int Action_Set1_Ins2, int N=-1, int L=0, int ifL_NE_QER_Ignore0_MakeRactChangingBy_New1Old2Max3Min4=0, int ifLminLTN_ifAdd_N1_Lmax2_LmaxRest3_MakeRectAnyway_Lmax4_LmaxRest5=4);
    virtual void addIneRow_simplyAsDataGiven(int L=0, int ifL_NE_QER_Ignore0_MakeRactChangingBy_New1Old2Max3Min4=0, int ifNonRect_Ignore0AddToLast1StretchToMax2=0 );
    virtual void delIneRow_simplyAsDataGiven(int N=-1, int ifNGTLminIgnore0ShortenNurLongRows1=0);
    //
    int setExtRow_simplyAsDataGiven_DataTypeN(const Coords2DInt&coords, int N=-1, int L=0, int ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4=0);
    int setExtRow_simplyAsDataGiven_ThatChangedRow_NewArr2DToGivenRowPosN(int InRowPosNN, int N=-1, int L=0, int ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4=0);
    Coords2DInt setExtRow_simplyAsDataGiven_CoordsNewToOld(const Coords2DInt&coords, int N=-1, int L=0, int ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4=0);

    //
    //TDataShiftResults  ExtRow_SetAddInsDel_dataNs(int Action_Set1_Add2_Ins3_Del4_Dflt0, int givenRowL=0, int inquiredRowNN=-1, int ChangedRowNN_0ifAll=-1, TDataShiftParams*DataShiftParam=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0, bool suiValsInsteadOfDefaultValsWherePossible=true);
    //int ExtRow_SetAddInsDel_ThatCorrectedByNewData_NewLength(int Action_Set1_Add2_Ins3_Del4_Dflt0, int givenRowL=0, int ExtRowNN_0ifAll=-1, TDataShiftParams*DataShiftParam=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0, bool suiValsInsteadOfDefaultValsWherePossible=true);

    //int ExtRow_SetAddInsDel_ThatCorrectedByNewData_PosInRowToDataTypeN(int Action_Set1_Add2_Ins3_Del4_Dflt0, int InRowPosNN, int givenRowL=0, int ExtRowNN_0ifAll=-1, TDataShiftParams*DataShiftParam=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0, bool suiValsInsteadOfDefaultValsWherePossible=true);
    //int ExtRow_SetAddInsDel_OldLengthOfExtRowN(int Action_Set1_Add2_Ins3_Del4_Dflt0, int inquiredRowNN, int ExtRowNN_0ifAll=-1, int givenRowL=0, TDataShiftParams*ShiftData=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0, bool suiValsInsteadOfDefaultValsWherePossible=true);
    //int ExtRow_SetAddInsDel_NewLengthOfExtRowN(int Action_Set1_Add2_Ins3_Del4_Dflt0, int inquiredRowNN, int ExtRowNN_0ifAll=-1, int givenRowL=0, TDataShiftParams*ShiftData=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0,  bool suiValsInsteadOfDefaultValsWherePossible=true);
    //
    //int ExtRow_SetAddInsDel_Arr2DNewCoordsToDataTypeN(int Action_Set1_Add2_Ins3_Del4_Dflt0, const Coords2DInt&coords, int ExtRowNN_0ifAll=-1, int givenRowL=0, TDataShiftParams*ShiftData=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0, bool suiValsInsteadOfDefaultValsWherePossible=true);
    //
    //
    //int ExtRow_SetAddInsDel_ThatCorrectedByNewData_FromArr2dNewToGivenRowPosN(int Action_Set1_Add2_Ins3_Del4_Dflt0, int InRowPosNN, int givenRowL=0, int ExtRowNN_0ifAll=-1, TDataShiftParams*DataShiftParam=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0, bool suiValsInsteadOfDefaultValsWherePossible=true);

    //int ExtRow_SetAddInsDel_ThatCorrectedByNewData_FromArr2dNewToOldRowPosN(int Action_Set1_Add2_Ins3_Del4_Dflt0, const Coords2DInt&coords, int givenRowL=0, int ExtRowNN_0ifAll=-1, TDataShiftParams*DataShiftParam=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0, bool suiValsInsteadOfDefaultValsWherePossible=true);

    //int ExtRow_SetAddInsDel_ThatCorrectedByNewData_FromArr2dNewToGivenRowPosN(int Action_Set1_Add2_Ins3_Del4_Dflt0, const Coords2DInt&coords, int givenRowL=0, int ExtRowNN_0ifAll=-1, TDataShiftParams*DataShiftParam=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0, bool suiValsInsteadOfDefaultValsWherePossible=true);

    //Coords2DInt ExtRow_SetAddInsDel_ThatCorrectedByNewData_CoordsFromArr2dNewToOld(int Action_Set1_Add2_Ins3_Del4_Dflt0, const Coords2DInt&coords, int givenRowL=0, int ExtRowNN_0ifAll=-1, TDataShiftParams*DataShiftParam=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0, bool suiValsInsteadOfDefaultValsWherePossible=true);

    //

    //void Set(std::vector<int>Ls, int ifNotRect_NonRect0_MakeRectBy_Min1Max2=0);
    ////int Set_GetExtNewRowLength(int* extRowsLengthes, int QExtRows, int ifNotRect_NonRect0_MakeRectBy_Min1Max2=0);//no need - 4 tgos: Lcur, Lold, Lmin, Lmax
    //int Set_Arr2DNewCoordsToDataTypeN(const Coords2DInt&coords, int* extRowsLengthes, int QExtRows=1, int ifNotRect_NonRect0_MakeRectBy_Min1Max2=0);
    //Coords2DInt Set_Arr2DNewToOldCoords(const Coords2DInt&coords, int* extRowsLengthes, int QExtRows=1, int ifNotRect_NonRect0_MakeRectBy_Min1Max2=0);
    //
    //
    //void Set(int* extRowsLengthes, int QExtRows=1, int ifNotRect_NonRect0_MakeRectBy_Min1Max2MinOfMax3MaxOfMax4=0, bool IfNotValsOfGivenRow_DefaultNotOwn=true);
    //
    //
    QString GetAsString();
    //
    //
};

class Array2DSize_V1D_VariaLength:public Array2DSize_Prototype{
    std::vector<int>rowsLs;
    //
  public:
    Array2DSize_V1D_VariaLength();
    Array2DSize_V1D_VariaLength(int QExtRows, int*RowsLs, int ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2);
    Array2DSize_V1D_VariaLength(int QExtRows, int RowsLs);
    Array2DSize_V1D_VariaLength(std::vector<int>Ls, int ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2);
    //virtual ~Array2DSize_Prototype();
    ~Array2DSize_V1D_VariaLength();
    //
    //std::vector<int> GetAsArrayOfExtRowsLengthes()const;  //new
    //
    //void construct();//SeNullIni is called
    virtual void SetNull();
    virtual void SetNullIni();
    virtual void SetOne();
    //
    virtual int GetTypeN()const;
    //
    virtual void Assign(Array2DSize_Prototype*obj);
    //
    virtual void Set(int* extRowsLengthes, int QExtRows=0, int ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2=0);
    virtual void Set(int QExtRows, int extRowsLength);
    // void Set(std::vector<int>Ls, int ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2=0);
    //
    virtual int GetQExtRows() const ;
    virtual int GetRowLength(int N=-1) const;
    virtual int GetRowLengthMin() const ;
    virtual int GetRowLengthMax() const ;
    //std::vector<int>GetLengthes() const;
    //std::vector<int>GetMinLengthRowNs() const;
    //std::vector<int>GetMaxLengthRowNs() const;
    //int GetQElements() const;
    //virtual Array2DSize_Prototype*GetSize_asPtr() const =0;
    //
    //int Arr2DBy1D_PosNByCoords(int ExtRowN, int IneRowN) const;
    //Coords2DInt Arr2DBy1D_CoordsByPosN(int PosN) const;
    ////int Arr2DBy1D_ExtRowNByPosN(int PosN) const;
    ////int Arr2DBy1D_IneRowNByPosN(int PosN) const;
    //
    //bool IsRectangularByType() const;
    //bool IsRectangularInFact() const;
   // //virtual bool IsEmpty() const;
    //bool IsEmpty() const;
    //
    //
    virtual void setExtRow_simplyAsDataGiven(int N=-1, int L=0, int ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4=0);
    virtual void addExtRow_simplyAsDataGiven(int L=0,           int ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4=0);
    virtual void insExtRow_simplyAsDataGiven(int N=-1, int L=0, int ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4=0);
    virtual void delExtRow_simplyAsDataGiven(int N=-1);
    virtual void set_or_ins_IneRow_simplyAsDataGiven(int Action_Set1_Ins2, int N=-1, int L=0, int ifL_NE_QER_Ignore0_MakeRactChangingBy_New1Old2Max3Min4=0, int ifLminLTN_ifAdd_N1_Lmax2_LmaxRest3_MakeRectAnyway_Lmax4_LmaxRest5=4);
    virtual void addIneRow_simplyAsDataGiven(int L=0, int ifL_NE_QER_Ignore0_MakeRactChangingBy_New1Old2Max3Min4=0, int ifNonRect_Ignore0AddToLast1StretchToMax2=0 );
    virtual void delIneRow_simplyAsDataGiven(int N=-1, int ifNGTLminIgnore0ShortenNurLongRows1=0);
    //
    //virtual void setIneRowLength_simplyAsDataGiven(int L, int N=-1, int ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4=0);
    //
    //int setIneRowLength_calcFinalL_simplyAsDataGiven(int L, int N=-1, int ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4=0);
    //
    //
    //TDataShiftResults  ExtRow_SetAddInsDel_dataNs(int Action_Set1_Add2_Ins3_Del4_Dflt0, int givenRowL=0, int inquiredRowNN=-1, int ChangedRowNN_0ifAll=-1, TDataShiftParams*DataShiftParam=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0, bool suiValsInsteadOfDefaultValsWherePossible=true);
    //int ExtRow_SetAddInsDel_ThatCorrectedByNewData_NewLength(int Action_Set1_Add2_Ins3_Del4_Dflt0, int givenRowL=0, int ExtRowNN_0ifAll=-1, TDataShiftParams*DataShiftParam=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0, bool suiValsInsteadOfDefaultValsWherePossible=true);

    //int ExtRow_SetAddInsDel_ThatCorrectedByNewData_PosInRowToDataTypeN(int Action_Set1_Add2_Ins3_Del4_Dflt0, int InRowPosNN, int givenRowL=0, int ExtRowNN_0ifAll=-1, TDataShiftParams*DataShiftParam=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0, bool suiValsInsteadOfDefaultValsWherePossible=true);
    //int ExtRow_SetAddInsDel_OldLengthOfExtRowN(int Action_Set1_Add2_Ins3_Del4_Dflt0, int inquiredRowNN, int ExtRowNN_0ifAll=-1, int givenRowL=0, TDataShiftParams*ShiftData=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0, bool suiValsInsteadOfDefaultValsWherePossible=true);
    //int ExtRow_SetAddInsDel_NewLengthOfExtRowN(int Action_Set1_Add2_Ins3_Del4_Dflt0, int inquiredRowNN, int ExtRowNN_0ifAll=-1, int givenRowL=0, TDataShiftParams*ShiftData=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0,  bool suiValsInsteadOfDefaultValsWherePossible=true);
    //
    //int ExtRow_SetAddInsDel_Arr2DNewCoordsToDataTypeN(int Action_Set1_Add2_Ins3_Del4_Dflt0, const Coords2DInt&coords, int ExtRowNN_0ifAll=-1, int givenRowL=0, TDataShiftParams*ShiftData=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0, bool suiValsInsteadOfDefaultValsWherePossible=true);
    //
    //
    //int ExtRow_SetAddInsDel_ThatCorrectedByNewData_FromArr2dNewToGivenRowPosN(int Action_Set1_Add2_Ins3_Del4_Dflt0, int InRowPosNN, int givenRowL=0, int ExtRowNN_0ifAll=-1, TDataShiftParams*DataShiftParam=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0, bool suiValsInsteadOfDefaultValsWherePossible=true);

    //int ExtRow_SetAddInsDel_ThatCorrectedByNewData_FromArr2dNewToOldRowPosN(int Action_Set1_Add2_Ins3_Del4_Dflt0, const Coords2DInt&coords, int givenRowL=0, int ExtRowNN_0ifAll=-1, TDataShiftParams*DataShiftParam=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0, bool suiValsInsteadOfDefaultValsWherePossible=true);

    //int ExtRow_SetAddInsDel_ThatCorrectedByNewData_FromArr2dNewToGivenRowPosN(int Action_Set1_Add2_Ins3_Del4_Dflt0, const Coords2DInt&coords, int givenRowL=0, int ExtRowNN_0ifAll=-1, TDataShiftParams*DataShiftParam=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0, bool suiValsInsteadOfDefaultValsWherePossible=true);

    //Coords2DInt ExtRow_SetAddInsDel_ThatCorrectedByNewData_CoordsFromArr2dNewToOld(int Action_Set1_Add2_Ins3_Del4_Dflt0, const Coords2DInt&coords, int givenRowL=0, int ExtRowNN_0ifAll=-1, TDataShiftParams*DataShiftParam=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0, bool suiValsInsteadOfDefaultValsWherePossible=true);

    //

    //void Set(std::vector<int>Ls, int ifNotRect_NonRect0_MakeRectBy_Min1Max2=0);
    ////int Set_GetExtNewRowLength(int* extRowsLengthes, int QExtRows, int ifNotRect_NonRect0_MakeRectBy_Min1Max2=0);//no need - 4 tgos: Lcur, Lold, Lmin, Lmax
    //int Set_Arr2DNewCoordsToDataTypeN(const Coords2DInt&coords, int* extRowsLengthes, int QExtRows=1, int ifNotRect_NonRect0_MakeRectBy_Min1Max2=0);
    //Coords2DInt Set_Arr2DNewToOldCoords(const Coords2DInt&coords, int* extRowsLengthes, int QExtRows=1, int ifNotRect_NonRect0_MakeRectBy_Min1Max2=0);;
    //
    //
    //void Set(int* extRowsLengthes, int QExtRows=1, int ifNotRect_NonRect0_MakeRectBy_Min1Max2MinOfMax3MaxOfMax4=0, bool IfNotValsOfGivenRow_DefaultNotOwn=true);
    //
    //
    //virtual QString GetAsStdString();
    //
    //
};

class Array2DSize_P_QERInner_VariaLength:public Array2DSize_Prototype{
    int QExtRows;
    int*rowsLs;
    //
  public:
    Array2DSize_P_QERInner_VariaLength();
    Array2DSize_P_QERInner_VariaLength(int QExtRows, int*RowsLs , int ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2=0);
    Array2DSize_P_QERInner_VariaLength(int QExtRows, int RowsLs);
    Array2DSize_P_QERInner_VariaLength(std::vector<int>Ls, int ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2=0);
    virtual ~Array2DSize_P_QERInner_VariaLength();
    //
    std::vector<int> GetAsArrayOfExtRowsLengthes()const;  //new
    //
    //void construct();//SeNullIni is called
    virtual void SetNull();
    virtual void SetNullIni();
    virtual void SetOne();
    //
    virtual int GetTypeN()const;
    //
    virtual void Assign(Array2DSize_Prototype*obj);
    //
    virtual void Set(int* extRowsLengthes=NULL, int QExtRows=0, int ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2=0);
    virtual void Set(int QExtRows, int extRowsLength);
    // void Set(std::vector<int>Ls, int ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2=0);
    //
    virtual int GetQExtRows() const;
    virtual int GetRowLength(int N=-1) const;
    virtual int GetRowLengthMin() const;
    virtual int GetRowLengthMax() const;
    //std::vector<int>GetLengthes() const;
    //std::vector<int>GetMinLengthRowNs() const;
    //std::vector<int>GetMaxLengthRowNs() const;
    //int GetQElements() const;
    //virtual Array2DSize_Prototype*GetSize_asPtr() const =0;
    //
    //int Arr2DBy1D_PosNByCoords(int ExtRowN, int IneRowN) const;
    //Coords2DInt Arr2DBy1D_CoordsByPosN(int PosN) const;
    //int Arr2DBy1D_ExtRowNByPosN(int PosN) const;
    //int Arr2DBy1D_IneRowNByPosN(int PosN) const;
    //
    // bool IsRectangularByType() const;
    // bool IsRectangularInFact() const;
    ////virtual bool IsEmpty() const;
    //bool IsEmpty() const;
    //virtual int GetTypeN() const =0;
    //
    //virtual void SetQExtRows(int Q, int IfNotRect_ERL_ByMin1ByMax2ByLast3);//V ha add, ins et del fns, mab to fn ns'nod?
    //void SetExtRowLength(int L, int NN_0ifAll=0, TDataShiftParams*ShiftData=NULL, int ifWasRectAndNotEqual_IgnoreAndLeaveByOld0_SetRectBy_New1_Max2_Min3_TransformToNonRectLTZero=1);
    //
    //
    virtual void setExtRow_simplyAsDataGiven(int N=-1, int L=0, int ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4=0);
    virtual void addExtRow_simplyAsDataGiven(int L=0,           int ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4=0);
    virtual void insExtRow_simplyAsDataGiven(int N=-1, int L=0, int ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4=0);
    virtual void delExtRow_simplyAsDataGiven(int N=-1);
    virtual void set_or_ins_IneRow_simplyAsDataGiven(int Action_Set1_Ins2, int N=-1, int L=0, int ifL_NE_QER_Ignore0_MakeRactChangingBy_New1Old2Max3Min4=0, int ifLminLTN_ifAdd_N1_Lmax2_LmaxRest3_MakeRectAnyway_Lmax4_LmaxRest5=4);
    virtual void addIneRow_simplyAsDataGiven(int L=0, int ifL_NE_QER_Ignore0_MakeRactChangingBy_New1Old2Max3Min4=0, int ifNonRect_Ignore0AddToLast1StretchToMax2=0 );
    virtual void delIneRow_simplyAsDataGiven(int N=-1, int ifNGTLminIgnore0ShortenNurLongRows1=0);
    //
    //
    //void Set(int* extRowsLengthes, int QExtRows=1, int ifNotRect_NonRect0_MakeRectBy_Min1Max2MinOfMax3MaxOfMax4=0, bool IfNotValsOfGivenRow_DefaultNotOwn=true);
    //
    //
    //virtual QString GetAsStdString();
    //
    //
};

class Array2DSize_P1D_NoQEIn_VariaLength:public Array2DSize_Prototype{
    int*RowsLs;
    //
  public:
    Array2DSize_P1D_NoQEIn_VariaLength();
    Array2DSize_P1D_NoQEIn_VariaLength(int QExtRows, int*RowsLs, int ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2=0);
    Array2DSize_P1D_NoQEIn_VariaLength(int QExtRows, int RowsLs);
    Array2DSize_P1D_NoQEIn_VariaLength(std::vector<int>Ls , int ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2=0);
    virtual ~Array2DSize_P1D_NoQEIn_VariaLength();
    //
    //std::vector<int> GetAsArrayOfExtRowsLengthes()const;  //new
    //
    //void construct();//SeNullIni is called
    virtual void SetNull();
    virtual void SetNullIni();
    virtual void SetOne();
    //
    virtual int GetTypeN()const;
    //
    virtual void Assign(Array2DSize_Prototype*obj);
    //
    virtual void Set(int* extRowsLengthes=NULL, int QExtRows=0, int ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2=0);
    virtual void Set(int QExtRows, int extRowsLength);
    //virtual void Set(std::vector<int>Ls, int ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2=0);
    //
    virtual int GetQExtRows(int QE=0) const;
    virtual int GetRowLength(int N=-1, int QE=0) const;
    virtual int GetRowLengthMin() const;
    virtual int GetRowLengthMax() const;
    //std::vector<int>GetLengthes(int QE=0) const;
    //std::vector<int>GetMinLengthRowNs(int QE=0) const;
    //std::vector<int>GetMaxLengthRowNs(int QE=0) const;
    //int GetQElements(int QE=0) const;
    //virtual Array2DSize_Prototype*GetSize_asPtr() const =0;
    //
    //int Arr2DBy1D_PosNByCoords(int ExtRowN, int IneRowN, int QE=0) const;
    //Coords2DInt Arr2DBy1D_CoordsByPosN(int PosN, int QE=0) const;
    //int Arr2DBy1D_ExtRowNByPosN(int PosN) const;
    //int Arr2DBy1D_IneRowNByPosN(int PosN) const;
    //
    // bool IsRectangularByType() const;
    // bool IsRectangularInFact(int QE=0) const;
    // bool IsEmpty(int QE=0) const =0;
    //virtual int GetTypeN() const =0;
    //
    //virtual void SetQExtRows(int Q, int IfNotRect_ERL_ByMin1ByMax2ByLast3);//V ha add, ins et del fns, mab to fn ns'nod?
    //
    //
    //
    // void SetExtRowLength(int L, int NN_0ifAll=0, TDataShiftParams*ShiftData=NULL, int ifWasRectAndNotEqual_IgnoreAndLeaveByOld0_SetRectBy_New1_Max2_Min3_TransformToNonRectLTZero=1);
    //
    //
    virtual void setExtRow_simplyAsDataGiven(int N=-1, int L=0, int ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4=0);
    virtual void addExtRow_simplyAsDataGiven(int L=0,           int ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4=0);
    virtual void insExtRow_simplyAsDataGiven(int N=-1, int L=0, int ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4=0);
    virtual void delExtRow_simplyAsDataGiven(int N=-1);
    virtual void set_or_ins_IneRow_simplyAsDataGiven(int Action_Set1_Ins2, int N=-1, int L=0, int ifL_NE_QER_Ignore0_MakeRactChangingBy_New1Old2Max3Min4=0, int ifLminLTN_ifAdd_N1_Lmax2_LmaxRest3_MakeRectAnyway_Lmax4_LmaxRest5=4);
    virtual void addIneRow_simplyAsDataGiven(int L=0, int ifL_NE_QER_Ignore0_MakeRactChangingBy_New1Old2Max3Min4=0, int ifNonRect_Ignore0AddToLast1StretchToMax2=0 );
    virtual void delIneRow_simplyAsDataGiven(int N=-1, int ifNGTLminIgnore0ShortenNurLongRows1=0);
    //
    //
    void Set(int* extRowsLengthes, int QExtRows=1, int ifNotRect_NonRect0_MakeRectBy_Min1Max2MinOfMax3MaxOfMax4=0, bool IfNotValsOfGivenRow_DefaultNotOwn=true);
    //
    //
    //virtual QString GetAsStdString();
    //
    //
};



class Array2DSize{
    Array2DSize_Prototype*data;
  public:
    Array2DSize(int QExtRows=0, int ExtRowLength=0, int TypeN=Arr2DSize_Default);
    Array2DSize(int*ExtRowsLengthes, int QExtRows, int TypeN=Arr2DSize_Default);
    Array2DSize(std::vector<int>Ls, int TypeN=Arr2DSize_Default);
    Array2DSize(const Array2DSize&obj);
    ~Array2DSize();
    void Assign(const Array2DSize&obj);

    Array2DSize operator = (const Array2DSize&obj);
   //
    std::vector<int> GetAsArrayOfExtRowsLengthes()const;  //new
    //
    void construct(int TypeN=Arr2DSize_Default);//SeNullIni is called
    void SetNull();
    void SetNullIni();
    void SetOne();
    //
    int GetTypeN()const;
    void SetTypeN(int TypeN);
    //
    void Assign(Array2DSize_Prototype*obj);
    //
    void Set(int* extRowsLengthes, int QExtRows=0, int ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2=0, int TypeN=Arr2DSize_Default);
    void Set(int QExtRows, int extRowsLength, int TypeN=Arr2DSize_Default);
    void Set(std::vector<int>Ls, int ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2=0, int TypeN=Arr2DSize_Default);
    //
    int GetQExtRows() const ;
    int GetRowLength(int N=-1) const ;
    int GetRowLengthMin() const ;
    int GetRowLengthMax() const ;
    std::vector<int>GetLengthes() const;
    std::vector<int>GetMinLengthRowNs() const;
    std::vector<int>GetMaxLengthRowNs() const;
    int GetQElements() const;
    //virtual Array2DSize_Prototype*GetSize_asPtr() const =0;
    //
    int Arr2DBy1D_PosNByCoords(int ExtRowN, int IneRowN) const;
    Coords2DInt Arr2DBy1D_CoordsByPosN(int PosN) const;
    //int Arr2DBy1D_ExtRowNByPosN(int PosN) const;
    //int Arr2DBy1D_IneRowNByPosN(int PosN) const;
    //
    bool IsRectangularByType() const;
    bool IsRectangularInFact() const;
    bool IsEmpty() const ;
    int GetIneRowLength(int N=-1, bool countWhole=false) const;
    //
    //
    //
    void setExtRow_simplyAsDataGiven(int N=-1, int L=0, int ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4=0);
    void addExtRow_simplyAsDataGiven(int L=0,           int ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4=0);
    void insExtRow_simplyAsDataGiven(int N=-1, int L=0, int ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4=0);
    void delExtRow_simplyAsDataGiven(int N=-1);
    void set_or_ins_IneRow_simplyAsDataGiven(int Action_Set1_Ins2, int N=-1, int L=0, int ifL_NE_QER_Ignore0_MakeRactChangingBy_New1Old2Max3Min4=0, int ifLminLTN_ifAdd_N1_Lmax2_LmaxRest3_MakeRectAnyway_Lmax4_LmaxRest5=4);
    void addIneRow_simplyAsDataGiven(int L=0, int ifL_NE_QER_Ignore0_MakeRactChangingBy_New1Old2Max3Min4=0, int ifNonRect_Ignore0AddToLast1StretchToMax2=0 );
    void delIneRow_simplyAsDataGiven(int N=-1, int ifNGTLminIgnore0ShortenNurLongRows1=0);
    //
    //
    int setIneRow_calcFinalL_simplyAsDataGiven(int L, int N=-1, int ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4=0);
    //
    //
    // ---------------------------------------------------------------------------------------------------

    void set_or_ins_ExtRow_simplyAsDataGiven_HilfsFun(int Action_Set1_Ins3, int ERNNGiven_0IfAll, const Coords2DInt&CoordsNew, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn, int&ERLNew, int&QExtRowsNew, int&DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0, int&InGivenRowPosN, Coords2DInt&CoordsOld);

    int set_or_ins_ExtRow_simplyAsDataGiven_QExtRowsNew(int Action_Set1_Ins3, int ERNNGiven_0IfAll, const Coords2DInt&CoordsNew, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn);
    int set_or_ins_ExtRow_simplyAsDataGiven_ExtRowLengthNew(int Action_Set1_Ins3, int ERNNGiven_0IfAll, const Coords2DInt&CoordsNew, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn);
    int set_or_ins_ExtRow_simplyAsDataGiven_DataTypeN(int Action_Set1_Ins3, int ERNNGiven_0IfAll, const Coords2DInt&CoordsNew, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn);
    int set_or_ins_ExtRow_simplyAsDataGiven_InGivenRowPosN(int Action_Set1_Ins3, int ERNNGiven_0IfAll, const Coords2DInt&CoordsNew, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn);
    Coords2DInt set_or_ins_ExtRow_simplyAsDataGiven_Arr2DNewToOldPosN(int Action_Set1_Ins3, int ERNNGiven_0IfAll, const Coords2DInt&CoordsNew, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn);

    void set_or_ins_ExtRow_simplyAsDataGiven_HilfsFun_v1(std::vector<int>&RowsLs, std::vector<Coords2DInt>&DataSources, int Action_Set1_Ins3, int ERNNGiven_0IfAll, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn);

    Arr2D_ResizeParams set_or_ins_ExtRow_simplyAsDataGiven_NewReSize(int Action_Set1_Ins3, int ERNNGiven_0IfAll, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn);

    Array2DSize set_or_ins_ExtRow_simplyAsDataGiven_NewSize(int Action_Set1_Ins3, int ERNNGiven_0IfAll, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn);

    //--------------------------------------------------------------------------------------------------

    void addExtRow_simplyAsDataGiven_HilfsFun(const Coords2DInt&CoordsNew, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn, int&ERLNew, int&QExtRowsNew, int&DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0, int&InGivenRowPosN, Coords2DInt&CoordsOld);

    int addExtRow_simplyAsDataGiven_QExtRowsNew(const Coords2DInt&CoordsNew, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn);
    int addExtRow_simplyAsDataGiven_ExtRowLengthNew(const Coords2DInt&CoordsNew, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn);
    int addExtRow_simplyAsDataGiven_DataType(const Coords2DInt&CoordsNew, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn);
    int addExtRow_simplyAsDataGiven_InGivenRowPosNN(const Coords2DInt&CoordsNew, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn);
    Coords2DInt addExtRow_simplyAsDataGiven_Arr2DCoordsNewToOld(const Coords2DInt&CoordsNew, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn);

    void addExtRow_simplyAsDataGiven_HilfsFun_v1(std::vector<int>Ls, std::vector<Coords2DInt>&DataSources, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn);

    Arr2D_ResizeParams addExtRow_simplyAsDataGiven_NewReSize(int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn);

    Array2DSize addExtRow_simplyAsDataGiven_NewSize(int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn);

    //--------------------------------------------------------------------------------------------------

    void delExtRow_HilfsFun(const Coords2DInt&CoordsNew, int ExtRowToDelNN, int&ERLNew, int&QExtRowsNew,  Coords2DInt&CoordsOld);

    int delExtRow_ExtRowNewLengthNew(const Coords2DInt&CoordsNew, int ExtRowToDelNN);
    int delExtRow_QExtRowsNew(const Coords2DInt&CoordsNew, int ExtRowToDelNN);
    Coords2DInt delExtRow_Arr2DCoordsNewToOld(const Coords2DInt&CoordsNew, int ExtRowToDelNN);

    void delExtRow_HilfsFun_v1(std::vector<int>Ls, std::vector<Coords2DInt>&DataSources, int ExtRowToDelNN);

    Arr2D_ResizeParams delExtRow_NewReSize(int ExtRowToDelNN);

    Array2DSize delExtRow_NewSize(int ExtRowToDelNN);

    //--------------------------------------------------------------------------------------------------

    void delIneRow_HilfsFun(const Coords2DInt&CoordsNew, int IneRowToDelNN, int ifN_GT_Lmin_CutLongOnly1_Ignore0, int&QExtRowsNew, int&ERLNew, Coords2DInt&CoordsOld);

    int delIneRow_ExtRowNewLength(const Coords2DInt&CoordsNew, int IneRowToDelNN, int ifN_GT_Lmin_CutLongOnly1_Ignore0);
    int delIneRow_QExtRowsNew(const Coords2DInt&CoordsNew, int IneRowToDelNN, int ifN_GT_Lmin_CutLongOnly1_Ignore0);
    Coords2DInt delIneRow_Arr2DCoordsNewToOld(const Coords2DInt&CoordsNew, int IneRowToDelNN, int ifN_GT_Lmin_CutLongOnly1_Ignore0);

    void delIneRow_HilfsFun_v1(std::vector<int>Ls, std::vector<Coords2DInt>&DataSources, const Coords2DInt&CoordsNew, int IneRowToDelNN, int ifN_GT_Lmin_CutLongOnly1_Ignore0);

    Arr2D_ResizeParams delIneRow_NewReSize( int IneRowToDelNN, int ifN_GT_Lmin_CutLongOnly1_Ignore0);

    Array2DSize delIneRow_NewSize(int IneRowToDelNN, int ifN_GT_Lmin_CutLongOnly1_Ignore0);

    //--------------------------------------------------------------------------------------------------

    void addIneRow_simplyAsDataGiven_HilfsFun(const Coords2DInt&CoordsNew, int givenL, int ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4, int ifNonRect_AddToLast1StretchToMax2Ignore0, int&DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0, int&QExtRowsNew, int&ERLNew, int&InGivenRowPosN,Coords2DInt&CoordsOld);

    int addIneRow_simplyAsDataGiven_NewExtRowLength(const Coords2DInt&CoordsNew, int givenL, int ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4, int ifNonRect_AddToLast1StretchToMax2Ignore0);
    int addIneRow_simplyAsDataGiven_QExtRowsNew(const Coords2DInt&CoordsNew, int givenL, int ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4, int ifNonRect_AddToLast1StretchToMax2Ignore0);
    int addIneRow_simplyAsDataGiven_DataTypeN(const Coords2DInt&CoordsNew, int givenL, int ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4, int ifNonRect_AddToLast1StretchToMax2Ignore0);
    Coords2DInt addIneRow_simplyAsDataGiven_Arr2DCoordsNewToOld(const Coords2DInt&CoordsNew, int givenL, int ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4, int ifNonRect_AddToLast1StretchToMax2Ignore0);

    void addIneRow_simplyAsDataGiven_HilfsFun_v1(std::vector<int>Ls, std::vector<Coords2DInt>&DataSources, int givenL, int ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4, int ifNonRect_AddToLast1StretchToMax2Ignore0);

    Arr2D_ResizeParams addIneRow_simplyAsDataGiven_NewReSize(int givenL, int ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4, int ifNonRect_AddToLast1StretchToMax2Ignore0);

    Array2DSize addIneRow_simplyAsDataGiven_NewSize(int givenL, int ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4, int ifNonRect_AddToLast1StretchToMax2Ignore0);

    //--------------------------------------------------------------------------------------------------

    void set_or_ins_IneRow_simplyAsDataGiven_HilfsFun(int Action_Set1_Ins3, const Coords2DInt&CoordsNew, int ToOperateIneRowNN_0ifAll, int givenL, int ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4, int if_Lmin_LT_N_Ignore0_ModifyLongOnly1_StretchTo_N2_Max3, int&DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0, int&QExtRowsNew, int&ERLNew, int&InGivenRowPosN,Coords2DInt&CoordsOld);

    int set_or_ins_IneRow_simplyAsDataGiven_QExtRows(int Action_Set1_Ins3, const Coords2DInt&CoordsNew, int ToOperateIneRowNN_0ifAll, int givenL, int ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4, int if_Lmin_LT_N_Ignore0_ModifyLongOnly1_StretchTo_N2_Max3);
    int set_or_ins_IneRow_simplyAsDataGiven_ExtRowL(int Action_Set1_Ins3, int InquiredExtRowNN, int ToOperateIneRowNN_0ifAll, int givenL, int ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4, int if_Lmin_LT_N_Ignore0_ModifyLongOnly1_StretchTo_N2_Max3);
    int set_or_ins_IneRow_simplyAsDataGiven_Arr2DNewCoordsToDataTypeN(int Action_Set1_Ins3, const Coords2DInt&CoordsNew, int ToOperateIneRowNN_0ifAll, int givenL, int ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4, int if_Lmin_LT_N_Ignore0_ModifyLongOnly1_StretchTo_N2_Max3);
    Coords2DInt set_or_ins_IneRow_simplyAsDataGiven_Arr2DNewCoordsNewToOld(int Action_Set1_Ins3, const Coords2DInt&CoordsNew, int ToOperateIneRowNN_0ifAll, int givenL, int ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4, int if_Lmin_LT_N_Ignore0_ModifyLongOnly1_StretchTo_N2_Max3);

    void set_or_ins_IneRow_simplyAsDataGiven_HilfsFun_v1(std::vector<int>Ls, std::vector<Coords2DInt>&DataSources, int Action_Set1_Ins3, int ToOperateIneRowNN_0ifAll, int givenL, int ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4, int if_Lmin_LT_N_Ignore0_ModifyLongOnly1_StretchTo_N2_Max3);

    Arr2D_ResizeParams set_or_ins_IneRow_simplyAsDataGiven_NewReSize(int Action_Set1_Ins3, int ToOperateIneRowNN_0ifAll, int givenL, int ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4, int if_Lmin_LT_N_Ignore0_ModifyLongOnly1_StretchTo_N2_Max3);

    Array2DSize set_or_ins_IneRow_simplyAsDataGiven_NewSize(int Action_Set1_Ins3, int ToOperateIneRowNN_0ifAll, int givenL, int ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4, int if_Lmin_LT_N_Ignore0_ModifyLongOnly1_StretchTo_N2_Max3);
    //
    //------------------------------------------------------------------------------------------------------
    //
    void Set_simplyAsDataGiven_HilfsFun2(int&QExtRowsNew, int&ERLNew, int&DataTypeN_Arr2DVals1_GivenVals2_Default3_Incorrect0, Coords2DInt&CoordsOld, int* extRowsLengthes, int QExtRowsGiven, int ifNotRect_NonRect0_MakeRectBy_Min1Max2MinOfMax3MaxOfMax4, bool IfNotValsOfGivenRow_DefaultNotOwn);

    int Set_simplyAsDataGiven_QExtRows2( int* extRowsLengthes, int QExtRowsGiven, int ifNotRect_NonRect0_MakeRectBy_Min1Max2MinOfMax3MaxOfMax4, bool IfNotValsOfGivenRow_DefaultNotOwn);
    int Set_simplyAsDataGiven_ExtRowNewLength2(int ExtRowNewNN,  int* extRowsLengthes, int QExtRowsGiven, int ifNotRect_NonRect0_MakeRectBy_Min1Max2MinOfMax3MaxOfMax4, bool IfNotValsOfGivenRow_DefaultNotOwn);
    int Set_simplyAsDataGiven_Arr2DCoordsNewToDataTypeN2(const Coords2DInt&CoordsNew, int* extRowsLengthes, int QExtRowsGiven, int ifNotRect_NonRect0_MakeRectBy_Min1Max2MinOfMax3MaxOfMax4, bool IfNotValsOfGivenRow_DefaultNotOwn);
    Coords2DInt Set_simplyAsDataGiven_Arr2DCoordsNewToOld2(const Coords2DInt&CoordsNew, int* extRowsLengthes, int QExtRowsGiven, int ifNotRect_NonRect0_MakeRectBy_Min1Max2MinOfMax3MaxOfMax4, bool IfNotValsOfGivenRow_DefaultNotOwn);

    void Set_simplyAsDataGiven_HilfsFun_v12(std::vector<int>&RowsLs, std::vector<Coords2DInt>&DataSources, int* extRowsLengthes, int QExtRows, int ifNotRect_NonRect0_MakeRectBy_Min1Max2, bool IfNotValsOfGivenRow_DefaultNotOwn);

    Arr2D_ResizeParams Set_simplyAsDataGiven_NewReSize2(int* extRowsLengthes, int QExtRows, int ifNotRect_NonRect0_MakeRectBy_Min1Max2, bool IfNotValsOfGivenRow_DefaultNotOwn);

    Array2DSize Set_simplyAsDataGiven_NewSize2(int* extRowsLengthes, int QExtRows, int ifNotRect_NonRect0_MakeRectBy_Min1Max2, bool IfNotValsOfGivenRow_DefaultNotOwn);
    //
    //--------------------------------------------------------------------------------------------------------
    //
    void Set_simplyAsDataGiven_HilfsFun(int&QExtRowsNew, int&ERLNew, int&DataTypeN_Arr2DVals1_GivenVals2_Default3_Incorrect0, Coords2DInt&CoordsOld, const Coords2DInt&CoordsNew, int* extRowsLengthes, int QExtRowsGiven, int ifNotRect_NonRect0_MakeRectBy_Min1Max2);
    int Set_simplyAsDataGiven_QExtRows(int* extRowsLengthes, int QExtRowsGiven, int ifNotRect_NonRect0_MakeRectBy_Min1Max2);
    int Set_simplyAsDataGiven_ExtRowNewLength(int ExtRowNewNN,  int* extRowsLengthes, int QExtRowsGiven, int ifNotRect_NonRect0_MakeRectBy_Min1Max2);
    int Set_simplyAsDataGiven_Arr2DCoordsNewToDataTypeN(const Coords2DInt&CoordsNew, int* extRowsLengthes, int QExtRowsGiven, int ifNotRect_NonRect0_MakeRectBy_Min1Max2);
    Coords2DInt Set_simplyAsDataGiven_Arr2DCoordsNewToOld(const Coords2DInt&CoordsNew, int* extRowsLengthes, int QExtRowsGiven, int ifNotRect_NonRect0_MakeRectBy_Min1Max2);
    Arr2D_ResizeParams Set_simplyAsDataGiven_NewReSize(int* extRowsLengthes, int QExtRows, int ifNotRect_NonRect0_MakeRectBy_Min1Max2);
    Array2DSize Set_simplyAsDataGiven_NewSize(int* extRowsLengthes, int QExtRows, int ifNotRect_NonRect0_MakeRectBy_Min1Max2);
    //
    //---------------------------------------------------------------------------------------------------------
    //
    TDataShiftResults  ExtRow_SetAddInsDel_dataNs(int Action_Set1_Add2_Ins3_Del4_Dflt0, int givenRowL=0, /*int inquiredRowNN=-1,*/ int ChangedRowNN_0ifAll=-1, TDataShiftParams*DataShiftParam=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0, bool suiValsInsteadOfDefaultValsWherePossible=true);
    int ExtRow_SetAddInsDel_ThatCorrectedByNewData_NewLength(int Action_Set1_Add2_Ins3_Del4_Dflt0, int givenRowL=0, int ExtRowNN_0ifAll=-1, TDataShiftParams*DataShiftParam=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0, bool suiValsInsteadOfDefaultValsWherePossible=true);

    int ExtRow_SetAddInsDel_ThatCorrectedByNewData_PosInRowToDataTypeN(int Action_Set1_Add2_Ins3_Del4_Dflt0, int InRowPosNN, int givenRowL=0, int ExtRowNN_0ifAll=-1, TDataShiftParams*DataShiftParam=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0, bool suiValsInsteadOfDefaultValsWherePossible=true);
    int ExtRow_SetAddInsDel_OldLengthOfExtRowN(int Action_Set1_Add2_Ins3_Del4_Dflt0, int inquiredRowNN, int ExtRowNN_0ifAll=-1, int givenRowL=0, TDataShiftParams*ShiftData=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0, bool suiValsInsteadOfDefaultValsWherePossible=true);
    int ExtRow_SetAddInsDel_NewLengthOfExtRowN(int Action_Set1_Add2_Ins3_Del4_Dflt0, int inquiredRowNN, int ExtRowNN_0ifAll=-1, int givenRowL=0, TDataShiftParams*ShiftData=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0,  bool suiValsInsteadOfDefaultValsWherePossible=true);
    //
    int ExtRow_SetAddInsDel_Arr2DNewCoordsToDataTypeN(int Action_Set1_Add2_Ins3_Del4_Dflt0, const Coords2DInt&coords, int ExtRowNN_0ifAll=-1, int givenRowL=0, TDataShiftParams*ShiftData=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0, bool suiValsInsteadOfDefaultValsWherePossible=true);
    //
    //
    int ExtRow_SetAddInsDel_ThatCorrectedByNewData_FromArr2dNewToGivenRowPosN(int Action_Set1_Add2_Ins3_Del4_Dflt0, int InRowPosNN, int givenRowL=0, int ChangedRowNN_0ifAll=-1, TDataShiftParams*DataShiftParam=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0, bool suiValsInsteadOfDefaultValsWherePossible=true);

    int ExtRow_SetAddInsDel_ThatCorrectedByNewData_FromArr2dNewToOldRowPosN(int Action_Set1_Add2_Ins3_Del4_Dflt0, int InRowNN, /*const Coords2DInt&coords,*/ int givenRowL=0, int ExtRowNN_0ifAll=-1, TDataShiftParams*DataShiftParam=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0, bool suiValsInsteadOfDefaultValsWherePossible=true);

    Coords2DInt ExtRow_SetAddInsDel_ThatCorrectedByNewData_CoordsFromArr2dNewToOld(int Action_Set1_Add2_Ins3_Del4_Dflt0, const Coords2DInt&coords, int givenRowL=0, int ExtRowNN_0ifAll=-1, TDataShiftParams*DataShiftParam=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0, bool suiValsInsteadOfDefaultValsWherePossible=true);
    //
    //
    //void Set(int* extRowsLengthes, int QExtRows=1, int ifNotRect_NonRect0_MakeRectBy_Min1Max2MinOfMax3MaxOfMax4=0, bool IfNotValsOfGivenRow_DefaultNotOwn=true);
    //
    //
    QString GetAsString();
    //
    //
};





// === wa Arr2D size, wi Arr2D classes ==============================================

template <class T> class Array2DElement{
  public:
    Coords2DInt position;
    T val;
    Array2DElement();
    Array2DElement(T data, const Coords2DInt& coords);
    Array2DElement(T data, int n1, int n2);
    void set(T data, const Coords2DInt& coords);
    void set(T data, int n1, int n2);
    ~Array2DElement();
};

template<typename T> Array2DElement<T>::Array2DElement(){}
template<typename T> Array2DElement<T>::Array2DElement(T data, const Coords2DInt& coords){
    this->set(data, coords);
}
template<typename T> Array2DElement<T>::Array2DElement(T data, int n1, int n2){
    this->set(data, n1, n2);
}
template<typename T> Array2DElement<T>::~Array2DElement(){}
template<typename T> void Array2DElement<T>::set(T data, const Coords2DInt& coords){
    this->data=data;
    this->coords=coords;
}
template<typename T> void Array2DElement<T>::set(T data, int n1, int n2){
    this->data=data;
    this->coords.set(n1, n2);
}

// === wa Arr2D classes, wi Arr2D ipse ==============================================




//-----------------------------------------------------------------------




//template<typename T> void Array2D_Shell_1<T>::SetExtRow(T*row, const T& DefaultVal, int givenRowL, int NN_0ifAll, int FirstN, int QDefaultsBefore, int Lreq, int ifWasRectAndNotEqual_IgnoreAndLeaveByOld0_SetRectBy_New1_Max2_Min3_TransformToNonRectLTZero){
//
//}


#endif // ARRAY1D_SIZE2D_ELEM2D_1_H


