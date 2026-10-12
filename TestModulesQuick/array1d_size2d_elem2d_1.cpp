#include "array1d_size2d_elem2d_1.h"

//array1d_size2D_elem2D_1::array1d_size2D_elem2D_1()
//{
//
//}

//class Coords2DInt{
//public:
 //   int x, y;
    Coords2DInt::Coords2DInt(int x, int y){
        this->set(x,y);
    }

    void Coords2DInt::set(int x, int y){
        this->x=x;
        this->y=y;
    }
    int Coords2DInt::GetSize() const{

    }
    int Coords2DInt::GetX1() const{
        return this->x;
    }
    int Coords2DInt::GetX2() const{
        return this->y;
    }
    int Coords2DInt::GetX3() const{

    }
    int Coords2DInt::GetX() const{
        return this->x;
    }
    int Coords2DInt::GetY() const{
        return this->y;
    }
    int Coords2DInt::GetZ() const{

    }
    void Coords2DInt::SetX1(int val){
        this->x=val;
    }
    void Coords2DInt::SetX2(int val){
        this->y=val;
    }
    void Coords2DInt::SetX3(int val){

    }
    void Coords2DInt::SetX(int val){
        this->x=val;
    }
    void Coords2DInt::SetY(int val){
        this->y=val;
    }
    void Coords2DInt::SetZ(int val){

    }
    bool Coords2DInt::IsNull(){
         return (this->x==0 && this->y==0);
    }
    //Coords2DInt& operator = (const Coords2DInt& obj);// n'nod ob no dyn objs
//};//Coords2DInt

//Array1D_Size2D::Array1D_Size2D()
//{
TDataShiftResults::TDataShiftResults(){
    this->ForOwnN1=0;
    this->ForOwnN2=0;
    this->Lcalc=0;
    this->OwnN1=0;
    this->OwnN2=0;
    this->PostN1=0;
    this->PostN2=0;
    this->PreN1=0;
    this->PreN2=0;
}
QString TDataShiftResults::ToString(){
    QString str="", sn;
    str="ForOwnN1=";
    sn.setNum(this->ForOwnN1);
    str+=sn;
    str+=" ";
    str="ForOwnN2=";
    sn.setNum(this->ForOwnN2);
    str+=sn;
    str+=" ";
    str="OwnN1=";
    sn.setNum(this->OwnN1);
    str+=sn;
    str+=" ";
    str="OwnN2=";
    sn.setNum(this->OwnN2);
    str+=sn;
    str+=" ";
    str="PostN1=";
    sn.setNum(this->PostN1);
    str+=sn;
    str+=" ";
    str="PostN2=";
    sn.setNum(this->PostN2);
    str+=sn;
    str+=" ";
    str="PreN1=";
    sn.setNum(this->PreN1);
    str+=sn;
    str+=" ";
    str="PreN2=";
    sn.setNum(this->PreN2);
    str+=sn;
    return str;
}

//}
//class TDataShiftParams{
//public:
//    int QDefaultsBefore, FirstN, Lreq;
    TDataShiftParams::TDataShiftParams(int FirstN, int QDefaultsBefore, int Lreq){
        this->FirstN=FirstN; this->QDefaultsBefore=QDefaultsBefore; this->Lreq=Lreq;
    }

    TDataShiftResults TDataShiftParams::Calc(int Lown, int vsh) {
            TDataShiftResults data;
            int LOwnTakenMax=Lown-this->FirstN+1;
            int LOwnTakenRe;//=this->QDefaultsBefore+LOwnTaken;
            int QAfter=0;
            if(vsh==1){
                printf("\nTDataShiftParams::Calc1 starts working\n");
                printf("Given: FirstN=%d, Lreq=%d, QDefaultsBefore=%d; Lown=%d\n",this->FirstN, this->Lreq, this->QDefaultsBefore, Lown);
                printf("LOwnTakenMax=%d\n",LOwnTakenMax);
            }
            if(this->Lreq==0){
                this->Lreq=this->FirstN+LOwnTakenMax-1;
            }
            //if(this->FirstN>Lown || this->QDefaultsBefore>=Lreq || this->FirstN>this->Lreq-this->QDefaultsBefore){
            if(this->FirstN>Lown || this->QDefaultsBefore>=Lreq ){
                data.PreN1=1;
                data.PreN2=this->Lreq;
                if(vsh==1){
                    if(this->FirstN>Lown){
                        printf(".FirstN>Lown ");
                    }
                    if(this->QDefaultsBefore>this->Lreq){
                        printf(".QDefaultsBefore>=.Lreq ");
                    }
                    if(this->FirstN>this->Lreq-this->QDefaultsBefore){
                        printf(".FirstN>=Lreq-QDefaultsBefore ");
                    }
                    printf("\n");
                    printf("Data: cannot be displayed .PreN1=1=%d, .PreN2=Lreq=%d\n",data.PreN1, data.PreN2);
                }
            }else{
                if(vsh==1){
                    printf("data can be displayed\n");
                }
                if(this->QDefaultsBefore>0){
                    data.PreN1=1;
                    data.PreN2=this->QDefaultsBefore;
                }
                data.OwnN1=this->FirstN;
                data.ForOwnN1=data.PreN2+1;
                if(this->QDefaultsBefore>+LOwnTakenMax>this->Lreq){
                    data.ForOwnN2=this->Lreq;
                    LOwnTakenRe=data.ForOwnN2-data.ForOwnN1+1;
                    data.OwnN2=data.OwnN1+LOwnTakenRe-1;
                    if(vsh==1){
                        printf("not whole data can be displayed\n");
                    }
                }else{
                    data.OwnN2=data.OwnN1+LOwnTakenMax-1;
                    data.ForOwnN2=data.ForOwnN1+LOwnTakenMax-1;
                    data.PostN1=data.ForOwnN2+1;
                    data.PostN2=this->Lreq;
                    if(vsh==1){
                        printf("whole data can be displayed\n");
                    }
                }
                if(vsh==1){
                    printf(".ForOwnN1=%d .ForOwnN2=%d .OwnN1=%d .OwnN2=%d\n", data.ForOwnN1, data.ForOwnN2, data.OwnN1, data.OwnN2);
                }
            }
            if(vsh==1){
                printf("; .PreN1=%d, .PreN2=%d\n", data.PreN1, data.PreN2);
                printf("TDataShiftParams::Calc1 finishes working\n");
            }
            return data;
        }//Calc

    //    void TDataShiftParams::SetDefault(){
    //        this->FirstN=1;
    //        this->Lreq=0;
    //        this->QDefaultsBefore=0;
    //    }
        void TDataShiftParams::Set(int FirstN, int QDefaultsBefore, int Lreq){
            this->FirstN=FirstN;
            this->Lreq=Lreq;
            this->QDefaultsBefore=QDefaultsBefore;
        }

        QString TDataShiftParams::ToString(){
            QString str="", sn;
            str+="FirstN=";
            sn.setNum(this->FirstN);
            str+=sn;
            str+=" ";
            str+=" Lreq=";
            sn.setNum(this->Lreq);
            str+=sn;
            str+=" ";
            str+=" QDefaultsBefore=";
            sn.setNum(this->QDefaultsBefore);
            str+=sn;
            // str+=" ";
            return str;
        }
        int TDataShiftParams::ArrayElementNToSubArrayElementN(int ArrayElementN, int Lown){
            int SubArrayElementN=0, takenOwnN, shiftQ;
            TDataShiftResults data = this->Calc(Lown);
            if(data.ForOwnN2>0 && ArrayElementN>=data.ForOwnN1 && ArrayElementN<=data.ForOwnN2){
                shiftQ=data.ForOwnN1-data.OwnN1;
                takenOwnN=ArrayElementN-shiftQ;
                SubArrayElementN=takenOwnN-this->FirstN+1;
            }
        }
        int TDataShiftParams::SubArrayElementNToArrayElementN(int SubArrayElementN, int Lown){
            int ArrayElementN=0, takenN;
            TDataShiftResults data = this->Calc(Lown);
            if(data.OwnN2>0 && SubArrayElementN>=data.OwnN1 && SubArrayElementN<=data.OwnN2){
                takenN=SubArrayElementN-this->FirstN+1;
                ArrayElementN=data.ForOwnN1+takenN-1;
            }
            return ArrayElementN;
        }

    //};

        int NInArrIfNegative(int N, int Q){
            if(N<0){
                N+=(Q+1);
            }
            if(Q>0 && N>=1 && N<=Q){
                //N=Q;
                //NOp
            }else{
                N=0;
            }
            return N;
        }

        int Arr1DSubArrElementPosN(int whereQ, int whatQ, int whatN, int PosN, bool IsReversed){
            int whereN;
            if(IsReversed==false){
                whereN=PosN+whatN-1;
            }else{
               whereN=PosN-whatN+1;
            }
            return whereN;
        }


    //================================================= Array2D_Size =================================================

//    class Array2DSize_Prototype{
        Array2DSize_Prototype::~Array2DSize_Prototype(){}
        //
        std::vector<int> Array2DSize_Prototype::GetAsArrayOfExtRowsLengthes()const{  //new}
            std::vector<int> Ls;
            int QExtRows=this->GetQExtRows();
             int curL;
             for(int i=1; i<=QExtRows; i++){
                 curL=this->GetRowLength(i);
                 Ls.push_back(curL);
             }
             return Ls;
        }
        //
        void Array2DSize_Prototype::construct(){//SeNullIni is called
            this->SetNullIni();
        }
        //virtual void SetNull()=0;
        //virtual void SetNullIni()=0;
        //virtual void SetOne()=0;
        //
        //virtual int GetTypeN()=0;
        //
        //virtual void Assign(Array2DSize_Prototype*obj)=0; // q'virtual?
        //
        //virtual void Set(int* extRowsLengthes, int QExtRows=0)=0;
        //virtual void Set_rect(int extRowsLength, int QExtRows=0)=0;//may descr it generally or may leave it virtual
        //virtual void Set(std::vector<int>Ls)=0;
        //
        //virtual int GetQExtRows() const =0;
        //virtual int GetRowLength(int N=-1) const =0;
        int Array2DSize_Prototype::GetRowLengthMin() const{
            int Lmin, Lmax, curL;
            for(int i=0; i<this->GetQExtRows(); i++){
                curL=this->GetRowLength(i+1);
                if(i==0 || (i>0 && curL<Lmin)){
                    curL=Lmin;
                }
                if(i==0 || (i>0 && curL>Lmax)){
                    curL=Lmax;
                }
            }
            return Lmin;
        }
        int Array2DSize_Prototype::GetRowLengthMax() const{
            int Lmin, Lmax, curL;
            for(int i=0; i<this->GetQExtRows(); i++){
                curL=this->GetRowLength(i+1);
                if(i==0 || (i>0 && curL<Lmin)){
                    curL=Lmin;
                }
                if(i==0 || (i>0 && curL>Lmax)){
                    curL=Lmax;
                }
            }
            return Lmax;
        }

        std::vector<int>Array2DSize_Prototype::GetLengthes() const{
            std::vector<int> Ls;
            int QExtRows=this->GetQExtRows();
            int curL;
            for(int NN=1; NN<=QExtRows; NN++){
                curL=this->GetRowLength(NN);
                Ls.push_back(curL);
            }
            return Ls;
        }
        std::vector<int> Array2DSize_Prototype::GetMinLengthRowNs() const{
            std::vector<int>Ns;
            int minL=this->GetRowLengthMin();
            int QExtRows=this->GetQExtRows(), curL;
            for(int NN=1; NN<=QExtRows; NN++){
                curL=this->GetRowLength(NN);
                if(curL==minL){
                    Ns.push_back(NN);
                }
            }
            return Ns;
        }
        std::vector<int> Array2DSize_Prototype::GetMaxLengthRowNs() const{
            std::vector<int>Ns;
            int maxL=this->GetRowLengthMax();
            int QExtRows=this->GetQExtRows(), curL;
            for(int NN=1; NN<=QExtRows; NN++){
                curL=this->GetRowLength(NN);
                if(curL==maxL){
                    Ns.push_back(NN);
                }
            }
            return Ns;
        }
        int Array2DSize_Prototype::GetQElements() const{
            int count=0, QExtRows=this->GetQExtRows(), curL;
            for(int NN=1; NN<=QExtRows; NN++){
                curL=this->GetRowLength(NN);
                count+=curL;
            }
            return count;
        }
        //virtual Array2DSize_Prototype*GetSize_asPtr() const =0;
        //
        int Array2DSize_Prototype::Arr2DBy1D_PosNByCoords(int ExtRowN, int IneRowN) const{
            int PosN=0, QElements=this->GetQElements(), QExtRows=this->GetQExtRows(), curL, extRowL;
            if(ExtRowN<0){
                ExtRowN+=(QExtRows+1);
            }
            if(ExtRowN>=1 && ExtRowN<=QExtRows){
                extRowL=this->GetRowLength(ExtRowN);
                if(IneRowN<0){
                    IneRowN+=(extRowL+1);
                }
                if(IneRowN>=1 && IneRowN<=extRowL){
                    for(int curERN=1; curERN<=ExtRowN-1; curERN++){
                         curL= this->GetRowLength(curERN);
                         PosN+=curL;
                    }
                    PosN+=IneRowN;
                }
            }
            return PosN;
        }
        Coords2DInt Array2DSize_Prototype::Arr2DBy1D_CoordsByPosN(int PosN) const{
            Coords2DInt coords;
            int  QElements=0, QExtRows=this->GetQExtRows(), curL, extRowL, count=0, curERN =0, ExtRowN, IneRowN;
            for(int i=0; i<QExtRows; i++){
                curL=this->GetRowLength(i+1);
                QElements+=curL;
            }
            if(PosN>=1 && PosN<=QElements){
                while(count<PosN){
                    curERN+=1;
                    curL=this->GetRowLength(curERN);
                    count+=curL;
                }
                ExtRowN=curERN;
                if(count>PosN){
                    //ExtRowN--;
                    IneRowN=count-PosN;
                }
                coords.x=ExtRowN;
                coords.y=IneRowN;
            }
            return coords;
        }
        //int Arr2DBy1D_ExtRowNByPosN(int PosN) const;
        //int Arr2DBy1D_IneRowNByPosN(int PosN) const;
        //
        bool Array2DSize_Prototype::IsRectangularByType() const{
            bool verdict=(this->GetTypeN()==Arr2DSize_Rect_TypeN);
            return verdict;
        }
        bool Array2DSize_Prototype::IsRectangularInFact() const{
            int minL=this->GetRowLengthMin(), maxL=this->GetRowLengthMax();
            bool verdict=(minL==maxL);
            return verdict;
        }
        bool Array2DSize_Prototype::IsEmpty() const{
            int QExtRows=this->GetQExtRows(),  Lmin=this->GetRowLengthMin(), Lmax=this->GetRowLengthMax();
            bool verdict=(QExtRows==0 || Lmin==0);
            return verdict;
        }
        int Array2DSize_Prototype::GetIneRowLength(int IRNN, bool countWhole) const{
            int IRL=0, QExtRows=this->GetQExtRows(), Lmax=this->GetRowLengthMax(), curL, ERNN;
            bool contin;
            if(IRNN<0){
                IRNN+=(Lmax+1);
            }
            if(IRNN>=1 && IRNN<=Lmax){
                //for(ERNN=1; ERNN<=QExtRows; ERNN++){
                //    curL=this->GetRowLength(ERNN);
                //    if(curL>=IRNN){
                //        IRL+=1;
                //    }
                //    if(curL==0){
                //        break;
                //    }
                //}
                contin=true;
                ERNN=0;
                while(contin){
                    ERNN+=1;
                    curL=this->GetRowLength(ERNN);
                    if(curL>=IRNN){
                        IRL+=1;
                    }
                    if( ERNN>=QExtRows || (curL<IRNN && countWhole==false)){
                        contin==false;
                    }
                }
            }
            return IRL;
        }

        bool Array2DSize_Prototype::isTransposable(){
            bool verdict=true;
            int QExtRows=this->GetQExtRows(), Lmax=this->GetRowLengthMax(), curL, IRL, IRL_prev;
            for(int IRNN=1; IRNN<=Lmax; IRNN++){
                if(IRNN>1){
                    IRL_prev=IRL;
                }
                IRL=this->GetIneRowLength(IRNN, false);
                if(IRL_prev>IRL){
                    verdict=false;
                }
            }
            return verdict;
        }

        //virtual int GetTypeN() const =0;
        //
        ////virtual void SetQExtRows(int Q, int IfNotRect_ERL_ByMin1ByMax2ByLast3)=0;//mab n'nod
        //
        //virtual void SetExtRowLength(int L, int NN_0ifAll=0, int FirstN=1, int QDefaultsBefore=0, int Lreq=0, int ifWasRectAndNotEqual_IgnoreAndLeaveByOld0_SetRectBy_New1_Max2_Min3_TransformToNonRectLTZero=1);

        // ---------------------------------------------------------------------------------------------

        void Array2DSize_Prototype::set_or_ins_ExtRow_simplyAsDataGiven_HilfsFun(int Action_Set1_Ins3, int ERNNGiven_0IfAll, const Coords2DInt&CoordsNew, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn, int&ERLNew, int&QExtRowsNew, int&DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0, int&InGivenRowPosN, Coords2DInt&CoordsOld){
            int QExtRowsOld=this->GetQExtRows();
            int Lmin=this->GetRowLengthMin(), Lmax=this->GetRowLengthMax(), LLast=this->GetRowLength(QExtRowsOld), ERNN=CoordsNew.x, IRNN=CoordsNew.y, ERLOld, theL;
            ERLNew=0;
            InGivenRowPosN=0;
            QExtRowsNew=QExtRowsOld;
            DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0=0;
            //Coords2DInt&CoordsOld)
            //givenL - f'rect s'dflt
            if(givenL==0 && Lmin==Lmax){
                givenL=Lmin;
            }
            //QExtRowsNew
            if(!(Lmin==Lmax && givenL!=Lmin && ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6==0)){
                if(Action_Set1_Ins3==3){
                    QExtRowsNew=QExtRowsOld+1;
                }//else remains = old
            }//else remains = old
            if(ERNN<0){
                ERNN+=(QExtRowsNew+1);
            }
            if(ERNNGiven_0IfAll<0){
                ERNNGiven_0IfAll+=(QExtRowsNew+1);
            }
            //addedL && ERLNew
            if(ERNNGiven_0IfAll==0 && Action_Set1_Ins3==1){
                theL=givenL;
                ERLNew=givenL;
            }else if(Lmin==Lmax && givenL==Lmin){
                theL=Lmin;
                ERLNew=Lmin;
            }else{
                switch(ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6){
                    case 0:
                        if(this->IsRectangularByType()){
                            //ignore
                            theL=0;
                            if(ERNN>=1 && ERNN<=QExtRowsOld){
                                ERLNew=this->GetRowLength(ERNN);
                            }
                        }else{
                            //
                            theL=givenL;
                            if(Action_Set1_Ins3==1){
                                ERLNew=this->GetRowLength(ERNN);//0 s'prg'd ovda
                            }else{//==3
                                if(ERNNGiven_0IfAll>=1 && ERNNGiven_0IfAll<=QExtRowsOld){
                                    if(ERNN>=1 && ERNN<=ERNNGiven_0IfAll){
                                        ERLNew=this->GetRowLength(ERNN);
                                    }else if(ERNN>ERNNGiven_0IfAll && ERNN<=QExtRowsNew){
                                        ERLNew=this->GetRowLength(ERNN-1);
                                    }else{// ==
                                        ERLNew=theL;
                                    }
                                }
                            }
                        }
                    break;
                    case 1:
                        theL=givenL;
                        ERLNew=givenL;
                    break;
                    case 2:
                        theL=Lmax;
                        ERLNew=Lmax;
                    break;
                    case 3:
                        theL=Lmin;
                        ERLNew=Lmin;
                    break;
                    case 4:
                        theL=LLast;
                        ERLNew=LLast;
                    break;
                    case 5:
                        if(givenL<Lmin){
                            theL=givenL;
                            ERLNew=givenL;
                        }else{
                            theL=Lmin;
                            ERLNew=Lmin;
                        }
                    break;
                    case 6:
                        if(givenL>Lmax){
                            theL=givenL;
                            ERLNew=givenL;
                        }else{
                            theL=Lmax;
                            ERLNew=Lmax;
                        }
                    break;
                }//switch
            }
            //fin
            if(ERNN>=1 && ERNN<=QExtRowsNew){
                if(IRNN<0){
                    IRNN+=(ERLNew+1);
                }
                if(ERNNGiven_0IfAll>=1 && ERNNGiven_0IfAll<=QExtRowsOld){
                    if(ERNN<ERNNGiven_0IfAll || Action_Set1_Ins3==1){
                        ERLOld=this->GetRowLength(ERNN);
                        if(IRNN>=1 && IRNN<=ERLNew){
                            if(IRNN<=ERLOld){
                                DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0=1;
                                CoordsOld.x=ERNN;
                                CoordsOld.y=IRNN;
                            }else if(IRNN>ERLOld){
                                DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0=3;
                            }
                        }
                    }else if(ERNN>ERNNGiven_0IfAll && Action_Set1_Ins3==3){
                        ERLOld=this->GetRowLength(ERNN-1);
                        if(IRNN>=1 && IRNN<=ERLNew){
                            if(IRNN<=ERLOld){
                                DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0=1;
                                CoordsOld.x=ERNN-1;
                                CoordsOld.y=IRNN;
                            }else if(IRNN>ERLOld){
                                if(Action_Set1_Ins3==1 && IRNN<=ERLOld)
                                DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0=3;
                            }
                        }
                    }else{//==
                        ERLOld=0;
                        if(IRNN>=1 && IRNN<=theL){
                            if(IRNN<=givenL){
                                DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0=2;
                                InGivenRowPosN=IRNN;
                            }else{// if(IRNN>L){
                                if(Action_Set1_Ins3==1 && IfNotValsOfGivenRow_DefaultNotOwn==false){
                                    DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0=1;
                                    CoordsOld.x=ERNN;
                                    CoordsOld.y=IRNN;
                                }else{
                                    DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0=3;
                                }
                            }
                        }
                    }//if ine
                }//if ext
            }//if for fin
        }//fun set / ins ext simple HilfsFun best


        int Array2DSize_Prototype::set_or_ins_ExtRow_simplyAsDataGiven_QExtRowsNew(int Action_Set1_Ins3, int ERNNGiven_0IfAll, const Coords2DInt&CoordsNew, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn){
            int ERLNew=0, QExtRowsNew=0, DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0=0, InGivenRowPosN=0;
            Coords2DInt CoordsOld;
            this->set_or_ins_ExtRow_simplyAsDataGiven_HilfsFun(Action_Set1_Ins3, ERNNGiven_0IfAll, CoordsNew, givenL, ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, IfNotValsOfGivenRow_DefaultNotOwn, ERLNew, QExtRowsNew, DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0, InGivenRowPosN, CoordsOld);
            return QExtRowsNew;
        }
        int Array2DSize_Prototype::set_or_ins_ExtRow_simplyAsDataGiven_ExtRowLengthNew(int Action_Set1_Ins3, int ERNNGiven_0IfAll, const Coords2DInt&CoordsNew, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn){
            int ERLNew=0, QExtRowsNew=0, DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0=0, InGivenRowPosN=0;
            Coords2DInt CoordsOld;
            this->set_or_ins_ExtRow_simplyAsDataGiven_HilfsFun(Action_Set1_Ins3, ERNNGiven_0IfAll, CoordsNew, givenL, ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, IfNotValsOfGivenRow_DefaultNotOwn, ERLNew, QExtRowsNew, DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0, InGivenRowPosN, CoordsOld);
            return ERLNew;
        }
        int Array2DSize_Prototype::set_or_ins_ExtRow_simplyAsDataGiven_DataTypeN(int Action_Set1_Ins3, int ERNNGiven_0IfAll, const Coords2DInt&CoordsNew, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn){
            int ERLNew=0, QExtRowsNew=0, DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0=0, InGivenRowPosN=0;
            Coords2DInt CoordsOld;
            this->set_or_ins_ExtRow_simplyAsDataGiven_HilfsFun(Action_Set1_Ins3, ERNNGiven_0IfAll, CoordsNew, givenL, ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, IfNotValsOfGivenRow_DefaultNotOwn, ERLNew, QExtRowsNew, DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0, InGivenRowPosN, CoordsOld);
            return DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0;
        }
        int Array2DSize_Prototype::set_or_ins_ExtRow_simplyAsDataGiven_InGivenRowPosN(int Action_Set1_Ins3, int ERNNGiven_0IfAll, const Coords2DInt&CoordsNew, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn){
            int ERLNew=0, QExtRowsNew=0, DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0=0, InGivenRowPosN=0;
            Coords2DInt CoordsOld;
            this->set_or_ins_ExtRow_simplyAsDataGiven_HilfsFun(Action_Set1_Ins3, ERNNGiven_0IfAll, CoordsNew, givenL, ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, IfNotValsOfGivenRow_DefaultNotOwn, ERLNew, QExtRowsNew, DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0, InGivenRowPosN, CoordsOld);
            return InGivenRowPosN;
        }
        Coords2DInt Array2DSize_Prototype::set_or_ins_ExtRow_simplyAsDataGiven_Arr2DNewToOldPosN(int Action_Set1_Ins3, int ERNNGiven_0IfAll, const Coords2DInt&CoordsNew, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn){
            int ERLNew=0, QExtRowsNew=0, DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0=0, InGivenRowPosN=0;
            Coords2DInt CoordsOld;
            this->set_or_ins_ExtRow_simplyAsDataGiven_HilfsFun(Action_Set1_Ins3, ERNNGiven_0IfAll, CoordsNew, givenL, ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, IfNotValsOfGivenRow_DefaultNotOwn, ERLNew, QExtRowsNew, DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0, InGivenRowPosN, CoordsOld);
            return CoordsOld;
        }

    //--------------------------------------------------------------------------------------------------

        void Array2DSize_Prototype::addExtRow_simplyAsDataGiven_HilfsFun(const Coords2DInt&CoordsNew, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn, int&ERLNew, int&QExtRowsNew, int&DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0, int&InGivenRowPosN, Coords2DInt&CoordsOld){
            int QExtRowsOld=this->GetQExtRows(), Lmin=this->GetRowLengthMin(), Lmax=this->GetRowLengthMax(), LLast=this->GetRowLength(QExtRowsOld), ERNN=CoordsNew.x, IRNN=CoordsNew.y, ERLOld, addedL;
            ERLNew=0;
            InGivenRowPosN=0;
            QExtRowsNew=QExtRowsOld;
            DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0=0;
            //Coords2DInt&CoordsOld)
            //givenL
            if(givenL==0 && Lmin==Lmax){
                givenL=Lmin;
            }
            //QExtRowsNew
            if(!(Lmin==Lmax && givenL!=Lmin && ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6==0)){
                QExtRowsNew=QExtRowsOld+1;
            }//else remains 0
            if(ERNN<0){
                ERNN+=(QExtRowsNew+1);
            }
            //addedL && ERLNew
            //if(ERNNGiven_0IfAll==0){// && Action_Set1_Ins3==1){
            //    addedL=givenL;
            //    ERLNew=givenL;
            //}else
            if(Lmin==Lmax && givenL==Lmin){
                addedL=Lmin;
                ERLNew=Lmin;
            }else{
                switch(ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6){
                    case 0:
                        if(this->IsRectangularByType()){
                            //ignore
                            addedL=0;
                            if(ERNN>=1 && ERNN<=QExtRowsOld){
                                ERLNew=this->GetRowLength(ERNN);
                            }
                        }else{
                            //
                            addedL=givenL;
                            if(ERNN==QExtRowsNew){
                                ERLNew=addedL;
                            }else if(ERNN>=1 && ERNN<=QExtRowsOld){
                                ERLNew=this->GetRowLength(ERNN);
                            }
                        }
                    break;
                    case 1:
                        addedL=givenL;
                        ERLNew=givenL;
                    break;
                    case 2:
                        addedL=Lmax;
                        ERLNew=Lmax;
                    break;
                    case 3:
                        addedL=Lmin;
                        ERLNew=Lmin;
                    break;
                    case 4:
                        addedL=LLast;
                        ERLNew=LLast;
                    break;
                    case 5:
                        if(givenL<Lmin){
                            addedL=givenL;
                            ERLNew=givenL;
                        }else{
                            addedL=Lmin;
                            ERLNew=Lmin;
                        }
                    break;
                    case 6:
                        if(givenL>Lmax){
                            addedL=givenL;
                            ERLNew=givenL;
                        }else{
                            addedL=Lmax;
                            ERLNew=Lmax;
                        }
                    break;
                }
            }
            //fin
            if(ERNN>=1 && ERNN<=QExtRowsOld){
                ERLOld=this->GetRowLength(ERNN);
                if(IRNN<0){
                    IRNN+=(ERLNew+1);
                }
                if(IRNN>=1 && IRNN<=ERLNew){
                    if(IRNN<=ERLOld){
                        DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0=2;
                        CoordsOld.x=ERNN;
                        CoordsOld.y=IRNN;
                    }else{// if(IRNN>ERLOld){
                        DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0=3;
                    }
                }//else DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0=0;
            }else if(ERNN==QExtRowsNew){
                if(IRNN<0){
                    IRNN+=(addedL+1);
                }
                if(IRNN>=1 && IRNN<=addedL){
                    if(IRNN<=givenL){
                        DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0=2;
                        InGivenRowPosN=IRNN;
                    }else{// if(IRNN>L){
                        DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0=3;
                    }
                }//else DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0=0;
            }
        }//fn - addExt simple HilfsFun best


        int Array2DSize_Prototype::addExtRow_simplyAsDataGiven_QExtRowsNew(const Coords2DInt&CoordsNew, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn){
            int ERLNew=0, QExtRowsNew=0, DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0=0, InGivenRowPosN=0;
            Coords2DInt CoordsOld;
            this->addExtRow_simplyAsDataGiven_HilfsFun(CoordsNew, givenL, ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, IfNotValsOfGivenRow_DefaultNotOwn, ERLNew, QExtRowsNew, DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0, InGivenRowPosN, CoordsOld);
            return QExtRowsNew;
        }
        int Array2DSize_Prototype::addExtRow_simplyAsDataGiven_ExtRowLengthNew(const Coords2DInt&CoordsNew, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn){
            int ERLNew=0, QExtRowsNew=0, DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0=0, InGivenRowPosN=0;
            Coords2DInt CoordsOld;
            this->addExtRow_simplyAsDataGiven_HilfsFun(CoordsNew, givenL, ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, IfNotValsOfGivenRow_DefaultNotOwn, ERLNew, QExtRowsNew, DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0, InGivenRowPosN, CoordsOld);
            return ERLNew;
        }
        int Array2DSize_Prototype::addExtRow_simplyAsDataGiven_DataType(const Coords2DInt&CoordsNew, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn){
            int ERLNew=0, QExtRowsNew=0, DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0=0, InGivenRowPosN=0;
            Coords2DInt CoordsOld;
            this->addExtRow_simplyAsDataGiven_HilfsFun(CoordsNew, givenL, ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, IfNotValsOfGivenRow_DefaultNotOwn, ERLNew, QExtRowsNew, DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0, InGivenRowPosN, CoordsOld);
            return DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0;
        }
        int Array2DSize_Prototype::addExtRow_simplyAsDataGiven_InGivenRowPosNN(const Coords2DInt&CoordsNew, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn){
            int ERLNew=0, QExtRowsNew=0, DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0=0, InGivenRowPosN=0;
            Coords2DInt CoordsOld;
            this->addExtRow_simplyAsDataGiven_HilfsFun(CoordsNew, givenL, ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, IfNotValsOfGivenRow_DefaultNotOwn, ERLNew, QExtRowsNew, DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0, InGivenRowPosN, CoordsOld);
            return InGivenRowPosN;
        }
        Coords2DInt Array2DSize_Prototype::addExtRow_simplyAsDataGiven_Arr2DCoordsNewToOld(const Coords2DInt&CoordsNew, int givenL, int ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, bool IfNotValsOfGivenRow_DefaultNotOwn){
            int ERLNew=0, QExtRowsNew=0, DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0=0, InGivenRowPosN=0;
            Coords2DInt CoordsOld;
            this->addExtRow_simplyAsDataGiven_HilfsFun(CoordsNew, givenL, ifNonRectForRect_NonRect0_MakeRactAddingAndMakingRest_L1Max2Minx3Last4MinOfLAndLmin5MaxOfLAndLmax6, IfNotValsOfGivenRow_DefaultNotOwn, ERLNew, QExtRowsNew, DataType_Arr2DVals1_GivenRowVals2_Default3_Incorrect0, InGivenRowPosN, CoordsOld);
            return CoordsOld;
        }

        //--------------------------------------------------------------------------------------------------

        void Array2DSize_Prototype::delExtRow_HilfsFun(const Coords2DInt&CoordsNew, int ExtRowToDelNN, int&ERLNew, int&QExtRowsNew,  Coords2DInt&CoordsOld){
            int QExtRowsOld=this->GetQExtRows(), ERNN=CoordsNew.x, IRNN=CoordsNew.y, ERLOld, QMinAllowed=DEFAULT_SIZE, LmaxNew=0, curL, LmaxOld=this->GetRowLengthMax();
            if(ExtRowToDelNN<0){
                ExtRowToDelNN+=(QExtRowsOld+1);
            }
            if(QExtRowsOld>QMinAllowed && ExtRowToDelNN>=1 && ExtRowToDelNN<=QExtRowsOld){
                QExtRowsNew=QExtRowsOld-1;
            }else{
                QExtRowsNew=QExtRowsOld;
            }
            if(ERNN<0){
                ERNN+=(QExtRowsNew+1);
            }
            //fin
            if(QExtRowsNew==QExtRowsOld-1){
                //LmaxNew
                if(ExtRowToDelNN<=QExtRowsOld){
                    if(ExtRowToDelNN>1 && ExtRowToDelNN<=QExtRowsOld){
                        for(int NN=1; NN<=QExtRowsOld; NN++){
                            curL=this->GetRowLength(NN);
                            if(NN==1 || (NN>1 && curL>LmaxNew && ExtRowToDelNN!=-NN)){
                                LmaxNew=curL;
                            }
                        }
                    }else if(ExtRowToDelNN==1){
                        for(int NN=2; NN<=QExtRowsOld; NN++){
                            curL=this->GetRowLength(NN);
                            if(NN==2 || (NN>1 && curL>LmaxNew && ExtRowToDelNN!=-NN)){
                                LmaxNew=curL;
                            }
                        }
                    }
                }
                //
                if(IRNN<0){
                    IRNN+=(LmaxNew+1);
                }
                //
                if(ERNN>=1 && ERNN<=QExtRowsNew){
                    if(ERNN<ExtRowToDelNN){
                        curL=this->GetRowLength(ERNN);
                        if(IRNN>=1 && IRNN<=curL){
                            CoordsOld.x=ERNN;
                            CoordsOld.y=IRNN;
                        }
                    }else{//(ERNN = ExtRowToDelNN+1 ... QExtRowsNew)
                        curL=this->GetRowLength(ERNN+1);
                        if(IRNN>=1 && IRNN<=curL){
                            CoordsOld.x=ERNN+1;
                            CoordsOld.y=IRNN;
                        }
                    }
                }
            }else{//QExtRowsNew==QExtRowsOld, opeg n'abl be fa, ignor'd - n'nod: opeg n'gedo'tc
                if(IRNN<0){
                    IRNN+=(LmaxOld+1);
                }
                if(ERNN>=1 & ERNN<=QExtRowsOld){
                    curL=this->GetRowLength(ERNN);
                    if(IRNN>=1 && IRNN<=curL){
                        CoordsOld.x=ERNN;
                        CoordsOld.y=IRNN;
                    }
                }
            }
        }//fn del ext simple HilfsFun best

        int Array2DSize_Prototype::delExtRow_ExtRowNewLengthNew(const Coords2DInt&CoordsNew, int ExtRowToDelNN){
            int ERLNew=0, QExtRowsNew=0;
            Coords2DInt CoordsOld;
            this->delExtRow_HilfsFun(CoordsNew, ExtRowToDelNN, ERLNew, QExtRowsNew,  CoordsOld);
            return ERLNew;
        }
        int Array2DSize_Prototype::delExtRow_QExtRowsNew(const Coords2DInt&CoordsNew, int ExtRowToDelNN){
            int ERLNew=0, QExtRowsNew=0;
            Coords2DInt CoordsOld;
            this->delExtRow_HilfsFun(CoordsNew, ExtRowToDelNN, ERLNew, QExtRowsNew,  CoordsOld);
            return ERLNew;
        }
        Coords2DInt Array2DSize_Prototype::delExtRow_Arr2DCoordsNewToOld(const Coords2DInt&CoordsNew, int ExtRowToDelNN){
            int ERLNew=0, QExtRowsNew=0;
            Coords2DInt CoordsOld;
            this->delExtRow_HilfsFun(CoordsNew, ExtRowToDelNN, ERLNew, QExtRowsNew,  CoordsOld);
            return CoordsOld;
        }


        //--------------------------------------------------------------------------------------------------

        void Array2DSize_Prototype::delIneRow_HilfsFun(const Coords2DInt&CoordsNew, int IneRowToDelNN, int ifN_GT_Lmin_CutLongOnly1_Ignore0, int&QExtRowsNew, int&ERLNew, Coords2DInt&CoordsOld){
            int QExtRows=this->GetQExtRows(), Lmax=this->GetRowLengthMax(), Lmin=this->GetRowLengthMin(), ERLOld, ERNN, IRNN, MinQAllowed=DEFAULT_SIZE;
            if(IneRowToDelNN<0){
                IneRowToDelNN+=(Lmax+1);
            }
            QExtRowsNew=QExtRows;
            if(ERNN<0){
                ERNN+=(QExtRowsNew+1);
            }
            if(IneRowToDelNN>=1 && IneRowToDelNN<=Lmax && !(IneRowToDelNN>Lmin && ifN_GT_Lmin_CutLongOnly1_Ignore0==0)){
                if(ERNN>=1 && ERNN<=QExtRows){
                    ERLOld=this->GetRowLength(ERNN);
                    if(ERLOld>=IneRowToDelNN){
                        ERLNew=ERLOld-1;
                    }else{
                        ERLNew=ERLOld;
                    }
                    if(IRNN<0){
                        IRNN+=(ERLNew+1);
                    }
                    if(IRNN>=1 && IRNN<=ERLNew){
                        CoordsOld.x=ERNN;
                        if(IRNN<IneRowToDelNN){
                            CoordsOld.y=IRNN;
                        }else{// if(IRNN>=IneRowToDelNN){
                            CoordsOld.y=IRNN+1;
                        }
                    }
                }
            }else{//operation forbiden
                if(ERNN>=1 && ERNN<=QExtRows){
                    ERLOld=this->GetRowLength(ERNN);
                    ERLNew=ERLOld;
                    if(IRNN>=1 && IRNN<=ERLNew){
                        CoordsOld.x=ERNN;
                        CoordsOld.y=IRNN;
                    }
                }
            }
        }//fn

        int Array2DSize_Prototype::delIneRow_ExtRowNewLength(const Coords2DInt&CoordsNew, int IneRowToDelNN, int ifN_GT_Lmin_CutLongOnly1_Ignore0){
            int QExtRowsNew=0, ERLNew=0;
            Coords2DInt CoordsOld;
            this->delIneRow_HilfsFun(CoordsNew, IneRowToDelNN, ifN_GT_Lmin_CutLongOnly1_Ignore0, QExtRowsNew, ERLNew, CoordsOld);
            return ERLNew;
        }
        int Array2DSize_Prototype::delIneRow_QExtRowsNew(const Coords2DInt&CoordsNew, int IneRowToDelNN, int ifN_GT_Lmin_CutLongOnly1_Ignore0){
            int QExtRowsNew=0, ERLNew=0;
            Coords2DInt CoordsOld;
            this->delIneRow_HilfsFun(CoordsNew, IneRowToDelNN, ifN_GT_Lmin_CutLongOnly1_Ignore0, QExtRowsNew, ERLNew, CoordsOld);
            return QExtRowsNew;
        }
        Coords2DInt Array2DSize_Prototype::delIneRow_Arr2DCoordsNewToOld(const Coords2DInt&CoordsNew, int IneRowToDelNN, int ifN_GT_Lmin_CutLongOnly1_Ignore0){
            int QExtRowsNew=0, ERLNew=0;
            Coords2DInt CoordsOld;
            this->delIneRow_HilfsFun(CoordsNew, IneRowToDelNN, ifN_GT_Lmin_CutLongOnly1_Ignore0, QExtRowsNew, ERLNew, CoordsOld);
            return CoordsOld;
        }



        //--------------------------------------------------------------------------------------------------



        void Array2DSize_Prototype::addIneRow_simplyAsDataGiven_HilfsFun(const Coords2DInt&CoordsNew, int givenL, int ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4, int ifNonRect_AddToLast1StretchToMax2Ignore0, int&DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0, int&QExtRowsNew, int&ERLNew, int&InGivenRowPosN,Coords2DInt&CoordsOld){
            //Coords2DInt CoordsOld; int int
            DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=0;
            InGivenRowPosN=0;
            int  ERLOld, Lmin=this->GetRowLengthMin(), Lmax=this->GetRowLengthMax();
            int QExtRowsOld=this->GetQExtRows(),  ERNN=CoordsNew.x, IRNN=CoordsNew.y, IRLLast;
            //IRLLast=this->GetIneRowLength(Lmax, false);
            if(givenL==0){
                if(Lmin==Lmax){
                    givenL=QExtRowsOld;
                }
            }
            //
            if(givenL==QExtRowsOld){
                QExtRowsNew=QExtRowsOld;
                if(ERNN<0){
                    ERNN+=(QExtRowsNew+1);
                }
                if(ERNN>=1 && ERNN<=QExtRowsOld){
                    ERLOld=this->GetRowLength(ERNN);
                    if(IRNN<0){
                        IRNN+=(ERLOld+1);
                    }
                    if(IRNN>=1){
                        if(Lmin==Lmax){
                            if(IRNN<=ERLOld){
                                ERLNew=Lmax+1;
                                DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=1;
                            }
                        }else{
                            switch(ifNonRect_AddToLast1StretchToMax2Ignore0){
                                case 0:
                                    //ignore
                                    //DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=0;
                                break;
                                case 1:
                                    ERLNew=ERLOld+1;
                                    if(IRNN<=ERLOld){
                                        DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=1;
                                    }else if(IRNN<=ERLNew){//asmda sdi ==, no ato tgos
                                        DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=2;
                                    }
                                break;
                                case 2:
                                    ERLNew=Lmax+1;
                                    if(IRNN<=ERLOld){
                                        DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=1;
                                    }else if(IRNN<=ERLNew){
                                        DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=2;
                                    }
                                break;
                            }
                        }
                    }//else DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=0; ob'IRNN
                }//else DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=0; ob'ERNN
            }else{//L!=QExtRowsOld
                if(givenL>0){

                    //QER
                    switch(ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4){
                        case 0:
                            QExtRowsNew=QExtRowsOld;//ob ignore
                        break;
                        case 1:
                            QExtRowsNew=givenL;
                        break;
                        case 2:
                            QExtRowsNew=QExtRowsOld;
                        break;
                        case 3:
                            if(givenL>QExtRowsOld){
                                QExtRowsNew=givenL;
                            }else{
                                QExtRowsNew=QExtRowsOld;
                            }
                        break;
                        case 4:
                            if(givenL>QExtRowsOld){
                                QExtRowsNew=givenL;
                            }else{
                                QExtRowsNew=QExtRowsOld;
                            }

                        break;
                    }
                    //
                    if(ERNN<0){
                        ERNN+=(QExtRowsNew+1);
                    }
                    //newL
                    if(ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4>=1 && ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4<=4){
                        ERLNew=Lmax+1;
                    }else if(ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4==0){
                        ERLNew=ERLOld;//ob ignore
                    }
                }else{//ob ignore
                    QExtRowsNew=givenL;
                    ERLNew=ERLOld;
                    if(ERNN>=1 && ERNN<=QExtRowsOld && IRNN>=1 && IRNN<=this->GetRowLength(ERNN)){
                        DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=1;
                        CoordsOld.x=ERNN;
                        CoordsOld.y=IRNN;
                    }
                }
            }
            //nu gefa
            if(givenL<=0 || (Lmin==Lmax && ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4==0)){
                //NOp;
                QExtRowsNew=QExtRowsOld;
                if(ERNN>=1 && ERNN<=QExtRowsOld){
                    ERLOld=this->GetRowLength(ERNN);
                    ERLNew=ERLOld;
                    if(IRNN>=1 && IRNN<=ERLOld){
                        DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=1;
                        CoordsOld.x=ERNN;
                        CoordsOld.y=IRNN;
                    }//else DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=0;
                }//else DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=0;
            }else{// action of adding Inner Row is provided
                if(QExtRowsOld==QExtRowsNew){ //usual normal case
                    if(ERNN>=1 && ERNN<=QExtRowsNew){
                        if(ERNN<=QExtRowsOld){
                            if(IRNN>=1 && IRNN<=ERLNew){
                                if(IRNN<=ERLOld){
                                    DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=1;
                                    CoordsOld.x=ERNN;
                                    CoordsOld.y=IRNN;
                                }else if(IRNN<ERLNew)
                                    DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=3;
                            }else{//IRNN==newL
                                if(ERNN<=givenL){
                                    DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=2;
                                    InGivenRowPosN=ERNN;
                                }else{
                                     DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=3;
                                }
                             }//else DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=0;
                        }//else{// if(ERNN<=QExtRowsNew){
                        //
                         //}
                    }//else DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=0;
                }else{//QExtRowsOld<>QExtRowsNew, abnormal, not needed, case
                    if(ERNN>=1 && ERNN<=QExtRowsNew){
                        if(ERNN<=QExtRowsOld){
                            if(IRNN>=1 && IRNN<=ERLNew){
                                if(IRNN<=ERLOld){
                                    DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=1;
                                    CoordsOld.x=ERNN;
                                    CoordsOld.y=IRNN;
                                }else if(IRNN<=ERLNew-1){//
                                    DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=3;
                                }else{// if(IRNN=newL){
                                    if(ERNN<=givenL){
                                        DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=2;
                                        InGivenRowPosN=ERNN;
                                    }else{
                                        DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=3;
                                    }
                                }
                            }//else DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=0; ob'IRNN
                        }else{// if(ERNN>QExtRowsOld <QExtRowsNew){
                            if(IRNN>=1 && IRNN<=ERLNew){
                                DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=3;
                            }
                        }//else DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=0; ob'IRNN
                    }//else DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=0;
                }
            }
            //}//else DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=0;
            //return newL;
        }

        int Array2DSize_Prototype::addIneRow_simplyAsDataGiven_NewExtRowLength(const Coords2DInt&CoordsNew, int givenL, int ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4, int ifNonRect_AddToLast1StretchToMax2Ignore0){
            int DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=0;
            int ERLNew=0;
            int InGivenRowPosN=0;
            int QExtRowsNew=0;
            Coords2DInt CoordsOld;
            this->addIneRow_simplyAsDataGiven_HilfsFun(CoordsNew, givenL, ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4, ifNonRect_AddToLast1StretchToMax2Ignore0, DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0, QExtRowsNew, ERLNew, InGivenRowPosN, CoordsOld);
            return ERLNew;
        }

        int Array2DSize_Prototype::addIneRow_simplyAsDataGiven_QExtRowsNew(const Coords2DInt&CoordsNew, int givenL, int ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4, int ifNonRect_AddToLast1StretchToMax2Ignore0){
            int DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=0;
            int ERLNew=0;
            int InGivenRowPosN=0;
            int QExtRowsNew=0;
            Coords2DInt CoordsOld;
            this->addIneRow_simplyAsDataGiven_HilfsFun(CoordsNew, givenL, ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4, ifNonRect_AddToLast1StretchToMax2Ignore0, DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0, QExtRowsNew, ERLNew, InGivenRowPosN,CoordsOld);
            return QExtRowsNew;
        }

        int Array2DSize_Prototype::addIneRow_simplyAsDataGiven_DataTypeN(const Coords2DInt&CoordsNew, int givenL, int ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4, int ifNonRect_AddToLast1StretchToMax2Ignore0){
            int DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=0;
            int ERLNew=0;
            int InGivenRowPosN=0;
            int QExtRowsNew=0;
            Coords2DInt CoordsOld;
            this->addIneRow_simplyAsDataGiven_HilfsFun(CoordsNew, givenL, ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4, ifNonRect_AddToLast1StretchToMax2Ignore0, DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0, QExtRowsNew, ERLNew, InGivenRowPosN,CoordsOld);
            return DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0;
        }

        Coords2DInt Array2DSize_Prototype::addIneRow_simplyAsDataGiven_Arr2DCoordsNewToOld(const Coords2DInt&CoordsNew, int givenL, int ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4, int ifNonRect_AddToLast1StretchToMax2Ignore0){
            int DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=0;
            int ERLNew=0;
            int InGivenRowPosN=0;
            int QExtRowsNew=0;
            Coords2DInt CoordsOld;
            this->addIneRow_simplyAsDataGiven_HilfsFun(CoordsNew, givenL, ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4, ifNonRect_AddToLast1StretchToMax2Ignore0, DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0, QExtRowsNew, ERLNew, InGivenRowPosN,CoordsOld);
            return CoordsOld;
        }

        //--------------------------------------------------------------------------------------------------

//        void Array2DSize_Prototype::insIneRow_simplyAsDataGiven_HilfsFun(const Coords2DInt&CoordsNew, int InsIneRowN, int L, int ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4, int ifNonRect_AddToLast1StretchToMax2Ignore0, int&DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0, int&QExtRowsNew, int&InquiredExtRowNewL, int&InGivenRowPosN,Coords2DInt&CoordsOld){
//            //Coords2DInt CoordsOld;
//            DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=0;
//            InGivenRowPosN=0;
//            int QExtRows=this->GetQExtRows(), InquiredExtRowOldL, Lmin=this->GetRowLengthMin(), Lmax=this->GetRowLengthMax();
//            int QExtRowsOld=this->GetQExtRows(), QExtRowsNew, InquiredExtRowNewL, ERNN=CoordsNew.x, IRNN=CoordsNew.y, IRLLast;
//            //IRLLast=this->GetIneRowLength(Lmax, false);
//            if(L==0){
//                if(Lmin==Lmax){
//                    L=QExtRowsOld;
//                }
//            }
//            if(ERNN<0){
//                ERNN+=(QExtRows+1);
//            }
//            if(InsIneRowN<0){
//                  InsIneRowN+=(Lmax+1);
//            }
//            if(L==QExtRowsOld){
//                QExtRowsNew=QExtRowsOld;
//                if(ERNN>=1 && ERNN<=QExtRowsOld){
//                    InquiredExtRowOldL=this->GetRowLength(ERNN);
//                    if(IRNN<0){
//                        IRNN+=(InquiredExtRowOldL+1);
//                    }
//                    if(IRNN>=1){
//                        if(Lmin==Lmax){
//                            if(InsIneRowN>=1 && InsIneRowN<=Lmax){
//                                if(InsIneRowN<=Lmin){
//                                    if(IRNN<=InquiredExtRowOldL){
//                                        InquiredExtRowNewL=Lmax+1;
//                                        DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=1;
//                                    }else{//IRNN =[InsIneRowN...InquiredExtRowOldL]

//                                    }
//                                }else{//InsIneRowN=[InquiredExtRowOldL...Lmax]
//                                    if(IRNN<=InquiredExtRowOldL){
//                                        InquiredExtRowNewL=Lmax+1;
//                                        DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=1;
//                                    }else{//IRNN =[InsIneRowN...InquiredExtRowOldL]

//                                    }
//                                }
//                            }else{
//                                if(InsIneRowN<=Lmin){
//                                    if(IRNN<=InquiredExtRowOldL){
//                                        InquiredExtRowNewL=Lmax+1;
//                                        DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=1;
//                                    }else{//IRNN =[]

//                                    }
//                                }
//                            }
//                        }else{//Lmin!=Lmax
//                            switch(ifNonRect_AddToLast1StretchToMax2Ignore0){
//                                case 0:
//                                    //ignore
//                                    //DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=0;
//                                break;
//                                case 1:
//                                    InquiredExtRowNewL=InquiredExtRowOldL+1;
//                                    if(IRNN<=InquiredExtRowOldL){
//                                        DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=1;
//                                    }else if(IRNN<=InquiredExtRowNewL){//asmda sdi ==, no ato tgos
//                                        DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=2;
//                                    }
//                                break;
//                                case 2:
//                                    InquiredExtRowNewL=Lmax+1;
//                                    if(IRNN<=InquiredExtRowOldL){
//                                        DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=1;
//                                    }else if(IRNN<=InquiredExtRowNewL){
//                                        DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=2;
//                                    }
//                                break;
//                            }
//                        }
//                    }//else DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=0; ob'IRNN
//                }//else DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=0; ob'ERNN
//            }else{//L!=QWExtRowsOld
//                if(L>0){
//                    //QER
//                    switch(ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4){
//                        case 0:
//                            QExtRowsNew=QExtRowsOld;//ob ignore
//                        break;
//                        case 1:
//                            QExtRowsNew=L;
//                        break;
//                        case 2:
//                            QExtRowsNew=QExtRowsOld;
//                        break;
//                        case 3:
//                            if(L>QExtRowsOld){
//                                QExtRowsNew=L;
//                            }else{
//                                QExtRowsNew=QExtRowsOld;
//                            }
//                        break;
//                        case 4:
//                            if(L>QExtRowsOld){
//                                QExtRowsNew=L;
//                            }else{
//                                QExtRowsNew=QExtRowsOld;
//                            }

//                        break;
//                    }
//                    //newL
//                    if(ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4>=1 && ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4<=4){
//                        InquiredExtRowNewL=Lmax+1;
//                    }else if(ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4==0){
//                        InquiredExtRowNewL=InquiredExtRowOldL;//ob ignore
//                    }
//                }else{//ob ignore
//                    QExtRowsNew=L;
//                    InquiredExtRowNewL=InquiredExtRowOldL;
//                }
//            }
//            //nu gefa
//            if(L<=0 || (Lmin==Lmax && ifL_NE_QER_Ignore0_SetRectByStretchToMaxAndQER_New1Old2Max3Min4==0)){
//                //NOp;
//                QExtRowsNew=QExtRowsOld;
//                if(ERNN>=1 && ERNN<=QExtRowsOld){
//                    InquiredExtRowOldL=this->GetRowLength(ERNN);
//                    InquiredExtRowNewL=InquiredExtRowOldL;
//                    if(IRNN>=1 && IRNN<=InquiredExtRowOldL){
//                        DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=1;
//                        CoordsOld.x=ERNN;
//                        CoordsOld.y=IRNN;
//                    }//else DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=0;
//                }//else DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=0;
//            }else{// action of adding Inner Row is provided
//                if(QExtRowsOld==QExtRowsNew){ //usual normal case
//                    if(ERNN>=1 && ERNN<=QExtRowsNew){
//                        if(ERNN<=QExtRowsOld){
//                            if(IRNN>=1 && IRNN<=InquiredExtRowNewL){
//                                if(IRNN<=InquiredExtRowOldL){
//                                    DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=1;
//                                    CoordsOld.x=ERNN;
//                                    CoordsOld.y=IRNN;
//                                }else if(IRNN<InquiredExtRowNewL)
//                                    DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=3;
//                            }else{//IRNN==newL
//                                if(ERNN<=L){
//                                    DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=2;
//                                    InGivenRowPosN=ERNN;
//                                }else{
//                                    DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=3;
//                                }
//                            }//else DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=0;
//                        }//else{// if(ERNN<=QExtRowsNew){
//                        //
//                        //}
//                    }//else DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=0;
//                }else{//QExtRowsOld<>QExtRowsNew, abnormal, not needed, case
//                    if(ERNN>=1 && ERNN<=QExtRowsNew){
//                        if(ERNN<=QExtRowsOld){
//                            if(IRNN>=1 && IRNN<=InquiredExtRowNewL){
//                                if(IRNN<=InquiredExtRowOldL){
//                                    DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=1;
//                                    CoordsOld.x=ERNN;
//                                    CoordsOld.y=IRNN;
//                                }else if(IRNN<=newL-1){//
//                                    DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=3;
//                                }else{// if(IRNN=newL){
//                                    if(ERNN<=L){
//                                        DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=2;
//                                        InGivenRowPosN=ERNN;
//                                    }else{
//                                        DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=3;
//                                    }
//                                }
//                            }//else DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=0; ob'IRNN
//                        }else{// if(ERNN>QExtRowsOld <QExtRowsNew){
//                            if(IRNN>=1 && IRNN<=InquiredExtRowNewL){
//                                DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=3;
//                            }
//                        }//else DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=0; ob'IRNN
//                    }//else DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=0;
//                }
//            }//else DataType_Arr2DVals1_GivenRowVal2_DefaultVal3_Incorrect0=0;
//        //}
//        //return newL;
//        }//fn

        //--------------------------------------------------------------------------------------------------

        //--------------------------------------------------------------------------------------------------

        TDataShiftResults  Array2DSize_Prototype::ExtRow_SetAddInsDel_dataNs(int Action_Set1_Add2_Ins3_Del4_Dflt0, int givenRowL, /*int inquiredRowNN,*/ int ChangedRowNN_0ifAll, TDataShiftParams*DataShiftParam, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, bool suiValsInsteadOfDefaultValsWherePossible){
            int res1L=0, res2L=0;
            int QExtRows=this->GetQExtRows(), oldL, calcdL;
            TDataShiftParams shiftData1, shiftData2;
            TDataShiftResults dataShiftRslts1, dataShiftRslts2;
            if(QExtRows>0 || (QExtRows==0 && Action_Set1_Add2_Ins3_Del4_Dflt0==2)){
                if(ChangedRowNN_0ifAll<0){
                    ChangedRowNN_0ifAll+=(QExtRows+1);
                }
                if(givenRowL==0){
                    givenRowL=oldL;
                }
                if(DataShiftParam!=NULL){
                    shiftData1=(*(DataShiftParam));
                }
                dataShiftRslts1=shiftData1.Calc(givenRowL);
                res1L=dataShiftRslts1.Lcalc;
                if(ChangedRowNN_0ifAll==0){
                    res1L=calcdL;//ob everywhere is equal
                }else if(ChangedRowNN_0ifAll>=1 && ChangedRowNN_0ifAll<=QExtRows){
                    oldL=this->GetRowLength(ChangedRowNN_0ifAll);
                    if(calcdL==oldL){
                        res1L=oldL;
                    }else{
                        if(this->IsRectangularByType() && ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4==0){
                            res1L=oldL;// sdi Nop;
                        }else if(this->IsRectangularInFact()){
                            switch(ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4){
                                case 0:
                                    res1L=calcdL;
                                break;
                                case 1:
                                    res1L=calcdL;
                                break;
                                case 2:
                                    res1L=oldL;
                                break;
                                case 3:
                                    res1L= calcdL>=oldL ? calcdL : oldL;
                                break;
                                case 4:
                                    res1L= calcdL<=oldL ? calcdL : oldL;
                                break;
                            }
                        }else{
                            res1L=calcdL;
                        }
                    }
                }
            }
            if(res1L==0){
                res2L=0;
            }else{
                if(res1L==calcdL){
                    res2L=res1L;
                    shiftData2=shiftData1;
                    dataShiftRslts1=dataShiftRslts2;
                }else{
                    shiftData2=shiftData1;
                    shiftData2.Lreq=res1L;
                    dataShiftRslts2=shiftData2.Calc(givenRowL);
                    res2L=dataShiftRslts2.Lcalc;
                    res2L=res1L;
                }
            }
            return dataShiftRslts2;
        }
        int Array2DSize_Prototype::ExtRow_SetAddInsDel_ThatCorrectedByNewData_NewLength(int Action_Set1_Add2_Ins3_Del4_Dflt0, int givenRowL, int ExtRowNN_0ifAll, TDataShiftParams*DataShiftParam, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, bool suiValsInsteadOfDefaultValsWherePossible){
            //                                ExtRow_SetAddInsDel_dataNs(int Action_Set1_Add2_Ins3_Del4_Dflt0, int givenRowL, int inquiredRowNN, int ChangedRowNN_0ifAll, TDataShiftParams*DataShiftParam, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, bool suiValsInsteadOfDefaultValsWherePossible)
            //                                ExtRow_SetAddInsDel_dataNs(int Action_Set1_Add2_Ins3_Del4_Dflt0, int givenRowL=0, /*int inquiredRowNN=-1,*/ int ChangedRowNN_0ifAll=-1, TDataShiftParams*DataShiftParam=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0, bool suiValsInsteadOfDefaultValsWherePossible=true);
            TDataShiftResults shiftData=this->ExtRow_SetAddInsDel_dataNs(    Action_Set1_Add2_Ins3_Del4_Dflt0,     givenRowL,   /*ExtRowNN_0ifAll, */        ExtRowNN_0ifAll,                  DataShiftParam,     ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4,      suiValsInsteadOfDefaultValsWherePossible);
            int finalL=shiftData.Lcalc;
            return finalL;
        }

        int Array2DSize_Prototype::ExtRow_SetAddInsDel_ThatCorrectedByNewData_PosInRowToDataTypeN(int Action_Set1_Add2_Ins3_Del4_Dflt0, int InRowPosNN, int givenRowL, int ExtRowNN_0ifAll, TDataShiftParams*DataShiftParam, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, bool suiValsInsteadOfDefaultValsWherePossible){
            int dataTypeN_OldArrayVal1_NewRowGivenVal2_DefaultVal3_Incorrect0=0,
                QExtRowsOld=this->GetQExtRows(), QExtRowsNew, finalL, oldL,
                inquiredRowNN=ExtRowNN_0ifAll;
            //TDataShiftParams shiftData;
            TDataShiftResults shiftDataNs;
            if(ExtRowNN_0ifAll>=1 && ExtRowNN_0ifAll<=QExtRowsNew){
                //                ExtRow_SetAddInsDel_dataNs(int Action_Set1_Add2_Ins3_Del4_Dflt0, int givenRowL, int inquiredRowNN, int ChangedRowNN_0ifAll, TDataShiftParams*DataShiftParam, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, bool suiValsInsteadOfDefaultValsWherePossible){
                shiftDataNs=this->ExtRow_SetAddInsDel_dataNs(    Action_Set1_Add2_Ins3_Del4_Dflt0,     givenRowL,     ExtRowNN_0ifAll,                                         DataShiftParam,     ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4,      suiValsInsteadOfDefaultValsWherePossible);
                finalL=shiftDataNs.Lcalc;//tams alr corr'd Lcalc sdi et shiftData
                //
                oldL=ExtRow_SetAddInsDel_OldLengthOfExtRowN(Action_Set1_Add2_Ins3_Del4_Dflt0, inquiredRowNN, ExtRowNN_0ifAll, givenRowL, DataShiftParam, ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, suiValsInsteadOfDefaultValsWherePossible);
                if(ExtRowNN_0ifAll<0){
                    ExtRowNN_0ifAll+=(QExtRowsNew+1);
                }
                if(InRowPosNN>=shiftDataNs.ForOwnN1 && InRowPosNN<=shiftDataNs.ForOwnN2){
                    dataTypeN_OldArrayVal1_NewRowGivenVal2_DefaultVal3_Incorrect0=2;
                }else{
                    if(InRowPosNN>=1 && InRowPosNN<=oldL){
                        if(suiValsInsteadOfDefaultValsWherePossible){
                            dataTypeN_OldArrayVal1_NewRowGivenVal2_DefaultVal3_Incorrect0=1;
                        }else{
                            dataTypeN_OldArrayVal1_NewRowGivenVal2_DefaultVal3_Incorrect0=3;
                        }
                    }else if(InRowPosNN>=1 && InRowPosNN<=finalL){
                        dataTypeN_OldArrayVal1_NewRowGivenVal2_DefaultVal3_Incorrect0=3;
                    }//else 0, ma to val s'dflt
                }
            }
            return dataTypeN_OldArrayVal1_NewRowGivenVal2_DefaultVal3_Incorrect0;
        }

        int Array2DSize_Prototype::ExtRow_SetAddInsDel_OldLengthOfExtRowN(int Action_Set1_Add2_Ins3_Del4_Dflt0, int inquiredRowNN, int ExtRowNN_0ifAll, int givenRowL, TDataShiftParams*ShiftData, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, bool suiValsInsteadOfDefaultValsWherePossible){
            int oldL=0, QExtRowsOld=this->GetQExtRows(), QExtRowsNew;
            switch(Action_Set1_Add2_Ins3_Del4_Dflt0){
                case 1:
                    QExtRowsNew=QExtRowsOld;
                break;
                case 2:
                    QExtRowsNew=QExtRowsOld+1;
                break;
                case 3:
                    QExtRowsNew=QExtRowsOld+1;
                break;
                case 4:
                    QExtRowsNew=QExtRowsOld-1;
                break;
            }
            if(inquiredRowNN<0){
                inquiredRowNN+=(QExtRowsNew+1);
            }
            if(ExtRowNN_0ifAll<0){
                ExtRowNN_0ifAll+=(QExtRowsNew+1);
            }
            if(inquiredRowNN>=1 && inquiredRowNN<=QExtRowsNew){
                switch(Action_Set1_Add2_Ins3_Del4_Dflt0){
                    case 1:
                        oldL=this->GetRowLength(inquiredRowNN);
                    break;
                    case 2:
                        if(inquiredRowNN<=QExtRowsOld){
                            oldL=this->GetRowLength(inquiredRowNN);
                        }
                    break;
                    case 3:
                        if(inquiredRowNN<ExtRowNN_0ifAll){
                            oldL=this->GetRowLength(inquiredRowNN);
                        }else if(inquiredRowNN>ExtRowNN_0ifAll){
                            oldL=this->GetRowLength(inquiredRowNN-1);
                        }
                    break;
                    case 4:
                        if(inquiredRowNN<ExtRowNN_0ifAll){
                            oldL=this->GetRowLength(inquiredRowNN);
                        }else if(inquiredRowNN>ExtRowNN_0ifAll){
                            oldL=this->GetRowLength(inquiredRowNN+1);
                        }
                    break;
                }
            }
            return oldL;
        }

        int Array2DSize_Prototype::ExtRow_SetAddInsDel_NewLengthOfExtRowN(int Action_Set1_Add2_Ins3_Del4_Dflt0, int inquiredRowNN, int ExtRowNN_0ifAll, int givenRowL, TDataShiftParams*ShiftData, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4,  bool suiValsInsteadOfDefaultValsWherePossible){
            //                     ExtRow_ThatCorrectedByNewData_SetAddInsDel_rowLval(int givenRowL, int ExtRowNN_0ifAll, TDataShiftParams*DataShiftParam, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, int SetExistingRowL1Add2Ins3Default0, bool suiValsInsteadOfDefaultValsWherePossible){
            int modifiedRowL=this->ExtRow_SetAddInsDel_ThatCorrectedByNewData_NewLength(Action_Set1_Add2_Ins3_Del4_Dflt0, givenRowL, ExtRowNN_0ifAll, ShiftData, ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, suiValsInsteadOfDefaultValsWherePossible),
                QExtRowsOld=this->GetQExtRows(), QExtRowsNew, oldL, allowedMinQ=DEFAULT_SIZE, finalL=0;
            //QExtRowsNew
            switch(Action_Set1_Add2_Ins3_Del4_Dflt0){
                case 1://Set
                    QExtRowsNew=QExtRowsOld;
                break;
                case 2://Add
                    QExtRowsNew=QExtRowsOld+1;
                break;
                case 3://Ins
                    QExtRowsNew=QExtRowsOld+1;
                case 4://Del
                    if(QExtRowsOld>allowedMinQ){
                        QExtRowsNew=QExtRowsOld-1;
                    }
                break;
            }
            if(inquiredRowNN<0){
                inquiredRowNN+=(QExtRowsNew+1);
            }
            if(ExtRowNN_0ifAll<0){
                ExtRowNN_0ifAll+=(QExtRowsNew+1);
            }
            if(inquiredRowNN>=1 && inquiredRowNN<=QExtRowsNew){
                // def oldL
                //         ExtRow_SetAddInsDel_OldLengthOfExtRowN(int Action_Set1_Add2_Ins3_Del4_Dflt0, int inquiredRowNN, int ExtRowNN_0ifAll, int givenRowL, TDataShiftParams*ShiftData, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, bool suiValsInsteadOfDefaultValsWherePossible){
                oldL=this->ExtRow_SetAddInsDel_OldLengthOfExtRowN(    Action_Set1_Add2_Ins3_Del4_Dflt0,     inquiredRowNN,     ExtRowNN_0ifAll,     givenRowL,                  ShiftData,     ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4,      suiValsInsteadOfDefaultValsWherePossible);
                // now finalL
                if(Action_Set1_Add2_Ins3_Del4_Dflt0==4){
                    finalL=oldL;
                //}else if(){
                //
                }else{
                    if(inquiredRowNN==ExtRowNN_0ifAll && ExtRowNN_0ifAll>0){
                        finalL=modifiedRowL;
                    }else{// not del and not modified row
                        switch(ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4){
                            case 1://if rect - by new
                                if(this->IsRectangularInFact()){
                                    finalL=modifiedRowL;
                                }else{
                                    finalL=oldL;
                                }
                            break;
                            case 2:
                                finalL=oldL;
                            break;
                            case 3:
                                if(this->IsRectangularInFact() && modifiedRowL>oldL && Action_Set1_Add2_Ins3_Del4_Dflt0!=4){
                                    finalL=modifiedRowL;
                                }else{
                                    finalL=oldL;
                                }
                            break;
                            case 4:
                                if(this->IsRectangularInFact() && modifiedRowL<oldL && Action_Set1_Add2_Ins3_Del4_Dflt0!=4){
                                    finalL=modifiedRowL;
                                }else{
                                    finalL=oldL;
                                }
                            break;
                            case 0:
                                finalL=oldL;
                                // if this->IsRectangularByType()==true - ignored
                                // if this->IsRectangularInFact()==true - row modified is modified, ma amda s'om row rest - D's L remains ob array ades n'rect
                                // if this->IsRectangularInFact()==false - row modified is modified, ma amda s'om row rest - D's L remains ob ns'rect
                            break;
                        }
                    }
                }
            }
            return finalL;
        }

        int Array2DSize_Prototype::ExtRow_SetAddInsDel_Arr2DNewCoordsToDataTypeN(int Action_Set1_Add2_Ins3_Del4_Dflt0, const Coords2DInt&coords, int ExtRowNN_0ifAll, int givenRowL, TDataShiftParams*ShiftData, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, bool suiValsInsteadOfDefaultValsWherePossible){
            //vikt! Ably, amda ns'all ver, ob I n'utf var OldPosOfExtRowN, ic s'vikt'l ut'type==arr2DVal! Cogf l'utf l'to var! => Sgwa I iqv et gecog all gut
            int typeN_OldArr2DVals1_NewGivenRowVals2_DefaultVals3_Incorrect0=0;
            int QExtRowsOld=this->GetQExtRows(), QExtRowsNew, oldL, allowedMinQ=DEFAULT_SIZE, inquiredRowNN=coords.x, IneRowNN=coords.y, finalL;
            int newModifiedRowPosInArr2D, oldModifiedRowPosInArr2D, oldPosOfNewInquiredExtRowN;
            //               ExtRow_SetAddInsDel_ThatCorrectedByNewData_NewLength(int Action_Set1_Add2_Ins3_Del4_Dflt0, int givenRowL=0, int ExtRowNN_0ifAll=-1, TDataShiftParams*DataShiftParam=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0, bool suiValsInsteadOfDefaultValsWherePossible=true);
            int modifiedRowL=ExtRow_SetAddInsDel_ThatCorrectedByNewData_NewLength(    Action_Set1_Add2_Ins3_Del4_Dflt0,     givenRowL,       ExtRowNN_0ifAll,                     ShiftData,          ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4,        suiValsInsteadOfDefaultValsWherePossible);
            //QExtRowsNew
            switch(Action_Set1_Add2_Ins3_Del4_Dflt0){
                case 1://Set
                    QExtRowsNew=QExtRowsOld;
                break;
                case 2://Add
                    QExtRowsNew=QExtRowsOld+1;
                break;
                case 3://Ins
                    QExtRowsNew=QExtRowsOld+1;
                break;
                case 4://Del
                    if(QExtRowsOld>allowedMinQ){
                        QExtRowsNew=QExtRowsOld-1;
                    }
                break;
            }
            if(inquiredRowNN<0){
                inquiredRowNN+=(QExtRowsNew+1);
            }
            if(ExtRowNN_0ifAll<0){
                ExtRowNN_0ifAll+=(QExtRowsNew+1);
            }
            if(inquiredRowNN>=1 && inquiredRowNN<=QExtRowsNew){
                if(IneRowNN<0){
                    IneRowNN+=(modifiedRowL+1);
                }
                finalL=this->ExtRow_SetAddInsDel_NewLengthOfExtRowN(    Action_Set1_Add2_Ins3_Del4_Dflt0,     inquiredRowNN,     ExtRowNN_0ifAll,     givenRowL,                  ShiftData,     ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4,       suiValsInsteadOfDefaultValsWherePossible);
                if(IneRowNN>=1 && IneRowNN<=finalL){
                    if(Action_Set1_Add2_Ins3_Del4_Dflt0==4){//del
                        // => finalL=oldL, to fun arb tak
                        typeN_OldArr2DVals1_NewGivenRowVals2_DefaultVals3_Incorrect0=1;
                    }else{
                        if(Action_Set1_Add2_Ins3_Del4_Dflt0==2 && QExtRowsOld==0){ //add, et ad noin //and to empty
                            // nur 1 row N <= QExtRowsNew is 1., ic s'new geq'y
                            typeN_OldArr2DVals1_NewGivenRowVals2_DefaultVals3_Incorrect0=2;
                        }else{
                            //---
                            switch(Action_Set1_Add2_Ins3_Del4_Dflt0){
                                case 1:
                                    newModifiedRowPosInArr2D=ExtRowNN_0ifAll;
                                    oldModifiedRowPosInArr2D=ExtRowNN_0ifAll;
                                    oldPosOfNewInquiredExtRowN=coords.x;
                                break;
                                case 2:
                                    newModifiedRowPosInArr2D=QExtRowsOld+1;
                                    oldModifiedRowPosInArr2D=ExtRowNN_0ifAll;
                                    oldPosOfNewInquiredExtRowN=coords.x;
                                break;
                                case 3:
                                    newModifiedRowPosInArr2D=ExtRowNN_0ifAll;
                                    oldModifiedRowPosInArr2D=ExtRowNN_0ifAll;
                                    if(coords.x<=ExtRowNN_0ifAll){
                                        oldPosOfNewInquiredExtRowN=coords.x;
                                    }else{
                                        oldPosOfNewInquiredExtRowN=coords.x-1;
                                    }
                                break;
                                case 4:
                                    newModifiedRowPosInArr2D=0;
                                    oldModifiedRowPosInArr2D=0;
                                    if(coords.x<=ExtRowNN_0ifAll){
                                        oldPosOfNewInquiredExtRowN=coords.x;
                                    }else{
                                        oldPosOfNewInquiredExtRowN=coords.x+1;
                                    }
                                break;
                            }
                            //---
                            if(inquiredRowNN==oldModifiedRowPosInArr2D){ // modified row // same as comment'd udda, ob to vars s'idq
                                // if(inquiredRowNN==ExtRowNN_0ifAll){
                                // Sha spec fun, def'n l'typeN ut'modif'd row
                                //                                                                 ExtRow_SetAddInsDel_ThatCorrectedByNewData_PosInRowToDataTypeN(int Action_Set1_Add2_Ins3_Del4_Dflt0, int InRowPosNN, int givenRowL, int ExtRowNN_0ifAll, TDataShiftParams*DataShiftParam, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, bool suiValsInsteadOfDefaultValsWherePossible){
                                //                                                             int ExtRow_SetAddInsDel_ThatCorrectedByNewData_PosInRowToDataTypeN(int Action_Set1_Add2_Ins3_Del4_Dflt0, int InRowPosNN, int givenRowL=0, int ExtRowNN_0ifAll=-1, TDataShiftParams*DataShiftParam=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0, bool suiValsInsteadOfDefaultValsWherePossible=true);
                                typeN_OldArr2DVals1_NewGivenRowVals2_DefaultVals3_Incorrect0=this->ExtRow_SetAddInsDel_ThatCorrectedByNewData_PosInRowToDataTypeN(    Action_Set1_Add2_Ins3_Del4_Dflt0,     IneRowNN,     givenRowL,       ExtRowNN_0ifAll,                          ShiftData,          ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4,        suiValsInsteadOfDefaultValsWherePossible);
                            }else{//n'modif'd row
                                //         ExtRow_SetAddInsDel_OldLengthOfExtRowN(int Action_Set1_Add2_Ins3_Del4_Dflt0, int inquiredRowNN, int ExtRowNN_0ifAll, int givenRowL, TDataShiftParams*ShiftData, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, bool suiValsInsteadOfDefaultValsWherePossible){
                                oldL=this->ExtRow_SetAddInsDel_OldLengthOfExtRowN(    Action_Set1_Add2_Ins3_Del4_Dflt0,     inquiredRowNN,     ExtRowNN_0ifAll,     givenRowL,                  ShiftData,     ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4,      suiValsInsteadOfDefaultValsWherePossible);
                                //                 ExtRow_SetAddInsDel_NewLengthOfExtRowN(int Action_Set1_Add2_Ins3_Del4_Dflt0, int inquiredRowNN, int ExtRowNN_0ifAll, int givenRowL, TDataShiftParams*ShiftData, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4,  bool suiValsInsteadOfDefaultValsWherePossible){
                                //finalL=this->ExtRow_SetAddInsDel_NewLengthOfExtRowN(    Action_Set1_Add2_Ins3_Del4_Dflt0,     inquiredRowNN,     ExtRowNN_0ifAll,     givenRowL,                  ShiftData,     ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4,       suiValsInsteadOfDefaultValsWherePossible);
                                if(IneRowNN<=oldL){
                                    typeN_OldArr2DVals1_NewGivenRowVals2_DefaultVals3_Incorrect0=1;
                                }else{
                                    typeN_OldArr2DVals1_NewGivenRowVals2_DefaultVals3_Incorrect0=3;
                                }

                            }
                        }
                    }
                }//else type=0
            }
            return typeN_OldArr2DVals1_NewGivenRowVals2_DefaultVals3_Incorrect0;
        }

        //...................................................................................................
        //int                      ExtRow_SetAddInsDel_ThatCorrectedByNewData_FromArr2dNewToGivenRowPosN(int Action_Set1_Add2_Ins3_Del4_Dflt0, int InRowPosNN, int givenRowL=0, int ChangedRowNN_0ifAll=-1, TDataShiftParams*DataShiftParam=NULL, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4=0, bool suiValsInsteadOfDefaultValsWherePossible=true);
        int Array2DSize_Prototype::ExtRow_SetAddInsDel_ThatCorrectedByNewData_FromArr2dNewToGivenRowPosN(int Action_Set1_Add2_Ins3_Del4_Dflt0, int InRowPosNN,  int givenRowL, int ChangedRowNN_0ifAll, TDataShiftParams*DataShiftParam, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, bool suiValsInsteadOfDefaultValsWherePossible){
            int givenRowPosN=0, dataTypeN_OldArrayVal1_NewRowGivenVal2_DefaultVal3_Incorrect0;
            TDataShiftResults shiftDataR=this->ExtRow_SetAddInsDel_dataNs(Action_Set1_Add2_Ins3_Del4_Dflt0, givenRowL, /*int inquiredRowNN=-1,*/ ChangedRowNN_0ifAll, DataShiftParam, ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, suiValsInsteadOfDefaultValsWherePossible);
            if(dataTypeN_OldArrayVal1_NewRowGivenVal2_DefaultVal3_Incorrect0==2){
                givenRowPosN=shiftDataR.ForOwnN1+InRowPosNN-1;
            }
            return givenRowPosN;
        }

        int Array2DSize_Prototype::ExtRow_SetAddInsDel_ThatCorrectedByNewData_FromArr2dNewToOldRowPosN(int Action_Set1_Add2_Ins3_Del4_Dflt0, int InRowPosNN,/*const Coords2DInt&coords,*/ int givenRowL, int ExtRowNN_0ifAll, TDataShiftParams*DataShiftParam, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, bool suiValsInsteadOfDefaultValsWherePossible){
            int oldArr2DRowPosN=0, dataTypeN_OldArrayVal1_NewRowGivenVal2_DefaultVal3_Incorrect0=0;//, InRowPosNN=coords.y;
            dataTypeN_OldArrayVal1_NewRowGivenVal2_DefaultVal3_Incorrect0=this->ExtRow_SetAddInsDel_ThatCorrectedByNewData_PosInRowToDataTypeN(Action_Set1_Add2_Ins3_Del4_Dflt0, InRowPosNN, givenRowL, ExtRowNN_0ifAll, DataShiftParam, ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, suiValsInsteadOfDefaultValsWherePossible);
            if(dataTypeN_OldArrayVal1_NewRowGivenVal2_DefaultVal3_Incorrect0==1){
                oldArr2DRowPosN=InRowPosNN;
            }
            return oldArr2DRowPosN;
        }
        //....................................................................................................
        //        int Array2DSize_Prototype::ExtRow_SetAddInsDel_ThatCorrectedByNewData_FromArr2dNewToGivenRowPosN(int Action_Set1_Add2_Ins3_Del4_Dflt0, int InRowPosNN, /*const Coords2DInt&coords,*/ int givenRowL, int ExtRowNN_0ifAll, TDataShiftParams*DataShiftParam, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, bool suiValsInsteadOfDefaultValsWherePossible){
        //            int inGivenRowPosNN=0, inOldArr2DRowPosNN, dataTypeN_OldArrayVal1_NewRowGivenVal2_DefaultVal3_Incorrect0,   QExtRowsOld=this->GetQExtRows(), QExtRowsNew, allowedMinQ=DEFAULT_SIZE, oldL, finalL;
        //            int newModifiedRowPosInArr2D, newInquiredRowPosInArr2D;//, oldPosOfNewInquiredExtRowN;
        //            switch(Action_Set1_Add2_Ins3_Del4_Dflt0){
        //                case 1:
        //                    QExtRowsNew=QExtRowsOld;
        //                break;
        //                case 2:
        //                    QExtRowsNew=QExtRowsOld+1;
        //                break;
        //                case 3:
        //                    QExtRowsNew=QExtRowsOld+1;
        //                break;
        //                case 4:
        //                    if(QExtRowsOld>allowedMinQ){
        //                        QExtRowsNew=QExtRowsOld-1;
        //                    }else{
        //                        QExtRowsNew=QExtRowsOld;
        //                    }
        //                break;
        //            }
        //            if(ExtRowNN_0ifAll<0){
        //                ExtRowNN_0ifAll+=(QExtRowsNew+1);
        //            }
        //            if(coords.x<0){
        //                coords.x+=(QExtRowsNew+1);
        //            }
        //            switch(Action_Set1_Add2_Ins3_Del4_Dflt0){
        //                case 1:
        //                    newModifiedRowPosInArr2D=ExtRowNN_0ifAll;
        //                    newInquiredRowPosInArr2D=coords.x;
        //                    //oldPosOfNewInquiredExtRowN=coords.x;
        //                break;
        //                case 2:
        //                    newModifiedRowPosInArr2D=QExtRowsOld+1;
        //                    newInquiredRowPosInArr2D=coords.x;
        //                    //oldPosOfNewInquiredExtRowN=coords.x;
        //                break;
        //                case 3:
        //                    newModifiedRowPosInArr2D=ExtRowNN_0ifAll;
        //                    if(coords.x<=ExtRowNN_0ifAll){
        //                        newInquiredRowPosInArr2D=coords.x;
        //                    }else{
        //                        newInquiredRowPosInArr2D=coords.x+1;
        //                    }
        //                    //if(coords.x<=ExtRowNN_0ifAll){
        //                    //    oldPosOfNewInquiredExtRowN=coords.x;
        //                    //}else{
        //                    //    oldPosOfNewInquiredExtRowN=coords.x-1;
        //                    //}
        //                break;
        //                case 4:
        //                    newModifiedRowPosInArr2D=0;
        //                    if(coords.x<=ExtRowNN_0ifAll){
        //                        newInquiredRowPosInArr2D=coords.x;
        //                    }else{
        //                        newInquiredRowPosInArr2D=coords.x-1;
        //                    }
        //                    //if(coords.x<=ExtRowNN_0ifAll){
        //                    //    oldPosOfNewInquiredExtRowN=coords.x;
        //                    //}else{
        //                    //    oldPosOfNewInquiredExtRowN=coords.x+1;
        //                    //}
        //                break;
        //            }
        //            if(newModifiedRowPosInArr2D>0 && coords.x==newModifiedRowPosInArr2D){
        //                finalL=this->ExtRow_SetAddInsDel_ThatCorrectedByNewData_NewLength(Action_Set1_Add2_Ins3_Del4_Dflt0, givenRowL, ExtRowNN_0ifAll, DataShiftParam, ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, suiValsInsteadOfDefaultValsWherePossible);
        //                if(coords.y<0){
        //                    coords.y+=(finalL+1;)
        //                }
        //                inOldArr2DRowPosNN=coords.y;
        //                givenRowPosN=this->ExtRow_SetAddInsDel_ThatCorrectedByNewData_FromArr2dNewToGivenRowPosN(Action_Set1_Add2_Ins3_Del4_Dflt0, inOldArr2DRowPosNN, givenRowL, ExtRowNN_0ifAll, DataShiftParam, ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, suiValsInsteadOfDefaultValsWherePossible);
        //            }//else 0, ic s' dflt
        //            return givenRowPosN;
        //        }

        Coords2DInt Array2DSize_Prototype::ExtRow_SetAddInsDel_ThatCorrectedByNewData_CoordsFromArr2dNewToOld(int Action_Set1_Add2_Ins3_Del4_Dflt0, const Coords2DInt&coords, int givenRowL, int ExtRowNN_0ifAll, TDataShiftParams*DataShiftParam, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, bool suiValsInsteadOfDefaultValsWherePossible){
            Coords2DInt coordsROld;
            int inGivenRowPosNN=0, inOldArr2DRowPosNN,  QExtRowsOld=this->GetQExtRows(), QExtRowsNew, allowedMinQ=DEFAULT_SIZE, inquiredRowNN=coords.x;
            int dataTypeN_OldArrayVal1_NewRowGivenVal2_DefaultVal3_Incorrect0=this->ExtRow_SetAddInsDel_Arr2DNewCoordsToDataTypeN(Action_Set1_Add2_Ins3_Del4_Dflt0, coords, ExtRowNN_0ifAll, givenRowL, DataShiftParam, ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, suiValsInsteadOfDefaultValsWherePossible);
            int oldL=this->ExtRow_SetAddInsDel_OldLengthOfExtRowN(Action_Set1_Add2_Ins3_Del4_Dflt0, inquiredRowNN, ExtRowNN_0ifAll, givenRowL, DataShiftParam, ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, suiValsInsteadOfDefaultValsWherePossible);
            int finalL=this->ExtRow_SetAddInsDel_NewLengthOfExtRowN(Action_Set1_Add2_Ins3_Del4_Dflt0, inquiredRowNN, ExtRowNN_0ifAll, givenRowL, DataShiftParam, ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4,  suiValsInsteadOfDefaultValsWherePossible);
            int newModifiedRowPosInArr2D, oldPosOfNewInquiredExtRowN, newInquiredRowPosInArr2D;
            if(dataTypeN_OldArrayVal1_NewRowGivenVal2_DefaultVal3_Incorrect0==1){
                switch(Action_Set1_Add2_Ins3_Del4_Dflt0){
                    case 1:
                        QExtRowsNew=QExtRowsOld;
                    break;
                    case 2:
                        QExtRowsNew=QExtRowsOld+1;
                    break;
                    case 3:
                        QExtRowsNew=QExtRowsOld+1;
                    break;
                    case 4:
                        if(QExtRowsOld>allowedMinQ){
                            QExtRowsNew=QExtRowsOld-1;
                        }else{
                            QExtRowsNew=QExtRowsOld;
                        }
                    break;
                }
                if(ExtRowNN_0ifAll<0){
                    ExtRowNN_0ifAll+=(QExtRowsNew+1);
                }
                if(inquiredRowNN<0){
                    inquiredRowNN+=(QExtRowsNew+1);
                }
                switch(Action_Set1_Add2_Ins3_Del4_Dflt0){
                    case 1:
                        newModifiedRowPosInArr2D=ExtRowNN_0ifAll;
                        oldPosOfNewInquiredExtRowN=inquiredRowNN;
                    break;
                    case 2:
                        newModifiedRowPosInArr2D=QExtRowsOld+1;
                        oldPosOfNewInquiredExtRowN=inquiredRowNN;
                    break;
                    case 3:
                        newModifiedRowPosInArr2D=ExtRowNN_0ifAll;
                        if(coords.x<=ExtRowNN_0ifAll){
                            oldPosOfNewInquiredExtRowN=inquiredRowNN;
                        }else{
                            oldPosOfNewInquiredExtRowN=inquiredRowNN-1;
                        }
                    break;
                    case 4:
                        newModifiedRowPosInArr2D=0;
                        if(coords.x<=ExtRowNN_0ifAll){
                            oldPosOfNewInquiredExtRowN=inquiredRowNN;
                        }else{
                            oldPosOfNewInquiredExtRowN=inquiredRowNN+1;
                        }
                    break;
                }
                if(dataTypeN_OldArrayVal1_NewRowGivenVal2_DefaultVal3_Incorrect0==1){
                    coordsROld.y=coords.y;
                    coordsROld.x=oldPosOfNewInquiredExtRowN;
                }
                //if(newModifiedRowPosInArr2D>0 && coords.x==newModifiedRowPosInArr2D){
                //    finalL=this->ExtRow_SetAddInsDel_ThatCorrectedByNewData_NewLength(Action_Set1_Add2_Ins3_Del4_Dflt0, givenRowL, ExtRowNN_0ifAll, DataShiftParam, ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, suiValsInsteadOfDefaultValsWherePossible);
                //    if(coords.y<0){
                //        coords.y+=(finalL+1;)
                //    }
                //    inOldArr2DRowPosNN=coords.y;
                //    dataTypeN_OldArrayVal1_NewRowGivenVal2_DefaultVal3_Incorrect0=this->ExtRow_SetAddInsDel_Arr2DNewCoordsToDataTypeN(Action_Set1_Add2_Ins3_Del4_Dflt0, coords, ExtRowNN_0ifAll, givenRowL, ShiftData, ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, suiValsInsteadOfDefaultValsWherePossible);
                //
                //}else{
                //
                //}
            }//else 0 ic s'default
            return coordsROld;
        }


        //----------------------------------------------------------------------------------------------------
        // virtual void  Set_GetExtNewRowLength(int* extRowsLengthes, int QExtRows=1, int ifNotRect_NonRect0_MakeRectBy_Min1Max2=0)=0;
        //int Set_GetExtNewRowLength(int* extRowsLengthes, int QExtRows=1, int ifNotRect_NonRect0_MakeRectBy_Min1Max2=0);//no need - 4 tgos: Lcur, Lold, Lmin, Lmax
        void Array2DSize_Prototype::Set(std::vector<int>Ls, int ifNotRect_NonRect0_MakeRectBy_Min1Max2){
            this->Set(Ls.data(), Ls.size(), ifNotRect_NonRect0_MakeRectBy_Min1Max2);
        }
        void Array2DSize_Prototype::Set(int QExtRows, int extRowsLength){
            std::vector<int>Ls;
            for(int i=-0; i<QExtRows; i++){
                Ls.push_back(extRowsLength);
            }
            this->Set(Ls);
        }

//        int Array2DSize_Prototype::Set_Arr2DNewCoordsToDataNewExtRowL(int ExtRowNN, int* extRowsLengthes, int QExtRows, int ifNotRect_NonRect0_MakeRectBy_Min1Max2){
//            int Lr=0;
//            if(ExtRowNN<0){
//                ExtRowNN+=(QExtRows+1);
//            }
//            if(ExtRowNN>=1 && ExtRowNN<=QExtRows && extRowsLengthes!=NULL){
//                for(int i=0; i<QExtRows; i++){
//                    curL=extRowsLengthes[i];
//                    if(i==0 || (i>0 && curL<Lmin)){
//                        Lmin=curL;
//                    }
//                    if(i==0 || (i>0 && curL>Lmax)){
//                        Lmax=curL;
//                    }
//                }
//                if(this->IsRectangularInFact()==false){
//                    Lr= extRowsLengthes[ExtRowNN-1];
//                }else if(Lmin==Lmax){
//                    Lr= extRowsLengthes[ExtRowNN-1];
//                }else{
//                    switch(ifNotRect_NonRect0_MakeRectBy_Min1Max2){
//                        case 1:
//                            Lr=Lmax;
//                        break;
//                        case 2:
//                            Lr=Lmin;
//                        break;
//                    }
//                }
//            }
//            return Lr;
//        }
        //int Set_Arr2DNewCoordsToDataTypeN(                     const Coords2DInt&coords, int* extRowsLengthes, int QExtRows=1, int ifNotRect_NonRect0_MakeRectBy_Min1Max2=0, bool IfNotValsOfGivenRow_DefaultNotOwn=true);
        int Array2DSize_Prototype::Set_Arr2DNewCoordsToDataTypeN(const Coords2DInt&coords, int* extRowsLengthes, int QExtRows,   int ifNotRect_NonRect0_MakeRectBy_Min1Max2, bool IfNotValsOfGivenRow_DefaultNotOwn){
            int typeN_NewVals1_DfltVals2_OldVals3_Incorrect0=0;//old vals s'noif
            int curL, Lmin, Lmax, Lnew, QExtRowsOld=this->GetQExtRows(), QExtRowsNew=QExtRows, ExtRowNN;
            if(extRowsLengthes!=NULL){
                for(int i=0; i<QExtRows; i++){
                    curL=extRowsLengthes[i];
                    if(i==0 || (i>0 && curL<Lmin)){
                        Lmin=curL;
                    }
                    if(i==0 || (i>0 && curL>Lmax)){
                        Lmax=curL;
                    }
                }
                ExtRowNN=coords.x;
                if(ExtRowNN<0){
                    ExtRowNN+=(QExtRows+1);
                }
                if(ExtRowNN>=1 || ExtRowNN<=QExtRows){//else type==0
                    //Lnew=this->Set_Arr2DNewCoordsToDataNewExtRowL(ExtRowNN, extRowsLengthes, QExtRows, ifNotRect_NonRect0_MakeRectBy_Min1Max2);
                    //no need - 4 tgos: Lcur, Lold, Lmin, Lmax
                    Lnew=extRowsLengthes[ExtRowNN-1];//qob ne?
                    if(Lnew<=extRowsLengthes[ExtRowNN-1]){
                        typeN_NewVals1_DfltVals2_OldVals3_Incorrect0=1;
                    }else{
                        typeN_NewVals1_DfltVals2_OldVals3_Incorrect0=2;
                    }
                }
            }
            return typeN_NewVals1_DfltVals2_OldVals3_Incorrect0;
        }

        Coords2DInt Array2DSize_Prototype::Set_Arr2DNewToOldCoords(const Coords2DInt&coords, int* extRowsLengthes, int QExtRows, int ifNotRect_NonRect0_MakeRectBy_Min1Max2){
            Coords2DInt CoordsOfGiven;
            int typeN=this->Set_Arr2DNewCoordsToDataTypeN(coords, extRowsLengthes, QExtRows, ifNotRect_NonRect0_MakeRectBy_Min1Max2);
            if(typeN==1){
                CoordsOfGiven=coords;
            }//else remain 0
            return CoordsOfGiven;
        }

        QString Array2DSize_Prototype::GetAsString(){
            QString qs="Size: ", sn, ts;
            int QER=this->GetQExtRows(), curL, Lmin=this->GetRowLengthMin(), Lmax=this->GetRowLengthMax();
            qs+="(type: ";
            if(this->GetTypeN()==Arr2DSize_Rect_TypeN){
                ts="Rect";
            }else if(this->GetTypeN()==Arr2DSize_VarLens_V_TypeN){
               ts="VarLV";
            }else if(this->GetTypeN()==Arr2DSize_VarLens_P_TypeN){
                ts="VarLP_EI";
            }
            qs+=ts;
            qs+=") ";
            qs+="QER=";
            sn.setNum(QER);
            qs+=sn;
            qs+=" ERL= ";
            if(this->IsRectangularInFact()==false){
                for(int N=1; N<=QER-1; N++){
                    curL=this->GetRowLength(N);
                    sn.setNum(curL);
                    qs+=sn;
                    qs+=";";
                }
            }
            curL=this->GetRowLength(QER);
            sn.setNum(curL);
            qs+=sn;
            if(this->IsRectangularInFact()==false){
                qs+=". (max=";
                sn.setNum(Lmax);
                qs+=sn;
                qs+="; min=";
                sn.setNum(Lmin);
                qs+=sn;
                qs+=")";
            }
            return qs;
        }

        //----------------------------------------------------------------------------------------------------

        void Array2DSize_Prototype::Set_HilfsFun(int&QExtRowsNew, int&ERLNew, int&DataTypeN_Arr2DVals1_GivenVals2_Default3_Incorrect0, Coords2DInt&CoordsOld, int* extRowsLengthes, int QExtRowsGiven, int ifNotRect_NonRect0_MakeRectBy_Min1Max2MinOfMax3MaxOfMax4, bool IfNotValsOfGivenRow_DefaultNotOwn){
            int QExtRowsOld=this->GetQExtRows(), Lmin=this->GetRowLengthMin(), Lmax=this->GetRowLengthMax(), ERLOld, ERNN, IRNN, LminGiven, LmaxGiven, curLexisting, curLgiven;
            QExtRowsNew=0;
            ERLNew=0;
            DataTypeN_Arr2DVals1_GivenVals2_Default3_Incorrect0=0;
            //Coords2DInt&CoordsOld
            for(ERNN=1; ERNN<=QExtRowsGiven; ERNN++){
                curLgiven=extRowsLengthes[ERNN-1];
                if(ERNN==1 || (ERNN>1 && curLgiven<LminGiven)){
                    LminGiven=curLgiven;
                }
                if(ERNN==1 || (ERNN>1 && curLgiven>LmaxGiven)){
                    LmaxGiven=curLgiven;
                }
            }
            if(LminGiven==LmaxGiven){
                QExtRowsNew=QExtRowsGiven;
                if(ERNN>=1 && ERNN<=QExtRowsNew){
                    ERLNew=LmaxGiven;
                }
            }else{
                if((this->IsRectangularByType() && ifNotRect_NonRect0_MakeRectBy_Min1Max2MinOfMax3MaxOfMax4==0)){
                    //NOp; forbiden operation
                    QExtRowsNew=QExtRowsOld;
                    if(ERNN>=1 && ERNN<=QExtRowsNew){
                        ERLNew=this->GetRowLength(ERNN);
                    }
               }else{
                   QExtRowsNew=QExtRowsGiven;
                   switch(ifNotRect_NonRect0_MakeRectBy_Min1Max2MinOfMax3MaxOfMax4){
                       case 0:
                           if(this->IsRectangularByType()){
                               if(ERNN>=1 && ERNN<=QExtRowsGiven){
                                   ERLOld=this->GetRowLength(ERNN);
                                   ERLNew=ERLOld;
                                   if(IRNN>=1 && IRNN<=ERLNew){
                                       DataTypeN_Arr2DVals1_GivenVals2_Default3_Incorrect0=2;
                                   }//else  DataTypeN_Arr2DVals1_GivenVals2_Default3_Incorrect0=0;
                               }//else  DataTypeN_Arr2DVals1_GivenVals2_Default3_Incorrect0=0;
                           }else{
                               if(ERNN>=1 && ERNN<=QExtRowsGiven){
                                   ERLOld=this->GetRowLength(ERNN);
                                   ERLNew=extRowsLengthes[ERNN-1];
                                   if(IRNN>=1 && IRNN<=ERLNew){
                                       DataTypeN_Arr2DVals1_GivenVals2_Default3_Incorrect0=2;
                                   }//else  DataTypeN_Arr2DVals1_GivenVals2_Default3_Incorrect0=0;
                               }//else  DataTypeN_Arr2DVals1_GivenVals2_Default3_Incorrect0=0;
                           }
                       break;
                       case 1:
                           if(ERNN>=1 && ERNN<=QExtRowsGiven){
                               ERLOld=this->GetRowLength(ERNN);
                           }
                           if(ERNN>=1 && ERNN<=QExtRowsNew){
                               ERLNew=LmaxGiven;//=extRowsLengthes[ERNN-1];
                           }
                       break;
                       case 2:
                           if(ERNN>=1 && ERNN<=QExtRowsGiven){
                               ERLOld=this->GetRowLength(ERNN);
                           }
                           if(ERNN>=1 && ERNN<=QExtRowsNew){
                               ERLNew=LminGiven;//=extRowsLengthes[ERNN-1];
                           }
                       break;
                       case 3:
                           if(ERNN>=1 && ERNN<=QExtRowsGiven){
                               ERLOld=this->GetRowLength(ERNN);
                           }
                           if(ERNN>=1 && ERNN<=QExtRowsNew){
                               if(LmaxGiven>=Lmax){
                                   ERLNew=LmaxGiven;//=extRowsLengthes[ERNN-1];
                               }else if(LminGiven>=Lmax){
                                   ERLNew=LminGiven;
                               }else{
                                   ERLNew=Lmax;
                               }
                           }
                       break;
                       case 4:
                           if(ERNN>=1 && ERNN<=QExtRowsGiven){
                               ERLOld=this->GetRowLength(ERNN);
                           }
                           if(ERNN>=1 && ERNN<=QExtRowsNew){
                               if(LminGiven<=Lmin){
                                   ERLNew=LminGiven;//=extRowsLengthes[ERNN-1];
                               //}else if(Lmax<=LminGiven){
                               //    ERLNew=Lmax;
                               }else{
                                   ERLNew=LminGiven;
                               }
                           }
                       break;
                   }//switch
               }// else n'vikt'l
            }//else vikt'l
            //fin
            if((this->IsRectangularByType() && ifNotRect_NonRect0_MakeRectBy_Min1Max2MinOfMax3MaxOfMax4==0)){
                //forbiden operation
                if(ERNN>=1 && ERNN<=QExtRowsNew){
                    if(IRNN<0){
                        IRNN+=(ERLNew+1);
                    }
                    if(IRNN>=1 && IRNN<=ERLOld){
                        DataTypeN_Arr2DVals1_GivenVals2_Default3_Incorrect0=1;
                        CoordsOld.x=ERNN;
                        CoordsOld.y=IRNN;
                    }//else  DataTypeN_Arr2DVals1_GivenVals2_Default3_Incorrect0=0; ob'IRNN
                }//else  DataTypeN_Arr2DVals1_GivenVals2_Default3_Incorrect0=0; ob'ERNN
            }else{//norm usual case
                if(ERNN>=1 && ERNN<=QExtRowsNew){
                    if(IRNN<0){
                        IRNN+=(curLgiven+1);
                    }
                    if(ERNN<=QExtRowsGiven){
                        curLgiven=extRowsLengthes[ERNN-1];
                        if(IRNN>=1 && ERLNew){
                            if(IRNN<=curLgiven){
                                DataTypeN_Arr2DVals1_GivenVals2_Default3_Incorrect0=2;
                                CoordsOld.x=ERNN;
                                CoordsOld.y=IRNN;
                            }else{
                                if(ERNN<=QExtRowsOld){
                                    curLexisting=this->GetRowLength(ERNN);
                                    if(IRNN<=curLexisting && IRNN>=curLgiven){
                                        if(IfNotValsOfGivenRow_DefaultNotOwn==false){
                                            DataTypeN_Arr2DVals1_GivenVals2_Default3_Incorrect0=1;
                                            CoordsOld.x=ERNN;
                                            CoordsOld.y=IRNN;
                                        }else{
                                            DataTypeN_Arr2DVals1_GivenVals2_Default3_Incorrect0=3;
                                        }
                                    }else{
                                        DataTypeN_Arr2DVals1_GivenVals2_Default3_Incorrect0=3;
                                    }
                                }else{
                                    DataTypeN_Arr2DVals1_GivenVals2_Default3_Incorrect0=3;
                                }
                            }
                        }
                    }else{
                        if(ERNN<=QExtRowsOld){
                            curLexisting=this->GetRowLength(ERNN);
                            if(IfNotValsOfGivenRow_DefaultNotOwn==false){
                                DataTypeN_Arr2DVals1_GivenVals2_Default3_Incorrect0=1;
                                CoordsOld.x=ERNN;
                                CoordsOld.y=IRNN;
                            }else{
                                DataTypeN_Arr2DVals1_GivenVals2_Default3_Incorrect0=3;
                            }
                        }else{
                            DataTypeN_Arr2DVals1_GivenVals2_Default3_Incorrect0=3;
                        }
                    }//
                }else{
                    DataTypeN_Arr2DVals1_GivenVals2_Default3_Incorrect0=0;
                }
            }//if, all tgos s'inda
        }//fun

        // ===========================================================================================================

        //class Array2DSize_Rectangular: public Array2DSize_Prototype{
        //    int QExtRows;
        //    int ExtRowsLength;
        //    //
        //  public:
            Array2DSize_Rectangular::Array2DSize_Rectangular(){
                this->construct();
            }
            Array2DSize_Rectangular::Array2DSize_Rectangular(int QExtRows, int*RowsLs, int ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2){
                this->construct();
                this->Set(RowsLs, QExtRows, ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2);
            }

            Array2DSize_Rectangular::Array2DSize_Rectangular(int QExtRows, int RowsLs){
                this->construct();
                this->Set(QExtRows, RowsLs);
            }
            Array2DSize_Rectangular::Array2DSize_Rectangular(std::vector<int>Ls, int ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2){
                this->construct();
                this-> Array2DSize_Prototype::Set(Ls, ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2);
            }
            //virtual ~Array2DSize_Prototype();
            Array2DSize_Rectangular::~Array2DSize_Rectangular(){}
            //
            //std::vector<int> GetAsArrayOfExtRowsLengthes()const;  //new
            //
            //void construct(){
            //    int
            //}

            void Array2DSize_Rectangular::SetNull(){
                this->QExtRows=0;
                this->ExtRowsLength=0;
            }

            void Array2DSize_Rectangular::SetNullIni(){
                this->QExtRows=0;
                this->ExtRowsLength=0;
            }
            void Array2DSize_Rectangular::SetOne(){
                this->QExtRows=1;
                this->ExtRowsLength=1;
            }
            //
            int Array2DSize_Rectangular::GetTypeN()const{
                return Arr2DSize_Rect_TypeN;
            }
            //
            void Array2DSize_Rectangular::Assign(Array2DSize_Prototype*obj){
                this->Set(obj->GetQExtRows(), obj->GetRowLengthMax());
            }

            //
            void Array2DSize_Rectangular::Set(int* extRowsLengthes, int QExtRows, int ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2){
                int curL, Lmin, Lmax, minSizeAllowed=DEFAULT_SIZE;
                if(QExtRows==0 && minSizeAllowed==0){
                        this->SetNull();
                }else{
                    if(QExtRows==0){
                        QExtRows=this->GetQExtRows();
                    }
                    if(extRowsLengthes!=NULL){
                        for(int i=0; i<QExtRows; i++){
                            curL=extRowsLengthes[i];
                            if(i==0 || (i>0 && curL<Lmin)){
                                Lmin=curL;
                            }
                            if(i==0 || (i>0 && curL>Lmax)){
                                Lmax=curL;
                            }
                        }
                        if(Lmin==Lmax){
                            if(QExtRows>0){
                                this->QExtRows=QExtRows;
                            }
                            this->ExtRowsLength=Lmax;
                        }else{
                            switch(ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2){
                                case 1:
                                    this->ExtRowsLength=Lmax;
                                break;
                                case 2:
                                    this->ExtRowsLength=Lmin;
                                break;
                                //case 3:
                                //
                                //break;
                                //case 4:
                                //
                                //break;
                            }
                        }
                    }
                }
            }

            void Array2DSize_Rectangular::Set(int QExtRows, int extRowsLength, int ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2){
                if(QExtRows>0){
                    this->QExtRows=QExtRows;
                }
                this->ExtRowsLength=extRowsLength;
            }
            //void Array2DSize_Rectangular::Set(std::vector<int>Ls, int ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2){
            //    this->Set(Ls.data(),Ls.size(), ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2);
            //}

            //
            int Array2DSize_Rectangular::GetQExtRows() const{
                return this->QExtRows;
            }
            int Array2DSize_Rectangular::GetRowLength(int N) const{
                return this->ExtRowsLength;
            }
            int Array2DSize_Rectangular::GetRowLengthMin() const{
                return this->ExtRowsLength;
            }
            int Array2DSize_Rectangular::GetRowLengthMax() const{
                 this->ExtRowsLength;
            }
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
            //virtual bool IsEmpty() const =0;
            //
            //
            void Array2DSize_Rectangular::setExtRow_simplyAsDataGiven(int N, int L, int ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4){
                if(N<0){
                    N+=(this->QExtRows+1);
                }
                if(L==0){
                    L=this->ExtRowsLength;
                }
                if(L>0 && N>=0 && N<=this->QExtRows){
                    if(N>=1){
                        if(L==this->ExtRowsLength){
                            //NOp: for size nil changes
                        }else{
                            switch(ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4){
                                case 0:
                                case 2:
                                    //NOp: ignored
                                break;
                                case 1:
                                    this->ExtRowsLength=L;
                                break;
                                case 3:
                                    if(L>this->ExtRowsLength){
                                        this->ExtRowsLength=L;
                                    }
                                break;
                                case 4:
                                    if(L<this->ExtRowsLength){
                                        this->ExtRowsLength=L;
                                    }
                                break;
                            }
                        }
                    }
                }
            }

            void Array2DSize_Rectangular::addExtRow_simplyAsDataGiven(int L,        int ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4){
                this->QExtRows+=1;
                if(L>0 && L!=this->ExtRowsLength){
                    switch(ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4){
                        case 1:
                            this->ExtRowsLength=L;
                        break;
                        case 2:
                            //NOp;
                        break;
                        case 3:
                            if(L>this->ExtRowsLength){
                                this->ExtRowsLength=L;
                            }
                        break;
                        case 4:
                        if(L<this->ExtRowsLength){
                            this->ExtRowsLength=L;
                        }
                        break;
                    }
                }
            }

            void Array2DSize_Rectangular::insExtRow_simplyAsDataGiven(int L, int N, int ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4){
                if(N<0){
                    N+=(this->QExtRows+1);
                }
                if(N>=1 && N<=this->QExtRows){
                    this->QExtRows+=1;
                    if(L>0 && L!=this->ExtRowsLength){
                        switch(ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4){
                            case 1:
                                this->ExtRowsLength=L;
                            break;
                            case 2:
                                //NOp;
                            break;
                            case 3:
                                if(L>this->ExtRowsLength){
                                    this->ExtRowsLength=L;
                                }
                            break;
                            case 4:
                            if(L<this->ExtRowsLength){
                                this->ExtRowsLength=L;
                            }
                            break;
                        }
                    }
                }
            }

            void Array2DSize_Rectangular::delExtRow_simplyAsDataGiven(       int N){
                int allowedMinSize=Arr2DSize_Rect_TypeN;
                if(this->QExtRows>allowedMinSize){
                    this->QExtRows-=1;
                }
            }

            //
            //
            void Array2DSize_Rectangular:: set_or_ins_IneRow_simplyAsDataGiven(int Action_Set1_Ins2, int N, int L, int ifL_NE_QER_Ignore0_MakeRactChangingBy_New1Old2Max3Min4, int ifLminLTN_ifAdd_N1_Lmax2_LmaxRest3_MakeRectAnyway_Lmax4_LmaxRest5){
                int QExtRowsOld=this->GetQExtRows(), Lmin=this->GetRowLengthMin(), Lmax=this->GetRowLengthMax(), LMaxLimited, LLast;
                if(N<0){
                    N+=(Lmax+1);
                }
                if(L>0 && L!=this->QExtRows && N>=1 && N<=Lmax){
                    if(Action_Set1_Ins2==2){
                        this->ExtRowsLength+=1;
                    }
                    switch(ifL_NE_QER_Ignore0_MakeRactChangingBy_New1Old2Max3Min4){
                        case 1:
                            this->QExtRows=L;
                        break;
                        case 2:
                            //NOp;
                        break;
                        case 3:
                            if(L>this->QExtRows){
                                this->QExtRows=L;
                            }
                        break;
                        case 4:
                            if(L<this->QExtRows){
                                this->QExtRows=L;
                            }
                        break;
                            //default: case 0: NOp; - NOp
                    }
                }//else NOp
            }//fn

            //
            void Array2DSize_Rectangular::addIneRow_simplyAsDataGiven(int L,        int ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4, int IfLIsGreaterHowToAddRows_AsItIs_Adding_Max1yMin2yLast3IRN4_SetRect_LMax10Min20LLast30IRN40){
                this->ExtRowsLength+=1;
                if(L>0 && L!=this->QExtRows){
                    switch(ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4){
                        case 1:
                            this->QExtRows=L;
                        break;
                        case 2:
                            //NOp;
                        break;
                        case 3:
                            if(L>this->QExtRows){
                                this->QExtRows=L;
                            }
                        break;
                        case 4:
                        if(L<this->QExtRows){
                            this->QExtRows=L;
                        }
                        break;
                    }
                }
            }



            void Array2DSize_Rectangular::delIneRow_simplyAsDataGiven(       int N, int ifNGTLminIgnore0ShortenNurLongRows1){
                int allowedMinSize=Arr2DSize_Rect_TypeN;
                if(this->ExtRowsLength>allowedMinSize){
                    this->ExtRowsLength-=1;
                }
            }

            //

            //

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

            //void Array2DSize_Rectangular::Set(int* extRowsLengthes, int QExtRowsGiven, int ifNotRect_NonRect0_MakeRectBy_Min1Max2MinOfMax3MaxOfMax4, bool IfNotValsOfGivenRow_DefaultNotOwn){
            //    int LminGiven, LmaxGiven, QExtRowsOld=this->GetQExtRows(), Lmin=this->GetRowLengthMin(), Lmax=this->GetRowLengthMax(), curLgiven, curLexisting;
            //    for(int ERNN=1; ERNN<=QExtRowsGiven; ERNN++){
            //        curLgiven=extRowsLengthes[ERNN-1];
            //        if(ERNN==1 || (ERNN>=1 && curLgiven<LminGiven)){
            //            LminGiven=curLgiven;
            //        }
            //        if(ERNN==1 || (ERNN>=1 && curLgiven>LmaxGiven)){
            //            LmaxGiven=curLgiven;
            //        }
            //    }
            //    if(LmaxGiven==LminGiven){
            //        this->QExtRows=QExtRowsGiven;
            //        this->ExtRowsLength=LmaxGiven;
            //    }else{
            //        switch(ifNotRect_NonRect0_MakeRectBy_Min1Max2MinOfMax3MaxOfMax4){
            //            case 0:
            //            case 2:
            //                //NOp; ob IsRextangularByType()==true;
            //            break;
            //            case 1:
            //                this->QExtRows=QExtRowsGiven;
            //                this->ExtRowsLength=LmaxGiven;
            //            break;
            //            case 3:
            //                this->QExtRows=QExtRowsGiven;
            //                if(LmaxGiven>Lmax){
            //                    this->ExtRowsLength=LmaxGiven;
            //                }//else NOp;
            //            break;
            //            case 4:
            //            this->QExtRows=QExtRowsGiven;
            //                if(LminGiven<Lmin){
            //                    this->ExtRowsLength=LmaxGiven;
            //                }//else NOp;
            //            break;
            //        }
            //    }
            //}//fn

            //void Set(std::vector<int>Ls, int ifNotRect_NonRect0_MakeRectBy_Min1Max2=0);
            ////int Set_GetExtNewRowLength(int* extRowsLengthes, int QExtRows, int ifNotRect_NonRect0_MakeRectBy_Min1Max2=0);//no need - 4 tgos: Lcur, Lold, Lmin, Lmax
            //int Set_Arr2DNewCoordsToDataTypeN(const Coords2DInt&coords, int* extRowsLengthes, int QExtRows=1, int ifNotRect_NonRect0_MakeRectBy_Min1Max2=0);
            //Coords2DInt Set_Arr2DNewToOldCoords(const Coords2DInt&coords, int* extRowsLengthes, int QExtRows=1, int ifNotRect_NonRect0_MakeRectBy_Min1Max2=0);

       // };

        //class Array2DSize_V1D_VariaLength: public Array2DSize_Prototype{
        //    int QExtRows;
        //    int ExtRowsLength;
        //    //
        //  public:
            Array2DSize_V1D_VariaLength::Array2DSize_V1D_VariaLength(){
                this->construct();
            }
            Array2DSize_V1D_VariaLength::Array2DSize_V1D_VariaLength(int QExtRows, int*RowsLs, int ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2){
                this->construct();
                this->Set(RowsLs, QExtRows, ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2);
            }

             Array2DSize_V1D_VariaLength::Array2DSize_V1D_VariaLength(int QExtRows, int RowsLs){
                    this->construct();
                    this->Set(QExtRows, RowsLs);
                }
                Array2DSize_V1D_VariaLength::Array2DSize_V1D_VariaLength(std::vector<int>Ls, int ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2){
                    this->construct();
                    this-> Array2DSize_Prototype::Set(Ls, ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2);
                }
                //virtual ~Array2DSize_Prototype();
                Array2DSize_V1D_VariaLength::~Array2DSize_V1D_VariaLength(){}
                //
                //std::vector<int> GetAsArrayOfExtRowsLengthes()const;  //new
                //
                //void construct();//SeNullIni is called
                void Array2DSize_V1D_VariaLength::SetNull(){
                    this->rowsLs.clear();
                }

                void Array2DSize_V1D_VariaLength::SetNullIni(){
                    this->rowsLs.clear();
                    //delete[] this->rowsLs;
                }
                void Array2DSize_V1D_VariaLength::SetOne(){
                    this->rowsLs.clear();
                    this->rowsLs.push_back(1);
                    //this->SetNull();
                    //this->rowsLs=new int[1];
                    //this->rowsLs[1-1]=1;
                    //this->QExtRows=1;
                }
                //
                int Array2DSize_V1D_VariaLength::GetTypeN()const{
                    return Arr2DSize_VarLens_V_TypeN;
                }
                //
                void Array2DSize_V1D_VariaLength::Assign(Array2DSize_Prototype*obj){
                    std::vector<int>Ls=obj->GetLengthes();
                    this-> Array2DSize_Prototype::Set(Ls, 0);
                }
                //
                void Array2DSize_V1D_VariaLength::Set(int* extRowsLengthes, int QExtRows, int ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2){
                    int curL, Lmin, Lmax, minSizeAllowed=DEFAULT_SIZE;
                    if(QExtRows==0 && minSizeAllowed==0){
                            this->SetNull();
                    }else{
                        if(QExtRows==0){
                            QExtRows=this->GetQExtRows();
                        }

                        if(extRowsLengthes!=NULL && QExtRows!=0){
                            for(int i=0; i<QExtRows; i++){
                                curL=extRowsLengthes[i];
                                if(i==0 || (i>0 && curL<Lmin)){
                                    Lmin=curL;
                                }
                                if(i==0 || (i>0 && curL>Lmax)){
                                    Lmax=curL;
                                }
                            }
                            if(Lmin==Lmax){
                                this->rowsLs.clear();
                                for(int i=0; i<QExtRows; i++){
                                    this->rowsLs.push_back(extRowsLengthes[i]);
                                }
                            }else{
                                switch(ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2){
                                    case 1:
                                        this->Set(Lmax, QExtRows);
                                    break;
                                    case 2:
                                        this->Set(Lmin, QExtRows);
                                    break;
                                    //case 3:
                                    //
                                    //break;
                                    //case 4:
                                    //
                                    //break;
                                }
                            }
                        }
                    }
                }

                void Array2DSize_V1D_VariaLength::Set(int QExtRows, int extRowsLength){
                    int minSizeAllowed=DEFAULT_SIZE;
                    if(QExtRows==0 && minSizeAllowed==0){
                        this->SetNull();
                    }else{
                        if(QExtRows==0){
                            QExtRows=this->GetQExtRows();
                        }
                        this->rowsLs.clear();
                        for(int i=0; i<QExtRows; i++){
                            this->rowsLs.push_back(extRowsLength);
                        }
                    }
                }

                //
                int Array2DSize_V1D_VariaLength::GetQExtRows() const{
                    return this->rowsLs.size();
                }
                int Array2DSize_V1D_VariaLength::GetRowLength(int N) const{
                    int Lr=0;
                    int QExtRows=this->GetQExtRows();
                    if(N<0){
                        N+=(QExtRows+1);
                    }
                    if(N>=1 && N<=QExtRows){
                        Lr=this->rowsLs[N-1];
                    }
                    return Lr;
                }
                int Array2DSize_V1D_VariaLength::GetRowLengthMin() const{
                    return Array2DSize_Prototype::GetRowLengthMin();
                }
                int Array2DSize_V1D_VariaLength::GetRowLengthMax() const{
                    return Array2DSize_Prototype::GetRowLengthMax();
                }
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
                //bool Array2DSize_V1D_VariaLength::IsEmpty() const{
                //    return (this->rowsLs.empty());
                //}
                //bool IsEmpty() const;
                //
                //

                void Array2DSize_V1D_VariaLength::setExtRow_simplyAsDataGiven(int ExtRowNN_0IfAll, int L, int ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4){
                    int QExtRows=this->GetQExtRows();
                    if(ExtRowNN_0IfAll<0){
                        ExtRowNN_0IfAll+=(QExtRows+1);
                    }
                    if(L==0){
                        L=rowsLs[ExtRowNN_0IfAll-1];
                    }
                    if(L>0 && ExtRowNN_0IfAll>=0 && ExtRowNN_0IfAll<=QExtRows){
                        if(ExtRowNN_0IfAll>=1){
                            if(L==this->rowsLs[ExtRowNN_0IfAll-1]){
                                //NOp: for size nil changes
                            }else{
                                switch(ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4){
                                    case 2:
                                        //NOp: ignored
                                    break;
                                    case 0:
                                    case 1:
                                         this->rowsLs[ExtRowNN_0IfAll-1]=L;
                                    break;
                                    case 3:
                                        if(L>this->rowsLs[ExtRowNN_0IfAll-1]){
                                            this->rowsLs[ExtRowNN_0IfAll-1]=L;
                                        }
                                    break;
                                    case 4:
                                        if(L<this->rowsLs[ExtRowNN_0IfAll-1]){
                                            this->rowsLs[ExtRowNN_0IfAll-1]=L;
                                        }
                                    break;
                                }
                            }
                        }else if(ExtRowNN_0IfAll==0){
                            for(int i=0; i<QExtRows; i++){
                                this->rowsLs[i]=L;
                            }
                        }
                    }
                }

                void Array2DSize_V1D_VariaLength::addExtRow_simplyAsDataGiven(int L,        int ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4){
                    int QExtRows=this->GetQExtRows(), Lmin=this->GetRowLengthMin(), Lmax=this->GetRowLengthMax();
                    //if(this->IsRectangularInFact()==false || ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4==0){
                    if(ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4==0){
                        this->rowsLs.push_back(L);
                    }else{
                        switch(ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4){
                            case 1:
                                this->Set(QExtRows+1, L);
                            break;
                            case 2:
                                this->Set(QExtRows+1, Lmin);
                            break;
                            case 3:
                                if(L>Lmax){
                                    this->Set(QExtRows+1, L);
                                }else{
                                    this->Set(QExtRows+1, Lmax);
                                }
                            break;
                            case 4:
                                if(L<Lmin){
                                    this->Set(QExtRows+1, L);
                                }else{
                                    this->Set(QExtRows+1, Lmin);
                                }
                            break;
                        }
                    }
                }

                void Array2DSize_V1D_VariaLength::insExtRow_simplyAsDataGiven(int N, int L, int ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4){
                    int QExtRows=this->GetQExtRows(), Lmin=this->GetRowLengthMin(), Lmax=this->GetRowLengthMax();
                    if(N<0){
                        N+=(QExtRows+1);
                    }
                    if(N>=1 && N<=QExtRows){
                        if(ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4==0){
                            this->rowsLs.insert(this->rowsLs.begin()+N-1, L);
                        }else{
                            switch(ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4){
                                case 1:
                                    this->Set(QExtRows+1, L);
                                break;
                                case 2:
                                    this->Set(QExtRows+1, Lmin);
                                break;
                                case 3:
                                    if(L>Lmax){
                                        this->Set(QExtRows+1, L);
                                    }else{
                                        this->Set(QExtRows+1, Lmax);
                                    }
                                break;
                                case 4:
                                    if(L<Lmin){
                                        this->Set(QExtRows+1, L);
                                    }else{
                                        this->Set(QExtRows+1, Lmin);
                                    }
                                break;
                            }
                        }
                    }
                }

                void Array2DSize_V1D_VariaLength::delExtRow_simplyAsDataGiven(       int N){
                    int allowedMinSize=Arr2DSize_Rect_TypeN, QExtRows=this->GetQExtRows();
                    if(QExtRows>allowedMinSize){
                        this->rowsLs.erase(this->rowsLs.begin()+N-1);
                    }
                }

                void Array2DSize_V1D_VariaLength::set_or_ins_IneRow_simplyAsDataGiven(int Action_Set1_Ins2, int N, int L, int ifL_NE_QER_Ignore0_MakeRactChangingBy_New1Old2Max3Min4, int ifLminLTN_ifAdd_N1_Lmax2_LmaxRest3_MakeRectAnyway_Lmax4_LmaxRest5){
                    int QExtRowsOld=this->GetQExtRows(), QExtRows, Lmax=this->GetRowLengthMax(), LmaxRest, LastL, curL, L2;//, Lmin=this->GetRowLengthMin();
                    int p1=ifL_NE_QER_Ignore0_MakeRactChangingBy_New1Old2Max3Min4;
                    if(N<0){
                        N+=(QExtRowsOld+1);
                    }
                    if(L==0){
                        L=QExtRowsOld;
                    }
                    if(L>0 && N>=1 && N<=Lmax){
                        if(L<=QExtRowsOld && (p1==1 || p1==4)){
                            for(int _N=1; _N<=L; _N++){
                                curL=this->GetRowLength(_N);
                                if(_N==1 || (_N>1 && LmaxRest<curL)){
                                    LmaxRest=curL;
                                }
                            }
                            switch(ifLminLTN_ifAdd_N1_Lmax2_LmaxRest3_MakeRectAnyway_Lmax4_LmaxRest5){
                                case 1:
                                    for(int _N=1; _N<=L; _N++){
                                        curL=this->GetRowLength(_N);
                                        if(curL>=N){
                                            switch(Action_Set1_Ins2){
                                                case 1:
                                                    this->rowsLs[_N-1]=this->rowsLs[_N-1];
                                                break;
                                                case 2:
                                                    this->rowsLs[_N-1]=this->rowsLs[_N-1]+1;
                                                break;
                                            }
                                        }else{
                                            switch(Action_Set1_Ins2){
                                                case 1:
                                                    this->rowsLs[_N-1]=N;
                                                break;
                                                case 2:
                                                    this->rowsLs[_N-1]=N+1;
                                                break;
                                            }
                                        }
                                    }
                                break;
                                case 2:
                                    for(int _N=1; _N<=L; _N++){
                                        curL=this->GetRowLength(_N);
                                        if(curL>=N){
                                            switch(Action_Set1_Ins2){
                                                case 1:
                                                    this->rowsLs[_N-1]=this->rowsLs[_N-1];
                                                break;
                                                case 2:
                                                    this->rowsLs[_N-1]=this->rowsLs[_N-1]+1;
                                                break;
                                            }

                                        }else{
                                            switch(Action_Set1_Ins2){
                                                case 1:
                                                    this->rowsLs[_N-1]=Lmax;
                                                break;
                                                case 2:
                                                    this->rowsLs[_N-1]=Lmax+1;
                                                break;
                                            }
                                        }
                                    }
                                break;
                                case 3:
                                    for(int _N=1; _N<=L; _N++){
                                        curL=this->GetRowLength(_N);
                                        if(curL>=N){
                                            switch(Action_Set1_Ins2){
                                                case 1:
                                                    this->rowsLs[_N-1]=this->rowsLs[_N-1];
                                                break;
                                                case 2:
                                                    this->rowsLs[_N-1]=this->rowsLs[_N-1]+1;
                                                break;
                                            }

                                        }else{
                                            switch(Action_Set1_Ins2){
                                                case 1:
                                                    this->rowsLs[_N-1]=LmaxRest;
                                                break;
                                                case 2:
                                                    this->rowsLs[_N-1]=LmaxRest+1;
                                                break;
                                            }
                                        }
                                    }
                                break;
                                case 4:
                                    for(int _N=1; _N<=L; _N++){
                                        this->rowsLs[_N-1]=Lmax+1;
                                    }
                                break;
                                case 5:
                                    for(int _N=1; _N<=L; _N++){
                                        this->rowsLs[_N-1]=LmaxRest+1;
                                    }
                                break;
                            }
                            if(L<QExtRowsOld){
                                for(int i=0; i<QExtRowsOld-L; i++){
                                    this->rowsLs.pop_back();
                                }
                            }
                        }else if(L>QExtRowsOld && (p1==1 || p1==3)){
                            switch(ifLminLTN_ifAdd_N1_Lmax2_LmaxRest3_MakeRectAnyway_Lmax4_LmaxRest5){
                                case 1:
                                    for(int _N=1; _N<=QExtRowsOld; _N++){
                                        if(curL>=N){
                                            switch(Action_Set1_Ins2){
                                                case 1:
                                                    this->rowsLs[_N-1]=this->rowsLs[_N-1];
                                                break;
                                                case 2:
                                                    this->rowsLs[_N-1]=this->rowsLs[_N-1]+1;
                                                break;
                                            }
                                        }else{
                                            switch(Action_Set1_Ins2){
                                                case 1:
                                                    this->rowsLs[_N-1]=N;
                                                break;
                                                case 2:
                                                    this->rowsLs[_N-1]=N+1;
                                                break;
                                            }
                                        }
                                    }
                                    for(int _N=QExtRowsOld+1; _N<=L; _N++){
                                        switch(Action_Set1_Ins2){
                                            case 1:
                                                this->rowsLs[_N-1]=N;
                                            break;
                                            case 2:
                                                this->rowsLs[_N-1]=N+1;
                                            break;
                                        }
                                    }
                                break;
                                case 2:
                                case 3:
                                    for(int _N=1; _N<=QExtRowsOld; _N++){
                                        if(curL>=N){
                                            switch(Action_Set1_Ins2){
                                                case 1:
                                                    this->rowsLs[_N-1]=this->rowsLs[_N-1];
                                                break;
                                                case 2:
                                                    this->rowsLs[_N-1]=this->rowsLs[_N-1]+1;
                                                break;
                                            }
                                        }else{
                                            switch(Action_Set1_Ins2){
                                                case 1:
                                                    this->rowsLs[_N-1]=Lmax;
                                                break;
                                                case 2:
                                                    this->rowsLs[_N-1]=Lmax+1;
                                                break;
                                            }
                                        }
                                    }
                                    for(int _N=QExtRowsOld+1; _N<=L; _N++){
                                        switch(Action_Set1_Ins2){
                                            case 1:
                                                this->rowsLs[_N-1]=Lmax;
                                            break;
                                            case 2:
                                                this->rowsLs[_N-1]=Lmax+1;
                                            break;
                                        }
                                    }
                                break;
                                case 4:
                                case 5:
                                    for(int _N=QExtRowsOld+1; _N<=L; _N++){
                                        switch(Action_Set1_Ins2){
                                            case 1:
                                                this->rowsLs[_N-1]=Lmax;
                                            break;
                                            case 2:
                                                this->rowsLs[_N-1]=Lmax+1;
                                            break;
                                        }
                                    break;
                                }
                            }//switch
                        }//if L<QExtRowsOld
                    }//if L>0 or ==0
                }//fn

                //
                void Array2DSize_V1D_VariaLength::addIneRow_simplyAsDataGiven(int L,        int ifL_NE_QER_Ignore0_MakeRactChangingBy_New1Old2Max3Min4, int ifNonRect_Ignore0AddToLast1StretchToMax2 ){
                    int QExtRowsOld=this->GetQExtRows(), QExtRows, Lmax=this->GetRowLengthMax(), minL, Lmin=this->GetRowLengthMin(), LmaxRest, LastL, curL, L2;//, Lmin=this->GetRowLengthMin();
                    int p1=ifL_NE_QER_Ignore0_MakeRactChangingBy_New1Old2Max3Min4;
                    //if(N<0){ //no N in add fun!
                     //   N+=(QExtRowsOld+1);
                    //}
                    if(L==0){
                        L=QExtRowsOld;
                    }
                    minL = QExtRowsOld<=L ? QExtRowsOld : L;
                    if(L>0  && ! (Lmin!=Lmax && ifNonRect_Ignore0AddToLast1StretchToMax2==0)){
                        if ( (L<=QExtRowsOld && (p1==1 || p1==4)) || (L>QExtRowsOld && (p1==1 || p1==3)) ) {
                            if(Lmin==Lmax || ifNonRect_Ignore0AddToLast1StretchToMax2==1){
                                for(int i=0; i<minL; i++){
                                    this->rowsLs[i]+=1;
                                }
                            }else if(ifNonRect_Ignore0AddToLast1StretchToMax2==2){
                                for(int _N=1;_N<minL;_N++){
                                    this->rowsLs[_N-1]=Lmax+1;
                                }
                            }
                        }
                        if( L<QExtRowsOld && (p1==1 || p1==4) ){
                            for(int i=0; i<QExtRowsOld-L; i++){
                                this->rowsLs.pop_back();
                            }
                        }else if(L>QExtRowsOld && (p1==1 || p1==3)){
                            switch(ifNonRect_Ignore0AddToLast1StretchToMax2){
                                case 1:
                                    for(int i=0; i<=L-QExtRowsOld; i++){
                                        this->rowsLs.push_back(1);
                                    }
                                break;
                                case 2:
                                    for(int i=0; i<=L-QExtRowsOld; i++){
                                        this->rowsLs.push_back(Lmax+1);
                                    }
                                break;
                            }
                        }
                    }//if L>0 or ==0
                }//fn



                void Array2DSize_V1D_VariaLength::delIneRow_simplyAsDataGiven(       int N, int ifNGTLminIgnore0ShortenNurLongRows1){
                    int allowedMinSize=Arr2DSize_Rect_TypeN;
                    int QExtRows=this->GetQExtRows(), Lmax=this->GetRowLengthMax(), Lmin=this->GetRowLengthMin(),curL;
                    if(N<0){
                        N+=(QExtRows+1);
                    }
                    if(N>Lmin || ifNGTLminIgnore0ShortenNurLongRows1==1){
                        for(int _N=1; _N<=QExtRows; _N++){
                            curL=this->GetRowLength(_N);
                            if(curL>=N){
                                this->rowsLs[_N-1]-=1;
                            }
                        }
                    }

                }//fn

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


                //
                //
                //void Array2DSize_V1D_VariaLength::Set(int* extRowsLengthes, int QExtRowsGiven, int ifNotRect_NonRect0_MakeRectBy_Min1Max2MinOfMax3MaxOfMax4, bool IfNotValsOfGivenRow_DefaultNotOwn){
                //    int LminGiven, LmaxGiven, QExtRowsOld=this->GetQExtRows(), Lmin=this->GetRowLengthMin(), Lmax=this->GetRowLengthMax(), curLgiven, curLexisting;
                //    for(int ERNN=1; ERNN<=QExtRowsGiven; ERNN++){
                //        curLgiven=extRowsLengthes[ERNN-1];
                //        if(ERNN==1 || (ERNN>=1 && curLgiven<LminGiven)){
                //            LminGiven=curLgiven;
                //        }
                //        if(ERNN==1 || (ERNN>=1 && curLgiven>LmaxGiven)){
                //            LmaxGiven=curLgiven;
                //        }
                //    }
                //    //if(LmaxGiven==LminGiven){
                //    //    this->QExtRows=QExtRowsGiven;
                //    //    this->ExtRowsLength=LmaxGiven;
                //    //}else{
                //        switch(ifNotRect_NonRect0_MakeRectBy_Min1Max2MinOfMax3MaxOfMax4){
                //            case 0:
                //                this->rowsLs.clear();
                //                for(int ERNN=1; ERNN<=QExtRowsGiven; ERNN++){
                //                    curLgiven=extRowsLengthes[ERNN-1];
                //                    this->rowsLs.push_back(curLgiven);
                //                }
                //            break;
                //            case 1:
                //                this->rowsLs.clear();
                //                for(int ERNN=1; ERNN<=QExtRowsGiven; ERNN++){
                //                    //curLgiven=extRowsLengthes[ERNN-1];
                //                    this->rowsLs.push_back(LmaxGiven);
                //                }
                //            break;
                //            case 2:
                //                this->rowsLs.clear();
                //                for(int ERNN=1; ERNN<=QExtRowsGiven; ERNN++){
                //                    //curLgiven=extRowsLengthes[ERNN-1];
                //                    this->rowsLs.push_back(LminGiven);
                //                }
                //            break;
                //            case 3:
                //                this->rowsLs.clear();
                //                if(LmaxGiven>=Lmax){
                //                    for(int ERNN=1; ERNN<=QExtRowsGiven; ERNN++){
                //                        //curLgiven=extRowsLengthes[ERNN-1];
                //                        this->rowsLs.push_back(LmaxGiven);
                //                    }
                //                }else{
                //                    for(int ERNN=1; ERNN<=QExtRowsGiven; ERNN++){
                //                        //curLgiven=extRowsLengthes[ERNN-1];
                //                        this->rowsLs.push_back(Lmax);
                //                    }
                //                }
                //            break;
                //            case 4:
                //                this->rowsLs.clear();
                //                if(LminGiven<=Lmin){
                //                    for(int ERNN=1; ERNN<=QExtRowsGiven; ERNN++){
                //                        //curLgiven=extRowsLengthes[ERNN-1];
                //                        this->rowsLs.push_back(LminGiven);
                //                    }
                //                }else{
                //                    for(int ERNN=1; ERNN<=QExtRowsGiven; ERNN++){
                //                        //curLgiven=extRowsLengthes[ERNN-1];
                //                        this->rowsLs.push_back(Lmin);
                //                    }
                //                }
                //            break;
                //        }
                //    //}
                //}//fn
                //
                //

                //void Set(std::vector<int>Ls, int ifNotRect_NonRect0_MakeRectBy_Min1Max2=0);
                ////int Set_GetExtNewRowLength(int* extRowsLengthes, int QExtRows, int ifNotRect_NonRect0_MakeRectBy_Min1Max2=0);//no need - 4 tgos: Lcur, Lold, Lmin, Lmax
                //int Set_Arr2DNewCoordsToDataTypeN(const Coords2DInt&coords, int* extRowsLengthes, int QExtRows=1, int ifNotRect_NonRect0_MakeRectBy_Min1Max2=0);
                //Coords2DInt Set_Arr2DNewToOldCoords(const Coords2DInt&coords, int* extRowsLengthes, int QExtRows=1, int ifNotRect_NonRect0_MakeRectBy_Min1Max2=0);
                //std::string Array2DSize_V1D_VariaLength::GetAsString(){
                //    return Array2DSize_Prototype::GetAsStdString();
                //}
           // };



                Array2DSize_P_QERInner_VariaLength::Array2DSize_P_QERInner_VariaLength(){
                    int QMiAllowed=DEFAULT_SIZE, rowL;
                    if(QMiAllowed==1){
                        this->QExtRows=1;
                        rowL=1;
                        this->rowsLs=new int[QExtRows];
                        for(int i=0; i<QExtRows; i++){
                            this->rowsLs[i]=rowL;
                        }
                    }

                }
                Array2DSize_P_QERInner_VariaLength::Array2DSize_P_QERInner_VariaLength(int QExtRows, int rowL){
                    this->rowsLs=new int[QExtRows];
                    for(int i=0; i<QExtRows; i++){
                        this->rowsLs[i]=rowL;
                    }
                    this->QExtRows=QExtRows;
                }
                Array2DSize_P_QERInner_VariaLength::Array2DSize_P_QERInner_VariaLength(int QExtRows, int*RowsLs , int ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2){
                    this->QExtRows=QExtRows;
                    int Lmin, Lmax, curL;
                    this->rowsLs=new int[this->QExtRows];
                    for(int i=0; i<this->QExtRows; i++){
                        curL=rowsLs[i];
                        if(i==0 || (i>0 && curL<Lmin)){
                            Lmin=curL;
                        }
                        if(i==0 || (i>0 && curL>Lmax)){
                            Lmax=curL;
                        }
                    }
                    if(Lmin==Lmax || ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2==0){
                        for(int i=0; i<this->QExtRows; i++){
                            this->rowsLs[i]=rowsLs[i];
                        }
                    }else{
                        switch(ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2){
                            case 1:
                                for(int i=0; i<this->QExtRows; i++){
                                    this->rowsLs[i]=Lmax;
                                }
                            break;
                            case 2:
                                for(int i=0; i<this->QExtRows; i++){
                                    this->rowsLs[i]=Lmin;
                                }
                            break;
                        }
                    }
                }
                Array2DSize_P_QERInner_VariaLength::Array2DSize_P_QERInner_VariaLength(std::vector<int>Ls, int ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2){
                    this->QExtRows=Ls.size();
                    int Lmin, Lmax, curL;
                    this->rowsLs=new int[this->QExtRows];
                    for(int i=0; i<QExtRows; i++){
                        curL=Ls[i];
                        if(i==0 || (i>0 && curL<Lmin)){
                            Lmin=curL;
                        }
                        if(i==0 || (i>0 && curL>Lmax)){
                            Lmax=curL;
                        }
                    }
                    if(Lmin==Lmax || ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2==0){
                        for(int i=0; i<this->QExtRows; i++){
                            this->rowsLs[i]=Ls[i];
                        }
                    }else{
                        switch(ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2){
                            case 1:
                                for(int i=0; i<this->QExtRows; i++){
                                    this->rowsLs[i]=Lmax;
                                }
                            break;
                            case 2:
                                for(int i=0; i<this->QExtRows; i++){
                                    this->rowsLs[i]=Lmin;
                                }
                            break;
                        }
                    }
                }
                Array2DSize_P_QERInner_VariaLength::~Array2DSize_P_QERInner_VariaLength(){
                    delete [] this->rowsLs;
                    //this->QExtRows=0;
                }


                        void Array2DSize_P_QERInner_VariaLength::SetNullIni(){
                            this->rowsLs=NULL;
                        }

                        //
                        //void construct();//SeNullIni is called
                        void Array2DSize_P_QERInner_VariaLength::SetNull(){
                            delete[] this->rowsLs;
                            this->rowsLs=NULL;
                        }


                        void Array2DSize_P_QERInner_VariaLength::SetOne(){
                            this->SetNull();
                            this->rowsLs=new int[1];
                            this->rowsLs[1-1]=1;
                            this->QExtRows=1;
                        }
                        //
                        int Array2DSize_P_QERInner_VariaLength::GetTypeN()const{
                            return Arr2DSize_VarLens_P_TypeN;
                        }
                        //
                        void Array2DSize_P_QERInner_VariaLength::Assign(Array2DSize_Prototype*obj){
                            std::vector<int>Ls=obj->GetLengthes();
                            this-> Array2DSize_Prototype::Set(Ls, 0);
                        }
                        //
                        void Array2DSize_P_QERInner_VariaLength::Set(int* extRowsLengthes, int QExtRows, int ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2){
                            int curL, Lmin, Lmax, minSizeAllowed=DEFAULT_SIZE, n;
                            if(QExtRows==0 && minSizeAllowed==0){
                                    this->SetNull();
                            }else{
                                if(QExtRows==0){
                                    QExtRows=this->GetQExtRows();
                                }

                                if(extRowsLengthes!=NULL && QExtRows!=0){
                                    for(int i=0; i<QExtRows; i++){
                                        curL=extRowsLengthes[i];
                                        if(i==0 || (i>0 && curL<Lmin)){
                                            Lmin=curL;
                                        }
                                        if(i==0 || (i>0 && curL>Lmax)){
                                            Lmax=curL;
                                        }
                                    }
                                    if(Lmin==Lmax){
                                        n=this->QExtRows;
                                        //this->rowsLs.clear();
                                        this->SetNull();
                                        for(int i=0; i<QExtRows; i++){
                                            //this->rowsLs.push_back(extRowsLengthes[i]);
                                            Arr1D_Add(this->rowsLs, n, extRowsLengthes[i]);
                                        }
                                    }else{
                                        switch(ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2){
                                            case 1:
                                                this->Set(Lmax, QExtRows);
                                            break;
                                            case 2:
                                                this->Set(Lmin, QExtRows);
                                            break;
                                            //case 3:
                                            //
                                            //break;
                                            //case 4:
                                            //
                                            //break;
                                        }
                                    }
                                }
                            }
                        }

                        void Array2DSize_P_QERInner_VariaLength::Set(int QExtRows, int extRowsLength){
                            int minSizeAllowed=DEFAULT_SIZE, n=0;
                            if(QExtRows==0 && minSizeAllowed==0){
                                this->SetNull();
                            }else{
                                if(QExtRows==0){
                                    QExtRows=this->GetQExtRows();
                                }
                                //this->rowsLs.clear();
                                this->SetNull();
                                for(int i=0; i<QExtRows; i++){
                                    //this->rowsLs.push_back(extRowsLength);
                                    Arr1D_Add(this->rowsLs, n, extRowsLength);
                                }
                            }
                        }

                        //
                        int Array2DSize_P_QERInner_VariaLength::GetQExtRows() const{
                            return this->QExtRows;
                        }
                        int Array2DSize_P_QERInner_VariaLength::GetRowLength(int N) const{
                            int Lr=0;
                            int QExtRows=this->GetQExtRows();
                            if(N<0){
                                N+=(QExtRows+1);
                            }
                            if(N>=1 && N<=QExtRows){
                                Lr=this->rowsLs[N-1];
                            }
                            return Lr;
                        }
//                        int Array2DSize_P_QERInner_VariaLength::GetRowLengthMin() const{
//
                   int Array2DSize_P_QERInner_VariaLength::GetRowLengthMin() const{
                        return Array2DSize_Prototype::GetRowLengthMin();
                    }
                    int Array2DSize_P_QERInner_VariaLength::GetRowLengthMax() const{
                        return Array2DSize_Prototype::GetRowLengthMax();
                    }
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
                        //bool Array2DSize_V1D_VariaLength::IsEmpty() const{
                        //    return (this->rowsLs.empty());
                        //}
                        //bool IsEmpty() const;
                        //
                        //
                    void Array2DSize_P_QERInner_VariaLength::setExtRow_simplyAsDataGiven(int ExtRowNN_0IfAll, int L, int ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4){
                        int QExtRows=this->GetQExtRows();
                        if(ExtRowNN_0IfAll<0){
                            ExtRowNN_0IfAll+=(QExtRows+1);
                        }
                        if(L==0){
                            L=this->rowsLs[ExtRowNN_0IfAll-1];
                        }
                        if(L>0 && ExtRowNN_0IfAll>=0 && ExtRowNN_0IfAll<=QExtRows){
                            if(ExtRowNN_0IfAll>=1){
                                if(L==this->rowsLs[ExtRowNN_0IfAll-1]){
                                    //NOp: for size nil changes
                                }else{
                                    switch(ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4){
                                        case 2:
                                            //NOp: ignored
                                        break;
                                        case 0:
                                        case 1:
                                             this->rowsLs[ExtRowNN_0IfAll-1]=L;
                                        break;
                                        case 3:
                                            if(L>this->rowsLs[ExtRowNN_0IfAll-1]){
                                                this->rowsLs[ExtRowNN_0IfAll-1]=L;
                                            }
                                        break;
                                        case 4:
                                            if(L<rowsLs[ExtRowNN_0IfAll-1]){
                                                this->rowsLs[ExtRowNN_0IfAll-1]=L;
                                            }
                                        break;
                                    }
                                }
                            }else if(ExtRowNN_0IfAll==0){
                                for(int i=0; i<QExtRows; i++){
                                    this->rowsLs[i]=L;
                                }
                            }
                        }
                    }

                        void Array2DSize_P_QERInner_VariaLength::addExtRow_simplyAsDataGiven(int L,        int ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4){
                            int n=this->QExtRows, Lmin=this->GetRowLengthMin(), Lmax=this->GetRowLengthMax();
                            //if(this->IsRectangularInFact()==false || ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4==0){
                            if(ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4==0){
                                //this->rowsLs.push_back(L);
                                Arr1D_Add(this->rowsLs, n, L);
                            }else{
                                switch(ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4){
                                    case 1:
                                        this->Set(QExtRows+1, L);
                                    break;
                                    case 2:
                                        this->Set(QExtRows+1, Lmin);
                                    break;
                                    case 3:
                                        if(L>Lmax){
                                            this->Set(QExtRows+1, L);
                                        }else{
                                            this->Set(QExtRows+1, Lmax);
                                        }
                                    break;
                                    case 4:
                                        if(L<Lmin){
                                            this->Set(QExtRows+1, L);
                                        }else{
                                            this->Set(QExtRows+1, Lmin);
                                        }
                                    break;
                                }
                            }
                        }

                        void Array2DSize_P_QERInner_VariaLength::insExtRow_simplyAsDataGiven(int N, int L, int ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4){
                            int n=this->QExtRows, Lmin=this->GetRowLengthMin(), Lmax=this->GetRowLengthMax();
                            if(N<0){
                                N+=(QExtRows+1);
                            }
                            if(N>=1 && N<=QExtRows){
                                if(ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4==0){
                                    //this->rowsLs.insert(this->rowsLs.begin()+N-1, L);
                                    Arr1D_InsToN_v2(this->rowsLs, n, N, L);
                                }else{
                                    switch(ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4){
                                        case 1:
                                            this->Set(QExtRows+1, L);
                                        break;
                                        case 2:
                                            this->Set(QExtRows+1, Lmin);
                                        break;
                                        case 3:
                                            if(L>Lmax){
                                                this->Set(QExtRows+1, L);
                                            }else{
                                                this->Set(QExtRows+1, Lmax);
                                            }
                                        break;
                                        case 4:
                                            if(L<Lmin){
                                                this->Set(QExtRows+1, L);
                                            }else{
                                                this->Set(QExtRows+1, Lmin);
                                            }
                                        break;
                                    }
                                }
                            }
                        }

                        void Array2DSize_P_QERInner_VariaLength::delExtRow_simplyAsDataGiven(       int N){
                            int allowedMinSize=Arr2DSize_Rect_TypeN, n=this->QExtRows;
                            if(N<0){
                                N+=(this->QExtRows+1);
                            }
                            if(QExtRows>allowedMinSize){
                                //this->rowsLs.erase(this->rowsLs.begin()+N-1);
                                Arr1D_DelN(this->rowsLs, n, N);
                            }
                        }

                        void Array2DSize_P_QERInner_VariaLength::set_or_ins_IneRow_simplyAsDataGiven(int Action_Set1_Ins2, int N, int L, int ifL_NE_QER_Ignore0_MakeRactChangingBy_New1Old2Max3Min4, int ifLminLTN_ifAdd_N1_Lmax2_LmaxRest3_MakeRectAnyway_Lmax4_LmaxRest5){
                            int QExtRowsOld=this->GetQExtRows(), QExtRows, Lmax=this->GetRowLengthMax(), LmaxRest, LastL, curL, L2;//, Lmin=this->GetRowLengthMin();
                            int p1=ifL_NE_QER_Ignore0_MakeRactChangingBy_New1Old2Max3Min4;
                            int n;
                            if(N<0){
                                N+=(QExtRowsOld+1);
                            }
                            if(L==0){
                                L=QExtRowsOld;
                            }
                            if(L>0 && N>=1 && N<=Lmax){
                                if(L<=QExtRowsOld && (p1==1 || p1==4)){
                                    for(int _N=1; _N<=L; _N++){
                                        curL=this->GetRowLength(_N);
                                        if(_N==1 || (_N>1 && LmaxRest<curL)){
                                            LmaxRest=curL;
                                        }
                                    }
                                    switch(ifLminLTN_ifAdd_N1_Lmax2_LmaxRest3_MakeRectAnyway_Lmax4_LmaxRest5){
                                        case 1:
                                            for(int _N=1; _N<=L; _N++){
                                                curL=this->GetRowLength(_N);
                                                if(curL>=N){
                                                    switch(Action_Set1_Ins2){
                                                        case 1:
                                                            this->rowsLs[_N-1]=this->rowsLs[_N-1];
                                                        break;
                                                        case 2:
                                                            this->rowsLs[_N-1]=this->rowsLs[_N-1]+1;
                                                        break;
                                                    }
                                                }else{
                                                    switch(Action_Set1_Ins2){
                                                        case 1:
                                                            this->rowsLs[_N-1]=N;
                                                        break;
                                                        case 2:
                                                            this->rowsLs[_N-1]=N+1;
                                                        break;
                                                    }
                                                }
                                            }
                                        break;
                                        case 2:
                                            for(int _N=1; _N<=L; _N++){
                                                curL=this->GetRowLength(_N);
                                                if(curL>=N){
                                                    switch(Action_Set1_Ins2){
                                                        case 1:
                                                            this->rowsLs[_N-1]=this->rowsLs[_N-1];
                                                        break;
                                                        case 2:
                                                            this->rowsLs[_N-1]=this->rowsLs[_N-1]+1;
                                                        break;
                                                    }

                                                }else{
                                                    switch(Action_Set1_Ins2){
                                                        case 1:
                                                            this->rowsLs[_N-1]=Lmax;
                                                        break;
                                                        case 2:
                                                            this->rowsLs[_N-1]=Lmax+1;
                                                        break;
                                                    }
                                                }
                                            }
                                        break;
                                        case 3:
                                            for(int _N=1; _N<=L; _N++){
                                                curL=this->GetRowLength(_N);
                                                if(curL>=N){
                                                    switch(Action_Set1_Ins2){
                                                        case 1:
                                                            this->rowsLs[_N-1]=this->rowsLs[_N-1];
                                                        break;
                                                        case 2:
                                                            this->rowsLs[_N-1]=this->rowsLs[_N-1]+1;
                                                        break;
                                                    }

                                                }else{
                                                    switch(Action_Set1_Ins2){
                                                        case 1:
                                                            this->rowsLs[_N-1]=LmaxRest;
                                                        break;
                                                        case 2:
                                                            this->rowsLs[_N-1]=LmaxRest+1;
                                                        break;
                                                    }
                                                }
                                            }
                                        break;
                                        case 4:
                                            for(int _N=1; _N<=L; _N++){
                                                this->rowsLs[_N-1]=Lmax+1;
                                            }
                                        break;
                                        case 5:
                                            for(int _N=1; _N<=L; _N++){
                                                this->rowsLs[_N-1]=LmaxRest+1;
                                            }
                                        break;
                                    }
                                    if(L<QExtRowsOld){
                                        n=QExtRowsOld;
                                        for(int i=0; i<QExtRowsOld-L; i++){
                                            //this->rowsLs.pop_back();
                                            //void Arr1D_DelN(T*&x, int&Q, int N);
                                            Arr1D_DelN(this->rowsLs, n, n);
                                        }
                                        this->QExtRows=n;
                                    }
                                }else if(L>QExtRowsOld && (p1==1 || p1==3)){
                                    switch(ifLminLTN_ifAdd_N1_Lmax2_LmaxRest3_MakeRectAnyway_Lmax4_LmaxRest5){
                                        case 1:
                                            for(int _N=1; _N<=QExtRowsOld; _N++){
                                                if(curL>=N){
                                                    switch(Action_Set1_Ins2){
                                                        case 1:
                                                            this->rowsLs[_N-1]=this->rowsLs[_N-1];
                                                        break;
                                                        case 2:
                                                            this->rowsLs[_N-1]=this->rowsLs[_N-1]+1;
                                                        break;
                                                    }
                                                }else{
                                                    switch(Action_Set1_Ins2){
                                                        case 1:
                                                            this->rowsLs[_N-1]=N;
                                                        break;
                                                        case 2:
                                                            this->rowsLs[_N-1]=N+1;
                                                        break;
                                                    }
                                                }
                                            }
                                            for(int _N=QExtRowsOld+1; _N<=L; _N++){
                                                switch(Action_Set1_Ins2){
                                                    case 1:
                                                        this->rowsLs[_N-1]=N;
                                                    break;
                                                    case 2:
                                                        this->rowsLs[_N-1]=N+1;
                                                    break;
                                                }
                                            }
                                        break;
                                        case 2:
                                        case 3:
                                            for(int _N=1; _N<=QExtRowsOld; _N++){
                                                if(curL>=N){
                                                    switch(Action_Set1_Ins2){
                                                        case 1:
                                                            this->rowsLs[_N-1]=this->rowsLs[_N-1];
                                                        break;
                                                        case 2:
                                                            this->rowsLs[_N-1]=this->rowsLs[_N-1]+1;
                                                        break;
                                                    }
                                                }else{
                                                    switch(Action_Set1_Ins2){
                                                        case 1:
                                                            this->rowsLs[_N-1]=Lmax;
                                                        break;
                                                        case 2:
                                                            this->rowsLs[_N-1]=Lmax+1;
                                                        break;
                                                    }
                                                }
                                            }
                                            for(int _N=QExtRowsOld+1; _N<=L; _N++){
                                                switch(Action_Set1_Ins2){
                                                    case 1:
                                                        this->rowsLs[_N-1]=Lmax;
                                                    break;
                                                    case 2:
                                                        this->rowsLs[_N-1]=Lmax+1;
                                                    break;
                                                }
                                            }
                                        break;
                                        case 4:
                                        case 5:
                                            for(int _N=QExtRowsOld+1; _N<=L; _N++){
                                                switch(Action_Set1_Ins2){
                                                    case 1:
                                                        this->rowsLs[_N-1]=Lmax;
                                                    break;
                                                    case 2:
                                                        this->rowsLs[_N-1]=Lmax+1;
                                                    break;
                                                }
                                            break;
                                        }
                                    }//switch
                                }//if L<QExtRowsOld
                            }//if L>0 or ==0
                        }//fn

                        //
                        void Array2DSize_P_QERInner_VariaLength::addIneRow_simplyAsDataGiven(int L,        int ifL_NE_QER_Ignore0_MakeRactChangingBy_New1Old2Max3Min4, int ifNonRect_Ignore0AddToLast1StretchToMax2 ){
                            int QExtRowsOld=this->GetQExtRows(), QExtRows, Lmax=this->GetRowLengthMax(), minL, Lmin=this->GetRowLengthMin(), LmaxRest, LastL, curL, L2;//, Lmin=this->GetRowLengthMin();
                            int p1=ifL_NE_QER_Ignore0_MakeRactChangingBy_New1Old2Max3Min4;
                            int n=QExtRowsOld;
                            //if(N<0){ //no N in add fun!
                             //   N+=(QExtRowsOld+1);
                            //}
                            if(L==0){
                                L=QExtRowsOld;
                            }
                            minL = QExtRowsOld<=L ? QExtRowsOld : L;
                            if(L>0  && ! (Lmin!=Lmax && ifNonRect_Ignore0AddToLast1StretchToMax2==0)){
                                if ( (L<=QExtRowsOld && (p1==1 || p1==4)) || (L>QExtRowsOld && (p1==1 || p1==3)) ) {
                                    if(Lmin==Lmax || ifNonRect_Ignore0AddToLast1StretchToMax2==1){
                                        for(int i=0; i<minL; i++){
                                            this->rowsLs[i]+=1;
                                        }
                                    }else if(ifNonRect_Ignore0AddToLast1StretchToMax2==2){
                                        for(int _N=1;_N<minL;_N++){
                                            this->rowsLs[_N-1]=Lmax+1;
                                        }
                                    }
                                }
                                if( L<QExtRowsOld && (p1==1 || p1==4) ){
                                    n=QExtRowsOld;
                                    for(int i=0; i<QExtRowsOld-L; i++){
                                        //this->rowsLs.pop_back();
                                        Arr1D_DelN(this->rowsLs, n, n);
                                    }
                                    this->QExtRows=n;
                                }else if(L>QExtRowsOld && (p1==1 || p1==3)){
                                    n=QExtRowsOld;
                                    switch(ifNonRect_Ignore0AddToLast1StretchToMax2){
                                        case 1:
                                            for(int i=0; i<=L-QExtRowsOld; i++){
                                                //this->rowsLs.push_back(1);
                                                Arr1D_Add(this->rowsLs, n, 1);
                                            }
                                            this->QExtRows=n;
                                        break;
                                        case 2:
                                            for(int i=0; i<=L-QExtRowsOld; i++){
                                                //this->rowsLs.push_back(Lmax+1);
                                                Arr1D_Add(this->rowsLs, n, (Lmax+1));
                                            }
                                        break;
                                    }
                                }
                            }//if L>0 or ==0
                        }//fn



                        void Array2DSize_P_QERInner_VariaLength::delIneRow_simplyAsDataGiven(       int N, int ifNGTLminIgnore0ShortenNurLongRows1){
                            int allowedMinSize=Arr2DSize_Rect_TypeN;
                            int QExtRows=this->GetQExtRows(), Lmax=this->GetRowLengthMax(), Lmin=this->GetRowLengthMin(),curL;
                            if(N<0){
                                N+=(QExtRows+1);
                            }
                            if(N>Lmin || ifNGTLminIgnore0ShortenNurLongRows1==1){
                                for(int _N=1; _N<=QExtRows; _N++){
                                    curL=this->GetRowLength(_N);
                                    if(curL>=N){
                                        this->rowsLs[_N-1]-=1;
                                    }
                                }
                            }

                        }//fn

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

                        //void Array2DSize_P_QERInner_VariaLength::Set(int* extRowsLengthes, int QExtRowsGiven, int ifNotRect_NonRect0_MakeRectBy_Min1Max2MinOfMax3MaxOfMax4, bool IfNotValsOfGivenRow_DefaultNotOwn){
                        //    int LminGiven, LmaxGiven, QExtRowsOld=this->GetQExtRows(), Lmin=this->GetRowLengthMin(), Lmax=this->GetRowLengthMax(), curLgiven, curLexisting, count=0;
                        //    for(int ERNN=1; ERNN<=QExtRowsGiven; ERNN++){
                        //        curLgiven=extRowsLengthes[ERNN-1];
                        //        if(ERNN==1 || (ERNN>=1 && curLgiven<LminGiven)){
                        //            LminGiven=curLgiven;
                        //        }
                        //        if(ERNN==1 || (ERNN>=1 && curLgiven>LmaxGiven)){
                        //            LmaxGiven=curLgiven;
                        //        }
                        //    }
                        //    //if(LmaxGiven==LminGiven){
                        //    //    this->QExtRows=QExtRowsGiven;
                        //    //    this->ExtRowsLength=LmaxGiven;
                        //    //}else{
                        //        switch(ifNotRect_NonRect0_MakeRectBy_Min1Max2MinOfMax3MaxOfMax4){
                        //            case 0:
                        //                this->SetNull();
                        //                for(int ERNN=1; ERNN<=QExtRowsGiven; ERNN++){
                        //                    curLgiven=extRowsLengthes[ERNN-1];
                        //                    Arr1D_Add(this->rowsLs, count, curLgiven);
                        //                }
                        //            case 1:
                        //                this->SetNull();
                        //                for(int ERNN=1; ERNN<=QExtRowsGiven; ERNN++){
                        //                    //curLgiven=extRowsLengthes[ERNN-1];
                        //                    Arr1D_Add(this->rowsLs, count, LminGiven);
                        //                }
                        //            break;
                        //            case 2:
                        //                this->SetNull();
                        //                for(int ERNN=1; ERNN<=QExtRowsGiven; ERNN++){
                        //                    //curLgiven=extRowsLengthes[ERNN-1];
                        //                    Arr1D_Add(this->rowsLs, count, LminGiven);
                        //                }
                        //            break;
                        //            case 3:
                        //                this->SetNull();
                        //                if(LmaxGiven>=Lmax){
                        //                    for(int ERNN=1; ERNN<=QExtRowsGiven; ERNN++){
                        //                        //curLgiven=extRowsLengthes[ERNN-1];
                        //                         Arr1D_Add(this->rowsLs, count, LmaxGiven);
                        //                    }
                        //                }else{
                        //                    for(int ERNN=1; ERNN<=QExtRowsGiven; ERNN++){
                        //                        //curLgiven=extRowsLengthes[ERNN-1];
                        //                         Arr1D_Add(this->rowsLs, count, Lmax);
                        //                    }
                        //                }
                        //            break;
                        //            case 4:
                        //                this->SetNull();
                        //                if(LminGiven<=Lmin){
                        //                    for(int ERNN=1; ERNN<=QExtRowsGiven; ERNN++){
                        //                        //curLgiven=extRowsLengthes[ERNN-1];
                        //                        this->rowsLs.push_back(LminGiven);
                        //                    }
                        //                }else{
                        //                    for(int ERNN=1; ERNN<=QExtRowsGiven; ERNN++){
                        //                        //curLgiven=extRowsLengthes[ERNN-1];
                        //                        this->rowsLs.push_back(Lmin);
                        //                    }
                        //                }
                        //            break;
                        //        }
                        //    //}
                        //}//fn


                        //void Set(std::vector<int>Ls, int ifNotRect_NonRect0_MakeRectBy_Min1Max2=0);
                        ////int Set_GetExtNewRowLength(int* extRowsLengthes, int QExtRows, int ifNotRect_NonRect0_MakeRectBy_Min1Max2=0);//no need - 4 tgos: Lcur, Lold, Lmin, Lmax
                        //int Set_Arr2DNewCoordsToDataTypeN(const Coords2DInt&coords, int* extRowsLengthes, int QExtRows=1, int ifNotRect_NonRect0_MakeRectBy_Min1Max2=0);
                        //Coords2DInt Set_Arr2DNewToOldCoords(const Coords2DInt&coords, int* extRowsLengthes, int QExtRows=1, int ifNotRect_NonRect0_MakeRectBy_Min1Max2=0);
                        //std::string Array2DSize_V1D_VariaLength::GetAsString(){
                        //    return Array2DSize_Prototype::GetAsStdString();
                        //}
                   // };

                   //class Array2DSize{
                   //         Array2DSize_Prototype*data;
                   //       public:
                            Array2DSize::Array2DSize(int QExtRows, int ExtRowLength, int TypeN){
                                int MinSizeAllowed=DEFAULT_SIZE;
                                this->construct(TypeN);
                                if((QExtRows>0 && ExtRowLength>0)|| ((QExtRows==0 || ExtRowLength==0))&& MinSizeAllowed==0){
                                    this->Set(QExtRows, ExtRowLength);
                                }
                            }

                            Array2DSize::Array2DSize(int*ExtRowsLengthes, int QExtRows, int TypeN){
                                this->construct(TypeN);
                                this->Set(ExtRowsLengthes, QExtRows, TypeN);
                            }

                            Array2DSize::Array2DSize(std::vector<int>Ls, int TypeN){
                                this->construct(TypeN);
                                this->Set(Ls, TypeN);
                            }
                            Array2DSize::Array2DSize(const Array2DSize&obj){
                                int typeNNew=obj.GetTypeN();
                                this->construct(typeNNew);
                                this->Assign(obj);
                            }

                            Array2DSize::~Array2DSize(){
                                delete this->data;
                            }

                            void Array2DSize::Assign(const Array2DSize&obj){
                                int Lmin=obj.GetRowLengthMin(), typeNNew=obj.GetTypeN(), typeNOld=this->GetTypeN();
                                std::vector<int>Ls;
                                if(obj.IsRectangularByType()){
                                    this->Set(obj.GetQExtRows(), Lmin, typeNNew);
                                }else{
                                    Ls=obj.GetLengthes();
                                    this->Set(Ls, typeNNew);
                                }
                            }

                            void Array2DSize::Assign( Array2DSize_Prototype*obj){
                                int Lmin=obj->GetRowLengthMin(), typeNOld=this->GetTypeN(), typeNNew=obj->GetTypeN();
                                std::vector<int>Ls;
                                if(obj->IsRectangularByType()){
                                    this->Set(obj->GetQExtRows(), Lmin, typeNNew);
                                }else{
                                    Ls=obj->GetLengthes();
                                    this->Set(Ls, typeNNew);
                                }
                                //this->data->Assign(obj);
                            }

                            Array2DSize Array2DSize::operator = (const Array2DSize&obj){
                                this->Assign(obj);
                                return *this;
                            }

                           //
                            std::vector<int> Array2DSize::GetAsArrayOfExtRowsLengthes()const{  //new
                                return this->data->GetAsArrayOfExtRowsLengthes();
                            }

                            //
                            void Array2DSize::construct(int TypeN){
                                switch(TypeN){
                                    case Arr2DSize_Rect_TypeN:
                                        this->data=new Array2DSize_Rectangular();
                                    break;
                                    case Arr2DSize_VarLens_V_TypeN:
                                        this->data=new Array2DSize_V1D_VariaLength();
                                    break;
                                    case Arr2DSize_VarLens_P_TypeN:
                                        this->data=new Array2DSize_P_QERInner_VariaLength();
                                    break;
                                }
                                this->data->SetNullIni();
                            }

                            void Array2DSize::SetNull(){
                                this->data->SetNull();
                            }

                            void Array2DSize::SetNullIni(){
                                this->data->SetNullIni();
                            }

                            void Array2DSize::SetOne(){
                                this->data->SetOne();
                            }

                            //
                            int Array2DSize::GetTypeN()const{
                                return this->data->GetTypeN();
                            }
                            //
                            void Array2DSize::SetTypeN(int TypeN){
                                int OldTypeN=this->GetTypeN(), Lmin=this->GetRowLengthMin(), Lmax=this->GetRowLengthMax(), QExtRows=this->GetQExtRows();
                                std::vector<int>Ls;
                                if(TypeN!=OldTypeN){
                                    if(OldTypeN==Arr2DSize_Rect_TypeN){
                                        delete this->data;
                                        switch(TypeN){
                                            //case Arr2DSize_Rect_TypeN:
                                                //this->data=new Array2DSize_Rectangular(QExtRows, Lmax);
                                                //NOp;
                                            //break;
                                            case Arr2DSize_VarLens_V_TypeN:
                                                this->data=new Array2DSize_V1D_VariaLength(QExtRows, Lmax);
                                            break;
                                            case Arr2DSize_VarLens_P_TypeN:
                                                this->data=new Array2DSize_P_QERInner_VariaLength(QExtRows, Lmax);
                                            break;
                                        }
                                    }else{
                                        if(TypeN==Arr2DSize_Rect_TypeN){
                                            delete this->data;
                                            this->data=new Array2DSize_Rectangular(QExtRows, Lmax);
                                        }else{
                                            Ls=this->GetLengthes();//nur amda os nod!
                                            delete this->data;
                                            switch(TypeN){
                                                //case Arr2DSize_Rect_TypeN:
                                                    //this->data=new Array2DSize_Rectangular(QExtRows, Lmax);
                                                    //NOp;
                                                //break;
                                                case Arr2DSize_VarLens_V_TypeN:
                                                    this->data=new Array2DSize_V1D_VariaLength(Ls, 0);
                                                break;
                                                case Arr2DSize_VarLens_P_TypeN:
                                                    this->data=new Array2DSize_P_QERInner_VariaLength(Ls, 0);
                                                break;
                                            }
                                        }
                                    }
                                }//else NOp;
                            }

                            int Array2DSize::GetIneRowLength(int IRNN, bool countWhole) const{
                                return this->data->GetIneRowLength(IRNN, countWhole);
                            }

                            //
                            //void Array2DSize::Assign(Array2DSize_Prototype*obj){
                            //    this->data->Assign(obj);
                            //}

                            //
                            void Array2DSize::Set(int* extRowsLengthes, int QExtRows, int ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2, int TypeN){
                                int TypeNOld=this->GetTypeN();
                                if(TypeNOld!=TypeN){
                                    this->construct(TypeN);
                                }
                                this->data->Set(extRowsLengthes, QExtRows, ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2);
                            }

                            void Array2DSize::Set(int QExtRows, int extRowsLength, int TypeN){
                                int TypeNOld=this->GetTypeN();
                                if(TypeNOld!=TypeN){
                                    this->construct(TypeN);
                                }
                                this->data->Set(extRowsLength, QExtRows);
                            }

                            void Array2DSize::Set(std::vector<int>Ls, int ifNotRectForRect_NonRect0_MakeRectBy_Min1Max2, int TypeN){
                                int TypeNOld=this->GetTypeN();
                                if(TypeNOld!=TypeN){
                                    this->construct(TypeN);
                                }
                                this->data->Set(Ls);
                            }

                            //
                            int Array2DSize::GetQExtRows() const{
                                return this->data->GetQExtRows();
                            }
                            int Array2DSize::GetRowLength(int N) const {
                                return this->data->GetQExtRows();
                            }
                            int Array2DSize::GetRowLengthMin() const {
                                return this->data->GetRowLengthMin();
                            }
                            int Array2DSize::GetRowLengthMax() const  {
                                return this->data->GetRowLengthMax();
                            }
                            std::vector<int> Array2DSize::GetLengthes() const{
                                return this->data->GetLengthes();
                            }
                            std::vector<int> Array2DSize::GetMinLengthRowNs() const{
                                return this->data->GetMinLengthRowNs();
                            }
                            std::vector<int> Array2DSize::GetMaxLengthRowNs() const{
                                return this->data->GetMinLengthRowNs();
                            }
                            int Array2DSize::GetQElements() const{
                                return this->data->GetQElements();
                            }
                            //virtual Array2DSize_Prototype*GetSize_asPtr() const =0;
                            //
                            int Array2DSize::Arr2DBy1D_PosNByCoords(int ExtRowN, int IneRowN) const{
                                return this->data->Arr2DBy1D_PosNByCoords(ExtRowN, IneRowN);
                            }
                            Coords2DInt Array2DSize::Arr2DBy1D_CoordsByPosN(int PosN) const{
                                return this->data->Arr2DBy1D_CoordsByPosN(PosN);
                            }
                            //int Arr2DBy1D_ExtRowNByPosN(int PosN) const;
                            //int Arr2DBy1D_IneRowNByPosN(int PosN) const;
                            //
                            bool Array2DSize::IsRectangularByType() const{
                                return this->data->IsRectangularByType();
                            }
                            bool Array2DSize::IsRectangularInFact() const{
                                return this->data->IsRectangularInFact();
                            }
                            bool Array2DSize::IsEmpty() const {
                                return this->data->IsEmpty();
                            }
                            //
                            //
                            void Array2DSize::setExtRow_simplyAsDataGiven(int ExtRowNN_0ifAll, int L, int ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4){
                                this->data->setExtRow_simplyAsDataGiven(ExtRowNN_0ifAll, L, ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4);
                            }
                            void Array2DSize::addExtRow_simplyAsDataGiven(int L,           int ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4){
                                this->data->addExtRow_simplyAsDataGiven(L, ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4);
                            }
                            void Array2DSize::insExtRow_simplyAsDataGiven(int N, int L, int ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4){
                                this->data->insExtRow_simplyAsDataGiven(N, L, ifNonRectForRect_NonRect0_MakeRactChangingBy_New1Old2Max3Min4);
                            }
                            void Array2DSize::delExtRow_simplyAsDataGiven(int N){
                                this->data->delExtRow_simplyAsDataGiven(N);
                            }
                            void Array2DSize::set_or_ins_IneRow_simplyAsDataGiven(int Action_Set1_Ins2, int N, int L, int ifL_NE_QER_Ignore0_MakeRactChangingBy_New1Old2Max3Min4, int ifLminLTN_ifAdd_N1_Lmax2_LmaxRest3_MakeRectAnyway_Lmax4_LmaxRest5){
                                this->data->set_or_ins_IneRow_simplyAsDataGiven(Action_Set1_Ins2, N, L, ifL_NE_QER_Ignore0_MakeRactChangingBy_New1Old2Max3Min4, ifLminLTN_ifAdd_N1_Lmax2_LmaxRest3_MakeRectAnyway_Lmax4_LmaxRest5);
                            }
                            void Array2DSize::addIneRow_simplyAsDataGiven(int L, int ifL_NE_QER_Ignore0_MakeRactChangingBy_New1Old2Max3Min4, int ifNonRect_Ignore0AddToLast1StretchToMax2){
                                this->data->addIneRow_simplyAsDataGiven(L, ifL_NE_QER_Ignore0_MakeRactChangingBy_New1Old2Max3Min4, ifNonRect_Ignore0AddToLast1StretchToMax2);
                            }
                            void Array2DSize::delIneRow_simplyAsDataGiven(int N, int ifNGTLminIgnore0ShortenNurLongRows1){
                                this->data->delIneRow_simplyAsDataGiven(N, ifNGTLminIgnore0ShortenNurLongRows1);
                            }
                            //
                            //
                            TDataShiftResults Array2DSize::ExtRow_SetAddInsDel_dataNs(int Action_Set1_Add2_Ins3_Del4_Dflt0, int givenRowL, /*int inquiredRowNN,*/ int ChangedRowNN_0ifAll, TDataShiftParams*DataShiftParam, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, bool suiValsInsteadOfDefaultValsWherePossible){
                                return this->ExtRow_SetAddInsDel_dataNs(Action_Set1_Add2_Ins3_Del4_Dflt0, givenRowL, /*inquiredRowNN,*/ ChangedRowNN_0ifAll, DataShiftParam, ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, suiValsInsteadOfDefaultValsWherePossible);
                            }

                            int Array2DSize::ExtRow_SetAddInsDel_ThatCorrectedByNewData_NewLength(int Action_Set1_Add2_Ins3_Del4_Dflt0, int givenRowL, int ExtRowNN_0ifAll, TDataShiftParams*DataShiftParam, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, bool suiValsInsteadOfDefaultValsWherePossible){
                                return this->data->ExtRow_SetAddInsDel_ThatCorrectedByNewData_NewLength(Action_Set1_Add2_Ins3_Del4_Dflt0, givenRowL, ExtRowNN_0ifAll, DataShiftParam, ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, suiValsInsteadOfDefaultValsWherePossible);
                            }

                            int Array2DSize::ExtRow_SetAddInsDel_ThatCorrectedByNewData_PosInRowToDataTypeN(int Action_Set1_Add2_Ins3_Del4_Dflt0, int InRowPosNN, int givenRowL, int ExtRowNN_0ifAll, TDataShiftParams*DataShiftParam, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, bool suiValsInsteadOfDefaultValsWherePossible){
                                return this->data->ExtRow_SetAddInsDel_ThatCorrectedByNewData_PosInRowToDataTypeN(Action_Set1_Add2_Ins3_Del4_Dflt0, InRowPosNN, givenRowL, ExtRowNN_0ifAll, DataShiftParam, ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, suiValsInsteadOfDefaultValsWherePossible);
                            }

                            int Array2DSize::ExtRow_SetAddInsDel_OldLengthOfExtRowN(int Action_Set1_Add2_Ins3_Del4_Dflt0, int inquiredRowNN, int ExtRowNN_0ifAll, int givenRowL, TDataShiftParams*ShiftData, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, bool suiValsInsteadOfDefaultValsWherePossible){
                                return this->data->ExtRow_SetAddInsDel_OldLengthOfExtRowN(Action_Set1_Add2_Ins3_Del4_Dflt0, inquiredRowNN, ExtRowNN_0ifAll, givenRowL, ShiftData, ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, suiValsInsteadOfDefaultValsWherePossible);
                            }

                            int Array2DSize::ExtRow_SetAddInsDel_NewLengthOfExtRowN(int Action_Set1_Add2_Ins3_Del4_Dflt0, int inquiredRowNN, int ExtRowNN_0ifAll, int givenRowL, TDataShiftParams*ShiftData, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4,  bool suiValsInsteadOfDefaultValsWherePossible){
                                return this->data->ExtRow_SetAddInsDel_NewLengthOfExtRowN(Action_Set1_Add2_Ins3_Del4_Dflt0, inquiredRowNN, ExtRowNN_0ifAll, givenRowL, ShiftData, ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, suiValsInsteadOfDefaultValsWherePossible);
                            }

                            //
                            int Array2DSize::ExtRow_SetAddInsDel_Arr2DNewCoordsToDataTypeN(int Action_Set1_Add2_Ins3_Del4_Dflt0, const Coords2DInt&coords, int ExtRowNN_0ifAll, int givenRowL, TDataShiftParams*ShiftData, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, bool suiValsInsteadOfDefaultValsWherePossible){
                                return this->data->ExtRow_SetAddInsDel_Arr2DNewCoordsToDataTypeN(Action_Set1_Add2_Ins3_Del4_Dflt0, coords, ExtRowNN_0ifAll, givenRowL, ShiftData, ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, suiValsInsteadOfDefaultValsWherePossible);
                            }
                            //
                            //
                            int Array2DSize::ExtRow_SetAddInsDel_ThatCorrectedByNewData_FromArr2dNewToGivenRowPosN(int Action_Set1_Add2_Ins3_Del4_Dflt0, int InRowPosNN, int givenRowL, int ExtRowNN_0ifAll, TDataShiftParams*DataShiftParam, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, bool suiValsInsteadOfDefaultValsWherePossible){
                                return this->data->ExtRow_SetAddInsDel_ThatCorrectedByNewData_FromArr2dNewToGivenRowPosN(Action_Set1_Add2_Ins3_Del4_Dflt0, InRowPosNN, givenRowL, ExtRowNN_0ifAll, DataShiftParam, ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, suiValsInsteadOfDefaultValsWherePossible);
                            }

                            int Array2DSize::ExtRow_SetAddInsDel_ThatCorrectedByNewData_FromArr2dNewToOldRowPosN(int Action_Set1_Add2_Ins3_Del4_Dflt0, int InRowNN, int givenRowL, int ExtRowNN_0ifAll, TDataShiftParams*DataShiftParam, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, bool suiValsInsteadOfDefaultValsWherePossible){
                                return this->data->ExtRow_SetAddInsDel_ThatCorrectedByNewData_FromArr2dNewToOldRowPosN(Action_Set1_Add2_Ins3_Del4_Dflt0, InRowNN, givenRowL, ExtRowNN_0ifAll, DataShiftParam, ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, suiValsInsteadOfDefaultValsWherePossible);
                            }



                            //int Array2DSize::ExtRow_SetAddInsDel_ThatCorrectedByNewData_FromArr2dNewToGivenRowPosN(int Action_Set1_Add2_Ins3_Del4_Dflt0, int InRowPosNN, int givenRowL, int ChangedRowNN_0ifAll, TDataShiftParams*DataShiftParam, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, bool suiValsInsteadOfDefaultValsWherePossible){
                            //    this->data->ExtRow_SetAddInsDel_ThatCorrectedByNewData_FromArr2dNewToGivenRowPosN(Action_Set1_Add2_Ins3_Del4_Dflt0, InRowPosNN, givenRowL, ChangedRowNN_0ifAll, DataShiftParam, ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, suiValsInsteadOfDefaultValsWherePossible);
                            //}

                            //int Array2DSize::ExtRow_SetAddInsDel_ThatCorrectedByNewData_FromArr2dNewToOldRowPosN(int Action_Set1_Add2_Ins3_Del4_Dflt0, int InRowNN, /*const Coords2DInt&coords,*/ int givenRowL, int ExtRowNN_0ifAll, TDataShiftParams*DataShiftParam, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, bool suiValsInsteadOfDefaultValsWherePossible){
                            //    int PosN;
                            //    PosN=this->data-> ExtRow_SetAddInsDel_ThatCorrectedByNewData_FromArr2dNewToOldRowPosN(Action_Set1_Add2_Ins3_Del4_Dflt0, InRowNN, /*const Coords2DInt&coords,*/ givenRowL, ExtRowNN_0ifAll, TDataShiftParams*DataShiftParam, ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, suiValsInsteadOfDefaultValsWherePossible);
                            //    return PosN;
                            //}

                            Coords2DInt Array2DSize::ExtRow_SetAddInsDel_ThatCorrectedByNewData_CoordsFromArr2dNewToOld(int Action_Set1_Add2_Ins3_Del4_Dflt0, const Coords2DInt&coords, int givenRowL, int ExtRowNN_0ifAll, TDataShiftParams*DataShiftParam, int ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, bool suiValsInsteadOfDefaultValsWherePossible){
                                Coords2DInt coordsR;
                                coordsR=this->data->ExtRow_SetAddInsDel_ThatCorrectedByNewData_CoordsFromArr2dNewToOld(Action_Set1_Add2_Ins3_Del4_Dflt0, coords, givenRowL, ExtRowNN_0ifAll, DataShiftParam, ifWasRectAndNotEqual_NonRect0_SetRectBy_New1_Old2_Max3_Min4, suiValsInsteadOfDefaultValsWherePossible);
                                return coordsR;
                            }
                            //
                            //
                            ////void Array2DSize::Set(int* extRowsLengthes, int QExtRows, int ifNotRect_NonRect0_MakeRectBy_Min1Max2MinOfMax3MaxOfMax4, bool IfNotValsOfGivenRow_DefaultNotOwn){
                            ////    this->data->Set(extRowsLengthes, QExtRows, ifNotRect_NonRect0_MakeRectBy_Min1Max2MinOfMax3MaxOfMax4, IfNotValsOfGivenRow_DefaultNotOwn);
                            ////}

                            //
                            //
                            QString Array2DSize::GetAsString(){
                                return this->data->GetAsString();
                            }
                            //
                            //
                        //};
