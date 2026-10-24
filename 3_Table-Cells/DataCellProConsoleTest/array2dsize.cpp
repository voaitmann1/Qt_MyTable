#include "array2dsize.h"

Int2DVectorOfSizeOrCoords::Int2DVectorOfSizeOrCoords(int d1, int d2){
    this->d1=d1; this->d2=d2;
}

//------------------------------------------------------------------------------

Array2DPositions::Array2DPositions(){}
Array2DPositions::Array2DPositions(std::vector<Int2DVectorOfSizeOrCoords>data){
    this->data=data;
}
int  Array2DPositions::GetQuantity(){ return this->data.size(); }
std::vector<Int2DVectorOfSizeOrCoords>Array2DPositions::Get(){ return this->data; }
void Array2DPositions::clear(){ this->data.clear(); }
void Array2DPositions::Set(std::vector<Int2DVectorOfSizeOrCoords>data){ this->data=data; }
void Array2DPositions::Add(const Int2DVectorOfSizeOrCoords& data){
    Array1DAddElement(this->data, data);
}

void Array2DPositions::Ins(const Int2DVectorOfSizeOrCoords& data, int N){
    Array1DInsElementToN(this->data, N, data);
}

void Array2DPositions::Add(int ExtRowN, int IneRowN){
    Int2DVectorOfSizeOrCoords data;
    data.d1=ExtRowN;
    data.d2=IneRowN;
    this->data.push_back(data);
}

void Array2DPositions::Ins(int ExtRowN, int IneRowN, int N){
    Int2DVectorOfSizeOrCoords data;
    data.d1=ExtRowN;
    data.d2=IneRowN;
    Array1DInsElementToN(this->data, N, data);
}
void Array2DPositions::Del(int N){
    Array1DDelElementFromN(this->data, N);
}

Int2DVectorOfSizeOrCoords Array2DPositions::GetElementN(int N){
    Int2DVectorOfSizeOrCoords R;
    R.d1=0;
    R.d2=0;
    if(N>=1 && N<=this->data.size()){
        R=this->data[N-1];
    }
    return R;
}

void Array2DPositions::GetN(int N, int&ExtRowN, int&IneRowN){
    Int2DVectorOfSizeOrCoords R=this->GetElementN(N);
    ExtRowN=R.d1;
    IneRowN=R.d2;
}

void Array2DPositions::SetN(const Int2DVectorOfSizeOrCoords&data, int N){
    if(N>=1 && N<=this->data.size()){
        this->data[N-1]=data;
    }
}

void Array2DPositions::SetN(int ExtRowN, int IneRowN, int N){
    Int2DVectorOfSizeOrCoords data;
    if(N>=1 && N<=this->data.size()){
        data.d1=ExtRowN;
        data.d2=IneRowN;
        this->data[N-1]=data;
    }
}

int Array2DPositions::GetExtRowN(int N){
    int ExtRowN,  IneRowN;
    Int2DVectorOfSizeOrCoords R=this->GetElementN(N);
    ExtRowN=R.d1;
    IneRowN=R.d2;
    return ExtRowN;
}

int Array2DPositions::GetIneRowN(int N){
    int ExtRowN,  IneRowN;
    Int2DVectorOfSizeOrCoords R=this->GetElementN(N);
    ExtRowN=R.d1;
    IneRowN=R.d2;
    return IneRowN;
}
void Array2DPositions::SetExtRowN(int N, int val){
    int ExtRowN,  IneRowN;
    Int2DVectorOfSizeOrCoords data;
    if(N>=1 && N<=this->data.size()){
        ExtRowN=val;
        IneRowN=data.d2;
        data.d1=ExtRowN;
        data.d2=IneRowN;
        this->data[N-1]=data;
    }
}
void Array2DPositions::SetIneRowN(int N, int val){
    int ExtRowN,  IneRowN;
    Int2DVectorOfSizeOrCoords data;
    if(N>=1 && N<=this->data.size()){
        ExtRowN=data.d1;
        IneRowN=val;
        data.d1=ExtRowN;
        data.d2=IneRowN;
        this->data[N-1]=data;
    }
}




//--------------------------------------------------------------------------------

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
        this->QExtRows-=1;
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
bool Array2DSize::isRectangular(){ return (this->Ls==NULL); }
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
    int Lmy;
    int Ltheir;
    if(this->QExtRows!=obj.QExtRows) verdict=false;
    //if(this->GetQExtRows()!=obj.GetQExtRows()) verdict=false;
    else if(this->Ls==NULL  && obj.Ls==NULL){
        if(this->IneRowsLength!=obj.IneRowsLength){
            verdict=false;
        }
    }else{
       for(int i=1; i<=this->QExtRows; i++){
           //Lmy=this->GetLength(i);
           //Ltheir=obj.GetLength(i);
           Lmy=this->Ls[i-1];
           Ltheir=obj.Ls[i-1];
           //if(this->GetLength(i)!=obj.GetLength(i)) verdict=false;
           if(Lmy!=Ltheir) verdict=false;
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
        c.setNum(this->GetLength(this->QExtRows));
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
                iL=this->LengthFullOfIneRowN(i);
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
int Array2DSize::LengthFullOfIneRowN(int N)const{//from start to 1st stop
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

int CalcElementNIfNegativeOf(int N, int Q){
    int y=N;
    if(N<0){
        y=N+Q;
    }
    return y;
}
