#include "matrices3.h"

//Matrices3::Matrices3()
//{
//
//}

void Matrix_Prototype::SetOne(double DfltVal){
    this->SetSize_Matrix(1, 1);
    this->SetComponent(DfltVal, 1, 1);
}

bool Matrix_Prototype::NsBelongHere_byEI(int ExtRowN, int IneRowN) const{
    bool verdict=true;
    int QExtRows=this->GetQExtRows(), LineLength=this->GetLength();
    if(ExtRowN<0){
        ExtRowN+=(QExtRows+1);
    }
    if(ExtRowN<1 || ExtRowN>QExtRows){
        verdict=false;
    }else{
        //CurLineLength=this->GetLength(ExtRowN);
        if(IneRowN<0){
            IneRowN+=(LineLength+1);
        }
        if(IneRowN<1 && IneRowN>LineLength){
            verdict=false;
        }
    }
    return verdict;
}
bool Matrix_Prototype::NsBelongHere_byLC(int LineN, int ColumnN) const{
    bool verdict=true;
    int QLines=this->GetQLines(), LineLength=this->GetQColumns();
    if(LineN<0){
        LineN+=(QLines+1);
    }
    if(LineN<1 || LineN>QLines){
        verdict=false;
    }else{
        //CurLineLength=this->GetLength(ExtRowN);
        if(ColumnN<0){
            ColumnN+=(LineLength+1);
        }
        if(ColumnN<1 && ColumnN>LineLength){
            verdict=false;
        }
    }
    return verdict;
}
//
//
std::vector<double> Matrix_Prototype::GetExtRowN_AsArray(int ExtRowN) const{
    std::vector<double>R;
    double val;
    int QExtRows=this->GetQExtRows(), CurRowLength=0;
    if(ExtRowN<0){
        ExtRowN+=(QExtRows+1);
    }
    if(ExtRowN>=1 && ExtRowN<=QExtRows){
        //CurRowLength=this->GetLength(ExtRowN);
        CurRowLength=this->GetLength();
        for(int i=1; i<=CurRowLength; i++){
            val=this->GetComponent_AsVal_byEI(ExtRowN, i);
            R.push_back(val);
        }
    }
    return R;
}
//double*GetExtRowN_AsPtr(int ExtRowN) const;
 std::vector<double> Matrix_Prototype::GetIneRowN_AsArray(int IneRowN) const{
    std::vector<double>R;
    double val;
    int N=-1;
    bool contin;
    int QExtRows=this->GetQExtRows(), CurRowLength=0, Lmax=this->GetLength();//GetMaxLength();
    if(IneRowN<0){
        IneRowN+=(Lmax+1);
    }
    if(IneRowN>=1 && IneRowN<=Lmax){
        N++;
        //contin=(this->GetLength(N+1)>=IneRowN);
        contin=(this->GetLength()>=IneRowN);
        while(contin){
            N++;
            val=this->GetComponent_AsVal_byEI(N, IneRowN);
            R.push_back(val);
            //contin=(N<QExtRows && this->GetLength(N+1)>=IneRowN);
            contin=(N<QExtRows && this->GetLength()>=IneRowN);
        }
    }
    return R;
}

std::vector<double> Matrix_Prototype::GetLineN_AsArray(int LineN) const{
    std::vector<double>R;
    double val;
    int QLines=this->GetQLines(), LineLength=this->GetQColumns();
    if(LineN<0){
        LineN+=(QLines+1);
    }
    if(LineN>=1 && LineN<=QLines){
        //CurRowLength=this->GetLength(ExtRowN);
        for(int i=1; i<=LineLength; i++){
            val=this->GetComponent(LineN, i);
            R.push_back(val);
        }
    }
    return R;
}
std::vector<double> Matrix_Prototype::GetColumnN_AsArray(int N) const{
    std::vector<double>R;
    double val;
    int QLines=this->GetQLines(), LineLength=this->GetQColumns();
    if(N<0){
        N+=(LineLength+1);
    }
    if(N>=1 && N<=LineLength){
        //CurRowLength=this->GetLength(ExtRowN);
        for(int i=1; i<=LineLength; i++){
            val=this->GetComponent(i, N);
            R.push_back(val);
        }
    }
    return R;
}

std::vector<double> Matrix_Prototype::GetContent_AsArray1D_ExtRows() const{
   std::vector<double>R;
   double val;
   int N=-1;
   bool contin;
   int QExtRows=this->GetQExtRows(), CurRowLength=0;
   for(int i=1; i<=CurRowLength; i++){
      // CurRowLength=this->GetLength(i);
       CurRowLength=this->GetLength();
       for(int j=1; j<=CurRowLength; j++){
           val=this->GetComponent_AsVal_byEI(i, j);
           R.push_back(val);
       }
   }
   return R;
}

std::vector<std::vector<double>> Matrix_Prototype::GetContent_AsArray2D_ExtRows() const{
   std::vector<double>row;
   std::vector<std::vector<double>>data;
   double val;
   int N=-1;
   bool contin;
   int QExtRows=this->GetQExtRows(), ExtRowLength=this->GetLength();//CurRowLength=0;
   for(int i=1; i<=ExtRowLength; i++){//for(int i=1; i<=CurRowLength; i++){
      // CurRowLength=this->GetLength(i);
       row.clear();
       for(int j=1; j<=ExtRowLength; j++){
           val=this->GetComponent_AsVal_byEI(i, j);
           row.push_back(val);
       }
       data.push_back(row);
   }
   return data;
}
std::vector<double> Matrix_Prototype::GetContent_AsArray1D_Lines() const{
   std::vector<double>R;
   double val;
   int N=-1;
   bool contin;
   int QLines=this->GetQLines(), QColumns=this->GetQColumns();//CurRowLength=0;
   for(int i=1; i<=QLines; i++){
       //CurRowLength=this->GetLength(i);
       for(int j=1; j<=QColumns; j++){
           val=this->GetComponent(i, j);
           R.push_back(val);
       }
   }
   return R;
}
std::vector<std::vector<double>> Matrix_Prototype::GetContent_AsArray2D_Lines() const{
   std::vector<double>row;
   std::vector<std::vector<double>>data;
   double val;
   int N=-1;
   bool contin;
   int QLines=this->GetQLines(), LineLength=this->GetQColumns();//ExtRowLength=this->GetLength();//CurRowLength=0;
   for(int i=1; i<=QLines; i++){
      // CurRowLength=this->GetLength(i);
       row.clear();
       for(int j=1; j<=LineLength; j++){
           val=this->GetComponent(i, j);
           row.push_back(val);
       }
       data.push_back(row);
   }
   return data;
}

//void                   SetExtRowN(                              int N, double*rowParam=NULL, int rowL=0, double defaultVal=0.0, TParamsOfDataShift*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int ifNLNE_ByM1ByNewRow2ByMax3=1);
void Matrix_Prototype::SetExtRowN(                        int ExtRowN, double*rowParam,      int rowL,   double defaultVal,     TParamsOfDataShift*DataShiftParams,      bool DefaulsAreSpecNotOwnVals,   int   ifNLNE_ByM1ByNewRow2ByMax3){//int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6){
    int QExtRows=this->GetQExtRows(),  curL=this->GetLength(), newL, maxL, factL ;// ,   Lmax=this->GetMaxLength(), Lmin=this->GetMinLength(),
    std::vector<double>rowNew, rowWas;
    TParamsOfDataShift DataShift;
    if(DataShiftParams!=NULL){
        DataShift=(*(DataShiftParams));
    }
    double val;
    //Array2DSize sizeOld=this->GetSize(), sizeNew=sizeOld.ReturnBy_SetLength(ExtRowN,rowL,DataShiftParams,SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6);
    if(ExtRowN<0){
        ExtRowN+=(QExtRows+1);
    }
    if(ExtRowN>=1 && ExtRowN<=QExtRows){
        //curL=this->GetLength(ExtRowN);
        //DataShift.QReq=newL;
        //// 1. resize
        //sizeNew=sizeOld.ReturnBy_SetLength(ExtRowN, rowL, &DataShift, SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6);
        ////2.
        newL=DataShift.CalcQ(rowL);//sizeNew.GetLength(ExtRowN);
        maxL = newL>=curL ? newL : curL;
        switch(ifNLNE_ByM1ByNewRow2ByMax3){
            case 1:
                factL=curL;
            break;
            case 2:
                factL=newL;
            break;
            case 3:
                factL=maxL;
            break;
        }
        if(factL!=curL){
            this->SetSize_Array(QExtRows, factL);//iif
        }
        DataShift.QReq=factL;
        //// 3. new row co to L:
        if(DefaulsAreSpecNotOwnVals==false){
            rowWas=this->GetExtRowN_AsArray(ExtRowN);
            //rowNew=Array1DGetSubArray_byLs_PreMark_v2(rowParam, rowL, rowWas.data(), rowWas.size(), defaultVal,&DataShift);
            //GetSubVector(T*X, int Q, T*X2, int Q2, T DefaultVal, TParamsOfDataShift*DataShiftParam){
            rowNew=GetSubVector(rowParam, rowL, rowWas.data(), rowWas.size(), defaultVal, &DataShift);
        }else{
            //rowNew=Array1DGetSubArray_byLs_PreMark_v2(rowParam, rowL,defaultVal, &DataShift);
            rowNew=GetSubVector(rowParam, rowL,defaultVal, &DataShift);
        }
        // 4. set vals
        for(int i=1; i<=factL; i++){
            val=rowNew[i-1];
            this->SetComponent_byEI(val, ExtRowN, i);
        }
    }//else NOp
}//SetExtRow
void Matrix_Prototype::SetExtRow_Simply(int ExtRowN, double*rowParam){
    double val;
    int QExtRows=this->GetQExtRows(), QIneRows=this->GetLength();
    if(ExtRowN<0){
        ExtRowN+=(QExtRows+1);
    }
    if(ExtRowN>=1 && ExtRowN<=QExtRows){
        for(int i=1; i<=QIneRows; i++){
            val=rowParam[i-1];
            this->SetComponent_byEI(val, ExtRowN, i);
        }
    }
}
//void    SetExtRowN(int N,double*rowParam, int rowL, TParamsOfDataShift*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true,double*DfltValParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2);
//void Matrix_Prototype::SetExtRowN(int N,double*rowParam, int rowL, TParamsOfDataShift*DataShiftParams,      bool DefaulsAreSpecNotOwnVals,     double*DfltValParam,      int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6){
//    double defaultVal;
//    if(DfltValParam!=NULL){
//        defaultVal=(*(DfltValParam));
//    }
//    //virtual              void                      SetExtRowN(int N, double defaultVal,double*rowParam, int rowL, TParamsOfDataShift*DataShiftParams=NULL,                          bool DefaulsAreSpecNotOwnVals=true, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2)=0;
//                                               this->SetExtRowN(    N,          defaultVal,   rowParam,     rowL,                  DataShiftParams,                                    DefaulsAreSpecNotOwnVals,          SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6);
//}
void Matrix_Prototype::SetLineN  (int LineN, double*rowParam, int rowL,        double defaultVal, TParamsOfDataShift *DataShiftParams,  bool DefaulsAreSpecNotOwnVals, int ifNLNE_ByM1ByNewRow2ByMax3){
    int QLines=this->GetQLines(),  curL=this->GetLength(), newL, maxL, factL;// ,   Lmax=this->GetMaxLength(), Lmin=this->GetMinLength(),
    std::vector<double>rowNew, rowWas;
    TParamsOfDataShift DataShift;
    if(DataShiftParams!=NULL){
        DataShift=(*(DataShiftParams));
    }
    double val;
    //Array2DSize sizeOld=this->GetSize(), sizeNew=sizeOld.ReturnBy_SetLength(ExtRowN,rowL,DataShiftParams,SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6);
    if(LineN<0){
        LineN+=(QLines+1);
    }
    if(LineN>=1 && LineN<=QLines){
        //curL=this->GetLength(ExtRowN);
        //DataShift.QReq=newL;
        //// 1. resize
        //sizeNew=sizeOld.ReturnBy_SetLength(ExtRowN, rowL, &DataShift, SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6);
        ////2.
        newL=DataShift.CalcQ(rowL);//sizeNew.GetLength(ExtRowN);
        maxL = newL>=curL ? newL : curL;
        switch(ifNLNE_ByM1ByNewRow2ByMax3){
            case 1:
                factL=curL;
            break;
            case 2:
                factL=newL;
            break;
            case 3:
                factL=maxL;
            break;
        }
        if(factL!=curL){
            this->SetSize_Matrix(QLines, factL);//iif
        }
        DataShift.QReq=factL;
        //// 3. new row co to L:
        if(DefaulsAreSpecNotOwnVals==false){
            rowWas=this->GetLineN_AsArray(LineN);
            //rowNew=Array1DGetSubArray_byLs_PreMark_v2(rowParam, rowL, rowWas.data(), rowWas.size(), defaultVal,&DataShift);
            //GetSubVector(T*X, int Q, T*X2, int Q2, T DefaultVal, TParamsOfDataShift*DataShiftParam){
            rowNew=GetSubVector(rowParam, rowL, rowWas.data(), rowWas.size(), defaultVal, &DataShift);
        }else{
            //rowNew=Array1DGetSubArray_byLs_PreMark_v2(rowParam, rowL,defaultVal, &DataShift);
            rowNew=GetSubVector(rowParam, rowL,defaultVal, &DataShift);
        }
        // 4. set vals
        for(int i=1; i<=factL; i++){
            val=rowNew[i-1];
            this->SetComponent(val, LineN, i);
        }
    }//else NOp
}
void Matrix_Prototype::SetLine_Simply(int LineN, double*rowParam){
    double val;
    int QLines=this->GetQLines(), QColumns=this->GetQColumns();
    if(LineN<0){
        LineN+=(QLines+1);
    }
    if(LineN>=1 && LineN<=QLines){
        for(int i=1; i<=QColumns; i++){
            val=rowParam[i-1];
            this->SetComponent(val, LineN, i);
        }
    }
}
//
// void              ArrayOf2DBy1D_AddExtRow(double*&X, Array2DSize&size, double DefaultVal, double*rowParam, int wholeRowL=0, TParamsOfDataShift*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL){
//virtual  void                    AddExtRow(                             double DefaultVal, double*rowParam, int wholeRowL=0,                         TParamsOfDataShift*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL);
//         void                    AddExtRow(                             double*rowParam, int wholeRowL=0,   double DefaultVal=0.0,    TParamsOfDataShift*DataShiftParam=NULL, int ifNLNE_ByM1ByNewRow2ByMax3=1,                                   TValsShowHide*vsh=NULL);
void Matrix_Prototype::AddExtRow(                             double*rowParam, int wholeRowL,    TParamsOfDataShift*DataShiftParam,   double DefaultVal, int ifNLNE_ByM1ByNewRow2ByMax3,                                   TValsShowHide*vsh){
    //int QExtRows=this->GetQExtRows(), Lmin=this->GetMinLngth(), Lmax=this->GetMaxLength();
    //Array2DSize sizeOld=this->GetSize(), sizeNew=sizeOld.ReturnBy_AddExt(wholeRowL,DataShiftParam,SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6);
    //this->SetSize(DefaultVal, sizeNew);
    //this->SetExtRowN(QExtRows+1, rowParam, wholeRowL, true, SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6);
    int QExtRows=this->GetQExtRows(), ExtRowL=this->GetLength(), oldL=ExtRowL, newL, maxL, factL;
    TParamsOfDataShift DataShift;
    if(wholeRowL==0){
        wholeRowL=ExtRowL;
    }
    if(DataShiftParam!=NULL){
        DataShift=*DataShiftParam;
    }
    newL=DataShift.CalcQ(wholeRowL);
    maxL = newL >= oldL ? newL : oldL;
    switch(ifNLNE_ByM1ByNewRow2ByMax3){
        case 1:
            factL=oldL;
        break;
        case 2:
            factL=newL;
        break;
        case 3:
            factL=maxL;
        break;
    }
    if(factL!=oldL){
        this->SetSize_Array(QExtRows+1, factL);
    }
    DataShift.QReq=factL;
    QExtRows=this->GetQExtRows();
    this->SetExtRowN(QExtRows, rowParam, wholeRowL, DefaultVal, &DataShift, true, ifNLNE_ByM1ByNewRow2ByMax3);
}
//                 void AddLine(double*rowParam, int wholeRowL=0,   double DefaultVal=0.0,    TParamsOfDataShift*DataShiftParam=NULL, int ifNLNE_ByM1ByNewRow2ByMax3=1,                                   TValsShowHide*vsh=NULL);
void  Matrix_Prototype::AddLine(double*rowParam, int wholeRowL,    TParamsOfDataShift*DataShiftParam,   double DefaultVal, int ifNLNE_ByM1ByNewRow2ByMax3,  TValsShowHide*vsh){
    int QLines=this->GetQLines(), QColumns=this->GetQColumns(), oldL=QColumns, newL, maxL, factL;
    TParamsOfDataShift DataShift;
    if(wholeRowL==0){
        wholeRowL=QColumns;//ExtRowL;
    }
    if(DataShiftParam!=NULL){
        DataShift=*DataShiftParam;
    }
    newL=DataShift.CalcQ(wholeRowL);
    maxL = newL >= oldL ? newL : oldL;
    switch(ifNLNE_ByM1ByNewRow2ByMax3){
        case 1:
            factL=oldL;
        break;
        case 2:
            factL=newL;
        break;
        case 3:
            factL=maxL;
        break;
    }
    if(factL!=oldL){
        this->SetSize_Matrix(QLines+1, factL);
    }
    DataShift.QReq=factL;
    QLines=this->GetQLines();
    this->SetLineN(QLines, rowParam, wholeRowL, DefaultVal, &DataShift, true, ifNLNE_ByM1ByNewRow2ByMax3);
}

void Matrix_Prototype::AddLine_Simply(double*rowParam){
    double val;
    int QLines=this->GetQLines(), QColumns=this->GetQColumns();
    this->SetSize_Matrix(QLines+1, QColumns);
    for(int i=1; i<=QColumns; i++){
        val=rowParam[i-1];
        this->SetComponent(val, QLines+1, i);
    }
}
void Matrix_Prototype::InsExtRowN(                int ExtRowN,             double*rowParam, int wholeRowL,    TParamsOfDataShift*DataShiftParam,   double DefaultVal, int ifNLNE_ByM1ByNewRow2ByMax3,                                   TValsShowHide*vsh){
    int QExtRows=this->GetQExtRows();
    if(ExtRowN<0){
        ExtRowN+=(QExtRows+1);
    }
    if(ExtRowN>=1 && ExtRowN<=QExtRows){
        this->AddExtRow(rowParam, wholeRowL,DataShiftParam,DefaultVal,ifNLNE_ByM1ByNewRow2ByMax3,vsh);
        for(int i=QExtRows+1; i>=ExtRowN+1; i--){
            this->SwapExtRows(i-1, i);
        }
    }
}
void  Matrix_Prototype::InsExtRow_Simply(int ExtRowN,double*rowParam){
    int QExtRows=this->GetQExtRows();
    if(ExtRowN<0){
        ExtRowN+=(QExtRows+1);
    }
    if(ExtRowN>=1 && ExtRowN<=QExtRows){
        this->AddExtRow(rowParam);
        for(int i=QExtRows+1; i>=ExtRowN+1; i--){
            this->SwapExtRows(i-1, i);
        }
    }
}
void Matrix_Prototype::InsLineN(                int LineN,             double*rowParam, int wholeRowL,    TParamsOfDataShift*DataShiftParam,   double DefaultVal, int ifNLNE_ByM1ByNewRow2ByMax3,                                   TValsShowHide*vsh){
    int QLines=this->GetQLines();
    if(LineN<0){
        LineN+=(QLines+1);
    }
    if(LineN>=1 && LineN<=QLines){
        this->AddExtRow(rowParam, wholeRowL,DataShiftParam,DefaultVal,ifNLNE_ByM1ByNewRow2ByMax3,vsh);
        for(int i=QLines+1; i>=LineN+1; i--){
            this->SwapExtRows(i-1, i);
        }
    }
}
void  Matrix_Prototype::InsLine_Simply(int LineN,double*rowParam){
    int QLines=this->GetQLines();
    if(LineN<0){
        LineN+=(QLines+1);
    }
    if(LineN>=1 && LineN<=QLines){
        this->AddLine(rowParam);
        for(int i=QLines+1; i>=QLines+1; i--){
            this->SwapLines(i-1, i);
        }
    }
}

void Matrix_Prototype::DelExtRowN(int ExtRowN){
   int QExtRows=this->GetQExtRows(), ExtRowL=this->GetLength();//, curL;
   if(ExtRowN<0){
       ExtRowN+=(QExtRows+1);
   }
   if(ExtRowN>=1 && ExtRowN<=QExtRows){
       for(int i=ExtRowN+1; i<=QExtRows; i++){
           this->SwapExtRows(i, i-1);
       }
       this->SetSize_Array(QExtRows-1, ExtRowL);//*Dflt=NULL by dflt
   }
}
void Matrix_Prototype::DelLineN(int LineN){
   int QLines=this->GetQLines(), QColumns=this->GetQColumns();//, curL;
   if(LineN<0){
       LineN+=(QLines+1);
   }
   if(LineN>=1 && LineN<=QLines){
       for(int i=LineN+1; i<=QLines; i++){
           this->SwapLines(i, i-1);
       }
       this->SetSize_Matrix(QLines-1, QColumns);//*Dflt=NULL by dflt
   }
}

//
//Ine row
//
void Matrix_Prototype::SetIneRowN(int IneRowN, double*rowParam, int wholeRowL, TParamsOfDataShift*DataShiftParam, double DefaultVal, bool DafaultsAreSpecNotOwnVals, int ifNLNE_ByM1ByNewRow2ByMax3,                                   TValsShowHide*vsh){
    int QExtRows=this->GetQExtRows(), MRowL=this->GetLength(), QERM=QExtRows, QERParam, QERmax, QERfact;
    //no need check if MRowL>Lmin ob in M Lmin=Lmax
    std::vector<double>rowFact, rowWas;
    TParamsOfDataShift DataShift;
    double val;
    if(DataShiftParam!=NULL){
        DataShift=*DataShiftParam;
    }
    QERParam=DataShift.CalcQ(wholeRowL);
    QERmax = QERM >= QERParam ? QERM : QERParam;
    if(IneRowN<0){
        IneRowN+=(MRowL+1);
    }
    if(IneRowN>=1 && IneRowN<=MRowL){
        switch(ifNLNE_ByM1ByNewRow2ByMax3){
            case 1:
                QERfact=QERM;
            break;
            case 2:
                QERfact=QERParam;
            break;
            case 3:
                QERfact=QERmax;
            break;
        }
        if(QERfact!=QERM){
            this->SetSize_Array(QERfact, MRowL);
        }
        DataShift.QReq=QERfact;
        if(DafaultsAreSpecNotOwnVals==false){
            rowWas=this->GetIneRowN_AsArray(IneRowN);
            rowFact=GetSubVector(rowParam, wholeRowL, rowWas.data(), rowWas.size(), DefaultVal, &DataShift);
        }else{
            rowFact=GetSubVector(rowParam, wholeRowL, DefaultVal,&DataShift);
        }
        for(int i=1; i<=QERfact; i++){
            val=rowFact[i-1];
            this->SetComponent_byEI(val, i, IneRowN);
        }
    }
}
void Matrix_Prototype::SetColumnN(int ColumnN, double*rowParam, int wholeRowL, TParamsOfDataShift*DataShiftParam, double DefaultVal, bool DafaultsAreSpecNotOwnVals, int ifNLNE_ByM1ByNewRow2ByMax3,                                   TValsShowHide*vsh){
    int QLines=this->GetQLines(), QColumns=this->GetQColumns(), QLM=QLines, QLParam, QLmax, QLfact;
    //no need check if MRowL>Lmin ob in M Lmin=Lmax
    std::vector<double>rowFact, rowWas;
    TParamsOfDataShift DataShift;
    double val;
    if(DataShiftParam!=NULL){
        DataShift=*DataShiftParam;
    }
    QLParam=DataShift.CalcQ(wholeRowL);
    QLmax = QLM >= QLParam ? QLM : QLParam;
    if(ColumnN<0){
        ColumnN+=(QColumns+1);
    }
    if(ColumnN>=1 && ColumnN<=QColumns){
        switch(ifNLNE_ByM1ByNewRow2ByMax3){
            case 1:
                QLfact=QLM;
            break;
            case 2:
                QLfact=QLParam;
            break;
            case 3:
                QLfact=QLmax;
            break;
        }
        if(QLfact!=QLM){
            this->SetSize_Matrix(QLfact, QColumns);
        }
        DataShift.QReq=QLfact;
        if(DafaultsAreSpecNotOwnVals==false){
            rowWas=this->GetIneRowN_AsArray(ColumnN);
            rowFact=GetSubVector(rowParam, wholeRowL, rowWas.data(), rowWas.size(), DefaultVal, &DataShift);
        }else{
            rowFact=GetSubVector(rowParam, wholeRowL, DefaultVal,&DataShift);
        }
        for(int i=1; i<=QLfact; i++){
            val=rowFact[i-1];
            this->SetComponent(val, i, ColumnN);
        }
    }
}

//virtual void SetIneRowSimply(int IneRowN,double*rowParam)=0;
void Matrix_Prototype::SetIneRowSimply(int IneRowN,double*rowParam){
    int RowL=this->GetLength(), QExtRows=this->GetQExtRows();
    double val;
    if(IneRowN<0){
        IneRowN+=(RowL+1);
    }
    if(IneRowN>=1 && IneRowN<=RowL){
        for(int i=1; i<=QExtRows; i++){
            val=rowParam[i-1];
            this->SetComponent_byEI(val, i, IneRowN);
        }
    }
}
void Matrix_Prototype::SetColumnSimply(int ColumnN,double*rowParam){
    int QColumns=this->GetQColumns(), QLines=this->GetQExtRows();
    double val;
    if(ColumnN<0){
        ColumnN+=(QColumns+1);
    }
    if(ColumnN>=1 && ColumnN<=QColumns){
        for(int i=1; i<=QLines; i++){
            val=rowParam[i-1];
            this->SetComponent(val, i, ColumnN);
        }
    }
}
//
//void             AddIneRow(double*&X, Array2DSize& size, double DefaultVal,double*rowParam=NULL, int wholeRowL=0, TParamsOfDataShift*dataShiftParam=NULL,  int ifNGTLmin_Ignore0AddToLast1StretchToMax2=0, int if_RowLNEQER_By2D2_ByMax3=2, bool SetRect=true);
//void               SetIneRowN(          int IneRowN,                   double*rowParam=NULL, int wholeRowL=0,                        TParamsOfDataShift*DataShiftParam=NULL, double DefaultVal=0.0, bool DafaultsAreSpecNotOwnVals=true, int ifNLNE_ByM1ByNewRow2ByMax3,                                   TValsShowHide*vsh);
//void   AddIneRow(                                                 double*rowParam=NULL, int wholeRowL=0, double DefaultVal=0.0, TParamsOfDataShift*dataShiftParam=NULL,                              int ifNLNE_ByM1ByNewRow2ByMax3=1);
void Matrix_Prototype::   AddIneRow(                                double*rowParam,      int wholeRowL,    TParamsOfDataShift*DataShiftParam,        double DefaultVal,                               int ifNLNE_ByM1ByNewRow2ByMax3){
    int QERM=this->GetQExtRows(), ERL=this->GetLength(), QERParam, QERFact, QERMax;
    //switch (control) {
    //case value:
   //
    //    break;
    //default:
    //    break;
    //}
    //std::vector<double>row;
    //double val;
    TParamsOfDataShift DataShift;
    if(DataShiftParam!=NULL){
        DataShift=*DataShiftParam;
    }
    QERParam=DataShift.CalcQ(wholeRowL);
    QERMax = QERM >= QERParam ? QERM : QERParam;
    switch(ifNLNE_ByM1ByNewRow2ByMax3){
        case 1:
            QERFact=QERM;
        break;
        case 2:
            QERFact=QERParam;
        break;
        case 3:
            QERFact=QERMax;
        break;
    }
    DataShift.QReq=QERFact;
    if(QERFact!=QERM){
        this->SetSize_Array(QERFact, ERL+1);
    }
    this->SetIneRowN(ERL+1, rowParam, wholeRowL, &DataShift, DefaultVal, true, ifNLNE_ByM1ByNewRow2ByMax3);
}
//void   AddColumn(                                                 double*rowParam=NULL, int wholeRowL=0,                        TParamsOfDataShift*dataShiftParam=NULL, double DefaultVal=0.0,  int ifNLNE_ByM1ByNewRow2ByMax3=1);
void Matrix_Prototype::AddColumn(                                   double*rowParam,      int wholeRowL,                          TParamsOfDataShift*DataShiftParam,      double DefaultVal,      int ifNLNE_ByM1ByNewRow2ByMax3){
    int QLM=this->GetQLines(), QColumns=this->GetQColumns(), QLParam, QLFact, QLMax;
    TParamsOfDataShift DataShift;
    if(DataShiftParam!=NULL){
        DataShift=*DataShiftParam;
    }
    QLParam=DataShift.CalcQ(wholeRowL);
    QLMax = QLM >= QLParam ? QLM : QLParam;
    switch(ifNLNE_ByM1ByNewRow2ByMax3){
        case 1:
            QLFact=QLM;
        break;
        case 2:
            QLFact=QLParam;
        break;
        case 3:
            QLFact=QLMax;
        break;
    }
    DataShift.QReq=QLFact;
    if(QLFact!=QLM){
        this->SetSize_Matrix(QLFact, QColumns+1);
    }
    this->SetColumnN(QColumns+1, rowParam, wholeRowL, &DataShift, DefaultVal, true, ifNLNE_ByM1ByNewRow2ByMax3);
}

void  Matrix_Prototype::AddIneRow_Simply(double*rowParam){
    int QExtRows=this->GetQExtRows(), rowL=this->GetLength();
    double val;
    this->SetSize_Array(QExtRows, rowL+1);
    for(int i=1; i<=QExtRows; i++){
        val=rowParam[i-1];
        this->SetComponent_byEI(val, i, rowL+1);
    }
}
void  Matrix_Prototype::AddColumn_Simply(double*rowParam){
    int QLines=this->GetQLines(), QColumns=this->GetQColumns();
    double val;
    this->SetSize_Matrix(QLines, QColumns+1);
    for(int i=1; i<=QLines; i++){
        val=rowParam[i-1];
        this->SetComponent(val, i, QColumns+1);
    }
}
//virtual void AddIneRow_Simply(double*rowParam, int L)=0;
//
// void               InsIneRowN(int IneRowN, double*rowParam=NULL, int wholeRowL=0, TParamsOfDataShift*DataShiftParam=NULL, double DefaultVal=0.0, int ifNLNE_ByM1ByNewRow2ByMax3=1);
//
void Matrix_Prototype::InsIneRowN(int IneRowN, double*rowParam,      int wholeRowL,   TParamsOfDataShift*DataShiftParam,      double DefaultVal,     int ifNLNE_ByM1ByNewRow2ByMax3){
    int QERM=this->GetQExtRows(), ERL=this->GetLength(), QERParam, QERFact, QERMax;
    TParamsOfDataShift DataShift;
    if(DataShiftParam!=NULL){
        DataShift=*DataShiftParam;
    }
    QERParam=DataShift.CalcQ(wholeRowL);
    QERMax = QERM >= QERParam ? QERM : QERParam;
    switch(ifNLNE_ByM1ByNewRow2ByMax3){
        case 1:
            QERFact=QERM;
        break;
        case 2:
            QERFact=QERParam;
        break;
        case 3:
            QERFact=QERMax;
        break;
    }
    DataShift.QReq=QERFact;
    if(QERFact!=QERM){
        this->SetSize_Array(QERFact, ERL+1);
    }
    for(int i=ERL+1; i>=IneRowN+1; i--){
       this->SwapIneRows(i-1, i);
    }
    this->SetIneRowN(IneRowN, rowParam, wholeRowL, &DataShift, DefaultVal, true, ifNLNE_ByM1ByNewRow2ByMax3);
}
//
//void               InsColumnN(                         int ColumnN, double*rowParam=NULL, int wholeRowL=0, TParamsOfDataShift*DataShiftParam=NULL, double DefaultVal=0.0,                         int ifNLNE_ByM1ByNewRow2ByMax3=1);
void Matrix_Prototype::InsColumnN(                       int ColumnN, double*rowParam,      int wholeRowL,   TParamsOfDataShift*DataShiftParam,      double DefaultVal,          int ifNLNE_ByM1ByNewRow2ByMax3){
    int QLM=this->GetQLines(), QColumns=this->GetQColumns(), QLParam, QLFact, QLMax;
    TParamsOfDataShift DataShift;
    if(DataShiftParam!=NULL){
        DataShift=*DataShiftParam;
    }
    QLParam=DataShift.CalcQ(wholeRowL);
    QLMax = QLM >= QLParam ? QLM : QLParam;
    switch(ifNLNE_ByM1ByNewRow2ByMax3){
        case 1:
            QLFact=QLM;
        break;
        case 2:
            QLFact=QLParam;
        break;
        case 3:
            QLFact=QLMax;
        break;
    }
    DataShift.QReq=QLFact;
    if(QLFact!=QLM){
        this->SetSize_Matrix(QLFact, QColumns+1);
    }
    for(int i=QColumns+1; i>=ColumnN+1; i--){
       this->SwapColumns(i-1, i);
    }
    this->SetColumnN(ColumnN, rowParam, wholeRowL, &DataShift, DefaultVal, true, ifNLNE_ByM1ByNewRow2ByMax3);
}
void Matrix_Prototype::InsIneRow_Simply(int IneRowN, double*rowParam){
    int QExtRows=this->GetQExtRows(), RowLength=this->GetLength();
    double val;
    if(IneRowN>=1 && IneRowN<=RowLength){
        this->SetSize_Array(QExtRows, RowLength+1);
        for(int i=RowLength+1; i>=IneRowN+1; i--){
            this->SwapIneRows(i-1, i);
        }
        this->SetIneRowSimply(IneRowN, rowParam);
    }
}
void Matrix_Prototype::InsColumn_Simply(int ColumnN, double*rowParam){
    int IneRowN=ColumnN;
    this->SetIneRowSimply(IneRowN, rowParam);
}

//virtual void DelIneRowN(int N=-1, int ifNGTLmin_Ignore0_DelLast1_NurProperL_AnyExtRow3_NurFromStartTillFirstBreak4=0);
void Matrix_Prototype::DelIneRowN(int IneRowN){
    int QExtRows=this->GetQExtRows(), ERL=this->GetLength();
    if(IneRowN<0){
        IneRowN+=(ERL+1);
    }
    if(IneRowN>=1 && IneRowN<=ERL){
        for(int i=IneRowN+1; i<=ERL; i++){
            this->SwapIneRows(i-1, i);
        }
    }
    this->SetSize_Array(QExtRows, ERL-1);
}
void Matrix_Prototype::DelColumnN(int ColumnN){
    int QLines=this->GetQLines(), QColumns=this->GetQColumns();
    if(ColumnN<0){
        ColumnN+=(QColumns+1);
    }
    if(ColumnN>=1 && ColumnN<=QColumns){
        for(int i=ColumnN+1; i<=QColumns; i++){
            this->SwapColumns(i-1, i);//!
        }
    }
    this->SetSize_Matrix(QLines, QColumns-1);
}

//virtual void DelIneRow_Simply(int N=-1)=0;
//
// Set Content
//
void Matrix_Prototype::Set_byEI(double**y, int QExtRows, int QIneRows){
    double val;
    this->SetSize_Array(QExtRows, QIneRows);
    for(int ExtRowN=1; ExtRowN<=QExtRows; ExtRowN++){
        for(int IneRowN=1; IneRowN<=QIneRows; IneRowN++){
            val=y[ExtRowN-1][IneRowN-1];
            this->SetComponent_byEI(val, ExtRowN, IneRowN);
        }
    }
}
void Matrix_Prototype::Set_byLC(double**y, int QLines, int QColumns){//by LC s'om param, ne om Matrix. F'Matrix s'SetComponent. Ors os ablb by EI, LC (zug o'Lines) et CL (zug o'Cols), ma nout CL, if LC s'Matrix order, f'Matrices' CL s'EI
    double val;
    this->SetSize_Matrix(QLines, QColumns);
    for(int LineN=1; LineN<=QLines; LineN++){
        for(int ColN=1; ColN<=QColumns; ColN++){
            val=y[LineN-1][ColN-1];
            this->SetComponent(val, LineN, ColN);
        }
    }
}
void Matrix_Prototype::Set_byCL(double**y, int QLines, int QColumns){//CL sdi y s'zug o'cols
    double val;
    this->SetSize_Matrix(QLines, QColumns);
    //
    for(int ColN=1; ColN<=QColumns; ColN++){
        for(int LineN=1; LineN<=QLines; LineN++){
            val=y[ColN-1][LineN-1];
            this->SetComponent(val, LineN, ColN);//tic fun obs concr M type
        }
    }
}
void Matrix_Prototype::Set_byEI(double*y, int QExtRows, int QIneRows){
    double val;
    int PosN;
    this->SetSize_Array(QExtRows, QIneRows);
    for(int ExtRowN=1; ExtRowN<=QExtRows; ExtRowN++){
        for(int IneRowN=1; IneRowN<=QIneRows; IneRowN++){
            //int GetPositionInArrayOf2DRealizedBy1D(int QExtRows, int ExtRowsLength, int ExtRowN, int IneRowPosN);
            PosN= GetPositionInArrayOf2DRealizedBy1D(    QExtRows,          QIneRows,     ExtRowN,     IneRowN);
            val=y[PosN-1];
            this->SetComponent_byEI(val, ExtRowN, IneRowN);
        }
    }
}
void Matrix_Prototype::Set_byLC(double*y, int QLines, int QColumns){//by LC s'om param, ne om Matrix. F'Matrix s'SetComponent. Ors os ablb by EI, LC (zug o'Lines) et CL (zug o'Cols), ma nout CL, if LC s'Matrix order, f'Matrices' CL s'EI
    double val;
    int PosN;
    this->SetSize_Matrix(QLines, QColumns);
    for(int LineN=1; LineN<=QLines; LineN++){
        for(int ColN=1; ColN<=QColumns; ColN++){
            //int GetPositionInArrayOf2DRealizedBy1D(int QExtRows, int ExtRowsLength, int ExtRowN, int IneRowPosN);
            //by LC sdi param s'zug o'lines
            PosN= GetPositionInArrayOf2DRealizedBy1D(    QLines,            QColumns,     LineN,     ColN);
            val=y[PosN-1];
            this->SetComponent(val, LineN, ColN);
        }
    }
}
void Matrix_Prototype::Set_byCL(double*y, int QLines, int QColumns){//CL=>-param s'zug o'cols
    double val;
    int PosN;
    this->SetSize_Matrix(QLines, QColumns);
    for(int LineN=1; LineN<=QLines; LineN++){
        for(int ColN=1; ColN<=QColumns; ColN++){
            //int GetPositionInArrayOf2DRealizedBy1D(int QExtRows, int ExtRowsLength, int ExtRowN, int IneRowPosN);
            //by LC sdi param s'zug o'lines
            PosN= GetPositionInArrayOf2DRealizedBy1D(    QColumns,            QLines,    ColN,     LineN);
            val=y[PosN-1];
            this->SetComponent(val, LineN, ColN);
        }
    }
}
void Matrix_Prototype::Set_byEI(double val, int QExtRows, int ExtRowsLength){
    //double val;
    this->SetSize_Array(QExtRows, ExtRowsLength);
    for(int i=1; i<=QExtRows; i++){
        for(int j=1; j<=ExtRowsLength; j++){
            this->SetComponent_byEI(val, i, j);
        }
    }
}
void Matrix_Prototype::Set_byLC(double val, int QLines, int QColumns){
   //double val;
    this->SetSize_Matrix(QLines, QColumns);
    for(int i=1; i<=QLines; i++){
        for(int j=1; j<=QColumns; j++){
            this->SetComponent(val, i, j);
        }
    }
}
void Matrix_Prototype::Set_byEIR(std::vector<double>arr, int QExtRows){
    int QElts=arr.size();
    int QIneRows=QElts/QExtRows;
    int PosN;
    double val;
    this->SetSize_Array(0.0, QExtRows, QIneRows);
    for(int i=1; i<=QExtRows; i++){
        for(int j=1; j<=QExtRows; j++){
            PosN=GetPositionInArrayOf2DRealizedBy1D(QExtRows, QIneRows, i, j);
            val=arr[PosN-1];
            this->SetComponent_byEI(val, i, j);
        }
    }
}
void Matrix_Prototype::Set_byLC(std::vector<double>arr, int QLines){
    int QElts=arr.size();
    int QColumns=QElts/QLines;
    int PosN, QExtRows=QLines, QIneRows=QColumns;
    double val;
    this->SetSize_Matrix(0.0, QLines, QColumns);
    for(int i=1; i<=QLines; i++){
        for(int j=1; j<=QColumns; j++){
            PosN=GetPositionInArrayOf2DRealizedBy1D(QExtRows, QIneRows, i, j);
            val=arr[PosN-1];
            this->SetComponent(val, i, j);
        }
    }
}
//void Matrix_Prototype::Set_byLC(std::vector<double>arr, int QLines){//os err ob n'veds str o'matrix, qo wi ext et qo wi ine rows!
//    int QExtRows=QLines;
//    this->Set_byEIR(arr, QExtRows);
//}
void Matrix_Prototype::Set_byCL(std::vector<double>arr, int QColumns){
    int QElts=arr.size();
    int QLines=QElts/QColumns;
    int PosN, QExtRows=QColumns, QIneRows=QLines;
    double val;
    this->SetSize_Matrix(0.0, QLines, QColumns);
    for(int i=1; i<=QLines; i++){
        for(int j=1; j<=QColumns; j++){
            PosN=GetPositionInArrayOf2DRealizedBy1D(QExtRows, QIneRows, i, j);
            val=arr[PosN-1];
            this->SetComponent(val, i, j);
        }
    }
}

void Matrix_Prototype::Set_byEIR(std::vector<std::vector<double>>arr, int ifLNE_ExtRows_By_Max3Min4){
    int curL, QExtRows=arr.size(), QIneRows, Lmax, Lmin, minL;
    double val;
    for(int i=1; i<=QExtRows; i++){
        curL=arr[i-1].size();
        if(i==1 || ((i>1)&&(curL>Lmax))){
            Lmax=curL;
        }
        if(i==1 || ((i>1)&&(curL<Lmin))){
            Lmin=curL;
        }
    }
    if(Lmax!=Lmin){
        switch(ifLNE_ExtRows_By_Max3Min4){
            case 3:
                QIneRows=Lmax;
            break;
            case 4:
                QIneRows=Lmin;
            break;
        }
    }else{
        QIneRows=Lmax;
    }
    this->SetSize_Array(QExtRows, QIneRows);
    for(int i=1; i<=QExtRows; i++){
        curL=arr[i-1].size();
        minL = curL >= QIneRows ? curL : QIneRows;
        for(int j=1; j<=minL; j++){
            val=arr[i-1][j-1];
            this->SetComponent_byEI(val, i, j);
        }
        for(int j=minL+1; j<=QIneRows; j++){
            val=0.0;
            this->SetComponent_byEI(val, i, j);
        }
    }
}

void Matrix_Prototype::Set_byLC(std::vector<std::vector<double>>arr, int ifLNE_Lines_By_Max3Min4){
    int curL, QLines=arr.size(), QColumns, Lmax, Lmin, minL;
    double val;
    for(int i=1; i<=QLines; i++){
        curL=arr[i-1].size();
        if(i==1 || ((i>1)&&(curL>Lmax))){
            Lmax=curL;
        }
        if(i==1 || ((i>1)&&(curL<Lmin))){
            Lmin=curL;
        }
    }
    if(Lmax!=Lmin){
        switch(ifLNE_Lines_By_Max3Min4){
            case 3:
                QColumns=Lmax;
            break;
            case 4:
                QColumns=Lmin;
            break;
        }
    }else{
        QColumns=Lmax;
    }
    this->SetSize_Matrix(QLines, QColumns);
    for(int i=1; i<=QLines; i++){
        curL=arr[i-1].size();
        minL = curL >= QColumns ? curL : QColumns;
        for(int j=1; j<=minL; j++){
            val=arr[i-1][j-1];
            this->SetComponent(val, i, j);
        }
        for(int j=minL+1; j<=QColumns; j++){
            val=0.0;
            this->SetComponent(val, i, j);
        }
    }
}
void Matrix_Prototype::Set_byCL(std::vector<std::vector<double>>arr, int ifLNE_Columns_By_Max3Min4){
    int curL, QLines, QColumns=arr.size(), Lmax, Lmin, minL;
    double val;
    for(int i=1; i<=QColumns; i++){
        curL=arr[i-1].size();
        if(i==1 || ((i>1)&&(curL>Lmax))){
            Lmax=curL;
        }
        if(i==1 || ((i>1)&&(curL<Lmin))){
            Lmin=curL;
        }
    }
    if(Lmax!=Lmin){
        switch(ifLNE_Columns_By_Max3Min4){
            case 3:
                QLines=Lmax;
            break;
            case 4:
                QLines=Lmin;
            break;
        }
    }else{
        QLines=Lmax;
    }
    this->SetSize_Matrix(QLines, QColumns);
    for(int i=1; i<=QColumns; i++){
        curL=arr[i-1].size();
        minL = curL >= QLines ? curL : QLines;
        for(int j=1; j<=minL; j++){
            val=arr[i-1][j-1];
            this->SetComponent(val, j, i);
        }
        for(int j=minL+1; j<=QLines; j++){
            val=0.0;
            this->SetComponent(val, j, i);
        }
    }
}

//
// Swap
//
void Matrix_Prototype::SwapVals_byEI(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2){
    int QExtRows=this->GetQExtRows(), rowL=this->GetLength(), L1=rowL, L2=rowL;
    double val1, val2, buf;
    if(ExtRowN1<0){
       ExtRowN1+=(QExtRows+1);
    }
    if(ExtRowN2<0){
       ExtRowN2+=(QExtRows+1);
    }
    if(ExtRowN1>=1 && ExtRowN1<=QExtRows && ExtRowN2>=1 && ExtRowN2<=QExtRows){
        //L1=this->GetLength(ExtRowN1);
        //L2=this->GetLength(ExtRowN2);
        if(IneRowN1>=1 && IneRowN1<=L1 && IneRowN2>=1 && IneRowN2<=L2){
            val1=this->GetComponent_AsVal_byEI(ExtRowN1, IneRowN1);
            val2=this->GetComponent_AsVal_byEI(ExtRowN2, IneRowN2);
            //
            buf=val1;
            val1=val2;
            val2=buf;
            //
            this->SetComponent_byEI(val1, ExtRowN1, IneRowN1);
            this->SetComponent_byEI(val2, ExtRowN2, IneRowN2);
        }
    }
}
void Matrix_Prototype::SwapVals_byLC(int LineN1, int ColN1, int LineN2, int ColN2){
    int QLines=this->GetQLines(), QColumns=this->GetQColumns(), L1=QColumns, L2=QColumns;
    double val1, val2, buf;
    if(LineN1<0){
       LineN1+=(QLines+1);
    }
    if(LineN2<0){
       LineN2+=(QLines+1);
    }
    if(LineN1>=1 && LineN1<=QLines && LineN2>=1 && LineN2<=QLines){
        //L1=this->GetLength(ExtRowN1);
        //L2=this->GetLength(ExtRowN2);
        if(ColN1>=1 && ColN1<=L1 && ColN2>=1 && ColN2<=L2){
            val1=this->GetComponent(LineN1, ColN1);
            val2=this->GetComponent(LineN2, ColN2);
            //
            buf=val1;
            val1=val2;
            val2=buf;
            //
            this->SetComponent(val1, LineN1, ColN1);
            this->SetComponent(val2, LineN2, ColN2);
        }
    }
}
//
//virtual void SwapExtRows(int N1, int N2)=0;
 void Matrix_Prototype::SwapExtRows(int N1, int N2){
    //std::vector<double> row1to2, row2to1;
    int QExtRows=this->GetQExtRows(),//, Lmax=this->GetMaxLength(), L1, L2;
    Lmax=this->GetLength(), L1=Lmax, L2=Lmax;
    if(N1<0){
        N1+=(QExtRows+1);
    }
    if(N2<0){
        N2+=(QExtRows+1);
    }
    //L1=this->GetLength(N1);
    //L2=this->GetLength(N2);
    if(N1>=1 && N1<=QExtRows && N2>=1 && N2<=QExtRows){
        //row1to2=this->GetExtRowN_AsArray(N1);
        //row1to2=this->GetExtRowN_AsArray(N2);
        //this->SetExtRow_Simply(N1, row2to1.data(), row2to1.size());
        //this->SetExtRow_Simply(N2, row1to2.data(), row1to2.size());
        //
        for(int i=1; i<=Lmax; i++){
            this->SwapVals_byEI(N1, i, N2, i);
        }
    }
}
 void Matrix_Prototype::SwapLines(int N1, int N2){
    //std::vector<double> row1to2, row2to1;
    int QLines=this->GetQLines(),//, Lmax=this->GetMaxLength(), L1, L2;
    Lmax=this->GetQColumns(), L1=Lmax, L2=Lmax;
    if(N1<0){
        N1+=(QLines+1);
    }
    if(N2<0){
        N2+=(QLines+1);
    }
    //L1=this->GetLength(N1);
    //L2=this->GetLength(N2);
    if(N1>=1 && N1<=QLines && N2>=1 && N2<=QLines){
        //row1to2=this->GetExtRowN_AsArray(N1);
        //row1to2=this->GetExtRowN_AsArray(N2);
        //this->SetExtRow_Simply(N1, row2to1.data(), row2to1.size());
        //this->SetExtRow_Simply(N2, row1to2.data(), row1to2.size());
        //
        for(int i=1; i<=Lmax; i++){
            this->SwapVals_byLC(N1, i, N2, i);
        }
    }
}
//virtual void SwapExtRows_Simply(int N1, int N2)=0;
//virtual void SwapExtRows_Simply(int N1, int N2)=0;
//virtual   void SwapIneRows(int N1, int N2)=0;
void Matrix_Prototype::SwapIneRows(int N1, int N2){
    //std::vector<double> row1to2, row2to1;
    int QExtRows=this->GetQExtRows(), //Lmax=this->GetMaxLength(), Lmin=this->GetMinLength(),L1, L2;
    Lmax=this->GetLength(), Lmin=this->GetLength(),L1, L2;
    if(N1<0){
        N1+=(Lmax+1);
    }
    if(N2<0){
        N2+=(Lmax+1);
    }
    //L1=this->GetLength(N1);
    //L2=this->GetLength(N2);
    if(N1>=1 && N1<=Lmax && N2>=1 && N2<=Lmax){
        if(N1<=Lmin && N2<=Lmin){
            //row1to2=this->GetIneRowN_AsArray(N1);
            //row1to2=this->GetIneRowN_AsArray(N2);
            //this->SetIneRow_Simply(N1, row2to1.data(), row2to1.size());
            //this->SetIneRow_Simply(N2, row1to2.data(), row1to2.size());
            for(int i=1; i<=QExtRows; i++){
                this->SwapVals_byEI(N1, i, N2, i);
            }
        }
    }
}
void Matrix_Prototype::SwapColumns(int N1, int N2){
    //std::vector<double> row1to2, row2to1;
    int QLines=this->GetQLines(), QColumns=this->GetQColumns();//, Lmax=this->GetMaxLength(), Lmin=this->GetMinLength(),L1=, L2;
    if(N1<0){
        N1+=(QColumns+1);
    }
    if(N2<0){
        N2+=(QColumns+1);
    }
    //L1=this->GetLength(N1);
    //L2=this->GetLength(N2);
    if(N1>=1 && N1<=QColumns && N2>=1 && N2<=QColumns){
        //if(N1<=Lmin && N2<=Lmin){
            //row1to2=this->GetIneRowN_AsArray(N1);
            //row1to2=this->GetIneRowN_AsArray(N2);
            //this->SetIneRow_Simply(N1, row2to1.data(), row2to1.size());
            //this->SetIneRow_Simply(N2, row1to2.data(), row1to2.size());
            for(int i=1; i<=QLines; i++){
                this->SwapVals_byLC(N1, i, N2, i);
            }
        //}
    }
}
//
// Reverse
//
//void ReverseExtRowN(int rowN);
 void Matrix_Prototype::ReverseExtRowN(int rowN){
    //int curL=this->GetLength(rowN), midN, N1, N2;
    int curL=this->GetLength(), midN, N1, N2;
    if(curL>0){
        if(curL%2==0){
            midN=curL/2;
        }else{
            midN=(curL-1)/2;
        }
    }
    for(N1=1; N1<=midN; N1++){
        N2=curL-N1+1;
        this->SwapVals_byEI(rowN, N1, rowN, N2);
    }
}
 void Matrix_Prototype::ReverseLineN(int LineN){
    //int curL=this->GetLength(rowN), midN, N1, N2;
    //int curL=this->GetLength(), midN, N1, N2;
    int QColumns=this->GetQColumns(), midN, N1, N2;
    if(QColumns>0){
        if(QColumns%2==0){
            midN=QColumns/2;
        }else{
            midN=(QColumns-1)/2;
        }
    }
    for(N1=1; N1<=midN; N1++){
        N2=QColumns-N1+1;
        //void SwapVals_byLC(int LineN1, int ColN1, int LineN2, int ColN2);
         this->SwapVals_byLC(    LineN,         N1,     LineN,         N2);
    }
}
//virtual void ReverseExtRowsSuccession()=0;
//virtual void ReverseExtRowsSuccession();
 void Matrix_Prototype::ReverseIneRowN(int IneRowN){
    //Array2DSize size=this->GetSize();
    //std::vector<double>data=this->GetContent_AsArray1D();
    //int Q=size.GetQExtRows();
    int QER=this->GetQExtRows();
    int rowL=this->GetLength();
    int Lmin, Lmax, Nmid, N1, N2, IRL_fact;
    //int Lmin=size.GetMinLength(), Lmax=size.GetMaxLength(), Nmid, N1, N2, IRL_fact;
    if(IneRowN<0){
        IneRowN+=(Lmax+1);
    }
    //IRL_fact=size.LengthFactOfIneRowN_From1stToFirstStop(IneRowN);
    IRL_fact=rowL;
    //if(Q>0 && IneRowN>=1 && IneRowN<=Lmin){
    if(IRL_fact>0){
        if(IRL_fact%2==0){
            Nmid=IRL_fact/2;
        }else{
            Nmid=(IRL_fact-1)/2;
        }
        for(N1=1; N1<=Nmid; N1++){
            N2=IRL_fact-N1+1;
            //ArrayOf2DBy1D_SwapVals(data, size, N1, IneRowN, N2, IneRowN);
            this->SwapVals_byEI(N1, IneRowN, N2, IneRowN);
        }
    }
}
 void Matrix_Prototype::ReverseColumnN(int ColumnN){
    //Array2DSize size=this->GetSize();
    //std::vector<double>data=this->GetContent_AsArray1D();
    //int Q=size.GetQExtRows();
    int QL=this->GetQLines();
    int QC=this->GetQColumns();
    //int Lmin=size.GetMinLength(), Lmax=size.GetMaxLength(), Nmid, N1, N2, IRL_fact;
    int Nmid, N1, N2;
    if(ColumnN<0){
        ColumnN+=(QC+1);
    }
    //IRL_fact=size.LengthFactOfIneRowN_From1stToFirstStop(IneRowN);
    //IRL_fact=QL;
    //if(Q>0 && IneRowN>=1 && IneRowN<=Lmin){
    if(QL>0){
        if(QL%2==0){
            Nmid=QL/2;
        }else{
            Nmid=(QL-1)/2;
        }
        for(N1=1; N1<=Nmid; N1++){
            N2=QL-N1+1;
            //ArrayOf2DBy1D_SwapVals(data, size, N1, IneRowN, N2, IneRowN);
            this->SwapVals_byLC(N1, ColumnN, N2, ColumnN);
        }
    }
}

//virtual void ReverseExtRowsSuccession()=0;
//void ReverseExtRowsSuccession()
 void Matrix_Prototype::ReverseExtRowsSuccession(){
    int QExtRows=this->GetQExtRows(), rowL=this->GetLength(), midN, N1, N2;//, Lmax=this->GetMaxLength(), Lmin=this->GetMinLength()
    std::vector<double>row1, row2;
    if(N1<0){
        N1+=(QExtRows+1);
    }
    if(N2<0){
        N2+=(QExtRows+1);
    }
    if(QExtRows%2==0){
        midN=QExtRows/2;
    }else{
        midN=(QExtRows-1)/2;
    }
    for(N1=1; N1<=midN; N1++){
        N2=QExtRows-N1+1;
        row1=this->GetExtRowN_AsArray(N1);
        row2=this->GetExtRowN_AsArray(N2);
        this->SetExtRow_Simply(N1, row2.data());//, row2.size());
        this->SetExtRow_Simply(N2, row1.data());//, row1.size());
    }
}
void Matrix_Prototype::ReverseLinesSuccession(){
    //int QExtRows=this->GetQExtRows(), rowL=this->GetLength, Lmax=this->GetMaxLength(), Lmin=this->GetMinLength(), midN, N1, N2;
    int QLines=this->GetQLines(), QColumns=this->GetQColumns(), midN, N1, N2;//, Lmax=this->GetMaxLength(), Lmin=this->GetMinLength();
    std::vector<double>row1, row2;
    if(N1<0){
        N1+=(QLines+1);
    }
    if(N2<0){
        N2+=(QLines+1);
    }
    if(QLines%2==0){
        midN=QLines/2;
    }else{
        midN=(QLines-1)/2;
    }
    for(N1=1; N1<=midN; N1++){
        N2=QLines-N1+1;
        row1=this->GetLineN_AsArray(N1);
        row2=this->GetLineN_AsArray(N2);
        this->SetExtRow_Simply(N1, row2.data());//, row2.size());
        this->SetExtRow_Simply(N2, row1.data());//, row1.size());
    }
}
void Matrix_Prototype::ReverseIneRowsSuccession(){
    int QExtRows=this->GetQExtRows(), midN, N1, N2, rowL=this->GetLength();//Lmax=this->GetMaxLength(), Lmin=this->GetMinLength(),rowL=Lmax;
    std::vector<double>row1, row2;
    if(N1<0){
        N1+=(rowL+1); // N1+=(Lmax+1);
    }
    if(N2<0){
        N2+=(rowL+1); // N2+=(Lmax+1);
    }
    //if(Lmin==Lmax){
        if(QExtRows%2==0){
            midN=rowL/2; // midN=Lmax/2;
        }else{
            midN=(rowL-1)/2; //midN=(Lmax-1)/2;
        }
        for(N1=1; N1<=midN; N1++){
            //N2=Lmax-N1+1;
            N2=rowL-N1+1;
            row1=this->GetIneRowN_AsArray(N1);
            row2=this->GetIneRowN_AsArray(N2);
            this->SetExtRow_Simply(N1, row2.data());//, row2.size());
            this->SetExtRow_Simply(N2, row1.data());//, row1.size());
        }
    //}
}
void Matrix_Prototype::ReverseColumnsSuccession(){
    //int QExtRows=this->GetQExtRows(), Lmax=this->GetMaxLength(), Lmin=this->GetMinLength(), midN, N1, N2, rowL=Lmax;
    int QLines=this->GetQLines(), QColumns=this->GetQColumns(), midN, N1, N2;//, Lmax=this->GetMaxLength(), Lmin=this->GetMinLength();
    std::vector<double>row1, row2;
    if(N1<0){
        N1+=(QColumns+1);
    }
    if(N2<0){
        N2+=(QColumns+1);
    }
    //if(Lmin==Lmax){
        if(QColumns%2==0){
            midN=QColumns/2;
        }else{
            midN=(QColumns-1)/2;
        }
        for(N1=1; N1<=midN; N1++){
            N2=QColumns-N1+1;
            row1=this->GetColumnN_AsArray(N1);
            row2=this->GetColumnN_AsArray(N2);
            this->SetExtRow_Simply(N1, row2.data());//, row2.size());
            this->SetExtRow_Simply(N2, row1.data());//, row1.size());
        }
    //}
}
//
//Seek
//
bool Matrix_Prototype::ValIsAtPos_byEI(double val, int ExtRowN, int IneRowN) const{//swa di prototype n'fit. Obe s' ERN alt IRN, so ERN 2x
   bool b=false;
   int QExtRows=this->GetQExtRows(), L;
   double ownVal;
   if(ExtRowN>=1 && ExtRowN<=QExtRows){
       L=this->GetLength();//L=this->GetLength(ExtRowN);
       if(IneRowN>=1 && IneRowN<=L){
           ownVal=this->GetComponent_AsVal_byEI(ExtRowN, ExtRowN);
           if(val==ownVal){
               b=true;
           }
       }
   }
   return b;
}
bool Matrix_Prototype::ValIsAtPos_byLC(double val, int LineN, int ColN) const{
   bool b=false;
   int QLines=this->GetQLines(), QColumns=this->GetQColumns(), L=QColumns;
   double ownVal;
   if(LineN>=1 && LineN<=QLines){
       //L=this->GetLength(LineN);
       if(ColN>=1 && ColN<=QColumns){
           ownVal=this->GetComponent(LineN, ColN);
           if(val==ownVal){
               b=true;
           }
       }
   }
   return b;
}

//TListOfNumberPairs Matrix_Prototype::SeekVal_ByEI(double val) const{
//   TListOfNumberPairs Ns;
//   bool b;
//   int QExtRows=this->GetQExtRows(), L=this->GetLength();
//   for(int i=1; i<=QExtRows; i++){
//       //L=this->GetLength(i);
//       for(int j=1; j<=L; j++){
//           b=this->ValIsAtPos_byEI(val, i, j);
//           if(b==true){
//               Ns.Add(i, j);
//           }
//       }
//   }
//   return Ns;
//}
//TListOfNumberPairs Matrix_Prototype::SeekVal(double val) const{
//   TListOfNumberPairs Ns;
//   bool b;
//   int QLines=this->GetQLines(), QColumns=this->GetQColumns(), L=QColumns;
//   for(int i=1; i<=QLines; i++){
//       //L=this->GetLength(i);
//       for(int j=1; j<=L; j++){
//           b=this->ValIsAtPos_byLC(val, i, j);
//           if(b==true){
//               Ns.Add(i, j);
//           }
//       }
//   }
//   return Ns;
//}
 std::vector<std::vector<int>> Matrix_Prototype::SeekVal_ByEI(double val) const{
   std::vector<std::vector<int>> Ns;
   std::vector<int>pair;
   bool b;
   int QExtRows=this->GetQExtRows(), L=this->GetLength();
   for(int i=1; i<=QExtRows; i++){
       //L=this->GetLength(i);
       for(int j=1; j<=L; j++){
           b=this->ValIsAtPos_byEI(val, i, j);
           if(b==true){
               pair.clear();
               pair.push_back(i);
               pair.push_back(j);
               Ns.push_back(pair);
               //Ns.Add(i, j);
           }
       }
   }
   return Ns;
}
std::vector<std::vector<int>> Matrix_Prototype::SeekVal(double val) const{
    std::vector<std::vector<int>> Ns;
    std::vector<int>pair;
    bool b;
    int QLines=this->GetQLines(), QColumns=this->GetQColumns(), L=QColumns;
    for(int i=1; i<=QLines; i++){
        //L=this->GetLength(i);
        for(int j=1; j<=L; j++){
            b=this->ValIsAtPos_byLC(val, i, j);
            if(b==true){
                pair.clear();
                pair.push_back(i);
                pair.push_back(j);
                Ns.push_back(pair);
                //Ns.Add(i, j);
            }
        }
    }
    return Ns;
}
bool Matrix_Prototype::ExtRowIsAtPos(double*row, int Q, int ExtRowN, int IneRowN) const{
   bool b=true;
   int QExtRows=this->GetQExtRows(), L=this->GetLength();
   double ownVal;
   if(ExtRowN>=1 && ExtRowN<=QExtRows){
       //L=this->GetLength(ExtRowN);
       if(IneRowN>=1 && IneRowN+Q-1<=L){
           for(int i=1; i<=Q; i++){
               ownVal=this->GetComponent_AsVal_byEI(ExtRowN, IneRowN+i-1);
               if(!(ownVal==row[i-1])){
                   b=false;
               }
           }
       }
   }
   return b;
}
bool Matrix_Prototype::LineIsAtPos(double*row, int Q, int LineN, int ColN) const{
   bool b=true;
   int QLines=this->GetQLines(), QColumns=this->GetQColumns();//, L=this->GetLength();
   double ownVal;
   if(LineN>=1 && LineN<=QLines){
       //L=this->GetLength(ExtRowN);
       if(ColN>=1 && ColN+Q-1<=QColumns){
           for(int i=1; i<=Q; i++){
               ownVal=this->GetComponent(LineN, ColN+i-1);
               if(!(ownVal==row[i-1])){
                   b=false;
               }
           }
       }
   }
   return b;
}

std::vector<std::vector<int>> Matrix_Prototype::SeekExtRow(double*row, int rowL) const{
    std::vector<std::vector<int>> Ns;
    std::vector<int>pair;
    bool b;
    int QExtRows=this->GetQExtRows(), curL=this->GetLength();
    for(int i=1; i<=QExtRows; i++){
        //curL=this->GetLength(i);
        for(int j=1; j<=curL-rowL+1; j++){
            b=this->ExtRowIsAtPos(row, rowL, i, j);
            if(b==true){
                pair.clear();
                pair.push_back(i);
                pair.push_back(j);
                Ns.push_back(pair);
                //Ns.Add(i, j);
            }
        }
    }
    return Ns;
}
std::vector<std::vector<int>> Matrix_Prototype::SeekLine(double*row, int rowL) const{
    std::vector<std::vector<int>> Ns;
    std::vector<int>pair;
    bool b;
    int QLines=this->GetQLines(), QColumns=this->GetQColumns();//, curL=this->GetLength();
    for(int i=1; i<=QLines; i++){
        //curL=this->GetLength(i);
        for(int j=1; j<=QColumns-rowL+1; j++){
            b=this->LineIsAtPos(row, rowL, i, j);
            if(b==true){
                pair.clear();
                pair.push_back(i);
                pair.push_back(j);
                Ns.push_back(pair);
                //Ns.Add(i, j);
            }
        }
    }
    return Ns;
}
 bool Matrix_Prototype::IneRowIsAtPos(double*row, int Q, int ExtRowN, int IneRowN) const{
    bool b=true;
    int QExtRows=this->GetQExtRows(), L=this->GetLength();
    double ownVal;
    if(ExtRowN>=1 && ExtRowN+Q-1<=QExtRows){
        //L=this->GetLength(ExtRowN);
        if(IneRowN>=1 && IneRowN<=L){
            for(int i=1; i<=Q; i++){
                //L=this->GetLength(i);
                if(IneRowN>L){
                    b=false;
                }
            }
            if(b==true){
                for(int i=1; i<=Q; i++){
                    ownVal=this->GetComponent_AsVal_byEI(ExtRowN+i-1, IneRowN);
                    if(!(ownVal==row[i-1])){
                        b=false;
                    }
                }
            }
        }
    }
    return b;
}
 bool Matrix_Prototype::ColumnIsAtPos(double*row, int Q, int LineN, int ColN) const{
    bool b=true;
    int QLines=this->GetQLines(), QColumns=this->GetQColumns(), L=QColumns;
    double ownVal;
    if(LineN>=1 && LineN+Q-1<=QLines){
        //L=this->GetLength(ExtRowN);
        if(ColN>=1 && ColN<=L){
            for(int i=1; i<=Q; i++){
                //L=this->GetLength(i);
                if(ColN>L){
                    b=false;
                }
            }
            if(b==true){
                for(int i=1; i<=Q; i++){
                    ownVal=this->GetComponent(LineN+i-1, ColN);
                    if(!(ownVal==row[i-1])){
                        b=false;
                    }
                }
            }
        }
    }
    return b;
}

 std::vector<std::vector<int>> Matrix_Prototype::SeekIneRow(double*row, int Q) const{
    std::vector<std::vector<int>> Ns;
    std::vector<int>pair;
    bool b;
    int QExtRows=this->GetQExtRows(), L=this->GetLength();
    for(int i=1; i<=QExtRows-Q+1; i++){
        //L=this->GetLength(i);
        for(int j=1; j<=L; j++){
            b=this->IneRowIsAtPos(row, Q, i, j);//wa err: ext - mab in prototype array es idem err
            if(b==true){
                pair.clear();
                pair.push_back(i);
                pair.push_back(j);
                Ns.push_back(pair);
                //Ns.Add(i, j);
            }
        }
    }
    return Ns;
}
std::vector<std::vector<int>> Matrix_Prototype::SeekColumn(double*row, int Q) const{
    std::vector<std::vector<int>> Ns;
    std::vector<int>pair;
    bool b;
    int QLines=this->GetQLines(), QColumns=this->GetQColumns(), L=QColumns;
    for(int i=1; i<=QLines-Q+1; i++){
        //L=this->GetLength(i);
        for(int j=1; j<=L; j++){
            b=this->ColumnIsAtPos(row, Q, i, j);
            if(b==true){
                pair.clear();
                pair.push_back(i);
                pair.push_back(j);
                Ns.push_back(pair);
                //Ns.Add(i, j);
            }
        }
    }
    return Ns;
}

bool Matrix_Prototype::Arr2DIsAtPos_byEI(std::vector<std::vector<double>>arr, int ExtRowN, int IneRowN, bool isNotTransposed, bool ExtRowsSuccIsNotReversed, bool EachExtRowIsNotReversed) const{
    //Array2DSize sizeWhere=this->GetSize(), sizeWhat=size;//GetSizeOf2DVector(arr);
    int QERWhere=this->GetQExtRows(), QERWhat=arr.size(), LmaxWhere=this->GetLength(), LmaxWhat;
    int whereExtRowN, whereIneRowN, whatExtRowN, whatIneRowN, WhereCurL=this->GetLength(), WhatCurL;
    double whereVal, whatVal;
    Int2DVectorOfSizeOrCoords WhereFromCoords, WhatCoords, WhereToCoords;
    bool b=true;
    WhereFromCoords.d1=ExtRowN;
    WhereFromCoords.d2=IneRowN;
    for(whatExtRowN=1; whatExtRowN<=QERWhat; whatExtRowN++){
        WhatCurL=arr[whatExtRowN-1].size();
        if(whatExtRowN==1 || (whatExtRowN>1 && WhatCurL>LmaxWhat)){
            LmaxWhat=WhatCurL;
        }
    }
    for(whatExtRowN=1; whatExtRowN<=QERWhat; whatExtRowN++){
        //WhatCurL=sizeWhat.GetLength(whatExtRowN);
        WhatCurL=arr[whatExtRowN-1].size();
        for(whatIneRowN=1; whatIneRowN<=WhatCurL; whatIneRowN++){
            WhatCoords.d1=whatExtRowN;
            WhatCoords.d2=whatIneRowN;
            WhereToCoords=Array2DCoordsTransform(WhereFromCoords, WhatCoords, isNotTransposed, ExtRowsSuccIsNotReversed, EachExtRowIsNotReversed);
            whereExtRowN=WhereToCoords.d1;
            whereIneRowN=WhereToCoords.d2;
            //WhereCurL=sizeWhere.GetLength(whereExtRowN);
            if(whereExtRowN>=1 && whereExtRowN<=QERWhere && whereIneRowN>=1 && whereIneRowN<=WhereCurL){
                whereVal=this->GetComponent_AsVal_byEI(whereExtRowN, whereIneRowN);
                //whatVal=ArrayOf2DBy1D_GetElement_AsVal(arr, sizeWhat, WhereToCoords.d1, WhereToCoords.d2);
                whatVal=arr[whatExtRowN-1][whatIneRowN-1];
                if(!(whereVal==whatVal)){
                    b=false;
                }
            }else{
                b=false;
            }
        }
    }
    return b;
}
bool Matrix_Prototype::Arr2DIsAtPos_byLC(std::vector<std::vector<double>>arr, int LineN, int ColN, bool isNotTransposed, bool ExtRowsSuccIsNotReversed, bool EachExtRowIsNotReversed) const{
    //Array2DSize sizeWhere=this->GetSize(), sizeWhat=size;//GetSizeOf2DVector(arr);
    //int QERWhere=this->GetQExtRows(), QERWhat=arr.size(), LmaxWhere=this->GetLength(),
    int LmaxWhat, WhereCurL=this->GetLength();
    //int whereExtRowN, whereIneRowN, whatExtRowN, whatIneRowN, WhereCurL=this->GetLength(), WhatCurL;
    int QLWhere=this->GetQLines(), QLWhat=arr.size(), QColumns=this->GetQColumns(), WhatCurL=QColumns;
    int whereLineN, whereColN, whatLineN, whatColN;
    double whereVal, whatVal;
    Int2DVectorOfSizeOrCoords WhereFromCoords, WhatCoords, WhereToCoords;
    bool b=true;
    WhereFromCoords.d1=LineN;
    WhereFromCoords.d2=ColN;
    for(whatLineN=1; whatLineN<=QLWhat; whatLineN++){
        WhatCurL=arr[whatLineN-1].size();
        if(whatLineN==1 || (whatLineN>1 && WhatCurL>LmaxWhat)){
            LmaxWhat=WhatCurL;
        }
    }
    for(whatLineN=1; whatLineN<=QLWhat; whatLineN++){
        //WhatCurL=sizeWhat.GetLength(whatExtRowN);
        WhatCurL=arr[whatLineN-1].size();
        for(whatColN=1; whatColN<=WhatCurL; whatColN++){
            WhatCoords.d1=whatLineN;
            WhatCoords.d2=whatColN;
            WhereToCoords=Array2DCoordsTransform(WhereFromCoords, WhatCoords, isNotTransposed, ExtRowsSuccIsNotReversed, EachExtRowIsNotReversed);
            whereLineN=WhereToCoords.d1;
            whereColN=WhereToCoords.d2;
            //WhereCurL=sizeWhere.GetLength(whereExtRowN);
            if(whereLineN>=1 && whereLineN<=QLWhere && whereColN>=1 && whereColN<=WhereCurL){
                whereVal=this->GetComponent(whereLineN, whereColN);
                //whatVal=ArrayOf2DBy1D_GetElement_AsVal(arr, sizeWhat, WhereToCoords.d1, WhereToCoords.d2);
                whatVal=arr[whatLineN-1][whatColN-1];
                if(!(whereVal==whatVal)){
                    b=false;
                }
            }else{
                b=false;
            }
        }
    }
    return b;
}

std::vector<std::vector<int>> Matrix_Prototype::SeekArr2D_byEI(std::vector<std::vector<double>>arr, bool isNotTransposed, bool ExtRowsSuccIsNotReversed, bool EachExtRowIsNotReversed) const{
    std::vector<std::vector<int>> NsPairs;
    std::vector<int>pair;
    bool b;
    int QExtRowsWhere=this->GetQExtRows(), QExtRowsWhat=arr.size(), curLWhere=this->GetLength(), //curLWhat,
        whereExtRowN, whereIneRowN, whatExtRowN, whatIneRowN;
    for(whereExtRowN=1; whereExtRowN<=QExtRowsWhere; whereExtRowN++){
        //curL in Matrix s'const for all ExtRows
        for(whereIneRowN=1; whereIneRowN<=curLWhere; whereIneRowN++){
            //curL in Matrix s'const for all ExtRows
            b=this->Arr2DIsAtPos_byEI(arr, whereExtRowN, whereIneRowN, isNotTransposed, ExtRowsSuccIsNotReversed, EachExtRowIsNotReversed);
            if(b){
                pair.clear();
                pair.push_back(whereExtRowN);
                pair.push_back(whereIneRowN);
                NsPairs.push_back(pair);
                //NsPairs.Add(whereExtRowN, whereIneRowN);
            }
        }
    }
    return NsPairs;
}
std::vector<std::vector<int>> Matrix_Prototype::SeekArr2D_byLC(std::vector<std::vector<double>>arr, bool isNotTransposed, bool ExtRowsSuccIsNotReversed, bool EachExtRowIsNotReversed) const{
    std::vector<std::vector<int>> NsPairs;
    std::vector<int>pair;
    bool b;
    int QLinesWhere=this->GetQLines(), QLinesWhat=arr.size(), QColsWhere=this->GetLength(), //curLWhat,
        whereLineN, whereColN, whatLinewN, whatColN;
    for(whereLineN=1; whereLineN<=QLinesWhere; whereLineN++){
        //curL in Matrix s'const for all ExtRows
        for(whereColN=1; whereColN<=QColsWhere; whereColN++){
            //curL in Matrix s'const for all ExtRows
            b=this->Arr2DIsAtPos_byLC(arr, whereLineN, whereColN, isNotTransposed, ExtRowsSuccIsNotReversed, EachExtRowIsNotReversed);
            if(b){
                pair.clear();
                pair.push_back(whereLineN);
                pair.push_back(whereColN);
                NsPairs.push_back(pair);
                //NsPairs.Add(whereExtRowN, whereIneRowN);
            }
        }
    }
    return NsPairs;
}
//
//Submatrix
//
std::vector<double> Matrix_Prototype::SubMatrix_As1DArr_ByEINs_NurBelonging(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2){
    std::vector<double>data, row;
    //std::vector<std::vector<double>>data;
    double val;
    int QExtRows=this->GetQExtRows(), RowL=this->GetLength();
    if(ExtRowN1<0){
        ExtRowN1+=(QExtRows+1);
    }
    if(ExtRowN2<0){
        ExtRowN2+=(QExtRows+1);
    }
    if(IneRowN1<0){
        IneRowN1+=(RowL+1);
    }
    if(IneRowN2<0){
        IneRowN2+=(RowL+1);
    }
    if(ExtRowN1>=1 && ExtRowN1<=QExtRows && ExtRowN2>=1 && ExtRowN2<=QExtRows && IneRowN1>=1 && IneRowN1<=RowL && IneRowN2>=1 && IneRowN2<=RowL){
        if(ExtRowN1<=ExtRowN2){
            if(IneRowN1<=IneRowN2){
                for(int i=ExtRowN1; i<=ExtRowN2; i++){
                    //row.clear();
                    for(int j=IneRowN1; j<=IneRowN2; j++){
                        val=this->GetComponent_AsVal_byEI(i, j);
                        data.push_back(val);
                    }
                    //data.push_back(row);
                }
            }else{
                for(int i=ExtRowN1; i<=ExtRowN2; i++){
                    row.clear();
                    for(int j=IneRowN1; j>=IneRowN2; j--){
                        val=this->GetComponent_AsVal_byEI(i, j);
                        data.push_back(val);
                    }
                    //data.push_back(row);
                }
            }
        }else{
            if(IneRowN1<=IneRowN2){
                for(int i=ExtRowN1; i>=ExtRowN2; i--){
                    //row.clear();
                    for(int j=IneRowN1; j<=IneRowN2; j++){
                        val=this->GetComponent_AsVal_byEI(i, j);
                        data.push_back(val);
                    }
                    //data.push_back(row);
                }
            }else{
                for(int i=ExtRowN1; i>=ExtRowN2; i--){
                    //row.clear();
                    for(int j=IneRowN1; j>=IneRowN2; j--){
                        val=this->GetComponent_AsVal_byEI(i, j);
                        data.push_back(val);
                    }
                    //data.push_back(row);
                }
            } //if IneRow
        }//if ExtRow
    }//if range belongs
    return data;
}
std::vector<double> Matrix_Prototype::SubMatrix_As1DArr_ByLCNs_NurBelonging(int LineN1, int ColN1, int LineN2, int ColN2){
    std::vector<double>data;//, row;
    //std::vector<std::vector<double>>data;
    double val;
    int QLines=this->GetQLines(), RowL=this->GetQColumns();
    if(LineN1<0){
        LineN1+=(QLines+1);
    }
    if(LineN2<0){
        LineN2+=(QLines+1);
    }
    if(ColN1<0){
        ColN1+=(RowL+1);
    }
    if(ColN2<0){
        ColN2+=(RowL+1);
    }
    if(LineN1>=1 && LineN1<=QLines && LineN2>=1 && LineN2<=QLines && ColN1>=1 && ColN1<=RowL && ColN2>=1 && ColN2<=RowL){
        if(LineN1<=LineN2){
            if(ColN1<=ColN2){
                for(int i=LineN1; i<=LineN2; i++){
                    //row.clear();
                    for(int j=ColN1; j<=ColN2; j++){
                        val=this->GetComponent(i, j);
                        data.push_back(val);
                    }
                    //data.push_back(row);
                }
            }else{
                for(int i=LineN1; i<=LineN2; i++){
                    //row.clear();
                    for(int j=ColN1; j>=ColN2; j--){
                        val=this->GetComponent(i, j);
                        data.push_back(val);
                    }
                    //data.push_back(row);
                }
            }
        }else{
            if(ColN1<=ColN2){
                for(int i=LineN1; i>=LineN2; i--){
                    //row.clear();
                    for(int j=ColN1; j<=ColN2; j++){
                        val=this->GetComponent(i, j);
                        data.push_back(val);
                    }
                    //data.push_back(row);
                }
            }else{
                for(int i=LineN1; i>=LineN2; i--){
                    //row.clear();
                    for(int j=ColN1; j>=ColN2; j--){
                        val=this->GetComponent(i, j);
                        data.push_back(val);
                    }
                    //data.push_back(row);
                }
            } //if Col
        }//if Line
    }//if range belongs
    return data;
}
std::vector<double> Matrix_Prototype::SubMatrix_As1DArr_ByCLNs_NurBelonging(int LineN1, int ColN1, int LineN2, int ColN2){
    std::vector<double>data;//, row;
    //std::vector<std::vector<double>>data;
    double val;
    int QLines=this->GetQLines(), RowL=this->GetQColumns();
    if(LineN1<0){
        LineN1+=(QLines+1);
    }
    if(LineN2<0){
        LineN2+=(QLines+1);
    }
    if(ColN1<0){
        ColN1+=(RowL+1);
    }
    if(ColN2<0){
        ColN2+=(RowL+1);
    }
    if(LineN1>=1 && LineN1<=QLines && LineN2>=1 && LineN2<=QLines && ColN1>=1 && ColN1<=RowL && ColN2>=1 && ColN2<=RowL){
        if(ColN1<=ColN2){//if(LineN1<=LineN2){
            if(LineN1<=LineN2){//if(ColN1<=ColN2){
                for(int j=ColN1; j<=ColN2; j++){//for(int i=LineN1; i<=LineN2; i++){
                    //row.clear();
                    for(int i=LineN1; i<=LineN2; i++){//for(int j=ColN1; j<=ColN2; j++){
                        val=this->GetComponent(i, j);
                        data.push_back(val);
                    }
                    //data.push_back(row);
                }
            }else{
                for(int j=ColN1; j<=ColN2; j++){
                    //row.clear();
                    for(int i=LineN1; i>=LineN2; i--){
                        val=this->GetComponent(i, j);
                        data.push_back(val);
                    }
                    //data.push_back(row);
                }
            }
        }else{
            if(LineN1<=LineN2){
                 for(int j=ColN1; j>=ColN2; j--){
                    //row.clear();
                    for(int i=LineN1; i<=LineN2; i++){
                        val=this->GetComponent(i, j);
                        data.push_back(val);
                    }
                    //data.push_back(row);
                }
            }else{
                for(int j=ColN1; j>=ColN2; j--){
                    //row.clear();
                    for(int i=LineN1; i>=LineN2; i--){
                        val=this->GetComponent(i, j);
                        data.push_back(val);
                    }
                    //data.push_back(row);
                }
            } //if Line
        }//if Col
    }//if range belongs
    return data;
}
std::vector<std::vector<double>> Matrix_Prototype::SubMatrix_As2DArr_ByEINs_NurBelonging(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2){
    std::vector<double>row;
    std::vector<std::vector<double>>data;
    double val;
    //int MaxERN1, MaxIRN1, MinIRN2, MinIRN2;
    int MaxERN1, MinIRN2;
    int QExtRows=this->GetQExtRows(), RowL=this->GetLength();
    if(ExtRowN1<0){
        ExtRowN1+=(QExtRows+1);
    }
    if(ExtRowN2<0){
        ExtRowN2+=(QExtRows+1);
    }
    if(IneRowN1<0){
        IneRowN1+=(RowL+1);
    }
    if(IneRowN2<0){
        IneRowN2+=(RowL+1);
    }
    if(ExtRowN1>=1 && ExtRowN1<=QExtRows && ExtRowN2>=1 && ExtRowN2<=QExtRows && IneRowN1>=1 && IneRowN1<=RowL && IneRowN2>=1 && IneRowN2<=RowL){
        if(ExtRowN1<=ExtRowN2){
            MaxERN1 = 1 >= ExtRowN1 ? 1 : ExtRowN1;
            if(IneRowN1<=IneRowN2){
                MinIRN2 = IneRowN2 <= RowL ? IneRowN2 : RowL;
                //for(int i=ExtRowN1; i<=0; i++){
                //
                //}
                for(int i=MaxERN1; i<=ExtRowN2; i++){
                    row.clear();
                    for(int j=IneRowN1; j<=IneRowN2; j++){
                        val=this->GetComponent_AsVal_byEI(i, j);
                        row.push_back(val);
                    }
                    data.push_back(row);
                }
            }else{
                for(int i=ExtRowN1; i<=ExtRowN2; i++){
                    row.clear();
                    for(int j=IneRowN1; j>=IneRowN2; j--){
                        val=this->GetComponent_AsVal_byEI(i, j);
                        row.push_back(val);
                    }
                    data.push_back(row);
                }
            }
        }else{
            if(IneRowN1<=IneRowN2){
                for(int i=ExtRowN1; i>=ExtRowN2; i--){
                    row.clear();
                    for(int j=IneRowN1; j<=IneRowN2; j++){
                        val=this->GetComponent_AsVal_byEI(i, j);
                        row.push_back(val);
                    }
                    data.push_back(row);
                }
            }else{
                for(int i=ExtRowN1; i>=ExtRowN2; i--){
                    row.clear();
                    for(int j=IneRowN1; j>=IneRowN2; j--){
                        val=this->GetComponent_AsVal_byEI(i, j);
                        row.push_back(val);
                    }
                    data.push_back(row);
                }
            } //if IneRow
        }//if ExtRow
    }//if range belongs
    return data;
}//fn
std::vector<std::vector<double>> Matrix_Prototype::SubMatrix_As2DArr_ByLCNs_NurBelonging(int LineN1, int ColN1, int LineN2, int ColN2){
    std::vector<double> row;
    std::vector<std::vector<double>>data;
    double val;
    int QLines=this->GetQLines(), RowL=this->GetQColumns();
    if(LineN1<0){
        LineN1+=(QLines+1);
    }
    if(LineN2<0){
        LineN2+=(QLines+1);
    }
    if(ColN1<0){
        ColN1+=(RowL+1);
    }
    if(ColN2<0){
        ColN2+=(RowL+1);
    }
    if(LineN1>=1 && LineN1<=QLines && LineN2>=1 && LineN2<=QLines && ColN1>=1 && ColN1<=RowL && ColN2>=1 && ColN2<=RowL){
        if(LineN1<=LineN2){
            if(ColN1<=ColN2){
                for(int i=LineN1; i<=LineN2; i++){
                    row.clear();
                    for(int j=ColN1; j<=ColN2; j++){
                        val=this->GetComponent(i, j);
                        row.push_back(val);
                    }
                    data.push_back(row);
                }
            }else{
                for(int i=LineN1; i<=LineN2; i++){
                    row.clear();
                    for(int j=ColN1; j>=ColN2; j--){
                        val=this->GetComponent(i, j);
                        row.push_back(val);
                    }
                    data.push_back(row);
                }
            }
        }else{
            if(ColN1<=ColN2){
                for(int i=LineN1; i>=LineN2; i--){
                    row.clear();
                    for(int j=ColN1; j<=ColN2; j++){
                        val=this->GetComponent(i, j);
                        row.push_back(val);
                    }
                    data.push_back(row);
                }
            }else{
                for(int i=LineN1; i>=LineN2; i--){
                    row.clear();
                    for(int j=ColN1; j>=ColN2; j--){
                        val=this->GetComponent(i, j);
                        row.push_back(val);
                    }
                    data.push_back(row);
                }
            } //if Col
        }//if Line
    }//if range belongs
    return data;
}
std::vector<std::vector<double>> Matrix_Prototype::SubMatrix_As2DArr_ByCLNs_NurBelonging(int LineN1, int ColN1, int LineN2, int ColN2){
    std::vector<double> row;
    std::vector<std::vector<double>>data;
    double val;
    int QLines=this->GetQLines(), RowL=this->GetQColumns();
    if(LineN1<0){
        LineN1+=(QLines+1);
    }
    if(LineN2<0){
        LineN2+=(QLines+1);
    }
    if(ColN1<0){
        ColN1+=(RowL+1);
    }
    if(ColN2<0){
        ColN2+=(RowL+1);
    }
    if(LineN1>=1 && LineN1<=QLines && LineN2>=1 && LineN2<=QLines && ColN1>=1 && ColN1<=RowL && ColN2>=1 && ColN2<=RowL){
        if(ColN1<=ColN2){//if(LineN1<=LineN2){
            if(LineN1<=LineN2){//if(ColN1<=ColN2){
                for(int j=ColN1; j<=ColN2; j++){//for(int i=LineN1; i<=LineN2; i++){
                    row.clear();
                    for(int i=LineN1; i<=LineN2; i++){//for(int j=ColN1; j<=ColN2; j++){
                        val=this->GetComponent(i, j);
                        row.push_back(val);
                    }
                    data.push_back(row);//qob wa coment'd?
                }
            }else{
                for(int j=ColN1; j<=ColN2; j++){
                    row.clear();
                    for(int i=LineN1; i>=LineN2; i--){
                        val=this->GetComponent(i, j);
                        row.push_back(val);
                    }
                    data.push_back(row);
                }
            }
        }else{
            if(LineN1<=LineN2){
                 for(int j=ColN1; j>=ColN2; j--){
                    row.clear();
                    for(int i=LineN1; i<=LineN2; i++){
                        val=this->GetComponent(i, j);
                        row.push_back(val);
                    }
                    data.push_back(row);
                }
            }else{
                for(int j=ColN1; j>=ColN2; j--){
                    row.clear();
                    for(int i=LineN1; i>=LineN2; i--){
                        val=this->GetComponent(i, j);
                        row.push_back(val);
                    }
                    data.push_back(row);
                }
            } //if Line
        }//if Col
    }//if range belongs
    return data;
}

std::vector<std::vector<double>> Matrix_Prototype::SubMatrixAsSuccOfRows_AsArr2D_byEI(TParamsOfDataShift ShiftParams){
    int QExtRows=this->GetQExtRows(), rowL=this->GetLength();
    std::vector<std::vector<double>>data;
    std::vector<double> row;
    TParamsOfDataShiftFin Ns;
    Ns=ShiftParams.CalcParams(QExtRows);
    double val;
    if(Ns.preN2>0){
        for(int i=Ns.preN1; i<=Ns.preN2; i++){
            row.clear();
            for(int j=1; j<=rowL; j++){
                row.push_back(0.0);
            }
            data.push_back(row);
        }
    }
    if(Ns.ownN2>0){
       for(int i=Ns.ownN1; i<=Ns.ownN2; i++){
           row.clear();
           for(int j=1; j<=rowL; j++){
               val=this->GetComponent_AsVal_byEI(i, j);
               row.push_back(val);
           }
           data.push_back(row);
       }
    }
    if(Ns.postN2>0){
        for(int i=Ns.postN1; i<=Ns.postN2; i++){
            row.clear();
            for(int j=1; j<=rowL; j++){
                row.push_back(0.0);
            }
            data.push_back(row);
        }
    }
    return data;
}
std::vector<std::vector<double>> Matrix_Prototype::SubMatrixAsSuccOfRows_AsArr2D_byEI(int QReq, int FromN, int QDefaultsBefore){
    std::vector<std::vector<double>>data;
    TParamsOfDataShift ShiftParams;
    ShiftParams.QReq=QReq;
    ShiftParams.FromN=FromN;
    ShiftParams.QDefaultsBefore=QDefaultsBefore;
    data=this->SubMatrixAsSuccOfRows_AsArr2D_byEI(ShiftParams);
    return data;
}

std::vector<std::vector<double>> Matrix_Prototype::SubMatrixAsSuccOfRows_AsArr2D_byLC(TParamsOfDataShift ShiftParams){
    int QLines=this->GetQLines(), QColumns=this->GetQColumns();
    std::vector<std::vector<double>>data;
    std::vector<double> row;
    TParamsOfDataShiftFin Ns;
    Ns=ShiftParams.CalcParams(QLines);
    double val;
    if(Ns.preN2>0){
        for(int i=Ns.preN1; i<=Ns.preN2; i++){
            row.clear();
            for(int j=1; j<=QColumns; j++){
                row.push_back(0.0);
            }
            data.push_back(row);
        }
    }
    if(Ns.ownN2>0){
       for(int i=Ns.ownN1; i<=Ns.ownN2; i++){
           row.clear();
           for(int j=1; j<=QColumns; j++){
               val=this->GetComponent(i, j);
               row.push_back(val);
           }
           data.push_back(row);
       }
    }
    if(Ns.postN2>0){
        for(int i=Ns.postN1; i<=Ns.postN2; i++){
            row.clear();
            for(int j=1; j<=QColumns; j++){
                row.push_back(0.0);
            }
            data.push_back(row);
        }
    }
    return data;
}
std::vector<std::vector<double>> Matrix_Prototype::SubMatrixAsSuccOfRows_AsArr2D_byLC(int QReq, int FromN,  int QDefaultsBefore){
    std::vector<std::vector<double>>data;
    TParamsOfDataShift ShiftParams;
    ShiftParams.QReq=QReq;
    ShiftParams.FromN=FromN;
    ShiftParams.QDefaultsBefore=QDefaultsBefore;
    data=this->SubMatrixAsSuccOfRows_AsArr2D_byLC(ShiftParams);
    return data;
}
std::vector<std::vector<double>> Matrix_Prototype::SubMatrixAsSuccOfRows_AsArr2D_byCL(TParamsOfDataShift ShiftParams){
    int QLines=this->GetQLines(), QColumns=this->GetQColumns(), LineN, ColN;
    std::vector<std::vector<double>>data;
    std::vector<double> row;
    TParamsOfDataShiftFin Ns;
    Ns=ShiftParams.CalcParams(QLines);
    double val;
    if(Ns.preN2>0){
        for(ColN=Ns.preN1; ColN<=Ns.preN2; ColN++){
            row.clear();
            for(LineN=1; LineN<=QLines; LineN++){
                row.push_back(0.0);
            }
            data.push_back(row);
        }
    }
    if(Ns.ownN2>0){
       for(ColN=Ns.ownN1; ColN<=Ns.ownN2; ColN++){
           row.clear();
           for(LineN=1; LineN<=QLines; LineN++){
               val=this->GetComponent(LineN, ColN);
               row.push_back(val);
           }
           data.push_back(row);
       }
    }
    if(Ns.postN2>0){
        for(ColN=Ns.postN1; ColN<=Ns.postN2; ColN++){
            row.clear();
            for(int LineN=1; LineN<=QLines; LineN++){
                row.push_back(0.0);
            }
            data.push_back(row);
        }
    }
    return data;
}
std::vector<std::vector<double>> Matrix_Prototype::SubMatrixAsSuccOfRows_AsArr2D_byCL(int QReq, int FromN,  int QDefaultsBefore){
    std::vector<std::vector<double>>data;
    TParamsOfDataShift ShiftParams;
    ShiftParams.QReq=QReq;
    ShiftParams.FromN=FromN;
    ShiftParams.QDefaultsBefore=QDefaultsBefore;
    data=this->SubMatrixAsSuccOfRows_AsArr2D_byCL(ShiftParams);
    return data;
}

//
// Concat
//
void Matrix_Prototype::ConcatAdding_byEI(Matrix_Prototype*obj, int shiftQ, TParamsOfDataShift*DataShiftParam, double DefaultVal){
    int QExtRowsThis=this->GetQExtRows(), QExtRowsObjWas=obj->GetQExtRows(), RowLengthThis=this->GetLength(),  RowLengthObj=obj->GetLength(), QExtRowsObjFact, QExtRowsFact,  RowLengthFact;
    int whereExtRowN, whereIneRowN, whatExtRowN, whatIneRowN;
    TParamsOfDataShift DataShift;
    TParamsOfDataShiftFin DataShiftFin;
    //std::vector<double> row;
    double val;
    if(DataShiftParam!=NULL){
        DataShift=*DataShiftParam;
    }
    QExtRowsObjFact=DataShift.CalcQ(QExtRowsObjWas);
    if(shiftQ>=0){
        if(shiftQ>RowLengthThis){
            RowLengthFact = shiftQ + RowLengthObj;
        }else{
            RowLengthFact =  RowLengthThis >= shiftQ+RowLengthObj ? RowLengthThis : shiftQ+RowLengthObj;
        }
    }else{//shiftQ<0
        if(-shiftQ>RowLengthObj){
            RowLengthFact = -shiftQ + RowLengthThis;
        }else{
            RowLengthFact = -shiftQ+RowLengthThis >= RowLengthObj ? -shiftQ+RowLengthThis : RowLengthObj;
        }
        for(int i=1; i<=-shiftQ; i++){
            this->InsExtRowN(1, NULL);
        }
    }
    DataShiftFin=DataShift.CalcParams(QExtRowsObjWas);
    QExtRowsFact=QExtRowsThis+QExtRowsObjFact;
    this->SetSize_Array(QExtRowsFact, RowLengthFact);
    DataShiftFin=DataShift.CalcParams(QExtRowsObjWas);
    if(shiftQ>=0){
        if(DataShiftFin.ownN2>0){
            for(whatExtRowN=DataShiftFin.ownN1; whatExtRowN<=DataShiftFin.ownN2; whatExtRowN++){
                whereExtRowN = QExtRowsThis+1+whatExtRowN-DataShiftFin.ownN1;
                for(whatIneRowN=1; whatIneRowN<=RowLengthObj; whatIneRowN++){
                    whereIneRowN = shiftQ+whatIneRowN;
                    val=obj->GetComponent_AsVal_byEI(whatExtRowN, whatIneRowN);
                    this->SetComponent_byEI(val, whereExtRowN, whereIneRowN);
                }
            }
        }
    }else{//shiftQ<0 shiftQ ExtRows s'ins'd, ini data s'shift'd ad nod locs
        if(DataShiftFin.ownN2>0){
            for(whatExtRowN=DataShiftFin.ownN1; whatExtRowN<=DataShiftFin.ownN2; whatExtRowN++){
                whereExtRowN = QExtRowsThis+1+whatExtRowN-DataShiftFin.ownN1;
                for(whatIneRowN=1; whatIneRowN<=RowLengthObj; whatIneRowN++){
                    whereIneRowN=whatIneRowN;//ob ini s'shifted shiftQ times
                    val=obj->GetComponent_AsVal_byEI(whatExtRowN, whatIneRowN);
                    this->SetComponent_byEI(val, whereExtRowN, whereIneRowN);
                }
            }
        }
    }
}//fn
void Matrix_Prototype::ConcatAdding_byLC(Matrix_Prototype*obj, int shiftQ, TParamsOfDataShift*DataShiftParam, double DefaultVal){
    int QLinesThis=this->GetQLines(), QLinesObjWas=obj->GetQLines(), QColumnsThis=this->GetQColumns(), QColumnsObj=obj->GetQColumns(),
        QLinesObjFact, QLinesFact,  QColumnsFact;
    int whereLineN, whereColN, whatLineN, whatColN;
    TParamsOfDataShift DataShift;
    TParamsOfDataShiftFin DataShiftFin;
    //std::vector<double> row;
    double val;
    if(DataShiftParam!=NULL){
        DataShift=*DataShiftParam;
    }
    QLinesObjFact=DataShift.CalcQ(QLinesObjWas);
    if(shiftQ>=0){
        if(shiftQ>QColumnsThis){
            QColumnsFact = shiftQ + QColumnsObj;
        }else{
            QColumnsFact =  QColumnsThis >= shiftQ+QColumnsObj ? QColumnsThis : shiftQ+QColumnsObj;
        }
    }else{//shiftQ<0
        if(-shiftQ>QColumnsObj){
            QColumnsFact = -shiftQ + QColumnsThis;
        }else{
            QColumnsFact = -shiftQ+QColumnsThis >= QColumnsObj ? -shiftQ+QColumnsThis : QColumnsObj;
        }
        for(int i=1; i<=-shiftQ; i++){
            this->InsExtRow_Simply(1, NULL);
        }
    }
    QLinesFact=QLinesThis+QLinesObjFact;
    this->SetSize_Matrix(QLinesFact, QColumnsFact);
    DataShiftFin=DataShift.CalcParams(QLinesObjWas);
    if(shiftQ>=0){
        if(DataShiftFin.ownN2>0){
            for(whatLineN=DataShiftFin.ownN1; whatLineN<=DataShiftFin.ownN2; whatLineN++){
                whereLineN = QLinesThis+1+whatLineN-DataShiftFin.ownN1;
                for(whatColN=1; whatColN<=QColumnsObj; whatColN++){
                    whereColN = shiftQ+whatColN;
                    val=obj->GetComponent(whatLineN, whatColN);
                    this->SetComponent(val, whereLineN, whereColN);
                }
            }
        }
    }else{//shiftQ<0 shiftQ ExtRows s'ins'd, ini data s'shift'd ad nod locs
        if(DataShiftFin.ownN2>0){
            for(whatLineN=DataShiftFin.ownN1; whatLineN<=DataShiftFin.ownN2; whatLineN++){
                whereLineN = QLinesThis+1+whatLineN-DataShiftFin.ownN1;
                for(whatColN=1; whatColN<=QColumnsObj; whatColN++){
                    whereColN=whatColN;//ob ini s'shifted shiftQ times
                    val=obj->GetComponent(whatLineN, whatColN);
                    this->SetComponent(val, whereLineN, whereColN);
                }
            }
        }
    }
}//fn

//virtual        void  ConcatStretching(     Matrix_Prototype*obj, double DefaultVal, int QShiftedExtRowNs=0,  TParamsOfDataShift*DataShiftParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3, bool Stretch1ToMax=true, bool SetRect=true);
//void                 ConcatStretching_byEI(Matrix_Prototype*obj, int QShiftedLinesNs=0,  TParamsOfDataShift*DataShiftParam=NULL);//, double DefaultVal=0);
void Matrix_Prototype::ConcatStretching_byEI(Matrix_Prototype*obj, int shiftQ,             TParamsOfDataShift*DataShiftParam){//,          double DefaultVal){
    int QExtRowsThis=this->GetQExtRows(), QExtRowsObjWas=obj->GetQExtRows(), RowLengthThis=this->GetLength(), RowLengthObj=this->GetLength(), QExtRowsObjFact, QExtRowsFact, RowLengthFact;
    std::vector<std::vector<double>>arr;//=obj->SubMatrixAsSuccOfRows_AsArr2D_byEI(DataShiftParam);//later
    TParamsOfDataShift DataShift;
    TParamsOfDataShiftFin DataShiftFin;
    int whereExtRowN, whereIneRowN, whatExtRowN, whatIneRowN;
    double val;
    //std::vector<double> row;
    if(DataShiftParam!=NULL){
        DataShift=*DataShiftParam;
    }
    arr=obj->SubMatrixAsSuccOfRows_AsArr2D_byEI(DataShift);
    QExtRowsObjFact=DataShift.CalcQ(QExtRowsObjWas);
    RowLengthFact=RowLengthThis+RowLengthObj;
    if(shiftQ>=0){
        if(shiftQ>QExtRowsThis){
            QExtRowsFact=shiftQ+QExtRowsObjFact;
        }else{
            QExtRowsFact = shiftQ+QExtRowsObjFact >= QExtRowsThis ? shiftQ+QExtRowsObjFact : QExtRowsThis;
        }
        //this->SetSize(QExtRowsThisFact, RowLengthFact);
    }else{
        if(-shiftQ>QExtRowsObjFact){
            QExtRowsFact=shiftQ+QExtRowsThis;
        }else{
            QExtRowsFact = -shiftQ+QExtRowsObjFact >=  QExtRowsThis ? -shiftQ+QExtRowsObjFact : QExtRowsThis;
        }
        //for(int i=1; i<=RowLengthFact; i++){
        //for(int i=1; i<=RowLengthThis; i++){
        //    row.push_back(0.0);
        //}
        for(int i=1; i<=-shiftQ; i++){
            this->InsExtRow_Simply(1, NULL);
        }
    }
    DataShiftFin=DataShift.CalcParams(QExtRowsObjWas);
    this->SetSize_Array(QExtRowsFact, RowLengthFact);
    if(shiftQ>=0){
        if(DataShiftFin.ownN2>0){
            for(whatExtRowN=DataShiftFin.ownN1; whatExtRowN<=DataShiftFin.ownN2; whatExtRowN++){
                whereExtRowN=shiftQ+1+whatExtRowN-DataShiftFin.ownN1;
                for(whatIneRowN=1; whatIneRowN<=RowLengthObj; whatIneRowN++){
                    whereIneRowN=RowLengthThis+whatIneRowN;
                    //
                    val=obj->GetComponent_AsVal_byEI(whatExtRowN, whatIneRowN);
                    this->SetComponent_byEI(val, whereExtRowN, whereIneRowN);
                }
                //rest s'0s of SetSize
            }
        }
    }else{//shiftQ<0,
        if(DataShiftFin.ownN2>0){
            for(whatExtRowN=DataShiftFin.ownN1; whatExtRowN<=DataShiftFin.ownN2; whatExtRowN++){
                whereExtRowN=whatExtRowN+1-DataShiftFin.ownN1;//ab 1.ExtRow, data o'this s'shift'd
                for(whatIneRowN=1; whatIneRowN<=RowLengthObj; whatIneRowN++){
                    whereIneRowN=RowLengthThis+whatIneRowN-1;
                    //
                    val=obj->GetComponent_AsVal_byEI(whatExtRowN, whatIneRowN);
                    this->SetComponent_byEI(val, whereExtRowN, whereIneRowN);
                }
                //rest s'0s of SetSize
            }
        }
    }
}//fn concat stretching EI
void Matrix_Prototype::ConcatStretching_byLC(Matrix_Prototype*obj, int shiftQ,              TParamsOfDataShift*DataShiftParam){//, double DefaultVal){
    int QLinesThis=this->GetQLines(), QLinesObjWas=obj->GetQLines(), QColumnsThis=this->GetQColumns(), QColumnsObj=this->GetQColumns(), QLinesObjFact, QLinesFact, QColumnsFact;
    std::vector<std::vector<double>>arr;
    TParamsOfDataShift DataShift;
    int whereLineN, whereColN, whatLineN, whatColN;
    double val;
    std::vector<double> row;
    if(DataShiftParam!=NULL){
        DataShift=*DataShiftParam;
    }
    arr=obj->SubMatrixAsSuccOfRows_AsArr2D_byEI(DataShift);
    QLinesObjFact=DataShift.CalcQ(QLinesObjWas);
    QColumnsFact=QColumnsThis+QColumnsObj;
    if(shiftQ>=0){
        if(shiftQ>QLinesThis){
            QLinesFact=shiftQ+QLinesObjFact;
        }else{
            QLinesFact = shiftQ+QLinesObjFact >= QLinesThis ? shiftQ+QLinesObjFact : QLinesThis;
        }
        //this->SetSize(QExtRowsThisFact, RowLengthFact);
    }else{
        if(-shiftQ>QLinesObjFact){
            QLinesFact=shiftQ+QLinesThis;
        }else{
            QLinesFact = -shiftQ+QLinesObjFact >=  QLinesThis ? -shiftQ+QLinesObjFact : QLinesThis;
        }
        //for(int i=1; i<=RowLengthFact; i++){
        //for(int i=1; i<=QColumnsThis; i++){
        //    row.push_back(0.0);
        //}
        for(int i=1; i<=-shiftQ; i++){
            this->InsColumnN(1, NULL);
        }
    }
    this->SetSize_Matrix(QLinesFact, QColumnsFact);
    if(shiftQ>=0){
        for(int whatLineN=1; whatLineN<=QLinesObjFact; whatLineN++){
            whereLineN=shiftQ+whatLineN-1;
            for(int whatColN=1; whatColN<=QColumnsObj; whatColN++){
                whereColN=QColumnsThis+whatColN-1;
                //
                val=obj->GetComponent(whatLineN, whatColN);
                this->SetComponent(val, whereLineN, whereColN);
            }
            //rest s'0s of SetSize
        }
    }else{
        for(int whatLineN=1; whatLineN<=QLinesObjFact; whatLineN++){
            whereLineN=whatLineN;
            for(int whatColN=1; whatColN<=QColumnsObj; whatColN++){
                whereColN=QColumnsThis+whatColN-1;
                //
                val=obj->GetComponent(whatLineN, whatColN);
                this->SetComponent(val, whereLineN, whereColN);
            }
            //rest s'0s of SetSize
        }
    }
}

void Matrix_Prototype::ValSetOrAddOrFillOrIgnore_byEI(double val, int ExtRowN, int IneRowN){
    int QExtRows=this->GetQExtRows(), RowLength=this->GetLength();
    if(ExtRowN==0 && IneRowN==0){
        //fill
        for(int i=1; i<=QExtRows; i++){
            for(int j=1; j<=RowLength; j++){
                this->SetComponent_byEI(val, i, j);
            }
        }
    }else if(ExtRowN>=1 && ExtRowN<=QExtRows && IneRowN==0){
        //fill ext Row
        //for(int i=1; i<=QExtRows; i++){
        for(int j=1; j<=RowLength; j++){
            this->SetComponent_byEI(val, ExtRowN, j);
        }
    }else if(ExtRowN==QExtRows+1 && IneRowN==0){
        //ext Row add and fill
        this->AddExtRow(NULL);
        for(int j=1; j<=RowLength; j++){
            this->SetComponent_byEI(val, ExtRowN, j);
        }
    }else if(ExtRowN==0 && IneRowN>=1 && IneRowN<=RowLength){
        //fill Ine Row
        for(int i=1; i<=QExtRows; i++){
        //for(int j=1; j<=RowLength; j++){
            this->SetComponent_byEI(val, i, IneRowN);
        //}
        }
    }else if(ExtRowN>=1 && ExtRowN<=QExtRows && IneRowN>=1 && IneRowN<=RowLength){
        //set
        this->SetComponent_byEI(val,  ExtRowN, IneRowN);
    }else if(ExtRowN>=1 && ExtRowN<=QExtRows && !(IneRowN>=1 && IneRowN<=RowLength)){
        //add ine row, locate to existing ext row
        this->SetSize_Array(QExtRows, RowLength+1);
        this->SetComponent_byEI(val,  ExtRowN, RowLength+1);
    }else if(!(ExtRowN>=1 && ExtRowN<=QExtRows) && IneRowN>=1 && IneRowN<=RowLength){
        //add ext row, locate to existing ine row
        this->SetSize_Array(QExtRows+1, RowLength);
        this->SetComponent_byEI(val,  QExtRows+1, IneRowN);
    }else if(!(ExtRowN>=1 && ExtRowN<=QExtRows) && !(IneRowN>=1 && IneRowN<=RowLength)){
        //add both
        this->SetSize_Array(QExtRows+1, RowLength+1);
        this->SetComponent_byEI(val, QExtRows+1, RowLength+1);
    }
}
void Matrix_Prototype::ValSetOrAddOrFillOrIgnore(double val, int LineN, int ColumnN){
    int QLines=this->GetQLines(), QColumns=this->GetQColumns();
    if(LineN==0 && ColumnN==0){
        //fill
        for(int i=1; i<=QLines; i++){
            for(int j=1; j<=QColumns; j++){
                this->SetComponent(val, i, j);
            }
        }
    }else if(LineN>=1 && LineN<=QLines && ColumnN==0){
        //fill line
        //for(int i=1; i<=QExtRows; i++){
        for(int j=1; j<=QColumns; j++){
            this->SetComponent(val, LineN, j);
        }
        //}
    }else if(LineN==0 && ColumnN>=1 && ColumnN<=ColumnN){
        //fill Ext Row
        for(int i=1; i<=QLines; i++){
        //for(int j=1; j<=RowLength; j++){
            this->SetComponent(val, i, ColumnN);
        //}
        }
    }else if(LineN>=1 && LineN<=QLines && ColumnN>=1 && ColumnN<=QColumns){
        //set
        this->SetComponent(val,  LineN, ColumnN);
    }else if(LineN>=1 && LineN<=QLines && !(ColumnN>=1 && ColumnN<=QColumns)){
        //add column, locate to existing line
        this->SetSize_Matrix(QLines, QColumns+1);
        this->SetComponent(val,  LineN, QColumns+1);
    }else if(!(LineN>=1 && LineN<=QLines) && ColumnN>=1 && ColumnN<=QColumns){
        //add line, locate to existin column
        this->SetSize_Matrix(QLines+1, QColumns);
        this->SetComponent(val,  QLines+1, ColumnN);
    }else if(!(LineN>=1 && LineN<=QLines) && !(ColumnN>=1 && ColumnN<=QColumns)){
        //add both
        this->SetSize_Matrix(QLines+1, QColumns+1);
        this->SetComponent(val, QLines+1, QColumns+1);
    }
}
//
// Std Cout
//
void Matrix_Prototype::StdCout_ExtRowN(int ExtRowN, QString ElemsDelim, bool UseBrackets)const{
    int curL=this->GetLength(), QExtRows=this->GetQExtRows();//(ExtRowN);
    double val;
    if(UseBrackets)std::cout<<"[";
    if(ExtRowN<0){
        ExtRowN+=(QExtRows+1);
    }
    if(ExtRowN>=1 && ExtRowN<=QExtRows){
        for(int i=1; i<=curL-1; i++){
            val=this->GetComponent_AsVal_byEI(ExtRowN, i);
            std::cout<<val;
            std::cout<<ElemsDelim.toStdString().c_str();
        }
        val=this->GetComponent_AsVal_byEI(ExtRowN, curL);
        std::cout<<val;
        if(UseBrackets)std::cout<<"]";
    }
}
void Matrix_Prototype::StdCout_IneRowN(int IneRowN, QString ElemsDelim, bool UseBrackets, bool Repr2DNot1D)const{
    //Array2DSize size=this->GetSize();
    int L=this->GetLength();//size.LengthFactOfIneRowN_From1stToFirstStop(IneRowN);
    double val;
    if(IneRowN<0){
        IneRowN+=(L+1);
    }
    if(IneRowN>=1 && IneRowN<=L){
        if(UseBrackets)std::cout<<"[";
        for(int i=1; i<=L-1; i++){
            val=this->GetComponent_AsVal_byEI(i, IneRowN);
            std::cout<<val;
            std::cout<<ElemsDelim.toStdString().c_str();
            if(Repr2DNot1D)std::cout<<std::endl;
        }
        val=this->GetComponent_AsVal_byEI(L, IneRowN);
        std::cout<<val;
        if(UseBrackets)std::cout<<"]";
        if(Repr2DNot1D)std::cout<<std::endl;
    }
}

void Matrix_Prototype::StdCout_LineN(int LineN, QString ElemsDelim, bool UseBrackets)const{
    int QColumns=this->GetQColumns(), QLines=this->GetQLines();//(ExtRowN);
    double val;
    if(LineN<0){
        LineN+=(QLines+1);
    }
    if(LineN>=1 && LineN<=QLines){
        if(UseBrackets)std::cout<<"[";
        for(int i=1; i<=QColumns-1; i++){
            val=this->GetComponent(LineN, i);
            std::cout<<val;
            std::cout<<ElemsDelim.toStdString().c_str();
        }
        val=this->GetComponent(LineN, QColumns);
        std::cout<<val;
        if(UseBrackets)std::cout<<"]";
    }
}
void Matrix_Prototype::StdCout_ColumnN(int ColumnN, QString ElemsDelim, bool UseBrackets, bool Repr2DNot1D)const{
    //Array2DSize size=this->GetSize();
    int QColumns=this->GetQColumns(), QLines=this->GetQLines();//size.LengthFactOfIneRowN_From1stToFirstStop(IneRowN);
    double val;
    if(UseBrackets)std::cout<<"[";
    for(int i=1; i<=QLines-1; i++){
        val=this->GetComponent(i, ColumnN);
        std::cout<<val;
        std::cout<<ElemsDelim.toStdString().c_str();
        if(Repr2DNot1D)std::cout<<std::endl;
    }
    val=this->GetComponent(QLines, ColumnN);
    std::cout<<val;
    if(UseBrackets)std::cout<<"]";
    if(Repr2DNot1D)std::cout<<std::endl;
}


//  void                       StdCout(QString ElemsDelim=", ", RowsDelim="; ", bool UseBrackets=true, bool Represent2DNot1D=true, bool ByExtRowsNotIneRows=true)const;
void Matrix_Prototype::StdCout(QString ElemsDelim, QString RowsDelim, bool UseBrackets, bool Represent2DNot1D, bool ByExtRowsNotIneRows)const{
    int QER=this->GetQExtRows(), curL=this->GetLength(), Lmax=curL;//this->GetMaxLength(), curL;
    if(ByExtRowsNotIneRows){
        if(UseBrackets)std::cout<<"[";
        StdCout_ExtRowN(1, ElemsDelim, UseBrackets);
        std::cout<<RowsDelim.toStdString().c_str();
        if(Represent2DNot1D)std::cout<<std::endl;
        for(int ERN=2; ERN<=QER-1; ERN++){
             if(Represent2DNot1D)std::cout<<" ";
             StdCout_ExtRowN(ERN, ElemsDelim, UseBrackets);
             std::cout<<RowsDelim.toStdString().c_str();
             if(Represent2DNot1D)std::cout<<std::endl;
        }
        if(Represent2DNot1D)std::cout<<" ";
        StdCout_ExtRowN(QER, ElemsDelim, UseBrackets);
        if(Represent2DNot1D)std::cout<<std::endl;
        if(UseBrackets)std::cout<<"]";
    }else{// if(this->GetSize().IsForTranspose()){//matrix s'rect sdi ally s'transpos'bl
        if(UseBrackets)std::cout<<"[";
        StdCout_IneRowN(1, ElemsDelim, UseBrackets);
        std::cout<<RowsDelim.toStdString().c_str();
        if(Represent2DNot1D)std::cout<<std::endl;
        for(int ERN=2; ERN<=Lmax-1; ERN++){
             if(Represent2DNot1D)std::cout<<" ";
             StdCout_IneRowN(ERN, ElemsDelim, UseBrackets);
             std::cout<<RowsDelim.toStdString().c_str();
             if(Represent2DNot1D)std::cout<<std::endl;
        }
        if(Represent2DNot1D)std::cout<<" ";
        StdCout_IneRowN(Lmax, ElemsDelim, UseBrackets);
        if(Represent2DNot1D)std::cout<<std::endl;
        if(UseBrackets)std::cout<<"]";
    }
}
//
// suppl fns
//
void Matrix_Prototype::FillByNs(){
    int QLines=this->GetQLines(), QColumns=this->GetQColumns();
    double val;
    for(int i=1; i<=QLines; i++){
        for(int j=1; j<=QColumns; j++){
            val=i*10+j;
            this->SetComponent(val, i, j);
        }
    }
}
void Matrix_Prototype::SetDataOfVect3D(double x, double y, double z){
    this->SetX(x);
    this->SetY(y);
    this->SetZ(z);
}
void Matrix_Prototype::MakeVect3D(double x, double y, double z){
    this->SetSize_Matrix(3, 1);
    this->SetX(x);
    this->SetY(y);
    this->SetZ(z);
}
void Matrix_Prototype::SetX(double val){
    this->SetComponent(val, 1, 1);
}
void Matrix_Prototype::SetY(double val){
    this->SetComponent(val, 2, 1);
}
void Matrix_Prototype::SetZ(double val){
    this->SetComponent(val, 3, 1);
}
double Matrix_Prototype::GetX(){
    double val=0;
    val=this->GetComponent(1, 1);
    return val;
}
double Matrix_Prototype::GetY(){
    double val=0;
    val=this->GetComponent(2, 1);
    return val;
}
double Matrix_Prototype::GetZ(){
    double val=0;
    val=this->GetComponent(3, 1);
    return val;
}
//
// end
//
//template <class T>class Matrix_V1I_ArrOfLines : public Array2D_Prototype{
//    std::vector<double>data;
//    Array2DSize size;
//public:
//
     Matrix_V1I_ArrOfLines::Matrix_V1I_ArrOfLines(){
        this->construct();
        this->SetNull();
        //this->SetOne();
    }
    //Matrix_V1I_ArrOfLines::Matrix_V1I_ArrOfLines(double DefaultVal, const Array2DSize& size){
    //    this->construct();
    //    this->Set(DefaultVal, size);
    //}
     Matrix_V1I_ArrOfLines::Matrix_V1I_ArrOfLines(double DefaultVal, int QExtRows, int QIneRows){
        this->construct();
        this->Set_byEI(DefaultVal, QExtRows, QIneRows);
    }
    //Matrix_V1I_ArrOfLines::Matrix_V1I_ArrOfLines(double DefaultVal, int QExtRows, int*Ls, bool RectIfPossible){
    //    this->construct();
    //    this->Set(DefaultVal, QExtRows, Ls, RectIfPossible);
    //}
    //Matrix_V1I_ArrOfLines::Matrix_V1I_ArrOfLines(double DefaultVal, std::vector<int>Ls, bool RectIfPossible){
    //    this->construct();
    //    this->Set(DefaultVal, Ls, RectIfPossible);
    //}
    //Matrix_V1I_ArrOfLines::Matrix_V1I_ArrOfLines(double*data, const Array2DSize& size){
    //    this->construct();
    //    this->Set(data, size);
    //}
     Matrix_V1I_ArrOfLines::Matrix_V1I_ArrOfLines(double*data, int QExtRows, int QIneRows){
        this->construct();
        this->Set_byEI(data, QExtRows, QIneRows);
    }
    //Matrix_V1I_ArrOfLines::Matrix_V1I_ArrOfLines(double*data, int QExtRows, int*Ls, bool RectIfPossible){
    //    this->construct();
    //    this->Set(data, QExtRows, Ls, RectIfPossible);
    //}
    //Matrix_V1I_ArrOfLines::Matrix_V1I_ArrOfLines(double*data, std::vector<int>Ls, bool RectIfPossible){
    //    this->construct();
    //    this->Set(data, Ls, RectIfPossible);
    //}
    //Matrix_V1I_ArrOfLines::Matrix_V1I_ArrOfLines(std::vector<double>data, const Array2DSize& size){
    //    this->construct();
    //    this->Set(data, size);
    //}
    Matrix_V1I_ArrOfLines::Matrix_V1I_ArrOfLines(std::vector<double>data, int QExtRows, int QIneRows){
        this->construct();
        this->Set_byEI(data.data(), QExtRows, QIneRows);
    }
    //Matrix_V1I_ArrOfLines::Matrix_V1I_ArrOfLines(std::vector<double>data, int QExtRows, int*Ls, bool RectIfPossible){
    //    this->construct();
    //    this->Set(data, QExtRows, Ls, RectIfPossible);
    //}
    //Matrix_V1I_ArrOfLines::Matrix_V1I_ArrOfLines(std::vector<double>data, std::vector<int>Ls, bool RectIfPossible){
    //    this->construct();
    //    this->Set(data, Ls, RectIfPossible);
    //}
    Matrix_V1I_ArrOfLines::Matrix_V1I_ArrOfLines(std::vector<std::vector<double>>data, int ifLNE_Lines_By_Max3Min4){
    //Matrix_V1I_ArrOfLines::Matrix_V1I_ArrOfLines(std::vector<std::vector<double>>data, bool ifNotRectNByMaxdNotMinLineLength, bool ifNotRectNByMaxdNotMinLineLength){
        this->construct();
        this->Set_byLC(data, ifLNE_Lines_By_Max3Min4);//LC! ob tal ord in matrices!
    }
    //Matrix_V1I_ArrOfLines::Matrix_V1I_ArrOfLines(double**data, const Array2DSize& size){
    //    this->construct();
    //    this->Set(data, size);
    //
    Matrix_V1I_ArrOfLines::Matrix_V1I_ArrOfLines(double**data, int QLines, int QColumns){
        this->construct();
        this->Set_byLC(data, QLines, QColumns);
    }
    //Matrix_V1I_ArrOfLines::Matrix_V1I_ArrOfLines(double**data, int QExtRows, int*Ls, bool RectIfPossible){
    //    this->construct();
    //    this->Set(data, QExtRows, Ls, RectIfPossible);
    //}
    //Matrix_V1I_ArrOfLines::Matrix_V1I_ArrOfLines(double**data, std::vector<int>Ls, bool RectIfPossible){
    //    this->construct();
    //    this->Set(data, Ls, RectIfPossible);
    //}
    //
     Matrix_V1I_ArrOfLines::Matrix_V1I_ArrOfLines(const Matrix_V1I_ArrOfLines& obj){
        this->construct();
        this->Assign(obj.clone());
    }
    //
    //virtual ~Array2D_Prototype()=default;
    Matrix_V1I_ArrOfLines::~Matrix_V1I_ArrOfLines(){
        //in this very case no destructor needed
        // in to cas no destr nods
    }
    //
    //virtual void SetNull()=0;
    void Matrix_V1I_ArrOfLines::SetNull(){
        this->data.clear();
        //this->size.SetNull();
        this->QLines=0;
    }
    //virtual void construct()=0;
    void Matrix_V1I_ArrOfLines::construct(){
        //in this very case no construct fn needed
        this->data.clear();
        //this->size.SetOne();
        //this->size.SetNull();
        this->SetNull();
        //this->SetOne();
    }

    //virtual Array2D_Prototype* CreateArray() const=0;
     Matrix_Prototype* Matrix_V1I_ArrOfLines::CreateMatrix() const{
        //return new Array2D_Prototype();//abstr class ha no constr,I cog
        return new Matrix_V1I_ArrOfLines();
    }
    //virtual Array2D_Prototype* clone()const=0;
     Matrix_Prototype* Matrix_V1I_ArrOfLines::clone()const{
        //return this;
        return new Matrix_V1I_ArrOfLines(*this);
    }
    //virtual int GetTypeN() const=0 ;
    int Matrix_V1I_ArrOfLines::GetTypeN() const{
        return MatrixTypeN_V1I;
    }
    //^ ecri'te err: non-member fn nabl ha cv-qualifier (points at const) Ma real err wa ze wa no  ef ::
    //
    void Matrix_V1I_ArrOfLines::Assign(Matrix_Prototype* obj){
        int QExtRows=obj->GetQExtRows(), RowLength=obj->GetLength(), QLines=obj->GetQLines(), QColumns=obj->GetQColumns();
        double val;
        this->SetSize_Array(QExtRows, RowLength);
        for(int i=1; i<=QExtRows; i++){
            for(int j=1; j<=RowLength; j++){
                val=obj->GetComponent_AsVal_byEI(i, j);
                this->SetComponent_byEI(val, i, j);
            }
        }
    }
    ////virtual void SetSize(double DfltValParam, const Array2DSize&size)=0;
    //virtual void SetSize_Array(int QExtRows=1, int QIneRows=1, double DefaultVal=0.0)=0;
    void Matrix_V1I_ArrOfLines::SetSize_Array(int QExtRows, int newL, double DefaultVal){
        int QExtRowsOld=this->GetQExtRows(), oldL=this->GetLength(), QRowsMin = QExtRowsOld <= QExtRows ? QExtRowsOld : QExtRows, PosN;
        //std::vector<double>row;
        std::vector<int>Ls;
        for(int i=1; i<=QExtRowsOld; i++){
            Ls.push_back(oldL);
        }
        if(QExtRows>QExtRowsOld){
            for(int i=1; i<=(QExtRows-QExtRowsOld); i++){
                for(int j=1; j<=oldL; j++){
                    this->data.push_back(DefaultVal);
                }
            }
        }else{//QExtRows<QExtRowsOld
            PosN=GetPositionInArrayOf2DRealizedBy1D(QExtRows, oldL, QExtRows+1, 1);
            for(int i=1; i<=(QExtRowsOld-QExtRows); i++){
                for(int j=1; j<=oldL; j++){
                    this->data.erase(this->data.begin()+PosN-1);
                }
            }
        }
        if(newL>oldL){
            for(int i=1; i<=(newL-oldL); i++){
                this->data.push_back(DefaultVal);
            }
            Ls[QExtRowsOld-1]=newL;
            for(int i=QExtRows-1; i>=1; i--){
                //int GetPositionInArrayOf2DRealizedBy1D(std::vector<int>Ls, int ExtRowN, int IneRowPosN);
                //int GetPositionInArrayOf2DRealizedBy1D(int QExtRows, int ExtRowsLength, int ExtRowN, int IneRowPosN);
                PosN=GetPositionInArrayOf2DRealizedBy1D(Ls, i, oldL);//mab arb'tl ety oldL alt Ls, ob go ab fin ad ini
                for(int j=1; j<=(newL-oldL); j++){
                    this->data.insert(this->data.begin()+PosN-1, DefaultVal);
                }
                Ls[i-1]=newL;
            }
        }else{//oldL>newL
            for(int i=QExtRows; i>=1; i--){
                PosN=GetPositionInArrayOf2DRealizedBy1D(Ls, i, newL+1);//mab arb'tl ety oldL alt Ls, ob go ab fin ad ini
                for(int j=1; j<=(oldL-newL); j++){
                    this->data.erase(this->data.begin()+PosN-1);
                }
                Ls[i-1]=newL;
            }
        }
        this->QLines=QExtRows;
    }//fn
    //virtual void SetSize_Matrix(int QLines=1, int QColumns=1, double DefaultVal=0.0)=0;
    void Matrix_V1I_ArrOfLines::SetSize_Matrix(int QLines, int QColumns, double DefaultVal){
        int QExtRows=QLines, RowL=QColumns;
        this->SetSize_Array(QExtRows, RowL, DefaultVal);
    }
    //
    //virtual int GetQExtRows() const=0;
    int Matrix_V1I_ArrOfLines::GetQExtRows() const{
        return this->QLines;
    }
    //virtual int GetLength(int ExtRowN=1) const=0;
    int Matrix_V1I_ArrOfLines::GetLength() const{
        int L=0;
        if(this->QLines>0){
            L=this->data.size()/this->QLines;
        }
        return L;
    }
    ////virtual int GetMinLength() const=0;
    ////virtual int GetMaxLength() const=0;
    //virtual int GetQLines() const=0;
    int Matrix_V1I_ArrOfLines::GetQLines() const{
        return this->QLines;
    }
    //virtual int GetQColumns() const=0;
    int Matrix_V1I_ArrOfLines::GetQColumns() const{
        return this->GetLength();
    }
    //bool NsBelongHere_byEI(int ExtRowN, int IneRowN) const;
    //bool NsBelongHere_byLC(int LineN, int ColN) const;
    //
    //std::vector<double> GetLineN_AsArray(int N) const;
    //std::vector<double> GetColumnN_AsArray(int N) const;
    //std::vector<double> GetContent_AsArray1D_ExtRows() const;
    //std::vector<std::vector<double>> GetContent_AsArray2D_ExtRowss() const;
    //std::vector<double> GetContent_AsArray1D_Lines() const;
    //std::vector<std::vector<double>> GetContent_AsArray2D_Lines() const;
    //
    //virtual double GetComponent_AsVal_byEI(int LineN, int ColN) const=0;
    double Matrix_V1I_ArrOfLines::GetComponent_AsVal_byEI(int ExtRowN, int IneRowN) const{
        double val=0;
        int QExtRows=this->GetQExtRows(), QIneRows=this->GetLength(), PosN;
        if(ExtRowN<0){
            ExtRowN+=(QExtRows+1);
        }
        if(IneRowN<0){
            IneRowN+=(QIneRows+1);
        }
        if(ExtRowN>=1 && ExtRowN<=QExtRows && IneRowN>=1 && IneRowN<=QIneRows){
            PosN=GetPositionInArrayOf2DRealizedBy1D(QExtRows, QIneRows,  ExtRowN, IneRowN);
            val=this->data[PosN-1];
        }
        return val;
    }
    double Matrix_V1I_ArrOfLines::GetComponent(int LineN, int ColN) const{
        double val=0;
        int QLines=this->GetQLines(), QColumns=this->GetQColumns(), ExtRowN, IneRowN, PosN, QExtRows, QIneRows;
        if(LineN<0){
            LineN+=(QLines+1);
        }
        if(ColN<0){
            ColN+=(QColumns+1);
        }
        if(LineN>=1 && LineN<=QLines && ColN>=1 && ColN<=QColumns){
            ExtRowN=LineN;
            IneRowN=ColN;
            QExtRows=QLines;
            QIneRows=QColumns;
            PosN=GetPositionInArrayOf2DRealizedBy1D(QExtRows, QIneRows,  ExtRowN, IneRowN);
            val=this->data[PosN-1];
        }
        return val;
        //return this->GetComponent_AsVal_byEI(LineN, ColN);
    }
      ////virtual double* GetComponent_AsPtr(int LineN, int ColN) const=0;
      ////virtual double* GetComponent_AsPtr(int LineN, int ColN) const;
      //
    //virtual void SetComponent_byEI(double val, int ExtRowN, int IneRowN)=0;
    void Matrix_V1I_ArrOfLines::SetComponent_byEI(double val, int ExtRowN, int IneRowN){
        int QExtRows=this->GetQExtRows(), QIneRows=this->GetLength(), PosN;
        if(ExtRowN<0){
            ExtRowN+=(QExtRows+1);
        }
        if(IneRowN<0){
            IneRowN+=(QIneRows+1);
        }
        if(ExtRowN>=1 && ExtRowN<=QExtRows && IneRowN>=1 && IneRowN<=QIneRows){
            PosN=GetPositionInArrayOf2DRealizedBy1D(QExtRows, QIneRows,  ExtRowN, IneRowN);
            this->data[PosN-1]=val;
        }
        //return val;
    }
    void Matrix_V1I_ArrOfLines::SetComponent(double val, int LineN, int ColN){
        int QLines=this->GetQLines(), QColumns=this->GetQColumns(), ExtRowN, IneRowN, PosN, QExtRows, QIneRows;
        if(LineN<0){
            LineN+=(QLines+1);
        }
        if(ColN<0){
            ColN+=(QColumns+1);
        }
        if(LineN>=1 && LineN<=QLines && ColN>=1 && ColN<=QColumns){
            ExtRowN=LineN;
            IneRowN=ColN;
            QExtRows=QLines;
            QIneRows=QColumns;
            PosN=GetPositionInArrayOf2DRealizedBy1D(QExtRows, QIneRows,  ExtRowN, IneRowN);
            this->data[PosN-1]=val;
        }
        //return val;
    }
    //
    // Ext row
    //
    void Matrix_V1I_ArrOfLines::AddExtRow_OwnType(                             double*rowParam, int wholeRowL,                             TParamsOfDataShift*DataShiftParam,   double DefaultVal,  int ifNLNE_ByM1ByNewRow2ByMax3,                                                         TValsShowHide*vsh){
        int QExtRows=this->GetQExtRows(), rowL=this->GetLength(), paramL, maxL, factL, PosN;
        std::vector<double>rowFact;
        TParamsOfDataShift DataShift;
        double val;
        if(DataShiftParam!=NULL){
            DataShift=(*(DataShiftParam));
        }
        if(rowL==0 && wholeRowL>0){
            paramL=DataShift.CalcQ(wholeRowL);
            factL=paramL;
        }else if(rowL>0){
            if(wholeRowL==0){
                wholeRowL=rowL;
            }
            paramL=DataShift.CalcQ(wholeRowL);
            if(paramL!=rowL){
                switch(ifNLNE_ByM1ByNewRow2ByMax3){
                    case 1:
                        factL=rowL;
                    break;
                    case 2:
                        factL=paramL;
                    break;
                    case 3:
                        maxL = rowL >= paramL ? rowL : paramL;
                        factL=maxL;
                    break;
                }
                this->SetSize_Array(QExtRows, factL, DefaultVal);
            }
        }
        for(int i=1; i<=factL; i++){
            val=this->data[i-1];
            this->data.push_back(val);
        }
        this->QLines++;
    }
    //
      void Matrix_V1I_ArrOfLines::AddLine_OwnType(                             double*rowParam, int wholeRowL,                             TParamsOfDataShift*DataShiftParam,   double DefaultVal,  int ifNLNE_ByM1ByNewRow2ByMax3,                                                         TValsShowHide*vsh){
        this->AddExtRow_OwnType(rowParam, wholeRowL, DataShiftParam, DefaultVal,ifNLNE_ByM1ByNewRow2ByMax3, vsh);
    }
      ////  virtual void AddExtRow_Simply(double*rowParam)=0;
      //  virtual void AddExtRow_Simply(double*rowParam)=0;
      void Matrix_V1I_ArrOfLines::AddExtRow_Simply_OwnType(double*rowParam){
          int RowLength=this->GetLength();
          double val;
          if(RowLength>0){
              for(int i=1; i<=RowLength; i++){
                  val=rowParam[i-1];
                  this->data.push_back(val);
              }
              this->QLines++;
          }
      }
      //virtual void AddLine_Simply(double*rowParam)=0;
      //virtual void AddLine_Simply_OwnType(double*rowParam)=0;
      void Matrix_V1I_ArrOfLines::AddLine_Simply_OwnType(double*rowParam){
          this->AddExtRow_Simply_OwnType(rowParam);
      }
      //
    void Matrix_V1I_ArrOfLines::InsExtRowN_OwnType(         int ExtRowN,                    double*rowParam, int wholeRowL,    TParamsOfDataShift*DataShiftParam,   double DefaultVal, int ifNLNE_ByM1ByNewRow2ByMax3,                                   TValsShowHide*vsh){
        std::vector<double>rowFact;
        TParamsOfDataShift DataShift;
        int QExtRows=this->GetQExtRows(), RowL=this->GetLength(), paramL, maxL, factL, erstPosN, curPosN;
        double val;
        if(ExtRowN<0){
            ExtRowN+=(QExtRows+1);
        }
        if(ExtRowN>1 && ExtRowN<=QExtRows){
            if(DataShiftParam!=NULL){
                DataShift=*DataShiftParam;
            }
            if(wholeRowL==0){
                wholeRowL=RowL;
            }
            paramL=DataShift.CalcQ(wholeRowL);
            if(paramL!=RowL){
                switch(ifNLNE_ByM1ByNewRow2ByMax3){
                    case 1:
                        factL=RowL;
                    break;
                    case 2:
                        factL=paramL;
                    break;
                    case 3:
                        maxL = RowL >= paramL ? RowL : paramL;
                        factL = maxL;
                    break;
                }
            }
            if(factL!=RowL){
                this->SetSize_Array(QExtRows, factL, DefaultVal);
            }
            if(factL!=paramL){
                DataShift.QReq=factL;
            }
            rowFact=GetSubVector(rowParam, wholeRowL, DefaultVal, &DataShift);
            erstPosN=GetPositionInArrayOf2DRealizedBy1D(QExtRows, factL, ExtRowN, 1);
            for(int i=1; i<=factL; i++){
                val=rowFact[i-1];
                curPosN=erstPosN+i-1;
                this->data.insert(this->data.begin()+curPosN-1, val);
            }
            this->QLines++;
        }
    }
    void Matrix_V1I_ArrOfLines::InsLineN_OwnType(         int LineN,                    double*rowParam, int wholeRowL,    TParamsOfDataShift*DataShiftParam,   double DefaultVal, int ifNLNE_ByM1ByNewRow2ByMax3,                                   TValsShowHide*vsh){
        int ExtRowN=LineN;
        //virtual void InsExtRowN_OwnType( int ExtRowN,                    double*rowParam=NULL, int wholeRowL=0,    TParamsOfDataShift*DataShiftParam=NULL,   double DefaultVal=0.0, int ifNLNE_ByM1ByNewRow2ByMax3=1,                                   TValsShowHide*vsh=NULL)=0;
        //virtual void   InsLineN_OwnType( int LineN,                      double*rowParam=NULL, int wholeRowL=0,    TParamsOfDataShift*DataShiftParam=NULL,   double DefaultVal=0.0, int ifNLNE_ByM1ByNewRow2ByMax3=1,                                   TValsShowHide*vsh=NULL)=0;
        this->InsExtRowN_OwnType(              ExtRowN,                           rowParam,          wholeRowL,                         DataShiftParam,               DefaultVal,         ifNLNE_ByM1ByNewRow2ByMax3,vsh);
    }


      //
      //                      void               InsExtRowN(         int ExtRowN,                    double*rowParam=NULL, int wholeRowL=0,    TParamsOfDataShift*DataShiftParam=NULL,   double DefaultVal=0.0, int ifNLNE_ByM1ByNewRow2ByMax3=1,                                   TValsShowHide*vsh=NULL);
      //                      void                 InsLineN(         int LineN,                      double*rowParam=NULL, int wholeRowL=0,    TParamsOfDataShift*DataShiftParam=NULL,   double DefaultVal=0.0, int ifNLNE_ByM1ByNewRow2ByMax3=1,                                   TValsShowHide*vsh=NULL);
      //virtual void InsExtRow_Simply(int N,double*rowParam)=0;
      void Matrix_V1I_ArrOfLines::InsExtRow_Simply_OwnType(int N, double*rowParam){
          double val;
          int QExtRows=this->GetQExtRows(), RowLength=this->GetLength(), ErstPosN=GetPositionInArrayOf2DRealizedBy1D(QExtRows, RowLength, N, 1), curPosN;
          for(int i=1; i<=QExtRows; i++){
              val=rowParam[i-1];
              curPosN=ErstPosN+i-1;
              this->data.insert(this->data.begin()+curPosN-1, val);
          }
          this->QLines++;
      }
      void Matrix_V1I_ArrOfLines::InsLine_Simply_OwnType(int ExtRowN, double*rowParam){
          int LineN=ExtRowN;
          this->InsExtRow_Simply_OwnType(LineN, rowParam);
      }
      //
      ///virtual void InsLine_Simply(int N,double*rowParam)=0;
      //void InsLine_Simply(int N,double*rowParam);
      //
      //void DelExtRowN(int N=-1);
      //virtual void DelExtRowN_Simply(int N=-1)=0;
      void Matrix_V1I_ArrOfLines::DelExtRowN_Simply(int N){
          int QExtRows=this->GetQExtRows(), RowLength=this->GetLength(), PosN=GetPositionInArrayOf2DRealizedBy1D(QExtRows, RowLength, N, 1);
          if(N>=1 && N<=QExtRows){
              for(int i=1; i<=RowLength; i++){
                  this->data.erase(this->data.begin()+PosN-1);
              }
          }
          this->QLines--;
      }
      void Matrix_V1I_ArrOfLines::DelLineN_Simply(int LineN){
          int ExtRowN=LineN;
          this->DelExtRowN_Simply(ExtRowN);
      }
      //
      //Ine row
      //
      //                         void               SetIneRowN(          int IneRowN,                   double*rowParam=NULL, int wholeRowL=0,                        TParamsOfDataShift*DataShiftParam=NULL, double DefaultVal=0.0, bool DafaultsAreSpecNotOwnVals=true, int ifNLNE_ByM1ByNewRow2ByMax3,                                   TValsShowHide*vsh);
      //                         void               SetColumnN(          int ColumnN,                   double*rowParam=NULL, int wholeRowL=0,                        TParamsOfDataShift*DataShiftParam=NULL, double DefaultVal=0.0, bool DafaultsAreSpecNotOwnVals=true, int ifNLNE_ByM1ByNewRow2ByMax3,                                   TValsShowHide*vsh);
      void  Matrix_V1I_ArrOfLines::SetIneRow_OwnType(         int IneRowN,                                        double*rowParam, int wholeRowL, TParamsOfDataShift*dataShiftParam, bool DefaultValsAreSpecNotOwnVals, double DefaultVal,                             int ifNLNE_ByM1ByNewRow2ByMax3){
          int QExtRows=this->GetQExtRows(), RowLength=this->GetLength(), paramQ, maxQ, factQ, PosN;
          std::vector<double>rowFact, rowWas;
          std::vector<int>Ls;
          TParamsOfDataShift dataShift;
          double val;
          if(dataShiftParam!=NULL){
              dataShift=*dataShiftParam;
          }
          if(wholeRowL==0){
              wholeRowL=QExtRows;
          }
          paramQ=dataShift.CalcQ(wholeRowL);
          if(IneRowN<0){
              IneRowN+=(RowLength+1);
          }
          if(IneRowN>=1 && IneRowN<=RowLength){
              switch(ifNLNE_ByM1ByNewRow2ByMax3){
                  case 1:
                      factQ=QExtRows;
                  break;
                  case 2:
                      factQ=paramQ;
                  break;
                  case 3:
                      maxQ = QExtRows >= paramQ ? QExtRows : paramQ;
                      factQ=maxQ;
                  break;
              }
              if(factQ!=QExtRows){
                  this->SetSize_Array(factQ, RowLength);
              }
              if(DefaultValsAreSpecNotOwnVals){
                  rowFact=GetSubVector(rowParam, wholeRowL, DefaultVal, &dataShift);
              }else{
                  rowWas=this->GetIneRowN_AsArray(IneRowN);
                  rowFact=GetSubVector(rowParam, wholeRowL,rowWas.data(), rowWas.size(),DefaultVal,&dataShift);
              }
              for(int i=1; i<=factQ; i++){
                  val=rowFact[i-1];
                  this->SetComponent_byEI(val, i, IneRowN);
              }
          }
      }
      void  Matrix_V1I_ArrOfLines::SetColumn_OwnType(         int ColumnN,                                        double*rowParam, int wholeRowL,  TParamsOfDataShift*dataShiftParam,  bool DefaultValsAreSpecNotOwnVals, double DefaultVal,  int ifNLNE_ByM1ByNewRow2ByMax3){
          int IneRowN=ColumnN;
          this->SetIneRow_OwnType(          IneRowN,                                        rowParam, wholeRowL,  dataShiftParam,  true,   DefaultVal,    ifNLNE_ByM1ByNewRow2ByMax3);
      }
      //virtual void SetIneRowSimply_OwnType(int IneRowN,double*rowParam)=0;
  void Matrix_V1I_ArrOfLines::SetIneRowSimply_OwnType(int IneRowN, double*rowParam){
      int QExtRows=this->GetQExtRows(), rowL=this->GetLength();
      double val;
      if(IneRowN<0){
          IneRowN+=(rowL+1);
      }
      if(IneRowN>=1 && IneRowN<=rowL){
          for(int i=1; i<=QExtRows; i++){
              val=rowParam[i-1];
              this->SetComponent_byEI(val, i, IneRowN);
          }
      }
  }
      //virtual void SetColumnSimply_OwnType(int IneRowN,double*rowParam)=0;
  void Matrix_V1I_ArrOfLines::SetColumnSimply_OwnType(int ColumnN, double*rowParam){
      int QLines=this->GetQLines(), QColumns=this->GetLength();
      double val;
      if(ColumnN<0){
          ColumnN+=(QColumns+1);
      }
      if(ColumnN>=1 && ColumnN<=QColumns){
          for(int i=1; i<=QLines; i++){
              val=rowParam[i-1];
              this->SetComponent_byEI(val, i, ColumnN);
          }
      }
  }

  void  Matrix_V1I_ArrOfLines::AddIneRow_OwnType(                                                 double*rowParam,     int wholeRowL,   TParamsOfDataShift*dataShiftParam,      double DefaultVal,     int ifNLNE_ByM1ByNewRow2ByMax3){
          int QExtRows=this->GetQExtRows(), RowLength=this->GetLength(), paramQ, maxQ, factQ, PosN;
          TParamsOfDataShift DataShift;
          std::vector<double>rowFact;
          double val;
          if(dataShiftParam!=NULL){
             DataShift=*dataShiftParam;
          }
          paramQ=DataShift.CalcQ(wholeRowL);
          if(QExtRows>0 && wholeRowL==0){
              wholeRowL=QExtRows;
              factQ=QExtRows;
          }else if(QExtRows==0 && wholeRowL>0){
              factQ=wholeRowL;
          }else if(paramQ!=RowLength){
              switch(ifNLNE_ByM1ByNewRow2ByMax3){
                  case 1:
                      factQ=QExtRows;
                  break;
                  case 2:
                     factQ=paramQ;
                  break;
                  case 3:
                     maxQ = QExtRows >= paramQ ? QExtRows : paramQ;
                     factQ=maxQ;
                  break;
              }
              DataShift.QReq=factQ;
          }
          this->SetSize_Array(factQ, RowLength+1);
          rowFact=GetSubVector(rowParam,wholeRowL, DefaultVal,&DataShift);
          for(int i=1; i<=factQ; i++){
              val=rowFact[i-1];
              this->SetComponent_byEI(val, i, RowLength+1);
          }
      }
    //virtual                void AddColumn_OwnType(double*rowParam=NULL, int wholeRowL=0, TParamsOfDataShift*dataShiftParam=NULL, double DefaultVal=0.0, int ifNLNE_ByM1ByNewRow2ByMax3=1);
    void   Matrix_V1I_ArrOfLines::AddColumn_OwnType(double*rowParam,      int wholeRowL,   TParamsOfDataShift*dataShiftParam,      double DefaultVal,     int ifNLNE_ByM1ByNewRow2ByMax3){
        this->AddIneRow_OwnType(rowParam, wholeRowL, dataShiftParam,  DefaultVal, ifNLNE_ByM1ByNewRow2ByMax3);
    }
    //virtual void AddIneRow_Simply(double*rowParam)=0;
    //virtual void AddIneRow_Simply_OwnType(double*rowParam)=0;
    void Matrix_V1I_ArrOfLines::AddIneRow_Simply_OwnType(double*rowParam){
        int QExtRows=this->GetQExtRows(), RowLength=this->GetLength();//, PosN;
        double val;
        this->SetSize_Array(QExtRows, RowLength+1);
        for(int i=1; i<=QExtRows; i++){
            val=rowParam[i-1];
            this->SetComponent_byEI(val, i, RowLength+1);
        }
    }
    //virtual void AddColumn_Simply(double*rowParam)=0;
    //virtual void AddColumn_Simply_OwnType(double*rowParam)=0;
    //virtual void AddColumn_Simply_OwnType(double*rowParam)=0;
    void Matrix_V1I_ArrOfLines::AddColumn_Simply_OwnType(double*rowParam){
        this->AddIneRow_Simply_OwnType(rowParam);
    }
    //                   void               InsIneRowN(                         int IneRowN, double DefaultVal,double*rowParam=NULL, int wholeRowL=0, double DefaultVal=0.0,TParamsOfDataShift*DataShiftParam=NULL, bool DefaulsAreSpecNotOwnVals=true,                          int ifNLNE_ByM1ByNewRow2ByMax3=1);
    //                   //
     //                       void                InsColumn(                         int IneRowN, double DefaultVal,double*rowParam=NULL, int wholeRowL=0, double DefaultVal=0.0,TParamsOfDataShift*DataShiftParam=NULL, bool DefaulsAreSpecNotOwnVals=true,                          int ifNLNE_ByM1ByNewRow2ByMax3=1);
     //
    void Matrix_V1I_ArrOfLines::InsIneRowN_OwnType(int IneRowN, double*rowParam, int wholeRowL, double DefaultVal,TParamsOfDataShift*DataShiftParam,                          int ifNLNE_ByM1ByNewRow2ByMax3){
         int QExtRows=this->GetQExtRows(), RowLength=this->GetLength();
         if(IneRowN<0){
             IneRowN+=(RowLength+1);
         }
         if(IneRowN>=1 && IneRowN>=RowLength){
             this->SetSize_Array(QExtRows, RowLength+1);
             for(int i=RowLength+1; i>=IneRowN+1; i--){
                 this->SwapIneRows(i-1, i);
             }
             this->SetIneRow_OwnType(IneRowN,rowParam,wholeRowL,DataShiftParam,true,DefaultVal,ifNLNE_ByM1ByNewRow2ByMax3);
         }
     }
    void Matrix_V1I_ArrOfLines::InsColumnN_OwnType(int ColumnN, double*rowParam, int wholeRowL, double DefaultVal, TParamsOfDataShift*DataShiftParam,                           int ifNLNE_ByM1ByNewRow2ByMax3){
        int IneRowN=ColumnN;
        this->InsIneRowN_OwnType( IneRowN, rowParam, wholeRowL, DefaultVal, DataShiftParam, ifNLNE_ByM1ByNewRow2ByMax3);
    }
    //virtual void InsIneRow_Simply_OwnType(int N, double*rowParam);
    void Matrix_V1I_ArrOfLines::InsIneRow_Simply_OwnType(int IneRowN, double*rowParam){
        int QExtRows=this->GetQExtRows(), RowLength=this->GetLength(), L, PosN;
        double val;
        std::vector<int>Ls;
        if(IneRowN<0){
            IneRowN+=(RowLength+1);
        }
        for(int i=RowLength; i>=1; i--){
            Ls.push_back(RowLength);
        }
        if(IneRowN>=1 && IneRowN<=RowLength){
            for(int i=RowLength; i>=1; i--){
                val=rowParam[i-1];
                PosN=GetPositionInArrayOf2DRealizedBy1D(Ls, i, IneRowN);
                this->data.insert(this->data.begin()+PosN-1, val);
                Ls[i-1]=RowLength+1;
            }
        }
    }
    //virtual void InsColumn_Simply(int N, double*rowParam);
    void Matrix_V1I_ArrOfLines::InsColumn_Simply_OwnType(int ColumnN, double*rowParam){
        int IneRowN=ColumnN;
        this->InsIneRow_Simply_OwnType(IneRowN, rowParam);
    }
    void Matrix_V1I_ArrOfLines::DelIneRow_Simply(int IneRowN){
        int QExtRows=this->GetQExtRows(), RowLength=this->GetLength(), PosN;
        std::vector<int>Ls;
        if(IneRowN<0){
            IneRowN+=(RowLength+1);
        }
        if(IneRowN>=1 && IneRowN<=RowLength){
            for(int i=1; i<=QExtRows; i++){
                Ls.push_back(RowLength);
            }
            for(int i=QExtRows; i>=1; i--){
                PosN=GetPositionInArrayOf2DRealizedBy1D(Ls, i, IneRowN);
                this->data.erase(this->data.begin()+PosN-1);
                Ls[i-1]--;
            }
        }
    }
    void Matrix_V1I_ArrOfLines::DelColumn_Simply(int ColN){
        int IneRowN=ColN;
        this->DelIneRow_Simply(IneRowN);
    }
    //
    // Set Content
    //
    //void Set_byEI(double**y, int QExtRows=1, int QIneRows=1);
    //void Set_byLC(double**y, int QLines=1, int QColumns=1);//by LC s'om param, ne om Matrix. F'Matrix s'SetComponent. Ors os ablb by EI, LC (zug o'Lines) et CL (zug o'Cols), ma nout CL, if LC s'Matrix order, f'Matrices' CL s'EI
    //void Set_byCL(double**y, int QLines=1, int QColumns=1);//CL sdi y s'zug o'cols
    //void Set_byEI(double*y, int QExtRows=1, int QIneRows=1);
    //void Set_byLC(double*y, int QLines=1, int QColumns=1);//by LC s'om param, ne om Matrix. F'Matrix s'SetComponent. Ors os ablb by EI, LC (zug o'Lines) et CL (zug o'Cols), ma nout CL, if LC s'Matrix order, f'Matrices' CL s'EI
    //void Set_byCL(double*y, int QLines=1, int QColumns=1);//CL=>-param s'zug o'cols
    //void Set_byEI(double val, int QExtRows=1, int ExtRowsLength=1);
    //void Set_byLC(double val, int QLines=1, int QColumns=1);
    //
    //void SwapVals_byEI(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
    //void SwapVals_byLC(int LineN1, int ColN1, int LineN2, int ColN2);
    //
    //void SwapExtRows(int N1, int N2);
    //
    //void SwapLines(int N1, int N2);
    //
    //void SwapIneRows(int N1, int N2);
    //
    //void SwapColumns(int N1, int N2);
    //
    //
    //void ReverseExtRowN(int rowN);
    //void ReverseLineN(int rowN);
    //void ReverseIneRowN(int rowN);
    //void ReverseColumnN(int rowN);
    //void ReverseExtRowsSuccession();
    //void ReverseLinesSuccession();
    //void ReverseIneRowsSuccession();
    //void ReverseColumnsSuccession();
    //
    //bool ValIsAtPos_byEI(double val, int ExtRowN, int IneRowN) const;
    //bool ValIsAtPos_byLC(double val, int LineN, int ColN) const;
    //TListOfNumberPairs SeekVal_ByEI(double val) const;
    //TListOfNumberPairs SeekVal(double val) const;
    //bool ExtRowIsAtPos(double*row, int Q, int ExtRowN, int IneRowN) const;
    //bool LineIsAtPos(double*row, int Q, int LineN,   int ColN) const;
    //TListOfNumberPairs SeekExtRow(double*row, int L) const;
    //TListOfNumberPairs SeekLine(double*row, int L) const;
    //bool IneRowIsAtPos(double*row, int Q, int ExtRowN, int IneRowN) const;
    //bool ColumnIsAtPos(double*row, int Q, int LineN, int ColN) const;
    //TListOfNumberPairs SeekIneRow(double*row, int Q) const;
    //TListOfNumberPairs SeekColumn(double*row, int Q) const;

    //bool Arr2DIsAtPos_byEI(std::vector<std::vector<double>>arr,             int ExtRowN, int IneRowN, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //bool Arr2DIsAtPos_byLC(std::vector<std::vector<double>>arr,             int LineN,   int ColN,    bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;

    //TListOfNumberPairs SeekArr2D_byEI(std::vector<std::vector<double>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //TListOfNumberPairs SeekArr2D_byLC(std::vector<std::vector<double>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;

    //TListOfNumberPairs SeekArr2D(std::vector<std::vector<double>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //TListOfNumberPairs SeekArr2D(Matrix_Prototype*obj, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //
    //
    //
    //
    //std::vector<double> SubMatrix_As1DArr_ByEINs_NurBelonging(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
    //std::vector<double> SubMatrix_As1DArr_ByLCNs_NurBelonging(int LineN1, int ColN1, int LineN2, int ColN2);
    //std::vector<double> SubMatrix_As1DArr_ByCLNs_NurBelonging(int LineN1, int ColN1, int LineN2, int ColN2);
    //std::vector<std::vector<double>> SubMatrix_As2DArr_ByEINs_NurBelonging(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
    //std::vector<std::vector<double>> SubMatrix_As2DArr_ByLCNs_NurBelonging(int LineN1, int ColN1, int LineN2, int ColN2);
    //std::vector<std::vector<double>> SubMatrix_As2DArr_ByCLNs_NurBelonging(int LineN1, int ColN1, int LineN2, int ColN2);

    //std::vector<std::vector<double>> SubMatrixAsSuccOfRows_AsArr2D_byEI(TParamsOfDataShift ShiftParams);
    //std::vector<std::vector<double>> SubMatrixAsSuccOfRows_AsArr2D_byEI(int QReq=0, int FromN=1, int QDefaultsBefore=0);

    //std::vector<std::vector<double>> SubMatrixAsSuccOfRows_AsArr2D_byLC(TParamsOfDataShift ShiftParams);
    //std::vector<std::vector<double>> SubMatrixAsSuccOfRows_AsArr2D_byLC(int QReq=0, int FromN=1, int QDefaultsBefore=0);
    //std::vector<std::vector<double>> SubMatrixAsSuccOfRows_AsArr2D_byCL(TParamsOfDataShift ShiftParams);
    //std::vector<std::vector<double>> SubMatrixAsSuccOfRows_AsArr2D_byCL(int QReq=0, int FromN=1, int QDefaultsBefore=0);
    //
    //void ConcatAdding_byEI(Matrix_Prototype*obj,int QShiftedCols=0, TParamsOfDataShift*DataShiftParam=NULL, double DefaultVal=0);
    //void ConcatAdding_byLC(Matrix_Prototype*obj,int QShiftedCols=0, TParamsOfDataShift*DataShiftParam=NULL, double DefaultVal=0);
    //void ConcatStretching_byEI(Matrix_Prototype*obj,  int QShiftedLinesNs=0,  TParamsOfDataShift*DataShiftParam=NULL);//, double DefaultVal=0);
    //void ConcatStretching_byLC(Matrix_Prototype*obj,  int QShiftedLinesNs=0,  TParamsOfDataShift*DataShiftParam=NULL);//, double DefaultVal=0);
    //
    //void ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore_byEI(double val, int ExtRowN, int ColN, double DefaultVal=0);
    //void ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(double val, int LineN, int ColN, double DefaultVal=0);
    //
    //void StdCout_ExtRowN(int ExtRowN, QString ElemsDelim="; ", bool UseBrackets=true)const;
    //void StdCout_IneRowN(int IneRowN, QString ElemsDelim="; ", bool UseBrackets=true, bool Represent2DNot1D=false)const;
    //void StdCout_LineN(int LineN, QString ElemsDelim="; ", bool UseBrackets=true)const;
    //void StdCout_ColumnN(int ColumnN, QString ElemsDelim="; ", bool UseBrackets=true, bool Represent2DNot1D=false)const;
    //void StdCout(QString ElemsDelim=", ", QString RowsDelim="; ", bool UseBrackets=true, bool Represent2DNot1D=true, bool ByExtRowsNotIneRows=true)const;

    //}; //Matrix_V1I_ArrOfLines


    //--------------------------------------------------------------------------------------



    //class Matrix{
    //    Matrix_Prototype*data;
    //public:
        //
    Matrix::Matrix(int QLines, int QColumns, double val, int TypeN){
        this->construct(TypeN);
        this->Set_byLC(val, QLines, QColumns, TypeN);
    }
    Matrix::Matrix(double*data, int QLines, int QColumns, int TypeN){
        this->construct(TypeN);
        this->Set_byLC(data, QLines, QColumns, TypeN);
    }
    Matrix::Matrix(std::vector<double>data, int QLines, int TypeN){
        this->construct(TypeN);
        this->Set_byLC(data, QLines,  TypeN);
    }
    Matrix::Matrix(double**data, int QLines, int QColumns, int TypeN){
        this->construct(TypeN);
        this->Set_byLC(data, QLines, QColumns, TypeN);
    }
    Matrix::Matrix(std::vector<std::vector<double>>data, int ifLNE_Lines_By_Max3Min4, int TypeN){
        this->construct(TypeN);
        //void Set_byLC(std::vector<std::vector<double>>arr, int ifLNE_Lines_By_Max3Min4=4, int TypeN=MatrixTypeN_V1I);
        this->Set_byLC(data, ifLNE_Lines_By_Max3Min4, TypeN);
    }
    Matrix::Matrix(Matrix_Prototype*obj){
        int TypeN;
        if(obj!=NULL){
            TypeN=obj->GetTypeN();
            this->construct(TypeN);
            this->Assign(obj);
        }
    }
    Matrix::Matrix(const Matrix&obj){
        int TypeN=obj.GetTypeN();
        this->construct(TypeN);
        this->Assign(obj);
    }
    Matrix::~Matrix(){
         delete this->data;
    }
    //
    void Matrix::Assign(Matrix_Prototype*obj){
        int TypeNObj, TypeNThis, QExtRowsThis, QExtRowsObj, RowLengthThis, RowLengthObj;
        double val;
        if(obj==NULL){
            //this->SetNull();
            //better NOp
        }else{
            TypeNObj=obj->GetTypeN();
            TypeNThis=this->GetTypeN();
            //, QLinesThis=this->GetQLines(), QColumnsThis=this->GetQColumns(), QLinesObj=obj.GetQLines(), QColumnsObj=obj.GetQColumns();
            QExtRowsThis=this->GetQExtRows();
            QExtRowsObj=obj->GetQExtRows();
            RowLengthThis=this->GetLength();
            RowLengthObj=obj->GetLength();
            if(TypeNObj!=TypeNThis){
                this->construct(TypeNObj);
            }
            if(QExtRowsThis!=QExtRowsObj ||RowLengthThis!=RowLengthObj){
                this->data->SetSize_Array(QExtRowsObj, RowLengthObj);
            }
            for(int i=1; i<=QExtRowsObj; i++){
                for(int j=1; j<=RowLengthObj; j++){
                    val=this->GetComponent_AsVal_byEI(i, j);
                    this->SetComponent_byEI(val, i, j);
                }
            }
        }
    }
    void Matrix::Assign(const Matrix&obj){
        int TypeNObj=obj.GetTypeN(), TypeNThis=this->GetTypeN();
        //, QLinesThis=this->GetQLines(), QColumnsThis=this->GetQColumns(), QLinesObj=obj.GetQLines(), QColumnsObj=obj.GetQColumns();
        int QExtRowsThis=this->GetQExtRows(), QExtRowsObj=obj.GetQExtRows(), RowLengthThis=this->GetLength(), RowLengthObj=obj.GetLength();
        double val;
        if(TypeNObj!=TypeNThis){
            this->construct(TypeNObj);
        }
        if(QExtRowsThis!=QExtRowsObj || RowLengthThis!=RowLengthObj){
            this->data->SetSize_Array(QExtRowsObj, RowLengthObj);
        }
        for(int i=1; i<=QExtRowsObj; i++){
            for(int j=1; j<=RowLengthObj; j++){
                val=this->GetComponent_AsVal_byEI(i, j);
                this->SetComponent_byEI(val, i, j);
            }
        }
    }
        //
    Matrix& Matrix::operator = (const Matrix&obj){
        this->Assign(obj);
        return *this;
    }
    Matrix& Matrix::operator = (Matrix_Prototype*obj){
        this->Assign(obj);
        return *this;
    }
        //
    Matrix_Prototype*Matrix::GetData(){
        return this->data;
    }
        //
    void Matrix::SetNull(){
       this->data->SetNull();
    }
    void Matrix::construct(int TypeN){
        switch(TypeN){
            case MatrixTypeN_V1I:
                this->data=new Matrix_V1I_ArrOfLines();
            break;
        }
    }
    ////virtual Matrix_Prototype* CreateArray() const=0;
    //virtual Matrix_Prototype* CreateMatrix() const=0;
    //virtual Matrix_Prototype* clone()const=0;
    int Matrix::GetTypeN() const{
        return this->data->GetTypeN();
    }
        //
    void Matrix::SetTypeN(int TypeN){
        int TypeNWas=this->GetTypeN(), QExtRows=this->GetQExtRows(), RowLength=this->GetLength(), QLines=this->GetQLines(), QColumns=this->GetQColumns();
        std::vector<double>data;
        double val;
        if(TypeNWas!=TypeN){
            data=this->GetContent_AsArray1D_Lines();
            this->SetNull();
            delete this->data;
            this->construct(TypeN);
        }
        //this->Set_byLC(data, QLines, TypeN);//so wu c-recursion
        this->SetSize_Matrix(QLines, QColumns);
        for(int i=1; i<=QLines; i++){
            for(int j=1; j<=QColumns; j++){
                val=this->GetComponent(i, j);
                this->SetComponent(val, i, j);
            }
        }
    }
        //
    void Matrix::SetOne(double DfltVal){
        this->SetSize_Array(1, 1);
        this->SetComponent_byEI(0.0, 1, 1);
    }
        //
        ////virtual void SetLengthOfExtRowN(int ExtRowN, int newL, double DefaultVal=0)=0;//es SetSize f'ce
        ////virtual void SetLengthOfExtRowN(int ExtRowN, int newL,double*DefaultValParam=NULL)=0;
        //
        //virtual void SetSize(double DfltValParam, const Array2DSize&size)=0;
        //virtual void SetSize_Array(int QExtRows=1, int QIneRows=1, double DefaultVal=0.0)=0;
        //virtual void SetSize_Matrix(int QLines=1, int QColumns=1, double DefaultVal=0.0)=0;
    void Matrix::SetSize_Array(int QExtRows, int QIneRows, double DefaultVal){
        this->data->SetSize_Array(QExtRows, QIneRows, DefaultVal);
    }
    void Matrix::SetSize_Matrix(int QLines, int QColumns, double DefaultVal){
        this->data->SetSize_Matrix(QLines, QColumns, DefaultVal);
    }
    int Matrix::GetQExtRows() const{
        return this->data->GetQExtRows();
    }
    int Matrix::GetLength() const{
        return this->data->GetLength();
    }
    int Matrix::GetQLines() const{
        return this->data->GetQLines();
    }
    int Matrix::GetQColumns() const{
        return this->data->GetQColumns();
    }
    bool Matrix::NsBelongHere_byEI(int ExtRowN, int IneRowN) const{
        return this->data->NsBelongHere_byEI(ExtRowN, IneRowN);
    }
    bool Matrix::NsBelongHere_byLC(int LineN, int ColN) const{
        return this->data->NsBelongHere_byLC(LineN, ColN);
    }
    std::vector<double> Matrix::GetExtRowN_AsArray(int rowN) const{
        return this->data->GetExtRowN_AsArray(rowN);
    }
        ////double*GetExtRowN_AsPtr(int ExtRowN) const;
    std::vector<double> Matrix::GetIneRowN_AsArray(int rowN) const{
        return this->data->GetIneRowN_AsArray(rowN);
    }
    std::vector<double> Matrix::GetLineN_AsArray(int N) const{
        return this->data->GetLineN_AsArray(N);
    }
    std::vector<double> Matrix::GetColumnN_AsArray(int N) const{
        return this->data->GetColumnN_AsArray(N);
    }
    std::vector<double> Matrix::GetContent_AsArray1D_ExtRows() const{
        return this->data->GetContent_AsArray1D_ExtRows();
    }
    std::vector<std::vector<double>> Matrix::GetContent_AsArray2D_ExtRows() const{
        return this->data->GetContent_AsArray2D_ExtRows();
    }
    std::vector<double> Matrix::GetContent_AsArray1D_Lines() const{
        return this->data->GetContent_AsArray1D_Lines();
    }
    std::vector<std::vector<double>> Matrix::GetContent_AsArray2D_Lines() const{
        return this->data->GetContent_AsArray2D_Lines();
    }
    //
    //
    double Matrix::GetComponent_AsVal_byEI(int LineN, int ColN) const{
        return this->data->GetComponent_AsVal_byEI(LineN, ColN);
    }
    double Matrix::GetComponent(int LineN, int ColN) const{
        return this->data->GetComponent(LineN, ColN);
    }
    void Matrix::SetComponent_byEI(double val, int ExtRowN, int IneRowN){
        return this->data->SetComponent_byEI(val, ExtRowN, IneRowN);
    }
    void Matrix::SetComponent(double val, int LineN, int ColN){
        return this->data->SetComponent(val, LineN, ColN);
    }
    //
    ////void AddToExtRowN(int RowN, doubleval);
    ////void InsToExtRowN(int RowN, int PosN, doubleval);
    ////void DelFromExtRowN(int RowN, int PosN);
    //
    ////virtual void AddToExtRowN_Simply(int ExtRowN, doubleval)=0;
    ////virtual void InsToExtRowN_Simply(int ExtRowN, int PosN, doubleval)=0;
    ////virtual void DelFromExtRowN_Simply(int RowN, int IneRowPosN)=0;
    //
    /// //all this is not for rectangular array!
    //
    // Ext row
    //
    //// void ArrayOf2DBy1D_SetExtRowN(double*&X, Array2DSize&size, int ExtRowN,       double DefaultVal,double*rowParam, int wholeRowL=0,                      TParamsOfDataShift*DataShiftParam=NULL, /*bool KeepIfRect=true,*/ bool DefaultIsSpecNotOwn=true,      int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2){
    ////virtual              void               SetExtRowN(                              int N, double defaultVal, double*rowParam,      int rowL,    TParamsOfDataShift*DataShiftParams=NULL,                          bool DefaulsAreSpecNotOwnVals=true, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2)=0;
    //
void Matrix::SetExtRowN(int N, double*rowParam, int rowL, double defaultVal, TParamsOfDataShift*DataShiftParams, bool DefaulsAreSpecNotOwnVals, int ifNLNE_ByM1ByNewRow2ByMax3){
    this->data->SetExtRowN( N,        rowParam,     rowL,        defaultVal,                    DataShiftParams,      DefaulsAreSpecNotOwnVals,     ifNLNE_ByM1ByNewRow2ByMax3);
}
    //
void Matrix::SetExtRow_Simply(int N,double*rowParam){
    this->data->SetExtRow_Simply(N, rowParam);
}
void Matrix::SetLineN   (                    int     N, double*rowParam, int rowL,        double defaultVal,TParamsOfDataShift*DataShiftParams,  bool DefaulsAreSpecNotOwnVals, int ifNLNE_ByM1ByNewRow2ByMax3){
    this->data->SetLineN(                            N,        rowParam,     rowL,               defaultVal,                   DataShiftParams,       DefaulsAreSpecNotOwnVals,     ifNLNE_ByM1ByNewRow2ByMax3);
}
void Matrix::SetLine_Simply(int N, double*rowParam){
    this->data->SetLine_Simply(N, rowParam);
}
void  Matrix::AddExtRow(                             double*rowParam, int wholeRowL,                             TParamsOfDataShift*DataShiftParam,   double DefaultVal,  int ifNLNE_ByM1ByNewRow2ByMax3,                                                         TValsShowHide*vsh){
    this->data->AddExtRow(                                  rowParam,     wholeRowL,                                                DataShiftParam,          DefaultVal,      ifNLNE_ByM1ByNewRow2ByMax3,                                                                       vsh);
}
                          //
void     Matrix::AddLine(                             double*rowParam, int wholeRowL,                             TParamsOfDataShift*DataShiftParam,   double DefaultVal,  int ifNLNE_ByM1ByNewRow2ByMax3,                                                         TValsShowHide*vsh){
    this->data->AddLine(                                     rowParam,     wholeRowL,                                                DataShiftParam,          DefaultVal,      ifNLNE_ByM1ByNewRow2ByMax3,                                                                       vsh);
}
void Matrix::AddExtRow_OwnType(                             double*rowParam, int wholeRowL,                             TParamsOfDataShift*DataShiftParam,   double DefaultVal,  int ifNLNE_ByM1ByNewRow2ByMax3,                                                         TValsShowHide*vsh){
    this->data->AddExtRow_OwnType(                                 rowParam   ,  wholeRowL,                                                DataShiftParam,          DefaultVal,      ifNLNE_ByM1ByNewRow2ByMax3,                                                                       vsh);
}
void Matrix::AddLine_OwnType(                             double*rowParam, int wholeRowL,                             TParamsOfDataShift*DataShiftParam,   double DefaultVal,  int ifNLNE_ByM1ByNewRow2ByMax3,                                                         TValsShowHide*vsh){
    this->data->AddLine_OwnType(                                 rowParam,     wholeRowL,                                                DataShiftParam,          DefaultVal,      ifNLNE_ByM1ByNewRow2ByMax3,                                                                       vsh);
}
void Matrix::AddExtRow_Simply_OwnType(double*rowParam){
    this->data->AddExtRow_Simply_OwnType(rowParam);
}
void Matrix::AddLine_Simply_OwnType(double*rowParam){
    this->data->AddLine_Simply_OwnType(rowParam);
}
void Matrix::AddLine_Simply(double*rowParam){
    this->data->AddLine_Simply(rowParam);
}
void     Matrix::InsExtRowN(         int ExtRowN,                    double*rowParam, int wholeRowL,    TParamsOfDataShift*DataShiftParam,   double DefaultVal, int ifNLNE_ByM1ByNewRow2ByMax3,                                   TValsShowHide*vsh){
    this->data->InsExtRowN(              ExtRowN,                           rowParam,     wholeRowL,                       DataShiftParam,          DefaultVal,     ifNLNE_ByM1ByNewRow2ByMax3,                                                 vsh);
}
void       Matrix::InsLineN(         int LineN,                      double*rowParam, int wholeRowL,    TParamsOfDataShift*DataShiftParam,   double DefaultVal, int ifNLNE_ByM1ByNewRow2ByMax3,                                   TValsShowHide*vsh){
    this->data->InsLineN(                LineN,                             rowParam,     wholeRowL,                       DataShiftParam,          DefaultVal,     ifNLNE_ByM1ByNewRow2ByMax3,                                                 vsh);
}
void       Matrix::InsExtRowN_OwnType( int ExtRowN,                    double*rowParam, int wholeRowL,    TParamsOfDataShift*DataShiftParam,   double DefaultVal, int ifNLNE_ByM1ByNewRow2ByMax3,                                   TValsShowHide*vsh){
    this->data->InsExtRowN_OwnType(        ExtRowN,                           rowParam,     wholeRowL,                        DataShiftParam,         DefaultVal,     ifNLNE_ByM1ByNewRow2ByMax3,                                                 vsh);
}
void         Matrix::InsLineN_OwnType( int LineN,                      double*rowParam, int wholeRowL,    TParamsOfDataShift*DataShiftParam,   double DefaultVal, int ifNLNE_ByM1ByNewRow2ByMax3,                                   TValsShowHide*vsh){
    this->data->InsLineN_OwnType(          LineN,                             rowParam,     wholeRowL,                       DataShiftParam,          DefaultVal,     ifNLNE_ByM1ByNewRow2ByMax3,                                                 vsh);
}
void Matrix::InsExtRow_Simply(int N, double*rowParam){
    this->data->InsExtRow_Simply(N, rowParam);
}
void Matrix::InsExtRow_Simply_OwnType(int N, double*rowParam){
    this->data->InsExtRow_Simply_OwnType(N, rowParam);
}
//
void Matrix::InsLine_Simply(int N,double*rowParam){
    this->data->InsLine_Simply(N, rowParam);
}
void Matrix::InsLine_Simply_OwnType(int N,double*rowParam){
    this->data->InsLine_Simply_OwnType(N, rowParam);
}
//
void Matrix::DelExtRowN(int N){
    this->data->DelExtRowN(N);
}
void Matrix::DelLineN(int N){
    this->data->DelLineN(N);
}
void Matrix::DelExtRowN_Simply(int N){
    this->data->DelExtRowN_Simply(N);
}
void Matrix::DelLineN_Simply(int N){
    this->data->DelLineN_Simply(N);
}
//
//Ine row
//
void     Matrix::SetIneRowN(          int IneRowN,                   double*rowParam, int wholeRowL,                        TParamsOfDataShift*DataShiftParam, double DefaultVal, bool DafaultsAreSpecNotOwnVals, int ifNLNE_ByM1ByNewRow2ByMax3,                                   TValsShowHide*vsh){
    this->data->SetIneRowN(               IneRowN,                          rowParam,     wholeRowL,                                           DataShiftParam,        DefaultVal,      DafaultsAreSpecNotOwnVals,     ifNLNE_ByM1ByNewRow2ByMax3,                                                 vsh);
}
void     Matrix::SetColumnN(          int ColumnN,                   double*rowParam, int wholeRowL,                        TParamsOfDataShift*DataShiftParam, double DefaultVal, bool DafaultsAreSpecNotOwnVals, int ifNLNE_ByM1ByNewRow2ByMax3,                                   TValsShowHide*vsh){
    this->data->SetColumnN(               ColumnN,                          rowParam,     wholeRowL,                                           DataShiftParam,        DefaultVal,      DafaultsAreSpecNotOwnVals,     ifNLNE_ByM1ByNewRow2ByMax3,                                                 vsh);
}
void Matrix::SetIneRowSimply(int IneRowN,double*rowParam){
    this->data->SetIneRowSimply(IneRowN, rowParam);
}
void Matrix::SetColumnSimply(int IneRowN,double*rowParam){
    this->data->SetColumnSimply(IneRowN, rowParam);
}
void Matrix::SetIneRow_OwnType(         int IneRowN,                                        double*rowParam, int wholeRowL, TParamsOfDataShift*dataShiftParam, bool DefaultsAreSpecNotOwnVals,  double DefaultVal,  int ifNLNE_ByM1ByNewRow2ByMax3){
    this->data->SetIneRow_OwnType(          IneRowN,                                               rowParam,     wholeRowL,                    dataShiftParam,      DefaultsAreSpecNotOwnVals,         DefaultVal,      ifNLNE_ByM1ByNewRow2ByMax3);
}
void Matrix::SetColumn_OwnType(         int ColumnN,                                        double*rowParam, int wholeRowL, TParamsOfDataShift*dataShiftParam, bool DefaultsAreSpecNotOwnVals,  double DefaultVal,  int ifNLNE_ByM1ByNewRow2ByMax3){
    this->data->SetColumn_OwnType(          ColumnN,                                               rowParam,     wholeRowL,                    dataShiftParam,      DefaultsAreSpecNotOwnVals,         DefaultVal,      ifNLNE_ByM1ByNewRow2ByMax3);
}

void Matrix::SetIneRowSimply_OwnType(int IneRowN,double*rowParam){
    this->data->SetIneRowSimply_OwnType(IneRowN, rowParam);
}
void Matrix::SetColumnSimply_OwnType(int ColumnN,double*rowParam){
    this->data->SetColumnSimply_OwnType(ColumnN, rowParam);
}
void   Matrix::AddIneRow(                                                 double*rowParam, int wholeRowL,                         TParamsOfDataShift*dataShiftParam, double DefaultVal,      int ifNLNE_ByM1ByNewRow2ByMax3){
    this->data->AddIneRow(                                                       rowParam,     wholeRowL,                                            dataShiftParam,        DefaultVal,          ifNLNE_ByM1ByNewRow2ByMax3);
}
void  Matrix::AddColumn(                                                 double*rowParam, int wholeRowL,                        TParamsOfDataShift*dataShiftParam, double DefaultVal,       int ifNLNE_ByM1ByNewRow2ByMax3){
    this->data->AddColumn(                                                      rowParam,     wholeRowL,                                           dataShiftParam,        DefaultVal,           ifNLNE_ByM1ByNewRow2ByMax3);
}
void Matrix::AddIneRow_OwnType(double*rowParam, int wholeRowL, TParamsOfDataShift*dataShiftParam, double DefaultVal, int ifNLNE_ByM1ByNewRow2ByMax3){
     this->data->AddIneRow_OwnType(   rowParam,     wholeRowL,                    dataShiftParam,        DefaultVal,     ifNLNE_ByM1ByNewRow2ByMax3);
}
void Matrix::AddColumn_OwnType(double*rowParam, int wholeRowL, TParamsOfDataShift*dataShiftParam, double DefaultVal, int ifNLNE_ByM1ByNewRow2ByMax3){
    this->data->AddColumn_OwnType(    rowParam,     wholeRowL,                    dataShiftParam,        DefaultVal,     ifNLNE_ByM1ByNewRow2ByMax3);
}
//
void Matrix::AddIneRow_Simply(double*rowParam){
    this->data->AddIneRow_Simply(rowParam);
}
//
void Matrix::AddColumn_Simply(double*rowParam){
    this->data->AddColumn_Simply(rowParam);
}
//
void Matrix::AddIneRow_Simply_OwnType(double*rowParam){
    this->data->AddIneRow_Simply_OwnType(rowParam);
}
//
void Matrix::AddColumn_Simply_OwnType(double*rowParam){
    this->data->AddColumn_Simply_OwnType(rowParam);
}
//
void     Matrix::InsIneRowN(                         int IneRowN, double*rowParam, int wholeRowL, TParamsOfDataShift*DataShiftParam, double DefaultVal,                         int ifNLNE_ByM1ByNewRow2ByMax3){
   this->data->InsIneRowN(                                 IneRowN,        rowParam,     wholeRowL,                    DataShiftParam,        DefaultVal,                             ifNLNE_ByM1ByNewRow2ByMax3);
}
//
void     Matrix::InsColumnN(                         int ColumnN, double*rowParam, int wholeRowL, TParamsOfDataShift*DataShiftParam, double DefaultVal,                         int ifNLNE_ByM1ByNewRow2ByMax3){
   this->data->InsColumnN(                                 ColumnN,        rowParam,     wholeRowL,                    DataShiftParam,        DefaultVal,                             ifNLNE_ByM1ByNewRow2ByMax3);
}
void Matrix::InsIneRowN_OwnType(int IneRowN, double*rowParam, int wholeRowL, double DefaultVal,TParamsOfDataShift*DataShiftParam,                          int ifNLNE_ByM1ByNewRow2ByMax3){
    this->data->InsIneRowN_OwnType( IneRowN,        rowParam,     wholeRowL,        DefaultVal,                   DataShiftParam,                              ifNLNE_ByM1ByNewRow2ByMax3);
}
void Matrix::InsColumnN_OwnType(int ColumnN, double*rowParam, int wholeRowL, double DefaultVal,TParamsOfDataShift*DataShiftParam,                           int ifNLNE_ByM1ByNewRow2ByMax3){
    this->data->InsColumnN_OwnType( ColumnN,        rowParam,     wholeRowL,        DefaultVal,                   DataShiftParam,                              ifNLNE_ByM1ByNewRow2ByMax3);
}
void Matrix::InsIneRow_Simply(int N, double*rowParam){
    this->data->InsIneRow_Simply(N, rowParam);
}
void Matrix::InsColumn_Simply(int N, double*rowParam){
    this->data->InsColumn_Simply(N, rowParam);
}
void Matrix::InsIneRow_Simply_OwnType(int IneRowN, double*rowParam){
    this->data->InsIneRow_Simply_OwnType(IneRowN, rowParam);
}
void Matrix::InsColumn_Simply_OwnType(int ColumnN, double*rowParam){
    this->data->InsColumn_Simply_OwnType(ColumnN, rowParam);
}
void Matrix::DelIneRowN(int N){
    this->data->DelIneRowN(N);
}
void Matrix::DelColumnN(int N){
    this->data->DelColumnN(N);
}
void Matrix::DelIneRow_Simply(int N){
    this->data->DelIneRow_Simply(N);
}
void Matrix::DelColumn_Simply(int N){
    this->data->DelColumn_Simply(N);
}
//
// Set Content
//
void Matrix::Set_byEI(double**y, int QExtRows, int QIneRows, int TypeN){
    this->data->Set_byEI(y, QExtRows, QIneRows);
}
void Matrix::Set_byLC(double**y, int QLines, int QColumns, int TypeN){
    this->data->Set_byLC(y, QLines, QColumns);
}
void Matrix::Set_byCL(double**y, int QLines, int QColumns, int TypeN){
    this->data->Set_byLC(y, QLines, QColumns);
}
void Matrix::Set_byEI(double*y, int QExtRows, int QIneRows, int TypeN){
    this->data->Set_byEI(y, QExtRows, QIneRows);
}
void Matrix::Set_byLC(double*y, int QLines, int QColumns, int TypeN){
    this->data->Set_byLC(y, QLines, QColumns);
}
void Matrix::Set_byCL(double*y, int QLines, int QColumns, int TypeN){
    this->data->Set_byLC(y, QLines, QColumns);
}
void Matrix::Set_byEI(double val, int QExtRows, int ExtRowsLength, int TypeN){
    this->data->Set_byEI(val, QExtRows, ExtRowsLength);
}
void Matrix::Set_byLC(double val, int QLines, int QColumns, int TypeN){
    this->data->Set_byLC(val, QLines, QColumns);
}
void Matrix::Set_byEIR(std::vector<double>arr, int QExtRows, int TypeN){
    this->data->Set_byEIR(arr, QExtRows);
}
void Matrix::Set_byLC(std::vector<double>arr, int QLines, int TypeN){
    this->data->Set_byLC(arr, QLines);
}
void Matrix::Set_byCL(std::vector<double>arr, int QColumns, int TypeN){
    this->data->Set_byCL(arr, QColumns);
}
void Matrix::Set_byEIR(std::vector<std::vector<double>>arr, int ifLNE_ExtRows_By_Max3Min4, int TypeN){
    this->data->Set_byEIR(arr, ifLNE_ExtRows_By_Max3Min4);
}
void Matrix::Set_byLC(std::vector<std::vector<double>>arr, int ifLNE_Lines_By_Max3Min4, int TypeN){
    this->data->Set_byEIR(arr, ifLNE_Lines_By_Max3Min4);
}
void Matrix::Set_byCL(std::vector<std::vector<double>>arr, int ifLNE_Lines_By_Max3Min4, int TypeN){
    this->data->Set_byCL(arr, ifLNE_Lines_By_Max3Min4);
}
//
void Matrix::SwapVals_byEI(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2){
    this->data->SwapVals_byEI(ExtRowN1, IneRowN1, ExtRowN2, IneRowN2);
}
void Matrix::SwapVals_byLC(int LineN1, int ColN1, int LineN2, int ColN2){
    this->data->SwapVals_byLC(LineN1, ColN1, LineN2, ColN2);
}
//
void Matrix::SwapExtRows(int N1, int N2){
    this->data->SwapExtRows(N1, N2);
}
//
void Matrix::SwapLines(int N1, int N2){
    this->data->SwapLines(N1, N2);
}
//
void Matrix::SwapIneRows(int N1, int N2){
    this->data->SwapIneRows(N1, N2);
}
//
void Matrix::SwapColumns(int N1, int N2){
    this->data->SwapColumns(N1, N2);
}
//
//
void Matrix::ReverseExtRowN(int rowN){
    this->data->ReverseExtRowN(rowN);
}
void Matrix::ReverseLineN(int rowN){
    this->data->ReverseLineN(rowN);
}
void Matrix::ReverseIneRowN(int rowN){
    this->data->ReverseIneRowN(rowN);
}
void Matrix::ReverseColumnN(int rowN){
    this->data->ReverseColumnN(rowN);
}
void Matrix::ReverseExtRowsSuccession(){
    this->data->ReverseExtRowsSuccession();
}
void Matrix::ReverseLinesSuccession(){
    this->data->ReverseLinesSuccession();
}
void Matrix::ReverseIneRowsSuccession(){
    this->data->ReverseIneRowsSuccession();
}
void Matrix::ReverseColumnsSuccession(){
    this->data->ReverseColumnsSuccession();
}
//
bool Matrix::ValIsAtPos_byEI(double val, int ExtRowN, int IneRowN) const{
    return this->data->ValIsAtPos_byEI(val, ExtRowN, IneRowN);
}
bool Matrix::ValIsAtPos_byLC(double val, int LineN, int ColN) const{
    return this->data->ValIsAtPos_byLC(val, LineN, ColN);
}
std::vector<std::vector<int>> Matrix::SeekVal_ByEI(double val) const{
    return this->data->SeekVal_ByEI(val);
}
std::vector<std::vector<int>> Matrix::SeekVal(double val) const{
    return this->data->SeekVal(val);
}
bool Matrix::ExtRowIsAtPos(double*row, int Q, int ExtRowN, int IneRowN) const{
    return this->data->ExtRowIsAtPos(row, Q, ExtRowN, IneRowN);
}
bool Matrix::LineIsAtPos(double*row, int Q, int LineN, int ColN) const{
    this->data->LineIsAtPos(row, Q, LineN, ColN);
}
std::vector<std::vector<int>> Matrix::SeekExtRow(double*row, int L) const{
    this->data->SeekExtRow(row, L);
}
std::vector<std::vector<int>> Matrix::SeekLine(double*row, int L) const{
    return this->data->SeekLine(row, L);
}
bool Matrix::IneRowIsAtPos(double*row, int Q, int ExtRowN, int IneRowN) const{
    this->data->IneRowIsAtPos(row, Q, ExtRowN, IneRowN);
}
bool Matrix::ColumnIsAtPos(double*row, int Q, int LineN, int ColN) const{
    return this->data->IneRowIsAtPos(row, Q, LineN, ColN);
}
std::vector<std::vector<int>> Matrix::SeekIneRow(double*row, int Q) const{
    return this->data->SeekIneRow(row, Q);
}
std::vector<std::vector<int>> Matrix::SeekColumn(double*row, int Q) const{
    return this->data->SeekColumn(row, Q);
}

bool Matrix::Arr2DIsAtPos_byEI(std::vector<std::vector<double>>arr,             int ExtRowN, int IneRowN, bool isNotTransposed, bool ExtRowsSuccIsNotReversed, bool EachExtRowIsNotReversed) const{
    return this->data->Arr2DIsAtPos_byEI(                             arr,                 ExtRowN,     IneRowN,      isNotTransposed,      ExtRowsSuccIsNotReversed,      EachExtRowIsNotReversed);
}
bool Matrix::           Arr2DIsAtPos_byLC(std::vector<std::vector<double>>arr,             int LineN,   int ColN,    bool isNotTransposed, bool ExtRowsSuccIsNotReversed, bool EachExtRowIsNotReversed) const{
     return this->data->Arr2DIsAtPos_byLC(                                arr,                 LineN,       ColN,         isNotTransposed,      ExtRowsSuccIsNotReversed,      EachExtRowIsNotReversed);
}
std::vector<std::vector<int>> Matrix::SeekArr2D_byEI(std::vector<std::vector<double>>arr, bool isNotTransposed, bool ExtRowsSuccIsNotReversed, bool EachExtRowIsNotReversed) const{
    return this->data->    SeekArr2D_byEI(                                arr,      isNotTransposed,      ExtRowsSuccIsNotReversed,      EachExtRowIsNotReversed);
}
std::vector<std::vector<int>> Matrix::SeekArr2D_byLC(std::vector<std::vector<double>>arr, bool isNotTransposed, bool ExtRowsSuccIsNotReversed, bool EachExtRowIsNotReversed) const{
    return this->data->    SeekArr2D_byLC(                                arr,      isNotTransposed,      ExtRowsSuccIsNotReversed,      EachExtRowIsNotReversed);
}
//
std::vector<double> Matrix::SubMatrix_As1DArr_ByEINs_NurBelonging(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2){
   return  this->data->     SubMatrix_As1DArr_ByEINs_NurBelonging(     ExtRowN1,    IneRowN1,     ExtRowN2,     IneRowN2);
}
std::vector<double> Matrix::SubMatrix_As1DArr_ByLCNs_NurBelonging(int LineN1, int ColN1, int LineN2, int ColN2){
    return  this->data->    SubMatrix_As1DArr_ByLCNs_NurBelonging(    LineN1,     ColN1,     LineN2,     ColN2);
}
std::vector<double> Matrix::SubMatrix_As1DArr_ByCLNs_NurBelonging(int LineN1, int ColN1, int LineN2, int ColN2){
    return  this->data->    SubMatrix_As1DArr_ByCLNs_NurBelonging(    LineN1,     ColN1,     LineN2,     ColN2);
}
std::vector<std::vector<double>> Matrix::SubMatrix_As2DArr_ByEINs_NurBelonging(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2){
    return  this->data->                 SubMatrix_As2DArr_ByEINs_NurBelonging(    ExtRowN1,     IneRowN1,     ExtRowN2,     IneRowN2);
 }
std::vector<std::vector<double>> Matrix::SubMatrix_As2DArr_ByLCNs_NurBelonging(int LineN1, int ColN1, int LineN2, int ColN2){
    return  this->data->                 SubMatrix_As2DArr_ByLCNs_NurBelonging(    LineN1,     ColN1,     LineN2,     ColN2);
}
std::vector<std::vector<double>> Matrix::SubMatrix_As2DArr_ByCLNs_NurBelonging(int LineN1, int ColN1, int LineN2, int ColN2){
    return  this->data->                 SubMatrix_As2DArr_ByCLNs_NurBelonging(    LineN1,     ColN1,     LineN2,     ColN2);
}

std::vector<std::vector<double>> Matrix::SubMatrixAsSuccOfRows_AsArr2D_byEI(TParamsOfDataShift ShiftParams){
    return  this->data->     SubMatrixAsSuccOfRows_AsArr2D_byEI(ShiftParams);
}
std::vector<std::vector<double>> Matrix::SubMatrixAsSuccOfRows_AsArr2D_byEI(int QReq, int FromN, int QDefaultsBefore){
    return  this->data->                 SubMatrixAsSuccOfRows_AsArr2D_byEI(    QReq,     FromN,     QDefaultsBefore);
}

std::vector<std::vector<double>> Matrix::SubMatrixAsSuccOfRows_AsArr2D_byLC(TParamsOfDataShift ShiftParams){
    return  this->data->                 SubMatrixAsSuccOfRows_AsArr2D_byLC(ShiftParams);
}
std::vector<std::vector<double>> Matrix::SubMatrixAsSuccOfRows_AsArr2D_byLC(int QReq, int FromN, int QDefaultsBefore){
    return  this->data->                 SubMatrixAsSuccOfRows_AsArr2D_byLC(    QReq,     FromN,     QDefaultsBefore);
}
std::vector<std::vector<double>> Matrix::SubMatrixAsSuccOfRows_AsArr2D_byCL(TParamsOfDataShift ShiftParams){
    return  this->data->                 SubMatrixAsSuccOfRows_AsArr2D_byCL(ShiftParams);
}
std::vector<std::vector<double>> Matrix::SubMatrixAsSuccOfRows_AsArr2D_byCL(int QReq, int FromN, int QDefaultsBefore){
    return  this->data->                 SubMatrixAsSuccOfRows_AsArr2D_byCL(    QReq,     FromN,     QDefaultsBefore);
}
//
void Matrix::ConcatAdding_byEI(Matrix_Prototype*obj,int QShiftedCols, TParamsOfDataShift*DataShiftParam, double DefaultVal){
      this->data->ConcatAdding_byEI(            obj,    QShiftedCols,                    DataShiftParam,        DefaultVal);
}
void Matrix::ConcatAdding_byLC(Matrix_Prototype*obj,int QShiftedCols, TParamsOfDataShift*DataShiftParam, double DefaultVal){
    this->data->ConcatAdding_byLC(              obj,    QShiftedCols,                    DataShiftParam,        DefaultVal);
}
void Matrix::   ConcatStretching_byEI(Matrix_Prototype*obj,  int QShiftedLinesNs,  TParamsOfDataShift*DataShiftParam){
    this->data->ConcatStretching_byEI(                 obj,      QShiftedLinesNs,                     DataShiftParam);
}
void Matrix::   ConcatStretching_byLC(Matrix_Prototype*obj,  int QShiftedLinesNs,  TParamsOfDataShift*DataShiftParam){
    this->data->ConcatStretching_byLC(                 obj,      QShiftedLinesNs,                     DataShiftParam);
}
//
void Matrix::   ValSetOrAddOrFillOrIgnore_byEI(double val, int ExtRowN, int IneRowN){
    this->data->ValSetOrAddOrFillOrIgnore_byEI(       val,     ExtRowN,     IneRowN);
}
void Matrix::   ValSetOrAddOrFillOrIgnore(double val, int LineN, int ColN){
    this->data->ValSetOrAddOrFillOrIgnore(       val,     LineN,     ColN);
}
//
void Matrix::   StdCout_ExtRowN(int ExtRowN, QString ElemsDelim, bool UseBrackets)const{
    this->data->StdCout_ExtRowN(  ExtRowN,        ElemsDelim,      UseBrackets);
}
void Matrix::   StdCout_IneRowN(int IneRowN, QString ElemsDelim, bool UseBrackets, bool Represent2DNot1D)const{
    this->data->StdCout_IneRowN(    IneRowN,         ElemsDelim,      UseBrackets,      Represent2DNot1D);
}
void Matrix::   StdCout_LineN(int LineN, QString ElemsDelim, bool UseBrackets)const{
    this->data->StdCout_LineN(    LineN,         ElemsDelim,      UseBrackets);
}
void Matrix::   StdCout_ColumnN(int ColumnN, QString ElemsDelim, bool UseBrackets, bool Represent2DNot1D)const{
    this->data->StdCout_ColumnN(    ColumnN,         ElemsDelim,      UseBrackets,      Represent2DNot1D);
}
void Matrix::   StdCout(QString ElemsDelim, QString RowsDelim, bool UseBrackets, bool Represent2DNot1D, bool ByExtRowsNotIneRows)const{
    this->data->StdCout(        ElemsDelim,         RowsDelim,      UseBrackets,      Represent2DNot1D,      ByExtRowsNotIneRows);
}
//
//
//
void Matrix::FillByNs(){
    int QLines=this->GetQLines(), QColumns=this->GetQColumns();
    double val;
    for(int i=1; i<=QLines; i++){
        for(int j=1; j<=QColumns; j++){
            val=i*10+j;
            this->SetComponent(val, i, j);
        }
    }
}
void Matrix::SetDataOfVect3D(double x, double y, double z){
    this->data->SetDataOfVect3D(x, y, z);
}
void Matrix::MakeVect3D(double x, double y, double z){
    this->data->MakeVect3D(x, y, z);
}
void Matrix::SetX(double val){
    this->data->SetX(val);
}
void Matrix::SetY(double val){
    this->data->SetY(val);
}
void Matrix::SetZ(double val){
    this->data->SetZ(val);
}
double Matrix::GetX() const{
    return this->data->GetX();
}
double Matrix::GetY() const{
    return this->data->GetY();
}
double Matrix::GetZ() const{
    return this->data->GetZ();
}
//
// Mathematics
//
void Matrix::Transpose(){
    this->Transpose();
}
Matrix  Matrix::GetTransposed(){
    return this->GetTransposed();
}
Matrix Matrix::MinorTo(int LineN, int ColN){
    Matrix M;
    //M = this.DelLineTo(LineN);
    // M = M.DelColTo(ColN);
    M = *this;
    M.DelLineN(LineN);
    M.DelColumnN(ColN);
    return M;
}
Matrix Matrix::MinorTo(Matrix M, int LineN, int ColN){
    Matrix MR;
    //M = this.DelLineTo(LineN);
    // M = M.DelColTo(ColN);
    MR = M;
    MR.DelLineN(LineN);
    MR.DelColumnN(ColN);
    return MR;
}
void Matrix::SetMinor(int LineN, int ColumnN){
    this->DelLineN(LineN);
    this->DelColumnN(ColumnN);
}
double Matrix::AlgSuppl(int LineN, int ColumnN) const{
    int QLines=this->GetQLines(), QColumns=this->GetQColumns();
    double d, r;
    Matrix M;
    //M = new Matrix();
    if ((LineN < 1) || (LineN > QLines) || (ColumnN < 1) || (ColumnN > QColumns)){
        r = 666;
    }else{
        //M = (Matrix)this.MemberwiseClone();
        M = *this;
        //M = MinorTo(M, LineN, ColumnN);
        M.SetMinor(LineN, ColumnN);
        d = M.Determinant();
        r = d;
        if ((LineN + ColumnN)%2 != 0){
            r *= (-1);
        }
    }
    return r;
}
double Matrix::Determinant() const{
    double r, d, AlgSpl;
    double c11=this->GetComponent(1,1), c12=this->GetComponent(1,2), c13=this->GetComponent(1,3),
           c21=this->GetComponent(2,1), c22=this->GetComponent(2,2), c23=this->GetComponent(2,3),
           c31=this->GetComponent(3,1), c32=this->GetComponent(3,2), c33=this->GetComponent(3,3);
    int QLines=this->GetQLines(), QColumns=this->GetQColumns(), RowN;
    if (QColumns != QLines) return 666;
    else{
        if (QLines == 1){
             r = c11;
        }else if (QLines == 2){
            r = c11 * c22 - c12 *c21;
        }else if (QLines == 3){
            r = c11 * c22 *c33 +c13 * c21 * c32 + c31 * c12 * c23 -
                c13 * c22 *c31 -c11 * c23 * c32 - c33 * c12 * c21;
        }else{
            RowN = 1;
            r = 0;
            for (int j = 1; j <= QColumns; j++){
                r += this->GetComponent(RowN, j) * this->AlgSuppl(RowN, j);
            }
        }
    }
    return r;
}
Matrix Matrix::CalcUnionMatrix() const{
    int QLines = this->GetQLines(), QColumns = this->GetQColumns();
    int TQLines = QColumns, TQColumns = QLines;
    double CurAlgSuppl;// det=this->Determinant(), vali, valf;
    Matrix MUR;// = new Matrix();
    //    double[][] c;
    //    double CurAlgSuppl;//, det = this.Determinant();
    //    c = new double[TQLines][];
    //    for (int i = 1; i <= TQLines; i++){
    //        c[i - 1] = new double[TQColumns];
    //    }
    //    for (int i = 1; i <= QLines; i++){
    //        for (int j = 1; j <= QColumns; j++){
    //            CurAlgSuppl = this.AlgSuppl(i, j);
    //            c[j - 1][i - 1] = CurAlgSuppl;
    //        }
    //    }
    //MUR = new Matrix(c, TQLines, TQColumns);
    MUR.SetSize_Matrix(TQLines, TQColumns);
    for(int i = 1; i <= QLines; i++){
        for(int j = 1; j <= QColumns; j++){
            CurAlgSuppl = this->AlgSuppl(i, j);
            MUR.SetComponent(CurAlgSuppl, j, i);
         }
    }
    return MUR;
}
Matrix Matrix::CalcInverted() const{
    Matrix MIR;
    double det = this->Determinant();
    if(this->GetQLines()>0 && this->GetQLines()==this->GetQColumns() && det != 0){
        MIR = this->CalcUnionMatrix();
        MIR = MIR * (1 / det);
    }
    return MIR;
}
void Matrix::MakeUnionMatrix(){
    *this=this->CalcUnionMatrix();
}

void Matrix::Invert(){
    *this=this->CalcInverted();
}
Matrix Matrix::CalcGivensRotationTransform(int N1, int N2, TValsShowHide* vsh){
    int QL=this->GetQLines();
    Matrix T(QL,QL);
    double a11=this->GetComponent(N1, N1), //a11=M.GetComponent(N1, N1),
           a21=this->GetComponent(N2, N1), //a21=M.GetComponent(N2, N1),
           c12, s12, denom;
    for(int i=1; i<=QL; i++){
        for(int j=1; j<=QL; j++){
            T.SetComponent(0, i, j);
        }
    }
    for(int i=1; i<=QL; i++){
        T.SetComponent(1, i, i);
    }
    if(a21==0){
        c12=1;
        s12=0;
    }else{
        denom=sqrt(a11*a11+a21*a21);
        c12=a11/denom;
        s12=a21/denom;
    }
    //MyLib.writeln(vsh, " T=" +M.ToString());
    //MyLib.writeln(vsh, " a11=" +a11.ToString() + " a21=" + a21.ToString()+ " c12=" + c12.ToString() + " s12=" + s12.ToString());
    T.SetComponent(c12, N1, N1);
    T.SetComponent(c12, N2, N2);
    T.SetComponent(s12, N1, N2);
    T.SetComponent(-s12, N2, N1);
    return T;
}
void Matrix::QRDecomposition(Matrix&Q, Matrix&R, Matrix*M, TValsShowHide*vsh){
    writeln(vsh, "QRDecomposition starts working");
    if (M == NULL){
        M = this;
    }
    int QL = M->GetQLines();
    //int[] ns = new int[QL-1];
    int* ns = new int[QL-1];
    //int countTsInLine;
    int jn, ii, jj;
    //Q = new Matrix(QL, QL);
    Q.SetNull();
    Q.SetSize_Matrix(QL, QL);
    for(int i = 1; i <= QL; i++){
        Q.SetComponent(1, i, i);
    }
    //Matrix[][] Ts=new Matrix[QL-1][];
    Matrix** Ts=new Matrix*[QL-1];
    for(int i = 1; i <= QL - 1; i++){
        ns[i - 1] = QL - 1 - i + 1;
        Ts[i - 1] = new Matrix[ns[i - 1]];
    }
    //Matrix[] TL=null;
    Matrix* TL=NULL;
    Matrix T;//, R=new Matrix(QL, QL);
    R.Assign(*M);
    //MyLib.writeln(vsh, "M="+M.ToString());
    //MyLib.writeln(vsh, "ini Q=" + Q.ToString());
    //MyLib.writeln(vsh, "ini R=" + R.ToString());
    for(int i = 1; i <= QL - 1; i++){
        //countTsInLine = 0;
        for(int j = i + 1; j <= QL; j++){
            //countTsInLine++; //in AddToVector
            //MyLib.writeln(vsh, "i=" + i.ToString()+" j="+j.ToString());
             T = R.CalcGivensRotationTransform(i, j);//, vsh);
             //MyLib.writeln(vsh, "T=" + T.ToString());
             R = T * R;
             //MyLib.writeln(vsh, "cur R=" + R.ToString());
             jn = j - i;
             Ts[i - 1][jn - 1] = T;
             //MyLib.AddToVector(ref TL, ref countTsInLine, R);
        }
        //MyLib.AddToVector(ref Ts, ref n, TL);
    }
    //R is completed, beginning wit Q
    for(int i=1; i<=QL-1; i++){
        ii = QL - 1 - i + 1;
        for(int j = 1; j <= ns[ii - 1]; j++){
            jj = ns[ii - 1] - j + 1;
            T = Ts[ii - 1][jj - 1];
            Q = Q * T;
        }
    }
    Q.Transpose();
    //
    if(ns!=NULL){
        delete[]ns;
    }
    delete[]TL;
    for(int i = 1; i <= QL - 1; i++){
        delete[]Ts[i-1];
    }
    delete[]Ts;
    //MyLib.writeln(vsh, "QRDecomposition finishes working");
}//fn QR decomp
//};

Matrix& operator + (const Matrix&M1, const Matrix&M2){
    Matrix M3;
    int QL1=M1.GetQLines(), QC1=M1.GetQColumns(),  QL2=M2.GetQLines(), QC2=M2.GetQColumns();
    double x1, x2, x3;
    M3.SetSize_Matrix(QL1, QC2);
    for(int i=1; i<=QL1; i++){
        for(int j=1; j<=QC2; j++){
            x1=M1.GetComponent(i, j);
            x2=M2.GetComponent(i, j);
            x3=x1+x2;
            M3.SetComponent(x3, i, j);
        }
    }
    return M3;
}
Matrix& operator - (const Matrix&M1, const Matrix&M2){
    Matrix M3;
    int QL1=M1.GetQLines(), QC1=M1.GetQColumns(),  QL2=M2.GetQLines(), QC2=M2.GetQColumns();
    double x1, x2, x3;
    M3.SetSize_Matrix(QL1, QC2);
    for(int i=1; i<=QL1; i++){
        for(int j=1; j<=QC2;j++){
            x1=M1.GetComponent(i, j);
            x2=M2.GetComponent(i, j);
            x3=x1-x2;
            M3.SetComponent(x3, i, j);
        }
    }
    return M3;
}
Matrix& operator * (const Matrix&M1, const Matrix&M2){
    Matrix MR;
    int QL1=M1.GetQLines(), QC1=M1.GetQColumns(), QL2=M2.GetQLines(), QC2=M2.GetQColumns(), QL, QC, QM;
    double x1, x2, x;
    if(QC1==QL2){
        QM=QC1;
        QL=QL1;
        QC=QC2;
        MR.SetSize_Matrix(QL, QC);
        for(int i=1; i<=QL; i++){
            for(int j=1; j<=QC; j++){
                for(int k=1; k<=QM; k++){
                    x1=M1.GetComponent(i, k);
                    x2=M2.GetComponent(k, j);
                    x=x1*x2;
                    MR.SetComponent(x, i, j);
                }
            }
        }
    }
    return MR;
}
Matrix& operator * (const Matrix&M1, double k){
    Matrix M3;
    int QL1=M1.GetQLines(), QC1=M1.GetQColumns();//,  QL2=M2.GetQLines(), QC2=M2.GetQColumns();
    double x1, x2, x3;
    M3.SetSize_Matrix(QL1, QC1);
    for(int i=1; i<=QL1; i++){
        for(int j=1; j<=QC1; j++){
            x1=M1.GetComponent(i, j);
            //x2=M2.GetComponent(i, j);
            x3=x1*k;
            M3.SetComponent(x3, i, j);
        }
    }
    return M3;
}
Matrix& operator * (double k, const Matrix&M2){
    Matrix M3;
    int QL2=M2.GetQLines(), QC2=M2.GetQColumns();//,  QL2=M2.GetQLines(), QC2=M2.GetQColumns();
    double x1, x2, x3;
    M3.SetSize_Matrix(QL2, QC2);
    for(int i=1; i<=QL2; i++){
        for(int j=1; j<=QC2; j++){
            x2=M2.GetComponent(i, j);
            //x1=M1.GetComponent(i, j);
            x3=x2*k;
            M3.SetComponent(x3, i, j);
        }
    }
    return M3;
}
Matrix& operator / (const Matrix&M1, const Matrix&M2){
    Matrix MI=M2.CalcInverted();
    Matrix MR=MI*M1;
    return MR;
}
Matrix CalcMatrixOfDirCossByEulersAngles(double gamma, double psi, double theta){
    Matrix MR(3, 3);
    MR.SetComponent(cos(psi) * cos(theta), 1, 1);
    MR.SetComponent(sin(psi) * sin(gamma) - cos(psi) * sin(theta) * cos(gamma), 1, 2);
    MR.SetComponent(sin(psi) * cos(gamma) + cos(psi) * sin(theta) * sin(gamma), 1, 3);
    MR.SetComponent(sin(theta), 2, 1);
    MR.SetComponent(cos(theta) * cos(gamma), 2, 2);
    MR.SetComponent(cos(theta) * sin(gamma), 2, 3);
    MR.SetComponent(-sin(psi) * cos(theta), 3, 1);
    MR.SetComponent(cos(psi) * sin(gamma) + sin(psi) * sin(theta) * cos(gamma), 3, 2);
    MR.SetComponent(cos(psi) * cos(gamma) - sin(psi) * sin(theta) * sin(gamma), 3, 3);
    return MR;
}
Matrix CalcMatrixOfDirCossByEulersAnglesDeg(double gammaDeg, double psiDeg, double thetaDeg){
    return CalcMatrixOfDirCossByEulersAngles(gammaDeg*M_PI/180, psiDeg*M_PI/180, thetaDeg*M_PI/180);
}
Matrix CalcMatrixOfDirCossByEulersAngles(const Matrix&MOfEulerAngles){
    Matrix MR(3, 3);
    double gamma = MOfEulerAngles.GetX(),
       psi   = MOfEulerAngles.GetY(),
       theta = MOfEulerAngles.GetZ();
    MR=CalcMatrixOfDirCossByEulersAngles(gamma, psi, theta);
    return MR;
}
Matrix CalcMatrixOfDirCossByEulersAnglesDeg(const Matrix&MOfEulerAnglesDeg){
    Matrix MR(3, 3);
    double gamma = MOfEulerAnglesDeg.GetX() * M_PI / 180,
        psi   = MOfEulerAnglesDeg.GetY() * M_PI / 180,
        theta = MOfEulerAnglesDeg.GetZ() * M_PI / 180;
    MR=CalcMatrixOfDirCossByEulersAngles(gamma, psi, theta);
    return MR;
}

std::vector<int>LinesLinDepToDel(Matrix M, double eps){
    std::vector<int>Ns;//, NsCur;
    std::vector<int>NsIn;
    std::vector<double>line1, line2;
    int QLines=M.GetQLines(), QColumns=M.GetQColumns(), countAll, Nf, N;
    bool b;
    double k1, k2, v1, v2;
    for(int i=1; i<=QLines-1; i++){
        NsIn=VectorSeekVal(Ns, i);
        if(NsIn.size()==0){
            for(int j=i+1; j<=QLines; j++){
                b=true;
                NsIn=VectorSeekVal(Ns, j);
                b=(NsIn.size()==0);
                countAll=Ns.size();
                if(countAll>0){//finding occured, checking for Ns
                    for(int k=1; k<=countAll; k++){
                        Nf=Ns[k-1];
                        if(Nf==j){
                            b=false;
                        }
                    }
                }
                if(b){//line ns'del'd in prev opeg, su N ns'in list o'Ns
                    line1=M.GetLineN_AsArray(i);
                    line2=M.GetLineN_AsArray(j);
                    //b=CheckIfRowsAreLinearDependent(line1.data(), line2.data(), QColumns);
                    N=1;
                    v1=line1[N-1];
                    v2=line2[N-1];
                    if(v1==0 || v2==0){
                        b=false;
                    }else{
                        k1=v1/v2;
                    }
                    for(N=2; N<=QColumns; N++){
                        v1=line1[N-1];
                        v2=line2[N-1];
                        if(v1==0 || v2==0){
                            b=false;
                        }else{
                            k2=v1/v2;
                            if(fabs(k1-k2)>=eps){
                                b=false;
                            }
                        }
                    }
                    //or these actions instead of separ fn
                    if(b){//lines are linearly dependent
                        Ns.push_back(j);
                    }
                }
            }//for
        }
    }//for
    return Ns;
}

Matrix GetMatrixForEigenVectors(const Matrix&M, double eigenVal, double eps){
    Matrix MR=M;
    int QLines=M.GetQLines(), QColumns=M.GetQColumns(), QLinDep, QLinNew;
    std::vector<int>Ns;
    double val;
    for(int i=1; i<=QLines; i++){
        val=M.GetComponent(i, i);
        MR.SetComponent(val-eigenVal, i, i);
    }
    Ns=LinesLinDepToDel(MR, eps);
    QLinDep=Ns.size();
    for(int i=QLinDep; i>=1; i--){
        MR.DelLineN(i);
    }
    QLinNew=QLines-QLinDep;
    return MR;
}

//std:;vector<double>



//
//Matrix TransformCoordsFromGlobalToLocalCS(const Matrix&VectOfCoordsInLocalCS,  const Matrix&VectOfEulerAngles, Matrix*LocalCSOriginInGlobalCS=NULL);
//Matrix TransformCoordsFromGlobalToLocalCS(const Matrix&VectOfCoordsInGlobalCS, const Matrix&VectOfEulerAngles, Matrix*LocalCSOriginInGlobalCS=NULL);
