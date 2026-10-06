#include "myarraylib.h"

//MyArrayLib::MyArrayLib()
//{
//
//}

// =======================================================================================================

//NumerSub Row - No Need, es
//template <typename T>std::vector<T> Array1DGetSubArray_byLs_PreMark_v1(T*x, int Lold, int Lreq=0, int whatFromN=1, int FirstDefaultValues=0){
//template <typename T>std::vector<T> Array1DGetSubArray_byLs_PreMark_v1(T*x, int Lold, int Lreq=0, int whatFromN=1, int FirstDefaultValues=0, T DefaultValue){
//template <typename T>std::vector<T> Array1DGetSubArray_byLs_PreMark_v1(T*x, int Lold, int Lreq=0, int whatFromN=1, int FirstDefaultValues=0, T*DefaultRow_LongEnough){
/*
std::vector<double>NumbersSubRow(std::vector<double> x, int LreqGiven, int FromN, int QDefaultBefore, double DefaultValParam){
    std::vector<double> R;
    //double*DefaultVal=new double;
    // *DefaultVal=DefaultValParam;
    //template <typename T>std::vector<T> Array1DGetSubArray_byLs_PreMark(T*x, int Lold, int Lreq=0, int whatFromN=1, int FirstDefaultValues=0, T*DfltValParam=NULL){
    //template <typename T>std::vector<T> Array1DGetSubArray_byLs_PreMark(std::vector<T>x, int Lreq=0, int whatFromN=1, int FirstDefaultValues=0, T*DfltValParam=NULL){
    //R= Array1DGetSubArray_byLs_PreMark(x, Lreq, FromN, QDefaultBefore, DefaultVal);
    //delete DefaultVal;
    //void Calc_Array1DSubArray_byLs_MarkupNs_vCycls(int&LreqCalcd, int&preN1_, int&preN2_, int&ownN1_, int&ownN2, int&ForOwnN1_, int&ForOwnN2, int&postN1, int&postN2_, int Lold, int LreqGiven, int whatFromN, int QDefaultValuesBefore){
    int LreqCalcd=0, preN1_=0, preN2_=0, ownN1_=0, ownN2=0, ForOwnN1_=0, ForOwnN2=0, postN1=0, postN2_=0, Lold=x.size();
    double CurVal;
    Calc_Array1DSubArray_byLs_MarkupNs_vFmls(LreqCalcd, preN1_, preN2_, ownN1_, ownN2, ForOwnN1_, ForOwnN2, postN1, postN2_, Lold, LreqGiven, FromN, QDefaultBefore);
    if(preN1_>0){
        for(int i=preN1_; i<=preN2_; i++){
            R.push_back(DefaultValParam);
        }
    }
    if(ownN1_>0){
        for(int i=ownN1_; i<=ownN2; i++){
            CurVal=x.at(i-1);
            R.push_back(CurVal);
        }
    }
    if(postN1>0){
        for(int i=postN1; i<=postN2_; i++){
            R.push_back(DefaultValParam);
        }
    }
    return R;
}

std::vector<double>NumbersSubRow(std::vector<double> x, int LreqGiven, int FromN, int QDefaultBefore, double*rowDflt){
    std::vector<double> R;
    int LreqCalcd=0, preN1_=0, preN2_=0, ownN1_=0, ownN2=0, ForOwnN1_=0, ForOwnN2=0, postN1=0, postN2_=0, Lold=x.size();
    double CurVal;
    Calc_Array1DSubArray_byLs_MarkupNs_vFmls(LreqCalcd, preN1_, preN2_, ownN1_, ownN2, ForOwnN1_, ForOwnN2, postN1, postN2_, Lold, LreqGiven, FromN, QDefaultBefore);
    if(preN1_>0){
        for(int i=preN1_; i<=preN2_; i++){
            CurVal=rowDflt[i-1];
            R.push_back(CurVal);
        }
    }
    if(ownN1_>0){
        for(int i=ownN1_; i<=ownN2; i++){
            CurVal=x.at(i-1);
            R.push_back(CurVal);
        }
    }
    if(postN1>0){
        for(int i=postN1; i<=postN2_; i++){
            CurVal=rowDflt[i-1];
            R.push_back(CurVal);
        }
    }
    return R;
}


std::vector<int>NumbersSubRow(std::vector<int> x, int LreqGiven, int FromN, int QDefaultBefore, int DefaultValParam){
    std::vector<int> R;
    int CurVal;
    int LreqCalcd=0, preN1_=0, preN2_=0, ownN1_=0, ownN2=0, ForOwnN1_=0, ForOwnN2=0, postN1=0, postN2_=0, Lold=x.size();
    //int, LreqGiven=0, whatFromN=0, QDefaultValuesBefore=0;
    //int*DefaultVal=new int;
    //int *DefaultVal=DefaultValParam;
    //template <typename T>std::vector<T> Array1DGetSubArray_byLs_PreMark(T*x, int Lold, int Lreq=0, int whatFromN=1, int FirstDefaultValues=0, T*DfltValParam=NULL){
    //template <typename T>std::vector<T> Array1DGetSubArray_byLs_PreMark(std::vector<T>x, int Lreq=0, int whatFromN=1, int FirstDefaultValues=0, T*DfltValParam=NULL){
    //R= Array1DGetSubArray_byLs_PreMark(x,  Lreq, FromN, QDefaultBefore, DefaultVal);
    //delete DefaultVal;
    //void Calc_Array1DSubArray_byLs_MarkupNs_vCycls(int&LreqCalcd, int&preN1_, int&preN2_, int&ownN1_, int&ownN2, int&ForOwnN1_, int&ForOwnN2, int&postN1, int&postN2_, int Lold, int LreqGiven, int whatFromN, int QDefaultValuesBefore){
    Calc_Array1DSubArray_byLs_MarkupNs_vFmls(LreqCalcd, preN1_, preN2_, ownN1_, ownN2, ForOwnN1_, ForOwnN2, postN1, postN2_, Lold, LreqGiven, FromN, QDefaultBefore);
    if(preN1_>0){
        for(int i=preN1_; i<=preN2_; i++){
            R.push_back(DefaultValParam);
        }
    }
    if(ownN1_>0){
        for(int i=ownN1_; i<=ownN2; i++){
            CurVal=x.at(i-1);
            R.push_back(CurVal);
        }
    }
    if(postN1>0){
        for(int i=postN1; i<=postN2_; i++){
            R.push_back(DefaultValParam);
        }
    }
    return R;
}



std::vector<int>NumbersSubRow(std::vector<int> x, int LreqGiven, int FromN, int QDefaultBefore, int*rowDflt){
    std::vector<int> R;
    int LreqCalcd=0, preN1_=0, preN2_=0, ownN1_=0, ownN2=0, ForOwnN1_=0, ForOwnN2=0, postN1=0, postN2_=0, Lold=x.size();
    int CurVal;
    Calc_Array1DSubArray_byLs_MarkupNs_vFmls(LreqCalcd, preN1_, preN2_, ownN1_, ownN2, ForOwnN1_, ForOwnN2, postN1, postN2_, Lold, LreqGiven, FromN, QDefaultBefore);
    if(preN1_>0){
        for(int i=preN1_; i<=preN2_; i++){
            CurVal=rowDflt[i-1];
            R.push_back(CurVal);
        }
    }
    if(ownN1_>0){
        for(int i=ownN1_; i<=ownN2; i++){
            CurVal=x.at(i-1);
            R.push_back(CurVal);
        }
    }
    if(postN1>0){
        for(int i=postN1; i<=postN2_; i++){
            CurVal=rowDflt[i-1];
            R.push_back(CurVal);
        }
    }
    return R;
}
*/



Array2DSize Array2DSize_ConcatAdding(const Array2DSize& size1, const Array2DSize& size2, int&ERN1, int&IRN1, int&ERN2, int&IRN2, int shift, int Q, int FromN, int QDfltValsBefore, bool SetRect){
    int Q1=size1.GetQExtRows(), Q2=size2.GetQExtRows(), Q3, lmax1=size1.GetMaxLength(), lmax2=size2.GetMaxLength(), lmax3;
    Array2DSize size3;
    int LreqCalcd=0, preN1_=0, preN2_=0, ownN1_=0, ownN2=0, ForOwnN1_=0, ForOwnN2=0, postN1=0, postN2_=0, Lold=Q2;
    if(Q==0){
        Q=Q2-FromN+1+QDfltValsBefore;
    }
    Q3=Q1+Q;
    if(FromN<0){
        FromN+=(Q2+1);
    }
    Calc_Array1DSubArray_byLs_MarkupNs_vFmls(LreqCalcd, preN1_, preN2_, ownN1_, ownN2, ForOwnN1_, ForOwnN2, postN1, postN2_, Lold, Q, FromN, QDfltValsBefore);
    if(shift>=0){
        //Q3 = Q1>shift+Q ? Q1 : shift+Q;
        //Calc_Array1DSubArray_byLs_MarkupNs_vFmls(LreqCalcd, preN1_, preN2_, ownN1_, ownN2, ForOwnN1_, ForOwnN2, postN1, postN2_, Lold, LreqGiven, FromN, QDefaultBefore);
        //Calc_Array1DSubArray_byLs_MarkupNs_vFmls(LreqCalcd, preN1_, preN2_, ownN1_, ownN2, ForOwnN1_, ForOwnN2, postN1, postN2_, Lold, Q, FromN, QDefaultBefore);
        ERN1=1;
        IRN1=1;
        if(ForOwnN2>0){
            ERN2=Q1+ForOwnN1_;
            IRN2=shift+1;
        }else{
             ERN2=0;
             IRN2=0;
        }
        lmax3 = lmax1 >= shift + lmax2 ? lmax1 : shift + lmax2;
        size3.SetNull();
        if(SetRect){
            size3.Set(Q3, lmax3);
        }else{
            for(int i=1; i<=Q1; i++){
                size3.AddExt(size1.GetLength(i));
            }
            if(preN2_>0){
                for(int i=ownN1_; i<=ownN2; i++){
                    size3.AddExt(lmax3);
                }
            }
            if(ERN2>0){
               for(int i=ownN1_; i<=ownN2; i++){
                   size3.AddExt(shift+size2.GetLength(i));
                }
            }
            if(postN2_>0){
                for(int i=postN1; i<=postN2_; i++){
                    size3.AddExt(lmax3);
                }
            }
        }
    }else{
        //Q3 = -shift+Q1 > Q ? -shift+Q1 : Q;
        //Calc_Array1DSubArray_byLs_MarkupNs_vFmls(LreqCalcd, preN1_, preN2_, ownN1_, ownN2, ForOwnN1_, ForOwnN2, postN1, postN2_, Lold, Q, FromN, QDefaultBefore);
        ERN1=1;
        IRN1=-shift+1;
        if(ForOwnN2>0){
            ERN2=Q1+ForOwnN1_;
            IRN2=1;
        }else{
             ERN2=0;
             IRN2=0;
        }
        lmax3 = -shift + lmax1 >= lmax2 ? -shift + lmax1 : lmax2;
        size3.SetNull();
        if(SetRect){
            size3.Set(Q3, lmax3);
        }else{
            for(int i=1; i<=Q1; i++){
                size3.AddExt(-shift+size1.GetLength(i));
            }
            if(preN2_>0){
                for(int i=ownN1_; i<=ownN2; i++){
                    size3.AddExt(lmax3);
                }
            }
            if(ERN2>0){
               for(int i=ownN1_; i<=ownN2; i++){
                   size3.AddExt(size2.GetLength(i));
                }
            }
            if(postN2_>0){
                for(int i=postN1; i<=postN2_; i++){
                    size3.AddExt(lmax3);
                }
            }
        }
    }
    return size3;
}


Array2DSize Array2DSize_ConcatStretching(const Array2DSize& size1, const Array2DSize& size2, int&ERN1, int&EIN1, int&ERN2, int&EIN2, int shift, int Q, int FromN, int QDfltValsBefore, bool Stretch1ToMax_Not_AddToLast, bool AppendToRect){
    int Q1=size1.GetQExtRows(), Q2=size2.GetQExtRows(), Q3, lmax1=size1.GetMaxLength(), lmax2=size2.GetMaxLength(), lmax3;
    Array2DSize size3;
    int LreqCalcd=0, preN1_=0, preN2_=0, ownN1_=0, ownN2=0, ForOwnN1_=0, ForOwnN2=0, postN1=0, postN2_=0, Lold=Q2;
    size3.SetNull();
    //if(Stretch1ToMax_Not_AddToLast){
    //
    //}else{
    //
    //}
    Calc_Array1DSubArray_byLs_MarkupNs_vFmls(LreqCalcd, preN1_, preN2_, ownN1_, ownN2, ForOwnN1_, ForOwnN2, postN1, postN2_, Lold, Q, FromN, QDfltValsBefore);
    if(shift>=0){
        Q3 = Q1>shift+Q ? Q1 : shift+Q;
        if(Stretch1ToMax_Not_AddToLast){
            if(AppendToRect){
                lmax3 = lmax1 + lmax2;
                size3.Set(Q3, lmax3);
            }else{
                if(shift>Q1){
                    for(int i=1; i<=Q1; i++){
                        size3.AddExt(size1.GetLength(i));
                    }
                    for(int i=Q1+1; i<=shift; i++){
                        size3.AddExt(lmax1 + lmax2);
                    }
                    if(Stretch1ToMax_Not_AddToLast){
                        if(preN2_>0){
                            for(int i=preN1_; i<=preN2_; i++){
                                size3.AddExt(lmax1 + lmax2);
                            }
                        }
                        if(ownN2>0){
                            for(int i=ownN1_; i<=ownN2; i++){
                                size3.AddExt(size2.GetLength(i));
                            }
                        }
                        if(postN2_>0){
                            for(int i=postN1; i<=postN2_; i++){
                                size3.AddExt(lmax1 + lmax2);
                            }
                        }
                    }else{
                        for(int i=1; i<=shift; i++){

                        }
                    }
                }else{

                }
            }
        }else{
            if(AppendToRect){

            }else{

            }
        }
    }else{
        Q3 = -shift+Q1 > Q ? -shift+Q1 : Q;
        if(Stretch1ToMax_Not_AddToLast){
            if(AppendToRect){

            }else{

            }
        }else{
            if(AppendToRect){

            }else{

            }
        }
    }
    return size3;
}





//===================================================================================================

int Array2DSizeBasedOn1D_PosByCoords(int ExtRowN, int IneRowN, int QExtRows, int*Ls){
    int PosN=0, curL;
    if(ExtRowN>=1 && ExtRowN<=QExtRows){
        if(Ls!=NULL){
            for(int i=1; i<=ExtRowN-1; i++){
                curL=Ls[i-1];
                PosN+=curL;
            }
            PosN+=IneRowN;
        }else{
            for(int i=1; i<=ExtRowN-1; i++){
                curL=0;
                PosN+=curL;
            }
            PosN+=IneRowN;
        }
    }
    return PosN;
}
int Array2DSizeBasedOn1D_PosByCoords(int ExtRowN, int IneRowN, std::vector<int>Ls){
    return Array2DSizeBasedOn1D_PosByCoords(ExtRowN, IneRowN, Ls.size(), Ls.data());
}
void Array2DSizeBasedOn1D_CoordsByPos(int PosN, int QExtRows, int*Ls, int&ExtRowN, int&IneRowN){
    int Ncur=0, Lcur, QElements=0;
    ExtRowN=0;
    IneRowN=0;
    bool contin, reasonably;
    reasonably=(PosN>=1 && Ls!=NULL && PosN<=QElements);
    if(reasonably){
        for(int i=1; i<=QExtRows; i++){
            Lcur=Ls[i-1];
            QElements+=Lcur;
        }
    }
    contin=reasonably;
    while(contin){
        ExtRowN++;
        Lcur=Ls[ExtRowN-1];
        if(Ncur<PosN && Ncur+Lcur>=PosN){
            contin=false;
        }
    }
    if(reasonably){
        IneRowN=PosN-Ncur;
    }
}
void Array2DSizeBasedOn1D_CoordsByPos(int PosN, std::vector<int>Ls, int&ExtRowN, int&IneRowN){
    Array2DSizeBasedOn1D_CoordsByPos(PosN, Ls.size(), Ls.data(), ExtRowN, IneRowN);
}

int Array2DSizeBasedOn1D_ExtRowNByPos(int PosN, std::vector<int>Ls){
    int IneRowN=0, ExtRowN=0;
    Array2DSizeBasedOn1D_CoordsByPos(PosN, Ls, ExtRowN, IneRowN);
    return ExtRowN;
}
int Array2DSizeBasedOn1D_IneRowNByPos(int PosN, std::vector<int>Ls){
    int IneRowN=0, ExtRowN=0;
    Array2DSizeBasedOn1D_CoordsByPos(PosN, Ls, ExtRowN, IneRowN);
    return ExtRowN;
}
int Array2DSizeBasedOn1D_ExtRowNByPos(int PosN, int QExtRows, int*Ls){
    int IneRowN=0, ExtRowN=0;
    Array2DSizeBasedOn1D_CoordsByPos(PosN, QExtRows, Ls, ExtRowN, IneRowN);
    return ExtRowN;
}
int Array2DSizeBasedOn1D_IneRowNByPos(int PosN, int QExtRows, int*Ls){
    int IneRowN=0, ExtRowN=0;
    Array2DSizeBasedOn1D_CoordsByPos(PosN, QExtRows, Ls, ExtRowN, IneRowN);
    return IneRowN;
}


//===================================================================================================

/*Int2DVectorOfSizeOrCoords::Int2DVectorOfSizeOrCoords(int d1, int d2){
    this->d1=d1; this->d2=d2;
}*/

//---------------------------------------------------------------------------------------------------

Array2DSize::Array2DSize(){
    this->Construct();
}
Array2DSize::Array2DSize(const Array2DSize&obj){
    this->Construct();
    this->Assign(obj);
}
Array2DSize::Array2DSize(int QExtRows, int  IneRowsLength, bool isNotVaria){
    this->Construct();
    this->QExtRows=QExtRows;
    if(isNotVaria){
        this->IneRowsLength=IneRowsLength;
        this->Ls=NULL;
    }else{
        this->Ls=new int[this->QExtRows];
        for(int i=1; i<=this->QExtRows; i++){
             this->Ls[i-1]=IneRowsLength;
        }
        this->IneRowsLength=0;
    }
}
Array2DSize::Array2DSize(int QExtRows, int*Ls){//, int isNotVariaAndSetByMin1Max2){
    this->Construct();
    this->QExtRows=QExtRows;
    this->IneRowsLength=0;
    this->Ls=new int[this->QExtRows];
    if(Ls!=NULL){
        for(int i=1; i<=this->QExtRows; i++){
            this->Ls[i-1]=Ls[i-1];
        }
    }
}
Array2DSize Array2DSize::operator =(const Array2DSize&obj){
    this->Assign(obj);
    return *this;
}
Array2DSize::~Array2DSize(){
    this->SetNull();
}
void Array2DSize::Assign(const Array2DSize&obj){
    this->SetNull();
    this->QExtRows=obj.QExtRows;
    if(obj.Ls!=NULL){
        this->IneRowsLength=0;
        if(this->Ls!=NULL) delete [] this->Ls;
        this->Ls=new int[obj.QExtRows];
        for(int i=1; i<=obj.QExtRows; i++){
            this->Ls[i-1]=obj.Ls[i-1];
        }
    }else{
        if(this->Ls!=NULL) delete [] this->Ls;
        this->Ls=NULL;
        this->IneRowsLength=obj.IneRowsLength;
    }
    this->QExtRows=obj.QExtRows;
}
void Array2DSize::Construct(){
    this->Ls=NULL;
    this->IneRowsLength=0;
    this->QExtRows=0;
}
void Array2DSize::SetNull(){
    if(this->Ls!=NULL){
        delete[]this->Ls;
    }
    this->Ls=NULL;
    this->IneRowsLength=0;
    this->QExtRows=0;
}
void Array2DSize::SetOne(bool isVaria){
    this->SetNull();
    this->QExtRows=1;
    if(isVaria==false){
        this->IneRowsLength=1;
    }else{
        this->Ls=new int(1);
        this->Ls[1-1]=1;
    }
}
bool Array2DSize::ExtRowNBelongsTo(int extRowN)const{return (extRowN>=1 && extRowN<=this->QExtRows);}
bool Array2DSize::PosBelongsTo(int extRowN, int ineRowN){
    return (this->ExtRowNBelongsTo(extRowN) && ineRowN>=1 && ineRowN<=this->GetLength(extRowN));
}

void Array2DSize::Set(int QExtRows, int IneRowsLength, bool preserveTypeIfVaria){
    if(this->Ls!=NULL){
        if(preserveTypeIfVaria){
            for(int i=1; i<=this->QExtRows; i++){
                this->Ls[i-1]=IneRowsLength;
            }
        }else{
            this->SetNull();
            this->IneRowsLength=IneRowsLength;
        }
    }else{
         this->IneRowsLength=IneRowsLength;
    }
    this->QExtRows=QExtRows;
}
void Array2DSize::Set(int QExtRows, int*Ls){
    if(Ls!=NULL){
        this->SetNull();
        this->Ls=new int[QExtRows];
        for(int i=1; i<=QExtRows; i++){
            this->Ls[i-1]=Ls[i-1];
        }
        this->QExtRows=QExtRows;
    }
}
void Array2DSize::Set1ExtRowVaria(int L){
    this->SetNull();
    this->QExtRows=1;
    this->Ls=new int[1];
    this->Ls[1-1]=L;
    this->IneRowsLength=0;
}
void Array2DSize::SetVaria(int QExtRows, int IneRowsLength){
    this->SetNull();
    this->QExtRows=QExtRows;
    this->IneRowsLength=0;
    this->Ls=new int[this->QExtRows];
    for(int i=1; i<=this->QExtRows; i++){
        this->Ls[i-1]=IneRowsLength;
    }
}
void Array2DSize::ConvertToRectIfAllLengthesAreEqual(){
    int mn=this->GetMinLength(), mx=this->GetMaxLength();
    if(mn=mx){
        delete[]this->Ls;
        this->Ls=NULL;
        this->IneRowsLength=mn;
    }
}

/*void Array2DSize::Add(int L, int ifConstAndNotEqual_Ignore0AddExisting1SetAll2){
    if(this->Ls!=NULL){
        Array1DAddElement(this->Ls, this->QExtRows, L);
    }else{
        if(ifConstAndNotEqual_Ignore0AddExisting1SetAll2==2){
            this->IneRowsLength=L;
        }
        if(ifConstAndNotEqual_Ignore0AddExisting1SetAll2==1 || ifConstAndNotEqual_Ignore0AddExisting1SetAll2==2){
            this->QExtRows+=1;
        }
    }
}
void Array2DSize::Ins(int N, int L){

}*/
void  Array2DSize::AddExt(int L){
    int LBefore=this->GetLength(this->GetQExtRows());
    if(L==0) L=LBefore;
    if(this->Ls!=NULL){
        Array1DAddElement(this->Ls, this->QExtRows, L);
    }else{
        if(L!=this->IneRowsLength){
            this->Ls=new int[this->QExtRows+1];
            for(int i=1; i<=this->QExtRows; i++){
                this->Ls[i-1]=this->IneRowsLength;
            }
            this->Ls[this->QExtRows+1-1]=L;
            this->IneRowsLength=0;
        }
        this->QExtRows+=1;
    }
}
void  Array2DSize::InsExt(int N, int L){
    int LBefore=this->GetLength(this->QExtRows);
    if(N==0) N=this->QExtRows;
    if(L==0) L=LBefore;
    if(this->Ls!=NULL){
        Array1DInsElementToN(this->Ls, this->QExtRows, N, L);
    }else{
        if(L!=this->IneRowsLength){
            this->Ls=new int[this->QExtRows+1];
            for(int i=1; i<=N-1; i++){
                this->Ls[i-1]=this->IneRowsLength;
            }
            this->Ls[N-1]=L;
            for(int i=N+1; i<=this->QExtRows; i++){
                this->Ls[i-1]=this->IneRowsLength;
            }
            this->Ls[this->QExtRows+1-1]=L;
            this->IneRowsLength=0;
        }
        this->QExtRows+=1;
    }
}

void Array2DSize::DelExt(int N){
    if(this->ExtRowNBelongsTo(N)){
        if(this->Ls!=NULL){
            Array1DDelElementFromN(this->Ls, this->QExtRows, N);
        }
        //this->QExtRows-=1;//no need: Del mut l'QE
        if(this->QExtRows==0)this->IneRowsLength=0;//better let it be
    }
}
//void  Array2DSize::DelIne(int N){
//    int minL=this->GetMinLength();
//    if(N<1) N=N+minL;
//    if(N>=1 && N<=minL){
//        if(this->Ls!=NULL){
//            for(int i=1; i<=this->QExtRows; i++){
//                this->Ls[i-1]-=1;
//            }
//        }else{
//            this->IneRowsLength-=1;
//        }
//    }
//}
void  Array2DSize::DelIneRow(){
    int minL=this->GetMinLength();
    if(this->Ls!=NULL){
        for(int i=1; i<=this->QExtRows; i++){
            this->Ls[i-1]-=1;
        }
    }else{
        this->IneRowsLength-=1;
    }
}
void  Array2DSize::AddOrInsIneRow(){
    if(this->Ls!=NULL){
        for(int i=1; i<=this->QExtRows; i++){
            this->Ls[i-1]+=1;
        }
    }else{
        this->IneRowsLength+=1;
    }
}
//void  Array2DSize::InsIne(int N){
//    int minL=this->GetMinLength();
//    if(N<1) N=N+minL;
//    if(N>=1 && N<=minL){
//        if(this->Ls!=NULL){
//            for(int i=1; i<=this->QExtRows; i++){
//                this->Ls[i-1]+=1;
//            }
//        }else{
//            this->IneRowsLength+=1;
//        }
//    }
//}
//void  Array2DSize::AddIne(){
//    int minL=this->GetMinLength();
//    if(N<1) N=N+minL;
//    if(N>=1 && N<=minL){
//        if(this->Ls!=NULL){
//            for(int i=1; i<=this->QExtRows; i++){
//                this->Ls[i-1]+=1;
//            }
//        }else{
//            this->IneRowsLength+=1;
//        }
//    }
//}

/*void Array2DSize::AddOrInsTo(int L, int N_0ToAllPreserveType_GTT0AndMakeVaria){
    int curL;
    if(this->ExtRowNBelongsTo(N_0ToAllPreserveType_GTT0AndMakeVaria)){
        if(N_0ToAllPreserveType_GTT0AndMakeVaria>0){
            curL=this->GetLength(N_0ToAllPreserveType_GTT0AndMakeVaria);
            this->SetLength((curL+L), N_0ToAllPreserveType_GTT0AndMakeVaria);
        }else{
            if(N_0ToAllPreserveType_GTT0AndMakeVaria==0){//ToAllPreserveType
                if(this->Ls!=NULL){
                    for(int i=1; i<=this->QExtRows; i++){
                        this->Ls[i-1]+=L;
                    }
                }else{
                    this->IneRowsLength+=L;
                }
            }
        }
    }
}
void Array2DSize::DelFrom(int L, int N_0ToAllPreserveType_GTT0AndMakeVaria){
    int curLwas, curLwillbe;
    bool b;
    if(this->ExtRowNBelongsTo(N_0ToAllPreserveType_GTT0AndMakeVaria)){
        curLwas=this->GetLength(N_0ToAllPreserveType_GTT0AndMakeVaria);
        curLwillbe=curLwas-L;
        if(curLwillbe>0){
            this->SetLength(curLwillbe, N_0ToAllPreserveType_GTT0AndMakeVaria);
        }
    }else{
        if(N_0ToAllPreserveType_GTT0AndMakeVaria==0){//ToAllPreserveType
            if(this->GetMinLength()-L>=0){
                if(this->Ls!=NULL){
                    for(int i=1; i<=this->QExtRows; i++){
                        this->Ls[i-1]-=L;
                    }
                }else{
                    this->IneRowsLength-=L;
                }
            }
        }
    }
}*/
void Array2DSize::AddOrInsTo(int N, int L){
    if(this->ExtRowNBelongsTo(N) && L>=0){
        if(this->Ls==NULL && L!=0){
            this->Ls=new int[this->QExtRows];
            for(int i=1; i<=this->QExtRows; i++){
                this->Ls[i-1]=this->IneRowsLength;
            }
            this->IneRowsLength=0;
        }
        this->Ls[N-1]+=L;
    }
}
void Array2DSize::DelFrom(int N, int L){
    if(this->ExtRowNBelongsTo(N) && L>=0){
        if(this->Ls==NULL && L!=0 && (this->GetLength(N-1)-L)>=0){
            this->Ls=new int[this->QExtRows];
            for(int i=1; i<=this->QExtRows; i++) this->Ls[i-1]=this->IneRowsLength;
            this->IneRowsLength=0;
        }
        this->Ls[N-1]+=L;
    }
}

int Array2DSize::GetQExtRows()const{ return this->QExtRows; }
bool Array2DSize::GetIfIsVariaLength()const{ return (this->Ls!=NULL); }
bool Array2DSize::isVariaLength(){ return (this->Ls!=NULL);}

int Array2DSize::GetLength(int N)const{
   int R=0;
   if(this->Ls!=NULL){
       if(N==0) N=this->QExtRows;
       if( this->ExtRowNBelongsTo(N)){
           R=this->Ls[N-1];
       }
   } else{
       R=this->IneRowsLength;
   }
   return R;
}
int Array2DSize::GetMinLength()const{
   int mn, mx;
    if(this->Ls!=NULL){
        mn=this->Ls[1-1];
        mx=this->Ls[1-1];
        for(int i=1; i<=this->QExtRows; i++){
            if(i==1 || (i>1 && this->Ls[i-1]<mn)) mn=this->Ls[i-1];
            if(i==1 || (i>1 && this->Ls[i-1]>mx)) mx=this->Ls[i-1];
        }
    }else{
        mn=this->IneRowsLength;
        mx=this->IneRowsLength;
    }
    return mn;
}

int Array2DSize::GetMaxLength()const{
    int mn, mx;
    if(this->Ls!=NULL){
        mn=this->Ls[1-1];
        mx=this->Ls[1-1];
        for(int i=1; i<=this->QExtRows; i++){
            if(i==1 || (i>1 && this->Ls[i-1]<mn)) mn=this->Ls[i-1];
            if(i==1 || (i>1 && this->Ls[i-1]>mx)) mx=this->Ls[i-1];
        }
    }else{
        mn=this->IneRowsLength;
        mx=this->IneRowsLength;
    }
    return mx;
 }

void Array2DSize::SwapExtRows(int N1, int N2){
    if(this->Ls!=NULL && this->ExtRowNBelongsTo(N1) && this->ExtRowNBelongsTo(N2)){
        Array1DSwapElements(this->Ls, this->QExtRows, N1, N2);
    }
}
void Array2DSize::Reverse(){
    if(this->Ls!=NULL)  Array1DReverse(this->Ls, this->QExtRows);
}
void Array2DSize::SetQExtRows(int N){
    int*R=NULL;
    int mn;
    if(N>=1){
        if(this->Ls!=NULL){
            mn=N>=this->QExtRows?N:this->QExtRows;
            R=new int[N];
            for(int i=1; i<=mn; i++){
                R[i-1]=this->Ls[i-1];
            }
            for(int i=mn+1; i<=N; i++){
                R[i-1]=1;
            }
            delete[]this->Ls;
            this->Ls=R;
        }
        this->QExtRows=N;
    }
}
void Array2DSize::SetIneRowsLength(int L_Minus1MinMinus2Max, bool setNotVaria){
    if(L_Minus1MinMinus2Max==-1) L_Minus1MinMinus2Max=this->GetMinLength();
    else if(L_Minus1MinMinus2Max==-2 )L_Minus1MinMinus2Max=this->GetMaxLength();
    if(L_Minus1MinMinus2Max>=1){
        if(this->Ls!=NULL && setNotVaria==false){
            for(int i=1; i<=this->QExtRows; i++){
                this->Ls[i-1]=L_Minus1MinMinus2Max;
            }
        }else{
            delete[]this->Ls;
            this->IneRowsLength=L_Minus1MinMinus2Max;
        }
    }
}
/*void Array2DSize::SetLength(int L, int N_0ToAllPreserveType_GTT0AndMakeVaria_Minus1ToAllMakeNotVaria){
    if(N_0ToAllPreserveType_GTT0AndMakeVaria_Minus1ToAllMakeNotVaria==-1){
        if(this->Ls==NULL){
            delete[]this->Ls;
            this->Ls=NULL;
            this->IneRowsLength=L;
        }
    }else if(N_0ToAllPreserveType_GTT0AndMakeVaria_Minus1ToAllMakeNotVaria==0){
        if(this->Ls==NULL){
            this->IneRowsLength=L;
        }else{
            for(int i=1; i<=this->QExtRows; i++){
                this->Ls[i-1]=L;
            }
        }
    }else if(N_0ToAllPreserveType_GTT0AndMakeVaria_Minus1ToAllMakeNotVaria>1 && this->ExtRowNBelongsTo(N_0ToAllPreserveType_GTT0AndMakeVaria_Minus1ToAllMakeNotVaria)){
        if(this->Ls==NULL){
            this->Ls=new int[this->QExtRows];
            for(int i=1; i<=this->QExtRows; i++){
                this->Ls[i-1]=this->IneRowsLength;
            }
            this->IneRowsLength=0;
        }
        this->Ls[N_0ToAllPreserveType_GTT0AndMakeVaria_Minus1ToAllMakeNotVaria-1]=L;
    }
}*/
void Array2DSize::SetLength(int L, int N){
    if(N<0){
        N=this->QExtRows+N;
    }
    if(this->Ls!=NULL){
        if(N==0){
            for(int i=1; i<=this->QExtRows; i++){
                this->Ls[i-1]=L;
            }
        }else if(this->ExtRowNBelongsTo(N)){
            this->Ls[N-1]=L;
        }
    }else{
        if(this->ExtRowNBelongsTo(N) && L!=this->IneRowsLength){
            this->Ls=new int[this->QExtRows];
            for(int i=1; i<=this->QExtRows; i++){
                this->Ls[i-1]=this->IneRowsLength;
            }
            this->Ls[N-1]=L;
            this->IneRowsLength=0;
        }else{
            this->IneRowsLength=L;
        }
    }
}

bool  Array2DSize::isSame(const Array2DSize&obj)const{
    bool verdict=true;
    //int Lmy;//
    //int Ltheir;//
    if(this->QExtRows!=obj.QExtRows) verdict=false;
    //if(this->GetQExtRows()!=obj.GetQExtRows()) verdict=false;
    //else if((this->Ls==NULL  && obj.Ls!=NULL)||(this->Ls==NULL  && obj.Ls!=NULL)){
    //     verdict=false;
    //}
    else if(this->Ls==NULL  && obj.Ls==NULL){
        if(this->IneRowsLength!=obj.IneRowsLength){
            verdict=false;
        }
    }else{
       for(int i=1; i<=this->QExtRows; i++){
           //Lmy=this->GetLength(i);
           //Ltheir=obj.GetLength(i);
           //Lmy=this->Ls[i-1];//no
           //Ltheir=obj.Ls[i-1];//no
           //if(Lmy!=Ltheir) verdict=false;
           if(this->GetLength(i)!=obj.GetLength(i)) verdict=false;
       }
    }
    return verdict;
}

QString  Array2DSize::GetAsQString(QString delim)const{
    QString c, s;
    c.setNum(this->QExtRows);
    s="Rows: ";
    s=s+c;
    s=s+" Lengthes: ";
    if(this->Ls!=NULL){
        s=s+"(";
        for(int i=1; i<=this->QExtRows-1; i++){
            c.setNum(this->GetLength(i));
            s=s+c;
            s=s+delim;
        }
        c.setNum(this->GetLength(this->QExtRows));
        s=s+c;
        s=s+")";
    }else{
        //c.setNum(this->GetLength(this->QExtRows));
        c.setNum(this->IneRowsLength);
        s=s+c;
    }
    return s;
}

std::string Array2DSize::GetAsStdString(std::string delim)const{
    std::string s2;
    QString delimer=QString(delim.c_str());
    QString s1;
    s1=this->GetAsQString(delimer);
    s2=s1.toStdString();
    return s2;
}

void Array2DSize::ShowToConsole()const{
    std::cout<<this->GetAsStdString()<<std::endl;
}

int Array2DSize::GetIneRowsLength(bool EvenIfVarButAllEqual)const{
    int Lmin=this->GetMinLength(), Lmax=this->GetMaxLength(), Lrect;
    if(this->Ls!=NULL && Lmin==Lmax && EvenIfVarButAllEqual){
        Lrect=Lmin;
    }else{
        Lrect=this->IneRowsLength;
    }
    return Lrect;
}
void Array2DSize::Transpose(){
    int iL=this->GetIneRowsLength(true), Lmax=this->GetMaxLength();
    int *Ls=NULL;
    if(this->IsForTranspose()){
        if(this->IneRowsLength>0){
            this->Set(this->IneRowsLength, this->QExtRows);
        }else{
            Ls=new int[Lmax];
            for(int i=1; i<=Lmax; i++){
                iL=this->LengthFullFormalOfIneRowN(i);
                Ls[i-1]=iL;
            }
            //if(this->Ls!=NULL){
            //    delete[]this->Ls;
            //}
            this->Set(Lmax, Ls);
            if(Ls!=NULL){
                delete[]Ls;
            }
        }
    }
}
bool Array2DSize::IsForTranspose() const{
    bool b=true;
    int L1=this->GetLength(1), L2 ;
    for(int i=2; i<=this->QExtRows; i++){
        L2=this->GetLength(i);
        if(L1<L2)b=false;
        L1=L2;
    }
    return b;
}
int Array2DSize::LengthFullFormalOfIneRowN(int N)const{//from start to 1st stop
    int L=0;
    if(N>=1 && N<=this->GetMaxLength()){
        for(int i=1; i<=this->QExtRows; i++){
            if(this->GetLength(i)>=N){
                L++;
            }
        }
    }
    return L;
}
int Array2DSize::LengthFactOfIneRowN_From1stToFirstStop(int N)const{//from start to 1st stop
    int LR=0, curL, Lmin=this->GetMinLength(), Lmax=this->GetMaxLength();
    bool isLongEnough=true;
    if(N>=1 && N<=Lmax){
        for(int i=1; i<=this->QExtRows; i++){
            curL=this->GetLength(i);
            if(curL>Lmin){
                isLongEnough=false;
                break;
            }else{
                LR++;
            }
        }
    }
    return LR;
}


int Array2DSize::GetPositionByCoordsIfRealizedAs1D(int ExtRowN, int IneRowN)const{
    int PosN=0;
    if(ExtRowN>=1 && ExtRowN<=this->GetQExtRows() && IneRowN>=1 && IneRowN<=this->GetLength(ExtRowN)){
        for(int i=1; i<=ExtRowN-1; i++){
            PosN+=this->GetLength(i);
        }
        PosN+=IneRowN;
    }
    return PosN;
}

void Array2DSize::GetCoordsByPositionIfRealizedAs1D(int PosN, int&ExtRowN, int&IneRowN)const{
    int QElementsInAll=0, QExtRows=this->GetQExtRows(), curN=0, curL;
    for(int i=1; i<=QExtRows; i++){
        QElementsInAll+=this->GetLength(i);
    }
    ExtRowN=0;
    IneRowN=0;
    bool contin=(PosN>=1 && PosN<=QElementsInAll);
    while(contin){
        ExtRowN++;
        curL=this->GetLength(ExtRowN);
        if(curN+curL<PosN){
            curN+=curL;
        }else{
            IneRowN=PosN-curN;
            contin=false;
        }
    }
}

int Array2DSize::GetExtRowNByPositionIfRealizedAs1D(int PosN)const{
    int ExtRowN=0, IneRowN=0;
    this->GetCoordsByPositionIfRealizedAs1D(PosN, ExtRowN, IneRowN);
    return ExtRowN;
}

int Array2DSize::Array2DSize::GetIneRowNByPositionIfRealizedAs1D(int PosN)const{
    int ExtRowN=0, IneRowN=0;
    this->GetCoordsByPositionIfRealizedAs1D(PosN, ExtRowN, IneRowN);
    return IneRowN;
}

std::vector<int>Array2DSize::GetLengthes()const{
    std::vector<int>Ls;
    if(this->Ls!=NULL){
        for(int i=1; i<=this->QExtRows; i++){
            Ls.push_back(this->Ls[i-1]);
        }
    }else{
        for(int i=1; i<=this->QExtRows; i++){
            Ls.push_back(this->IneRowsLength);//wa this-IneRowsLength ma n'wa err!
        }
    }
    return Ls;
}
int Array2DSize::GetQElements()const{
    int count=0, L;
    if(this->Ls!=NULL){
        for(int i=1; i<=this->QExtRows; i++){
            L=this->GetLength(i);
            count+=L;
        }
    }else{
        count=this->QExtRows*this->IneRowsLength;
    }
    return count;
}

bool Array2DSize::isRectangularInFact() const{
    int Lmin=this->GetMinLength(), Lmax=this->GetMaxLength();
    return (Lmin==Lmax);
}

bool Array2DSize::isRectangularEvenByStr() const{
   return (this->Ls==NULL);
}
//
//
//
Array2DSize Array2DSize::GetSubSuccessionOfExtRows(int FromN, int QReq, int QDfltBefore, int ifDefaultRowsPresent_LZero0_StretchToL1max1_StretchToLFinMax2) const{
    Array2DSize size2;
    std::vector<int>Ls1, Ls2;
    int Q1=this->GetQExtRows(), L1max=this->GetMaxLength(), L2max, curL2, Q2;
    Ls1=this->GetLengthes();
    int DfltVal=0;
    int LreqCalcd, preN1, preN2, ownN1, ownN2, ForOwnN1, ForOwnN2, postN1, postN2, Lini,
        LreqGiven=QReq;//,
        //whatFromN, QDefaultValuesAfter;
    //void Calc_Array1DSubArray_byLs_MarkupNs_vFml_FixedDfltsAfter(int&LreqCalcd, int&preN1, int&preN2, int&ownN1, int&ownN2, int&ForOwnN1, int&ForOwnN2, int&postN1, int&postN2, int Lini, int LreqGiven=0, int whatFromN=1, int QDefaultValuesAfter=0);
    //template <typename T>std::vector<T> Array1DGetSubArray_byLs_PreMark(T*x, int Lold, int Lreq=0, int whatFromN=1, int FirstDefaultValues=0, T*DfltValParam=NULL){
    Ls2=                                  Array1DGetSubArray_byLs_PreMark(          Ls1,     QReq,           FromN,              QDfltBefore,    &DfltVal);
    size2.Set(Ls2.size(), Ls2.data());
    Q2=size2.GetQExtRows();
    L2max=size2.GetMaxLength();

    if(size2.GetMinLength()==size2.GetMaxLength() && this->isRectangularEvenByStr()){
        size2.Set(Ls2.size(), L1max);
    }else{
        size2.Set(Ls2.size(), Ls2.data());
        switch(ifDefaultRowsPresent_LZero0_StretchToL1max1_StretchToLFinMax2){
            case 1:
                for(int i=1; i<=Q2; i++){
                    curL2=size2.GetLength(i);
                    if(curL2==0){
                        size2.SetLength(L1max, i);
                    }
                }
            break;
            case 2:
            for(int i=1; i<=Q2; i++){
                curL2=size2.GetLength(i);
                if(curL2==0){
                    size2.SetLength(L2max, i);
                }
            }

            break;
            //default: NOp;
        }
    }
    return size2;//size3;
}

Array2DSize Array2DSize::ReturnBy_SetLength(int ExtRowN, int proposedRowL, TDataShiftParams*DataShiftParam, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6)const{
    Array2DSize sizeNew, size1=(*(this));
    int QExtRows=this->GetQExtRows(), Lmin=this->GetMinLength(), Lmax=this->GetMaxLength(), newL, maxL, curL;
    TDataShiftParams DataShift;
    bool isRectEvenByStr=size1.isRectangularEvenByStr();
    if(DataShiftParam!=NULL){
        DataShift=(*(DataShiftParam));
    }
    if(ExtRowN<0){
        ExtRowN+=(QExtRows+1);
    }
    sizeNew.SetNull();
    if(ExtRowN>=1 && ExtRowN<=QExtRows){
        sizeNew=(*(this));//size;
        curL=size1.GetLength(ExtRowN);
        if(proposedRowL==0){
            proposedRowL=curL;
        }
        if(DataShift.QReq==0){
            DataShift.QReq=curL;
        }
        // 1. newL
        switch(SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6){
            case 0:
            case 1:
            case 2:
                //NOp
                newL= DataShift.QReq;//vrn if ==0 fa ov
            break;
            case 3:
                maxL = Lmax >= DataShift.QReq ? Lmax : DataShift.QReq;
                newL=maxL;
            break;
            case 4:
                newL=Lmax;
            break;
            case 5:
                newL=curL;
            break;
            case 6:
                newL=DataShift.QReq;
            break;
        }
        DataShift.QReq=newL;
        // 2. form size
        if(curL!=newL){
            switch(SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6){
                case 0:
                case 1:
                case 2:
                    //nablb rect
                    sizeNew.SetLength(newL, ExtRowN);
                break;
                case 3:
                case 4:
                case 5:
                case 6:
                    sizeNew.Set(QExtRows, newL);//newL s'def'd ov
                break;
            }
        }else{
            if(isRectEvenByStr && newL==curL && SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6==1){
                sizeNew.SetVaria(QExtRows, newL);
            }
        }
    }
}
Array2DSize Array2DSize::ReturnBy_AddExt(int proposedRowL, TDataShiftParams*DataShiftParam, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6)const{
    TDataShiftParams DataShift;
    Array2DSize sizeNew, sizePre, size1=(*this);
    int QExtRows=this->GetQExtRows(), Lmin=this->GetMinLength(), Lmax=this->GetMaxLength(), newL, maxL, curL, preL, lastL=this->GetLength(QExtRows);
    bool isRectEvenByStr=size1.isRectangularEvenByStr();
    if(proposedRowL==0 && isRectEvenByStr){
        proposedRowL=lastL;
    }//aso if isRectEvenByStr==f, 0 stay
    if(DataShiftParam!=NULL){
        DataShift=(*(DataShiftParam));
    }
     // 1.
    sizePre=(*this);//size;
    switch(SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6){
        case 0:
        case 2:
            if(isRectEvenByStr && DataShift.QReq==Lmax){
                sizePre.Set(QExtRows+1, Lmax);
                //ob farr ms'repas'trc size co rect str
            }else{
                sizePre.AddExt(Lmax);
            }
        break;
        case 1://always varia
        case 3://alum rect amda et farr=>n'ute care
        case 4:
        case 5:
        case 6:
            sizePre.AddExt(1);
        break;

    }
    // 2.
    //Array2DSize Array2DSize_GetNewSizeChangingExtRow(const Array2DSize& size1, int ExtRowN, int proposedRowL, TDataShiftParams*DataShiftParam, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6){
    sizeNew=Array2DSize_GetNewSizeChangingExtRow(sizePre, QExtRows+1, proposedRowL, DataShiftParam, SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6);
}
Array2DSize Array2DSize::ReturnBy_InsExt(int ExtRowN, int proposedRowL, TDataShiftParams*DataShiftParam, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6)const{
    Array2DSize sizeNew, sizePre, size1=(*this);
    int QExtRows=this->GetQExtRows(), Lmin=this->GetMinLength(), Lmax=this->GetMaxLength(), newL, maxL, curL, preL, lastL=this->GetLength(QExtRows);
    //bool isRectEvenByStr=size1.isRectangularEvenByStr();
    bool isRectEvenByStr=this->isRectangularEvenByStr();
    TDataShiftParams DataShift;
    if(DataShiftParam!=NULL){
        DataShift=(*(DataShiftParam));
    }
    if(ExtRowN<0){
        ExtRowN+=(QExtRows+1);
    }
    if(ExtRowN>=1 && ExtRowN<=QExtRows){
        if(proposedRowL==0 && isRectEvenByStr){
            proposedRowL=lastL;
        }//aso if isRectEvenByStr==f, 0 stay
        // 1.
        sizePre=(*this);//size;
        switch(SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6){
            case 0:
            case 2:
                if(isRectEvenByStr && DataShift.QReq==Lmax){
                    sizePre.Set(QExtRows+1, Lmax);
                    //ob farr ms'repas'trc size co rect str
                }else{
                    sizePre.InsExt(ExtRowN, Lmax);
                }
            break;
            case 1://always varia
            case 3://alum rect amda et farr=>n'ute care
            case 4:
            case 5:
            case 6:
                sizePre.InsExt(ExtRowN, 1);
            break;
        }
    }//aso NOp
    // 2.
    //Array2DSize Array2DSize_GetNewSizeChangingExtRow(const Array2DSize& size1, int ExtRowN, int proposedRowL, TDataShiftParams*DataShiftParam, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6){
    sizeNew=Array2DSize_GetNewSizeChangingExtRow(sizePre, ExtRowN, proposedRowL, DataShiftParam, SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6);
}





//template<typename T> void ArrayOf2DBy1D_SetIneRowN(T*&X, Array2Dize& size, int IneRowN, const T& DefaultVal, T*rowParam=NULL, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, bool DefaulsAreSpecNotOwnVals=true, int if_LsNE_Ignore0_Resize_NewByOld_QERAndStretchIfShorter2_QEROrIRL_FromStartTillBreak3_All_NsBy2D4_NsByLongEnoughRows5_ByMaxQERAndStretchOrIRL6_OldByNew_FromStartAndStretchIfShorterAndTrimOrAddExt7=2, bool SetRectAnyway=true){
//Array2DSize Array2DSize::ReturnBy_SetIne_v1(                               int IneRowN,                                       int paramRowL,   TDataShiftParams*DataShiftParam,                                          int if_LsNE_Ignore0_Resize_NewByOld_QERAndStretchIfShorter2_QEROrIRL_FromStartTillBreak3_All_NsBy2D4_NsByLongEnoughRows5_ByMaxQERAndStretchOrIRL6_OldByNew_FromStartAndStretchIfShorterAndTrimOrAddExt7){
//Array2DSize ReturnBy_SetIne_v1(int IneRowN, int paramRowL=0, TDataShiftParams*DataShiftParam=NULL, int if_LsNE_Ignore0_Resize_NewByOld_QERAndStretchIfShorter2_QEROrIRL_FromStartTillBreak3_All_NsBy2D4_NsByLongEnoughRows5_ByMaxQERAndStretchOrIRL6_OldByNew_FromStartAndStretchIfShorterAndTrimOrAddExt7=2)const;
Array2DSize Array2DSize::ReturnBy_SetIne_v1(int IneRowN, int paramRowL, TDataShiftParams*DataShiftParam, int if_LsNE_Ignore0_Resize_NewByOld_QERAndStretchIfShorter2_QEROrIRL_FromStartTillBreak3_All_NsBy2D4_NsByLongEnoughRows5_ByMaxQERAndStretchOrIRL6_OldByNew_FromStartAndStretchIfShorterAndTrimOrAddExt7, bool SetRectAnyway)const{
    //if_LsNE_Ignore0_Resize_NewByOld_QERAndStretchIfShorter2_QEROrIRL_FromStartTillBreak3_All_NsBy2D4_NsBy1D5_ByMaxQERAndStretchOrIRL6_OldByNew_FromStartAndStretchIfShorterAndTrimOrAddExt7=2
    Array2DSize size=(*(this)), sizeNew=size;//size;
    int QER=size.GetQExtRows(), Lmax=size.GetMaxLength(), Lmin=size.GetMinLength(), curL, count=0,
        IRL_All=size.LengthFullFormalOfIneRowN(IneRowN), IRL_FromStartToBreak=size.LengthFactOfIneRowN_From1stToFirstStop(IneRowN),
            newL,
            Lreq1, Lreq2, QER2, Lmin2, Lmax2;

    //std::vector<T>rowFact, rowPre, rowWas;
    std::vector<int>NsLGE=size.GetNsOfExtRowsWhoseLengthIsGE(IneRowN);
    //T val;
    TDataShiftParams DataShift;
    bool NewQERRequired, QERAddRequired, QERTrimRequired, StretchRequired;
    int IRL_QER0_IRL_All_NsAs_AllExtRows1_LongEnoughExtRows2_FromStartToBreak3;
    //
    if(IneRowN<0){
        IneRowN+=(Lmax+1);
    }
    if(IneRowN>=1 && IneRowN<=Lmax){
        if(DataShiftParam!=NULL){
            DataShift=(*(DataShiftParam));
        }
        Lreq1=DataShift.GetQAll(paramRowL);//ce fun ms'be iqv'd!
        if(!(if_LsNE_Ignore0_Resize_NewByOld_QERAndStretchIfShorter2_QEROrIRL_FromStartTillBreak3_All_NsBy2D4_NsByLongEnoughRows5_ByMaxQERAndStretchOrIRL6_OldByNew_FromStartAndStretchIfShorterAndTrimOrAddExt7==0 && Lreq1!=QER)){
            if(IneRowN<=Lmin && QER==Lreq1){
               //sizeNew remains == size
            }else{//Lmin
                //
                switch(if_LsNE_Ignore0_Resize_NewByOld_QERAndStretchIfShorter2_QEROrIRL_FromStartTillBreak3_All_NsBy2D4_NsByLongEnoughRows5_ByMaxQERAndStretchOrIRL6_OldByNew_FromStartAndStretchIfShorterAndTrimOrAddExt7){
                    case 0://Ignore0
                       //NOp: tal ife
                    break;
                    case 1:
                        //NOp: to cas s'reserv'd uz add - add to last if L<N
                    break;
                    case 2://Resize_NewByOld_QERAndStretchIfShorter2
                        for(int i=1; i<=QER; i++){
                            curL=size.GetLength(i);
                            if(curL<IneRowN){
                                sizeNew.SetLength(IneRowN, i);
                            }
                        }
                    break;
                    case 3: //Resize_NewByOld__QEROrIRL_FromStartTillBreak3
                        if(IRL_FromStartToBreak>0){
                            //NOp
                        }else{//or better nop?
                            for(int i=1; i<=QER; i++){
                                curL=size.GetLength(i);
                                if(curL<IneRowN){
                                    sizeNew.SetLength(IneRowN, i);
                                }
                            }
                        }
                    break;
                    case 4://Resize_NewByOld__QEROrIRL__All_NsBy2D4 //non-rational vrn for own vals
                        if(IRL_All<QER){
                            //NOp;
                        }else{//or better nop?
                            Lreq2=QER;
                            if(Lmin<IneRowN){
                                for(int i=1; i<=QER; i++){
                                    curL=size.GetLength(i);
                                    if(curL<IneRowN){
                                        sizeNew.SetLength(IneRowN, i);
                                    }
                                }
                            }
                        }
                    break;
                    case 5://Resize_NewByOld__QEROrIRL__All__NsByLongEnoughRows5
                        if(IRL_All<QER){
                            //NOp
                        }else{//or better nop?
                            for(int i=1; i<=QER; i++){
                                curL=size.GetLength(i);
                                if(curL<IneRowN){
                                    sizeNew.SetLength(IneRowN, i);
                                }
                            }
                        }
                    break;
                    case 6://if_LsNE__ByMaxQERAndStretchOrIRL6_
                        Lreq2 = Lreq1 > QER ? Lreq1 : QER;
                        if(Lreq1 > QER){
                            for(int i=QER+1; i<=Lreq1; i++){
                                sizeNew.AddExt(IneRowN);
                            }
                            QER2=sizeNew.GetQExtRows();
                        }
                        if(Lmin<IneRowN){
                            //StretchRequired=true;
                            for(int i=1; i<=QER2; i++){
                                curL=sizeNew.GetLength(i);
                                if(curL<IneRowN){
                                    sizeNew.SetLength(IneRowN, i);
                                }
                            }
                        }
                    break;
                    case 7://if_LsNE__OldByNew_FromStartAndStretchIfShorterAndTrimOrAddExt7
                        Lreq2=Lreq1;
                        if(QER<Lreq1){
                            for(int i=QER; i>=Lreq1; i--){
                                sizeNew.DelExt(i);
                            }
                        }else if(Lreq1 > QER){
                            for(int i=QER+1; i<=Lreq1; i++){
                                sizeNew.AddExt(IneRowN);
                            }

                        }
                        QER2=sizeNew.GetQExtRows();
                        if(Lmin<IneRowN){
                            //StretchRequired=true;
                            for(int i=1; i<=QER2; i++){
                                curL=sizeNew.GetLength(i);
                                if(curL<IneRowN){
                                    sizeNew.SetLength(IneRowN, i);
                                }
                            }
                        }
                    break;
                }//switch
            }//Lmin or not
            if(SetRectAnyway){
                size.Set(sizeNew.GetQExtRows(), sizeNew.GetMaxLength());
            }else{
                size=sizeNew;
            }
        }//if not ignore if Ls ne fit
    }//if possible - Lmax
    return sizeNew;
}//fn set ine (was v1 et mav'd)

//nabls altf l'ins m'set ob set s'om data, et amda s'size
//Array2DSize            ReturnBy_InsIne_v1(int IneRowN, int paramRowL=0, TDataShiftParams*DataShiftParam=NULL, int if_LsNE_Ignore0_Resize_NewByOld_QERAndStretchIfShorter2_QEROrIRL_FromStartTillBreak3_All_NsBy2D4_NsByLongEnoughRows5_ByMaxQERAndStretchOrIRL6_OldByNew_FromStartAndStretchIfShorterAndTrimOrAddExt7=2, bool SetRectAnyway=true)const;
Array2DSize Array2DSize::ReturnBy_InsIne_v1(int IneRowN, int paramRowL,   TDataShiftParams*DataShiftParam,      int if_LsNE_Ignore0_Resize_NewByOld_QERAndStretchIfShorter2_QEROrIRL_FromStartTillBreak3_All_NsBy2D4_NsByLongEnoughRows5_ByMaxQERAndStretchOrIRL6_OldByNew_FromStartAndStretchIfShorterAndTrimOrAddExt7,   bool SetRectAnyway)const{
    Array2DSize size=*this, sizeNew=size;
    int QER=size.GetQExtRows(), Lmax=size.GetMaxLength(), Lmin=size.GetMinLength(),
        curL, count=0,
       IRL_All=size.LengthFullFormalOfIneRowN(IneRowN), IRL_FromStartToBreak=size.LengthFactOfIneRowN_From1stToFirstStop(IneRowN),
           newL,
           Lreq1, Lreq2, QER2, Lmin2, Lmax2;
    TDataShiftParams DataShift;
    //sizeNew=size.ReturnBy_SetIne_v1(IneRowN, paramRowL, DataShiftParam, if_LsNE_Ignore0_Resize_NewByOld_QERAndStretchIfShorter2_QEROrIRL_FromStartTillBreak3_All_NsBy2D4_NsByLongEnoughRows5_ByMaxQERAndStretchOrIRL6_OldByNew_FromStartAndStretchIfShorterAndTrimOrAddExt7);
    if(IneRowN<0){
        IneRowN+=(Lmax+1);
    }
    if(IneRowN>=1 && IneRowN<=Lmax){
        if(DataShiftParam!=NULL){
            DataShift=(*(DataShiftParam));
        }
        Lreq1=DataShift.GetQAll(paramRowL);//ce fun ms'be iqv'd!
        if(!(if_LsNE_Ignore0_Resize_NewByOld_QERAndStretchIfShorter2_QEROrIRL_FromStartTillBreak3_All_NsBy2D4_NsByLongEnoughRows5_ByMaxQERAndStretchOrIRL6_OldByNew_FromStartAndStretchIfShorterAndTrimOrAddExt7==0 && Lreq1!=QER)){
            if(IneRowN<=Lmin && QER==Lreq1){
               //sizeNew remains == size
            }else{//Lmin
                //
                switch(if_LsNE_Ignore0_Resize_NewByOld_QERAndStretchIfShorter2_QEROrIRL_FromStartTillBreak3_All_NsBy2D4_NsByLongEnoughRows5_ByMaxQERAndStretchOrIRL6_OldByNew_FromStartAndStretchIfShorterAndTrimOrAddExt7){
                    case 0://Ignore0
                       //NOp: tal ife
                    break;
                    case 1:
                        //NOp: to cas s'reserv'd uz add - add to last if L<N
                    break;
                    case 2://Resize_NewByOld_QERAndStretchIfShorter2
                        for(int i=1; i<=QER; i++){
                            curL=size.GetLength(i);
                            if(curL<IneRowN){
                                //sizeNew.SetLength(IneRowN, i);
                                sizeNew.SetLength(IneRowN+1, i);
                            }else{
                                sizeNew.SetLength(curL+1, i);
                            }
                        }
                    break;
                    case 3: //Resize_NewByOld__QEROrIRL_FromStartTillBreak3
                        if(IRL_FromStartToBreak>0){
                            for(int i=1; i<=IRL_FromStartToBreak; i++){
                                curL=size.GetLength(i);
                                sizeNew.SetLength(curL+1, i);
                            }//else NOp
                        }else{//or better nop?
                            for(int i=1; i<=QER; i++){
                                curL=size.GetLength(i);
                                if(curL<IneRowN){
                                    //sizeNew.SetLength(IneRowN, i);
                                    sizeNew.SetLength(IneRowN+1, i);
                                }else{
                                    sizeNew.SetLength(curL+1, i);
                                }
                            }
                        }
                    break;
                    case 4://Resize_NewByOld__QEROrIRL__All_NsBy2D4 //non-rational vrn for own vals
                    case 5://Resize_NewByOld__QEROrIRL__All__NsByLongEnoughRows5
                        if(IRL_All<QER){
                            for(int i=1; i<=QER; i++){
                                curL=size.GetLength(i);
                                if(curL>=IneRowN){
                                    //sizeNew.SetLength(IneRowN, i);
                                    sizeNew.SetLength(curL+1, i);
                                }//else nop
                            }
                        }else{//or better nop?
                            Lreq2=QER;
                            if(Lmin<IneRowN){
                                for(int i=1; i<=QER; i++){
                                    curL=size.GetLength(i);
                                    if(curL<IneRowN){
                                        //sizeNew.SetLength(IneRowN, i);
                                        sizeNew.SetLength(IneRowN+1, i);
                                    }else{
                                        sizeNew.SetLength(curL+1, i);
                                    }
                                }
                            }
                        }
                    break;
                    case 6://if_LsNE__ByMaxQERAndStretchOrIRL6_
                        Lreq2 = Lreq1 > QER ? Lreq1 : QER;
                        if(Lreq1 > QER){
                            for(int i=QER+1; i<=Lreq1; i++){
                                sizeNew.AddExt(IneRowN);
                            }
                            QER2=sizeNew.GetQExtRows();
                        }
                        if(Lmin<IneRowN){
                            //StretchRequired=true;
                            for(int i=1; i<=QER2; i++){
                                curL=sizeNew.GetLength(i);
                                if(curL<IneRowN){
                                    sizeNew.SetLength(IneRowN+1, i);
                                }else{
                                    sizeNew.SetLength(curL+1, i);
                                }
                            }
                        }
                    break;
                    case 7://if_LsNE__OldByNew_FromStartAndStretchIfShorterAndTrimOrAddExt7
                        Lreq2=Lreq1;
                        if(QER<Lreq1){
                            for(int i=QER; i>=Lreq1; i--){
                                sizeNew.DelExt(i);
                            }
                        }else if(Lreq1 > QER){
                            for(int i=QER+1; i<=Lreq1; i++){
                                sizeNew.AddExt(IneRowN);
                            }

                        }
                        QER2=sizeNew.GetQExtRows();
                        if(Lmin<IneRowN){
                            //StretchRequired=true;
                            for(int i=1; i<=QER2; i++){
                                curL=sizeNew.GetLength(i);
                                if(curL<IneRowN){
                                    sizeNew.SetLength(IneRowN, i);
                                }
                            }
                        }
                    break;
                }//switch
            }//Lmin or not
            if(SetRectAnyway){
                size.Set(sizeNew.GetQExtRows(), sizeNew.GetMaxLength());
            }else{
                size=sizeNew;
            }
        }//if not ignore if Ls ne fit
    }//if possible - Lmax
    return sizeNew;
}



Array2DSize Array2DSize::ReturnBy_AddIne(int ifNotRect_Ignore0_AddToLast1_StretchToMax2)const{
    Array2DSize sizeNew;
    int L, QExtRows=this->GetQExtRows(), Lmin=this->GetMinLength(), Lmax=this->GetMaxLength();
    sizeNew=(*(this));
    if(Lmin!=Lmax){
        switch(ifNotRect_Ignore0_AddToLast1_StretchToMax2){
            case 0:
                //NOp
            break;
            case 1:
                for(int i=1; i<=QExtRows; i++){
                    L=this->GetLength(i);
                    sizeNew.SetLength(L+1, i);
                }
            break;
            case 2:
                for(int i=1; i<=QExtRows; i++){
                    sizeNew.SetLength(Lmax+1, i);
                }
            break;
        }
    }else{
        if(this->isRectangularEvenByStr()){
            sizeNew.Set(QExtRows, Lmax+1);
        }else{
            for(int i=1; i<=QExtRows; i++){
                L=this->GetLength(i);
                sizeNew.SetLength(L+1, i);
            }
        }
    }
    return sizeNew;
}
//Array2DSize Array2DSize::ReturnBy_InsIne_v1(int IneRowN, int L1, TDataShiftParams*DataShiftParam, int if_LsNE_Ignore0_Resize_NewByOld_IRL1_QERAndStretchToN2_QERAndStretchToMax3_ByMax_QERorIRL4_QER5_OldByNew_FromStartAndStretchToN6_FromStartAndStretchToMax7)const{
//    int QER=this->GetQExtRows(), Lmin=this->GetMinLength(), Lmax=this->GetMaxLength(), IRL_ALL, IRL_FromStartTillBreak, Lreq1, curL;
//    TDataShiftParams DataShift;
//    Array2DSize sizeR=*this, sizeNew=size.ReturnBy_SetIne;
//    if(DataShiftParam!=NULL){
//        DataShift=(*(DataShiftParam));
//    }
//    if(IneRowN<0){
//        IneRowN+=(Lmax+1);
//    }
//    if(L1==0){
//        L1=QER;
//    }
//    IRL_ALL=this->LengthFullFormalOfIneRowN(IneRowN);
//    IRL_FromStartTillBreak=this->LengthFactOfIneRowN_From1stToFirstStop(IneRowN);
//    Lrec1=DataShift.GetQAll(L1);
//    if(Lrec1==QER && IneRowN>=Lmin){
//        //NOp;
//    }else{
//        switch(if_LsNE_Ignore0_Resize_NewByOld_IRL1_QERAndStretchToN2_QERAndStretchToMax3_ByMax_QERorIRL4_QER5_OldByNew_FromStartAndStretchToN6_FromStartAndStretchToMax7){
//            case 0:
//                //NOp;
//            break;
//            case 1:
//                //DataShift.QReq=IRL_ALL;
//                //NOp;
//            break;
//            case 2:
//                DataShift.QReq=IRL_ALL;
//                for(int i=1; i<=QER; i++){
//                    curL=this->GetLength(i);
//                    if(curL<=IneRowN){
//                        //sizeR.SetLength(IneRowN, i);
//                        sizeR.SetLength(IneRowN+1, i);
//                    }
//                }
//            break;
//            case 3:
//                DataShift.QReq=Lmax;
//                sizeR.Set(QER, Lmax);
//            break;
//            case 4:
//                if(IRL_FromStartTillBreak >= Lrec1){
//                    DataShift.QReq=IRL_FromStartTillBreak;
//                    //NOp;
//                }else if(IRL_AL >= Lreq1){
//                    DataShift.QReq=IRL_ALL;
//                    //NOp;
//                }else if(QER >= Lreq1){
//                    DataShift.QReq=QER;
//                    //NOp;
//                }else{
//                    DataShift.QReq=Lreq1;
//                }
//                if(DataShift.QReq==Lreq1){

//                }
//            break;
//            case 5:
//                DataShift.QReq = QER >= Lrec1 ? QER : Lrec1;
//            break;
//            case 6:

//            break;
//            case 7:

//            break;
//            //case 8:
//            //
//            //break;
//        }
//    }
//}

//Array2DSize Array2DSize::ReturnBy_InsIne(int IneRowN, int ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_AnyExt3_NurFromStartTillFirstStop4)const{
//    Array2DSize sizeNew;
//    int L, QExtRows=this->GetQExtRows(), Lmin=this->GetMinLength(), Lmax=this->GetMaxLength(),
//        IRLFrowSrartToErstStop, IRLAllFormal, count;
//    IRLFrowSrartToErstStop=this->LengthFactOfIneRowN_From1stToFirstStop(IneRowN);
//    IRLAllFormal=this->LengthFullFormalOfIneRowN(IneRowN);
//    sizeNew=(*(this));
//    if(Lmin==Lmax){
//        if(this->isRectangularEvenByStr()){
//            sizeNew.Set(QExtRows, Lmax+1);
//        }else{
//            //sizeNew=(*(this));
//            for(int i=1; i<=QExtRows; i++){
//                L=this->GetLength(i);
//                sizeNew.SetLength(L+1, i);
//            }
//        }
//    }else if(IneRowN<=Lmin){
//        for(int i=1; i<=QExtRows; i++){
//            L=this->GetLength(i);
//            sizeNew.SetLength(L+1, i);
//        }
//    }else{
//        switch(ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_AnyExt3_NurFromStartTillFirstStop4){
//            case 0:
//                //sizeNew=(*(this));
//                //sizeNew.SetNull();
//            break;
//            case 1:
//                for(int i=1; i<=QExtRows; i++){
//                    L=this->GetLength(i);
//                    sizeNew.SetLength(L+1, i);
//                }
//            break;
//            case 2:
//                for(int i=1; i<=QExtRows; i++){
//                    L=this->GetLength(i);
//                    if(L<=IneRowN){
//                        sizeNew.SetLength(IneRowN+1, i);
//                    }else{
//                        sizeNew.SetLength(L+1, i);
//                    }
//                }
//            break;
//            case 3:
//                for(int i=1; i<=QExtRows; i++){
//                    L=this->GetLength(i);
//                    if(L<=IneRowN){
//                        sizeNew.SetLength(IneRowN+1, i);
//                    }else{
//                        sizeNew.SetLength(L+1, i);
//                    }
//                }
//            break;
//            case 4:
//                count=0;
//                if(IRLFrowSrartToErstStop==0){
//                    //NOp
//                }else{
//                    for(int i=1; i<=QExtRows; i++){
//                        L=this->GetLength(i);
//                        if(IneRowN<=L){
//                            count++;
//                            if(count>=IRLFrowSrartToErstStop){
//                                break;
//                            }else{
//                                sizeNew.SetLength(L+1, i);
//                            }
//                        }else{
//                            //NOp;
//                        }
//                    }
//                }
//            break;
//        }
//    }
//    return sizeNew;
//}

Array2DSize Array2DSize::ReturnBy_DelIne(int IneRowN, int ifNGTLmin_Ignore0_DelLast1_NurProperL_AnyExtRow3_NurFromStartTillFirstBreak4)const{
    int QExtRows=this->GetQExtRows(), Lmin=this->GetMinLength(), Lmax=this->GetMaxLength(), curL;
    Array2DSize sizeOld=(*(this)), sizeNew=sizeOld;
    if(IneRowN<0){
        IneRowN+=(Lmax+1);
    }
    if(IneRowN>=1 && IneRowN<=Lmax){
        //sizeNew=sizeOld.ReturnBy_DelIne - no tic fn
        if(IneRowN<=Lmin) {
            //components
            if(sizeOld.isRectangularEvenByStr()){
                sizeNew.Set(QExtRows, Lmin-1);
            }else{
                for(int i=1; i<=QExtRows; i++){
                    curL=this->GetLength(i);
                    sizeNew.SetLength(curL-1, i);
                }
            }
        }else{
            switch(ifNGTLmin_Ignore0_DelLast1_NurProperL_AnyExtRow3_NurFromStartTillFirstBreak4){
                case 0:
                    //NOp
                break;
                case 1:
                    for(int i=1; i<=QExtRows; i++){
                        curL=this->GetLength(i);
                        if(curL>0){
                            sizeNew.SetLength(curL-1, i);//n'vikts, > Lmin or no
                        }
                    }
                break;
                case 2:
                    //NOp
                break;
                case 3:
                    for(int i=1; i<=QExtRows; i++){
                        curL=this->GetLength(i);
                        if(curL>=IneRowN){
                            sizeNew.SetLength(curL-1, i);//n'vikts, > Lmin or no
                        }//else NOp;
                    }
                break;
                case 4:
                    if(this->GetLength(1)>=IneRowN){
                        for(int i=1; i<=QExtRows; i++){
                            curL=this->GetLength(i);
                            if(curL>=IneRowN){
                                sizeNew.SetLength(curL-1, i);//n'vikts, > Lmin or no
                            }else{
                                break;//from erst
                            }
                        }
                    }
                break;
            }
        }
    }
    return sizeNew;
}
//Array2DSize Array2DSize::ReturnBy_SetIne(int IneRowN, int ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_AnyExt3_NurFromStartTillFirstStop4)const{
//    Array2DSize sizeNew=(*(this));
//    int QExtRows=this->GetQExtRows(), Lmax=this->GetMaxLength(), Lmin=this->GetMinLength(), curL;
//    if(IneRowN>Lmin && IneRowN<=Lmax){
//        switch(ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_AnyExt3_NurFromStartTillFirstStop4){
//            case 0:
//            case 3:
//            case 4:
//                //NOp;
//            break;
//            case 1:
//                for(int i=1; i<=QExtRows; i++){
//                    curL=this->GetLength(i);
//                    if(curL<IneRowN){
//                        sizeNew.SetLength(curL+1, i);
//                    }
//                }
//            break;
//            case 2:
//                for(int i=1; i<=QExtRows; i++){
//                    curL=this->GetLength(i);
//                    if(curL<IneRowN){
//                        sizeNew.SetLength(IneRowN+1, i);
//                    }
//                }
//            break;
//        }
//    }//else NOp
//    Lmin=sizeNew.GetMinLength();
//    Lmax=sizeNew.GetMaxLength();
//    if(this->isRectangularEvenByStr() && Lmin==Lmax){
//        sizeNew.Set(QExtRows, Lmax);
//    }//else varia lengthes remain after resizing
//    return sizeNew;
//}
std::vector<int>Array2DSize::GetNsOfExtRowsWhoseLengthIsGE(int L)const{
    std::vector<int> NsGE;//, NsLT;
    int QER=this->GetQExtRows(), curL;
    for(int N=1; N<=QER; N++){
        curL=this->GetLength(N);
        if(curL>=L){
            NsGE.push_back(N);
        }else{
            //NsLT.push_back(N);
        }
    }
    return NsGE;
}

std::vector<int>Array2DSize::GetNsOfExtRowsWhoseLengthIsLT(int L)const{
    //std::vector<int> NsGE, NsLT;
    std::vector<int>  NsLT;
    int QER=this->GetQExtRows(), curL;
    for(int N=1; N<=QER; N++){
        curL=this->GetLength(N);
        if(curL>=L){
            //NsGE.push_back(N);
        }else{
            NsLT.push_back(N);
        }
    }
    return NsLT;
}

/*
void GetSubArrayNs(int Q, int&QReqCalcd, int&preN1, int&preN2, int&ownN1, int&ownN2, int&ForOwnN1, int&ForOwnN2, int&postN1, int&postN2, int FromN, int QReqGiven, int QDefaultsBefore){
    int QPost=0, QOwnRe=0 ;//re means rest or really
    if(QReqGiven==0){
        QReqCalcd=QDefaultsBefore+Q-FromN+1;
    }else{//QReqGiven>0
        QReqCalcd=QReqGiven;
        if(QDefaultsBefore>=QReqGiven || FromN>Q){
            //pre only
            preN1=1;
            preN2=QReqGiven;
        }else{
            //smth else xpt pre
            preN1 = QDefaultsBefore>0 ? 1 : 0;
            preN2=QDefaultsBefore;
            ownN1=FromN;
            ForOwnN1=preN2+1;
            if(QDefaultsBefore+Q-FromN+1<QReqGiven){
                //post exist, QOwn - full except FromN
                QOwnRe=Q-FromN+1;
                QPost=QReqGiven-QDefaultsBefore-QOwnRe;
                postN1=ForOwnN2+1;
                postN2=QReqGiven;
            }else{//QDefaultsBefore+Q-FromN+1>=QReqGiven
                //no post, own is all ic ns'pre, not full or full
                QOwnRe=QReqGiven-QDefaultsBefore;
                //ForOwnN2=QReqGiven;
            }
            ownN2=FromN-1+QOwnRe;
            ForOwnN2=ForOwnN1+QOwnRe-1;
        }
    }//cases
}//fn
*/

std::vector<double>GetSubArray(double*X, int Q, int FromN, int QReqGiven, int QDefaultsBefore, double DefaultVal){
    std::vector<double>Y;
    double val;
    int preN1=0, preN2=0, ownN1=0, ownN2=0, ForOwnN1=0, ForOwnN2=0, postN1=0, postN2=0;
    int QReqCalcd;
    //void GetSubArrayNs(int Q, int&QReqCalcd, int&preN1, int&preN2, int&ownN1, int&ownN2, int&ForOwnN1, int&ForOwnN2, int&postN1, int&postN2, int FromN=1, int QReqGiven=0, int QDefaultsBefore=0){
          GetSubArrayNs(     Q,     QReqCalcd,     preN1,     preN2,     ownN1,     ownN2,     ForOwnN1,     ForOwnN2,     postN1,     postN2,     FromN,       QReqGiven,       QDefaultsBefore);
    if(preN2>0){
       for(int i=preN1; i<=preN2; i++){
           Y.push_back(DefaultVal);
       }
    }
    if(ownN2>0){
        for(int i=preN1; i<=preN2; i++){
            val=X[i-1];
            Y.push_back(val);
        }
    }
    if(postN2>0){
       for(int i=postN1; i<=postN2; i++){
           Y.push_back(DefaultVal);
       }
    }
    return Y;
}



//------------------------------------------------------------------------------------------------------
//Array2DSize Array2DSize_GetSubSuccessionOfExtRows(const Array2DSize& size1, TDataShiftParams*dataShiftParam=NULL, int ifDefaultRowsPresent_LZero0_StretchToL1max1_StretchToLFinMax2=1);
//void Array2DSize_ConcatAdding(const Array2DSize& size1, const Array2DSize& size2, Array2DSize& size3, std::vector<Int2DVectorOfSizeOrCoords>&Ns1OfData1, std::vector<Int2DVectorOfSizeOrCoords>&Ns1OfData2, int shiftQ=0, TDataShiftParams*dataShiftParam=NULL,/*int QReq=0, int FromN=1, int QDfltBefore=0,*/ bool SetRect=true);
//void Array2DSize_ConcatStretching(const Array2DSize& size1, const Array2DSize& size2,  Array2DSize& size3, std::vector<Int2DVectorOfSizeOrCoords>&Ns1OfData1, std::vector<Int2DVectorOfSizeOrCoords>&Ns1OfData2, int shiftQ=0, TDataShiftParams*dataShiftParam=NULL,/*int QReq=0, int FromN=1, int QDfltBefore=0,*/ bool Stretch1ToMax=true, bool SetRect=true);
//Array2DSize Array2DSize_GetSubSuccessionOfExtRows(const Array2DSize& size1, TDataShiftParams*dataShiftParam=NULL, int ifDefaultRowsPresent_LZero0_StretchToL1max1_StretchToLFinMax2=1);
Array2DSize   Array2DSize_GetSubSuccessionOfExtRows(const Array2DSize& size1, TDataShiftParams*DataShiftParam,      int ifDefaultRowsPresent_LZero0_StretchToL1max1_StretchToLFinMax2){
    Array2DSize size2;
    std::vector<int>Ls1, Ls2;
    TDataShiftParams DataShift;
    int whatFromN, QReq, QDfltBefore;
    int Q1=size1.GetQExtRows(), L1max=size1.GetMaxLength(), L2max, curL2, Q2;
    Ls1=size1.GetLengthes();
    int DfltVal=0;
    int LreqCalcd, preN1, preN2, ownN1, ownN2, ForOwnN1, ForOwnN2, postN1, postN2, Lini,
        LreqGiven=QReq;//,
        //whatFromN, QDefaultValuesAfter;
    //void Calc_Array1DSubArray_byLs_MarkupNs_vFml_FixedDfltsAfter(int&LreqCalcd, int&preN1, int&preN2, int&ownN1, int&ownN2, int&ForOwnN1, int&ForOwnN2, int&postN1, int&postN2, int Lini, int LreqGiven=0, int whatFromN=1, int QDefaultValuesAfter=0);
    //template <typename T>std::vector<T> Array1DGetSubArray_byLs_PreMark(T*x, int Lold, int Lreq=0, int whatFromN=1, int FirstDefaultValues=0, T*DfltValParam=NULL){
    if(DataShiftParam!=NULL){
        DataShift=(*(DataShiftParam));
    }
    whatFromN=DataShift.FromN;
    QReq=DataShift.GetQAll(size1.GetQExtRows());
    QDfltBefore=DataShift.QDfltBefore;
    //
    Ls2=                                  Array1DGetSubArray_byLs_PreMark(          Ls1,     QReq,       whatFromN,       QDfltBefore,    &DfltVal);
    size2.Set(Ls2.size(), Ls2.data());
    Q2=size2.GetQExtRows();
    L2max=size2.GetMaxLength();

    if(size2.GetMinLength()==size2.GetMaxLength() && size1.isRectangularEvenByStr()){
        size2.Set(Ls2.size(), L1max);
    }else{
        size2.Set(Ls2.size(), Ls2.data());
        switch(ifDefaultRowsPresent_LZero0_StretchToL1max1_StretchToLFinMax2){
            case 1:
                for(int i=1; i<=Q2; i++){
                    curL2=size2.GetLength(i);
                    if(curL2==0){
                        size2.SetLength(L1max, i);
                    }
                }
            break;
            case 2:
            for(int i=1; i<=Q2; i++){
                curL2=size2.GetLength(i);
                if(curL2==0){
                    size2.SetLength(L2max, i);
                }
            }

            break;
            //default: NOp;
        }
    }
    return size2;//3;
}

//void Array2DSize_ConcatAdding(const Array2DSize& size1, const Array2DSize& size2, Array2DSize& size3, std::vector<Int2DVectorOfSizeOrCoords>&Ns1OfData1, std::vector<Int2DVectorOfSizeOrCoords>&Ns1OfData2, int shiftQ=0, int QReq=0, int FromN=1, int QDfltBefore=0, bool SetRect=true);
//void Array2DSize_ConcatAdding(const Array2DSize& size1, const Array2DSize& size2, Array2DSize& size3, std::vector<Int2DVectorOfSizeOrCoords>&Ns1OfData1, std::vector<Int2DVectorOfSizeOrCoords>&Ns1OfData2, int shiftQ=0, TDataShiftParams*dataShiftParam=NULL, bool SetRect=true);
void   Array2DSize_ConcatAdding(const Array2DSize& size1, const Array2DSize& size2, Array2DSize& size3, std::vector<Int2DVectorOfSizeOrCoords>&Ns1OfData1, std::vector<Int2DVectorOfSizeOrCoords>&Ns1OfData2, int shiftQ,   TDataShiftParams*dataShiftParam,      bool SetRect){
    TDataShiftParams DataShift;
    int FromN,  QReq,    QDfltBefore;
    int QE1=size1.GetQExtRows(), Lmax1=size1.GetMaxLength(), Lmin1=size1.GetMinLength(),
        QE2all=size2.GetQExtRows(),Lmax2all=size2.GetMaxLength(), Lmin2all=size2.GetMinLength(),
        QE2fact, Lmax2fact, Lmin2fact;
    int QE3, Lmax3;//,size3;
    int ifDefaultRowsPresent_LZero0_StretchToL1max1_StretchToLFinMax2=0;
    Int2DVectorOfSizeOrCoords NsPair;
    Array2DSize size2fact;
    if(dataShiftParam!=NULL){
        DataShift=(*(dataShiftParam));
    }
    FromN=DataShift.FromN;
    QReq=DataShift.GetQAll(QE2all);
    QDfltBefore=DataShift.QDfltBefore;
    if(SetRect){
        ifDefaultRowsPresent_LZero0_StretchToL1max1_StretchToLFinMax2=2;
    }
    size2fact=size2.GetSubSuccessionOfExtRows(FromN, QReq, QDfltBefore, ifDefaultRowsPresent_LZero0_StretchToL1max1_StretchToLFinMax2);
    QE2fact=size2fact.GetQExtRows();
    Lmax2fact=size2fact.GetMaxLength();
    if(shiftQ>=0){
        Lmax3 = Lmax1 >=  shiftQ+Lmax2fact ? Lmax1 : shiftQ+Lmax2fact;
        if(SetRect){
            size3.Set(QE2fact, Lmax3);
        }else{
            for(int i=1; i<=QE1; i++){
                size3.AddExt(size1.GetLength(i));
                //
                NsPair.d1=i;
                NsPair.d2=1;
                Ns1OfData1.push_back(NsPair);
            }
            for(int i=1; i<=QE2fact; i++){
                size3.AddExt(size2fact.GetLength(i)+shiftQ);
                //
                NsPair.d1=i;
                NsPair.d2=shiftQ+1;
                Ns1OfData2.push_back(NsPair);
            }
        }
    }else{
        //Lmax3 =  -shift+L1max >= L2max ? -shift+L1max : L2max;
        Lmax3 =  -shiftQ+Lmax1 >= Lmax2all ? -shiftQ+Lmax1 : Lmax2all;
        if(SetRect){
            size3.Set(QE2fact, Lmax3);
        }else{
            for(int i=1; i<=QE1; i++){
                size3.AddExt( -shiftQ+size1.GetLength(i));
                //
                NsPair.d1=i;
                NsPair.d2= -shiftQ+1;
                Ns1OfData1.push_back(NsPair);
            }
            for(int i=1; i<=QE2fact; i++){
                size3.AddExt(size2fact.GetLength(i));
                //
                NsPair.d1=i;
                NsPair.d2=1;
                Ns1OfData2.push_back(NsPair);
            }
        }
    }
    //return size3;
}

//void Array2DSize_ConcatStretching(const Array2DSize& size1, const Array2DSize& size2, Array2DSize& size3, std::vector<Int2DVectorOfSizeOrCoords>&Ns1OfData1, std::vector<Int2DVectorOfSizeOrCoords>&Ns1OfData2, int shiftQ=0, int QReq=0, int FromN=1, int QDfltBefore=0, bool Stretch1ToMax=true, bool SetRect=true);
//void Array2DSize_ConcatStretching(const Array2DSize& size1, const Array2DSize& size2, Array2DSize& size3, std::vector<Int2DVectorOfSizeOrCoords>&Ns1OfData1, std::vector<Int2DVectorOfSizeOrCoords>&Ns1OfData2, int shiftQ=0, TDataShiftParams*dataShiftParam=NULL, bool Stretch1ToMax=true, bool SetRect=true);
void   Array2DSize_ConcatStretching(const Array2DSize& size1, const Array2DSize& size2, Array2DSize& size3, std::vector<Int2DVectorOfSizeOrCoords>&Ns1OfData1, std::vector<Int2DVectorOfSizeOrCoords>&Ns1OfData2, int shiftQ,   TDataShiftParams*dataShiftParam,      bool Stretch1ToMax,      bool SetRect){
    int QE1=size1.GetQExtRows(), Lmax1=size1.GetMaxLength(), Lmin1=size1.GetMinLength(),
        QE2all=size2.GetQExtRows(),Lmax2all=size2.GetMaxLength(), Lmin2all=size2.GetMinLength(),
        QE2fact, Lmax2fact, Lmin2fact,
        L1;
    int QE3, Lmax3, curL, minQ;
    int FromN, QReq, QDfltBefore;
    Array2DSize  size2fact, size1fact;//, L1;
    TDataShiftParams DataShift;
    int ifDefaultRowsPresent_LZero0_StretchToL1max1_StretchToLFinMax2=0;
    int data1OwnN, data2OwnN, data1NewN, data2NewN;
    Int2DVectorOfSizeOrCoords NsPair;
    if(dataShiftParam!=NULL){
        DataShift=(*(dataShiftParam));
    }
    FromN=DataShift.FromN;
    QReq=DataShift.GetQAll(QE2all);
    QDfltBefore=DataShift.QDfltBefore;
    //
    size2fact=size2.GetSubSuccessionOfExtRows(FromN, QReq, QDfltBefore, ifDefaultRowsPresent_LZero0_StretchToL1max1_StretchToLFinMax2);
    QE2fact=size2fact.GetQExtRows();
    Lmax2fact=size2fact.GetMaxLength();
    size1fact=size1;
    Lmax3=size1.GetMaxLength()+size2fact.GetMaxLength();
    if(Stretch1ToMax && !size1.isRectangularEvenByStr()){
        for(int i=1; i<=QE1; i++){
            curL=size1fact.GetLength(i);
            size1fact.SetLength(Lmax1, curL);
        }
    }
    if(shiftQ>=0){
        if(shiftQ<=QE1){
            for(data1OwnN=1; data1OwnN<=shiftQ; data1OwnN++){
                data1NewN=data1OwnN;
                size3.AddExt(size1.GetLength(data1OwnN));
                NsPair.d1=data1NewN;
                NsPair.d2=1;
                Ns1OfData1.push_back(NsPair);
            }
            if(shiftQ+QE2fact<=QE1){
                //if(Stretch1ToMax){//no need ob if true data1 s'nua stretch'd, see ov
                //commom data 1+2
                for(data2OwnN=1; data2OwnN<=QE2fact; data2OwnN++){
                    data2NewN=data2OwnN+shiftQ;
                    data1NewN=data2NewN;
                    data1OwnN=data1NewN;
                    size3.AddExt(size1.GetLength(data1OwnN)+size2fact.GetLength(data2OwnN));
                    NsPair.d1=data1NewN;
                    NsPair.d2=1;
                    Ns1OfData1.push_back(NsPair);
                    NsPair.d1=data2NewN;
                    NsPair.d2=size1.GetLength(data1OwnN)+1;//if Stretch1ToMax, S'nua stretch'd
                    Ns1OfData2.push_back(NsPair);
                }
                //rest data 1 only
                for(data1NewN=shiftQ+QE2fact+1; data1NewN<=QE1; data1NewN++){
                    //data2CurN=i;
                    data1OwnN=data1NewN;
                    size3.AddExt(size1.GetLength(data1OwnN));
                    NsPair.d1=data1NewN;
                    NsPair.d2=1;
                    Ns1OfData1.push_back(NsPair);
                }
                //}
            }else{//shiftQ+QE2fact>QE1
                //data 1 + data 2, part of it, wo data1 !=0
                for(data1OwnN=shiftQ+1; data1OwnN<=QE1; data1OwnN++){
                    data1NewN=data1OwnN;
                    data2NewN=data1NewN;
                    data2OwnN=data2NewN-shiftQ;
                    size3.AddExt(size1.GetLength(data1OwnN)+size2fact.GetLength(data2OwnN));
                    NsPair.d1=data1NewN;
                    NsPair.d2=1;
                    Ns1OfData1.push_back(NsPair);
                    NsPair.d1=data2NewN;
                    NsPair.d2=size1.GetLength(data1OwnN)+1;
                    Ns1OfData2.push_back(NsPair);
                }
                if(Stretch1ToMax){
                    L1=Lmax1;
                }else{
                    L1=0;
                }
                //data 2 rest part
                for(int data2NewN=QE1+1; data2NewN<=shiftQ+QE2fact; data2NewN++){
                    data2OwnN=data2NewN-shiftQ;
                    size3.AddExt(L1+size2fact.GetLength(data2OwnN));//wa i-shiftQ. I men L(ownN)
                    NsPair.d1=data2NewN;
                    NsPair.d2=L1+1;
                    Ns1OfData2.push_back(NsPair);
                }
            }
        }else{//shiftQ>QE1
            //data 1 all only
            for(int i=1; i<=QE1; i++){
                size3.AddExt(size1.GetLength(i));
                NsPair.d1=i;
                NsPair.d2=1;
                Ns1OfData1.push_back(NsPair);
            }
            if(Stretch1ToMax){
                L1=Lmax1;
            }else{
                L1=0;
            }
            //defaults between data 1 et 2
            for(int i=QE1+1; i<=shiftQ; i++){
                size3.AddExt(L1);
                //No Ns
            }
            //data 2 all only
            for(data2OwnN=1; data2OwnN<=QE2fact; data2OwnN++){
                data2NewN=data2OwnN+shiftQ;
                size3.AddExt(L1+size2fact.GetLength(data2OwnN));//? wa i, amda s'no i. Ms'b L(ownN), newN s'ut lif udce
                NsPair.d1=data2NewN;
                NsPair.d2=L1+1;
                Ns1OfData2.push_back(NsPair);
            }
        }
    }else{//shiftQ<0 //this branch is not finished!
        if(-shiftQ<=QE2fact){
            //data 2 -shiftQ
            if(Stretch1ToMax){
                L1=Lmax1;
            }else{
                L1=0;
            }
            for(data2NewN=1; data2NewN<=-shiftQ; data2NewN++){
                data2OwnN=data2NewN;
                size3.AddExt(L1+size2fact.GetLength(data2OwnN));
                NsPair.d1=data2NewN;
                NsPair.d2=L1+1;
                Ns1OfData2.push_back(NsPair);
            }
            if(-shiftQ+QE2fact<=QE1){
                //data 1 + data 2, data 2 all exy erst -shiftQ, data 1 ab 1
                for(data2OwnN=-shiftQ+1; data2OwnN<=QE2fact; data2OwnN++){
                    L1=size1.GetLength(data1OwnN);//if stretch, S'fa nua
                    data2NewN=data2OwnN+(-shiftQ);
                    data1NewN=data2NewN;
                    data1OwnN=data1NewN-(-shiftQ);
                    size3.AddExt(L1+size2fact.GetLength(data2OwnN));
                    NsPair.d1=data1NewN;
                    NsPair.d2=1;
                    Ns1OfData1.push_back(NsPair);
                    NsPair.d1=data2NewN;
                    NsPair.d2=L1+1;//if stretch, S'fa nua
                    Ns1OfData2.push_back(NsPair);
                }
                //rest data 1
                for(data1NewN=-shiftQ+QE2fact+1; data1NewN<=-shiftQ+QE1; data1NewN++){
                    data1OwnN=data1NewN-(-shiftQ);
                    size3.AddExt(size1.GetLength(data1OwnN));//if stretch, S'fa
                    NsPair.d1=data1NewN;
                    NsPair.d2=1;
                    Ns1OfData1.push_back(NsPair);
                }
            }else{// -shiftQ+QE2fact > QE1
                //af -shiftQ
                //data 1 all, data 2 -shiftQ+1...-shiftQ+QE1
                for(data1OwnN=1; data1OwnN<=QE1; data1OwnN++){
                    data1NewN=data1OwnN-shiftQ;
                    data2NewN=data1NewN;
                    data2OwnN=data2NewN;
                    L1=size1.GetLength(data1OwnN);
                    size3.AddExt(L1+size2fact.GetLength(data2OwnN));
                    NsPair.d1=data1NewN;
                    NsPair.d2=1;
                    Ns1OfData1.push_back(NsPair);
                    NsPair.d1=data2NewN;
                    NsPair.d2=L1+1;//if stretch, S'fa nua
                    Ns1OfData2.push_back(NsPair);
                }
                //rest data 2 -shiftQ+QE1...-shiftQ+QE2fact
                if(Stretch1ToMax){
                    L1=Lmax1;
                }else{
                    L1=0;
                }
                for(data2OwnN=-shiftQ+QE1+1; data2OwnN<=-shiftQ+QE2fact; data2OwnN++){
                    data2NewN=data2OwnN;
                    size3.AddExt(L1+size2fact.GetLength(data2OwnN));
                    NsPair.d1=data2NewN;
                    NsPair.d2=L1+1;//if stretch, S'fa nua
                    Ns1OfData2.push_back(NsPair);
                }
            }
        }else{// (-shiftQ > QE2fact)
            //all data 2
            if(Stretch1ToMax){
                L1=Lmax1;
            }else{
                L1=0;
            }
            for(data2OwnN=1; data2OwnN<=QE2fact; data2OwnN++){
                data2NewN=data2OwnN;
                size3.AddExt(L1+size2fact.GetLength(data2OwnN));
                NsPair.d1=data2NewN;
                NsPair.d2=L1+1;//if stretch, S'fa nua
                Ns1OfData2.push_back(NsPair);
            }
            // defaults between 2 and 1
            for(int i=QE2fact+1; i<=-shiftQ; i++){
                size3.AddExt(L1);
                //No Ns
            }
            //all data 1
            for(data1OwnN=1; data1OwnN<=QE1; data1OwnN++){
                L1=size1.GetLength(data1OwnN);
                size3.AddExt(L1);//if stretch, S'fa nua
                data1NewN=data1OwnN-shiftQ;
                NsPair.d1=data1NewN;
                NsPair.d2=1;
                Ns1OfData1.push_back(NsPair);
            }
        }// if(-shiftQ<=QE2fact) or >
    }//if(shiftQ>=0) or <0
    if(SetRect){
        size3.Set(size3.GetQExtRows(), Lmax3);
    }
}//fn



Array2DSize Array2DSize_GetNewSizeChangingExtRow(const Array2DSize& size1, int ExtRowN, int proposedRowL, TDataShiftParams*DataShiftParam, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6){
    Array2DSize sizeNew;
    int QExtRows=size1.GetQExtRows(), Lmin=size1.GetMinLength(), Lmax=size1.GetMaxLength(), newL, maxL, curL;
    bool isRectEvenByStr=size1.isRectangularEvenByStr();
    TDataShiftParams DataShift;
    if(DataShiftParam!=NULL){
        DataShift=(*(DataShiftParam));
    }
    if(ExtRowN<0){
        ExtRowN+=(QExtRows+1);
    }
    sizeNew.SetNull();
    if(ExtRowN>=1 && ExtRowN<=QExtRows){
        sizeNew=size1;
        curL=size1.GetLength(ExtRowN);
        if(proposedRowL==0){
            proposedRowL=curL;
        }
        if(DataShift.QReq==0){
            DataShift.QReq=curL;
        }
        // 1. newL
        switch(SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6){
            case 0:
            case 1:
            case 2:
                //NOp
                newL= DataShift.QReq;//vrn if ==0 fa ov
            break;
            case 3:
                maxL = Lmax >= DataShift.QReq ? Lmax : DataShift.QReq;
                newL=maxL;
            break;
            case 4:
                newL=Lmax;
            break;
            case 5:
                newL=curL;
            break;
            case 6:
                newL=DataShift.QReq;
            break;
        }
        DataShift.QReq=newL;
        // 2. form size
        if(curL!=newL){
            switch(SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6){
                case 0:
                case 1:
                case 2:
                    //nablb rect
                    sizeNew.SetLength(newL, ExtRowN);
                break;
                case 3:
                case 4:
                case 5:
                case 6:
                    sizeNew.Set(QExtRows, newL);//newL s'def'd ov
                break;
            }
        }else{
            if(isRectEvenByStr && newL==curL && SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6==1){
                sizeNew.SetVaria(QExtRows, newL);
            }
        }
    }
}
Array2DSize Array2DSize_GetNewSizeAddingExtRow(const Array2DSize& size1, int proposedRowL, TDataShiftParams*DataShiftParam, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6){
    Array2DSize sizeNew, sizePre;
    int QExtRows=size1.GetQExtRows(), Lmin=size1.GetMinLength(), Lmax=size1.GetMaxLength(), newL, maxL, curL, preL, lastL=size1.GetLength(QExtRows);
    bool isRectEvenByStr=size1.isRectangularEvenByStr();
    TDataShiftParams DataShift;
    if(DataShiftParam!=NULL){
        DataShift=(*(DataShiftParam));
    }
    if(proposedRowL==0 && isRectEvenByStr){
        proposedRowL=lastL;
    }//aso if isRectEvenByStr==f, 0 stay
     // 1.
    sizePre=size1;
    switch(SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6){
        case 0:
        case 2:
            if(isRectEvenByStr && DataShift.QReq==Lmax){
                sizePre.Set(QExtRows+1, Lmax);
                //ob farr ms'repas'trc size co rect str
            }else{
                sizePre.AddExt(Lmax);
            }
        break;
        case 1://always varia
        case 3://alum rect amda et farr=>n'ute care
        case 4:
        case 5:
        case 6:
            sizePre.AddExt(1);
        break;

    }
    // 2.
    //Array2DSize Array2DSize_GetNewSizeChangingExtRow(const Array2DSize& size1, int ExtRowN, int proposedRowL, TDataShiftParams*DataShiftParam, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6){
    sizeNew=Array2DSize_GetNewSizeChangingExtRow(sizePre, QExtRows+1, proposedRowL, DataShiftParam, SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6);
}
Array2DSize Array2DSize_GetNewSizeInsingExtRow(const Array2DSize& size1, int ExtRowN, int proposedRowL, TDataShiftParams*DataShiftParam, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6){
    Array2DSize sizeNew, sizePre;
    int QExtRows=size1.GetQExtRows(), Lmin=size1.GetMinLength(), Lmax=size1.GetMaxLength(), newL, maxL, curL, preL, lastL=size1.GetLength(QExtRows);
    bool isRectEvenByStr=size1.isRectangularEvenByStr();
    TDataShiftParams DataShift;
    if(DataShiftParam!=NULL){
        DataShift=(*(DataShiftParam));
    }
    if(ExtRowN<0){
        ExtRowN+=(QExtRows+1);
    }
    if(ExtRowN>=1 && ExtRowN<=QExtRows){
        if(proposedRowL==0 && isRectEvenByStr){
            proposedRowL=lastL;
        }//aso if isRectEvenByStr==f, 0 stay
        // 1.
        sizePre=size1;
        switch(SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6){
            case 0:
            case 2:
                if(isRectEvenByStr && DataShift.QReq==Lmax){
                    sizePre.Set(QExtRows+1, Lmax);
                    //ob farr ms'repas'trc size co rect str
                }else{
                    sizePre.InsExt(ExtRowN, Lmax);
                }
            break;
            case 1://always varia
            case 3://alum rect amda et farr=>n'ute care
            case 4:
            case 5:
            case 6:
                sizePre.InsExt(ExtRowN, 1);
            break;
        }
    }//aso NOp
    // 2.
    //Array2DSize Array2DSize_GetNewSizeChangingExtRow(const Array2DSize& size1, int ExtRowN, int proposedRowL, TDataShiftParams*DataShiftParam, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6){
    sizeNew=Array2DSize_GetNewSizeChangingExtRow(sizePre, ExtRowN, proposedRowL, DataShiftParam, SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6);
}

//

void Array2DSize_FindPositionOfOneInOther(const Array2DSize&sizeWhere, const Array2DSize&sizeWhat, Int2DVectorOfSizeOrCoords CoordsWhereFrom, Int2DVectorOfSizeOrCoords CoordsInWhat, Int2DVectorOfSizeOrCoords& CoordsWhereTo, bool isNotTransposed, bool ExtRowsSuccIsNotReversed, bool EachRowIsNotReversed){
    int QERWhere=sizeWhere.GetQExtRows(), QERWhat=sizeWhat.GetQExtRows(), LWhere=sizeWhere.GetLength(CoordsWhereFrom.d1), LWhatt=sizeWhat.GetLength(CoordsInWhat.d1);
    if(isNotTransposed){
        if(ExtRowsSuccIsNotReversed){
            if(EachRowIsNotReversed){
                // [11> 12 13
                //  v
                //  21  22 23
                //  31  32 33
                CoordsWhereTo.d1=CoordsWhereFrom.d1+CoordsInWhat.d1-1;
                CoordsWhereTo.d2=CoordsWhereFrom.d2+CoordsInWhat.d2-1;
            }else{
                // 13 12 <11]
                //        v
                // 23 22  21
                // 33 32  31
                CoordsWhereTo.d1=CoordsWhereFrom.d1+CoordsInWhat.d1-1;
                CoordsWhereTo.d2=CoordsWhereFrom.d2-CoordsInWhat.d2+1;
            }
        }else{
            if(EachRowIsNotReversed){
                //  31  32 33
                //  21  22 23
                //  ^
                // [11> 12 13
                CoordsWhereTo.d1=CoordsWhereFrom.d1-CoordsInWhat.d1+1;
                CoordsWhereTo.d2=CoordsWhereFrom.d2+CoordsInWhat.d2-1;
            }else{
                // 33 32  31
                // 23 22  21
                //        ^
                // 13 12 <11]
                CoordsWhereTo.d1=CoordsWhereFrom.d1-CoordsInWhat.d1+1;
                CoordsWhereTo.d2=CoordsWhereFrom.d2-CoordsInWhat.d2+1;
            }
        }
    }else{
        if(ExtRowsSuccIsNotReversed){
            if(EachRowIsNotReversed){
                // [11> 21 31
                //  v
                //  12  22 32
                //  13  23 33
                CoordsWhereTo.d1=CoordsWhereFrom.d1+CoordsInWhat.d2-1;
                CoordsWhereTo.d2=CoordsWhereFrom.d2+CoordsInWhat.d1-1;
            }else{
                //  31  21 <11]
                //          v
                //  32  22  12
                //  33  23  13
                CoordsWhereTo.d1=CoordsWhereFrom.d1+CoordsInWhat.d2-1;
                CoordsWhereTo.d2=CoordsWhereFrom.d1-CoordsInWhat.d1+1;
            }
        }else{
            if(EachRowIsNotReversed){
                //  13  23 33
                //  12  22 32
                //  ^
                // [11> 21 31
                CoordsWhereTo.d1=CoordsWhereFrom.d1-CoordsInWhat.d2+1;
                CoordsWhereTo.d2=CoordsWhereFrom.d2+CoordsInWhat.d1-1;
            }else{
                //  33  23  13
                //  32  22  12
                //          ^
                //  31  21 <11]
                CoordsWhereTo.d1=CoordsWhereFrom.d1-CoordsInWhat.d2+1;
                CoordsWhereTo.d2=CoordsWhereFrom.d1-CoordsInWhat.d1+1;
            }
        }
    }
}//fn

bool Array2DSize_IsOneInOtherAtPos(const Array2DSize&sizeWhere, const Array2DSize&sizeWhat, int ExtRowN, int IneRowN, bool isNotTransposed, bool ExtRowsSuccIsNotReversed, bool EachRowIsNotReversed){
    bool b=true;
    Int2DVectorOfSizeOrCoords CoordsInWhat, CoordsWhereTo, CoordsWhereFrom;
    int QERWhere=sizeWhere.GetQExtRows(), QERWhat=sizeWhat.GetQExtRows(), LWhere, LWhat;
    CoordsWhereFrom.d1=ExtRowN;
    CoordsWhereFrom.d2=IneRowN;
    for(int i=1; i<=QERWhat; i++){
        LWhat=sizeWhat.GetLength(i);
        for(int j=1; j<=LWhat; j++){
            CoordsInWhat.d1=i;
            CoordsInWhat.d2=j;
            //void Array2DSize_FindPositionOfOneInOther(const Array2DSize&sizeWhere, const Array2DSize&sizeWhat, Int2DVectorOfSizeOrCoords CoordsWhereFrom, Int2DVectorOfSizeOrCoords CoordsInWhat, Int2DVectorOfSizeOrCoords& CoordsWhereTo, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachRowIsNotReversed=true){
            Array2DSize_FindPositionOfOneInOther(                         sizeWhere,                   sizeWhat,                           CoordsWhereFrom,                           CoordsInWhat,                            CoordsWhereTo,      isNotTransposed,           ExtRowsSuccIsNotReversed,          EachRowIsNotReversed);
            if(CoordsWhereTo.d1>=1 && CoordsWhereTo.d1<=QERWhere){
                LWhere=sizeWhere.GetLength(CoordsWhereTo.d1);
                if(CoordsWhereTo.d2>=1 && CoordsWhereTo.d2<=LWhere){
                    //NOp;
                }else{
                    b=false;
                }
            }else{
                b=false;
            }
            if(b==false){
                break;
            }
        }
        if(b==false){
            break;
        }
    }
    return b;
}


//=======================================================================================================

/*

//Array2DSizePrototype*Array2DSizePrototype::clone() const{
//    return new Array2DSizePrototype(*this);
//}
//
bool Array2DSizePrototype::IsRectangularFact() const{
    return(this->GetMinLength()==this->GetMaxLength());
}
bool Array2DSizePrototype::IsVariableLengthFact() const{
    return(this->GetMinLength()!=this->GetMaxLength());
}



//class Array2DSizeVarLenP: public Array2DSizePrototype
//{
//    int*Ls;
//    int QExtRows;
//public:
    //virtual Array2DSize();
    //Array2DSizeVarLenP(const Array2DSizeVarLenP&obj);//I men no not ob in dyn polymorf S nablb realf'd
    Array2DSizeVarLenP::Array2DSizeVarLenP(int QExtRows, int ExtRowsLength): Array2DSizePrototype(QExtRows, ExtRowsLength){
        this->Construct();
        this->Set(QExtRows, ExtRowsLength);
    }
    Array2DSizeVarLenP::Array2DSizeVarLenP(int QExtRows, int*Ls) :Array2DSizePrototype(){//{//: Array2DSizePrototype(QExtRows, Ls){
        this->Construct();
        this->Set(QExtRows, Ls);
    }
    Array2DSizeVarLenP::Array2DSizeVarLenP(std::vector<int>Ls) :Array2DSizePrototype(){//{//: Array2DSizePrototype(Ls){
        this->Construct();
        this->Set(Ls);
    }
    //Array2DSizeVarLenP operator =(const Array2DSizePrototype&obj);
    //Array2DSizeVarLenP* Array2DSizeVarLenP::clone() const {
    //    return this;
    //}
    Array2DSizeVarLenP::~Array2DSizeVarLenP(){
        delete[]this->Ls;
    }
    //virtual void Assign(const Array2DSizePrototype&obj);//I men no not ob in dyn polymorf S nablb realf'd
    //void Array2DSizeVarLenP::Assign(Array2DSizeVarLenP*obj){//I hope ce abls ob Array2DSizeVarLenP s'heir of Array2DSizePrototype]
    //    this->SetNull();
    //    this->Set(obj->QExtRows, obj->Ls);
    //}
    void Array2DSizeVarLenP::Construct(){
        this->QExtRows=0;
        this->Ls=NULL;
    }

    void Array2DSizeVarLenP::SetNull(){
        if(this->Ls!=NULL){
            delete this->Ls;
        }
        this->QExtRows=0;
    }
    //
    bool Array2DSizeVarLenP::IsRectangularType() const{
        return false;
    }
    bool Array2DSizeVarLenP::IsVariableLengthType() const{
        return true;
    }
    //bool Array2DSizeVarLenP::IsRectangularFact() const{
    //    int Lmin=this->GetMinLength(), Lmax=this->GetMaxLength();
    //    return (Lmin==Lmax);
    //}
    //bool Array2DSizeVarLenP::IsVariableLengthFact() const{
    //    int Lmin=this->GetMinLength(), Lmax=this->GetMaxLength();
    //    return (Lmin!=Lmax);
    //}
    //
    //virtual void SetVaria();
    //virtual void SetRectangular(int L_ifVaria_min_m1_max_less=-2);
    //
    void Array2DSizeVarLenP::SetOne(){
        this->SetNull();
        this->Set(1, 1);
    }
    bool Array2DSizeVarLenP::ExtRowNBelongsTo(int extRowN) const{
        bool verdict;
        verdict=(extRowN>=1 && extRowN<=this->QExtRows);
        return verdict;
    }
    bool Array2DSizeVarLenP::PosBelongsTo(int extRowN, int ineRowN){
        int L;
        bool b;
        b=(this->ExtRowNBelongsTo(extRowN));
        if(b){
           L=this->GetLength(extRowN);
           b=(ineRowN>=1 && ineRowN<=L);
        }
        return b;
    }
    void Array2DSizeVarLenP::Set(int QExtRows, int IneRowsLength){
        this->SetNull();
        this->QExtRows=QExtRows;
        this->Ls=new int[this->QExtRows];
        for(int i=1; i<=this->QExtRows; i++){
            this->Ls[i-1]=IneRowsLength;
        }
    }
    void Array2DSizeVarLenP::Set(int QExtRows,int*Ls){
        this->SetNull();
        this->QExtRows=QExtRows;
        this->Ls=new int[this->QExtRows];
        if(this->Ls!=NULL){
            for(int i=1; i<this->QExtRows; i++){
                this->Ls[i-1]=Ls[i-1];
            }
        }else{
            for(int i=1; i<this->QExtRows; i++){
                this->Ls[i-1]=0;
            }
        }
    }
    void Array2DSizeVarLenP::Set(std::vector<int>Ls){
        this->SetNull();
        this->QExtRows=Ls.size();
        for(int i=1; i<this->QExtRows; i++){
            this->Ls[i-1]=Ls[i-1];
        }
    }
    //virtual void Set1ExtRowVaria(int L);
    //virtual void SetVaria(int QExtRows, int IneRowsLength);
    //virtual void ConvertToRectIfAllLengthesAreEqual();
    //virtual void Add(int L, int ifConstAndNotEqual_Ignore0AddExisting1SetAll2=2);
    //virtual void Ins(int N, int L);
    void Array2DSizeVarLenP::AddExt(int L){
        Array1DAddElement(this->Ls, this->QExtRows, L);
    }
    void  Array2DSizeVarLenP::InsExt(int N, int L){
        Array1DInsElementToN(this->Ls, this->QExtRows, N, L);
    }
    void Array2DSizeVarLenP::DelExt(int N){
        Array1DDelElementFromN(this->Ls, this->QExtRows, N);
    }
    void Array2DSizeVarLenP::DelIneRow(){
        for(int i=1; i<=this->QExtRows; i++){
            this->Ls[i-1]--;
        }
    }
    void Array2DSizeVarLenP::AddOrInsIneRow(){
        for(int i=1; i<=this->QExtRows; i++){
            this->Ls[i-1]++;
        }
    }
    //virtual void AddOrInsTo(int L=0, int N_0ToAllPreserveType_GTT0AndMakeVaria=0);
    //virtual void DelFrom(int L, int N_0ToAllPreserveType_GTT0AndMakeVaria=0);
    void Array2DSizeVarLenP::AddOrInsTo(int N, int L){
        if(N>=1 && N<=this->GetQExtRows() && L>=1){
            this->Ls+=L;
        }
    }
    void  Array2DSizeVarLenP::DelFrom(int N, int L){
        if(N>=1 && N<=this->GetQExtRows() && L>=1){
            this->Ls-=L;
        }
    }
    int Array2DSizeVarLenP::GetQExtRows() const{
        return this->QExtRows;
    }
    //virtual bool GetIfIsVariaLength() const;
    //virtual bool Array2DSizeVarLenP::isVariaLength() const{return true; }
    //virtual bool isRectangular() const;
    int Array2DSizeVarLenP::GetLength(int N) const{
        int L=0, minL, maxL, curL, QExtRows=this->GetQExtRows();
        if(N>=1 && N<=this->GetQExtRows()){
            L=this->Ls[N-1];
        }else if(N==0){
            minL=0;
            maxL=0;
            for(int i=1; i<=QExtRows; i++){
                curL=Ls[i-1];
                if(i==1 || (i>1 && curL<minL)){
                    minL=curL;
                }
                if(i==1 || (i>1 && curL>maxL)){
                    maxL=curL;
                }
            }
            if(minL==maxL){
                L=this->Ls[1-1];
            }//else remains 0
        }
        return L;
    }
    int Array2DSizeVarLenP::GetMinLength()const{
        int L=0, minL, maxL, curL, QExtRows=this->GetQExtRows();
        for(int i=1; i<=QExtRows; i++){
            curL=Ls[i-1];
            if(i==1 || (i>1 && curL<minL)){
                minL=curL;
            }
            if(i==1 || (i>1 && curL>maxL)){
                maxL=curL;
            }
        }
        return minL;
    }
    int Array2DSizeVarLenP::GetMaxLength()const{
        int L=0, minL, maxL, curL, QExtRows=this->GetQExtRows();
        for(int i=1; i<=QExtRows; i++){
            curL=Ls[i-1];
            if(i==1 || (i>1 && curL<minL)){
                minL=curL;
            }
            if(i==1 || (i>1 && curL>maxL)){
                maxL=curL;
            }
        }
        return maxL;
    }
    void Array2DSizeVarLenP::SwapExtRows(int N1, int N2){
        int buf, QExtRows=this->GetQExtRows();
        if(N1>=1 && N1<=QExtRows && N2>=1 && N2<=QExtRows){
            buf=this->Ls[N1-1];
            this->Ls[N1-1]=this->Ls[N2-1];
            this->Ls[N2-1]=buf;
        }
    }
    void Array2DSizeVarLenP::Reverse(){
        Array1DReverse(this->Ls, this->QExtRows);
    }
    //virtual void SetQExtRows(int N);
    //virtual void SetIneRowsLength(int L_Minus1MinMinus2Max=-1, bool preserveTypeIfVaria=false);
    //virtual void SetLength(int L, int N_0ToAllPreserveType_GTT0AndMakeVaria_Minus1ToAllMakeNotVaria=0);
    void Array2DSizeVarLenP::SetLength(int L, int N){
        int QExtRows=this->GetQExtRows();
        if(N<0){
            N=QExtRows+N+1;
        }
        if(N>=1 && N<=QExtRows){
            this->Ls[N-1]=L;
        }else if(N==0){
            for(int i=1; i<=QExtRows; i++){
                this->Ls[i-1]=L;
            }
        }
    }
    QString Array2DSizeVarLenP::GetAsQString(QString delim)const{
       QString s, sn;
       int QExtRows=this->GetQExtRows();
       sn.setNum(QExtRows);
       s="Size: "+sn+": [";
       for(int i=1; i<=QExtRows-1; i++){
          sn.setNum(this->Ls[i-1]);
          s+=sn;
          s+=delim;
       }
       sn.setNum(this->Ls[QExtRows-1]);
       s+=sn;
       s+="]";
       return s;
    }
    std::string Array2DSizeVarLenP::GetAsStdString(std::string delim) const{
        QString qsd=QString(delim.c_str());
        QString qs=this->GetAsQString(qsd);
        std::string ss=qs.toStdString();
        return ss;
    }
    void  Array2DSizeVarLenP::ShowToConsole() const{
        std::string ss=this->GetAsStdString();
        std::cout<<ss;
    }
    //virtual bool isSame(const Array2DSizeVarLenP&obj)const;
    //bool Array2DSizeVarLenP::isSame(Array2DSizeVarLenP*obj)const{
    //    bool b;
    //    int QExtRows=this->GetQExtRows();
    //    b=(this->GetQExtRows()==obj->GetQExtRows());
    //    if(b){
    //        for(int i=1; i<=QExtRows; i++){
    //            if(this->Ls[i-1]!=obj->Ls[i-1]){
    //                b=false;
    //            }
    //        }
    //    }
    //    return b;
    //}
    int Array2DSizeVarLenP::GetIneRowsLength()const{ return this->GetLength(0); }
    int Array2DSizeVarLenP::LengthFullOfIneRowN(int IneRowN) const{//from start to 1st stop
        int count, QExtRows=this->GetQExtRows(), Lmax=this->GetMaxLength(), Lcur, N=0;
        bool breakreached=false, contin=(N>=1 && N<=Lmax);
        while(contin){
            N++;
            Lcur=this->GetLength(N);
            if(Lcur>=IneRowN){
                if(breakreached==false){
                    count++;
                }else{
                    count=0;
                    contin=false;
                }
            }else{
                breakreached=true;
            }
        }
        return count;
    }
    bool Array2DSizeVarLenP::IsForTranspose() const{
        bool b=true;
        int count, QExtRows=this->GetQExtRows(), Lmax=this->GetMaxLength(), Lcur, Lnxt, N=0;
        for(int i=1; i<=QExtRows-1; i++){
            Lcur=this->LengthFullOfIneRowN(i);
            Lnxt=this->LengthFullOfIneRowN(i+1);
            if(Lcur>Lnxt){
                b=false;
            }
        }
        return b;
    }
    void Array2DSizeVarLenP::Transpose(){
        int*Ls=NULL, Lmax=this->GetMaxLength();
        if(this->IsForTranspose()){
            Ls=new int[Lmax];
            for(int i=1; i<=Lmax; i++){
                Ls[i-1]=this->LengthFullOfIneRowN(i);
            }
            this->Set(Lmax, Ls);
        }
    }
//};

    //class Array2DSizeVarLenV: public Array2DSizePrototype
    //{
    //    int*Ls;
    //    int QExtRows;
    //public:
        //virtual Array2DSize();
        //Array2DSizeVarLenV(const Array2DSizeVarLenV&obj);//I men no not ob in dyn polymorf S nablb realf'd
    Array2DSizeVarLenV::Array2DSizeVarLenV(int QExtRows, int ExtRowsLength): Array2DSizePrototype(){//{// : Array2DSizePrototype(QExtRows, ExtRowsLength){
            this->Construct();
            this->Set(QExtRows, ExtRowsLength);
        }
        Array2DSizeVarLenV::Array2DSizeVarLenV(int QExtRows, int*Ls){// : Array2DSizePrototype(QExtRows, Ls){
            this->Construct();
            this->Set(QExtRows, Ls);
        }
        Array2DSizeVarLenV::Array2DSizeVarLenV(std::vector<int>Ls){// : Array2DSizePrototype(Ls){
            this->Construct();
            this->Set(Ls);
        }
        //Array2DSizeVarLenV operator =(const Array2DSizePrototype&obj);
        //Array2DSizeVarLenV* Array2DSizeVarLenV::clone() const {
        //    return this;
        //}
        Array2DSizeVarLenV::~Array2DSizeVarLenV(){}
        //virtual void Assign(const Array2DSizePrototype&obj);//I men no not ob in dyn polymorf S nablb realf'd
        //void Array2DSizeVarLenV::Assign(Array2DSizeVarLenV*obj){//I hope ce abls ob Array2DSizeVarLenV s'heir of Array2DSizePrototype]
        //    this->SetNull();
        //    this->Set(obj->Ls);
        //}
        void Array2DSizeVarLenV::Construct(){
            this->SetNull();
        }

        void Array2DSizeVarLenV::SetNull(){
            this->Ls.clear();
        }
        //
        bool Array2DSizeVarLenV::IsRectangularType() const{
            return false;
        }
        bool Array2DSizeVarLenV::IsVariableLengthType() const{
            return true;
        }
        bool Array2DSizeVarLenV::IsRectangularFact() const{
            int Lmin=this->GetMinLength(), Lmax=this->GetMaxLength();
            return (Lmin==Lmax);
        }
        bool Array2DSizeVarLenV::IsVariableLengthFact() const{
            int Lmin=this->GetMinLength(), Lmax=this->GetMaxLength();
            return (Lmin!=Lmax);
        }
        //
        //virtual void SetVaria();
        //virtual void SetRectangular(int L_ifVaria_min_m1_max_less=-2);
        //
        void Array2DSizeVarLenV::SetOne(){
            this->SetNull();
            this->Set(1, 1);
        }
        bool Array2DSizeVarLenV::ExtRowNBelongsTo(int extRowN)const{
            bool verdict;
            verdict=(extRowN>=1 && extRowN<=this->GetQExtRows());
            return verdict;
        }
        bool Array2DSizeVarLenV::PosBelongsTo(int extRowN, int ineRowN){
            int L;
            bool b;
            b=(this->ExtRowNBelongsTo(extRowN));
            if(b){
               L=this->GetLength(extRowN);
               b=(ineRowN>=1 && ineRowN<=L);
            }
            return b;
        }
        void Array2DSizeVarLenV::Set(int QExtRows, int ExtRowsLength){
            this->SetNull();
            for(int i=1; i<=QExtRows; i++){
                this->Ls.push_back(ExtRowsLength);
            }
        }
        void Array2DSizeVarLenV::Set(int QExtRows, int*Ls){
            this->SetNull();
            if(Ls!=NULL){
                for(int i=1; i<QExtRows; i++){
                    this->Ls.push_back(Ls[i-1]);
                }
            }else{
                for(int i=1; i<QExtRows; i++){
                    this->Ls.push_back(0);
                }
            }
        }
        void Array2DSizeVarLenV::Set(std::vector<int>Ls){
            this->Ls=Ls;
        }
        //virtual void Set1ExtRowVaria(int L);
        //virtual void SetVaria(int QExtRows, int IneRowsLength);
        //virtual void ConvertToRectIfAllLengthesAreEqual();
        //virtual void Add(int L, int ifConstAndNotEqual_Ignore0AddExisting1SetAll2=2);
        //virtual void Ins(int N, int L);
        void Array2DSizeVarLenV::AddExt(int L){
            Array1DAddElement(this->Ls, L);
        }
        void  Array2DSizeVarLenV::InsExt(int N, int L){
            Array1DInsElementToN(this->Ls, N, L);
        }
        void Array2DSizeVarLenV::DelExt(int N){
            Array1DDelElementFromN(this->Ls, N);
        }
        void Array2DSizeVarLenV::DelIneRow(){
            int QExtRows=this->GetQExtRows();
            for(int i=1; i<=QExtRows; i++){
                this->Ls[i-1]--;
            }
        }
        void Array2DSizeVarLenV::AddOrInsIneRow(){
            int QExtRows=this->GetQExtRows();
            for(int i=1; i<=QExtRows; i++){
                this->Ls[i-1]++;
            }
        }
        //virtual void AddOrInsTo(int L=0, int N_0ToAllPreserveType_GTT0AndMakeVaria=0);
        //virtual void DelFrom(int L, int N_0ToAllPreserveType_GTT0AndMakeVaria=0);
        void Array2DSizeVarLenV::AddOrInsTo(int N, int L){
            if(N>=1 && N<=this->GetQExtRows() && L>=1){
                this->Ls[N-1]+=L;
            }
        }
        void  Array2DSizeVarLenV::DelFrom(int N, int L){
            if(N>=1 && N<=this->GetQExtRows() && L>=1){
                this->Ls[N-1]-=L;
            }
        }
        int Array2DSizeVarLenV::GetQExtRows() const{
            return this->Ls.size();
        }
        //virtual bool GetIfIsVariaLength() const;
        //virtual bool Array2DSizeVarLenV::isVariaLength() const{return true; }
        //virtual bool isRectangular() const;
        int Array2DSizeVarLenV::GetLength(int N) const{
            int L=0, minL, maxL, curL, QExtRows=this->GetQExtRows();
            if(N>=1 && N<=this->GetQExtRows()){
                L=this->Ls[N-1];
            }else if(N==0){
                minL=0;
                maxL=0;
                for(int i=1; i<=QExtRows; i++){
                    curL=Ls[i-1];
                    if(i==1 || (i>1 && curL<minL)){
                        minL=curL;
                    }
                    if(i==1 || (i>1 && curL>maxL)){
                        maxL=curL;
                    }
                }
                if(minL==maxL){
                    L=this->Ls[1-1];
                }//else remains 0
            }
            return L;
        }
        int Array2DSizeVarLenV::GetMinLength()const{
            int L=0, minL, maxL, curL, QExtRows=this->GetQExtRows();
            for(int i=1; i<=QExtRows; i++){
                curL=Ls[i-1];
                if(i==1 || (i>1 && curL<minL)){
                    minL=curL;
                }
                if(i==1 || (i>1 && curL>maxL)){
                    maxL=curL;
                }
            }
            return minL;
        }
        int Array2DSizeVarLenV::GetMaxLength()const{
            int L=0, minL, maxL, curL, QExtRows=this->GetQExtRows();
            for(int i=1; i<=QExtRows; i++){
                curL=Ls[i-1];
                if(i==1 || (i>1 && curL<minL)){
                    minL=curL;
                }
                if(i==1 || (i>1 && curL>maxL)){
                    maxL=curL;
                }
            }
            return maxL;
        }
        void Array2DSizeVarLenV::SwapExtRows(int N1, int N2){
            int buf, QExtRows=this->GetQExtRows();
            if(N1>=1 && N1<=QExtRows && N2>=1 && N2<=QExtRows){
                buf=this->Ls[N1-1];
                this->Ls[N1-1]=this->Ls[N2-1];
                this->Ls[N2-1]=buf;
            }
        }
        void Array2DSizeVarLenV::Reverse(){
            Array1DReverse(this->Ls);
        }
        //virtual void SetQExtRows(int N);
        //virtual void SetIneRowsLength(int L_Minus1MinMinus2Max=-1, bool preserveTypeIfVaria=false);
        //virtual void SetLength(int L, int N_0ToAllPreserveType_GTT0AndMakeVaria_Minus1ToAllMakeNotVaria=0);
        void Array2DSizeVarLenV::SetLength(int L, int N){
            int QExtRows=this->GetQExtRows();
            if(N<0){
                N=QExtRows+N+1;
            }
            if(N>=1 && N<=QExtRows){
                this->Ls[N-1]=L;
            }else if(N==0){
                for(int i=1; i<=QExtRows; i++){
                    this->Ls[i-1]=L;
                }
            }
        }
        QString Array2DSizeVarLenV::GetAsQString(QString delim)const{
           QString s, sn;
           int QExtRows=this->GetQExtRows();
           sn.setNum(QExtRows);
           s="Size: "+sn+": [";
           for(int i=1; i<=QExtRows-1; i++){
              sn.setNum(this->Ls[i-1]);
              s+=sn;
              s+=delim;
           }
           sn.setNum(this->Ls[QExtRows-1]);
           s+=sn;
           s+="]";
           return s;
        }
        std::string Array2DSizeVarLenV::GetAsStdString(std::string delim) const{
            QString qsd=QString(delim.c_str());
            QString qs=this->GetAsQString(qsd);
            std::string ss=qs.toStdString();
            return ss;
        }
        void  Array2DSizeVarLenV::ShowToConsole() const{
            std::string ss=this->GetAsStdString();
            std::cout<<ss;
        }
        //virtual bool isSame(const Array2DSizeVarLenV&obj)const;
        bool Array2DSizeVarLenV::isSame(Array2DSizeVarLenV*obj)const{
            bool b;
            int QExtRows=this->GetQExtRows();
            b=(this->GetQExtRows()==obj->GetQExtRows());
            if(b){
                for(int i=1; i<=QExtRows; i++){
                    if(this->Ls[i-1]!=obj->Ls[i-1]){
                        b=false;
                    }
                }
            }
            return b;
        }
        int Array2DSizeVarLenV::GetIneRowsLength()const{ return this->GetLength(0); }
        int Array2DSizeVarLenV::LengthFullOfIneRowN(int IneRowN) const{//from start to 1st stop
            int count, QExtRows=this->GetQExtRows(), Lmax=this->GetMaxLength(), Lcur, N=0;
            bool breakreached=false, contin=(N>=1 && N<=Lmax);
            while(contin){
                N++;
                Lcur=this->GetLength(N);
                if(Lcur>=IneRowN){
                    if(breakreached==false){
                        count++;
                    }else{
                        count=0;
                        contin=false;
                    }
                }else{
                    breakreached=true;
                }
            }
            return count;
        }
        bool  Array2DSizeVarLenV::IsForTranspose() const{
            bool b=true;
            int count, QExtRows=this->GetQExtRows(), Lmax=this->GetMaxLength(), Lcur, Lnxt, N=0;
            for(int i=1; i<=QExtRows-1; i++){
                Lcur=this->LengthFullOfIneRowN(i);
                Lnxt=this->LengthFullOfIneRowN(i+1);
                if(Lcur>Lnxt){
                    b=false;
                }
            }
            return b;
        }
        void Array2DSizeVarLenV::Transpose(){
            int*Ls=NULL, Lmax=this->GetMaxLength();
            if(this->IsForTranspose()){
                Ls=new int[Lmax];
                for(int i=1; i<=Lmax; i++){
                    Ls[i-1]=this->LengthFullOfIneRowN(i);
                }
                this->Set(Lmax, Ls);
            }
        }
    //};


//class Array2DSizeRect: public Array2DSizePrototype
//{
//    int QExtRows;
//    int ExtRowLength;
//public:
    //virtual Array2DSize();
        Array2DSizeRect::Array2DSizeRect(int QExtRows, int ExtRowsLength){// : Array2DSizePrototype(QExtRows, ExtRowsLength){
            this->Construct();
            this->Set(QExtRows, ExtRowsLength);
        }
        Array2DSizeRect::Array2DSizeRect(int QExtRows, int*Ls){// : Array2DSizePrototype(QExtRows, Ls){
            this->Construct();
            this->Set(QExtRows, Ls[1-1]);
        }
        Array2DSizeRect::Array2DSizeRect(std::vector<int>Ls){// : Array2DSizePrototype(Ls) {
            this->Construct();
            if(Ls.size()>0){
                this->Set(QExtRows, Ls[1-1]);
            }
        }
        //Array2DSizeRect operator =(const Array2DSizePrototype&obj);
        //Array2DSizeRect* Array2DSizeRect::clone() const {
        //    return this;
        //}
        Array2DSizeRect::~Array2DSizeRect(){}
        //virtual void Assign(const Array2DSizePrototype&obj);//I men no not ob in dyn polymorf S nablb realf'd
        void Array2DSizeRect::Assign(Array2DSizeRect*obj){//I hope ce abls ob Array2DSizeRect s'heir of Array2DSizePrototype]
            this->SetNull();
            this->Set(obj->QExtRows, obj->ExtRowLength);
        }
        void Array2DSizeRect::Construct(){
            this->SetNull();
        }

        void Array2DSizeRect::SetNull(){
            this->QExtRows=0;
            this->ExtRowLength=0;
        }
        //
        bool Array2DSizeRect::IsRectangularType() const{
            return true;
        }
        bool Array2DSizeRect::IsVariableLengthType() const{
            return false;
        }
        bool Array2DSizeRect::IsRectangularFact() const{
            int Lmin=this->GetMinLength(), Lmax=this->GetMaxLength();
            return (Lmin==Lmax);
        }
        bool Array2DSizeRect::IsVariableLengthFact() const{
            int Lmin=this->GetMinLength(), Lmax=this->GetMaxLength();
            return (Lmin!=Lmax);
        }
        //
        //virtual void SetVaria();
        //virtual void SetRectangular(int L_ifVaria_min_m1_max_less=-2);
        //
        void Array2DSizeRect::SetOne(){
            this->SetNull();
            this->Set(1, 1);
        }
        bool Array2DSizeRect::ExtRowNBelongsTo(int extRowN)const{
            bool verdict;
            verdict=(extRowN>=1 && extRowN<=this->GetQExtRows());
            return verdict;
        }
        bool Array2DSizeRect::PosBelongsTo(int extRowN, int ineRowN){
            int L;
            bool b;
            b=(this->ExtRowNBelongsTo(extRowN));
            if(b){
               L=this->ExtRowLength;
               b=(ineRowN>=1 && ineRowN<=L);
            }
            return b;
        }
        void Array2DSizeRect::Set(int QExtRows, int ExtRowLength){
            this->QExtRows=QExtRows;
            this->ExtRowLength=ExtRowLength;
        }
        void Array2DSizeRect::Set(int QExtRows, int*Ls){
            this->QExtRows=QExtRows;
            if(Ls!=NULL){
                this->ExtRowLength=Ls[1-1];
            }
        }
        void Array2DSizeRect::Set(std::vector<int>Ls){
            this->QExtRows=Ls.size();
            if(this->QExtRows>0){
                this->ExtRowLength=Ls[1-1];
            }else{
                this->ExtRowLength=0;
            }
        }
        //virtual void Set1ExtRowVaria(int L);
        //virtual void SetVaria(int QExtRows, int IneRowsLength);
        //virtual void ConvertToRectIfAllLengthesAreEqual();
        //virtual void Add(int L, int ifConstAndNotEqual_Ignore0AddExisting1SetAll2=2);
        //virtual void Ins(int N, int L);
        void Array2DSizeRect::AddExt(int L){
            this->ExtRowLength++;
        }
        void  Array2DSizeRect::InsExt(int N, int L){
            this->ExtRowLength++;
        }
        void Array2DSizeRect::DelExt(int N){
            this->ExtRowLength--;
        }
        void Array2DSizeRect::DelIneRow(){
            this->ExtRowLength--;
        }
        void Array2DSizeRect::AddOrInsIneRow(){
             this->ExtRowLength++;
        }
        //virtual void AddOrInsTo(int L=0, int N_0ToAllPreserveType_GTT0AndMakeVaria=0);
        //virtual void DelFrom(int L, int N_0ToAllPreserveType_GTT0AndMakeVaria=0);
        void Array2DSizeRect::AddOrInsTo(int N, int L){
            //NOp;
        }
        void Array2DSizeRect::DelFrom(int N, int L){
            //NOp;
        }
        int Array2DSizeRect::GetQExtRows() const{
            return this->QExtRows;
        }
        //virtual bool GetIfIsVariaLength() const;
        //virtual bool Array2DSizeRect::isVariaLength() const{return true; }
        //virtual bool isRectangular() const;
        int Array2DSizeRect::GetLength(int N) const{
            return this->ExtRowLength;
        }
        int Array2DSizeRect::GetMinLength()const{
            return this->ExtRowLength;
        }
        int Array2DSizeRect::GetMaxLength()const{
            return this->ExtRowLength;
        }
        void Array2DSizeRect::SwapExtRows(int N1, int N2){
            //NOp;
        }
        void Array2DSizeRect::Reverse(){
            //NOp;
        }
        //virtual void SetQExtRows(int N);
        //virtual void SetIneRowsLength(int L_Minus1MinMinus2Max=-1, bool preserveTypeIfVaria=false);
        //virtual void SetLength(int L, int N_0ToAllPreserveType_GTT0AndMakeVaria_Minus1ToAllMakeNotVaria=0);
        void Array2DSizeRect::SetLength(int L, int N){
            this->ExtRowLength=L;
        }
        QString Array2DSizeRect::GetAsQString(QString delim)const{
           QString s, sn;
           int QExtRows=this->GetQExtRows();
           sn.setNum(QExtRows);
           s="Size: E="+sn+" x I=";

           sn.setNum(this->ExtRowLength);
           s+=sn;
           return s;
        }
        std::string Array2DSizeRect::GetAsStdString(std::string delim) const{
            QString qsd=QString(delim.c_str());
            QString qs=this->GetAsQString(qsd);
            std::string ss=qs.toStdString();
            return ss;
        }
        void  Array2DSizeRect::ShowToConsole() const{
            std::string ss=this->GetAsStdString();
            std::cout<<ss;
        }
        //virtual bool isSame(const Array2DSizeRect&obj)const;
        bool Array2DSizeRect::isSame(Array2DSizeRect*obj)const{
            return (this->QExtRows == obj->QExtRows && this->ExtRowLength == obj->ExtRowLength);
        }
        int Array2DSizeRect::GetIneRowsLength()const{ return this->GetLength(0); }
        int Array2DSizeRect::LengthFullOfIneRowN(int IneRowN) const{//from start to 1st stop
            return this->QExtRows;
        }
        bool  Array2DSizeRect::IsForTranspose() const{
            return true;
        }
        void Array2DSizeRect::Transpose(){
            this->Set(this->ExtRowLength, this->QExtRows);
        }
    //};
//};




//class Array2DSizeDPS //Dynamic Polymorph Shell
//{
//    Array2DSizePrototype*size;
//public:
    //virtual Array2DSize();
        Array2DSizeDPS::Array2DSizeDPS(int QExtRows, int ExtRowsLength, bool isNotVaria){
            if(isNotVaria){
                this->size=new Array2DSizeRect(QExtRows, ExtRowsLength);
            }else{
                this->size=new Array2DSizeVarLenV(QExtRows, ExtRowsLength);
            }
            this->size=new Array2DSizeVarLenP(QExtRows, ExtRowsLength);
        }

        Array2DSizeDPS::Array2DSizeDPS(int QExtRows, int*Ls, bool RectIfAllSame){
            int Lmin, Lmax, Lcur;
            for(int i=1; i<=QExtRows; i++){
                if(i==1 || (i>1 && Lcur<Lmin)){
                    Lmin=Lcur;
                }
                if(i==1 || (i>1 && Lcur<Lmax)){
                    Lmax=Lcur;
                }
            }
            if(Lmin==Lmax && RectIfAllSame){
                this->size=new Array2DSizeRect(QExtRows, Lmax);
            }else{
                this->size=new Array2DSizeVarLenP(QExtRows, Ls);
            }
        }
        Array2DSizeDPS::Array2DSizeDPS(std::vector<int>Ls, bool RectIfAllSame){
            int QExtRows=Ls.size(), Lmin, Lmax, Lcur;
            for(int i=1; i<=QExtRows; i++){
                if(i==1 || (i>1 && Lcur<Lmin)){
                    Lmin=Lcur;
                }
                if(i==1 || (i>1 && Lcur<Lmax)){
                    Lmax=Lcur;
                }
            }
            if(Lmin==Lmax && RectIfAllSame){
                this->size=new Array2DSizeRect(QExtRows, Lmax);
            }else{
                this->size=new Array2DSizeVarLenV(Ls);
            }
        }
        Array2DSizeDPS::Array2DSizeDPS(const Array2DSizeDPS&obj){
            this->SetNull();
            this->Assign(obj);
        }

        Array2DSizeDPS::~Array2DSizeDPS(){
            delete this->size;
        }

        void Array2DSizeDPS::Assign(const Array2DSizeDPS&obj){
            this->size=obj.size->clone();
        }

        Array2DSizeDPS& Array2DSizeDPS::operator =(const Array2DSizeDPS&obj){
            this->Assign(obj);
            return*this;
        }

        //void Array2DSizeDPS::Construct(){}

        void Array2DSizeDPS::SetNull(){
            this->size->SetNull();
        }

        //
        bool Array2DSizeDPS::IsRectangularType()const{
            return this->size->IsRectangularType();
        }
        bool Array2DSizeDPS::IsRectangularFact()const{
             return this->size->IsRectangularFact();
        }
        bool Array2DSizeDPS::IsVariableLengthType()const{
            return this->size->IsVariableLengthType();
        }
        //bool Array2DSizeDPS::IsVariableLenghFact()const{
        //    return this->size->IsVariableLenghFact();
        //}
        //
        //virtual void SetVaria();
        //virtual void SetRectangular(int L_ifVaria_min_m1_max_less=-2);
        //
        void Array2DSizeDPS::SetOne(bool isVaria){
            this->size->SetOne();
        }
        bool Array2DSizeDPS::ExtRowNBelongsTo(int extRowN)const{
            return this->size->ExtRowNBelongsTo(extRowN);
        }
        bool Array2DSizeDPS::PosBelongsTo(int extRowN, int ineRowN){
            return this->size->PosBelongsTo(extRowN, ineRowN);
        }
        void Array2DSizeDPS::Set(int QExtRows, int ExtRowsLength, bool PreserveType){
            if(this->size->IsRectangularType()==false && PreserveType==false){
                delete this->size;
                this->size=new Array2DSizeVarLenV(QExtRows, ExtRowsLength);
            }else{
                this->size->Set(QExtRows, ExtRowsLength);
            }
        }
        void Array2DSizeDPS::Set(int QExtRows,int*Ls, bool RectIfAllSame){
            int Lmin, Lmax, Lcur;
            if(Ls!=NULL){
                for(int i=1; i<=QExtRows; i++){
                    Lcur=Ls[i-1];
                    if(i==1 || (i>1 && Lcur<Lmin)){
                        Lmin=Lcur;
                    }
                    if(i==1 || (i>1 && Lcur>Lmax)){
                        Lmax=Lcur;
                    }
                }
                if(Lmin==Lmax && this->size->IsRectangularType()==false){
                    delete this->size;
                    this->size=new Array2DSizeRect(QExtRows, Lmax);
                }else{
                    this->size->Set(QExtRows, Ls);
                }
            }
        }

        //void Add(int L, int ifConstAndNotEqual_Ignore0AddExisting1SetAll2=2);
        //void Ins(int N, int L);
        void Array2DSizeDPS::AddExt(int L){
            this->size->AddExt(L);
        }

        void Array2DSizeDPS::InsExt(int N, int L){
            this->size->InsExt(N, L);
        }
        void Array2DSizeDPS::DelExt(int N){
            this->size->DelExt(N);
        }
        void Array2DSizeDPS::DelIneRow(){ this->size->DelIneRow(); }
        void Array2DSizeDPS::AddOrInsIneRow(){ this->size->AddOrInsIneRow(); }
        //virtual void AddOrInsTo(int L=0, int N_0ToAllPreserveType_GTT0AndMakeVaria=0);
        //virtual void DelFrom(int L, int N_0ToAllPreserveType_GTT0AndMakeVaria=0);
        void Array2DSizeDPS::AddOrInsTo(int N, int L){ this->size->AddOrInsTo(N, L); }
        void Array2DSizeDPS::DelFrom(int N, int L){ this->size->DelFrom(N, L); }
        int Array2DSizeDPS::GetQExtRows() const { return this->size->GetQExtRows(); }
        //bool GetIfIsVariaLength() const;
        //bool isVariaLength();
        //bool isRectangular() const;
        int Array2DSizeDPS::GetLength(int N)const { return this->size->GetLength(N); }
        int Array2DSizeDPS::GetMinLength()const { return this->size->GetMinLength(); }
        int Array2DSizeDPS::GetMaxLength()const { return this->size->GetMaxLength(); }
        void Array2DSizeDPS::SwapExtRows(int N1, int N2) { return this->size->SwapExtRows(N1, N2); }
        void Array2DSizeDPS::Reverse() { this->size->Reverse(); }
        //void Array2DSizeDPS::SetQExtRows(int N) { this->size->SetQExtRows(N); }
        //void Array2DSizeDPS::SetIneRowsLength(int L_MinMinus1MaxLess, bool preserveTypeIfVaria){
        //    int QExtRows=this->GetQExtRows();
        //    if(L_MinMinus1MaxLess==-1){
        //        L_MinMinus1MaxLess=this->size->GetMinLength();
        //    }else if(L_MinM1MaxLess<0){
        //        L_MinMinus1MaxLess=this->size->GetMaxLength();
        //    }
        //    if(preserveTypeIfVaria=false && this->size->IsRectangularType()==false){
        //        delete this->size;
        //        this->size=new Array2DSizeRect(QExtRows, L_MinMinus1MaxLess);
        //    }else{
        //        this->size->Set(QExtRows, L_MinMinus1MaxLess);
        //    }
        //}
        //void SetLength(int L, int N_0ToAllPreserveType_GTT0AndMakeVaria_Minus1ToAllMakeNotVaria=0);
        void Array2DSizeDPS::SetLength(int L, int N){ this->size->SetLength(L, N); }

        QString Array2DSizeDPS::GetAsQString(QString delim)const{
            return this->size->GetAsQString(delim);
        }
        std::string Array2DSizeDPS::GetAsStdString(std::string delim) const{
            return this->size->GetAsStdString(delim);
        }
        void Array2DSizeDPS::ShowToConsole() const{ this->size->ShowToConsole(); }
        //bool Array2DSizeDPS::isSame(const Array2DSizeDPS&obj)const;
        int Array2DSizeDPS::GetIneRowsLength(bool EvenIfVarButAllEqual)const{
            int L;
            if(this->size->IsRectangularType()==false && (EvenIfVarButAllEqual==false || this->size->IsRectangularFact()==false)){
                L=0;
            }else{
                L=this->size->GetLength(0);
            }
            return L;
        }
        //
        int Array2DSizeDPS::LengthFullOfIneRowN(int N) const{//from start to 1st stop
            return this->size->LengthFullOfIneRowN(N);
        }
        bool Array2DSizeDPS::IsForTranspose() const { return this->size->IsForTranspose(); }
        void Array2DSizeDPS::Transpose() { this->size->Transpose(); }
        //
        void Array2DSizeDPS::Set1ExtRowVaria(int L){
            std::vector<int>Ls;
            delete this->size;
            Ls.push_back(L);
            this->size=new Array2DSizeVarLenV(Ls);
        }

        void Array2DSizeDPS::SetVectorPotentiallyVaria(int Q){
            std::vector<int>Ls;
            delete this->size;
            for(int i=1; i<=Q; i++){
                Ls.push_back(1);
            }
            this->size=new Array2DSizeVarLenV(Ls);
        }
        void Array2DSizeDPS::SetVaria(int QExtRows, int ExtRowsLength){
            std::vector<int>Ls;
            delete this->size;
            for(int i=1; i<=QExtRows; i++){
                Ls.push_back(ExtRowsLength);
            }
            this->size=new Array2DSizeVarLenV(Ls);
        }
        void Array2DSizeDPS::ConvertToRectIfAllLengthesAreEqual(){
            int Q=this->GetQExtRows(), L=this->GetMaxLength();
            if(this->size->IsRectangularType()==false && this->size->IsRectangularFact()==true){
                delete this->size;
                this->size=new Array2DSizeRect(Q, L);
            }
        }

        void Array2DSizeDPS::ConvertToRect(int L_ifVaria_min_m1_max_less){
            int Q=this->GetQExtRows();
            if(L_ifVaria_min_m1_max_less==-1){
                L_ifVaria_min_m1_max_less=this->size->GetMinLength();
            }else if(L_ifVaria_min_m1_max_less<0){
                L_ifVaria_min_m1_max_less=this->size->GetMaxLength();
            }
            delete this->size;
            this->size=new Array2DSizeRect(Q, L_ifVaria_min_m1_max_less);
        }
        void Array2DSizeDPS::ConvertToVaria(){
            std::vector<int>Ls;
            int QExtRows=this->size->GetQExtRows(), ExtRowsLength=this->size->GetLength(0);
            if(this->size->IsRectangularType()==false){
                for(int i=1; i<=QExtRows; i++){
                    Ls.push_back(ExtRowsLength);
                }
                delete this->size;
                this->size=new Array2DSizeVarLenV(Ls);
            }
        }

//};

 */


//=======================================================================================================

// ------------------------------------------------------------------------------------------------------

int CalcElementNIfNegativeOf(int N, int Q){
    int y=N;
    if(N<0){
        y=N+Q;
    }
    return y;
}


//===================================================================================================

//===================================================================================================

/*
//class Matrix_P{
//    Array2D_PS<double>data;
//public:
    Matrix_P::Matrix_P(int QLines, int QColumns, double**X){
        double*DefaultDouble=new double;
        (*(DefaultDouble))=0;
        this->data.Set(QLines, QColumns, true, X, DefaultDouble);
        delete DefaultDouble;
        //wi checked et appended by Set
    }

    Matrix_P::Matrix_P(std::vector<std::vector<double>>X){
        this->data.Set(X);//X, true, ics'dflt
    }

    Matrix_P::Matrix_P(int Q, double*X, bool VectNotLine){
        this->data.Set(Q, VectNotLine, X);//,true
    }

    Matrix_P::Matrix_P(std::vector<double>X, bool VectNotLine){
        this->data.Set(X, VectNotLine);//true
    }

    Matrix_P::Matrix_P(const Matrix_P& obj){

    }

    Matrix_P::~Matrix_P(){}

    void Matrix_P::Assign(const Matrix_P& obj){
        this->data=obj.data;
    }

    Matrix_P& Matrix_P::operator = (const Matrix_P& obj){
        this->Assign(obj);
        return *this;
    }

    void Matrix_P::SetSize(int QLines, int QColumns){
        double*DefaultDouble=new double;
        (*(DefaultDouble))=0;
        this->data.SetSize(QLines, QColumns, true, DefaultDouble);
        delete DefaultDouble;
    }

    int Matrix_P::GetQLines(){
        return this->data.GetQExtRows();
    }

    int Matrix_P::GetQColumns(){
        return this->data.GetLength(1);
    }

    void Matrix_P::Set(int QLines, int QColumns, double**X){
        double*DefaultDouble=new double;
        (*(DefaultDouble))=0;
        this->data.Set(QLines, QColumns, true, X, DefaultDouble);
        delete DefaultDouble;
    }

    void Matrix_P::Set(std::vector<std::vector<double>>X){
        this->data.Set(X);//true
        //append it with stretching!
    }

    void Matrix_P::Set(int Q, double*X, bool VectNotLine){
        double*DefaultDouble=new double;
        (*(DefaultDouble))=0;
        this->data.Set(Q, VectNotLine, X);//rect=true, defaultVal n'ved qut
        delete DefaultDouble;
    }

    void Matrix_P::Set(std::vector<double>X, bool VectNotLine){
        this->data.Set(X, VectNotLine);//,rect=true)
    }

    std::vector<double> Matrix_P::GetLineN(int LineN){

    }

    std::vector<double> Matrix_P::GetColumnN(int LineN){

    }

    double Matrix_P::GetElement(int LineN, int ColumnN){

    }

    void Matrix_P::SetElement(double x, int LineN, int ColumnN){

    }

//};

//class Matrix_V{
//    Array2D_V<double>data;
//public:
    Matrix_V::Matrix_V(int QLines, int QColumns, double**X){

    }

    Matrix_V::Matrix_V(std::vector<std::vector<double>>X){

    }

    Matrix_V::Matrix_V(int Q, double*X, bool VectNotLine){

    }

    Matrix_V::Matrix_V(std::vector<double>X, bool VectNotLine){

    }

    Matrix_V::Matrix_V(const Matrix_V& obj){

    }

    Matrix_V::~Matrix_V(){}

    void Matrix_V::Assign(const Matrix_V& obj){

    }

    Matrix_V& Matrix_V::operator = (const Matrix_V& obj){

    }

    void Matrix_V::SetSize(int QLines, int QColumns){

    }

    int Matrix_V::GetQLines(){

    }

    int Matrix_V::GetQColumns(){

    }

    void Matrix_V::Set(int QLines, int QColumns, double**X){

    }

    void Matrix_V::Set(std::vector<std::vector<double>>X){

    }

    void Matrix_V::Set(int Q, double*X, bool VectNotLine){

    }

    void Matrix_V::Set(std::vector<double>X, bool VectNotLinee){

    }

    std::vector<double> Matrix_V::GetLineN(int LineN){

    }

    std::vector<double> Matrix_V::GetColumnN(int LineN){

    }

    double Matrix_V::GetElement(int LineN, int ColumnN){

    }

    void Matrix_V::SetElement(double x, int LineN, int ColumnN){

    }
    */

//};


//========================================================================================

//========================================================================================

Array2D_OfInt_ForTest::Array2D_OfInt_ForTest(int TypeN){
    this->construct(TypeN);
    this->SetNull();
}
 Array2D_OfInt_ForTest::Array2D_OfInt_ForTest(int**arr, const Array2DSize& size, int TypeN){
    this->construct(TypeN);
    this->Set(arr, size, true, TypeN);
}
 Array2D_OfInt_ForTest::Array2D_OfInt_ForTest(int**arr, int QExtRows, int IneRowsLength, int TypeN){
    this->construct(TypeN);
    this->Set(arr, QExtRows, IneRowsLength);//, true, TypeN);
}
// TTest2DArray::TTest2DArray(int**arr, int QExtRows, int*IneRowsLengthes, int TypeN){
//    this->construct(TypeN);
//    this->Set(arr, QExtRows, IneRowsLengthes);//, true, TypeN);
//}
Array2D_OfInt_ForTest::Array2D_OfInt_ForTest(int**arr, std::vector<int>IneRowsLengthes, int TypeN){
    this->construct(TypeN);
    this->Set(arr, IneRowsLengthes);//, true, TypeN);
}
Array2D_OfInt_ForTest::Array2D_OfInt_ForTest(int*arr, const Array2DSize& size, int TypeN){
    this->construct(TypeN);
    this->Set(arr, size);//, true, TypeN);
}
Array2D_OfInt_ForTest::Array2D_OfInt_ForTest(int*arr, int QExtRows, int IneRowsLength, int TypeN){
    this->construct(TypeN);
    this->Set(arr, QExtRows, IneRowsLength);//, true, TypeN);
}
//TTest2DArray::TTest2DArray(int*arr, int QExtRows, int*IneRowsLengthes, int TypeN){
//    this->construct(TypeN);
//    this->Set(arr, QExtRows, IneRowsLengthes);//, true, TypeN);
//}
Array2D_OfInt_ForTest::Array2D_OfInt_ForTest(int*arr, std::vector<int>IneRowsLengthes, int TypeN){
    this->construct(TypeN);
    this->Set(arr, IneRowsLengthes);//, true, TypeN);
}
Array2D_OfInt_ForTest::Array2D_OfInt_ForTest(std::vector<int>arr, const Array2DSize& size, int TypeN){
    this->construct(TypeN);
    this->Set(arr, size);//, true, TypeN);
}
Array2D_OfInt_ForTest::Array2D_OfInt_ForTest(std::vector<int>arr, int QExtRows, int IneRowsLength, int TypeN){
    this->construct(TypeN);
    this->Set(arr, QExtRows, IneRowsLength);//, true, TypeN);
}
//TTest2DArray::TTest2DArray(std::vector<int>arr, int QExtRows, int*IneRowsLengthes, int TypeN){
//    this->construct(TypeN);
//    this->Set(arr, QExtRows, IneRowsLengthes);//, true, TypeN);
//}
Array2D_OfInt_ForTest::Array2D_OfInt_ForTest(std::vector<int>arr, std::vector<int>IneRowsLengthes, int TypeN){
    this->construct(TypeN);
    this->Set(arr, IneRowsLengthes);//, true, TypeN);
}
Array2D_OfInt_ForTest::Array2D_OfInt_ForTest(std::vector<std::vector<int>>arr, int TypeN){
    this->construct(TypeN);
    this->Set(arr);//, true, TypeN);
}
Array2D_OfInt_ForTest::Array2D_OfInt_ForTest(int DefaulVal, const Array2DSize& size, int TypeN){
    this->construct(TypeN);
    this->Set(DefaulVal, size);//, true, TypeN);
}
Array2D_OfInt_ForTest::Array2D_OfInt_ForTest(int DefaulVal, int QExtRows, int IneRowsLength, int TypeN){
    this->construct(TypeN);
    Array2DSize size(QExtRows, IneRowsLength);
    this->Set(DefaulVal, size);//, true, TypeN);
}
//TTest2DArray::TTest2DArray(const int& DefaulVal, int QExtRows, int*IneRowsLengthes, int TypeN){
//    this->construct(TypeN);
//    Array2DSize size;
//    size.Set(QExtRows, IneRowsLengthes);
//    this->Set(DefaulVal, size);//, true, TypeN);
//}
Array2D_OfInt_ForTest::Array2D_OfInt_ForTest(int DefaulVal, std::vector<int>IneRowsLengthes, int TypeN){
    this->construct(TypeN);
    Array2DSize size;
    size.Set(IneRowsLengthes.size(), IneRowsLengthes.data());
    this->Set(DefaulVal, size);//, true, TypeN);
}
//
//TTest2DArray::TTest2DArray(Array2D_Prototype<int>*obj){
//    int TypeN=obj->GetTypeN();
//    std::vector<int>arr=obj->GetContent_AsArray1D();
//    Array2DSize size=obj->GetSize();
//    this->construct(obj->GetTypeN());
//    this->Set(arr, size);
//}
//TTest2DArray::TTest2DArray(const Array2D_V1L<int>&obj){
//    int TypeN=Array2D_TypeN_V1L;
//    std::vector<int>arr=obj.GetContent_AsArray1D();
//    Array2DSize size=obj.GetSize();
//    this->construct(obj.GetTypeN());
//    this->Set(arr, size);
//}
//TTest2DArray::TTest2DArray(const Array2D_P1L<int>&obj){
//    int TypeN=Array2D_TypeN_P1L;
//    std::vector<int>arr=obj.GetContent_AsArray1D();
//    Array2DSize size=obj.GetSize();
//    this->construct(obj.GetTypeN());
//    this->Set(arr, size);
//}
//
Array2D_OfInt_ForTest::Array2D_OfInt_ForTest(const Array2D_OfInt_ForTest&obj){
    int TypeN=obj.GetTypeN();
    std::vector<int>arr=obj.GetContent_AsArray1D();
    Array2DSize size=obj.GetSize();
    this->construct(obj.GetTypeN());
    this->Set(arr, size);
}
//
 Array2D_OfInt_ForTest::~Array2D_OfInt_ForTest(){
    this->data.SetNull();
    //delete this->data;
}
//
// void Array2D_shell:: Assign(Array2D_Prototype<int>*obj){
//    int TypeN=obj->GetTypeN();
//    std::vector<int>arr=obj->GetContent_AsArray1D();
//    Array2DSize size=obj->GetSize();
//    this->construct(obj->GetTypeN());
//    this->Set(arr, size);
//}
//
// void Array2D_shell:: Assign(const Array2D_V1L<int>&obj){
//    int TypeN=Array2D_TypeN_V1L;
//    std::vector<int>arr=obj.GetContent_AsArray1D();
//    Array2DSize size=obj.GetSize();
//    this->construct(obj.GetTypeN());
//    this->Set(arr, size);
//}
// void Array2D_shell:: Assign(const Array2D_P1L<int>&obj){
//    int TypeN=Array2D_TypeN_P1L;
//    std::vector<int>arr=obj.GetContent_AsArray1D();
//    Array2DSize size=obj.GetSize();
//    this->construct(obj.GetTypeN());
//    this->Set(arr, size);
//}
//
 void Array2D_OfInt_ForTest:: Assign(const Array2D_OfInt_ForTest&obj){
    int TypeN=obj.GetTypeN();
    std::vector<int>arr=obj.GetContent_AsArray1D();
    Array2DSize size=obj.GetSize();
    this->construct(obj.GetTypeN());
    this->Set(arr, size);
}
//
// Array2D_shell& Array2D_shell::operator = (const Array2D_V1L<int>&obj){
//    this->Assign(obj);
//    return *this;
//}
// Array2D_shell&  Array2D_shell::operator = (const Array2D_P1L<int>&obj){
//    this->Assign(obj);
//    return *this;
//}
//
 Array2D_OfInt_ForTest&  Array2D_OfInt_ForTest::operator = (const Array2D_OfInt_ForTest&obj){
    this->Assign(obj);
    return *this;
}
//
 void Array2D_OfInt_ForTest::SetTypeN(int TypeN){
    std::vector<int>arr=this->GetContent_AsArray1D();
    Array2DSize size=this->GetSize();
    bool isEmpty=(size.GetQExtRows()==0);
    this->data.SetNull();
    //delete this->data;
    this->construct(TypeN);
    this->Set(arr, size);
}
//
//virtual void SetNull()=0;
 void Array2D_OfInt_ForTest::SetNull(){
    this->data.SetNull();
}
void Array2D_OfInt_ForTest::construct(int TypeN){
    switch(TypeN){
        case Array2D_TypeN_V1L:
            this->data=new Array2D_V1L<int>();
        break;
        case Array2D_TypeN_P1L:
            this->data=new Array2D_P1L<int>();
        break;
    }
}
//virtual Array2D_Prototype* CreateArray() const=0;
//Array2D_Prototype* TTest2DArray::CreateArray() const{
//    return this->data->CreateArray();
//}
//Array2D_Prototype<int>* TTest2DArray::GetData(int TypeNParam) const{
//    int TypeNWas=this->GetTypeN;
//    Array2D_Prototype<int>*ptr;
//    std::vector<int>arr=this->GetContent_AsArray1D();
//    Array2DSize size=this->GetSize();
//    if(TypeNParam==0 || TyprNParam==TypeNWas){
//        ptr=this->data;
//    }else{
//        switch(TypeNParam){
//            case Array2D_TypeN_V1L:
//                ptr=new Array2D_V1L(arr, size);
//            break;
//            case Array2D_TypeN_P1L:
//                ptr=new Array2D_P1L(arr, size);
//            break;
//        }
//    }
//    return ptr;
//}
//Array2D_Prototype<int>* TTest2DArray::GetData() const{
//    return this->data;
//}
Array2D_Prototype<int>* Array2D_OfInt_ForTest::GetData(int TypeNParam) const{
    //int TypeNWas=this->GetTypeN;
    Array2D_Prototype<int>*ptr;
    std::vector<int>arr=this->GetContent_AsArray1D();
    Array2DSize size=this->GetSize();
    switch(TypeNParam){
        case Array2D_TypeN_V1L:
            ptr=new Array2D_V1L<int>(arr, size);//amda n'wa <int>, rt S ecri err: expected ; af Array2D_V1L
        break;
        case Array2D_TypeN_P1L:
            ptr=new Array2D_P1L<int>(arr, size);
        break;
    }
    return ptr;
}
//virtual Array2D_Prototype* clone() const=0;
//Array2D_Prototype<int>* TTest2DArray::clone() const{
//    return this->data->clone();
//}
//virtual int GetTypeN() const=0;
int Array2D_OfInt_ForTest::GetTypeN() const{
    return this->data.GetTypeN();
}
//
void Array2D_OfInt_ForTest::SetOne(int*DfltVal){
    this->data.SetOne(DfltVal);
}
void Array2D_OfInt_ForTest::SetOne(const int&DfltVal){
    this->data.SetOne(DfltVal);
}
//
void Array2D_OfInt_ForTest::SetSize(const int& DefaultVal, const Array2DSize&size){
    this->data.SetSize(DefaultVal, size);
}
//
void Array2D_OfInt_ForTest::SetSize(const Array2DSize&size, int*DfltValParam){
    this->data.SetSize(size, DfltValParam);
}
void Array2D_OfInt_ForTest::SetSize(int QExtRows, int ExtRowsLength, int*DfltValParam){
    this->data.SetSize(QExtRows, ExtRowsLength, DfltValParam);
}
//void TTest2DArray::SetSize(int QExtRows, int*ExtRowsLengthes, int*DfltValParam){
//    this->data.SetSize(QExtRows, ExtRowsLengthes, DfltValParam);
//}
void Array2D_OfInt_ForTest::SetSize(std::vector<int>ExtRowsLengthes, int*DfltValParam){
    this->data.SetSize(ExtRowsLengthes, DfltValParam);
}
//
void Array2D_OfInt_ForTest::SetSize(const int& DfltValParam, int QExtRows, int ExtRowsLength){
    this->data.SetSize(DfltValParam, QExtRows, ExtRowsLength);
}
//void TTest2DArray::SetSize(const int& DfltValParam, int QExtRows, int*ExtRowsLengthes){
//    this->data.SetSize(DfltValParam, QExtRows, ExtRowsLengthes);
//}
void Array2D_OfInt_ForTest::SetSize(const int& DfltValParam, std::vector<int>Lengthes){
    this->data.SetSize(DfltValParam, Lengthes);
}
//
//virtual int GetQExtRows() const=0;
int Array2D_OfInt_ForTest::GetQExtRows() const{
    return this->data.GetQExtRows();
}
//virtual int GetLength(int ExtRowN=1) const=0;
int Array2D_OfInt_ForTest::GetLength(int ExtRowN)const{
    return this->data.GetLength(ExtRowN);
}
//virtual int GetMinLength() const=0;
int Array2D_OfInt_ForTest::GetMinLength() const{
    return this->data.GetMinLength();
}
//virtual int GetMaxLength() const=0;
int Array2D_OfInt_ForTest::GetMaxLength() const{
    return this->data.GetMaxLength();
}
//
//virtual Array2DSize GetSize()const=0;
Array2DSize Array2D_OfInt_ForTest::GetSize()const{
    return this->data.GetSize();
}
//
////bool LineNBelongsHere(int LineN) const;
////bool ColNBelongsHere(int ColN) const;
 bool Array2D_OfInt_ForTest::NsBelongHere(int ExtRowN, int IneRowN) const{
    return this->data.NsBelongHere(ExtRowN, IneRowN);
}
//
////std::vector<int> GetArrayOfExtRowN(int LineN);
////std::vector<int> GetArrayOfIneRowN(int ColN);
////std::vector<int> GetContentAsArray1D();
////std::vector<std::vector<int>> GetContentAsArray2D();
//
// std::vector<int> TTest2DArray::GetExtRowN_AsArray(int rowN) const{
//    return this->data.GetExtRowN_AsArray(rowN);
//}
//// int*GetExtRowN_AsPtr(int ExtRowN) const;
// std::vector<int> TTest2DArray::GetIneRowN_AsArray(int rowN) const{
//    return this->data.GetIneRowN_AsArray(rowN);
//}
 std::vector<int>  Array2D_OfInt_ForTest::GetIneRowN_AsArray(int IneRowN,  int defaultVal,                         int ifNGTLmin_Ignore0_DefaultsForShorter1_NurProperL_AnyExtRow2_NurFromStartTillErstStop3) const{
    return this->data.GetIneRowN_AsArray(IneRowN, defaultVal, ifNGTLmin_Ignore0_DefaultsForShorter1_NurProperL_AnyExtRow2_NurFromStartTillErstStop3);
}
 std::vector<int> Array2D_OfInt_ForTest::GetIneRowN_AsArray(int IneRowN,                      int*DefaultValParam, int ifNGTLmin_Ignore0_DefaultsForShorter1_NurProperL_AnyExtRow2_NurFromStartTillErstStop3) const{
    return this->data.GetIneRowN_AsArray(IneRowN, DefaultValParam, ifNGTLmin_Ignore0_DefaultsForShorter1_NurProperL_AnyExtRow2_NurFromStartTillErstStop3);
}
 std::vector<int> Array2D_OfInt_ForTest::GetContent_AsArray1D() const{
    return this->data.GetContent_AsArray1D();
}
std::vector<std::vector<int>> Array2D_OfInt_ForTest::GetContent_AsArray2D() const{
    return this->data.GetContent_AsArray2D();
}
//
//
//virtual T GetComponent_AsVal(int LineN, int ColN) const=0;
 int  Array2D_OfInt_ForTest::GetComponent_AsVal(int LineN, int ColN) const{
    return this->data.GetComponent_AsVal(LineN, ColN);
}
//virtual int* GetComponent_AsPtr(int LineN, int ColN) const=0;
 int* Array2D_OfInt_ForTest::GetComponent_AsPtr(int LineN, int ColN) const{
    return this->data.GetComponent_AsPtr(LineN, ColN);
}
//
//virtual void SetComponent(const int& val, int LineN, int ColN)=0;
 void Array2D_OfInt_ForTest::SetComponent(const int& val, int LineN, int ColN){
    this->data.SetComponent(val, LineN, ColN);
}
//
 void Array2D_OfInt_ForTest::AddToExtRowN(int RowN, const int&val){
    this->data.AddToExtRowN(RowN, val);
}
 void Array2D_OfInt_ForTest::InsToExtRowN(int RowN, int PosN, const int&val){
    this->data.InsToExtRowN(RowN, PosN, val);
}
 void Array2D_OfInt_ForTest::DelFromExtRowN(int RowN, int PosN){
    this->data.DelFromExtRowN(RowN, PosN);
}
//virtual void AddToExtRowN_Simply(int ExtRowN, const int&val)=0;
 void Array2D_OfInt_ForTest::AddToExtRowN_Simply(int ExtRowN, const int&val){
    this->data.AddToExtRowN_Simply(ExtRowN, val);
}
//virtual void InsToExtRowN_Simply(int ExtRowN, int PosN, const int&val)=0;
 void Array2D_OfInt_ForTest::InsToExtRowN_Simply(int ExtRowN, int PosN, const int&val){
    this->data.InsToExtRowN_Simply(ExtRowN, PosN, val);
}

//virtual void DelFromExtRowN_Simply(int RowN, int IneRowPosN)=0;
 void Array2D_OfInt_ForTest::DelFromExtRowN_Simply(int RowN, int IneRowPosN){
     this->data.DelFromExtRowN_Simply(RowN, IneRowPosN);
}
//
// Ext row
//
 ////virtual              void               SetExtRowN(                              int N, const int& defaultVal,  int*rowParam,      int rowL,    TDataShiftParams*DataShiftParams=NULL,                          bool DefaulsAreSpecNotOwnVals=true, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2)=0;
void Array2D_OfInt_ForTest::SetExtRowN(                                int N,       int defaultVal, int*rowParam, int rowL,        TDataShiftParams*DataShiftParams, bool DefaulsAreSpecNotOwnVals,                      int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6){
    this->data.SetExtRowN(N, defaultVal, rowParam, rowL, DataShiftParams,  DefaulsAreSpecNotOwnVals,  SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6);
}
void Array2D_OfInt_ForTest::SetExtRowN(                                int N,                       int*rowParam, int rowL,        TDataShiftParams*DataShiftParams, bool DefaulsAreSpecNotOwnVals, int*DfltValParam,    int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6){
    int DefaultVal;
    if(DfltValParam!=NULL){
        DefaultVal=(*(DfltValParam));
    }
    this->data.SetExtRowN(N, DefaultVal, rowParam, rowL, DataShiftParams,  DefaulsAreSpecNotOwnVals,  SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6);
}
//
//void SetExtRow_Simply(int N, int*rowParam)=0;
void Array2D_OfInt_ForTest::SetExtRow_Simply(int N, int*rowParam){
    this->data.SetExtRow_Simply(N, rowParam);
}
//void SetExtRow_Simply(int N, int*rowParam, int L)=0;
void Array2D_OfInt_ForTest::SetExtRow_Simply(int N, int*rowParam, int L){
    this->data.SetExtRow_Simply(N, rowParam, L);
}
//
////void ArrayOf2DBy1D_AddExtRow(int*&X, Array2DSize&size, int DefaultVal, int*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL){
void Array2D_OfInt_ForTest::AddExtRow(                        int DefaultVal, int*rowParam, int wholeRowL,   TDataShiftParams*DataShiftParam,      int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6,   TValsShowHide*vsh){
                               this->data.AddExtRow(                          DefaultVal,   rowParam,     wholeRowL,                    DataShiftParam,          SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6,                 vsh);
}

////void ArrayOf2DBy1D_AddExtRow(int*&X, Array2DSize&size, int*rowParam, int wholeRowL=0, int*DefaultValParam=NULL, TDataShiftParams*DataShiftParam=NULL,  int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL){
void Array2D_OfInt_ForTest::AddExtRow(                        int*rowParam, int wholeRowL,   int*DefaultValParam,      TDataShiftParams*DataShiftParam,       int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6,   TValsShowHide*vsh){
                               this->data.AddExtRow(                          rowParam,     wholeRowL,     DefaultValParam,                       DataShiftParam,           SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6,                 vsh);
}

//
//virtual void AddExtRow_Simply(int*rowParam)=0;
void Array2D_OfInt_ForTest::AddExtRow_Simply(int*rowParam){
    this->data.AddExtRow_Simply(rowParam);
}
//virtual void AddExtRow_Simply(int*rowParam, int L)=0;
void Array2D_OfInt_ForTest::AddExtRow_Simply(int*rowParam, int L){
    this->data.AddExtRow_Simply(rowParam, L);
}
//
////void ArrayOf2DBy1D_InsExtRow(int*&X, Array2DSize&size, int ExtRowN, int DefaultVal, int*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL){
void    Array2D_OfInt_ForTest::InsExtRow(                     int ExtRowN, int DefaultVal, int*rowParam, int wholeRowL,   TDataShiftParams*DataShiftParam,      int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6,   TValsShowHide*vsh){
                                  this->data.InsExtRow(                         ExtRowN,   DefaultVal,   rowParam,     wholeRowL,                    DataShiftParam,          SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6,                 vsh);
}

////void ArrayOf2DBy1D_InsExtRow(int*&X, Array2DSize&size, int ExtRowN, int*rowParam, int wholeRowL=0,  int*DfltValParam=NULL, TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL){
void    Array2D_OfInt_ForTest::InsExtRow(                      int ExtRowN, int*rowParam, int wholeRowL,    int*DfltValParam,      TDataShiftParams*DataShiftParam,      int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6,   TValsShowHide*vsh){
                                  this->data.InsExtRow(                          ExtRowN,   rowParam,     wholeRowL,      DfltValParam,                       DataShiftParam,          SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6,                 vsh);
}

//
//virtual void InsExtRow_Simply(int N, int*rowParam)=0;
void Array2D_OfInt_ForTest::InsExtRow_Simply(int N, int*rowParam){
    this->data.InsExtRow_Simply(N, rowParam);
}
//virtual void InsExtRow_Simply(int N, int*rowParam, int L)=0;
void Array2D_OfInt_ForTest::InsExtRow_Simply(int N, int*rowParam, int L){
    this->data.InsExtRow_Simply(N, rowParam, L);
}
//
//void DelExtRowN(int N=-1);
//virtual void DelExtRowN_Simply(int N=-1)=0;
void Array2D_OfInt_ForTest::DelExtRowN_Simply(int N){
    this->data.DelExtRowN_Simply(N);
}
//
//Ine row
//
//void             SetIneRowN(int IneRowN,        int DefaultVal, int*rowParam=NULL, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, bool DefaulsAreSpecNotOwnVals=true,                           int if_LsNE_Ignore0_Resize_NewByOld_QERAndStretchIfShorter2_QEROrIRL_FromStartTillBreak3_All_NsBy2D4_NsByLongEnoughRows5_ByMaxQERAndStretchOrIRL6_OldByNew_FromStartAndStretchIfShorterAndTrimOrAddExt7=2, bool SetRectAnyway=true);
//void             SetIneRowN(int IneRowN,                        int*rowParam=NULL, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, bool DefaulsAreSpecNotOwnVals=true, int*DefaultValParam=NULL, int if_LsNE_Ignore0_Resize_NewByOld_QERAndStretchIfShorter2_QEROrIRL_FromStartTillBreak3_All_NsBy2D4_NsByLongEnoughRows5_ByMaxQERAndStretchOrIRL6_OldByNew_FromStartAndStretchIfShorterAndTrimOrAddExt7=2, bool SetRectAnyway=true);
//
void Array2D_OfInt_ForTest::SetIneRowN(int IneRowN,       int DefaultVal,  int*rowParam,      int wholeRowL,   TDataShiftParams*DataShiftParam,      bool DefaulsAreSpecNotOwnVals,                                int if_LsNE_Ignore0_Resize_NewByOld_QERAndStretchIfShorter2_QEROrIRL_FromStartTillBreak3_All_NsBy2D4_NsByLongEnoughRows5_ByMaxQERAndStretchOrIRL6_OldByNew_FromStartAndStretchIfShorterAndTrimOrAddExt7,   bool SetRectAnyway){
        this->data.SetIneRowN(    IneRowN,           DefaultVal,      rowParam,          wholeRowL,                    DataShiftParam,           DefaulsAreSpecNotOwnVals,                                    if_LsNE_Ignore0_Resize_NewByOld_QERAndStretchIfShorter2_QEROrIRL_FromStartTillBreak3_All_NsBy2D4_NsByLongEnoughRows5_ByMaxQERAndStretchOrIRL6_OldByNew_FromStartAndStretchIfShorterAndTrimOrAddExt7,        SetRectAnyway);
}
void Array2D_OfInt_ForTest::SetIneRowN(int IneRowN,                        int*rowParam,      int wholeRowL,   TDataShiftParams*DataShiftParam,      bool DefaulsAreSpecNotOwnVals,      int*DefaultValParam,      int if_LsNE_Ignore0_Resize_NewByOld_QERAndStretchIfShorter2_QEROrIRL_FromStartTillBreak3_All_NsBy2D4_NsByLongEnoughRows5_ByMaxQERAndStretchOrIRL6_OldByNew_FromStartAndStretchIfShorterAndTrimOrAddExt7,   bool SetRectAnyway){
        this->data.SetIneRowN(    IneRowN,                            rowParam,          wholeRowL,                  DataShiftParam,             DefaulsAreSpecNotOwnVals,          DefaultValParam,          if_LsNE_Ignore0_Resize_NewByOld_QERAndStretchIfShorter2_QEROrIRL_FromStartTillBreak3_All_NsBy2D4_NsByLongEnoughRows5_ByMaxQERAndStretchOrIRL6_OldByNew_FromStartAndStretchIfShorterAndTrimOrAddExt7,        SetRectAnyway);
}
//
//virtual void SetIneRowSimply(int IneRowN, int*rowParam)=0;
void Array2D_OfInt_ForTest::SetIneRowSimply(int IneRowN, int*rowParam){
    this->data.SetIneRowSimply(IneRowN, rowParam);
}
//
//void             AddIneRow(    int DefaultVal,   T*rowParam=NULL, int wholeRowL=0, TDataShiftParams*dataShiftParam=NULL,                           int ifNGTLmin_Ignore0AddToLast1StretchToMax2=0, int if_RowLNEQER_By2D2_ByMax3=2, bool SetRect=true);
//void             AddIneRow(                      T*rowParam=NULL, int wholeRowL=0, TDataShiftParams*dataShiftParam=NULL, int*DefaultValParam=NULL, int ifNGTLmin_Ignore0AddToLast1StretchToMax2=0, int if_RowLNEQER_By2D2_ByMax3=2, bool SetRect=true);
void Array2D_OfInt_ForTest::AddIneRow(    int DefaultVal, int*rowParam,      int wholeRowL,    TDataShiftParams*dataShiftParam,                               int ifNGTLmin_Ignore0AddToLast1StretchToMax2,   int if_RowLNEQER_By2D2_ByMax3,   bool SetRect){
        this->data.AddIneRow(        DefaultVal,     rowParam,          wholeRowL,                     dataShiftParam,                                   ifNGTLmin_Ignore0AddToLast1StretchToMax2,       if_RowLNEQER_By2D2_ByMax3,        SetRect);
}
void Array2D_OfInt_ForTest::AddIneRow(                    int*rowParam, int wholeRowL, TDataShiftParams*dataShiftParam, int*DefaultValParam, int ifNGTLmin_Ignore0AddToLast1StretchToMax2, int if_RowLNEQER_By2D2_ByMax3, bool SetRect){
        this->data.AddIneRow(                      rowParam,     wholeRowL,                  dataShiftParam,     DefaultValParam,     ifNGTLmin_Ignore0AddToLast1StretchToMax2,     if_RowLNEQER_By2D2_ByMax3,      SetRect);
}
//
//virtual void AddIneRow_Simply(int*rowParam)=0;
void Array2D_OfInt_ForTest::AddIneRow_Simply(int*rowParam){
    this->data.AddIneRow_Simply(rowParam);
}
//
//void             InsIneRowN(int IneRowN, const T& DefaultVal,   T*rowParam=NULL, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, bool DefaulsAreSpecNotOwnVals=true,                         int if_LsNE_Ignore0_Resize_NewByOld_QERAndStretchIfShorter2_QEROrIRL_FromStartTillBreak3_All_NsBy2D4_NsByLongEnoughRows5_ByMaxQERAndStretchOrIRL6_OldByNew_FromStartAndStretchIfShorterAndTrimOrAddExt7=2, bool SetRectAnyway=true);
//void             InsIneRowN(int IneRowN,                        T*rowParam=NULL, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, bool DefaulsAreSpecNotOwnVals=true, T*DefaultValParam=NULL, int if_LsNE_Ignore0_Resize_NewByOld_QERAndStretchIfShorter2_QEROrIRL_FromStartTillBreak3_All_NsBy2D4_NsByLongEnoughRows5_ByMaxQERAndStretchOrIRL6_OldByNew_FromStartAndStretchIfShorterAndTrimOrAddExt7=2, bool SetRectAnyway=true);
void Array2D_OfInt_ForTest::InsIneRowN(int IneRowN,      int DefaultVal, int*rowParam,      int wholeRowL,   TDataShiftParams*DataShiftParam,      bool DefaulsAreSpecNotOwnVals,                              int if_LsNE_Ignore0_Resize_NewByOld_QERAndStretchIfShorter2_QEROrIRL_FromStartTillBreak3_All_NsBy2D4_NsByLongEnoughRows5_ByMaxQERAndStretchOrIRL6_OldByNew_FromStartAndStretchIfShorterAndTrimOrAddExt7,   bool SetRectAnyway){
        this->data.InsIneRowN(    IneRowN,          DefaultVal,     rowParam,          wholeRowL,                    DataShiftParam,           DefaulsAreSpecNotOwnVals,                                  if_LsNE_Ignore0_Resize_NewByOld_QERAndStretchIfShorter2_QEROrIRL_FromStartTillBreak3_All_NsBy2D4_NsByLongEnoughRows5_ByMaxQERAndStretchOrIRL6_OldByNew_FromStartAndStretchIfShorterAndTrimOrAddExt7,        SetRectAnyway);
}
void Array2D_OfInt_ForTest::InsIneRowN(int IneRowN,                      int*rowParam,      int wholeRowL,   TDataShiftParams*DataShiftParam,      bool DefaulsAreSpecNotOwnVals,     int*DefaultValParam,       int if_LsNE_Ignore0_Resize_NewByOld_QERAndStretchIfShorter2_QEROrIRL_FromStartTillBreak3_All_NsBy2D4_NsByLongEnoughRows5_ByMaxQERAndStretchOrIRL6_OldByNew_FromStartAndStretchIfShorterAndTrimOrAddExt7,   bool SetRectAnyway){
        this->data.InsIneRowN(    IneRowN,                          rowParam,          wholeRowL,                    DataShiftParam,           DefaulsAreSpecNotOwnVals,         DefaultValParam,           if_LsNE_Ignore0_Resize_NewByOld_QERAndStretchIfShorter2_QEROrIRL_FromStartTillBreak3_All_NsBy2D4_NsByLongEnoughRows5_ByMaxQERAndStretchOrIRL6_OldByNew_FromStartAndStretchIfShorterAndTrimOrAddExt7,        SetRectAnyway);
}
//
//virtual void InsIneRow_Simply(int N, int*rowParam)=0;
void Array2D_OfInt_ForTest::InsIneRow_Simply(int N, int*rowParam){
    this->data.InsIneRow_Simply(N, rowParam);
}
//
//void DelIneRowN(int N=-1, int ifNGTLmin_Ignore0_DelLast1_NurProperL_AnyExtRow3_NurFromStartTillFirstBreak4=0);
//virtual void DelIneRow_Simply(int N=-1)=0;
void Array2D_OfInt_ForTest::DelIneRow_Simply(int N){
    this->data.DelIneRow_Simply(N);
}
//
// Set Content
//
void Array2D_OfInt_ForTest::Set(int**y, const Array2DSize& size,  bool WriteSize, int TypeN){
    int PrevTypeN=this->GetTypeN();
    if(PrevTypeN!=TypeN){
        this->SetTypeN(TypeN);
    }
    this->data.Set(y, size, WriteSize);
}
void Array2D_OfInt_ForTest::Set(int**y, std::vector<int>ExtRowsLengthes, bool RectIfPossible, bool WriteSize, int TypeN){
    //writeSize - qut?
    int PrevTypeN=this->GetTypeN();
    if(PrevTypeN!=TypeN){
        this->SetTypeN(TypeN);
    }
    this->data.Set(y, ExtRowsLengthes, RectIfPossible, WriteSize);
}
//void TTest2DArray::Set(int**y, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible, bool WriteSize, int TypeN){
//    int PrevTypeN=this->GetTypeN();
//    if(PrevTypeN!=TypeN){
//        this->SetTypeN(TypeN);
//    }
//    this->data.Set(y, QExtRows, ExtRowsLengthes, RectIfPossible, WriteSize);
//}
void Array2D_OfInt_ForTest::Set(int**y, int QExtRows, int ExtRowsLength, bool RectIfPossible, bool WriteSize, int TypeN){
    int PrevTypeN=this->GetTypeN();
    if(PrevTypeN!=TypeN){
        this->SetTypeN(TypeN);
    }
    this->data.Set(y, QExtRows, ExtRowsLength, RectIfPossible, WriteSize);
}
void Array2D_OfInt_ForTest::Set(int*y, const Array2DSize& size, bool WriteSize, int TypeN){
    int PrevTypeN=this->GetTypeN();
    if(PrevTypeN!=TypeN){
        this->SetTypeN(TypeN);
    }
    this->data.Set(y, size, WriteSize);
}
void Array2D_OfInt_ForTest::Set(int*y, std::vector<int>ExtRowsLengthes, bool WriteSize, int TypeN){
    int PrevTypeN=this->GetTypeN();
    if(PrevTypeN!=TypeN){
        this->SetTypeN(TypeN);
    }
    this->data.Set(y, ExtRowsLengthes, WriteSize);
}
//void TTest2DArray::Set(int*y, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible,  bool WriteSize, int TypeN){
//    int PrevTypeN=this->GetTypeN();
//    if(PrevTypeN!=TypeN){
//        this->SetTypeN(TypeN);
//    }
//    this->data.Set(y, ExtRowsLengthes, WriteSize);
//}
void Array2D_OfInt_ForTest::Set(int*y, int QExtRows, int ExtRowsLength, bool RectIfPossible, bool sizeVaria, bool WriteSize, int TypeN){
    //size Varia - qut? - nah RectIfPossible. Noam ady, mab os err
    int PrevTypeN=this->GetTypeN();
    if(PrevTypeN!=TypeN){
        this->SetTypeN(TypeN);
    }
    this->data.Set(y, QExtRows, ExtRowsLength, RectIfPossible, sizeVaria, WriteSize);
}
void Array2D_OfInt_ForTest::Set(std::vector<std::vector<int>>y, bool RectIfPossible, bool WriteSize, int TypeN){
    int PrevTypeN=this->GetTypeN();
    if(PrevTypeN!=TypeN){
        this->SetTypeN(TypeN);
    }
    this->data.Set(y, RectIfPossible, WriteSize);
}
void Array2D_OfInt_ForTest::Set(std::vector<int>y, const Array2DSize& size, bool WriteSize, int TypeN){
    int PrevTypeN=this->GetTypeN();
    if(PrevTypeN!=TypeN){
        this->SetTypeN(TypeN);
    }
    this->data.Set(y, size, WriteSize);
}
void Array2D_OfInt_ForTest::Set(std::vector<int>y, std::vector<int>ExtRowsLengthes, bool RectIfPossible, bool WriteSize, int TypeN){
    int PrevTypeN=this->GetTypeN();
    if(PrevTypeN!=TypeN){
        this->SetTypeN(TypeN);
    }
    this->data.Set(y, ExtRowsLengthes, RectIfPossible, WriteSize);
}
//void TTest2DArray::Set(std::vector<int>y, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible, bool WriteSize, int TypeN){
//    int PrevTypeN=this->GetTypeN();
//    if(PrevTypeN!=TypeN){
//        this->SetTypeN(TypeN);
//    }
//    this->data.Set(y, QExtRows, ExtRowsLengthes, RectIfPossible, WriteSize);
//}
void Array2D_OfInt_ForTest::Set(std::vector<int>y, int QExtRows, int ExtRowsLength, bool RectIfPossible, bool WriteSize, int TypeN){
    //RectIfPossible - qut?
    int PrevTypeN=this->GetTypeN();
    if(PrevTypeN!=TypeN){
        this->SetTypeN(TypeN);
    }
    this->data.Set(y, QExtRows, ExtRowsLength, RectIfPossible, WriteSize);
}
void Array2D_OfInt_ForTest::Set(const int&val, const Array2DSize& size, bool WriteSize, int TypeN){
    int PrevTypeN=this->GetTypeN();
    if(PrevTypeN!=TypeN){
        this->SetTypeN(TypeN);
    }
    this->data.Set(val, size, WriteSize);
}
void Array2D_OfInt_ForTest::Set(const int&val, std::vector<int>ExtRowsLengthes, bool RectIfPossible, bool WriteSize, int TypeN){
    int PrevTypeN=this->GetTypeN();
    if(PrevTypeN!=TypeN){
        this->SetTypeN(TypeN);
    }
    this->data.Set(val, ExtRowsLengthes, RectIfPossible, WriteSize);
}
//void TTest2DArray::Set(const int&val, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible, bool WriteSize, int TypeN){
//    int PrevTypeN=this->GetTypeN();
//    if(PrevTypeN!=TypeN){
//        this->SetTypeN(TypeN);
//    }
//    this->data.Set(val, QExtRows, ExtRowsLengthes, RectIfPossible, WriteSize);
//}
void Array2D_OfInt_ForTest::Set(const int&val, int QExtRows, int ExtRowsLength, bool RectIfPossible, bool WriteSize, int TypeN){
    int PrevTypeN=this->GetTypeN();
    if(PrevTypeN!=TypeN){
        this->SetTypeN(TypeN);
    }
    this->data.Set(val, QExtRows, ExtRowsLength, RectIfPossible, WriteSize);
}
//
void Array2D_OfInt_ForTest::SwapVals(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2){
    this->data.SwapVals(ExtRowN1, IneRowN1, ExtRowN2, IneRowN2);
}
void Array2D_OfInt_ForTest::SwapExtRows(int N1, int N2){
    this->data.SwapExtRows(N1, N2);
}
void Array2D_OfInt_ForTest::SwapIneRows(int N1, int N2){
    this->data.SwapIneRows(N1, N2);
}
//
void Array2D_OfInt_ForTest::ReverseExtRowN(int rowN){
    this->data.ReverseExtRowN(rowN);
}
void Array2D_OfInt_ForTest::ReverseIneRowN(int rowN){
    this->data.ReverseIneRowN(rowN);
}
////virtual void TTest2DArray::ReverseExtRowsSuccession()=0;
void Array2D_OfInt_ForTest::ReverseExtRowsSuccession(){
    this->data.ReverseExtRowsSuccession();
}
////virtual void TTest2DArray::ReverseIneRowsSuccession()=0;
void Array2D_OfInt_ForTest::ReverseIneRowsSuccession(){
    this->data.ReverseIneRowsSuccession();
}
//
 bool Array2D_OfInt_ForTest::ValIsAtPos(const int&val, int ExtRowN, int IneRowN) const{
    return this->data.ValIsAtPos(val, ExtRowN, IneRowN);
}
//swa S di n'fit prototype - obe s': alt IneRowN wa ExtRowN, so ExtRowN 2x, ce alt err
////std::vector<std::vector<int>> SeekVal(const int&val) const;
////std::vector<Int2DVectorOfSizeOrCoords> SeekVal(const int&val) const;
 TListOfNumberPairs Array2D_OfInt_ForTest::SeekVal(const int&val) const{
    return this->data.SeekVal(val);
}
//so class name. Ma to vrns co std::vector ety di n'fit prototype
 bool Array2D_OfInt_ForTest::ExtRowIsAtPos(int*row, int Q, int ExtRowN, int IneRowN) const{
    return this->data.ExtRowIsAtPos(row, Q, ExtRowN, IneRowN);
}
////std::vector<std::vector<int>> SeekExtRow(int*row, int L) const;
////std::vector<Int2DVectorOfSizeOrCoords> SeekExtRow(int*row, int L) const;
 TListOfNumberPairs Array2D_OfInt_ForTest:: SeekExtRow(int*row, int L) const{
    return this->data.SeekExtRow(row, L);
}
 bool Array2D_OfInt_ForTest::IneRowIsAtPos(int*row, int Q, int ExtRowN, int IneRowN) const{
    return this->data.IneRowIsAtPos(row, Q, ExtRowN, IneRowN);
}
////std::vector<std::vector<int>> SeekIneRow(int*row, int Q) const;
////std::vector<Int2DVectorOfSizeOrCoords> SeekIneRow(int*row, int Q) const;
 TListOfNumberPairs Array2D_OfInt_ForTest::SeekIneRow(int*row, int Q) const{
    return this->data.SeekIneRow(row, Q);
}
//
 bool Array2D_OfInt_ForTest::Arr2DIsAtPos(std::vector<std::vector<int>>arr, int ExtRowN, int IneRowN, bool isNotTransposed, bool ExtRowsSuccIsNotReversed, bool EachExtRowIsNotReversed) const{
    return this->data.Arr2DIsAtPos(arr, ExtRowN, IneRowN, isNotTransposed, ExtRowsSuccIsNotReversed, EachExtRowIsNotReversed);
}
 bool Array2D_OfInt_ForTest::Arr2DIsAtPos(Array2D_Prototype<int>*arr, int ExtRowN, int IneRowN, bool isNotTransposed, bool ExtRowsSuccIsNotReversed, bool EachExtRowIsNotReversed) const{
    return this->data.Arr2DIsAtPos(arr, ExtRowN, IneRowN, isNotTransposed, ExtRowsSuccIsNotReversed, EachExtRowIsNotReversed);
}
////std::vector<std::vector<int>> SeekArr2D(std::vector<std::vector<int>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
////std::vector<Int2DVectorOfSizeOrCoords> SeekArr2D(std::vector<std::vector<int>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
 TListOfNumberPairs Array2D_OfInt_ForTest::SeekArr2D(std::vector<std::vector<int>>arr, bool isNotTransposed, bool ExtRowsSuccIsNotReversed, bool EachExtRowIsNotReversed) const{
     return this->data.SeekArr2D(arr, isNotTransposed, ExtRowsSuccIsNotReversed, EachExtRowIsNotReversed);
}
////std::vector<std::vector<int>> SeekArr2D(Array2D_Prototype*arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
////std::vector<Int2DVectorOfSizeOrCoords> SeekArr2D(Array2D_Prototype*arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
 TListOfNumberPairs Array2D_OfInt_ForTest::SeekArr2D(Array2D_Prototype<int>*obj, bool isNotTransposed, bool ExtRowsSuccIsNotReversed, bool EachExtRowIsNotReversed) const{
    return this->data.SeekArr2D(obj, isNotTransposed, ExtRowsSuccIsNotReversed, EachExtRowIsNotReversed);
}
//
////virtual void ConcatAdding(Array2D_Prototype*obj, int DefaultVal,int QShiftedCols=0,  TDataShiftParams*DataShiftParam=NULL, bool SetRect=true, inint DfltRowL_00_11_Lmin2_Lmax3=1);
void Array2D_OfInt_ForTest::ConcatAdding(Array2D_Prototype<int>*obj, int DefaultVal,int QShiftedCols,  TDataShiftParams*DataShiftParam, bool SetRect, int DfltRowL_00_11_Lmin2_Lmax3){
    this->data.ConcatAdding(obj, DefaultVal, QShiftedCols, DataShiftParam, SetRect, DfltRowL_00_11_Lmin2_Lmax3);
}
////virtual void ConcatAdding(Array2D_Prototype*obj, int QShiftedCols=0, TDataShiftParams*DataShiftParam=NULL, int*DefaultValParam=NULL, bool SetRect=true, inint DfltRowL_00_11_Lmin2_Lmax3=1);
void Array2D_OfInt_ForTest::ConcatAdding(Array2D_Prototype<int>*obj, int QShiftedCols, TDataShiftParams*DataShiftParam, int*DefaultValParam, bool SetRect, int DfltRowL_00_11_Lmin2_Lmax3){
    this->data.ConcatAdding(obj, QShiftedCols, DataShiftParam, DefaultValParam, SetRect, DfltRowL_00_11_Lmin2_Lmax3);
}
////_ConcatStretching(int*X1, const Array2DSize& size1, int*X2, const Array2DSize& size2, int*&X3, Array2DSize& size3, int DefaultVal, int shiftQ=0, TDataShiftParams*DataShiftParam=NULL, inint DfltRowL_00_11_Lmin2_Lmax3=3, bool Stretch1ToMax=true, bool SetRect=true){
////virtual void ConcatStretching(Array2D_Prototype*obj, int DefaultVal, int QShiftedExtRowNs=0,  TDataShiftParams*DataShiftParam=NULL, inint DfltRowL_00_11_Lmin2_Lmax3=3, bool Stretch1ToMax=true, bool SetRect=true);
void Array2D_OfInt_ForTest::ConcatStretching(Array2D_Prototype<int>*obj, int DefaultVal, int QShiftedExtRowNs,  TDataShiftParams*DataShiftParam, int DfltRowL_00_11_Lmin2_Lmax3, bool Stretch1ToMax, bool SetRect){
                               this->data.ConcatStretching(                     obj,   DefaultVal,     QShiftedExtRowNs,                   DataShiftParam,     DfltRowL_00_11_Lmin2_Lmax3, Stretch1ToMax, SetRect);
}
////virtual void ConcatStretching(Array2D_Prototype*obj, int QShiftedExtRowNs=0, TDataShiftParams*DataShiftParam=NULL, inint DfltRowL_00_11_Lmin2_Lmax3=3, bool Stretch1ToMax=true, bool SetRect=true, int*DefaultValParam=NULL);
void Array2D_OfInt_ForTest::ConcatStretching(Array2D_Prototype<int>*obj, int QShiftedExtRowNs, TDataShiftParams*DataShiftParam, int DfltRowL_00_11_Lmin2_Lmax3, bool Stretch1ToMax, bool SetRect, int*DefaultValParam){
    this->data.ConcatStretching(obj, QShiftedExtRowNs, DataShiftParam, DfltRowL_00_11_Lmin2_Lmax3, Stretch1ToMax, SetRect, DefaultValParam);
}
//
std::vector<int> Array2D_OfInt_ForTest::GetSubArray_AsStdVect1D(int ExtRowN, int IneRowN, const Array2DSize& size, bool isNotTransposed, bool ExtRowsSuccIsNotReversed, bool EachExtRowIsNotReversed) const{
    Array2D_OfInt_ForTest obj;
    std::vector<int>dataV;
    //    this->data.GetSubArray_As1DArr(dataP, ExtRowN, IneRowN, size, isNotTransposed, ExtRowsSuccIsNotReversed, EachExtRowIsNotReversed);
    dataV=this->data.GetSubArray_AsStdVect1D(       ExtRowN, IneRowN, size, isNotTransposed, ExtRowsSuccIsNotReversed, EachExtRowIsNotReversed);
    obj.Set(dataV, size);
    //return obj;
    return dataV;
}
//Array2D_shell                                      GetSubArray_AsSuccOfExtRows(int DefaultVal, TDataShiftParams*DataShiftParam=NULL,                    inint DfltRowL_00_11_Lmin2_Lmax3=3) const;
 Array2D_OfInt_ForTest Array2D_OfInt_ForTest::GetSubArray_AsSuccOfExtRows(int DefaultVal, TDataShiftParams*DataShiftParam,                         int DfltRowL_00_11_Lmin2_Lmax3) const{
    Array2D_OfInt_ForTest R;
    //int*dataP;
    std::vector<int>dataR;
    Array2DSize sizeR;
    //void      GetSubArray_AsSuccOfExtRows_As1DArr(int*&XR, Array2DSize& sizeR, int DefaultVal, DataShiftParams*DataShiftParam=NULL, inint DfltRowL_00_11_Lmin2_Lmax3=3);
    //this->data.GetSubArray_AsSuccOfExtRows_As1DArr(dataP,              sizeR,   DefaultVal, DataShiftParam,                          DfltRowL_00_11_Lmin2_Lmax3);
    this->data.GetSubArray_AsSuccOfExtRows_As1DArr(dataR,              sizeR,   DefaultVal, DataShiftParam,                          DfltRowL_00_11_Lmin2_Lmax3);
    //R.Set(dataP, sizeR, this->GetTypeN());
    R.Set(dataR, sizeR, this->GetTypeN());
    //if(dataP!=NULL){
    //    delete[]dataP;
    //}
    return R;
}
 Array2D_OfInt_ForTest Array2D_OfInt_ForTest::GetSubArray_AsSuccOfExtRows(TDataShiftParams*DataShiftParam,      int*DefaultValParam,      int DfltRowL_00_11_Lmin2_Lmax3)const{
    int DefaultVal;
    if(DefaultValParam!=NULL){
        DefaultVal=(*(DefaultValParam));
    }
    return this->GetSubArray_AsSuccOfExtRows(DefaultVal, DataShiftParam, DfltRowL_00_11_Lmin2_Lmax3);
}
//
void Array2D_OfInt_ForTest::ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(int val, int ExtRowN, int IneRowN, int DefaultVal, int SetRect_No0IfPossible1AnywayYes2){
    this->data.ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(val, ExtRowN, IneRowN, DefaultVal, SetRect_No0IfPossible1AnywayYes2);
}
void Array2D_OfInt_ForTest::ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(int val, int ExtRowN, int IneRowN, int SetRect_No0IfPossible1AnywayYes2, int*DefaultValParam){
    this->data.ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(val, ExtRowN, IneRowN, SetRect_No0IfPossible1AnywayYes2, DefaultValParam);
}
//
void Array2D_OfInt_ForTest::StdCout_ExtRowN(int ExtRowN, QString ElemsDelim, bool UseBrackets)const{
    this->data.StdCout_ExtRowN(ExtRowN, ElemsDelim, UseBrackets);
}
void Array2D_OfInt_ForTest::StdCout_IneRowN(int IneRowN, QString ElemsDelim, bool UseBrackets, bool Represent2DNot1D)const{
    this->data.StdCout_IneRowN(IneRowN, ElemsDelim, UseBrackets, Represent2DNot1D);
}
void Array2D_OfInt_ForTest::StdCout(QString ElemsDelim, QString RowsDelim, bool UseBrackets, bool Represent2DNot1D, bool ByExtRowsNotIneRows)const{
   this->data.StdCout(ElemsDelim, RowsDelim, UseBrackets, Represent2DNot1D, ByExtRowsNotIneRows);
}
//
void Array2D_OfInt_ForTest::FillByNs(){
    int QExtRows=this->GetQExtRows(), curL;
    double val;
    for(int i=1; i<=QExtRows; i++){
        curL=this->GetLength(i);
        for(int j=1; j<=curL; j++){
            val = i * 10 + j;
            this->SetComponent(val, i, j);
        }
    }
}
//};//TTest2DArray
