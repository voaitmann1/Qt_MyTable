#include "matrica.h"

int GetPositionNInArray2DRectRealizedAs1D(int ExtRowN, int IneRowN, int QExtRows, int QIneRows){
    int PosN=0, L;
    if(ExtRowN<0){
        ExtRowN+=(QExtRows+1);
    }
    if(IneRowN<0){
        IneRowN+=(QIneRows+1);
    }
    if(ExtRowN>=1 && ExtRowN<=QExtRows && IneRowN>=1 && IneRowN<=QIneRows){
        for(int i=1; i<=ExtRowN-1; i++){
            L=QIneRows;
            PosN+=L;
        }
        PosN+=IneRowN;
    }
    return PosN;
}
//=============================================================================================================================================================
//class Array2DRect_Test_Int_Simple{
//     Array2D_Test_Int_Simple<int>data;
//public:
     Array2DRect_Test_Int_Simple::Array2DRect_Test_Int_Simple(){
        this->construct();
     }
     Array2DRect_Test_Int_Simple::Array2DRect_Test_Int_Simple(std::vector<int>data, int QLines, int QColumns){
         this->construct();
         //this->data.Set();//later swi I lif ce geqy
     }

     Array2DRect_Test_Int_Simple::Array2DRect_Test_Int_Simple(std::vector<std::vector<int>>data){
        this->construct();
     }

     Array2DRect_Test_Int_Simple::Array2DRect_Test_Int_Simple(int val, int QLines, int QColumns){
        this->construct();
     }

     Array2DRect_Test_Int_Simple::Array2DRect_Test_Int_Simple(const Array2DRect_Test_Int_Simple&obj){
         this->construct();
         this->Assign(obj);
     }
     Array2DRect_Test_Int_Simple::~Array2DRect_Test_Int_Simple(){
         //noid fy amda
     }
     //void A(const TArray2D_Rect_Simple_Prototype<T>&obj);
     //void Array2DRect_Test_Int_Simple::Assign(TArray2D_Rect_Simple_Prototype<T>*obj);
     void Array2DRect_Test_Int_Simple::Assign(const Array2DRect_Test_Int_Simple&obj){
         this->data=obj.data;
     }

     Array2DRect_Test_Int_Simple&  Array2DRect_Test_Int_Simple::operator = (const Array2DRect_Test_Int_Simple&obj){
         this->Assign(obj);
         return *this;
     }

     int  Array2DRect_Test_Int_Simple::GetTypeN(){
         return this->data.GetTypeN();
     }
     void  Array2DRect_Test_Int_Simple::SetTypeN(int TypeN){
         this->data.SetTypeN(DataType_int_N);//S lif: required from here
     }
     void  Array2DRect_Test_Int_Simple::construct(){
         this->SetTypeN(DataType_int_N);
     }
     //virtual void construct()=0; et ei atal...
     void Array2DRect_Test_Int_Simple::SetNull(){
         this->data.SetNull();
     }

     void Array2DRect_Test_Int_Simple::SetOne(int  val){
         this->data.SetOne(val);
     }

     int Array2DRect_Test_Int_Simple::PosNOf(int LineN, int ColN)const{}
     int Array2DRect_Test_Int_Simple::GetQExtRows()const{}
     int Array2DRect_Test_Int_Simple::GetQIneRows()const{}
     int Array2DRect_Test_Int_Simple::GetQLines()const{}
     int Array2DRect_Test_Int_Simple::GetQColumns()const{}
     void Array2DRect_Test_Int_Simple::SetSize_EIR(int QExtRows, int QIneRows){}
     void Array2DRect_Test_Int_Simple::SetSize(int QLines, int QColumns){}
     //
     void Array2DRect_Test_Int_Simple::Set_EIR(std::vector<int>data, int QExtRows, int QIneRows){}
     void Array2DRect_Test_Int_Simple::Set_EIR(std::vector<std::vector<int>>data){}
     void Array2DRect_Test_Int_Simple::Set_EIR(int QExtRows, int QIneRows, int val){}
     void Array2DRect_Test_Int_Simple::Set(int QLines, int QColumns, int val){}
     void Array2DRect_Test_Int_Simple::Set_Lines(std::vector<int>data, int QLines, int QColumns){}
     void Array2DRect_Test_Int_Simple::Set_Lines(std::vector<std::vector<int>>data){}
     //void Set_Lines(const T&val, int QLines, int QColumns);
     void Array2DRect_Test_Int_Simple::Set_Columns(std::vector<int>data, int QLines, int QColumns){}
     void Array2DRect_Test_Int_Simple::Set_Columns(std::vector<std::vector<int>>data){}
     //void Set_Columns(const T&val, int QLines, int QColumns);
     //void Set(const Matrix_V1S_Lines_Simple&obj);
     //
     void Array2DRect_Test_Int_Simple::SetVal_EIR(int ExtRowN, int IneRowN, int val){}
     void Array2DRect_Test_Int_Simple::SetVal(int LineN, int ColumnN, int val){}
     //ComplexNum& GetVal_EIR(int ExtRowN, int IneRowN)const;
     int Array2DRect_Test_Int_Simple::GetVal_EIR(int ExtRowN, int IneRowN)const{}
     //ComplexNum& GetVal(int LineN, int ColumnN)const;
     int Array2DRect_Test_Int_Simple::GetVal(int LineN, int ColumnN)const{}
     std::vector<int> Array2DRect_Test_Int_Simple::GetExtRowN(int N)const{}
     std::vector<int> Array2DRect_Test_Int_Simple::GetLineN(int N)const{}
     std::vector<int> Array2DRect_Test_Int_Simple::GetIneRowN(int N)const{}
     std::vector<int> Array2DRect_Test_Int_Simple::GetColumnN(int N)const{}
     std::vector<int> Array2DRect_Test_Int_Simple::GetContent_ExtRows()const{}
     std::vector<int> Array2DRect_Test_Int_Simple::GetContent_Lines()const{}
     std::vector<int> Array2DRect_Test_Int_Simple::GetContent_Columns()const{}
     //
     //
     void Array2DRect_Test_Int_Simple::SwapVals_EIR(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2){}
     void Array2DRect_Test_Int_Simple::SwapVals(int LineN1, int ColN1, int LineN2, int ColN2){}
     void Array2DRect_Test_Int_Simple::SwapExtRows(int ExtRowN1, int ExtRowN2){}
     void Array2DRect_Test_Int_Simple::SwapIneRows(int IneRowN1, int IneRowN2){}
     void Array2DRect_Test_Int_Simple::SwapLines(int LineN1, int LineN2){}
     void Array2DRect_Test_Int_Simple::SwapColumns(int ColN1, int ColN2){}
     //
     //
     void Array2DRect_Test_Int_Simple::SetExtRow_Simple(int N, int*row, int rowL, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4){}
     void Array2DRect_Test_Int_Simple::SetLine_Simple(int N, int*row, int rowL, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4){}
     void Array2DRect_Test_Int_Simple::SetIneRow_Simple(int N, int*row, int rowL, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4){}
     void Array2DRect_Test_Int_Simple::SetColumn_Simple(int N, int*row, int rowL, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4){}
     //
     void Array2DRect_Test_Int_Simple::AddExtRow_Simple(int*row, int rowL, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4){}
     void Array2DRect_Test_Int_Simple::AddLine_Simple(int*row, int rowL, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4){}
     void Array2DRect_Test_Int_Simple::AddIneRow_Simple(int*row, int rowL, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4){}
     void Array2DRect_Test_Int_Simple::AddColumn_Simple(int*row, int rowL, int IfLNE_Ignore0_ByOld1_ByNew2_ByMax3_ByMin4){}
     //
     void Array2DRect_Test_Int_Simple::InsExtRow_Simple(int N, int*row){}
     void Array2DRect_Test_Int_Simple::InsLine_Simple(int N, int*row){}
     void Array2DRect_Test_Int_Simple::InsIneRow_Simple(int N, int*row){}
     void Array2DRect_Test_Int_Simple::InsColumn_Simple(int N, int*row){}
     //
     void Array2DRect_Test_Int_Simple::DelExtRow_Simple(int N){}
     void Array2DRect_Test_Int_Simple::DelLine_Simple(int N){}
     void Array2DRect_Test_Int_Simple::DelIneRow_Simple(int N){}
     void Array2DRect_Test_Int_Simple::DelColumn_Simple(int N){}
     //
     //
     //TArray2D_Rect_Simple_Prototype<T> SubMatrix_EIR(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
     //TArray2D_Rect_Simple_Prototype<T> SubMatrix(int LineN1, int ColumnN1, int LineN2, int ColumnN2);
     ////Matrix_V1S_Lines_Simple SubMatrix_EIR(int ExtRowN1, int QExtRows, int QEmptyExtRowsBefore);
     ////Matrix_V1S_Lines_Simple SubMatrix_Lines(int LineN1, int QLines, int QEmptyLinesBefore);
     ////Matrix_V1S_Lines_Simple SubMatrix_Columns(int ColN1, int QCols, int QEmptyColsBefore);
     //
     //
     Array2DRect_Test_Int_Simple Array2DRect_Test_Int_Simple::GetExtRowN_AsArray2DRect(int N)const{}
     Array2DRect_Test_Int_Simple Array2DRect_Test_Int_Simple::GetLineN_AsArray2DRect(int N)const{}
     Array2DRect_Test_Int_Simple Array2DRect_Test_Int_Simple::GetIneRowN_AsArray2DRect(int N)const{}
     Array2DRect_Test_Int_Simple Array2DRect_Test_Int_Simple::GetColumnN_AsArray2DRect(int N)const{}
     //
     //
     Array2DRect_Test_Int_Simple Array2DRect_Test_Int_Simple::SubMatrix_EIR(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2){}
     Array2DRect_Test_Int_Simple Array2DRect_Test_Int_Simple::SubMatrix(int LineN1, int ColumnN1, int LineN2, int ColumnN2){}
     ////Matrix_V1S_Lines_Simple SubMatrix_EIR(int ExtRowN1, int QExtRows, int QEmptyExtRowsBefore);
     ////Matrix_V1S_Lines_Simple SubMatrix_Lines(int LineN1, int QLines, int QEmptyLinesBefore);
     ////Matrix_V1S_Lines_Simple SubMatrix_Columns(int ColN1, int QCols, int QEmptyColsBefore);
     //
     void Array2DRect_Test_Int_Simple::StdCout_ExtRowN(int N, std::string delim, bool showBrackets, bool RepresentVertNotHor){}
     void Array2DRect_Test_Int_Simple::StdCout_IneRowN(int N, std::string delim, bool showBrackets, bool RepresentVertNotHor){}
     void Array2DRect_Test_Int_Simple::StdCout_LineN(int N, std::string delim, bool showBrackets,  bool RepresentVertNotHor){}
     void Array2DRect_Test_Int_Simple::StdCout_ColN(int N, std::string delim, bool showBrackets, bool Represent2DNot1D){}
     void Array2DRect_Test_Int_Simple::StdCout_EIR(std::string delimElem, std::string delimRow, bool showBrackets, bool Represent2DNot1D, bool HorExt){}
     void Array2DRect_Test_Int_Simple::StdCout(std::string delimElem, std::string delimRow, bool showBrackets, bool Represent2DNot1D){}
//};

//==============================================================================================================================================================


Matrix_V1S_Lines_Simple::Matrix_V1S_Lines_Simple(){

}
Matrix_V1S_Lines_Simple::Matrix_V1S_Lines_Simple(std::vector<ComplexNum>data, int QLines, int QColumns){

}
Matrix_V1S_Lines_Simple::Matrix_V1S_Lines_Simple(std::vector<std::vector<ComplexNum>>data){

}
Matrix_V1S_Lines_Simple::Matrix_V1S_Lines_Simple(const ComplexNum&val, int QLines, int QColumns){

}
Matrix_V1S_Lines_Simple::Matrix_V1S_Lines_Simple(std::vector<double>data, int QLines, int QColumns){

}
Matrix_V1S_Lines_Simple::Matrix_V1S_Lines_Simple(std::vector<std::vector<double>>data){

}
Matrix_V1S_Lines_Simple::Matrix_V1S_Lines_Simple(double val, int QLines, int QColumns){

}
Matrix_V1S_Lines_Simple::Matrix_V1S_Lines_Simple(const Matrix_V1S_Lines_Simple&obj){

}
Matrix_V1S_Lines_Simple::~Matrix_V1S_Lines_Simple(){

}
void Matrix_V1S_Lines_Simple::Assign(const Matrix_V1S_Lines_Simple&obj){
    ComplexNum val;
    int QExtRows=obj.GetQExtRows(), QIneRows=obj.GetQIneRows();
    this->SetSize_EIR(QExtRows, QIneRows);
    for(int i=1; i<=QExtRows; i++){
        for(int j=1; j<=QIneRows; j++){
            val=obj.GetVal_EIR(i, j);
            this->SetVal_EIR(val, i, j);
        }
    }
}
Matrix_V1S_Lines_Simple& Matrix_V1S_Lines_Simple::operator = (const Matrix_V1S_Lines_Simple&obj){

}
void Matrix_V1S_Lines_Simple::construct(){
    this->SetNull();
}
void Matrix_V1S_Lines_Simple::SetNull(){
    this->data.clear();
    this->QLines=0;
}
void Matrix_V1S_Lines_Simple::SetOne(double Re, double Im){
    ComplexNum num(Re, Im);
    this->SetNull();
    this->data.push_back(num);
    this->QLines=1;
}
int Matrix_V1S_Lines_Simple::PosNOfEIR(int ExtRowN, int IneRowN)const{
    int PosN=0, QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows(), L;//, QColumns=QIneRows, N, L;
    if(ExtRowN>=1 && ExtRowN<=QExtRows && IneRowN>=1 && IneRowN<=QIneRows){
        for(int i=1; i<=ExtRowN-1; i++){
            L=QIneRows;
            PosN+=L;
        }
        PosN+=IneRowN;
    }
    return PosN;
}
int Matrix_V1S_Lines_Simple::PosNOf(int LineN, int ColN)const{
    int ExtRowN=LineN, IneRowN=ColN, PosN=0;
    PosN=this->PosNOfEIR(ExtRowN, IneRowN);
    return PosN;
}
int Matrix_V1S_Lines_Simple::GetQExtRows()const{
    return this->QLines;
}
int Matrix_V1S_Lines_Simple::GetQIneRows()const{
    int QElements=this->data.size(), QExtRows=this->GetQExtRows();
    int QIneRows=QElements/QExtRows;
    return QIneRows;
}
int Matrix_V1S_Lines_Simple::GetQLines()const{
    return this->QLines;
}
int Matrix_V1S_Lines_Simple::GetQColumns()const{
    return this->GetQIneRows();
}

void Matrix_V1S_Lines_Simple::SetSize_EIR(int QExtRows, int QIneRows){
    ComplexNum val;//(0, 0) by default
    this->data.clear();
    for(int i=1; i<=QExtRows; i++){
        for(int j=1; j<=QIneRows; j++){
            this->data.push_back(val);
        }
    }
    this->QLines=QExtRows;
}
void Matrix_V1S_Lines_Simple::SetSize(int QLines, int QColumns){
    int QExtRows=QLines, QIneRows=QColumns;
    this->SetSize_EIR(QExtRows, QIneRows);
}
void Matrix_V1S_Lines_Simple::Set_EIR(std::vector<ComplexNum>data, int QExtRows, int QIneRows){
    int L, count, QElements=data.size();
    ComplexNum defaultVal, curVal;//by default (0; 0)
    this->SetNull();
    this->SetSize_EIR(QExtRows, QIneRows);
    for(int i=1; i<=QExtRows; i++){
        L=QIneRows;
        for(int j=1; j<=L; j++){
            count++;
            if(count>QElements){
                this->SetVal_EIR(defaultVal, i, j);
            }else{
                curVal=data[count-1];
                this->SetVal_EIR(curVal, i, j);
            }
        }
    }
    QLines=QExtRows;
}
void Matrix_V1S_Lines_Simple::Set_EIR(std::vector<std::vector<ComplexNum>>data){
    int QExtRows=data.size(), curL, count, Lmin, Lmax;
    ComplexNum curVal, dafaultVal;//by default (0, 0)
    for(int i=1; i<=QExtRows; i++){
        curL=data[i-1].size();
        if(i==1 && (i>1 && curL>Lmax)){
            Lmax=curL;
        }
    }
    this->SetSize_EIR(QExtRows, Lmax);
    for(int i=1; i<=QExtRows; i++){
        curL=data[i-1].size();
        for(int j=1; j<=curL; j++){
            curVal=data[i-1][j-1];
            this->SetVal_EIR(curVal, i, j);
        }
        for(int j=curL+1; j<=Lmax; j++){
            this->SetVal_EIR(dafaultVal, i, j);
        }
    }
}
void Matrix_V1S_Lines_Simple::Set_EIR(const ComplexNum&val, int QExtRows, int QIneRows){
    this->SetSize_EIR(QExtRows, QIneRows);
    for(int i=1; i<=QExtRows; i++){
        for(int j=1; j<=QExtRows; j++){
            this->SetVal_EIR(val, i, j);
        }
    }
}
void Matrix_V1S_Lines_Simple::Set_EIR(std::vector<double>data, int QExtRows, int QIneRows){
    ComplexNum val;
    int PosN;
    double re, im=0;
    this->SetSize_EIR(QExtRows, QIneRows);
    for(int i=1; i<=QExtRows; i++){
        for(int j=1; j<=QExtRows; j++){
            PosN=this->PosNOfEIR(i, j);
            re=data[PosN-1];
            val.SetDecart(re, im);
            this->SetVal_EIR(val, i, j);
        }
    }
}
void Matrix_V1S_Lines_Simple::Set_EIR(std::vector<std::vector<double>>data){
    int QExtRows=data.size(), QIneRows, curL, maxL;
    ComplexNum val;
    double re, im;
    for(int i=1; i<=QExtRows; i++){
        curL=data[i-1].size();
        if(i==1 || (i>1 && curL>maxL)){
            maxL=curL;
        }
    }
    QIneRows=maxL;
    this->SetSize_EIR(QExtRows, QIneRows);
    for(int i=1; i<=QExtRows; i++){
        curL=data[i-1].size();
        for(int j=1; j<=curL; j++){
            re=data[i-1][j-1];
            val.SetDecart(re, im);
            this->SetVal_EIR(val, i, j);
        }
        for(int j=curL+1; j<=QIneRows; j++){
            re=0;
            val.SetDecart(re, im);
            this->SetVal_EIR(val, i, j);
        }
    }
}
void Matrix_V1S_Lines_Simple::Set_EIR(double val, int QExtRows, int QIneRows){
    ComplexNum cVal;
    int PosN;
    double re, im=0;
    this->SetSize_EIR(QExtRows, QIneRows);
    for(int i=1; i<=QExtRows; i++){
        for(int j=1; j<=QExtRows; j++){
            re=val;
            cVal.SetDecart(re, im);
            this->SetVal_EIR(cVal, i, j);
        }
    }
}
void Matrix_V1S_Lines_Simple::Set_Lines(std::vector<ComplexNum>data, int QLines, int QColumns){
    int QExtRows=QLines, QIneRows=QColumns;
    this->Set_EIR(data, QExtRows, QIneRows);
}
void Matrix_V1S_Lines_Simple::Set_Lines(std::vector<std::vector<ComplexNum>>data){
    this->Set_EIR(data);
}
void Matrix_V1S_Lines_Simple::Set_Lines(const ComplexNum&val, int QLines, int QColumns){
    int QExtRows=QLines, QIneRows=QColumns;
    this->Set_EIR(val, QExtRows, QIneRows);
}
void Matrix_V1S_Lines_Simple::Set_Lines(std::vector<double>data, int QLines, int QColumns){
    int QExtRows=QLines, QIneRows=QColumns;
    this->Set_EIR(data, QExtRows, QIneRows);
}
void Matrix_V1S_Lines_Simple::Set_Lines(std::vector<std::vector<double>>data){
    this->Set_EIR(data);
}
void Matrix_V1S_Lines_Simple::Set_Lines(double val, int QLines, int QColumns){
    int QExtRows=QLines, QIneRows=QColumns;
    this->Set_EIR(val, QExtRows, QIneRows);
}
void Matrix_V1S_Lines_Simple::Set_Columns(std::vector<ComplexNum>data, int QLines, int QColumns){
    ComplexNum curVal, dfltVal;
    int count=0, PosN;
    this->SetSize(QLines, QColumns);
    //
    for(int j=1; j<=QColumns; j++){
        for(int i=1; i<=QLines; i++){
            count++;
            PosN=this->PosNOf(j, i);
            curVal=data[PosN-1];//also possible
            curVal=data[count-1];
            this->SetVal(curVal, i, j);
        }
    }
}
void Matrix_V1S_Lines_Simple::Set_Columns(std::vector<std::vector<ComplexNum>>data){
    ComplexNum curVal, dfltVal;
    int QColumns=data.size(), QLines, maxL, curL;
    for(int i=1; i<=QColumns; i++){
        curL=data[i-1].size();
        if(i==1 || (i>1 && curL>maxL)){
            maxL=curL;
        }
    }
    QLines=maxL;
    this->SetSize(QLines, QColumns);
    for(int i=1; i<=QColumns; i++){
        curL=data.size();
        for(int j=1; j<=curL; j++){
            curVal=data[i-1][j-1];
            this->SetVal(curVal, j, i);
        }
        for(int j=curL+1; j<=QLines; j++){
            this->SetVal(dfltVal, j, i);
        }
    }
    this->QLines-QLines;
}
void Matrix_V1S_Lines_Simple::Set_Columns(const ComplexNum&val, int QLines, int QColumns){
    //ComplexNum curVal(val, 0);
    this->SetSize(QLines, QColumns);
    for(int i=1; i<=QLines; i++){
        for(int j=1; j<=QColumns; j++){
            this->SetVal(val, i, j);
        }
    }
}
void Matrix_V1S_Lines_Simple::Set_Columns(std::vector<double>data, int QLines, int QColumns){
    ComplexNum cVal;
    double rVal;
    int count=0, QElements=data.size();
    this->SetSize(QLines, QColumns);
    for(int j=1; j<=QColumns; j++){
        for(int i=1; i<=QLines; i++){
            count++;
            if(count>QElements){
                rVal=0;
            }else{
                rVal=data[count-1];
            }
            cVal.SetDecart(rVal, 0);
            this->SetVal(cVal, i, j);
        }
    }
}
void Matrix_V1S_Lines_Simple::Set_Columns(std::vector<std::vector<double>>data){
    ComplexNum cVal;
    double rVal;
    int QColumns=data.size(), QLines, curL, maxL;
    for(int i=1; i<=QColumns; i++){
        curL=data[i-1].size();
        if(i==1 || (i>1 && curL>maxL)){
            maxL=curL;
        }
    }
    QLines=maxL;
    for(int i=1; i<=QColumns; i++){
        curL=data[i-1].size();
        for(int j=1; j<=curL; j++){
            rVal=data[i-1][j-1];
            cVal.SetDecart(rVal, 0);
            this->SetVal(cVal, j, i);
        }
        for(int j=curL+1; j<=QLines; j++){
            rVal=0;
            cVal.SetDecart(rVal, 0);
            this->SetVal(cVal, j, i);
        }
    }
}
void Matrix_V1S_Lines_Simple::Set_Columns(double val, int QLines, int QColumns){
    ComplexNum cVal(val, 0);
    for(int i=1; i<=QLines; i++){
        for(int j=1; j<=QColumns; j++){
            this->SetVal(cVal, i, j);
        }
    }
}
void Matrix_V1S_Lines_Simple::SetVal_EIR(const ComplexNum&val, int ExtRowN, int IneRowN){
    int PosN=0;
    PosN=this->PosNOfEIR(ExtRowN, IneRowN);
    if(PosN!=0){
        this->data[PosN-1]=val;
    }
}
void Matrix_V1S_Lines_Simple::SetVal(const ComplexNum&val, int LineN, int ColumnN){
    int ExtRowN=LineN, IneRowN=ColumnN;
    this->SetVal_EIR(val, ExtRowN, IneRowN);
}
//ComplexNum& Matrix_V1S_Lines_Simple::GetVal_EIR(int ExtRowN, int IneRowN)const{
ComplexNum Matrix_V1S_Lines_Simple::GetVal_EIR(int ExtRowN, int IneRowN)const{
    int PosN=0;
    PosN=this->PosNOfEIR(ExtRowN, IneRowN);
    if(PosN!=0){
        return this->data[PosN-1];
    }
}
//ComplexNum& Matrix_V1S_Lines_Simple::GetVal(int LineN, int ColumnN)const{
ComplexNum Matrix_V1S_Lines_Simple::GetVal(int LineN, int ColumnN)const{
    int ExtRowN=LineN, IneRowN=ColumnN;
    return this->GetVal_EIR(ExtRowN, IneRowN);
}
double Matrix_V1S_Lines_Simple::GetVal_Re_EIR(int ExtRowN, int IneRowN)const{
    ComplexNum component=this->GetVal_EIR(ExtRowN, IneRowN);
    return component.GetRe();
}
double Matrix_V1S_Lines_Simple::GetVal_Re(int LineN, int ColumnN)const{
    ComplexNum component=this->GetVal(LineN, ColumnN);
    return component.GetRe();
}
double Matrix_V1S_Lines_Simple::GetVal_Im_EIR(int ExtRowN, int IneRowN)const{
    ComplexNum component=this->GetVal_EIR(ExtRowN, IneRowN);
    return component.GetIm();
}
double Matrix_V1S_Lines_Simple::GetVal_Im(int LineN, int ColumnN)const{
    ComplexNum component=this->GetVal(LineN, ColumnN);
    return component.GetIm();
}
std::vector<ComplexNum> Matrix_V1S_Lines_Simple::GetExtRowN(int N)const{
    std::vector<ComplexNum> row;
    ComplexNum val;
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows();
    if(N>=1 && N<=QExtRows){
        for(int i=1; i<=QIneRows; i++){
            val=this->GetVal_EIR(N, i);
            row.push_back(val);
        }
    }
    return row;
}
std::vector<ComplexNum> Matrix_V1S_Lines_Simple::GetLineN(int N)const{
    std::vector<ComplexNum> row;
    ComplexNum val;
    int QLines=this->GetQLines(), QColumns=this->GetQColumns();
    if(N>=1 && N<=QLines){
        for(int i=1; i<=QColumns; i++){
            val=this->GetVal(N, i);
            row.push_back(val);
        }
    }
    return row;
}
std::vector<ComplexNum> Matrix_V1S_Lines_Simple::GetIneRowN(int N)const{
    std::vector<ComplexNum> row;
    ComplexNum val;
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows();
    if(N>=1 && N<=QIneRows){
        for(int i=1; i<=QExtRows; i++){
            val=this->GetVal_EIR(i, N);
            row.push_back(val);
        }
    }
    return row;
}
std::vector<ComplexNum> Matrix_V1S_Lines_Simple::GetColumnN(int N)const{
    std::vector<ComplexNum> row;
    ComplexNum val;
    int QLines=this->GetQLines(), QColumns=this->GetQColumns();
    if(N>=1 && N<=QColumns){
        for(int i=1; i<=QLines; i++){
            val=this->GetVal(i, N);
            row.push_back(val);
        }
    }
    return row;
}
std::vector<ComplexNum> Matrix_V1S_Lines_Simple::GetContent_ExtRows()const{
    std::vector<ComplexNum> row;
    ComplexNum val;
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows();
    for(int i=1; i<=QExtRows; i++){
        for(int j=1; j<=QIneRows; j++){
            val=this->GetVal_EIR(i, j);
            row.push_back(val);
        }
    }
    return row;
}
std::vector<ComplexNum> Matrix_V1S_Lines_Simple::GetContent_Lines()const{
    std::vector<ComplexNum> row;
    ComplexNum val;
    int QLines=this->GetQLines(), QColumns=this->GetQColumns();
    for(int i=1; i<=QLines; i++){
        for(int j=1; j<=QColumns; j++){
            val=this->GetVal(i, j);
            row.push_back(val);
        }
    }
    return row;
}
std::vector<ComplexNum> Matrix_V1S_Lines_Simple::GetContent_Columns()const{
    std::vector<ComplexNum> row;
    ComplexNum val;
    int QLines=this->GetQLines(), QColumns=this->GetQColumns();
    for(int i=1; i<=QColumns; i++){
        for(int j=1; j<=QLines; j++){
            val=this->GetVal(i, j);
            row.push_back(val);
        }
    }
    return row;
}
//
//
void Matrix_V1S_Lines_Simple::SwapVals_EIR(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2){
    ComplexNum valBuf, val1, val2;
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows();
    if(  ExtRowN1>=1 && ExtRowN1<=QExtRows && IneRowN1>=1 && IneRowN1<=QIneRows
       &&ExtRowN2>=1 && ExtRowN2<=QExtRows && IneRowN2>=1 && IneRowN2<=QIneRows
      )
    {
          val1=this->GetVal_EIR(ExtRowN1, IneRowN1);
          val2=this->GetVal_EIR(ExtRowN2, IneRowN2);
          valBuf=val1;
          val1=val2;
          val2=valBuf;
          this->SetVal_EIR(val1, ExtRowN2, IneRowN2);
          this->SetVal_EIR(val2, ExtRowN1, IneRowN1);
    }
}
void Matrix_V1S_Lines_Simple::SwapVals(int LineN1, int ColN1, int LineN2, int ColN2){
    int ExtRowN1, IneRowN1, ExtRowN2, IneRowN2;
    ExtRowN1=LineN1;
    IneRowN1=ColN1;
    ExtRowN2=LineN2;
    IneRowN2=ColN2;
    this->SwapVals_EIR(ExtRowN1, IneRowN1, ExtRowN2, IneRowN2);
}
void Matrix_V1S_Lines_Simple::SwapExtRows(int ExtRowN1, int ExtRowN2){
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows();
    if(ExtRowN1>=1 && ExtRowN1<=QExtRows && ExtRowN2>=1 && ExtRowN2<=QExtRows){
        for(int i=1; i<=QIneRows; i++){
            this->SwapVals_EIR(ExtRowN1, i, ExtRowN2, i);
        }
    }
}
void Matrix_V1S_Lines_Simple::SwapIneRows(int IneRowN1, int IneRowN2){
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows();
    if(IneRowN1>=1 && IneRowN1<=QIneRows && IneRowN2>=1 && IneRowN2<=QIneRows){
        for(int i=1; i<=QExtRows; i++){
            this->SwapVals_EIR(i, IneRowN1, i, IneRowN2);
        }
    }
}
void Matrix_V1S_Lines_Simple::SwapLines(int LineN1, int LineN2){
    int ExtRowN1 = LineN1, ExtRowN2 = LineN2;
    this->SwapExtRows(ExtRowN1, ExtRowN2);
}
void Matrix_V1S_Lines_Simple::SwapColumns(int ColN1, int ColN2){
    int IneRowN1 = ColN1, IneRowN2 = ColN2;
    this->SwapIneRows(IneRowN1, IneRowN2);
}
//
//
void Matrix_V1S_Lines_Simple::SetExtRow_Simple(ComplexNum*row, int N){
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows(), curL;
    ComplexNum val;
    if(N>=1 && N<=QExtRows){
        for(int i=1; i<=QIneRows; i++){
            val=row[i-1];
            this->SetVal_EIR(val, N, i);
        }
    }
}
void Matrix_V1S_Lines_Simple::SetLine_Simple(ComplexNum*row, int LineN){
    int ExtRowN=LineN;
    this->SetExtRow_Simple(row, ExtRowN);
}
void Matrix_V1S_Lines_Simple::SetIneRow_Simple(ComplexNum*row, int N){
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows(), curL;
    ComplexNum val;
    if(N>=1 && N<=QExtRows){
        for(int i=1; i<=QExtRows; i++){
            val=row[i-1];
            this->SetVal_EIR(val, i, N);
        }
    }
}
void Matrix_V1S_Lines_Simple::SetColumn_Simple(ComplexNum*row, int ColN){
    int IneRowN=ColN;
    this->SetIneRow_Simple(row, IneRowN);
}
//
void Matrix_V1S_Lines_Simple::SetExtRow_Simple(double*row, int N){
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows(), curL;
    ComplexNum val;
    if(N>=1 && N<=QExtRows){
        for(int i=1; i<=QIneRows; i++){
            val.SetDecart(row[i-1], 0);
            this->SetVal_EIR(val, N, i);
        }
    }
}
void Matrix_V1S_Lines_Simple::SetLine_Simple(double*row, int LineN){
    int ExtRowN=LineN;
    this->SetExtRow_Simple(row, ExtRowN);
}
void Matrix_V1S_Lines_Simple::SetIneRow_Simple(double*row, int N){
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows(), curL;
    ComplexNum val;
    if(N>=1 && N<=QExtRows){
        for(int i=1; i<=QExtRows; i++){
            val.SetDecart(row[i-1], 0);
            this->SetVal_EIR(val, i, N);
        }
    }
}
void Matrix_V1S_Lines_Simple::SetColumn_Simple(double*row, int ColN){
    int IneRowN=ColN;
    this->SetIneRow_Simple(row, IneRowN);
}
//
void Matrix_V1S_Lines_Simple::AddExtRow_Simple(ComplexNum*row){
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows();
    if(QExtRows>0 && QIneRows>0){
        this->SetSize_EIR(QExtRows+1, QIneRows);
        this->SetExtRow_Simple(row, QExtRows+1);
    }
}
void Matrix_V1S_Lines_Simple::AddLine_Simple(ComplexNum*row){
    this->AddExtRow_Simple(row);
}
void Matrix_V1S_Lines_Simple::AddIneRow_Simple(ComplexNum*row){
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows();
    if(QExtRows>0 && QIneRows>0){
        this->SetSize_EIR(QExtRows, QIneRows+1);
        this->SetIneRow_Simple(row, QIneRows+1);
    }
}
void Matrix_V1S_Lines_Simple::AddColumn_Simple(ComplexNum*row){
    this->AddIneRow_Simple(row);
}
//
void Matrix_V1S_Lines_Simple::InsExtRow_Simple(ComplexNum*row, int N){
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows();
    if(N>=1 && N<=QExtRows){
        this->SetSize_EIR(QExtRows+1, QIneRows);
        for(int i=QExtRows+1; i>=N+1; i--){
            this->SwapExtRows(i-1, i);
        }
        this->SetExtRow_Simple(row, N);
    }
}
void Matrix_V1S_Lines_Simple::InsLine_Simple(ComplexNum*row, int LineN){
    int ExtRowN=LineN;
    this->InsExtRow_Simple(row, ExtRowN);
}
void Matrix_V1S_Lines_Simple::InsIneRow_Simple(ComplexNum*row, int N){
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows();
    if(N>=1 && N<=QExtRows){
        this->SetSize_EIR(QExtRows, QIneRows+1);
        for(int i=QIneRows+1; i>=N+1; i--){
            this->SwapIneRows(i-1, i);
        }
        this->SetIneRow_Simple(row, N);
    }
}
void Matrix_V1S_Lines_Simple::InsColumn_Simple(ComplexNum*row, int ColN){
    int IneRowN=ColN;
    this->InsIneRow_Simple(row, IneRowN);
}
//
void Matrix_V1S_Lines_Simple::DelExtRow_Simple(int N){
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows();
    if(N>=1 && N<=QExtRows){
        for(int i=N+1; i<=QExtRows; i++){
            this->SwapExtRows(i-1, i);
        }
        this->SetSize_EIR(QExtRows-1, QIneRows);
    }
}
void Matrix_V1S_Lines_Simple::DelLine_Simple(int LineN){
    int ExtRowN=LineN;
    this->DelExtRow_Simple(ExtRowN);
}
void Matrix_V1S_Lines_Simple::DelIneRow_Simple(int N){
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows();
    if(N>=1 && N<=QIneRows){
        for(int i=N+1; i<=QIneRows; i++){
            this->SwapIneRows(i-1, i);
        }
        this->SetSize_EIR(QExtRows, QIneRows-1);
    }
}
void Matrix_V1S_Lines_Simple::DelColumn_Simple(int ColN){
    int IneRowN=ColN;
    this->DelIneRow_Simple(IneRowN);
}
//
//
Matrix_V1S_Lines_Simple Matrix_V1S_Lines_Simple::SubMatrix_EIR(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2){
    int QExtRowsOwn=this->GetQExtRows(), QIneRowsOwn=this->GetQIneRows(), QExtRows, QIneRows;
    int whereExtRowN, whatExtRowN, whereIneRowN, whatIneRowN;
    Matrix_V1S_Lines_Simple R;
    std::vector<ComplexNum>row;
    ComplexNum val;
    if(ExtRowN1<0){
        ExtRowN1+=(QExtRowsOwn+1);
    }
    if(ExtRowN2<0){
        ExtRowN2+=(QExtRowsOwn+1);
    }
    if(IneRowN1<0){
        IneRowN1+=(QIneRowsOwn+1);
    }
    if(IneRowN2<0){
        IneRowN2+=(QIneRowsOwn+1);
    }
    //
    if(ExtRowN2>=ExtRowN1){
        QExtRows=ExtRowN2-ExtRowN1;
    }else{
        QExtRows=ExtRowN1-ExtRowN2;
    }
    if(IneRowN2>=IneRowN1){
        QIneRows=IneRowN2-IneRowN1;
    }else{
        QIneRows=IneRowN1-IneRowN2;
    }
    if((ExtRowN2<0 && ExtRowN1<0) || (IneRowN2<0 && IneRowN1<0) || (ExtRowN2>QExtRows && ExtRowN1>QExtRows) || (IneRowN2>QIneRows && IneRowN1>QIneRows)){
        R.SetSize_EIR(QExtRows, QIneRows);
        for(int i=1; i<=QExtRows; i++){
            for(int j=1; j<=QIneRows; j++){
                R.SetVal_EIR(val, i, j);//val dflt (0, 0)
            }
        }
    }else if(ExtRowN1>=1 && ExtRowN1<=QExtRowsOwn && ExtRowN2>=1 && ExtRowN2<=QExtRowsOwn    &&    IneRowN1>=1 && ExtRowN1<=QIneRowsOwn && IneRowN2>=1 && IneRowN2<=QIneRowsOwn){
        R.SetSize_EIR(QExtRows, QIneRows);
        if(ExtRowN2>=ExtRowN1){
            if(IneRowN2>=IneRowN1){
                for(whereExtRowN=ExtRowN1; whereExtRowN<=ExtRowN2; whereExtRowN++){
                    whatExtRowN=whereExtRowN-ExtRowN1+1;
                    for(whereIneRowN=IneRowN1; whereIneRowN<=IneRowN2; whereIneRowN++){
                        whatIneRowN=whereIneRowN-IneRowN1+1;
                        val=this->GetVal_EIR(whereExtRowN, whereIneRowN);
                        R.SetVal_EIR(val, whatExtRowN, whatIneRowN);
                    }
                }
            }else{
                for(whereExtRowN=ExtRowN1; whereExtRowN<=ExtRowN2; whereExtRowN++){
                    whatExtRowN=whereExtRowN-ExtRowN1+1;
                    for(whereIneRowN=IneRowN1; whereIneRowN>=IneRowN2; whereIneRowN--){
                        whatIneRowN=whereIneRowN-IneRowN1+1;
                        val=this->GetVal_EIR(whereExtRowN, whereIneRowN);
                        R.SetVal_EIR(val, whatExtRowN, whatIneRowN);
                    }
                }
            }
        }else{
            if(IneRowN2>=IneRowN1){
                for(whereExtRowN=ExtRowN1; whereExtRowN>=ExtRowN2; whereExtRowN--){
                    whatExtRowN=whereExtRowN-ExtRowN1+1;
                    for(whereIneRowN=IneRowN1; whereIneRowN<=IneRowN2; whereIneRowN++){
                        whatIneRowN=whereIneRowN-IneRowN1+1;
                        val=this->GetVal_EIR(whereExtRowN, whereIneRowN);
                        R.SetVal_EIR(val, whatExtRowN, whatIneRowN);
                    }
                }
            }else{
                for(whereExtRowN=ExtRowN1; whereExtRowN>=ExtRowN2; whereExtRowN--){
                    whatExtRowN=whereExtRowN-ExtRowN1+1;
                    for(whereIneRowN=IneRowN1; whereIneRowN>=IneRowN2; whereIneRowN--){
                        whatIneRowN=whereIneRowN-IneRowN1+1;
                        val=this->GetVal_EIR(whereExtRowN, whereIneRowN);
                        R.SetVal_EIR(val, whatExtRowN, whatIneRowN);
                    }
                }
            }
        }
        for(int i=1; i<=QExtRows; i++){
            for(int j=1; j<=QIneRows; j++){
                R.SetVal_EIR(val, i, j);//val dflt (0, 0)
            }
        }
    }
    //
    return R;
}
Matrix_V1S_Lines_Simple Matrix_V1S_Lines_Simple::SubMatrix(int LineN1, int ColumnN1, int LineN2, int ColumnN2){
    int ExtRowN1=LineN1, ExtRowN2=LineN2, IneRowN1=ColumnN1, IneRowN2=ColumnN2;
    return this->SubMatrix_EIR(ExtRowN1, IneRowN1, ExtRowN2, IneRowN2);
}
//
//
void Matrix_V1S_Lines_Simple::StdCout_ExtRowN(int N, std::string delim, bool showBrackets, bool RepresentVertNotHor){
    ComplexNum val;
    QString sn;
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows();
    if(N>=1 && N<=QExtRows){
        if(showBrackets){
            std::cout<<"[";
        }
        for(int i=1; i<=QIneRows-1; i++){
            val=this->GetVal_EIR(N, i);
            sn=val.ToString();
            std::cout<<sn.toStdString();
            std::cout<<delim;
            if(RepresentVertNotHor){
                std::cout<<std::endl;
                if(RepresentVertNotHor){
                     std::cout<<" ";
                }
            }
        }
        val=this->GetVal_EIR(N, QIneRows);
        sn=val.ToString();
        std::cout<<sn.toStdString();
        if(showBrackets){
            std::cout<<"]";
        }
    }
}

void Matrix_V1S_Lines_Simple::StdCout_IneRowN(int N, std::string delim, bool showBrackets, bool RepresentVertNotHor){
    ComplexNum val;
    QString sn;
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows();
    if(N>=1 && N<=QIneRows){
        if(showBrackets){
            std::cout<<"[";
        }
        for(int i=1; i<=QExtRows-1; i++){
            val=this->GetVal_EIR(i, N);
            sn=val.ToString();
            std::cout<<sn.toStdString();
            std::cout<<delim;
            if(RepresentVertNotHor){
                std::cout<<std::endl;
                if(RepresentVertNotHor){
                     std::cout<<" ";
                }
            }
        }
        val=this->GetVal_EIR(N, QIneRows);
        sn=val.ToString();
        std::cout<<sn.toStdString();
        if(showBrackets){
            std::cout<<"]";
        }
    }
}
void Matrix_V1S_Lines_Simple::StdCout_LineN(int LineN, std::string delim, bool showBrackets, bool RepresentVertNotHor){
    int ExtRowN=LineN;
    this->StdCout_ExtRowN(ExtRowN, delim, showBrackets);
}

void Matrix_V1S_Lines_Simple::StdCout_ColN(int ColN, std::string delim, bool showBrackets, bool Represent2DNot1D){
    int IneRowN=ColN;
    this->StdCout_IneRowN(IneRowN, delim, showBrackets);
}
void Matrix_V1S_Lines_Simple::StdCout_EIR_ExtHor(std::string delimElem, std::string delimRow, bool showBrackets, bool Represent2DNot1D){
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetQIneRows();
    if(showBrackets){
        std::cout<<"[";
    }
    for(int i=1; i<=QExtRows-1; i++){
        this->StdCout_ExtRowN(1, delimElem, showBrackets, false);
        std::cout<<delimRow;
        if(Represent2DNot1D){
            std::cout<<std::endl;
            if(showBrackets){
                 std::cout<<" ";
            }
        }
    }
    this->StdCout_ExtRowN(QExtRows, delimElem, showBrackets, false);
    if(showBrackets){
        std::cout<<"]";
    }
}

void Matrix_V1S_Lines_Simple::StdCout(std::string delimElem, std::string delimRow, bool showBrackets, bool Represent2DNot1D){
    this->StdCout_EIR_ExtHor(delimElem, delimRow, showBrackets, Represent2DNot1D);
}
