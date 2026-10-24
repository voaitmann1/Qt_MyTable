#include "matrices.h"

//class Matrix_Prototype{
//    virtual ~Matrix_Prototype()=default;
    //
//    virtual void SetNull()=0;
//    virtual void construct()=0;
//    virtual Matrix_Prototype* CreateArray() const=0;
//    virtual Matrix_Prototype* clone()const=0;
//    virtual int GetTypeN() const=0 ;
    //
    //void SetOne(T*DfltVal=NULL);
    //void SetOne(const T&DfltVal);
    void Matrix_Prototype::SetOne(){
        this->SetSize(1, 1);
    }
    //
    ////virtual void SetSize(const T& DfltValParam, const Array2DSize&size)=0;
    //
    ////void SetSize(const Array2DSize&size, T*DfltValParam=NULL);//virtual ob hin Sdo mut l'size data
    ////void SetSize(int QExtRows=1, int ExtRowsLength=1, T*DfltValParam=NULL);
    ////void SetSize(int QExtRows=1, int*ExtRowsLengthes=NULL, T*DfltValParam=NULL);//if Null => L=0
    ////void SetSize(std::vector<int>ExtRowsLengthes, T*DfltValParam=NULL);
    //
    ////void SetSize(const T& DfltValParam, int QExtRows=1, int ExtRowsLength=1);//virtual ob hin Sdo mut l'size data
    ////void SetSize(const T& DfltValParam, int QExtRows=1, int*ExtRowsLengthes=NULL);//if Null => L=0
    ////void SetSize(const T& DfltValParam, std::vector<int>Lengthes);
    //
    //virtual void SetSize(int QExtRows=1, int ExtRowsLength=1)=0;
    //
    ////virtual int GetQExtRows() const=0;
    ////virtual int GetLength(int ExtRowN=1) const=0;
    ////virtual int GetMinLength() const=0;
    ////virtual int GetMaxLength() const=0;
    //virtual int GetQLines()=0;
    //virtual int GetQColumns()=0;
    //virtual Array2DSize GetSize()const =0;
    //
    //bool LineNBelongsHere(int LineN) const;
    //bool ColNBelongsHere(int ColN) const;
    bool Matrix_Prototype::NsBelongHere(int LineN, int ColN) const{
        int QLines=this->GetQLines(), QColumns=this->GetQColumns();
        bool verdict;
        verdict=(LineN>=1 && LineN<=QLines && ColN>=1 && ColN<=QColumns);
        return verdict;
    }
    //
    //std::vector<T> GetArrayOfExtRowN(int LineN);
    //std::vector<T> GetArrayOfIneRowN(int ColN);
    //std::vector<T> GetContentAsArray1D();
    //std::vector<std::vector<T>> GetContentAsArray2D();
    //
    //std::vector<T> GetExtRowN_AsArray(int rowN) const;
    std::vector<double> Matrix_Prototype::GetLineN_AsArray(int rowN) const{
        double val;
        std::vector<double> row;
        int QLines=this->GetQLines(), QColumns=this->GetQColumns();
        if(rowN>=1 && rowN<=QLines){
            for(int i=1; i<=QColumns; i++){
                val=this->GetComponent(rowN, i);
                row.push_back(val);
            }
        }
        return row;
    }
    // T*GetExtRowN_AsPtr(int ExtRowN) const;
    //std::vector<T> GetIneRowN_AsArray(int rowN) const;
    std::vector<double> Matrix_Prototype::GetColumnN_AsArray(int rowN) const{
        double val;
        std::vector<double> row;
        int QLines=this->GetQLines(), QColumns=this->GetQColumns();
        if(rowN>=1 && rowN<=QColumns){
            for(int i=1; i<=QLines; i++){
                val=this->GetComponent(i, rowN);
                row.push_back(val);
            }
        }
        return row;
    }
    //std::vector<T> GetIneRowN_AsArray(int IneRowN, const T& defaultVal,                         int ifNGTLmin_Ignore0_DefaultsForShorter1_NurProperL_AnyExtRow2_NurFromStartTillErstStop3=0) const;
    //std::vector<T> GetIneRowN_AsArray(int IneRowN,                      T*DefaultValParam=NULL, int ifNGTLmin_Ignore0_DefaultsForShorter1_NurProperL_AnyExtRow2_NurFromStartTillErstStop3=0) const;
    //std::vector<T> GetContent_AsArray1D() const;
    //std::vector<std::vector<T>> GetContent_AsArray2D() const;
    std::vector<double> Matrix_Prototype::GetContent_AsArray1DOfLines() const{
        double val;
        std::vector<double> row;
        int QLines=this->GetQLines(), QColumns=this->GetQColumns();
        for(int i=1; i<=QLines; i++){
            for(int j=1; j<=QColumns; j++){
                val=this->GetComponent(i, j);
                row.push_back(val);
            }
        }
        return row;
    }
    std::vector<double> Matrix_Prototype::GetContent_AsArray1DOfColumns() const{
        double val;
        std::vector<double> row;
        int QLines=this->GetQLines(), QColumns=this->GetQColumns();
        for(int i=1; i<=QColumns; i++){
            for(int j=1; j<=QLines; j++){
                val=this->GetComponent(i, j);
                row.push_back(val);
            }
        }
        return row;
    }
    std::vector<std::vector<double>> Matrix_Prototype::GetContent_AsArray2DOfLines() const{
        double val;
        std::vector<double> row;
        std::vector<std::vector<double>> data;
        int QLines=this->GetQLines(), QColumns=this->GetQColumns();
        for(int i=1; i<=QLines; i++){
            for(int j=1; j<=QColumns; j++){
                val=this->GetComponent(i, j);
                row.push_back(val);
            }
            data.push_back(row);
        }
        return data;
    }
    std::vector<std::vector<double>> Matrix_Prototype::GetContent_AsArray2DOfColumns() const{
        double val;
        std::vector<double> row;
        std::vector<std::vector<double>> data;
        int QLines=this->GetQLines(), QColumns=this->GetQColumns();
        for(int i=1; i<=QColumns; i++){
            for(int j=1; j<=QLines; j++){
                val=this->GetComponent(i, j);
                row.push_back(val);
            }
            data.push_back(row);
        }
        return data;
    }
    //
    //
    ////virtual T GetComponent_AsVal(int LineN, int ColN) const=0;
    ////virtual T* GetComponent_AsPtr(int LineN, int ColN) const=0;
    //virtual double GetComponent(int LineN, int ColN) const=0;
    ////virtual double* GetComponent_AsPtr(int LineN, int ColN) const=0;
    //
    ////virtual void SetComponent(const T& val, int LineN, int ColN)=0;
    //virtual void SetComponent(double val, int LineN, int ColN)=0;
    //
    //void AddToExtRowN(int RowN, const T&val);
    //void InsToExtRowN(int RowN, int PosN, const T&val);
    //void DelFromExtRowN(int RowN, int PosN);
    //
    //virtual void AddToExtRowN_Simply(int ExtRowN, const T&val)=0;
    //virtual void InsToExtRowN_Simply(int ExtRowN, int PosN, const T&val)=0;
    //virtual void DelFromExtRowN_Simply(int RowN, int IneRowPosN)=0;
    //
    // Ext row
    //
    //template<typename T> void ArrayOf2DBy1D_SetExtRowN(T*&X, Array2DSize&size, int ExtRowN,       T DefaultVal, T*rowParam, int wholeRowL=0,                      TDataShiftParams*DataShiftParam=NULL, /*bool KeepIfRect=true,*/ bool DefaultIsSpecNotOwn=true,      int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2){
    //virtual              void               SetExtRowN(                              int N, const T& defaultVal,  T*rowParam,      int rowL,    TDataShiftParams*DataShiftParams=NULL,                          bool DefaulsAreSpecNotOwnVals=true, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2)=0;
    //void SetExtRowN(int N, const T& defaultVal, T*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true,                      int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2);
    //void SetExtRowN(int N,                      T*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, T*DfltValParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2);
    //
    //void SetExtRow_Simply(int N, T*rowParam)=0;
    //void SetExtRow_Simply(int N, T*rowParam, int L)=0;
    //
    //virtual void SetLineN_OwnDataType(int N,      double*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1)=0;
    void Matrix_Prototype::SetLineN_Gen(int N,      double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParams, bool DefaulsAreSpecNotOwnVals, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3){
        int QLines=this->GetQLines(), QColumns=this->GetQColumns(), LPre;
        std::vector<double>rowFact ,rowWas;
        TDataShiftParams DataShift;
        double val;
        if(DataShiftParams!=NULL){
            DataShift=(*(DataShiftParams));
        }
        LPre=DataShift.GetQAll(wholeRowL);
        //rowPre=Array1DGetSubArray_byLs_PreMark_v2(rowParam, wholeRowL, 0, &DataShift);
        //LPre=rowPre.size();
        if(wholeRowL==0){
            wholeRowL=QColumns;
        }
        switch(IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3){
            case 1:
                DataShift.QReq=QColumns;
            break;
            case 2:
                DataShift.QReq=LPre;
            break;
            case 3:
                DataShift.QReq = QColumns>= LPre ? QColumns : LPre;
            break;
        }
        //template <typename T>std::vector<T> Array1DGetSubArray_byLs_PreMark_v2(T*x, int rowL, T DefaultValue, TDataShiftParams*DataShiftParam=NULL){
        //template <typename T>std::vector<T> Array1DGetSubArray_byLs_PreMark_v2(T*x, int rowL, T*x2, int L2, T DefaultVal, TDataShiftParams*DataShiftParam=NULL){
        if(DefaulsAreSpecNotOwnVals==false){
            rowWas=this->GetLineN_AsArray(N);
            rowFact=Array1DGetSubArray_byLs_PreMark_v2(rowParam, wholeRowL, rowWas.data(), rowWas.size(), 0.0, &DataShift);
        }else{
            rowFact=Array1DGetSubArray_byLs_PreMark_v2(rowParam, wholeRowL, 0.0, &DataShift);
        }
        for(int i=1; i<=QColumns; i++){
            val=rowFact[i-1];
            this->SetComponent(val, N, i);
        }
    }
    //virtual void SetLineN_Simply(int N, double*rowParam)=0;
    //
    //template<typename T>void ArrayOf2DBy1D_AddExtRow(T*&X, Array2DSize&size, T DefaultVal, T*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL){
    //                      void               AddExtRow(                        T DefaultVal, T*rowParam, int wholeRowL=0,                         TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL);
    //template<typename T>void ArrayOf2DBy1D_AddExtRow(T*&X, Array2DSize&size, T*rowParam, int wholeRowL=0, T*DefaultValParam=NULL, TDataShiftParams*DataShiftParam=NULL,  int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL){
    //                      void               AddExtRow(                                      T*rowParam, int wholeRowL=0, T*DefaultValParam=NULL, TDataShiftParams*DataShiftParam=NULL,  int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL);
    //
    //virtual void AddExtRow_Simply(T*rowParam)=0;
    //virtual void AddExtRow_Simply(T*rowParam, int L)=0;
    //
    //virtual void AddLine_OwnDataType(double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL)=0;
    void Matrix_Prototype::AddLine_Gen(double*rowParam, int wholeRowL, TDataShiftParams*DataShiftParam, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3, TValsShowHide*vsh){
        int QLines=this->GetQLines(), QColumns=this->GetQColumns();
        this->SetSize(QLines+1, QColumns);
        this->SetLineN_Gen(QLines+1, rowParam, wholeRowL, DataShiftParam);
    }
    //virtual void AddLine_Simply(double*rowParam)=0;

    //template<typename T>void ArrayOf2DBy1D_InsExtRow(T*&X, Array2DSize&size, int ExtRowN, T DefaultVal, T*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL){
    //                      void               InsExtRow(                        int ExtRowN, T DefaultVal, T*rowParam, int wholeRowL=0,                      TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL);
    //template<typename T>void ArrayOf2DBy1D_InsExtRow(T*&X, Array2DSize&size, int ExtRowN, T*rowParam, int wholeRowL=0,  T*DfltValParam=NULL, TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL){
    //                      void               InsExtRow(                        int ExtRowN,               T*rowParam, int wholeRowL=0, T*DfltValParam=NULL, TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL);
    //
    //virtual void InsExtRow_Simply(int N, T*rowParam)=0;
    //virtual void InsExtRow_Simply(int N, T*rowParam, int L)=0;
    //
    //virtual void InsLine_OwnDataType(int LineN, double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL)=0;
    //void                 InsLine_Gen(int LineN, double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    void Matrix_Prototype::InsLine_Gen(int LineN, double*rowParam, int wholeRowL,   TDataShiftParams*DataShiftParam,      int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3,   TValsShowHide*vsh){
        int QLines=this->GetQLines(), QColumns=this->GetQColumns();
        if(LineN>=1 && LineN<=QLines){
            this->SetSize(QLines+1, QColumns);
            for(int i=QLines+1; i>=LineN+1; i--){
                this->SwapLines(i-1, i);
            }
            this->SetLineN_Gen(LineN, rowParam, wholeRowL, DataShiftParam,true, IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3);
        }
    }
    //virtual void InsLine_Simply(int LineN,double*rowParam)=0;
    //
    //void DelExtRowN(int N=-1);
    //virtual void DelExtRowN_Simply(int N=-1)=0;
    //
    //virtual void DelLineN_Simply(int N=-1)=0;
    void Matrix_Prototype::DelLineN_Gen(int LineN){
        int QLines=this->GetQLines(), QColumns=this->GetQColumns();
        if(LineN>=1 && LineN<=QLines){
            for(int i=LineN+1; i<=QLines; i++){
                this->SwapLines(i-1, i);
            }
            this->SetSize(QLines-1, QColumns);
        }
    }
    //
    //Ine row
    //
    ////void SetIneRowN( int IneRowN, const T& defaultVal, T*rowParam=NULL, int rowL=0, TDataShiftParams*DataShiftParam=NULL,                         bool DefaulsAreSpecNotOwnVals=true, int arr2D_ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_AnyExtRow3_NurFromStartTillErstStop4=0, int arr1D_ifNurProperL_NsSame1_EltsWithNsOfShoeterExtRowsNeUsed2=1);
    ////void SetIneRowN( int IneRowN,                      T*rowParam=NULL, int rowL=0, TDataShiftParams*DataShiftParam=NULL, T*DefaultValParam=NULL, bool DefaulsAreSpecNotOwnVals=true, int arr2D_ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_AnyExtRow3_NurFromStartTillErstStop4=0, int arr1D_ifNurProperL_NsSame1_EltsWithNsOfShoeterExtRowsNeUsed2=1);
    //
    ////virtual void SetIneRowSimply(int IneRowN, T*rowParam)=0;
    //
    //
    //virtual void SetColumnN_OwnDataType(int N,          double*rowParam, int      rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1)=0;
    void Matrix_Prototype::SetColumnN_Gen(int N,          double*rowParam, int wholeRowL, TDataShiftParams*DataShiftParams, bool DefaulsAreSpecNotOwnVals, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3){
        std::vector<double>rowFact ,rowWas;
        TDataShiftParams DataShift;
        int QLines=this->GetQLines(), QColumns=this->GetQColumns(), Lpre;
        double val;
        if(DataShiftParams!=NULL){
            DataShift=(*(DataShiftParams));
        }
        //rowPre=Array1DGetSubArray_byLs_PreMark_v2(rowParam, wholeRowL, 0, &DataShift);
        //LPre=rowPre.size();
        Lpre=DataShift.GetQAll(wholeRowL);
        if(wholeRowL==0){
            wholeRowL=QLines;
        }
        switch(IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3){
            case 1:
                DataShift.QReq = QLines;
            break;
            case 2:
                DataShift.QReq = Lpre;
            break;
            case 3:
                DataShift.QReq = QLines >= Lpre ? QColumns : Lpre;
            break;
        }
        if(DefaulsAreSpecNotOwnVals==false){
            rowWas=this->GetColumnN_AsArray(N);
            rowFact=Array1DGetSubArray_byLs_PreMark_v2(rowParam, wholeRowL, rowWas.data(), rowWas.size(), 0.0, &DataShift);
        }else{
            rowFact=Array1DGetSubArray_byLs_PreMark_v2(rowParam, wholeRowL, 0.0, &DataShift);
        }
        for(int i=1; i<=QLines; i++){
            val=rowFact[i-1];
            this->SetComponent(val, i, N);
        }
    }
    //void SetColumnN_Simply(int N, double*rowParam)=0;
    ////template<typename T>void ArrayOf2DBy1D_AddIneRow(T*&X, Array2DSize& size, T DefaultVal, T*rowParam=NULL, int wholeRowL=0, TDataShiftParams*dataShiftParam=NULL,                         int ifNGTLmin_Ignore0AddToLast1StretchToMax2=0, bool RectIfPossible=true){
    ////                     void               AddIneRow(                         T DefaultVal, T*rowParam=NULL, int wholeRowL=0, TDataShiftParams*dataShiftParam=NULL,                         int ifNGTLmin_Ignore0AddToLast1StretchToMax2=0, bool RectIfPossible=true)=0;
    ////                     void               AddIneRow(                                       T*rowParam=NULL, int wholeRowL=0, TDataShiftParams*dataShiftParam=NULL, T*DefaultValParam=NULL, int ifNGTLmin_Ignore0AddToLast1StretchToMax2=0, bool RectIfPossible=true)=0;
    //
    ////virtual void AddIneRow_Simply(T*rowParam)=0;
    //
    //virtual void AddColumn_OwnDataType(double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL)=0;
    void Matrix_Prototype::AddColumn_Gen                (double*rowParam, int wholeRowL, TDataShiftParams*DataShiftParam, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3, TValsShowHide*vsh){
        int QLines=this->GetQLines(), QColumns=this->GetQColumns();
        this->SetSize(QLines, QColumns+1);
        this->SetColumnN_Gen(QColumns+1, rowParam, wholeRowL, DataShiftParam);
    }
    //virtual void  AddColumn_Simply(double*rowParam)=0;
    //
    //template<typename T>void ArrayOf2DBy1D_InsIneRowN(T*&X, Array2DSize& size, int IneRowN, T DefaultVal, T*rowParam=NULL, int wholeRowL=0,                         TDataShiftParams*DataShiftParam=NULL, int ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_ValForShorterIsMissedForNsFitKeeping3_NextNewValToNextProperL4=1){
    //                      void               InsIneRowN(                         int IneRowN, T DefaultVal, T*rowParam=NULL, int wholeRowL=0,                         TDataShiftParams*DataShiftParam=NULL, int arr2D_ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_AnyExtRow3_NurFromStartTillErstStop4=0, int arr1D_ifNurProperL_NsSame1_EltsWithNsOfShoeterExtRowsNeUsed2=1);
    //                      void               InsIneRowN(                         int IneRowN,               T*rowParam=NULL, int wholeRowL=0, T*DefaultValParam=NULL, TDataShiftParams*DataShiftParam=NULL, int arr2D_ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_AnyExtRow3_NurFromStartTillErstStop4=0, int arr1D_ifNurProperL_NsSame1_EltsWithNsOfShoeterExtRowsNeUsed2=1);
    //
    //virtual void InsIneRow_Simply(int N, T*rowParam)=0;
    //
    //virtual void InsColumn_OwnDataType(int ColN, double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL)=0;
    void Matrix_Prototype::InsColumn_Gen                (int ColN, double*rowParam, int wholeRowL, TDataShiftParams*DataShiftParam, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3, TValsShowHide*vsh){
        int QLines=this->GetQLines(), QColumns=this->GetQColumns();
        this->SetSize(QLines, QColumns+1);
        if(ColN>=1 && ColN<=QColumns){
            for(int i=QColumns; i>=ColN+1; i--){
                this->SwapColumns(i-1, i);
            }
        }
        this->SetColumnN_Gen(ColN, rowParam, wholeRowL, DataShiftParam, true, IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3);
    }
    //virtual void InsColumn_Simply(int ColN, double*rowParam)=0;
    //
    //void DelIneRowN(int N=-1, int ifNGTLmin_Ignore0_DelLast1_NurProperL_AnyExtRow3_NurFromStartTillFirstBreak4=0);
    //virtual void DelIneRow_Simply(int N=-1)=0;
    //
    //virtual void DelColumnN_Simply(int N=-1)=0;
    void Matrix_Prototype::DelColumnN_Gen(int ColN){
        int QLines=this->GetQLines(), QColumns=this->GetQColumns();
        if(ColN>=1 && ColN<=QColumns){
            for(int i=ColN+1; i<=QColumns; i++){
                this->SwapColumns(i-1, i);
            }
            this->SetSize(QLines, QColumns-1);
        }
    }
    //
    // Set Content
    //
    //void Set(T**y, const Array2DSize& size,  bool WriteSize=true);
    //void Set(T**y, std::vector<int>ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(T**y, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(T**y, int QExtRows, int ExtRowsLength=1, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(T*y, const Array2DSize& size, bool WriteSize=true);
    //void Set(T*y, std::vector<int>ExtRowsLengthes, bool WriteSize=true);
    //void Set(T*y, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true,  bool WriteSize=true);
    //void Set(T*y, int QExtRows, int ExtRowsLength=1, bool RectIfPossible=true, bool sizeVaria=false, bool WriteSize=true);
    //void Set(std::vector<std::vector<T>>y, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(std::vector<T>y, const Array2DSize& size, bool WriteSize=true);
    //void Set(std::vector<T>y, std::vector<int>ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(std::vector<T>y, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(std::vector<T>y, int QExtRows, int ExtRowsLength=1, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(const T&val, const Array2DSize& size, bool WriteSize=true);
    //void Set(const T&val, std::vector<int>ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(const T&val, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(const T&val, int QExtRows, int ExtRowsLength=1, bool RectIfPossible=true, bool WriteSize=true);
    //
    void Matrix_Prototype::Set_arrOfLines(double**y, int QLines, int QColumns){
        double val;
        this->SetSize(QLines, QColumns);
        for(int i=1; i<=QLines; i++){
            for(int j=1; j<=QColumns; j++){
               val=y[i-1][j-1];
               this->SetComponent(val, i, j);
            }
        }
    }
    void Matrix_Prototype::Set_arrOfLines(double*y, int QLines, int QColumns){
        double val;
        Array2DSize size(QLines, QColumns);
        this->SetSize(QLines, QColumns);
        for(int i=1; i<=QLines; i++){
            for(int j=1; j<=QColumns; j++){
               val=ArrayOf2DBy1D_GetElement_AsVal(y, size, i, j);
               this->SetComponent(val, i, j);
            }
        }
    }
    void Matrix_Prototype::Set_arrOfLines(std::vector<double>y, int QLines, int QColumns){
        double val;
        Array2DSize size(QLines, QColumns);
        this->SetSize(QLines, QColumns);
        for(int i=1; i<=QLines; i++){
            for(int j=1; j<=QColumns; j++){
               val=ArrayOf2DBy1D_GetElement_AsVal(y, size, i, j);
               this->SetComponent(val, i, j);
            }
        }
    }
    void Matrix_Prototype::Set_arrOfLines(std::vector<std::vector<double>>y){
        Array2DSize size=GetSizeOf2DVector(y);
        int QLines=size.GetQExtRows(), QColumns=size.GetLength(1);
        double val;
        this->SetSize(QLines, QColumns);
        for(int i=1; i<=QLines; i++){
            for(int j=1; j<=QColumns; j++){
               val=y[i-1][j-1];
               this->SetComponent(val, i, j);
            }
        }
    }
    void Matrix_Prototype::Set_arrOfColumns(double**y, int QLines, int QColumns){
        int QExtRows=QColumns, QIneRows=QLines, LineN, ColN;
        double val;
        this->SetSize(QLines, QColumns);
        for(int ExtRowN=1; ExtRowN<=QExtRows; ExtRowN++){
            for(int IneRowN=1; IneRowN<=QIneRows; IneRowN++){
                val=y[ExtRowN-1][IneRowN-1];
                LineN=IneRowN;
                ColN=ExtRowN;
                this->SetComponent(val, LineN, ColN);
            }
        }
    }
    void Matrix_Prototype::Set_arrOfColumns(double*y, int QLines, int QColumns){
        Array2DSize size;
        int QExtRows=QColumns, QIneRows=QLines, LineN, ColN;
        size.Set(QExtRows, QIneRows);
        double val;
        this->SetSize(QLines, QColumns);
        for(int ExtRowN=1; ExtRowN<=QExtRows; ExtRowN++){
            for(int IneRowN=1; IneRowN<=QIneRows; IneRowN++){
                val=ArrayOf2DBy1D_GetElement_AsVal(y, size, ExtRowN, IneRowN);
                LineN=IneRowN;
                ColN=ExtRowN;
                this->SetComponent(val, LineN, ColN);
            }
        }
    }
    void Matrix_Prototype::Set_arrOfColumns(std::vector<double>y, int QLines, int QColumns){
        Array2DSize size;
        int QExtRows=QColumns, QIneRows=QLines, LineN, ColN;
        size.Set(QExtRows, QIneRows);
        double val;
        this->SetSize(QLines, QColumns);
        for(int ExtRowN=1; ExtRowN<=QExtRows; ExtRowN++){
            for(int IneRowN=1; IneRowN<=QIneRows; IneRowN++){
                val=ArrayOf2DBy1D_GetElement_AsVal(y, size, ExtRowN, IneRowN);
                LineN=IneRowN;
                ColN=ExtRowN;
                this->SetComponent(val, LineN, ColN);
            }
        }
    }
    void Matrix_Prototype::Set_arrOfColumns(std::vector<std::vector<double>>y){
        Array2DSize size=GetSizeOf2DVector(y);
        int QColumns=size.GetQExtRows(), QLines=size.GetLength(1), QExtRows=QColumns, QIneRows=QLines, LineN, ColN;
        double val;
        this->SetSize(QLines, QColumns);
        for(int ExtRowN=1; ExtRowN<=QExtRows; ExtRowN++){
            for(int IneRowN=1; IneRowN<=QIneRows; IneRowN++){
                val=y[ExtRowN-1][IneRowN-1];
                LineN=IneRowN;
                ColN=ExtRowN;
                this->SetComponent(val, LineN, ColN);
            }
        }
    }
    //
    void Matrix_Prototype::SwapVals(int LineN1, int ColN1, int LineN2, int ColN2){
        double buf, x1=this->GetComponent(LineN1, ColN1), x2=this->GetComponent(LineN2, ColN2);
        buf=x1;//this->GetComponent_AsVal(LineN1, ColN1);
        x1=x2;
        x2=buf;
        this->SetComponent(x1, LineN1, ColN1);
        this->SetComponent(x2, LineN2, ColN2);
    }
    //
    //void SwapExtRows(int N1, int N2);
    //void SwapIneRows(int N1, int N2);
    void Matrix_Prototype::SwapLines(int N1, int N2){
        int QLines=this->GetQLines(), QColumns=this->GetQColumns();
        std::vector<double>row1, row2;
        if(N1>=1 && N1<=QLines && N1>=1 && N2<=QLines){
            row1=this->GetLineN_AsArray(N1);
            row2=this->GetLineN_AsArray(N2);
            this->SetLineN_Gen(N1, row2.data(), row2.size());
            this->SetLineN_Gen(N2, row2.data(), row2.size());
        }
    }
    void Matrix_Prototype::SwapColumns(int N1, int N2){
        int QLines=this->GetQLines(), QColumns=this->GetQColumns();
        std::vector<double>row1, row2;
        if(N1>=1 && N1<=QColumns && N1>=1 && N2<=QColumns){
            row1=this->GetColumnN_AsArray(N1);
            row2=this->GetColumnN_AsArray(N2);
            this->SetColumnN_Gen(N1, row2.data(), row2.size());
            this->SetColumnN_Gen(N2, row2.data(), row2.size());
        }
    }
    //
    void Matrix_Prototype::ReverseLineN(int rowN){
        int QLines=this->GetQLines(), QColumns=this->GetQColumns(), N1, N2, Nmid;
        //std::vector<double>row1, row2;
        double x1, x2;
        if(QColumns%2==0){
            Nmid=QColumns/2;
        }else{
            Nmid=(QColumns-1)/2;
        }
        for(N1=1; N1<=Nmid; N1++){
            N2=QColumns+1-N1;
            this->SwapVals(rowN, N1, rowN, N2);
        }
    }
    void Matrix_Prototype::ReverseColumnN(int rowN){
        int QLines=this->GetQLines(), QColumns=this->GetQColumns(), N1, N2, Nmid;
        //std::vector<double>row1, row2;
        double x1, x2;
        if(QLines%2==0){
            Nmid=QLines/2;
        }else{
            Nmid=(QLines-1)/2;
        }
        for(N1=1; N1<=Nmid; N1++){
            N2=QLines+1-N1;
            this->SwapVals(N1, rowN, N2, rowN);
        }
    }
    void Matrix_Prototype::ReverseLinesSuccession(){
        int QLines=this->GetQLines(), QColumns=this->GetQColumns(), N1, N2, Nmid;
        std::vector<double>row1, row2;
        if(QLines%2==0){
            Nmid=QLines/2;
        }else{
            Nmid=(QLines-1)/2;
        }
        for(N1=1; N1<=Nmid; N1++){
            N2=QLines+1-N1;
            this->SwapLines(N1, N2);
        }
    }
    void Matrix_Prototype::ReverseColumnsSuccession(){
        int QLines=this->GetQLines(), QColumns=this->GetQColumns(), N1, N2, Nmid;
        std::vector<double>row1, row2;
        if(QColumns%2==0){
            Nmid=QColumns/2;
        }else{
            Nmid=(QColumns-1)/2;
        }
        for(N1=1; N1<=Nmid; N1++){
            N2=QColumns+1-N1;
            this->SwapColumns(N1, N2);
        }
    }
    //
    //bool ValIsAtPos(const T&val, int ExtRowN, int IneRowN) const;
    bool Matrix_Prototype::ValIsAtPos(double val, int LineN, int ColumnN) const{
        bool b;
        int QLines=this->GetQLines(), QColumns=this->GetQColumns();
        double x=this->GetComponent(LineN, ColumnN);
        if(LineN>=1 && LineN<=QLines && ColumnN>=1 && ColumnN<=QColumns){
            x=this->GetComponent(LineN, ColumnN);
            b=(x==val);
        }else{
            b=false;
        }
        return b;
    }
    //swa S di n'fit prototype - obe s': alt IneRowN wa ExtRowN, so ExtRowN 2x, ce alt err
    //std::vector<std::vector<int>> SeekVal(const T&val) const;
    //std::vector<Int2DVectorOfSizeOrCoords> SeekVal(const T&val) const;
    //TListOfNumberPairs SeekVal(const T&val) const;
    TListOfNumberPairs Matrix_Prototype::SeekVal(double val) const{
        TListOfNumberPairs R;
        double x;
        int QLines=this->GetQLines(), QColumns=this->GetQColumns();
        for(int i=1; i<=QLines; i++){
            for(int j=1; j<=QColumns; j++){
                x=this->GetComponent(i, j);
                if(x==val){
                    R.Add(i, j);
                }
            }
        }
        return R;
    }
    //so class name. Ma to vrns co std::vector ety di n'fit prototype
    //bool ExtRowIsAtPos(T*row, int Q, int ExtRowN, int IneRowN) const;
    bool Matrix_Prototype::LineIsAtPos(double*row, int Q, int LineN, int ColN) const{
        bool b=true;
        double whereVal, whatVal;
        int QLines=this->GetQLines(), QColumns=this->GetQColumns(), whereN, whatN;
        if(LineN>=1 && LineN<=QLines && ColN>=1 && ColN<=QColumns && ColN+Q-1<=QColumns){
            for(whatN=1; whatN<=Q; whatN++){
                whereN=ColN+whatN-1;
                whereVal=this->GetComponent(LineN, whereN);
                whatVal=row[whatN-1];
                if(whereVal!=whatVal){
                    b=false;
                }
            }
        }else{
            b=false;
        }
        return b;
    }
    //std::vector<std::vector<int>> SeekExtRow(T*row, int L) const;
    //std::vector<Int2DVectorOfSizeOrCoords> SeekExtRow(T*row, int L) const;
    //TListOfNumberPairs SeekExtRow(T*row, int L) const;
    TListOfNumberPairs Matrix_Prototype::SeekLine(double*row, int L) const{
        int QLines=this->GetQLines(), QColumns=this->GetQColumns();
        TListOfNumberPairs R;
        bool b;
        for(int i=1; i<=QLines; i++){
            for(int j=1; j<=QColumns; j++){
                b=this->LineIsAtPos(row, L, i, j);
                if(b){
                    R.Add(i, j);
                }
            }
        }
        return R;
    }
    //bool IneRowIsAtPos(T*row, int Q, int ExtRowN, int IneRowN) const;
    bool Matrix_Prototype::ColumnIsAtPos(double*row, int L, int LineN, int ColN) const{
        bool b=true;
        double whereVal, whatVal;
        int QLines=this->GetQLines(), QColumns=this->GetQColumns(), whereN, whatN;
        if(LineN>=1 && LineN<=QLines && ColN>=1 && ColN<=QColumns && LineN+L-1<=QLines){
            for(whatN=1; whatN<=L; whatN++){
                whereN=ColN+whatN-1;
                whereVal=this->GetComponent(whereN, ColN);
                whatVal=row[whatN-1];
                if(whereVal!=whatVal){
                    b=false;
                }
            }
        }else{
            b=false;
        }
        return b;
    }
    //std::vector<std::vector<int>> SeekIneRow(T*row, int Q) const;
    //std::vector<Int2DVectorOfSizeOrCoords> SeekIneRow(T*row, int Q) const;
    //TListOfNumberPairMatrix_Prototype::s SeekIneRow(T*row, int Q) const;
    TListOfNumberPairs Matrix_Prototype::SeekColumn(double*row, int Q) const{
        int QLines=this->GetQLines(), QColumns=this->GetQColumns();
        TListOfNumberPairs R;
        bool b;
        for(int i=1; i<=QLines; i++){
            for(int j=1; j<=QColumns; j++){
                b=this->ColumnIsAtPos(row, Q, i, j);
                if(b){
                    R.Add(i, j);
                }
            }
        }
        return R;
    }
    //bool Arr2DIsAtPos(std::vector<std::vector<T>>arr, int ExtRowN, int IneRowN, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    bool Matrix_Prototype::Arr2DIsAtPos(std::vector<std::vector<double>>arr, int LineN, int ColN, bool ArrOfLinesNotColumns, bool isNotTransposed, bool ExtRowsSuccIsNotReversed, bool EachExtRowIsNotReversed) const{
        bool b;
        Array2D_shell<double> Where;
        std::vector<double>data=this->GetContent_AsArray1DOfLines();
        Array2DSize size(this->GetQLines(), this->GetQColumns());
        if(ArrOfLinesNotColumns){
            data=this->GetContent_AsArray1DOfLines();
        }else{
            data=this->GetContent_AsArray1DOfColumns();
        }
        Where.Set(data, size);
        b=Where.Arr2DIsAtPos(arr, LineN, ColN, isNotTransposed, ExtRowsSuccIsNotReversed, EachExtRowIsNotReversed);
        return b;
    }
    bool Matrix_Prototype::Arr2DIsAtPos(Matrix_Prototype*obj, int LineN, int ColN, bool ArrOfLinesNotColumns, bool isNotTransposed, bool ExtRowsSuccIsNotReversed, bool EachExtRowIsNotReversed) const{
        bool b;
        Array2D_shell<double> Where;
        std::vector<double>data=this->GetContent_AsArray1DOfLines();
        Array2DSize size(this->GetQLines(), this->GetQColumns());
        if(ArrOfLinesNotColumns){
            data=this->GetContent_AsArray1DOfLines();
        }else{
            data=this->GetContent_AsArray1DOfColumns();
        }
        Where.Set(data, size);
        //
        //bool Arr2DIsAtPos(std::vector<T>arr, const Array2DSize& size, int ExtRowN, int IneRowN, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
        b=Where.Arr2DIsAtPos(obj->GetContent_AsArray1DOfLines(),  size,       LineN,       ColN,       isNotTransposed,           ExtRowsSuccIsNotReversed,           EachExtRowIsNotReversed);
        return b;
    }

    //std::vector<std::vector<int>> SeekArr2D(std::vector<std::vector<T>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //std::vector<Int2DVectorOfSizeOrCoords> SeekArr2D(std::vector<std::vector<T>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //TListOfNumberPairs SeekArr2D(std::vector<std::vector<T>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    TListOfNumberPairs Matrix_Prototype::SeekArr2D(std::vector<std::vector<double>>arr, bool ArrOfLinesNotColumns, bool isNotTransposed, bool ExtRowsSuccIsNotReversed, bool EachExtRowIsNotReversed) const{
        TListOfNumberPairs R;
        bool b;
        int QLines=this->GetQLines(), QColumns=this->GetQColumns();
        for(int LineN=1; LineN<=QLines; LineN++){
            for(int ColN=1; ColN<=QColumns; ColN++){
                b=Arr2DIsAtPos(arr, LineN, ColN, ArrOfLinesNotColumns, isNotTransposed, ExtRowsSuccIsNotReversed, EachExtRowIsNotReversed);
                if(b){
                    R.Add(LineN, ColN)   ;
                }
            }
        }
        return R;
    }
    //std::vector<std::vector<int>> SeekArr2D(Array2D_Prototype*arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //std::vector<Int2DVectorOfSizeOrCoords> SeekArr2D(Array2D_Prototype*arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    TListOfNumberPairs Matrix_Prototype::SeekArr2D(Matrix_Prototype*obj, bool ArrOfLinesNotColumns, bool isNotTransposed, bool ExtRowsSuccIsNotReversed, bool EachExtRowIsNotReversed) const{
        TListOfNumberPairs R;
        bool b;
        int QLines=this->GetQLines(), QColumns=this->GetQColumns();
        for(int LineN=1; LineN<=QLines; LineN++){
            for(int ColN=1; ColN<=QColumns; ColN++){
                b=Arr2DIsAtPos(obj, LineN, ColN, ArrOfLinesNotColumns, isNotTransposed, ExtRowsSuccIsNotReversed, EachExtRowIsNotReversed);
                if(b){
                    R.Add(LineN, ColN);
                }
            }
        }
        return R;
    }

    //
    //virtual void ConcatAdding(Matrix_Prototype*obj, T DefaultVal,int QShiftedCols=0,  TDataShiftParams*DataShiftParam=NULL, bool SetRect=true, int DfltRowL_00_11_Lmin2_Lmax3=1);
    //virtual void ConcatAdding(Matrix_Prototype*obj, int QShiftedCols=0, TDataShiftParams*DataShiftParam=NULL, T*DefaultValParam=NULL, bool SetRect=true, int DfltRowL_00_11_Lmin2_Lmax3=1);
    //
    void Matrix_Prototype::ConcatAdding(Matrix_Prototype*obj, Matrix_Prototype*&R, int QShiftedCols,  TDataShiftParams*DataShiftParam){
        std::vector<double> data1 = this->GetContent_AsArray1DOfLines(), data2=obj->GetContent_AsArray1DOfLines(), dataR;
        Array2DSize size1(this->GetQLines(), this->GetQColumns()), size2(obj->GetQLines(), obj->GetQColumns()), size3;
        //std::vector<int>Ns1, Ns2;
        std::vector<Int2DVectorOfSizeOrCoords>Ns1, Ns2;
        //void Array2DSize_ConcatAdding(const Array2DSize& size1, const Array2DSize& size2, Array2DSize& size3, std::vector<Int2DVectorOfSizeOrCoords>&Ns1OfData1, std::vector<Int2DVectorOfSizeOrCoords>&Ns1OfData2, int shiftQ=0, TDataShiftParams*dataShiftParam=NULL,/*int QReq=0, int FromN=1, int QDfltBefore=0,*/ bool SetRect=true);
               Array2DSize_ConcatAdding(                   size1,                    size2,              size3,                                               Ns1,                                               Ns2, QShiftedCols,                  DataShiftParam,                                                                  true);
        //template <typename T> ArrayOf2DBy1D_ConcatAdding(T*X1, const Array2DSize& size1, T*X2, const Array2DSize& size2, T*&X3, Array2DSize& size3, T DefaultVal, int shiftQ=0, TDataShiftParams*DataShiftParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3, bool SetRect=true){
                                ArrayOf2DBy1D_ConcatAdding(data1,                   size1, data2,                   size2, dataR,              size3, 0.0,          QShiftedCols,                  DataShiftParam,                                     3,              true);
        R->Set_arrOfLines(dataR,size3.GetQExtRows(), size3.GetLength(1));
    }
    //_ConcatStretching(T*X1, const Array2DSize& size1, T*X2, const Array2DSize& size2, T*&X3, Array2DSize& size3, T DefaultVal, int shiftQ=0, TDataShiftParams*DataShiftParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3, bool Stretch1ToMax=true, bool SetRect=true){
    //virtual void ConcatStretching(Matrix_Prototype*obj, T DefaultVal, int QShiftedExtRowNs=0,  TDataShiftParams*DataShiftParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3, bool Stretch1ToMax=true, bool SetRect=true);
    //virtual void ConcatStretching(Matrix_Prototype*obj, int QShiftedExtRowNs=0, TDataShiftParams*DataShiftParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3, bool Stretch1ToMax=true, bool SetRect=true, T*DefaultValParam=NULL);
    void  Matrix_Prototype::ConcatStretching(Matrix_Prototype*obj, Matrix_Prototype*&R, int QShiftedCols,  TDataShiftParams*DataShiftParam){
        std::vector<double> data1 = this->GetContent_AsArray1DOfLines(), data2=obj->GetContent_AsArray1DOfLines(), dataR;
        Array2DSize size1(this->GetQLines(), this->GetQColumns()), size2(obj->GetQLines(), obj->GetQColumns()), size3;
        //std::vector<int>Ns1, Ns2;
        std::vector<Int2DVectorOfSizeOrCoords>Ns1, Ns2;
        //void Array2DSize_ConcatAdding(const Array2DSize& size1, const Array2DSize& size2, Array2DSize& size3, std::vector<Int2DVectorOfSizeOrCoords>&Ns1OfData1, std::vector<Int2DVectorOfSizeOrCoords>&Ns1OfData2, int shiftQ=0, TDataShiftParams*dataShiftParam=NULL,/*int QReq=0, int FromN=1, int QDfltBefore=0,*/ bool SetRect=true);
        Array2DSize_ConcatAdding                           (size1,                   size2,              size3,Ns1, Ns2, QShiftedCols,DataShiftParam, true);
        //template <typename T> ArrayOf2DBy1D_ConcatAdding(T*X1, const Array2DSize& size1, T*X2, const Array2DSize& size2, T*&X3, Array2DSize& size3, T DefaultVal, int shiftQ=0, TDataShiftParams*DataShiftParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3, bool SetRect=true){
        ArrayOf2DBy1D_ConcatAdding(                       data1,                    size1, data2,                   size2, dataR,              size3,         0.0,  QShiftedCols,                  DataShiftParam,                                     3,              true);
        R->Set_arrOfLines(dataR,size3.GetQExtRows(), size3.GetLength(1));
    }
    //
    //virtual Matrix_Prototype*GetSubMatrix(int ExtRowN, int IneRowN, const Array2DSize& size, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const=0;
    //virtual Matrix_Prototype*GetSubMatrix(TDataShiftParams*DataShiftParam=NULL) const=0;
    //
    //void ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(T val, int ExtRowN, int IneRowN, T DefaultVal, bool SetRect=true, int DfltRowL_00_11_Max2_Min3=2);
    //void ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(T val, int ExtRowN, int IneRowN, bool SetRect=true, int DfltRowL_00_11_Max2_Min3=2, T*DefaultValParam=NULL);
    //void ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(double val, int ExtRowN, int IneRowN);
    void Matrix_Prototype::ValSetOrAddOrFillOrIgnore(double val, int LineN, int ColN){
        std::vector<double>data=this->GetContent_AsArray1DOfLines();
        Array2DSize size(this->GetQLines(),this->GetQColumns());
        //template <typename T> ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(std::vector<T>&X, Array2DSize& size, T val, int ExtRowN, int IneRowN, T DefaultVal, bool SetRect=true, int DfltRowL_00_11_Max2_Min3=2){
                                ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(            data,              size,   val,       LineN,         ColN,         0.0,              true,                              2);
    }
    //
    void Matrix_Prototype::StdCout_LineN(int LineN, QString ElemsDelim, bool UseBrackets)const{
        std::vector<double>data=this->GetContent_AsArray1DOfLines();
        Array2DSize size(this->GetQLines(),this->GetQColumns());
        //ArrayOf2DBy1D_StdCOutSingleExtRow(T*X, const Array2DSize&size, int ExtRowN, QString delimElem="; ", bool useBrackets=true)
         ArrayOf2DBy1D_StdCOutSingleExtRow(data.data(),            size,       LineN,         ElemsDelim,          UseBrackets);
    }
    void Matrix_Prototype::StdCout_ColN(int ColN, QString ElemsDelim, bool UseBrackets, bool Represent2DNot1D)const{
        std::vector<double>data=this->GetContent_AsArray1DOfLines();
        Array2DSize size(this->GetQLines(),this->GetQColumns());
        ArrayOf2DBy1D_StdCOutSingleIneRow(data.data(), size, ColN, ElemsDelim, UseBrackets);
    }
    void Matrix_Prototype::StdCout(QString ElemsDelim, QString RowsDelim, bool UseBrackets, bool Represent2DNot1D, bool ByExtRowsNotIneRows)const{
        std::vector<double>data=this->GetContent_AsArray1DOfLines();
        Array2DSize size(this->GetQLines(),this->GetQColumns());
        ArrayOf2DBy1D_StdCOut(data.data(), size, ElemsDelim, RowsDelim, UseBrackets, Represent2DNot1D, true);
    }
//};//Matrix_Prototype

//class Matrix_TmpltArr2DShell_ArrOfLines : public Matrix_Prototype{
//    Array2D_Shell<double> data;
//public:
    Matrix_TmpltArr2DShell_ArrOfLines::Matrix_TmpltArr2DShell_ArrOfLines(int QLines, int QColumns){
        this->data.Set(0.0, QLines, QColumns);
    }
    Matrix_TmpltArr2DShell_ArrOfLines::Matrix_TmpltArr2DShell_ArrOfLines(double val, int QLines, int QColumns){
        this->data.Set(val, QLines, QColumns);
    }
    Matrix_TmpltArr2DShell_ArrOfLines::Matrix_TmpltArr2DShell_ArrOfLines(double*arrOfLines, int QLines, int QColumns){
        this->data.Set(arrOfLines, QLines, QColumns);
    }
    Matrix_TmpltArr2DShell_ArrOfLines::Matrix_TmpltArr2DShell_ArrOfLines(double**arrOfLines, int QLines, int QColumns){
        this->data.Set(arrOfLines, QLines, QColumns);
    }
    Matrix_TmpltArr2DShell_ArrOfLines::Matrix_TmpltArr2DShell_ArrOfLines(std::vector<double>arrOfLines, int QLines, int QColumns){
        this->data.Set(arrOfLines, QLines, QColumns);
    }
    Matrix_TmpltArr2DShell_ArrOfLines::Matrix_TmpltArr2DShell_ArrOfLines(std::vector<std::vector<double>>arrOfLines){
        this->data.Set(arrOfLines);
    }
    //
    Matrix_TmpltArr2DShell_ArrOfLines::Matrix_TmpltArr2DShell_ArrOfLines(const Matrix_TmpltArr2DShell_ArrOfLines& obj){
        this->data=obj.data;
    }
    //
    Matrix_TmpltArr2DShell_ArrOfLines::~Matrix_TmpltArr2DShell_ArrOfLines(){
        this->SetNull();
    }
    //
    //
    //virtual void SetNull()=0;
    void Matrix_TmpltArr2DShell_ArrOfLines::SetNull(){
        this->data.SetNull();
    }
    //virtual void construct()=0;
    void Matrix_TmpltArr2DShell_ArrOfLines::construct(){
        //NOp ob in this ery case ut's no need to do  something here
    }
    //virtual Matrix_Prototype* CreateMatrix() const=0;
    Matrix_TmpltArr2DShell_ArrOfLines* Matrix_TmpltArr2DShell_ArrOfLines::CreateMatrix() const{
        return new Matrix_TmpltArr2DShell_ArrOfLines(1, 1);
    }
    //virtual Matrix_Prototype* clone()const=0;
    Matrix_TmpltArr2DShell_ArrOfLines* Matrix_TmpltArr2DShell_ArrOfLines::clone()const{
        return this;
    }
    //virtual Matrix_Prototype* GetData()const=0;
    //virtual Matrix_TmpltArr2DShell_ArrOfLines* GetData()const;
    //virtual int GetTypeN() const=0 ;
    int Matrix_TmpltArr2DShell_ArrOfLines::GetTypeN() const{
        return Matrix_TmpltArr2DShell_ArrOfLines_TypeN;
    }
    //
    //void SetOne(T*DfltVal=NULL);
    //void SetOne(const T&DfltVal);
    void Matrix_TmpltArr2DShell_ArrOfLines::SetOne(){
        this->data.SetOne(0.0);
    }
    //
    ////virtual void SetSize(const T& DfltValParam, const Array2DSize&size)=0;
    //
    ////void SetSize(const Array2DSize&size, T*DfltValParam=NULL);//virtual ob hin Sdo mut l'size data
    ////void SetSize(int QExtRows=1, int ExtRowsLength=1, T*DfltValParam=NULL);
    ////void SetSize(int QExtRows=1, int*ExtRowsLengthes=NULL, T*DfltValParam=NULL);//if Null => L=0
    ////void SetSize(std::vector<int>ExtRowsLengthes, T*DfltValParam=NULL);
    //
    ////void SetSize(const T& DfltValParam, int QExtRows=1, int ExtRowsLength=1);//virtual ob hin Sdo mut l'size data
    ////void SetSize(const T& DfltValParam, int QExtRows=1, int*ExtRowsLengthes=NULL);//if Null => L=0
    ////void SetSize(const T& DfltValParam, std::vector<int>Lengthes);
    //
    //virtual void SetSize(int QExtRows=1, int ExtRowsLength=1)=0;
    void Matrix_TmpltArr2DShell_ArrOfLines::SetSize(int QLines, int QColumns){
        int QExtRows=QLines,  ExtRowsLength=QColumns;
        this->data.SetSize(0.0, QExtRows, ExtRowsLength);
    }
    //
    ////virtual int GetQExtRows() const=0;
    ////virtual int GetLength(int ExtRowN=1) const=0;
    ////virtual int GetMinLength() const=0;
    ////virtual int GetMaxLength() const=0;
    //virtual int GetQLines()=0;
    int Matrix_TmpltArr2DShell_ArrOfLines::GetQLines()const{
        int QL=this->data.GetQExtRows();
        return QL;
    }

    //virtual int GetQColumns()=0;
    int Matrix_TmpltArr2DShell_ArrOfLines::GetQColumns()const{
        int QC=this->data.GetLength(1);
        return QC;
    }
    //virtual Array2DSize GetSize()const =0;
    //
    ////bool LineNBelongsHere(int LineN) const;
    ////bool ColNBelongsHere(int ColN) const;
    //bool NsBelongHere(int ExtRowN, int IneRowN) const;
    //
    ////std::vector<T> GetArrayOfExtRowN(int LineN);
    ////std::vector<T> GetArrayOfIneRowN(int ColN);
    ////std::vector<T> GetContentAsArray1D();
    ////std::vector<std::vector<T>> GetContentAsArray2D();
    //
    ////std::vector<T> GetExtRowN_AsArray(int rowN) const;
    //std::vector<double> GetLineN_AsArray(int rowN) const;
    //// T*GetExtRowN_AsPtr(int ExtRowN) const;
    ////std::vector<T> GetIneRowN_AsArray(int rowN) const;
    //std::vector<double> GetColumnN_AsArray(int rowN) const;
    ////std::vector<T> GetIneRowN_AsArray(int IneRowN, const T& defaultVal,                         int ifNGTLmin_Ignore0_DefaultsForShorter1_NurProperL_AnyExtRow2_NurFromStartTillErstStop3=0) const;
    ////std::vector<T> GetIneRowN_AsArray(int IneRowN,                      T*DefaultValParam=NULL, int ifNGTLmin_Ignore0_DefaultsForShorter1_NurProperL_AnyExtRow2_NurFromStartTillErstStop3=0) const;
    ////std::vector<T> GetContent_AsArray1D() const;
    ////std::vector<std::vector<T>> GetContent_AsArray2D() const;
    //std::vector<double> GetContent_AsArray1DOfLines() const;
    //std::vector<double> GetContent_AsArray1DOfColumns() const;
    //std::vector<std::vector<double>> GetContent_AsArray2DOfLines() const;
    //std::vector<std::vector<double>> GetContent_AsArray2DOfColumns() const;
    //
    //
    ////virtual T GetComponent_AsVal(int LineN, int ColN) const=0;
    ////virtual T* GetComponent_AsPtr(int LineN, int ColN) const=0;
    //virtual double GetComponent_AsVal(int LineN, int ColN) const=0;
    double Matrix_TmpltArr2DShell_ArrOfLines::GetComponent(int LineN, int ColN) const{
       int ExtRowN=LineN, IneRowN=ColN;
       double y=this->data.GetComponent_AsVal(ExtRowN, IneRowN);
        return y;
    }
    //virtual double* GetComponent_AsPtr(int LineN, int ColN) const=0;
    //double* Matrix_TmpltArr2DShell_ArrOfLines::GetComponent_AsPtr(int LineN, int ColN) const{
    // //   int ExtRowN=LineN, IneRowN=ColN;
    //    double*y=this->data.GetComponent_AsPtr(ExtRowN, IneRowN);
    //    return y;
    //}
    //
    ////virtual void SetComponent(const T& val, int LineN, int ColN)=0;
    //virtual void SetComponent(double val, int LineN, int ColN)=0;
    void Matrix_TmpltArr2DShell_ArrOfLines::SetComponent(double val, int LineN, int ColN){
        int ExtRowN=LineN, IneRowN=ColN;
        this->data.SetComponent(val, ExtRowN, IneRowN);
    }
    //
    ////void AddToExtRowN(int RowN, const T&val);
    ////void InsToExtRowN(int RowN, int PosN, const T&val);
    ////void DelFromExtRowN(int RowN, int PosN);
    //
    ////virtual void AddToExtRowN_Simply(int ExtRowN, const T&val)=0;
    ////virtual void InsToExtRowN_Simply(int ExtRowN, int PosN, const T&val)=0;
    ////virtual void DelFromExtRowN_Simply(int RowN, int IneRowPosN)=0;
    //
    // Ext row
    //
    ////template<typename T> void ArrayOf2DBy1D_SetExtRowN(T*&X, Array2DSize&size, int ExtRowN,       T DefaultVal, T*rowParam, int wholeRowL=0,                      TDataShiftParams*DataShiftParam=NULL, /*bool KeepIfRect=true,*/ bool DefaultIsSpecNotOwn=true,      int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2){
    ////virtual              void               SetExtRowN(                              int N, const T& defaultVal,  T*rowParam,      int rowL,    TDataShiftParams*DataShiftParams=NULL,                          bool DefaulsAreSpecNotOwnVals=true, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2)=0;
    ////void SetExtRowN(int N, const T& defaultVal, T*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true,                      int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2);
    ////void SetExtRowN(int N,                      T*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, T*DfltValParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2);
    //
    ////void SetExtRow_Simply(int N, T*rowParam)=0;
    ////void SetExtRow_Simply(int N, T*rowParam, int L)=0;
    //
    //virtual void SetLineN_OwnDataType(int N,      double*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1)=0;
    void Matrix_TmpltArr2DShell_ArrOfLines::SetLineN_OwnDataType(int N,      double*rowParam, int rowL, TDataShiftParams*DataShiftParams, bool DefaulsAreSpecNotOwnVals, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3){
        int SizeRect_DoNotCare0_No1_IfPossible2_Anyway_Max3_Lnax4_Old5_New6;
        switch(IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3){
            case 1:
                SizeRect_DoNotCare0_No1_IfPossible2_Anyway_Max3_Lnax4_Old5_New6=5;
            break;
            case 2:
                SizeRect_DoNotCare0_No1_IfPossible2_Anyway_Max3_Lnax4_Old5_New6=6;//or 4, into cas ne vikts
            break;
            case 3:
                SizeRect_DoNotCare0_No1_IfPossible2_Anyway_Max3_Lnax4_Old5_New6=3;
            break;
        }
        this->data.SetExtRowN(N, 0.0, rowParam, rowL,DataShiftParams, DefaulsAreSpecNotOwnVals,SizeRect_DoNotCare0_No1_IfPossible2_Anyway_Max3_Lnax4_Old5_New6);
    }
    //void SetLineN_Gen(int N,                      double*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1);
    //virtual void SetLineN_Simply(int N, double*rowParam)=0;
    void Matrix_TmpltArr2DShell_ArrOfLines::SetLineN_Simply(int N, double*rowParam){
        this->data.SetExtRow_Simply(N, rowParam);
    }
    //
    ////template<typename T>void ArrayOf2DBy1D_AddExtRow(T*&X, Array2DSize&size, T DefaultVal, T*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL){
    ////                      void               AddExtRow(                        T DefaultVal, T*rowParam, int wholeRowL=0,                         TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL);
    ////template<typename T>void ArrayOf2DBy1D_AddExtRow(T*&X, Array2DSize&size, T*rowParam, int wholeRowL=0, T*DefaultValParam=NULL, TDataShiftParams*DataShiftParam=NULL,  int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL){
    //                      void               AddExtRow(                                      T*rowParam, int wholeRowL=0, T*DefaultValParam=NULL, TDataShiftParams*DataShiftParam=NULL,  int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL);
    //
    ////virtual void AddExtRow_Simply(T*rowParam)=0;
    ////virtual void AddExtRow_Simply(T*rowParam, int L)=0;
    //
    //virtual void AddLine_OwnDataType(double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL)=0;
    void Matrix_TmpltArr2DShell_ArrOfLines::AddLine_OwnDataType(double*rowParam, int wholeRowL, TDataShiftParams*DataShiftParam, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3, TValsShowHide*vsh){
        int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6;
        switch(IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3){
            case 1:
                SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=4;
            break;
            case 2:
                SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=6;
            break;
            case 3:
                SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=3;
            break;
        }
        this->data.AddExtRow(0.0, rowParam, wholeRowL, DataShiftParam, SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6);
    }
    //void AddLine_Gen(double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    //virtual void AddLine_Simply(double*rowParam)=0;
    void Matrix_TmpltArr2DShell_ArrOfLines::AddLine_Simply(double*rowParam){
        this->data.AddExtRow_Simply(rowParam);
    }

    ////template<typename T>void ArrayOf2DBy1D_InsExtRow(T*&X, Array2DSize&size, int ExtRowN, T DefaultVal, T*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL){
    ////                      void               InsExtRow(                        int ExtRowN, T DefaultVal, T*rowParam, int wholeRowL=0,                      TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL);
    ////template<typename T>void ArrayOf2DBy1D_InsExtRow(T*&X, Array2DSize&size, int ExtRowN, T*rowParam, int wholeRowL=0,  T*DfltValParam=NULL, TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL){
    ////                      void               InsExtRow(                        int ExtRowN,               T*rowParam, int wholeRowL=0, T*DfltValParam=NULL, TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL);
    //
    ////virtual void InsExtRow_Simply(int N, T*rowParam)=0;
    ////virtual void InsExtRow_Simply(int N, T*rowParam, int L)=0;
    //
    //virtual void InsLine_OwnDataType(double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL)=0;
    void Matrix_TmpltArr2DShell_ArrOfLines::InsLine_OwnDataType(int LineN, double*rowParam, int wholeRowL, TDataShiftParams*DataShiftParam, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3, TValsShowHide*vsh){
        int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6;
        switch(IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3){
            case 1:
                SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=4;
            break;
            case 2:
                SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=6;
            break;
            case 3:
                SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=3;
            break;
        }
        this->data.InsExtRow(LineN, 0.0, rowParam, wholeRowL, DataShiftParam, IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3);
    }
    //void InsLine_Gen(double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    //virtual void InsLine_Simply(double*rowParam)=0;
    void Matrix_TmpltArr2DShell_ArrOfLines::InsLine_Simply(int LineN, double*rowParam){
        this->data.InsExtRow_Simply(LineN, rowParam);
    }
    //
    ////void DelExtRowN(int N=-1);
    ////virtual void DelExtRowN_Simply(int N=-1)=0;
    //
    //virtual void DelLineN(int N=-1)=0;
    void Matrix_TmpltArr2DShell_ArrOfLines::DelLineN(int N){
        this->data.DelExtRowN_Simply(N);
    }
    //
    //Ine row
    //
    //void SetIneRowN( int IneRowN, const T& defaultVal, T*rowParam=NULL, int rowL=0, TDataShiftParams*DataShiftParam=NULL,                         bool DefaulsAreSpecNotOwnVals=true, int arr2D_ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_AnyExtRow3_NurFromStartTillErstStop4=0, int arr1D_ifNurProperL_NsSame1_EltsWithNsOfShoeterExtRowsNeUsed2=1);
    //void SetIneRowN( int IneRowN,                      T*rowParam=NULL, int rowL=0, TDataShiftParams*DataShiftParam=NULL, T*DefaultValParam=NULL, bool DefaulsAreSpecNotOwnVals=true, int arr2D_ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_AnyExtRow3_NurFromStartTillErstStop4=0, int arr1D_ifNurProperL_NsSame1_EltsWithNsOfShoeterExtRowsNeUsed2=1);
    //
    //virtual void SetIneRowSimply(int IneRowN, T*rowParam)=0;
    //
    //virtual void SetColumnN_OwnDataType(int N,          double*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1)=0;
    void Matrix_TmpltArr2DShell_ArrOfLines::SetColumnN_OwnDataType(int N,          double*rowParam, int rowL, TDataShiftParams*DataShiftParams, bool DefaulsAreSpecNotOwnVals, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3){

    }
    //void SetColumnN_Gen                (int N,          double*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1);
    //virtual void SetColumnN_Simply(int N, double*rowParam)=0;
    void Matrix_TmpltArr2DShell_ArrOfLines::SetColumnN_Simply(int N, double*rowParam){
        this->data.SetIneRowSimply(N, rowParam);
    }
    //
    //template<typename T>void ArrayOf2DBy1D_AddIneRow(T*&X, Array2DSize& size, T DefaultVal, T*rowParam=NULL, int wholeRowL=0, TDataShiftParams*dataShiftParam=NULL,                         int ifNGTLmin_Ignore0AddToLast1StretchToMax2=0, bool RectIfPossible=true){
    //                     void               AddIneRow(                         T DefaultVal, T*rowParam=NULL, int wholeRowL=0, TDataShiftParams*dataShiftParam=NULL,                         int ifNGTLmin_Ignore0AddToLast1StretchToMax2=0, bool RectIfPossible=true)=0;
    //                     void               AddIneRow(                                       T*rowParam=NULL, int wholeRowL=0, TDataShiftParams*dataShiftParam=NULL, T*DefaultValParam=NULL, int ifNGTLmin_Ignore0AddToLast1StretchToMax2=0, bool RectIfPossible=true)=0;
    //
    //virtual void AddIneRow_Simply(T*rowParam)=0;
    //
    //virtual void AddColumn_OwnDataType(double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL)=0;
    void Matrix_TmpltArr2DShell_ArrOfLines::AddColumn_OwnDataType(double*rowParam, int wholeRowL, TDataShiftParams*DataShiftParam){
        this->data.AddIneRow(0.0, rowParam, wholeRowL,DataShiftParam);
    }
    //void AddColumn_Gen                (double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    //virtual void  AddColumn_Simply(double*rowParam)=0;
    void Matrix_TmpltArr2DShell_ArrOfLines::AddColumn_Simply(double*rowParam){
        this->data.AddIneRow_Simply(rowParam);
    }
    //
    //template<typename T>void ArrayOf2DBy1D_InsIneRowN(T*&X, Array2DSize& size, int IneRowN, T DefaultVal, T*rowParam=NULL, int wholeRowL=0,                         TDataShiftParams*DataShiftParam=NULL, int ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_ValForShorterIsMissedForNsFitKeeping3_NextNewValToNextProperL4=1){
    //                      void               InsIneRowN(                         int IneRowN, T DefaultVal, T*rowParam=NULL, int wholeRowL=0,                         TDataShiftParams*DataShiftParam=NULL, int arr2D_ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_AnyExtRow3_NurFromStartTillErstStop4=0, int arr1D_ifNurProperL_NsSame1_EltsWithNsOfShoeterExtRowsNeUsed2=1);
    //                      void               InsIneRowN(                         int IneRowN,               T*rowParam=NULL, int wholeRowL=0, T*DefaultValParam=NULL, TDataShiftParams*DataShiftParam=NULL, int arr2D_ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_AnyExtRow3_NurFromStartTillErstStop4=0, int arr1D_ifNurProperL_NsSame1_EltsWithNsOfShoeterExtRowsNeUsed2=1);
    //
    //virtual void InsIneRow_Simply(int N, T*rowParam)=0;
    //
    //virtual void InsColumn_OwnDataType(int ColN, double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL)=0;
    void Matrix_TmpltArr2DShell_ArrOfLines::InsColumn_OwnDataType(int ColN, double*rowParam, int wholeRowL, TDataShiftParams*DataShiftParam){
        this->data.AddIneRow(0.0, rowParam, wholeRowL, DataShiftParam);
    }
    //void InsColumn_Gen                (int ColN, double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    //virtual void InsColumn_Simply(int ColN, double*rowParam)=0;
    void Matrix_TmpltArr2DShell_ArrOfLines::InsColumn_Simply(int ColN, double*rowParam){
        this->data.InsIneRow_Simply(ColN, rowParam);
    }
    //
    //
    ////void DelIneRowN(int N=-1, int ifNGTLmin_Ignore0_DelLast1_NurProperL_AnyExtRow3_NurFromStartTillFirstBreak4=0);
    ////virtual void DelIneRow_Simply(int N=-1)=0;
    //
    //virtual void DelColumnN(int N=-1)=0;
    void Matrix_TmpltArr2DShell_ArrOfLines::DelColumnN(int N){
        this->data.DelIneRowN(N);
    }
    //
    // Set Content
    //
    //void Set(T**y, const Array2DSize& size,  bool WriteSize=true);
    //void Set(T**y, std::vector<int>ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(T**y, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(T**y, int QExtRows, int ExtRowsLength=1, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(T*y, const Array2DSize& size, bool WriteSize=true);
    //void Set(T*y, std::vector<int>ExtRowsLengthes, bool WriteSize=true);
    //void Set(T*y, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true,  bool WriteSize=true);
    //void Set(T*y, int QExtRows, int ExtRowsLength=1, bool RectIfPossible=true, bool sizeVaria=false, bool WriteSize=true);
    //void Set(std::vector<std::vector<T>>y, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(std::vector<T>y, const Array2DSize& size, bool WriteSize=true);
    //void Set(std::vector<T>y, std::vector<int>ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(std::vector<T>y, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(std::vector<T>y, int QExtRows, int ExtRowsLength=1, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(const T&val, const Array2DSize& size, bool WriteSize=true);
    //void Set(const T&val, std::vector<int>ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(const T&val, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(const T&val, int QExtRows, int ExtRowsLength=1, bool RectIfPossible=true, bool WriteSize=true);
    //
    //void Set_arrOfLines(double**y, int QExtRows, int ExtRowsLength=1);
    //void Set_arrOfLines(double*y, int QExtRows, int ExtRowsLength=1);
    //void Set_arrOfLines(std::vector<double>y, int QExtRows, int ExtRowsLength=1);
    //void Set_arrOfLines(std::vector<std::vector<double>>y);
    //void Set_arrOfColumns(double**y, int QExtRows, int ExtRowsLength=1);
    //void Set_arrOfColumns(double*y, int QExtRows, int ExtRowsLength=1);
    //void Set_arrOfColumns(std::vector<double>y, int QExtRows, int ExtRowsLength=1);
    //void Set_arrOfColumns(std::vector<std::vector<double>>y);
    //
    //void SwapVals(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
    //
    //void SwapExtRows(int N1, int N2);
    //void SwapIneRows(int N1, int N2);
    //
    //void ReverseExtRowN(int rowN);//wa virtual...=0, nu n'tak
    //void ReverseIneRowN(int rowN);//wa virtual...=0, nu n'tak
    //virtual void ReverseExtRowsSuccession()
    //virtual void ReverseIneRowsSuccession();
    //
    ////bool ValIsAtPos(const T&val, int ExtRowN, int IneRowN) const;
    //bool ValIsAtPos(double val, int ExtRowN, int IneRowN) const;
    ////swa S di n'fit prototype - obe s': alt IneRowN wa ExtRowN, so ExtRowN 2x, ce alt err
    ////std::vector<std::vector<int>> SeekVal(const T&val) const;
    ////std::vector<Int2DVectorOfSizeOrCoords> SeekVal(const T&val) const;
    ////TListOfNumberPairs SeekVal(const T&val) const;
    //TListOfNumberPairs SeekVal(double val) const;
    ////so class name. Ma to vrns co std::vector ety di n'fit prototype
    ////bool ExtRowIsAtPos(T*row, int Q, int ExtRowN, int IneRowN) const;
    //bool LineIsAtPos(double*row, int Q, int ExtRowN, int IneRowN) const;
    ////std::vector<std::vector<int>> SeekExtRow(T*row, int L) const;
    ////std::vector<Int2DVectorOfSizeOrCoords> SeekExtRow(T*row, int L) const;
    ////TListOfNumberPairs SeekExtRow(T*row, int L) const;
    //TListOfNumberPairs SeekLine(double*row, int L) const;
    //bool IneRowIsAtPos(T*row, int Q, int ExtRowN, int IneRowN) const;
    //bool ColumnIsAtPos(double*row, int Q, int ExtRowN, int IneRowN) const;
    //std::vector<std::vector<int>> SeekIneRow(T*row, int Q) const;
    //std::vector<Int2DVectorOfSizeOrCoords> SeekIneRow(T*row, int Q) const;
    ////TListOfNumberPairs SeekIneRow(T*row, int Q) const;
    //TListOfNumberPairs SeekColumn(double*row, int Q) const;

    ////bool Arr2DIsAtPos(std::vector<std::vector<T>>arr, int ExtRowN, int IneRowN, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //bool Arr2DIsAtPos(std::vector<std::vector<double>>arr, int ExtRowN, int IneRowN, bool ArrOfLinesNotColumns=true, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //bool Arr2DIsAtPos(Matrix_Prototype*obj, int ExtRowN, int IneRowN, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;

    ////std::vector<std::vector<int>> SeekArr2D(std::vector<std::vector<T>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    ////std::vector<Int2DVectorOfSizeOrCoords> SeekArr2D(std::vector<std::vector<T>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    ////TListOfNumberPairs SeekArr2D(std::vector<std::vector<T>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //TListOfNumberPairs SeekArr2D(std::vector<std::vector<double>>arr, bool ArrOfLinesNotColumns=true, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    ////std::vector<std::vector<int>> SeekArr2D(Array2D_Prototype*arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    ////std::vector<Int2DVectorOfSizeOrCoords> SeekArr2D(Array2D_Prototype*arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //TListOfNumberPairs SeekArr2D(Matrix_Prototype*obj, bool ArrOfLinesNotColumns=true, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //
    ////virtual void ConcatAdding(Matrix_Prototype*obj, T DefaultVal,int QShiftedCols=0,  TDataShiftParams*DataShiftParam=NULL, bool SetRect=true, int DfltRowL_00_11_Lmin2_Lmax3=1);
    ////virtual void ConcatAdding(Matrix_Prototype*obj, int QShiftedCols=0, TDataShiftParams*DataShiftParam=NULL, T*DefaultValParam=NULL, bool SetRect=true, int DfltRowL_00_11_Lmin2_Lmax3=1);
    //
    //void ConcatAdding(Matrix_Prototype*obj, int QShiftedCols=0,  TDataShiftParams*DataShiftParam=NULL);
    ////_ConcatStretching(T*X1, const Array2DSize& size1, T*X2, const Array2DSize& size2, T*&X3, Array2DSize& size3, T DefaultVal, int shiftQ=0, TDataShiftParams*DataShiftParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3, bool Stretch1ToMax=true, bool SetRect=true){
    ////virtual void ConcatStretching(Matrix_Prototype*obj, T DefaultVal, int QShiftedExtRowNs=0,  TDataShiftParams*DataShiftParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3, bool Stretch1ToMax=true, bool SetRect=true);
    ////virtual void ConcatStretching(Matrix_Prototype*obj, int QShiftedExtRowNs=0, TDataShiftParams*DataShiftParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3, bool Stretch1ToMax=true, bool SetRect=true, T*DefaultValParam=NULL);
    //void ConcatStretching(Matrix_Prototype*obj, int QShiftedCols=0,  TDataShiftParams*DataShiftParam=NULL);
    //
    //virtual Matrix_Prototype*GetSubMatrix(int ExtRowN, int IneRowN, const Array2DSize& size, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const=0;
    Matrix_TmpltArr2DShell_ArrOfLines* Matrix_TmpltArr2DShell_ArrOfLines::GetSubMatrix(int LineN, int ColN, const Array2DSize& size, bool isNotTransposed, bool ExtRowsSuccIsNotReversed, bool EachExtRowIsNotReversed) const{
        double* dataRow=NULL;
        Matrix_TmpltArr2DShell_ArrOfLines*M=this->CreateMatrix();
        this->data.GetSubArray_AsPtrRef(dataRow, LineN, ColN,  size, isTransposed, ExtRowsSuccIsNotReversed, EachExtRowIsNotReversed);
        M->Set_arrOfLines(data, size.GetQExtRows(), size.GetLength(1));
        if(dataRow=NULL){
            delete[]dataRow;
        }
        return M;
    }
    //virtual Matrix_Prototype*GetSubMatrix(TDataShiftParams*DataShiftParam=NULL) const=0;
    Matrix_TmpltArr2DShell_ArrOfLines* Matrix_TmpltArr2DShell_ArrOfLines::GetSubMatrix(TDataShiftParams*DataShiftParam) const{
        double* dataRow=NULL;
        Array2DSize size;
        Matrix_TmpltArr2DShell_ArrOfLines*M=this->CreateMatrix();
        this->data.GetSubArray_AsSuccOfExtRows(dataRow, size, 0.0, DataShiftParam);
        M->Set_arrOfLines(data, size.GetQExtRows(), size.GetLength(1));
        if(dataRow=NULL){
            delete[]dataRow;
        }
        return M;
    }
    //
    ////void ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(T val, int ExtRowN, int IneRowN, T DefaultVal, bool SetRect=true, int DfltRowL_00_11_Max2_Min3=2);
    ////void ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(T val, int ExtRowN, int IneRowN, bool SetRect=true, int DfltRowL_00_11_Max2_Min3=2, T*DefaultValParam=NULL);
    //
    //void ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(int ExtRowN, int IneRowN);
    //void ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(int ExtRowN, int IneRowN);
    //
    //void StdCout_ExtRowN(int ExtRowN, QString ElemsDelim="; ", bool UseBrackets=true)const;
    //void StdCout_IneRowN(int IneRowN, QString ElemsDelim="; ", bool UseBrackets=true, bool Represent2DNot1D=false)const;
    //void StdCout(QString ElemsDelim=", ", QString RowsDelim="; ", bool UseBrackets=true, bool Represent2DNot1D=true, bool ByExtRowsNotIneRows=true)const;
//};//Matrix_TmpltArrV1L_ArrOfLines




//class Matrix_TmpltArr2DShell_ArrOfColumns : public Matrix_Prototype{
//    Array2D_Shell<double> data;
//public:
    Matrix_TmpltArr2DShell_ArrOfColumns(int QLines=1, int QColumns=1);
    Matrix_TmpltArr2DShell_ArrOfColumns(double val, int QLines=1, int QColumns=1);
    Matrix_TmpltArr2DShell_ArrOfColumns(double*arrOfColumns, int QLines=1, int QColumns=1);
    Matrix_TmpltArr2DShell_ArrOfColumns(double**arr, int QLines=1, int QColumns=1);
    Matrix_TmpltArr2DShell_ArrOfColumns(std::vector<double>arrOfColumns, int QLines=1, int QColumns=1);
    Matrix_TmpltArr2DShell_ArrOfColumns(std::vector<std::vector<double>>arrOfColumns);
    //
    Matrix_TmpltArrV1L_ArrOfLines(const Matrix_TmpltArrV1L_ArrOfLines& obj);
    //
    virtual ~Matrix_TmpltArrV1L_ArrOfLines();
    //
    //virtual void SetNull()=0;
    virtual void SetNull();
    //virtual void construct()=0;
    virtual void construct();
    //virtual Matrix_Prototype* CreateArray() const=0;
    virtual Matrix_TmpltArr2DShell_ArrOfLines* CreateArray() const;
    //virtual Matrix_Prototype* clone()const=0;
    virtual Matrix_Prototype* clone()const;
    //virtual int GetTypeN() const=0 ;
    virtual int GetTypeN() const;
    //
    //void SetOne(T*DfltVal=NULL);
    //void SetOne(const T&DfltVal);
    void SetOne();
    //
    ////virtual void SetSize(const T& DfltValParam, const Array2DSize&size)=0;
    //
    ////void SetSize(const Array2DSize&size, T*DfltValParam=NULL);//virtual ob hin Sdo mut l'size data
    ////void SetSize(int QExtRows=1, int ExtRowsLength=1, T*DfltValParam=NULL);
    ////void SetSize(int QExtRows=1, int*ExtRowsLengthes=NULL, T*DfltValParam=NULL);//if Null => L=0
    ////void SetSize(std::vector<int>ExtRowsLengthes, T*DfltValParam=NULL);
    //
    ////void SetSize(const T& DfltValParam, int QExtRows=1, int ExtRowsLength=1);//virtual ob hin Sdo mut l'size data
    ////void SetSize(const T& DfltValParam, int QExtRows=1, int*ExtRowsLengthes=NULL);//if Null => L=0
    ////void SetSize(const T& DfltValParam, std::vector<int>Lengthes);
    //
    //virtual void SetSize(int QExtRows=1, int ExtRowsLength=1)=0;
    virtual void SetSize(int QExtRows=1, int ExtRowsLength=1);
    //
    ////virtual int GetQExtRows() const=0;
    ////virtual int GetLength(int ExtRowN=1) const=0;
    ////virtual int GetMinLength() const=0;
    ////virtual int GetMaxLength() const=0;
    //virtual int GetQLines()=0;
    virtual int GetQLines();
    //virtual int GetQColumns()=0;
    virtual int GetQColumns();
    //virtual Array2DSize GetSize()const =0;
    //
    ////bool LineNBelongsHere(int LineN) const;
    ////bool ColNBelongsHere(int ColN) const;
    //bool NsBelongHere(int ExtRowN, int IneRowN) const;
    //
    ////std::vector<T> GetArrayOfExtRowN(int LineN);
    ////std::vector<T> GetArrayOfIneRowN(int ColN);
    ////std::vector<T> GetContentAsArray1D();
    ////std::vector<std::vector<T>> GetContentAsArray2D();
    //
    ////std::vector<T> GetExtRowN_AsArray(int rowN) const;
    //std::vector<double> GetLineN_AsArray(int rowN) const;
    //// T*GetExtRowN_AsPtr(int ExtRowN) const;
    ////std::vector<T> GetIneRowN_AsArray(int rowN) const;
    //std::vector<double> GetColumnN_AsArray(int rowN) const;
    ////std::vector<T> GetIneRowN_AsArray(int IneRowN, const T& defaultVal,                         int ifNGTLmin_Ignore0_DefaultsForShorter1_NurProperL_AnyExtRow2_NurFromStartTillErstStop3=0) const;
    ////std::vector<T> GetIneRowN_AsArray(int IneRowN,                      T*DefaultValParam=NULL, int ifNGTLmin_Ignore0_DefaultsForShorter1_NurProperL_AnyExtRow2_NurFromStartTillErstStop3=0) const;
    ////std::vector<T> GetContent_AsArray1D() const;
    ////std::vector<std::vector<T>> GetContent_AsArray2D() const;
    //std::vector<double> GetContent_AsArray1DOfLines() const;
    //std::vector<double> GetContent_AsArray1DOfColumns() const;
    //std::vector<std::vector<double>> GetContent_AsArray2DOfLines() const;
    //std::vector<std::vector<double>> GetContent_AsArray2DOfColumns() const;
    //
    //
    ////virtual T GetComponent_AsVal(int LineN, int ColN) const=0;
    ////virtual T* GetComponent_AsPtr(int LineN, int ColN) const=0;
    //virtual double GetComponent_AsVal(int LineN, int ColN) const=0;
    virtual double GetComponent_AsVal(int LineN, int ColN) const;
    //virtual double* GetComponent_AsPtr(int LineN, int ColN) const=0;
    virtual double* GetComponent_AsPtr(int LineN, int ColN) const;
    //
    ////virtual void SetComponent(const T& val, int LineN, int ColN)=0;
    //virtual void SetComponent(double val, int LineN, int ColN)=0;
    virtual void SetComponent(double val, int LineN, int ColN);
    //
    ////void AddToExtRowN(int RowN, const T&val);
    ////void InsToExtRowN(int RowN, int PosN, const T&val);
    ////void DelFromExtRowN(int RowN, int PosN);
    //
    ////virtual void AddToExtRowN_Simply(int ExtRowN, const T&val)=0;
    ////virtual void InsToExtRowN_Simply(int ExtRowN, int PosN, const T&val)=0;
    ////virtual void DelFromExtRowN_Simply(int RowN, int IneRowPosN)=0;
    //
    // Ext row
    //
    ////template<typename T> void ArrayOf2DBy1D_SetExtRowN(T*&X, Array2DSize&size, int ExtRowN,       T DefaultVal, T*rowParam, int wholeRowL=0,                      TDataShiftParams*DataShiftParam=NULL, /*bool KeepIfRect=true,*/ bool DefaultIsSpecNotOwn=true,      int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2){
    ////virtual              void               SetExtRowN(                              int N, const T& defaultVal,  T*rowParam,      int rowL,    TDataShiftParams*DataShiftParams=NULL,                          bool DefaulsAreSpecNotOwnVals=true, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2)=0;
    ////void SetExtRowN(int N, const T& defaultVal, T*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true,                      int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2);
    ////void SetExtRowN(int N,                      T*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, T*DfltValParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2);
    //
    ////void SetExtRow_Simply(int N, T*rowParam)=0;
    ////void SetExtRow_Simply(int N, T*rowParam, int L)=0;
    //
    //virtual void SetLineN_OwnDataType(int N,      double*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1)=0;
    virtual void SetLineN_OwnDataType(int N,      double*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1);
    //void SetLineN_Gen(int N,                      double*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1);
    //virtual void SetLineN_Simply(int N, double*rowParam)=0;
    virtual void SetLineN_Simply(int N, double*rowParam);
    //
    ////template<typename T>void ArrayOf2DBy1D_AddExtRow(T*&X, Array2DSize&size, T DefaultVal, T*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL){
    ////                      void               AddExtRow(                        T DefaultVal, T*rowParam, int wholeRowL=0,                         TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL);
    ////template<typename T>void ArrayOf2DBy1D_AddExtRow(T*&X, Array2DSize&size, T*rowParam, int wholeRowL=0, T*DefaultValParam=NULL, TDataShiftParams*DataShiftParam=NULL,  int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL){
    //                      void               AddExtRow(                                      T*rowParam, int wholeRowL=0, T*DefaultValParam=NULL, TDataShiftParams*DataShiftParam=NULL,  int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL);
    //
    ////virtual void AddExtRow_Simply(T*rowParam)=0;
    ////virtual void AddExtRow_Simply(T*rowParam, int L)=0;
    //
    //virtual void AddLine_OwnDataType(double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL)=0;
    virtual void AddLine_OwnDataType(double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    //void AddLine_Gen(double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    //virtual void AddLine_Simply(double*rowParam)=0;
    virtual void AddLine_Simply(double*rowParam);

    ////template<typename T>void ArrayOf2DBy1D_InsExtRow(T*&X, Array2DSize&size, int ExtRowN, T DefaultVal, T*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL){
    ////                      void               InsExtRow(                        int ExtRowN, T DefaultVal, T*rowParam, int wholeRowL=0,                      TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL);
    ////template<typename T>void ArrayOf2DBy1D_InsExtRow(T*&X, Array2DSize&size, int ExtRowN, T*rowParam, int wholeRowL=0,  T*DfltValParam=NULL, TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL){
    ////                      void               InsExtRow(                        int ExtRowN,               T*rowParam, int wholeRowL=0, T*DfltValParam=NULL, TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL);
    //
    ////virtual void InsExtRow_Simply(int N, T*rowParam)=0;
    ////virtual void InsExtRow_Simply(int N, T*rowParam, int L)=0;
    //
    //virtual void InsLine_OwnDataType(double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL)=0;
    virtual void InsLine_OwnDataType(double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    //void InsLine_Gen(double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    //virtual void InsLine_Simply(double*rowParam)=0;
    virtual void InsLine_Simply(double*rowParam);
    //
    ////void DelExtRowN(int N=-1);
    ////virtual void DelExtRowN_Simply(int N=-1)=0;
    //
    //virtual void DelLineN(int N=-1)=0;
    virtual void DelLineN(int N=-1);
    //virtual void DelLineN(int N=-1)=0;
    virtual void DelLineN(int N=-1);
    //
    //Ine row
    //
    //void SetIneRowN( int IneRowN, const T& defaultVal, T*rowParam=NULL, int rowL=0, TDataShiftParams*DataShiftParam=NULL,                         bool DefaulsAreSpecNotOwnVals=true, int arr2D_ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_AnyExtRow3_NurFromStartTillErstStop4=0, int arr1D_ifNurProperL_NsSame1_EltsWithNsOfShoeterExtRowsNeUsed2=1);
    //void SetIneRowN( int IneRowN,                      T*rowParam=NULL, int rowL=0, TDataShiftParams*DataShiftParam=NULL, T*DefaultValParam=NULL, bool DefaulsAreSpecNotOwnVals=true, int arr2D_ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_AnyExtRow3_NurFromStartTillErstStop4=0, int arr1D_ifNurProperL_NsSame1_EltsWithNsOfShoeterExtRowsNeUsed2=1);
    //
    //virtual void SetIneRowSimply(int IneRowN, T*rowParam)=0;
    //
    //virtual void SetColumnN_OwnDataType(int N,          double*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1)=0;
    virtual void SetColumnN_OwnDataType(int N,          double*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1);
    //void SetColumnN_Gen                (int N,          double*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1);
    //virtual void SetColumnN_Simply(int N, double*rowParam)=0;
    virtual void SetColumnN_Simply(int N, double*rowParam);
    //
    //template<typename T>void ArrayOf2DBy1D_AddIneRow(T*&X, Array2DSize& size, T DefaultVal, T*rowParam=NULL, int wholeRowL=0, TDataShiftParams*dataShiftParam=NULL,                         int ifNGTLmin_Ignore0AddToLast1StretchToMax2=0, bool RectIfPossible=true){
    //                     void               AddIneRow(                         T DefaultVal, T*rowParam=NULL, int wholeRowL=0, TDataShiftParams*dataShiftParam=NULL,                         int ifNGTLmin_Ignore0AddToLast1StretchToMax2=0, bool RectIfPossible=true)=0;
    //                     void               AddIneRow(                                       T*rowParam=NULL, int wholeRowL=0, TDataShiftParams*dataShiftParam=NULL, T*DefaultValParam=NULL, int ifNGTLmin_Ignore0AddToLast1StretchToMax2=0, bool RectIfPossible=true)=0;
    //
    //virtual void AddIneRow_Simply(T*rowParam)=0;
    //
    //virtual void AddColumn_OwnDataType(double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL)=0;
    virtual void AddColumn_OwnDataType(double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    //void AddColumn_Gen                (double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    //virtual void  AddColumn_Simply(double*rowParam)=0;
    virtual void  AddColumn_Simply(double*rowParam)=0;
    //
    //template<typename T>void ArrayOf2DBy1D_InsIneRowN(T*&X, Array2DSize& size, int IneRowN, T DefaultVal, T*rowParam=NULL, int wholeRowL=0,                         TDataShiftParams*DataShiftParam=NULL, int ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_ValForShorterIsMissedForNsFitKeeping3_NextNewValToNextProperL4=1){
    //                      void               InsIneRowN(                         int IneRowN, T DefaultVal, T*rowParam=NULL, int wholeRowL=0,                         TDataShiftParams*DataShiftParam=NULL, int arr2D_ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_AnyExtRow3_NurFromStartTillErstStop4=0, int arr1D_ifNurProperL_NsSame1_EltsWithNsOfShoeterExtRowsNeUsed2=1);
    //                      void               InsIneRowN(                         int IneRowN,               T*rowParam=NULL, int wholeRowL=0, T*DefaultValParam=NULL, TDataShiftParams*DataShiftParam=NULL, int arr2D_ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_AnyExtRow3_NurFromStartTillErstStop4=0, int arr1D_ifNurProperL_NsSame1_EltsWithNsOfShoeterExtRowsNeUsed2=1);
    //
    //virtual void InsIneRow_Simply(int N, T*rowParam)=0;
    //
    //virtual void InsColumn_OwnDataType(int ColN, double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL)=0;
    virtual void InsColumn_OwnDataType(int ColN, double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    //void InsColumn_Gen                (int ColN, double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    //virtual void InsColumn_Simply(int ColN, double*rowParam)=0;
    virtual void InsColumn_Simply(int ColN, double*rowParam);
    //
    //
    ////void DelIneRowN(int N=-1, int ifNGTLmin_Ignore0_DelLast1_NurProperL_AnyExtRow3_NurFromStartTillFirstBreak4=0);
    ////virtual void DelIneRow_Simply(int N=-1)=0;
    //
    //virtual void DelColumnN(int N=-1)=0;
    virtual void DelColumnN(int N=-1);
    //
    // Set Content
    //
    //void Set(T**y, const Array2DSize& size,  bool WriteSize=true);
    //void Set(T**y, std::vector<int>ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(T**y, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(T**y, int QExtRows, int ExtRowsLength=1, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(T*y, const Array2DSize& size, bool WriteSize=true);
    //void Set(T*y, std::vector<int>ExtRowsLengthes, bool WriteSize=true);
    //void Set(T*y, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true,  bool WriteSize=true);
    //void Set(T*y, int QExtRows, int ExtRowsLength=1, bool RectIfPossible=true, bool sizeVaria=false, bool WriteSize=true);
    //void Set(std::vector<std::vector<T>>y, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(std::vector<T>y, const Array2DSize& size, bool WriteSize=true);
    //void Set(std::vector<T>y, std::vector<int>ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(std::vector<T>y, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(std::vector<T>y, int QExtRows, int ExtRowsLength=1, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(const T&val, const Array2DSize& size, bool WriteSize=true);
    //void Set(const T&val, std::vector<int>ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(const T&val, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(const T&val, int QExtRows, int ExtRowsLength=1, bool RectIfPossible=true, bool WriteSize=true);
    //
    //void Set_arrOfLines(double**y, int QExtRows, int ExtRowsLength=1);
    //void Set_arrOfLines(double*y, int QExtRows, int ExtRowsLength=1);
    //void Set_arrOfLines(std::vector<double>y, int QExtRows, int ExtRowsLength=1);
    //void Set_arrOfLines(std::vector<std::vector<double>>y);
    //void Set_arrOfColumns(double**y, int QExtRows, int ExtRowsLength=1);
    //void Set_arrOfColumns(double*y, int QExtRows, int ExtRowsLength=1);
    //void Set_arrOfColumns(std::vector<double>y, int QExtRows, int ExtRowsLength=1);
    //void Set_arrOfColumns(std::vector<std::vector<double>>y);
    //
    //void SwapVals(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
    //
    //void SwapExtRows(int N1, int N2);
    //void SwapIneRows(int N1, int N2);
    //
    //void ReverseExtRowN(int rowN);//wa virtual...=0, nu n'tak
    //void ReverseIneRowN(int rowN);//wa virtual...=0, nu n'tak
    //virtual void ReverseExtRowsSuccession()=0;
    virtual void ReverseExtRowsSuccession();
    //virtual void ReverseIneRowsSuccession()=0;
    virtual void ReverseIneRowsSuccession();
    //
    ////bool ValIsAtPos(const T&val, int ExtRowN, int IneRowN) const;
    //bool ValIsAtPos(double val, int ExtRowN, int IneRowN) const;
    ////swa S di n'fit prototype - obe s': alt IneRowN wa ExtRowN, so ExtRowN 2x, ce alt err
    ////std::vector<std::vector<int>> SeekVal(const T&val) const;
    ////std::vector<Int2DVectorOfSizeOrCoords> SeekVal(const T&val) const;
    ////TListOfNumberPairs SeekVal(const T&val) const;
    //TListOfNumberPairs SeekVal(double val) const;
    ////so class name. Ma to vrns co std::vector ety di n'fit prototype
    ////bool ExtRowIsAtPos(T*row, int Q, int ExtRowN, int IneRowN) const;
    //bool LineIsAtPos(double*row, int Q, int ExtRowN, int IneRowN) const;
    ////std::vector<std::vector<int>> SeekExtRow(T*row, int L) const;
    ////std::vector<Int2DVectorOfSizeOrCoords> SeekExtRow(T*row, int L) const;
    ////TListOfNumberPairs SeekExtRow(T*row, int L) const;
    //TListOfNumberPairs SeekLine(double*row, int L) const;
    //bool IneRowIsAtPos(T*row, int Q, int ExtRowN, int IneRowN) const;
    //bool ColumnIsAtPos(double*row, int Q, int ExtRowN, int IneRowN) const;
    //std::vector<std::vector<int>> SeekIneRow(T*row, int Q) const;
    //std::vector<Int2DVectorOfSizeOrCoords> SeekIneRow(T*row, int Q) const;
    ////TListOfNumberPairs SeekIneRow(T*row, int Q) const;
    //TListOfNumberPairs SeekColumn(double*row, int Q) const;

    ////bool Arr2DIsAtPos(std::vector<std::vector<T>>arr, int ExtRowN, int IneRowN, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //bool Arr2DIsAtPos(std::vector<std::vector<double>>arr, int ExtRowN, int IneRowN, bool ArrOfLinesNotColumns=true, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //bool Arr2DIsAtPos(Matrix_Prototype*obj, int ExtRowN, int IneRowN, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;

    ////std::vector<std::vector<int>> SeekArr2D(std::vector<std::vector<T>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    ////std::vector<Int2DVectorOfSizeOrCoords> SeekArr2D(std::vector<std::vector<T>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    ////TListOfNumberPairs SeekArr2D(std::vector<std::vector<T>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //TListOfNumberPairs SeekArr2D(std::vector<std::vector<double>>arr, bool ArrOfLinesNotColumns=true, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    ////std::vector<std::vector<int>> SeekArr2D(Array2D_Prototype*arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    ////std::vector<Int2DVectorOfSizeOrCoords> SeekArr2D(Array2D_Prototype*arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //TListOfNumberPairs SeekArr2D(Matrix_Prototype*obj, bool ArrOfLinesNotColumns=true, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //
    ////virtual void ConcatAdding(Matrix_Prototype*obj, T DefaultVal,int QShiftedCols=0,  TDataShiftParams*DataShiftParam=NULL, bool SetRect=true, int DfltRowL_00_11_Lmin2_Lmax3=1);
    ////virtual void ConcatAdding(Matrix_Prototype*obj, int QShiftedCols=0, TDataShiftParams*DataShiftParam=NULL, T*DefaultValParam=NULL, bool SetRect=true, int DfltRowL_00_11_Lmin2_Lmax3=1);
    //
    //void ConcatAdding(Matrix_Prototype*obj, int QShiftedCols=0,  TDataShiftParams*DataShiftParam=NULL);
    ////_ConcatStretching(T*X1, const Array2DSize& size1, T*X2, const Array2DSize& size2, T*&X3, Array2DSize& size3, T DefaultVal, int shiftQ=0, TDataShiftParams*DataShiftParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3, bool Stretch1ToMax=true, bool SetRect=true){
    ////virtual void ConcatStretching(Matrix_Prototype*obj, T DefaultVal, int QShiftedExtRowNs=0,  TDataShiftParams*DataShiftParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3, bool Stretch1ToMax=true, bool SetRect=true);
    ////virtual void ConcatStretching(Matrix_Prototype*obj, int QShiftedExtRowNs=0, TDataShiftParams*DataShiftParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3, bool Stretch1ToMax=true, bool SetRect=true, T*DefaultValParam=NULL);
    //void ConcatStretching(Matrix_Prototype*obj, int QShiftedCols=0,  TDataShiftParams*DataShiftParam=NULL);
    //
    //virtual Matrix_Prototype*GetSubMatrix(int ExtRowN, int IneRowN, const Array2DSize& size, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const=0;
    virtual Matrix_TmpltArr2DShell_ArrOfColumns*GetSubMatrix(int ExtRowN, int IneRowN, const Array2DSize& size, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //virtual Matrix_Prototype*GetSubMatrix(TDataShiftParams*DataShiftParam=NULL) const=0;
    virtual Matrix_TmpltArr2DShell_ArrOfColumns*GetSubMatrix(TDataShiftParams*DataShiftParam=NULL) const;
    //
    ////void ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(T val, int ExtRowN, int IneRowN, T DefaultVal, bool SetRect=true, int DfltRowL_00_11_Max2_Min3=2);
    ////void ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(T val, int ExtRowN, int IneRowN, bool SetRect=true, int DfltRowL_00_11_Max2_Min3=2, T*DefaultValParam=NULL);
    //
    //void ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(int ExtRowN, int IneRowN);
    //void ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(int ExtRowN, int IneRowN);
    //
    //void StdCout_ExtRowN(int ExtRowN, QString ElemsDelim="; ", bool UseBrackets=true)const;
    //void StdCout_IneRowN(int IneRowN, QString ElemsDelim="; ", bool UseBrackets=true, bool Represent2DNot1D=false)const;
    //void StdCout(QString ElemsDelim=", ", QString RowsDelim="; ", bool UseBrackets=true, bool Represent2DNot1D=true, bool ByExtRowsNotIneRows=true)const;
};//Matrix_TmpltArr_V1L_ArrOfColumns





class Matrix{//Shell
    Matrix_Prototype* data;
public:
    Matrix(int QLines=1, int QColumns=1, int TypeN=Matrix_TmpltArrr_V1L_ArrOfLines_TypeN);
    Matrix(double val, int QLines=1, int QColumns=1, int TypeN=Matrix_TmpltArrr_V1L_ArrOfLines_TypeN);
    Matrix(double*arrOfLines, int QLines=1, int QColumns=1, int TypeN=Matrix_TmpltArrr_V1L_ArrOfLines_TypeN);
    Matrix(double**arr, int QLines=1, int QColumns=1, int TypeN=Matrix_TmpltArrr_V1L_ArrOfLines_TypeN);
    Matrix(std::vector<double>arrOfLines, int QLines=1, int QColumns=1, int TypeN=Matrix_TmpltArrr_V1L_ArrOfLines_TypeN);
    Matrix(std::vector<std::vector<double>>arrOfLines);
    //
    Matrix(const Matrix& obj);
    //
    ~Matrix();
    //
    //
    void SetNull();
    void construct(int TypeN);
    //virtual Matrix_Prototype* CreateArray() const=0;
    //virtual Matrix_Prototype* CreateArray() const=0;
    //virtual Matrix_Prototype* clone()const=0;
    Matrix clone()const;
    int GetTypeN() const ;
    //
    //void SetOne(T*DfltVal=NULL);
    //void SetOne(const T&DfltVal);
    void SetOne();
    //
    //virtual void SetSize(const T& DfltValParam, const Array2DSize&size)=0;
    //
    //void SetSize(const Array2DSize&size, T*DfltValParam=NULL);//virtual ob hin Sdo mut l'size data
    //void SetSize(int QExtRows=1, int ExtRowsLength=1, T*DfltValParam=NULL);
    //void SetSize(int QExtRows=1, int*ExtRowsLengthes=NULL, T*DfltValParam=NULL);//if Null => L=0
    //void SetSize(std::vector<int>ExtRowsLengthes, T*DfltValParam=NULL);
    //
    //void SetSize(const T& DfltValParam, int QExtRows=1, int ExtRowsLength=1);//virtual ob hin Sdo mut l'size data
    //void SetSize(const T& DfltValParam, int QExtRows=1, int*ExtRowsLengthes=NULL);//if Null => L=0
    //void SetSize(const T& DfltValParam, std::vector<int>Lengthes);
    //
    //virtual void SetSize(int QExtRows=1, int ExtRowsLength=1)=0;
    void SetSize(int QExtRows=1, int ExtRowsLength=1);
    //
    //virtual int GetQExtRows() const=0;
    //virtual int GetLength(int ExtRowN=1) const=0;
    //virtual int GetMinLength() const=0;
    //virtual int GetMaxLength() const=0;
    //virtual int GetQLines()=0;
    int GetQLines();
    //virtual int GetQColumns()=0;
    int GetQColumns();
    //virtual Array2DSize GetSize()const =0;
    //
    //bool LineNBelongsHere(int LineN) const;
    //bool ColNBelongsHere(int ColN) const;
    bool NsBelongHere(int ExtRowN, int IneRowN) const;
    //
    //std::vector<T> GetArrayOfExtRowN(int LineN);
    //std::vector<T> GetArrayOfIneRowN(int ColN);
    //std::vector<T> GetContentAsArray1D();
    //std::vector<std::vector<T>> GetContentAsArray2D();
    //
    //std::vector<T> GetExtRowN_AsArray(int rowN) const;
    std::vector<double> GetLineN_AsArray(int rowN) const;
    // T*GetExtRowN_AsPtr(int ExtRowN) const;
    //std::vector<T> GetIneRowN_AsArray(int rowN) const;
    std::vector<double> GetColumnN_AsArray(int rowN) const;
    //std::vector<T> GetIneRowN_AsArray(int IneRowN, const T& defaultVal,                         int ifNGTLmin_Ignore0_DefaultsForShorter1_NurProperL_AnyExtRow2_NurFromStartTillErstStop3=0) const;
    //std::vector<T> GetIneRowN_AsArray(int IneRowN,                      T*DefaultValParam=NULL, int ifNGTLmin_Ignore0_DefaultsForShorter1_NurProperL_AnyExtRow2_NurFromStartTillErstStop3=0) const;
    //std::vector<T> GetContent_AsArray1D() const;
    //std::vector<std::vector<T>> GetContent_AsArray2D() const;
    std::vector<double> GetContent_AsArray1DOfLines() const;
    std::vector<double> GetContent_AsArray1DOfColumns() const;
    std::vector<std::vector<double>> GetContent_AsArray2DOfLines() const;
    std::vector<std::vector<double>> GetContent_AsArray2DOfColumns() const;
    //
    //
    //virtual T GetComponent_AsVal(int LineN, int ColN) const=0;
    //virtual T* GetComponent_AsPtr(int LineN, int ColN) const=0;
    double GetComponent_AsVal(int LineN, int ColN) const;
    double* GetComponent_AsPtr(int LineN, int ColN) const;
    //
    //virtual void SetComponent(const T& val, int LineN, int ColN)=0;
    void SetComponent(double val, int LineN, int ColN);
    //
    //void AddToExtRowN(int RowN, const T&val);
    //void InsToExtRowN(int RowN, int PosN, const T&val);
    //void DelFromExtRowN(int RowN, int PosN);
    //
    //virtual void AddToExtRowN_Simply(int ExtRowN, const T&val)=0;
    //virtual void InsToExtRowN_Simply(int ExtRowN, int PosN, const T&val)=0;
    //virtual void DelFromExtRowN_Simply(int RowN, int IneRowPosN)=0;
    //
    // Ext row
    //
    //template<typename T> void ArrayOf2DBy1D_SetExtRowN(T*&X, Array2DSize&size, int ExtRowN,       T DefaultVal, T*rowParam, int wholeRowL=0,                      TDataShiftParams*DataShiftParam=NULL, /*bool KeepIfRect=true,*/ bool DefaultIsSpecNotOwn=true,      int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2){
    //virtual              void               SetExtRowN(                              int N, const T& defaultVal,  T*rowParam,      int rowL,    TDataShiftParams*DataShiftParams=NULL,                          bool DefaulsAreSpecNotOwnVals=true, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2)=0;
    //void SetExtRowN(int N, const T& defaultVal, T*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true,                      int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2);
    //void SetExtRowN(int N,                      T*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, T*DfltValParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2);
    //
    //void SetExtRow_Simply(int N, T*rowParam)=0;
    //void SetExtRow_Simply(int N, T*rowParam, int L)=0;
    //
    void SetLineN_OwnDataType(int N,      double*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1);
    void SetLineN_Gen(        int N,      double*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1);
    void             SetLineN(int N,      double*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1);
    void SetLineN_Simply     (int N, double*rowParam);
    //
    //template<typename T>void ArrayOf2DBy1D_AddExtRow(T*&X, Array2DSize&size, T DefaultVal, T*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL){
                          void               AddExtRow(                        T DefaultVal, T*rowParam, int wholeRowL=0,                         TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL);
    //template<typename T>void ArrayOf2DBy1D_AddExtRow(T*&X, Array2DSize&size, T*rowParam, int wholeRowL=0, T*DefaultValParam=NULL, TDataShiftParams*DataShiftParam=NULL,  int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL){
                          void               AddExtRow(                                      T*rowParam, int wholeRowL=0, T*DefaultValParam=NULL, TDataShiftParams*DataShiftParam=NULL,  int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_LastL5_NewL6=2, TValsShowHide*vsh=NULL);
    //
    //virtual void AddExtRow_Simply(T*rowParam)=0;
    //virtual void AddExtRow_Simply(T*rowParam, int L)=0;
    //
    void AddLine_OwnDataType(double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    void AddLine_Gen        (double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    void AddLine            (double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    void AddLine_Simply(double*rowParam);
    //
    //template<typename T>void ArrayOf2DBy1D_InsExtRow(T*&X, Array2DSize&size, int ExtRowN, T DefaultVal, T*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL){
    //                      void               InsExtRow(                        int ExtRowN, T DefaultVal, T*rowParam, int wholeRowL=0,                      TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL);
    //template<typename T>void ArrayOf2DBy1D_InsExtRow(T*&X, Array2DSize&size, int ExtRowN, T*rowParam, int wholeRowL=0,  T*DfltValParam=NULL, TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL){
    //                      void               InsExtRow(                        int ExtRowN,               T*rowParam, int wholeRowL=0, T*DfltValParam=NULL, TDataShiftParams*DataShiftParam=NULL, int SizeRect_DoNotCare0_Not1_IfPossible2_AnywayBy_MaxOfBoth3_MaxLIn2DArr4_OldL5_NewL6=2, TValsShowHide*vsh=NULL);
    //
    //virtual void InsExtRow_Simply(int N, T*rowParam)=0;
    //virtual void InsExtRow_Simply(int N, T*rowParam, int L)=0;
    //
    void InsLine_OwnDataType(double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    void InsLine_Gen        (double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    void InsLine            (double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    void InsLine_Simply(double*rowParam);
    //
    //void DelExtRowN(int N=-1);
    //virtual void DelExtRowN_Simply(int N=-1)=0;
    //
    void DelLineN(int N=-1);
    //
    //Ine row
    //
    //void SetIneRowN( int IneRowN, const T& defaultVal, T*rowParam=NULL, int rowL=0, TDataShiftParams*DataShiftParam=NULL,                         bool DefaulsAreSpecNotOwnVals=true, int arr2D_ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_AnyExtRow3_NurFromStartTillErstStop4=0, int arr1D_ifNurProperL_NsSame1_EltsWithNsOfShoeterExtRowsNeUsed2=1);
    //void SetIneRowN( int IneRowN,                      T*rowParam=NULL, int rowL=0, TDataShiftParams*DataShiftParam=NULL, T*DefaultValParam=NULL, bool DefaulsAreSpecNotOwnVals=true, int arr2D_ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_AnyExtRow3_NurFromStartTillErstStop4=0, int arr1D_ifNurProperL_NsSame1_EltsWithNsOfShoeterExtRowsNeUsed2=1);
    //
    //virtual void SetIneRowSimply(int IneRowN, T*rowParam)=0;
    //
    //
    //void SetColumnN(int N,                      double*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1);
    void SetColumnN_OwnDataType(int N,            double*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1);
    void SetColumnN_Gen        (int N,            double*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1);
    //void SetColumnN            (int N,            double*rowParam, int rowL, TDataShiftParams*DataShiftParams=NULL, bool DefaulsAreSpecNotOwnVals=true, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1);
    void SetColumnN_Simply(int N, double*rowParam);
    //template<typename T>void ArrayOf2DBy1D_AddIneRow(T*&X, Array2DSize& size, T DefaultVal, T*rowParam=NULL, int wholeRowL=0, TDataShiftParams*dataShiftParam=NULL,                         int ifNGTLmin_Ignore0AddToLast1StretchToMax2=0, bool RectIfPossible=true){
    //                     void               AddIneRow(                         T DefaultVal, T*rowParam=NULL, int wholeRowL=0, TDataShiftParams*dataShiftParam=NULL,                         int ifNGTLmin_Ignore0AddToLast1StretchToMax2=0, bool RectIfPossible=true)=0;
    //                     void               AddIneRow(                                       T*rowParam=NULL, int wholeRowL=0, TDataShiftParams*dataShiftParam=NULL, T*DefaultValParam=NULL, int ifNGTLmin_Ignore0AddToLast1StretchToMax2=0, bool RectIfPossible=true)=0;
    //
    //virtual void AddIneRow_Simply(T*rowParam)=0;
    //
    void AddColumn_OwnDataType(double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    void AddColumn_Gen        (double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    //void AddColumn            (double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    void  AddColumn_Simply(double*rowParam);
    //
    //template<typename T>void ArrayOf2DBy1D_InsIneRowN(T*&X, Array2DSize& size, int IneRowN, T DefaultVal, T*rowParam=NULL, int wholeRowL=0,                         TDataShiftParams*DataShiftParam=NULL, int ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_ValForShorterIsMissedForNsFitKeeping3_NextNewValToNextProperL4=1){
    //                      void               InsIneRowN(                         int IneRowN, T DefaultVal, T*rowParam=NULL, int wholeRowL=0,                         TDataShiftParams*DataShiftParam=NULL, int arr2D_ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_AnyExtRow3_NurFromStartTillErstStop4=0, int arr1D_ifNurProperL_NsSame1_EltsWithNsOfShoeterExtRowsNeUsed2=1);
    //                      void               InsIneRowN(                         int IneRowN,               T*rowParam=NULL, int wholeRowL=0, T*DefaultValParam=NULL, TDataShiftParams*DataShiftParam=NULL, int arr2D_ifNGTLmin_Ignore0_AddToShorter1_StretchShorterToN2_NurProperL_AnyExtRow3_NurFromStartTillErstStop4=0, int arr1D_ifNurProperL_NsSame1_EltsWithNsOfShoeterExtRowsNeUsed2=1);
    //
    //virtual void InsIneRow_Simply(int N, T*rowParam)=0;
    //
    void InsColumn_OwnDataType(int ColN, double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    void InsColumn_Gen        (int ColN, double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    //void InsColumn            (int ColN, double*rowParam, int wholeRowL=0, TDataShiftParams*DataShiftParam=NULL, int IfDiffL_ByOld1_ByNew2_ByMaxOfBoth3=1, TValsShowHide*vsh=NULL);
    void InsColumn_Simply(int ColN, double*rowParam);
    //
    //void DelIneRowN(int N=-1, int ifNGTLmin_Ignore0_DelLast1_NurProperL_AnyExtRow3_NurFromStartTillFirstBreak4=0);
    //virtual void DelIneRow_Simply(int N=-1)=0;
    //
    void DelColumnN(int N=-1);
    //
    // Set Content
    //
    //void Set(T**y, const Array2DSize& size,  bool WriteSize=true);
    //void Set(T**y, std::vector<int>ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(T**y, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(T**y, int QExtRows, int ExtRowsLength=1, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(T*y, const Array2DSize& size, bool WriteSize=true);
    //void Set(T*y, std::vector<int>ExtRowsLengthes, bool WriteSize=true);
    //void Set(T*y, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true,  bool WriteSize=true);
    //void Set(T*y, int QExtRows, int ExtRowsLength=1, bool RectIfPossible=true, bool sizeVaria=false, bool WriteSize=true);
    //void Set(std::vector<std::vector<T>>y, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(std::vector<T>y, const Array2DSize& size, bool WriteSize=true);
    //void Set(std::vector<T>y, std::vector<int>ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(std::vector<T>y, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(std::vector<T>y, int QExtRows, int ExtRowsLength=1, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(const T&val, const Array2DSize& size, bool WriteSize=true);
    //void Set(const T&val, std::vector<int>ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(const T&val, int QExtRows, int*ExtRowsLengthes, bool RectIfPossible=true, bool WriteSize=true);
    //void Set(const T&val, int QExtRows, int ExtRowsLength=1, bool RectIfPossible=true, bool WriteSize=true);
    //
    void Set_arrOfLines(double**y, int QExtRows, int ExtRowsLength=1);
    void Set_arrOfLines(double*y, int QExtRows, int ExtRowsLength=1);
    void Set_arrOfLines(std::vector<double>y, int QExtRows, int ExtRowsLength=1);
    void Set_arrOfLines(std::vector<std::vector<double>>y);
    void Set_arrOfColumns(double**y, int QExtRows, int ExtRowsLength=1);
    void Set_arrOfColumns(double*y, int QExtRows, int ExtRowsLength=1);
    void Set_arrOfColumns(std::vector<double>y, int QExtRows, int ExtRowsLength=1);
    void Set_arrOfColumns(std::vector<std::vector<double>>y);
    //
    void SwapVals(int ExtRowN1, int IneRowN1, int ExtRowN2, int IneRowN2);
    //
    void SwapExtRows(int N1, int N2);
    void SwapIneRows(int N1, int N2);
    //
    void ReverseExtRowN(int rowN);//wa virtual...=0, nu n'tak
    void ReverseIneRowN(int rowN);//wa virtual...=0, nu n'tak
    void ReverseExtRowsSuccession();
    void ReverseIneRowsSuccession();
    //
    //bool ValIsAtPos(const T&val, int ExtRowN, int IneRowN) const;
    bool ValIsAtPos(double val, int ExtRowN, int IneRowN) const;
    //swa S di n'fit prototype - obe s': alt IneRowN wa ExtRowN, so ExtRowN 2x, ce alt err
    //std::vector<std::vector<int>> SeekVal(const T&val) const;
    //std::vector<Int2DVectorOfSizeOrCoords> SeekVal(const T&val) const;
    //TListOfNumberPairs SeekVal(const T&val) const;
    TListOfNumberPairs SeekVal(double val) const;
    //so class name. Ma to vrns co std::vector ety di n'fit prototype
    //bool ExtRowIsAtPos(T*row, int Q, int ExtRowN, int IneRowN) const;
    bool ExtRowIsAtPos(double*row, int Q, int ExtRowN, int IneRowN) const;
    //std::vector<std::vector<int>> SeekExtRow(T*row, int L) const;
    //std::vector<Int2DVectorOfSizeOrCoords> SeekExtRow(T*row, int L) const;
    //TListOfNumberPairs SeekExtRow(T*row, int L) const;
    TListOfNumberPairs SeekExtRow(double*row, int L) const;
    //bool IneRowIsAtPos(T*row, int Q, int ExtRowN, int IneRowN) const;
    bool IneRowIsAtPos(double*row, int Q, int ExtRowN, int IneRowN) const;
    //std::vector<std::vector<int>> SeekIneRow(T*row, int Q) const;
    //std::vector<Int2DVectorOfSizeOrCoords> SeekIneRow(T*row, int Q) const;
    //TListOfNumberPairs SeekIneRow(T*row, int Q) const;
    TListOfNumberPairs SeekIneRow(double*row, int Q) const;

    //bool Arr2DIsAtPos(std::vector<std::vector<T>>arr, int ExtRowN, int IneRowN, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    bool Arr2DIsAtPos(std::vector<std::vector<double>>arr, int ExtRowN, int IneRowN, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    bool Arr2DIsAtPos(Matrix_Prototype*arr, int ExtRowN, int IneRowN, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;

    //std::vector<std::vector<int>> SeekArr2D(std::vector<std::vector<T>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //std::vector<Int2DVectorOfSizeOrCoords> SeekArr2D(std::vector<std::vector<T>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //TListOfNumberPairs SeekArr2D(std::vector<std::vector<T>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    TListOfNumberPairs SeekArr2D(std::vector<std::vector<double>>arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //std::vector<std::vector<int>> SeekArr2D(Array2D_Prototype*arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //std::vector<Int2DVectorOfSizeOrCoords> SeekArr2D(Array2D_Prototype*arr, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    TListOfNumberPairs SeekArr2D(Matrix_Prototype*obj, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const;
    //
    //virtual void ConcatAdding(Matrix_Prototype*obj, T DefaultVal,int QShiftedCols=0,  TDataShiftParams*DataShiftParam=NULL, bool SetRect=true, int DfltRowL_00_11_Lmin2_Lmax3=1);
    //virtual void ConcatAdding(Matrix_Prototype*obj, int QShiftedCols=0, TDataShiftParams*DataShiftParam=NULL, T*DefaultValParam=NULL, bool SetRect=true, int DfltRowL_00_11_Lmin2_Lmax3=1);
    //
    void ConcatAdding(Matrix_Prototype*obj, int QShiftedCols=0, TDataShiftParams*DataShiftParam=NULL);
    //_ConcatStretching(T*X1, const Array2DSize& size1, T*X2, const Array2DSize& size2, T*&X3, Array2DSize& size3, T DefaultVal, int shiftQ=0, TDataShiftParams*DataShiftParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3, bool Stretch1ToMax=true, bool SetRect=true){
    //virtual void ConcatStretching(Matrix_Prototype*obj, T DefaultVal, int QShiftedExtRowNs=0,  TDataShiftParams*DataShiftParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3, bool Stretch1ToMax=true, bool SetRect=true);
    //virtual void ConcatStretching(Matrix_Prototype*obj, int QShiftedExtRowNs=0, TDataShiftParams*DataShiftParam=NULL, int DfltRowL_00_11_Lmin2_Lmax3=3, bool Stretch1ToMax=true, bool SetRect=true, T*DefaultValParam=NULL);
    void ConcatStretching(Matrix_Prototype*obj, int QShiftedCols=0, TDataShiftParams*DataShiftParam=NULL);
    //
    //virtual Matrix_Prototype*GetSubMatrix(int ExtRowN, int IneRowN, const Array2DSize& size, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const=0;
    Matrix GetSubMatrix(int ExtRowN, int IneRowN, const Array2DSize& size, bool isNotTransposed=true, bool ExtRowsSuccIsNotReversed=true, bool EachExtRowIsNotReversed=true) const=0;
    //virtual Matrix_Prototype*GetSubMatrix(TDataShiftParams*DataShiftParam=NULL) const=0;
    Matrix GetSubMatrix(TDataShiftParams*DataShiftParam=NULL) const=0;
    //
    //void ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(T val, int ExtRowN, int IneRowN, T DefaultVal, bool SetRect=true, int DfltRowL_00_11_Max2_Min3=2);
    //void ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(T val, int ExtRowN, int IneRowN, bool SetRect=true, int DfltRowL_00_11_Max2_Min3=2, T*DefaultValParam=NULL);
    //
    void ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(int ExtRowN, int IneRowN);
    void ArrayOf2DBy1D_ValSetOrAddOrFillOrIgnore(int ExtRowN, int IneRowN);
    //
    void StdCout_ExtRowN(int ExtRowN, QString ElemsDelim="; ", bool UseBrackets=true) const;
    void StdCout_IneRowN(int IneRowN, QString ElemsDelim="; ", bool UseBrackets=true, bool Represent2DNot1D=false) const;
    void StdCout(QString ElemsDelim=", ", QString RowsDelim="; ", bool UseBrackets=true, bool Represent2DNot1D=true, bool ByExtRowsNotIneRows=true) const;

    // ===== ^ Data Part ====== v Math part =====



};//Matrix//Shell


Matrix operator + (const Matrix& M1, const Matrix& M2){
    double x1, x2, x;
    int QLines1=M1.GetQLines(), QColumns1=M1.GetQColumns(), QLines=M2.GetQLines(), QColumns=M2.GetQColumns();
    Matrix MR;
    if(QLines1==QLines && QColumns1==QColumns){
        MR.SetSize(QLines, QColumns);
        for(int i=1; i<=QLines; i++){
            for(int j=1; j<=QColumns; j++){
                x1=M1.GetComponent(i, j);
                x2=M2.GetComponent(i, j);
                x=x1+x2;
                MR.SetComponent(x, i, j);
            }
        }
    }
    return MR;
}
Matrix operator - (const Matrix& M1, const Matrix& M2){
    double x1, x2, x;
    int QLines1=M1.GetQLines(), QColumns1=M1.GetQColumns(), QLines=M2.GetQLines(), QColumns=M2.GetQColumns();
    Matrix MR;
    if(QLines1==QLines && QColumns1==QColumns){
        MR.SetSize(QLines, QColumns);
        for(int i=1; i<=QLines; i++){
            for(int j=1; j<=QColumns; j++){
                x1=M1.GetComponent(i, j);
                x2=M2.GetComponent(i, j);
                x=x1-x2;
                MR.SetComponent(x, i, j);
            }
        }
    }
    return MR;
}
Matrix operator * (const Matrix& M1, const Matrix& M2){
    double x1, x2, x;
    int QLines1=M1.GetQLines(), QColumns1=M1.GetQColumns(), QLines2=M2.GetQLines(), QColumns2=M2.GetQColumns(), QLines, QColumns, QTimes;
    Matrix MR;
    if(QColumns1==QLines2){
        QColumns=QColumns2;
        QLines=QLines1;
        QTimes=QColumns1;
        MR.SetSize(QLines, QColumns);
        for(int i=1; i<=QLines; i++){
            for(int j=1; j<=QColumns; j++){
                x=0;
                for(int k=1; k<=QTimes; k++){
                    x1=M1.GetComponent(i, k);
                    x2=M2.GetComponent(k, j);
                    x+=x1*x2;
                }
                MR.SetComponent(x, i, j);
            }
        }
    }
    return MR;
}
Matrix operator / (const Matrix& M1, const Matrix& M2);

Matrix operator * (const Matrix& M, double k){
    double x1, x2;
    int QLines=M.GetQLines(), QColumns=M.GetQColumns();
    Matrix MR;
    //if(QLines1==QLines && QColumns1==QColumns){
    MR.SetSize(QLines, QColumns);
    for(int i=1; i<=QLines; i++){
        for(int j=1; j<=QColumns; j++){
            x1=M.GetComponent(i, j);
            x2=x1*k;
            MR.SetComponent(x2, i, j);
        }
    }
    //}
    return MR;
}
Matrix operator * (double k, const Matrix& M){
    double x1, x2;
    int QLines=M.GetQLines(), QColumns=M.GetQColumns();
    Matrix MR;
    //if(QLines1==QLines && QColumns1==QColumns){
    MR.SetSize(QLines, QColumns);
    for(int i=1; i<=QLines; i++){
        for(int j=1; j<=QColumns; j++){
            x1=M.GetComponent(i, j);
            x2=x1*k;
            MR.SetComponent(x2, i, j);
        }
    }
    //}
    return MR;
}

Matrix operator + (const Matrix& M, double x){
    double c;
    int QLines=M.GetQLines(), QColumns=M.GetQColumns();
    Matrix MR;
    MR.SetSize(QLines, QColumns);
    for(int i=1; i<=QLines; i++){
        for(int j=1; j<=QColumns; j++){
            c=M.GetComponent(i, j);
            MR.SetComponent(c+x, i, j);
        }
    }
    return MR;
}
Matrix operator + (double x, const Matrix& M){
    double c;
    int QLines=M.GetQLines(), QColumns=M.GetQColumns();
    Matrix MR;
    MR.SetSize(QLines, QColumns);
    for(int i=1; i<=QLines; i++){
        for(int j=1; j<=QColumns; j++){
            c=M.GetComponent(i, j);
            MR.SetComponent(c+x, i, j);
        }
    }
    return MR;
}
Matrix operator - (const Matrix& M, double x){
    double c;
    int QLines=M.GetQLines(), QColumns=M.GetQColumns();
    Matrix MR;
    MR.SetSize(QLines, QColumns);
    for(int i=1; i<=QLines; i++){
        for(int j=1; j<=QColumns; j++){
            c=M.GetComponent(i, j);
            MR.SetComponent(c-x, i, j);
        }
    }
    return MR;
}
Matrix operator - (double x, const Matrix& M){
    double c;
    int QLines=M.GetQLines(), QColumns=M.GetQColumns();
    Matrix MR;
    MR.SetSize(QLines, QColumns);
    for(int i=1; i<=QLines; i++){
        for(int j=1; j<=QColumns; j++){
            c=M.GetComponent(i, j);
            MR.SetComponent(x-c, i, j);
        }
    }
    return MR;
}

bool operator ==(const Matrix& M1, const Matrix& M2){
    bool areEqual=true;
    double x1, x2;
    int QLines1=M1.GetQLines(), QColumns1=M1.GetQColumns(), QLines2=M2.GetQLines(), QColumns2=M2.GetQColumns();
    if(QLines1==QLines && QColumns1==QColumns2){
        for(int i=1; i<=QLines1; i+){
            for(int j=1; j<=QColumns2; j+){
                x1=M1.GetComponent(i, j);
                x2=M2.GetComponent(i, j);
                if(x1!=x2){
                    areEqual=false;
                }
            }
        }
    }else{
        areEqual=false;
    }
    return areEqual;
}
bool operator !=(const Matrix& M1, const Matrix& M2){
    bool areEqual= (M1==M2);
    return (areEqual==false);
}
