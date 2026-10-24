#ifndef ARRAY1DLIB_H
#define ARRAY1DLIB_H

//#include"mylib.h"
//#include"tvalsshowhide.h"
/*class Array1DLib
{
public:
    Array1DLib();
};*/

template <typename T> void Array1DShowConsole(T*x, int Q, std::string delim="; ", bool LineNotCol=true){
    if(x!=NULL){
        for(int i=1; i<=Q-1; i++){
            std::cout<<x[i-1];
            if(LineNotCol){
                std::cout<<delim;
            }else{
                std::cout<<std::endl;
            }
        }
        std::cout<<x[Q-1];
        std::cout<<std::endl;
    }
}
template <typename T> void Array1DShowConsole(std::vector<T>x, std::string delim="; ", bool LineNotCol=true){
    int Q=x.size();
    if(x.size()!=0){
       for(int i=1; i<=Q-1; i++){
           std::cout<<x[i-1];
           if(LineNotCol){
               std::cout<<delim;
           }else{
               std::cout<<std::endl;
           }
       }
       std::cout<<x[Q-1];
       std::cout<<std::endl;
   }
}

template <typename T> std::vector<T> Array1DAssign(T*y=NULL, int Qy=0,  T*DfltValParam=NULL){
    std::vector<T>vec;
    T DfltVal;
    if(DfltValParam!=NULL) DfltVal=(*(DfltValParam));
    if(Qy==0){
        if(y==NULL){
            vec.clear();
        }
    }else{
        if(y==NULL){
            for(int i=1; i<=Qy; i++){
                vec.push_back(DfltVal);
            }
        }else{
            for(int i=1; i<=Qy; i++){
                vec.push_back(y[i-1]);
            }
        }
    }
    return vec;
}
template <typename T> void Array1DAssign(std::vector<T>&vec, T y[], int L=0){
    vec.clear();
    int Q=vec.size();
    if(L==0){
        vec.assign(y, y+sizeof(y)/sizeof(y[0]));
    }else{
        for(int i=1; i<=L; i++){
            vec.push_back(y[i-1]);
        }
    }

}

template <typename T> void  Array1DAssign(T*&x, int Qx=0, T*y=NULL, int Qy=0,  T*DfltValParam=NULL){
    T DfltVal;
    if(Qy==0){
        if(y!=NULL){
            Qy=Qx;
        }
    }
    if(Qx!=Qy && Qx>0){
        if(x!=NULL){
            delete[]x;
            x=NULL;
        }
    }
    if(x==NULL && Qy>0){
        x=new T[Qy];
    }
    if(Qy>0){
        if(y!=NULL){
            for(int i=1; i<=Qy; i++){
                x[i-1]=y[i-1];
            }
        }else{
            if(DfltValParam!=NULL){
                DfltVal=(*(DfltValParam));
            }
            for(int i=1; i<=Qy; i++){
                x[i-1]=DfltVal;
            }
        }
    }
}
template <typename T> void  Array1DAssign(T*&x, int Qx, std::vector<T>y, T*DfltValParam=NULL){
    Array1DAssign(x, Qx, y.data(), y.size(), DfltValParam);
}
template <typename T> void  Array1DAssign(std::vector<T>x, std::vector<T>y){
    x=y;
}

/*template <typename T>std::vector<T> Array1DGetSubArray(T*x, int wholeRowL, int FromN=1, int ToN=0, T*DfltValParam=NULL){
    std::vector<T>y;
    int LastN;
    T DfltVal;
    if(DfltValParam!=NULL){
        DfltVal=(*(DfltValParam));
    }
    if(ToN==0){
        ToN=wholeRowL;
    }
    if(FromN<1){
        FromN+=wholeRowL;
    }
    if(ToN<1){
        ToN+=wholeRowL;
    }
    if(FromN>0 || ToN>0){
        if(FromN<0){
            for(int i=FromN; i<1; i++){
                y.push_back(DfltVal);
            }
            if(ToN<=wholeRowL){
                for(int i=1; i<=ToN; i++){
                    y.push_back(x[i-1]);
                }
            }else{
                for(int i=1; i<=wholeRowL; i++){
                    y.push_back(x[i-1]);
                }
                for(int i=wholeRowL+1; i<=ToN; i++){
                    y.push_back(DfltVal);
                }
            }
        }else if(FromN<ToN && FromN<=wholeRowL){
            if(ToN<=wholeRowL){
                for(int i=FromN; i<=ToN; i++){
                    y.push_back(x[i-1]);
                }
            }else{
                for(int i=FromN; i<=wholeRowL; i++){
                    y.push_back(x[i-1]);
                }
                for(int i=wholeRowL+1; i<=ToN; i++){
                    y.push_back(DfltVal);
                }
            }
        }else if(ToN<FromN && ToN<=wholeRowL && FromN>=1){
            for(int i=FromN; i>=wholeRowL+1; i--){
                y.push_back(DfltVal);
            }
            if(ToN>=1){
                for(int i=wholeRowL; i>=ToN; i--){
                     y.push_back(x[i-1]);
                }
            }else{
                for(int i=wholeRowL; i>=1; i--){
                     y.push_back(x[i-1]);
                }
                for(int i=0; i>=ToN; i--){
                   y.push_back(DfltVal);
                }
            }
        }
    }
    return y;
}
template <typename T>std::vector<T> Array1DGetSubArray(std::vector<T>x,  int FromN=1, int ToN=0, T*DfltValParam=NULL){
   return  Array1DGetSubArray(x.data(), x.size(), FromN, ToN, DfltValParam);

}*/
template <typename T>std::vector<T> Array1DGetSubArray_byNs(T*x, int LOld, int N1=1, int N2=-1, T*DfltValParam=NULL){
    std::vector<T>y;
    T DfltVal;
    int Nmin, Nmax;
    if(DfltValParam!=NULL){
        DfltVal=(*(DfltValParam));
    }
    if(N1<0){
        N1+=(LOld+1);
    }
    if(N2<0){
        N2+=(LOld+1);
    }
    if(N1<=N2){
        if(N1<0){
            for(int i=1; i<=(-N1-1); i++){
                y.push_back(DfltVal);
            }
            N1=1;
        }
        Nmin= N2<=LOld ? N2: LOld;
        for(int i=1; i<=Nmin; i++){
            y.push_back(x[i-1]);
        }
        for(int i=LOld+1; i<=N2; i++){
            y.push_back(DfltVal);
        }
    }else{
        if(N1>LOld){
           for(int i=N1; i>=LOld+1; i--){
               y.push_back(DfltVal);
           }
           N1=LOld;
        }
        Nmax = N2>=1 ? N2: 1;
        for(int i=N1; i>=Nmax; i--){
             y.push_back(x[i-1]);
        }
        if(N2<0){
            for(int i=1; i>=(-N2); i--){
                y.push_back(DfltVal);
            }
        }
    }
    return y;
}
template <typename T>std::vector<T> Array1DGetSubArray_byNs(std::vector<T>x,  int N1=1, int N2=-1, T*DfltValParam=NULL){
    return  Array1DGetSubArray_byNs(x.data(), x.size(), N1, N2, DfltValParam);
}

template <typename T>std::vector<T> Array1DGetSubArray_byLs(T*x, int Lold, int Lnew=0, int FromN=1, int FirstDefaultValues=0, T*DfltValParam=NULL){
    std::vector<T>y;
    T DfltVal;
    bool contin;
    int whereCurN, whatCurN;
    if(DfltValParam!=NULL){
        DfltVal=(*(DfltValParam));
    }
    if(Lnew==0){
        Lnew=Lold-(FromN-1)+FirstDefaultValues;
    }
    for(int whereCurN=1; whereCurN<=FirstDefaultValues; whereCurN++){
        y.push_back(DfltVal);
    }
    whereCurN=FirstDefaultValues;
    whatCurN=FromN-1;
    contin=(Lold>0);
    //contin=(whereN>=1 && whereN<Lold && whatN<Lnew);
    if(x!=NULL){
        while(contin){
            whatCurN++;
            whereCurN++;
            y.push_back(x[whatCurN-1]);
            if(whereCurN==Lnew){
                contin=false;
            }
            if(whatCurN==Lold){
                contin=false;
            }
        }
    }else{
        while(contin){
            whatCurN++;
            whereCurN++;
            y.push_back(DfltVal);
            //contin=(whereN<Lold && whatN<Lnew);
            if(whereCurN==Lnew){
                contin=false;
            }
            if(whatCurN==Lold){
                contin=false;
            }
        }
    }
    whereCurN=Lold-(FromN-1)+FirstDefaultValues;
    if(whereCurN<Lnew){
        for(int i=whereCurN+1; i<=Lnew; i++){
             y.push_back(DfltVal);
        }
    }
    return y;
}
template <typename T>std::vector<T> Array1DGetSubArray_byLs(std::vector<T>x, int Lnew=0, int FromN=1, int FirstDefaultValues=0, T*DfltValParam=NULL){
    return Array1DGetSubArray_byLs(x.data(), x.size(), Lnew, FromN, FirstDefaultValues, DfltValParam);
}

/*template <typename T>std::vector<T> Array1DGetSubArray_byLs(std::vector<T>x, int Lnew=0, int FromN=1, int FirstDefaultValues=0, T*DfltValParam=NULL){
    std::vector<T>y;
    T DfltVal;
    int Lold=x.size();
    bool contin;
    int whereCurN, whatCurN;
    if(DfltValParam!=NULL){
        DfltVal=(*(DfltValParam));
    }
    if(Lnew==0){
        Lnew=Lold-(FromN-1)+FirstDefaultValues;
    }
    for(int whereCurN=1; whereCurN<=FirstDefaultValues; whereCurN++){
        y.push_back(DfltVal);
    }
    whereCurN=FirstDefaultValues;
    whatCurN=FromN-1;
    contin=(Lold>0);
    if(x.size()!=0){
        while(contin){
            whatCurN++;
            whereCurN++;
            y.push_back(x[whatCurN-1]);
            if(whereCurN==Lnew){
                contin=false;
            }
            if(whatCurN==Lold){
                contin=false;
            }
        }
    }else{
        while(contin){
            whatCurN++;
            whereCurN++;
            y.push_back(DfltVal);
            if(whereCurN==Lnew){
                contin=false;
            }
            if(whatCurN==Lold){
                contin=false;
            }
        }
    }
    whereCurN=Lold-(FromN-1)+FirstDefaultValues;
    if(whereCurN<Lnew){
        for(int i=whereCurN+1; i<=Lnew; i++){
             y.push_back(DfltVal);
        }
    }
    return y;
}*/


template <typename T>void Array1DSetSize(T*&x, int QOld, int QNew,  T*DfltValExt=NULL, int PreserveVals=true){
    T*y=NULL;
    T DefaultVal;
    if(DfltValExt!=NULL){
        DefaultVal=(*(DfltValExt));
    }
    int mn= QOld <= QNew ? QOld : QNew;
    if(x!=NULL && QOld!=QNew){
        y=new T[QNew];
        if(PreserveVals){
            for(int i=1; i<=mn; i++){
                y[i-1]=x[i-1];
            }
            for(int i=mn+1; i<=QNew; i++){
                y[i-1]=DefaultVal;
            }
        }
        delete[]x;
        x=y;
    }
}

template <typename T>void Array1DSetSize(std::vector<T>&x, int QNew,  T*DfltValExt=NULL, int PreserveVals=true){
    T*y=NULL;
    T DefaultVal;
    int QOld=x.size();
    if(DfltValExt!=NULL){
        DefaultVal=(*(DfltValExt));
    }
    int mn= QOld <= QNew ? QOld : QNew;
    if(x!=NULL && QOld!=QNew){
        y=new T[QNew];
        if(PreserveVals){
            for(int i=1; i<=mn; i++){
                y[i-1]=x[i-1];
            }
            for(int i=mn+1; i<=QNew; i++){
                y[i-1]=DefaultVal;
            }
        }
        x.clear();
        for(int i=1; i<=QNew; i++){
            x.push_back(y[i-1]);
        }
        delete[]y;
        y=NULL;
    }
}

template <typename T>void Array1DReSize(T*&x, int&Q, int dQ, T*DfltVal=NULL, int PreserveVals=true){
    int QOld=Q;
    Q+=dQ;
    Array1DSetSize(x, QOld, Q, DfltVal, PreserveVals);
}

template <typename T>void Array1DReSize(std::vector<T>&x, int dQ, T*DfltVal=NULL, int PreserveVals=true){
    int Q=x.size();
    int QOld=Q;
    Q+=dQ;
    Array1DSetSize(x, QOld, Q, DfltVal, PreserveVals);
}

template <typename T>void Array1DAddElement(T*&x, int&Q, T z){//new considers vrn x=NULL
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
    if(x!=NULL){
        delete[]x;
    }
    x=y;
    Q++;
}
template <typename T>void Array1DAddElement(std::vector<T>&x, T z){
    x.push_back(z);
}


template <typename T>void Array1DInsElementToN(T*&x, int&Q, int N, T z, TValsShowHide*vsh=NULL/*, int PreserveVals=true*/){
    T*y;
   // int OldN, NewN;
    std::string msg="VectorInsElementToN starts working";
    writeln(vsh,msg);//"VectorInsElementToN starts working");
    if(N<1) N=Q+N;//N=CalcElementNIfNegativeOf(int N, int Q);
    if(N>=1 && N<=Q){
        msg="N is within range of arrays size";
        writeln(vsh,msg);//"N is within range of arrays size");
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
    msg="VectorInsElementToN finishes working";
    writeln(vsh,msg);//"VectorInsElementToN finishes working");
}

template <typename T>void Array1DInsElementToN(std::vector<T>&x, int N, T z){
    x.insert(x.begin()+N-1, z);
}

template <typename T>void Array1DDelElementFromN(T*&x, int&Q, int N){
    T*y=NULL;
    if(N<1) N=Q-N;
    if(N>=1 && N<=Q){
        y=new T[Q-1];
        for(int i=1; i<=Q; i++){
            if(i<N)y[i-1]=x[i-1];
            else if(i>N) y[i-1-1]=x[i-1];
        }
        delete[]x;
        x=y;
        Q--;
    }
}

template <typename T>void Array1DDelElementFromN(std::vector<T>&x, int N){
    x.erase(x.begin()+N-1);
}

//
template <typename T>void Array1DSwapElements(T*&x, int Q, int N1, int N2){
    T buf;
    if(N1<1) N1=Q+N1; //if(N1<1) N1=Q+N1;//N=CalcElementNIfNegativeOf(int N1, int Q);
    if(N2<1) N2=Q+N2; //if(N2<1) N2=Q+N2;//N=CalcElementNIfNegativeOf(int N2, int Q);
    if(N1>=1 && N1<=Q && N2>=1 && N2<=Q){
        buf=x[N1-1];
        x[N1-1]=x[N2-1];
        x[N2-1]=buf;
    }
}
template <typename T>void Array1DSwapElements(std::vector<T>&x, int N1, int N2){
    T buf;
    int Q=x.size();
    if(N1<1) N1=Q+N1; //if(N1<1) N1=Q+N1;//N=CalcElementNIfNegativeOf(int N1, int Q);
    if(N2<1) N2=Q+N2; //if(N2<1) N2=Q+N2;//N=CalcElementNIfNegativeOf(int N2, int Q);
    if(N1>=1 && N1<=Q && N2>=1 && N2<=Q){
        buf=x[N1-1];
        x[N1-1]=x[N2-1];
        x[N2-1]=buf;
    }
}
template <typename T>void Array1DReverse(T*&x, int Q){
    int N, N1, N2;
    if(Q%2==0){
        N=Q/2;
    }else{
        N=(Q-1)/2;
    }
    for(int i=1; i<=N; i++){
        N1=i;
        N2=Q-i+1;
        Array1DSwapElements(x, Q, N1, N2);
    }
}

template <typename T>void Array1DReverse(std::vector<T>&x){
    int N, N1, N2;
    int Q=x.size();
    if(Q%2==0){
        N=Q/2;
    }else{
        N=(Q-1)/2;
    }
    for(int i=1; i<=N; i++){
        N1=i;
        N2=Q-i+1;
        Array1DSwapElements(x, N1, N2);
    }
}

template <typename T> std::vector<T> Array1DArray1DGetSubArrayAsStdVector(T*data, int curL, int N1=1, int N2=0, T*DfltVal=NULL){
    T x;
    std::vector<T>arr;
    T dflt;
    if(DfltVal!=NULL){
        dflt=(*(DfltVal));
    }
    //dflt=GetDefaultVal(DfltVal);
    if(N2==0){
        N2=curL;
    }
    if(N1<1) N1=curL+N1; //if(N1<1) N1=Q+N1;//N=CalcElementNIfNegativeOf(int N1, int Q);
    if(N2<1) N2=curL+N2; //if(N2<1) N2=Q+N2;//N=CalcElementNIfNegativeOf(int N2, int Q);
    //if(N1>N2){
    //    //
    //    N1=N2;
    //}
    //if(N1<1){
    //    N1=1;
    //}
    int minL;//=N2<curL?N2:curL;
    //for(int i=1; i<=minL; i++){
    //    x=data[i-1];
    //    arr.push_back(x);
    //}
    //for(int i=minL+1; i<=N2; i++){
    //    arr.push_back(dflt);
    //}
    //
    //if(N1>=1 && N1<=curL && N2>=1 && N2<=curL){
    if(N1>=1 && N1<=curL && N2>=1 && N1<=N2){
        minL=N2<curL?N2:curL;
        for(int i=N1; i<=N2; i++){
            arr.push_back(data[i-1]);
        }
        for(int i=minL+1; i<=N2; i++){
            arr.push_back(dflt);
        }
    }else if(N1>=1 && N1<=curL && N2>=1 && N2<=curL && N2<N1){
        minL=N1<curL?N1:curL;
        for(int i=minL+1; i<=N1; i++){
            arr.push_back(dflt);
        }
        for(int i=N1; i>=N2; i--){
            arr.push_back(data[i-1]);
        }
    }
    return arr;
}
template <typename T> std::vector<T> Array1DArray1DGetSubArrayAsStdVector(std::vector<T>data, int N1=1, int N2=0, T*DfltVal=NULL){
    T x;
    int curL=data.size();
    std::vector<T>arr;
    T dflt;
    if(DfltVal!=NULL){
        dflt=(*(DfltVal));
    }
    int Q=data.size();
    //dflt=GetDefaultVal(DfltVal);
    if(N2==0){
        N2=curL;
    }
    if(N1<1) N1=Q+N1; //if(N1<1) N1=Q+N1;//N=CalcElementNIfNegativeOf(int N1, int Q);
    if(N2<1) N2=Q+N2; //if(N2<1) N2=Q+N2;//N=CalcElementNIfNegativeOf(int N2, int Q);
    int minL;//=N2<curL?N2:curL;
    //
    if(N1>=1 && N1<=curL && N2>=1 && N1<=N2){
        minL=N2<curL?N2:curL;
        for(int i=N1; i<=N2; i++){
            arr.push_back(data[i-1]);
        }
        for(int i=minL+1; i<=N2; i++){
            arr.push_back(dflt);
        }
    }else if(N1>=1 && N1<=curL && N2>=1 && N2<=curL && N2<N1){
        minL=N1<curL?N1:curL;
        for(int i=minL+1; i<=N1; i++){
            arr.push_back(dflt);
        }
        for(int i=N1; i>=N2; i--){
            arr.push_back(data[i-1]);
        }
    }
    return arr;
}
template <typename T> std::vector<int>Array1DSeek(T*data, T val, int curL, bool(*Equals)(const T& x1, const T& x2, int params)=EqualSimple, int FromN=1, int ToN=0){
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
template <typename T> std::vector<int>Array1DSeek(const std::vector<T>&data, T val, bool(*Equals)(const T& x1, const T& x2, int params)=EqualSimple, int FromN=1, int ToN=0){
    std::vector<int> Ns;
    int curL=data.size();
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
template <typename T> std::vector<int>Array1DSeekSimply(T*data, T val, int curL, int FromN=1, int ToN=0, int param=0){
    std::vector<int> Ns;
    int Q=curL;
    if(ToN==0 or ToN>Q) ToN=Q;
    if(FromN<1){
        //FromN= CalcElementNIfNegativeOf(FromN, curL);
        FromN=Q+FromN+1;
    }
    //if(FromN<=ToN){
    if(FromN<=ToN && FromN>=1){
        for(int i=FromN; i<=ToN; i++){
            if(data[i-1]==val){
                Ns.push_back(i);
            }
        }
    }
    //else
    //{
    //    for(int i=FromN; i>=ToN; i--){
    //        if(data[i-1]==val){
    //            Ns.push_back(i);
    //        }
    //    }
    //}
    return Ns;
}//fn
template <typename T> std::vector<int>Array1DSeekSimply(std::vector<T>data, T val,  int FromN=1, int ToN=0, int param=0){
    std::vector<int> Ns;
    int Q=data.size();
    if(ToN==0 or ToN>Q) ToN=Q;
    if(FromN<=ToN){
        for(int i=FromN; i<=ToN; i++){
            if(data[i-1]==val){
                Ns.push_back(i);
            }
        }
    }else{
        for(int i=FromN; i>=ToN; i--){
            if(data[i-1]==val){
                Ns.push_back(i);
            }
        }
    }
    return Ns;
}//fn
template <typename T> bool Array1DSuccIsAtPos(T*data, T*succ, int L, int PosN, int succL, bool(*Equals)(const T& x1, const T& x2, int param)=EqualSimple, TValsShowHide*vsh=NULL){
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
template <typename T> bool Array1DSuccIsAtPos(const std::vector<T>&data, const std::vector<T>&succ, int PosN, bool(*Equals)(const T& x1, const T& x2, int param)=EqualSimple, TValsShowHide*vsh=NULL){
    int L=data.size();
    int succL=succ.size();
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
template <typename T> bool Array1DSuccIsAtPosSimply(T*data, T*succ, int L, int succL, int PosN, int param=0, TValsShowHide*vsh=NULL){
    bool verdict=true;
    int j;
    for(int i=1; i<=succL; i++){
        j=PosN+i-1;
        if(data[j-1]!=succ[i-1]){
            verdict=false;
        }
    }
    return verdict;
}
template <typename T> bool Array1DSuccIsAtPosSimply(std::vector<T>data, std::vector<T>succ, int PosN, int param=0, TValsShowHide*vsh=NULL){
    bool verdict=true;
    int j, L=data.size(), succL=succ.size();
    for(int i=1; i<=succL; i++){
        j=PosN+i-1;
        if(data[j-1]!=succ[i-1]){
            verdict=false;
        }
    }
    return verdict;
}
template <typename T> std::vector<int>Array1DSeek(T*data, T*succ, int succL, int curL, bool (*Equals)(const T& x1, const T& x2, int params)=EqualSimple, int FromN=1, int ToN=0, TValsShowHide*vsh=NULL){
    std::vector<int> Ns;
    int Q=curL;
    writeln(vsh, "Seek(1D in 1D) starts working");
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
                if(Array1DSuccIsAtPos(data, succ, curL, i, succL, Equals, vsh)){
                    Ns.push_back(i);
                    writeln(vsh,"Found!");
                }else  writeln(vsh,"NOT found");
            }
        }
    }
    writeln(vsh, "Seek(1D in 1D) finishes working");
    return Ns;
}
/*
template <typename T> std::vector<int>Array1DSeek(const std::vector<T>&data, const std::vector<T>&succ, bool (*Equals)(const T& x1, const T& x2, int params)=EqualSimple, int FromN=1, int ToN=0, TValsShowHide*vsh=NULL){
    std::vector<int> Ns;
    int Q=data.size();//curL;
    int succL=succ.size();
    writeln(vsh, "Seek(1D in 1D) starts working");
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
                if(Array1DSuccIsAtPos(data, succ, curL, i, succL, Equals, vsh)){
                    Ns.push_back(i);
                    writeln(vsh,"Found!");
                }else  writeln(vsh,"NOT found");
            }
        }
    }
    writeln(vsh, "Seek(1D in 1D) finishes working");
    return Ns;
}
template <typename T> std::vector<int>Array1DSeekSimply(T*data, T*succ, int curL, int succL, int FromN=1, int ToN=0, int param=0, TValsShowHide*vsh=NULL){
    std::vector<int> Ns;
    int Q=curL, j;
    writeln(vsh, "Seek(1D in 1D) starts working");
    if(ToN==0) ToN=Q;
    if(FromN<=ToN){
        if(ToN==Q)ToN=ToN-succL+1;
        writeln(vsh,"Length to seek in: "+IntToStr(Q)+" Length to seek: "+IntToStr(succL)+" order: direct");
        for(int i=FromN; i<=ToN; i++){
            writeln(vsh,"PosNn: "+IntToStr(i)+"checking... ");
            if(Array1DSuccIsAtPos(data, succ, curL, i, succL, Equals, vsh)){
                Ns.push_back(i);
                writeln(vsh,"Found!");
            }else  writeln(vsh,"NOT found");
        }
    }else{
        if(ToN==1) ToN=succL;
        writeln(vsh,"Length to seek in: "+IntToStr(Q)+" Length to seek: "+IntToStr(succL)+" order: reversed");
        for(int i=FromN; i>=ToN; i--){
            j=i-succL+1;
            writeln(vsh,"PosNn: "+IntToStr(j)+"("+IntToStr(i)+")"+" checking... ");
            if(Array1DSuccIsAtPos(data, succ, curL, j, succL, Equals, vsh)){
                Ns.push_back(i);//or j
                writeln(vsh,"Found!");
            }else  writeln(vsh,"NOT found");
        }
    }
    writeln(vsh, "Seek(1D in 1D) finishes working");
    return Ns;
}
template <typename T> std::vector<int>Array1DSeekSimply(const std::vector<T>&data, const std::vector<T>&succ, int FromN=1, int ToN=0, int param=0, TValsShowHide*vsh=NULL){
    std::vector<int> Ns;
    int Q=data.size(), succL=succ.size(), j;
    writeln(vsh, "Seek(1D in 1D) starts working");
    if(ToN==0) ToN=Q;
    if(FromN<=ToN){
        if(ToN==Q)ToN=ToN-succL+1;
        writeln(vsh,"Length to seek in: "+IntToStr(Q)+" Length to seek: "+IntToStr(succL)+" order: direct");
        for(int i=FromN; i<=ToN; i++){
            writeln(vsh,"PosNn: "+IntToStr(i)+"checking... ");
            if(Array1DSuccIsAtPos(data, succ, curL, i, succL, Equals, vsh)){
                Ns.push_back(i);
                writeln(vsh,"Found!");
            }else  writeln(vsh,"NOT found");
        }
    }else{
        if(ToN==1) ToN=succL;
        writeln(vsh,"Length to seek in: "+IntToStr(Q)+" Length to seek: "+IntToStr(succL)+" order: reversed");
        for(int i=FromN; i>=ToN; i--){
            j=i-succL+1;
            writeln(vsh,"PosNn: "+IntToStr(j)+"("+IntToStr(i)+")"+" checking... ");
            if(Array1DSuccIsAtPos(data, succ, curL, j, succL, Equals, vsh)){
                Ns.push_back(i);//or j
                writeln(vsh,"Found!");
            }else  writeln(vsh,"NOT found");
        }
    }
    writeln(vsh, "Seek(1D in 1D) finishes working");
    return Ns;
}
template <typename T> int Array1DSeekFirst(T*data, T val, int curL, bool (*Equals)(const T& x1, const T& x2, int params)=EqualSimple, int FromN=1, int ToN=0){
    int N=0;
    std::vector<int> Ns=Array1DSeek(data, val, curL, Equals, FromN, ToN);
    if(Ns.size()>0){
        N=Ns[1-1];
    }
    return N;
}
template <typename T> int Array1DSeekLast(T*data, T val, int curL, bool (*Equals)(const T& x1, const T& x2, int params)=EqualSimple, int FromN=1, int ToN=0){
    int N=0;
    std::vector<int> Ns=Seek(data, val, curL, Equals, FromN, ToN);
    int count=Ns.size();
    if(count>0){
        N=Ns[count-1];
    }
    return N;
}
template <typename T> int Array1DSeekFirst(T*data, T*succ, int succL, int curL, bool (*Equals)(const T& x1, const T& x2, int params)=EqualSimple, int FromN=1, int ToN=0){
    int N=0;
    std::vector<int> Ns=Seek(data, succ, succL,curL, Equals, FromN, ToN);
    if(Ns.size()>0){
        N=Ns[1-1];
    }
    return N;
}
template <typename T> int Array1DSeekLast(T*data, T*succ, int succL, int curL, bool (*Equals)(const T& x1, const T& x2, int params)=EqualSimple, int FromN=1, int ToN=0){
    int N=0;
    std::vector<int>  Ns=Seek(data, succ, succL,curL, Equals,  FromN, ToN);
    int count=Ns.size();
    if(count>0){
        N=Ns[count-1];
    }
    return N;
}

template <typename T> int Array1DSeekFirst(T*data, T val, int curL,  int FromN=1, int ToN=0, int param=0){
    int N=0;
    std::vector<int> Ns=Array1DSeek(data, val, curL, FromN, ToN, param);
    if(Ns.size()>0){
        N=Ns[1-1];
    }
    return N;
}
template <typename T> int Array1DSeekLast(T*data, T val, int curL, int FromN=1, int ToN=0, int param=0){
    int N=0;
    std::vector<int> Ns=Seek(data, val, curL, Equals, FromN, ToN, param);
    int count=Ns.size();
    if(count>0){
        N=Ns[count-1];
    }
    return N;
}
template <typename T> int Array1DSeekFirst(T*data, T*succ, int succL, int FromN=1, int ToN=0, int param=0){
    int N=0;
    std::vector<int> Ns=Seek(data, succ, succL, curL, FromN, ToN, param);
    if(Ns.size()>0){
        N=Ns[1-1];
    }
    return N;
}
template <typename T> int Array1DSeekLast(T*data, T*succ, int succL, int curL, int FromN=1, int ToN=0, int param=0){
    int N=0;
    std::vector<int>  Ns=Seek(data, succ, succL,curL, FromN, ToN, param);
    int count=Ns.size();
    if(count>0){
        N=Ns[count-1];
    }
    return N;
}

template <typename T> void Array1DShowToConsole(T*x, int L, char* delim=" \0"){
    for(int i=1; i<=L; i++){
        std::cout<<x[i-1];
        std::cout<<delim;
    }
    std::cout<<std::endl;
}
*/

#endif // ARRAY1DLIB_H
