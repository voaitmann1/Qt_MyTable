#ifndef ARRAY2DLIB_H
#define ARRAY2DLIB_H

#include"array1d_size2d_elem2d_1.h"

//class Array2DLib
//{
//public:
//    Array2DLib();
//};

const int ARR2D_TYPE_V1D_RECTANGULAR=1;
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
    virtual ~Array2D_Prototype();
    virtual int GetTypeN() const=0;
    //virtual void SetTypeN(int typeN=0)=0;
    virtual int GetQExtRows() const =0;
    virtual int GetExtRowLength(int rowN=-1)const =0;
    virtual T GetElement(int ExtRowN, int inRowPosN)const =0;
    virtual T* GetPointerToElement(int ExtRowN, int inRowPosN)const =0;
    virtual void SetElement(const T& val, int ExtRowN, int inRowPosN)=0;
    virtual bool IsRectangularInFact() const ;
    virtual bool IsRectangularByType() const =0;
    virtual int GetLengthOfRowN(int N=-1) const=0;
    virtual std::vector<int> GetSizeAsStdVector() const;
    virtual Array2DSize GetSize()=0;
    virtual int GetRowLengthMax() const ;
    virtual int GetRowLengthMin() const ;
    std::vector<int>GetNsOfLmax() const;
    std::vector<int>GetNsOfLmin()const;
    std::vector<int>GetNsOfL(int L) const ;
    //
    virtual void SetSize(int QExtRows=1, int ExtRowlength=1);
    virtual void SetSize(int*ExtRowlengthes, int QExtRows=1, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0)=0;
    void SetSize(std::vector<int>Ls, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    void SetSize(const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    void SetSize(const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //
    virtual void construct();
    virtual void SetNullIni()=0;
    virtual void SetNull()=0;
    virtual void SetOne(T*val=NULL)=0;
    virtual void SetOne(const T&val);
    //
    std::vector<std::vector<T>>GetData_AsStdVector2D();
    std::vector<T>GetData_AsStdVector1D();
    //
    virtual void Assign(const Array2D_Prototype*obj)=0;
    //
    //
    void Set_simplyAsDataGiven(T** data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    void Set_simplyAsDataGiven(T** data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    void Set_simplyAsDataGiven(T** data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void Set_simplyAsDataGiven_vU(T** data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    virtual void Set_simplyAsDataGiven(T** data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);//=0;
    virtual void Set_simplyAsDataGiven(T** data, int QExtRows, int ExtRowsL);
    //
    virtual void Set_simplyAsDataGiven(std::vector<std::vector<T>>data, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0)=0;
    //
    void Set_simplyAsDataGiven(T* data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    void Set_simplyAsDataGiven(T* data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0)=0;
    void Set_simplyAsDataGiven(T* data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0)=0;
    //void Set_simplyAsDataGiven_vU(T* data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    virtual void Set_simplyAsDataGiven(T* data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);//=0;
    virtual void Set_simplyAsDataGiven(T* data, int QExtRows, int ExtRowsL);
    //
    void Set_simplyAsDataGiven(std::vector<T>data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    void Set_simplyAsDataGiven(std::vector<T>data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    void Set_simplyAsDataGiven(std::vector<T>data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void Set_simplyAsDataGiven_vU(std::vector<T>data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    virtual void Set_simplyAsDataGiven(std::vector<T>data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);//=0;
    virtual void Set_simplyAsDataGiven(std::vector<T>data, int QExtRows, int ExtRowsL);
    //
    void Set_simplyAsDataGiven(const T& data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    void Set_simplyAsDataGiven(const T& data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0)=0;
    void Set_simplyAsDataGiven(const T& data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void Set_simplyAsDataGiven_vU(const T& data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    virtual void Set_simplyAsDataGiven(const T& data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);//=0;
    virtual void Set_simplyAsDataGiven(const T& data, int QExtRows, int ExtRowsL);
    //
    //virtual void Set, Add, Ins, Del Ext, Ine Row (T*row, int rowL, int rowN, rest params) et all neto =0;
};

template<typename T> void Array2D_Prototype<T>::construct(){
    int sizeDflt=DEFAULT_SIZE;//ARR2D_SIZE_DEFAULT;
    this->SetNullIni();
    if(sizeDflt==1){
        this->SetOne();
    }
}
template<typename T> void Array2D_Prototype<T>::SetOne(T*val){
    this->SetSize(1, 1);
    T valInner;
    if(val!=NULL){
        valInner=(*(val));
        this->SetElement(valInner, 1, 1);
    }
}
template<typename T> void Array2D_Prototype<T>::SetOne(const T&val){
    this->SetOne(&val);
}

template<typename T> bool Array2D_Prototype<T>::IsRectangularInFact()const{
    bool verdict;
    int Lmax=this->GetRowLengthMax(), Lmin=this->GetRowLengthMin();
    verdict=(Lmin==Lmax);
    return verdict;
}

template<typename T> std::vector<int> Array2D_Prototype<T>::GetSizeAsStdVector()const{
    std::vector<int>Ls;
    int QExtRows=this->GetQExtRows(), curL, minL, maxL;
    for(int NN=1; NN<=QExtRows; NN++){
        curL=this->GetLengthOfRowN(NN);
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
        curL=this->GetLengthOfRowN(NN);
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
        curL=this->GetLengthOfRowN(NN);
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
template<typename T> void Array2D_Prototype<T>::SetSize(std::vector<int>Ls, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->SetSize(Ls.data(), Ls.size(), ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_Prototype<T>::SetSize(int QExtRows, int ExtRowlength){
    std::vector<int>Ls;
    for(int i=0; i<QExtRows; i++){
        Ls.push_back(ExtRowlength);
    }
    this->SetSize(Ls.data(), Ls.size(), 2);
}
//
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(T** data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->Set_simplyAsDataGiven(data, size.GetAsArrayOfExtRowsLengthes().data(), size.GetQExtRows(), ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(T** data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->Set_simplyAsDataGiven(data, size->GetAsArrayOfExtRowsLengthes().data(), size->GetQExtRows(), ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(T** data, std::vector<int>Ls, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->Set_simplyAsDataGiven(data, Ls.data(), Ls.size(), ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(T** data, int QExtRows, int L){
    int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0;
    std::vector<int>Ls;
    for(int i=0; i<QExtRows; i++){
        Ls.push_back(L);
    }
    this->Set_simplyAsDataGiven(data, Ls, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
//
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(T** data, int QExtRows, int*Ls, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    int curL;
    T val;
    this->SetSize(Ls, QExtRows, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
    for(int ERNN=1; ERNN<=QExtRows; ERNN++){
        curL=Ls[ERNN-1];
        for(int IRNN=1; IRNN<=curL; IRNN++){
            val=data[ERNN-1][IRNN-1];
            this->SetElement(val, ERNN, IRNN);
        }
    }
}
//
//
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(T* data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->Set_simplyAsDataGiven(data, size.GetAsArrayOfExtRowsLengthes().data(), size.GetQExtRows(), ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(T* data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->Set_simplyAsDataGiven(data, size->GetAsArrayOfExtRowsLengthes().data(), size->GetQExtRows(), ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(T* data, std::vector<int>Ls, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->Set_simplyAsDataGiven(data, Ls.data(), Ls.size(), ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(T* data, int QExtRows, int L){
    int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0;
    std::vector<int>Ls;
    for(int i=0; i<QExtRows; i++){
        Ls.push_back(L);
    }
    this->Set_simplyAsDataGiven(data, Ls, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(T* data, int QExtRows, int*Ls, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    int curL, posNN;
    T val;
    this->SetSize(Ls, QExtRows, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
    for(int ERNN=1; ERNN<=QExtRows; ERNN++){
        curL=Ls[ERNN-1];
        for(int IRNN=1; IRNN<=curL; IRNN++){
            //Arr2DBy1D_PosNByCoords(int ExtRowN, int IneRowN, std::vector<int>Ls)
            posNN=Arr2DBy1D_PosNByCoords(ERNN, IRNN, QExtRows, Ls);//mylib.h, or fy in array
            val=data[posNN-1];
            this->SetElement(val, ERNN, IRNN);
        }
    }
}
//
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(std::vector<T>data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->Set_simplyAsDataGiven(data, size.GetAsArrayOfExtRowsLengthes().data(), size.GetQExtRows(), ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(std::vector<T>data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->Set_simplyAsDataGiven(data, size->GetAsArrayOfExtRowsLengthes().data(), size->GetQExtRows(), ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(std::vector<T>data, std::vector<int>Ls, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->Set_simplyAsDataGiven(data, Ls.data(), Ls.size(), ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(std::vector<T>data, int QExtRows, int L){
    int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0;
    std::vector<int>Ls;
    for(int i=0; i<QExtRows; i++){
        Ls.push_back(L);
    }
    this->Set_simplyAsDataGiven(data, Ls, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
//
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(std::vector<T>data, int QExtRows, int*Ls, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->Set_simplyAsDataGiven_vU(data.data(), QExtRows, Ls, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
//
//
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(const T&data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->Set_simplyAsDataGiven(data, size.GetAsArrayOfExtRowsLengthes().data(), size.GetQExtRows(), ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(const T&data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->Set_simplyAsDataGiven(data, size->GetAsArrayOfExtRowsLengthes().data(), size->GetQExtRows(), ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(const T&data, std::vector<int>Ls, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->Set_simplyAsDataGiven(data, Ls.data(), Ls.size(), ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(const T&data, int QExtRows, int L){
    int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0;
    std::vector<int>Ls;
    for(int i=0; i<QExtRows; i++){
        Ls.push_back(L);
    }
    this->Set_simplyAsDataGiven(data, Ls, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
//
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven(const T&val, int QExtRows, int*Ls, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    std::vector<T>data;
    int curL;
    for(int i=0; i<QExtRows; i++){
        curL=Ls[i];
        for(int j=0; j<curL; j++){
            data.push_back(val);
        }
    }
    this->Set_simplyAsDataGiven_vU(data, QExtRows, Ls, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
//
//
template <class T> class Array2D_V1_Rect: public Array2D_Prototype<T>{
    std::vector<T>data;
    Array2DSize size;
  public:
    Array2D_V1_Rect(T** data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    Array2D_V1_Rect(T** data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    Array2D_V1_Rect(T** data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void Set_simplyAsDataGiven_vU(T** data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    Array2D_V1_Rect(T** data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);//=0;
    Array2D_V1_Rect(T** data, int QExtRows, int ExtRowsL);
    //
    Array2D_V1_Rect(std::vector<std::vector<T>>data, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0)=0;
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
    Array2D_V1_Rect(const T& data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0)=0;
    Array2D_V1_Rect(const T& data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void Set_simplyAsDataGiven_vU(const T& data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    Array2D_V1_Rect(const T& data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);//=0;
    Array2D_V1_Rect(const T& data, int QExtRows, int ExtRowsL);
    //
    ~Array2D_V1_Rect();
    //

    //
    //virtual ~Array2D_Prototype();
    virtual int GetTypeN() const;//=0;
    //virtual void SetTypeN(int typeN=0);//=0;
    virtual int GetQExtRows() const;// =0;
    virtual int GetExtRowLength(int rowN=-1)const;// =0;
    virtual T GetElement(int ExtRowN, int inRowPosN)const;// =0;
    virtual T* GetPointerToElement(int ExtRowN, int inRowPosN)const;// =0;
    virtual void SetElement(const T& val, int ExtRowN, int inRowPosN);//=0;
    virtual bool IsRectangularInFact() const ;
    virtual bool IsRectangularByType() const;// =0;
    virtual int GetLengthOfRowN(int N=-1) const;//=0;
    virtual std::vector<int> GetSizeAsStdVector() const;
    virtual Array2DSize GetSize();//=0;
    virtual int GetRowLengthMax() const ;
    virtual int GetRowLengthMin() const ;
    //std::vector<int>GetNsOfLmax() const;
    //std::vector<int>GetNsOfLmin()const;
    //std::vector<int>GetNsOfL(int L) const ;
    //
    virtual void SetSize(int QExtRows=1, int ExtRowlength=1);
    virtual void SetSize(int*ExtRowlengthes, int QExtRows=1, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);//=0;
    //void SetSize(std::vector<int>Ls, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void SetSize(const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void SetSize(const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //
    virtual void construct();
    virtual void SetNullIni();//=0;
    virtual void SetNull()=0;
    virtual void SetOne(const T&val);//=0;
    virtual void SetOne(T *param);
    //
    //std::vector<std::vector<T>>GetData_AsStdVector2D();
    //std::vector<T>GetData_AsStdVector1D();
    //
    virtual void Assign(const Array2D_Prototype<T>*obj);//=0;
    //
    //
    //void Set_simplyAsDataGiven(T** data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void Set_simplyAsDataGiven(T** data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void Set_simplyAsDataGiven(T** data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    ////void Set_simplyAsDataGiven_vU(T** data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    virtual void Set_simplyAsDataGiven(T** data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    virtual void Set_simplyAsDataGiven(T** data, int QExtRows, int ExtRowsL);
    //
    virtual void Set_simplyAsDataGiven(std::vector<std::vector<T>>data, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);//=0;
    //
    //void Set_simplyAsDataGiven(T* data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void Set_simplyAsDataGiven(T* data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0)=0;
    //void Set_simplyAsDataGiven(T* data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0)=0;
    ////void Set_simplyAsDataGiven_vU(T* data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    virtual void Set_simplyAsDataGiven(T* data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);//=0;
    virtual void Set_simplyAsDataGiven(T* data, int QExtRows, int ExtRowsL);
    //
    //void Set_simplyAsDataGiven(std::vector<T>data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void Set_simplyAsDataGiven(std::vector<T>data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void Set_simplyAsDataGiven(std::vector<T>data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    ////void Set_simplyAsDataGiven_vU(std::vector<T>data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    virtual void Set_simplyAsDataGiven(std::vector<T>data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);//=0;
    virtual void Set_simplyAsDataGiven(std::vector<T>data, int QExtRows, int ExtRowsL);
    //
    //void Set_simplyAsDataGiven(const T& data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    //void Set_simplyAsDataGiven(const T& data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0)=0;
    //void Set_simplyAsDataGiven(const T& data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    ////void Set_simplyAsDataGiven_vU(const T& data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    virtual void Set_simplyAsDataGiven(const T& data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);//=0;
    virtual void Set_simplyAsDataGiven(const T& data, int QExtRows, int ExtRowsL);
    //
    //virtual void Set, Add, Ins, Del Ext, Ine Row (T*row, int rowL, int rowN, rest params) et all neto =0;
};
//
//template<typename T> void Array2D_V1_Rect<T>::Set_simplyAsDataGiven(const T&val){}

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
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=1){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=2;
    }
    this->Set_simplyAsDataGiven(data, ExtRowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> Array2D_V1_Rect<T>::Array2D_V1_Rect(std::vector<T>data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->construct();
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=1){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=2;
    }
    this->Set_simplyAsDataGiven(data, QExtRows, ExtRowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> Array2D_V1_Rect<T>::Array2D_V1_Rect(std::vector<T>data, int QExtRows, int ExtRowsL){
    this->construct();
    this->Set_simplyAsDataGiven(data, QExtRows, ExtRowsL);
}
template<typename T> Array2D_V1_Rect<T>::Array2D_V1_Rect(const T& data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->construct();
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=1){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=2;
    }
    this->Set_simplyAsDataGiven(data, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> Array2D_V1_Rect<T>::Array2D_V1_Rect(const T& data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->construct();
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=1){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=2;
    }
    this->Set_simplyAsDataGiven(data, size, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> Array2D_V1_Rect<T>::Array2D_V1_Rect(const T& data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->construct();
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=1){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=2;
    }
    this->Set_simplyAsDataGiven(data, ExtRowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> Array2D_V1_Rect<T>::Array2D_V1_Rect(const T& data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    this->construct();
    if(ifNotRect_NonRect0_MakeRectBy_Max1Min2!=1){
        ifNotRect_NonRect0_MakeRectBy_Max1Min2=2;
    }
    this->Set_simplyAsDataGiven(data, QExtRows, ExtRowsLs, ifNotRect_NonRect0_MakeRectBy_Max1Min2);
}
template<typename T> Array2D_V1_Rect<T>::Array2D_V1_Rect(const T& data, int QExtRows, int ExtRowsL){
    this->construct();
    this->Set_simplyAsDataGiven(data, QExtRows, ExtRowsL);
}
//
template<typename T> int Array2D_V1_Rect<T>::GetTypeN() const{
    return Arr2DSize_Rect_TypeN;
}
template<typename T> int Array2D_V1_Rect<T>::GetQExtRows() const{
    return this->size.GetQExtRows();
}
template<typename T> int Array2D_V1_Rect<T>::GetExtRowLength(int rowN) const{
    return this->size.GetRowLength(rowN);
}
template<typename T> T Array2D_V1_Rect<T>::GetElement(int ExtRowN, int inRowPosN) const{
    int PosNN=Arr2DBy1D_PosNByCoords(ExtRowN, inRowPosN, this->GetQEQExtRows(), this->GetRowLengthMax());
    return this->data[PosNN-1];
}
template<typename T> T* Array2D_V1_Rect<T>::GetPointerToElement(int ExtRowN, int inRowPosN) const{
    int PosNN=Arr2DBy1D_PosNByCoords(ExtRowN, inRowPosN, this->GetQEQExtRows(), this->GetRowLengthMax());
    return &(this->data[PosNN-1]);
}
template<typename T> void Array2D_V1_Rect<T>::SetElement(const T& val, int ExtRowN, int inRowPosN){
    int PosNN=Arr2DBy1D_PosNByCoords(ExtRowN, inRowPosN, this->GetQEQExtRows(), this->GetRowLengthMax());
    this->data[PosNN-1]=val;
}
template<typename T> bool Array2D_V1_Rect<T>::IsRectangularInFact()const{
    return Array2D_Prototype<T>::IsRectangularInFact();
    //return this->size.IsRectangularInFact();
}
template<typename T> bool Array2D_V1_Rect<T>::IsRectangularByType()const{
    return this->size.IsRectangularByType();
}
template<typename T> int  Array2D_V1_Rect<T>::GetLengthOfRowN(int N)const{
    return this->size.GetRowLength(N);
}
template<typename T> std::vector<int>  Array2D_V1_Rect<T>::GetSizeAsStdVector()const{
    return this->size.GetSizeAsStdVector();
}
template<typename T> Array2DSize  Array2D_V1_Rect<T>::GetSize(){
    return this->size;
}
template<typename T> int  Array2D_V1_Rect<T>::GetRowLengthMin()const{
    return this->size.GetRowLengthMin();
}
template<typename T> int  Array2D_V1_Rect<T>::GetRowLengthMax()const{
    return this->size.GetRowLengthMax();
}
//
template<typename T> void  Array2D_V1_Rect<T>::SetSize(int QExtRows, int ExtRowlength){
    T val;
    int QElementsOld=this->GetQExtRows(), QElementsNew=QExtRows*ExtRowlength;
    if(QElementsOld<QElementsNew){
        for(int i=0; i<(QElementsNew-QElementsOld); i++){
            this->data.push_back(val);
        }
    }else if(QElementsOld>QElementsNew){
        for(int i=0; i<(QElementsOld-QElementsNew); i++){
            this->data.pop_back();
        }
    }
    this->size.Set(QExtRows, ExtRowlength, Arr2DSize_Rect_TypeN);
}
template<typename T> void  Array2D_V1_Rect<T>::SetSize(int*ExtRowlengthes, int QExtRows, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
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
    this->size.Set(ExtRowlengthes, QExtRows, Arr2DSize_Rect_TypeN);
}

//
template<typename T> void  Array2D_V1_Rect<T>::construct(){
    Array2D_Prototype<T>::construct();
}
template<typename T> void  Array2D_V1_Rect<T>::SetNullIni(){
    this->SetNull();
}
template<typename T> void  Array2D_V1_Rect<T>::SetNull(){
    this->data.clear();
    this->size.SetNull();
}
template<typename T> void  Array2D_V1_Rect<T>::SetOne(const T&val){
    this->data.clear();
    this->size.SetNull();
    this->data.push_back(val);
    this->size.Set(1, 1);
}
template<typename T> void  Array2D_V1_Rect<T>::SetOne(T*param){
    T val;
    if(param!=NULL){
        val=(*(param));
    }
    this->SetOne(val);
}
//
template<typename T> void  Array2D_V1_Rect<T>::Assign(const Array2D_Prototype<T>*obj){
    int LminGiven, LmaxGiven, curL, ObjQExtRows;
    std::vector<int>ObjSize;
    std::vector<T>ObjData;
    ObjData=obj->GetData_AsStdVector1D();
    ObjSize=obj->GetSizeAsStdVector();
    ObjQExtRows=ObjSize.size();
    for(int i=0; i<ObjQExtRows; i++){
        curL=ObjSize[i];
        if(i==0 || (i>0 && curL<LminGiven)){
            LminGiven=curL;
        }
        if(i==0 || (i>0 && curL<LmaxGiven)){
            LmaxGiven=curL;
        }
    }
    Array2DSize sizeNew(ObjSize, Arr2DSize_Rect_TypeN);
    this->Set_simplyAsDataGiven(ObjData, sizeNew, 2);
}
//
template<typename T> void  Array2D_V1_Rect<T>::Set_simplyAsDataGiven(T** data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){
    Coords2DInt coordsGiven, coordsOwn;
    int curL, LminGiven, LmaxGiven;
    std::vector<int>ObjSize;
    std::vector<T>ObjData, GivenData=this->GetData_AsStdVector1D();
    for(int i=0; i<QExtRows; i++){
        curL=ObjSize[i];
        if(i==0 || (i>0 && curL<LminGiven)){
            LminGiven=curL;
        }
        if(i==0 || (i>0 && curL<LmaxGiven)){
            LmaxGiven=curL;
        }
    }
    this->SetSize(QExtRows, LmaxGiven);
    //
    // algorythm of filling with vals
}


#endif // ARRAY2DLIB_H
