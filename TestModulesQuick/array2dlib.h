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
    virtual void SetTypeN(int typeN=0)=0;
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
    virtual void SetSize(int QExtRows=1, int ExtRowlength=1)=0;
    virtual void SetSize(int*ExtRowlengthes, int QExtRows=1, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0)=0;
    virtual void SetSize(std::vector<int>Ls, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0)=0;
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
    void Set_simplyAsDataGiven_vU(T** data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    virtual void Set_simplyAsDataGiven(T** data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0)=0;
    virtual void Set_simplyAsDataGiven(T** data, int QExtRows, int ExtRowsL);
    //
    virtual void Set_simplyAsDataGiven(std::vector<std::vector<T>>data, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0)=0;
    //
    void Set_simplyAsDataGiven(T* data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    void Set_simplyAsDataGiven(T* data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0)=0;
    void Set_simplyAsDataGiven(T* data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0)=0;
    void Set_simplyAsDataGiven_vU(T* data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    virtual void Set_simplyAsDataGiven(T* data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0)=0;
    virtual void Set_simplyAsDataGiven(T* data, int QExtRows, int ExtRowsL);
    //
    void Set_simplyAsDataGiven(std::vector<T>data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    void Set_simplyAsDataGiven(std::vector<T>data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    void Set_simplyAsDataGiven(std::vector<T>data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    void Set_simplyAsDataGiven_vU(std::vector<T>data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    virtual void Set_simplyAsDataGiven(std::vector<T>data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0)=0;
    virtual void Set_simplyAsDataGiven(std::vector<T>data, int QExtRows, int ExtRowsL);
    //
    void Set_simplyAsDataGiven(const T& data, const Array2DSize_Prototype*size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    void Set_simplyAsDataGiven(const T& data, const Array2DSize&size, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0)=0;
    void Set_simplyAsDataGiven(const T& data, std::vector<int>ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    void Set_simplyAsDataGiven_vU(const T& data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0);
    virtual void Set_simplyAsDataGiven(const T& data, int QExtRows, int*ExtRowsLs, int ifNotRect_NonRect0_MakeRectBy_Max1Min2=0)=0;
    virtual void Set_simplyAsDataGiven(const T& data, int QExtRows, int ExtRowsL);
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
//
//template<typename T> int Array2D_Prototype<T>::GetRowLengthMax() const{
//    std::vector<int>Ls=this->GetSizeAsStdVector(), NsOfLmin, NsOfLmax, NsOfL;
//    int QExtRows=Ls.size(), Lmin, Lmax, curL, givenL=-1;
//    for(int ERNN=1; ERNN<=QExtRows; ERNN++){
//        curL=this->GetLengthOfRowN(ERNN);
//        if(ERNN==1 || (ERNN>1 && curL<Lmin)){
//            Lmin=curL;
//        }
//        if(ERNN==1 || (ERNN>1 && curL>Lmax)){
//            Lmax=curL;
//        }
//    }
//    for(int ERNN=1; ERNN<=QExtRows; ERNN++){
//        curL=this->GetLengthOfRowN(ERNN);
//        Ls.push_back(curL);
//        if(curL==givenL){
//            NsOfL.push_back(ERNN);
//        }
//        if(curL==Lmax){
//            NsOfLmax.push_back(ERNN);
//        }
//        if(curL==Lmin){
//            NsOfLmin.push_back(ERNN);
//        }
//    }
//    return Lmax;
//}
//template<typename T> int Array2D_Prototype<T>::GetRowLengthMin() const {
//    std::vector<int>Ls=this->GetSizeAsStdVector(), NsOfLmin, NsOfLmax, NsOfL;
//    int QExtRows=Ls.size(), Lmin, Lmax, curL, givenL=-1;
//    for(int ERNN=1; ERNN<=QExtRows; ERNN++){
//        curL=this->GetLengthOfRowN(ERNN);
//        if(ERNN==1 || (ERNN>1 && curL<Lmin)){
//            Lmin=curL;
//        }
//        if(ERNN==1 || (ERNN>1 && curL>Lmax)){
//            Lmax=curL;
//        }
//    }
//    for(int ERNN=1; ERNN<=QExtRows; ERNN++){
//        curL=this->GetLengthOfRowN(ERNN);
//        Ls.push_back(curL);
//        if(curL==givenL){
//            NsOfL.push_back(ERNN);
//        }
//        if(curL==Lmax){
//            NsOfLmax.push_back(ERNN);
//        }
//        if(curL==Lmin){
//            NsOfLmin.push_back(ERNN);
//        }
//    }
//    return LsLmin
//}
//template<typename T> std::vector<int> Array2D_Prototype<T>::GetNsOfLmax() const{
//    std::vector<int>Ls=this->GetSizeAsStdVector(), NsOfLmin, NsOfLmax, NsOfL;
//    int QExtRows=Ls.size(), Lmin, Lmax, curL, givenL=-1;
//    for(int ERNN=1; ERNN<=QExtRows; ERNN++){
//        curL=this->GetLengthOfRowN(ERNN);
//        if(ERNN==1 || (ERNN>1 && curL<Lmin)){
//            Lmin=curL;
//        }
//        if(ERNN==1 || (ERNN>1 && curL>Lmax)){
//            Lmax=curL;
//        }
//    }
//    for(int ERNN=1; ERNN<=QExtRows; ERNN++){
//        curL=this->GetLengthOfRowN(ERNN);
//        Ls.push_back(curL);
//        if(curL==givenL){
//            NsOfL.push_back(ERNN);
//        }
//        if(curL==Lmax){
//            NsOfLmax.push_back(ERNN);
//        }
//        if(curL==Lmin){
//            NsOfLmin.push_back(ERNN);
//        }
//    }
//    return NsOfLmax;
//}
//template<typename T> std::vector<int> Array2D_Prototype<T>::GetNsOfLmin()const{
//    std::vector<int>Ls=this->GetSizeAsStdVector(), NsOfLmin, NsOfLmax, NsOfL;
//    int QExtRows=Ls.size(), Lmin, Lmax, curL, givenL=-1;
//    for(int ERNN=1; ERNN<=QExtRows; ERNN++){
//        curL=this->GetLengthOfRowN(ERNN);
//        if(ERNN==1 || (ERNN>1 && curL<Lmin)){
//            Lmin=curL;
//        }
//        if(ERNN==1 || (ERNN>1 && curL>Lmax)){
//            Lmax=curL;
//        }
//    }
//    for(int ERNN=1; ERNN<=QExtRows; ERNN++){
//        curL=this->GetLengthOfRowN(ERNN);
//        Ls.push_back(curL);
//        if(curL==givenL){
//            NsOfL.push_back(ERNN);
//        }
//        if(curL==Lmax){
//            NsOfLmax.push_back(ERNN);
//        }
//        if(curL==Lmin){
//            NsOfLmin.push_back(ERNN);
//        }
//    }
//    return NsOfLmin;
//}
//template<typename T> std::vector<int> Array2D_Prototype<T>::GetNsOfL(int L) const{
//    std::vector<int>Ls=this->GetSizeAsStdVector(), NsOfLmin, NsOfLmax, NsOfL;
//    int QExtRows=Ls.size(), Lmin, Lmax, curL, givenL=-1;
//    for(int ERNN=1; ERNN<=QExtRows; ERNN++){
//        curL=this->GetLengthOfRowN(ERNN);
//        if(ERNN==1 || (ERNN>1 && curL<Lmin)){
//            Lmin=curL;
//        }
//        if(ERNN==1 || (ERNN>1 && curL>Lmax)){
//            Lmax=curL;
//        }
//    }
//    for(int ERNN=1; ERNN<=QExtRows; ERNN++){
//        curL=this->GetLengthOfRowN(ERNN);
//        Ls.push_back(curL);
//        if(curL==givenL){
//            NsOfL.push_back(ERNN);
//        }
//        if(curL==Lmax){
//            NsOfLmax.push_back(ERNN);
//        }
//        if(curL==Lmin){
//            NsOfLmin.push_back(ERNN);
//        }
//    }
//    return NsOfL;
//}
//template<typename T> std::vector<int> Array2D_Prototype<T>::GetSizeAsStdVector() const {
//    std::vector<int>Ls=this->GetSizeAsStdVector(), NsOfLmin, NsOfLmax, NsOfL;
//    int QExtRows=Ls.size(), Lmin, Lmax, curL, givenL=-1;
//    for(int ERNN=1; ERNN<=QExtRows; ERNN++){
//        curL=this->GetLengthOfRowN(ERNN);
//        if(ERNN==1 || (ERNN>1 && curL<Lmin)){
//            Lmin=curL;
//        }
//        if(ERNN==1 || (ERNN>1 && curL>Lmax)){
//            Lmax=curL;
//        }
//    }
//    for(int ERNN=1; ERNN<=QExtRows; ERNN++){
//        curL=this->GetLengthOfRowN(ERNN);
//        Ls.push_back(curL);
//        if(curL==givenL){
//            NsOfL.push_back(ERNN);
//        }
//        if(curL==Lmax){
//            NsOfLmax.push_back(ERNN);
//        }
//        if(curL==Lmin){
//            NsOfLmin.push_back(ERNN);
//        }
//    }
//    return Ls;
//}
//
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
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven_vU(T** data, int QExtRows, int*Ls, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){

}
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
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven_vU(T* data, int QExtRows, int*Ls, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){


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
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven_vU(std::vector<T>data, int QExtRows, int*Ls, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){

}
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
template<typename T> void Array2D_Prototype<T>::Set_simplyAsDataGiven_vU(const T&data, int QExtRows, int*Ls, int ifNotRect_NonRect0_MakeRectBy_Max1Min2){

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
//

//




#endif // ARRAY2DLIB_H
