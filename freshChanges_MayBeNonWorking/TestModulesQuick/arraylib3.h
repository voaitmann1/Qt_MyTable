#ifndef ARRAYLIB3_H
#define ARRAYLIB3_H

#include "array1d_size2d_elem2d_1.h"



//class arrayLib3
//{
//public:
//    arrayLib3();
//};

//const int ARR2D_SIZE_DEFAULT=0;
const int ARR2D_TYPE_RECTANGULAR=1;
const int ARR2D_TYPE_RARE=2;
const int ARR2D_TYPE_VAR_LEN_P=3;
const int ARR2D_TYPE_VAR_LEN_V=4;
const int ARR2D_TYPE_VAR_LEN_P_1D=5;
const int ARR2D_TYPE_VAR_LEN_V_1D=6;
const int ARR2D_TYPE_DEFAULT=ARR2D_TYPE_VAR_LEN_V_1D;

template <class T> class Array2D_Prototype{
    virtual ~Array2D_Prototype();
    virtual int GetTypeN() const=0;
    virtual void SetTypeN(int typeN=0)=0;
    virtual int GetQExtRows() const =0;
    virtual int GetExtRowLength(int rowN=-1)const =0;
    virtual T GetElement(int ExtRowN, int inRowPosN)const =0;
    virtual void SetElement(const T& val, int ExtRowN, int inRowPosN)=0;
    virtual bool IsRectangularInFact() const ;
    virtual bool IsRectangularByType() const =0;
    virtual int GetLengthOfRowN(int N=-1) const=0;
    virtual std::vector<int> GetSizeAsStdVector() const;
    virtual int GetRowLengthMax() const ;
    virtual int GetRowLengthMin() const ;
    virtual std::vector<int>GetNsOfLmax() const;
    virtual std::vector<int>GetNsOfLmin()const;
    virtual std::vector<int>GetNsOfL(int L)const ;
    //
    virtual void SetSize(int QExtRows=1, int ExtRowlength=1)=0;
    virtual void SetSize(int*ExtRowlengthes, int QExtRows=1)=0;
    virtual void SetSize(std::vector<int>Ls)=0;
    void SetSize(const Array2DSize&size);
    void SetSize(Array2DSize_Prototype*size);
    //
    virtual void construct();
    virtual void SetNullIni()=0;
    virtual void SetNull()=0;
    virtual void SetOne(T*val=NULL)=0;
    virtual void SetOne(const T&val);
    //
    //
    //
    //virtual void Set(const std::vector<std::vector<T>>data, const T& defaultVal, TParamsOfDataShift*dataShift=NULL, bool transposed=false, int ifNotRect_DoForNonRect0_ByMin1_ByMax2ByLast3ByExisting4=0);
    ////
    //virtual void Set(const std::vector<T>data, std::vector<int>Ls, const T& defaultVal, TParamsOfDataShift*dataShift=NULL, bool transposed=false, int ifNotRect_DoForNonRect0_ByMin1_ByMax2ByLast3ByExisting4=0);
    //virtual void Set(const std::vector<T>data, int*Ls, int QExtRows, const T& defaultVal, TParamsOfDataShift*dataShift=NULL, bool transposed=false, int ifNotRect_DoForNonRect0_ByMin1_ByMax2ByLast3ByExisting4=0);
    //virtual void Set(const std::vector<T>data, int QExtRows, int extRowL, const T& defaultVal, TParamsOfDataShift*dataShift=NULL, bool transposed=false);
    ////
    //virtual void Set(const T*data, std::vector<int>Ls, const T& defaultVal, TParamsOfDataShift*dataShift=NULL, bool transposed=false, int ifNotRect_DoForNonRect0_ByMin1_ByMax2ByLast3ByExisting4=0, int QElementsGiven=-1);//prototype ne match, ne marked
    //virtual void Set(const T*data, int*Ls, int QExtRows=1, const T& defaultVal, TParamsOfDataShift*dataShift=NULL, bool transposed=false, int ifNotRect_DoForNonRect0_ByMin1_ByMax2ByLast3ByExisting4=0, int QElementsGiven=-1);//prototype ne match, ne marked
    //virtual void Set(const T*data, int QExtRows=1, int extRowL=1, const T& defaultVal, TParamsOfDataShift*dataShift=NULL, bool transposed=false, int QElementsGiven=-1);//prototype ne match, ne marked
    ////
    //virtual void Set(const T**data, std::vector<int>Ls, const T& defaultVal, TParamsOfDataShift*dataShift=NULL, bool transposed=false, int ifNotRect_DoForNonRect0_ByMin1_ByMax2ByLast3ByExisting4=0);//for real: prototype ne match
    //virtual void Set(const T**data, int*Ls, int QExtRows, const T& defaultVal, TParamsOfDataShift*dataShift=NULL, bool transposed=false, int ifNotRect_DoForNonRect0_ByMin1_ByMax2ByLast3ByExisting4=0);//prototype ne match, ne marked
    //virtual void Set(const T**data, int QExtRows, int extRowL, const T& defaultVal, TParamsOfDataShift*dataShift=NULL, bool transposed=false);//prototype ne match, marked several times
    ////
    //virtual void Set(const T&data, std::vector<int>Ls, const T& defaultVal, TParamsOfDataShift*dataShift=NULL, bool transposed=false, int ifNotRect_DoForNonRect0_ByMin1_ByMax2ByLast3ByExisting4=0);
    //virtual void Set(const T&data, int*Ls, int QExtRows, const T& defaultVal, TParamsOfDataShift*dataShift=NULL, bool transposed=false, int ifNotRect_DoForNonRect0_ByMin1_ByMax2ByLast3ByExisting4=0);
    //virtual void Set(const T&data, int QExtRows, int extRowL, const T& defaultVal, TParamsOfDataShift*dataShift=NULL, bool transposed=false);
    ////
    ////
    //virtual void Set(const std::vector<std::vector<T>>data, TParamsOfDataShift*dataShift=NULL, bool transposed=false, T*dfltVal=NULL, int ifNotRect_DoForNonRect0_ByMin1_ByMax2ByLast3ByExisting4=0);
    ////
    //virtual void Set(const std::vector<T>data, std::vector<int>Ls, TParamsOfDataShift*dataShift=NULL, bool transposed=false, T*dfltVal=NULL, int ifNotRect_DoForNonRect0_ByMin1_ByMax2ByLast3ByExisting4=0);
    //virtual void Set(const std::vector<T>data, int*Ls, int QExtRows, TParamsOfDataShift*dataShift=NULL, bool transposed=false, T*dfltVal=NULL, int ifNotRect_DoForNonRect0_ByMin1_ByMax2ByLast3ByExisting4=0);
    //virtual void Set(const std::vector<T>data, int QExtRows, int extRowL, TParamsOfDataShift*dataShift=NULL, bool transposed=false, T*dfltVal=NULL, bool transposed=false);
    ////
    //virtual void Set(const T*data, std::vector<int>Ls, TParamsOfDataShift*dataShift=NULL, bool transposed=false, T*dfltVal=NULL, int ifNotRect_DoForNonRect0_ByMin1_ByMax2ByLast3ByExisting4=0, int QElementsGiven=-1);//prototype ne match, ne marked
    //virtual void Set(const T*data, int*Ls, int QExtRows=1, TParamsOfDataShift*dataShift=NULL, bool transposed=false, T*dfltVal=NULL, int ifNotRect_DoForNonRect0_ByMin1_ByMax2ByLast3ByExisting4=0, int QElementsGiven=-1);//prototype ne match, ne marked
    //virtual void Set(const T*data, int QExtRows=1, int extRowL=1, TParamsOfDataShift*dataShift=NULL, bool transposed=false, T*dfltVal=NULL, int QElementsGiven=-1);//prototype ne match, ne marked
    ////
    //virtual void Set(const T**data, std::vector<int>Ls, TParamsOfDataShift*dataShift=NULL, bool transposed=false, T*dfltVal=NULL, int ifNotRect_DoForNonRect0_ByMin1_ByMax2ByLast3ByExisting4=0);//for real: prototype ne match
    //virtual void Set(const T**data, int*Ls, int QExtRows, TParamsOfDataShift*dataShift=NULL, bool transposed=false, T*dfltVal=NULL, int ifNotRect_DoForNonRect0_ByMin1_ByMax2ByLast3ByExisting4=0);//prototype ne match, ne marked
    //virtual void Set(const T**data, int QExtRows, int extRowL, TParamsOfDataShift*dataShift=NULL, bool transposed=false, T*dfltVal=NULL);//prototype ne match, marked several times
    ////
    //virtual void Set(const T&data, std::vector<int>Ls, TParamsOfDataShift*dataShift=NULL, bool transposed=false, T*dfltVal=NULL,  int ifNotRect_DoForNonRect0_ByMin1_ByMax2ByLast3ByExisting4=0);
    //virtual void Set(const T&data, int*Ls, int QExtRows, TParamsOfDataShift*dataShift=NULL, bool transposed=false, T*dfltVal=NULL, int ifNotRect_DoForNonRect0_ByMin1_ByMax2ByLast3ByExisting4=0);
    //virtual void Set(const T&data, int QExtRows, int extRowL, TParamsOfDataShift*dataShift=NULL, bool transposed=false, T*dfltVal=NULL);
    //
    //
    //
    virtual void set_simpleAsDataGiven(const std::vector<std::vector<T>>data, int ifNotRect_DoForNonRect0_ByMin1=0);
    //
    virtual void set_simpleAsDataGiven(const std::vector<T>data, std::vector<int>Ls, int ifNotRect_DoForNonRect0_ByMin1=0);
    virtual void set_simpleAsDataGiven(const std::vector<T>data, int*Ls, int QExtRows, int ifNotRect_DoForNonRect0_ByMin1=0);
    virtual void set_simpleAsDataGiven(const std::vector<T>data, int QExtRows, int extRowL);
    //
    virtual void set_simpleAsDataGiven(const T*data, std::vector<int>Ls, int ifNotRect_DoForNonRect0_ByMin1=0, int QElementsGiven=-1);//prototype ne match, ne marked
    virtual void set_simpleAsDataGiven(const T*data, int*Ls, int QExtRows=1, int ifNotRect_DoForNonRect0_ByMin1=0, int QElementsGiven=-1);//prototype ne match, ne marked
    virtual void set_simpleAsDataGiven(const T*data, int QExtRows=1, int extRowL=1, int QElementsGiven=-1);//prototype ne match, ne marked
    //
    virtual void set_simpleAsDataGiven(const T**data, std::vector<int>Ls, int ifNotRect_DoForNonRect0_ByMin1=0);//for real: prototype ne match
    virtual void set_simpleAsDataGiven(const T**data, int*Ls, int QExtRows, int ifNotRect_DoForNonRect0_ByMin1=0);//prototype ne match, ne marked
    virtual void set_simpleAsDataGiven(const T**data, int QExtRows, int extRowL);//prototype ne match, marked several times
    //
    //virtual void set_simpleAsDataGiven(const T&data, std::vector<int>Ls, int ifNotRect_DoForNonRect0_ByMin1=0);
    //virtual void set_simpleAsDataGiven(const T&data, int*Ls, int QExtRows, int ifNotRect_DoForNonRect0_ByMin1=0);
    //virtual void set_simpleAsDataGiven(const T&data, int QExtRows, int extRowL);
    //
    //
    //
    ////virtual void SetExtRow(T*row, int rowL, int extRowNN=-1, const T&defaultVal, int ifNotRect_NonRect0_RectBy_New1Old2Min3Max4=0, bool reversed=false, TParamsOfDataShift*dataShift=NULL);
    ////virtual void SetExtRow(T*row, int rowL=0, int extRowNN=-1, int ifNotRect_NonRect0_RectBy_New1Old2Min3Max4=0, bool reversed=false, TParamsOfDataShift*dataShift=NULL, T*dfltVal=NULL);
    //virtual void setExtRow_simpleAsDataGiven(T*row, int rowL=0, int extRowNN=-1, int ifNotRect_NonRect0_RectBy_New1Old2Min3Max4=0);
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

template<typename T>void Array2D_Prototype<T>::set_simpleAsDataGiven(std::vector<std::vector<T>>data, int ifNotRect_DoForNonRect0_ByMin1){
    std::vector<int>Ls;
    T val;
    int QExtRows=data.size(), curL, maxL, minL;//, greaterL;
    for(int NN=1; NN<=QExtRows; NN++){
        curL=data[NN-1].size();
        Ls.push_back(curL);
        if(NN==1 ||(NN>1 && curL>maxL)){
            maxL=curL;
        }
        if(NN==1 ||(NN>1 && curL<minL)){
            minL=curL;
        }
    }
    //
    if(minL==maxL || ifNotRect_DoForNonRect0_ByMin1==0){
        this->SetSize(Ls);
        for(int ERNN=1; ERNN<=QExtRows; ERNN++){
            for(int IRNN=1; IRNN<=Ls[ERNN-1]; IRNN++){
                val=data[ERNN-1][IRNN-1];
                this->SetElement(val, ERNN, IRNN);
            }
        }
    }else{
        if(ifNotRect_DoForNonRect0_ByMin1==1){
            this->SetSize(QExtRows, minL);
            for(int ERNN=1; ERNN<=QExtRows; ERNN++){
                for(int IRNN=1; IRNN<=minL; IRNN++){
                    val=data[ERNN-1][IRNN-1];
                    this->SetElement(val, ERNN, IRNN);
                }
            }
        }else{
            //NOp
        }
    }
}

template<typename T> void Array2D_Prototype<T>::set_simpleAsDataGiven(T**data, int*Ls, int QExtRows, int ifNotRect_DoForNonRect0_ByMin1){//prototype ne match, marked
    T val;
    int curL, maxL, minL, lastL=0;//, greaterL;
    if(Ls!=NULL){
        for(int NN=1; NN<=QExtRws; NN++){
            curL=Ls[NN-1];
            Ls.push_back(curL);
            if(NN==1 ||(NN>1 && curL>maxL)){
                maxL=curL;
            }
            if(NN==1 ||(NN>1 && curL<minL)){
                minL=curL;
            }
        }
        lastL=Ls[QExtRows-1];
   }else{
        minL =0;
        maxL =0;
        lastL=0;
    }
    //
    if(minL==maxL || ifNotRect_DoForNonRect0_ByMin1==0){
        this->SetSize(Ls, QExtRows);
        for(int ERNN=1; ERNN<=QExtRws; ERNN++){
            for(int IRNN=1; IRNN<=Ls[ERNN-1]; IRNN++){
                val=data[ERNN-1][IRNN-1];
                this->SetElement(val, ERNN, IRNN);
            }
        }
    }else{
        if(ifNotRect_DoForNonRect0_ByMin1==1){
            this->SetSize(QExtRows, minL);
            for(int ERNN=1; ERNN<=QExtRws; ERNN++){
                for(int IRNN=1; IRNN<=minL; IRNN++){
                    val=data[ERNN-1][IRNN-1];
                    this->SetElement(val, ERNN, IRNN);
                }
            }
        }else{
            //NOp
        }
    }
}

template<typename T> void Array2D_Prototype<T>::set_simpleAsDataGiven(T**data, std::vector<int>Ls, int ifNotRect_DoForNonRect0_ByMin1){//prototype ne match, marked
    this->set_simpleAsDataGiven(data, Ls.data(), Ls.size());
}

template<typename T> void Array2D_Prototype<T>::set_simpleAsDataGiven(T**data, int QExtRows, int extRowL){//prototype ne match, marked
   std::vector<int>Ls;
   for(int i=0; i<QExtRows; i++){
       Ls.push_back(extRowL);
   }
   this->set_simpleAsDataGiven(data, Ls);
}

template<typename T> void Array2D_Prototype<T>::set_simpleAsDataGiven(T*data, int*Ls, int QExtRows, int ifNotRect_DoForNonRect0_ByMin1, int QElementsGiven){//prototype ne match, marked
    T val;
    int PosNN, QElementsNeeded=0;
    if(Ls!=NULL){
        for(int NN=1; NN<=QExtRws; NN++){
            QElementsNeeded+=Ls[NN-1];
        }
    }//else sum of 0s
    if(QElementsGiven<0){
        QElementsGiven= QElementsNeeded;
    }
    if(QElementsNeeded>0  && QElementsGiven>=0 && QElementsNeeded<=QElementsGiven){
        this->SetSize(Ls, QExtRows);
        if(data!=NULL){
            for(int ERNN=1; ERNN<=QExtRws; ERNN++){
                for(int IRNN=1; IRNN<=Ls[ERNN-1]; IRNN++){
                    PosNN=Arr2DBy1D_PosNByCoords(ERNN, IRNN, Ls);
                    val=data[PosNN-1];
                    this->SetElement(val, ERNN, IRNN);
                }
            }
        }
    }
}

template<typename T> void Array2D_Prototype<T>::set_simpleAsDataGiven(std::vector<T>data, std::vector<int>Ls, int ifNotRect_DoForNonRect0_ByMin1){
    this->set_simpleAsDataGiven(data.data(), Ls.data(), Ls.size(), data.size());
}

template<typename T> void Array2D_Prototype<T>::set_simpleAsDataGiven(T*data, std::vector<int>Ls, int ifNotRect_DoForNonRect0_ByMin1, int QElementsGiven){//prototype ne match, marked
   this->set_simpleAsDataGiven(data, Ls.data(), Ls.size(), QElementsGiven);
}





template<typename T> void Array2D_Prototype<T>::set_simpleAsDataGiven(T*data, int QExtRows, int extRowL, int QElementsGiven){//prototype ne match, marked
    std::vector<int>Ls;
    int QElementsNereded=QExtRows*extRowL;
    for(int i=0; i<QExtRows; i++){
        Ls.push_back(extRowL);
    }
    this->set_simpleAsDataGiven(data, Ls.data(), Ls.size(), QElementsGiven);
}


//template<typename T> void Array2D_Prototype<T>::setExtRow_simpleAsDataGiven(T*row, int rowL, int extRowNN, int ifNotRect_NonRect0_RectBy_New1Old2Min3Max4){
//    int QExtRows=this->GetQExtRows(), oldRowL, newL, minL=this->GetRowLengthMin(), maxL=this->GetRowLengthMax();
//    std::vector<int>Ls;
//    T val;
//    if(extRowNN<0){
//        extRowNN+=(QExtRows+1);
//    }
//    if(extRowNN>=0 && extRowNN<=QExtRows){//ja, hin 0, n'1
//        oldRowL=this->GetExtRowLength(extRowNN);
//        if(rowL==0){
//            rowL=oldRowL;
//        }
//        if(rowL==oldRowL){
//            //NOp: no resizing
//        }else{
//            Ls=this->GetSizeAsStdVector();
//            if(minL!=maxL || ifNotRect_NonRect0_RectBy_New1Old2Min3Max4==0){
//                Ls[extRowNN-1]=rowL;
//                this->SetSize(Ls);
//            }else{
//                switch(ifNotRect_NonRect0_RectBy_New1Old2Min3Max4){
//                    case 1:
//                        newL=rowL;
//                    break;
//                    case 2:
//                        newL=oldRowL;
//                    break;
//                    case 3:
//                        if(rowL<oldRowL){
//                            newL=rowL;
//                        }
//                    break;
//                    case 4:
//                        if(rowL>oldRowL){
//                            newL=rowL;
//                        }
//                    break;
//                }
//                if(newL!=oldRowL){
//                    this->SetSize(QExtRows, newL);
//                }
//            }
//        }
//        if(row!=NULL && rowL!=0){
//            if(extRowNN>0){
//                for(int IRNN=1;  IRNN<=rowL; IRNN++){
//                    val=row[IRNN-1];
//                    this->SetElement(val, extRowNN, IRNN);
//                }
//            }else if(extRowNN==0){
//                for(int IRNN=1;  IRNN<=rowL; IRNN++){
//                    val=row[IRNN-1];
//                    for(int ERNN=1; ERNN<=QExtRows;  ERNN++){
//                        this->SetElement(val, ERNN, IRNN);
//                    }
//                }
//            }
//        }
//    }//else extRowNN n'fit
//}//fn setExtRow_simple
template<typename T> void Array2D_Prototype<T>::SetSize(const Array2DSize&size){
    std::vector<int>rowLs=size.GetLengthes();
    this->SetSize(rowLs);
}
template<typename T> void Array2D_Prototype<T>::SetSize(Array2DSize_Prototype*size){
    std::vector<int>rowLs=size->GetLengthes();
    this->SetSize(rowLs);
}



//---------------------------------------------------------------------

template <class T> class Array2D_Rectangular{

    virtual ~Array2D_Rectangular();
    virtual int GetTypeN()=0;
    virtual void SetTypeN(int typeN=0)=0;
    virtual int GetQExtRows()=0;
    virtual int GetExtRoLength(int rowN=-1)=0;
    virtual T GetElement(int ExtRowN, int inRowPosN)=0;
    virtual void SetElement(const T& val, int ExtRowN, int inRowPosN)=0;
    virtual void SetSize(int QExtRows=1, int ExtRowlength=1)=0;
    virtual void SetSize(int*ExtRowlengthes, int QExtRows=1)=0;
    virtual void SetSize(std::vector<int>Ls)=0;
};




template <class T> class Array2D_P1D_R{
    T*data;
    Array2DSize_Prototype*size;
    Array2D_P1D_R(int QEsxtRows, int*rowsLs);
    virtual ~Array2D_P1D_R()=0;
    virtual void SetSize(const Array2DSize& sizeNew);
    virtual T GetElement(int ExtRowN, int IneRowN);
    virtual T GetElement(const Coords2DInt& coords);
    virtual void SetElement(const T& val, int ExtRowN, int IneRowN);
    virtual void SetElement(const T& val, const Coords2DInt& coords);
    virtual int GetTypeN()const;

};

template <class T> class Array2D_P1D_VL{
    virtual ~Array2D_P1D_VL()=0;
    virtual void SetSize(const Array2DSize& sizeNew);
    virtual T GetElement(int ExtRowN, int IneRowN);
    virtual T GetElement(const Coords2DInt& coords);
    virtual void SetElement(const T& val, int ExtRowN, int IneRowN);
    virtual void SetElement(const T& val, const Coords2DInt& coords);
    virtual int GetTypeN()const;
};
template <class T> class Array2D_V1D_R{
    virtual ~Array2D_V1D_R()=0;
    virtual void SetSize(const Array2DSize& sizeNew);
    virtual T GetElement(int ExtRowN, int IneRowN);
    virtual T GetElement(const Coords2DInt& coords);
    virtual void SetElement(const T& val, int ExtRowN, int IneRowN);
    virtual void SetElement(const T& val, const Coords2DInt& coords);
    virtual int GetTypeN()const;
};

template <class T> class Array2D_V1D_VL{
    virtual ~Array2D_V1D_VL()=0;
    virtual void SetSize(const Array2DSize& sizeNew);
    virtual T GetElement(int ExtRowN, int IneRowN);
    virtual T GetElement(const Coords2DInt& coords);
    virtual void SetElement(const T& val, int ExtRowN, int IneRowN);
    virtual void SetElement(const T& val, const Coords2DInt& coords);
    virtual int GetTypeN()const;
};

template <class T> class Array2D_RareElemenrtsList{
    virtual ~Array2D_RareElemenrtsList()=0;
    virtual void SetSize(const Array2DSize& sizeNew);
    virtual T GetElement(int ExtRowN, int IneRowN);
    virtual T GetElement(const Coords2DInt& coords);
    virtual void SetElement(const T& val, int ExtRowN, int IneRowN);
    virtual void SetElement(const T& val, const Coords2DInt& coords);
    virtual int GetTypeN()const;
};

//---------------------------------------------------------


template <class T> class Array2D_Shell_1{
  public:
    Array2D_Prototype<T>*data;
    Array2DSize size;
    //
    Array2D_Shell_1();
    Array2D_Shell_1(T**data, Array2DSize_Prototype*size, int typeN=0);
    Array2D_Shell_1(T*data, Array2DSize_Prototype*size, int typeN=0);
    Array2D_Shell_1(const T& data, Array2DSize_Prototype*size, int typeN=0);
    Array2D_Shell_1(T**data, std::vector<int>Ls, int typeN=0);
    Array2D_Shell_1(T*data, std::vector<int>Ls, int typeN=0);
    Array2D_Shell_1(const T& data, std::vector<int>Ls, int typeN=0);
    Array2D_Shell_1(T**data, int QExtRows, int*rowsLs, int typeN=0);
    Array2D_Shell_1(T*data, int QExtRows, int*rowsLs, int typeN=0);
    Array2D_Shell_1(T**data, int QExtRows, int rowL, int typeN=0);
    Array2D_Shell_1(T*data, int QExtRows, int rowL, int typeN=0);
    Array2D_Shell_1(const T& data, int QExtRows, int rowL, int typeN=0);
    Array2D_Shell_1(std::vector<std::vector<T>>data, int ifNotRectButNeededRect_ByMin1ByMax2, int typeN=0);
    Array2D_Shell_1(std::vector<T>data, Array2DSize_Prototype*size, int typeN=0);
    Array2D_Shell_1(std::vector<T>data, std::vector<int>Ls, int typeN=0);
    Array2D_Shell_1(std::vector<T>data, int QExtRows, int*rowsLs, int typeN=0);
    Array2D_Shell_1(std::vector<T>data, int QExtRows, int rowL, int typeN=0);
    //
    Array2D_Shell_1(const Array2D_Shell_1& obj);
    //
    ~Array2D_Shell_1();
    //
    void construct(int typeN=0);
    //
    void SetNullIni();
    void SetNull();
    void SetOne(const T&val);
    void SetOne(T*val=NULL);
    //
    void Assign(const Array2D_Shell_1& obj);
    //
    void SetSize(const Array2DSize& sizeNew);
    void SetSize(Array2DSize_Prototype*sizeNew);
    void SetSize(std::vector<int>Ls);
    void SetSize(int*Ls, int QExtRows=1);
    void SetSize(int QExtRows=1, int extRowL=1);
    T GetElement(int ExtRowN, int IneRowN);
    T GetElement(const Coords2DInt& coords);
    void SetElement(const T& val, int ExtRowN, int IneRowN);
    void SetElement(const T& val, const Coords2DInt& coords);
    int GetTypeN()const;
    //
    void SetTypeN(int typeN);
    //
    //void Set(const std::vector<std::vector<T>>data, const T& defaultVal, TParamsOfDataShift*dataShift=NULL, bool transposed=false, int ifNotRect_DoForNonRect0_ByMin1_ByMax2ByLast3ByExisting4=0);
    ////
    //void Set(const std::vector<T>data, std::vector<int>Ls, const T& defaultVal, TParamsOfDataShift*dataShift=NULL, bool transposed=false, int ifNotRect_DoForNonRect0_ByMin1_ByMax2ByLast3ByExisting4=0);
    //void Set(const std::vector<T>data, int*Ls, int QExtRows, const T& defaultVal, TParamsOfDataShift*dataShift=NULL, bool transposed=false, int ifNotRect_DoForNonRect0_ByMin1_ByMax2ByLast3ByExisting4=0);
    //void Set(const std::vector<T>data, int QExtRows, int extRowL, const T& defaultVal, TParamsOfDataShift*dataShift=NULL, bool transposed=false);
    ////
    //void Set(const T*data, std::vector<int>Ls, const T& defaultVal, TParamsOfDataShift*dataShift=NULL, bool transposed=false, int ifNotRect_DoForNonRect0_ByMin1_ByMax2ByLast3ByExisting4=0, int QElementsGiven=-1);//prototype ne match, ne marked
    //void Set(const T*data, int*Ls, int QExtRows=1, const T& defaultVal, TParamsOfDataShift*dataShift=NULL, bool transposed=false, int ifNotRect_DoForNonRect0_ByMin1_ByMax2ByLast3ByExisting4=0, int QElementsGiven=-1);//prototype ne match, ne marked
    //void Set(const T*data, int QExtRows=1, int extRowL=1, const T& defaultVal, TParamsOfDataShift*dataShift=NULL, bool transposed=false, int QElementsGiven=-1);//prototype ne match, ne marked
    ////
    //void Set(const T**data, std::vector<int>Ls, const T& defaultVal, TParamsOfDataShift*dataShift=NULL, bool transposed=false, int ifNotRect_DoForNonRect0_ByMin1_ByMax2ByLast3ByExisting4=0);//for real: prototype ne match
    //void Set(const T**data, int*Ls, int QExtRows, const T& defaultVal, TParamsOfDataShift*dataShift=NULL, bool transposed=false, int ifNotRect_DoForNonRect0_ByMin1_ByMax2ByLast3ByExisting4=0);//prototype ne match, ne marked
    //void Set(const T**data, int QExtRows, int extRowL, const T& defaultVal, TParamsOfDataShift*dataShift=NULL, bool transposed=false);//prototype ne match, marked several times
    ////
    //void Set(const T&data, std::vector<int>Ls, const T& defaultVal, TParamsOfDataShift*dataShift=NULL, bool transposed=false, int ifNotRect_DoForNonRect0_ByMin1_ByMax2ByLast3ByExisting4=0);
    //void Set(const T&data, int*Ls, int QExtRows, const T& defaultVal, TParamsOfDataShift*dataShift=NULL, bool transposed=false, int ifNotRect_DoForNonRect0_ByMin1_ByMax2ByLast3ByExisting4=0);
    //void Set(const T&data, int QExtRows, int extRowL, const T& defaultVal, TParamsOfDataShift*dataShift=NULL, bool transposed=false);
    ////
    ////
    //void Set(const std::vector<std::vector<T>>data, TParamsOfDataShift*dataShift=NULL, bool transposed=false, T*dfltVal=NULL, int ifNotRect_DoForNonRect0_ByMin1_ByMax2ByLast3ByExisting4=0);
    ////
    //void Set(const std::vector<T>data, std::vector<int>Ls, TParamsOfDataShift*dataShift=NULL, bool transposed=false, T*dfltVal=NULL, int ifNotRect_DoForNonRect0_ByMin1_ByMax2ByLast3ByExisting4=0);
    //void Set(const std::vector<T>data, int*Ls, int QExtRows, TParamsOfDataShift*dataShift=NULL, bool transposed=false, T*dfltVal=NULL, int ifNotRect_DoForNonRect0_ByMin1_ByMax2ByLast3ByExisting4=0);
    //void Set(const std::vector<T>data, int QExtRows, int extRowL, TParamsOfDataShift*dataShift=NULL, bool transposed=false, T*dfltVal=NULL, bool transposed=false);
    ////
    //void Set(const T*data, std::vector<int>Ls, TParamsOfDataShift*dataShift=NULL, bool transposed=false, T*dfltVal=NULL, int ifNotRect_DoForNonRect0_ByMin1_ByMax2ByLast3ByExisting4=0, int QElementsGiven=-1);//prototype ne match, ne marked
    //void Set(const T*data, int*Ls, int QExtRows=1, TParamsOfDataShift*dataShift=NULL, bool transposed=false, T*dfltVal=NULL, int ifNotRect_DoForNonRect0_ByMin1_ByMax2ByLast3ByExisting4=0, int QElementsGiven=-1);//prototype ne match, ne marked
    //void Set(const T*data, int QExtRows=1, int extRowL=1, TParamsOfDataShift*dataShift=NULL, bool transposed=false, T*dfltVal=NULL, int QElementsGiven=-1);//prototype ne match, ne marked
    ////
    //void Set(const T**data, std::vector<int>Ls, TParamsOfDataShift*dataShift=NULL, bool transposed=false, T*dfltVal=NULL, int ifNotRect_DoForNonRect0_ByMin1_ByMax2ByLast3ByExisting4=0);//for real: prototype ne match
    //void Set(const T**data, int*Ls, int QExtRows, TParamsOfDataShift*dataShift=NULL, bool transposed=false, T*dfltVal=NULL, int ifNotRect_DoForNonRect0_ByMin1_ByMax2ByLast3ByExisting4=0);//prototype ne match, ne marked
    //void Set(const T**data, int QExtRows, int extRowL, TParamsOfDataShift*dataShift=NULL, bool transposed=false, T*dfltVal=NULL);//prototype ne match, marked several times
    ////
    //void Set(const T&data, std::vector<int>Ls, TParamsOfDataShift*dataShift=NULL, bool transposed=false, T*dfltVal=NULL,  int ifNotRect_DoForNonRect0_ByMin1_ByMax2ByLast3ByExisting4=0);
    //void Set(const T&data, int*Ls, int QExtRows, TParamsOfDataShift*dataShift=NULL, bool transposed=false, T*dfltVal=NULL, int ifNotRect_DoForNonRect0_ByMin1_ByMax2ByLast3ByExisting4=0);
    //void Set(const T&data, int QExtRows, int extRowL, TParamsOfDataShift*dataShift=NULL, bool transposed=false, T*dfltVal=NULL);
    //
    //
    //
    void set_simpleAsDataGiven(const std::vector<std::vector<T>>data, int ifNotRect_DoForNonRect0_ByMin1=0);
    //
    void set_simpleAsDataGiven(const std::vector<T>data, std::vector<int>Ls, int ifNotRect_DoForNonRect0_ByMin1=0);
    void set_simpleAsDataGiven(const std::vector<T>data, int*Ls, int QExtRows, int ifNotRect_DoForNonRect0_ByMin1=0);
    void set_simpleAsDataGiven(const std::vector<T>data, int QExtRows, int extRowL);
    //
    void set_simpleAsDataGiven(const T*data, std::vector<int>Ls, int ifNotRect_DoForNonRect0_ByMin1=0, int QElementsGiven=-1);//prototype ne match, ne marked
    void set_simpleAsDataGiven(const T*data, int*Ls, int QExtRows=1, int ifNotRect_DoForNonRect0_ByMin1=0, int QElementsGiven=-1);//prototype ne match, ne marked
    void set_simpleAsDataGiven(const T*data, int QExtRows=1, int extRowL=1, int QElementsGiven=-1);//prototype ne match, ne marked
    //
    void set_simpleAsDataGiven(const T**data, std::vector<int>Ls, int ifNotRect_DoForNonRect0_ByMin1=0);//for real: prototype ne match
    void set_simpleAsDataGiven(const T**data, int*Ls, int QExtRows, int ifNotRect_DoForNonRect0_ByMin1=0);//prototype ne match, ne marked
    void set_simpleAsDataGiven(const T**data, int QExtRows, int extRowL);//prototype ne match, marked several times
    //
    //void set_simpleAsDataGiven(const T&data, std::vector<int>Ls, int ifNotRect_DoForNonRect0_ByMin1=0);
    //void set_simpleAsDataGiven(const T&data, int*Ls, int QExtRows, int ifNotRect_DoForNonRect0_ByMin1=0);
    //void set_simpleAsDataGiven(const T&data, int QExtRows, int extRowL);
    //
    std::vector<std::vector<T>>GetData();
    std::vector<T>GetDataAsVector();
    //
    //
    //void SetExtRow(T*row, int rowL, int extRowNN=-1, const T&defaultVal, int ifNotRect_NonRect0_RectBy_New1Old2Min3Max4=0, bool reversed=false, TParamsOfDataShift*dataShift=NULL);
    //void SetExtRow(T*row, int rowL=0, int extRowNN=-1, int ifNotRect_NonRect0_RectBy_New1Old2Min3Max4=0, bool reversed=false, TParamsOfDataShift*dataShift=NULL, T*dfltVal=NULL);
    void setExtRow_simpleAsDataGiven(T*row, int rowL=0, int extRowNN=-1, int ifNotRect_NonRect0_RectBy_New1Old2Min3Max4=0);
    //
    void setIneRow_simpleAsDataGiven(T*row, int rowL=0, int extRowNN=-1, int ifNotRect_NonRect0_RectBy_New1Old2Min3Max4=0);
    //
    //
    void addExtRow_simpleAsDataGiven(T*row, int rowL=0,                  int ifNotRect_NonRect0_RectBy_New1Old2Min3Max4=0);
    void insExtRow_simpleAsDataGiven(T*row, int rowL=0, int extRowNN=-1, int ifNotRect_NonRect0_RectBy_New1Old2Min3Max4=0);
    void delExtRow_simpleAsDataGiven(                   int extRowNN=-1);
    void addIneRow_simpleAsDataGiven(T*row, int rowL=0,                  int ifNotRect_NonRect0_RectBy_New1Old2Min3Max4=0);
    void insIneRow_simpleAsDataGiven(T*row, int rowL=0, int extRowNN=-1, int ifNotRect_NonRect0_RectBy_New1Old2Min3Max4=0);
    void delIneRow_simpleAsDataGiven(                   int extRowNN=-1);
    //
};

template<typename T> Array2D_Shell_1<T>::Array2D_Shell_1(){
    int typeN=ARR2D_TYPE_DEFAULT;//ARR2D_TYPE_DEFAULT was not declared in this scope
}

template<typename T> void Array2D_Shell_1<T>::SetSize(int*Ls, int QExtRows){
    this->data->SetSize(Ls, QExtRows);
    this->size.Set();
}

template<typename T> void Array2D_Shell_1<T>::setExtRow_simpleAsDataGiven(T*row, int rowL, int extRowNN, int ifNotRect_NonRect0_RectBy_New1Old2Min3Max4){
    int QExtRows=this->GetQExtRows(), oldRowL, newL, minL=this->GetRowLengthMin(), maxL=this->GetRowLengthMax();
    std::vector<int>Ls;
    T val;
    if(extRowNN<0){
        extRowNN+=(QExtRows+1);
    }
    if(extRowNN>=0 && extRowNN<=QExtRows){//ja, hin 0, n'1
        oldRowL=this->GetExtRowLength(extRowNN);
        if(rowL==0){
            rowL=oldRowL;
        }
        if(rowL==oldRowL){
            //NOp: no resizing
        }else{
            Ls=this->GetSizeAsStdVector();
            if(minL!=maxL || ifNotRect_NonRect0_RectBy_New1Old2Min3Max4==0){
                Ls[extRowNN-1]=rowL;
                this->SetSize(Ls);
            }else{
                switch(ifNotRect_NonRect0_RectBy_New1Old2Min3Max4){
                    case 1:
                        newL=rowL;
                    break;
                    case 2:
                        newL=oldRowL;
                    break;
                    case 3:
                        if(rowL<oldRowL){
                            newL=rowL;
                        }
                    break;
                    case 4:
                        if(rowL>oldRowL){
                            newL=rowL;
                        }
                    break;
                }
                if(newL!=oldRowL){
                    this->SetSize(QExtRows, newL);
                }
            }
        }
        if(row!=NULL && rowL!=0){
            if(extRowNN>0){
                for(int IRNN=1;  IRNN<=rowL; IRNN++){
                    val=row[IRNN-1];
                    this->SetElement(val, extRowNN, IRNN);
                }
            }else if(extRowNN==0){
                for(int IRNN=1;  IRNN<=rowL; IRNN++){
                    val=row[IRNN-1];
                    for(int ERNN=1; ERNN<=QExtRows;  ERNN++){
                        this->SetElement(val, ERNN, IRNN);
                    }
                }
            }
        }
    }//else extRowNN n'fit
}//fn setExtRow_simple

template<typename T> void Array2D_Shell_1<T>::addExtRow_simpleAsDataGiven(T*row, int rowL,                  int ifNotRect_NonRect0_RectBy_New1Old2Min3Max4){

}

//void insExtRow_simpleAsDataGiven(T*row, int rowL=0, int extRowNN=-1, int ifNotRect_NonRect0_RectBy_New1Old2Min3Max4=0);
//void delExtRow_simpleAsDataGiven(                   int extRowNN=-1);
//void addIneRow_simpleAsDataGiven(T*row, int rowL=0,                  int ifNotRect_NonRect0_RectBy_New1Old2Min3Max4=0);
//void insIneRow_simpleAsDataGiven(T*row, int rowL=0, int extRowNN=-1, int ifNotRect_NonRect0_RectBy_New1Old2Min3Max4=0);
//void delIneRow_simpleAsDataGiven(                   int extRowNN=-1);



#endif // ARRAYLIB3_H
