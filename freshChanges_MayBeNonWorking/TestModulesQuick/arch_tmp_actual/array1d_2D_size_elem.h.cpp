#include "array1d_2D_size_elem.h"


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


//    TDataShiftResults TDataShiftParams::Calc0(int Lown, int vsh) {
//        TDataShiftResults data;
//        int LOwnTaken=Lown-this->FirstN+1;
//        int LTaken=this->QDefaultsBefore+LOwnTaken;
//        int QAfter=0;
//        if(vsh==1){
//            printf("TDataShiftParams::Calc starts working\n");
//            printf("Given: FirstN=%d, Lreq=%d, QDefaultsBefore=%d; Lown=%d\n",this->FirstN, this->Lreq, this->QDefaultsBefore, Lown);
//        }
//        if(this->Lreq==0){
//            this->Lreq=LTaken;
//        }
//        //if(this->FirstN>Lown || QDefaultsBefore>LOwnTaken){
//        if(this->FirstN>Lown || this->QDefaultsBefore>=Lreq || this->FirstN>this->Lreq-this->QDefaultsBefore){
//            data.PreN1=1;
//            data.PreN2=this->Lreq;
//            if(vsh==1){
//                if(this->FirstN>Lown){
//                    printf(".FirstN>Lown \n");
//                }
//                if(this->QDefaultsBefore>this->Lreq){
//                    printf(".QDefaultsBefore>=.Lreq \n");
//                }
//                if(this->FirstN>this->Lreq-this->QDefaultsBefore){
//                    printf(".FirstN>=Lreq-QDefaultsBefore \n");
//                }
//                printf("Data: cannot be displayed .PreN1=1=%d, .PreN2=Lreq=%d\n",data.PreN1, data.PreN2);
//            }
//        }else{
//            if(vsh==1){
//                printf("data can be displayed\n");
//            }
//            data.OwnN1=this->FirstN;
//            data.ForOwnN1=data.PreN2+1;

//            if(this->QDefaultsBefore>this->Lreq-Lown){//but < Lreq
//                data.PreN2=this->QDefaultsBefore;
//                LOwnTaken=this->Lreq-this->QDefaultsBefore;
//                data.OwnN2=this->FirstN+LOwnTaken-1;
//                data.ForOwnN2=data.ForOwnN1+LOwnTaken-1;
//                if(vsh==1){
//                    printf(".Lreq-Lown < .QDefaultsBefore < .Lreq\n");
//                    //printf(" PreN2=%d, OwnN1=%d, OwnN2=%d, ForOwnN1=%d\n",data.PreN2, data.OwnN1, data.OwnN2, data.ForOwnN1);
//                }
//            }else{//&& FirstN<=Lown
//                if(this->QDefaultsBefore>0){
//                    data.PreN1=1;
//                    data.PreN2=this->QDefaultsBefore;
//                    if(vsh==1){
//                        printf(".QDefaultsBefore>0 => .PreN1=%d, .PreN2=%d\n", data.PreN1, data.PreN2);
//                    }
//                }
//                data.ForOwnN1=data.PreN2+1;
//                data.OwnN1=this->FirstN;
//                if(this->Lreq<=this->QDefaultsBefore+LOwnTaken){
//                    data.ForOwnN2=this->Lreq;
//                    LOwnTaken=data.ForOwnN2-data.ForOwnN1+1;
//                    data.ForOwnN2=data.ForOwnN1+LOwnTaken-1;//needed in alt branch ut calc PostN1
//                    //data.OwnN2=this->FirstN+LOwnTaken-1;
//                    if(vsh==1){
//                        printf(".Lreq<=.QDefaultsBefore+LOwnTaken\n");
//                        //printf("ForOwnN1=%d ForOwnN2=%d OwnN1=%d OwnN2=%d\n", data.ForOwnN1, data.ForOwnN2, data.OwnN1, data.OwnN2);
//                    }
//                }else{//this->Lreq>LOwnTaken
//                    data.OwnN2=data.OwnN1+LOwnTaken-1;
//                    data.ForOwnN2=data.ForOwnN1+LOwnTaken-1;//nod ut calc PostN1
//                    data.PostN1=data.ForOwnN2+1;
//                    data.PostN2=this->Lreq;
//                    if(vsh==1){
//                        printf(".Lreq>.QDefaultsBefore+LOwnTaken\n");
//                        //printf("ForOwnN1=%d ForOwnN2=%d OwnN1=%d OwnN2=%d\n", data.ForOwnN1, data.ForOwnN2, data.OwnN1, data.OwnN2);
//                        //printf(" .PostN1=%d, .PostN2=%d\n", data.PostN1, data.PostN2);
//                    }

//                }
//                //data.ForOwnN2=data.ForOwnN1+LOwnTaken-1;//nod efce in 1 of branches ut calc PostN1
//                data.OwnN2=this->FirstN+LOwnTaken-1;
//                if(vsh==1){
//                    printf(".ForOwnN1=%d .ForOwnN2=%d .OwnN1=%d .OwnN2=%d\n", data.ForOwnN1, data.ForOwnN2, data.OwnN1, data.OwnN2);
//                    if(data.PostN1>0 || data.PostN2>0){
//                        printf("; .PostN1=%d, .PostN2=%d\n", data.PostN1, data.PostN2);
//                    }
//                    //printf("\n");
//                }
//            }
//        }
//        if(vsh==1){
//            printf("; .PreN1=%d, .PreN2=%d\n", data.PreN1, data.PreN2);
//            printf("TDataShiftParams::Calc finishes working\n");
//        }
//        return data;
//    }//Calc0

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

//class Array2DSize_Prototype{
    //public:
        Array2DSize_Prototype::~Array2DSize_Prototype(){}//in .h it is pure virtual
        //
        // virtual Array2DSize_Prototype* GetCopy()=0; //new
        std::vector<int> Array2DSize_Prototype::GetAsArrayOfExtRowsLengthes()const{
            std::vector<int>Ls;
            int QER=this->GetQExtRows(), curL;
            for(int N=1; N<=QER; N++){
                curL=this->GetRowLength(N-1);
                Ls.push_back(curL);
            }
            return Ls;
        }
        //
        void Array2DSize_Prototype::construct(){
            int dfltSize=DEFAULT_SIZE;
            this->SetNullIni();
            if(dfltSize==1){
                this->SetOne();
            }
        }
        //virtual void SetNull()=0;
        //virtual void SetNullIni()=0;
        //virtual void SetOne()=0;
        //
        //virtual int GetTypeN()=0;
        //
        //virtual void Assign(Array2DSize_Prototype*obj)=0;
        //
        //virtual void Set(int* extRowsLengthes=NULL, int QExtRows=0)=0;
        //virtual void Set(int extRowsLength=0, int QExtRows=0)=0;//may descr it generally or may leave it virtual
        //virtual void Set(std::vector<int>Ls)=0;
        //
        //virtual int GetQExtRows() const =0;
        //virtual int GetRowLength(int N=-1) const =0;
        //virtual int GetRowLengthMin() const =0;
        //virtual int GetRowLengthMax() const =0;
        std::vector<int> Array2DSize_Prototype::GetLengthes() const{
            std::vector<int>Ls;
            int curL, QER=this->GetQExtRows();
            for(int i=1; i<=QER; i++){
                curL=this->GetRowLength(i);
                Ls.push_back(curL);
            }
            return Ls;
        }
        std::vector<int> Array2DSize_Prototype::GetMinLengthRowNs() const{
            std::vector<int>Ns;
            int curL, QER=this->GetQExtRows(), minL=this->GetRowLengthMin(), maxL=this->GetRowLengthMax();
            for(int N=1; N<=QER; N++){
                curL=this->GetRowLength(N);
                if(curL==minL){
                    Ns.push_back(N);
                }
            }
            return Ns;
        }
        std::vector<int> Array2DSize_Prototype::GetMaxLengthRowNs() const {
            std::vector<int>Ns;
            int curL, QER=this->GetQExtRows(), minL=this->GetRowLengthMin(), maxL=this->GetRowLengthMax();
            for(int N=1; N<=QER; N++){
                curL=this->GetRowLength(N);
                if(curL==maxL){
                    Ns.push_back(N);
                }
            }
            return Ns;
        }
        int Array2DSize_Prototype::GetQElements() const{
            int countElements=0, QER=this->GetQExtRows(), curL;
            for(int N=1; N<=QER; N++){
                curL=this->GetRowLength(N-1);
                countElements+=curL;
            }
            return countElements;
        }
        //virtual Array2DSize_Prototype*GetSize_asPtr() const =0;
        //
        int Array2DSize_Prototype::Arr2DBy1D_PosNByCoords(int ExtRowN, int IneRowN) const{
            int PosN=0, QER=this->GetQExtRows(), curL;
            for(int N=1; N<=ExtRowN-1; N++){
                curL=this->GetRowLength(N);
                PosN+=curL;
            }
            PosN+=IneRowN;
            return PosN;
        }
        Coords2DInt Array2DSize_Prototype::Arr2DBy1D_CoordsByPosN(int PosN) const{
            Coords2DInt coords;
            int QER=this->GetQExtRows(), ExtRowN=0, IneRowN=0, curL, curN=0;
            while(curN<PosN){
                ExtRowN+=1;
                curL=this->GetRowLength(ExtRowN);
                curN+=curL;
            }
            if(curN<PosN){
                ExtRowN-=1;
                curN-=curL;
                IneRowN=PosN-curN;
            }else{//curN<PosN
                IneRowN=curL;
            }
            coords.set(ExtRowN, IneRowN);
            return coords;
        }
        //int Arr2DBy1D_ExtRowNByPosN(int PosN) const;
        //int Arr2DBy1D_IneRowNByPosN(int PosN) const;
        //
        //virtual bool IsRectangularByType() const =0;
        //virtual bool IsRectangularInFact() const =0;
        //virtual bool IsEmpty() const =0;
        //virtual int GetTypeN() const =0;
        //
        //virtual int SetRowLength(int L, int N=0, int ifNotEqual_Ignore0Old1New2Max3Min4)=0;
        //virtual int SetQExtRows(int Q, int IfNotRect_ERL_ByMin1ByMax2ByLast3)=0;
        //
        //virtual void SetExtRow(int RowN, int L=0, TDataShiftParams*DataShiftParams=NULL, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1)=0;
        //
        //virtual Coords2DInt SetExtRow_CoordsByElementN(int ElementN, int RowN, int L=0, TDataShiftParams*DataShiftParams=NULL, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1)=0;
        //
        //virtual void AddExtRow(         int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL)=0;
        //
        //virtual Coords2DInt AddExtRow_CoordsByElementN(int ElementN,       int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL)=0;
        //virtual int AddExtRow_ElementNByCoords(const Coords2DInt& coords,  int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL)=0;
        //
        //virtual void InsExtRow(int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL)=0;
        //
        //virtual Coords2DInt InsExtRow_CoordsByElementN(    int ElementN,        int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL)=0;
        //virtual int InsExtRow_ElementNByCoords(      const Coords2DInt& coords, int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL)=0;
        //virtual Coords2DInt InsExtRow_CoordsOldByNew(const Coords2DInt& coords, int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL)=0;
        //virtual Coords2DInt InsExtRow_CoordsNewByOld(const Coords2DInt& coords, int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL)=0;
        //
        //virtual void DelExtRow(int N=-1)=0;
        //
        ////Coords2DInt DelExtRow_CoordsOldByNew(const Coords2DInt& coords, int N=-1);//no need
        ////Coords2DInt DelExtRow_CoordsNewByOld(const Coords2DInt& coords, int N=-1);//no need
        //
        //virtual void AddIneRow(int L=0, int IfNotSameQER_ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL)=0;
        //
        //virtual Coords2DInt AddIneRow_CoordsByElementN(int ElementN,      int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL);
        //virtual int AddIneRow_ElementNByCoords(const Coords2DInt& coords, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL);
        //
        //virtual void InsIneRow(int N=0, int L=0, int IfNotSameQER_ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL)=0;
        //
        //virtual Coords2DInt InsIneRow_CoordsByElementN(    int ElementN,        int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1)=0;
        //virtual int InsIneRow_ElementNByCoords(      const Coords2DInt& coords, int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1)=0;
        //virtual Coords2DInt InsIneRow_CoordsOldByNew(const Coords2DInt& coords, int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1)=0;
        //virtual Coords2DInt InsIneRow_CoordsNewByOld(const Coords2DInt& coords, int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1)=0;
        //
        //virtual void DelIneRow(int N=-1)=0;
        ////Coords2DInt DelIneRow_CoordsOldByNew(const Coords2DInt& coords, int N=-1);//no need
        ////Coords2DInt DelIneRow_CoordsNewByOld(const Coords2DInt& coords, int N=-1);//no need
        //
        //
        //virtual void AddOrInsToExtRowN(int N=-1)=0;
        //virtual void DelFromExtRowN(int N=-1)=0;
        //
        void Array2DSize_Prototype::SwapExtRows(int N1, int N2){
            int L1, L2, QER=this->GetQExtRows();
            if(N1<=0){
                N1+=(QER-1);
            }
            if(N2<=0){
                N2+=(QER-1);
            }
            if(N1>=1 && N1<=QER && N2>=1 && N2<=QER){
                L1=this->GetRowLength(N1);
                L2=this->GetRowLength(N2);
                this->SetRowLength(L2, N1);
                this->SetRowLength(L1, N2);
            }
        }

        ////void SwapIneRows(int N1, int N2)=0;//No need
        void Array2DSize_Prototype::ReverseExtRowsSuccession(){
            int midN, N1, N2, L1, L2, QER=this->GetQExtRows();
            if(QER%2==0){
                midN=QER/2;
            }else{
                midN=(QER-1)/2;
            }
            for(N1=1; N1<=midN; N1++){
                N2=QER-N1+1;
                this->SwapExtRows(N1, N2);
            }
        }
        //virtual void ShiftExtRowsCyclelyToBegin()=0;
        //virtual void ShiftExtRowsCyclelyToEnd()=0;
        //
        bool Array2DSize_Prototype::IsTransposable() const{
            bool verdict=true;
            int QER=this->GetQExtRows(), curL1, curL2, maxL=this->GetRowLengthMax();
            curL1=this->GetRowLength(1);
            for(int N=2; N<=QER; N++){
                curL2=this->GetRowLength(N);
                if(curL2>curL1){
                    verdict=false;
                }
                curL1=curL2;
            }
            return verdict;
        }
        //
        //virtual void Transpose()=0;
        std::vector<int> Array2DSize_Prototype::TransposeTo(){
            int QER=this->GetQExtRows(), maxL=this->GetRowLengthMax(), curL;
            std::vector<int>LT;
            if(this->IsTransposable()){
                
            }
            return LT;
        }
        //
        Coords2DInt Array2DSize_Prototype::Transpose_CoordsOfSinglePointFromIniToT(const Coords2DInt& coords1)const{
            Coords2DInt coords2;//mab 0
            int ExtRowN1=coords1.x, IneRowN1=coords1.y, ExtRowN2, IneRowN2, curL, QER=this->GetQExtRows();
            if(this->IsTransposable() && ExtRowN1>=1 && ExtRowN1<=QER && IneRowN1>=1 && IneRowN1<=this->GetRowLength(ExtRowN1)){
                 IneRowN2=ExtRowN1;
                 ExtRowN2=this->GetLengthOfIneRowN_FromFirstNoEmptyPoss(IneRowN1);
                 coords2.x= ExtRowN2;
                 coords2.y= IneRowN2;
            }
            return coords2;
        }
        Coords2DInt Array2DSize_Prototype::Transpose_CoordsOfSinglePointFromTToIni(const Coords2DInt& coords1)const{
            Coords2DInt coords2;//mab 0
            int ExtRowN1=coords1.x, IneRowN1=coords1.y, ExtRowN2, IneRowN2, curL, QER=this->GetQExtRows();
            if(this->IsTransposable() && ExtRowN1>=1 && ExtRowN1<=QER && IneRowN1>=1 && IneRowN1<=this->GetRowLength(ExtRowN1)){
                 IneRowN2=ExtRowN1;
                 ExtRowN2=this->GetLengthOfIneRowN_FromFirstNoEmptyPoss(IneRowN1);
                 coords2.x= ExtRowN2;
                 coords2.y= IneRowN2;
            }
            return coords2;
        }
        //Coords2DInt Transpose_CoordsBefByAft(const Coords2DInt& coords);
        //
        int Array2DSize_Prototype::GetLengthOfIneRowN_FromFirstNoEmptyPoss(int N) const{
            int QER=this->GetQExtRows(), curL, extRowN=0;
            curL=N;
            while(extRowN<QER || curL>=N){
                extRowN++;
                curL=this->GetRowLength(extRowN);
            }
            return extRowN;
        }
        //
        //virtual void ConcatAdding(Array2DSize_Prototype*obj, int shiftQ=0, TDataShiftParams*ExtRows=NULL)=0;
        //
        //Coords2DInt ConcatAdding_CoordsWhereByWhat(const Coords2DInt& coords, Array2DSize_Prototype*obj, int shiftQ=0);//mab virt if rules of array change str
        //Coords2DInt ConcatAdding_CoordsWhatByWhere(const Coords2DInt& coords, Array2DSize_Prototype*obj, int shiftQ=0);

        //virtual void ConcatStretching(Array2DSize_Prototype*obj, int shiftQ=0, TDataShiftParams*ExtRows=NULL)=0;

        //Coords2DInt ConcatStretching_CoordsWhereByWhat(const Coords2DInt& coords, Array2DSize_Prototype*obj, int shiftQ=0);
        //Coords2DInt ConcatStretching_CoordsWhatByWhere(const Coords2DInt& coords, Array2DSize_Prototype*obj, int shiftQ=0);
        //
        //virtual void SubArray(const TDataShiftParams&DataShift, int Ldflt=1, bool IsTransposed=false, bool ExtRowsSuccessionIsReversed=false, EachExtRowIsReversed=false)=0;
        //virtual void SubArray(const Coords2DInt& IniPoint, Array2DSize_Prototype*subArrSize, bool IsTransposed=false, bool ExtRowsSuccessionIsReversed=false, bool EachExtRowIsReversed=false, TDataShiftParams*ExtRows=NULL)=0;
        std::vector<int> Array2DSize_Prototype::SubArrayTo(const Coords2DInt& IniPoint, Array2DSize_Prototype*subArrSize, bool IsTransposed, bool ExtRowsSuccessionIsReversed, bool EachExtRowIsReversed, TDataShiftParams*ExtRows){
            std::vector<int>LsFrom=this->GetAsArrayOfExtRowsLengthes(), LsIni=subArrSize->GetAsArrayOfExtRowsLengthes(), LsMod, LsNew;
            LsMod=Arr1D_GetSubArr_ByLs(LsIni.data(), LsIni.size(), ExtRows);

            return LsNew;
        }
        //
        //                     Coords2DInt SubArray_CoordsWhereByWhat(const Coords2DInt& coordsGiven, const Coords2DInt& IniPoint, Array2DSize_Prototype*objDflt, int Ldflt=1,  bool IsTransposed=false, bool ExtRowsSuccessionIsReversed=false, bool EachExtRowIsReversed=false, TDataShiftParams*ExtRows=NULL);
        //                     Coords2DInt SubArray_CoordsWhatByWhere(const Coords2DInt& coordsGiven, const Coords2DInt& IniPoint, Array2DSize_Prototype*objDflt, int Ldflt=1,  bool IsTransposed=false, bool ExtRowsSuccessionIsReversed=false, bool EachExtRowIsReversed=false, TDataShiftParams*ExtRows=NULL);
        //
        Coords2DInt Array2DSize_Prototype::SubArray_CoordsWhereByWhat(const Coords2DInt& coordsWhat, const Coords2DInt& IniPoint, Array2DSize_Prototype*whatSize, bool IsTransposed, bool ExtRowsSuccessionIsReversed, bool EachExtRowIsReversed, TDataShiftParams*ExtRows){
            Coords2DInt coordsWhere;
            int QERWhere=this->GetQExtRows(), QERWhat=whatSize->GetQExtRows(),
                whereExtRowN,//=coordsWhere.x,
                whereIneRowN,//=coordsWhere.y,
                whatExtRowN=coordsWhat.x, whatIneRowN=coordsWhat.y,
                iniPointExtRowN=IniPoint.x, iniPointIneRowN=IniPoint.y;
            std::vector<int>whatSizeArr=whatSize->GetAsArrayOfExtRowsLengthes(),
                    //template <typename T> std::vector<T>GetSubVector(T*X, int Q,  TParamsOfDataShift*DataShiftParam, T*DefaultValParam=NULL)
                    //template<typename T> std::vector<T> Arr1D_GetSubArr_ByLs(const T*x, int Q, TDataShiftParams*DataShiftParams, T*dfltVal=NULL){//no vector specific
                    whatModSizeArr=Arr1D_GetSubArr_ByLs(whatSizeArr.data(), whatSizeArr.size(), ExtRows),//deduced conflicting types for parameter T (int and TDataShiftParams)
                    whereSizeArr=this->GetAsArrayOfExtRowsLengthes();
            if(IsTransposed==false){
                if(ExtRowsSuccessionIsReversed==false){
                    if(EachExtRowIsReversed==false){
                        // 11 12 13
                        // 21
                        // 31 32
                        whereExtRowN=iniPointExtRowN+whatExtRowN-1;
                        whereIneRowN=iniPointIneRowN+whatIneRowN-1;
                    }else{
                        // 13 12 11
                        //       21
                        //    32 31
                        whereExtRowN=iniPointExtRowN+whatExtRowN-1;
                        whereIneRowN=iniPointIneRowN-whatIneRowN+1;
                    }
                }else{
                    if(EachExtRowIsReversed==false){
                        // 31 32
                        // 21
                        // 11 12 13
                        whereExtRowN=iniPointExtRowN-whatExtRowN+1;
                        whereIneRowN=iniPointIneRowN+whatIneRowN-1;
                    }else{
                        //    32 31
                        //       21
                        // 13 12 11
                        whereExtRowN=iniPointExtRowN-whatExtRowN+1;
                        whereIneRowN=iniPointIneRowN-whatIneRowN+1;
                    }
                }
            }else{
                if(ExtRowsSuccessionIsReversed==false){
                    if(EachExtRowIsReversed==false){
                        // 11 21 31
                        // 12    32
                        // 13
                        whereExtRowN=iniPointExtRowN+whatIneRowN-1;
                        whereIneRowN=iniPointIneRowN+whatExtRowN-1;
                    }else{
                        // 13
                        // 12    32
                        // 11 21 31
                        whereExtRowN=iniPointExtRowN-whatIneRowN+1;
                        whereIneRowN=iniPointIneRowN+whatExtRowN-1;
                    }
                }else{
                    if(EachExtRowIsReversed==false){
                        // 31 21 11
                        // 32    12
                        //       13
                        whereExtRowN=iniPointExtRowN+whatIneRowN-1;
                        whereIneRowN=iniPointIneRowN-whatExtRowN+1;
                    }else{
                        //       13
                        // 32    12
                        // 31 21 11
                        whereExtRowN=iniPointExtRowN-whatIneRowN+1;
                        whereIneRowN=iniPointIneRowN-whatExtRowN+1;
                    }
                }
            }
            coordsWhere.set(whereExtRowN, whereIneRowN);
            return coordsWhere;
        }

        Coords2DInt Array2DSize_Prototype::SubArray_CoordsWhatByWhere(const Coords2DInt& coordsWhere, const Coords2DInt& IniPoint, Array2DSize_Prototype*whatSize, bool IsTransposed, bool ExtRowsSuccessionIsReversed, bool EachExtRowIsReversed, TDataShiftParams*ExtRows){
            Coords2DInt coordsWhat;
            int QERWhere=this->GetQExtRows(), QERWhat=whatSize->GetQExtRows(),
                whereExtRowN=coordsWhere.x,
                whereIneRowN=coordsWhere.y,
                whatExtRowN, whatIneRowN,
                iniPointExtRowN=IniPoint.x, iniPointIneRowN=IniPoint.y;
            std::vector<int>whatSizeArr=whatSize->GetAsArrayOfExtRowsLengthes(),
                    //template <typename T> std::vector<T>GetSubVector(T*X, int Q,  TParamsOfDataShift*DataShiftParam, T*DefaultValParam=NULL)
                    //template<typename T> std::vector<T> Arr1D_GetSubArr_ByLs(const T*x, int Q, TDataShiftParams*DataShiftParams, T*dfltVal=NULL){//no vector specific
                    whatModSizeArr=Arr1D_GetSubArr_ByLs(whatSizeArr.data(), whatSizeArr.size(), ExtRows),//deduced conflicting types for parameter T (int and TDataShiftParams)
                    whereSizeArr=this->GetAsArrayOfExtRowsLengthes();
            if(IsTransposed==false){
                if(ExtRowsSuccessionIsReversed==false){
                    if(EachExtRowIsReversed==false){
                        // 11 12 13
                        // 21
                        // 31 32
                        //whereExtRowN=iniPointExtRowN+whatExtRowN-1;
                        //=>
                        whatExtRowN=whereExtRowN-iniPointExtRowN+1;
                        //whereIneRowN=iniPointIneRowN+whatIneRowN-1;
                        //=>
                        whatIneRowN=whereIneRowN-iniPointIneRowN+1;
                    }else{
                        // 13 12 11
                        //       21
                        //    32 31
                        //whereExtRowN=iniPointExtRowN+whatExtRowN-1;
                        //=>
                        whatExtRowN=whereExtRowN-iniPointExtRowN+1;
                        //whereIneRowN=iniPointIneRowN-whatIneRowN+1;
                        //=>
                        whatIneRowN==iniPointIneRowN-whereIneRowN+1;
                    }
                }else{
                    if(EachExtRowIsReversed==false){
                        // 31 32
                        // 21
                        // 11 12 13
                        //whereExtRowN=iniPointExtRowN-whatExtRowN+1;
                        //=>
                        whatExtRowN=iniPointExtRowN-whereExtRowN+1;
                        //whereIneRowN=iniPointIneRowN+whatIneRowN-1;
                        //=>
                        whatIneRowN=whereIneRowN-iniPointIneRowN+1;
                    }else{
                        //    32 31
                        //       21
                        // 13 12 11
                        //whereExtRowN=iniPointExtRowN-whatExtRowN+1;
                        //=>
                        whatExtRowN=iniPointExtRowN-whereExtRowN+1;
                        //whereIneRowN=iniPointIneRowN-whatIneRowN+1;
                        //=>
                        whatIneRowN=iniPointIneRowN-whereIneRowN+1;
                    }
                }
            }else{
                if(ExtRowsSuccessionIsReversed==false){
                    if(EachExtRowIsReversed==false){
                        // 11 21 31
                        // 12    32
                        // 13
                        //whereExtRowN=iniPointExtRowN+whatIneRowN-1;
                        //=>
                        whatIneRowN=whereExtRowN-iniPointExtRowN+1;
                        //whereIneRowN=iniPointIneRowN+whatExtRowN-1;
                        //=>
                        whatExtRowN=whereIneRowN-iniPointIneRowN+1;
                    }else{
                        // 13
                        // 12    32
                        // 11 21 31
                        //whereExtRowN=iniPointExtRowN-whatIneRowN+1;
                        //=>
                        whatIneRowN=iniPointExtRowN-whereExtRowN+1;
                        //whereIneRowN=iniPointIneRowN+whatExtRowN-1;
                        //=>
                        whereIneRowN=whatExtRowN-iniPointIneRowN+1;
                    }
                }else{
                    if(EachExtRowIsReversed==false){
                        // 31 21 11
                        // 32    12
                        //       13
                        //whereExtRowN=iniPointExtRowN+whatIneRowN-1;
                        //=>
                        whatIneRowN= whereExtRowN-iniPointExtRowN+1;
                        //whereIneRowN=iniPointIneRowN-whatExtRowN+1;
                        //=>
                        whatExtRowN=iniPointIneRowN-whereIneRowN+1;
                    }else{
                        //       13
                        // 32    12
                        // 31 21 11
                        //whereExtRowN=iniPointExtRowN-whatIneRowN+1;
                        //=>
                        whatIneRowN=iniPointExtRowN-whereExtRowN+1;
                        //whereIneRowN=iniPointIneRowN-whatExtRowN+1;
                        //=>
                        whatExtRowN=iniPointIneRowN-whereIneRowN+1;
                    }
                }
            }
            coordsWhat.set(whatExtRowN, whatIneRowN);
            return coordsWhat;
        }
        //void ConcatAdding(Array2DSize_Prototype*obj, int shiftQ=0, TDataShiftParams*ExtRows=NULL)=0;
        //
        //Coords2DInt ConcatAdding_CoordsWhereByWhat(const Coords2DInt& coords, Array2DSize_Prototype*obj, int shiftQ=0)=0;//mab virt if rules of array change str
        //Coords2DInt ConcatAdding_CoordsWhatByWhere(const Coords2DInt& coords, Array2DSize_Prototype*obj, int shiftQ=0)=0;
        //
        //void ConcatStretching(Array2DSize_Prototype*obj, int shiftQ=0, TDataShiftParams*ExtRows=NULL)=0=0;
        //
        //Coords2DInt ConcatStretching_CoordsWhereByWhat(const Coords2DInt& coords, Array2DSize_Prototype*obj, int shiftQ=0)=0;
        //Coords2DInt ConcatStretching_CoordsWhatByWhere(const Coords2DInt& coords, Array2DSize_Prototype*obj, int shiftQ=0)=0;
    //};//Array2DSize_Prototype

    //class Array2DSize_Rectangular: public Array2DSize_Prototype{
    //    int QExtRows, ExtRowLength;
    //public:
        Array2DSize_Rectangular::Array2DSize_Rectangular(int QExtRows, int ExtRowLength){
            this->QExtRows=QExtRows;
            this->ExtRowLength=ExtRowLength;
        }
        //
        //virtual
        Array2DSize_Rectangular::~Array2DSize_Rectangular(){}
        //
        //
        //
        Array2DSize_Prototype* Array2DSize_Rectangular::GetCopy(){
            //return this;
        }
        //std::vector<int> GetAsArrayOfExtRowsLengthes();
        //
        //void construct();//SeNullIni is called
        void Array2DSize_Rectangular::SetNull(){
            this->QExtRows=0;
            this->ExtRowLength=0;
        }
        void Array2DSize_Rectangular::SetNullIni(){
            this->SetNull();
        }
        void Array2DSize_Rectangular::SetOne(){
            this->QExtRows=1;
            this->ExtRowLength=1;
        }
        //
        int  Array2DSize_Rectangular::GetTypeN(){
            return Array2DSize_Rectangular_TypeN;
        }
        //
        void Array2DSize_Rectangular::Assign(Array2DSize_Prototype*obj){
            this->ExtRowLength=obj->GetRowLengthMax();
            this->QExtRows=obj->GetQExtRows();
        }
        //
        void Array2DSize_Rectangular::Set(int* extRowsLengthes, int QExtRows){
            this->QExtRows=QExtRows;
            if(extRowsLengthes!=NULL){
                this->ExtRowLength=extRowsLengthes[1-1];
            }else{
                this->ExtRowLength=0;
            }
        }
        void Array2DSize_Rectangular::Set(int extRowsLength, int QExtRows){
            this->ExtRowLength=extRowsLength;
            this->QExtRows=QExtRows;
        }//may descr it generally or may leave it virtual
        //
        int Array2DSize_Rectangular::GetQExtRows() const {
            return this->QExtRows;
        }
        int Array2DSize_Rectangular::GetRowLength(int N) const {
            return this->ExtRowLength;
        }
        int Array2DSize_Rectangular::GetRowLengthMin() const{
            return this->ExtRowLength;
        }
        int Array2DSize_Rectangular::GetRowLengthMax() const{
            return this->ExtRowLength;
        }
        //std::vector<int> Array2DSize_Rectangular::GetLengthes() const;
        //std::vector<int> Array2DSize_Rectangular::GetMinLengthRowNs() const;
        //std::vector<int> Array2DSize_Rectangular::GetMaxLengthRowNs() const;
        int Array2DSize_Rectangular::GetQElements() const{
            return this->QExtRows*this->ExtRowLength;
        }
        //virtual Array2DSize_Prototype*GetSize_asPtr() const =0;
        //
        //int Array2DSize_Rectangular::Arr2DBy1D_PosNByCoords(int ExtRowN, int IneRowN) const{}
        //Coords2DInt Array2DSize_Rectangular::Arr2DBy1D_CoordsByPosN(int PosN) const{}
        //int Arr2DBy1D_ExtRowNByPosN(int PosN) const;
        //int Arr2DBy1D_IneRowNByPosN(int PosN) const;
        //
        bool Array2DSize_Rectangular::IsRectangularByType() const{
            return true;
        }
        bool Array2DSize_Rectangular::IsRectangularInFact() const{
            return true;
        }
        bool Array2DSize_Rectangular::IsEmpty() const{
            return(this->QExtRows==0 || this->ExtRowLength==0);
        }
        //int Array2DSize_Rectangular::GetTypeN() const{}
        //
        int Array2DSize_Rectangular::SetRowLength(int L, int N, int ifNotEqual_Ignore0Old1New2Max3Min4){

        }
        int Array2DSize_Rectangular::SetQExtRows(int Q, int IfNotRect_ERL_ByMin1ByMax2ByLast3){

        }
        //
        void Array2DSize_Rectangular::SetExtRow(int RowN, int L, TDataShiftParams*DataShiftParams, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4){
            TDataShiftParams DataShiftParam;
            if(DataShiftParams!=NULL){
                DataShiftParam=(*(DataShiftParams));
            }
            TDataShiftResults dataLen=DataShiftParam.Calc(L);
            int Lmod=dataLen.Lcalc, p=ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4;
            if(Lmod!=this->GetRowLengthMax()){
                if(p==2 || (Lmod>this->ExtRowLength && p==3) || (Lmod<this->ExtRowLength && p==4)){
                    this->ExtRowLength=Lmod;
                }
            }
        }
        //
        //Coords2DInt SetExtRow_CoordsByElementN(int ElementN, int RowN, int L=0, TDataShiftParams*DataShiftParams=NULL, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1);
        //
        void Array2DSize_Rectangular::AddExtRow(         int L, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4, TDataShiftParams*DataShiftParams){

        }
        //
        //Coords2DInt AddExtRow_CoordsByElementN(int ElementN,       int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL);
        //int AddExtRow_ElementNByCoords(const Coords2DInt& coords,  int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL);
        //
        void Array2DSize_Rectangular::InsExtRow(int N, int L, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4, TDataShiftParams*DataShiftParams){

        }
        //
        //Coords2DInt InsExtRow_CoordsByElementN(    int ElementN,        int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL);
        //int InsExtRow_ElementNByCoords(      const Coords2DInt& coords, int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL);
        //Coords2DInt InsExtRow_CoordsOldByNew(const Coords2DInt& coords, int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL);
        //Coords2DInt InsExtRow_CoordsNewByOld(const Coords2DInt& coords, int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL);
        //
        void Array2DSize_Rectangular::DelExtRow(int N){

        }
        //
        //Coords2DInt DelExtRow_CoordsOldByNew(const Coords2DInt& coords, int N=-1);//no need
        //Coords2DInt DelExtRow_CoordsNewByOld(const Coords2DInt& coords, int N=-1);//no need
        //
        void Array2DSize_Rectangular::AddIneRow(int L, int IfNotSameQER_ByOld1ByNew2ByMax3ByMin4, TDataShiftParams*DataShiftParams){

        }
        //
        //Coords2DInt AddIneRow_CoordsByElementN(int ElementN,      int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL);
        //int AddIneRow_ElementNByCoords(const Coords2DInt& coords, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1, TDataShiftParams*DataShiftParams=NULL);
        //
        void Array2DSize_Rectangular::InsIneRow(int N, int L, int IfNotSameQER_ByOld1ByNew2ByMax3ByMin4, TDataShiftParams*DataShiftParams){

        }
        //
        //Coords2DInt InsIneRow_CoordsByElementN(    int ElementN,        int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1);
        //int InsIneRow_ElementNByCoords(      const Coords2DInt& coords, int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1);
        //Coords2DInt InsIneRow_CoordsOldByNew(const Coords2DInt& coords, int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1);
        //Coords2DInt InsIneRow_CoordsNewByOld(const Coords2DInt& coords, int N=0, int L=0, int ifRectangularAndNotEqual_Default0ByOld1ByNew2ByMax3ByMin4=1);
        //
        void Array2DSize_Rectangular::DelIneRow(int N){

        }
        //
        //Coords2DInt DelIneRow_CoordsOldByNew(const Coords2DInt& coords, int N=-1);//no need
        //Coords2DInt DelIneRow_CoordsNewByOld(const Coords2DInt& coords, int N=-1);//no need
        //
        //
        void Array2DSize_Rectangular::AddOrInsToExtRowN(int N){

        }
        void Array2DSize_Rectangular::DelFromExtRowN(int N){

        }
        //
        void Array2DSize_Rectangular::SwapExtRows(int N1, int N2){
            //NOp;
        }
        //void SwapIneRows(int N1, int N2)=0;//No need
        void Array2DSize_Rectangular::ReverseExtRowsSuccession(){

        }
        //void Array2DSize_Rectangular::ShiftExtRowsCyclelyToBegin(){}
        //void Array2DSize_Rectangular::ShiftExtRowsCyclelyToEnd(){}
        //
        //bool IsForTranspose() const;
        //
        void Array2DSize_Rectangular::Transpose(){
            int buf=this->QExtRows;
            this->QExtRows=this->ExtRowLength;
            this->ExtRowLength=buf;
        }
        //Coords2DInt Transpose_CoordsAftByBef(const Coords2DInt& coords);
        //Coords2DInt Transpose_CoordsBefByAft(const Coords2DInt& coords);
        //
        //int GetLengthOfIneRowN_FromFirstNoEmptyPoss(int N=-1) const;
        //
        //void Array2DSize_Rectangular::ConcatAdding(Array2DSize_Prototype*obj, int shiftQ){}
        //void Array2DSize_Rectangular::ConcatStretching(Array2DSize_Prototype*obj, int shiftQ){}
        //
        //Coords2DInt ConcatAdding_CoordsWhereByWhat(const Coords2DInt& coords, Array2DSize_Prototype*obj, int shiftQ=0);//mab virt if rules of array change str
        //Coords2DInt ConcatAdding_CoordsWhatByWhere(const Coords2DInt& coords, Array2DSize_Prototype*obj, int shiftQ=0);
        //Coords2DInt ConcatStretching_CoordsWhereByWhat(const Coords2DInt& coords, Array2DSize_Prototype*obj, int shiftQ=0);
        //Coords2DInt ConcatStretching_CoordsWhatByWhere(const Coords2DInt& coords, Array2DSize_Prototype*obj, int shiftQ=0);
        //
        //virtual void SubArray(const Coords2DInt& IniPoint, Array2DSize_Prototype*subArrSize, bool IsTransposed=false, bool ExtRowsSuccessionIsReversed=false, bool EachExtRowIsReversed=false, TDataShiftParams*ExtRows=NULL)=0;
        std::vector<int>  Array2DSize_Rectangular::SubArrayTo(const Coords2DInt& IniPoint, Array2DSize_Prototype*subArrSize, bool IsTransposed, bool ExtRowsSuccessionIsReversed, bool EachExtRowIsReversed, TDataShiftParams*ExtRows){

        }
        //
        //Coords2DInt SubArray_CoordsWhereByWhat(const Coords2DInt& coordsGiven, const Coords2DInt& IniPoint, const TDataShiftParams&DataShift, Array2DSize_Prototype*objDflt, bool IsTransposed=false, bool ExtRowsSuccessionIsReversed=false, EachExtRowIsReversed=false, TDataShiftParams*ExtRows=NULL);
        //Coords2DInt SubArray_CoordsWhatByWhere(const Coords2DInt& coordsGiven, const Coords2DInt& IniPoint, const TDataShiftParams&DataShift, Array2DSize_Prototype*objDflt, bool IsTransposed=false, bool ExtRowsSuccessionIsReversed=false, EachExtRowIsReversed=false, TDataShiftParams*ExtRows=NULL);
        //
        void Array2DSize_Rectangular::ConcatAdding(Array2DSize_Prototype*size2, int shiftQ, TDataShiftParams*ExtRows){
            std::vector<int>Ls1,
                            Ls2Ini=size2->GetAsArrayOfExtRowsLengthes(),
                            Ls2Mod=Arr1D_GetSubArr_ByLs(Ls2Ini.data(), Ls2Ini.size(), ExtRows),
                            LsR;
            int L1=this->GetRowLengthMax(), L2=size2->GetRowLengthMax(), Q3=Ls2Mod.size();
            if(shiftQ>=0){
                if(shiftQ+L2>L1){
                    this->ExtRowLength=shiftQ+L2;
                }
            }else{
                if(-shiftQ+L1<L2){
                    this->ExtRowLength=L2;
                }else{
                    this->ExtRowLength=-shiftQ+L1;
                }
            }
            this->QExtRows+=Q3;
        }
        //
        Coords2DInt Array2DSize_Rectangular::ConcatAdding_Coords1To3(const Coords2DInt& coords, Array2DSize_Prototype*size2, int shiftQ, TDataShiftParams*ExtRows){
            Coords2DInt coordsR;
            int ExtRowN=coords.x, ineRowN=coords.y, QER1=this->GetQExtRows(), QER2=size2->GetQExtRows();
            if(coords.x>=1 && coords.x<=QER1 && coords.y>=1 && coords.y<=this->GetRowLength(coords.x)){
                if(shiftQ>=0){
                    coordsR.y=coords.y;
                }else{
                    coordsR.y=coords.y-shiftQ;//ob negative
                }
                coordsR.x=coords.x;
            }
            return coordsR;
        }
        Coords2DInt Array2DSize_Rectangular::ConcatAdding_Coords3To1(const Coords2DInt& coords, Array2DSize_Prototype*size2, int shiftQ, TDataShiftParams*ExtRows){
            Coords2DInt coordsR;
            int ExtRowN=coords.x, ineRowN=coords.y;
            if(shiftQ>=0){
                coordsR=coords;
            }else{
                ineRowN-=shiftQ;//ob negative
                coordsR.y=ineRowN;
            }
            return coordsR;
        }
        Coords2DInt Array2DSize_Rectangular::ConcatAdding_Coords2To3(const Coords2DInt& coords, Array2DSize_Prototype*size2, int shiftQ, TDataShiftParams*ExtRows){
            Coords2DInt coordsR;
            int ExtRowN=coords.x, ineRowN=coords.y, QER1=this->GetQExtRows(), QER2=size2->GetQExtRows();
            if(coords.x>=1 && coords.x<=QER2 && coords.y>=1 && coords.y<=size->GetRowLength(coords.x)){
                if(shiftQ>=0){
                    coordsR.y=coords.y+shiftQ;
                }else{
                    coordsR.y=coords.y;
                }
                coordsR.x=coords.x+QER1;
            }
            return coordsR;
        }
        Coords2DInt Array2DSize_Rectangular::ConcatAdding_Coords3To2(const Coords2DInt& coords, Array2DSize_Prototype*size2, int shiftQ, TDataShiftParams*ExtRows){
            Coords2DInt coordsR;
            int ExtRowN=coords.x, ineRowN=coords.y, QER1=this->GetQExtRows(), QER2=size2->GetQExtRows();
            if(coords.x>=1 && coords.x<=QER2 && coords.y>=1 && coords.y<=size->GetRowLength(coords.x)){
                if(shiftQ>=0){
                    coordsR.y=coords.y+shiftQ;
                }else{
                    coordsR.y=coords.y;
                }
                coordsR.x=coords.x+QER1;
            }
            return coordsR;
        }
        //
        void Array2DSize_Rectangular::ConcatStretching(Array2DSize_Prototype*size2, int shiftQ, TDataShiftParams*ExtRows){
            std::vector<int>Ls1,
                            Ls2Ini=size2->GetAsArrayOfExtRowsLengthes(),
                            Ls2Mod=Arr1D_GetSubArr_ByLs(Ls2Ini.data(), Ls2Ini.size(), ExtRows),
                            LsR;
            int L1=this->GetRowLengthMax(), L2=size2->GetRowLengthMax(), Q1=this->GetQExtRows(), Q3=Ls2Mod.size();
            if(shiftQ>=0){
                if(shiftQ+Q3>Q1){
                    this->QExtRows=shiftQ+Q3;
                }
            }else{
                if(-shiftQ+Q1<Q3){
                    this->QExtRows=Q3;
                }else{
                    this->QExtRows=-shiftQ+Q1;
                }
            }
            this->QExtRows+=L2;
        }
        //
        Coords2DInt Array2DSize_Rectangular::ConcatStretching_Coords1To3(const Coords2DInt& coords, Array2DSize_Prototype*size2, int shiftQ, TDataShiftParams*ExtRows){
            Coords2DInt coordsR;
            std::vector<int>Ls1,
                            Ls2Ini=size2->GetAsArrayOfExtRowsLengthes(),
                            Ls2Mod=Arr1D_GetSubArr_ByLs(Ls2Ini.data(), Ls2Ini.size(), ExtRows),
                            LsR;
            int ExtRowN1=coords.x, IneRowN1=coords.y, QER1=this->GetQExtRows(), QER2=size2->GetQExtRows();
            int L1=this->GetRowLengthMax(), L2=size2->GetRowLengthMax(), Q1=this->GetQExtRows(), Q3=Ls2Mod.size();
            if(coords.x>=1 && coords.x<=QER1 && coords.y>=1 && coords.y<=this->GetRowLength(coords.x)){
                if(shiftQ>=0){
                    coordsR.y=coords.y+this->Get;
                }else{
                    coordsR.y=coords.y-shiftQ;//+, but nergative
                }
                coordsR.x=coords.x;
            }
        }
        Coords2DInt Array2DSize_Rectangular::ConcatStretching_Coords2To3(const Coords2DInt& coords, Array2DSize_Prototype*size2, int shiftQ, TDataShiftParams*ExtRows){
            Coords2DInt coordsR;
            std::vector<int>Ls1,
                            Ls2Ini=size2->GetAsArrayOfExtRowsLengthes(),
                            Ls2Mod=Arr1D_GetSubArr_ByLs(Ls2Ini.data(), Ls2Ini.size(), ExtRows),
                            LsR;
            int ExtRowN1=coords.x, IneRowN1=coords.y, QER1=this->GetQExtRows(), QER2=size2->GetQExtRows();
            int L1=this->GetRowLengthMax(), L2=size2->GetRowLengthMax(), Q1=this->GetQExtRows(), Q3=Ls2Mod.size();
            if(coords.x>=1 && coords.x<=QER2 && coords.y>=1 && coords.y<=size2->GetRowLength(coords.x)){
                if(shiftQ>=0){
                    coordsR.y=coords.y;
                }else{
                    coordsR.y=coords.y-shiftQ;//+, but nergative
                }
                coordsR.x=QER1+coords.x;
            }
        }
        Coords2DInt Array2DSize_Rectangular::ConcatStretching_Coords2To3(const Coords2DInt& coords, Array2DSize_Prototype*size2, int shiftQ, TDataShiftParams*ExtRows){

        }
        Coords2DInt Array2DSize_Rectangular::ConcatStretching_Coords3To2(const Coords2DInt& coords, Array2DSize_Prototype*size2, int shiftQ, TDataShiftParams*ExtRows){

        }
    //};//Array2DSize_Rectangular
