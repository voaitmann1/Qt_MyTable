#ifndef ARRAY1D_SIZE2D_H
#define ARRAY1D_SIZE2D_H

#include"mylib.h"


//class Array1D_Size2D
//{
//public:
//    Array1D_Size2D();
//};

const int Array2DSize_Rectangular_TypeN=0;
const int Array2DSize_VariaLength_TypeN=1;
//const int Array2DSize_VariaLength_StdVector_TypeN=1;
//const int Array2DSize_VariaLength_IntPtr_TypeN=2;
const int Array2DSize_Default_TypeN=Array2DSize_Rectangular_TypeN;

const int Array2D_By1D_LC_Ptr_TypeN=0;
const int Array2D_By1D_LC_stdVectSafe_Rect_TypeN=1;
const int Array2D_By1D_LC_Rare_TypeN=3;
//const int Array2D_Default_TypeN=Array2DSize_Rectangular_TypeN;


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
            N_AllIf0=NInArrIfNegative(N_AllIf0, Q);
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
        //delete[]Y;Y=NULL; !x is pointing to it!
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
    //Q3=Z.size();//
    //QR=Q1+Q3;
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
    //delete[]x1nw;
    //x1nw=NULL;
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
/*template<typename T> std::vector<T> Arr1D_ConcatAdding(std::vector<T>&x1, int Q1, T*x2, int Q2, TDataShiftParams*dsp=NULL, T*dfltVal=NULL){//vrn for vect
    T DefaultVal;
    TDataShiftParams DataShiftParams;
    if(dsp!=NULL){
        DataShiftParams=(*(dsp));
    }
    std::vector<T> Z= Arr1D_GetSubArr_ByLs(x2, Q2, DefaultVal, DataShiftParams);
    int Q3=Z.size();
    if(dfltVal!=NULL){
        DefaultVal=(*(dfltVal));
    }
    Arr1D_ConcatAdding(x1,  x2, Q2, DefaultVal, DataShiftParams);
}*/

//=== wa Arr1D, wi: Arr2D info =================================

const int DEFAULT_SIZE=0;//1;

const int Arr2DSize_Rect_TypeN=10;
const int Arr2DSize_VarLens_V_TypeN=21;
const int Arr2DSize_VarLens_P_TypeN=22;

class Array2DSize_Prototype{
    public:
    virtual ~Array2DSize_Prototype()=0;//in .cpp it is described, though empty
    //
    virtual Array2DSize_Prototype* GetCopy()=0; //new
    std::vector<int> GetAsArrayOfExtRowsLengthes()const;  //new
    //
    void construct();//SeNullIni is called
    virtual void SetNull()=0;
    virtual void SetNullIni()=0;
    virtual void SetOne()=0;
    //
    virtual int GetTypeN()=0;
    //
    virtual void Assign(Array2DSize_Prototype*obj)=0;
    //
    virtual void Set(int* extRowsLengthes=NULL, int QExtRows=0)=0;
    virtual void Set(int extRowsLength=0, int QExtRows=0)=0;//may descr it generally or may leave it virtual
    virtual void Set(std::vector<int>Ls)=0;
    //
    virtual int GetQExtRows() const =0;
    virtual int GetRowLength(int N=-1) const =0;
    virtual int GetRowLengthMin() const =0;
    virtual int GetRowLengthMax() const =0;
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
    virtual bool IsRectangularByType() const =0;
    virtual bool IsRectangularInFact() const =0;
    virtual bool IsEmpty() const =0;
    //virtual int GetTypeN() const =0;
    //
    virtual int SetRowLength(int L, int N=0, int ifNotEqual_Ignore0Old1New2Max3Min4=1)=0;
    virtual int SetQExtRows(int Q, int IfNotRect_ERL_ByMin1ByMax2ByLast3)=0;
    //
    virtual void SetExtRow(int RowN, int L=0, TDataShiftParams*DataShiftParams=NULL, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1)=0;
    //
    virtual Coords2DInt SetExtRow_CoordsByElementN(int ElementN, int RowN, int L=0, TDataShiftParams*DataShiftParams=NULL, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1)=0;//, Array2DSize_Prototype*sizeIni=NULL, int QERIni=0)=0;
    //virtual ob setting row depends on 2D arr type
    //
    virtual void AddExtRow(         int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL)=0;
    //
    virtual Coords2DInt AddExtRow_CoordsByElementN(int ElementN,       int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL)=0;
    virtual int AddExtRow_ElementNByCoords(const Coords2DInt& coords,  int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL)=0;
    //
    virtual void InsExtRow(int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL)=0;
    //
    virtual Coords2DInt InsExtRow_CoordsByElementN(    int ElementN,        int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL)=0;
    virtual int InsExtRow_ElementNByCoords(      const Coords2DInt& coords, int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL)=0;
    virtual Coords2DInt InsExtRow_CoordsOldByNew(const Coords2DInt& coords, int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL)=0;
    virtual Coords2DInt InsExtRow_CoordsNewByOld(const Coords2DInt& coords, int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL)=0;
    //
    virtual void DelExtRow(int N=-1)=0;
    //
    //Coords2DInt DelExtRow_CoordsOldByNew(const Coords2DInt& coords, int N=-1);//no need
    //Coords2DInt DelExtRow_CoordsNewByOld(const Coords2DInt& coords, int N=-1);//no need
    //
    virtual void AddIneRow(int L=0, int IfNotSameQER_ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL)=0;
    //
    virtual Coords2DInt AddIneRow_CoordsByElementN(int ElementN,      int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL);
    virtual int AddIneRow_ElementNByCoords(const Coords2DInt& coords, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL);
    //
    virtual void InsIneRow(int N=0, int L=0, int IfNotSameQER_ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL)=0;
    //
    virtual Coords2DInt InsIneRow_CoordsByElementN(    int ElementN,        int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1)=0;
    virtual int InsIneRow_ElementNByCoords(      const Coords2DInt& coords, int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1)=0;
    virtual Coords2DInt InsIneRow_CoordsOldByNew(const Coords2DInt& coords, int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1)=0;
    virtual Coords2DInt InsIneRow_CoordsNewByOld(const Coords2DInt& coords, int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1)=0;
    //
    virtual void DelIneRow(int N=-1)=0;
    //
    //Coords2DInt DelIneRow_CoordsOldByNew(const Coords2DInt& coords, int N=-1);//no need
    //Coords2DInt DelIneRow_CoordsNewByOld(const Coords2DInt& coords, int N=-1);//no need
    //
    //
    virtual void AddOrInsToExtRowN(int N=-1)=0;
    virtual void DelFromExtRowN(int N=-1)=0;
    //
    virtual void SwapExtRows(int N1, int N2)=0;
    //void SwapIneRows(int N1, int N2)=0;//No need
    virtual void ReverseExtRowsSuccession()=0;
    virtual void ShiftExtRowsCyclelyToBegin()=0;
    virtual void ShiftExtRowsCyclelyToEnd()=0;
    //
    bool IsTransposable() const;
    //
    virtual void Transpose()=0;
    std::vector<int> TransposeTo();
    //
    //Coords2DInt Transpose_CoordsAftByBef(const Coords2DInt& coords);
    Coords2DInt Transpose_CoordsOfSinglePointFromIniToT(const Coords2DInt& coords)const;
    Coords2DInt Transpose_CoordsOfSinglePointFromTToIni(const Coords2DInt& coords)const;
    //
    int GetLengthOfIneRowN_FromFirstNoEmptyPoss(int N=-1) const;

    //
    //virtual void SubArray(const TDataShiftParams&DataShift, int Ldflt=1, bool IsTransposed=false, bool ExtRowsSuccessionIsReversed=false, EachExtRowIsReversed=false)=0;
    virtual void SubArray(const Coords2DInt& IniPoint, Array2DSize_Prototype*subArrSize, bool IsTransposed=false, bool ExtRowsSuccessionIsReversed=false, bool EachExtRowIsReversed=false, TDataShiftParams*ExtRows=NULL)=0;
    std::vector<int> SubArrayTo(const Coords2DInt& IniPoint, Array2DSize_Prototype*subArrSize, bool IsTransposed=false, bool ExtRowsSuccessionIsReversed=false, bool EachExtRowIsReversed=false, TDataShiftParams*ExtRows=NULL);
    //
    //Coords2DInt SubArray_CoordsWhereByWhat(const Coords2DInt& coordsGiven, const Coords2DInt& IniPoint, Array2DSize_Prototype*objDflt, int Ldflt=1,  bool IsTransposed=false, bool ExtRowsSuccessionIsReversed=false, bool EachExtRowIsReversed=false, TDataShiftParams*ExtRows=NULL);
    //Coords2DInt SubArray_CoordsWhatByWhere(const Coords2DInt& coordsGiven, const Coords2DInt& IniPoint, Array2DSize_Prototype*objDflt, int Ldflt=1,  bool IsTransposed=false, bool ExtRowsSuccessionIsReversed=false, bool EachExtRowIsReversed=false, TDataShiftParams*ExtRows=NULL);
    //
    Coords2DInt SubArray_CoordsWhereByWhat(const Coords2DInt& coordsGiven, const Coords2DInt& IniPoint, Array2DSize_Prototype*objDflt, bool IsTransposed=false, bool ExtRowsSuccessionIsReversed=false, bool EachExtRowIsReversed=false, TDataShiftParams*ExtRows=NULL);
    Coords2DInt SubArray_CoordsWhatByWhere(const Coords2DInt& coordsGiven, const Coords2DInt& IniPoint, Array2DSize_Prototype*objDflt, bool IsTransposed=false, bool ExtRowsSuccessionIsReversed=false, bool EachExtRowIsReversed=false, TDataShiftParams*ExtRows=NULL);
    //
    virtual void ConcatAdding(Array2DSize_Prototype*obj, int shiftQ=0, TDataShiftParams*ExtRows=NULL, Array2DSize_Prototype*sizeIni=NULL, int QERIni=0)=0;
    //
    //
    virtual Coords2DInt ConcatAdding_Coords1To3(const Coords2DInt& coords, Array2DSize_Prototype*size2, int shiftQ=0, TDataShiftParams*ExtRows=NULL, Array2DSize_Prototype*sizeIni=NULL, int QERIni=0)=0;
    virtual Coords2DInt ConcatAdding_Coords3To1(const Coords2DInt& coords, Array2DSize_Prototype*size2, int shiftQ=0, TDataShiftParams*ExtRows=NULL, Array2DSize_Prototype*sizeIni=NULL, int QERIni=0)=0;
    virtual Coords2DInt ConcatAdding_Coords2To3(const Coords2DInt& coords, Array2DSize_Prototype*size2, int shiftQ=0, TDataShiftParams*ExtRows=NULL, Array2DSize_Prototype*sizeIni=NULL, int QERIni=0)=0;
    virtual Coords2DInt ConcatAdding_Coords3To2(const Coords2DInt& coords, Array2DSize_Prototype*size2, int shiftQ=0, TDataShiftParams*ExtRows=NULL, Array2DSize_Prototype*sizeIni=NULL, int QERIni=0)=0;
    //
    //
    virtual void ConcatStretching(Array2DSize_Prototype*obj, int shiftQ=0, TDataShiftParams*ExtRows=NULL, Array2DSize_Prototype*sizeIni=NULL, int QERIni=0)=0;
    //
    virtual Coords2DInt ConcatStretching_Coords1To3(const Coords2DInt& coords, Array2DSize_Prototype*size2, int shiftQ=0, TDataShiftParams*ExtRows=NULL, Array2DSize_Prototype*sizeIni=NULL, int QERIni=0)=0;
    virtual Coords2DInt ConcatStretching_Coords3To1(const Coords2DInt& coords, Array2DSize_Prototype*size2, int shiftQ=0, TDataShiftParams*ExtRows=NULL, Array2DSize_Prototype*sizeIni=NULL, int QERIni=0)=0;
    virtual Coords2DInt ConcatStretching_Coords2To3(const Coords2DInt& coords, Array2DSize_Prototype*size2, int shiftQ=0, TDataShiftParams*ExtRows=NULL, Array2DSize_Prototype*sizeIni=NULL, int QERIni=0)=0;
    virtual Coords2DInt ConcatStretching_Coords3To2(const Coords2DInt& coords, Array2DSize_Prototype*size2, int shiftQ=0, TDataShiftParams*ExtRows=NULL, Array2DSize_Prototype*sizeIni=NULL, int QERIni=0)=0;
};//Array2DSize_Prototype


class Array2DSize_Rectangular: public Array2DSize_Prototype{
    int QExtRows, ExtRowLength;
public:
    Array2DSize_Rectangular(int QExtRows=0, int ExtRowLength=0);
    //
    //virtual
    ~Array2DSize_Rectangular();
    //
    //
    //
    Array2DSize_Prototype* GetCopy();
    //std::vector<int> GetAsArrayOfExtRowsLengthes(); /
    //
    //void construct();//SeNullIni is called
    virtual void SetNull();
    virtual void SetNullIni();
    virtual void SetOne();
    //
    virtual int GetTypeN();
    //
    virtual void Assign(Array2DSize_Prototype*obj);
    //
    virtual void Set(int* extRowsLengthes=NULL, int QExtRows=0);
    virtual void Set(int extRowsLength=0, int QExtRows=0);//may descr it generally or may leave it virtual
    //
    virtual int GetQExtRows() const ;
    virtual int GetRowLength(int N=-1) const ;
    virtual int GetRowLengthMin() const;
    virtual int GetRowLengthMax() const;
    //std::vector<int>GetLengthes() const;
    //std::vector<int>GetMinLengthRowNs() const;
    //std::vector<int>GetMaxLengthRowNs() const;
    virtual int GetQElements() const;
    //virtual Array2DSize_Prototype*GetSize_asPtr() const =0;
    //
    //int Arr2DBy1D_PosNByCoords(int ExtRowN, int IneRowN) const;
    //Coords2DInt Arr2DBy1D_CoordsByPosN(int PosN) const;
    //int Arr2DBy1D_ExtRowNByPosN(int PosN) const;
    //int Arr2DBy1D_IneRowNByPosN(int PosN) const;
    //
    virtual bool IsRectangularByType() const;
    virtual bool IsRectangularInFact() const;
    virtual bool IsEmpty() const;
    //int GetTypeN() const;
    //
    virtual int SetRowLength(int L, int N=0, int ifNotEqual_Ignore0Old1New2Max3Min4=1);
    virtual int SetQExtRows(int Q, int IfNotRect_ERL_ByMin1ByMax2ByLast3);
    //
    virtual void SetExtRow(int RowN, int L=0, TDataShiftParams*DataShiftParams=NULL, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1);
    //
    //Coords2DInt SetExtRow_CoordsByElementN(int ElementN, int RowN, int L=0, TDataShiftParams*DataShiftParams=NULL, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1);
    //
    virtual void AddExtRow(         int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL);
    //
    //Coords2DInt AddExtRow_CoordsByElementN(int ElementN,       int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL);
    //int AddExtRow_ElementNByCoords(const Coords2DInt& coords,  int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL);
    //
    virtual void InsExtRow(int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL);
    //
    //Coords2DInt InsExtRow_CoordsByElementN(    int ElementN,        int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL);
    //int InsExtRow_ElementNByCoords(      const Coords2DInt& coords, int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL);
    //Coords2DInt InsExtRow_CoordsOldByNew(const Coords2DInt& coords, int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL);
    //Coords2DInt InsExtRow_CoordsNewByOld(const Coords2DInt& coords, int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL);
    //
    virtual void DelExtRow(int N=-1);
    //
    //Coords2DInt DelExtRow_CoordsOldByNew(const Coords2DInt& coords, int N=-1);//no need
    //Coords2DInt DelExtRow_CoordsNewByOld(const Coords2DInt& coords, int N=-1);//no need
    //
    virtual void AddIneRow(int L=0, int IfNotSameQER_ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL);
    //
    //Coords2DInt AddIneRow_CoordsByElementN(int ElementN,      int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL);
    //int AddIneRow_ElementNByCoords(const Coords2DInt& coords, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL);
    //
   virtual void InsIneRow(int N=0, int L=0, int IfNotSameQER_ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL);
    //
    //Coords2DInt InsIneRow_CoordsByElementN(    int ElementN,        int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1);
    //int InsIneRow_ElementNByCoords(      const Coords2DInt& coords, int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1);
    //Coords2DInt InsIneRow_CoordsOldByNew(const Coords2DInt& coords, int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1);
    //Coords2DInt InsIneRow_CoordsNewByOld(const Coords2DInt& coords, int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1);
    //
    virtual void DelIneRow(int N=-1);
    //
    //Coords2DInt DelIneRow_CoordsOldByNew(const Coords2DInt& coords, int N=-1);//no need
    //Coords2DInt DelIneRow_CoordsNewByOld(const Coords2DInt& coords, int N=-1);//no need
    //
    //
    virtual void AddOrInsToExtRowN(int N=-1);
    virtual void DelFromExtRowN(int N=-1);
    //
    virtual void SwapExtRows(int N1, int N2);
    //void SwapIneRows(int N1, int N2)=0;//No need
    virtual void ReverseExtRowsSuccession();
    //void ShiftExtRowsCyclelyToBegin();//No need
    //void ShiftExtRowsCyclelyToEnd();//No need
    //
    //bool IsForTranspose() const;
    //
    virtual void Transpose();
    //
    //Coords2DInt Transpose_CoordsAftByBef(const Coords2DInt& coords);
    //Coords2DInt Transpose_CoordsBefByAft(const Coords2DInt& coords);
    //
    //int GetLengthOfIneRowN_FromFirstNoEmptyPoss(int N=-1) const;
    //
    virtual void SubArray(const Coords2DInt& IniPoint, Array2DSize_Prototype*subArrSize, bool IsTransposed=false, bool ExtRowsSuccessionIsReversed=false, bool EachExtRowIsReversed=false, TDataShiftParams*ExtRows=NULL);
    std::vector<int> SubArrayTo(const Coords2DInt& IniPoint, Array2DSize_Prototype*subArrSize, bool IsTransposed=false, bool ExtRowsSuccessionIsReversed=false, bool EachExtRowIsReversed=false, TDataShiftParams*ExtRows=NULL);
    //
    //Coords2DInt SubArray_CoordsWhereByWhat(const Coords2DInt& coordsGiven, const Coords2DInt& IniPoint, const TDataShiftParams&DataShift, Array2DSize_Prototype*sizeWhat,  bool IsTransposed=false, bool ExtRowsSuccessionIsReversed=false, EachExtRowIsReversed=false, TDataShiftParams*ExtRows=NULL, Array2DSize_Prototype*sizeIni=NULL, int QERIni=0);
    //Coords2DInt SubArray_CoordsWhatByWhere(const Coords2DInt& coordsGiven, const Coords2DInt& IniPoint, const TDataShiftParams&DataShift, Array2DSize_Prototype*sizeWhere, bool IsTransposed=false, bool ExtRowsSuccessionIsReversed=false, EachExtRowIsReversed=false, TDataShiftParams*ExtRows=NULL, Array2DSize_Prototype*sizeIni=NULL, int QERIni=0);
    //
    virtual void ConcatAdding(Array2DSize_Prototype*obj, int shiftQ=0, TDataShiftParams*ExtRows=NULL, Array2DSize_Prototype*sizeIni=NULL, int QERIni=0);
    //
    //
    virtual Coords2DInt ConcatAdding_Coords1To3(const Coords2DInt& coords, Array2DSize_Prototype*size2, int shiftQ=0, TDataShiftParams*ExtRows=NULL, Array2DSize_Prototype*sizeIni=NULL, int QERIni=0);
    virtual Coords2DInt ConcatAdding_Coords3To1(const Coords2DInt& coords, Array2DSize_Prototype*size2, int shiftQ=0, TDataShiftParams*ExtRows=NULL, Array2DSize_Prototype*sizeIni=NULL, int QERIni=0);
    virtual Coords2DInt ConcatAdding_Coords2To3(const Coords2DInt& coords, Array2DSize_Prototype*size2, int shiftQ=0, TDataShiftParams*ExtRows=NULL, Array2DSize_Prototype*sizeIni=NULL, int QERIni=0);
    virtual Coords2DInt ConcatAdding_Coords3To2(const Coords2DInt& coords, Array2DSize_Prototype*size2, int shiftQ=0, TDataShiftParams*ExtRows=NULL, Array2DSize_Prototype*sizeIni=NULL, int QERIni=0);
    //
    virtual void ConcatStretching(Array2DSize_Prototype*obj, int shiftQ=0, TDataShiftParams*ExtRows=NULL, Array2DSize_Prototype*sizeIni=NULL, int QERIni=0);
    //
    virtual Coords2DInt ConcatStretching_Coords1To3(const Coords2DInt& coords, Array2DSize_Prototype*size2, int shiftQ=0, TDataShiftParams*ExtRows=NULL, Array2DSize_Prototype*sizeIni=NULL, int QERIni=0);
    virtual Coords2DInt ConcatStretching_Coords3To1(const Coords2DInt& coords, Array2DSize_Prototype*size2, int shiftQ=0, TDataShiftParams*ExtRows=NULL, Array2DSize_Prototype*sizeIni=NULL, int QERIni=0);
    virtual Coords2DInt ConcatStretching_Coords2To3(const Coords2DInt& coords, Array2DSize_Prototype*size2, int shiftQ=0, TDataShiftParams*ExtRows=NULL, Array2DSize_Prototype*sizeIni=NULL, int QERIni=0);
    virtual Coords2DInt ConcatStretching_Coords3To2(const Coords2DInt& coords, Array2DSize_Prototype*size2, int shiftQ=0, TDataShiftParams*ExtRows=NULL, Array2DSize_Prototype*sizeIni=NULL, int QERIni=0);
};//Array2DSize_Rectangular

class Array2DSize_VariaLength: public Array2DSize_Prototype{
    //int QExtRows;
    //int*ExtRowLengthes;
    std::vector<int>Lengthes;
public:
    Array2DSize_VariaLength(int QExtRows=0, int ExtRowLength=0);
    Array2DSize_VariaLength(int QExtRows=0, int*ExtRowLength=NULL);
    //
    /*virtual*/ ~Array2DSize_VariaLength();
    //
    Array2DSize_Prototype* GetCopy();
    //std::vector<int> GetAsArrayOfExtRowsLengthes(); /
    //
    //void construct();//SeNullIni is called
    virtual void SetNull();
    virtual void SetNullIni();
    virtual void SetOne();
    //
    virtual int GetTypeN();
    //
    virtual void Assign(Array2DSize_Prototype*obj);
    //
    virtual void Set(int* extRowsLengthes=NULL, int QExtRows=0);
    virtual void Set(int extRowsLength=0, int QExtRows=0);//may descr it generally or may leave it virtual
    //
    virtual int GetQExtRows() const ;
    virtual int GetRowLength(int N=-1) const ;
    virtual int GetRowLengthMin() const;
    virtual int GetRowLengthMax() const;
    //std::vector<int>GetLengthes() const;
    //std::vector<int>GetMinLengthRowNs() const;
    //std::vector<int>GetMaxLengthRowNs() const;
    virtual int GetQElements() const;
    //virtual Array2DSize_Prototype*GetSize_asPtr() const =0;
    //
    //int Arr2DBy1D_PosNByCoords(int ExtRowN, int IneRowN) const;
    //Coords2DInt Arr2DBy1D_CoordsByPosN(int PosN) const;
    //int Arr2DBy1D_ExtRowNByPosN(int PosN) const;
    //int Arr2DBy1D_IneRowNByPosN(int PosN) const;
    //
    virtual bool IsRectangularByType() const;
    virtual bool IsRectangularInFact() const;
    virtual bool IsEmpty() const;
    //int GetTypeN() const;
    //
    virtual int SetRowLength(int L, int N=0, int ifNotEqual_Ignore0Old1New2Max3Min4=1);
    virtual int SetQExtRows(int Q, int IfNotRect_ERL_ByMin1ByMax2ByLast3);
    //
    virtual void SetExtRow(int RowN, int L=0, TDataShiftParams*DataShiftParams=NULL, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1);
    //
    //Coords2DInt SetExtRow_CoordsByElementN(int ElementN, int RowN, int L=0, TDataShiftParams*DataShiftParams=NULL, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1);
    //
    virtual void AddExtRow(         int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL);
    //
    //Coords2DInt AddExtRow_CoordsByElementN(int ElementN,       int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL);
    //int AddExtRow_ElementNByCoords(const Coords2DInt& coords,  int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL);
    //
    virtual void InsExtRow(int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL);
    //
    //Coords2DInt InsExtRow_CoordsByElementN(    int ElementN,        int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL);
    //int InsExtRow_ElementNByCoords(      const Coords2DInt& coords, int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL);
    //Coords2DInt InsExtRow_CoordsOldByNew(const Coords2DInt& coords, int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL);
    //Coords2DInt InsExtRow_CoordsNewByOld(const Coords2DInt& coords, int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL);
    //
    virtual void DelExtRow(int N=-1);
    //
    //Coords2DInt DelExtRow_CoordsOldByNew(const Coords2DInt& coords, int N=-1);//no need
    //Coords2DInt DelExtRow_CoordsNewByOld(const Coords2DInt& coords, int N=-1);//no need
    //
    virtual void AddIneRow(int L=0, int IfNotSameQER_ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL);
    //
    //Coords2DInt AddIneRow_CoordsByElementN(int ElementN,      int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL);
    //int AddIneRow_ElementNByCoords(const Coords2DInt& coords, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL);
    //
    virtual void InsIneRow(int N=0, int L=0, int IfNotSameQER_ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL);
    //
    //Coords2DInt InsIneRow_CoordsByElementN(    int ElementN,        int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1);
    //int InsIneRow_ElementNByCoords(      const Coords2DInt& coords, int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1);
    //Coords2DInt InsIneRow_CoordsOldByNew(const Coords2DInt& coords, int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1);
    //Coords2DInt InsIneRow_CoordsNewByOld(const Coords2DInt& coords, int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1);
    //
    virtual void DelIneRow(int N=-1);
    //
    //Coords2DInt DelIneRow_CoordsOldByNew(const Coords2DInt& coords, int N=-1);//no need
    //Coords2DInt DelIneRow_CoordsNewByOld(const Coords2DInt& coords, int N=-1);//no need
    //
    //
    virtual void AddOrInsToExtRowN(int N=-1);
    virtual void DelFromExtRowN(int N=-1);
    //
    virtual void SwapExtRows(int N1, int N2);
    //void SwapIneRows(int N1, int N2)=0;//No need
    virtual void ReverseExtRowsSuccession();
    //void ShiftExtRowsCyclelyToBegin();//No need
    //void ShiftExtRowsCyclelyToEnd();//No need
    //
    //bool IsForTranspose() const;
    //
    virtual void Transpose();
    //
    //Coords2DInt Transpose_CoordsAftByBef(const Coords2DInt& coords);
    //Coords2DInt Transpose_CoordsBefByAft(const Coords2DInt& coords);
    //
    //int GetLengthOfIneRowN_FromFirstNoEmptyPoss(int N=-1) const;
    //
    virtual void SubArray(const Coords2DInt& IniPoint, Array2DSize_Prototype*subArrSize, bool IsTransposed=false, bool ExtRowsSuccessionIsReversed=false, bool EachExtRowIsReversed=false, TDataShiftParams*ExtRows=NULL);
    std::vector<int> SubArrayTo(const Coords2DInt& IniPoint, Array2DSize_Prototype*subArrSize, bool IsTransposed=false, bool ExtRowsSuccessionIsReversed=false, bool EachExtRowIsReversed=false, TDataShiftParams*ExtRows=NULL);
    //
    //Coords2DInt SubArray_CoordsWhereByWhat(const Coords2DInt& coordsGiven, const Coords2DInt& IniPoint, const TDataShiftParams&DataShift, Array2DSize_Prototype*sizeWhat,  bool IsTransposed=false, bool ExtRowsSuccessionIsReversed=false, EachExtRowIsReversed=false, TDataShiftParams*ExtRows=NULL);
    //Coords2DInt SubArray_CoordsWhatByWhere(const Coords2DInt& coordsGiven, const Coords2DInt& IniPoint, const TDataShiftParams&DataShift, Array2DSize_Prototype*sizeWhere, bool IsTransposed=false, bool ExtRowsSuccessionIsReversed=false, EachExtRowIsReversed=false, TDataShiftParams*ExtRows=NULL);
    //
    virtual void ConcatAdding(Array2DSize_Prototype*obj, int shiftQ=0, TDataShiftParams*ExtRows=NULL, Array2DSize_Prototype*sizeIni=NULL, int QERIni=0);
    //
    virtual Coords2DInt ConcatAdding_Coords1To3(const Coords2DInt& coords, Array2DSize_Prototype*size2, int shiftQ=0, TDataShiftParams*ExtRows=NULL, Array2DSize_Prototype*sizeIni=NULL, int QERIni=0);
    virtual Coords2DInt ConcatAdding_Coords3To1(const Coords2DInt& coords, Array2DSize_Prototype*size2, int shiftQ=0, TDataShiftParams*ExtRows=NULL, Array2DSize_Prototype*sizeIni=NULL, int QERIni=0);
    virtual Coords2DInt ConcatAdding_Coords2To3(const Coords2DInt& coords, Array2DSize_Prototype*size2, int shiftQ=0, TDataShiftParams*ExtRows=NULL, Array2DSize_Prototype*sizeIni=NULL, int QERIni=0);
    virtual Coords2DInt ConcatAdding_Coords3To2(const Coords2DInt& coords, Array2DSize_Prototype*size2, int shiftQ=0, TDataShiftParams*ExtRows=NULL, Array2DSize_Prototype*sizeIni=NULL, int QERIni=0);
    //
    virtual void ConcatStretching(Array2DSize_Prototype*obj, int shiftQ=0, TDataShiftParams*ExtRows=NULL, Array2DSize_Prototype*sizeIni=NULL, int QERIni=0);
    //
    virtual Coords2DInt ConcatStretching_Coords1To3(const Coords2DInt& coords, Array2DSize_Prototype*size2, int shiftQ=0, TDataShiftParams*ExtRows=NULL, Array2DSize_Prototype*sizeIni=NULL, int QERIni=0);
    virtual Coords2DInt ConcatStretching_Coords3To1(const Coords2DInt& coords, Array2DSize_Prototype*size2, int shiftQ=0, TDataShiftParams*ExtRows=NULL, Array2DSize_Prototype*sizeIni=NULL, int QERIni=0);
    virtual Coords2DInt ConcatStretching_Coords2To3(const Coords2DInt& coords, Array2DSize_Prototype*size2, int shiftQ=0, TDataShiftParams*ExtRows=NULL, Array2DSize_Prototype*sizeIni=NULL, int QERIni=0);
    virtual Coords2DInt ConcatStretching_Coords3To2(const Coords2DInt& coords, Array2DSize_Prototype*size2, int shiftQ=0, TDataShiftParams*ExtRows=NULL, Array2DSize_Prototype*sizeIni=NULL, int QERIni=0);
};//Array2DSize_VariaLength

class Array2DSize_Shell{
    Array2DSize_Prototype*data;
public:
    //Array2DSize_Shell();
    Array2DSize_Shell(int QExtRows=0, int ExtRowLength=0, bool isRectangular=true);
    Array2DSize_Shell(int QExtRows=0, int*ExtRowLength=NULL, bool isRectangularIfInFact=false);
    //
    Array2DSize_Shell(const Array2DSize_Shell&obj);
    //
    ~Array2DSize_Shell();
    //
    void construct();
    void SetNull();
    void SetNullIni();
    void SetOne();
    //
    void Assign(Array2DSize_Prototype*obj);
    void Assign(const Array2DSize_Shell&obj);
    //
    //Array2DSize_Prototype*GetSize_asPtr() const ;
    //
    Array2DSize_Shell& operator = (const Array2DSize_Shell&obj);
    //
    Array2DSize_Prototype*GetData()const;
    //
    void SetTypeN(int TypeN=0);
    void Set(int*extRowsLengthes=NULL, int QExtRows=0, int TypeN=0);
    void Set(int extRowsLength=0, int QExtRows=0, int TypeN=0);
    //
    int GetQExtRows() const ;
    int GetRowLength(int N=-1) const ;
    int GetRowLengthMin() const ;
    int GetRowLengthMax() const ;
    std::vector<int>GetLengthes() const ;
    std::vector<int>GetMinLengthRowNs() const ;
    std::vector<int>GetMaxLengthRowNs() const ;
    int GetQElements() const;
    //
    bool IsRectangularByType() const ;
    bool IsRectangularInFact() const ;
    bool IsEmpty() const ;
    int GetTypeN() const;
    //
    int SetRowLength(int L, int N=0);
    int SetQExtRows(int Q, int IfNotRect_ERL_ByMin1ByMax2ByLast3);
    //
    void AddExtRow(int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1);
    void InsExtRow(int N=-1, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1);
    //virtual void AddExtRow(int L=0, int ifRectangularAndNotEqual_Ignore0ByOld1ByNew2ByMax3ByMin4=1);
    //virtual void InsExtRow(int N=0, int L=0, int ifRectangularAndNotEqual_Ignore0ByOld1ByNew2ByMax3ByMin4=1);
    void DelExtRow(int N=-1);
    //
    virtual Coords2DInt AddExtRow_Coords(int ElementN, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1);
    virtual Coords2DInt InsExtRow_Coords(int ElementN, int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1);
    //
    void AddIneRow(int L=0, int IfNotSameQER_Default0ByOld1ByNew2ByMax3ByMin4=1);
    void InsIneRow(int N=-1, int L=0, int IfNotSameQER_Default0ByOld1ByNew2ByMax3ByMin4=1);
    //virtual void AddIneRow(int EachExtRowIfVariaLen_Ignore0_AddToEach1_StretchToMax2=0, int L=0, int IfNotSameQER_ByOld1ByNew2ByMax3ByMin4=1);
    //virtual void InsIneRow(int N=0, int EachExtRowIfVariaLen_Ignore0_AddToEach1_StretchToN2=0, int L=0, int IfNotSameQER_ByOld1ByNew2ByMax3ByMin4=1);
    void DelIneRow(int N=-1);
    //
    virtual Coords2DInt AddIneRow_Coords(int ElementN, int L=0, int IfNotSameQER_ByOld1ByNew2ByMax3ByMin4=1);
    virtual Coords2DInt InsIneRow_Coords(int ElementN, int N=0, int L=0, int IfNotSameQER_ByOld1ByNew2ByMax3ByMin4=1);
    //
    void AddOrInsToExtRowN(int N=-1);
    void DelFromExtRowN(int N=-1);
    //
    void SwapExtRows(int N1, int N2);
    //void SwapIneRows(int N1, int N2)=0;//No need
    void ReverseExtRows();
    void ShiftExtRowsCyclelyToBegin();
    void ShiftExtRowsCyclelyToEnd();
    //
    void Transpose();
    //
    virtual Coords2DInt Transpose_Coords(const Coords2DInt& coords);
    //
    int GetLengthOfIneRowN_FromFirstNoEmptyPoss(int N=-1) const;
    bool IsForTranspose() const;
    //
    void ConcatAdding(Array2DSize_Prototype*obj, int shiftQ=0);
    void ConcatStretching(Array2DSize_Prototype*obj, int shiftQ=0);
    Array2DSize_Shell ConcatAddingTo(Array2DSize_Prototype*obj, int shiftQ=0);
    Array2DSize_Shell ConcatStretchingTo(Array2DSize_Prototype*obj, int shiftQ=0);
    //
    virtual Coords2DInt ConcatAdding_Coords(const Coords2DInt& coords, Array2DSize_Prototype*obj, int shiftQ=0);
    virtual Coords2DInt ConcatStretching_Coords(const Coords2DInt& coords, Array2DSize_Prototype*obj, int shiftQ=0);
    //
    void SubArray(const TDataShiftParams&DataShift, int Ldflt=1);
    void SubArray(const TDataShiftParams&DataShift, Array2DSize_Prototype*objDflt);
    void SubArray(const TDataShiftParams&DataShift, const Array2DSize_Shell&objDflt);
    Array2DSize_Shell SubArrayTo(const TDataShiftParams&DataShift, int Ldflt=1);
    Array2DSize_Shell SubArrayTo(const TDataShiftParams&DataShift, Array2DSize_Prototype*objDflt);
    Array2DSize_Shell SubArrayTo(const TDataShiftParams&DataShift, const Array2DSize_Shell&objDflt);
};//Array2DSize_Shell

Array2DSize_Shell Array2DSizes_ConcatAdding(const Array2DSize_Shell&obj1, const Array2DSize_Shell&obj2, TDataShiftParams*ShiftParams=NULL);
Array2DSize_Shell Array2DSizes_ConcatStretching(const Array2DSize_Shell&obj1, const Array2DSize_Shell&obj2, TDataShiftParams*ShiftParams=NULL, int ifErstNotRect_Ignore1_StretchToMax2_AddToLast3=2);


int PosNInArr2DAs1D(int QER, int Ls[], int ExtRowN, int IneRowN, int L1D=-1);
int PosNInArr2DAs1D(int IRL, int ExtRowN, int IneRowN, int L1D=-1);

int PosNInArr2DAs1D_LC(int QER, int Ls[], int LineN, int ColN, int arr2DIsRowOfCols0Lines1=1);
int PosNInArr2DAs1D_RLC(int QER, int Ls[], int LineN, int ColN);
int PosNInArr2DAs1D_RCL(int QER, int Ls[], int LineN, int ColN);



template<typename T> Array2DSize_Shell GetSizeOfVector2D(std::vector<std::vector<T>>);

//=== wa Arr2D Info. wi: Arr2D classes ===================================================================================

template<class T> class Array2DElement{
public:
    T data;
    Coords2DInt coords;
    Array2DElement();
    Array2DElement(T data, const Coords2DInt& coords);
    Array2DElement(T data, int n1, int n2);
    void set(T data, const Coords2DInt& coords);
    void set(T data, int n1, int n2);
    ~Array2DElement();
};

template<typename T> Array2DElement<T>::Array2DElement(){}
template<typename T> Array2DElement<T>::Array2DElement(T data, const Coords2DInt& coords){
    this->Set(data, coords);
}
template<typename T> Array2DElement<T>::Array2DElement(T data, int n1, int n2){
    this->data=data;
    this->coords.set(n1, n2);
}
template<typename T> Array2DElement<T>::~Array2DElement(){}
template<typename T> void Array2DElement<T>::Set(T data, const Coords2DInt& coords){
    this->data=data;
    this->coords=coords;
}
template<typename T> void Array2DElement<T>::Set(T data, int n1, int n2){
    this->data=data;
    this->coords.set(n1, n2);
}

#endif // ARRAY1D_SIZE2D_H
