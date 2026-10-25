#ifndef ARRAY2DLIB_H
#define ARRAY2DLIB_H

#include"array1d_size2d_elem2d_1.h"

//class Array2DLib
//{
//public:
//    Array2DLib();
//};

const int ARR2D_TYPE_V1D_RECTANGULAR=1;//ARR2D_TYPE_V1D_RECTANGULAR
const int ARR2D_TYPE_P1D_RECTANGULAR=2;
const int ARR2D_TYPE_V2D_RECTANGULAR=3;
const int ARR2D_TYPE_P2D_RECTANGULAR=4;
const int ARR2D_TYPE_V1D_VAR_LEN=11;
const int ARR2D_TYPE_P1D_VAR_LEN=12;
const int ARR2D_TYPE_V2D_VAR_LEN=13;
const int ARR2D_TYPE_P2D_VAR_LEN=14;
const int ARR2D_TYPE_V1D_RARE_RECTANGULAR=21;
const int ARR2D_TYPE_P1D_RARE_RECTANGULAR=22;
const int ARR2D_TYPE_V1D_RARE_VAR_LEN=31;
const int ARR2D_TYPE_P1D_RARE_VAR_LEN=32;
const int ARR2D_TYPE_DEFAULT=ARR2D_TYPE_V1D_RECTANGULAR;

template <class T> class Array2D_Prototype{
  public:
    //virtual ~Array2D_Prototype()=0;
    virtual ~Array2D_Prototype();
    virtual int GetTypeN() const=0;
    //virtual void SetTypeN(int typeN=0)=0;
    virtual int GetQExtRows() const =0;
    virtual int GetExtRowLength(int rowN=-1)const =0;
    virtual T GetElement(int ExtRowN, int inRowPosN)const =0;
    virtual const T* GetPointerToElement(int ExtRowN, int inRowPosN)const =0;
    virtual void SetElement(const T& val, int ExtRowN, int inRowPosN)=0;
    virtual bool IsRectangularInFact() const ;
    virtual bool IsRectangularByType() const =0;
    virtual int GetLengthOfIneRowN(int N=-1) const=0;
    virtual std::vector<int> GetSizeAsStdVector() const;
    virtual Array2DSize GetSize()const=0;
    virtual int GetRowLengthMax() const ;
    virtual int GetRowLengthMin() const ;
    std::vector<int>GetNsOfLmax() const;
    std::vector<int>GetNsOfLmin()const;
    std::vector<int>GetNsOfL(int L) const ;
    //
    //
    virtual void SetSize(const T&defaultVal, int QExtRows=1, int ExtRowlength=1);
    virtual void SetSize(const T&defaultVal, int*ExtRowlengthes, int QExtRows=1, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0)=0;
    void SetSize(const T&defaultVal, std::vector<int>Ls, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    void SetSize(const T&defaultVal, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    void SetSize(const T&defaultVal, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //
    void SetSize(int QExtRows=1, int ExtRowlength=1, T*dfltVal=NULL);
    void SetSize(int*ExtRowlengthes, int QExtRows=1, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, T*dfltVal=NULL);//=0;
    void SetSize(std::vector<int>Ls, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, T*dfltVal=NULL);
    void SetSize(const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, T*dfltVal=NULL);
    void SetSize(const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, T*dfltVal=NULL);
    //
    //
    virtual void construct();
    virtual void SetNullIni()=0;
    virtual void SetNull()=0;
    void SetOne(T*val=NULL);
    virtual void SetOne(const T&val)=0;
    //
    std::vector<std::vector<T>>GetData_AsStdVector2D()const;
    std::vector<T>GetData_AsStdVector1D() const;
    //
    void Assign(const Array2D_Prototype<T>*obj);//=0;
    //
    //
    virtual void Set_Size_TypeN(int TypeN)=0;
    virtual void Set_Size(const Array2DSize& size)=0;
    virtual void Set_Size(const Array2DSize_Prototype* size)=0;
    virtual void Set_Size(int QExtRows, int RowsL)=0;
    virtual void Set_Size(int QExtRows, int*RowsLs)=0;
    virtual void Set_Size(std::vector<int>RowsLs)=0;
    virtual int Get_Size_TypeN()=0;
    //
    //
    //void Set_simplyAsDataGiven(T** data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void Set_simplyAsDataGiven(T** data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void Set_simplyAsDataGiven(T** data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    ////void Set_simplyAsDataGiven_vU(T** data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //virtual void Set_simplyAsDataGiven(T** data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);//=0;
    //virtual void Set_simplyAsDataGiven(T** data, int QExtRows, int ExtRowsL);
    //
    //virtual void Set_simplyAsDataGiven(std::vector<std::vector<T>>data, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0)=0;
    //
    //void Set_simplyAsDataGiven(T* data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void Set_simplyAsDataGiven(T* data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0)=0;
    //void Set_simplyAsDataGiven(T* data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0)=0;
    ////void Set_simplyAsDataGiven_vU(T* data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //virtual void Set_simplyAsDataGiven(T* data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);//=0;
    //virtual void Set_simplyAsDataGiven(T* data, int QExtRows, int ExtRowsL);
    ////
    //void Set_simplyAsDataGiven(std::vector<T>data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void Set_simplyAsDataGiven(std::vector<T>data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void Set_simplyAsDataGiven(std::vector<T>data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    ////void Set_simplyAsDataGiven_vU(std::vector<T>data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //virtual void Set_simplyAsDataGiven(std::vector<T>data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);//=0;
    //virtual void Set_simplyAsDataGiven(std::vector<T>data, int QExtRows, int ExtRowsL);
    ////
    //void Set_simplyAsDataGiven(const T& data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void Set_simplyAsDataGiven(const T& data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0)=0;
    //void Set_simplyAsDataGiven(const T& data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    ////void Set_simplyAsDataGiven_vU(const T& data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //virtual void Set_simplyAsDataGiven(const T& data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);//=0;
    //virtual void Set_simplyAsDataGiven(const T& data, int QExtRows, int ExtRowsL);
    //
    void Set_simplyAsDataGiven(const T&defaultVal, T** data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    void Set_simplyAsDataGiven(const T&defaultVal, T** data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    void Set_simplyAsDataGiven(const T&defaultVal, T** data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void Set_simplyAsDataGiven_vU(T** data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    virtual void Set_simplyAsDataGiven(const T&defaultVal, T** data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    virtual void Set_simplyAsDataGiven(const T&defaultVal, T** data, int QExtRows, int ExtRowsL);
    //
    virtual void Set_simplyAsDataGiven(const T&defaultVal, std::vector<std::vector<T>>data, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);//=0;
    //
    void Set_simplyAsDataGiven(const T&defaultVal, T* data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    void Set_simplyAsDataGiven(const T&defaultVal, T* data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);//=0;
    void Set_simplyAsDataGiven(const T&defaultVal, T* data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);//=0;
    //void Set_simplyAsDataGiven_vU(T* data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    virtual void Set_simplyAsDataGiven(const T&defaultVal, T* data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    virtual void Set_simplyAsDataGiven(const T&defaultVal, T* data, int QExtRows, int ExtRowsL);
    //
    void Set_simplyAsDataGiven(const T&defaultVal, std::vector<T>data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    void Set_simplyAsDataGiven(const T&defaultVal, std::vector<T>data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    void Set_simplyAsDataGiven(const T&defaultVal, std::vector<T>data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void Set_simplyAsDataGiven_vU(std::vector<T>data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    virtual void Set_simplyAsDataGiven(const T&defaultVal, std::vector<T>data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    virtual void Set_simplyAsDataGiven(const T&defaultVal, std::vector<T>data, int QExtRows, int ExtRowsL);
    //
    void Set_simplyAsDataGiven(const T&defaultVal, const T& data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    void Set_simplyAsDataGiven(const T&defaultVal, const T& data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);//=0;
    void Set_simplyAsDataGiven(const T&defaultVal, const T& data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void Set_simplyAsDataGiven_vU(const T& data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    virtual void Set_simplyAsDataGiven(const T&defaultVal, const T& data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    virtual void Set_simplyAsDataGiven(const T&defaultVal, const T& data, int QExtRows, int ExtRowsL);
    //
    //
    //
    void Set_simplyAsDataGiven(T** data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, T*dfltVal=NULL);
    void Set_simplyAsDataGiven(T** data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, T*dfltVal=NULL);
    void Set_simplyAsDataGiven(T** data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, T*dfltVal=NULL);
    //void Set_simplyAsDataGiven_vU(T** data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    void Set_simplyAsDataGiven(T** data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, T*dfltVal=NULL);
    void Set_simplyAsDataGiven(T** data, int QExtRows, int ExtRowsL, T*dfltVal=NULL);
    //
    void Set_simplyAsDataGiven(std::vector<std::vector<T>>data, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, T*dfltVal=NULL);
    //
    void Set_simplyAsDataGiven(T* data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, T*dfltVal=NULL);
    void Set_simplyAsDataGiven(T* data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, T*dfltVal=NULL);//=0;
    void Set_simplyAsDataGiven(T* data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, T*dfltVal=NULL);//=0;
    //void Set_simplyAsDataGiven_vU(T* data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    void Set_simplyAsDataGiven(T* data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, T*dfltVal=NULL);
    void Set_simplyAsDataGiven(T* data, int QExtRows, int ExtRowsL, T*dfltVal=NULL);
    //
    void Set_simplyAsDataGiven(std::vector<T>data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, T*dfltVal=NULL);
    void Set_simplyAsDataGiven(std::vector<T>data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, T*dfltVal=NULL);
    void Set_simplyAsDataGiven(std::vector<T>data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, T*dfltVal=NULL);
    //void Set_simplyAsDataGiven_vU(std::vector<T>data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    void Set_simplyAsDataGiven(std::vector<T>data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, T*dfltVal=NULL);
    void Set_simplyAsDataGiven(std::vector<T>data, int QExtRows, int ExtRowsL, T*dfltVal=NULL);
    //
    void Set_simplyAsDataGiven(const T& data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, T*dfltVal=NULL);
    void Set_simplyAsDataGiven(const T& data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, T*dfltVal=NULL);
    void Set_simplyAsDataGiven(const T& data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, T*dfltVal=NULL);
    //void Set_simplyAsDataGiven_vU(const T& data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    void Set_simplyAsDataGiven(const T& data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, T*dfltVal=NULL);
    void Set_simplyAsDataGiven(const T& data, int QExtRows, int ExtRowsL, T*dfltVal=NULL);
    //
    //virtual void Set, Add, Ins, Del Ext, Ine Row (T*row, int rowL, int rowN, rest params) et all neto =0;
};

template<typename T> Array2D_Prototype<T>::~Array2D_Prototype(){}

template<typename T> void Array2D_Prototype<T>::construct(){
    int sizeDflt=DEFAULT_SIZE;//ARR2D_SIZE_DEFAULT;
    this->SetNullIni();
    if(sizeDflt==1){
        this->SetOne();
    }
}
template<typename T> void Array2D_Prototype<T>::SetOne(T*val){
    T valInner;
    if(val!=NULL){
        valInner=(*(val));
    }
    this->SetSize(valInner, 1, 1);
    this->SetElement(valInner, 1, 1);
}
template<typename T> void Array2D_Prototype<T>::SetOne(const T&val){
    this->SetOne(&val);
}

template<typename T> bool Array2D_Prototype<T>::IsRectangularInFact()const{
    bool verdict;
    int Lmax=this->GetRowLengthMax(),
        Lmin=this->GetRowLengthMin();
    verdict=(Lmin==Lmax);
    return verdict;
}

template<typename T> std::vector<int> Array2D_Prototype<T>::GetSizeAsStdVector()const{
    std::vector<int>Ls;
    int QExtRows=this->GetQExtRows(), curL, minL, maxL;
    for(int NN=1; NN<=QExtRows; NN++){
        curL=this->GetLengthOfIneRowN(NN);
        if(NN==1 || (NN>1 && curL<minL)){
            minL=curL;
        }
        if(NN==1 || (NN>1 && curL>maxL)){
            maxL=curL;
        }
        Ls.push_back(curL);
    }
    return Ls;
}
template<typename T> int Array2D_Prototype<T>::GetRowLengthMin()const{
    int QExtRows=this->GetQExtRows(), curL, minL, maxL;
    //std::vector<int>Ls=this->GetSizeAsStdVector();
    for(int NN=1; NN<=QExtRows; NN++){
        curL=this->GetLengthOfIneRowN(NN);
        if(NN==1 || (NN>1 && curL<minL)){
            minL=curL;
        }
        if(NN==1 || (NN>1 && curL>maxL)){
            maxL=curL;
        }
        //Ls.push_back(curL);
    }
    return minL;
}
template<typename T> int Array2D_Prototype<T>::GetRowLengthMax()const{
    int QExtRows=this->GetQExtRows(), curL, minL, maxL;
    //std::vector<int>Ls=this->GetSizeAsStdVector();
    for(int NN=1; NN<=QExtRows; NN++){
        curL=this->GetLengthOfIneRowN(NN);
        if(NN==1 || (NN>1 && curL<minL)){
            minL=curL;
        }
        if(NN==1 || (NN>1 && curL>maxL)){
            maxL=curL;
        }
        //Ls.push_back(curL);
    }
    return maxL;
}
template<typename T> std::vector<int> Array2D_Prototype<T>::GetNsOfLmax()const{
    std::vector<int>NsMin, NsMax, Ls=this->GetSizeAsStdVector();
    int QExtRows=Ls.size(), curL, minL, maxL;
    for(int NN=1; NN<=QExtRows; NN++){
        curL=Ls[NN-1];
        if(NN==1 || (NN>1 && curL>maxL)){
            maxL=curL;
            NsMax.push_back(NN);
        }
        if(NN==1 || (NN>1 && curL<minL)){
            minL=curL;
            NsMin.push_back(NN);
        }
    }
    return NsMax;
}
template<typename T> std::vector<int> Array2D_Prototype<T>::GetNsOfLmin()const{
    std::vector<int>NsMin, NsMax, Ls=this->GetSizeAsStdVector();
    int QExtRows=Ls.size(), curL, minL, maxL;
    for(int NN=1; NN<=QExtRows; NN++){
        curL=Ls[NN-1];
        if(NN==1 || (NN>1 && curL>maxL)){
            maxL=curL;
            NsMax.push_back(NN);
        }
        if(NN==1 || (NN>1 && curL<minL)){
            minL=curL;
            NsMin.push_back(NN);
        }
    }
    return NsMin;
}
template<typename T> std::vector<int> Array2D_Prototype<T>::GetNsOfL(int L)const{
    std::vector<int>NsMin, NsMax, NsL, Ls=this->GetSizeAsStdVector();
    int QExtRows=Ls.size(), curL, minL, maxL;
    for(int NN=1; NN<=QExtRows; NN++){
        curL=Ls[NN-1];
        //if(NN==1 || (NN>1 && curL>maxL)){
        //   maxL=curL;
        //    NsMax.push_back(NN);
        //}
        //if(NN==1 || (NN>1 && curL<minL)){
        //    minL=curL;
        //    NsMin.push_back(NN);
        //}
        if(curL==L){
            NsL.push_back(NN);
        }
    }
    return NsL;
}
//
template<typename T> std::vector<T> Array2D_Prototype<T>::GetData_AsStdVector1D()const{
    std::vector<T> R;
    T val;
    int QExtRows=this->GetQExtRows(), Lmax=this->GetRowLengthMax(), curL;
    std::vector<int>Ls;
    if(this->IsRectangularByType()){
        for(int ERNN=1; ERNN<=QExtRows; ERNN++){
            for(int IRNN=1; IRNN<=Lmax; IRNN++){
                val=this->GetElement(ERNN, IRNN);
                R.push_back(val);
            }
        }
    }else{
        Ls=this->GetSizeAsStdVector();
        for(int ERNN=1; ERNN<=QExtRows; ERNN++){
            curL=Ls[ERNN-1];
            for(int IRNN=1; IRNN<=Lmax; IRNN++){
                val=this->GetElement(ERNN, IRNN);
                R.push_back(val);
            }
        }
    }
    return R;
}
//
template<typename T> void Array2D_Prototype<T>::Assign(const Array2D_Prototype<T>*obj){
    int QExtRowsNew=obj->GetQExtRows(),  LminNew=obj->GetRowLengthMin(),  LmaxNew=this->GetRowLengthMax(),
        QExtRowsOld=this->GetQExtRows(), LminOld=this->GetRowLengthMin(), LmaxOld=this->GetRowLengthMax(),
        curL;
    std::vector<int>LsOld, LsNew;
    T dfltVal, val;
    if(this->IsRectangularByType()){
        //NOp;
    }else{
        if(LminNew==LmaxNew){
            //NOp;
        }else{
            LsNew=obj->GetSizeAsStdVector();
        }
        for(int ERNN=1; ERNN<=QExtRowsNew; ERNN++){
            curL=obj->GetExtRowLength(ERNN);
            for(int IRNN=1; IRNN<=curL; IRNN++){
                val=obj->GetElement(ERNN, IRNN);
                this->SetElement(val, ERNN, IRNN);
            }
        }
    }
    if(!(this->IsRectangularByType()==false && LminNew!=LmaxNew)){
        this->SetSize(dfltVal, QExtRowsNew, LmaxNew);
        for(int ERNN=1; ERNN<=QExtRowsNew; ERNN++){
            curL=obj->GetExtRowLength(ERNN);
            for(int IRNN=1; IRNN<=curL; IRNN++){
                if(IRNN<=curL){
                    val=obj->GetElement(ERNN, IRNN);
                    this->SetElement(val, ERNN, IRNN);
                }else{
                    this->SetElement(val, ERNN, IRNN);
                }
            }
        }
    }
}
//
//
template<typename T> void Array2D_Prototype<T>::SetSize(std::vector<int>Ls, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->SetSize(defaultVal, Ls, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_Prototype<T>::SetSize(int*ExtRowlengthes, int QExtRows, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->SetSize(defaultVal, ExtRowlengthes, QExtRows, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_Prototype<T>::SetSize(int QExtRows, int ExtRowlength, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->SetSize(defaultVal, QExtRows, ExtRowlength);
}
template<typename T> void Array2D_Prototype<T>::SetSize(const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->SetSize(defaultVal, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_Prototype<T>::SetSize(const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->SetSize(defaultVal, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
//
template<typename T> void Array2D_Prototype<T>::SetSize(const T&defaultVal, std::vector<int>Ls, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->SetSize(defaultVal, Ls.data(), Ls.size(), ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_Prototype<T>::SetSize(const T&defaultVal, int QExtRows, int ExtRowlength){
    std::vector<int>Ls;
    for(int i=0; i<QExtRows; i++){
        Ls.push_back(ExtRowlength);
    }
    this->SetSize(defaultVal, Ls.data(), Ls.size(), 0);
}
template<typename T> void Array2D_Prototype<T>::SetSize(const T&defaultVal, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    std::vector<int>Ls=size.GetAsArrayOfExtRowsLengthes();
    this->SetSize(defaultVal, Ls.data(), Ls.size(), 0);
}
template<typename T> void Array2D_Prototype<T>::SetSize(const T&defaultVal, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    std::vector<int>Ls=size->GetAsArrayOfExtRowsLengthes();
    this->SetSize(defaultVal, Ls.data(), Ls.size(), 0);
}
//
//
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(const T&defaultVal, T** data, int QExtRows, int*Ls, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    int curL, LmaxGiven, LminGiven, ERLNew;
    T val;
    for(int i=0; i<QExtRows; i++){
        curL=Ls[i];
        if(i==0 || (i>0 && curL<LminGiven)){
            LminGiven=curL;
        }
        if(i==0 || (i>0 && curL>LmaxGiven)){
            LmaxGiven=curL;
        }
    }
    //
    if(LmaxGiven=LminGiven){
        ERLNew=LminGiven;
    }else{
        switch(ifNotRect_NonRect0_MakeRectBy_Max1Min2){

            case 1:
                ERLNew=LmaxGiven;
            break;
            case 2:
                ERLNew=LminGiven;
            break;
            default: //and case 0:
                if(this->IsRectangularByType()){
                    //NOp;
                }else{
                    //later
                }
                ERLNew=-1;
             break;
        }
    }
    //
    if(LminGiven!=LmaxGiven){
        if(this->IsRectangularByType()){
            //NOp; no Set
        }else{
            for(int i=0; i<QExtRows; i++){
                curL=Ls[i];
            }
            for(int ERNN=1; ERNN<=QExtRows; ERNN++){
                curL=Ls[ERNN-1];
                for(int IRNN=1; IRNN<=curL; IRNN++){
                    //PosNNGiven=Arr2DBy1D_PosNByCoords(ERNN, IRNN, Ls);
                    val=data[ERNN-1][IRNN-1];
                    this->SetElement(defaultVal, ERNN, IRNN);
                }
            }
        }
        this->SetSize(defaultVal, Ls, QExtRows, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
    }else{
        this->SetSize(defaultVal, QExtRows, ERLNew);
        //
        for(int ERNN=1; ERNN<=QExtRows; ERNN++){
            curL=Ls[ERNN-1];
            for(int IRNN=1; IRNN<=ERLNew; IRNN++){
                if(IRNN<=curL){
                    //PosNNGiven=Arr2DBy1D_PosNByCoords(ERNN, IRNN, Ls);
                    val=data[ERNN-1][IRNN-1];
                    this->SetElement(val, ERNN, IRNN);
                }else{
                    this->SetElement(defaultVal, ERNN, IRNN);
                }
            }
        }
    }
}
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(T** data, int QExtRows, int*Ls, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->Set_simplyAsDataGiven(defaultVal, data, QExtRows, Ls, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}

template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(const T&defaultVal, std::vector<std::vector<T>>data, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    int curL, LmaxGiven, LminGiven, ERLNew, QExtRows=data.size();
    std::vector<int>Ls;
    T val;
    for(int i=0; i<QExtRows; i++){
        curL=data[i].size();
        Ls.push_back(curL);
    }
    for(int i=0; i<QExtRows; i++){
        curL=Ls[i];
        if(i==0 || (i>0 && curL<LminGiven)){
            LminGiven=curL;
        }
        if(i==0 || (i>0 && curL>LmaxGiven)){
            LmaxGiven=curL;
        }
    }
    //
    if(LmaxGiven=LminGiven){
        ERLNew=LminGiven;
    }else{
        switch(ifNotRect_NonRect0_MakeRectBy_Max1Min2){
            //case 0:
            //    if(this->IsRectangularByType()){
            //        //NOp;
            //    }else{
            //        //later
            //    }
            //    ERLNew=-1;
            //break;
            case 1:
                ERLNew=LmaxGiven;
            break;
            case 2:
                ERLNew=LminGiven;
            break;
            default: //and case ==0
                if(this->IsRectangularByType()){
                    //NOp;
                }else{
                    //later
                }
                ERLNew=-1;
            break;
        }
    }
    //
    if(LminGiven!=LmaxGiven){
        if(this->IsRectangularByType()){
            //NOp; no Set
        }else{
            for(int i=0; i<QExtRows; i++){
                curL=Ls[i];
            }
            for(int ERNN=1; ERNN<=QExtRows; ERNN++){
                curL=Ls[ERNN-1];
                for(int IRNN=1; IRNN<=curL; IRNN++){
                    //PosNNGiven=Arr2DBy1D_PosNByCoords(ERNN, IRNN, Ls);
                    val=data[ERNN-1][IRNN-1];
                    this->SetElement(defaultVal, ERNN, IRNN);
                }
            }
        }
        this->SetSize(defaultVal, Ls, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
    }else{
        this->SetSize(defaultVal, QExtRows, ERLNew);
        //
        for(int ERNN=1; ERNN<=QExtRows; ERNN++){
            curL=Ls[ERNN-1];
            for(int IRNN=1; IRNN<=ERLNew; IRNN++){
                if(IRNN<=curL){
                    //PosNNGiven=Arr2DBy1D_PosNByCoords(ERNN, IRNN, Ls);
                    val=data[ERNN-1][IRNN-1];
                    this->SetElement(val, ERNN, IRNN);
                }else{
                    this->SetElement(defaultVal, ERNN, IRNN);
                }
            }
        }
    }
}
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(std::vector<std::vector<T>>data, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->Set_simplyAsDataGiven(defaultVal, data, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}

template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(const T&defaultVal, T* data, int QExtRows, int*Ls, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    int curL, PosNNGiven, LmaxGiven, LminGiven, ERLNew;
    T val;
    for(int i=0; i<QExtRows; i++){
        curL=Ls[i];
        if(i==0 || (i>0 && curL<LminGiven)){
            LminGiven=curL;
        }
        if(i==0 || (i>0 && curL>LmaxGiven)){
            LmaxGiven=curL;
        }
    }
    //
    if(LmaxGiven=LminGiven){
        ERLNew=LminGiven;
    }else{
        switch(ifNotRect_NonRect0_MakeRectBy_Max1Min2){
            //case 0:
            //
            //break;
            case 1:
                ERLNew=LmaxGiven;
            break;
            case 2:
                ERLNew=LminGiven;
            break;
            default:// and case==0
                if(this->IsRectangularByType()){
                    //NOp;
                }else{
                    //later
                }
                ERLNew=-1;
            break;
        }
    }
    //
    if(LminGiven!=LmaxGiven){
        if(this->IsRectangularByType()){
            //NOp; no Set
        }else{
            for(int i=0; i<QExtRows; i++){
                curL=Ls[i];
            }
            for(int ERNN=1; ERNN<=QExtRows; ERNN++){
                curL=Ls[ERNN-1];
                for(int IRNN=1; IRNN<=curL; IRNN++){
                    PosNNGiven=Arr2DBy1D_PosNByCoords(ERNN, IRNN, QExtRows, Ls);
                    val=data[PosNNGiven-1];
                    this->SetElement(defaultVal, ERNN, IRNN);
                }
            }
        }
        this->SetSize(defaultVal, Ls, QExtRows, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
    }else{
        this->SetSize(defaultVal, QExtRows, ERLNew);
        //
        for(int ERNN=1; ERNN<=QExtRows; ERNN++){
            curL=Ls[ERNN-1];
            for(int IRNN=1; IRNN<=ERLNew; IRNN++){
                if(IRNN<=curL){
                    PosNNGiven=Arr2DBy1D_PosNByCoords(ERNN, IRNN, QExtRows, Ls);
                    val=data[PosNNGiven-1];
                    this->SetElement(val, ERNN, IRNN);
                }else{
                    this->SetElement(defaultVal, ERNN, IRNN);
                }
            }
        }
    }
}
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(T* data, int QExtRows, int*Ls, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->Set_simplyAsDataGiven(defaultVal, data, QExtRows, Ls, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}

template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(const T&defaultVal, std::vector<T>data, int QExtRows, int*Ls, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->Set_simplyAsDataGiven(defaultVal, data.data(), QExtRows, Ls, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(std::vector<T>data, int QExtRows, int*Ls, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->Set_simplyAsDataGiven(defaultVal, data.data(), QExtRows, Ls, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(const T&defaultVal, const T&data, int QExtRows, int*Ls, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    std::vector<T>vals;
    T val;
    int curL, QElts;
    for(int ERNN=1; ERNN<=QExtRows; ERNN++){
        curL=Ls[ERNN];
        for(int IRNN=1; IRNN<=curL; IRNN++){
            vals.push_back(data);
        }
    }
    this->Set_simplyAsDataGiven(defaultVal, vals, QExtRows, Ls, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(const T&data, int QExtRows, int*Ls, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->Set_simplyAsDataGiven(defaultVal, data, QExtRows, Ls, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
//
//T**data
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(const T&defaultVal, T** data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    std::vector<int>Ls=size.GetAsArrayOfExtRowsLengthes();
    this->Set_simplyAsDataGiven(defaultVal, data, Ls, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(T** data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->Set_simplyAsDataGiven(defaultVal, data, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(const T&defaultVal, T** data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    std::vector<int>Ls=size->GetAsArrayOfExtRowsLengthes();
    this->Set_simplyAsDataGiven(defaultVal, data, Ls, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(T** data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->Set_simplyAsDataGiven(defaultVal, data, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(const T&defaultVal, T** data, int QExtRows, int ExtRowsLs){
    std::vector<int>Ls;
    int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0;
    for(int i=0; i<QExtRows; i++){
        Ls.push_back(ExtRowsLs);
    }
    this->SetSize(defaultVal, Ls, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(T** data, int QExtRows, int ExtRowsLs, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->SetSize(defaultVal, QExtRows, ExtRowsLs);
}
//
//T*data
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(const T&defaultVal, T* data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    std::vector<int>Ls=size.GetAsArrayOfExtRowsLengthes();
    this->Set_simplyAsDataGiven(defaultVal, data, Ls, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(T* data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->Set_simplyAsDataGiven(defaultVal, data, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(const T&defaultVal, T* data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    std::vector<int>Ls=size->GetAsArrayOfExtRowsLengthes();
    this->Set_simplyAsDataGiven(defaultVal, data, Ls, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(T* data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->Set_simplyAsDataGiven(defaultVal, data, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(const T&defaultVal, T* data, int QExtRows, int ExtRowsL){
    std::vector<int>Ls;
    //int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0;
    for(int i=0; i<QExtRows; i++){
        Ls.push_back(ExtRowsL);
    }
    //this->SetSize(defaultVal, data, QExtRows, ExtRowsL);
    this->SetSize(defaultVal, QExtRows, ExtRowsL);
}
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(T* data, int QExtRows, int ExtRowsLs, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->SetSize(defaultVal, data, QExtRows, ExtRowsLs);
}
//
// std::vector<T>data
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(const T&defaultVal, std::vector<T>data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    std::vector<int>Ls=size.GetAsArrayOfExtRowsLengthes();
    this->Set_simplyAsDataGiven(defaultVal, data, Ls, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven( std::vector<T>data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->Set_simplyAsDataGiven(defaultVal, data, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(const T&defaultVal,  std::vector<T>data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    std::vector<int>Ls=size->GetAsArrayOfExtRowsLengthes();
    this->Set_simplyAsDataGiven(defaultVal, data, Ls, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven( std::vector<T>data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->Set_simplyAsDataGiven(defaultVal, data, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(const T&defaultVal,  std::vector<T>data, int QExtRows, int ExtRowsLs){
    std::vector<int>Ls;
    int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0;
    for(int i=0; i<QExtRows; i++){
        Ls.push_back(ExtRowsLs);
    }
    this->SetSize(defaultVal, Ls);
}
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven( std::vector<T>data, int QExtRows, int ExtRowsLs, T*dfltVal){
    T defaultVal;
    int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->SetSize(defaultVal, QExtRows, ExtRowsLs);
}
//
// const T& data
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(const T&defaultVal, const T& data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    std::vector<int>Ls=size.GetAsArrayOfExtRowsLengthes();
    this->Set_simplyAsDataGiven(defaultVal, data, Ls, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven( const T& data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->Set_simplyAsDataGiven(defaultVal, data, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(const T&defaultVal,  const T& data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    std::vector<int>Ls=size->GetAsArrayOfExtRowsLengthes();
    this->Set_simplyAsDataGiven(defaultVal, data, Ls, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven( const T& data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->Set_simplyAsDataGiven(defaultVal, data, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(const T&defaultVal,  const T& data, int QExtRows, int ExtRowsL){
    std::vector<int>Ls;
    int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0;
    for(int i=0; i<QExtRows; i++){
        Ls.push_back(ExtRowsL);
    }
    this->SetSize(defaultVal, Ls, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven( const T& data, int QExtRows, int ExtRowsLs, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->SetSize(defaultVal, QExtRows, ExtRowsLs);
}


//
//
template <class T> class Array2D_V1: public Array2D_Prototype<T>{
    std::vector<T>data;
    Array2DSize size;
  public:
    Array2D_V1();
    Array2D_V1(T** data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    Array2D_V1(T** data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    Array2D_V1(T** data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void Set_simplyAsDataGiven_vU(T** data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    Array2D_V1(T** data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);//=0;
    Array2D_V1(T** data, int QExtRows, int ExtRowsL);
    //
    Array2D_V1(std::vector<std::vector<T>>data, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //
    Array2D_V1(T* data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    Array2D_V1(T* data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    Array2D_V1(T* data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void Set_simplyAsDataGiven_vU(T* data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    Array2D_V1(T* data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);//=0;
    Array2D_V1(T* data, int QExtRows, int ExtRowsL);
    //
    Array2D_V1(std::vector<T>data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    Array2D_V1(std::vector<T>data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    Array2D_V1(std::vector<T>data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void Set_simplyAsDataGiven_vU(std::vector<T>data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    Array2D_V1(std::vector<T>data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);//=0;
    Array2D_V1(std::vector<T>data, int QExtRows, int ExtRowsL);
    //
    Array2D_V1(const T& data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    Array2D_V1(const T& data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    Array2D_V1(const T& data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void Set_simplyAsDataGiven_vU(const T& data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    Array2D_V1(const T& data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);//=0;
    Array2D_V1(const T& data, int QExtRows, int ExtRowsL);
    //
    ~Array2D_V1();
    //
    //
    virtual void Set_Size_TypeN(int TypeN);
    virtual void Set_Size(const Array2DSize& size);
    virtual void Set_Size(const Array2DSize_Prototype* size);
    virtual void Set_Size(int QExtRows, int RowsL);
    virtual void Set_Size(int QExtRows, int*RowsLs);
    virtual void Set_Size(std::vector<int>RowsLs);
    virtual int Get_Size_TypeN();
    //
    //
    //virtual ~Array2D_Prototype();
    virtual int GetTypeN() const;//=0;
    //virtual void SetTypeN(int typeN=0);//=0;
    virtual int GetQExtRows() const;// =0;
    virtual int GetExtRowLength(int rowN=-1)const;// =0;
    virtual T GetElement(int ExtRowN, int inRowPosN)const;// =0;
    virtual const T* GetPointerToElement(int ExtRowN, int inRowPosN)const;// =0;
    virtual void SetElement(const T& val, int ExtRowN, int inRowPosN);//=0;
    virtual bool IsRectangularInFact() const ;
    virtual bool IsRectangularByType() const;// =0;
    virtual int GetLengthOfIneRowN(int N=-1) const;//=0;
    virtual std::vector<int> GetSizeAsStdVector() const;
    virtual Array2DSize GetSize()const;//=0;
    virtual int GetRowLengthMax() const ;
    virtual int GetRowLengthMin() const ;
    //std::vector<int>GetNsOfLmax() const;
    //std::vector<int>GetNsOfLmin()const;
    //std::vector<int>GetNsOfL(int L) const ;
    //
    virtual void SetSize(const T& defaultVal, int QExtRows=1, int ExtRowlength=1);
    virtual void SetSize(const T& defaultVal, int*ExtRowlengthes, int QExtRows=1, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void SetSize(std::vector<int>Ls, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void SetSize(const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void SetSize(const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //
    virtual void construct();
    virtual void SetNullIni();
    virtual void SetNull();
    //void SetOne(T*val=NULL);
    virtual void SetOne(const T&val);
    //
    //std::vector<std::vector<T>>GetData_AsStdVector2D();
    //std::vector<T>GetData_AsStdVector1D();
    //
    //void Assign(const Array2D_Prototype<T>*obj);
    //

    //void Set_simplyAsDataGiven(T** data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void Set_simplyAsDataGiven(T** data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void Set_simplyAsDataGiven(T** data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    ////void Set_simplyAsDataGiven_vU(T** data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    virtual void Set_simplyAsDataGiven(const T& defaultVal, T** data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    virtual void Set_simplyAsDataGiven(const T& defaultVal, T** data, int QExtRows, int ExtRowsL);
    //
    virtual void Set_simplyAsDataGiven(const T& defaultVal, std::vector<std::vector<T>>data, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //
    //void Set_simplyAsDataGiven(T* data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void Set_simplyAsDataGiven(T* data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0)=0;
    //void Set_simplyAsDataGiven(T* data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0)=0;
    ////void Set_simplyAsDataGiven_vU(T* data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    virtual void Set_simplyAsDataGiven(const T& defaultVal, T* data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    virtual void Set_simplyAsDataGiven(const T& defaultVal, T* data, int QExtRows, int ExtRowsL);
    //
    //void Set_simplyAsDataGiven(std::vector<T>data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void Set_simplyAsDataGiven(std::vector<T>data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void Set_simplyAsDataGiven(std::vector<T>data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    ////void Set_simplyAsDataGiven_vU(std::vector<T>data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    virtual void Set_simplyAsDataGiven(const T& defaultVal, std::vector<T>data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    virtual void Set_simplyAsDataGiven(const T& defaultVal, std::vector<T>data, int QExtRows, int ExtRowsL);
    //
    //void Set_simplyAsDataGiven(const T& data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void Set_simplyAsDataGiven(const T& data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0)=0;
    //void Set_simplyAsDataGiven(const T& data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    ////void Set_simplyAsDataGiven_vU(const T& data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    virtual void Set_simplyAsDataGiven(const T& defaultVal, const T& data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);//=0;
    virtual void Set_simplyAsDataGiven(const T& defaultVal, const T& data, int QExtRows, int ExtRowsL);
    //
    //virtual void Set, Add, Ins, Del Ext, Ine Row (T*row, int rowL, int rowN, rest params) et all neto =0;
};
//
//template<typename T> void Array2D_V1_Rect<T>::Set_simplyAsDataGiven(const T&val){}

template<typename T> Array2D_V1<T>::Array2D_V1(){
    this->construct();
}
template<typename T> Array2D_V1<T>::Array2D_V1(T** data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->construct();
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2<0 || ifNotRect_NonRect0_MakeRectBy_Max1Min2>2){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=2;
    }
    this->Set_simplyAsDataGiven(data, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> Array2D_V1<T>::Array2D_V1(T** data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->construct();
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2<0 || ifNotRect_NonRect0_MakeRectBy_Max1Min2>2){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=2;
    }
    this->Set_simplyAsDataGiven(data, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> Array2D_V1<T>::Array2D_V1(T** data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->construct();
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2<0 || ifNotRect_NonRect0_MakeRectBy_Max1Min2>2){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=2;
    }
    this->Set_simplyAsDataGiven(data, ExtRowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> Array2D_V1<T>::Array2D_V1(T** data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->construct();
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2<0 || ifNotRect_NonRect0_MakeRectBy_Max1Min2>2){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=2;
    }
    this->Set_simplyAsDataGiven(data, QExtRows, ExtRowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> Array2D_V1<T>::Array2D_V1(std::vector<std::vector<T>>data, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->construct();
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2<0 || ifNotRect_NonRect0_MakeRectBy_Max1Min2>2){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=2;
    }
    this->Set_simplyAsDataGiven(data, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> Array2D_V1<T>::Array2D_V1(T* data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->construct();
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2<0 || ifNotRect_NonRect0_MakeRectBy_Max1Min2>2){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=2;
    }
    this->Set_simplyAsDataGiven(data, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> Array2D_V1<T>::Array2D_V1(T* data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->construct();
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2<0 || ifNotRect_NonRect0_MakeRectBy_Max1Min2>2){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=2;
    }
    this->Set_simplyAsDataGiven(data, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> Array2D_V1<T>::Array2D_V1(T* data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->construct();
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2<0 || ifNotRect_NonRect0_MakeRectBy_Max1Min2>2){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=2;
    }
    this->Set_simplyAsDataGiven(data, ExtRowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> Array2D_V1<T>::Array2D_V1(T* data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->construct();
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2<0 || ifNotRect_NonRect0_MakeRectBy_Max1Min2>2){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=2;
    }
    this->Set_simplyAsDataGiven(data, QExtRows, ExtRowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> Array2D_V1<T>::Array2D_V1(T* data, int QExtRows, int ExtRowsL){
    this->construct();
    this->Set_simplyAsDataGiven(data, QExtRows, ExtRowsL);
}
template<typename T> Array2D_V1<T>::Array2D_V1(std::vector<T>data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->construct();
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2<0 || ifNotRect_NonRect0_MakeRectBy_Max1Min2>2){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=2;
    }
    this->Set_simplyAsDataGiven(data, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> Array2D_V1<T>::Array2D_V1(std::vector<T>data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->construct();
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2<0 || ifNotRect_NonRect0_MakeRectBy_Max1Min2>2){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=2;
    }
    this->Set_simplyAsDataGiven(data, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> Array2D_V1<T>::Array2D_V1(std::vector<T>data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->construct();
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2<0 || ifNotRect_NonRect0_MakeRectBy_Max1Min2>2){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=2;
    }
    this->Set_simplyAsDataGiven(data, ExtRowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> Array2D_V1<T>::Array2D_V1(std::vector<T>data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->construct();
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2<0 || ifNotRect_NonRect0_MakeRectBy_Max1Min2>2){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=2;
    }
    this->Set_simplyAsDataGiven(data, QExtRows, ExtRowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> Array2D_V1<T>::Array2D_V1(std::vector<T>data, int QExtRows, int ExtRowsL){
    this->construct();
    this->Set_simplyAsDataGiven(data, QExtRows, ExtRowsL);
}
template<typename T> Array2D_V1<T>::Array2D_V1(const T& data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->construct();
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2<0 || ifNotRect_NonRect0_MakeRectBy_Max1Min2>2){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=2;
    }
    this->Set_simplyAsDataGiven(data, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> Array2D_V1<T>::Array2D_V1(const T& data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->construct();
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2<0 || ifNotRect_NonRect0_MakeRectBy_Max1Min2>2){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=2;
    }
    this->Set_simplyAsDataGiven(data, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> Array2D_V1<T>::Array2D_V1(const T& data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->construct();
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2<0 || ifNotRect_NonRect0_MakeRectBy_Max1Min2>2){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=2;
    }
    this->Set_simplyAsDataGiven(data, ExtRowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> Array2D_V1<T>::Array2D_V1(const T& data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->construct();
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2<0 || ifNotRect_NonRect0_MakeRectBy_Max1Min2>2){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=2;
    }
    this->Set_simplyAsDataGiven(data, QExtRows, ExtRowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> Array2D_V1<T>::Array2D_V1(const T& data, int QExtRows, int ExtRowsL){
    this->construct();
    this->Set_simplyAsDataGiven(data, QExtRows, ExtRowsL);
}
//
template<typename T> Array2D_V1<T>::~Array2D_V1(){
    this->data.clear();
    this->size.SetNull();
}
//
template<typename T> int Array2D_V1<T>::GetTypeN() const{
    return ARR2D_TYPE_V1D_VAR_LEN;
}
template<typename T> int Array2D_V1<T>::GetQExtRows() const{
    return this->size.GetQExtRows();
}
template<typename T> int Array2D_V1<T>::GetExtRowLength(int rowN) const{
    return this->size.GetRowLength(rowN);
}
template<typename T> T Array2D_V1<T>::GetElement(int ExtRowN, int inRowPosN) const{
    int PosNN=Arr2DBy1D_PosNByCoords(ExtRowN, inRowPosN, this->GetQExtRows(), this->GetRowLengthMax());
    return this->data[PosNN-1];
}
template<typename T> const T* Array2D_V1<T>::GetPointerToElement(int ExtRowN, int inRowPosN) const{
    int PosNN=Arr2DBy1D_PosNByCoords(ExtRowN, inRowPosN, this->GetQExtRows(), this->GetRowLengthMax());
    const T*ptr;
    //T*ptr;
    ptr=&(this->data[PosNN-1]);
    return ptr;
}
template<typename T> void Array2D_V1<T>::SetElement(const T& val, int ExtRowN, int inRowPosN){
    int QExtRows=this->GetQExtRows(), Lmax=this->GetRowLengthMax(), PosNN=0;
    std::vector<int>Ls;
    if(this->IsRectangularInFact()){
        PosNN=Arr2DBy1D_PosNByCoords(ExtRowN, inRowPosN, QExtRows, Lmax);
    }else{
        Ls=this->GetSizeAsStdVector();
        PosNN=Arr2DBy1D_PosNByCoords(ExtRowN, inRowPosN, QExtRows, Ls.data());
    }
    this->data[PosNN-1]=val;
}
template<typename T> bool Array2D_V1<T>::IsRectangularInFact()const{
    return Array2D_Prototype<T>::IsRectangularInFact();
    //return this->size.IsRectangularInFact();
}
template<typename T> bool Array2D_V1<T>::IsRectangularByType()const{
    return this->size.IsRectangularByType();
}
template<typename T> int  Array2D_V1<T>::GetLengthOfIneRowN(int N)const{
    return this->size.GetIneRowLength(N);
}
template<typename T> std::vector<int>  Array2D_V1<T>::GetSizeAsStdVector()const{
    return this->size.GetAsArrayOfExtRowsLengthes();
}
template<typename T> Array2DSize  Array2D_V1<T>::GetSize()const{
    return this->size;
}
template<typename T> int  Array2D_V1<T>::GetRowLengthMin()const{
    return this->size.GetRowLengthMin();
}
template<typename T> int  Array2D_V1<T>::GetRowLengthMax()const{
    return this->size.GetRowLengthMax();
}
//
template<typename T> void  Array2D_V1<T>::SetSize(const T& defaultVal, int QExtRows, int ExtRowlength){
    //T val;
    int QElementsOld=this->GetQExtRows(), QElementsNew=QExtRows*ExtRowlength;
    if(QElementsOld<QElementsNew){
        for(int i=0; i<(QElementsNew-QElementsOld); i++){
            this->data.push_back(defaultVal);
        }
    }else if(QElementsOld>QElementsNew){
        for(int i=0; i<(QElementsOld-QElementsNew); i++){
            this->data.pop_back();
        }
    }
    this->size.Set(ExtRowlength, QExtRows, Arr2DSize_Rect_TypeN);
}
template<typename T> void  Array2D_V1<T>::SetSize(const T& defaultVal, int*ExtRowlengthes, int QExtRows, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    T val;
    int QElementsOld=this->GetQExtRows(), QElementsNew=0, curL;
    for(int i=0; i<QExtRows; i++){
        curL=ExtRowlengthes[i];
        QElementsNew+=curL;
    }
    if(QElementsOld<QElementsNew){
        for(int i=0; i<(QElementsNew-QElementsOld); i++){
            this->data.push_back(val);
        }
    }else if(QElementsOld>QElementsNew){
        for(int i=0; i<(QElementsOld-QElementsNew); i++){
            this->data.pop_back();
        }
    }
    //this->size.Set(defaultVal, ExtRowlengthes, QExtRows, Arr2DSize_Rect_TypeN);
    this->size.Set(ExtRowlengthes, QExtRows, Arr2DSize_Rect_TypeN);
}
//
template<typename T> void  Array2D_V1<T>::construct(){
    T val;
    int minQAllowed=DEFAULT_SIZE;
    this->SetNullIni();
    if(minQAllowed==1){
        this->SetOne(val);
    }
}
template<typename T> void  Array2D_V1<T>::SetNull(){
    this->data.clear();
    this->size.SetNull();
}
template<typename T> void  Array2D_V1<T>::SetNullIni(){
    this->SetNull();
}
template<typename T> void  Array2D_V1<T>::SetOne(const T& val){
    this->data.clear();
    this->data.push_back(val);
    this->size.SetOne();
}
///
//
//void Set_simplyAsDataGiven(T** data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2);
template<typename T> void Array2D_V1<T>::Set_simplyAsDataGiven(const T& defaultVal, T** data, int QExtRowsGiven, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    std::vector<T>dataOld=this->GetData_AsStdVector1D();
    bool IfNotValsOfGivenRow_DefaultNotOwn=false;
    T val;
    Array2DSize sizeNew=this->size.Set_simplyAsDataGiven_NewSize(ExtRowsLs, QExtRowsGiven, ifNotRect_NonRect0_MakeRectBy_Max1Min2, IfNotValsOfGivenRow_DefaultNotOwn);
    Coords2DInt CoordsNew, CoordsOld;
    int curLNew, curLOld, QExtRowsNew=sizeNew.GetQExtRows(), QExtRowsOld=this->GetQExtRows(), PosNN;
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=2 && ifNotRect_NonRect0_MakeRectBy_Max1Min2!=0){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=1;
    }
    //
    this->Array2D_Prototype<T>::SetSize(defaultVal, sizeNew, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
    for(int ERNN=1; ERNN<=QExtRowsNew; ERNN++){
        curLNew=sizeNew.GetRowLength(ERNN);
        for(int IRNN=1; IRNN<=curLNew; IRNN++){
            CoordsNew.set(ERNN, IRNN);
            CoordsOld=this->size.Set_simplyAsDataGiven_Arr2DCoordsNewToOld(CoordsNew, ExtRowsLs, QExtRowsGiven, ifNotRect_NonRect0_MakeRectBy_Max1Min2, IfNotValsOfGivenRow_DefaultNotOwn);
            if(CoordsOld.x>=1 && CoordsOld.x<=QExtRowsGiven){
                if(sizeNew.IsRectangularByType()==false){
                    PosNN=Arr2DBy1D_PosNByCoords(CoordsOld.x, CoordsOld.y, sizeNew.GetAsArrayOfExtRowsLengthes());
                }else{
                    PosNN=Arr2DBy1D_PosNByCoords(CoordsOld.x, CoordsOld.y, sizeNew.GetQExtRows(), sizeNew.GetRowLengthMax());
                }
                val=data[ERNN-1][IRNN-1];
            }else if(CoordsOld.x==Arr2D_DataType_DefaultVals){
                val=defaultVal;
            }
            this->SetElement(val, ERNN, IRNN);
        }
    }
}//fn
template<typename T> void Array2D_V1<T>::Set_simplyAsDataGiven(const T& defaultVal, T* data, int QExtRowsGiven, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    std::vector<T>dataOld=this->GetData_AsStdVector1D();
    bool IfNotValsOfGivenRow_DefaultNotOwn=false;
    T val;
    Array2DSize sizeNew=this->size.Set_simplyAsDataGiven_NewSize(ExtRowsLs, QExtRowsGiven, ifNotRect_NonRect0_MakeRectBy_Max1Min2, IfNotValsOfGivenRow_DefaultNotOwn);
    Coords2DInt CoordsNew, CoordsOld;
    int curLNew, curLOld, QExtRowsNew=sizeNew.GetQExtRows(), QExtRowsOld=this->GetQExtRows(), PosNNNew, PosNNOld;
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=2 && ifNotRect_NonRect0_MakeRectBy_Max1Min2!=0){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=1;
    }
    this->Array2D_Prototype<T>::SetSize(defaultVal, sizeNew, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
    for(int ERNN=1; ERNN<=QExtRowsNew; ERNN++){
        curLNew=sizeNew.GetRowLength(ERNN);
        for(int IRNN=1; IRNN<=curLNew; IRNN++){
            CoordsNew.set(ERNN, IRNN);
            CoordsOld=this->size.Set_simplyAsDataGiven_Arr2DCoordsNewToOld(CoordsNew, ExtRowsLs, QExtRowsGiven, ifNotRect_NonRect0_MakeRectBy_Max1Min2, IfNotValsOfGivenRow_DefaultNotOwn);
            if(CoordsOld.x>=1 && CoordsOld.x<=QExtRowsGiven){
                if(sizeNew.IsRectangularByType()==false){
                    PosNNNew=Arr2DBy1D_PosNByCoords(CoordsOld.x, CoordsOld.y, sizeNew.GetAsArrayOfExtRowsLengthes());
                }else{
                    PosNNNew=Arr2DBy1D_PosNByCoords(CoordsOld.x, CoordsOld.y, sizeNew.GetQExtRows(), sizeNew.GetRowLengthMax());
                }
                val=data[PosNNNew-1];
            }else if(CoordsOld.x==Arr2D_DataType_DefaultVals){
                val=defaultVal;
            }
            this->SetElement(val, ERNN, IRNN);
        }
    }
}//fn
template<typename T> void Array2D_V1<T>::Set_simplyAsDataGiven(const T& defaultVal, std::vector<T>data, int QExtRowsGiven, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    std::vector<T>dataOld=this->GetData_AsStdVector1D();
    bool IfNotValsOfGivenRow_DefaultNotOwn=false;
    T val;
    int QEltsNewRe=data.size();
    Array2DSize sizeNew=this->size.Set_simplyAsDataGiven_NewSize(ExtRowsLs, QExtRowsGiven, ifNotRect_NonRect0_MakeRectBy_Max1Min2, IfNotValsOfGivenRow_DefaultNotOwn);
    Coords2DInt CoordsNew, CoordsOld;
    int curLNew, curLOld, QExtRowsNew=sizeNew.GetQExtRows(), QExtRowsOld=this->GetQExtRows(), PosNNNew, PosNNOld;
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=2 && ifNotRect_NonRect0_MakeRectBy_Max1Min2!=0){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=1;
    }
    this->Array2D_Prototype<T>::SetSize(defaultVal, sizeNew, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
    for(int ERNN=1; ERNN<=QExtRowsNew; ERNN++){
        curLNew=sizeNew.GetRowLength(ERNN);
        for(int IRNN=1; IRNN<=curLNew; IRNN++){
            CoordsNew.set(ERNN, IRNN);
            CoordsOld=this->size.Set_simplyAsDataGiven_Arr2DCoordsNewToOld(CoordsNew, ExtRowsLs, QExtRowsGiven, ifNotRect_NonRect0_MakeRectBy_Max1Min2, IfNotValsOfGivenRow_DefaultNotOwn);
            if(CoordsOld.x>=1 && CoordsOld.x<=QExtRowsGiven){
                if(sizeNew.IsRectangularByType()==false){
                    PosNNNew=Arr2DBy1D_PosNByCoords(CoordsOld.x, CoordsOld.y, sizeNew.GetAsArrayOfExtRowsLengthes());
                }else{
                    PosNNNew=Arr2DBy1D_PosNByCoords(CoordsOld.x, CoordsOld.y, sizeNew.GetQExtRows(), sizeNew.GetRowLengthMax());
                }
                if(PosNNNew<=QEltsNewRe){
                    val=data[PosNNNew-1];
                }else{
                    val=defaultVal;
                }
            }else if(CoordsOld.x==Arr2D_DataType_DefaultVals){
                val=defaultVal;
            }
            this->SetElement(val, ERNN, IRNN);
        }
    }
}//fn
template<typename T> void Array2D_V1<T>::Set_simplyAsDataGiven(const T& defaultVal, std::vector<std::vector<T>> data,  int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    std::vector<T>dataOld=this->GetData_AsStdVector1D();
    bool IfNotValsOfGivenRow_DefaultNotOwn=false;
    int QExtRowsGiven=data.size(), curL;
    std::vector<int>ExtRowsLs;
    for(int i=0; i<QExtRowsGiven; i++){
        curL=data[i].size();
        ExtRowsLs.push_back(curL);
    }
    T val;
    //Array2DSize                  Set_simplyAsDataGiven_NewSize(int* extRowsLengthes, int QExtRows, int ifNotRect_NonRect0_MakeRectBy_Min1Max2, bool IfNotValsOfGivenRow_DefaultNotOwn);
    Array2DSize sizeNew=this->size.Set_simplyAsDataGiven_NewSize(ExtRowsLs.data(),           ExtRowsLs.size(),     ifNotRect_NonRect0_MakeRectBy_Max1Min2,      IfNotValsOfGivenRow_DefaultNotOwn);
    Coords2DInt CoordsNew, CoordsOld;
    int curLNew, curLOld, QExtRowsNew=sizeNew.GetQExtRows(), QExtRowsOld=this->GetQExtRows(), PosNN;
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=2 && ifNotRect_NonRect0_MakeRectBy_Max1Min2!=0){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=1;
    }
    for(int i=0; i<QExtRowsGiven; i++){
        curL=data[i-1].size();
        ExtRowsLs.push_back(curL);
    }
    this->Array2D_Prototype<T>::SetSize(defaultVal, sizeNew, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
    for(int ERNN=1; ERNN<=QExtRowsNew; ERNN++){
        curLNew=sizeNew.GetRowLength(ERNN);
        curL=ExtRowsLs[ERNN-1];
        for(int IRNN=1; IRNN<=curLNew; IRNN++){
            CoordsNew.set(ERNN, IRNN);
            CoordsOld=this->size.Set_simplyAsDataGiven_Arr2DCoordsNewToOld(CoordsNew, ExtRowsLs.data(), ExtRowsLs.size(), ifNotRect_NonRect0_MakeRectBy_Max1Min2, IfNotValsOfGivenRow_DefaultNotOwn);
            if(CoordsOld.x>=1 && CoordsOld.x<=QExtRowsGiven){
                if(sizeNew.IsRectangularByType()==false){
                    PosNN=Arr2DBy1D_PosNByCoords(CoordsOld.x, CoordsOld.y, sizeNew.GetAsArrayOfExtRowsLengthes());
                }else{
                    PosNN=Arr2DBy1D_PosNByCoords(CoordsOld.x, CoordsOld.y, sizeNew.GetQExtRows(), sizeNew.GetRowLengthMax());
                }
                if(IRNN>=1 && IRNN<=curL){
                    val=data[ERNN-1][IRNN-1];
                }else{
                    val=defaultVal;
                }
            }else if(CoordsOld.x==Arr2D_DataType_DefaultVals){
                val=defaultVal;
            }
            this->SetElement(val, ERNN, IRNN);
        }
    }
}//fn
template<typename T> void Array2D_V1<T>::Set_simplyAsDataGiven(const T& defaultVal, const T& data, int QExtRowsGiven, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    std::vector<T>dataOld=this->GetData_AsStdVector1D();
    bool IfNotValsOfGivenRow_DefaultNotOwn=false;
    T val;
    Array2DSize sizeNew=this->size.Set_simplyAsDataGiven_NewSize(ExtRowsLs, QExtRowsGiven, ifNotRect_NonRect0_MakeRectBy_Max1Min2, IfNotValsOfGivenRow_DefaultNotOwn);
    Coords2DInt CoordsNew, CoordsOld;
    int curLNew, curLOld, QExtRowsNew=sizeNew.GetQExtRows(), QExtRowsOld=this->GetQExtRows(), PosNN;
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=2 && ifNotRect_NonRect0_MakeRectBy_Max1Min2!=0){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=1;
    }
    this->Array2D_Prototype<T>::SetSize(defaultVal, sizeNew, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
    for(int ERNN=1; ERNN<=QExtRowsNew; ERNN++){
        curLNew=sizeNew.GetRowLength(ERNN);
        for(int IRNN=1; IRNN<=curLNew; IRNN++){
            CoordsNew.set(ERNN, IRNN);
            CoordsOld=this->size.Set_simplyAsDataGiven_Arr2DCoordsNewToOld(CoordsNew, ExtRowsLs, QExtRowsGiven, ifNotRect_NonRect0_MakeRectBy_Max1Min2, IfNotValsOfGivenRow_DefaultNotOwn);
            if(CoordsOld.x>=1 && CoordsOld.x<=QExtRowsGiven){
                //if(sizeNew.IsRectangularByType()==false){
                //    PosNN=Arr2DBy1D_PosNByCoords(CoordsOld.x, CoordsOld.y, sizeNew.GetAsArrayOfExtRowsLengthes());
                //}else{
                //    PosNN=Arr2DBy1D_PosNByCoords(CoordsOld.x, CoordsOld.y, sizeNew.GetQExtRows(), sizeNew.GetRowLengthMax());
                //}
                val=data;
            }else if(CoordsOld.x==Arr2D_DataType_DefaultVals){
                val=defaultVal;
            }
            this->SetElement(val, ERNN, IRNN);
        }
    }
}//fn
template<typename T> void Array2D_V1<T>::Set_simplyAsDataGiven(const T& defaultVal, T** data, int QExtRowsGiven, int ExtRowsL){
    std::vector<T>dataOld=this->GetData_AsStdVector1D();
    bool IfNotValsOfGivenRow_DefaultNotOwn=false;
    T val;
    Array2DSize sizeNew;
    //=this->size.Set_simplyAsDataGiven_NewSize(QExtRowsGiven, ExtRowsL);//, ifNotRect_NonRect0_MakeRectBy_Max1Min2, IfNotValsOfGivenRow_DefaultNotOwn);
    sizeNew.Set(QExtRowsGiven, ExtRowsL);
    Coords2DInt CoordsNew, CoordsOld;
    int curLNew, curLOld, QExtRowsNew=sizeNew.GetQExtRows(), QExtRowsOld=this->GetQExtRows(), PosNN;
    //
    this->Array2D_Prototype<T>::SetSize(defaultVal, sizeNew);
    for(int ERNN=1; ERNN<=QExtRowsNew; ERNN++){
        for(int IRNN=1; IRNN<=ExtRowsL; IRNN++){
            val=data[ERNN-1][IRNN-1];
            this->SetElement(val, ERNN, IRNN);
        }
    }
}//fn
template<typename T> void Array2D_V1<T>::Set_simplyAsDataGiven(const T& defaultVal, T* data, int QExtRowsGiven, int ExtRowsL){
    T val;
    int posNN=0;
    this->Array2D_Prototype<T>::SetSize(defaultVal, QExtRowsGiven, ExtRowsL);
    for(int ERNN=1; ERNN<=QExtRowsGiven; ERNN++){
        for(int IRNN=1; IRNN<=ExtRowsL; IRNN++){
            posNN=Arr2DBy1D_PosNByCoords(ERNN, IRNN, QExtRowsGiven, ExtRowsL);
            val=data[posNN-1];
            this->SetElement(val, ERNN, IRNN);
        }
    }
}//fn
template<typename T> void Array2D_V1<T>::Set_simplyAsDataGiven(const T& defaultVal, std::vector<T>data, int QExtRowsGiven, int ExtRowsL){
    this->Set_simplyAsDataGiven(defaultVal, data.data(), QExtRowsGiven, ExtRowsL);
}//fn
template<typename T> void Array2D_V1<T>::Set_simplyAsDataGiven(const T& defaultVal, const T& data, int QExtRowsGiven, int ExtRowsL){
    this->Array2D_Prototype<T>::SetSize(defaultVal, QExtRowsGiven, ExtRowsL);
    for(int ERNN=1; ERNN<=QExtRowsGiven; ERNN++){
        for(int IRNN=1; IRNN<=ExtRowsL; IRNN++){
            this->SetElement(data, ERNN, IRNN);
        }
    }
}//fn
//
//
template<typename T> void Array2D_V1<T>::Set_Size_TypeN(int TypeN){
    this->size.SetTypeN(TypeN);
}
template<typename T> void Array2D_V1<T>::Set_Size(const Array2DSize& size){
    this->size.Assign(size);
}
template<typename T> void Array2D_V1<T>::Set_Size(const Array2DSize_Prototype* size){
    this->size.Assign(size);
}
template<typename T> void Array2D_V1<T>::Set_Size(std::vector<int>RowsLs){
    this->size.Set(RowsLs);
}
template<typename T> void Array2D_V1<T>::Set_Size(int QExtRows, int*RowsLs){
    this->size.Set(RowsLs, QExtRows);
}
template<typename T> void Array2D_V1<T>::Set_Size(int QExtRows, int RowsL){
    this->size.Set(QExtRows, RowsL);
}
template<typename T> int Array2D_V1<T>::Get_Size_TypeN(){
    this->size.GetTypeN();
}
//
//
//
template <class T> class Array2D_V1_Rect: public Array2D_V1<T>{
    //std::vector<T>data; // ab parent
    //Array2DSize size;   // ab parent
  public:
    Array2D_V1_Rect();
    Array2D_V1_Rect(T** data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    Array2D_V1_Rect(T** data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    Array2D_V1_Rect(T** data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void Set_simplyAsDataGiven_vU(T** data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    Array2D_V1_Rect(T** data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);//=0;
    Array2D_V1_Rect(T** data, int QExtRows, int ExtRowsL);
    //
    Array2D_V1_Rect(std::vector<std::vector<T>>data, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //
    Array2D_V1_Rect(T* data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    Array2D_V1_Rect(T* data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    Array2D_V1_Rect(T* data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void Set_simplyAsDataGiven_vU(T* data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    Array2D_V1_Rect(T* data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);//=0;
    Array2D_V1_Rect(T* data, int QExtRows, int ExtRowsL);
    //
    Array2D_V1_Rect(std::vector<T>data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    Array2D_V1_Rect(std::vector<T>data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    Array2D_V1_Rect(std::vector<T>data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void Set_simplyAsDataGiven_vU(std::vector<T>data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    Array2D_V1_Rect(std::vector<T>data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);//=0;
    Array2D_V1_Rect(std::vector<T>data, int QExtRows, int ExtRowsL);
    //
    Array2D_V1_Rect(const T& data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    Array2D_V1_Rect(const T& data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    Array2D_V1_Rect(const T& data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void Set_simplyAsDataGiven_vU(const T& data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    Array2D_V1_Rect(const T& data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);//=0;
    Array2D_V1_Rect(const T& data, int QExtRows, int ExtRowsL);
    //
    ~Array2D_V1_Rect();
    //
    //
    virtual void Set_Size_TypeN(int TypeN);
    virtual void Set_Size(const Array2DSize& size);
    virtual void Set_Size(const Array2DSize_Prototype* size);
    virtual void Set_Size(int QExtRows, int RowsL);
    virtual void Set_Size(int QExtRows, int*RowsLs);
    virtual void Set_Size(std::vector<int>RowsLs);
    virtual int Get_Size_TypeN();
    //
    //
    //virtual ~Array2D_Prototype();
    virtual int GetTypeN() const;//=0;
    //virtual void SetTypeN(int typeN=0);//=0;
    virtual int GetQExtRows() const;// =0;
    virtual int GetExtRowLength(int rowN=-1)const;// =0;
    virtual T GetElement(int ExtRowN, int inRowPosN)const;// =0;
    virtual const T* GetPointerToElement(int ExtRowN, int inRowPosN)const;// =0;
    virtual void SetElement(const T& val, int ExtRowN, int inRowPosN);//=0;
    virtual bool IsRectangularInFact() const ;
    virtual bool IsRectangularByType() const;// =0;
    virtual int GetLengthOfIneRowN(int N=-1) const;//=0;
    virtual std::vector<int> GetSizeAsStdVector() const;
    virtual Array2DSize GetSize()const;//=0;
    virtual int GetRowLengthMax() const ;
    virtual int GetRowLengthMin() const ;
    //std::vector<int>GetNsOfLmax() const;
    //std::vector<int>GetNsOfLmin()const;
    //std::vector<int>GetNsOfL(int L) const ;
    //
    virtual void SetSize(const T& defaultVal, int QExtRows=1, int ExtRowlength=1);
    virtual void SetSize(const T& defaultVal, int*ExtRowlengthes, int QExtRows=1, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);//=0;
    //void SetSize(std::vector<int>Ls, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void SetSize(const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void SetSize(const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //
    virtual void construct();
    virtual void SetNullIni();//=0;
    virtual void SetNull();
    //void SetOne(T*val=NULL);//=0;
    virtual void SetOne(const T&val);
    //
    //std::vector<std::vector<T>>GetData_AsStdVector2D();
    //std::vector<T>GetData_AsStdVector1D();
    //
    //void Assign(const Array2D_Prototype<T>*obj);//=0;
    //
    //
    //void Set_simplyAsDataGiven(T** data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void Set_simplyAsDataGiven(T** data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void Set_simplyAsDataGiven(T** data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    ////void Set_simplyAsDataGiven_vU(T** data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    virtual void Set_simplyAsDataGiven(const T& defaultVal, T** data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    virtual void Set_simplyAsDataGiven(const T& defaultVal, T** data, int QExtRows, int ExtRowsL);
    //
    virtual void Set_simplyAsDataGiven(const T& defaultVal, std::vector<std::vector<T>>data, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);//=0;
    //
    //void Set_simplyAsDataGiven(T* data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void Set_simplyAsDataGiven(T* data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0)=0;
    //void Set_simplyAsDataGiven(T* data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0)=0;
    ////void Set_simplyAsDataGiven_vU(T* data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    virtual void Set_simplyAsDataGiven(const T& defaultVal, T* data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);//=0;
    virtual void Set_simplyAsDataGiven(const T& defaultVal, T* data, int QExtRows, int ExtRowsL);
    //
    //void Set_simplyAsDataGiven(std::vector<T>data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void Set_simplyAsDataGiven(std::vector<T>data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void Set_simplyAsDataGiven(std::vector<T>data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    ////void Set_simplyAsDataGiven_vU(std::vector<T>data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    virtual void Set_simplyAsDataGiven(const T& defaultVal, std::vector<T>data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);//=0;
    virtual void Set_simplyAsDataGiven(const T& defaultVal, std::vector<T>data, int QExtRows, int ExtRowsL);
    //
    //void Set_simplyAsDataGiven(const T& data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void Set_simplyAsDataGiven(const T& data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0)=0;
    //void Set_simplyAsDataGiven(const T& data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    ////void Set_simplyAsDataGiven_vU(const T& data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    virtual void Set_simplyAsDataGiven(const T& defaultVal, const T& data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);//=0;
    virtual void Set_simplyAsDataGiven(const T& defaultVal, const T& data, int QExtRows, int ExtRowsL);
    //
    //virtual void Set, Add, Ins, Del Ext, Ine Row (T*row, int rowL, int rowN, rest params) et all neto =0;
};

template<typename T> Array2D_V1_Rect<T>::Array2D_V1_Rect(){
    this->construct();
}
template<typename T> Array2D_V1_Rect<T>::Array2D_V1_Rect(T** data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->construct();
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=1){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=2;
    }
    this->Set_simplyAsDataGiven(data, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> Array2D_V1_Rect<T>::Array2D_V1_Rect(T** data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->construct();
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=1){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=2;
    }
    this->Set_simplyAsDataGiven(data, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> Array2D_V1_Rect<T>::Array2D_V1_Rect(T** data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->construct();
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=1){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=2;
    }
    this->Set_simplyAsDataGiven(data, ExtRowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> Array2D_V1_Rect<T>::Array2D_V1_Rect(T** data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->construct();
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=1){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=2;
    }
    this->Set_simplyAsDataGiven(data, QExtRows, ExtRowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> Array2D_V1_Rect<T>::Array2D_V1_Rect(std::vector<std::vector<T>>data, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->construct();
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=1){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=2;
    }
    this->Set_simplyAsDataGiven(data, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> Array2D_V1_Rect<T>::Array2D_V1_Rect(T* data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->construct();
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=1){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=2;
    }
    this->Set_simplyAsDataGiven(data, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> Array2D_V1_Rect<T>::Array2D_V1_Rect(T* data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->construct();
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=1){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=2;
    }
    this->Set_simplyAsDataGiven(data, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> Array2D_V1_Rect<T>::Array2D_V1_Rect(T* data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->construct();
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=1){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=2;
    }
    this->Set_simplyAsDataGiven(data, ExtRowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> Array2D_V1_Rect<T>::Array2D_V1_Rect(T* data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->construct();
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=1){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=2;
    }
    this->Set_simplyAsDataGiven(data, QExtRows, ExtRowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> Array2D_V1_Rect<T>::Array2D_V1_Rect(T* data, int QExtRows, int ExtRowsL){
    this->construct();
    this->Set_simplyAsDataGiven(data, QExtRows, ExtRowsL);
}
template<typename T> Array2D_V1_Rect<T>::Array2D_V1_Rect(std::vector<T>data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->construct();
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=1){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=2;
    }
    this->Set_simplyAsDataGiven(data, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> Array2D_V1_Rect<T>::Array2D_V1_Rect(std::vector<T>data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->construct();
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=1){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=2;
    }
    this->Set_simplyAsDataGiven(data, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> Array2D_V1_Rect<T>::Array2D_V1_Rect(std::vector<T>data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->construct();
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=2){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=1;
    }
    this->Set_simplyAsDataGiven(data, ExtRowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> Array2D_V1_Rect<T>::Array2D_V1_Rect(std::vector<T>data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->construct();
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=2){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=1;
    }
    this->Set_simplyAsDataGiven(data, QExtRows, ExtRowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> Array2D_V1_Rect<T>::Array2D_V1_Rect(std::vector<T>data, int QExtRows, int ExtRowsL){
    this->construct();
    this->Set_simplyAsDataGiven(data, QExtRows, ExtRowsL);
}
template<typename T> Array2D_V1_Rect<T>::Array2D_V1_Rect(const T& data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->construct();
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=2 && ifNotRect_NonRect0_MakeRectBy_Max1Min2!=0){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=1;
    }
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=0){
        this->Set_simplyAsDataGiven(data, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
    }
}
template<typename T> Array2D_V1_Rect<T>::Array2D_V1_Rect(const T& data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->construct();
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=2){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=1;
    }
    this->Set_simplyAsDataGiven(data, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> Array2D_V1_Rect<T>::Array2D_V1_Rect(const T& data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->construct();
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=2){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=1;
    }
    this->Set_simplyAsDataGiven(data, ExtRowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> Array2D_V1_Rect<T>::Array2D_V1_Rect(const T& data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->construct();
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=2){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=1;
    }
    this->Set_simplyAsDataGiven(data, QExtRows, ExtRowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> Array2D_V1_Rect<T>::Array2D_V1_Rect(const T& data, int QExtRows, int ExtRowsL){
    this->construct();
    this->Set_simplyAsDataGiven(data, QExtRows, ExtRowsL);
}
//
template<typename T> Array2D_V1_Rect<T>::~Array2D_V1_Rect(){
    //this->data.clear();
    //this->size.SetNull();
    this->Array2D_V1<T>::SetNull();
}
//
//////virtual ~Array2D_Prototype();
//virtual int GetTypeN() const;//=0;
//////virtual void SetTypeN(int typeN=0);//=0;
//virtual int GetQExtRows() const;// =0;
//virtual int GetExtRowLength(int rowN=-1)const;// =0;
//virtual T GetElement(int ExtRowN, int inRowPosN)const;// =0;
//virtual const T* GetPointerToElement(int ExtRowN, int inRowPosN)const;// =0;
//virtual void SetElement(const T& val, int ExtRowN, int inRowPosN);//=0;
//virtual bool IsRectangularInFact() const ;
//virtual bool IsRectangularByType() const;// =0;
//virtual int GetLengthOfIneRowN(int N=-1) const;//=0;
//virtual std::vector<int> GetSizeAsStdVector() const;
//virtual Array2DSize GetSize()const;//=0;
//virtual int GetRowLengthMax() const ;
//virtual int GetRowLengthMin() const ;
//////std::vector<int>GetNsOfLmax() const;
//////std::vector<int>GetNsOfLmin()const;
//////std::vector<int>GetNsOfL(int L) const ;
//
template<typename T> int  Array2D_V1_Rect<T>::GetTypeN() const{
    return ARR2D_TYPE_V1D_RECTANGULAR;
}
template<typename T> int  Array2D_V1_Rect<T>::GetQExtRows()const{
   return this->Array2D_V1<T>::GetQExtRows();
}
template<typename T> int  Array2D_V1_Rect<T>::GetExtRowLength(int N)const{
   return this->Array2D_V1<T>::GetExtRowLength(N);
}
template<typename T> T  Array2D_V1_Rect<T>::GetElement(int ExtRowN, int inRowPosN)const{
    return  Array2D_V1<T>::GetElement(ExtRowN, inRowPosN);
}
template<typename T> const T*  Array2D_V1_Rect<T>::GetPointerToElement(int ExtRowN, int inRowPosN)const{
    return  Array2D_V1<T>::GetPointerToElement(ExtRowN, inRowPosN);
}
template<typename T> bool  Array2D_V1_Rect<T>::IsRectangularInFact()const{
   return this->Array2D_V1<T>::IsRectangularInFact();
}
template<typename T> bool  Array2D_V1_Rect<T>::IsRectangularByType()const{
   return this->Array2D_V1<T>::IsRectangularByType();
}
template<typename T> void  Array2D_V1_Rect<T>::SetElement(const T&val, int ExtRowN, int inRowPosN){
   this->Array2D_V1<T>::SetElement(val, ExtRowN, inRowPosN);
}
template<typename T> int  Array2D_V1_Rect<T>::GetLengthOfIneRowN(int N)const{
   return this->Array2D_V1<T>::GetLengthOfIneRowN(N);
}
template<typename T> std::vector<int>  Array2D_V1_Rect<T>::GetSizeAsStdVector()const{
   return this->Array2D_V1<T>::GetSizeAsStdVector();
}
template<typename T> Array2DSize Array2D_V1_Rect<T>::GetSize()const{
   return this->Array2D_V1<T>::GetSize();
}
template<typename T> int  Array2D_V1_Rect<T>::GetRowLengthMin()const{
    return  Array2D_V1<T>::GetRowLengthMin();
}
template<typename T> int  Array2D_V1_Rect<T>::GetRowLengthMax()const{
    return  Array2D_V1<T>::GetRowLengthMax();
}
//
template<typename T> void  Array2D_V1_Rect<T>::construct(){
    Array2D_V1<T>::construct();
    //this->Array2D_V1<T>::size.SetTypeN(Arr2DSize_Rect_TypeN);
    //this->size.SetTypeN(Arr2DSize_Rect_TypeN);
    this->Array2D_V1<T>::Set_Size_TypeN(Arr2DSize_Rect_TypeN);
}
template<typename T> void  Array2D_V1_Rect<T>::SetNull(){
    Array2D_V1<T>::SetNull();
}
template<typename T> void  Array2D_V1_Rect<T>::SetNullIni(){
    Array2D_V1<T>::SetNullIni();
}
template<typename T> void  Array2D_V1_Rect<T>::SetOne(const T&val){
    Array2D_V1<T>::SetOne(val);
}
//
template<typename T> void Array2D_V1_Rect<T>::SetSize(const T& defaultVal, int QExtRows, int ExtRowlength){
    this->Array2D_V1<T>::SetSize(defaultVal, QExtRows, ExtRowlength);
}
template<typename T> void Array2D_V1_Rect<T>::SetSize(const T& defaultVal, int*ExtRowlengthes, int QExtRows, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=2 && ifNotRect_NonRect0_MakeRectBy_Max1Min2!=0){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=1;
    }
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=0){
        this->Array2D_V1<T>::SetSize(defaultVal, ExtRowlengthes, QExtRows, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
    }
}
//
//void Set_simplyAsDataGiven(T** data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2);
template<typename T> void Array2D_V1_Rect<T>::Set_simplyAsDataGiven(const T& defaultVal, T** data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=2 && ifNotRect_NonRect0_MakeRectBy_Max1Min2!=0){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=1;
    }
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=0){
        this->Array2D_V1<T>::Set_simplyAsDataGiven(defaultVal, data, QExtRows, ExtRowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
    }
}
template<typename T> void Array2D_V1_Rect<T>::Set_simplyAsDataGiven(const T& defaultVal, T** data, int QExtRows, int ExtRowsL){
    //if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=2 && ifNotRect_NonRect0_MakeRectBy_Max1Min2!=0){
    //    ifNotRect_NonRect0_MakeRectBy_Max1Min2=1;
    //}
    //if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=0){
    this->Array2D_V1<T>::Set_simplyAsDataGiven(defaultVal, data, QExtRows, ExtRowsL);
    //}
}
template<typename T> void Array2D_V1_Rect<T>::Set_simplyAsDataGiven(const T& defaultVal, std::vector<std::vector<T>>data, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=2 && ifNotRect_NonRect0_MakeRectBy_Max1Min2!=0){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=1;
    }
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=0){
        this->Array2D_V1<T>::Set_simplyAsDataGiven(defaultVal, data, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
    }
}
template<typename T> void Array2D_V1_Rect<T>::Set_simplyAsDataGiven(const T& defaultVal, T* data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=2 && ifNotRect_NonRect0_MakeRectBy_Max1Min2!=0){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=1;
    }
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=0){
        this->Array2D_V1<T>::Set_simplyAsDataGiven(defaultVal, data, QExtRows, ExtRowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
    }
}
template<typename T> void Array2D_V1_Rect<T>::Set_simplyAsDataGiven(const T& defaultVal, T* data, int QExtRows, int ExtRowsL){
    //if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=2 && ifNotRect_NonRect0_MakeRectBy_Max1Min2!=0){
    //    ifNotRect_NonRect0_MakeRectBy_Max1Min2=1;
    //}
    //if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=0){
    this->Array2D_V1<T>::Set_simplyAsDataGiven(defaultVal, data, QExtRows, ExtRowsL);
    //}
}
template<typename T> void Array2D_V1_Rect<T>::Set_simplyAsDataGiven(const T& defaultVal, std::vector<T>data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=2 && ifNotRect_NonRect0_MakeRectBy_Max1Min2!=0){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=1;
    }
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=0){
        this->Array2D_V1<T>::Set_simplyAsDataGiven(defaultVal, data, QExtRows, ExtRowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
    }
}
template<typename T> void Array2D_V1_Rect<T>::Set_simplyAsDataGiven(const T& defaultVal, std::vector<T>data, int QExtRows, int ExtRowsL){
    //if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=2 && ifNotRect_NonRect0_MakeRectBy_Max1Min2!=0){
    //    ifNotRect_NonRect0_MakeRectBy_Max1Min2=1;
    //}
    //if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=0){
    this->Array2D_V1<T>::Set_simplyAsDataGiven(defaultVal, data, QExtRows, ExtRowsL);
    //}
}
template<typename T> void Array2D_V1_Rect<T>::Set_simplyAsDataGiven(const T& defaultVal, const T& data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=2 && ifNotRect_NonRect0_MakeRectBy_Max1Min2!=0){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=1;
    }
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=0){
        this->Array2D_V1<T>::Set_simplyAsDataGiven(defaultVal, data, QExtRows, ExtRowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
    }
}
template<typename T> void Array2D_V1_Rect<T>::Set_simplyAsDataGiven(const T& defaultVal, const T& data, int QExtRows, int ExtRowsL){
    //if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=2 && ifNotRect_NonRect0_MakeRectBy_Max1Min2!=0){
    //    ifNotRect_NonRect0_MakeRectBy_Max1Min2=1;
    //}
    //if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=0){
    this->Array2D_V1<T>::Set_simplyAsDataGiven(defaultVal, data, QExtRows, ExtRowsL);
    //}
}
//
//
template<typename T> void Array2D_V1_Rect<T>::Set_Size_TypeN(int TypeN){
    //this->size.SetTypeN(TypeN);
}
template<typename T> void Array2D_V1_Rect<T>::Set_Size(const Array2DSize& size){
    this->Array2D_V1<T>::Set_Size(size);
}
template<typename T> void Array2D_V1_Rect<T>::Set_Size(const Array2DSize_Prototype* size){
    this->Array2D_V1<T>::Set_Size(size);
}
template<typename T> void Array2D_V1_Rect<T>::Set_Size(std::vector<int>RowsLs){
    this->Array2D_V1<T>::Set_Size(RowsLs);
}
template<typename T> void Array2D_V1_Rect<T>::Set_Size(int QExtRows, int*RowsLs){
    this->Array2D_V1<T>::Set_Size(QExtRows, RowsLs);
}
template<typename T> void Array2D_V1_Rect<T>::Set_Size(int QExtRows, int RowsL){
    this->Array2D_V1<T>::Set_Size(QExtRows, RowsL);
}
template<typename T> int Array2D_V1_Rect<T>::Get_Size_TypeN(){
    return this->Array2D_V1<T>::Get_Size_TypeN();
}
//
//
//

template <class T> class Array2D_EIR{
    Array2D_Prototype<T>*data;
  public:
    //
    Array2D_EIR();
    Array2D_EIR(const T& defaultVal, T** data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR);
    Array2D_EIR(const T& defaultVal, T** data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR);
    Array2D_EIR(const T& defaultVal, T** data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR);
    //void Set_simplyAsDataGiven_vU(T** data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    Array2D_EIR(const T& defaultVal, T** data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR);
    Array2D_EIR(const T& defaultVal, T** data, int QExtRows, int ExtRowsL, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR);
    //
    Array2D_EIR(const T& defaultVal, std::vector<std::vector<T>>data, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR);
    //
    Array2D_EIR(const T& defaultVal, T* data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR);
    Array2D_EIR(const T& defaultVal, T* data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR);
    Array2D_EIR(const T& defaultVal, T* data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR);
    //void Set_simplyAsDataGiven_vU(T* data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    Array2D_EIR(const T& defaultVal, T* data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR);//=0;
    Array2D_EIR(const T& defaultVal, T* data, int QExtRows, int ExtRowsL, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR);
    //
    Array2D_EIR(const T& defaultVal, std::vector<T>data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR);
    Array2D_EIR(const T& defaultVal, std::vector<T>data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR);
    Array2D_EIR(const T& defaultVal, std::vector<T>data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR);
    //void Set_simplyAsDataGiven_vU(std::vector<T>data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    Array2D_EIR(const T& defaultVal, std::vector<T>data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR);//=0;
    Array2D_EIR(const T& defaultVal, std::vector<T>data, int QExtRows, int ExtRowsL, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR);
    //
    Array2D_EIR(const T& defaultVal, const T& data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR);
    Array2D_EIR(const T& defaultVal, const T& data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR);
    Array2D_EIR(const T& defaultVal, const T& data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR);
    //void Set_simplyAsDataGiven_vU(const T& data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    Array2D_EIR(const T& defaultVal, const T& data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR);//=0;
    Array2D_EIR(const T& defaultVal, const T& data, int QExtRows, int ExtRowsL, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR);
    //
    //
    Array2D_EIR(T** data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR, T*dfltVal=NULL);
    Array2D_EIR(T** data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR, T*dfltVal=NULL);
    Array2D_EIR(T** data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR, T*dfltVal=NULL);
    //void Set_simplyAsDataGiven_vU(T** data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    Array2D_EIR(T** data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR, T*dfltVal=NULL);
    Array2D_EIR(T** data, int QExtRows, int ExtRowsL, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR, T*dfltVal=NULL);
    //
    Array2D_EIR(std::vector<std::vector<T>>data, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR, T*dfltVal=NULL);
    //
    Array2D_EIR(T* data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR, T*dfltVal=NULL);
    Array2D_EIR(T* data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR, T*dfltVal=NULL);
    Array2D_EIR(T* data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR, T*dfltVal=NULL);
    //void Set_simplyAsDataGiven_vU(T* data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    Array2D_EIR(T* data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR, T*dfltVal=NULL);//=0;
    Array2D_EIR(T* data, int QExtRows, int ExtRowsL, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR, T*dfltVal=NULL);
    //
    Array2D_EIR(std::vector<T>data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR, T*dfltVal=NULL);
    Array2D_EIR(std::vector<T>data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR, T*dfltVal=NULL);
    Array2D_EIR(std::vector<T>data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR, T*dfltVal=NULL);
    //void Set_simplyAsDataGiven_vU(std::vector<T>data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    Array2D_EIR(std::vector<T>data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR, T*dfltVal=NULL);//=0;
    Array2D_EIR(std::vector<T>data, int QExtRows, int ExtRowsL, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR, T*dfltVal=NULL);
    //
    Array2D_EIR(const T& data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR, T*dfltVal=NULL);
    Array2D_EIR(const T& data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR, T*dfltVal=NULL);
    Array2D_EIR(const T& data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR, T*dfltVal=NULL);
    //void Set_simplyAsDataGiven_vU(const T& data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    Array2D_EIR(const T& data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR, T*dfltVal=NULL);//=0;
    Array2D_EIR(const T& data, int QExtRows, int ExtRowsL, int TypeN=ARR2D_TYPE_V2D_RECTANGULAR, T*dfltVal=NULL);
    //
    Array2D_EIR(const Array2D_EIR<T>& obj);
    //
    ~Array2D_EIR();
    //
    //
    //virtual ~Array2D_Prototype();
    int GetTypeN() const;//=0;
    int GetQExtRows() const;// =0;
    int GetExtRowLength(int rowN=-1)const;// =0;
    T GetElement(int ExtRowN, int inRowPosN)const;// =0;
    T* GetPointerToElement(int ExtRowN, int inRowPosN)const;// =0;
    void SetElement(const T& val, int ExtRowN, int inRowPosN);//=0;
    bool IsRectangularInFact() const ;
    bool IsRectangularByType() const;// =0;
    int GetLengthOfRowN(int N=-1) const;//=0;
    std::vector<int> GetSizeAsStdVector() const;
    Array2DSize GetSize()const;//=0;
    int GetRowLengthMax() const ;
    int GetRowLengthMin() const ;
    std::vector<int>GetNsOfLmax() const;
    std::vector<int>GetNsOfLmin()const;
    std::vector<int>GetNsOfL(int L) const ;
    //
    void construct(int TypeN=ARR2D_TYPE_V1D_RECTANGULAR);
    void SetNullIni();//=0;
    void SetNull();
    void SetOne(T*val=NULL);//=0;
    void SetOne(const T&val);
    //
    void SetTypeN(int TypeN=Arr2DSize_Rect_TypeN);
    //
    std::vector<std::vector<T>>GetData_AsStdVector2D();
    std::vector<T>GetData_AsStdVector1D();
    //
    void Assign(const Array2D_Prototype<T>*obj);
    //
    void Assign(const Array2D_EIR<T>&obj);
    //
    Array2D_EIR<T>& operator =(const Array2D_EIR<T>&obj); //if no &  - error
    //
    Array2D_Prototype<T>*GetData();
    //
    //
    void SetSize(const T& defaultVal, int QExtRows=1, int ExtRowlength=1);
    void SetSize(const T& defaultVal, int*ExtRowlengthes, int QExtRows=1, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    void SetSize(const T& defaultVal, std::vector<int>Ls, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    void SetSize(const T& defaultVal, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    void SetSize(const T& defaultVal, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //
    void SetSize(int QExtRows=1, int ExtRowlength=1, T*dfltVal=NULL);
    void SetSize(int*ExtRowlengthes, int QExtRows=1, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, T*dfltVal=NULL);
    void SetSize(std::vector<int>Ls, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, T*dfltVal=NULL);
    void SetSize(const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, T*dfltVal=NULL);
    void SetSize(const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, T*dfltVal=NULL);
    //
    //
    void Set_simplyAsDataGiven(const T&defaultVal, T** data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=0);
    void Set_simplyAsDataGiven(const T&defaultVal, T** data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=0);
    void Set_simplyAsDataGiven(const T&defaultVal, T** data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=0);
    void Set_simplyAsDataGiven(const T&defaultVal, T** data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=0);
    void Set_simplyAsDataGiven(const T&defaultVal, T** data, int QExtRows, int ExtRowsL, int TypeN=0);
    //
    void Set_simplyAsDataGiven(const T&defaultVal, std::vector<std::vector<T>>data, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=0);
    //
    void Set_simplyAsDataGiven(const T&defaultVal, T* data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=0);
    void Set_simplyAsDataGiven(const T&defaultVal, T* data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=0);
    void Set_simplyAsDataGiven(const T&defaultVal, T* data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=0);
    void Set_simplyAsDataGiven(const T&defaultVal, T* data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=0);
    void Set_simplyAsDataGiven(const T&defaultVal, T* data, int QExtRows, int ExtRowsL, int TypeN=0);
    //
    void Set_simplyAsDataGiven(const T&defaultVal, std::vector<T>data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=0);
    void Set_simplyAsDataGiven(const T&defaultVal, std::vector<T>data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=0);
    void Set_simplyAsDataGiven(const T&defaultVal, std::vector<T>data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=0);
    void Set_simplyAsDataGiven(const T&defaultVal, std::vector<T>data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=0);
    void Set_simplyAsDataGiven(const T&defaultVal, std::vector<T>data, int QExtRows, int ExtRowsL, int TypeN=0);
    //0
    void Set_simplyAsDataGiven(const T&defaultVal, const T& data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=0);
    void Set_simplyAsDataGiven(const T&defaultVal, const T& data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=0);
    void Set_simplyAsDataGiven(const T&defaultVal, const T& data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=0);
    void Set_simplyAsDataGiven(const T&defaultVal, const T& data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=0);
    void Set_simplyAsDataGiven(const T&defaultVal, const T& data, int QExtRows, int ExtRowsL, int TypeN=0);
    //
    //
    void Set_simplyAsDataGiven(T** data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=0, T*dfltVal=NULL);
    void Set_simplyAsDataGiven(T** data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=0, T*dfltVal=NULL);
    void Set_simplyAsDataGiven(T** data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=0, T*dfltVal=NULL);
    void Set_simplyAsDataGiven(T** data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=0, T*dfltVal=NULL);
    void Set_simplyAsDataGiven(T** data, int QExtRows, int ExtRowsL, int TypeN=0, T*dfltVal=NULL);
    //
    void Set_simplyAsDataGiven(std::vector<std::vector<T>>data, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=0, T*dfltVal=NULL);//=0;
    //
    void Set_simplyAsDataGiven(T* data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=0, T*dfltVal=NULL);
    void Set_simplyAsDataGiven(T* data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=0, T*dfltVal=NULL);
    void Set_simplyAsDataGiven(T* data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=0, T*dfltVal=NULL);
    void Set_simplyAsDataGiven(T* data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=0, T*dfltVal=NULL);//=0;
    void Set_simplyAsDataGiven(T* data, int QExtRows, int ExtRowsL, int TypeN=0, T*dfltVal=NULL);
    //
    void Set_simplyAsDataGiven(std::vector<T>data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=0, T*dfltVal=NULL);
    void Set_simplyAsDataGiven(std::vector<T>data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=0, T*dfltVal=NULL);
    void Set_simplyAsDataGiven(std::vector<T>data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=0, T*dfltVal=NULL);
    void Set_simplyAsDataGiven(std::vector<T>data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=0, T*dfltVal=NULL);//=0;
    void Set_simplyAsDataGiven(std::vector<T>data, int QExtRows, int ExtRowsL, int TypeN=0, T*dfltVal=NULL);
    //
    void Set_simplyAsDataGiven(const T& data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=0, T*dfltVal=NULL);
    void Set_simplyAsDataGiven(const T& data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=0, T*dfltVal=NULL);
    void Set_simplyAsDataGiven(const T& data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=0, T*dfltVal=NULL);
    void Set_simplyAsDataGiven(const T& data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=0, T*dfltVal=NULL);//=0;
    void Set_simplyAsDataGiven(const T& data, int QExtRows, int ExtRowsL, int TypeN=0, T*dfltVal=NULL);
    //
    //
    void ShowExtRowToConsole(int RowN, QString ElementDelim=", ", bool Show2Not1D=true, bool ShowBrackets=true);
    void ShowIneRowToConsole(int RowN, QString ElementDelim=", ", bool Show2Not1D=true, bool ShowBrackets=true);
    void ShowToConsole(QString rowDelim="; ", QString ElementDelim=", ", bool Show2Not1D=true, bool ShowBrackets=true);
};

template<typename T> Array2D_EIR<T>::Array2D_EIR(){
    this->construct();
}
template<typename T> Array2D_EIR<T>::Array2D_EIR(const T& defaultVal, T** data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN){
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive(defaultVal, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> Array2D_EIR<T>::Array2D_EIR(T** data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN, T*dfltVal){
    T deaultVal;
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive(size, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN, dfltVal);
}
template<typename T> Array2D_EIR<T>::Array2D_EIR(const T&defaultVal, T** data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN){
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive(defaultVal, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> Array2D_EIR<T>::Array2D_EIR(T** data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN, T*dfltVal){
    T deaultVal;
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive(size, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN, dfltVal);
}
template<typename T> Array2D_EIR<T>::Array2D_EIR(const T&defaultVal, T** data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN){
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive(defaultVal, ExtRowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> Array2D_EIR<T>::Array2D_EIR(T** data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN, T*dfltVal){
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive(ExtRowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN, dfltVal);
}
template<typename T> Array2D_EIR<T>::Array2D_EIR(const T& defaultVal, T** data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN){
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive(defaultVal, data, QExtRows, ExtRowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> Array2D_EIR<T>::Array2D_EIR(T** data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN, T*dfltVal){
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive( data, QExtRows, ExtRowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN, dfltVal);
}
template<typename T> Array2D_EIR<T>::Array2D_EIR(const T& defaultVal, T** data, int QExtRows, int ExtRowsL, int TypeN){
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive(defaultVal, data, QExtRows, ExtRowsL, TypeN);
}
template<typename T> Array2D_EIR<T>::Array2D_EIR(T** data, int QExtRows, int ExtRowsL, int TypeN, T*dfltVal){
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive( data, QExtRows, ExtRowsL, TypeN, dfltVal);
}
template<typename T> Array2D_EIR<T>::Array2D_EIR(const T& defaultVal, std::vector<std::vector<T>>data, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN){
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive(defaultVal, data, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> Array2D_EIR<T>::Array2D_EIR(std::vector<std::vector<T>>data, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN, T*dfltVal){
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive(data, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN, dfltVal);
}

template<typename T> Array2D_EIR<T>::Array2D_EIR(const T& defaultVal, T* data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN){
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive(defaultVal, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> Array2D_EIR<T>::Array2D_EIR(T* data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN, T*dfltVal){
    T deaultVal;
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive(size, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN, dfltVal);
}
template<typename T> Array2D_EIR<T>::Array2D_EIR(const T&defaultVal, T* data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN){
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive(defaultVal, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> Array2D_EIR<T>::Array2D_EIR(T* data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN, T*dfltVal){
    T deaultVal;
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive(size, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN, dfltVal);
}
template<typename T> Array2D_EIR<T>::Array2D_EIR(const T&defaultVal, T* data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN){
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive(defaultVal, ExtRowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> Array2D_EIR<T>::Array2D_EIR(T* data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN, T*dfltVal){
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive(ExtRowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN, dfltVal);
}
template<typename T> Array2D_EIR<T>::Array2D_EIR(const T& defaultVal, T* data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN){
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive(defaultVal, data, QExtRows, ExtRowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> Array2D_EIR<T>::Array2D_EIR(T* data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN, T*dfltVal){
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive( data, QExtRows, ExtRowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN, dfltVal);
}
template<typename T> Array2D_EIR<T>::Array2D_EIR(const T& defaultVal, T* data, int QExtRows, int ExtRowsL, int TypeN){
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive(defaultVal, data, QExtRows, ExtRowsL, TypeN);
}
template<typename T> Array2D_EIR<T>::Array2D_EIR(T* data, int QExtRows, int ExtRowsL, int TypeN, T*dfltVal){
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive( data, QExtRows, ExtRowsL, TypeN, dfltVal);
}
template<typename T> Array2D_EIR<T>::Array2D_EIR(const T& defaultVal, std::vector<T>data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN){
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive(defaultVal, data, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> Array2D_EIR<T>::Array2D_EIR(std::vector<T>data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN, T*dfltVal){
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive(data, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN, dfltVal);
}
template<typename T> Array2D_EIR<T>::Array2D_EIR(const T& defaultVal, std::vector<T>data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN){
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive(defaultVal, data, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> Array2D_EIR<T>::Array2D_EIR(std::vector<T>data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN, T*dfltVal){
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive(data, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN, dfltVal);
}
template<typename T> Array2D_EIR<T>::Array2D_EIR(const T& defaultVal, std::vector<T>data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN){
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive(defaultVal, data, ExtRowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> Array2D_EIR<T>::Array2D_EIR(std::vector<T>data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN, T*dfltVal){
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive(data, ExtRowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN, dfltVal);
}
template<typename T> Array2D_EIR<T>::Array2D_EIR(const T& defaultVal, std::vector<T>data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN){
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive(defaultVal, data, QExtRows, ExtRowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> Array2D_EIR<T>::Array2D_EIR(std::vector<T>data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN, T*dfltVal){
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive(data, QExtRows, ExtRowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN, dfltVal);
}
template<typename T> Array2D_EIR<T>::Array2D_EIR(const T& defaultVal, std::vector<T>data, int QExtRows, int ExtRowsL, int TypeN){
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive(defaultVal, data, QExtRows, ExtRowsL, TypeN);
}
template<typename T> Array2D_EIR<T>::Array2D_EIR(std::vector<T>data, int QExtRows, int ExtRowsL, int TypeN, T*dfltVal){
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive(data, QExtRows, ExtRowsL, TypeN, dfltVal);
}
template<typename T> Array2D_EIR<T>::Array2D_EIR(const T& defaultVal, const T&data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN){
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive(defaultVal, data, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> Array2D_EIR<T>::Array2D_EIR(const T&data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN, T*dfltVal){
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive(data, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN, dfltVal);
}
template<typename T> Array2D_EIR<T>::Array2D_EIR(const T& defaultVal, const T&data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN){
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive(defaultVal, data, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> Array2D_EIR<T>::Array2D_EIR(const T& data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN, T*dfltVal){
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive(data, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN, dfltVal);
}
template<typename T> Array2D_EIR<T>::Array2D_EIR(const T& defaultVal, const T& data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN){
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive(defaultVal, data, ExtRowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> Array2D_EIR<T>::Array2D_EIR(const T& data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN, T*dfltVal){
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive(data, ExtRowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN, dfltVal);
}
template<typename T> Array2D_EIR<T>::Array2D_EIR(const T& defaultVal, const T& data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN){
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive(defaultVal, data, QExtRows, ExtRowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> Array2D_EIR<T>::Array2D_EIR(const T&, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN, T*dfltVal){
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive(data, QExtRows, ExtRowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN, dfltVal);
}
template<typename T> Array2D_EIR<T>::Array2D_EIR(const T& defaultVal, const T& data, int QExtRows, int ExtRowsL, int TypeN){
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive(defaultVal, data, QExtRows, ExtRowsL, TypeN);
}
template<typename T> Array2D_EIR<T>::Array2D_EIR(const T& data, int QExtRows, int ExtRowsL, int TypeN, T*dfltVal){
    this->construct(TypeN);
    this->Array2D_V1<T>::Set_simplyAsDataGive(data, QExtRows, ExtRowsL, TypeN, dfltVal);
}
//
template<typename T> Array2D_EIR<T>::Array2D_EIR(const Array2D_EIR& obj){
    int TypeN=obj.GetTypeN();
    this->construct(TypeN);
    this-Assign(obj);
}
//
template<typename T> Array2D_EIR<T>::~Array2D_EIR(){
    delete this->data;
}
//
template<typename T> void Array2D_EIR<T>::Assign(const Array2D_EIR<T>& obj){
    int TypeN=obj.GetTypeN();
    std::vector<T>data=this->GetData_AsStdVector1D();
    Array2DSize size=obj.GetSize();
    int ifNotRect_NonRect0_MakeRectBy_Max1Min2;
    if(TypeN==ARR2D_TYPE_V1D_RECTANGULAR || TypeN==ARR2D_TYPE_P1D_RECTANGULAR){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=2;
    }else{
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=0;
    }
    this->Set_simplyAsDataGiven(data,size, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
//
template<typename T> void Array2D_EIR<T>::Assign(const Array2D_Prototype<T>*obj){
    int TypeN=obj.GetTypeN();
    this->SetTypeN(TypeN);
    this->data->Assign(obj);
}
//
template<typename T> Array2D_EIR<T>& Array2D_EIR<T>::operator = (const Array2D_EIR<T>& obj){
    this->Assign(obj);
    return *this;
}
//
template<typename T> Array2D_Prototype<T>* Array2D_EIR<T>::GetData(){
    return this->data;
}
//
template<typename T> int Array2D_EIR<T>::GetTypeN() const{
    return this->data->GetTypeN();
}
template<typename T> int Array2D_EIR<T>::GetQExtRows() const{
    return this->data->GetQExtRows();
}
template<typename T> int Array2D_EIR<T>::GetExtRowLength(int N) const{
    return this->data->GetExtRowLength(N);
}
template<typename T> T Array2D_EIR<T>::GetElement(int ExtRowN, int inRowPosN) const{
    return this->data->GetElement(ExtRowN, inRowPosN);
}
template<typename T> T* Array2D_EIR<T>::GetPointerToElement(int ExtRowN, int inRowPosN) const{
    return this->data->GetPointerToElement(ExtRowN, inRowPosN);
}
template<typename T> void Array2D_EIR<T>::SetElement(const T& val, int ExtRowN, int inRowPosN){
    this->data->SetElement(val, ExtRowN, inRowPosN);
}
template<typename T> bool Array2D_EIR<T>::IsRectangularInFact() const{
    return this->data->IsRectangularInFact();
}
template<typename T> bool Array2D_EIR<T>::IsRectangularByType() const{
    return this->data->IsRectangularByType();
}
template<typename T> int Array2D_EIR<T>::GetLengthOfRowN(int N) const{
    return this->data->GetLengthOfIneRowN(N);
}
template<typename T> std::vector<int> Array2D_EIR<T>::GetSizeAsStdVector() const{
    return this->data->GetSizeAsStdVector();
}
template<typename T> Array2DSize Array2D_EIR<T>::GetSize() const{
    return this->data->GetSize();
}
template<typename T> int Array2D_EIR<T>::GetRowLengthMax() const{
    return this->data->GetRowLengthMax();
}
template<typename T> int Array2D_EIR<T>::GetRowLengthMin() const{
    return this->data->GetRowLengthMin();
}
template<typename T> std::vector<int> Array2D_EIR<T>::GetNsOfLmax() const{
    return this->data->GetNsOfLmax();
}
template<typename T> std::vector<int> Array2D_EIR<T>::GetNsOfLmin() const{
    return this->data->GetNsOfLmin();
}
template<typename T> std::vector<int> Array2D_EIR<T>::GetNsOfL(int L) const{
    return this->data->GetNsOfL(L);
}
//
template<typename T> void Array2D_EIR<T>::construct(int TypeN) {
    switch(TypeN){
        case ARR2D_TYPE_V1D_VAR_LEN:
            this->data=new Array2D_V1< T>();
        break;//ARR2D_TYPE_V1D_RECTANGULAR
        case ARR2D_TYPE_V1D_RECTANGULAR: //
            this->data=new Array2D_V1_Rect<T>();
        break;
    }
}
template<typename T> void Array2D_EIR<T>::SetNullIni() {
    this->data->SetNullIni();
}
template<typename T> void Array2D_EIR<T>::SetNull() {
    this->data->SetNull();
}
template<typename T> void Array2D_EIR<T>::SetOne(const T& val) {
    this->data->SetOne(val);
}
template<typename T> void Array2D_EIR<T>::SetOne(T*val) {
    this->data->SetOne(val);
}
template<typename T> void Array2D_EIR<T>::SetTypeN(int TypeN) {
    int OldTypeN=this->GetTypeN();
    Array2D_Prototype<T>*objPtr;
    //Array2D_EIR<T> obj;
    if(OldTypeN!=TypeN) {
        objPtr=this->GetData();
        //obj=(*(this));
        switch(TypeN){
            case ARR2D_TYPE_V1D_VAR_LEN:
                this->data=new Array2D_V1<T>();
            break;
            case ARR2D_TYPE_V1D_RECTANGULAR: // ARR2D_TYPE_V1D_RECTANGULAR
                this->data=new Array2D_V1_Rect<T>();
            break;
        }
        //this->data->Assign(obj);
        this->data->Assign(objPtr);
    }
}
//
template<typename T> std::vector<T> Array2D_EIR<T>::GetData_AsStdVector1D() {
    return this->data->GetData_AsStdVector1D();
}
template<typename T> std::vector<std::vector<T>> Array2D_EIR<T>::GetData_AsStdVector2D() {
    return this->data->GetData_AsStdVector2D();
}
//
template<typename T> void Array2D_EIR<T>::SetSize(const T& defaultVal, int QExtRows, int ExtRowlength){
    this->data->SetSize(defaultVal, QExtRows,  ExtRowlength);
}
template<typename T> void Array2D_EIR<T>::SetSize(const T& defaultVal, int*ExtRowlengthes, int QExtRows, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->data->SetSize(defaultVal, ExtRowlengthes, QExtRows, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_EIR<T>::SetSize(const T& defaultVal, std::vector<int>Ls, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->data->SetSize(defaultVal, Ls, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_EIR<T>::SetSize(const T& defaultVal, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->data->SetSize(defaultVal, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_EIR<T>::SetSize(const T& defaultVal, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->data->SetSize(defaultVal, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
//
template<typename T> void Array2D_EIR<T>::SetSize(int QExtRows, int ExtRowlength, T*dfltVal){
    this->data->SetSize(QExtRows,  ExtRowlength, dfltVal);
}
template<typename T> void Array2D_EIR<T>::SetSize(int*ExtRowlengthes, int QExtRows, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, T*dfltVal){
    this->data->SetSize(ExtRowlengthes, QExtRows, ifNotRect_NonRect0_MakeRectBy_Max1Min2, dfltVal);
}
template<typename T> void Array2D_EIR<T>::SetSize(std::vector<int>Ls, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, T*dfltVal){
    this->data->SetSize(Ls, ifNotRect_NonRect0_MakeRectBy_Max1Min2, dfltVal);
}
template<typename T> void Array2D_EIR<T>::SetSize(const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, T*dfltVal){
    this->data->SetSize(size, ifNotRect_NonRect0_MakeRectBy_Max1Min2, dfltVal);
}
template<typename T> void Array2D_EIR<T>::SetSize(const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, T*dfltVal){
    this->data->SetSize(size, ifNotRect_NonRect0_MakeRectBy_Max1Min2, dfltVal);
}
//
//
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven(const T& defaultVal, T** data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN){
    this->SetTypeN(TypeN);
    this->data->Set_simplyAsDataGiven(defaultVal, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven(T** data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->Set_simplyAsDataGiven(defaultVal, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven(const T& defaultVal, T** data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN){
    this->SetTypeN(TypeN);
    this->data->Set_simplyAsDataGiven(defaultVal, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven(T** data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->Set_simplyAsDataGiven(defaultVal, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven(const T& defaultVal, T** data, std::vector<int>rowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN){
    this->SetTypeN(TypeN);
    this->data->Set_simplyAsDataGiven(defaultVal, rowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven( T** data, std::vector<int>rowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->Set_simplyAsDataGiven(defaultVal, rowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven(const T& defaultVal, T** data, int QExtRows, int*rowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN){
    this->SetTypeN(TypeN);
    this->data->Set_simplyAsDataGiven(defaultVal, QExtRows, rowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven( T** data, int QExtRows, int*rowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->Set_simplyAsDataGiven(defaultVal, QExtRows, rowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven(const T& defaultVal, T** data, int QExtRows, int rowL, int TypeN){
    this->SetTypeN(TypeN);
    this->data->Set_simplyAsDataGiven(defaultVal, QExtRows, rowL, TypeN);
}
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven(T** data, int QExtRows, int rowL, int TypeN, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->Set_simplyAsDataGiven(defaultVal, QExtRows, rowL, TypeN);
}
//
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven(const T& defaultVal, T* data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN){
    this->SetTypeN(TypeN);
    this->data->Set_simplyAsDataGiven(defaultVal, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven(T* data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->Set_simplyAsDataGiven(defaultVal, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven(const T& defaultVal, T* data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN){
    this->SetTypeN(TypeN);
    this->data->Set_simplyAsDataGiven(defaultVal, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven(T* data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->Set_simplyAsDataGiven(defaultVal, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven(const T& defaultVal, T* data, std::vector<int>rowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN){
    this->SetTypeN(TypeN);
    this->data->Set_simplyAsDataGiven(defaultVal, rowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven(T* data, std::vector<int>rowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->Set_simplyAsDataGiven(defaultVal, rowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven(const T& defaultVal, T* data, int QExtRows, int*rowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN){
    this->SetTypeN(TypeN);
    this->data->Set_simplyAsDataGiven(defaultVal, QExtRows, rowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven(T* data, int QExtRows, int*rowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->Set_simplyAsDataGiven(defaultVal, QExtRows, rowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven(const T& defaultVal, T* data, int QExtRows, int rowL, int TypeN){
    this->SetTypeN(TypeN);
    this->data->Set_simplyAsDataGiven(defaultVal, QExtRows, rowL, TypeN);
}
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven(T* data, int QExtRows, int rowL, int TypeN, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->Set_simplyAsDataGiven(defaultVal, QExtRows, rowL, TypeN);
}
//
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven(const T& defaultVal, std::vector<T>data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN){
    this->SetTypeN(TypeN);
    this->data->Set_simplyAsDataGiven(defaultVal, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven(std::vector<T>data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->Set_simplyAsDataGiven(defaultVal, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven(const T& defaultVal, std::vector<T>data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN){
    this->SetTypeN(TypeN);
    this->data->Set_simplyAsDataGiven(defaultVal, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven(std::vector<T>data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->Set_simplyAsDataGiven(defaultVal, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven(const T& defaultVal, std::vector<T>data, std::vector<int>rowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN){
    this->SetTypeN(TypeN);
    this->data->Set_simplyAsDataGiven(defaultVal, rowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven(std::vector<T>data, std::vector<int>rowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->Set_simplyAsDataGiven(defaultVal, rowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven(const T& defaultVal, std::vector<T>data, int QExtRows, int*rowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN){
    this->SetTypeN(TypeN);
    this->data->Set_simplyAsDataGiven(defaultVal, QExtRows, rowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven(std::vector<T>data, int QExtRows, int*rowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->Set_simplyAsDataGiven(defaultVal, QExtRows, rowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven(const T& defaultVal, std::vector<T>data, int QExtRows, int rowL, int TypeN){
    this->SetTypeN(TypeN);
    this->data->Set_simplyAsDataGiven(defaultVal, QExtRows, rowL, TypeN);
}
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven(std::vector<T>data, int QExtRows, int rowL, int TypeN, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->Set_simplyAsDataGiven(defaultVal, QExtRows, rowL, TypeN);
}
//
//void                                    Set_simplyAsDataGiven(const T&defaultVal,  std::vector<std::vector<T>>data, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=0);//=0;
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven(const T& defaultVal, std::vector<std::vector<T>>data, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN){
    this->SetTypeN(TypeN);
    this->data->Set_simplyAsDataGiven(defaultVal, data, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
//void                                    Set_simplyAsDataGiven(std::vector<std::vector<T>>data, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0, int TypeN=0, T*dfltVal=NULL);//=0;
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven(std::vector<std::vector<T>>data, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->Set_simplyAsDataGiven(defaultVal, data, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
//
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven(const T& defaultVal, const T&  data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN){
    this->SetTypeN(TypeN);
    this->data->Set_simplyAsDataGiven(defaultVal, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven(const T& data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->Set_simplyAsDataGiven(defaultVal, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven(const T& defaultVal, const T& data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN){
    this->SetTypeN(TypeN);
    this->data->Set_simplyAsDataGiven(defaultVal, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven(const T& data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->Set_simplyAsDataGiven(defaultVal, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven(const T& defaultVal, const T& data, std::vector<int>rowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN){
    this->SetTypeN(TypeN);
    this->data->Set_simplyAsDataGiven(defaultVal, rowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven(const T& data, std::vector<int>rowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->Set_simplyAsDataGiven(defaultVal, rowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven(const T& defaultVal, const T& data, int QExtRows, int*rowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN){
    this->SetTypeN(TypeN);
    this->data->Set_simplyAsDataGiven(defaultVal, QExtRows, rowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven(const T& data, int QExtRows, int*rowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2, int TypeN, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->Set_simplyAsDataGiven(defaultVal, QExtRows, rowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2, TypeN);
}
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven(const T& defaultVal, const T& data, int QExtRows, int rowL, int TypeN){
    this->SetTypeN(TypeN);
    this->data->Set_simplyAsDataGiven(defaultVal, QExtRows, rowL, TypeN);
}
template<typename T> void Array2D_EIR<T>::Set_simplyAsDataGiven(const T& data, int QExtRows, int rowL, int TypeN, T*dfltVal){
    T defaultVal;
    if(dfltVal!=NULL){
        defaultVal=(*(dfltVal));
    }
    this->Set_simplyAsDataGiven(defaultVal, QExtRows, rowL, TypeN);
}
//
//
template<typename T> void Array2D_EIR<T>::ShowExtRowToConsole(int RowNN, QString ElementDelim, bool Show2Not1D, bool ShowBrackets){
    T element;
    int QExtRows=this->GetQExtRows();
    if(RowNN<0){
        RowNN=(QExtRows+1);
    }
    int rowL=this->GetExtRowLength(RowNN);
    if(ShowBrackets){
        std::cout<<"[";
    }
    for(int IRNN=1; IRNN<=rowL-1; IRNN++){
        element=this->GetElement(RowNN, IRNN);
        std::cout<<element;
        std::cout<<ElementDelim.toStdString().c_str();
    }
    element=this->GetElement(RowNN, rowL);
    std::cout<<element;
    if(ShowBrackets){
        std::cout<<"]";
    }
}
template<typename T> void Array2D_EIR<T>::ShowIneRowToConsole(int RowNN, QString ElementDelim, bool Show2Not1D, bool ShowBrackets){
    T element;
    int QExtRows=this->GetQExtRows();
    if(RowNN<0){
        RowNN=(QExtRows+1);
    }
    int rowL=this->GetLengthOfRowN(RowNN);//Ine?
    if(ShowBrackets){
        std::cout<<"[";
    }
    for(int ERNN=1; ERNN<=rowL-1; ERNN++){
        element=this->GetElement(ERNN, RowNN);
        std::cout<<element;
        std::cout<<ElementDelim.toStdString().c_str();
    }
    element=this->GetElement(rowL, RowNN);
    std::cout<<element;
    if(ShowBrackets){
        std::cout<<"]";
    }
}
template<typename T> void Array2D_EIR<T>::ShowToConsole(QString rowDelim, QString ElementDelim, bool Show2Not1D, bool ShowBrackets){
    T element;
    int QExtRows=this->GetQExtRows();
    if(ShowBrackets){
        std::cout<<"[";
    }
    this->ShowExtRowToConsole(1, ElementDelim, ShowBrackets);
    std::cout<<rowDelim.toStdString().c_str();
    if(Show2Not1D){
        std::cout<<std::endl;
    }
    for(int ERNN=2; ERNN<=QExtRows-1; ERNN++){
        if(ShowBrackets){
            std::cout<<" ";
        }
        this->ShowExtRowToConsole(ERNN, ElementDelim, ShowBrackets);
        std::cout<<rowDelim.toStdString().c_str();
        if(Show2Not1D){
            std::cout<<std::endl;
        }
    }
    if(ShowBrackets){
        std::cout<<" ";
    }
    if(QExtRows>2){
        this->ShowExtRowToConsole(QExtRows, ElementDelim, ShowBrackets);
    }
    if(ShowBrackets){
        std::cout<<"]";
    }
    if(Show2Not1D){
        std::cout<<std::endl;
    }
}
//
//


#endif // ARRAY2DLIB_H
