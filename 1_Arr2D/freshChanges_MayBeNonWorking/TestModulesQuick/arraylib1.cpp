#include "arraylib1.h"

//arrayLib1::arrayLib1()
//{
//
//}

//class TDataShiftResults{
//public:
//    int PreN1, PreN2, PostN1, PostN2, OwnN1, OwnN2, ForOwnN1, ForOwnN2;
TDataShiftResults::TDataShiftResults(){
    this->PreN1=0;
    this->PreN2=0;
    this->PostN1=0;
    this->PostN2=0;
    this->OwnN1=0;
    this->OwnN2=0;
    this->ForOwnN1=0;
    this->ForOwnN2=0;
    this->Lcalc=0;
}

//};

//class TDataShift{
//public:
//    int QDefaultsBefore, FirstN, Lreq;
TDataShiftParams::TDataShiftParams(int FirstN, int QDefaultsBefore, int Lreq){
    this->FirstN=FirstN;
    this->QDefaultsBefore=QDefaultsBefore;
    this->Lreq=Lreq;
}
TDataShiftResults TDataShiftParams::Calc(int Lown)const{
    TDataShiftResults R;
    int LOwnLeft, L1=this->QDefaultsBefore+Lown-FirstN+1;;
    if(Lreq==0 || L1<=Lreq){
        LOwnLeft=Lown-FirstN+1;
        if(QDefaultsBefore>0){
            R.PreN1=1;
            R.PreN2=this->QDefaultsBefore;
        }
        R.OwnN1=this->FirstN+1;
        R.OwnN2=Lown;
        R.ForOwnN1=R.PreN2+1;
        R.ForOwnN2=R.PreN2+LOwnLeft-1;
        if(Lreq>0 && Lreq>L1){
            R.PostN1=R.OwnN2+1;
            R.PostN2=R.PostN1+(Lreq-L1)-1;
            R.Lcalc=Lreq;
        }else{//Lreq==0
            R.Lcalc=L1;
        }
    }else{//0<Lreq<L1
        if(QDefaultsBefore>0){
            R.PreN1=1;
            if(QDefaultsBefore>Lreq){
                R.PreN2=Lreq;
            }else{
                R.PreN2=QDefaultsBefore;
            }
        }
        if(QDefaultsBefore<Lreq){
            LOwnLeft=Lreq-QDefaultsBefore;//LownLeft<Lown
            if(FirstN>LOwnLeft){
                R.PreN2=Lreq;
            }else{
                R.OwnN1=FirstN;
                R.OwnN2=Lreq;
                R.ForOwnN1=R.PreN2+1;
                R.ForOwnN2=R.ForOwnN1+LOwnLeft-1;
            }
        }
    }
    return R;
}

//};


Array2DSize_Prototype::~Array2DSize_Prototype() {}

void Array2DSize_Prototype::construct(){
    this->SetNullIni();
    //this->SetOne();
}

bool Array2DSize_Prototype::IsForTranspose() const{
    bool verdict=true;
    std::vector<int>Ls=this->GetLengthes();
    int L1, L2, Q=this->GetQExtRows();
    for(int i=1; i<=Q-1; i++){
        L1=Ls[i-1];
        L2=Ls[i+1-1];
        if(L1<L2){
            verdict=false;
        }
    }
    return verdict;
}

int Array2DSize_Prototype::GetQElements() const{
    int count=0, QER, curL;
    QER=this->GetQExtRows();
    for(int N=1; N<=QER; N++){
        curL=this->GetRowLength(N);
        count+=curL;
    }
    return count;
}

//class Array2DSize_Rectangular: public Array2DSize_Prototype{
//    int QExtRows, ExtRowLength;
//public:
    Array2DSize_Rectangular::Array2DSize_Rectangular(int QExtRows, int ExtRowLength){
        this->Set(ExtRowLength, QExtRows);
    }
    //
    Array2DSize_Rectangular:: ~Array2DSize_Rectangular(){}
    //
    void Array2DSize_Rectangular::SetNull(){
        this->QExtRows=0;
        this->ExtRowLength=0;
    }
    void Array2DSize_Rectangular::SetNullIni(){
        this->QExtRows=0;
        this->ExtRowLength=0;
    }
    void Array2DSize_Rectangular::SetOne(){
        this->QExtRows=1;
        this->ExtRowLength=1;
    }
    //
    void Array2DSize_Rectangular::Assign(Array2DSize_Prototype*obj){
        if(obj->IsRectangularInFact()){
            this->ExtRowLength=obj->GetRowLength();
            this->QExtRows=obj->GetQExtRows();
        }else{
            //NOp;//or better:
            this->ExtRowLength=obj->GetRowLengthMax();
            this->QExtRows=obj->GetQExtRows();
        }
    }
    //
    void Array2DSize_Rectangular::Set(int* extRowsLengthes, int QExtRows){
        int mn, mx, curL;
        if(QExtRows>-1){
            this->QExtRows=QExtRows;
        }
        if(QExtRows>0){
            if(extRowsLengthes!=NULL){
                for(int i=1; i<=QExtRows; i++){
                    curL=extRowsLengthes[i-1];
                    if(i==1 || (i>1 && curL>mx)){
                        mx=curL;
                    }
                    if(i==1 || (i>1 && curL<mn)){
                        mn=curL;
                    }
                }
                //if(mn==mx){
                //    this->ExtRowLength=mx;
                //}
                this->ExtRowLength=mx;
            }else{
                this->ExtRowLength=0;
            }
        }else{
            this->QExtRows=0;
        }
    }
    //
    void Array2DSize_Rectangular::Set(int extRowsLength, int QExtRows){
         this->QExtRows=QExtRows;
         this->ExtRowLength=ExtRowLength;
    }
    //
    int Array2DSize_Rectangular::GetQExtRows() const {
        return this->QExtRows;
    }
    int Array2DSize_Rectangular::GetRowLength(int N) const {
        return this->ExtRowLength;
    }
    int Array2DSize_Rectangular::GetRowLengthMin() const {
        return this->ExtRowLength;
    }
    int Array2DSize_Rectangular::GetRowLengthMax() const {
        return this->ExtRowLength;
    }
    std::vector<int> Array2DSize_Rectangular::GetLengthes() const {
        std::vector<int>Ls;
        for(int i=1; i<=this->QExtRows; i++){
            Ls.push_back(this->ExtRowLength);
        }
        return Ls;
    }
    std::vector<int> Array2DSize_Rectangular::GetMinLengthRowNs() const {
        std::vector<int>Ns;
        for(int i=1; i<=this->QExtRows; i++){
            Ns.push_back(i);
        }
        return Ns;
    }
    std::vector<int> Array2DSize_Rectangular::GetMaxLengthRowNs() const {
        std::vector<int>Ns;
        for(int i=1; i<=this->QExtRows; i++){
            Ns.push_back(i);
        }
        return Ns;
    }
    //int Array2DSize_Rectangular::GetQElements() const{
    //    return this->QExtRows*this->ExtRowLength;
    //}
    //
    bool Array2DSize_Rectangular::IsRectangularByType() const {
        return true;
    }
    bool Array2DSize_Rectangular::IsRectangularInFact() const {
        return true;
    }
    bool Array2DSize_Rectangular::IsEmpty() const {
        return (this->QExtRows==0 || this->ExtRowLength==0);
    }
    int Array2DSize_Rectangular::GetTypeN() const{
        return Array2DSize_Rectangular_TypeN;
    }
    //
    int Array2DSize_Rectangular::SetRowLength(int L, int N)  {
        this->ExtRowLength=L;
    }
    int Array2DSize_Rectangular::SetQExtRows(int Q, int IfNotRect_ERL_ByMin1ByMax2ByLast3){
        this->QExtRows=Q;
    }
    //

    //
    void Array2DSize_Rectangular::AddExtRow(int L, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4){//
        //SIMPLE: Lmin==Lmax
        if(L==0 || L==this->ExtRowLength){
            this->QExtRows+=1;
        }else{
            switch(ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4){
                case 0:
                    //NOp; Default means ignore
                break;
                case 1:
                    this->QExtRows+=1;//
                break;
                case 2:
                    this->QExtRows+=1;
                    this->ExtRowLength=L;
                break;
                case 3:
                    this->QExtRows+=1;
                    if(L>this->ExtRowLength){
                        this->ExtRowLength=L;
                    }
                break;
                case 4:
                    this->QExtRows+=1;
                    if(L<this->ExtRowLength){
                        this->ExtRowLength=L;
                    }
                break;
            }
        }
    }

    void Array2DSize_Rectangular::AddExtRow(int L, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4){//
        //SIMPLE: Lmin==Lmax
        if(L==0 || L==this->ExtRowLength){
            this->QExtRows+=1;
        }else{
            switch(ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4){
                case 0:
                    //NOp; Default means ignore
                break;
                case 1:
                    this->QExtRows+=1;//
                break;
                case 2:
                    this->QExtRows+=1;
                    this->ExtRowLength=L;
                break;
                case 3:
                    this->QExtRows+=1;
                    if(L>this->ExtRowLength){
                        this->ExtRowLength=L;
                    }
                break;
                case 4:
                    this->QExtRows+=1;
                    if(L<this->ExtRowLength){
                        this->ExtRowLength=L;
                    }
                break;
            }
        }
    }

    void Array2DSize_Rectangular::InsExtRow(int N, int L, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4){
        int minL=this->GetRowLengthMin();
        if(N<0){
            N+=(this->QExtRows+1);
        }
        if(N>=1 && N<=minL){
            this->AddExtRow(L, ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4);//for rect onlly
        }
    }

    //virtual void AddExtRow(int L=0, int ifRectangularAndNotEqual_Ignore0ByOld1ByNew2ByMax3ByMin4=1);
    //virtual void InsExtRow(int N=0, int L=0, int ifRectangularAndNotEqual_Ignore0ByOld1ByNew2ByMax3ByMin4=1);
    void Array2DSize_Rectangular::DelExtRow(int N){
        int minL=this->GetRowLengthMin();
        if(N<0){
            N+=(this->QExtRows+1);
        }
        if(N>=1 && N<=minL){
            this->QExtRows--;
        }
    }
    //
    Coords2DInt Array2DSize_Rectangular::AddIneRow_Coords(int ElementN,          int L, int IfNotSameQER_ByOld1ByNew2ByMax3ByMin4){
        Coords2DInt coords;
        Array2DSize_Rectangular SizeNew;
        SizeNew.Assign(this);
        int  QER=this->GetQExtRows(),  minQ = L <= QER ? L : QER,  maxQ = L >= QER ? L : QER;
        SizeNew.AddExtRow(L, IfNotSameQER_ByOld1ByNew2ByMax3ByMin4);
        if(L==0 || L==this->ExtRowLength){
             //this->QExtRows+=1;
             coords.set(ElementN, this->QExtRows+1);
        }else{
            switch(IfNotSameQER_ByOld1ByNew2ByMax3ByMin4){
                case 0:
                    //NOp; Default means ignore
                break;
                case 1://old
                    //this->QExtRows+=1;
                    if(ElementN>=1 && ElementN<=QER){
                        coords.set(ElementN, this->QExtRows+1);
                    }
                break;
                case 2://new
                    //this->QExtRows+=1;
                    //this->ExtRowLength=L;
                    if(ElementN>=1 && ElementN<=L){
                        coords.set(ElementN, this->QExtRows+1);//
                    }
                break;
                case 3://max
                    //this->QExtRows+=1;
                    //if(L>this->ExtRowLength){
                    //    this->ExtRowLength=L;
                    //}
                    if(ElementN>=1 && ElementN<=maxQ){
                        coords.set(ElementN, this->QExtRows+1);//
                    }
                break;
                case 4:
                    //this->QExtRows+=1;
                    //if(L<this->ExtRowLength){
                    //    this->ExtRowLength=L;
                    //}
                    if(ElementN>=1 && ElementN<=minQ){
                        coords.set(ElementN, this->QExtRows+1);//
                    }
                break;
            }
        }
        return coords;
    }

    //
    void Array2DSize_Rectangular::AddIneRow(int L, int IfNotSameQER_ByOld1ByNew2ByMax3ByMin4){
        this->ExtRowLength+=1;
        if(L>this->QExtRows && (IfNotSameQER_ByOld1ByNew2ByMax3ByMin4==2 || IfNotSameQER_ByOld1ByNew2ByMax3ByMin4==3) ){
            this->QExtRows=L;
        }else if(L<this->QExtRows && (IfNotSameQER_ByOld1ByNew2ByMax3ByMin4==2 || IfNotSameQER_ByOld1ByNew2ByMax3ByMin4==4) ){
            this->QExtRows=L;
        }
    }
    void Array2DSize_Rectangular::InsIneRow(   int N, int L, int IfNotSameQER_ByOld1ByNew2ByMax3ByMin4){
        if(N<0){
            N+=(this->ExtRowLength+1);
        }
        this->AddIneRow(L, IfNotSameQER_ByOld1ByNew2ByMax3ByMin4);
    }
    void Array2DSize_Rectangular::DelIneRow(int N){
        if(N<0){
            N+=(this->ExtRowLength+1);
        }
        if(N>=1 && N<=this->ExtRowLength){
           this->ExtRowLength--;
        }
    }

    Coords2DInt Array2DSize_Rectangular::InsIneRow_Coords(int ElementN, int N, int L, int IfNotSameQER_ByOld1ByNew2ByMax3ByMin4){
        Coords2DInt coords;
        Array2DSize_Rectangular SizeNew;
        SizeNew.Assign(this);
        int  QER=this->GetQExtRows(), minQ = L <= QER ? L : QER, maxQ = L >= QER ? L : QER;
        SizeNew.AddExtRow(L, IfNotSameQER_ByOld1ByNew2ByMax3ByMin4);
        if(L==0 || L==this->ExtRowLength){
            this->QExtRows+=1;
        }else{
            switch(IfNotSameQER_ByOld1ByNew2ByMax3ByMin4){
                case 0:
                    //NOp; Default means ignore
                break;
                case 1://old
                    //this->QExtRows+=1;
                    if(ElementN>=1 && ElementN<=QER){
                        coords.set(ElementN, this->QExtRows+1);
                    }
                break;
                case 2://new
                    //this->QExtRows+=1;
                    //this->ExtRowLength=L;
                    if(ElementN>=1 && ElementN<=L){
                        coords.set(ElementN, this->QExtRows+1);//
                    }
                break;
                case 3://max
                    //this->QExtRows+=1;
                    //if(L>this->ExtRowLength){
                    //    this->ExtRowLength=L;
                    //}
                    if(ElementN>=1 && ElementN<=maxQ){
                        coords.set(ElementN, this->QExtRows+1);//
                    }
                break;
                case 4:
                    //this->QExtRows+=1;
                    //if(L<this->ExtRowLength){
                    //    this->ExtRowLength=L;
                    //}
                    if(ElementN>=1 && ElementN<=minQ){
                        coords.set(ElementN, this->QExtRows+1);//
                    }
                break;
            }
        }
        return coords;
    }
    //
    //void Array2DSize_Rectangular::AddIneRow(int EachExtRowIfVariaLen_Ignore0_AddToEach1_StretchToMax2, int L, int IfNotSameQER_ByOld1ByNew2ByMax3ByMin4){
    //    //
    //    if(L!=this->ExtRowLength){
    //        switch(IfNotSameQER_ByOld1ByNew2ByMax3ByMin4){
    //            case 0:
    //                //Nop;
    //            break;
    //            case 1:
    //                //Nop;
    //            break;
    //            case 2:
    //                this->QExtRows=L;
    //            break;
    //            case 3:
    //                if(L>this->QExtRows){
    //                    this->QExtRows=L;
    //               }
    //            break;
    //            case 4:
    //                if(L<this->QExtRows){
    //                    this->QExtRows=L;
    //                }
    //            break;
    //        }
    //        if(IfNotSameQER_ByOld1ByNew2ByMax3ByMin4!=0){
    //            this->ExtRowLength++;
    //        }
    //    }else{
    //        this->ExtRowLength++;
    //    }
    //}
    //void Array2DSize_Rectangular::InsIneRow(int N, int EachExtRowIfVariaLen_Ignore0_AddToEach1_StretchToMax2_StretchToN3, int L, int IfNotSameQER_ByOld1ByNew2ByMax3ByMin4){
    //    //
    //    if(N<0){
    //        N+=(this->ExtRowLength+1);
    //    }
    //    if(N>=1 && N<=this->ExtRowLength){
    //        this->AddIneRow(EachExtRowIfVariaLen_Ignore0_AddToEach1_StretchToMax2_StretchToN3, L, IfNotSameQER_ByOld1ByNew2ByMax3ByMin4);//for this type only
    //    }
    //}
    //void Array2DSize_Rectangular::DelIneRow(int N){
    //    if(N<0){
    //        N+=(this->ExtRowLength+1);
    //    }
    //    if(N>=1 && N<=this->ExtRowLength && this->QExtRows>0){
    //        this->ExtRowLength--;
    //    }
    //}
    //
    void Array2DSize_Rectangular::AddOrInsToExtRowN(int N){
        //NOp: ignoring
    }
    void Array2DSize_Rectangular::DelFromExtRowN(int N){
         //NOp: ignoring
    }
    //
    void Array2DSize_Rectangular::SwapExtRows(int N1, int N2){
        //NOp: ignoring
    }
    //void SwapIneRows(int N1, int N2)=0;//No need
    void Array2DSize_Rectangular::ReverseExtRows(){
        //NOp: ignoring
    }
    void Array2DSize_Rectangular::ShiftExtRowsCyclelyToBegin(){
        //NOp: ignoring
    }
    void Array2DSize_Rectangular::ShiftExtRowsCyclelyToEnd(){
        //NOp: ignoring
    }
    //
    void Array2DSize_Rectangular::Transpose(){
        int buf=this->QExtRows;
        this->QExtRows=this->ExtRowLength;
        this->ExtRowLength=buf;
    }

    Coords2DInt Array2DSize_Rectangular::Transpose_Coords(const Coords2DInt&element){
        Coords2DInt elementNew;
        //int buf=this->QExtRows;
        //this->QExtRows=this->ExtRowLength;
        //this->ExtRowLength=buf;
        int ERN_given=element.GetX1(), IRN_given=element.GetX2();
        if(this->IsForTranspose() && ERN_given >= 1 && ERN_given <=this->ExtRowLength && IRN_given >= 1 && IRN_given <=this->QExtRows){
            elementNew.set(IRN_given, ERN_given);
        }
        return elementNew;
    }
    int Array2DSize_Rectangular::GetLengthOfIneRowN_FromFirstNoEmptyPoss(int N) const{
        return this->ExtRowLength;
    }
    //bool Array2DSize_Rectangular::IsForTranspose() const{
    //    ;
    //}
    //
    void Array2DSize_Rectangular::ConcatAdding(Array2DSize_Prototype*obj, int shiftQ){
        int obj_QExtRows=obj->GetQExtRows(), obj_ExtRowLength=obj->GetRowLengthMax();
        this->QExtRows=this->QExtRows+obj->GetQExtRows();
        if(shiftQ>=0 && this->ExtRowLength<shiftQ+obj_ExtRowLength){
            this->ExtRowLength=shiftQ+obj_ExtRowLength;
        }else if(shiftQ<0){
            if(-shiftQ+obj_ExtRowLength>this->ExtRowLength){
                this->ExtRowLength=-shiftQ+obj_ExtRowLength;
            }else{
                this->ExtRowLength=-shiftQ+this->ExtRowLength;
            }
        }
    }
    void Array2DSize_Rectangular::ConcatStretching(Array2DSize_Prototype*obj, int shiftQ){
        int obj_QExtRows=obj->GetQExtRows(), obj_ExtRowLength=obj->GetRowLengthMax();
        this->ExtRowLength+=obj->GetRowLengthMax();
        if(shiftQ>=0){
            if(shiftQ+obj_ExtRowLength > this->ExtRowLength){
                this->ExtRowLength=shiftQ+obj_ExtRowLength;
            }
        }else{
            if(-shiftQ+obj_QExtRows>this->QExtRows){
                this->QExtRows=-shiftQ+obj_QExtRows;
            }else{
                this->QExtRows=-shiftQ;
            }
        }
    }

    //
    void Array2DSize_Rectangular::SubArray(const TDataShiftParams&DataShift, int Ldflt){
        TDataShiftResults Ns=DataShift.Calc(this->QExtRows);
        this->QExtRows=Ns.Lcalc;//for this type S'satq
    }

    void Array2DSize_Rectangular::SubArray(const TDataShiftParams&DataShift, Array2DSize_Prototype*objDflt){
        TDataShiftResults Ns=DataShift.Calc(this->QExtRows);
        this->QExtRows=Ns.Lcalc;//for this type S'satq
    }

//};

//class Array2DSize_VariaLength: public Array2DSize_Prototype{
//    int QExtRows;
//    int*ExtRowLengthes;
//public:
    Array2DSize_VariaLength::Array2DSize_VariaLength(int QExtRows, int ExtRowLength){
        for(int i=1; i<=QExtRows; i++){
            this->Lengthes.push_back(ExtRowLength);
        }
    }
    Array2DSize_VariaLength::Array2DSize_VariaLength(int QExtRows, int*ExtRowLength){
        if(QExtRows>0){
            for(int i=1; i<=QExtRows; i++){
                this->Lengthes.push_back(ExtRowLength[i-1]);
            }
        }
    }
    //
    Array2DSize_VariaLength:: ~Array2DSize_VariaLength(){}
    //
    void Array2DSize_VariaLength::SetNull(){
        //this->QExtRows=0;
        //if(this->ExtRowLength!=NULL){
        //    delete this->ExtRowLength;
        //}
        //this->Lengthes=NULL;
        this->Lengthes.clear();
    }
    void Array2DSize_VariaLength::SetNullIni(){
        //this->QExtRows=0;
        //this->Lengthes=NULL;
        //
        //NOp;
    }
    void Array2DSize_VariaLength::SetOne(){
        //this->QExtRows=1;
        //this->Lengthes=1;
        this->SetNull();
        this->Lengthes.push_back(1);
    }
    //
    void Array2DSize_VariaLength::Assign(Array2DSize_Prototype*obj){
        this->SetNull();
        int obj_QER=obj->GetQExtRows(), L;
        for(int i=1; i<=obj_QER; i++){
            L=obj->GetRowLength(i);
            this->Lengthes.push_back(L);
        }
    }
    //
    void Array2DSize_VariaLength::Set(int* extRowsLengthes, int QExtRows){
        int L;
        this->SetNull();
        if(QExtRows>0 && extRowsLengthes!=NULL){
            for(int i=1; i<=QExtRows; i++){
                L=this->GetRowLength(i);
                this->Lengthes.push_back(L);
            }
        }
    }
    void Array2DSize_VariaLength::Set(int extRowsLength, int QExtRows){
        this->SetNull();
        if(QExtRows>0){
            for(int i=1; i<=QExtRows; i++){
                this->Lengthes.push_back(extRowsLength);
            }
        }
    }
    //
    int Array2DSize_VariaLength:: GetQExtRows() const {
        return this->Lengthes.size();
    }
    int Array2DSize_VariaLength::GetRowLength(int N) const {
        int QER=this->GetQExtRows(), L=0;
        if(N<0){
            N+=(QER+1);
        }
        if(N>=1 && N<=QER){
            L=this->Lengthes[N-1];
        }

    }
    int Array2DSize_VariaLength::GetRowLengthMin() const {
        int mn, mx, QER=this->Lengthes.size(), curL;
        for(int i=1; i<=QER; i++){
            curL=this->Lengthes[i-1];
            if(i==1 || (i>1 && curL<mn)){
                mn=curL;
            }
            if(i==1 || (i>1 && curL>mx)){
                mx=curL;
            }
        }
        return mn;
    }
    int Array2DSize_VariaLength::GetRowLengthMax() const {
        int mn, mx, QER=this->Lengthes.size(), curL;
        for(int i=1; i<=QER; i++){
            curL=this->Lengthes[i-1];
            if(i==1 || (i>1 && curL<mn)){
                mn=curL;
            }
            if(i==1 || (i>1 && curL>mx)){
                mx=curL;
            }
        }
        return mx;
    }
    std::vector<int> Array2DSize_VariaLength::GetLengthes() const {
        return this->Lengthes;
    }
    std::vector<int> Array2DSize_VariaLength::GetMinLengthRowNs() const {
        std::vector<int>Ns;
        int QER=this->Lengthes.size(), curL, mn=this->GetRowLengthMin(), mx=this->GetRowLengthMax();
        for(int i=1; i<=QER; i++){
            curL=Lengthes[i-1];
            if(curL==mn){
                Ns.push_back(i);
            }
        }
        return Ns;
    }
    std::vector<int> Array2DSize_VariaLength::GetMaxLengthRowNs() const {
        std::vector<int>Ns;
        int QER=this->Lengthes.size(), curL, mn=this->GetRowLengthMin(), mx=this->GetRowLengthMax();
        for(int i=1; i<=QER; i++){
            curL=Lengthes[i-1];
            if(curL==mx){
                Ns.push_back(i);
            }
        }
        return Ns;
    }
    //int Array2DSize_VariaLength::GetQElements() const{
    //    int count=0;
    //    int QER=this->GetQ
    //    return count;
    //}
    //
    bool Array2DSize_VariaLength::IsRectangularByType() const { return false; }
    bool Array2DSize_VariaLength::IsRectangularInFact() const {
        return (this->GetRowLengthMax() == this->GetRowLengthMin());
    }
    bool Array2DSize_VariaLength::IsEmpty() const {
        return (this->Lengthes.size()==0 || this->GetRowLengthMax()==0);
    }
    int Array2DSize_VariaLength::GetTypeN() const{
        return Array2DSize_VariaLength_TypeN;
    }
    //
    int Array2DSize_VariaLength::SetRowLength(int L, int N){
        int QER=this->Lengthes.size();
        if(N<0){
            N+=(QER+1);
        }
        if(N>+1 && N<=QER && L>-1){
            this->Lengthes[N-1]=L;
        }
    }
    int Array2DSize_VariaLength::SetQExtRows(int Q, int IfNotRect_ERL_IfNotPositive_ByMin_m1_ByMax_m2_ByLast_m3){
        int Qold=this->GetQExtRows(), minL=this->GetRowLengthMin(), maxL=this->GetRowLengthMax(), L2;
        std::vector<int>Ls2;
        if(Q==0){
            this->Lengthes.clear();
        }else if(Q>Qold){
            if(minL==maxL){
                L2=maxL;
            }else if(IfNotRect_ERL_IfNotPositive_ByMin_m1_ByMax_m2_ByLast_m3==-1){
                L2=minL;
            }else if(IfNotRect_ERL_IfNotPositive_ByMin_m1_ByMax_m2_ByLast_m3==-2){
                L2=maxL;
            }else if(IfNotRect_ERL_IfNotPositive_ByMin_m1_ByMax_m2_ByLast_m3==-3){
                L2=this->GetRowLength(Qold);
            }else{
                L2=IfNotRect_ERL_IfNotPositive_ByMin_m1_ByMax_m2_ByLast_m3;
            }
            for(int i=Qold+1; i<=Q; i++){
                this->Lengthes.push_back(L2);
            }
        }else if(Q<Qold){
            for(int i=1; i<=Q; i++){
                L2=this->Lengthes[i-1];
                Ls2.push_back(L2);
            }
            this->Lengthes=Ls2;
        }
    }
    //
    //void Array2DSize_Rectangular::AddOrInsExtRow(){
    //    this->QExtRows+=1;
    //    //this->ExtRowLength+=1;
    //}
    //
    void Array2DSize_VariaLength::AddExtRow(int L, int ifRectangularAndNotEqual_Ignore0ByOld1ByNew2ByMax3ByMin4){
        //int minL=this->GetRowLengthMin(), maxL=this->GetRowLengthMax();
        //if(minL==maxL && L!=minL && ifRectangularAndNotEqual_Ignore0ByOld1ByNew2ByMax3ByMin4){
        //    switch(ifRectangularAndNotEqual_Ignore0ByOld1ByNew2ByMax3ByMin4){
        //        case 0:
        //
        //        break;
        //        case 1:
        //
        //        break;
        //        case 2:
        //
        //        break;
        //     }
        //}
        //ifRectangularAndNotEqual_Ignore0ByOld1ByNew2ByMax3ByMin4 ignored
        this->Lengthes.push_back(L);
    }
    void Array2DSize_VariaLength::InsExtRow(int N, int L, int ifRectangularAndNotEqual_Ignore0ByOld1ByNew2ByMax3ByMin4){
        int Q=this->Lengthes.size();
        if(Q>0){
            if(N<0){
                N+=(Q+1);
            }
            if(N>=1 && N<=Q){
                Arr1D_InsToN(this->Lengthes, N, L);
            }
        }
        //ifRectangularAndNotEqual_Ignore0ByOld1ByNew2ByMax3ByMin4 ignored
    }
    void Array2DSize_VariaLength::DelExtRow(int N){
        int Q=this->Lengthes.size();
        if(Q>0){
            if(N<0){
                N+=(Q+1);
            }
            if(N>=1 && N<=Q){
                Arr1D_DelN(this->Lengthes, N);
            }
        }
    }
    //
    //void Array2DSize_VariaLength::AddIneRow(int EachExtRowIfVariaLen_Ignore0_AddToEach1_StretchToMax2, int L, int IfNotSameQER_ByOld1ByNew2ByMax3ByMin4){
    //
    //}

    //void Array2DSize_VariaLength::AddIneRow(int EachExtRowIfVariaLen_Ignore0_AddToEach1_StretchToMax2, int L, int IfNotSameQER_ByOld1ByNew2ByMax3ByMin4){
    //    int QER=this->GetQExtRows(), minL=this->GetRowLengthMin(), maxL=this->GetRowLengthMax(), curL;
    //    if(minL==maxL){
    //        if(L==0 || L==QER){
    //
    //        }else if(L<QER){
    //
    //        }else{//L>QER
    //
    //        }
    //    }else{
    //        switch(EachExtRowIfVariaLen_Ignore0_AddToEach1_StretchToMax2){
    //            case 0:
    //                //NOp
    //            break;
    //            case 1://add to each
    //                if(L==0 || L==QER){
    //                    for(int i=1; i<=QER; i++){
    //                        this->Lengthes[i-1]+=1;
    //                    }
    //                }else if(L<QER){
    //                    for(int i=1; i<=L; i++){
    //                        this->Lengthes[i-1]+=1;
    //                    }
    //                }else{//L>QER
    //                    switch(IfNotSameQER_ByOld1ByNew2ByMax3ByMin4){
    //                        case 0:
    //                            //NOp
    //                        break;
    //                        case 1://old
    //                        case 4://min, QER<L
    //                            for(int i=1; i<=QER; i++){
    //                                this->Lengthes[i-1]+=1;
    //                            }
    //                        break;
    //                        case 2://new
    //                        case 3:
    //                            for(int i=1; i<=QER; i++){
    //                                this->Lengthes[i-1]+=1;
    //                            }
    //                            for(int i=QER+1; i<=L; i++){
    //                                this->Lengthes.push_back(1);
    //                            }
    //                        break;
    //                    }
    //                }
    //            break;
    //            case 2://stretch to max
    //                for(int i=1; i<=QER; i++){
    //                    this->Lengthes[i-1]=maxL;
    //                }
    //                if(L==0 || L==QER){
    //                    for(int i=1; i<=QER; i++){
    //                        this->Lengthes[i-1]+=1;
    //                    }
    //                }else if(L<QER){
    //                    for(int i=1; i<=L; i++){
    //                        this->Lengthes[i-1]+=1;
    //                    }
    //                }else{//L>QER
    //                    for(int i=1; i<=QER; i++){
    //                        this->Lengthes[i-1]+=1;
    //                    }
    //                    for(int i=QER+1; i<=L; i++){
    //                        this->Lengthes.push_back(maxL+1);
    //                    }
    //                }
    //            break;
    //        }
    //    }
    //}
    //void Array2DSize_VariaLength::InsIneRow(int N, int EachExtRowIfVariaLen_Ignore0_AddToEach1_StretchToN2, int L, int IfNotSameQER_ByOld1ByNew2ByMax3ByMin4){
    //    int QER=this->GetQExtRows(), minL=this->GetRowLengthMin();
    //    if((L==0 || L==QER) && (N==0 || N==minL)){
    //        for(int i=1; i<=QER; i++){
    //            this->Lengthes[i-1]+=1;
    //        }
    //    }else{
    //        if()
    //        if(N>minL){
    //
    //        }
    //    }
    //}
    void Array2DSize_VariaLength::AddIneRow(int L, int IfNotSameQER_Default0ByOld1ByNew2ByMax3ByMin4){

    }
    void Array2DSize_VariaLength::InsIneRow(int N, int L, int IfNotSameQER_Default0ByOld1ByNew2ByMax3ByMin4){}
    void Array2DSize_VariaLength::DelIneRow(int N){}
    //
    void Array2DSize_VariaLength::AddOrInsToExtRowN(int N){}
    void Array2DSize_VariaLength::DelFromExtRowN(int N){}
    //
    void Array2DSize_VariaLength::SwapExtRows(int N1, int N2){}
    //void SwapIneRows(int N1, int N2)=0{}//No need
    void Array2DSize_VariaLength:: ReverseExtRows(){}
    void Array2DSize_VariaLength::ShiftExtRowsCyclelyToBegin(){}
    void Array2DSize_VariaLength::ShiftExtRowsCyclelyToEnd(){}
    //
    void Array2DSize_VariaLength::Transpose(){

    }
    int Array2DSize_VariaLength::GetLengthOfIneRowN_FromFirstNoEmptyPoss(int N) const{}
    //bool Array2DSize_VariaLength::IsForTranspose() const{}
    //
    void Array2DSize_VariaLength::ConcatAdding(Array2DSize_Prototype*obj, int shiftQ){}
    void Array2DSize_VariaLength::ConcatStretching(Array2DSize_Prototype*obj, int shiftQ){}
    //
    void Array2DSize_VariaLength::SubArray(const TDataShiftParams&DataShift, int Ldflt){
        TDataShiftResults Ns=DataShift.Calc(this->GetQExtRows());
        std::vector<int>Ls;
        int L;//, QER;
        if(Ns.PreN2>0){
            for(int i=1; i<=Ns.PreN2; i++){
                Ls.push_back(Ldflt);
            }
        }
        if(Ns.OwnN2>0){
            for(int i=Ns.PreN1; i<=Ns.PreN2; i++){
                L=this->GetRowLength(i);
                Ls.push_back(L);
            }
        }
        if(Ns.PostN2>0){
            for(int i=1; i<=Ns.PreN2; i++){
                Ls.push_back(Ldflt);
            }
        }
        this->Lengthes=Ls;
        //this->QExtRows=Ns.Lcalc;QER=Ls.size();
    }

    void Array2DSize_VariaLength::SubArray(const TDataShiftParams&DataShift, Array2DSize_Prototype*objDflt){
        TDataShiftResults Ns=DataShift.Calc(this->GetQExtRows());
        std::vector<int>Ls;
        int L;
        if(Ns.PreN2>0){
            for(int i=1; i<=Ns.PreN2; i++){
                L=objDflt->GetRowLength(i);
                Ls.push_back(L);
            }
        }
        if(Ns.OwnN2>0){
            for(int i=Ns.PreN1; i<=Ns.PreN2; i++){
                L=this->GetRowLength(i);
                Ls.push_back(L);
            }
        }
        if(Ns.PostN2>0){
            for(int i=1; i<=Ns.PreN2; i++){
                L=objDflt->GetRowLength(i);
                Ls.push_back(L);
            }
        }
        this->Lengthes=Ls;
        //this->QExtRows=Ns.Lcalc;QER=Ls.size();
    }
//}{}

//class Array2DSize_Shell{
//    Array2DSize_Prototype*data{}
//public:
     //Array2DSize_Shell::Array2DSize_Shell(){//undef'd ref to vtable for Array2DSize_Shell
     //    this->data = new Array2DSize_Rectangular(0, 0);
     //}

    Array2DSize_Shell::Array2DSize_Shell(int QExtRows, int ExtRowLength, bool isRectangular){
        //std::vector<int>Ls;
        if(isRectangular){
            this->data = new Array2DSize_Rectangular(QExtRows, ExtRowLength);
        }else{
            this->data = new Array2DSize_VariaLength(QExtRows, ExtRowLength);
        }
    }
    Array2DSize_Shell::Array2DSize_Shell(int QExtRows, int*ExtRowLength, bool isRectangularIfIsInFact){
        int curL, minL, maxL;
        bool isRectByFact=false;
        if(isRectangularIfIsInFact){
            for(int i=1; i<=QExtRows; i++){
                curL=ExtRowLength[i-1];
                if( i==1 || (i>1 && curL<minL) ){
                    minL=curL;
                }
                if( i==1 || (i>1 && curL>maxL) ){
                    maxL=curL;
                }
            }
            if(minL==maxL){
                this->data = new Array2DSize_Rectangular(QExtRows, maxL);
                isRectByFact=true;
            }else{
                this->data = new Array2DSize_VariaLength(QExtRows, ExtRowLength);
            }
        }else{
            this->data = new Array2DSize_VariaLength(QExtRows, ExtRowLength);
        }
    }
    //
    Array2DSize_Shell::Array2DSize_Shell(const Array2DSize_Shell&obj){
        int thisTypeN=this->GetTypeN(), objTypeN=obj.GetTypeN();
        bool thisIsRectByType=this->IsRectangularByType(), objIsRectByType=obj.IsRectangularByType();
        if(objIsRectByType){
            if(thisIsRectByType){
                this->Set(obj.GetQExtRows(), obj.GetRowLengthMax());
            }else{
                delete this->data;
                this->data=new Array2DSize_VariaLength(obj.GetQExtRows(), obj.GetLengthes().data());
            }
        }else{
            if(thisIsRectByType){
                delete this->data;
                this->data=new Array2DSize_Rectangular(obj.GetQExtRows(), obj.GetRowLengthMax());
            }else{
                this->Set(obj.GetLengthes().data(), obj.GetQExtRows());
            }
        }
    }
    //
    Array2DSize_Shell::~Array2DSize_Shell(){
        delete this->data;
    }
    //
    void  Array2DSize_Shell::Assign(Array2DSize_Prototype*obj){
        //
        if(obj->IsRectangularByType()){
            if(this->IsRectangularByType()==false){
                if(this->data!=NULL){
                    delete this->data;
                }
                this->data=new Array2DSize_Rectangular(obj->GetQExtRows(), obj->GetRowLengthMax());
            }else{//this->IsRectangularByType()==true
                this->data->Set(obj->GetRowLengthMax(), obj->GetQExtRows());
            }
        }else{//obj->IsRectangularByType()==false
            if(this->IsRectangularByType()){
                if(this->data!=NULL){
                    delete this->data;
                }
                if(obj->IsRectangularInFact()){
                    this->data=new Array2DSize_VariaLength(obj->GetQExtRows(), obj->GetLengthes().data());
                }
            }else{//this->IsRectangularByType()==false
                this->data->Set(obj->GetLengthes().data(), obj->GetQExtRows());
            }
        }
    }
    void  Array2DSize_Shell::Assign(const Array2DSize_Shell&obj){
        this->Assign(obj.GetData());
    }
    //
    Array2DSize_Shell& Array2DSize_Shell::operator = (const Array2DSize_Shell&obj){
        this->Assign(obj);
        return *this;
    }
    //
    Array2DSize_Prototype* Array2DSize_Shell::GetData()const{
        return this->data;
    }
    //
    //
    void Array2DSize_Shell::SetTypeN(int TypeN){
        int thisTypeN=this->GetTypeN();
        std::vector<int>Ls=this->GetLengthes();
        int QER=this->GetQExtRows(), maxL=this->GetRowLengthMax();
        if(TypeN==Array2DSize_Rectangular_TypeN){
            if(thisTypeN==Array2DSize_VariaLength_TypeN){
                if(this->data!=NULL){
                    delete this->data;
                }
                this->data=new Array2DSize_Rectangular(QER, maxL);
            }else{//this->IsRectangularByType()==true
                //NOp; //this->data->Set(obj->GetRowLengthMax(), obj->GetQExtRows());
            }
        }else{//obj->IsRectangularByType()==false, typeN===Array2DSize_VariaLength_TypeN
            if(thisTypeN==Array2DSize_Rectangular_TypeN){
                if(this->data!=NULL){
                    delete this->data;
                }
                if(TypeN==Array2DSize_Rectangular_TypeN){
                    this->data=new Array2DSize_VariaLength(QER, Ls.data());
                }
            }else{//this->IsRectangularByType()==false
                this->data->Set(Ls.data(), QER);
            }
        }
    }
    void Array2DSize_Shell::Set(int* extRowsLengthes, int QExtRows, int TypeN){
        this->SetTypeN(TypeN);
        this->data->Set(extRowsLengthes, QExtRows);//if S'rect,
    }
    void Array2DSize_Shell::Set(int extRowsLength, int QExtRows, int TypeN){
        this->SetTypeN(TypeN);
        this->data->Set(QExtRows, extRowsLength);//if S'rect,
    }
    //
    int Array2DSize_Shell::GetQExtRows() const {}
    int Array2DSize_Shell::GetRowLength(int N) const {}
    int Array2DSize_Shell::GetRowLengthMin() const {}
    int Array2DSize_Shell::GetRowLengthMax() const {}
    std::vector<int> Array2DSize_Shell::GetLengthes() const {}
    std::vector<int> Array2DSize_Shell::GetMinLengthRowNs() const {}
    std::vector<int> Array2DSize_Shell::GetMaxLengthRowNs() const {}
    //
    bool Array2DSize_Shell::IsRectangularByType() const {
        return this->data->IsRectangularByType();
    }
    bool Array2DSize_Shell::IsRectangularInFact() const {
        return this->data->IsRectangularInFact();
    }
    bool Array2DSize_Shell::IsEmpty() const {
        return this->data->IsEmpty();
    }
    int Array2DSize_Shell::GetTypeN() const{
        return this->data->GetTypeN();
    }
    //
    int Array2DSize_Shell::SetRowLength(int L, int N){}
    int Array2DSize_Shell::SetQExtRows(int Q, int IfNotRect_ERL_ByMin1ByMax2ByLast3){}
    //
    void Array2DSize_Shell::AddExtRow(int L, int ifRectangularAndNotEqual_Ignore0ByOld1ByNew2ByMax3ByMin4){}
    void Array2DSize_Shell::InsExtRow(int N, int L, int ifRectangularAndNotEqual_Ignore0ByOld1ByNew2ByMax3ByMin4){}
    void Array2DSize_Shell::DelExtRow(int N){}
    //
    //void Array2DSize_Shell::AddIneRow(int EachExtRowIfVariaLen_Ignore0_AddToEach1_StretchToMax2, int L, int IfNotSameQER_ByOld1ByNew2ByMax3ByMin4){}
    //void Array2DSize_Shell::InsIneRow(int N, int EachExtRowIfVariaLen_Ignore0_AddToEach1_StretchToMax2, int L, int IfNotSameQER_ByOld1ByNew2ByMax3ByMin4){}
    void Array2DSize_Shell::AddIneRow(int L, int IfNotSameQER_ByOld1ByNew2ByMax3ByMin4){}
    void Array2DSize_Shell::InsIneRow(int N, int L, int IfNotSameQER_ByOld1ByNew2ByMax3ByMin4){}
    void Array2DSize_Shell::DelIneRow(int N){}
    //
    void Array2DSize_Shell::AddOrInsToExtRowN(int N){}
    void Array2DSize_Shell::DelFromExtRowN(int N){}
    //
    void Array2DSize_Shell::SwapExtRows(int N1, int N2){}
    //void SwapIneRows(int N1, int N2)=0{}//No need
    void Array2DSize_Shell::ReverseExtRows(){}
    void Array2DSize_Shell::ShiftExtRowsCyclelyToBegin(){}
    void Array2DSize_Shell::ShiftExtRowsCyclelyToEnd(){}
    //
    void Array2DSize_Shell::Transpose(){}
    int Array2DSize_Shell::GetLengthOfIneRowN_FromFirstNoEmptyPoss(int N) const{}
    bool Array2DSize_Shell::IsForTranspose() const{}
    //
    void Array2DSize_Shell::ConcatAdding(Array2DSize_Prototype*obj, int shiftQ){}
    void Array2DSize_Shell::ConcatStretching(Array2DSize_Prototype*obj, int shiftQ){}
    Array2DSize_Shell Array2DSize_Shell::ConcatAddingTo(Array2DSize_Prototype*obj, int shiftQ){}
    Array2DSize_Shell Array2DSize_Shell::ConcatStretchingTo(Array2DSize_Prototype*obj, int shiftQ){}
//}{}



int PosNInArr2DAs1D(int QER, int Ls[], int ExtRowN, int IneRowN, int L1D){
    int posN=0, Lcur, Lmax;
    for(int i=1; i<=QER; i++){
        Lcur=Ls[i-1];
        if(i==1 || (i>1 && Lmax>Lcur)){
            Lcur=Lmax;
        }
    }
    if(ExtRowN<0){
        ExtRowN+=(QER-1);
    }
    if(ExtRowN>=1 && ExtRowN<=QER){
        Lcur=Ls[ExtRowN-1];
        if(IneRowN<0){
            IneRowN+=(Lmax-1);
        }
        if(IneRowN>=1 && IneRowN<=Lcur){
            for(int i=1; i<=ExtRowN; i++){
                posN+=Ls[i-1];
            }
            posN+=IneRowN;
            //
            if(posN>=1 && (L1D==-1 || L1D>0 && posN<=L1D)){
                //NOp
            }else{
                posN=0;
            }
        }
    }
    return posN;
}
int PosNInArr2DAs1D(int IRL, int ExtRowN, int IneRowN, int L1D){
    int posN=0, QER;
    if(IRL>0 && IneRowN>=1 && IneRowN<=IRL){
        if(L1D>0){
            QER=L1D/IRL;
            if(ExtRowN<0){
             ExtRowN+=(QER-1);
            }
        }
        if(ExtRowN>=1 && ExtRowN<=QER){
            for(int i=1; i<=ExtRowN-1; i++){
                posN+=IRL;
            }
            posN+=IneRowN;
        }
        if(L1D>0 && posN>L1D){
            posN=0;
        }
    }
    return posN;
}

int PosNInArr2DAs1D_LC(int QER, int Ls[], int LineN, int ColN, int arr2DIsRowOfCols0Lines1){
    int posN=0, ExtRowN, IneRowN;
    if(arr2DIsRowOfCols0Lines1==1){
        ExtRowN=LineN;
        IneRowN=ColN;
    }else{
        ExtRowN=ColN;
        IneRowN=LineN;
    }
    posN=PosNInArr2DAs1D(QER, Ls, ExtRowN, IneRowN);
    return posN;
}

int PosNInArr2DAs1D_RLC(int QER, int Ls[], int LineN, int ColN){
    int posN=0, ExtRowN, IneRowN;
    ExtRowN=LineN;
    IneRowN=ColN;
    posN=PosNInArr2DAs1D(QER, Ls, ExtRowN, IneRowN);
    return posN;
}
int PosNInArr2DAs1D_RCL(int QER, int Ls[], int LineN, int ColN){
    int posN=0, ExtRowN, IneRowN;
    ExtRowN=ColN;
    IneRowN=LineN;
    posN=PosNInArr2DAs1D(QER, Ls, ExtRowN, IneRowN);
    return posN;
}

Coords2DInt PosOfSubArr2DElementInArr2D(int whereExtRowN_of11, int whereIneRowN_of11, int whatExtRowN, int whatIneRowN, int whatQER, int whatLs[], int ReversedRowOfExtRows=0, int EachExtRowIsReversed=0, int isTransposed=0){
    Coords2DInt whereCoordsFin;
    int whereExtRowN=0;
    int whereIneRowN=0;
    int MaxWhatL=0;
    int whatL;
    for(int i=1; i<=whatQER; i++){
        whatL=whatLs[i-1];
        if (i==1 or (i>1 and whatL>MaxWhatL)){
            MaxWhatL=whatL;
       }
    }
    if(isTransposed==0){
        if(ReversedRowOfExtRows==0){
            whereExtRowN=whereExtRowN_of11 + whatExtRowN - 1;
            if(EachExtRowIsReversed==0){
                // 11 12 13 14
                // 21 22
                // 31 32 33
                whereIneRowN=whereIneRowN_of11 + whatIneRowN -1;
            }else{
                // 14 13 12 11
                //       22 21
                //    33 32 31
                whereIneRowN=whereIneRowN_of11 + MaxWhatL - 1 - whatIneRowN;// iqv!
            }
        }else{//ReversedRowOfExtRows==1:
            whereExtRowN=whereExtRowN_of11 + whatQER -1 + (whatExtRowN - 1);
            if(EachExtRowIsReversed==0){
                // 31 32 33
                // 21 22
                // 11 12 13 14
                whereIneRowN=whereIneRowN_of11 + whatIneRowN - 1;
           }else{
                //    33 32 31
                //       22 21
                // 14 13 12 11
                whereIneRowN=whereIneRowN_of11 + MaxWhatL - 1 - whatIneRowN;
            }
        }
    }else{//isTransposed==1
        if(ReversedRowOfExtRows==0){
            whereIneRowN = whereIneRowN_of11 + whatExtRowN - 1;
            if(EachExtRowIsReversed==0){
                // 11 21 31
                // 12 22 32
                // 13    33
                // 14
                whereExtRowN = whereExtRowN_of11 + whatIneRowN - 1;
            }else{//if EachExtRowIsReversed==1
                // 14
                // 13    33
                // 12 22 32
                // 11 21 31
                whereExtRowN = whereExtRowN_of11 - whatExtRowN + 1;
            }
        }else{//ReversedRowOfExtRows==1:
            whereIneRowN = whereIneRowN_of11 + whatQER - 1 - whatExtRowN + 1; //I men os ver
            if(ReversedRowOfExtRows==0){
                // 31 21 11
                // 32 22 12
                // 33    13
                //      14
                whereExtRowN = whereExtRowN_of11 + whatIneRowN - 1;
            }else{
                //       14
                // 33    13
                // 32 22 12
                // 31 21 11
                whereExtRowN = whereExtRowN_of11 + whatIneRowN - 1;
            }
        }
    }
    whereCoordsFin.x=whereExtRowN;
    whereCoordsFin.y=whereIneRowN;
    return whereCoordsFin;
}

template<typename T> Array2DSize_Shell GetSizeOfVector2D(std::vector<std::vector<T>> data){
    std::vector<int>Ls;
    int minL, maxL, QER, curL;
    QER=data.size();
    Array2DSize_Shell size;
    if(QER>0){
        for(int N=1; N<=QER; N++){
            curL=data[N-1].size();
            if(N==1 || (N>1 && curL<minL)){
                minL=curL;
            }
            if(N==1 || (N>1 && curL>maxL)){
                maxL=curL;
            }
            Ls.push_back(curL);
        }
        size.Set(Ls.data(), Ls.size());
    }
    return size;
}


//class Coords2DInt{
//    int x, y;
    Coords2DInt::Coords2DInt(int x, int y){
        this->set(x, y);
    }

    void Coords2DInt::set(int x, int y){
        this->x=x;
        this->y=y;
        //this->z=z;
    }
    int Coords2DInt::GetSize() const{
        return 2;
    }

    int Coords2DInt::GetX1() const{
        return this->x;
    }

    int Coords2DInt::GetX2() const{
        return this->y;
    }
    //int Coords2DInt::GetX3(){
    //    return this->z;
    //}
    int Coords2DInt::GetX() const{
        return this->x;
    }
    int Coords2DInt::GetY() const{
        return this->y;
    }
    //int Coords2DInt::GetZ(){
    //    return this->z;
    //}
    void Coords2DInt::SetX1(int val){
        this->x=val;
    }
    void Coords2DInt::SetX2(int val){
        this->y=val;
    }
    //void Coords2DInt::SetX3(int val){
    //    this->z=val;
    //}
    void Coords2DInt::SetX(int val){
        this->x=val;
    }
    void Coords2DInt::SetY(int val){
        this->y=val;
    }
    //void Coords2DInt::SetZ(int val){
    //    this->z=val;
    //}

//};


