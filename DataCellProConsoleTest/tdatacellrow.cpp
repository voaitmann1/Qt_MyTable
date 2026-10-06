#include "tdatacellrow.h"

#include "tdatacellrow.h"

//TDataCellRow::TDataCellRow()
//{
//
//}
//
//class TDataCellRow
//{
//    TVectorOfCells row;
//public:
    TDataCellRow::TDataCellRow(){}
    TDataCellRow:: TDataCellRow(TDataCellRow&obj){}
    TDataCellRow::TDataCellRow(TVectorOfCells cells){
        this->row=cells;
    }
    TDataCellRow::TDataCellRow(DataCell* cells, int Q){
        if(Q>0 && Q<MaxInt && cells!=NULL){
            if(!this->row.empty()) this->row.clear();
            for(int i=1; i<=Q; i++){
                this->row.push_back(cells[i-1]);
            }
        }
    }
    TDataCellRow::TDataCellRow(double*arr, int Q){
        DataCell cell;
        if(Q>0 && Q<MaxInt && arr!=NULL){
            if(!this->row.empty()) this->row.clear();
            for(int i=1; i<=Q; i++){
                cell=arr[i-1];
                this->row.push_back(cell);
            }
        }
    }
    TDataCellRow::TDataCellRow(float*arr, int Q){
        DataCell cell;
        if(Q>0 && Q<MaxInt && arr!=NULL){
            if(!this->row.empty()) this->row.clear();
            for(int i=1; i<=Q; i++){
                cell=arr[i-1];
                this->row.push_back(cell);
            }
        }
    }
    TDataCellRow::TDataCellRow(int*arr, int Q){
        DataCell cell;
        if(Q>0 && Q<MaxInt && arr!=NULL){
            if(!this->row.empty()) this->row.clear();
            for(int i=1; i<=Q; i++){
                cell=arr[i-1];
                this->row.push_back(cell);
            }
        }
    }
    TDataCellRow::TDataCellRow(bool*arr, int Q){
        DataCell cell;
        if(Q>0 && Q<MaxInt && arr!=NULL){
            if(!this->row.empty()) this->row.clear();
            for(int i=1; i<=Q; i++){
                cell=arr[i-1];
                this->row.push_back(cell);
            }
        }
    }
    TDataCellRow::TDataCellRow(QString*arr, int Q){
        DataCell cell;
        if(Q>0 && Q<MaxInt && arr!=NULL){
            if(!this->row.empty()) this->row.clear();
            for(int i=1; i<=Q; i++){
                cell=arr[i-1];
                this->row.push_back(cell);
            }
        }
    }
    //
    TDataCellRow::TDataCellRow(TDoubleVector arr){Set(arr);}
    TDataCellRow::TDataCellRow(TFloatVector arr){Set(arr);}
    TDataCellRow::TDataCellRow(TIntVector arr){Set(arr);}
    TDataCellRow::TDataCellRow(TBoolVector arr){Set(arr);}
    TDataCellRow::TDataCellRow(TStringVector arr){Set(arr);}
    //TDataCellRow::TDataCellRow(TStdStringVector arr){Set(arr);}
    //
    void TDataCellRow::Assign(TDataCellRow&obj){
        this->row=obj.row;
    }
    TDataCellRow& TDataCellRow::operator=(TDataCellRow&obj){
        Assign(obj);
        return *this;
    }
    //
    int TDataCellRow::GetSize(){
        return this->row.size();
    }
    int TDataCellRow::GetTypeN(int N){
        int TN;
        if(N>=1 && N<=this->row.size()){
            TN=this->row[N-1].GetTypeN();
        }
        return TN;
    }
    int TDataCellRow::GetLengthN(int N){
        int R;
        if(N>=1 && N<=this->row.size()){
            R=this->row[N-1].GetLength();
        }
        return R;
    }
    TypeCell* TDataCellRow::GetTypeInfoN(int N){
        TypeCell TypeInfo;
        if(N>=1 && N<=this->row.size()){
            TypeInfo.SetTypeN(this->GetTypeN(N));
            TypeInfo.SetLength(this->GetLengthN(N));
        }
        return &TypeInfo;
    }
    //
    DataCell* TDataCellRow::GetCellN(int N){
        DataCell*pcell=NULL;
        if(N>0 && N<=this->row.size()) pcell=&(this->row[N-1]);
        return pcell;
    }
    //
    void TDataCellRow::Set(TVectorOfCells cells){
        this->row=cells;
    }
    void TDataCellRow::Set(DataCell* cells, int Q){
        if(cells!=NULL && Q>0 && Q<MaxInt){
            if(!this->row.empty()) this->row.clear();
            for(int i=1; i<=Q; i++) this->row.push_back(cells[i-1]);
        }
    }
    void TDataCellRow::Set(double*arr, int Q){
        DataCell cell;
        if(arr!=NULL && Q>0 && Q<MaxInt){
            if(!this->row.empty()) this->row.clear();
            for(int i=1; i<=Q; i++){
                cell=arr[i-1];
                this->row.push_back(cell);
            }
        }
    }
    void TDataCellRow::Set(float*arr, int Q){
        DataCell cell;
        if(arr!=NULL && Q>0 && Q<MaxInt){
            if(!this->row.empty()) this->row.clear();
            for(int i=1; i<=Q; i++){
                cell=arr[i-1];
                this->row.push_back(cell);
            }
        }
    }
    void TDataCellRow::Set(int*arr, int Q){
        DataCell cell;
        if(arr!=NULL && Q>0 && Q<MaxInt){
            if(!this->row.empty()) this->row.clear();
            for(int i=1; i<=Q; i++){
                cell=arr[i-1];
                this->row.push_back(cell);
            }
        }
    }
    void TDataCellRow::Set(bool*arr, int Q){
        DataCell cell;
        if(arr!=NULL && Q>0 && Q<MaxInt){
            if(!this->row.empty()) this->row.clear();
            for(int i=1; i<=Q; i++){
                //cell=arr[i-1];
                cell.Assign(arr[i-1]);
                this->row.push_back(cell);
            }
        }
    }
    void TDataCellRow::Set(QString*arr, int Q){
        DataCell cell;
        if(arr!=NULL && Q>0 && Q<MaxInt){
            if(!this->row.empty()) this->row.clear();
            for(int i=1; i<=Q; i++){
                cell=arr[i-1];
                this->row.push_back(cell);
            }
        }
    }
    //
    //
    void TDataCellRow::Set(TDoubleVector arr){
        DataCell cell;
        int Q=arr.size();
        if(Q!=0){
            if(!this->row.empty()) this->row.clear();
            for(int i=1; i<=Q; i++){
                cell=arr[i-1];
                this->row.push_back(cell);
            }
        }
    }
    void TDataCellRow::Set(TFloatVector arr){
        DataCell cell;
        int Q=arr.size();
        if(Q!=0){
            if(!this->row.empty()) this->row.clear();
            for(int i=1; i<=Q; i++){
                cell=arr[i-1];
                this->row.push_back(cell);
            }
        }
    }
    void TDataCellRow::Set(TIntVector arr){
        DataCell cell;
        int Q=arr.size();
        if(Q!=0){
            if(!this->row.empty()) this->row.clear();
            for(int i=1; i<=Q; i++){
                cell=arr[i-1];
                this->row.push_back(cell);
            }
        }
    }
    void TDataCellRow::Set(TBoolVector arr){
        DataCell cell;
        int Q=arr.size();
        if(Q!=0){
            if(!this->row.empty()) this->row.clear();
            for(int i=1; i<=Q; i++){
                cell=arr[i-1];
                this->row.push_back(cell);
            }
        }
    }
    void TDataCellRow::Set(TStringVector arr){
        DataCell cell;
        int Q=arr.size();
        if(Q!=0){
            if(!this->row.empty()) this->row.clear();
            for(int i=1; i<=Q; i++){
                cell=arr[i-1];
                this->row.push_back(cell);
            }
        }
    }
    //void TDataCellRow::Set(TStdStringVector arr){
    //    DataCell cell;
    //    int Q=arr.size();
    //    if(Q!=0){
    //        if(!this->row.empty()) this->row.clear();
    //        for(int i=1; i<=Q; i++){
    //            cell=arr[i-1];
    //            this->row.push_back(cell);
    //        }
    //    }
    //}
    //
    void TDataCellRow::SetValAndTypeDoubleN(double val, int N){
        if(N>0 && N<=this->row.size()){
            this->row[N-1].SetValAndTypeDouble(val);
        }
    }
    void TDataCellRow::SetValAndTypeFloatN(float val, int N){
        if(N>0 && N<=this->row.size()){
            this->row[N-1].SetValAndTypeFloat(val);
        }
    }
    void TDataCellRow::SetValAndTypeIntN(int val, int N){
        if(N>0 && N<=this->row.size()){
            this->row[N-1].SetValAndTypeInt(val);
        }
    }
    void TDataCellRow::SetValAndTypeBoolN(bool val, int N){
        if(N>0 && N<=this->row.size()){
            this->row[N-1].SetValAndTypeBool(val);
        }
    }
    void TDataCellRow::SetValAndTypeStringN(QString val, int N){
        if(N>0 && N<=this->row.size()){
            this->row[N-1].SetValAndTypeString(val);
        }
    }
    //
    void TDataCellRow::SetArrAndTypeDoubleN(double* arr, int Q, int N){
        if(N>0 && N<=this->row.size()){
            this->row[N-1].SetArrAndTypeDouble(arr, Q);
        }
    }
    void TDataCellRow::SetArrAndTypeFloatN(float *arr,  int Q,int N){
        if(N>0 && N<=this->row.size()){
            this->row[N-1].SetArrAndTypeFloat(arr, Q);
        }
    }
    void TDataCellRow::SetArrAndTypeIntN(int *arr,  int Q,int N){
        if(N>0 && N<=this->row.size()){
            this->row[N-1].SetArrAndTypeInt(arr, Q);
        }
    }
    void TDataCellRow::SetArrAndTypeBoolN(bool *arr,  int Q,int N){
        if(N>0 && N<=this->row.size()){
            this->row[N-1].SetArrAndTypeBool(arr, Q);
        }
    }
    void TDataCellRow::SetArrAndTypeStringN(QString *arr,  int Q,int N){
        if(N>0 && N<=this->row.size()){
            this->row[N-1].SetArrAndTypeString(arr, Q);
        }
    }
    //
    void TDataCellRow::SetByValDoubleN(double val, int N){
            if(N>0 && N<=this->row.size()){
                this->row[N-1].SetByValDouble(val);
            }
        }
        void TDataCellRow::SetByValFloatN(float val, int N){
            if(N>0 && N<=this->row.size()){
                this->row[N-1].SetByValFloat(val);
            }
        }
        void TDataCellRow::SetByValIntN(int val, int N){
            if(N>0 && N<=this->row.size()){
                this->row[N-1].SetByValInt(val);
            }
        }
        void TDataCellRow::SetByValBoolN(bool val, int N){
            if(N>0 && N<=this->row.size()){
                this->row[N-1].SetByValBool(val);
            }
        }
        void TDataCellRow::SetByValStringN(QString val, int N){
            if(N>0 && N<=this->row.size()){
                this->row[N-1].SetByValString(val);
            }
        }
        //
        void TDataCellRow::SetByArrDoubleN(double* arr, int Q, int N){
            if(N>0 && N<=this->row.size()){
                this->row[N-1].SetByArrDouble(arr, Q);
            }
        }
        void TDataCellRow::SetByArrFloatN(float *arr,  int Q,int N){
            if(N>0 && N<=this->row.size()){
                this->row[N-1].SetByArrFloat(arr, Q);
            }
        }
        void TDataCellRow::SetByArrIntN(int *arr, int Q,int N){
            if(N>0 && N<=this->row.size()){
                this->row[N-1].SetByArrInt(arr, Q);
            }
        }
        void TDataCellRow::SetByArrBoolN(bool *arr, int Q,int N){
            if(N>0 && N<=this->row.size()){
                this->row[N-1].SetByArrBool(arr, Q);
            }
        }
        void TDataCellRow::SetByArrStringN(QString *arr, int Q,int N){
            if(N>0 && N<=this->row.size()){
                this->row[N-1].SetByArrString(arr, Q);
            }
        }
        //
        //
        void  TDataCellRow::SetBy(TDoubleVector x){
            int QMin;
            DataCell cell;
            if(this->row.size()<=x.size())QMin=this->row.size(); else QMin=x.size();
            if(this->row.size()==0){
                for(int i=1; i<=QMin; i++){
                    cell.Assign(x[i-1]);
                    this->row.push_back(cell);
                }
            }else{
                for(int i=1; i<=QMin; i++){
                    this->row[i-1].SetByValDouble(x[i-1]);
                }
            }
        }
        void  TDataCellRow::SetBy(TFloatVector x){
            int QMin;
            DataCell cell;
            if(this->row.size()<=x.size())QMin=this->row.size(); else QMin=x.size();
            if(this->row.size()==0){
                for(int i=1; i<=QMin; i++){
                    cell.Assign(x[i-1]);
                    this->row.push_back(cell);
                }
            }else{
                for(int i=1; i<=QMin; i++){
                    this->row[i-1].SetByValFloat(x[i-1]);
                }
            }
        }
        void  TDataCellRow::SetBy(TIntVector x){
            int QMin;
            DataCell cell;
            if(this->row.size()<=x.size())QMin=this->row.size(); else QMin=x.size();
            if(this->row.size()==0){
                for(int i=1; i<=QMin; i++){
                    cell.Assign(x[i-1]);
                    this->row.push_back(cell);
                }
            }else{
                for(int i=1; i<=QMin; i++){
                    this->row[i-1].SetByValInt(x[i-1]);
                }
            }
        }
        void  TDataCellRow::SetBy(TBoolVector x){
            int QMin;
            DataCell cell;
            if(this->row.size()<=x.size())QMin=this->row.size(); else QMin=x.size();
            if(this->row.size()==0){
                for(int i=1; i<=QMin; i++){
                    cell.Assign(x[i-1]);
                    this->row.push_back(cell);
                }
            }else{
                for(int i=1; i<=QMin; i++){
                    this->row[i-1].SetByValBool(x[i-1]);
                }
            }
        }
        void  TDataCellRow::SetBy(TStringVector x){
            int QMin;
            DataCell cell;
            if(this->row.size()<=x.size())QMin=this->row.size(); else QMin=x.size();
            if(this->row.size()==0){
                for(int i=1; i<=QMin; i++){
                    cell.Assign(x[i-1]);
                    this->row.push_back(cell);
                }
            }else{
                for(int i=1; i<=QMin; i++){
                    this->row[i-1].SetByValString(x[i-1]);
                }
            }
        }
        //void  TDataCellRow::SetBy(TStdStringVector x){}
        //
        //
        double TDataCellRow::GetDoubleValN(int CellN){
            double y=0;
            if(CellN>0 && CellN<=this->row.size()) y=this->row[CellN-1].GetDoubleVal();
            return y;
        }
        float TDataCellRow::GetFloatValN(int CellN){
            float y=0;
            if(CellN>0 && CellN<=this->row.size()) y=this->row[CellN-1].GetFloatVal();
            return y;
        }
        int TDataCellRow::GetIntValN(int CellN){
            int y=0;
            if(CellN>0 && CellN<=this->row.size()) y=this->row[CellN-1].GetIntVal();
            return y;
        }
        bool TDataCellRow::GetBoolValN(int CellN){
            bool y;
            if(CellN>0 && CellN<=this->row.size()) y=this->row[CellN-1].GetBoolVal();
            return y;
        }
        QString TDataCellRow::ToStringN(int CellN){
            QString y="";
            if(CellN>0 && CellN<=this->row.size()) y=this->row[CellN-1].ToString();
            return y;
        }
        //
        double TDataCellRow::GetDoubleValNN(int CellN, int ValN){
            double y=0;
            if(CellN>0 && CellN<=this->row.size()) y=this->row[CellN-1].GetDoubleValN(ValN);
            return y;
        }
        float TDataCellRow::GetFloatValNN(int CellN, int ValN){
            float y=0;
            if(CellN>0 && CellN<=this->row.size()) y=this->row[CellN-1].GetFloatValN(ValN);
            return y;
        }
        int TDataCellRow::GetIntValNN(int CellN, int ValN){
            int y=0;
            if(CellN>0 && CellN<=this->row.size()) y=this->row[CellN-1].GetIntValN(ValN);
            return y;
        }
        bool TDataCellRow::GetBoolValNN(int CellN, int ValN){
            bool y;
            if(CellN>0 && CellN<=this->row.size()) y=this->row[CellN-1].GetBoolValN(ValN);
            return y;
        }
        QString TDataCellRow::ToStringNN(int CellN, int ValN){
            QString y="";
            if(CellN>0 && CellN<=this->row.size()) y=this->row[CellN-1].ToStringN(ValN);
            return y;
        }
        //
        void TDataCellRow::GetDoubleArrN(double*&arr, int&Length, int N){
            if(N>0 && N<=this->row.size()){
                this->row[N-1].GetDoubleArr(arr, Length);
            }
        }
        void TDataCellRow::GetFloatArrN(float*&arr, int&Length, int N){
            if(N>0 && N<=this->row.size()){
                this->row[N-1].GetFloatArr(arr, Length);
            }
        }
        void TDataCellRow::GetIntArrN(int*&arr, int&Length, int N){
            if(N>0 && N<=this->row.size()){
                this->row[N-1].GetIntArr(arr, Length);
            }
        }
        void TDataCellRow::GetBoolArrN(bool*&arr, int&Length, int N){
            if(N>0 && N<=this->row.size()){
                this->row[N-1].GetBoolArr(arr, Length);
            }
        }
        void TDataCellRow::GetStringArrN(QString*&arr, int&Length, int N){
            if(N>0 && N<=this->row.size()){
                this->row[N-1].ToStringArr(arr, Length);
            }
        }
        //
        void TDataCellRow::ReturnAsDoubleArrByActiveValsOfCells(double arr[], int&QCells){
            QCells=this->row.size();
            //if(arr!=NULL)delete[]arr;
            //arr=new double[QCells];
            for(int i=1; i<=QCells; i++){
                arr[i-1]=this->row[i-1].GetDoubleVal();
            }
        }
        void TDataCellRow::ReturnAsFloatArrByActiveValsOfCells(float arr[], int&QCells){
            QCells=this->row.size();
            //if(arr!=NULL)delete[]arr;
            //arr=new double[QCells];
            for(int i=1; i<=QCells; i++){
                arr[i-1]=this->row[i-1].GetFloatVal();
            }
        }
        void TDataCellRow::ReturnAsIntArrByActiveValsOfCells(int arr[], int&QCells){
            QCells=this->row.size();
            //if(arr!=NULL)delete[]arr;
            //arr=new double[QCells];
            for(int i=1; i<=QCells; i++){
                arr[i-1]=this->row[i-1].GetIntVal();
            }
        }
        void TDataCellRow::ReturnAsBoolArrByActiveValsOfCells(bool arr[], int&QCells){
            QCells=this->row.size();
            //if(arr!=NULL)delete[]arr;
            //arr=new double[QCells];
            for(int i=1; i<=QCells; i++){
                arr[i-1]=this->row[i-1].GetBoolVal();
            }
        }
        void TDataCellRow::ReturnAsStringArrByActiveValsOfCells(QString arr[], int&QCells){
            QCells=this->row.size();
            //if(arr!=NULL)delete[]arr;
            //arr=new double[QCells];
            for(int i=1; i<=QCells; i++){
                arr[i-1]=this->row[i-1].ToString();
            }
        }
        //
        void TDataCellRow::SetN(DataCell*cell, int N){
            if(N>0 && N<=this->row.size() && cell!=NULL){
                this->row[N-1]=(*(cell));
            }
        }
        void TDataCellRow::Add(DataCell*cell){
            if(cell!=NULL) this->row.push_back((*cell));
        }
        void TDataCellRow::Ins(DataCell*cell, int N){
             if(N>0 && N<=this->row.size() && cell!=NULL) this->row.insert(this->row.begin()+N-1, *cell);
        }
        void TDataCellRow::Del(int N){
            if(N>0 && N<=this->row.size() ) this->row.erase(this->row.begin()+N-1);

        }
        //
        QString TDataCellRow::GetAsStringSimple(QString Separator){
            QString WholeRow="", snglCell;
            int L=this->row.size();
            for(int i=1; i<=L-1; i++){
                snglCell=this->row[i-1].ToString()+Separator;
                WholeRow=WholeRow+snglCell;
            }
            if(L>0){
                snglCell=this->row[L-1].ToString();
                WholeRow=WholeRow+snglCell;
            }
            return WholeRow;
        }
        //
        TDoubleVector TDataCellRow::TDataCellRow::GetAsDoubleVector(){
            int L;
            TDoubleVector R;
            L=this->row.size();
            if(L>0){
                for(int i=1; i<=L; i++){
                    R.push_back(this->row[i-1].GetDoubleVal());
                }
            }
            return R;
        }
        TFloatVector TDataCellRow::GetAsFloatVector(){
            int L;
            TFloatVector R;
            L=this->row.size();
            if(L>0){
                for(int i=1; i<=L; i++){
                    R.push_back(this->row[i-1].GetFloatVal());
                }
            }
            return R;
        }
        TIntVector TDataCellRow::GetAsIntVector(){
            int L;
            TIntVector R;
            L=this->row.size();
            if(L>0){
                for(int i=1; i<=L; i++){
                    R.push_back(this->row[i-1].GetIntVal());
                }
            }
            return R;
        }
        TBoolVector TDataCellRow::GetAsBoolVector(){
            int L;
            TBoolVector R;
            L=this->row.size();
            if(L>0){
                for(int i=1; i<=L; i++){
                    R.push_back(this->row[i-1].GetBoolVal());
                }
            }
            return R;
        }
        TStringVector TDataCellRow::GetAsStringVector(){
            int L;
            TStringVector R;
            L=this->row.size();
            if(L>0){
                for(int i=1; i<=L; i++){
                    R.push_back(this->row[i-1].ToString());
                }
            }
            return R;
        }
        //
        TVectorOfCells TDataCellRow::GetCells(){return this->row;}
        //
        void  TDataCellRow::SetNull(){this->row.clear();}


//};

//===============================================================================================================
        TDataCellRow_WithHeader::TDataCellRow_WithHeader(DataCell* Hdr, TDataCellRow row){
            this->Header=Hdr;
            this->row=row.GetCells();
        }
//----------------------------------------------------------------------------------------------------------------
        TDataCellRow* TDataCellRow_WithHeader::GetContent(){
            TDataCellRow *Row=NULL, row;
            if(!this->row.empty()){
                for(int i=1; i<=this->row.size(); i++){
                    row.Add((&(this->row.at(i-1))));
                }
                Row=&row;
            }
            return Row;
        }

        void  TDataCellRow_WithHeader::SetBy(TDoubleVector x){
                int QMin;
                DataCell cell;
                if(this->row.size()<=x.size())QMin=this->row.size(); else QMin=x.size();
                if(this->row.size()==0){
                    for(int i=1; i<=QMin; i++){
                        cell.Assign(x[i-1]);
                        this->row.push_back(cell);
                    }
                }else{
                    for(int i=1; i<=QMin; i++){
                        this->row[i-1].SetByValDouble(x[i-1]);
                    }
                }
            }
            void  TDataCellRow_WithHeader::SetBy(TFloatVector x){
                int QMin;
                DataCell cell;
                if(this->row.size()<=x.size())QMin=this->row.size(); else QMin=x.size();
                if(this->row.size()==0){
                    for(int i=1; i<=QMin; i++){
                        cell.Assign(x[i-1]);
                        this->row.push_back(cell);
                    }
                }else{
                    for(int i=1; i<=QMin; i++){
                        this->row[i-1].SetByValFloat(x[i-1]);
                    }
                }
            }
            void  TDataCellRow_WithHeader::SetBy(TIntVector x){
                int QMin;
                DataCell cell;
                if(this->row.size()<=x.size())QMin=this->row.size(); else QMin=x.size();
                if(this->row.size()==0){
                    for(int i=1; i<=QMin; i++){
                        cell.Assign(x[i-1]);
                        this->row.push_back(cell);
                    }
                }else{
                    for(int i=1; i<=QMin; i++){
                        this->row[i-1].SetByValInt(x[i-1]);
                    }
                }
            }
            void  TDataCellRow_WithHeader::SetBy(TBoolVector x){
                int QMin;
                DataCell cell;
                if(this->row.size()<=x.size())QMin=this->row.size(); else QMin=x.size();
                if(this->row.size()==0){
                    for(int i=1; i<=QMin; i++){
                        cell.Assign(x[i-1]);
                        this->row.push_back(cell);
                    }
                }else{
                    for(int i=1; i<=QMin; i++){
                        this->row[i-1].SetByValBool(x[i-1]);
                    }
                }
            }
            void  TDataCellRow_WithHeader::SetBy(TStringVector x){
                int QMin;
                DataCell cell;
                if(this->row.size()<=x.size())QMin=this->row.size(); else QMin=x.size();
                if(this->row.size()==0){
                    for(int i=1; i<=QMin; i++){
                        cell.Assign(x[i-1]);
                        this->row.push_back(cell);
                    }
                }else{
                    for(int i=1; i<=QMin; i++){
                        this->row[i-1].SetByValString(x[i-1]);
                    }
                }
            }
            //void  TDataCellRow_WithHeader::SetBy(TStdStringVector x){}
            //
            //
            double TDataCellRow_WithHeader::GetDoubleValN(int CellN){
                double y=0;
                if(CellN>0 && CellN<=this->row.size()) y=this->row[CellN-1].GetDoubleVal();
                return y;
            }
            float TDataCellRow_WithHeader::GetFloatValN(int CellN){
                float y=0;
                if(CellN>0 && CellN<=this->row.size()) y=this->row[CellN-1].GetFloatVal();
                return y;
            }
            int TDataCellRow_WithHeader::GetIntValN(int CellN){
                int y=0;
                if(CellN>0 && CellN<=this->row.size()) y=this->row[CellN-1].GetIntVal();
                return y;
            }
            bool TDataCellRow_WithHeader::GetBoolValN(int CellN){
                bool y;
                if(CellN>0 && CellN<=this->row.size()) y=this->row[CellN-1].GetBoolVal();
                return y;
            }
            QString TDataCellRow_WithHeader::ToStringN(int CellN){
                QString y="";
                if(CellN>0 && CellN<=this->row.size()) y=this->row[CellN-1].ToString();
                return y;
            }
            //
            double TDataCellRow_WithHeader::GetDoubleValNN(int CellN, int ValN){
                double y=0;
                if(CellN>0 && CellN<=this->row.size()) y=this->row[CellN-1].GetDoubleValN(ValN);
                return y;
            }
            float TDataCellRow_WithHeader::GetFloatValNN(int CellN, int ValN){
                float y=0;
                if(CellN>0 && CellN<=this->row.size()) y=this->row[CellN-1].GetFloatValN(ValN);
                return y;
            }
            int TDataCellRow_WithHeader::GetIntValNN(int CellN, int ValN){
                int y=0;
                if(CellN>0 && CellN<=this->row.size()) y=this->row[CellN-1].GetIntValN(ValN);
                return y;
            }
            bool TDataCellRow_WithHeader::GetBoolValNN(int CellN, int ValN){
                bool y;
                if(CellN>0 && CellN<=this->row.size()) y=this->row[CellN-1].GetBoolValN(ValN);
                return y;
            }
            QString TDataCellRow_WithHeader::ToStringNN(int CellN, int ValN){
                QString y="";
                if(CellN>0 && CellN<=this->row.size()) y=this->row[CellN-1].ToStringN(ValN);
                return y;
            }
            //
            void TDataCellRow_WithHeader::GetDoubleArrN(double*&arr, int&Length, int N){
                if(N>0 && N<=this->row.size()){
                    this->row[N-1].GetDoubleArr(arr, Length);
                }
            }
            void TDataCellRow_WithHeader::GetFloatArrN(float*&arr, int&Length, int N){
                if(N>0 && N<=this->row.size()){
                    this->row[N-1].GetFloatArr(arr, Length);
                }
            }
            void TDataCellRow_WithHeader::GetIntArrN(int*&arr, int&Length, int N){
                if(N>0 && N<=this->row.size()){
                    this->row[N-1].GetIntArr(arr, Length);
                }
            }
            void TDataCellRow_WithHeader::GetBoolArrN(bool*&arr, int&Length, int N){
                if(N>0 && N<=this->row.size()){
                    this->row[N-1].GetBoolArr(arr, Length);
                }
            }
            void TDataCellRow_WithHeader::GetStringArrN(QString*&arr, int&Length, int N){
                if(N>0 && N<=this->row.size()){
                    this->row[N-1].ToStringArr(arr, Length);
                }
            }
            //
            void TDataCellRow_WithHeader::ReturnAsDoubleArrByActiveValsOfCells(double arr[], int&QCells){
                QCells=this->row.size();
                //if(arr!=NULL)delete[]arr;
                //arr=new double[QCells];
                for(int i=1; i<=QCells; i++){
                    arr[i-1]=this->row[i-1].GetDoubleVal();
                }
            }
            void TDataCellRow_WithHeader::ReturnAsFloatArrByActiveValsOfCells(float arr[], int&QCells){
                QCells=this->row.size();
                //if(arr!=NULL)delete[]arr;
                //arr=new double[QCells];
                for(int i=1; i<=QCells; i++){
                    arr[i-1]=this->row[i-1].GetFloatVal();
                }
            }
            void TDataCellRow_WithHeader::ReturnAsIntArrByActiveValsOfCells(int arr[], int&QCells){
                QCells=this->row.size();
                //if(arr!=NULL)delete[]arr;
                //arr=new double[QCells];
                for(int i=1; i<=QCells; i++){
                    arr[i-1]=this->row[i-1].GetIntVal();
                }
            }
            void TDataCellRow_WithHeader::ReturnAsBoolArrByActiveValsOfCells(bool arr[], int&QCells){
                QCells=this->row.size();
                //if(arr!=NULL)delete[]arr;
                //arr=new double[QCells];
                for(int i=1; i<=QCells; i++){
                    arr[i-1]=this->row[i-1].GetBoolVal();
                }
            }
            void TDataCellRow_WithHeader::ReturnAsStringArrByActiveValsOfCells(QString arr[], int&QCells){
                QCells=this->row.size();
                //if(arr!=NULL)delete[]arr;
                //arr=new double[QCells];
                for(int i=1; i<=QCells; i++){
                    arr[i-1]=this->row[i-1].ToString();
                }
            }
            //
            void TDataCellRow_WithHeader::SetN(DataCell*cell, int N){
                if(N>0 && N<=this->row.size() && cell!=NULL){
                    this->row[N-1]=(*(cell));
                }
            }
            void TDataCellRow_WithHeader::Add(DataCell*cell){
                if(cell!=NULL) this->row.push_back((*cell));
            }
            void TDataCellRow_WithHeader::Ins(DataCell*cell, int N){
                 if(N>0 && N<=this->row.size() && cell!=NULL) this->row.insert(this->row.begin()+N-1, *cell);
            }
            void TDataCellRow_WithHeader::Del(int N){
                if(N>0 && N<=this->row.size() ) this->row.erase(this->row.begin()+N-1);

            }
            //
            QString TDataCellRow_WithHeader::GetAsStringSimple(QString Separator, QString SeparatorBetweenHeaderAndContent){
                QString WholeRow="", snglCell;
                //  int X;
                int L=this->row.size();
                WholeRow=this->Header.ToString()+SeparatorBetweenHeaderAndContent;
                for(int i=1; i<=L-1; i++){
                    snglCell=this->row[i-1].ToString()+Separator;
                    WholeRow=WholeRow+snglCell;
                }
                if(L>0){
                    snglCell=this->row[L-1].ToString();
                    WholeRow=WholeRow+snglCell;
                }
                return WholeRow;
            }
            //
            TDoubleVector TDataCellRow_WithHeader::GetAsDoubleVector(){
                int L;
                TDoubleVector R;
                L=this->row.size();
                if(L>0){
                    for(int i=1; i<=L; i++){
                        R.push_back(this->row[i-1].GetDoubleVal());
                    }
                }
                return R;
            }
            TFloatVector TDataCellRow_WithHeader::GetAsFloatVector(){
                int L;
                TFloatVector R;
                L=this->row.size();
                if(L>0){
                    for(int i=1; i<=L; i++){
                        R.push_back(this->row[i-1].GetFloatVal());
                    }
                }
                return R;
            }
            TIntVector TDataCellRow_WithHeader::GetAsIntVector(){
                int L;
                TIntVector R;
                L=this->row.size();
                if(L>0){
                    for(int i=1; i<=L; i++){
                        R.push_back(this->row[i-1].GetIntVal());
                    }
                }
                return R;
            }
            TBoolVector TDataCellRow_WithHeader::GetAsBoolVector(){
                int L;
                TBoolVector R;
                L=this->row.size();
                if(L>0){
                    for(int i=1; i<=L; i++){
                        R.push_back(this->row[i-1].GetBoolVal());
                    }
                }
                return R;
            }
                //
                QString GetAsStringSimple(QString SeparatorOfContents="; ", QString SeparatorBetweenHdrAndCnt=": ");
        //  };
