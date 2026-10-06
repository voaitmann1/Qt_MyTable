#include "datacell.h"

//class TCellDouble: TDataCell
//{
//    double val;
//    :
//datacell.cpp

#include "datacell.h"

//class TCellDouble: TDataCell
//{
//    double val;
//    :
    TCellDouble::TCellDouble() { this->val = 0; }
    TCellDouble::TCellDouble(double val) { SetByValDouble(val); }
    TCellDouble::TCellDouble(float val) { SetByValFloat(val); }
    TCellDouble::TCellDouble(int val) { SetByValInt(val); }
    TCellDouble::TCellDouble(bool val) { SetByValBool(val); }
    TCellDouble::TCellDouble(QString val) { SetByValString(val); }
    //
    TCellDouble::TCellDouble(double* val, int Q) { SetByArrDouble(val, Q); }
    TCellDouble::TCellDouble(float* val, int Q) { SetByArrFloat(val, Q); }
    TCellDouble::TCellDouble(int* val, int Q) { SetByArrInt(val, Q); }
    TCellDouble::TCellDouble(bool* val, int Q) { SetByArrBool(val, Q); }
    TCellDouble::TCellDouble(QString* val, int Q) { SetByArrString(val, Q); }
    //
    //hope they will not be needed
//    TCellDouble(TCellDouble&obj){
//        this->Assign(obj);
//    }
//    //
//    TCellDouble& operator =(TCellDouble&obj){
//        this->Assign(obj);
//        return*this;
//    }
//    //
//    void Assign(TCellDouble&obj){
//        this->data=obj.data;
//    }
    void TCellDouble::construct(int n){
        this->val=0;
    }


    int TCellDouble::GetTypeN() { return DoubleTypeN; }
    int TCellDouble::GetActiveN() { return 1;}
    void TCellDouble::SetActiveN(int N) { }
    int TCellDouble::GetLength() { return 1; }
    void TCellDouble::SetLength(int L){}
    //
    double TCellDouble::GetDoubleVal() { return val; }
    float TCellDouble::GetFloatVal() {
        float r;
        r = (float)val;
        return r;
    }
    int TCellDouble::GetIntVal()
    {
        int r;
        r =(int) round(val);
        return r;
    }
    bool TCellDouble::GetBoolVal() {
        bool r;
        if(BoolValByDefault==true){
            if (val == 0) r = false;
            else r = true;
        }else{
            if (val == 1) r = true;
            else r = false;
        }
        return r;
    }
    QString TCellDouble::ToString() {
        QString s;
        s=RealToString(val);
        s.setNum(val);
        return s;//val.ToString();
    }
    //
    double TCellDouble::GetDoubleValN(int N) { return val; }
    float TCellDouble::GetFloatValN(int N) { return (float)val; }
    int TCellDouble::GetIntValN(int N)
    {
        int r;
        r = (int)round(val);
        return r;
    }
    bool TCellDouble::GetBoolValN(int N)
    {
        bool r;
        if(BoolValByDefault==true){
            if (val == 0) r = false;
            else r = true;
        }else{
            if (val == 1) r = true;
            else r = false;
        }
        return r;
    }
    QString TCellDouble::ToStringN(int N) {
        QString s;
        //QString RealToString(double x, int Repr_IntAndFrac0_ExpAfOrderLim1_ExpAnyhow2=0,  int QAftComma=6, int OrdAfWhichExp=6, int BaseDec=10);
        s=RealToString(val);
        s.setNum(val);
        return s;
    }
    //
    void TCellDouble::SetByValDouble(double val) { this->val = (double)val; }
    void TCellDouble::SetByValFloat(float val) { this->val = (double)val; }
    void TCellDouble::SetByValInt(int val) { this->val = (double)val; }
    void TCellDouble::SetByValBool(bool val)
    {
        int i;
        i = BoolToInt(val);
        this->val=(double)i;
    }
    void TCellDouble::SetByValString(QString val) {
        //this->val = Convert.ToDouble(val);
        //this->val = NumberParse.StrToFloat(val);
        this->val=StrToReal(val);
        this->val =val.toDouble();
    } //hin S' ne abl convert!!
    //
    void TCellDouble::SetByValDoubleN(double val, int N) { SetByValDouble(val); }
    void TCellDouble::SetByValFloatN(float val, int N) { SetByValFloat(val); }
    void TCellDouble::SetByValIntN(int val, int N) { SetByValInt(val); }
    void TCellDouble::SetByValBoolN(bool val, int N) { SetByValBool(val); }
    void TCellDouble::SetByValStringN(QString val, int N) { SetByValString(val); }
    //
    void TCellDouble::SetVal(double val) { this->val = (double)val; }
    void TCellDouble::SetVal(int val) { this->val = (double)val; }
    void TCellDouble::SetVal(bool val)
    {
        int i;
        i = BoolToInt(val);
        this->val = (double)i;
    }
    void TCellDouble::SetVal(QString val) {
        //this->val = Convert.ToDouble(val);
        this->val=StrToReal(val);
        this->val=val.toDouble();
    }
    //
    void TCellDouble::SetValN(double val, int N) { SetVal(val); }
    void TCellDouble::SetValN(int val, int N) { SetVal(val); }
    void TCellDouble::SetValN(bool val, int N) { SetVal(val); }
    void TCellDouble::SetValN(QString val, int N) { SetVal(val); }
    //
    void TCellDouble::SetByArrDouble(double* val, int Q){
       if(val!=NULL)SetByValDouble(val[1-1]);
       else SetByValDouble(0);
    }
    void TCellDouble::SetByArrFloat(float* val, int Q)
    {
        if (val != NULL) SetByValFloat(val[1 - 1]);
        else SetByValFloat(0);
    }
    void TCellDouble::SetByArrInt(int* val, int Q)
    {
        if (val != NULL) SetByValInt(val[1 - 1]);
        else SetByValInt(0);
    }
    void TCellDouble::SetByArrBool(bool* val, int Q)
    {
        if (val != NULL) SetByValBool(val[1 - 1]);
        else SetByValBool(BoolValByDefault);
    }
    void TCellDouble::SetByArrString(QString* val, int Q)
    {
        if (val != NULL) SetByValString(val[1 - 1]);
        else SetByValString("");
    }
    //
    void TCellDouble::SetByArr(double* val, int Q){
        if(val!=NULL)SetByValDouble(val[1-1]);
        else SetByValDouble(0);
    }
    void TCellDouble::SetByArr(int* val, int Q)
    {
        if (val != NULL) SetByValInt(val[1 - 1]);
        else SetByValInt(0);
    }
    void TCellDouble::SetByArr(bool* val, int Q)
    {
        if (val != NULL) SetByValBool(val[1 - 1]);
        else SetByValBool(BoolValByDefault);
    }
    void TCellDouble::SetByArr(QString* val, int Q)
    {
        if (val != NULL) SetByValString(val[1 - 1]);
        else SetByValString("");
    }
    //
    void TCellDouble::AddOrInsDoubleVal(double val, int N)
    {
        this->val = val;
    }
    void TCellDouble::AddOrInsFloatVal(float val, int N)
    {
        this->val = (double)val;
    }
    void TCellDouble::AddOrInsIntVal(int val, int N)
    {
        this->val = (double)val;
    }
    void TCellDouble::AddOrInsBoolVal(bool val, int N)
    {
        this->val = (double) BoolToInt(val);
    }
    void TCellDouble::AddOrInsStringVal(QString val, int N)
    {
        this->val=StrToReal(val, NULL, 10);
        //this->val.SetNum(val);// Convert.ToDouble(val);
    }
    //
    void TCellDouble::DelValN(int N) { }
    //
    void TCellDouble::GetDoubleArr(double*&Arr,  int&QItems) {
        QItems=1;
        Arr = new double[QItems];
        Arr[1 - 1] = GetDoubleVal();
    }
    void TCellDouble::GetFloatArr( float*&Arr, int&QItems) {
        QItems = 1;
        Arr = new float[QItems];
        Arr[1 - 1] = GetFloatVal();
    }
    void TCellDouble::GetIntArr( int*&Arr,  int&QItems) {
        QItems = 1;
        Arr = new int[QItems];
        Arr[1 - 1] = GetIntVal();
    }
    void TCellDouble::GetBoolArr( bool*&Arr,  int&QItems) {
        QItems = 1;
        Arr = new bool[QItems];
        Arr[1 - 1] = GetBoolVal();
    }
    void TCellDouble::ToStringArr(QString*&Arr, int&QItems) {
        QItems = 1;
        if(Arr!=NULL)delete[]Arr;
        Arr = new QString[QItems];
        Arr[1 - 1] = ToString();
    }
    //
    void TCellDouble::SetNameN(QString name, int N) { SetByValStringN(name, N);  }
    void TCellDouble::SetName1(QString name) { SetByValStringN(name, 1); }
    void TCellDouble::SetName2(QString name) { SetByValStringN(name, 2); }
    //void TCellDouble::SetName3(QString name) { SetByValStringN(name, 3); }
    //void TCellDouble::SetNames(QString* Arr, int Q) { SetByArrString(Arr, Q); }
    QString TCellDouble::GetNameN(int N) { return ToStringN(N); }
    QString TCellDouble::GetName() { return ToString(); }
    QString TCellDouble::GetName1() { return ToStringN(1); }
    QString TCellDouble::GetName2() { return ToStringN(2); }
    //QString TCellDouble::GetName3() { return ToStringN(3); }
    //void TCellDouble::GetNames(QString*&Arr, int&QItems) { ToStringArr(Arr, QItems); }
    //int TCellDouble::GetLengthOfNamesList() { return 1; }
    //
    void TCellDouble::SetItems(QString*items, int Q, int ActiveN){
        if(items!=NULL){
            this->val=items[1-1].toDouble();
        }
    }
    void TCellDouble::GetItems(QString*&items, int&Q){
        if(items!=NULL){
            delete[]items;
        }
        items=new QString[1];
        items[1-1]=FloatToStr(this->val);
    }
    void TCellDouble::SetItem(QString item, int itemN){
        if(itemN==1 || itemN==-1){
            this->val=item.toDouble();//better own fn
        }
    }
    void TCellDouble::InsItem(QString item, int itemN){}
    void TCellDouble::AddItem(QString item){}
    void TCellDouble::DelItem(int itemN){}
    QString TCellDouble::GetItem(int itemN){
       QString R="0";
        if(itemN==1 || itemN==-1){
            R.setNum(this->val);
        }
        return R;
    }
    int TCellDouble::GetLengthOfItemsList(){ return 0; }
    //
    //
//     override object Clone(){
//        return new TCellDouble(this->GetDoubleVal());
//    }
//};//cl


    //class TCellFloat: TDataCell
    //{
    //    double val;
    //    :
        TCellFloat::TCellFloat() { this->val = 0; }
        TCellFloat::TCellFloat(double val) { SetByValDouble(val); }
        TCellFloat::TCellFloat(float val) { SetByValFloat(val); }
        TCellFloat::TCellFloat(int val) { SetByValInt(val); }
        TCellFloat::TCellFloat(bool val) { SetByValBool(val); }
        TCellFloat::TCellFloat(QString val) { SetByValString(val); }
        //
        TCellFloat::TCellFloat(double* val, int Q) { SetByArrDouble(val, Q); }
        TCellFloat::TCellFloat(float* val, int Q) { SetByArrFloat(val, Q); }
        TCellFloat::TCellFloat(int* val, int Q) { SetByArrInt(val, Q); }
        TCellFloat::TCellFloat(bool* val, int Q) { SetByArrBool(val, Q); }
        TCellFloat::TCellFloat(QString* val, int Q) { SetByArrString(val, Q); }
        //
        //hope they will not be needed
    //    TCellFloat(TCellFloat&obj){
    //        this->Assign(obj);
    //    }
    //    //
    //    TCellFloat& operator =(TCellFloat&obj){
    //        this->Assign(obj);
    //        return*this;
    //    }
    //    //
    //    void Assign(TCellFloat&obj){
    //        this->data=obj.data;
    //    }
        void TCellFloat::construct(int n){
            this->val=0;
        }
        int TCellFloat::GetTypeN() { return FloatTypeN; }
        int TCellFloat::GetActiveN() { return 1;}
        void TCellFloat::SetActiveN(int N) { }
        int TCellFloat::GetLength() { return 1; }
        void TCellFloat::SetLength(int L){}
        //
        double TCellFloat::GetDoubleVal(){
            double r;
            r = (double)val;
            return r;
        }
        float TCellFloat::GetFloatVal() {
//            float r;
//            r = (float)val;
            return val;
//            return r;
        }
        int TCellFloat::GetIntVal()
        {
            int r;
            r =(int) round(val);
            return r;
        }
        bool TCellFloat::GetBoolVal() {
            bool r;
            if(BoolValByDefault==true){
                if (val == 0) r = false;
                else r = true;
            }else{
                if (val == 1) r = true;
                else r = false;
            }
            return r;
        }
        QString TCellFloat::ToString() {
            QString s;
            s=RealToString(val);
            s.setNum(val);
            return s;//val.ToString();
        }
        //
        double TCellFloat::GetDoubleValN(int N) { return (double)val; }
        float TCellFloat::GetFloatValN(int N) { return val; }
        int TCellFloat::GetIntValN(int N)
        {
            int r;
            r = (int)round(val);
            return r;
        }
        bool TCellFloat::GetBoolValN(int N)
        {
            bool r;
            if(BoolValByDefault==true){
                if (val == 0) r = false;
                else r = true;
            }else{
                if (val == 1) r = true;
                else r = false;
            }
            return r;
        }
        QString TCellFloat::ToStringN(int N) {
            QString s;
            //QString RealToString(double x, int Repr_IntAndFrac0_ExpAfOrderLim1_ExpAnyhow2=0,  int QAftComma=6, int OrdAfWhichExp=6, int BaseDec=10);
            s=RealToString(val);
            s.setNum(val);
            return s;
        }
        //
        void TCellFloat::SetByValDouble(double val) { this->val = (float)val; }
        void TCellFloat::SetByValFloat(float val) { this->val = (float)val; }
        void TCellFloat::SetByValInt(int val) { this->val = (float)val; }
        void TCellFloat::SetByValBool(bool val)
        {
            int i;
            i = BoolToInt(val);
            this->val=(float)i;
        }
        void TCellFloat::SetByValString(QString val) {
            //this->val = Convert.ToDouble(val);
            //this->val = NumberParse.StrToFloat(val);
            this->val=(float)StrToReal(val);
            this->val =val.toFloat();
        } //hin S' ne abl convert!!
        //
        void TCellFloat::SetByValDoubleN(double val, int N) { SetByValDouble(val); }
        void TCellFloat::SetByValFloatN(float val, int N) { SetByValFloat(val); }
        void TCellFloat::SetByValIntN(int val, int N) { SetByValInt(val); }
        void TCellFloat::SetByValBoolN(bool val, int N) { SetByValBool(val); }
        void TCellFloat::SetByValStringN(QString val, int N) { SetByValString(val); }
        //
        void TCellFloat::SetVal(double val) { this->val = (float)val; }
        void TCellFloat::SetVal(int val) { this->val = (float)val; }
        void TCellFloat::SetVal(bool val)
        {
            int i;
            i = BoolToInt(val);
            this->val = (double)i;
        }
        void TCellFloat::SetVal(QString val) {
            //this->val = Convert.ToDouble(val);
            this->val=(float)StrToReal(val);
            this->val=val.toFloat();
        }
        //
        void TCellFloat::SetValN(double val, int N) { SetVal(val); }
        void TCellFloat::SetValN(int val, int N) { SetVal(val); }
        void TCellFloat::SetValN(bool val, int N) { SetVal(val); }
        void TCellFloat::SetValN(QString val, int N) { SetVal(val); }
        //
        void TCellFloat::SetByArrDouble(double* val, int Q){
           if(val!=NULL)SetByValDouble(val[1-1]);
           else SetByValDouble(0);
        }
        void TCellFloat::SetByArrFloat(float* val, int Q)
        {
            if (val != NULL) SetByValFloat(val[1 - 1]);
            else SetByValFloat(0);
        }
        void TCellFloat::SetByArrInt(int* val, int Q)
        {
            if (val != NULL) SetByValInt(val[1 - 1]);
            else SetByValInt(0);
        }
        void TCellFloat::SetByArrBool(bool* val, int Q)
        {
            if (val != NULL) SetByValBool(val[1 - 1]);
            else SetByValBool(BoolValByDefault);
        }
        void TCellFloat::SetByArrString(QString* val, int Q)
        {
            if (val != NULL) SetByValString(val[1 - 1]);
            else SetByValString("");
        }
        //
        void TCellFloat::SetByArr(double* val, int Q){
            if(val!=NULL)SetByValDouble(val[1-1]);
            else SetByValDouble(0);
        }
        void TCellFloat::SetByArr(int* val, int Q)
        {
            if (val != NULL) SetByValInt(val[1 - 1]);
            else SetByValInt(0);
        }
        void TCellFloat::SetByArr(bool* val, int Q)
        {
            if (val != NULL) SetByValBool(val[1 - 1]);
            else SetByValBool(BoolValByDefault);
        }
        void TCellFloat::SetByArr(QString* val, int Q)
        {
            if (val != NULL) SetByValString(val[1 - 1]);
            else SetByValString("");
        }
        //
        void TCellFloat::AddOrInsDoubleVal(double val, int N)
        {
            this->val = (float)val;
        }
        void TCellFloat::AddOrInsFloatVal(float val, int N)
        {
            this->val = (float)val;
        }
        void TCellFloat::AddOrInsIntVal(int val, int N)
        {
            this->val = (float)val;
        }
        void TCellFloat::AddOrInsBoolVal(bool val, int N)
        {
            this->val = (float) BoolToInt(val);
        }
        void TCellFloat::AddOrInsStringVal(QString val, int N)
        {
            this->val=StrToReal(val, NULL, 10);
            //this->val.SetNum(val);// Convert.ToDouble(val);
        }
        //
        void TCellFloat::DelValN(int N) { }
        //
        void TCellFloat::GetDoubleArr(double*&Arr,  int&QItems) {
            QItems=1;
            Arr = new double[QItems];
            Arr[1 - 1] = GetDoubleVal();
        }
        void TCellFloat::GetFloatArr( float*&Arr, int&QItems) {
            QItems = 1;
            Arr = new float[QItems];
            Arr[1 - 1] = GetFloatVal();
        }
        void TCellFloat::GetIntArr( int*&Arr,  int&QItems) {
            QItems = 1;
            Arr = new int[QItems];
            Arr[1 - 1] = GetIntVal();
        }
        void TCellFloat::GetBoolArr( bool*&Arr,  int&QItems) {
            QItems = 1;
            Arr = new bool[QItems];
            Arr[1 - 1] = GetBoolVal();
        }
        void TCellFloat::ToStringArr(QString*&Arr, int&QItems) {
            QItems = 1;
            if(Arr!=NULL)delete[]Arr;
            Arr = new QString[QItems];
            Arr[1 - 1] = ToString();
        }
        //
        void TCellFloat::SetNameN(QString name, int N) { SetByValStringN(name, N);  }
        void TCellFloat::SetName1(QString name) { SetByValStringN(name, 1); }
        void TCellFloat::SetName2(QString name) { SetByValStringN(name, 2); }
        //void TCellFloat::SetName3(QString name) { SetByValStringN(name, 3); }
        //void TCellFloat::SetNames(QString* Arr, int Q) { SetByArrString(Arr, Q); }
        QString TCellFloat::GetNameN(int N) { return ToStringN(N); }
        QString TCellFloat::GetName1() { return ToStringN(1); }
        QString TCellFloat::GetName2() { return ToStringN(2); }
        //QString TCellFloat::GetName3() { return ToStringN(3); }
        //void TCellFloat::GetNames(QString*&Arr, int&QItems) { ToStringArr(Arr, QItems); }
        //int TCellFloat::GetLengthOfNamesList() { return 1; }
        //
        void TCellFloat::SetItems(QString*items, int Q, int ActiveN){
            if(items!=NULL){
                this->val=items[1-1].toFloat();
            }
        }
        void TCellFloat::GetItems(QString*&items, int&Q){
            if(items!=NULL){
                delete[]items;
            }
            items=new QString[1];
            items[1-1]=FloatToStr(this->val);
        }
        void TCellFloat::SetItem(QString item, int itemN){
            if(itemN==1 || itemN==-1){
                this->val=item.toFloat();//better own fn
            }
        }
        void TCellFloat::InsItem(QString item, int itemN){}
        void TCellFloat::AddItem(QString item){}
        void TCellFloat::DelItem(int itemN){}
        QString TCellFloat::GetItem(int itemN){
           QString R="0";
            if(itemN==1 || itemN==-1){
                R.setNum(this->val);
            }
            return R;
        }
        int TCellFloat::GetLengthOfItemsList(){ return 0; }
        //
    //     override object Clone(){
    //        return new TCellDouble(this->GetDoubleVal());
    //    }
    //};//cl  //TCellFloat



//class TCellInt: TDataCell
   //{
   //    double val;
   //    :
   TCellInt::TCellInt() { this->val = 0; }
   TCellInt::TCellInt(double val) { SetByValDouble(val); }
   TCellInt::TCellInt(float val) { SetByValFloat(val); }
   TCellInt::TCellInt(int val) { SetByValInt(val); }
   TCellInt::TCellInt(bool val) { SetByValBool(val); }
   TCellInt::TCellInt(QString val) { SetByValString(val); }
   //
   TCellInt::TCellInt(double* val, int Q) { SetByArrDouble(val, Q); }
   TCellInt::TCellInt(float* val, int Q) { SetByArrFloat(val, Q); }
   TCellInt::TCellInt(int* val, int Q) { SetByArrInt(val, Q); }
   TCellInt::TCellInt(bool* val, int Q) { SetByArrBool(val, Q); }
   TCellInt::TCellInt(QString* val, int Q) { SetByArrString(val, Q); }
   //
                    //hope they will not be needed
                //    TCellInt(TCellInt&obj){
                //        this->Assign(obj);
                //    }
                //    //
                //    TCellInt& operator =(TCellInt&obj){
                //        this->Assign(obj);
                //        return*this;
                //    }
                //    //
                //    void Assign(TCellInt&obj){
                //        this->data=obj.data;
                //    }
    void TCellInt::construct(int n){
        this->val=0;
    }
    int TCellInt::GetTypeN() { return IntTypeN; }
    int TCellInt::GetActiveN() { return 1;}
    void TCellInt::SetActiveN(int N) { }
    int TCellInt::GetLength() { return 1; }
    void TCellInt::SetLength(int L){}
    //
    double TCellInt::GetDoubleVal(){
        double r;
        r = (double)val;
        return r;
    }
    float TCellInt::GetFloatVal() {
        float r;
        r = (float)val;
        return r;
    }
    int TCellInt::GetIntVal()
    {
        //int r;
        //r =(int) round(val);
        //return r;
        return val;
    }
    bool TCellInt::GetBoolVal() {
        bool r;
        if(BoolValByDefault==true){
            if (val == 0) r = false;
            else r = true;
        }else{
            if (val == 1) r = true;
            else r = false;
        }
        return r;
    }
    QString TCellInt::ToString() {
        QString s;
        s=RealToString(val);
        s.setNum(val);
        return s;//val.ToString();
    }
    //
    double TCellInt::GetDoubleValN(int N) { return (double)val; }
    float TCellInt::GetFloatValN(int N) { return (float)val; }
    int TCellInt::GetIntValN(int N)
    {
         //int r;
         //r = (int)round(val);
         //return r;
         return val;
    }
    bool TCellInt::GetBoolValN(int N)
    {
        bool r;
        if(BoolValByDefault==true){
            if (val == 0) r = false;
            else r = true;
        }else{
            if (val == 1) r = true;
            else r = false;
        }
        return r;
    }
    QString TCellInt::ToStringN(int N) {
        QString s;
        //QString RealToString(double x, int Repr_IntAndFrac0_ExpAfOrderLim1_ExpAnyhow2=0,  int QAftComma=6, int OrdAfWhichExp=6, int BaseDec=10);
        s=IntToStringSimple(BoolToInt(val)); // s=RealToString(val);
        s.setNum(BoolToInt(val));
        return s;
    }
    //
    void TCellInt::SetByValDouble(double val) { this->val = (int)round(val); }
    void TCellInt::SetByValFloat(float val) { this->val = (int)round(val);  }
    void TCellInt::SetByValInt(int val) { this->val = val; }
    void TCellInt::SetByValBool(bool val)
    {
         this->val=BoolToInt(val);
         // this->val=(double)i;
   }
   void TCellInt::SetByValString(QString val) {
       //this->val = Convert.ToDouble(val);
       //this->val = NumberParse.StrToFloat(val);
       this->val=(int)StrToInt(val);
       this->val =val.toInt();
   } //hin S' ne abl convert!!
   //
   void TCellInt::SetByValDoubleN(double val, int N) { SetByValDouble(val); }
   void TCellInt::SetByValFloatN(float val, int N) { SetByValFloat(val); }
   void TCellInt::SetByValIntN(int val, int N) { SetByValInt(val); }
   void TCellInt::SetByValBoolN(bool val, int N) { SetByValBool(val); }
   void TCellInt::SetByValStringN(QString val, int N) { SetByValString(val); }
   //
   void TCellInt::SetVal(double val) {  this->val = (int)round(val); }
   void TCellInt::SetVal(int val) { this->val = val; }
   void TCellInt::SetVal(bool val)
   {
       this->val = BoolToInt(val);
   }
   void TCellInt::SetVal(QString val) {
       //this->val = Convert.ToDouble(val);
       this->val=StrToInt(val);
       this->val=val.toInt();
   }
   //
   void TCellInt::SetValN(double val, int N) { SetVal(val); }
   void TCellInt::SetValN(int val, int N) { SetVal(val); }
   void TCellInt::SetValN(bool val, int N) { SetVal(val); }
   void TCellInt::SetValN(QString val, int N) { SetVal(val); }
   //
   void TCellInt::SetByArrDouble(double* val, int Q){
       if(val!=NULL)SetByValDouble(val[1-1]);
       else SetByValDouble(0);
   }
   void TCellInt::SetByArrFloat(float* val, int Q)
   {
       if (val != NULL) SetByValFloat(val[1 - 1]);
       else SetByValFloat(0);
   }
   void TCellInt::SetByArrInt(int* val, int Q)
   {
       if (val != NULL) SetByValInt(val[1 - 1]);
       else SetByValInt(0);
   }
   void TCellInt::SetByArrBool(bool* val, int Q)
   {
       if (val != NULL) SetByValBool(val[1 - 1]);
       else SetByValBool(BoolValByDefault);
   }
   void TCellInt::SetByArrString(QString* val, int Q)
   {
       if (val != NULL) SetByValString(val[1 - 1]);
       else SetByValString("");
   }
   //
   void TCellInt::SetByArr(double* val, int Q){
       if(val!=NULL)SetByValDouble(val[1-1]);
       else SetByValDouble(0);
   }
   void TCellInt::SetByArr(int* val, int Q)
   {
       if (val != NULL) SetByValInt(val[1 - 1]);
       else SetByValInt(0);
   }
   void TCellInt::SetByArr(bool* val, int Q)
   {
       if (val != NULL) SetByValBool(val[1 - 1]);
       else SetByValBool(BoolValByDefault);
   }
   void TCellInt::SetByArr(QString* val, int Q)
   {
       if (val != NULL) SetByValString(val[1 - 1]);
       else SetByValString("");
   }
   //
   void TCellInt::AddOrInsDoubleVal(double val, int N)
   {
       this->val = (int)round(val);
   }
   void TCellInt::AddOrInsFloatVal(float val, int N)
   {
       this->val = (int)round(val);
   }
   void TCellInt::AddOrInsIntVal(int val, int N)
   {
       //this->val = (float)val;
       this->val = val;
   }
   void TCellInt::AddOrInsBoolVal(bool val, int N)
   {
       int r;
       r=BoolToInt(val);
       this->val = r;
   }
   void TCellInt::AddOrInsStringVal(QString val, int N)
   {
       this->val=StrToInt(val, NULL, 10);
       //this->val.SetNum(val);// Convert.ToDouble(val);
   }
   //
   void TCellInt::DelValN(int N) { }
   //
   void TCellInt::GetDoubleArr(double*&Arr,  int&QItems) {
       QItems=1;
       Arr = new double[QItems];
       Arr[1 - 1] = GetDoubleVal();
   }
   void TCellInt::GetFloatArr( float*&Arr, int&QItems) {
       QItems = 1;
       Arr = new float[QItems];
       Arr[1 - 1] = GetFloatVal();
   }
   void TCellInt::GetIntArr( int*&Arr,  int&QItems) {
       QItems = 1;
       Arr = new int[QItems];
       Arr[1 - 1] = GetIntVal();
   }
   void TCellInt::GetBoolArr( bool*&Arr,  int&QItems) {
       QItems = 1;
       Arr = new bool[QItems];
       Arr[1 - 1] = GetBoolVal();
   }
   void TCellInt::ToStringArr(QString*&Arr, int&QItems) {
       QItems = 1;
       if(Arr!=NULL)delete[]Arr;
       Arr = new QString[QItems];
       Arr[1 - 1] = ToString();
   }
   //
   void TCellInt::SetNameN(QString name, int N) { SetByValStringN(name, N);  }
   void TCellInt::SetName1(QString name) { SetByValStringN(name, 1); }
   void TCellInt::SetName2(QString name) { SetByValStringN(name, 2); }
   //void TCellInt::SetName3(QString name) { SetByValStringN(name, 3); }
  //void TCellInt::SetNames(QString* Arr, int Q) { SetByArrString(Arr, Q); }
   QString TCellInt::GetNameN(int N) { return ToStringN(N); }
   QString TCellInt::GetName1() { return ToStringN(1); }
   QString TCellInt::GetName2() { return ToStringN(2); }
   //QString TCellInt::GetName3() { return ToStringN(3); }
   //void TCellInt::GetNames(QString*&Arr, int&QItems) { ToStringArr(Arr, QItems); }
   //int TCellInt::GetLengthOfNamesList() { return 1; }
   void TCellInt::SetItems(QString*items, int Q, int ActiveN){
       if(items!=NULL){
           this->val=items[1-1].toInt();
       }
   }
   void TCellInt::GetItems(QString*&items, int&Q){
       if(items!=NULL){
           delete[]items;
       }
       items=new QString[1];
       items[1-1]=IntToStr(this->val);
   }
   void TCellInt::SetItem(QString item, int itemN){
       if(itemN==1 || itemN==-1){
           this->val=item.toInt();//better own fn
       }
   }
   void TCellInt::InsItem(QString item, int itemN){}
   void TCellInt::AddItem(QString item){}
   void TCellInt::DelItem(int itemN){}
   QString TCellInt::GetItem(int itemN){
      QString R="0";
       if(itemN==1 || itemN==-1){
           R.setNum(this->val);
       }
       return R;
   }
   int TCellInt::GetLengthOfItemsList(){ return 0; }
   //
                //     override object Clone(){
                //        return new TCellDouble(this->GetDoubleVal());
                //    }
//};//cl  //TCellInt




   //class TCellBool: TDataCell
      //{
      //    double val;
      //    :
      TCellBool::TCellBool() { this->val = BoolValByDefault; }
      TCellBool::TCellBool(double val) { SetByValDouble(val); }
      TCellBool::TCellBool(float val) { SetByValFloat(val); }
      TCellBool::TCellBool(int val) { SetByValInt(val); }
      TCellBool::TCellBool(bool val) { SetByValBool(val); }
      TCellBool::TCellBool(QString val) { SetByValString(val); }
      //
      TCellBool::TCellBool(double* val, int Q) { SetByArrDouble(val, Q); }
      TCellBool::TCellBool(float* val, int Q) { SetByArrFloat(val, Q); }
      TCellBool::TCellBool(int* val, int Q) { SetByArrInt(val, Q); }
      TCellBool::TCellBool(bool* val, int Q) { SetByArrBool(val, Q); }
      TCellBool::TCellBool(QString* val, int Q) { SetByArrString(val, Q); }
      //
                       //hope they will not be needed
                   //    TCellBool(TCellBool&obj){
                   //        this->Assign(obj);
                   //    }
                   //    //
                   //    TCellBool& operator =(TCellBool&obj){
                   //        this->Assign(obj);
                   //        return*this;
                   //    }
                   //    //
                   //    void Assign(TCellBool&obj){
                   //        this->data=obj.data;
                   //    }
      void TCellBool::construct(int n){
          this->val=BoolValByDefault;
      }
       int TCellBool::GetTypeN() { return BoolTypeN; }
       int TCellBool::GetActiveN() { return 1;}
       void TCellBool::SetActiveN(int N) { }
       int TCellBool::GetLength() { return 1; }
       void TCellBool::SetLength(int L){}
       //
       double TCellBool::GetDoubleVal(){
           double r;
           int z;
           z=BoolToInt(this->val);
           r = (double)z;
           return r;
       }
       float TCellBool::GetFloatVal() {
           float r;
           r = (float)BoolToInt(this->val);
           return r;
       }
       int TCellBool::GetIntVal()
       {
           //int r;
           //r =(int) round(val);
           //return r;
           return BoolToInt(this->val);;
       }
       bool TCellBool::GetBoolVal() {
           //bool r;
           //if(BoolValByDefault==true){
           //    if (val == 0) r = false;
           //    else r = true;
           //}else{
           //    if (val == 1) r = true;
           //    else r = false;
           //}
           //return r;
           return val;
       }
       QString TCellBool::ToString() {
           QString s;
           s=IntToStringSimple(BoolToInt(val)); // s=RealToString(val);
           s.setNum(BoolToInt(val));
           return s;//val.ToString();
       }
       //
       double TCellBool::GetDoubleValN(int N) { return (double)BoolToInt(val); }
       float TCellBool::GetFloatValN(int N) { return (float)BoolToInt(val); }
       int TCellBool::GetIntValN(int N)
       {
            //int r;
            //r = (int)round(val);
            //return r;
            return BoolToInt(val);
       }
       bool TCellBool::GetBoolValN(int N)
       {
           //bool r;
           //if(BoolValByDefault==true){
           //    if (val == 0) r = false;
           //    else r = true;
           //}else{
           //    if (val == 1) r = true;
           //    else r = false;
           //}
           //return r;
           return val;
       }
       QString TCellBool::ToStringN(int N) {
           QString s;
           //QString RealToString(double x, int Repr_IntAndFrac0_ExpAfOrderLim1_ExpAnyhow2=0,  int QAftComma=6, int OrdAfWhichExp=6, int BaseDec=10);
           s=RealToString(val);
           s.setNum(val);
           return s;
       }
       //
       void TCellBool::SetByValDouble(double val) { this->val = IntToBool((int)round(val)); }
       void TCellBool::SetByValFloat(float val) { this->val = IntToBool((int)round(val)); }
       void TCellBool::SetByValInt(int val) { this->val = IntToBool(val); }
       void TCellBool::SetByValBool(bool val)
       {
            //int i;
            //i = BoolToInt(val);
            //this->val=i;
            // this->val=(double)i;
            this->val=val;
      }
      void TCellBool::SetByValString(QString val) {
          //this->val = Convert.ToDouble(val);
          //this->val = NumberParse.StrToFloat(val);
          this->val=IntToBool(StrToInt(val));
          this->val =IntToBool(val.toInt());
      } //hin S' ne abl convert!!
      //
      void TCellBool::SetByValDoubleN(double val, int N) { SetByValDouble(val); }
      void TCellBool::SetByValFloatN(float val, int N) { SetByValFloat(val); }
      void TCellBool::SetByValIntN(int val, int N) { SetByValInt(val); }
      void TCellBool::SetByValBoolN(bool val, int N) { SetByValBool(val); }
      void TCellBool::SetByValStringN(QString val, int N) { SetByValString(val); }
      //
      void TCellBool::SetVal(double val) { this->val = IntToBool((int)round(val));}
      void TCellBool::SetVal(int val) {this->val = IntToBool(val); }
      void TCellBool::SetVal(bool val)
      {
          //int i;
          //i = BoolToInt(val);
          //this->val=i;
          // this->val=(double)i;
          this->val=val;
      }
      void TCellBool::SetVal(QString val) {
          //this->val = Convert.ToDouble(val);
          this->val=IntToBool(StrToInt(val));
          this->val==IntToBool(val.toInt());
      }
      //
      void TCellBool::SetValN(double val, int N) { SetVal(val); }
      void TCellBool::SetValN(int val, int N) { SetVal(val); }
      void TCellBool::SetValN(bool val, int N) { SetVal(val); }
      void TCellBool::SetValN(QString val, int N) { SetVal(val); }
      //
      void TCellBool::SetByArrDouble(double* val, int Q){
          if(val!=NULL)SetByValDouble(val[1-1]);
          else SetByValDouble(0);
      }
      void TCellBool::SetByArrFloat(float* val, int Q)
      {
          if (val != NULL) SetByValFloat(val[1 - 1]);
          else SetByValFloat(0);
      }
      void TCellBool::SetByArrInt(int* val, int Q)
      {
          if (val != NULL) SetByValInt(val[1 - 1]);
          else SetByValInt(0);
      }
      void TCellBool::SetByArrBool(bool* val, int Q)
      {
          if (val != NULL) SetByValBool(val[1 - 1]);
          else SetByValBool(BoolValByDefault);
      }
      void TCellBool::SetByArrString(QString* val, int Q)
      {
          if (val != NULL) SetByValString(val[1 - 1]);
          else SetByValString("");
      }
      //
      void TCellBool::SetByArr(double* val, int Q){
          if(val!=NULL)SetByValDouble(val[1-1]);
          else SetByValDouble(0);
      }
      void TCellBool::SetByArr(int* val, int Q)
      {
          if (val != NULL) SetByValInt(val[1 - 1]);
          else SetByValInt(0);
      }
      void TCellBool::SetByArr(bool* val, int Q)
      {
          if (val != NULL) SetByValBool(val[1 - 1]);
          else SetByValBool(BoolValByDefault);
      }
      void TCellBool::SetByArr(QString* val, int Q)
      {
          if (val != NULL) SetByValString(val[1 - 1]);
          else SetByValString("");
      }
      //
      void TCellBool::AddOrInsDoubleVal(double val, int N)
      {
          this->val = IntToBool((int)round(val));
      }
      void TCellBool::AddOrInsFloatVal(float val, int N)
      {
          this->val = IntToBool((int)round(val));
      }
      void TCellBool::AddOrInsIntVal(int val, int N)
      {
          //this->val = (float)val;
          this->val = IntToBool(val);
      }
      void TCellBool::AddOrInsBoolVal(bool val, int N)
      {
          //int r;
          //r=BoolToInt(val);
          //this->val = r;
          this->val = val;
      }
      void TCellBool::AddOrInsStringVal(QString val, int N)
      {
          this->val=IntToBool(StrToInt(val, NULL, 10));
          //this->val.SetNum(val);// Convert.ToDouble(val);
      }
      //
      void TCellBool::DelValN(int N) { }
      //
      void TCellBool::GetDoubleArr(double*&Arr,  int&QItems) {
          QItems=1;
          Arr = new double[QItems];
          Arr[1 - 1] = GetDoubleVal();
      }
      void TCellBool::GetFloatArr( float*&Arr, int&QItems) {
          QItems = 1;
          Arr = new float[QItems];
          Arr[1 - 1] = GetFloatVal();
      }
      void TCellBool::GetIntArr( int*&Arr,  int&QItems) {
          QItems = 1;
          Arr = new int[QItems];
          Arr[1 - 1] = GetIntVal();
      }
      void TCellBool::GetBoolArr( bool*&Arr,  int&QItems) {
          QItems = 1;
          Arr = new bool[QItems];
          Arr[1 - 1] = GetBoolVal();
      }
      void TCellBool::ToStringArr(QString*&Arr, int&QItems) {
          QItems = 1;
          if(Arr!=NULL)delete[]Arr;
          Arr = new QString[QItems];
          Arr[1 - 1] = ToString();
      }
      //
      void TCellBool::SetNameN(QString name, int N) { SetByValStringN(name, N);  }
      void TCellBool::SetName1(QString name) { SetByValStringN(name, 1); }
      void TCellBool::SetName2(QString name) { SetByValStringN(name, 2); }
      //void TCellBool::SetName3(QString name) { SetByValStringN(name, 3); }
      //void TCellBool::SetNames(QString* Arr, int Q) { SetByArrString(Arr, Q); }
      QString TCellBool::GetNameN(int N) { return ToStringN(N); }
      QString TCellBool::GetName1() { return ToStringN(1); }
      QString TCellBool::GetName2() { return ToStringN(2); }
      //QString TCellBool::GetName3() { return ToStringN(3); }
      //void TCellBool::GetNames(QString*&Arr, int&QItems) { ToStringArr(Arr, QItems); }
      //int TCellBool::GetLengthOfNamesList() { return 1; }
      void TCellBool::SetItems(QString*items, int Q, int ActiveN){
          if(items!=NULL){
              this->val=IntToBool(items[1-1].toInt());
          }
      }
      void TCellBool::GetItems(QString*&items, int&Q){
          if(items!=NULL){
              delete[]items;
          }
          items=new QString[1];
          items[1-1]=IntToStr(BoolToInt(this->val));
      }
      void TCellBool::SetItem(QString item, int itemN){
          if(itemN==1 || itemN==-1){
              this->val=IntToBool(item.toInt());//better own fn
          }
      }
      void TCellBool::InsItem(QString item, int itemN){}
      void TCellBool::AddItem(QString item){}
      void TCellBool::DelItem(int itemN){}
      QString TCellBool::GetItem(int itemN){
         QString R="0";
          if(itemN==1 || itemN==-1){
              if(this->val){
                  R="1";
              }
          }
          return R;
      }
      int TCellBool::GetLengthOfItemsList(){ return 0; }
      //
                   //     override object Clone(){
                   //        return new TCellDouble(this->GetDoubleVal());
                   //    }
   //};//cl  //TCellBool



      //class TCellString: TDataCell
         //{
         //    double val;
         //    :
         void TCellString::construct(int n){
             this->val="";
         }
         TCellString::TCellString() { this->val = ""; }
         TCellString::TCellString(double val) { SetByValDouble(val); }
         TCellString::TCellString(float val) { SetByValFloat(val); }
         TCellString::TCellString(int val) { SetByValInt(val); }
         TCellString::TCellString(bool val) { SetByValBool(val); }
         TCellString::TCellString(QString val) { SetByValString(val); }
         //
         TCellString::TCellString(double* val, int Q) { SetByArrDouble(val, Q); }
         TCellString::TCellString(float* val, int Q) { SetByArrFloat(val, Q); }
         TCellString::TCellString(int* val, int Q) { SetByArrInt(val, Q); }
         TCellString::TCellString(bool* val, int Q) { SetByArrBool(val, Q); }
         TCellString::TCellString(QString* val, int Q) { SetByArrString(val, Q); }
         //
                          //hope they will not be needed
                      //    TCellString(TCellString&obj){
                      //        this->Assign(obj);
                      //    }
                      //    //
                      //    TCellString& operator =(TCellString&obj){
                      //        this->Assign(obj);
                      //        return*this;
                      //    }
                      //    //
                      //    void Assign(TCellString&obj){
                      //        this->data=obj.data;
                      //    }
          int TCellString::GetTypeN() { return StringTypeN; }
          int TCellString::GetActiveN() { return 1;}
          void TCellString::SetActiveN(int N) { }
          int TCellString::GetLength() { return 1; }
          void TCellString::SetLength(int L){}
          //
          double TCellString::GetDoubleVal(){
              double r;
              r=StrToReal(val, NULL);
              r=val.toDouble();
              return r;
          }
          float TCellString::GetFloatVal() {
              float r;
              r=StrToReal(val, NULL);
              r=val.toFloat();
              return r;
          }
          int TCellString::GetIntVal()
          {
              int r;
              r=StrToInt(val, NULL);
              r=val.toInt();
              return r;
          }
          bool TCellString::GetBoolVal() {
              int i=GetIntVal();
              return IntToBool(i);
          }
          QString TCellString::ToString() {
              //QString s;
              //s=IntToString(BoolToInt(val)); // s=RealToString(val);
              //s.setNum(BoolToInt(val));
              //return s;//val.ToString();
              return val;
          }
          //
          double TCellString::GetDoubleValN(int N) { return GetDoubleVal(); }
          float TCellString::GetFloatValN(int N) { return GetFloatVal();; }
          int TCellString::GetIntValN(int N) { return GetIntVal(); }
          bool TCellString::GetBoolValN(int N) { return GetBoolVal();}

          QString TCellString::ToStringN(int N) {
              return ToString();
          }
          //
          void TCellString::SetByValDouble(double val) {
              this->val=RealToString(val);
              this->val.setNum(val);
          }
          void TCellString::SetByValFloat(float val) {
              this->val=RealToString((double)val);
              this->val.setNum(val);
          }
          void TCellString::SetByValInt(int val) {
              this->val=IntToStr(val);
              this->val.setNum(val);
          }
          void TCellString::SetByValBool(bool val)
          {
               int i;
               i = BoolToInt(val);
               SetByValInt(i);
         }
         void TCellString::SetByValString(QString val) {
             this->val =val;
         }
         //
         void TCellString::SetByValDoubleN(double val, int N) { SetByValDouble(val); }
         void TCellString::SetByValFloatN(float val, int N) { SetByValFloat(val); }
         void TCellString::SetByValIntN(int val, int N) { SetByValInt(val); }
         void TCellString::SetByValBoolN(bool val, int N) { SetByValBool(val); }
         void TCellString::SetByValStringN(QString val, int N) { SetByValString(val); }
         //
         void TCellString::SetVal(double val) {
             this->val=RealToString(val);
             this->val.setNum(val);
         }
         void TCellString::SetVal(int val) {
             this->val=IntToStringSimple(val);
             this->val.setNum(val);
         }
         void TCellString::SetVal(bool val){
             int i;
             i = BoolToInt(val);
             SetByValInt(i);
         }
         void TCellString::SetVal(QString val) {
             this->val=val;
         }
         //
         void TCellString::SetValN(double val, int N){
             this->val=RealToString(val);
             this->val.setNum(val);
         }
         void TCellString::SetValN(int val, int N)  {
             this->val=IntToStringSimple(val);
             this->val.setNum(val);
         }
         void TCellString::SetValN(bool val, int N) {
             int i;
             i = BoolToInt(val);
             SetByValInt(i);
         }
         void TCellString::SetValN(QString val, int N){
             this->val=val;
         }
         //
         void TCellString::SetByArrDouble(double* val, int Q){
             if(val!=NULL)SetByValDouble(val[1-1]);
             else SetByValDouble(0);
         }
         void TCellString::SetByArrFloat(float* val, int Q)
         {
             if (val != NULL) SetByValFloat(val[1 - 1]);
             else SetByValFloat(0);
         }
         void TCellString::SetByArrInt(int* val, int Q)
         {
             if (val != NULL) SetByValInt(val[1 - 1]);
             else SetByValInt(0);
         }
         void TCellString::SetByArrBool(bool* val, int Q)
         {
             if (val != NULL) SetByValBool(val[1 - 1]);
             else SetByValBool(BoolValByDefault);
         }
         void TCellString::SetByArrString(QString* val, int Q)
         {
             if (val != NULL) SetByValString(val[1 - 1]);
             else SetByValString("");
         }
         //
         void TCellString::SetByArr(double* val, int Q){
             if(val!=NULL)SetByValDouble(val[1-1]);
             else SetByValDouble(0);
         }
         void TCellString::SetByArr(int* val, int Q)
         {
             if (val != NULL) SetByValInt(val[1 - 1]);
             else SetByValInt(0);
         }
         void TCellString::SetByArr(bool* val, int Q)
         {
             if (val != NULL) SetByValBool(val[1 - 1]);
             else SetByValBool(BoolValByDefault);
         }
         void TCellString::SetByArr(QString* val, int Q)
         {
             if (val != NULL) SetByValString(val[1 - 1]);
             else SetByValString("");
         }
         //
         void TCellString::AddOrInsDoubleVal(double val, int N) {
             this->val=RealToString(val);
             this->val.setNum(val);
         }
         void TCellString::AddOrInsFloatVal(float val, int N) {
             this->val=RealToString((double)val);
             this->val.setNum(val);
         }
         void TCellString::AddOrInsIntVal(int val, int N){
             this->val=IntToStringSimple(val);
             this->val.setNum(val);
         }
         void TCellString::AddOrInsBoolVal(bool val, int N)
         {
              int i;
              i = BoolToInt(val);
              SetByValInt(i);
        }
         void TCellString::AddOrInsStringVal(QString val, int N){
             this->val=val;
         }
         //
         void TCellString::DelValN(int N) { }
         //
         void TCellString::GetDoubleArr(double*&Arr,  int&QItems) {
             QItems=1;
             Arr = new double[QItems];
             Arr[1 - 1] = GetDoubleVal();
         }
         void TCellString::GetFloatArr( float*&Arr, int&QItems) {
             QItems = 1;
             Arr = new float[QItems];
             Arr[1 - 1] = GetFloatVal();
         }
         void TCellString::GetIntArr( int*&Arr,  int&QItems) {
             QItems = 1;
             Arr = new int[QItems];
             Arr[1 - 1] = GetIntVal();
         }
         void TCellString::GetBoolArr( bool*&Arr,  int&QItems) {
             QItems = 1;
             Arr = new bool[QItems];
             Arr[1 - 1] = GetBoolVal();
         }
         void TCellString::ToStringArr(QString*&Arr, int&QItems) {
             QItems = 1;
             if(Arr!=NULL)delete[]Arr;
             Arr = new QString[QItems];
             Arr[1 - 1] = ToString();
         }
         //
         void TCellString::SetNameN(QString name, int N) { SetByValStringN(name, N);  }
         void TCellString::SetName1(QString name) { SetByValStringN(name, 1); }
         void TCellString::SetName2(QString name) { SetByValStringN(name, 2); }
         //void TCellString::SetName3(QString name) { SetByValStringN(name, 3); }
         //void TCellString::SetNames(QString* Arr, int Q) { SetByArrString(Arr, Q); }
         QString TCellString::GetNameN(int N) { return ToStringN(N); }
         QString TCellString::GetName1() { return ToStringN(1); }
         QString TCellString::GetName2() { return ToStringN(2); }
         //QString TCellString::GetName3() { return ToStringN(3); }
         //void TCellString::GetNames(QString*&Arr, int&QItems) { ToStringArr(Arr, QItems); }
         //int TCellString::GetLengthOfNamesList() { return 1; }
         //
         void TCellString::SetItems(QString*items, int Q, int ActiveN){
             if(items!=NULL){
                 this->val=items[1-1];
             }
         }
         void TCellString::GetItems(QString*&items, int&Q){
             if(items!=NULL){
                 delete[]items;
             }
             items=new QString[1];
             items[1-1]=this->val;
         }
         void TCellString::SetItem(QString item, int itemN){
             if(itemN==1 || itemN==-1){
                 this->val=item;//better own fn
             }
         }
         void TCellString::InsItem(QString item, int itemN){}
         void TCellString::AddItem(QString item){}
         void TCellString::DelItem(int itemN){}
         QString TCellString::GetItem(int itemN){
            QString R="0";
             if(itemN==1 || itemN==-1){
                 R=this->val;
             }
             return R;
         }
         int TCellString::GetLengthOfItemsList(){ return 0; }
                      //     override object Clone(){
                      //        return new TCellDoubleArr(this->GetDoubleVal());
                      //    }
      //};//cl  //TCellString


         //class TCellDoubleArr: TDataCell
         //{
         //    double val;
         //    :
             TCellDoubleArr::TCellDoubleArr() {
                double val=0;
                //
                ActiveN=0;
                Length=0;
                //
                ActiveN=1;
                Length=1;
                //
                content.push_back(val);
             }
             TCellDoubleArr::TCellDoubleArr(double val) { SetByValDouble(val); }
             TCellDoubleArr::TCellDoubleArr(float val) { SetByValFloat(val); }
             TCellDoubleArr::TCellDoubleArr(int val) { SetByValInt(val); }
             TCellDoubleArr::TCellDoubleArr(bool val) { SetByValBool(val); }
             TCellDoubleArr::TCellDoubleArr(QString val) { SetByValString(val); }
             //
             TCellDoubleArr::TCellDoubleArr(double* val, int Q) { SetByArrDouble(val, Q); }
             TCellDoubleArr::TCellDoubleArr(float* val, int Q) { SetByArrFloat(val, Q); }
             TCellDoubleArr::TCellDoubleArr(int* val, int Q) { SetByArrInt(val, Q); }
             TCellDoubleArr::TCellDoubleArr(bool* val, int Q) { SetByArrBool(val, Q); }
             TCellDoubleArr::TCellDoubleArr(QString* val, int Q) { SetByArrString(val, Q); }
             //
             //hope they will not be needed
             //    TCellDoubleArr(TCellDoubleArr&obj){
             //        this->Assign(obj);
             //    }
             //    //
             //    TCellDoubleArr& operator =(TCellDoubleArr&obj){
             //        this->Assign(obj);
             //        return*this;
             //    }
             //    //
             //    void Assign(TCellDoubleArr&obj){
             //        this->data=obj.data;
             //    }
             void TCellDoubleArr::construct(int n){
                 //this->val=new double[n];
                 for(int i=1; i<=n; i++) this->content.push_back(0);
             }
             int TCellDoubleArr::GetTypeN() { return DoubleArrayTypeN; }
             int TCellDoubleArr::GetActiveN() { return ActiveN;}
             void TCellDoubleArr::SetActiveN(int N) {
                 if(N>=1 && N<=content.size()) this->ActiveN=N;
             }
             int TCellDoubleArr::GetLength() { return Length; }
             void TCellDoubleArr::SetLength(int L){
                 double val=0;
                 int iL=content.size();
                 if(L>=1 && L<=MaxInt){
                     if(L>iL){
                         for(int i=1; i<=L-iL; i++){
                            content.push_back(val);
                         }
                     }else if(L<iL){
                         for(int i=1; i<=iL-L; i++){
                            content.pop_back();
                         }
                     }
                     Length=L;
                 }
             }//SetLength
             //
             double TCellDoubleArr::GetDoubleVal() {
                double val;
                val=content[ActiveN-1];
                return val;
             }
             float TCellDoubleArr::GetFloatVal() {
                 float val;
                 val=(float)content[ActiveN-1];
                 return val;
             }
             int TCellDoubleArr::GetIntVal()
             {
                 double val;
                 val=content[ActiveN-1];
                 int r;
                 //r =(int) round(content[ActiveN-1]);
                 r =(int) round(val);
                 return r;
             }
             bool TCellDoubleArr::GetBoolVal() {
                 bool r;
                 double val=content[ActiveN-1];
                 if(BoolValByDefault==true){
                     if (val == 0) r = false;
                     else r = true;
                 }else{
                     if (val == 1) r = true;
                     else r = false;
                 }
                 return r;
             }
             QString TCellDoubleArr::ToString() {
                 double val=content[ActiveN-1];
                 QString s;
                 s=RealToString(val);
                 s.setNum(val);
                 return s;//val.ToString();
             }
             //
             double TCellDoubleArr::GetDoubleValN(int N) {
                 double val=0;
                 if(N>=1 && N<=content.size()){
                     val=content[N-1];
                 }
                 return val;
             }
             float TCellDoubleArr::GetFloatValN(int N){
                 float val=0;
                 if(N>=1 && N<=content.size()){
                     val=(float)content[N-1];
                 }
                 return val;
             }
             int TCellDoubleArr::GetIntValN(int N)
             {
                 int r=0;
                 double val=0;
                 this->Length=this->content.size();
                 if(N>=1 && N<=Length){
                     val=this->content[N-1];
                     r = (int)round(val);
                 }
                 return r;
             }
             bool TCellDoubleArr::GetBoolValN(int N)
             {
                 double val;
                 bool r=BoolValByDefault;
                 this->Length=this->content.size();
                 if(N>= 1 && N<=Length){
                     val=this->content[N-1];
                     if(BoolValByDefault==true){
                        if (val == 0) r = false;
                         else r = true;
                    }else{
                        if (val == 1) r = true;
                        else r = false;
                    }
                 }
                 return r;
             }
             QString TCellDoubleArr::ToStringN(int N) {
                 QString s;
                 //QString RealToString(double x, int Repr_IntAndFrac0_ExpAfOrderLim1_ExpAnyhow2=0,  int QAftComma=6, int OrdAfWhichExp=6, int BaseDec=10);
                 double val=content[ActiveN-1];
                 s=RealToString(val);
                 s.setNum(val);
                 return s;
             }
             //
             void TCellDoubleArr::SetByValDouble(double val) {
                 //this->val = (double)val;
                 content[ActiveN-1]=val;
             }
             void TCellDoubleArr::SetByValFloat(float val) {
                 //this->val = (double)val;
                 content[ActiveN-1]=(double)val;
             }
             void TCellDoubleArr::SetByValInt(int val) {
                 //this->val = (double)val;
                 content[ActiveN-1]=(double)val;
             }
             void TCellDoubleArr::SetByValBool(bool val)
             {
                 int i;
                 i = BoolToInt(val);
                 //this->val=(double)i;
                 content[ActiveN-1]=(double)i;
             }
             void TCellDoubleArr::SetByValString(QString val) {
                 double x;
                 //this->val = Convert.ToDouble(val);
                 //this->val = NumberParse.StrToFloat(val);
                 x=StrToReal(val);
                 x =val.toDouble();
                 content[ActiveN-1]=x;
             } //hin S' ne abl convert!!
             //
             void TCellDoubleArr::SetByValDoubleN(double val, int N) {
                 //SetByValDouble(val);
                 if(N>=1 && N<=content.size()) content[N-1]=val;
             }
             void TCellDoubleArr::SetByValFloatN(float val, int N){
                 //SetByValFloat(val);
                 if(N>=1 && N<=content.size()) content[N-1]=(double)val;
             }
             void TCellDoubleArr::SetByValIntN(int val, int N) {
                 //SetByValInt(val);
                 if(N>=1 && N<=content.size()) content[N-1]=(double)val;
             }
             void TCellDoubleArr::SetByValBoolN(bool val, int N) {
                 SetByValBool(val);
                 if(N>=1 && N<=content.size()) content[N-1]=(double)BoolToInt(val);
             }
             void TCellDoubleArr::SetByValStringN(QString val, int N) {
                 SetByValString(val);
                 double x;
                 x=StrToReal(val);
                 x=val.toDouble();
                 if(N>=1 && N<=content.size()) content[N-1]=x;
             }
             //
             void TCellDoubleArr::SetVal(double val) {
                 //this->val = (double)val;
                 content[ActiveN-1]=val;
             }
             void TCellDoubleArr::SetVal(int val) {
                 //this->val = (double)val;
                 content[ActiveN-1]=(double)val;
             }
             void TCellDoubleArr::SetVal(bool val)
             {
                 int i;
                 i = BoolToInt(val);
                 //this->val = (double)i;
                 content[ActiveN-1]=(double)i;
             }
             void TCellDoubleArr::SetVal(QString val) {
                 double x;
                 //this->val = Convert.ToDouble(val);
                 //this->val=StrToReal(val);
                 //this->val=val.toDouble();
                 x=StrToReal(val);
                 x=val.toDouble();
                 content[ActiveN-1]=x;
             }
             //
             void TCellDoubleArr::SetValN(double val, int N) {
                 //SetVal(val);
                 if(N>=1 && N<=content.size())content[N-1]=val;
             }
             void TCellDoubleArr::SetValN(int val, int N) {
                 //SetVal(val);
                 if(N>=1 && N<=content.size())content[N-1]=(double)val;
             }
             void TCellDoubleArr::SetValN(bool val, int N) {
                 //SetVal(val);
                 int x=BoolToInt(val);
                 if(N>=1 && N<=content.size())content[N-1]=(double)x;
             }
             void TCellDoubleArr::SetValN(QString val, int N) {
                 //SetVal(val);
                 double x=StrToReal(val);
                 x=val.toDouble();
                 if(N>=1 && N<=content.size())content[N-1]=x;
             }
             //
             void TCellDoubleArr::SetByArrDouble(double* val, int Q){
                 int MinN;
                 if(Length>=Q) MinN=Q; else MinN=Length;
                 if(val!=NULL){
                     for(int i=1; i<=MinN; i++) content[i-1]=val[i-1];
                 }
                 else
                 {
                    //for(int i=1; i<=MinN; i++) content[i-1]=0;
                    //NOp; NULL as argument let it be means nothing to change
                 }
             }
             void TCellDoubleArr::SetByArrFloat(float* val, int Q){
                 int MinN;
                 if(Length>=Q) MinN=Q; else MinN=Length;
                 if(val!=NULL){
                     for(int i=1; i<=MinN; i++) content[i-1]=(double)val[i-1];
                 }
                 else
                 {
                    //for(int i=1; i<=MinN; i++) content[i-1]=0;
                    //NOp; NULL as argument let it be means nothing to change
                 }
             }
             void TCellDoubleArr::SetByArrInt(int* val, int Q){
                 int MinN;
                 if(Length>=Q) MinN=Q; else MinN=Length;
                 if(val!=NULL){
                     for(int i=1; i<=MinN; i++) content[i-1]=(double)val[i-1];
                 }
                 else
                 {
                    //for(int i=1; i<=MinN; i++) content[i-1]=0;
                    //NOp; NULL as argument let it be means nothing to change
                 }
             }
             void TCellDoubleArr::SetByArrBool(bool* val, int Q){
                 int MinN;
                 if(Length>=Q) MinN=Q; else MinN=Length;
                 if(val!=NULL){
                     for(int i=1; i<=MinN; i++) content[i-1]=(double)BoolToInt(val[i-1]);
                 }
                 else
                 {
                    //for(int i=1; i<=MinN; i++) content[i-1]=0;
                    //NOp; NULL as argument let it be means nothing to change
                 }
             }
             void TCellDoubleArr::SetByArrString(QString* val, int Q){
                 double x;
                 int MinN;
                 if(Length>=Q) MinN=Q; else MinN=Length;
                 if(val!=NULL){
                     for(int i=1; i<=MinN; i++){
                         x=StrToReal(val[i-1]);
                         x=val[i-1].toDouble();
                         content[i-1]=x;
                     }
                 }
                 else
                 {
                    // for(int i=1; i<=MinN; i++){
                    //     x=0;
                    //     content[i-1]=x;
                    //}
                    //NOp; NULL as argument let it be means nothing to change
                 }
             }
             //
             void TCellDoubleArr::SetByArr(double* val, int Q){
                 int MinN;
                 if(Length>=Q) MinN=Q; else MinN=Length;
                 if(val!=NULL){
                     for(int i=1; i<=MinN; i++) content[i-1]=val[i-1];
                 }
                 else
                 {
                    //for(int i=1; i<=MinN; i++) content[i-1]=0;
                    //NOp; NULL as argument let it be means nothing to change
                 }
             }
             void TCellDoubleArr::SetByArr(int* val, int Q){
                 int MinN;
                 if(Length>=Q) MinN=Q; else MinN=Length;
                 if(val!=NULL){
                     for(int i=1; i<=MinN; i++) content[i-1]=(double)val[i-1];
                 }
                 else
                 {
                    //for(int i=1; i<=MinN; i++) content[i-1]=0;
                    //NOp; NULL as argument let it be means nothing to change
                 }
             }
             void TCellDoubleArr::SetByArr(bool* val, int Q){
                 int MinN;
                 if(Length>=Q) MinN=Q; else MinN=Length;
                 if(val!=NULL){
                     for(int i=1; i<=MinN; i++) content[i-1]=(double)BoolToInt(val[i-1]);
                 }
                 else
                 {
                    //for(int i=1; i<=MinN; i++) content[i-1]=0;
                    //NOp; NULL as argument let it be means nothing to change
                 }
             }
             void TCellDoubleArr::SetByArr(QString* val, int Q){
                 double x;
                 int MinN;
                 if(Length>=Q) MinN=Q; else MinN=Length;
                 if(val!=NULL){
                     for(int i=1; i<=MinN; i++){
                         x=StrToReal(val[i-1]);
                         x=val[i-1].toDouble();
                         content[i-1]=x;
                     }
                 }
                 else
                 {
                    // for(int i=1; i<=MinN; i++){
                    //     x=0;
                    //     content[i-1]=x;
                    //}
                    //NOp; NULL as argument let it be means nothing to change
                 }
             }
             //
             void TCellDoubleArr::AddOrInsDoubleVal(double val, int N){
                 //SetByValDouble(val);
                 this->Length=this->content.size();
                 if(N>=1 && N<=Length) content.insert(content.begin()+N-1,val);
                 else{
                     content.push_back(val);
                     Length++;
                     //ActiveN=N;
                 }
             }
             void TCellDoubleArr::AddOrInsFloatVal(float val, int N){
                 //SetByValDouble(val);
                 this->Length=this->content.size();
                 if(N>=1 && N<=Length) content.insert(content.begin()+N-1,(double)val);
                 else{
                     content.push_back((double)val);
                     Length++;
                     //ActiveN=N;
                 }
             }
             void TCellDoubleArr::AddOrInsIntVal(int val, int N){
                 //SetByValDouble(val);
                 this->Length=this->content.size();
                 if(N>=1 && N<=Length) content.insert(content.begin()+N-1,(double)val);
                 else{
                     content.push_back((double)val);
                     Length++;
                     //ActiveN=N;
                 }
             }
             void TCellDoubleArr::AddOrInsBoolVal(bool val, int N){
                 int x=BoolToInt(val);
                 //SetByValDouble(val);
                 this->Length=this->content.size();
                 if(N>=1 && N<=Length) {
                     content.insert(content.begin()+N-1,(double)x);
                 }else{
                     content.push_back((double)x);
                     Length++;
                     //ActiveN=N;
                 }
             }
             void TCellDoubleArr::AddOrInsStringVal(QString val, int N){
                 double x=StrToReal(val);
                 x=val.toDouble();
                 //SetByValDouble(val);
                 this->Length=this->content.size();
                 if(N>=1 && N<=Length){
                     content.insert(content.begin()+N-1,x);
                 }else{
                     content.push_back(x);
                     Length++;
                     //ActiveN=N;
                 }
             }
             //
             void TCellDoubleArr::DelValN(int N) {
                 this->Length=this->content.size();
                 if(N>=1 && N<=Length){
                     content.erase(content.begin()+N-1);
                }
             }
             //
             void TCellDoubleArr::GetDoubleArr(double*&Arr,  int&QItems) {
                 QItems=Length;
                 if(Arr!=NULL){
                     delete[]Arr;
                     Arr=new double[QItems];
                 }
                 for(int i=1; i<=QItems; i++) Arr[i-1] = GetDoubleValN(i);
             }
             void TCellDoubleArr::GetFloatArr( float*&Arr, int&QItems){
                 QItems=Length;
                 if(Arr!=NULL){
                     delete[]Arr;
                     Arr=new float[QItems];
                 }
                 for(int i=1; i<=QItems; i++) Arr[i-1] = GetFloatValN(i);
             }
             void TCellDoubleArr::GetIntArr( int*&Arr,  int&QItems){
                 QItems=Length;
                 if(Arr!=NULL){
                     delete[]Arr;
                     Arr=new int[QItems];
                 }
                 for(int i=1; i<=QItems; i++) Arr[i-1] = GetIntValN(i);
             }
             void TCellDoubleArr::GetBoolArr( bool*&Arr,  int&QItems){
                 QItems=Length;
                 if(Arr!=NULL){
                     delete[]Arr;
                     Arr=new bool[QItems];
                 }
                 for(int i=1; i<=QItems; i++) Arr[i-1] = GetBoolValN(i);
             }
             void TCellDoubleArr::ToStringArr(QString*&Arr, int&QItems) {
                 QItems=Length;
                 if(Arr!=NULL){
                     delete[]Arr;
                     Arr=new QString[QItems];
                 }
                 for(int i=1; i<=QItems; i++) Arr[i-1] = ToStringN(i);
             }
             //
             void TCellDoubleArr::SetNameN(QString name, int N) { SetByValStringN(name, N);  }
             void TCellDoubleArr::SetName1(QString name) { SetByValStringN(name, 1); }
             void TCellDoubleArr::SetName2(QString name) { SetByValStringN(name, 2); }
             //void TCellDoubleArr::SetName3(QString name) { SetByValStringN(name, 3); }
             //void TCellDoubleArr::SetNames(QString* Arr, int Q) { SetByArrString(Arr, Q); }
             QString TCellDoubleArr::GetNameN(int N) { return ToStringN(N); }
             QString TCellDoubleArr::GetName1() { return ToStringN(1); }
             QString TCellDoubleArr::GetName2() { return ToStringN(2); }
             //QString TCellDoubleArr::GetName3() { return ToStringN(3); }
             //void TCellDoubleArr::GetNames(QString*&Arr, int&QItems) { ToStringArr(Arr, QItems); }
             //int TCellDoubleArr::GetLengthOfNamesList() { return 1; }
             //
             void TCellDoubleArr::SetItems(QString*items, int Q, int ActiveN){
                 double val;
                 QString item;
                 //if(this->content==NULL){
                 if(this->content.size()!=0){
                     //delete this->content;
                     this->content.clear();
                     //this->content=NULL;
                     this->Length=0;
                     this->ActiveN=0;
                 }
                 if(items!=NULL){
                     this->Length=Q;
                     //content=new double[this->Length];
                     for(int i=1; i<=this->Length; i++){
                         //this->content[i-1]=items[i-1];
                         //val=items[i-1].toDouble;
                         item=items[i-1];
                         val=item.toDouble();
                         //val=StrToFloat(items[i-1]);
                         this->content.push_back(val);
                     }
                     //this->ActiveN=ActiveN;
                 }
                 this->Length=Q;
                 this->ActiveN=ActiveN;
             }
             void TCellDoubleArr::GetItems(QString*&items, int&Q){
                 double val;
                 QString item;
                 if(items!=NULL){
                     delete[]items;
                 }
                 items=NULL;
                 Q=this->Length;
                 if(this->content.size()>0){
                    items=new QString[Q];
                    for(int i=1; i<=Q; i++){
                        //val=FloatToStr(this-content[i-1]);
                        //items[1-1]/*=FloatToStr*/(this-content[i-1]);
                        val=this->content[i-1];
                        item=FloatToStr(val);
                        items[i-1]=item;
                    }
                 }
             }
             void TCellDoubleArr::SetItem(QString item, int itemN){
                 if(itemN==0){
                     itemN-=this->Length;
                 }
                 if(itemN>=1 || itemN<=this->Length){
                     this->content[itemN-1]=item.toDouble();//better own fn
                 }
             }
             void TCellDoubleArr::InsItem(QString item, int itemN){
                 double val=item.toDouble();
                 Array1DInsElementToN(this->content, itemN, val);
                 this->Length+=1;
             }
             void TCellDoubleArr::AddItem(QString item){
                 double val=item.toDouble();
                 Array1DAddElement(this->content, val);
                 this->Length+=1;
             }
             void TCellDoubleArr::DelItem(int itemN){
                 Array1DDelElementFromN(this->content, itemN);
                 this->Length-=1;
             }
             QString TCellDoubleArr::GetItem(int itemN){
                 QString R="0";
                 if(itemN<0){
                     itemN+=(this->Length+1);
                 }
                 if(itemN==1 && itemN<=this->Length){
                     R.setNum(this->content[itemN-1]);
                 }
                 return R;
             }
             int TCellDoubleArr::GetLengthOfItemsList(){ return this->Length; }
             //
             //
         //     override object Clone(){
         //        return new TCellDoubleArr(this->GetDoubleVal());
         //    }
//};//cl TCellDoubleArr



             //class TCellFloatArr: TDataCell
             //{
             //    double val;
             //    :
                 TCellFloatArr::TCellFloatArr() {
                    double val=0;
                    //
                    ActiveN=0;
                    Length=0;
                    //
                    ActiveN=1;
                    Length=1;
                    //
                    content.push_back(val);
                 }
                 void TCellFloatArr::construct(int n){
                     //this->val=new float[n];
                     //for(int i=1; i<=n; i++) val[i-1]=0;
                      for(int i=1; i<=n; i++) this->content.push_back(0);
                 }
                 TCellFloatArr::TCellFloatArr(double val) { SetByValDouble(val); }
                 TCellFloatArr::TCellFloatArr(float val) { SetByValFloat(val); }
                 TCellFloatArr::TCellFloatArr(int val) { SetByValInt(val); }
                 TCellFloatArr::TCellFloatArr(bool val) { SetByValBool(val); }
                 TCellFloatArr::TCellFloatArr(QString val) { SetByValString(val); }
                 //
                 TCellFloatArr::TCellFloatArr(double* val, int Q) { SetByArrDouble(val, Q); }
                 TCellFloatArr::TCellFloatArr(float* val, int Q) { SetByArrFloat(val, Q); }
                 TCellFloatArr::TCellFloatArr(int* val, int Q) { SetByArrInt(val, Q); }
                 TCellFloatArr::TCellFloatArr(bool* val, int Q) { SetByArrBool(val, Q); }
                 TCellFloatArr::TCellFloatArr(QString* val, int Q) { SetByArrString(val, Q); }
                 //
                 //hope they will not be needed
             //    TCellFloatArr(TCellFloatArr&obj){
             //        this->Assign(obj);
             //    }
             //    //
             //    TCellFloatArr& operator =(TCellFloatArr&obj){
             //        this->Assign(obj);
             //        return*this;
             //    }
             //    //
             //    void Assign(TCellFloatArr&obj){
             //        this->data=obj.data;
             //    }
                 int TCellFloatArr::GetTypeN() { return FloatArrayTypeN; }
                 int TCellFloatArr::GetActiveN() { return ActiveN;}
                 void TCellFloatArr::SetActiveN(int N) {
                     if(N>=1 && N<=content.size()) this->ActiveN=N;
                 }
                 int TCellFloatArr::GetLength() { return Length; }
                 void TCellFloatArr::SetLength(int L){
                     float val=0;
                     int iL=content.size();
                     if(L>=1 && L<=MaxInt){
                         if(L>iL){
                             for(int i=1; i<=L-iL; i++){
                                content.push_back(val);
                             }
                         }else if(L<iL){
                             for(int i=1; i<=iL-L; i++){
                                content.pop_back();
                             }
                         }
                         Length=L;
                     }
                 }//SetLength
                 //
                 double TCellFloatArr::GetDoubleVal() {
                    double val;
                    val=(double)content[ActiveN-1];
                    return val;
                 }
                 float TCellFloatArr::GetFloatVal() {
                     float val;
                     //val=(float)content[ActiveN-1];
                     val=content[ActiveN-1];
                     return val;
                 }
                 int TCellFloatArr::GetIntVal()
                 {
                     float val;
                     val=content[ActiveN-1];
                     int r;
                     //r =(int) round(content[ActiveN-1]);
                     r =(int) round(val);
                     return r;
                 }
                 bool TCellFloatArr::GetBoolVal() {
                     bool r;
                     float val=content[ActiveN-1];
                     if(BoolValByDefault==true){
                         if (val == 0) r = false;
                         else r = true;
                     }else{
                         if (val == 1) r = true;
                         else r = false;
                     }
                     return r;
                 }
                 QString TCellFloatArr::ToString() {
                     float val=content[ActiveN-1];
                     QString s;
                     s=RealToString((double)val);
                     s.setNum(val);
                     return s;//val.ToString();
                 }
                 //
                 double TCellFloatArr::GetDoubleValN(int N) {
                     double val=0;
                     if(N>=1 && N<=content.size()){
                         val=(double)content[N-1];
                     }
                     return val;
                 }
                 float TCellFloatArr::GetFloatValN(int N){
                     float val=0;
                     if(N>=1 && N<=content.size()){
                         //val=(float)content[N-1];
                         val=content[N-1];
                     }
                     return val;
                 }
                 int TCellFloatArr::GetIntValN(int N)
                 {
                     float val;
                     int r=0;
                     if(N>=1 && N<=content.size()){
                         val=content[N-1];
                         r = (int)round(val);
                     }
                     return r;
                 }
                 bool TCellFloatArr::GetBoolValN(int N)
                 {
                     bool r=BoolValByDefault;
                     float val;
                     this->Length=this->content.size();
                     if(N>=1 && N<=Length){
                        if(BoolValByDefault==true){
                            if (val == 0) r = false;
                            else r = true;
                        }else{
                            if (val == 1) r = true;
                            else r = false;
                        }
                     }
                     return r;
                 }
                 QString TCellFloatArr::ToStringN(int N) {
                     QString s;
                     //QString RealToString(double x, int Repr_IntAndFrac0_ExpAfOrderLim1_ExpAnyhow2=0,  int QAftComma=6, int OrdAfWhichExp=6, int BaseDec=10);
                     //double val=(double)content[ActiveN-1];
                     float val=content[ActiveN-1];
                     //s=RealToString((float)val);
                     s=RealToString(val);
                     s.setNum(val);
                     return s;
                 }
                 //
                 void TCellFloatArr::SetByValDouble(double val) {
                     //this->val = (double)val;
                     content[ActiveN-1]=(float)val;
                 }
                 void TCellFloatArr::SetByValFloat(float val) {
                     //this->val = (double)val;
                     //content[ActiveN-1]=(float)val;
                     content[ActiveN-1]=(float)val;
                 }
                 void TCellFloatArr::SetByValInt(int val) {
                     //this->val = (double)val;
                     content[ActiveN-1]=(float)val;
                 }
                 void TCellFloatArr::SetByValBool(bool val)
                 {
                     int i;
                     i = BoolToInt(val);
                     //this->val=(double)i;
                     content[ActiveN-1]=(float)i;
                 }
                 void TCellFloatArr::SetByValString(QString val) {
                     float x;
                     //this->val = Convert.ToDouble(val);
                     //this->val = NumberParse.StrToFloat(val);
                     x=(float)StrToReal(val);
                     x =val.toFloat();
                     content[ActiveN-1]=x;
                 } //hin S' ne abl convert!!
                 //
                 void TCellFloatArr::SetByValDoubleN(double val, int N) {
                     //SetByValDouble(val);
                     if(N>=1 && N<=content.size()) content[N-1]=(float)val;
                 }
                 void TCellFloatArr::SetByValFloatN(float val, int N){
                     //SetByValFloat(val);
                     //if(N>=1 && N<=content.size()) content[N-1]=(float)val;
                     if(N>=1 && N<=content.size()) content[N-1]=val;
                 }
                 void TCellFloatArr::SetByValIntN(int val, int N) {
                     //SetByValInt(val);
                     if(N>=1 && N<=content.size()) content[N-1]=(float)val;
                 }
                 void TCellFloatArr::SetByValBoolN(bool val, int N) {
                     SetByValBool(val);
                     if(N>=1 && N<=content.size()) content[N-1]=(float)BoolToInt(val);
                 }
                 void TCellFloatArr::SetByValStringN(QString val, int N) {
                     SetByValString(val);
                     double x;
                     x=StrToReal(val);
                     x=val.toFloat();
                     if(N>=1 && N<=content.size()) content[N-1]=(float)x;
                 }
                 //
                 void TCellFloatArr::SetVal(double val) {
                     //this->val = (double)val;
                     content[ActiveN-1]=(float)val;
                 }
                 void TCellFloatArr::SetVal(int val) {
                     //this->val = (double)val;
                     //content[ActiveN-1]=(float)val;
                     content[ActiveN-1]=val;
                 }
                 void TCellFloatArr::SetVal(bool val)
                 {
                     int i;
                     i = BoolToInt(val);
                     //this->val = (double)i;
                     content[ActiveN-1]=(float)i;
                 }
                 void TCellFloatArr::SetVal(QString val) {
                     double x;
                     //this->val = Convert.ToDouble(val);
                     //this->val=StrToReal(val);
                     //this->val=val.toDouble();
                     x=StrToReal(val);
                     x=val.toDouble();
                     content[ActiveN-1]=(float)x;
                 }
                 //
                 void TCellFloatArr::SetValN(double val, int N) {
                     //SetVal(val);
                     if(N>=1 && N<=content.size())content[N-1]=(float)val;
                 }
                 void TCellFloatArr::SetValN(int val, int N) {
                     //SetVal(val);
                     //if(N>=1 && N<=content.size())content[N-1]=(float)val;
                     if(N>=1 && N<=content.size())content[N-1]=val;
                 }
                 void TCellFloatArr::SetValN(bool val, int N) {
                     //SetVal(val);
                     int x=BoolToInt(val);
                     if(N>=1 && N<=content.size())content[N-1]=(float)x;
                 }
                 void TCellFloatArr::SetValN(QString val, int N) {
                     //SetVal(val);
                     double x=StrToReal(val);
                     x=val.toDouble();
                     if(N>=1 && N<=content.size())content[N-1]=(float)x;
                 }
                 //
                 void TCellFloatArr::SetByArrDouble(double* val, int Q){
                     int MinN;
                     if(Length>=Q) MinN=Q; else MinN=Length;
                     if(val!=NULL){
                         for(int i=1; i<=MinN; i++) content[i-1]=(float)val[i-1];
                     }
                     else
                     {
                        //for(int i=1; i<=MinN; i++) content[i-1]=0;
                        //NOp; NULL as argument let it be means nothing to change
                     }
                 }
                 void TCellFloatArr::SetByArrFloat(float* val, int Q){
                     int MinN;
                     if(Length>=Q) MinN=Q; else MinN=Length;
                     if(val!=NULL){
                         //for(int i=1; i<=MinN; i++) content[i-1]=(float)val[i-1];
                         for(int i=1; i<=MinN; i++) content[i-1]=val[i-1];
                     }
                     else
                     {
                        //for(int i=1; i<=MinN; i++) content[i-1]=0;
                        //NOp; NULL as argument let it be means nothing to change
                     }
                 }
                 void TCellFloatArr::SetByArrInt(int* val, int Q){
                     int MinN;
                     if(Length>=Q) MinN=Q; else MinN=Length;
                     if(val!=NULL){
                         for(int i=1; i<=MinN; i++) content[i-1]=(float)val[i-1];
                     }
                     else
                     {
                        //for(int i=1; i<=MinN; i++) content[i-1]=0;
                        //NOp; NULL as argument let it be means nothing to change
                     }
                 }
                 void TCellFloatArr::SetByArrBool(bool* val, int Q){
                     int MinN;
                     if(Length>=Q) MinN=Q; else MinN=Length;
                     if(val!=NULL){
                         for(int i=1; i<=MinN; i++) content[i-1]=(float)BoolToInt(val[i-1]);
                     }
                     else
                     {
                        //for(int i=1; i<=MinN; i++) content[i-1]=0;
                        //NOp; NULL as argument let it be means nothing to change
                     }
                 }
                 void TCellFloatArr::SetByArrString(QString* val, int Q){
                     float x;
                     int MinN;
                     if(Length>=Q) MinN=Q; else MinN=Length;
                     if(val!=NULL){
                         for(int i=1; i<=MinN; i++){
                             x=(float)StrToReal(val[i-1]);
                             x=val[i-1].toFloat();
                             content[i-1]=x;
                         }
                     }
                     else
                     {
                        // for(int i=1; i<=MinN; i++){
                        //     x=0;
                        //     content[i-1]=x;
                        //}
                        //NOp; NULL as argument let it be means nothing to change
                     }
                 }
                 //
                 void TCellFloatArr::SetByArr(double* val, int Q){
                     int MinN;
                     if(Length>=Q) MinN=Q; else MinN=Length;
                     if(val!=NULL){
                         for(int i=1; i<=MinN; i++) content[i-1]=(float)val[i-1];
                     }
                     else
                     {
                        //for(int i=1; i<=MinN; i++) content[i-1]=0;
                        //NOp; NULL as argument let it be means nothing to change
                     }
                 }
                 void TCellFloatArr::SetByArr(int* val, int Q){
                     int MinN;
                     if(Length>=Q) MinN=Q; else MinN=Length;
                     if(val!=NULL){
                         for(int i=1; i<=MinN; i++) content[i-1]=(float)val[i-1];
                     }
                     else
                     {
                        //for(int i=1; i<=MinN; i++) content[i-1]=0;
                        //NOp; NULL as argument let it be means nothing to change
                     }
                 }
                 void TCellFloatArr::SetByArr(bool* val, int Q){
                     int MinN;
                     if(Length>=Q) MinN=Q; else MinN=Length;
                     if(val!=NULL){
                         for(int i=1; i<=MinN; i++) content[i-1]=(float)BoolToInt(val[i-1]);
                     }
                     else
                     {
                        //for(int i=1; i<=MinN; i++) content[i-1]=0;
                        //NOp; NULL as argument let it be means nothing to change
                     }
                 }
                 void TCellFloatArr::SetByArr(QString* val, int Q){
                     float x;
                     int MinN;
                     if(Length>=Q) MinN=Q; else MinN=Length;
                     if(val!=NULL){
                         for(int i=1; i<=MinN; i++){
                             x=(float)StrToReal(val[i-1]);
                             x=val[i-1].toFloat();
                             content[i-1]=x;
                         }
                     }
                     else
                     {
                        // for(int i=1; i<=MinN; i++){
                        //     x=0;
                        //     content[i-1]=x;
                        //}
                        //NOp; NULL as argument let it be means nothing to change
                     }
                 }
                 //
                 void TCellFloatArr::AddOrInsDoubleVal(double val, int N){
                     //SetByValDouble(val);
                     this->Length=this->content.size();
                     if(N>=1 && N<=Length){
                        content.insert(content.begin()+N-1,(float)val);
                     }else{
                         content.push_back((float)val);
                         Length++;
                         //ActiveN=N;
                     }
                 }
                 void TCellFloatArr::AddOrInsFloatVal(float val, int N){
                     //SetByValDouble(val);
                     //if(N>=1 && N<=content.size()) content.insert(N-1,(float)val);
                     this->Length=this->content.size();
                     if(N>=1 && N<=Length){
                        content.insert(content.begin()+N-1,(float)val);
                     }else{
                         //content.push_back((float)val);
                         content.push_back(val);
                         Length++;
                         //ActiveN=N;
                     }
                 }
                 void TCellFloatArr::AddOrInsIntVal(int val, int N){
                     //SetByValDouble(val);
                     this->Length=this->content.size();
                     if(N>=1 && N<=Length){
                        content.insert(content.begin()+N-1,(float)val);
                     }else{
                         content.push_back((float)val);
                         Length++;
                         //ActiveN=N;
                     }
                 }
                 void TCellFloatArr::AddOrInsBoolVal(bool val, int N){
                     int x=BoolToInt(val);
                     //SetByValDouble(val);
                     this->Length=this->content.size();
                     if(N>=1 && N<=Length){
                        content.insert(content.begin()+N-1,(float)val);
                     }else{
                         content.push_back((float)x);
                         Length++;
                         //ActiveN=N;
                     }
                 }
                 void TCellFloatArr::AddOrInsStringVal(QString val, int N){
                     float x=(float)StrToReal(val);
                     x=val.toFloat();
                     //SetByValDouble(val);
                     this->Length=this->content.size();
                     if(N>=1 && N<=Length){
                        content.insert(content.begin()+N-1,x);
                     }else{
                         content.push_back(x);
                         Length++;
                         //ActiveN=N;
                     }
                 }
                 //
                 void TCellFloatArr::DelValN(int N) {
                    if(N>=1 && N<=content.size()){
                        content.erase(content.begin()+N-1);
                    }
                 }
                 //
                 void TCellFloatArr::GetDoubleArr(double*&Arr,  int&QItems) {
                     QItems=Length;
                     if(Arr!=NULL){
                         delete[]Arr;
                         Arr=new double[QItems];
                     }
                     for(int i=1; i<=QItems; i++) Arr[i-1] = GetDoubleValN(i);
                 }
                 void TCellFloatArr::GetFloatArr( float*&Arr, int&QItems){
                     QItems=Length;
                     if(Arr!=NULL){
                         delete[]Arr;
                         Arr=new float[QItems];
                     }
                     for(int i=1; i<=QItems; i++) Arr[i-1] = GetFloatValN(i);
                 }
                 void TCellFloatArr::GetIntArr( int*&Arr,  int&QItems){
                     QItems=Length;
                     if(Arr!=NULL){
                         delete[]Arr;
                         Arr=new int[QItems];
                     }
                     for(int i=1; i<=QItems; i++) Arr[i-1] = GetIntValN(i);
                 }
                 void TCellFloatArr::GetBoolArr( bool*&Arr,  int&QItems){
                     QItems=Length;
                     if(Arr!=NULL){
                         delete[]Arr;
                         Arr=new bool[QItems];
                     }
                     for(int i=1; i<=QItems; i++) Arr[i-1] = GetBoolValN(i);
                 }
                 void TCellFloatArr::ToStringArr(QString*&Arr, int&QItems) {
                     QItems=Length;
                     if(Arr!=NULL){
                         delete[]Arr;
                         Arr=new QString[QItems];
                     }
                     for(int i=1; i<=QItems; i++) Arr[i-1] = ToStringN(i);
                 }
                 //
                 void TCellFloatArr::SetNameN(QString name, int N) { SetByValStringN(name, N);  }
                 void TCellFloatArr::SetName1(QString name) { SetByValStringN(name, 1); }
                 void TCellFloatArr::SetName2(QString name) { SetByValStringN(name, 2); }
                 //void TCellFloatArr::SetName3(QString name) { SetByValStringN(name, 3); }
                 //void TCellFloatArr::SetNames(QString* Arr, int Q) { SetByArrString(Arr, Q); }
                 QString TCellFloatArr::GetNameN(int N) { return ToStringN(N); }
                 QString TCellFloatArr::GetName1() { return ToStringN(1); }
                 QString TCellFloatArr::GetName2() { return ToStringN(2); }
                 //QString TCellFloatArr::GetName3() { return ToStringN(3); }
                // void TCellFloatArr::GetNames(QString*&Arr, int&QItems) { ToStringArr(Arr, QItems); }
                 //int TCellFloatArr::GetLengthOfNamesList() { return 1; }
                 //
                 void TCellFloatArr::SetItems(QString*items, int Q, int ActiveN){
                     float val;
                     QString item;
                     //if(this->content==NULL){
                     if(this->content.size()!=0){
                         //delete this->content;
                         this->content.clear();
                         //this->content=NULL;
                         this->Length=0;
                         this->ActiveN=0;
                     }
                     if(items!=NULL){
                         this->Length=Q;
                         //content=new double[this->Length];
                         for(int i=1; i<=this->Length; i++){
                             //this->content[i-1]=items[i-1];
                             //val=items[i-1].toDouble;
                             item=items[i-1];
                             val=item.toFloat();
                             //val=StrToFloat(items[i-1]);
                             this->content.push_back(val);
                         }
                         this->ActiveN=ActiveN;
                         this->Length=Q;
                         //}
                     }
                 }
                 void TCellFloatArr::GetItems(QString*&items, int&Q){
                     float val;
                     QString item;
                     if(items!=NULL){
                         delete[]items;
                     }
                     items=NULL;
                     Q=this->Length;
                     if(this->content.size()>0){
                        items=new QString[Q];
                        for(int i=1; i<=Q; i++){
                            //val=FloatToStr(this-content[i-1]);
                            //items[1-1]/*=FloatToStr*/(this-content[i-1]);
                            val=this->content[i-1];
                            item=FloatToStr(val);
                            items[i-1]=item;
                        }
                     }
                 }
                 void TCellFloatArr::SetItem(QString item, int itemN){
                     if(itemN==0){
                         itemN-=this->Length;
                     }
                     if(itemN>=1 || itemN<=this->Length){
                         this->content[itemN-1]=item.toFloat();//better own fn
                     }
                 }
                 void TCellFloatArr::InsItem(QString item, int itemN){
                     float val=item.toFloat();
                     Array1DInsElementToN(this->content, itemN, val);
                     this->Length+=1;
                 }
                 void TCellFloatArr::AddItem(QString item){
                     float val=item.toFloat();
                     Array1DAddElement(this->content, val);
                     this->Length+=1;
                 }
                 void TCellFloatArr::DelItem(int itemN){
                     Array1DDelElementFromN(this->content, itemN);
                     this->Length-=1;
                 }
                 QString TCellFloatArr::GetItem(int itemN){
                     QString R="0";
                     if(itemN<0){
                         itemN+=(this->Length+1);
                     }
                     if(itemN==1 && itemN<=this->Length){
                         R.setNum(this->content[itemN-1]);
                     }
                     return R;
                 }
                 int TCellFloatArr::GetLengthOfItemsList(){ return this->Length; }
             //     override object Clone(){
             //        return new TCellFloatArr(this->GetDoubleVal());
             //    }
    //};//cl TCellFloatArr



                 //class TCellIntArr: TDataCell
                 //{
                 //    double val;
                 //    :
                     TCellIntArr::TCellIntArr() {
                        double val=0;
                        //
                        ActiveN=0;
                        Length=0;
                        //
                        ActiveN=1;
                        Length=1;
                        //
                        content.push_back(val);
                     }
                     void TCellIntArr::construct(int n){
                         //this->val=new int[n];
                         //for(int i=1; i<=n; i++) val[i-1]=0;
                          for(int i=1; i<=n; i++) this->content.push_back(0);
                     }
                     TCellIntArr::TCellIntArr(double val) { SetByValDouble(val); }
                     TCellIntArr::TCellIntArr(float val) { SetByValFloat(val); }
                     TCellIntArr::TCellIntArr(int val) { SetByValInt(val); }
                     TCellIntArr::TCellIntArr(bool val) { SetByValBool(val); }
                     TCellIntArr::TCellIntArr(QString val) { SetByValString(val); }
                     //
                     TCellIntArr::TCellIntArr(double* val, int Q) { SetByArrDouble(val, Q); }
                     TCellIntArr::TCellIntArr(float* val, int Q) { SetByArrFloat(val, Q); }
                     TCellIntArr::TCellIntArr(int* val, int Q) { SetByArrInt(val, Q); }
                     TCellIntArr::TCellIntArr(bool* val, int Q) { SetByArrBool(val, Q); }
                     TCellIntArr::TCellIntArr(QString* val, int Q) { SetByArrString(val, Q); }
                     //
                     //hope they will not be needed
                 //    TCellIntArr(TCellIntArr&obj){
                 //        this->Assign(obj);
                 //    }
                 //    //
                 //    TCellIntArr& operator =(TCellIntArr&obj){
                 //        this->Assign(obj);
                 //        return*this;
                 //    }
                 //    //
                 //    void Assign(TCellIntArr&obj){
                 //        this->data=obj.data;
                 //    }
                     int TCellIntArr::GetTypeN() { return IntArrayTypeN; }
                     int TCellIntArr::GetActiveN() { return ActiveN;}
                     void TCellIntArr::SetActiveN(int N) {
                         if(N>=1 && N<=content.size()) this->ActiveN=N;
                     }
                     int TCellIntArr::GetLength() { return Length; }
                     void TCellIntArr::SetLength(int L){
                         int val=0;
                         int iL=content.size();
                         if(L>=1 && L<=MaxInt){
                             if(L>iL){
                                 for(int i=1; i<=L-iL; i++){
                                    content.push_back(val);
                                 }
                             }else if(L<iL){
                                 for(int i=1; i<=iL-L; i++){
                                    content.pop_back();
                                 }
                             }
                             Length=L;
                         }
                     }//SetLength
                     //
                     double TCellIntArr::GetDoubleVal() {
                        double val;
                        val=(double)content[ActiveN-1];
                        return val;
                     }
                     float TCellIntArr::GetFloatVal() {
                         float val;
                         val=(float)content[ActiveN-1];
                         return val;
                     }
                     int TCellIntArr::GetIntVal()
                     {
                         int val;
                         val=content[ActiveN-1];
                         //int r;
                         //r =(int) round(content[ActiveN-1]);
                         //r =(int) round(val);
                         //return r;
                         return val;
                     }
                     bool TCellIntArr::GetBoolVal() {
                         bool r;
                         int val=content[ActiveN-1];
                         if(BoolValByDefault==true){
                             if (val == 0) r = false;
                             else r = true;
                         }else{
                             if (val == 1) r = true;
                             else r = false;
                         }
                         return r;
                     }
                     QString TCellIntArr::ToString() {
                         int val=content[ActiveN-1];
                         QString s;
                         s=IntToStringSimple(val);
                         s.setNum(val);
                         return s;//val.ToString();
                     }
                     //
                     double TCellIntArr::GetDoubleValN(int N) {
                         double val=0;
                         if(N>=1 && N<=content.size()){
                             val=(double)content[N-1];
                         }
                         return val;
                     }
                     float TCellIntArr::GetFloatValN(int N){
                         float val=0;
                         if(N>=1 && N<=content.size()){
                             val=(float)content[N-1];
                         }
                         return val;
                     }
                     int TCellIntArr::GetIntValN(int N)
                     {
                         int r=0;
                         if(N>=1 && N<=content.size()){
                            //r = (int)round(content[N-1]);
                            r = content[N-1];
                         }
                         return r;
                     }
                     bool TCellIntArr::GetBoolValN(int N)
                     {
                         int val;
                         bool r=BoolValByDefault, chk=BoolValByDefault;
                         //if(chk==true){
                         this->Length=this->content.size();
                         if(N>=1 && N<=this->Length){
                             val=content[N-1];
                             if(BoolValByDefault==true){
                                if (val == 0) r = false;
                                else r = true;
                            }else{
                                if (val == 1) r = true;
                                else r = false;
                            }
                         }
                         return r;
                     }
                     QString TCellIntArr::ToStringN(int N) {
                         QString s="";
                         //QString RealToString(double x, int Repr_IntAndFrac0_ExpAfOrderLim1_ExpAnyhow2=0,  int QAftComma=6, int OrdAfWhichExp=6, int BaseDec=10);
                         int val=content[ActiveN-1];
                         //float val=content[ActiveN-1];
                         s=IntToStringSimple(val);
                         s.setNum(val);
                         return s;
                     }
                     //
                     void TCellIntArr::SetByValDouble(double val) {
                         //this->val = (double)val;
                         int y=(int)round(val);
                         content[ActiveN-1]=y;
                     }
                     void TCellIntArr::SetByValFloat(float val) {
                         //this->val = (double)val;
                         //content[ActiveN-1]=(float)val;
                         //int y=(int)round(val);
                         int y=(int)round(val);
                         content[ActiveN-1]=y;
                     }
                     void TCellIntArr::SetByValInt(int val) {
                         //this->val = (double)val;
                         //content[ActiveN-1]=(float)val;
                         content[ActiveN-1]=val;
                     }
                     void TCellIntArr::SetByValBool(bool val)
                     {
                         int i;
                         i = BoolToInt(val);
                         //this->val=(double)i;
                         content[ActiveN-1]=i;
                     }
                     void TCellIntArr::SetByValString(QString val) {
                         double x;
                         int y;
                         x=StrToReal(val);
                         x=val.toDouble();
                         y=IntPart(x);
                         y=(int)round(x);
                         y=val.toInt();
                         content[ActiveN-1]=y;
                     } //hin S' ne abl convert!!
                     //
                     void TCellIntArr::SetByValDoubleN(double val, int N) {
                         //SetByValDouble(val);
                         if(N>=1 && N<=content.size()) content[N-1]=(int)round(val);
                     }
                     void TCellIntArr::SetByValFloatN(float val, int N){
                         //SetByValFloat(val);
                         //if(N>=1 && N<=content.size()) content[N-1]=(float)val;
                         if(N>=1 && N<=content.size())  content[N-1]=(int)round(val);
                     }
                     void TCellIntArr::SetByValIntN(int val, int N) {
                         //SetByValInt(val);
                         if(N>=1 && N<=content.size()) content[N-1]=val;
                     }
                     void TCellIntArr::SetByValBoolN(bool val, int N) {
                         SetByValBool(val);
                         if(N>=1 && N<=content.size()) content[N-1]=BoolToInt(val);
                     }
                     void TCellIntArr::SetByValStringN(QString val, int N) {
                         double x;
                         int y;
                         x=StrToReal(val);
                         x=val.toDouble();
                         y=IntPart(x);
                         y=(int)round(x);
                         y=val.toInt();
                         if(N>=1 && N<=content.size())content[N-1]=y;
                     }
                     //
                     void TCellIntArr::SetVal(double val) {
                         //this->val = (double)val;
                         content[ActiveN-1]=(int)round(val);
                     }
                     void TCellIntArr::SetVal(int val) {
                         //this->val = (double)val;
                         //content[ActiveN-1]=(float)val;
                         content[ActiveN-1]=val;
                     }
                     void TCellIntArr::SetVal(bool val)
                     {
                         int i;
                         i = BoolToInt(val);
                         //this->val = (double)i;
                         content[ActiveN-1]=BoolToInt(i);
                     }
                     void TCellIntArr::SetVal(QString val) {
                         double x=StrToReal(val);
                         int y;
                         y=IntPart(x);
                         y=(int)round(x);
                         y=val.toInt();
                         content[ActiveN-1]=y;
                     }
                     //
                     void TCellIntArr::SetValN(double val, int N) {
                         //SetVal(val);
                         if(N>=1 && N<=content.size())content[N-1]=(int)round(val);
                     }
                     void TCellIntArr::SetValN(int val, int N) {
                         //SetVal(val);
                         //if(N>=1 && N<=content.size())content[N-1]=(float)val;
                         if(N>=1 && N<=content.size())content[N-1]=val;
                     }
                     void TCellIntArr::SetValN(bool val, int N) {
                         //SetVal(val);
                         int x=BoolToInt(val);
                         if(N>=1 && N<=content.size())content[N-1]=x;
                     }
                     void TCellIntArr::SetValN(QString val, int N) {
                         double x;
                         int y;
                         x=StrToReal(val);
                         x=val.toDouble();
                         y=IntPart(x);
                         y=(int)round(x);
                         y=val.toInt();
                         if(N>=1 && N<=content.size())content[N-1]=y;
                     }
                     //
                     void TCellIntArr::SetByArrDouble(double* val, int Q){
                         int MinN;
                         if(Length>=Q) MinN=Q; else MinN=Length;
                         if(val!=NULL){
                             for(int i=1; i<=MinN; i++) content[i-1]=(float)val[i-1];
                         }
                         else
                         {
                            //for(int i=1; i<=MinN; i++) content[i-1]=0;
                            //NOp; NULL as argument let it be means nothing to change
                         }
                     }
                     void TCellIntArr::SetByArrFloat(float* val, int Q){
                         int MinN;
                         if(Length>=Q) MinN=Q; else MinN=Length;
                         if(val!=NULL){
                             //for(int i=1; i<=MinN; i++) content[i-1]=(float)val[i-1];
                             for(int i=1; i<=MinN; i++) content[i-1]=val[i-1];
                         }
                         else
                         {
                            //for(int i=1; i<=MinN; i++) content[i-1]=0;
                            //NOp; NULL as argument let it be means nothing to change
                         }
                     }
                     void TCellIntArr::SetByArrInt(int* val, int Q){
                         int MinN;
                         if(Length>=Q) MinN=Q; else MinN=Length;
                         if(val!=NULL){
                             for(int i=1; i<=MinN; i++) content[i-1]=(float)val[i-1];
                         }
                         else
                         {
                            //for(int i=1; i<=MinN; i++) content[i-1]=0;
                            //NOp; NULL as argument let it be means nothing to change
                         }
                     }
                     void TCellIntArr::SetByArrBool(bool* val, int Q){
                         int MinN;
                         if(Length>=Q) MinN=Q; else MinN=Length;
                         if(val!=NULL){
                             for(int i=1; i<=MinN; i++) content[i-1]=(float)BoolToInt(val[i-1]);
                         }
                         else
                         {
                            //for(int i=1; i<=MinN; i++) content[i-1]=0;
                            //NOp; NULL as argument let it be means nothing to change
                         }
                     }
                     void TCellIntArr::SetByArrString(QString* val, int Q){
                         double x;
                         int y;
                         int MinN;
                         if(Length>=Q) MinN=Q; else MinN=Length;
                         if(val!=NULL){
                             for(int i=1; i<=MinN; i++){
                                 x=StrToReal(val[i-1]);
                                 x=val[i-1].toDouble();
                                 y=IntPart(x);
                                 y=(int)round(x);
                                 y=val[i-1].toInt();
                                 content[i-1]=y;
                             }
                         }
                         else
                         {
                            // for(int i=1; i<=MinN; i++){
                            //     x=0;
                            //     content[i-1]=x;
                            //}
                            //NOp; NULL as argument let it be means nothing to change
                         }
                     }
                     //
                     void TCellIntArr::SetByArr(double* val, int Q){
                         int MinN;
                         if(Length>=Q) MinN=Q; else MinN=Length;
                         if(val!=NULL){
                             for(int i=1; i<=MinN; i++) content[i-1]=(int)round(val[i-1]);
                         }
                         else
                         {
                            //for(int i=1; i<=MinN; i++) content[i-1]=0;
                            //NOp; NULL as argument let it be means nothing to change
                         }
                     }
                     void TCellIntArr::SetByArr(int* val, int Q){
                         int MinN;
                         if(Length>=Q) MinN=Q; else MinN=Length;
                         if(val!=NULL){
                             for(int i=1; i<=MinN; i++) content[i-1]=val[i-1];
                         }
                         else
                         {
                            //for(int i=1; i<=MinN; i++) content[i-1]=0;
                            //NOp; NULL as argument let it be means nothing to change
                         }
                     }
                     void TCellIntArr::SetByArr(bool* val, int Q){
                         int MinN;
                         if(Length>=Q) MinN=Q; else MinN=Length;
                         if(val!=NULL){
                             for(int i=1; i<=MinN; i++) content[i-1]=BoolToInt(val[i-1]);
                         }
                         else
                         {
                            //for(int i=1; i<=MinN; i++) content[i-1]=0;
                            //NOp; NULL as argument let it be means nothing to change
                         }
                     }
                     void TCellIntArr::SetByArr(QString* val, int Q){
                         double x;
                         int y;
                         int MinN;
                         if(Length>=Q) MinN=Q; else MinN=Length;
                         if(val!=NULL){
                             for(int i=1; i<=MinN; i++){
                                 x=StrToReal(val[i-1]);
                                 x=val[i-1].toDouble();
                                 y=IntPart(x);
                                 y=(int)round(x);
                                 y=val[i-1].toInt();
                                 content[i-1]=y;
                             }
                         }
                         else
                         {
                            // for(int i=1; i<=MinN; i++){
                            //     x=0;
                            //     content[i-1]=x;
                            //}
                            //NOp; NULL as argument let it be means nothing to change
                         }
                     }
                     //
                     void TCellIntArr::AddOrInsDoubleVal(double val, int N){
                         //SetByValDouble(val);
                         this->Length=this->content.size();
                         if(N>=1 && N<=Length){
                             content.insert(content.begin()+N-1,(int)round(val));
                         }else{
                             content.push_back((int)round(val));
                             Length++;
                             //ActiveN=N;
                         }
                     }
                     void TCellIntArr::AddOrInsFloatVal(float val, int N){
                         //SetByValDouble(val);
                         //if(N>=1 && N<=content.size()) content.insert(N-1,(float)val);
                         this->Length=this->content.size();
                         if(N>=1 && N<=Length){
                             content.insert(content.begin()+N-1,(int)round(val));
                         }else{
                             //content.push_back((float)val);
                             content.push_back((int)round(val));
                             Length++;
                             //ActiveN=N;
                         }
                     }
                     void TCellIntArr::AddOrInsIntVal(int val, int N){
                         //SetByValDouble(val);
                         this->Length=this->content.size();
                         if(N>=1 && N<=Length){
                             content.insert(content.begin()+N-1,(int)round(val));
                         }else{
                             content.push_back(val);
                             Length++;
                             //ActiveN=N;
                         }
                     }
                     void TCellIntArr::AddOrInsBoolVal(bool val, int N){
                         int x=BoolToInt(val);
                         //SetByValDouble(val);
                         this->Length=this->content.size();
                         if(N>=1 && N<=Length){
                             content.insert(content.begin()+N-1,BoolToInt(val));
                         }else{
                             content.push_back(BoolToInt(x));
                             Length++;
                             //ActiveN=N;
                         }
                     }
                     void TCellIntArr::AddOrInsStringVal(QString val, int N){
                         double x=StrToReal(val);
                         int y=IntPart(x);
                         x=val.toDouble();
                         y=(int)round(x);
                         //SetByValDouble(val);
                         this->Length=this->content.size();
                         if(N>=1 && N<=Length){
                             content.insert(content.begin()+N-1,y);
                         }else{
                             content.push_back(y);
                             Length++;
                             //ActiveN=N;
                         }
                     }
                     //
                     void TCellIntArr::DelValN(int N) {
                         this->Length=this->content.size();
                         if(N>=1 && N<=Length){
                            content.erase(content.begin()+N-1);
                        }
                     }
                     //
                     void TCellIntArr::GetDoubleArr(double*&Arr,  int&QItems) {
                         QItems=Length;
                         if(Arr!=NULL){
                             delete[]Arr;
                             Arr=new double[QItems];
                         }
                         for(int i=1; i<=QItems; i++) Arr[i-1] = GetDoubleValN(i);
                     }
                     void TCellIntArr::GetFloatArr( float*&Arr, int&QItems){
                         QItems=Length;
                         if(Arr!=NULL){
                             delete[]Arr;
                             Arr=new float[QItems];
                         }
                         for(int i=1; i<=QItems; i++) Arr[i-1] = GetFloatValN(i);
                     }
                     void TCellIntArr::GetIntArr( int*&Arr,  int&QItems){
                         QItems=Length;
                         if(Arr!=NULL){
                             delete[]Arr;
                             Arr=new int[QItems];
                         }
                         for(int i=1; i<=QItems; i++) Arr[i-1] = GetIntValN(i);
                     }
                     void TCellIntArr::GetBoolArr( bool*&Arr,  int&QItems){
                         QItems=Length;
                         if(Arr!=NULL){
                             delete[]Arr;
                             Arr=new bool[QItems];
                         }
                         for(int i=1; i<=QItems; i++) Arr[i-1] = GetBoolValN(i);
                     }
                     void TCellIntArr::ToStringArr(QString*&Arr, int&QItems) {
                         QItems=Length;
                         if(Arr!=NULL){
                             delete[]Arr;
                             Arr=new QString[QItems];
                         }
                         for(int i=1; i<=QItems; i++) Arr[i-1] = ToStringN(i);
                     }
                     //
                     void TCellIntArr::SetNameN(QString name, int N) { SetByValStringN(name, N);  }
                     void TCellIntArr::SetName1(QString name) { SetByValStringN(name, 1); }
                     void TCellIntArr::SetName2(QString name) { SetByValStringN(name, 2); }
                     //void TCellIntArr::SetName3(QString name) { SetByValStringN(name, 3); }
                     //void TCellIntArr::SetNames(QString* Arr, int Q) { SetByArrString(Arr, Q); }
                     QString TCellIntArr::GetNameN(int N) { return ToStringN(N); }
                     QString TCellIntArr::GetName1() { return ToStringN(1); }
                     QString TCellIntArr::GetName2() { return ToStringN(2); }
                     //QString TCellIntArr::GetName3() { return ToStringN(3); }
                     //void TCellIntArr::GetNames(QString*&Arr, int&QItems) { ToStringArr(Arr, QItems); }
                     //int TCellIntArr::GetLengthOfNamesList() { return 1; }
                     //
                     //
                     void TCellIntArr::SetItems(QString*items, int Q, int ActiveN){
                         int val;
                         QString item;
                         //if(this->content==NULL){
                         if(this->content.size()!=0){
                             //delete this->content;
                             this->content.clear();
                             //this->content=NULL;
                             this->Length=0;
                             this->ActiveN=0;
                         }
                         if(items!=NULL){
                             this->Length=Q;
                             //content=new double[this->Length];
                             for(int i=1; i<=this->Length; i++){
                                 //this->content[i-1]=items[i-1];
                                 //val=items[i-1].toDouble;
                                 item=items[i-1];
                                 val=item.toInt();
                                 //val=StrToFloat(items[i-1]);
                                 this->content.push_back(val);
                             }
                             this->ActiveN=ActiveN;
                             this->Length=Q;
                             //}
                         }
                     }
                     void TCellIntArr::GetItems(QString*&items, int&Q){
                         int val;
                         QString item;
                         if(items!=NULL){
                             delete[]items;
                         }
                         items=NULL;
                         Q=this->Length;
                         if(this->content.size()>0){
                            items=new QString[Q];
                            for(int i=1; i<=Q; i++){
                                //val=FloatToStr(this-content[i-1]);
                                //items[1-1]/*=FloatToStr*/(this-content[i-1]);
                                val=this->content[i-1];
                                item=IntToStr(val);
                                items[i-1]=item;
                            }
                         }
                     }
                     void TCellIntArr::SetItem(QString item, int itemN){
                         if(itemN==0){
                             itemN-=this->Length;
                         }
                         if(itemN>=1 || itemN<=this->Length){
                             this->content[itemN-1]=item.toInt();//better own fn
                         }
                     }
                     void TCellIntArr::InsItem(QString item, int itemN){
                         int val=item.toInt();
                         Array1DInsElementToN(this->content, itemN, val);
                         this->Length+=1;
                     }
                     void TCellIntArr::AddItem(QString item){
                         int val=item.toInt();
                         Array1DAddElement(this->content, val);
                         this->Length+=1;
                     }
                     void TCellIntArr::DelItem(int itemN){
                         Array1DDelElementFromN(this->content, itemN);
                         this->Length-=1;
                     }
                     QString TCellIntArr::GetItem(int itemN){
                         QString R="0";
                         if(itemN<0){
                             itemN+=(this->Length+1);
                         }
                         if(itemN==1 && itemN<=this->Length){
                             R.setNum(this->content[itemN-1]);
                         }
                         return R;
                     }
                     int TCellIntArr::GetLengthOfItemsList(){ return this->Length; }
                 //     override object Clone(){
                 //        return new TCellIntArr(this->GetDoubleVal());
                 //    }
        //};//cl TCellIntArr


                     //class TCellBoolArr: TDataCell
                     //{
                     //    double val;
                     //    :
                         TCellBoolArr::TCellBoolArr() {
                            double val=0;
                            //
                            ActiveN=0;
                            Length=0;
                            //
                            ActiveN=1;
                            Length=1;
                            //
                            content.push_back(val);
                         }
                         TCellBoolArr::TCellBoolArr(double val) { SetByValDouble(val); }
                         TCellBoolArr::TCellBoolArr(float val) { SetByValFloat(val); }
                         TCellBoolArr::TCellBoolArr(int val) { SetByValInt(val); }
                         TCellBoolArr::TCellBoolArr(bool val) { SetByValBool(val); }
                         TCellBoolArr::TCellBoolArr(QString val) { SetByValString(val); }
                         //
                         TCellBoolArr::TCellBoolArr(double* val, int Q) { SetByArrDouble(val, Q); }
                         TCellBoolArr::TCellBoolArr(float* val, int Q) { SetByArrFloat(val, Q); }
                         TCellBoolArr::TCellBoolArr(int* val, int Q) { SetByArrInt(val, Q); }
                         TCellBoolArr::TCellBoolArr(bool* val, int Q) { SetByArrBool(val, Q); }
                         TCellBoolArr::TCellBoolArr(QString* val, int Q) { SetByArrString(val, Q); }
                         //
                         //hope they will not be needed
                     //    TCellBoolArr(TCellBoolArr&obj){
                     //        this->Assign(obj);
                     //    }
                     //    //
                     //    TCellBoolArr& operator =(TCellBoolArr&obj){
                     //        this->Assign(obj);
                     //        return*this;
                     //    }
                     //    //
                     //    void Assign(TCellBoolArr&obj){
                     //        this->data=obj.data;
                     //    }
                         void TCellBoolArr::construct(int n){
                             //this->val=new bool[n];
                             //for(int i=1; i<=n; i++) val[i-1]=BoolValByDefault;
                              for(int i=1; i<=n; i++) this->content.push_back(BoolValByDefault);
                         }
                         int TCellBoolArr::GetTypeN() { return BoolArrayTypeN; }
                         int TCellBoolArr::GetActiveN() { return ActiveN;}
                         void TCellBoolArr::SetActiveN(int N) {
                             if(N>=1 && N<=content.size()) this->ActiveN=N;
                         }
                         int TCellBoolArr::GetLength() { return Length; }
                         void TCellBoolArr::SetLength(int L){
                             bool val=BoolValByDefault;
                             int iL=content.size();
                             if(L>=1 && L<=MaxInt){
                                 if(L>iL){
                                     for(int i=1; i<=L-iL; i++){
                                        content.push_back(val);
                                     }
                                 }else if(L<iL){
                                     for(int i=1; i<=iL-L; i++){
                                        content.pop_back();
                                     }
                                 }
                                 Length=L;
                             }
                         }//SetLength
                         //
                         double TCellBoolArr::GetDoubleVal() {
                            double val;
                            val=(double)BoolToInt(content[ActiveN-1]);
                            return val;
                         }
                         float TCellBoolArr::GetFloatVal() {
                             float val;
                             val=(float)BoolToInt(content[ActiveN-1]);
                             return val;
                         }
                         int TCellBoolArr::GetIntVal()
                         {
                             int val;
                             val=BoolToInt(content[ActiveN-1]);
                             //int r;
                             //r =(int) round(content[ActiveN-1]);
                             //r =(int) round(val);
                             //return r;
                             return val;
                         }
                         bool TCellBoolArr::GetBoolVal() {
                             //bool r=BoolValByDefault, chk=BoolValByDefault;
                             //int val=content[ActiveN-1];
                             ////if(chk==true){
                             //if(BoolValByDefault==true){
                             //    if (val == 0) r = false;
                             //    else r = true;
                             //}else{
                             //    if (val == 1) r = true;
                             //    else r = false;
                             //}
                             //return r;
                             return this->content[ActiveN-1];
                         }
                         QString TCellBoolArr::ToString() {
                             int val=BoolToInt(content[ActiveN-1]);
                             QString s;
                             s=IntToStringSimple(val);
                             s.setNum(val);
                             return s;//val.ToString();
                         }
                         //
                         double TCellBoolArr::GetDoubleValN(int N) {
                             double val=0;
                             if(N>=1 && N<=content.size()){
                                 val=(double)BoolToInt(content[N-1]);
                             }
                             return val;
                         }
                         float TCellBoolArr::GetFloatValN(int N){
                             float val=0;
                             if(N>=1 && N<=content.size()){
                                 val=(float)BoolToInt(content[N-1]);
                             }
                             return val;
                         }
                         int TCellBoolArr::GetIntValN(int N)
                         {
                             int r=0;
                             if(N>=1 && N<=content.size()){
                                //r = (int)round(content[N-1]);
                                r = BoolToInt(content[N-1]);
                             }
                             return r;
                         }
                         bool TCellBoolArr::GetBoolValN(int N)
                         {
                             //bool r=BoolValByDefault, chk=BoolValByDefault;
                             ////if(chk==true){
                             //if(BoolValByDefault==true){
                             //    if (val == 0) r = false;
                             //    else r = true;
                             //}else{
                             //    if (val == 1) r = true;
                             //    else r = false;
                             //}
                             //return r;
                             return content[N-1];
                         }
                         QString TCellBoolArr::ToStringN(int N) {
                             QString s="";
                             //QString RealToString(double x, int Repr_IntAndFrac0_ExpAfOrderLim1_ExpAnyhow2=0,  int QAftComma=6, int OrdAfWhichExp=6, int BaseDec=10);
                             int val=content[ActiveN-1];
                             //float val=content[ActiveN-1];
                             s=IntToStringSimple(val);
                             s.setNum(val);
                             return s;
                         }
                         //
                         void TCellBoolArr::SetByValDouble(double val) {
                             //this->val = (double)val;
                             int y=(int)round(val);
                             content[ActiveN-1]=IntToBool(y);
                         }
                         void TCellBoolArr::SetByValFloat(float val) {
                             //this->val = (double)val;
                             //content[ActiveN-1]=(float)val;
                             //int y=(int)round(val);
                             int y=(int)round(val);
                             content[ActiveN-1]=IntToBool(y);;
                         }
                         void TCellBoolArr::SetByValInt(int val) {
                             //this->val = (double)val;
                             //content[ActiveN-1]=(float)val;
                             content[ActiveN-1]=IntToBool(val);
                         }
                         void TCellBoolArr::SetByValBool(bool val)
                         {
                             //int i;
                             //i = BoolToInt(val);
                             ////this->val=(double)i;
                             //content[ActiveN-1]=i;
                             content[ActiveN-1]=val;
                         }
                         void TCellBoolArr::SetByValString(QString val) {
                             double x;
                             int y;
                             x=StrToReal(val);
                             x=val.toDouble();
                             y=IntPart(x);
                             y=(int)round(x);
                             y=val.toInt();
                             content[ActiveN-1]=IntToBool(y);
                         } //hin S' ne abl convert!!
                         //
                         void TCellBoolArr::SetByValDoubleN(double val, int N) {
                             //SetByValDouble(val);
                             if(N>=1 && N<=content.size()) content[N-1]=IntToBool((int)round(val));
                         }
                         void TCellBoolArr::SetByValFloatN(float val, int N){
                             //SetByValFloat(val);
                             //if(N>=1 && N<=content.size()) content[N-1]=(float)val;
                             if(N>=1 && N<=content.size())  content[N-1]=IntToBool((int)round(val));
                         }
                         void TCellBoolArr::SetByValIntN(int val, int N) {
                             //SetByValInt(val);
                             if(N>=1 && N<=content.size()) content[N-1]=IntToBool(val);
                         }
                         void TCellBoolArr::SetByValBoolN(bool val, int N) {
                             SetByValBool(val);
                             if(N>=1 && N<=content.size()) content[N-1]=val;
                         }
                         void TCellBoolArr::SetByValStringN(QString val, int N) {
                             double x;
                             int y;
                             x=StrToReal(val);
                             x=val.toDouble();
                             y=IntPart(x);
                             y=(int)round(x);
                             y=val.toInt();
                             if(N>=1 && N<=content.size())content[N-1]=IntToBool(y);
                         }
                         //
                         void TCellBoolArr::SetVal(double val) {
                             //this->val = (double)val;
                             content[ActiveN-1]=IntToBool((int)round(val));
                         }
                         void TCellBoolArr::SetVal(int val) {
                             //this->val = (double)val;
                             //content[ActiveN-1]=(float)val;
                             content[ActiveN-1]=IntToBool(val);
                         }
                         void TCellBoolArr::SetVal(bool val)
                         {
                             //int i;
                             //i = BoolToInt(val);
                             ////this->val = (double)i;
                             //content[ActiveN-1]=BoolToInt(i);
                             content[ActiveN-1]=val;
                         }
                         void TCellBoolArr::SetVal(QString val) {
                             double x=StrToReal(val);
                             int y;
                             y=IntPart(x);
                             y=(int)round(x);
                             y=val.toInt();
                             content[ActiveN-1]=IntToBool(y);
                         }
                         //
                         void TCellBoolArr::SetValN(double val, int N) {
                             //SetVal(val);
                             this->Length=content.size();
                             if(N>=1 && N<=Length) content[N-1]=IntToBool((int)round(val));
                         }
                         void TCellBoolArr::SetValN(int val, int N) {
                             //SetVal(val);
                             //if(N>=1 && N<=content.size())content[N-1]=(float)val;
                             this->Length=content.size();
                             if(N>=1 && N<=Length) content[N-1]=IntToBool(val);
                         }
                         void TCellBoolArr::SetValN(bool val, int N) {
                             //SetVal(val);
                             //int x=BoolToInt(val);
                             //if(N>=1 && N<=content.size())content[N-1]=x;
                             this->Length=content.size();
                             if(N>=1 && N<=Length)content[N-1]=val;
                         }
                         void TCellBoolArr::SetValN(QString val, int N) {
                             double x;
                             int y;
                             x=StrToReal(val);
                             x=val.toDouble();
                             y=IntPart(x);
                             y=(int)round(x);
                             y=val.toInt();
                             if(N>=1 && N<=content.size())content[N-1]=y;
                         }
                         //
                         void TCellBoolArr::SetByArrDouble(double* val, int Q){
                             int MinN;
                             if(Length>=Q) MinN=Q; else MinN=Length;
                             if(val!=NULL){
                                 for(int i=1; i<=MinN; i++) content[i-1]=(int)round(val[i-1]);
                             }
                             else
                             {
                                //for(int i=1; i<=MinN; i++) content[i-1]=0;
                                //NOp; NULL as argument let it be means nothing to change
                             }
                         }
                         void TCellBoolArr::SetByArrFloat(float* val, int Q){
                             int MinN;
                             if(Length>=Q) MinN=Q; else MinN=Length;
                             if(val!=NULL){
                                 //for(int i=1; i<=MinN; i++) content[i-1]=(float)val[i-1];
                                 for(int i=1; i<=MinN; i++) content[i-1]=val[i-1];
                             }
                             else
                             {
                                //for(int i=1; i<=MinN; i++) content[i-1]=0;
                                //NOp; NULL as argument let it be means nothing to change
                             }
                         }
                         void TCellBoolArr::SetByArrInt(int* val, int Q){
                             int MinN;
                             if(Length>=Q) MinN=Q; else MinN=Length;
                             if(val!=NULL){
                                 for(int i=1; i<=MinN; i++) content[i-1]=BoolToInt(val[i-1]);
                             }
                             else
                             {
                                //for(int i=1; i<=MinN; i++) content[i-1]=0;
                                //NOp; NULL as argument let it be means nothing to change
                             }
                         }
                         void TCellBoolArr::SetByArrBool(bool* val, int Q){
                             int MinN;
                             if(Length>=Q) MinN=Q; else MinN=Length;
                             if(val!=NULL){
                                 for(int i=1; i<=MinN; i++) content[i-1]=val[i-1];
                             }
                             else
                             {
                                //for(int i=1; i<=MinN; i++) content[i-1]=0;
                                //NOp; NULL as argument let it be means nothing to change
                             }
                         }
                         void TCellBoolArr::SetByArrString(QString* val, int Q){
                             double x;
                             int y;
                             int MinN;
                             if(Length>=Q) MinN=Q; else MinN=Length;
                             if(val!=NULL){
                                 for(int i=1; i<=MinN; i++){
                                     x=StrToReal(val[i-1]);
                                     x=val[i-1].toDouble();
                                     y=IntPart(x);
                                     y=(int)round(x);
                                     y=val[i-1].toInt();
                                     content[i-1]=IntToBool(y);
                                 }
                             }
                             else
                             {
                                // for(int i=1; i<=MinN; i++){
                                //     x=0;
                                //     content[i-1]=x;
                                //}
                                //NOp; NULL as argument let it be means nothing to change
                             }
                         }
                         //
                         void TCellBoolArr::SetByArr(double* val, int Q){
                             int MinN;
                             if(Length>=Q) MinN=Q; else MinN=Length;
                             if(val!=NULL){
                                 for(int i=1; i<=MinN; i++) content[i-1]=IntToBool((int)round(val[i-1]));
                             }
                             else
                             {
                                //for(int i=1; i<=MinN; i++) content[i-1]=0;
                                //NOp; NULL as argument let it be means nothing to change
                             }
                         }
                         void TCellBoolArr::SetByArr(int* val, int Q){
                             int MinN;
                             if(Length>=Q) MinN=Q; else MinN=Length;
                             if(val!=NULL){
                                 for(int i=1; i<=MinN; i++) content[i-1]=BoolToInt(val[i-1]);
                             }
                             else
                             {
                                //for(int i=1; i<=MinN; i++) content[i-1]=0;
                                //NOp; NULL as argument let it be means nothing to change
                             }
                         }
                         void TCellBoolArr::SetByArr(bool* val, int Q){
                             int MinN;
                             if(Length>=Q) MinN=Q; else MinN=Length;
                             if(val!=NULL){
                                 for(int i=1; i<=MinN; i++) content[i-1]=BoolToInt(val[i-1]);
                             }
                             else
                             {
                                //for(int i=1; i<=MinN; i++) content[i-1]=0;
                                //NOp; NULL as argument let it be means nothing to change
                             }
                         }
                         void TCellBoolArr::SetByArr(QString* val, int Q){
                             double x;
                             int y;
                             int MinN;
                             if(Length>=Q) MinN=Q; else MinN=Length;
                             if(val!=NULL){
                                 for(int i=1; i<=MinN; i++){
                                     x=StrToReal(val[i-1]);
                                     x=val[i-1].toDouble();
                                     y=IntPart(x);
                                     y=(int)round(x);
                                     y=val[i-1].toInt();
                                     content[i-1]=IntToBool(y);
                                 }
                             }
                             else
                             {
                                // for(int i=1; i<=MinN; i++){
                                //     x=0;
                                //     content[i-1]=x;
                                //}
                                //NOp; NULL as argument let it be means nothing to change
                             }
                         }
                         //
                         void TCellBoolArr::AddOrInsDoubleVal(double val, int N){
                             //SetByValDouble(val);
                             this->Length=this->content.size();
                             if(N>=1 && N<=Length) content.insert(content.begin()+N-1,(int)round(val));
                             else{
                                 content.push_back(IntToBool((int)round(val)));
                                 Length++;
                                 //ActiveN=N;
                             }
                         }
                         void TCellBoolArr::AddOrInsFloatVal(float val, int N){
                             //SetByValDouble(val);
                             //if(N>=1 && N<=content.size()) content.insert(N-1,(float)val);
                             this->Length=this->content.size();
                             if(N>=1 && N<=Length) content.insert(content.begin()+N-1,(int)round(val));
                             else{
                                 //content.push_back((float)val);
                                 content.push_back(IntToBool((int)round(val)));
                                 Length++;
                                 //ActiveN=N;
                             }
                         }
                         void TCellBoolArr::AddOrInsIntVal(int val, int N){
                             //SetByValDouble(val);
                             this->Length=this->content.size();
                             if(N>=1 && N<=Length) content.insert(content.begin()+N-1,IntToBool(val));
                             else{
                                 content.push_back(IntToBool(val));
                                 this->Length++;
                                 //ActiveN=N;
                             }
                         }
                         void TCellBoolArr::AddOrInsBoolVal(bool val, int N){
                             int x=BoolToInt(val);
                             //SetByValDouble(val);
                             this->Length=this->content.size();
                             if(N>=1 && N<=Length){
                                content.insert(content.begin()+N-1,val);
                             }else{
                                 content.push_back(x);
                                 Length++;
                                 //ActiveN=N;
                             }
                         }
                         void TCellBoolArr::AddOrInsStringVal(QString val, int N){
                             double x=StrToReal(val);
                             int y=IntPart(x);
                             x=val.toDouble();
                             y=(int)round(x);
                             //SetByValDouble(val);
                             if(N>=1 && N<=content.size()){
                                 content.insert(content.begin()+N-1,IntToBool(y));
                             }else{
                                 content.push_back(IntToBool(y));
                                 Length++;
                                 //ActiveN=N;
                             }
                         }
                         //
                         void TCellBoolArr::DelValN(int N) {
                            if(N>=1 && N<=content.size()){
                                content.erase(content.begin()+N-1);
                            }
                         }
                         //
                         void TCellBoolArr::GetDoubleArr(double*&Arr,  int&QItems) {
                             QItems=Length;
                             if(Arr!=NULL){
                                 delete[]Arr;
                                 Arr=new double[QItems];
                             }
                             for(int i=1; i<=QItems; i++) Arr[i-1] = GetDoubleValN(i);
                         }
                         void TCellBoolArr::GetFloatArr( float*&Arr, int&QItems){
                             QItems=Length;
                             if(Arr!=NULL){
                                 delete[]Arr;
                                 Arr=new float[QItems];
                             }
                             for(int i=1; i<=QItems; i++) Arr[i-1] = GetFloatValN(i);
                         }
                         void TCellBoolArr::GetIntArr( int*&Arr,  int&QItems){
                             QItems=Length;
                             if(Arr!=NULL){
                                 delete[]Arr;
                                 Arr=new int[QItems];
                             }
                             for(int i=1; i<=QItems; i++) Arr[i-1] = GetIntValN(i);
                         }
                         void TCellBoolArr::GetBoolArr( bool*&Arr,  int&QItems){
                             QItems=Length;
                             if(Arr!=NULL){
                                 delete[]Arr;
                                 Arr=new bool[QItems];
                             }
                             for(int i=1; i<=QItems; i++) Arr[i-1] = GetBoolValN(i);
                         }
                         void TCellBoolArr::ToStringArr(QString*&Arr, int&QItems) {
                             QItems=Length;
                             if(Arr!=NULL){
                                 delete[]Arr;
                                 Arr=new QString[QItems];
                             }
                             for(int i=1; i<=QItems; i++) Arr[i-1] = ToStringN(i);
                         }
                         //
                         void TCellBoolArr::SetNameN(QString name, int N) { SetByValStringN(name, N);  }
                         void TCellBoolArr::SetName1(QString name) { SetByValStringN(name, 1); }
                         void TCellBoolArr::SetName2(QString name) { SetByValStringN(name, 2); }
                         //void TCellBoolArr::SetName3(QString name) { SetByValStringN(name, 3); }
                         //void TCellBoolArr::SetNames(QString* Arr, int Q) { SetByArrString(Arr, Q); }
                         QString TCellBoolArr::GetNameN(int N) { return ToStringN(N); }
                         QString TCellBoolArr::GetName1() { return ToStringN(1); }
                         QString TCellBoolArr::GetName2() { return ToStringN(2); }
                         //QString TCellBoolArr::GetName3() { return ToStringN(3); }
                         //void TCellBoolArr::GetNames(QString*&Arr, int&QItems) { ToStringArr(Arr, QItems); }
                         //int TCellBoolArr::GetLengthOfNamesList() { return 1; }
                         //
                         //
                         void TCellBoolArr::SetItems(QString*items, int Q, int ActiveN){
                             bool val;
                             QString item;
                             //if(this->content==NULL){
                             if(this->content.size()!=0){
                                 //delete this->content;
                                 this->content.clear();
                                 //this->content=NULL;
                                 this->Length=0;
                                 this->ActiveN=0;
                             }
                             if(items!=NULL){
                                 this->Length=Q;
                                 //content=new double[this->Length];
                                 for(int i=1; i<=this->Length; i++){
                                     //this->content[i-1]=items[i-1];
                                     //val=items[i-1].toDouble;
                                     item=items[i-1];
                                     val=IntToBool(item.toInt());
                                     //val=StrToFloat(items[i-1]);
                                     this->content.push_back(val);
                                 }
                                 this->ActiveN=ActiveN;
                                 this->Length=Q;
                                // }
                             }
                         }
                         void TCellBoolArr::GetItems(QString*&items, int&Q){
                             bool val;
                             QString item;
                             if(items!=NULL){
                                 delete[]items;
                             }
                             items=NULL;
                             Q=this->Length;
                             if(this->content.size()>0){
                                items=new QString[Q];
                                for(int i=1; i<=Q; i++){
                                    //val=FloatToStr(this-content[i-1]);
                                    //items[1-1]/*=FloatToStr*/(this-content[i-1]);
                                    val=this->content[i-1];
                                    item=IntToStr(BoolToInt(val));
                                    items[i-1]=item;
                                }
                             }
                         }
                         void TCellBoolArr::SetItem(QString item, int itemN){
                             if(itemN==0){
                                 itemN-=this->Length;
                             }
                             if(itemN>=1 || itemN<=this->Length){
                                 this->content[itemN-1]=IntToBool(item.toInt());//better own fn
                             }
                         }
                         void TCellBoolArr::InsItem(QString item, int itemN){
                             bool val=IntToBool(item.toInt());
                             Array1DInsElementToN(this->content, itemN, val);
                             this->Length+=1;
                         }
                         void TCellBoolArr::AddItem(QString item){
                             bool val=IntToBool(item.toInt());
                             Array1DAddElement(this->content, val);
                             this->Length+=1;
                         }
                         void TCellBoolArr::DelItem(int itemN){
                             Array1DDelElementFromN(this->content, itemN);
                             this->Length-=1;
                         }
                         QString TCellBoolArr::GetItem(int itemN){
                             QString R="0";
                             if(itemN<0){
                                 itemN+=(this->Length+1);
                             }
                             if(itemN==1 && itemN<=this->Length){
                                 R.setNum(this->content[itemN-1]);
                             }
                             return R;
                         }
                         int TCellBoolArr::GetLengthOfItemsList(){ return this->Length; }
                     //     override object Clone(){
                     //        return new TCellBoolArr(this->GetDoubleVal());
                     //    }
            //};//cl TCellBoolArr



   //class TCellStringArr: TDataCell
                         //{
                         //    double val;
                         //    :
                             TCellStringArr::TCellStringArr() {
                                QString val="";
                                //
                                ActiveN=0;
                                Length=0;
                                //
                                ActiveN=1;
                                Length=1;
                                //
                                content.push_back(val);
                             }
                             TCellStringArr::TCellStringArr(double val) { SetByValDouble(val); }
                             TCellStringArr::TCellStringArr(float val) { SetByValFloat(val); }
                             TCellStringArr::TCellStringArr(int val) { SetByValInt(val); }
                             TCellStringArr::TCellStringArr(bool val) { SetByValBool(val); }
                             TCellStringArr::TCellStringArr(QString val) { SetByValString(val); }
                             //
                             TCellStringArr::TCellStringArr(double* val, int Q) { SetByArrDouble(val, Q); }
                             TCellStringArr::TCellStringArr(float* val, int Q) { SetByArrFloat(val, Q); }
                             TCellStringArr::TCellStringArr(int* val, int Q) { SetByArrInt(val, Q); }
                             TCellStringArr::TCellStringArr(bool* val, int Q) { SetByArrBool(val, Q); }
                             TCellStringArr::TCellStringArr(QString* val, int Q) { SetByArrString(val, Q); }
                             //
                             //hope they will not be needed
                         //    TCellStringArr(TCellStringArr&obj){
                         //        this->Assign(obj);
                         //    }
                         //    //
                         //    TCellStringArr& operator =(TCellStringArr&obj){
                         //        this->Assign(obj);
                         //        return*this;
                         //    }
                         //    //
                         //    void Assign(TCellStringArr&obj){
                         //        this->data=obj.data;
                         //    }
                             void TCellStringArr::construct(int n){
                                 //this->val=new QString[n];
                                 //for(int i=1; i<=n; i++) val[i-1]="";
                                 for(int i=1; i<=n; i++) this->content.push_back("");
                             }
                             int TCellStringArr::GetTypeN() { return StringArrayTypeN; }
                             int TCellStringArr::GetActiveN() { return ActiveN;}
                             void TCellStringArr::SetActiveN(int N) {
                                 if(N>=1 && N<=content.size()) this->ActiveN=N;
                             }
                             int TCellStringArr::GetLength() { return Length; }
                             void TCellStringArr::SetLength(int L){
                                 QString val="";
                                 int iL=content.size();
                                 if(L>=1 && L<=MaxInt){
                                     if(L>iL){
                                         for(int i=1; i<=L-iL; i++){
                                            content.push_back(val);
                                         }
                                     }else if(L<iL){
                                         for(int i=1; i<=iL-L; i++){
                                            content.pop_back();
                                         }
                                     }
                                     Length=L;
                                 }
                             }//SetLength
                             //
                             double TCellStringArr::GetDoubleVal() {
                                 double val;
                                 val=StrToReal(content[ActiveN-1]);
                                 //val=(double)content[ActiveN-1];
                                 val=content[ActiveN-1].toDouble();
                                 return val;
                             }
                             float TCellStringArr::GetFloatVal() {
                                 float val;
                                 //val=(floatcontent[ActiveN-1];
                                 val=(float)StrToReal(content[ActiveN-1]);
                                 val=content[ActiveN-1].toFloat();
                                 return val;
                             }
                             int TCellStringArr::GetIntVal()
                             {
                                 int val;
                                 //val=content[ActiveN-1];
                                 val=StrToInt(content[ActiveN-1]);
                                 val=content[ActiveN-1].toInt();
                                 //int r;
                                 //r =(int) round(content[ActiveN-1]);
                                 //r =(int) round(val);
                                 //return r;
                                 return val;
                             }
                             bool TCellStringArr::GetBoolVal() {
                                 bool r, ItIsTrueWord, ItIsFalseWord;
                                 QString val;
                                 ItIsTrueWord=IsTrueWord(content[ActiveN-1]);
                                 ItIsFalseWord=IsFalseWord(content[ActiveN-1]);
                                 //val=content[ActiveN-1];
                                 if(BoolValByDefault==true){
                                     if (ItIsFalseWord) r = false;
                                     else r = true;
                                 }else{
                                     if (ItIsTrueWord) r = true;
                                     else r = false;
                                 }
                                 return r;
                             }
                             QString TCellStringArr::ToString() {
                                 //int val=content[ActiveN-1];
                                 //QString s;
                                 //s=IntToString(val);
                                 //s.setNum(val);
                                 //return s;//val.ToString();
                                 return content[ActiveN-1];
                             }
                             //
                             double TCellStringArr::GetDoubleValN(int N) {
                                 double val=0;
                                 if(N>=1 && N<=content.size()){
                                     val=StrToReal(content[N-1]);
                                     val=content[N-1].toDouble();
                                 }
                                 return val;
                             }
                             float TCellStringArr::GetFloatValN(int N){
                                 float val=0;
                                 if(N>=1 && N<=content.size()){
                                     val=(float)StrToReal(content[N-1]);
                                     val=content[N-1].toFloat();
                                 }
                                 return val;
                             }
                             int TCellStringArr::GetIntValN(int N)
                             {
                                 int r=0;
                                 if(N>=1 && N<=content.size()){
                                    //r = (int)round(content[N-1]);
                                    r = StrToInt(content[N-1]);
                                    r=content[N-1].toInt();
                                 }
                                 return r;
                             }
                             bool TCellStringArr::GetBoolValN(int N)
                             {
                                 bool r=BoolValByDefault, chk=BoolValByDefault;
                                 if(N>=1 && N<=content.size()){
                                     //if(chk==true){
                                     if(BoolValByDefault==true){
                                         if (IsFalseWord(content[N-1])) r = false;
                                         else r = true;
                                     }else{
                                         if (IsTrueWord(content[N-1])) r = true;
                                         else r = false;
                                     }
                                 }
                                 return r;
                             }
                             QString TCellStringArr::ToStringN(int N) {
                                 QString s="";
                                 ////QString RealToString(double x, int Repr_IntAndFrac0_ExpAfOrderLim1_ExpAnyhow2=0,  int QAftComma=6, int OrdAfWhichExp=6, int BaseDec=10);
                                 //int val=content[ActiveN-1];
                                 ////float val=content[ActiveN-1];
                                 //s=IntToString(val);
                                 //s.setNum(val);
                                 //return s;
                                 if(N>=1 && N<=content.size()) s=content[N-1];
                                 return s;
                             }
                             //
                             void TCellStringArr::SetByValDouble(double val) {
                                 QString s;
                                 s.setNum(val);
                                 s=RealToString(val);
                                 content[ActiveN-1]=s;
                             }
                             void TCellStringArr::SetByValFloat(float val) {
                                 QString s;
                                 s.setNum(val);
                                 s=RealToString((double)val);
                                 content[ActiveN-1]=s;
                             }
                             void TCellStringArr::SetByValInt(int val) {
                                 QString s;
                                 s.setNum(val);
                                 s=IntToStr(val);
                                 content[ActiveN-1]=s;
                             }
                             void TCellStringArr::SetByValBool(bool val)
                             {
                                 int i;
                                 i = BoolToInt(val);
                                 //this->val=(double)i;
                                 content[ActiveN-1]=IntToStr(i);
                                 content[ActiveN-1].setNum(i);
                             }
                             void TCellStringArr::SetByValString(QString val) {
                                 content[ActiveN-1]=val;
                             }
                             //
                             void TCellStringArr::SetByValDoubleN(double val, int N) {
                                 //SetByValDouble(val);
                                 if(N>=1 && N<=content.size()) content[N-1]=RealToString(val);
                                 if(N>=1 && N<=content.size()) content[N-1].setNum(val);
                             }
                             void TCellStringArr::SetByValFloatN(float val, int N){
                                 //SetByValFloat(val);
                                 if(N>=1 && N<=content.size()) content[N-1]=RealToString((double)val);
                                 if(N>=1 && N<=content.size()) content[N-1].setNum(val);
                             }
                             void TCellStringArr::SetByValIntN(int val, int N) {
                                 //SetByValInt(val);
                                 this->Length=this->content.size();
                                 if(N>=1 && N<=Length) (content[N-1])=IntToStringSimple(val);
                                 if(N>=1 && N<=Length) content[N-1].setNum(val);
                             }
                             void TCellStringArr::SetByValBoolN(bool val, int N) {
                                 SetByValBool(val);
                                 if(N>=1 && N<=content.size()) content[N-1]=IntToStr(BoolToInt(val));
                                 if(N>=1 && N<=content.size()) content[N-1].setNum(BoolToInt(val));
                             }
                             void TCellStringArr::SetByValStringN(QString val, int N) {
                                 if(N>=1 && N<=content.size())content[N-1]=val;
                             }
                             //
                             void TCellStringArr::SetVal(double val) {
                                 //this->val = (double)val;
                                 content[ActiveN-1]=RealToString(val);
                                 content[ActiveN-1].setNum(val);
                             }
                             void TCellStringArr::SetVal(int val) {
                                 //this->val = (double)val;
                                 //content[ActiveN-1]=(float)val;
                                 content[ActiveN-1]=IntToStr(val);
                                 content[ActiveN-1].setNum(val);
                             }
                             void TCellStringArr::SetVal(bool val)
                             {
                                 int i;
                                 i = BoolToInt(val);
                                 content[ActiveN-1]=IntToStr(i);
                                 content[ActiveN-1].setNum(i);
                             }
                             void TCellStringArr::SetVal(QString val) {
                                 content[ActiveN-1]=val;
                             }
                             //
                             void TCellStringArr::SetValN(double val, int N) {
                                 //SetVal(val);
                                 if(N>=1 && N<=content.size())content[N-1]=RealToString(val);
                                 if(N>=1 && N<=content.size())content[N-1].setNum(val);
                             }
                             void TCellStringArr::SetValN(int val, int N) {
                                 //SetVal(val);
                                 //if(N>=1 && N<=content.size())content[N-1]=(float)val;
                                 if(N>=1 && N<=content.size())content[N-1]=IntToStr(val);
                                 if(N>=1 && N<=content.size())content[N-1].setNum(val);
                             }
                             void TCellStringArr::SetValN(bool val, int N) {
                                 if(N>=1 && N<=content.size())content[N-1]=IntToStr(BoolToInt(val));
                                 if(N>=1 && N<=content.size())content[N-1].setNum(BoolToInt(val));
                             }
                             void TCellStringArr::SetValN(QString val, int N) {
                                 if(N>=1 && N<=content.size())content[N-1]=val;
                             }
                             //
                             void TCellStringArr::SetByArrDouble(double* val, int Q){
                                 int MinN;
                                 if(Length>=Q) MinN=Q; else MinN=Length;
                                 if(val!=NULL){
                                     for(int i=1; i<=MinN; i++){
                                         content[i-1]=RealToString(val[i-1]);
                                         content[i-1].setNum(val[i-1]);
                                     }
                                 }
                                 else
                                 {
                                    //for(int i=1; i<=MinN; i++) content[i-1]=0;
                                    //NOp; NULL as argument let it be means nothing to change
                                 }
                             }
                             void TCellStringArr::SetByArrFloat(float* val, int Q){
                                 int MinN;
                                 if(Length>=Q) MinN=Q; else MinN=Length;
                                 if(val!=NULL){
                                     for(int i=1; i<=MinN; i++){
                                         content[i-1]=RealToString((double)val[i-1]);
                                         content[i-1].setNum(val[i-1]);
                                     }
                                 }
                                 else
                                 {
                                    //for(int i=1; i<=MinN; i++) content[i-1]=0;
                                    //NOp; NULL as argument let it be means nothing to change
                                 }
                             }
                             void TCellStringArr::SetByArrInt(int* val, int Q){
                                 int MinN;
                                 if(Length>=Q) MinN=Q; else MinN=Length;
                                 if(val!=NULL){
                                     for(int i=1; i<=MinN; i++){
                                         content[i-1]=IntToStr(val[i-1]);
                                         content[i-1].setNum(val[i-1]);
                                     }
                                 }
                                 else
                                 {
                                    //for(int i=1; i<=MinN; i++) content[i-1]=0;
                                    //NOp; NULL as argument let it be means nothing to change
                                 }
                             }
                             void TCellStringArr::SetByArrBool(bool* val, int Q){
                                 int MinN;
                                 if(Length>=Q) MinN=Q; else MinN=Length;
                                 if(val!=NULL){
                                     for(int i=1; i<=MinN; i++) {
                                         content[i-1]=IntToStr(BoolToInt(val[i-1]));
                                         content[i-1].setNum(BoolToInt(val[i-1]));
                                     }
                                 }
                                 else
                                 {
                                    //for(int i=1; i<=MinN; i++) content[i-1]=0;
                                    //NOp; NULL as argument let it be means nothing to change
                                 }
                             }
                             void TCellStringArr::SetByArrString(QString* val, int Q){
                                 //double x;
                                 //int y;
                                 int MinN;
                                 if(Length>=Q) MinN=Q; else MinN=Length;
                                 if(val!=NULL){
                                     for(int i=1; i<=MinN; i++){
                                         //x=StrToReal(val[i-1]);
                                         //x=val[i-1].toDouble();
                                         //y=IntPart(x);
                                         //y=(int)round(x);
                                         //y=val[i-1].toInt();
                                         //content[i-1]=y;
                                         content[i-1]=val[i-1];
                                     }
                                 }
                                 else
                                 {
                                    // for(int i=1; i<=MinN; i++){
                                    //     x=0;
                                    //     content[i-1]=x;
                                    //}
                                    //NOp; NULL as argument let it be means nothing to change
                                 }
                             }
                             //
                             void TCellStringArr::SetByArr(double* val, int Q){
                                 int MinN;
                                 if(Length>=Q) MinN=Q; else MinN=Length;
                                 if(val!=NULL){
                                     for(int i=1; i<=MinN; i++){
                                         //content[i-1]=(int)round(val[i-1]);
                                         content[i-1]=RealToString(val[i-1]);
                                         content[i-1].setNum(val[i-1]);
                                     }
                                 }
                                 else
                                 {
                                    //for(int i=1; i<=MinN; i++) content[i-1]=0;
                                    //NOp; NULL as argument let it be means nothing to change
                                 }
                             }
                             void TCellStringArr::SetByArr(int* val, int Q){
                                 int MinN;
                                 if(Length>=Q) MinN=Q; else MinN=Length;
                                 if(val!=NULL){
                                     for(int i=1; i<=MinN; i++){
                                         //content[i-1]=(int)round(val[i-1]);
                                         content[i-1]=RealToString((double)val[i-1]);
                                         content[i-1].setNum(val[i-1]);
                                     }
                                 }
                                 else
                                 {
                                    //for(int i=1; i<=MinN; i++) content[i-1]=0;
                                    //NOp; NULL as argument let it be means nothing to change
                                 }
                             }
                             void TCellStringArr::SetByArr(bool* val, int Q){
                                 int MinN;
                                 if(Length>=Q) MinN=Q; else MinN=Length;
                                 if(val!=NULL){
                                     for(int i=1; i<=MinN; i++){
                                         content[i-1]=IntToStr(BoolToInt(val[i-1]));
                                         content[i-1].setNum(BoolToInt(val[i-1]));
                                     }
                                 }
                                 else
                                 {
                                    //for(int i=1; i<=MinN; i++) content[i-1]=0;
                                    //NOp; NULL as argument let it be means nothing to change
                                 }
                             }
                             void TCellStringArr::SetByArr(QString* val, int Q){
                                 double x;
                                 int y;
                                 int MinN;
                                 if(Length>=Q) MinN=Q; else MinN=Length;
                                 if(val!=NULL){
                                     for(int i=1; i<=MinN; i++){
                                         //x=StrToReal(val[i-1]);
                                         //x=val[i-1].toDouble();
                                         //y=IntPart(x);
                                         //y=(int)round(x);
                                         //y=val[i-1].toInt();
                                         //content[i-1]=y;
                                         content[i-1]=val[i-1];
                                     }
                                 }
                                 else
                                 {
                                    // for(int i=1; i<=MinN; i++){
                                    //     x=0;
                                    //     content[i-1]=x;
                                    //}
                                    //NOp; NULL as argument let it be means nothing to change
                                 }
                             }
                             //
                             void TCellStringArr::AddOrInsDoubleVal(double val, int N){
                                 //SetByValDouble(val);
                                 QString s;
                                 s=RealToString(val);
                                 s.setNum(val);
                                 if(N>=1 && N<=content.size()) content.insert(content.begin()+N-1,s);
                                 else{
                                     content.push_back(s);
                                     Length++;
                                     //ActiveN=N;
                                 }
                             }
                             void TCellStringArr::AddOrInsFloatVal(float val, int N){
                                 //SetByValDouble(val);
                                 //if(N>=1 && N<=content.size()) content.insert(N-1,(float)val);
                                 QString s;
                                 s=RealToString((double)val);
                                 s.setNum(val);
                                 if(N>=1 && N<=content.size()) content.insert(content.begin()+N-1,s);
                                 else{
                                     //content.push_back((float)val);
                                     content.push_back(s);
                                     Length++;
                                     //ActiveN=N;
                                 }
                             }
                             void TCellStringArr::AddOrInsIntVal(int val, int N){
                                 //SetByValDouble(val);
                                 QString s;
                                 s=IntToStringSimple(val);
                                 s.setNum(val);
                                 if(N>=1 && N<=content.size()) content.insert(content.begin()+N-1,s);
                                 else{
                                     content.push_back(s);
                                     Length++;
                                     //ActiveN=N;
                                 }
                             }
                             void TCellStringArr::AddOrInsBoolVal(bool val, int N){
                                 int x=BoolToInt(val);
                                 //SetByValDouble(val);
                                 QString s;
                                 s=IntToStringSimple(x);
                                 s.setNum(x);
                                 if(N>=1 && N<=content.size()){
                                    content.insert(content.begin()+N-1,s);
                                 }else{
                                     content.push_back(s);
                                     Length++;
                                     //ActiveN=N;
                                 }
                             }
                             void TCellStringArr::AddOrInsStringVal(QString val, int N){
                                 //double x=StrToReal(val);
                                 //int y=IntPart(x);
                                 //x=val.toDouble();
                                 //y=(int)round(x);
                                 //SetByValDouble(val);
                                 if(N>=1 && N<=content.size()){
                                    content.insert(content.begin()+N-1,val);
                                 }else{
                                     content.push_back(val);
                                     Length++;
                                     //ActiveN=N;
                                 }
                             }
                             //
                             void TCellStringArr::DelValN(int N) {
                                if(N>=1 && N<=content.size()){
                                    content.erase(content.begin()+N-1);
                                }
                             }
                             //
                             void TCellStringArr::GetDoubleArr(double*&Arr,  int&QItems) {
                                 QItems=Length;
                                 if(Arr!=NULL){
                                     delete[]Arr;
                                     Arr=new double[QItems];
                                 }
                                 for(int i=1; i<=QItems; i++) Arr[i-1] = GetDoubleValN(i);
                             }
                             void TCellStringArr::GetFloatArr( float*&Arr, int&QItems){
                                 QItems=Length;
                                 if(Arr!=NULL){
                                     delete[]Arr;
                                     Arr=new float[QItems];
                                 }
                                 for(int i=1; i<=QItems; i++) Arr[i-1] = GetFloatValN(i);
                             }
                             void TCellStringArr::GetIntArr( int*&Arr,  int&QItems){
                                 QItems=Length;
                                 if(Arr!=NULL){
                                     delete[]Arr;
                                     Arr=new int[QItems];
                                 }
                                 for(int i=1; i<=QItems; i++) Arr[i-1] = GetIntValN(i);
                             }
                             void TCellStringArr::GetBoolArr( bool*&Arr,  int&QItems){
                                 QItems=Length;
                                 if(Arr!=NULL){
                                     delete[]Arr;
                                     Arr=new bool[QItems];
                                 }
                                 for(int i=1; i<=QItems; i++) Arr[i-1] = GetBoolValN(i);
                             }
                             void TCellStringArr::ToStringArr(QString*&Arr, int&QItems) {
                                 QItems=Length;
                                 if(Arr!=NULL){
                                     delete[]Arr;
                                     Arr=new QString[QItems];
                                 }
                                 for(int i=1; i<=QItems; i++) Arr[i-1] = ToStringN(i);
                             }
                             //
                             void TCellStringArr::SetNameN(QString name, int N) { SetByValStringN(name, N);  }
                             void TCellStringArr::SetName1(QString name) { SetByValStringN(name, 1); }
                             void TCellStringArr::SetName2(QString name) { SetByValStringN(name, 2); }
                             //void TCellStringArr::SetName3(QString name) { SetByValStringN(name, 3); }
                             //void TCellStringArr::SetNames(QString* Arr, int Q) { SetByArrString(Arr, Q); }
                             QString TCellStringArr::GetNameN(int N) { return ToStringN(N); }
                             QString TCellStringArr::GetName1() { return ToStringN(1); }
                             QString TCellStringArr::GetName2() { return ToStringN(2); }
                             //QString TCellStringArr::GetName3() { return ToStringN(3); }
                             //void TCellStringArr::GetNames(QString*&Arr, int&QItems) { ToStringArr(Arr, QItems); }
                             //int TCellStringArr::GetLengthOfNamesList() { return 1; }
                             //
                             //
                             void TCellStringArr::SetItems(QString*items, int Q, int ActiveN){
                                 QString val;
                                 QString item;
                                 //if(this->content==NULL){
                                 if(this->content.size()!=0){
                                     //delete this->content;
                                     this->content.clear();
                                     //this->content=NULL;
                                     this->Length=0;
                                     this->ActiveN=0;
                                 }
                                 if(items!=NULL){
                                     this->Length=Q;
                                     //content=new double[this->Length];
                                     for(int i=1; i<=this->Length; i++){
                                         //this->content[i-1]=items[i-1];
                                         //val=items[i-1].toDouble;
                                         item=items[i-1];
                                         val=item;
                                         //val=StrToFloat(items[i-1]);
                                         this->content.push_back(val);
                                     }
                                     this->ActiveN=ActiveN;
                                     this->Length=Q;
                                     //}
                                 }
                             }
                             void TCellStringArr::GetItems(QString*&items, int&Q){
                                 QString val;
                                 QString item;
                                 if(items!=NULL){
                                     delete[]items;
                                 }
                                 items=NULL;
                                 Q=this->Length;
                                 if(this->content.size()>0){
                                    items=new QString[Q];
                                    for(int i=1; i<=Q; i++){
                                        //val=FloatToStr(this-content[i-1]);
                                        //items[1-1]/*=FloatToStr*/(this-content[i-1]);
                                        val=this->content[i-1];
                                        item=val;
                                        items[i-1]=item;
                                    }
                                 }
                             }
                             void TCellStringArr::SetItem(QString item, int itemN){
                                 if(itemN==0){
                                     itemN-=this->Length;
                                 }
                                 if(itemN>=1 || itemN<=this->Length){
                                     this->content[itemN-1]=item;//better own fn
                                 }
                             }
                             void TCellStringArr::InsItem(QString item, int itemN){
                                 QString val=item;//.toDouble();
                                 Array1DInsElementToN(this->content, itemN, val);
                                 this->Length+=1;
                             }
                             void TCellStringArr::AddItem(QString item){
                                QString val=item;//.toDouble();
                                 Array1DAddElement(this->content, val);
                                 this->Length+=1;
                             }
                             void TCellStringArr::DelItem(int itemN){
                                 Array1DDelElementFromN(this->content, itemN);
                                 this->Length-=1;
                             }
                             QString TCellStringArr::GetItem(int itemN){
                                 QString R="";
                                 if(itemN<0){
                                     itemN+=(this->Length+1);
                                 }
                                 if(itemN==1 && itemN<=this->Length){
                                     R=this->content[itemN-1];
                                 }
                                 return R;
                             }
                             int TCellStringArr::GetLengthOfItemsList(){ return this->Length; }
                         //
                         //     override object Clone(){
                         //        return new TCellStringArr(this->GetDoubleVal());
                         //    }
                //};//cl TCellStringArr



                //class TDBCOlHeader_Items_Double: TDataCell
                             //{
                             //    double val;
                             //    :
                                TDBCOlHeader_Items_Double::TDBCOlHeader_Items_Double() {
                                   /*double val=0;
                                   //
                                   ActiveN=0;
                                   Length=0;
                                   //
                                   ActiveN=1;
                                   Length=1;
                                   //
                                   content.push_back(val);*/
                                   this->construct();
                                }
                                //TDBCOlHeader_Items_Double::TDBCOlHeader_Items_Double(double val) { this->construct(); SetByValDouble(val); }
                                //TDBCOlHeader_Items_Double::TDBCOlHeader_Items_Double(float val) { this->construct(); SetByValFloat(val); }
                                //TDBCOlHeader_Items_Double::TDBCOlHeader_Items_Double(int val) {  this->construct(); SetByValInt(val); }
                                //TDBCOlHeader_Items_Double::TDBCOlHeader_Items_Double(bool val) { this->construct(); SetByValBool(val); }
                                //TDBCOlHeader_Items_Double::TDBCOlHeader_Items_Double(QString val) { this->construct(); SetByValString(val); }
                                //
                                TDBCOlHeader_Items_Double::TDBCOlHeader_Items_Double(double* val, int Q) { this->construct(); SetByArrDouble(val, Q); }
                                //TDBCOlHeader_Items_Double::TDBCOlHeader_Items_Double(float* val, int Q) { this->construct(); SetByArrFloat(val, Q); }
                                //TDBCOlHeader_Items_Double::TDBCOlHeader_Items_Double(int* val, int Q) { this->construct(); SetByArrInt(val, Q); }
                                //TDBCOlHeader_Items_Double::TDBCOlHeader_Items_Double(bool* val, int Q) { this->construct(); SetByArrBool(val, Q); }
                                //TDBCOlHeader_Items_Double::TDBCOlHeader_Items_Double(QString* val, int Q) { this->construct();SetByArrString(val, Q); }
                                TDBCOlHeader_Items_Double::TDBCOlHeader_Items_Double(double* val, int QItems, QString* name, int QNames){
                                    int countItems=1, countNames=1;
                                    if(QNames>7)countNames=7;
                                    else if(QNames<1) countNames=1;
                                    else countNames=QNames;
                                    if(QItems>MaxInt)countItems=MaxInt;
                                    else if(QItems<1)countItems=1;
                                    else countItems=QItems;
                                    if(val==NULL){
                                        if(countItems>MaxInt/2)countItems=1;
                                        for(int i=1; i<=countItems; i++)this->content.push_back(0);
                                    }else{
                                        for(int i=1; i<=countItems; i++)this->content.push_back(val[i-1]);
                                    }
                                    //
                                    if(name==NULL){
                                        for(int i=1; i<=countNames; i++)this->names.push_back("");
                                    }else{
                                        for(int i=1; i<=countNames; i++)this->names.push_back(name[i-1]);
                                    }
                                 }

                                 //
                                 //hope they will not be needed
                                 //    TCellDoubleArr(TCellDoubleArr&obj){
                                 //        this->Assign(obj);
                                 //    }
                                 //    //
                                 //    TCellDoubleArr& operator =(TCellDoubleArr&obj){
                                 //        this->Assign(obj);
                                 //        return*this;
                                 //    }
                                 //    //
                                 //    void Assign(TCellDoubleArr&obj){
                                 //        this->data=obj.data;
                                 //    }
                                 void TDBCOlHeader_Items_Double::construct(int n){
                                     //this->val=new double[n];
                                     int qi=7;
                                     for(int i=1; i<=n; i++) this->content.push_back(0);
                                     for(int i=1; i<=qi; i++) this->names.push_back("");
                                 }
                                 int TDBCOlHeader_Items_Double::GetTypeN() { return DoubleItemsDBFieldHeaderCellTypeN; }
                                 int TDBCOlHeader_Items_Double::GetActiveN() { return ActiveN_ByDefault;}
                                 void TDBCOlHeader_Items_Double::SetActiveN(int N) {
                                     if(N>=1 && N<=content.size()) this->ActiveN_ByDefault=N;
                                 }
                                 int TDBCOlHeader_Items_Double::GetLength() { return this->LengthOfItemsSet; }
                                 void TDBCOlHeader_Items_Double::SetLength(int L){
                                     double val=0;
                                     int iL=content.size();
                                     if(L>=1 && L<=MaxInt){
                                         if(L>iL){
                                             for(int i=1; i<=L-iL; i++){
                                                content.push_back(val);
                                             }
                                         }else if(L<iL){
                                             for(int i=1; i<=iL-L; i++){
                                                content.pop_back();
                                             }
                                         }
                                         this->LengthOfItemsSet=L;
                                     }
                                 }//SetLength
                                 //
                                 double TDBCOlHeader_Items_Double::GetDoubleVal() {
                                    int ActiveN=1;
                                    double val;
                                    val=content[ActiveN-1];
                                    return val;
                                 }
                                 float TDBCOlHeader_Items_Double::GetFloatVal() {
                                      int ActiveN=1;
                                     float val;
                                     val=(float)content[ActiveN-1];
                                     return val;
                                 }
                                 int TDBCOlHeader_Items_Double::GetIntVal()
                                 {
                                      int ActiveN=1;
                                     double val;
                                     val=content[ActiveN-1];
                                     int r;
                                     //r =(int) round(content[ActiveN-1]);
                                     r =(int) round(val);
                                     return r;
                                 }
                                 bool TDBCOlHeader_Items_Double::GetBoolVal() {
                                     bool r;
                                      int ActiveN=1;
                                     double val=content[ActiveN-1];
                                     if(BoolValByDefault==true){
                                         if (val == 0) r = false;
                                         else r = true;
                                     }else{
                                         if (val == 1) r = true;
                                         else r = false;
                                     }
                                     return r;
                                 }
                                 QString TDBCOlHeader_Items_Double::ToString() {
                                     int ActiveN=1;
                                     double val=content[ActiveN-1];
                                     QString s;
                                     s=RealToString(val);
                                     s.setNum(val);
                                     return s;//val.ToString();
                                 }
                                 //
                                 double TDBCOlHeader_Items_Double::GetDoubleValN(int N) {
                                     double val=0;
                                     if(N>=1 && N<=content.size()){
                                         val=content[N-1];
                                     }
                                     return val;
                                 }
                                 float TDBCOlHeader_Items_Double::GetFloatValN(int N){
                                     float val=0;
                                     if(N>=1 && N<=content.size()){
                                         val=(float)content[N-1];
                                     }
                                     return val;
                                 }
                                 int TDBCOlHeader_Items_Double::GetIntValN(int N)
                                 {
                                     int r=0;
                                     double val=0;
                                     this->LengthOfItemsSet=this->content.size();
                                     if(N>=1 && N<=this->LengthOfItemsSet){
                                         val=this->content[N-1];
                                         r = (int)round(val);
                                     }
                                     return r;
                                 }
                                 bool TDBCOlHeader_Items_Double::GetBoolValN(int N)
                                 {
                                     double val;
                                     bool r=BoolValByDefault;
                                     this->LengthOfItemsSet=this->content.size();
                                     if(N>= 1 && N<=LengthOfItemsSet){
                                         val=this->content[N-1];
                                         if(BoolValByDefault==true){
                                            if (val == 0) r = false;
                                             else r = true;
                                        }else{
                                            if (val == 1) r = true;
                                            else r = false;
                                        }
                                     }
                                     return r;
                                 }
                                 QString TDBCOlHeader_Items_Double::ToStringN(int N) {
                                     QString s;
                                     //QString RealToString(double x, int Repr_IntAndFrac0_ExpAfOrderLim1_ExpAnyhow2=0,  int QAftComma=6, int OrdAfWhichExp=6, int BaseDec=10);
                                     double val=content[N-1];
                                     s=RealToString(val);
                                     s.setNum(val);
                                     return s;
                                 }
                                 //
                                 void TDBCOlHeader_Items_Double::SetByValDouble(double val) {
                                     //this->val = (double)val;
                                     int ActiveN=1;
                                     content[ActiveN-1]=val;
                                 }
                                 void TDBCOlHeader_Items_Double::SetByValFloat(float val) {
                                     //this->val = (double)val;
                                     int ActiveN=1;
                                     content[ActiveN-1]=(double)val;
                                 }
                                 void TDBCOlHeader_Items_Double::SetByValInt(int val) {
                                     //this->val = (double)val;
                                     int ActiveN=1;
                                     content[ActiveN-1]=(double)val;
                                 }
                                 void TDBCOlHeader_Items_Double::SetByValBool(bool val)
                                 {
                                     int i;
                                     i = BoolToInt(val);
                                     int ActiveN=1;
                                     //this->val=(double)i;
                                     content[ActiveN-1]=(double)i;
                                 }
                                 void TDBCOlHeader_Items_Double::SetByValString(QString val) {
                                     double x;
                                     int ActiveN=1;
                                     //this->val = Convert.ToDouble(val);
                                     //this->val = NumberParse.StrToFloat(val);
                                     x=StrToReal(val);
                                     x =val.toDouble();
                                     content[ActiveN-1]=x;
                                 } //hin S' ne abl convert!!
                                 //
                                 void TDBCOlHeader_Items_Double::SetByValDoubleN(double val, int N) {
                                     //SetByValDouble(val);
                                     if(N>=1 && N<=content.size()) content[N-1]=val;
                                 }
                                 void TDBCOlHeader_Items_Double::SetByValFloatN(float val, int N){
                                     //SetByValFloat(val);
                                     if(N>=1 && N<=content.size()) content[N-1]=(double)val;
                                 }
                                 void TDBCOlHeader_Items_Double::SetByValIntN(int val, int N) {
                                     //SetByValInt(val);
                                     if(N>=1 && N<=content.size()) content[N-1]=(double)val;
                                 }
                                 void TDBCOlHeader_Items_Double::SetByValBoolN(bool val, int N) {
                                     SetByValBool(val);
                                     if(N>=1 && N<=content.size()) content[N-1]=(double)BoolToInt(val);
                                 }
                                 void TDBCOlHeader_Items_Double::SetByValStringN(QString val, int N) {
                                     SetByValString(val);
                                     double x;
                                     x=StrToReal(val);
                                     x=val.toDouble();
                                     if(N>=1 && N<=content.size()) content[N-1]=x;
                                 }
                                 //
                                 void TDBCOlHeader_Items_Double::SetVal(double val) {
                                     //this->val = (double)val;
                                     int ActiveN=1;
                                     content[ActiveN-1]=val;
                                 }
                                 void TDBCOlHeader_Items_Double::SetVal(int val) {
                                     //this->val = (double)val;
                                     int ActiveN=1;
                                     content[ActiveN-1]=(double)val;
                                 }
                                 void TDBCOlHeader_Items_Double::SetVal(bool val)
                                 {
                                     int i;
                                     int ActiveN=1;
                                     i = BoolToInt(val);
                                     //this->val = (double)i;
                                     content[ActiveN-1]=(double)i;
                                 }
                                 void TDBCOlHeader_Items_Double::SetVal(QString val) {
                                     double x;
                                     int ActiveN=1;
                                     //this->val = Convert.ToDouble(val);
                                     //this->val=StrToReal(val);
                                     //this->val=val.toDouble();
                                     x=StrToReal(val);
                                     x=val.toDouble();
                                     content[ActiveN-1]=x;
                                 }
                                 //
                                 void TDBCOlHeader_Items_Double::SetValN(double val, int N) {
                                     //SetVal(val);
                                     if(N>=1 && N<=content.size())content[N-1]=val;
                                 }
                                 void TDBCOlHeader_Items_Double::SetValN(int val, int N) {
                                     //SetVal(val);
                                     if(N>=1 && N<=content.size())content[N-1]=(double)val;
                                 }
                                 void TDBCOlHeader_Items_Double::SetValN(bool val, int N) {
                                     //SetVal(val);
                                     int x=BoolToInt(val);
                                     if(N>=1 && N<=content.size())content[N-1]=(double)x;
                                 }
                                 void TDBCOlHeader_Items_Double::SetValN(QString val, int N) {
                                     //SetVal(val);
                                     double x=StrToReal(val);
                                     x=val.toDouble();
                                     if(N>=1 && N<=content.size())content[N-1]=x;
                                 }
                                 //
                                 void TDBCOlHeader_Items_Double::SetByArrDouble(double* val, int Q){
                                     int MinN;
                                     this->LengthOfItemsSet=this->content.size();
                                     if(this->LengthOfItemsSet>=Q) MinN=Q; else MinN=this->LengthOfItemsSet;
                                     if(val!=NULL){
                                         for(int i=1; i<=MinN; i++) content[i-1]=val[i-1];
                                     }
                                     else
                                     {
                                        //for(int i=1; i<=MinN; i++) content[i-1]=0;
                                        //NOp; NULL as argument let it be means nothing to change
                                     }
                                 }
                                 void TDBCOlHeader_Items_Double::SetByArrFloat(float* val, int Q){
                                     int MinN;
                                     if(this->LengthOfItemsSet>=Q) MinN=Q; else MinN=this->LengthOfItemsSet;
                                     if(val!=NULL){
                                         for(int i=1; i<=MinN; i++) content[i-1]=(double)val[i-1];
                                     }
                                     else
                                     {
                                        //for(int i=1; i<=MinN; i++) content[i-1]=0;
                                        //NOp; NULL as argument let it be means nothing to change
                                     }
                                 }
                                 void TDBCOlHeader_Items_Double::SetByArrInt(int* val, int Q){
                                     int MinN;
                                     if(this->LengthOfItemsSet>=Q) MinN=Q; else MinN=this->LengthOfItemsSet;
                                     if(val!=NULL){
                                         for(int i=1; i<=MinN; i++) content[i-1]=(double)val[i-1];
                                     }
                                     else
                                     {
                                        //for(int i=1; i<=MinN; i++) content[i-1]=0;
                                        //NOp; NULL as argument let it be means nothing to change
                                     }
                                 }
                                 void TDBCOlHeader_Items_Double::SetByArrBool(bool* val, int Q){
                                     int MinN;
                                     if(this->LengthOfItemsSet>=Q) MinN=Q; else MinN=this->LengthOfItemsSet;
                                     if(val!=NULL){
                                         for(int i=1; i<=MinN; i++) content[i-1]=(double)BoolToInt(val[i-1]);
                                     }
                                     else
                                     {
                                        //for(int i=1; i<=MinN; i++) content[i-1]=0;
                                        //NOp; NULL as argument let it be means nothing to change
                                     }
                                 }
                                 void TDBCOlHeader_Items_Double::SetByArrString(QString* val, int Q){
                                     double x;
                                     int MinN;
                                     if(this->LengthOfItemsSet>=Q) MinN=Q; else MinN=this->LengthOfItemsSet;
                                     if(val!=NULL){
                                         for(int i=1; i<=MinN; i++){
                                             x=StrToReal(val[i-1]);
                                             x=val[i-1].toDouble();
                                             content[i-1]=x;
                                         }
                                     }
                                     else
                                     {
                                        // for(int i=1; i<=MinN; i++){
                                        //     x=0;
                                        //     content[i-1]=x;
                                        //}
                                        //NOp; NULL as argument let it be means nothing to change
                                     }
                                 }
                                 //
                                 void TDBCOlHeader_Items_Double::SetByArr(double* val, int Q){
                                     int MinN;
                                     if(this->LengthOfItemsSet>=Q) MinN=Q; else MinN=this->LengthOfItemsSet;
                                     if(val!=NULL){
                                         for(int i=1; i<=MinN; i++) content[i-1]=val[i-1];
                                     }
                                     else
                                     {
                                        //for(int i=1; i<=MinN; i++) content[i-1]=0;
                                        //NOp; NULL as argument let it be means nothing to change
                                     }
                                 }
                                 void TDBCOlHeader_Items_Double::SetByArr(int* val, int Q){
                                     int MinN;
                                     if(this->LengthOfItemsSet>=Q) MinN=Q; else MinN=this->LengthOfItemsSet;
                                     if(val!=NULL){
                                         for(int i=1; i<=MinN; i++) content[i-1]=(double)val[i-1];
                                     }
                                     else
                                     {
                                        //for(int i=1; i<=MinN; i++) content[i-1]=0;
                                        //NOp; NULL as argument let it be means nothing to change
                                     }
                                 }
                                 void TDBCOlHeader_Items_Double::SetByArr(bool* val, int Q){
                                     int MinN;
                                     if(this->LengthOfItemsSet>=Q) MinN=Q; else MinN=this->LengthOfItemsSet;
                                     if(val!=NULL){
                                         for(int i=1; i<=MinN; i++) content[i-1]=(double)BoolToInt(val[i-1]);
                                     }
                                     else
                                     {
                                        //for(int i=1; i<=MinN; i++) content[i-1]=0;
                                        //NOp; NULL as argument let it be means nothing to change
                                     }
                                 }
                                 void TDBCOlHeader_Items_Double::SetByArr(QString* val, int Q){
                                     double x;
                                     int MinN;
                                     if(this->LengthOfItemsSet>=Q) MinN=Q; else MinN=this->LengthOfItemsSet;
                                     if(val!=NULL){
                                         for(int i=1; i<=MinN; i++){
                                             x=StrToReal(val[i-1]);
                                             x=val[i-1].toDouble();
                                             content[i-1]=x;
                                         }
                                     }
                                     else
                                     {
                                        // for(int i=1; i<=MinN; i++){
                                        //     x=0;
                                        //     content[i-1]=x;
                                        //}
                                        //NOp; NULL as argument let it be means nothing to change
                                     }
                                 }
                                 //
                                 void TDBCOlHeader_Items_Double::AddOrInsDoubleVal(double val, int N){
                                     //SetByValDouble(val);
                                     this->LengthOfItemsSet=this->content.size();
                                     if(N>=1 && N<=this->LengthOfItemsSet) content.insert(content.begin()+N-1,val);
                                     else{
                                         content.push_back(val);
                                         this->LengthOfItemsSet++;
                                         //ActiveN=N;
                                     }
                                 }
                                 void TDBCOlHeader_Items_Double::AddOrInsFloatVal(float val, int N){
                                     //SetByValDouble(val);
                                     this->LengthOfItemsSet=this->content.size();
                                     if(N>=1 && N<=this->LengthOfItemsSet) content.insert(content.begin()+N-1,(double)val);
                                     else{
                                         content.push_back((double)val);
                                         this->LengthOfItemsSet++;
                                         //ActiveN=N;
                                     }
                                 }
                                 void TDBCOlHeader_Items_Double::AddOrInsIntVal(int val, int N){
                                     //SetByValDouble(val);
                                     this->LengthOfItemsSet=this->content.size();
                                     if(N>=1 && N<=this->LengthOfItemsSet) content.insert(content.begin()+N-1,(double)val);
                                     else{
                                         content.push_back((double)val);
                                         this->LengthOfItemsSet++;
                                         //ActiveN=N;
                                     }
                                 }
                                 void TDBCOlHeader_Items_Double::AddOrInsBoolVal(bool val, int N){
                                     int x=BoolToInt(val);
                                     //SetByValDouble(val);
                                     this->LengthOfItemsSet=this->content.size();
                                     if(N>=1 && N<=this->LengthOfItemsSet) {
                                         content.insert(content.begin()+N-1,(double)x);
                                     }else{
                                         content.push_back((double)x);
                                         this->LengthOfItemsSet++;
                                         //ActiveN=N;
                                     }
                                 }
                                 void TDBCOlHeader_Items_Double::AddOrInsStringVal(QString val, int N){
                                     double x=StrToReal(val);
                                     x=val.toDouble();
                                     //SetByValDouble(val);
                                     this->LengthOfItemsSet=this->content.size();
                                     if(N>=1 && N<=this->LengthOfItemsSet){
                                         content.insert(content.begin()+N-1,x);
                                     }else{
                                         content.push_back(x);
                                         this->LengthOfItemsSet++;
                                         //ActiveN=N;
                                     }
                                 }
                                 //
                                 void TDBCOlHeader_Items_Double::DelValN(int N) {
                                     this->LengthOfItemsSet=this->content.size();
                                     if(N>=1 && N<=this->LengthOfItemsSet){
                                         content.erase(content.begin()+N-1);
                                    }
                                 }
                                 //
                                 void TDBCOlHeader_Items_Double::GetDoubleArr(double*&Arr,  int&QItems) {
                                     QItems=this->LengthOfItemsSet;
                                     if(Arr!=NULL){
                                         delete[]Arr;
                                         Arr=new double[QItems];
                                     }
                                     for(int i=1; i<=QItems; i++) Arr[i-1] = GetDoubleValN(i);
                                 }
                                 void TDBCOlHeader_Items_Double::GetFloatArr( float*&Arr, int&QItems){
                                     QItems=this->LengthOfItemsSet;
                                     if(Arr!=NULL){
                                         delete[]Arr;
                                         Arr=new float[QItems];
                                     }
                                     for(int i=1; i<=QItems; i++) Arr[i-1] = GetFloatValN(i);
                                 }
                                 void TDBCOlHeader_Items_Double::GetIntArr( int*&Arr,  int&QItems){
                                     QItems=this->LengthOfItemsSet;
                                     if(Arr!=NULL){
                                         delete[]Arr;
                                         Arr=new int[QItems];
                                     }
                                     for(int i=1; i<=QItems; i++) Arr[i-1] = GetIntValN(i);
                                 }
                                 void TDBCOlHeader_Items_Double::GetBoolArr( bool*&Arr,  int&QItems){
                                     QItems=this->LengthOfItemsSet;
                                     if(Arr!=NULL){
                                         delete[]Arr;
                                         Arr=new bool[QItems];
                                     }
                                     for(int i=1; i<=QItems; i++) Arr[i-1] = GetBoolValN(i);
                                 }
                                 void TDBCOlHeader_Items_Double::ToStringArr(QString*&Arr, int&QItems) {
                                     QItems=this->LengthOfItemsSet;
                                     if(Arr!=NULL){
                                         delete[]Arr;
                                         Arr=new QString[QItems];
                                     }
                                     for(int i=1; i<=QItems; i++) Arr[i-1] = ToStringN(i);
                                 }
                                 //
                                 void TDBCOlHeader_Items_Double::SetNameN(QString name, int N) {
                                     if(N>=1 && N<=7){
                                         while(this->names.size()<N-1){
                                             this->names.push_back("");
                                         }
                                         this->names[N-1]=name;
                                     }
                                 }
                                 void TDBCOlHeader_Items_Double::SetName1(QString name){
                                     int N=1;
                                     while(this->names.size()<N-1){
                                         this->names.push_back("");
                                     }
                                     this->names[N-1]=name;
                                  }
                                 void TDBCOlHeader_Items_Double::SetName2(QString name){
                                     int N=2;
                                     while(this->names.size()<N-1){
                                         this->names.push_back("");
                                     }
                                     this->names[N-1]=name;
                                  }
                                 //void TDBCOlHeader_Items_Double::SetName3(QString name){
                                 //    int N=3;
                                 //    while(this->names.size()<N-1){
                                 //        this->names.push_back("");
                                 //    }
                                 //    this->names[N-1]=name;
                                 // }
                                 //void TDBCOlHeader_Items_Double::SetNames(QString* Arr, int Q){
                                 //   this->LengthOfNamesSet=this->names.size();
                                 //   if(Q>=1 && Q<=7){
                                 //       for(int i=1; i<=Q; i++){
                                 //           if(this->LengthOfItemsSet<=Q) this->names[i-1]=Arr[i-1];
                                 //           else this->names.push_back(Arr[i-1]);
                                //        }
                                 //   }
                                 //}
                                 QString TDBCOlHeader_Items_Double::GetNameN(int N) {
                                     QString R="";
                                     this->LengthOfNamesSet=this->names.size();
                                     if(N>=1 && N<=7 && N<this->LengthOfItemsSet) R=this->names[N-1];
                                     return R;
                                 }
                                 QString TDBCOlHeader_Items_Double::GetName1() {
                                     int N=1;
                                     QString R="";
                                     this->LengthOfNamesSet=this->names.size();
                                     if(N>=1 && N<=7 && N<=this->LengthOfItemsSet) R=this->names[N-1];
                                     return R;
                                 }
                                 QString TDBCOlHeader_Items_Double::GetName2() {
                                     int N=2;
                                     QString R="";
                                      this->LengthOfNamesSet=this->names.size();
                                     if(N>=1 && N<=7 && N<=this->LengthOfItemsSet) R=this->names[N-1];
                                     return R;
                                 }
                                 //QString TDBCOlHeader_Items_Double::GetName3() {
                                 //    int N=3;
                                 //    QString R="";
                                 //     this->LengthOfNamesSet=this->names.size();
                                 //    if(N>=1 && N<=7 && N<=this->LengthOfNamesSet) R=this->names[N-1];
                                 //    return R;
                                 //}
                                 //void TDBCOlHeader_Items_Double::GetNames(QString*&Arr, int&QItems) {
                                 //       if(Arr!=NULL) delete[]Arr;
                                 //       QItems=this->GetLengthOfNamesList();
                                 //       if(Arr==NULL) Arr=new QString[QItems];
                                 //       for(int i=1; i<=QItems; i++) Arr[i-1]=this->names[i-1];
                                 //}
                                // int TDBCOlHeader_Items_Double::GetLengthOfNamesList(){
                                 //    this->LengthOfNamesSet=this->names.size();
                                //     return this->LengthOfNamesSet;
                                // }
                                 //
                                 void TDBCOlHeader_Items_Double::SetItems(QString*items, int Q, int ActiveN){
                                     double val;
                                     QString item;
                                     //if(this->content==NULL){
                                     if(this->content.size()!=0){
                                         //delete this->content;
                                         this->content.clear();
                                         //this->content=NULL;
                                         this->LengthOfItemsSet=0;
                                         //this->ActiveN=0;
                                     }
                                     if(items!=NULL){
                                         this->LengthOfItemsSet=Q;
                                         //content=new double[this->Length];
                                         for(int i=1; i<=this->LengthOfItemsSet; i++){
                                             //this->content[i-1]=items[i-1];
                                             //val=items[i-1].toDouble;
                                             item=items[i-1];
                                             val=item.toDouble();
                                             //val=StrToFloat(items[i-1]);
                                             this->content.push_back(val);
                                         }
                                         //this->ActiveN=ActiveN;
                                         this->LengthOfItemsSet=Q;
                                         //}
                                     }
                                 }
                                 void TDBCOlHeader_Items_Double::GetItems(QString*&items, int&Q){
                                     double val;
                                     QString item;
                                     if(items!=NULL){
                                         delete[]items;
                                     }
                                     items=NULL;
                                     Q=this->LengthOfItemsSet;
                                     if(this->content.size()>0){
                                        items=new QString[Q];
                                        for(int i=1; i<=Q; i++){
                                            //val=FloatToStr(this-content[i-1]);
                                            //items[1-1]/*=FloatToStr*/(this-content[i-1]);
                                            val=this->content[i-1];
                                            item=FloatToStr(val);
                                            items[i-1]=item;
                                        }
                                     }
                                 }
                                 void TDBCOlHeader_Items_Double::SetItem(QString item, int itemN){
                                     if(itemN==0){
                                         itemN-=this->LengthOfItemsSet;
                                     }
                                     if(itemN>=1 || itemN<=this->LengthOfItemsSet){
                                         this->content[itemN-1]=item.toDouble();//better own fn
                                     }
                                 }
                                 void TDBCOlHeader_Items_Double::InsItem(QString item, int itemN){
                                     double val=item.toDouble();
                                     Array1DInsElementToN(this->content, itemN, val);
                                     this->LengthOfItemsSet+=1;
                                 }
                                 void TDBCOlHeader_Items_Double::AddItem(QString item){
                                     double val=item.toDouble();
                                     Array1DAddElement(this->content, val);
                                     this->LengthOfItemsSet+=1;
                                 }
                                 void TDBCOlHeader_Items_Double::DelItem(int itemN){
                                     Array1DDelElementFromN(this->content, itemN);
                                     this->LengthOfItemsSet-=1;
                                 }
                                 QString TDBCOlHeader_Items_Double::GetItem(int itemN){
                                     QString R="0";
                                     if(itemN<0){
                                         itemN+=(this->LengthOfItemsSet+1);
                                     }
                                     if(itemN==1 && itemN<=this->LengthOfItemsSet){
                                         R.setNum(this->content[itemN-1]);
                                     }
                                     return R;
                                 }
                                 int TDBCOlHeader_Items_Double::GetLengthOfItemsList(){ return this->LengthOfItemsSet; }
                             //     override object Clone(){
                             //        return new TCellDoubleArr(this->GetDoubleVal());
                             //    }
                    //};//cl TDBCOlHeader_Items_Double


                                 //TCellIntArr

                                 //class TDBCOlHeader_Items_Int: TDataCell
                                 //{
                                 //    double val;
                                 //    :
                                     TDBCOlHeader_Items_Int::TDBCOlHeader_Items_Int() {
                                        //double val=0;
                                        ////
                                        //ActiveN=0;
                                        //Length=0;
                                        ////
                                        //ActiveN=1;
                                        //Length=1;
                                        ////
                                        //content.push_back(val);
                                        ////
                                        this->construct();
                                     }
                                     void TDBCOlHeader_Items_Int::construct(int n){
                                         //this->val=new double[n];
                                         int qi=7;
                                         for(int i=1; i<=n; i++) this->content.push_back(0);
                                         for(int i=1; i<=qi; i++) this->names.push_back("");
                                     }
                                     //TDBCOlHeader_Items_Int::TDBCOlHeader_Items_Int(double val) { SetByValDouble(val); }
                                     //TDBCOlHeader_Items_Int::TDBCOlHeader_Items_Int(float val) { SetByValFloat(val); }
                                     //TDBCOlHeader_Items_Int::TDBCOlHeader_Items_Int(int val) { SetByValInt(val); }
                                     //TDBCOlHeader_Items_Int::TDBCOlHeader_Items_Int(bool val) { SetByValBool(val); }
                                     //TDBCOlHeader_Items_Int::TDBCOlHeader_Items_Int(QString val) { SetByValString(val); }
                                     //
                                     //TDBCOlHeader_Items_Int::TDBCOlHeader_Items_Int(double* val, int Q) { SetByArrDouble(val, Q); }
                                     //TDBCOlHeader_Items_Int::TDBCOlHeader_Items_Int(float* val, int Q) { SetByArrFloat(val, Q); }
                                     TDBCOlHeader_Items_Int::TDBCOlHeader_Items_Int(int* val, int Q) {  this->construct();SetByArrInt(val, Q); }
                                     //TDBCOlHeader_Items_Int::TDBCOlHeader_Items_Int(bool* val, int Q) { SetByArrBool(val, Q); }
                                     //TDBCOlHeader_Items_Int::TDBCOlHeader_Items_Int(QString* val, int Q) { this->construct(); SetByArrString(val, Q); }
                                     TDBCOlHeader_Items_Int::TDBCOlHeader_Items_Int(int* val, int QItems, QString* name, int QNames){
                                         int countItems=1, countNames=1;
                                         if(QNames>7)countNames=7;
                                         else if(QNames<1) countNames=1;
                                         else countNames=QNames;
                                         if(QItems>MaxInt)countItems=MaxInt;
                                         else if(QItems<1)countItems=1;
                                         else countItems=QItems;
                                         if(val==NULL){
                                             if(countItems>MaxInt/2)countItems=1;
                                             for(int i=1; i<=countItems; i++)this->content.push_back(0);
                                         }else{
                                             for(int i=1; i<=countItems; i++)this->content.push_back(val[i-1]);
                                         }
                                         //
                                         if(name==NULL){
                                             for(int i=1; i<=countNames; i++)this->names.push_back("");
                                         }else{
                                             for(int i=1; i<=countNames; i++)this->names.push_back(name[i-1]);
                                         }
                                     }
                                     //
                                     //hope they will not be needed
                                 //    TDBCOlHeader_Items_Int(TDBCOlHeader_Items_Int&obj){
                                 //        this->Assign(obj);
                                 //    }
                                 //    //
                                 //    TDBCOlHeader_Items_Int& operator =(TDBCOlHeader_Items_Int&obj){
                                 //        this->Assign(obj);
                                 //        return*this;
                                 //    }
                                 //    //
                                 //    void Assign(TDBCOlHeader_Items_Int&obj){
                                 //        this->data=obj.data;
                                 //    }
                                     int TDBCOlHeader_Items_Int::GetTypeN() { return IntArrayTypeN; }
                                     int TDBCOlHeader_Items_Int::GetActiveN() { return ActiveN_ByDefault;}
                                     void TDBCOlHeader_Items_Int::SetActiveN(int N) {
                                         if(N>=1 && N<=content.size()) this->ActiveN_ByDefault=N;
                                     }
                                     int TDBCOlHeader_Items_Int::GetLength() { return this->LengthOfItemsSet; }
                                     void TDBCOlHeader_Items_Int::SetLength(int L){
                                         int val=0;
                                         int iL=content.size();
                                         if(L>=1 && L<=MaxInt){
                                             if(L>iL){
                                                 for(int i=1; i<=L-iL; i++){
                                                    content.push_back(val);
                                                 }
                                             }else if(L<iL){
                                                 for(int i=1; i<=iL-L; i++){
                                                    content.pop_back();
                                                 }
                                             }
                                             this->LengthOfItemsSet=L;
                                         }
                                     }//SetLength
                                     //
                                     double TDBCOlHeader_Items_Int::GetDoubleVal() {
                                        int ActiveN=1;
                                         double val;
                                        val=(double)content[ActiveN-1];
                                        return val;
                                     }
                                     float TDBCOlHeader_Items_Int::GetFloatVal() {
                                         int ActiveN=1;
                                         float val;
                                         val=(float)content[ActiveN-1];
                                         return val;
                                     }
                                     int TDBCOlHeader_Items_Int::GetIntVal()
                                     {
                                         int ActiveN=1;
                                         int val;
                                         val=content[ActiveN-1];
                                         //int r;
                                         //r =(int) round(content[ActiveN-1]);
                                         //r =(int) round(val);
                                         //return r;
                                         return val;
                                     }
                                     bool TDBCOlHeader_Items_Int::GetBoolVal() {
                                         bool r;
                                         int ActiveN=1;
                                         int val=content[ActiveN-1];
                                         if(BoolValByDefault==true){
                                             if (val == 0) r = false;
                                             else r = true;
                                         }else{
                                             if (val == 1) r = true;
                                             else r = false;
                                         }
                                         return r;
                                     }
                                     QString TDBCOlHeader_Items_Int::ToString() {
                                         int ActiveN=1;
                                         int val=content[ActiveN-1];
                                         QString s;
                                         s=IntToStringSimple(val);
                                         s.setNum(val);
                                         return s;//val.ToString();
                                     }
                                     //
                                     double TDBCOlHeader_Items_Int::GetDoubleValN(int N) {
                                         double val=0;
                                         if(N>=1 && N<=content.size()){
                                             val=(double)content[N-1];
                                         }
                                         return val;
                                     }
                                     float TDBCOlHeader_Items_Int::GetFloatValN(int N){
                                         float val=0;
                                         if(N>=1 && N<=content.size()){
                                             val=(float)content[N-1];
                                         }
                                         return val;
                                     }
                                     int TDBCOlHeader_Items_Int::GetIntValN(int N)
                                     {
                                         int r=0;
                                         if(N>=1 && N<=content.size()){
                                            //r = (int)round(content[N-1]);
                                            r = content[N-1];
                                         }
                                         return r;
                                     }
                                     bool TDBCOlHeader_Items_Int::GetBoolValN(int N)
                                     {
                                         int val;
                                         bool r=BoolValByDefault, chk=BoolValByDefault;
                                         //if(chk==true){
                                         this->LengthOfItemsSet=this->content.size();
                                         if(N>=1 && N<=this->LengthOfItemsSet){
                                             val=content[N-1];
                                             if(BoolValByDefault==true){
                                                if (val == 0) r = false;
                                                else r = true;
                                            }else{
                                                if (val == 1) r = true;
                                                else r = false;
                                            }
                                         }
                                         return r;
                                     }
                                     QString TDBCOlHeader_Items_Int::ToStringN(int N) {
                                         int ActiveN=1;
                                         QString s="";
                                         //QString RealToString(double x, int Repr_IntAndFrac0_ExpAfOrderLim1_ExpAnyhow2=0,  int QAftComma=6, int OrdAfWhichExp=6, int BaseDec=10);
                                         int val=content[ActiveN-1];
                                         //float val=content[ActiveN-1];
                                         s=IntToStringSimple(val);
                                         s.setNum(val);
                                         return s;
                                     }
                                     //
                                     void TDBCOlHeader_Items_Int::SetByValDouble(double val) {
                                         int ActiveN=1;
                                         //this->val = (double)val;
                                         int y=(int)round(val);
                                         content[ActiveN-1]=y;
                                     }
                                     void TDBCOlHeader_Items_Int::SetByValFloat(float val) {
                                        int ActiveN=1;
                                         //this->val = (double)val;
                                         //content[ActiveN-1]=(float)val;
                                         //int y=(int)round(val);
                                         int y=(int)round(val);
                                         content[ActiveN-1]=y;
                                     }
                                     void TDBCOlHeader_Items_Int::SetByValInt(int val) {
                                         int ActiveN=1;
                                         //this->val = (double)val;
                                         //content[ActiveN-1]=(float)val;
                                         content[ActiveN-1]=val;
                                     }
                                     void TDBCOlHeader_Items_Int::SetByValBool(bool val)
                                     {
                                         int ActiveN=1;
                                         int i;
                                         i = BoolToInt(val);
                                         //this->val=(double)i;
                                         content[ActiveN-1]=i;
                                     }
                                     void TDBCOlHeader_Items_Int::SetByValString(QString val) {
                                        int ActiveN=1;
                                         double x;
                                         int y;
                                         x=StrToReal(val);
                                         x=val.toDouble();
                                         y=IntPart(x);
                                         y=(int)round(x);
                                         y=val.toInt();
                                         content[ActiveN-1]=y;
                                     } //hin S' ne abl convert!!
                                     //
                                     void TDBCOlHeader_Items_Int::SetByValDoubleN(double val, int N) {
                                         //SetByValDouble(val);
                                         if(N>=1 && N<=content.size()) content[N-1]=(int)round(val);
                                     }
                                     void TDBCOlHeader_Items_Int::SetByValFloatN(float val, int N){
                                         //SetByValFloat(val);
                                         //if(N>=1 && N<=content.size()) content[N-1]=(float)val;
                                         if(N>=1 && N<=content.size())  content[N-1]=(int)round(val);
                                     }
                                     void TDBCOlHeader_Items_Int::SetByValIntN(int val, int N) {
                                         //SetByValInt(val);
                                         if(N>=1 && N<=content.size()) content[N-1]=val;
                                     }
                                     void TDBCOlHeader_Items_Int::SetByValBoolN(bool val, int N) {
                                         SetByValBool(val);
                                         if(N>=1 && N<=content.size()) content[N-1]=BoolToInt(val);
                                     }
                                     void TDBCOlHeader_Items_Int::SetByValStringN(QString val, int N) {
                                         double x;
                                         int y;
                                         x=StrToReal(val);
                                         x=val.toDouble();
                                         y=IntPart(x);
                                         y=(int)round(x);
                                         y=val.toInt();
                                         if(N>=1 && N<=content.size())content[N-1]=y;
                                     }
                                     //
                                     void TDBCOlHeader_Items_Int::SetVal(double val) {
                                         int ActiveN=1;
                                         //this->val = (double)val;
                                         content[ActiveN-1]=(int)round(val);
                                     }
                                     void TDBCOlHeader_Items_Int::SetVal(int val) {
                                         int ActiveN=1;
                                         //this->val = (double)val;
                                         //content[ActiveN-1]=(float)val;
                                         content[ActiveN-1]=val;
                                     }
                                     void TDBCOlHeader_Items_Int::SetVal(bool val)
                                     {
                                         int ActiveN=1;
                                         int i;
                                         i = BoolToInt(val);
                                         //this->val = (double)i;
                                         content[ActiveN-1]=BoolToInt(i);
                                     }
                                     void TDBCOlHeader_Items_Int::SetVal(QString val) {
                                         int ActiveN=1;
                                         double x=StrToReal(val);
                                         int y;
                                         y=IntPart(x);
                                         y=(int)round(x);
                                         y=val.toInt();
                                         content[ActiveN-1]=y;
                                     }
                                     //
                                     void TDBCOlHeader_Items_Int::SetValN(double val, int N) {
                                         //SetVal(val);
                                         if(N>=1 && N<=content.size())content[N-1]=(int)round(val);
                                     }
                                     void TDBCOlHeader_Items_Int::SetValN(int val, int N) {
                                         //SetVal(val);
                                         //if(N>=1 && N<=content.size())content[N-1]=(float)val;
                                         if(N>=1 && N<=content.size())content[N-1]=val;
                                     }
                                     void TDBCOlHeader_Items_Int::SetValN(bool val, int N) {
                                         //SetVal(val);
                                         int x=BoolToInt(val);
                                         if(N>=1 && N<=content.size())content[N-1]=x;
                                     }
                                     void TDBCOlHeader_Items_Int::SetValN(QString val, int N) {
                                         double x;
                                         int y;
                                         x=StrToReal(val);
                                         x=val.toDouble();
                                         y=IntPart(x);
                                         y=(int)round(x);
                                         y=val.toInt();
                                         if(N>=1 && N<=content.size())content[N-1]=y;
                                     }
                                     //
                                     void TDBCOlHeader_Items_Int::SetByArrDouble(double* val, int Q){
                                         int MinN;
                                         if(this->LengthOfItemsSet>=Q) MinN=Q; else MinN=this->LengthOfItemsSet;
                                         if(val!=NULL){
                                             for(int i=1; i<=MinN; i++) content[i-1]=(float)val[i-1];
                                         }
                                         else
                                         {
                                            //for(int i=1; i<=MinN; i++) content[i-1]=0;
                                            //NOp; NULL as argument let it be means nothing to change
                                         }
                                     }
                                     void TDBCOlHeader_Items_Int::SetByArrFloat(float* val, int Q){
                                         int MinN;
                                         if(this->LengthOfItemsSet>=Q) MinN=Q; else MinN=this->LengthOfItemsSet;
                                         if(val!=NULL){
                                             //for(int i=1; i<=MinN; i++) content[i-1]=(float)val[i-1];
                                             for(int i=1; i<=MinN; i++) content[i-1]=val[i-1];
                                         }
                                         else
                                         {
                                            //for(int i=1; i<=MinN; i++) content[i-1]=0;
                                            //NOp; NULL as argument let it be means nothing to change
                                         }
                                     }
                                     void TDBCOlHeader_Items_Int::SetByArrInt(int* val, int Q){
                                         int MinN;
                                         if(this->LengthOfItemsSet>=Q) MinN=Q; else MinN=this->LengthOfItemsSet;
                                         if(val!=NULL){
                                             for(int i=1; i<=MinN; i++) content[i-1]=(float)val[i-1];
                                         }
                                         else
                                         {
                                            //for(int i=1; i<=MinN; i++) content[i-1]=0;
                                            //NOp; NULL as argument let it be means nothing to change
                                         }
                                     }
                                     void TDBCOlHeader_Items_Int::SetByArrBool(bool* val, int Q){
                                         int MinN;
                                         if(this->LengthOfItemsSet>=Q) MinN=Q; else MinN=this->LengthOfItemsSet;
                                         if(val!=NULL){
                                             for(int i=1; i<=MinN; i++) content[i-1]=(float)BoolToInt(val[i-1]);
                                         }
                                         else
                                         {
                                            //for(int i=1; i<=MinN; i++) content[i-1]=0;
                                            //NOp; NULL as argument let it be means nothing to change
                                         }
                                     }
                                     void TDBCOlHeader_Items_Int::SetByArrString(QString* val, int Q){
                                         double x;
                                         int y;
                                         int MinN;
                                         if(this->LengthOfItemsSet>=Q) MinN=Q; else MinN=this->LengthOfItemsSet;
                                         if(val!=NULL){
                                             for(int i=1; i<=MinN; i++){
                                                 x=StrToReal(val[i-1]);
                                                 x=val[i-1].toDouble();
                                                 y=IntPart(x);
                                                 y=(int)round(x);
                                                 y=val[i-1].toInt();
                                                 content[i-1]=y;
                                             }
                                         }
                                         else
                                         {
                                            // for(int i=1; i<=MinN; i++){
                                            //     x=0;
                                            //     content[i-1]=x;
                                            //}
                                            //NOp; NULL as argument let it be means nothing to change
                                         }
                                     }
                                     //
                                     void TDBCOlHeader_Items_Int::SetByArr(double* val, int Q){
                                         int MinN;
                                         if(this->LengthOfItemsSet>=Q) MinN=Q; else MinN=this->LengthOfItemsSet;
                                         if(val!=NULL){
                                             for(int i=1; i<=MinN; i++) content[i-1]=(int)round(val[i-1]);
                                         }
                                         else
                                         {
                                            //for(int i=1; i<=MinN; i++) content[i-1]=0;
                                            //NOp; NULL as argument let it be means nothing to change
                                         }
                                     }
                                     void TDBCOlHeader_Items_Int::SetByArr(int* val, int Q){
                                         int MinN;
                                         if(this->LengthOfItemsSet>=Q) MinN=Q; else MinN=this->LengthOfItemsSet;
                                         if(val!=NULL){
                                             for(int i=1; i<=MinN; i++) content[i-1]=val[i-1];
                                         }
                                         else
                                         {
                                            //for(int i=1; i<=MinN; i++) content[i-1]=0;
                                            //NOp; NULL as argument let it be means nothing to change
                                         }
                                     }
                                     void TDBCOlHeader_Items_Int::SetByArr(bool* val, int Q){
                                         int MinN;
                                         if(this->LengthOfItemsSet>=Q) MinN=Q; else MinN=this->LengthOfItemsSet;
                                         if(val!=NULL){
                                             for(int i=1; i<=MinN; i++) content[i-1]=BoolToInt(val[i-1]);
                                         }
                                         else
                                         {
                                            //for(int i=1; i<=MinN; i++) content[i-1]=0;
                                            //NOp; NULL as argument let it be means nothing to change
                                         }
                                     }
                                     void TDBCOlHeader_Items_Int::SetByArr(QString* val, int Q){
                                         double x;
                                         int y;
                                         int MinN;
                                         if(this->LengthOfItemsSet>=Q) MinN=Q; else MinN=this->LengthOfItemsSet;
                                         if(val!=NULL){
                                             for(int i=1; i<=MinN; i++){
                                                 x=StrToReal(val[i-1]);
                                                 x=val[i-1].toDouble();
                                                 y=IntPart(x);
                                                 y=(int)round(x);
                                                 y=val[i-1].toInt();
                                                 content[i-1]=y;
                                             }
                                         }
                                         else
                                         {
                                            // for(int i=1; i<=MinN; i++){
                                            //     x=0;
                                            //     content[i-1]=x;
                                            //}
                                            //NOp; NULL as argument let it be means nothing to change
                                         }
                                     }
                                     //
                                     void TDBCOlHeader_Items_Int::AddOrInsDoubleVal(double val, int N){
                                         //SetByValDouble(val);
                                         this->LengthOfItemsSet=this->content.size();
                                         if(N>=1 && N<=this->LengthOfItemsSet){
                                             content.insert(content.begin()+N-1,(int)round(val));
                                         }else{
                                             content.push_back((int)round(val));
                                             this->LengthOfItemsSet++;
                                             //ActiveN=N;
                                         }
                                     }
                                     void TDBCOlHeader_Items_Int::AddOrInsFloatVal(float val, int N){
                                         //SetByValDouble(val);
                                         //if(N>=1 && N<=content.size()) content.insert(N-1,(float)val);
                                         this->LengthOfItemsSet=this->content.size();
                                         if(N>=1 && N<=this->LengthOfItemsSet){
                                             content.insert(content.begin()+N-1,(int)round(val));
                                         }else{
                                             //content.push_back((float)val);
                                             content.push_back((int)round(val));
                                             this->LengthOfItemsSet++;
                                             //ActiveN=N;
                                         }
                                     }
                                     void TDBCOlHeader_Items_Int::AddOrInsIntVal(int val, int N){
                                         //SetByValDouble(val);
                                         this->LengthOfItemsSet=this->content.size();
                                         if(N>=1 && N<=this->LengthOfItemsSet){
                                             content.insert(content.begin()+N-1,(int)round(val));
                                         }else{
                                             content.push_back(val);
                                             this->LengthOfItemsSet++;
                                             //ActiveN=N;
                                         }
                                     }
                                     void TDBCOlHeader_Items_Int::AddOrInsBoolVal(bool val, int N){
                                         int x=BoolToInt(val);
                                         //SetByValDouble(val);
                                         this->LengthOfItemsSet=this->content.size();
                                         if(N>=1 && N<=this->LengthOfItemsSet){
                                             content.insert(content.begin()+N-1,BoolToInt(val));
                                         }else{
                                             content.push_back(BoolToInt(x));
                                             this->LengthOfItemsSet++;
                                             //ActiveN=N;
                                         }
                                     }
                                     void TDBCOlHeader_Items_Int::AddOrInsStringVal(QString val, int N){
                                         double x=StrToReal(val);
                                         int y=IntPart(x);
                                         x=val.toDouble();
                                         y=(int)round(x);
                                         //SetByValDouble(val);
                                         this->LengthOfItemsSet=this->content.size();
                                         if(N>=1 && N<=this->LengthOfItemsSet){
                                             content.insert(content.begin()+N-1,y);
                                         }else{
                                             content.push_back(y);
                                             this->LengthOfItemsSet++;
                                             //ActiveN=N;
                                         }
                                     }
                                     //
                                     void TDBCOlHeader_Items_Int::DelValN(int N) {
                                         this->LengthOfItemsSet=this->content.size();
                                         if(N>=1 && N<=this->LengthOfItemsSet){
                                            content.erase(content.begin()+N-1);
                                        }
                                     }
                                     //
                                     void TDBCOlHeader_Items_Int::GetDoubleArr(double*&Arr,  int&QItems) {
                                         this->LengthOfItemsSet=this->content.size();
                                         QItems=this->LengthOfItemsSet;
                                         if(Arr!=NULL){
                                             delete[]Arr;
                                             Arr=new double[QItems];
                                         }
                                         for(int i=1; i<=QItems; i++) Arr[i-1] = GetDoubleValN(i);
                                     }
                                     void TDBCOlHeader_Items_Int::GetFloatArr( float*&Arr, int&QItems){
                                         this->LengthOfItemsSet=this->content.size();
                                         QItems=this->LengthOfItemsSet;
                                         if(Arr!=NULL){
                                             delete[]Arr;
                                             Arr=new float[QItems];
                                         }
                                         for(int i=1; i<=QItems; i++) Arr[i-1] = GetFloatValN(i);
                                     }
                                     void TDBCOlHeader_Items_Int::GetIntArr( int*&Arr,  int&QItems){
                                         this->LengthOfItemsSet=this->content.size();
                                         QItems=this->LengthOfItemsSet;
                                         if(Arr!=NULL){
                                             delete[]Arr;
                                             Arr=new int[QItems];
                                         }
                                         for(int i=1; i<=QItems; i++) Arr[i-1] = GetIntValN(i);
                                     }
                                     void TDBCOlHeader_Items_Int::GetBoolArr( bool*&Arr,  int&QItems){
                                         this->LengthOfItemsSet=this->content.size();
                                         QItems=this->LengthOfItemsSet;
                                         if(Arr!=NULL){
                                             delete[]Arr;
                                             Arr=new bool[QItems];
                                         }
                                         for(int i=1; i<=QItems; i++) Arr[i-1] = GetBoolValN(i);
                                     }
                                     void TDBCOlHeader_Items_Int::ToStringArr(QString*&Arr, int&QItems) {
                                         this->LengthOfItemsSet=this->content.size();
                                         QItems=this->LengthOfItemsSet;
                                         if(Arr!=NULL){
                                             delete[]Arr;
                                             Arr=new QString[QItems];
                                         }
                                         for(int i=1; i<=QItems; i++) Arr[i-1] = ToStringN(i);
                                     }
                                     //
                                     void TDBCOlHeader_Items_Int::SetNameN(QString name, int N) {
                                         if(N>=1 && N<=7){
                                             while(this->names.size()<N-1){
                                                 this->names.push_back("");
                                             }
                                             this->names[N-1]=name;
                                         }
                                     }
                                     void TDBCOlHeader_Items_Int::SetName1(QString name){
                                         int N=1;
                                         while(this->names.size()<N-1){
                                             this->names.push_back("");
                                         }
                                         this->names[N-1]=name;
                                      }
                                     void TDBCOlHeader_Items_Int::SetName2(QString name){
                                         int N=2;
                                         while(this->names.size()<N-1){
                                             this->names.push_back("");
                                         }
                                         this->names[N-1]=name;
                                      }
                                     //void TDBCOlHeader_Items_Int::SetName3(QString name){
                                     //    int N=3;
                                     //    while(this->names.size()<N-1){
                                     //        this->names.push_back("");
                                     //    }
                                     //    this->names[N-1]=name;
                                     // }
                                     //void TDBCOlHeader_Items_Int::SetNames(QString* Arr, int Q){
                                     //   this->LengthOfNamesSet=this->names.size();
                                     //   if(Q>=1 && Q<=7){
                                     //       for(int i=1; i<=Q; i++){
                                     //           if(this->LengthOfItemsSet<=Q) this->names[i-1]=Arr[i-1];
                                     //           else this->names.push_back(Arr[i-1]);
                                     //       }
                                     //   }
                                     //}
                                     QString TDBCOlHeader_Items_Int::GetNameN(int N) {
                                         QString R="";
                                         this->LengthOfNamesSet=this->names.size();
                                         if(N>=1 && N<=7 && N<this->LengthOfItemsSet) R=this->names[N-1];
                                         return R;
                                     }
                                     QString TDBCOlHeader_Items_Int::GetName1() {
                                         int N=1;
                                         QString R="";
                                         this->LengthOfNamesSet=this->names.size();
                                         if(N>=1 && N<=7 && N<=this->LengthOfItemsSet) R=this->names[N-1];
                                         return R;
                                     }
                                     QString TDBCOlHeader_Items_Int::GetName2() {
                                         int N=2;
                                         QString R="";
                                          this->LengthOfNamesSet=this->names.size();
                                         if(N>=1 && N<=7 && N<=this->LengthOfItemsSet) R=this->names[N-1];
                                         return R;
                                     }
                                     //QString TDBCOlHeader_Items_Int::GetName3() {
                                     //    int N=3;
                                     //    QString R="";
                                     //     this->LengthOfNamesSet=this->names.size();
                                     //    if(N>=1 && N<=7 && N<=this->LengthOfNamesSet) R=this->names[N-1];
                                     //    return R;
                                     //}
                                     //void TDBCOlHeader_Items_Int::GetNames(QString*&Arr, int&QItems) {
                                     //       if(Arr!=NULL) delete[]Arr;
                                     //       QItems=this->GetLengthOfNamesList();
                                     //       if(Arr==NULL) Arr=new QString[QItems];
                                     //       for(int i=1; i<=QItems; i++) Arr[i-1]=this->names[i-1];
                                     //}
                                     //int TDBCOlHeader_Items_Int::GetLengthOfNamesList(){
                                     //    this->LengthOfNamesSet=this->names.size();
                                     //    return this->LengthOfNamesSet;
                                     //}
                                     //
                                     void TDBCOlHeader_Items_Int::SetItems(QString*items, int Q, int ActiveN){
                                         int val;
                                         QString item;
                                         //if(this->content==NULL){
                                         if(this->content.size()!=0){
                                             //delete this->content;
                                             this->content.clear();
                                             //this->content=NULL;
                                             this->LengthOfItemsSet=0;
                                             //this->ActiveN=0;
                                         }
                                         if(items!=NULL){
                                             this->LengthOfItemsSet=Q;
                                             //content=new double[this->Length];
                                             for(int i=1; i<=this->LengthOfItemsSet; i++){
                                                 //this->content[i-1]=items[i-1];
                                                 //val=items[i-1].toDouble;
                                                 item=items[i-1];
                                                 val=item.toInt();
                                                 //val=StrToFloat(items[i-1]);
                                                 this->content.push_back(val);
                                             }
                                             //this->ActiveN=ActiveN;
                                             this->LengthOfItemsSet=Q;
                                             //}
                                         }
                                     }
                                     void TDBCOlHeader_Items_Int::GetItems(QString*&items, int&Q){
                                         int val;
                                         QString item;
                                         if(items!=NULL){
                                             delete[]items;
                                         }
                                         items=NULL;
                                         Q=this->LengthOfItemsSet;
                                         if(this->content.size()>0){
                                            items=new QString[Q];
                                            for(int i=1; i<=Q; i++){
                                                //val=FloatToStr(this-content[i-1]);
                                                //items[1-1]/*=FloatToStr*/(this-content[i-1]);
                                                val=this->content[i-1];
                                                item=IntToStr(val);
                                                items[i-1]=item;
                                            }
                                         }
                                     }
                                     void TDBCOlHeader_Items_Int::SetItem(QString item, int itemN){
                                         int val;
                                         if(itemN<0){
                                             itemN-=this->LengthOfItemsSet;
                                         }
                                         if(itemN>=1 || itemN<=this->LengthOfItemsSet){
                                             val=item.toInt();//better own fn
                                             this->content[itemN-1]=val;
                                         }
                                     }
                                     void TDBCOlHeader_Items_Int::InsItem(QString item, int itemN){
                                         int val=item.toInt();
                                         Array1DInsElementToN(this->content, itemN, val);
                                         this->LengthOfItemsSet+=1;
                                     }
                                     void TDBCOlHeader_Items_Int::AddItem(QString item){
                                         int val=item.toInt();
                                         Array1DAddElement(this->content, val);
                                         this->LengthOfItemsSet+=1;
                                     }
                                     void TDBCOlHeader_Items_Int::DelItem(int itemN){
                                         Array1DDelElementFromN(this->content, itemN);
                                         this->LengthOfItemsSet-=1;
                                     }
                                     QString TDBCOlHeader_Items_Int::GetItem(int itemN){
                                         QString R="0";
                                         if(itemN<0){
                                             itemN+=(this->LengthOfItemsSet+1);
                                         }
                                         if(itemN==1 && itemN<=this->LengthOfItemsSet){
                                             R.setNum(this->content[itemN-1]);
                                         }
                                         return R;
                                     }
                                     int TDBCOlHeader_Items_Int::GetLengthOfItemsList(){ return this->LengthOfItemsSet; }
                                 //     override object Clone(){
                                 //        return new TDBCOlHeader_Items_Int(this->GetDoubleVal());
                                 //    }
                        //};//cl TDBCOlHeader_Items_Int



    //class TDBCOlHeader_Items_String: TDataCell
    //{
          //    double val;
          //    :
          TDBCOlHeader_Items_String::TDBCOlHeader_Items_String() {
              //QString val="";
              //
              //ActiveN=0;
              //Length=0;
              //
              //ActiveN=1;
              //Length=1;
              //
              //content.push_back(val);
              this->construct();
          }
          //TDBCOlHeader_Items_String::TDBCOlHeader_Items_String(double val) { this->construct();  SetByValDouble(val); }
          //TDBCOlHeader_Items_String::TDBCOlHeader_Items_String(float val) { this->construct(); SetByValFloat(val); }
          //TDBCOlHeader_Items_String::TDBCOlHeader_Items_String(int val) { this->construct(); SetByValInt(val); }
          //TDBCOlHeader_Items_String::TDBCOlHeader_Items_String(bool val) { this->construct(); SetByValBool(val); }
          //TDBCOlHeader_Items_String::TDBCOlHeader_Items_String(QString val) { this->construct(); SetByValString(val); }
          //
          //TDBCOlHeader_Items_String::TDBCOlHeader_Items_String(double* val, int Q) { this->construct(); SetByArrDouble(val, Q); }
          //TDBCOlHeader_Items_String::TDBCOlHeader_Items_String(float* val, int Q) { this->construct(); SetByArrFloat(val, Q); }
          //TDBCOlHeader_Items_String::TDBCOlHeader_Items_String(int* val, int Q) { this->construct(); SetByArrInt(val, Q); }
          //TDBCOlHeader_Items_String::TDBCOlHeader_Items_String(bool* val, int Q) { this->construct(); SetByArrBool(val, Q); }
          TDBCOlHeader_Items_String::TDBCOlHeader_Items_String(QString* val, int Q) { this->construct(); SetByArrString(val, Q); }
          //
          TDBCOlHeader_Items_String::TDBCOlHeader_Items_String(QString* val, int QItems, QString* name, int QNames){
              int countItems=1, countNames=1;
              if(QNames>7)countNames=7;
              else if(QNames<1) countNames=1;
              else countNames=QNames;
              if(QItems>MaxInt)countItems=MaxInt;
              else if(QItems<1)countItems=1;
              else countItems=QItems;
              if(val==NULL){
                  if(countItems>MaxInt/2)countItems=1;
                  for(int i=1; i<=countItems; i++)this->content.push_back("");
              }else{
                  for(int i=1; i<=countItems; i++)this->content.push_back(val[i-1]);
              }
              //
              if(name==NULL){
                  for(int i=1; i<=countNames; i++)this->names.push_back("");
              }else{
                  for(int i=1; i<=countNames; i++)this->names.push_back(name[i-1]);
              }
          }
          //hope they will not be needed
          //    TDBCOlHeader_Items_String(TDBCOlHeader_Items_String&obj){
          //        this->Assign(obj);
                                                           //    }
                                                           //    //
                                                           //    TDBCOlHeader_Items_String& operator =(TDBCOlHeader_Items_String&obj){
                                                           //        this->Assign(obj);
                                                           //        return*this;
                                                           //    }
                                                           //    //
                                                           //    void Assign(TDBCOlHeader_Items_String&obj){
                                                           //        this->data=obj.data;
                                                           //    }
                                                               void TDBCOlHeader_Items_String::construct(int n){
                                                                   //this->val=new double[n];
                                                                   int qi=7;
                                                                   for(int i=1; i<=n; i++) this->content.push_back("");
                                                                   for(int i=1; i<=qi; i++) this->names.push_back("");
                                                               }
                                                               int TDBCOlHeader_Items_String::GetTypeN() { return StringArrayTypeN; }
                                                               int TDBCOlHeader_Items_String::GetActiveN() { return ActiveN_ByDefault;}
                                                               void TDBCOlHeader_Items_String::SetActiveN(int N) {
                                                                   if(N>=1 && N<=content.size()) this->ActiveN_ByDefault=N;
                                                               }
                                                               int TDBCOlHeader_Items_String::GetLength() { return this->LengthOfItemsSet; }
                                                               void TDBCOlHeader_Items_String::SetLength(int L){
                                                                   QString val="";
                                                                   int iL=content.size();
                                                                   if(L>=1 && L<=MaxInt){
                                                                       if(L>iL){
                                                                           for(int i=1; i<=L-iL; i++){
                                                                              content.push_back(val);
                                                                           }
                                                                       }else if(L<iL){
                                                                           for(int i=1; i<=iL-L; i++){
                                                                              content.pop_back();
                                                                           }
                                                                       }
                                                                       this->LengthOfItemsSet=L;
                                                                   }
                                                               }//SetLength
                                                               //
                                                               double TDBCOlHeader_Items_String::GetDoubleVal() {
                                                                   int ActiveN=1;
                                                                   double val;
                                                                   val=StrToReal(content[ActiveN-1]);
                                                                   //val=(double)content[ActiveN-1];
                                                                   val=content[ActiveN-1].toDouble();
                                                                   return val;
                                                               }
                                                               float TDBCOlHeader_Items_String::GetFloatVal() {
                                                                    int ActiveN=1;
                                                                   float val;
                                                                   //val=(floatcontent[ActiveN-1];
                                                                   val=(float)StrToReal(content[ActiveN-1]);
                                                                   val=content[ActiveN-1].toFloat();
                                                                   return val;
                                                               }
                                                               int TDBCOlHeader_Items_String::GetIntVal()
                                                               {
                                                                    int ActiveN=1;
                                                                   int val;
                                                                   //val=content[ActiveN-1];
                                                                   val=StrToInt(content[ActiveN-1]);
                                                                   val=content[ActiveN-1].toInt();
                                                                   //int r;
                                                                   //r =(int) round(content[ActiveN-1]);
                                                                   //r =(int) round(val);
                                                                   //return r;
                                                                   return val;
                                                               }
                                                               bool TDBCOlHeader_Items_String::GetBoolVal() {
                                                                    int ActiveN=1;
                                                                   bool r, ItIsTrueWord, ItIsFalseWord;
                                                                   QString val;
                                                                   ItIsTrueWord=IsTrueWord(content[ActiveN-1]);
                                                                   ItIsFalseWord=IsFalseWord(content[ActiveN-1]);
                                                                   //val=content[ActiveN-1];
                                                                   if(BoolValByDefault==true){
                                                                       if (ItIsFalseWord) r = false;
                                                                       else r = true;
                                                                   }else{
                                                                       if (ItIsTrueWord) r = true;
                                                                       else r = false;
                                                                   }
                                                                   return r;
                                                               }
                                                               QString TDBCOlHeader_Items_String::ToString() {
                                                                    int ActiveN=1;
                                                                   //int val=content[ActiveN-1];
                                                                   //QString s;
                                                                   //s=IntToString(val);
                                                                   //s.setNum(val);
                                                                   //return s;//val.ToString();
                                                                   return content[ActiveN-1];
                                                               }
                                                               //
                                                               double TDBCOlHeader_Items_String::GetDoubleValN(int N) {
                                                                   double val=0;
                                                                   if(N>=1 && N<=content.size()){
                                                                       val=StrToReal(content[N-1]);
                                                                       val=content[N-1].toDouble();
                                                                   }
                                                                   return val;
                                                               }
                                                               float TDBCOlHeader_Items_String::GetFloatValN(int N){
                                                                   float val=0;
                                                                   if(N>=1 && N<=content.size()){
                                                                       val=(float)StrToReal(content[N-1]);
                                                                       val=content[N-1].toFloat();
                                                                   }
                                                                   return val;
                                                               }
                                                               int TDBCOlHeader_Items_String::GetIntValN(int N)
                                                               {
                                                                   int r=0;
                                                                   if(N>=1 && N<=content.size()){
                                                                      //r = (int)round(content[N-1]);
                                                                      r = StrToInt(content[N-1]);
                                                                      r=content[N-1].toInt();
                                                                   }
                                                                   return r;
                                                               }
                                                               bool TDBCOlHeader_Items_String::GetBoolValN(int N)
                                                               {
                                                                   bool r=BoolValByDefault, chk=BoolValByDefault;
                                                                   if(N>=1 && N<=content.size()){
                                                                       //if(chk==true){
                                                                       if(BoolValByDefault==true){
                                                                           if (IsFalseWord(content[N-1])) r = false;
                                                                           else r = true;
                                                                       }else{
                                                                           if (IsTrueWord(content[N-1])) r = true;
                                                                           else r = false;
                                                                       }
                                                                   }
                                                                   return r;
                                                               }
                                                               QString TDBCOlHeader_Items_String::ToStringN(int N) {
                                                                   QString s="";
                                                                   ////QString RealToString(double x, int Repr_IntAndFrac0_ExpAfOrderLim1_ExpAnyhow2=0,  int QAftComma=6, int OrdAfWhichExp=6, int BaseDec=10);
                                                                   //int val=content[ActiveN-1];
                                                                   ////float val=content[ActiveN-1];
                                                                   //s=IntToString(val);
                                                                   //s.setNum(val);
                                                                   //return s;
                                                                   if(N>=1 && N<=content.size()) s=content[N-1];
                                                                   return s;
                                                               }
                                                               //
                                                               void TDBCOlHeader_Items_String::SetByValDouble(double val) {
                                                                   int ActiveN=1;
                                                                   QString s;
                                                                   s.setNum(val);
                                                                   s=RealToString(val);
                                                                   content[ActiveN-1]=s;
                                                               }
                                                               void TDBCOlHeader_Items_String::SetByValFloat(float val) {
                                                                    int ActiveN=1;
                                                                   QString s;
                                                                   s.setNum(val);
                                                                   s=RealToString((double)val);
                                                                   content[ActiveN-1]=s;
                                                               }
                                                               void TDBCOlHeader_Items_String::SetByValInt(int val) {
                                                                    int ActiveN=1;
                                                                   QString s;
                                                                   s.setNum(val);
                                                                   s=IntToStr(val);
                                                                   content[ActiveN-1]=s;
                                                               }
                                                               void TDBCOlHeader_Items_String::SetByValBool(bool val)
                                                               {
                                                                    int ActiveN=1;
                                                                   int i;
                                                                   i = BoolToInt(val);
                                                                   //this->val=(double)i;
                                                                   content[ActiveN-1]=IntToStr(i);
                                                                   content[ActiveN-1].setNum(i);
                                                               }
                                                               void TDBCOlHeader_Items_String::SetByValString(QString val) {
                                                                    int ActiveN=1;
                                                                   content[ActiveN-1]=val;
                                                               }
                                                               //
                                                               void TDBCOlHeader_Items_String::SetByValDoubleN(double val, int N) {
                                                                   //SetByValDouble(val);
                                                                   if(N>=1 && N<=content.size()) content[N-1]=RealToString(val);
                                                                   if(N>=1 && N<=content.size()) content[N-1].setNum(val);
                                                               }
                                                               void TDBCOlHeader_Items_String::SetByValFloatN(float val, int N){
                                                                   //SetByValFloat(val);
                                                                   if(N>=1 && N<=content.size()) content[N-1]=RealToString((double)val);
                                                                   if(N>=1 && N<=content.size()) content[N-1].setNum(val);
                                                               }
                                                               void TDBCOlHeader_Items_String::SetByValIntN(int val, int N) {
                                                                   //SetByValInt(val);
                                                                   this->LengthOfItemsSet=this->content.size();
                                                                   if(N>=1 && N<=this->LengthOfItemsSet) (content[N-1])=IntToStringSimple(val);
                                                                   if(N>=1 && N<=this->LengthOfItemsSet) content[N-1].setNum(val);
                                                               }
                                                               void TDBCOlHeader_Items_String::SetByValBoolN(bool val, int N) {
                                                                   SetByValBool(val);
                                                                   if(N>=1 && N<=content.size()) content[N-1]=IntToStr(BoolToInt(val));
                                                                   if(N>=1 && N<=content.size()) content[N-1].setNum(BoolToInt(val));
                                                               }
                                                               void TDBCOlHeader_Items_String::SetByValStringN(QString val, int N) {
                                                                   if(N>=1 && N<=content.size())content[N-1]=val;
                                                               }
                                                               //
                                                               void TDBCOlHeader_Items_String::SetVal(double val) {
                                                                   int ActiveN=1;
                                                                   //this->val = (double)val;
                                                                   content[ActiveN-1]=RealToString(val);
                                                                   content[ActiveN-1].setNum(val);
                                                               }
                                                               void TDBCOlHeader_Items_String::SetVal(int val) {
                                                                   int ActiveN=1;
                                                                   //this->val = (double)val;
                                                                   //content[ActiveN-1]=(float)val;
                                                                   content[ActiveN-1]=IntToStr(val);
                                                                   content[ActiveN-1].setNum(val);
                                                               }
                                                               void TDBCOlHeader_Items_String::SetVal(bool val)
                                                               {
                                                                   int ActiveN=1;
                                                                   int i;
                                                                   i = BoolToInt(val);
                                                                   content[ActiveN-1]=IntToStr(i);
                                                                   content[ActiveN-1].setNum(i);
                                                               }
                                                               void TDBCOlHeader_Items_String::SetVal(QString val) {
                                                                   int ActiveN=1;
                                                                   content[ActiveN-1]=val;
                                                               }
                                                               //
                                                               void TDBCOlHeader_Items_String::SetValN(double val, int N) {
                                                                   //SetVal(val);
                                                                   if(N>=1 && N<=content.size())content[N-1]=RealToString(val);
                                                                   if(N>=1 && N<=content.size())content[N-1].setNum(val);
                                                               }
                                                               void TDBCOlHeader_Items_String::SetValN(int val, int N) {
                                                                   //SetVal(val);
                                                                   //if(N>=1 && N<=content.size())content[N-1]=(float)val;
                                                                   if(N>=1 && N<=content.size())content[N-1]=IntToStr(val);
                                                                   if(N>=1 && N<=content.size())content[N-1].setNum(val);
                                                               }
                                                               void TDBCOlHeader_Items_String::SetValN(bool val, int N) {
                                                                   if(N>=1 && N<=content.size())content[N-1]=IntToStr(BoolToInt(val));
                                                                   if(N>=1 && N<=content.size())content[N-1].setNum(BoolToInt(val));
                                                               }
                                                               void TDBCOlHeader_Items_String::SetValN(QString val, int N) {
                                                                   if(N>=1 && N<=content.size())content[N-1]=val;
                                                               }
                                                               //
                                                               void TDBCOlHeader_Items_String::SetByArrDouble(double* val, int Q){
                                                                   int MinN;
                                                                   if(this->LengthOfItemsSet>=Q) MinN=Q; else MinN=this->LengthOfItemsSet;
                                                                   if(val!=NULL){
                                                                       for(int i=1; i<=MinN; i++){
                                                                           content[i-1]=RealToString(val[i-1]);
                                                                           content[i-1].setNum(val[i-1]);
                                                                       }
                                                                   }
                                                                   else
                                                                   {
                                                                      //for(int i=1; i<=MinN; i++) content[i-1]=0;
                                                                      //NOp; NULL as argument let it be means nothing to change
                                                                   }
                                                               }
                                                               void TDBCOlHeader_Items_String::SetByArrFloat(float* val, int Q){
                                                                   int MinN;
                                                                   if(this->LengthOfItemsSet>=Q) MinN=Q; else MinN=this->LengthOfItemsSet;
                                                                   if(val!=NULL){
                                                                       for(int i=1; i<=MinN; i++){
                                                                           content[i-1]=RealToString((double)val[i-1]);
                                                                           content[i-1].setNum(val[i-1]);
                                                                       }
                                                                   }
                                                                   else
                                                                   {
                                                                      //for(int i=1; i<=MinN; i++) content[i-1]=0;
                                                                      //NOp; NULL as argument let it be means nothing to change
                                                                   }
                                                               }
                                                               void TDBCOlHeader_Items_String::SetByArrInt(int* val, int Q){
                                                                   int MinN;
                                                                   if(this->LengthOfItemsSet>=Q) MinN=Q; else MinN=this->LengthOfItemsSet;
                                                                   if(val!=NULL){
                                                                       for(int i=1; i<=MinN; i++){
                                                                           content[i-1]=IntToStr(val[i-1]);
                                                                           content[i-1].setNum(val[i-1]);
                                                                       }
                                                                   }
                                                                   else
                                                                   {
                                                                      //for(int i=1; i<=MinN; i++) content[i-1]=0;
                                                                      //NOp; NULL as argument let it be means nothing to change
                                                                   }
                                                               }
                                                               void TDBCOlHeader_Items_String::SetByArrBool(bool* val, int Q){
                                                                   int MinN;
                                                                   if(this->LengthOfItemsSet>=Q) MinN=Q; else MinN=this->LengthOfItemsSet;
                                                                   if(val!=NULL){
                                                                       for(int i=1; i<=MinN; i++) {
                                                                           content[i-1]=IntToStr(BoolToInt(val[i-1]));
                                                                           content[i-1].setNum(BoolToInt(val[i-1]));
                                                                       }
                                                                   }
                                                                   else
                                                                   {
                                                                      //for(int i=1; i<=MinN; i++) content[i-1]=0;
                                                                      //NOp; NULL as argument let it be means nothing to change
                                                                   }
                                                               }
                                                               void TDBCOlHeader_Items_String::SetByArrString(QString* val, int Q){
                                                                   //double x;
                                                                   //int y;
                                                                   int MinN;
                                                                   if(this->LengthOfItemsSet>=Q) MinN=Q; else MinN=this->LengthOfItemsSet;
                                                                   if(val!=NULL){
                                                                       for(int i=1; i<=MinN; i++){
                                                                           //x=StrToReal(val[i-1]);
                                                                           //x=val[i-1].toDouble();
                                                                           //y=IntPart(x);
                                                                           //y=(int)round(x);
                                                                           //y=val[i-1].toInt();
                                                                           //content[i-1]=y;
                                                                           content[i-1]=val[i-1];
                                                                       }
                                                                   }
                                                                   else
                                                                   {
                                                                      // for(int i=1; i<=MinN; i++){
                                                                      //     x=0;
                                                                      //     content[i-1]=x;
                                                                      //}
                                                                      //NOp; NULL as argument let it be means nothing to change
                                                                   }
                                                               }
                                                               //
                                                               void TDBCOlHeader_Items_String::SetByArr(double* val, int Q){
                                                                   int MinN;
                                                                   if(this->LengthOfItemsSet>=Q) MinN=Q; else MinN=this->LengthOfItemsSet;
                                                                   if(val!=NULL){
                                                                       for(int i=1; i<=MinN; i++){
                                                                           //content[i-1]=(int)round(val[i-1]);
                                                                           content[i-1]=RealToString(val[i-1]);
                                                                           content[i-1].setNum(val[i-1]);
                                                                       }
                                                                   }
                                                                   else
                                                                   {
                                                                      //for(int i=1; i<=MinN; i++) content[i-1]=0;
                                                                      //NOp; NULL as argument let it be means nothing to change
                                                                   }
                                                               }
                                                               void TDBCOlHeader_Items_String::SetByArr(int* val, int Q){
                                                                   int MinN;
                                                                   if(this->LengthOfItemsSet>=Q) MinN=Q; else MinN=this->LengthOfItemsSet;
                                                                   if(val!=NULL){
                                                                       for(int i=1; i<=MinN; i++){
                                                                           //content[i-1]=(int)round(val[i-1]);
                                                                           content[i-1]=RealToString((double)val[i-1]);
                                                                           content[i-1].setNum(val[i-1]);
                                                                       }
                                                                   }
                                                                   else
                                                                   {
                                                                      //for(int i=1; i<=MinN; i++) content[i-1]=0;
                                                                      //NOp; NULL as argument let it be means nothing to change
                                                                   }
                                                               }
                                                               void TDBCOlHeader_Items_String::SetByArr(bool* val, int Q){
                                                                   int MinN;
                                                                   if(this->LengthOfItemsSet>=Q) MinN=Q; else MinN=this->LengthOfItemsSet;
                                                                   if(val!=NULL){
                                                                       for(int i=1; i<=MinN; i++){
                                                                           content[i-1]=IntToStr(BoolToInt(val[i-1]));
                                                                           content[i-1].setNum(BoolToInt(val[i-1]));
                                                                       }
                                                                   }
                                                                   else
                                                                   {
                                                                      //for(int i=1; i<=MinN; i++) content[i-1]=0;
                                                                      //NOp; NULL as argument let it be means nothing to change
                                                                   }
                                                               }
                                                               void TDBCOlHeader_Items_String::SetByArr(QString* val, int Q){
                                                                   double x;
                                                                   int y;
                                                                   int MinN;
                                                                   if(this->LengthOfItemsSet>=Q) MinN=Q; else MinN=this->LengthOfItemsSet;
                                                                   if(val!=NULL){
                                                                       for(int i=1; i<=MinN; i++){
                                                                           //x=StrToReal(val[i-1]);
                                                                           //x=val[i-1].toDouble();
                                                                           //y=IntPart(x);
                                                                           //y=(int)round(x);
                                                                           //y=val[i-1].toInt();
                                                                           //content[i-1]=y;
                                                                           content[i-1]=val[i-1];
                                                                       }
                                                                   }
                                                                   else
                                                                   {
                                                                      // for(int i=1; i<=MinN; i++){
                                                                      //     x=0;
                                                                      //     content[i-1]=x;
                                                                      //}
                                                                      //NOp; NULL as argument let it be means nothing to change
                                                                   }
                                                               }
                                                               //
                                                               void TDBCOlHeader_Items_String::AddOrInsDoubleVal(double val, int N){
                                                                   //SetByValDouble(val);
                                                                   QString s;
                                                                   s=RealToString(val);
                                                                   s.setNum(val);
                                                                   if(N>=1 && N<=content.size()) content.insert(content.begin()+N-1,s);
                                                                   else{
                                                                       content.push_back(s);
                                                                       this->LengthOfItemsSet++;
                                                                       //ActiveN=N;
                                                                   }
                                                               }
                                                               void TDBCOlHeader_Items_String::AddOrInsFloatVal(float val, int N){
                                                                   //SetByValDouble(val);
                                                                   //if(N>=1 && N<=content.size()) content.insert(N-1,(float)val);
                                                                   QString s;
                                                                   s=RealToString((double)val);
                                                                   s.setNum(val);
                                                                   if(N>=1 && N<=content.size()) content.insert(content.begin()+N-1,s);
                                                                   else{
                                                                       //content.push_back((float)val);
                                                                       content.push_back(s);
                                                                       this->LengthOfItemsSet++;
                                                                       //ActiveN=N;
                                                                   }
                                                               }
                                                               void TDBCOlHeader_Items_String::AddOrInsIntVal(int val, int N){
                                                                   //SetByValDouble(val);
                                                                   QString s;
                                                                   s=IntToStringSimple(val);
                                                                   s.setNum(val);
                                                                   if(N>=1 && N<=content.size()) content.insert(content.begin()+N-1,s);
                                                                   else{
                                                                       content.push_back(s);
                                                                       this->LengthOfItemsSet++;
                                                                       //ActiveN=N;
                                                                   }
                                                               }
                                                               void TDBCOlHeader_Items_String::AddOrInsBoolVal(bool val, int N){
                                                                   int x=BoolToInt(val);
                                                                   //SetByValDouble(val);
                                                                   QString s;
                                                                   s=IntToStringSimple(x);
                                                                   s.setNum(x);
                                                                   if(N>=1 && N<=content.size()){
                                                                      content.insert(content.begin()+N-1,s);
                                                                   }else{
                                                                       content.push_back(s);
                                                                       this->LengthOfItemsSet++;
                                                                       //ActiveN=N;
                                                                   }
                                                               }
                                                               void TDBCOlHeader_Items_String::AddOrInsStringVal(QString val, int N){
                                                                   //double x=StrToReal(val);
                                                                   //int y=IntPart(x);
                                                                   //x=val.toDouble();
                                                                   //y=(int)round(x);
                                                                   //SetByValDouble(val);
                                                                   if(N>=1 && N<=content.size()){
                                                                      content.insert(content.begin()+N-1,val);
                                                                   }else{
                                                                       content.push_back(val);
                                                                       this->LengthOfItemsSet++;
                                                                       //ActiveN=N;
                                                                   }
                                                               }
                                                               //
                                                               void TDBCOlHeader_Items_String::DelValN(int N) {
                                                                  if(N>=1 && N<=content.size()){
                                                                      content.erase(content.begin()+N-1);
                                                                  }
                                                               }
                                                               //
                                                               void TDBCOlHeader_Items_String::GetDoubleArr(double*&Arr,  int&QItems) {
                                                                   QItems=this->LengthOfItemsSet;
                                                                   if(Arr!=NULL){
                                                                       delete[]Arr;
                                                                       Arr=new double[QItems];
                                                                   }
                                                                   for(int i=1; i<=QItems; i++) Arr[i-1] = GetDoubleValN(i);
                                                               }
                                                               void TDBCOlHeader_Items_String::GetFloatArr( float*&Arr, int&QItems){
                                                                   QItems=this->LengthOfItemsSet;
                                                                   if(Arr!=NULL){
                                                                       delete[]Arr;
                                                                       Arr=new float[QItems];
                                                                   }
                                                                   for(int i=1; i<=QItems; i++) Arr[i-1] = GetFloatValN(i);
                                                               }
                                                               void TDBCOlHeader_Items_String::GetIntArr( int*&Arr,  int&QItems){
                                                                   QItems=this->LengthOfItemsSet;
                                                                   if(Arr!=NULL){
                                                                       delete[]Arr;
                                                                       Arr=new int[QItems];
                                                                   }
                                                                   for(int i=1; i<=QItems; i++) Arr[i-1] = GetIntValN(i);
                                                               }
                                                               void TDBCOlHeader_Items_String::GetBoolArr( bool*&Arr,  int&QItems){
                                                                   QItems=this->LengthOfItemsSet;
                                                                   if(Arr!=NULL){
                                                                       delete[]Arr;
                                                                       Arr=new bool[QItems];
                                                                   }
                                                                   for(int i=1; i<=QItems; i++) Arr[i-1] = GetBoolValN(i);
                                                               }
                                                               void TDBCOlHeader_Items_String::ToStringArr(QString*&Arr, int&QItems) {
                                                                   QItems=this->LengthOfItemsSet;
                                                                   if(Arr!=NULL){
                                                                       delete[]Arr;
                                                                       Arr=new QString[QItems];
                                                                   }
                                                                   for(int i=1; i<=QItems; i++) Arr[i-1] = ToStringN(i);
                                                               }
                                                               //
                                                               void TDBCOlHeader_Items_String::SetNameN(QString name, int N) {
                                                                   if(N>=1 && N<=7){
                                                                       while(this->names.size()<N-1){
                                                                           this->names.push_back("");
                                                                       }
                                                                       this->names[N-1]=name;
                                                                   }
                                                               }
                                                               void TDBCOlHeader_Items_String::SetName1(QString name){
                                                                   int N=1;
                                                                   while(this->names.size()<N-1){
                                                                       this->names.push_back("");
                                                                   }
                                                                   this->names[N-1]=name;
                                                                }
                                                               void TDBCOlHeader_Items_String::SetName2(QString name){
                                                                   int N=2;
                                                                   while(this->names.size()<N-1){
                                                                       this->names.push_back("");
                                                                   }
                                                                   this->names[N-1]=name;
                                                                }
                                                               //void TDBCOlHeader_Items_String::SetName3(QString name){
                                                               //    int N=3;
                                                               //    while(this->names.size()<N-1){
                                                               //        this->names.push_back("");
                                                               //    }
                                                               //    this->names[N-1]=name;
                                                               // }
                                                               //void TDBCOlHeader_Items_String::SetNames(QString* Arr, int Q){
                                                               //   this->LengthOfNamesSet=this->names.size();
                                                               //   if(Q>=1 && Q<=7){
                                                               //       for(int i=1; i<=Q; i++){
                                                               //           if(this->LengthOfItemsSet<=Q) this->names[i-1]=Arr[i-1];
                                                               //           else this->names.push_back(Arr[i-1]);
                                                               //       }
                                                               //   }
                                                               //}
                                                               QString TDBCOlHeader_Items_String::GetNameN(int N) {
                                                                   QString R="";
                                                                   this->LengthOfNamesSet=this->names.size();
                                                                   if(N>=1 && N<=7 && N<this->LengthOfItemsSet) R=this->names[N-1];
                                                                   return R;
                                                               }
                                                               QString TDBCOlHeader_Items_String::GetName1() {
                                                                   int N=1;
                                                                   QString R="";
                                                                   this->LengthOfNamesSet=this->names.size();
                                                                   if(N>=1 && N<=7 && N<=this->LengthOfItemsSet) R=this->names[N-1];
                                                                   return R;
                                                               }
                                                               QString TDBCOlHeader_Items_String::GetName2() {
                                                                   int N=2;
                                                                   QString R="";
                                                                    this->LengthOfNamesSet=this->names.size();
                                                                   if(N>=1 && N<=7 && N<=this->LengthOfItemsSet) R=this->names[N-1];
                                                                   return R;
                                                               }
                                                               //QString TDBCOlHeader_Items_String::GetName3() {
                                                               //    int N=3;
                                                               //    QString R="";
                                                               //     this->LengthOfNamesSet=this->names.size();
                                                               //    if(N>=1 && N<=7 && N<=this->LengthOfNamesSet) R=this->names[N-1];
                                                               //    return R;
                                                               //}
                                                               //void TDBCOlHeader_Items_String::GetNames(QString*&Arr, int&QItems) {
                                                               //       if(Arr!=NULL) delete[]Arr;
                                                               //       QItems=this->GetLengthOfNamesList();
                                                               //       if(Arr==NULL) Arr=new QString[QItems];
                                                               //       for(int i=1; i<=QItems; i++) Arr[i-1]=this->names[i-1];
                                                              // }
                                                              //int TDBCOlHeader_Items_String::GetLengthOfNamesList(){
                                                              //     this->LengthOfNamesSet=this->names.size();
                                                              //     return this->LengthOfNamesSet;
                                                              // }
                                                               //
                                                               void TDBCOlHeader_Items_String::SetItems(QString*items, int Q, int ActiveN){
                                                                   QString val;
                                                                   QString item;
                                                                   //if(this->content==NULL){
                                                                   if(this->content.size()!=0){
                                                                       //delete this->content;
                                                                       this->content.clear();
                                                                       //this->content=NULL;
                                                                       this->LengthOfItemsSet=0;
                                                                       //this->ActiveN=0;
                                                                   }
                                                                   if(items!=NULL){
                                                                       this->LengthOfItemsSet=Q;
                                                                       //content=new double[this->Length];
                                                                       for(int i=1; i<=this->LengthOfItemsSet; i++){
                                                                           //this->content[i-1]=items[i-1];
                                                                           //val=items[i-1].toDouble;
                                                                           item=items[i-1];
                                                                           val=item;
                                                                           //val=StrToFloat(items[i-1]);
                                                                           this->content.push_back(val);
                                                                       }
                                                                       //this->ActiveN=ActiveN;
                                                                       this->LengthOfItemsSet=Q;
                                                                       //}
                                                                   }
                                                               }
                                                               void TDBCOlHeader_Items_String::GetItems(QString*&items, int&Q){
                                                                   QString val;
                                                                   QString item;
                                                                   if(items!=NULL){
                                                                       delete[]items;
                                                                   }
                                                                   items=NULL;
                                                                   Q=this->LengthOfItemsSet;
                                                                   if(this->content.size()>0){
                                                                      items=new QString[Q];
                                                                      for(int i=1; i<=Q; i++){
                                                                          //val=FloatToStr(this-content[i-1]);
                                                                          //items[1-1]/*=FloatToStr*/(this-content[i-1]);
                                                                          val=this->content[i-1];
                                                                          item=val;
                                                                          items[i-1]=item;
                                                                      }
                                                                   }
                                                               }
                                                               void TDBCOlHeader_Items_String::SetItem(QString item, int itemN){
                                                                   if(itemN==0){
                                                                       itemN-=this->LengthOfItemsSet;
                                                                   }
                                                                   if(itemN>=1 || itemN<=this->LengthOfItemsSet){
                                                                       this->content[itemN-1]=item;//better own fn
                                                                   }
                                                               }
                                                               void TDBCOlHeader_Items_String::InsItem(QString item, int itemN){
                                                                   QString val=item;//.toDouble();
                                                                   Array1DInsElementToN(this->content, itemN, val);
                                                                   this->LengthOfItemsSet+=1;
                                                               }
                                                               void TDBCOlHeader_Items_String::AddItem(QString item){
                                                                   QString val=item;//.toFloat();
                                                                   Array1DAddElement(this->content, val);
                                                                   this->LengthOfItemsSet+=1;
                                                               }
                                                               void TDBCOlHeader_Items_String::DelItem(int itemN){
                                                                   Array1DDelElementFromN(this->content, itemN);
                                                                   this->LengthOfItemsSet-=1;
                                                               }
                                                               QString TDBCOlHeader_Items_String::GetItem(int itemN){
                                                                   QString R="";
                                                                   if(itemN<0){
                                                                       itemN+=(this->LengthOfItemsSet+1);
                                                                   }
                                                                   if(itemN==1 && itemN<=this->LengthOfItemsSet){
                                                                       R=this->content[itemN-1];
                                                                   }
                                                                   return R;
                                                               }
                                                               int TDBCOlHeader_Items_String::GetLengthOfItemsList(){ return this->LengthOfItemsSet; }
                                                           //     override object Clone(){
                                                           //        return new TDBCOlHeader_Items_String(this->GetDoubleVal());
                                                           //    }
                                                  //};//cl TDBCOlHeader_Items_String





    // class DataCell:ICloneable
    //        {
    //            TDataCell cell;
    //             DataCell() {
    //                cell = NULL;
    //                SetDefault0();
    //            }
            //
    DataCell::DataCell() {//1
        cell = NULL;
        SetDefault0();
    }
    DataCell::DataCell(double val)
    {
        cell = NULL;
        SetDefault0();
        SetValAndTypeDouble(val);
    }
    DataCell::DataCell(float val)
    {
        cell = NULL;
        SetDefault0();
        SetValAndTypeFloat(val);
    }
    DataCell::DataCell(int val)
    {
         cell = NULL;
         SetDefault0();
         SetValAndTypeInt(val);
    }
    DataCell::DataCell(bool val)
    {
        cell = NULL;
        SetDefault0();
        SetValAndTypeBool(val);
    }
    DataCell::DataCell(QString val)
    {
        cell = NULL;
        SetDefault0();
        SetValAndTypeString(val);
    }
    DataCell::DataCell(double*arr, int Length)
    {
        cell = NULL;
        SetDefault0();
        SetArrAndTypeDouble(arr, Length);
    }
    DataCell::DataCell(float*arr, int Length)
    {
        cell = NULL;
        SetDefault0();
        SetArrAndTypeFloat(arr, Length);
    }
    DataCell::DataCell(int*arr, int Length)
    {
         cell = NULL;
         SetDefault0();
         SetArrAndTypeInt(arr, Length);
    }
    DataCell::DataCell(bool*arr, int Length)
    {
        cell = NULL;
        SetDefault0();
        SetArrAndTypeBool(arr, Length);
    }
    DataCell::DataCell(QString*arr, int Length)
    {
         cell = NULL;
         SetDefault0();
         SetArrAndTypeString(arr, Length);
    }
    /*DataCell::DataCell(int val, bool ConstNotVar)
    {
        cell = NULL;
        SetDefault0();
        if (ConstNotVar)
        {
            cell = new TCellUniqueNumKeeper(val);
        }
        else
        {
            SetValAndTypeInt(val);
        }
     }*/
     DataCell::DataCell(int TypeN, int N)
     {
         double DoubleVal = 0;
         float FloatVal = 0;
         int IntVal = 0;
         bool BoolVal =BoolValByDefault;
         QString StringVal = "";
         double *DoubleArr = NULL;
         float* FloatArr = NULL;
         int* IntArr = NULL;
         bool* BoolArr = NULL;
         QString* StringArr = NULL;
         cell = NULL;
         //SetDefault0();
         SetDefault0();
         switch (TypeN)
         {
              case DoubleTypeN:
                  cell = new TCellDouble();
              break;
              case FloatTypeN:
                  cell = new TCellFloat();
              break;
              case IntTypeN:
                  cell = new TCellInt();
              break;
              case BoolTypeN:
                  cell = new TCellBool();
              break;
              case StringTypeN:
                  cell = new TCellString();
              break;
              case DoubleArrayTypeN:
                  if (N < 1 || N > MaxInt) N = 1;
                  DoubleArr = new double[N];
                  for (int i = 1; i <= N; i++) DoubleArr[i - 1] = 0;
                  cell = new TCellDoubleArr(DoubleArr, N);
                  delete[]DoubleArr;
              break;
              case FloatArrayTypeN:
                  if (N < 1 || N > MaxInt) N = 1;
                  FloatArr = new float[N];
                  for (int i = 1; i <= N; i++) FloatArr[i - 1] = 0;
                  cell = new TCellFloatArr(FloatArr, N);
                  delete[]FloatArr;
              break;
              case IntArrayTypeN:
                  if (N < 1 || N > MaxInt) N = 1;
                  IntArr = new int[N];
                  for (int i = 1; i <= N; i++) IntArr[i - 1] = 0;
                  cell = new TCellIntArr(IntArr, N);
                  delete[]IntArr;
              break;
              case BoolArrayTypeN:
                  if (N < 1 || N > MaxInt) N = 1;
                  BoolArr = new bool[N];
                  for (int i = 1; i <= N; i++) BoolArr[i - 1] = BoolValByDefault;
                  cell = new TCellBoolArr(IntArr, N);
                  delete[]BoolArr;
               break;
               case StringArrayTypeN:
                   if (N < 1 || N > MaxInt) N = 1;
                   StringArr = new QString[N];
                   for (int i = 1; i <= N; i++) StringArr[i - 1] = "";
                   cell = new TCellStringArr(StringArr, N);
                   delete[]StringArr;
               break;
               //case UniqueIntValKeeperTypeN:
               //    cell = new TCellUniqueNumKeeper(N);
               //break;
          }
          this->cell->SetActiveN(1);
          //SetActiveN(1);
      }
      //DataCell::DataCell(DataCellTypeInfo TypeInf)
     /*
      DataCell::DataCell(TypeCell *TypeInf)
      {
          int TypeN=TypeInf->GetTypeN();
          int length=TypeInf->GetLength();
          int N=length;
          double DoubleVal = 0;
          float FloatVal = 0;
          int IntVal = 0;
          bool BoolVal = BoolValByDefault;
          QString StringVal = "";
          double * DoubleArr = NULL;
          float* FloatArr = NULL;
          int* IntArr = NULL;
          bool* BoolArr = NULL;
          QString* StringArr = NULL;
          cell = NULL;
          //SetDefault0();
          switch (TypeN)
          {
               case DoubleTypeN:
                   cell = new TCellDouble();
               break;
               case FloatTypeN:
                   cell = new TCellFloat();
               break;
               case IntTypeN:
                   cell = new TCellInt();
               break;
               case BoolTypeN:
                   cell = new TCellBool();
               break;
               case StringTypeN:
                   cell = new TCellString();
               break;
               case DoubleArrayTypeN:
                   if (length < 1 || N > MaxInt) N = 1;
                   DoubleArr = new double[N];
                   for (int i = 1; i <= N; i++) DoubleArr[i - 1] = 0;
                   cell = new TCellDoubleArr(DoubleArr, N);
                   delete[]DoubleArr;
               break;
               case FloatArrayTypeN:
                   if (N < 1 || N > MaxInt) N = 1;
                   FloatArr = new float[N];
                   for (int i = 1; i <= N; i++) FloatArr[i - 1] = 0;
                   cell = new TCellFloatArr(FloatArr, N);
                   delete[]FloatArr;
               break;
               case IntArrayTypeN:
                   if (N < 1 || N > MaxInt) N = 1;
                   IntArr = new int[N];
                   for (int i = 1; i <= N; i++) IntArr[i - 1] = 0;
                   cell = new TCellIntArr(IntArr, N);
                   delete[]IntArr;
               break;
               case BoolArrayTypeN:
                   if (N < 1 || N > MaxInt) N = 1;
                   BoolArr = new bool[N];
                   for (int i = 1; i <= N; i++) BoolArr[i - 1] = BoolValByDefault;
                   cell = new TCellBoolArr(IntArr, N);
                   delete[]BoolArr;
               break;
               case StringArrayTypeN:
                    if (N < 1 || N > MaxInt) N = 1;
                    StringArr = new QString[N];
                    for (int i = 1; i <= N; i++) StringArr[i - 1] = "";
                    cell = new TCellStringArr(StringArr, N);
                    delete[]StringArr;
               break;
               //case UniqueIntValKeeperTypeN:
               //    cell = new TCellUniqueNumKeeper(N);
               //break;
           }
           this->cell->SetActiveN(1);
      }
      */
      //
      void DataCell::SetDefault0()
      {
          int TypeN = DefaultAnyCellTypeN;
          switch (TypeN)
          {
               case DoubleTypeN:
                   cell = new TCellDouble();
               break;
               case FloatTypeN:
                   cell = new TCellFloat();
               break;
               case IntTypeN:
                   cell = new TCellInt();
               break;
               case BoolTypeN:
                   cell = new TCellBool();
               break;
               case StringTypeN:
                   cell = new TCellString();
               break;
               case DoubleArrayTypeN:
                   cell = new TCellDoubleArr();
               break;
               case FloatArrayTypeN:
                   cell = new TCellFloatArr();
               break;
               case IntArrayTypeN:
                   cell = new TCellIntArr();
               break;
               case BoolArrayTypeN:
                   cell = new TCellBoolArr();
               break;
               case StringArrayTypeN:
                   cell = new TCellStringArr();
              break;
           }//swch
        }//fn
            //
      TDataCell* DataCell::GetCell() {
          return (this->cell);
      }
            //
      //DataCellTypeInfo DataCell::GetTypeInfo()
      //TypeCell* DataCell::GetTypeInfo()
      //{
      //     int TypeN = GetTypeN();
      //     int length = GetLength();
      //     //DataCellTypeInfo TypeInf = new DataCellTypeInfo(TypeN, length);
      //     TypeCell TypeInf ;//= new DataCellTypeInfo(TypeN, length);
      //     return &TypeInf;
      // }
      // void DataCell::SetTypeAndDefaultValByTypeInf(TypeCell *TypeInf, bool PreserveVal)
      // {
      //     //TableCellAccessConfiguration cfg;//=new TableCellAccessConfiguration();
     //      int TypeN = TypeInf->GetTypeN();
     //      int length = TypeInf->GetLength();
     //      //cfg.LengthOfArrCellTypes=length;
      //     //cfg.PreserveVal=PreserveVal;
      //     //this->SetTypeN(TypeN, &cfg);
      //     this->SetTypeN(TypeN, length, BoolToInt(PreserveVal));
      // }
       /*
      void DataCell::SetType(TypeCell *TypeInf)
        {
            double dVal;
            float fVal;
            int iVal;
            bool bVal;
            QString sVal;
            double*dArr=NULL;
            float*fArr=NULL;
            int* iArr=NULL;
            bool*bArr=NULL;
            QString* sArr=NULL, *names=NULL;
            int TypeN, TypeNPrev, LengthOfItemsSet, PrevLengthOfItemsSet, LengthOfNamesSet, MinLengthOfItemsSet;
            //
            if(cell!=NULL){
                TypeNPrev=cell->GetTypeN();
            }else{
                TypeNPrev=0;
            }
            //if(cell!=NULL)PrevLengthOfItemsSet=cell->GetLength();
            //else PrevLengthOfItemsSet=1;//0;
            if(TypeInf==NULL){
                TypeN=DoubleTypeN;
                LengthOfItemsSet = 1;
            }else{
                TypeN = TypeInf->GetTypeN();
                LengthOfItemsSet = TypeInf->GetLength();
            }
            if(cell==NULL){
                TypeNPrev=DoubleTypeN;
                PrevLengthOfItemsSet = 1;
            }else{
                TypeNPrev = cell->GetTypeN();
                PrevLengthOfItemsSet = cell->GetLength();
            }
            //
            if(TypeNPrev!=TypeN){
                switch(TypeN){
                    case DoubleTypeN:
                        if(cell==NULL){
                            dVal=0;
                        }else{
                            dVal=cell->GetDoubleVal();
                            if(TypeN!=TypeNPrev){
                                delete cell;
                                cell=new TCellDouble(dVal);
                            }
                        }
                    break;
                    case FloatTypeN:
                        if(cell==NULL){
                            fVal=0;
                        }else{
                            fVal=cell->GetFloatVal();
                            if(TypeN!=TypeNPrev){
                                delete cell;
                                cell=new TCellFloat(fVal);
                            }
                        }
                    break;
                    case IntTypeN:
                        if(cell==NULL){
                            iVal=0;
                        }else{
                            iVal=cell->GetIntVal();
                            if(TypeN!=TypeNPrev){
                                delete cell;
                                cell=new TCellInt(iVal);
                            }
                        }
                    break;
                    case BoolTypeN:
                        if(cell==NULL){
                            bVal=BoolValByDefault;
                        }else{
                            bVal=cell->GetBoolVal();
                            if(TypeN!=TypeNPrev){
                                delete cell;
                                cell=new TCellBool(bVal);
                            }
                        }
                    break;
                    case StringTypeN:
                        if(cell==NULL){
                            sVal="";
                        }else{
                            sVal=cell->ToString();
                            if(TypeN!=TypeNPrev){
                                delete cell;
                                cell=new TCellString(sVal);
                            }
                        }
                    break;
                    case UniqueIntValKeeperTypeN:
                        //
                    break;
                    case DoubleArrayTypeN:

                        if(cell==NULL){
                            dArr=0;
                        }else{

                        }
                    break;
                    case FloatArrayTypeN:

                    break;
                    case IntArrayTypeN:

                    break;
                    case BoolArrayTypeN:

                    break;
                    case StringArrayTypeN:

                    break;
                    case DoubleItemsDBFieldHeaderCellTypeN:

                    break;
                    case IntItemsDBFieldHeaderCellTypeN:

                    break;
                    case StringItemsDBFieldHeaderCellTypeN:

                    break;
                }//switch
            }else{// if(TypeNPrev!=TypeN)
                if(cell!=NULL)PrevLengthOfItemsSet=cell->GetLength();
                else PrevLengthOfItemsSet=1;//0;
            }
        }//fn
      */
       //
             double DataCell::GetDoubleVal()
            {
                return cell->GetDoubleVal();
            }
             float DataCell::GetFloatVal()
            {
                return cell->GetFloatVal();
            }
             int DataCell::GetIntVal()
            {
                return cell->GetIntVal();
            }
             bool DataCell::GetBoolVal()
            {
                return cell->GetBoolVal();
            }
            QString DataCell::ToString()
            {
                //QString s;
                //s=RealToString(this->val);
                //s.setNum(this->val);
                //return cell.ToString();
                return this->cell->ToString();
            }
            //
            void DataCell::GetDoubleArr(double*&vals, int&count)
            {
                cell->GetDoubleArr(vals, count);
            }
             void DataCell::GetFloatArr(float*&vals, int&count)
            {
                cell->GetFloatArr(vals, count);
            }
             void DataCell::GetIntArr(int*&vals, int&count)
            {
                cell->GetIntArr(vals, count);
            }
             void DataCell::GetBoolArr(bool*&vals, int&count)
            {
                cell->GetBoolArr(vals,count);
            }
             void DataCell::ToStringArr(QString*&vals, int&count)
            {
                cell->ToStringArr(vals, count);
            }
            //
             double DataCell::GetDoubleValN(int N)
            {
                return cell->GetDoubleValN(N);
            }
             float DataCell::GetFloatValN(int N)
            {
                return cell->GetFloatValN(N);
            }
             int DataCell::GetIntValN(int N)
            {
                return cell->GetIntValN(N);
            }
             bool DataCell::GetBoolValN(int N)
            {
                return cell->GetBoolValN(N);
            }
            QString DataCell::ToStringN(int N)
            {
                return cell->ToStringN(N);
            }
            //
             void DataCell::SetVal(double val){ cell->SetVal(val); }
             void DataCell::SetVal(int val){ cell->SetVal(val); }
             void DataCell::SetVal(bool val) { cell->SetVal(val); }
             void DataCell::SetVal(QString val) { cell->SetVal(val); }
            //
             void DataCell::SetValN(double val, int N) { cell->SetValN(val, N); }
             void DataCell::SetValN(float val, int N) { cell->SetValN(val, N); }
             void DataCell::SetValN(int val, int N) { cell->SetValN(val, N); }
             void DataCell::SetValN(bool val, int N) { cell->SetValN(val, N); }
             void DataCell::SetValN(QString val, int N) { cell->SetValN(val, N); }
            //
             int DataCell::GetTypeN() { return cell->GetTypeN(); }
             int DataCell::GetLength() {
                int N = 0;
                if (cell != NULL) N = cell->GetLength();
                return N;
            }
             int DataCell::GetActiveN() {
                int N = 0;
                if (cell != NULL) N = cell->GetActiveN();
                return N;
            }
            //
             void DataCell::SetActiveN(int N)
            {
                cell->SetActiveN(N);
            }
             void DataCell::SetLength(int Length){
                cell->SetLength(Length);
            }
            //
             void DataCell::DelValN(int N)
            {
                cell->DelValN(N);
            }
            //
             void DataCell::AddOrInsDoubleVal(double val, int N)
            {
                cell->AddOrInsDoubleVal(val, N);
            }
             void DataCell::AddOrInsFloatVal(float val, int N)
            {
                cell->AddOrInsFloatVal(val, N);
            }
             void DataCell::AddOrInsIntVal(int val, int N)
            {
                cell->AddOrInsIntVal(val, N);
            }
             void DataCell::AddOrInsBoolVal(bool val, int N)
            {
                cell->AddOrInsBoolVal(val, N);
            }
             void DataCell::AddOrInsStringVal(QString val, int N)
            {
                cell->AddOrInsStringVal(val, N);
            }
            //
             void DataCell::Assign(double val)
            {
                cell = new TCellDouble();
                cell->SetVal(val);
                //cell.SetValAndT
            }
             void DataCell::Assign(float val)
            {
                cell = new TCellFloat();
                cell->SetVal(val);
            }
             void DataCell::Assign(int val)
            {
                cell = new TCellInt();
                cell->SetVal(val);
            }
             void DataCell::Assign(bool val)
            {
                cell = new TCellBool();
                cell->SetVal(val);
            }
             void DataCell::Assign(QString val)
            {
                cell = new TCellString();
                cell->SetVal(val);
            }
             void DataCell::Assign(double val, int N)
            {
                double*arr=NULL;
                int ActualLength, PrevLength, MinLength, PrevTypeN;
                //TDataCell* bufCell=NULL;
                if(cell!=NULL)PrevTypeN=cell->GetTypeN();
                if(cell!=NULL)PrevLength=cell->GetLength();
                if(cell!=NULL)PrevTypeN=cell->GetTypeN();
                if(cell!=NULL && !((PrevTypeN==DoubleArrayTypeN || PrevTypeN==DoubleItemsDBFieldHeaderCellTypeN)&&PrevLength>=N)){
                    if(N<PrevLength) ActualLength=PrevLength; else ActualLength=N;
                    if(ActualLength<=PrevLength) MinLength=ActualLength; else MinLength=PrevLength;
                    arr=new double[ActualLength];
                    for(int i=1; i<=ActualLength; i++) arr[i-1]=0;
                    if(cell!=NULL)for(int i=1; i<=PrevLength; i++) arr[i-1]=cell->GetDoubleValN(i);
                    if(cell!=NULL)delete cell;
                    cell = new TCellDoubleArr(arr, ActualLength);
                    delete[]arr;
                }
                cell->SetValN(val, N);
                /*if (cell==NULL || (cell->GetTypeN() != DoubleTypeN && PrevLength < N))
                {
                    bufCell=cell;
                    if(N<PrevLength) ActualLength=PrevLength; else ActualLength=N;
                    if(ActualLength<=PrevLength) MinLength=ActualLength; else MinLength=PrevLength;
                    arr=new double[ActualLength];
                    for(int i=1; i<=ActualLength; i++) arr[i-1]=0;
                    for(int i=1; i<=MinLength; i++) arr[i-1]=bufCell.GetDoubleValN(N);
                    cell = new TCellDoubleArr(arr, ActualLength);
                }
                cell->SetValN(val, N);
                delete[]arr;*/
            }
             void DataCell::Assign(float val, int N)
            {
                float* arr = NULL;
                int ActualLength, PrevLength, MinLength, PrevTypeN;
                //TDataCell* bufCell=NULL;
                if(cell!=NULL)PrevTypeN=cell->GetTypeN();
                if(cell!=NULL)PrevLength=cell->GetLength();
                if(cell!=NULL)PrevTypeN=cell->GetTypeN();
                if(cell!=NULL && !((PrevTypeN==FloatArrayTypeN || PrevTypeN==DoubleItemsDBFieldHeaderCellTypeN)&&PrevLength>=N)){
                    if(N<PrevLength) ActualLength=PrevLength; else ActualLength=N;
                    if(ActualLength<=PrevLength) MinLength=ActualLength; else MinLength=PrevLength;
                    arr=new float[ActualLength];
                    for(int i=1; i<=ActualLength; i++) arr[i-1]=0;
                    if(cell!=NULL)for(int i=1; i<=PrevLength; i++) arr[i-1]=cell->GetFloatValN(i);
                    if(cell!=NULL)delete cell;
                    cell = new TCellFloatArr(arr, ActualLength);
                    delete[]arr;
                }
                cell->SetValN(val, N);
                /*int ActualLength, PrevLength = cell->GetLength(), MinLength;
                TDataCell bufCell;
                if (cell==NULL || (cell->GetTypeN() != DoubleTypeN && PrevLength < N))
                {
                    bufCell = cell;
                    if (N < PrevLength) ActualLength = PrevLength; else ActualLength = N;
                    if (ActualLength <= PrevLength) MinLength = ActualLength; else MinLength = PrevLength;
                    arr = new float[ActualLength];
                    for (int i = 1; i <= ActualLength; i++) arr[i - 1] = 0;
                    for (int i = 1; i <= MinLength; i++) arr[i - 1] = bufCell.GetFloatValN(N);
                    cell = new TCellFloatArr(arr, ActualLength);
                }
                cell->SetValN(val, N);
                delete[]arr;*/
            }
             void DataCell::Assign(int val, int N)
            {
                int* arr = NULL;
                int ActualLength, PrevLength, MinLength, PrevTypeN;
                //TDataCell* bufCell=NULL;
                if(cell!=NULL)PrevTypeN=cell->GetTypeN();
                if(cell!=NULL)PrevLength=cell->GetLength();
                if(cell!=NULL)PrevTypeN=cell->GetTypeN();
                if(cell!=NULL && !((PrevTypeN==IntArrayTypeN || PrevTypeN==IntItemsDBFieldHeaderCellTypeN)&&PrevLength>=N)){
                    if(N<PrevLength) ActualLength=PrevLength; else ActualLength=N;
                    if(ActualLength<=PrevLength) MinLength=ActualLength; else MinLength=PrevLength;
                    arr=new int[ActualLength];
                    for(int i=1; i<=ActualLength; i++) arr[i-1]=0;
                    if(cell!=NULL)for(int i=1; i<=PrevLength; i++) arr[i-1]=cell->GetIntValN(i);
                    if(cell!=NULL)delete cell;
                    cell = new TCellIntArr(arr, ActualLength);
                    delete[]arr;
                }
                cell->SetValN(val, N);
                /*int ActualLength, PrevLength = cell->GetLength(), MinLength;
                TDataCell bufCell;
                if (cell==NULL || (cell->GetTypeN() != DoubleTypeN && PrevLength < N))
                {
                    bufCell = cell;
                    if (N < PrevLength) ActualLength = PrevLength; else ActualLength = N;
                    if (ActualLength <= PrevLength) MinLength = ActualLength; else MinLength = PrevLength;
                    arr = new int[ActualLength];
                    for (int i = 1; i <= ActualLength; i++) arr[i - 1] = 0;
                    for (int i = 1; i <= MinLength; i++) arr[i - 1] = bufCell.GetIntValN(N);
                    cell = new TCellIntArr(arr, ActualLength);
                }
                cell->SetValN(val, N);
                delete[]arr;*/
            }
             void DataCell::Assign(bool val, int N)
            {
                bool* arr = NULL;
                int ActualLength, PrevLength, MinLength, PrevTypeN;
                //TDataCell* bufCell=NULL;
                if(cell!=NULL)PrevTypeN=cell->GetTypeN();
                if(cell!=NULL)PrevLength=cell->GetLength();
                if(cell!=NULL)PrevTypeN=cell->GetTypeN();
                if(cell!=NULL && !((PrevTypeN==BoolArrayTypeN /*|| PrevTypeN==IntItemsDBFieldHeaderCellTypeN*/)&&PrevLength>=N)){
                    if(N<PrevLength) ActualLength=PrevLength; else ActualLength=N;
                    if(ActualLength<=PrevLength) MinLength=ActualLength; else MinLength=PrevLength;
                    arr=new bool[ActualLength];
                    for(int i=1; i<=ActualLength; i++) arr[i-1]=BoolValByDefault;
                    if(cell!=NULL)for(int i=1; i<=PrevLength; i++) arr[i-1]=cell->GetBoolValN(i);
                    if(cell!=NULL)delete cell;
                    cell = new TCellBoolArr(arr, ActualLength);
                    delete[]arr;
                }
                cell->SetValN(val, N);
                /*int ActualLength, PrevLength, MinLength, PrevTypeN;
                //TDataCell* bufCell=NULL;
                if(cell!=NULL)PrevTypeN=cell->GetTypeN();
                if(cell!=NULL)PrevLength=cell->GetLength();
                if(cell!=NULL)PrevTypeN=cell->GetTypeN();
                if(cell!=NULL && !((PrevTypeN==IntArrayTypeN || PrevTypeN==IntItemsDBFieldHeaderCellTypeN)&&PrevLength>=N)){
                    if(N<PrevLength) ActualLength=PrevLength; else ActualLength=N;
                    if(ActualLength<=PrevLength) MinLength=ActualLength; else MinLength=PrevLength;
                    arr=new bool[ActualLength];
                    for(int i=1; i<=ActualLength; i++) arr[i-1]=0;
                    if(cell!=NULL)for(int i=1; i<=PrevLength; i++) arr[i-1]=cell->GetDoubleValN(N);
                    if(cell!=NULL)delete cell;
                    cell = new TCellDoubleArr(arr, ActualLength);
                    delete[]arr;
                }
                cell->SetValN(val, N);*/
                /*
                int ActualLength, PrevLength = cell->GetLength(), MinLength;
                TDataCell bufCell;
                if (cell==NULL || (cell.GetTypeN() != DoubleTypeN && PrevLength < N))
                {
                    bufCell = cell;
                    if (N < PrevLength) ActualLength = PrevLength; else ActualLength = N;
                    if (ActualLength <= PrevLength) MinLength = ActualLength; else MinLength = PrevLength;
                    arr = new bool[ActualLength];
                    for (int i = 1; i <= ActualLength; i++) arr[i - 1] = BoolValByDefault;
                    for (int i = 1; i <= MinLength; i++) arr[i - 1] = bufCell.GetBoolValN(N);
                    cell = new TCellBoolArr(arr, ActualLength);
                }
                cell->SetValN(val, N);
                delete[]arr;
                */
            }
             void DataCell::Assign(QString val, int N)
            {
                QString* arr = NULL;
                int ActualLength, PrevLength, MinLength, PrevTypeN;
                //TDataCell* bufCell=NULL;
                if(cell!=NULL)PrevTypeN=cell->GetTypeN();
                if(cell!=NULL)PrevLength=cell->GetLength();
                if(cell!=NULL)PrevTypeN=cell->GetTypeN();
                if(cell!=NULL && !((PrevTypeN==StringArrayTypeN || PrevTypeN==StringItemsDBFieldHeaderCellTypeN)&&PrevLength>=N)){
                    if(N<PrevLength) ActualLength=PrevLength; else ActualLength=N;
                    if(ActualLength<=PrevLength) MinLength=ActualLength; else MinLength=PrevLength;
                    arr=new QString[ActualLength];
                    for(int i=1; i<=ActualLength; i++) arr[i-1]="";
                    if(cell!=NULL)for(int i=1; i<=PrevLength; i++) arr[i-1]=cell->ToStringN(i);
                    if(cell!=NULL)delete cell;
                    cell = new TCellStringArr(arr, ActualLength);
                    delete[]arr;
                }
                cell->SetValN(val, N);
                /*int ActualLength, PrevLength = cell->GetLength(), MinLength;
                TDataCell bufCell;
                if (cell==NULL || (cell.GetTypeN() != DoubleTypeN && PrevLength < N))
                {
                    bufCell = cell;
                    if (N < PrevLength) ActualLength = PrevLength; else ActualLength = N;
                    if (ActualLength <= PrevLength) MinLength = ActualLength; else MinLength = PrevLength;
                    arr = new string[ActualLength];
                    for (int i = 1; i <= ActualLength; i++) arr[i - 1] = "";
                    for (int i = 1; i <= MinLength; i++) arr[i - 1] = bufCell.ToStringN(N);
                    cell = new TCellBoolArr(arr, ActualLength);
                }
                cell->SetValN(val, N);
                delete[]arr;*/
            }
             void DataCell::Assign(double* val, int count)
            {
                //cell = new TCellDoubleArr(val, count);
                 if(cell!=NULL)delete cell;
                cell = new TCellDoubleArr(val, count);
            }
             void DataCell::Assign(float* val, int count)
            {
                //cell = new TCellFloatArr(val, count);
                 if(cell!=NULL)delete cell;
                cell = new TCellFloatArr(val, count);
            }
             void DataCell::Assign(int* val, int count)
            {
                //cell = new TCellIntArr(val, count);
                 if(cell!=NULL)delete cell;
                cell = new TCellIntArr(val, count);
            }
             void DataCell::Assign(bool* val, int count)
            {
                //cell = new TCellBoolArr(val,  count);
                 if(cell!=NULL)delete cell;
                cell = new TCellBoolArr(val,  count);
            }
             void DataCell::Assign(QString* val, int count)
            {
                //cell = new TCellStringArr(val, count);
                 if(cell!=NULL)delete cell;
                cell = new TCellStringArr(val, count);
            }
            /* void DataCell::Assign(double* val, int count, QString name1, QString name2, QString name3)
            {
                cell = new TDataBaseFieldHeader_WithItems_Double(val, count, name1, name2, name3);
            }
             void DataCell::Assign(QString* val, int count, QString name1, QString name2, QString name3)
            {
                cell = new TDataBaseFieldHeader_WithItems_String(val, count, name1, name2, name3);
            }*/
             void DataCell::Assign(double* val, int countItems, QString* names, int countNames)
             {
                 if(cell!=NULL) delete cell;
                 cell = new TDBCOlHeader_Items_Double(val, countItems, names, countNames);
             }
             /*void DataCell::Assign(float* val, int countItems, QString* names, int countNames)
             {
                 if(cell!=NULL) delete cell;
                 cell = new TDBCOlHeader_Items_Double(val, countItems, names, countNames);
             }*/
             void DataCell::Assign(int* val, int countItems, QString* names, int countNames)
             {
                 if(cell!=NULL) delete cell;
                 cell = new TDBCOlHeader_Items_Int(val, countItems, names, countNames);
             }
             void DataCell::Assign(QString* val, int countItems, QString* names, int countNames)
             {
                  if(cell!=NULL) delete cell;
                 cell = new TDBCOlHeader_Items_String(val, countItems, names, countNames);
             }
            //void DataCell::Assign(TDataCell obj)//dynamic cast?
            //{
            //    cell = obj;
            //}
            void DataCell::Assign(TDataCell* obj)
            {
                int TypeN, Length=0;
                double DoubleVal;
                float FloatVal;
                int IntVal;
                bool BoolVal;
                QString StringVal;
                double* DoubleArr = NULL;
                float* FloatArr = NULL;
                int* IntArr = NULL;
                bool* BoolArr = NULL;
                QString* StringArr = NULL;
                //
                if(this->cell!=NULL) delete cell;
                //
                if (obj == NULL) cell = NULL;
                else
                {
                    TypeN = obj->GetTypeN();
                    switch (TypeN)
                    {
                        case DoubleTypeN:
                            DoubleVal = obj->GetDoubleVal();
                            cell = new TCellDouble(DoubleVal);
                            break;
                        case FloatTypeN:
                            FloatVal = obj->GetFloatVal();
                            cell = new TCellFloat(FloatVal);
                            break;
                        case IntTypeN:
                            IntVal = obj->GetIntVal();
                            cell = new TCellInt(IntVal);
                            break;
                        case BoolTypeN:
                            BoolVal = obj->GetBoolVal();
                            cell = new TCellBool(BoolVal);
                            break;
                        case StringTypeN:
                            StringVal = obj->ToString();
                            cell = new TCellString(StringVal);
                            break;
                        case DoubleArrayTypeN:
                            obj->GetDoubleArr(DoubleArr, Length);
                            cell = new TCellDoubleArr(DoubleArr, Length);
                            break;
                        case FloatArrayTypeN:
                            obj->GetFloatArr(FloatArr, Length);
                            cell = new TCellFloatArr(FloatArr, Length);
                            break;
                        case IntArrayTypeN:
                            obj->GetIntArr(IntArr, Length);
                            cell = new TCellIntArr(IntArr, Length);
                            break;
                        case BoolArrayTypeN:
                            obj->GetBoolArr(BoolArr, Length);
                            cell = new TCellBoolArr(BoolArr, Length);
                            break;
                        case StringArrayTypeN:
                            obj->ToStringArr(StringArr, Length);
                            cell = new TCellStringArr(StringArr, Length);
                            break;
                    }//swch
                }//if
            }
            void DataCell::Assign(DataCell obj)
            {
                int TypeN, Length=0;
                double DoubleVal;
                float FloatVal;
                int IntVal;
                bool BoolVal;
                QString StringVal;
                double* DoubleArr = NULL;
                float* FloatArr = NULL;
                int* IntArr = NULL;
                bool* BoolArr = NULL;
                QString* StringArr = NULL;
                //if (obj == NULL) cell = NULL;
               // else
               //{
                    TypeN = obj.GetTypeN();
                    switch (TypeN)
                    {
                        case DoubleTypeN:
                            DoubleVal = obj.GetDoubleVal();
                            cell = new TCellDouble(DoubleVal);
                            break;
                        case FloatTypeN:
                            FloatVal = obj.GetFloatVal();
                            cell = new TCellFloat(FloatVal);
                            break;
                        case IntTypeN:
                            IntVal = obj.GetIntVal();
                            cell = new TCellInt(IntVal);
                            break;
                        case BoolTypeN:
                            BoolVal = obj.GetBoolVal();
                            cell = new TCellBool(BoolVal);
                            break;
                        case StringTypeN:
                            StringVal = obj.ToString();
                            cell = new TCellString(StringVal);
                            break;
                        case DoubleArrayTypeN:
                            obj.GetDoubleArr(DoubleArr, Length);
                            cell = new TCellDoubleArr(DoubleArr, Length);
                            break;
                        case FloatArrayTypeN:
                            obj.GetFloatArr(FloatArr, Length);
                            cell = new TCellFloatArr(FloatArr, Length);
                            break;
                        case IntArrayTypeN:
                            obj.GetIntArr(IntArr, Length);
                            cell = new TCellIntArr(IntArr, Length);
                            break;
                        case BoolArrayTypeN:
                            obj.GetBoolArr(BoolArr, Length);
                            cell = new TCellBoolArr(BoolArr, Length);
                            break;
                        case StringArrayTypeN:
                            obj.ToStringArr(StringArr, Length);
                            cell = new TCellStringArr(StringArr, Length);
                            break;
                    }//swch
                //}//if
            }//fn asgn
            //mark34-1
             void DataCell::AssignBy(TDataCell *CellFrom)
            {
                TDataCell *CellTo = this->cell;
                int TypeTo = CellTo->GetTypeN(), TypeFrom = CellFrom->GetTypeN(), LenFrom = CellFrom->GetLength(), LenTo = CellTo->GetLength(), LenMin;
                double DoubleVal;
                float FloatVal;
                int IntVal;
                bool BoolVal;
                QString StringVal;
                double* DoubleArr = NULL;
                float* FloatArr = NULL;
                int* IntArr = NULL;
                bool* BoolArr = NULL;
                QString* StringArr = NULL;
                if (LenFrom >= LenTo) LenMin = LenFrom; else LenMin = LenTo;
                switch (TypeFrom)
                {
                    case DoubleTypeN:
                        switch (TypeTo)
                        {
                            case DoubleTypeN:
                                CellTo->SetByValDouble(CellFrom->GetDoubleVal());
                                //DoubleVal=CellFrom->GetDoubleVal();
                                //CellTo->SetByValDouble(DoubleVal);
                                break;
                            case FloatTypeN:
                                //CellTo->SetByValFloat(CellFrom.GetFloatVal());
                                //CellTo.SetByValDouble(CellFrom.GetDoubleVal());
                                FloatVal = CellFrom->GetFloatVal();
                                CellTo->SetByValFloat(FloatVal);
                                DoubleVal = CellFrom->GetDoubleVal();
                                CellTo->SetByValDouble(DoubleVal);
                                break;
                            case IntTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                                CellTo->SetByValDouble(CellFrom->GetDoubleVal());
                                break;
                            case BoolTypeN:
                                CellTo->SetByValBool(CellFrom->GetBoolVal());
                                CellTo->SetByValDouble(CellFrom->GetDoubleVal());
                                break;
                            case StringTypeN:
                                CellTo->SetByValString(CellFrom->ToString());
                                CellTo->SetByValDouble(CellFrom->GetDoubleVal());
                                break;
                            case DoubleArrayTypeN:
                                CellFrom->GetDoubleArr(DoubleArr, LenFrom);
                                CellTo->SetByArrDouble(DoubleArr, LenFrom);
                                break;
                            case FloatArrayTypeN:
                                CellFrom->GetDoubleArr(DoubleArr, LenFrom);
                                CellTo->SetByArrDouble(DoubleArr, LenFrom);
                                CellFrom->GetFloatArr(FloatArr, LenFrom);
                                CellTo->SetByArrFloat(FloatArr, LenFrom);
                                break;
                            case IntArrayTypeN:
                                CellFrom->GetDoubleArr(DoubleArr, LenFrom);
                                CellTo->SetByArrDouble(DoubleArr, LenFrom);
                                CellFrom->GetIntArr(IntArr, LenFrom);
                                CellTo->SetByArrInt(IntArr, LenFrom);
                                break;
                            case BoolArrayTypeN:
                                CellFrom->GetDoubleArr(DoubleArr, LenFrom);
                                CellTo->SetByArrDouble(DoubleArr, LenFrom);
                                CellFrom->GetBoolArr(BoolArr, LenFrom);
                                CellTo->SetByArrBool(BoolArr, LenFrom);
                                break;
                            case StringArrayTypeN:
                                CellFrom->GetDoubleArr(DoubleArr, LenFrom);
                                CellTo->SetByArrDouble(DoubleArr, LenFrom);
                                CellFrom->ToStringArr(StringArr, LenFrom);
                                CellTo->SetByArrString(StringArr, LenFrom);
                                break;
                            case UniqueIntValKeeperTypeN:
                                //NOp;
                                break;
                            case DoubleItemsDBFieldHeaderCellTypeN://ne done!
                                //NOp;
                                break;
                            case IntItemsDBFieldHeaderCellTypeN://ne done!
                                //NOp;
                                break;
                            case StringItemsDBFieldHeaderCellTypeN://ne done!
                                //NOp;
                                break;
                        }//switch
                        break;
                    case FloatTypeN:
                        switch (TypeTo)
                        {
                            case DoubleTypeN:
                                DoubleVal = CellFrom->GetDoubleVal();
                                CellTo->SetByValDouble(CellFrom->GetDoubleVal());
                                FloatVal = CellFrom->GetFloatVal();
                                CellTo->SetByValFloat(FloatVal);
                                break;
                            case FloatTypeN:
                                FloatVal = CellFrom->GetFloatVal();
                                CellTo->SetByValFloat(FloatVal);
                                //IntVal=CellFrom->GetIntVal();
                                //CellTo->SetByValInt(IntVal);
                                break;
                            case IntTypeN:
                                CellTo->SetByValFloat(CellFrom->GetFloatVal());
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                                break;
                            case BoolTypeN:
                                CellTo->SetByValFloat(CellFrom->GetFloatVal());
                                CellTo->SetByValBool(CellFrom->GetBoolVal());
                                break;
                            case StringTypeN:
                                CellTo->SetByValString(CellFrom->ToString());
                                CellTo->SetByValDouble(CellFrom->GetDoubleVal());
                                break;
                            case DoubleArrayTypeN:
                                FloatVal = CellFrom->GetFloatVal();
                                CellTo->SetByValFloat(FloatVal);
                                CellFrom->GetDoubleArr(DoubleArr, LenFrom);
                                CellTo->SetByArrDouble(DoubleArr, LenFrom);
                                break;
                            case FloatArrayTypeN:
                                CellFrom->GetFloatArr(FloatArr, LenFrom);
                                CellTo->SetByArrFloat(FloatArr, LenFrom);
                                //CellFrom->GetFloatArr(  FloatArr,   LenFrom);
                                //CellTo->SetByArrFloat(FloatArr, LenFrom);
                                break;
                            case IntArrayTypeN:
                                CellFrom->GetFloatArr(FloatArr, LenFrom);
                                CellTo->SetByArrFloat(FloatArr, LenFrom);
                                CellFrom->GetIntArr(IntArr, LenFrom);
                                CellTo->SetByArrInt(IntArr, LenFrom);
                                break;
                            case BoolArrayTypeN:
                                CellFrom->GetFloatArr(FloatArr, LenFrom);
                                CellTo->SetByArrFloat(FloatArr, LenFrom);
                                CellFrom->GetBoolArr(BoolArr, LenFrom);
                                CellTo->SetByArrBool(BoolArr, LenFrom);
                                break;
                            case StringArrayTypeN:
                                CellFrom->GetFloatArr(FloatArr, LenFrom);
                                CellTo->SetByArrFloat(FloatArr, LenFrom);
                                CellFrom->ToStringArr(StringArr, LenFrom);
                                CellTo->SetByArrString(StringArr, LenFrom);
                                break;
                            case UniqueIntValKeeperTypeN:
                                //NOp;
                                break;
                            case DoubleItemsDBFieldHeaderCellTypeN://ne done!
                                //NOp;
                                break;
                            case IntItemsDBFieldHeaderCellTypeN://ne done!
                                //NOp;
                                break;
                            case StringItemsDBFieldHeaderCellTypeN://ne done!
                                //NOp;
                                break;
                        }//switch
                        break;
                    case IntTypeN:
                        switch (TypeTo)
                        {
                            case DoubleTypeN:
                                CellTo->SetByValDouble(CellFrom->GetDoubleVal());
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                                break;
                            case FloatTypeN:
                                CellTo->SetByValFloat(CellFrom->GetFloatVal());
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                                break;
                            case IntTypeN:
                                //CellTo->SetByValFloat(CellFrom->GetFloatVal());
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                                break;
                            case BoolTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                                CellTo->SetByValBool(CellFrom->GetBoolVal());
                                break;
                            case StringTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                                CellTo->SetByValString(CellFrom->ToString());
                                break;
                            case DoubleArrayTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                                CellFrom->GetDoubleArr(DoubleArr, LenFrom);
                                CellTo->SetByArrDouble(DoubleArr, LenFrom);
                                break;
                            case FloatArrayTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                                CellFrom->GetFloatArr(FloatArr, LenFrom);
                                CellTo->SetByArrFloat(FloatArr, LenFrom);
                                //CellFrom->GetFloatArr(  FloatArr,   LenFrom);
                                //CellTo->SetByArrFloat(FloatArr, LenFrom);
                                break;
                            case IntArrayTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                                CellFrom->GetIntArr(IntArr, LenFrom);
                                CellTo->SetByArrInt(IntArr, LenFrom);
                                break;
                            case BoolArrayTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                                CellFrom->GetBoolArr(BoolArr, LenFrom);
                                CellTo->SetByArrBool(BoolArr, LenFrom);
                                break;
                            case StringArrayTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                                CellFrom->ToStringArr(StringArr, LenFrom);
                                CellTo->SetByArrString(StringArr, LenFrom);
                                break;
                            case UniqueIntValKeeperTypeN:
                                //NOp;
                                break;
                            case DoubleItemsDBFieldHeaderCellTypeN://ne done!
                                //NOp;
                                break;
                            case IntItemsDBFieldHeaderCellTypeN://ne done!
                                //NOp;
                                break;
                            case StringItemsDBFieldHeaderCellTypeN://ne done!
                                //NOp;
                                break;
                        }//switch
                        break;
                    case BoolTypeN:
                        switch (TypeTo)
                        {
                            case DoubleTypeN:
                                CellTo->SetByValBool(CellFrom->GetBoolVal());
                                //CellTo->SetByValInt(CellFrom->GetIntVal());
                                break;
                            case FloatTypeN:
                                CellTo->SetByValFloat(CellFrom->GetFloatVal());
                                CellTo->SetByValBool(CellFrom->GetBoolVal());
                                break;
                            case IntTypeN:
                                CellTo->SetByValBool(CellFrom->GetBoolVal());
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                                break;
                            case BoolTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                                CellTo->SetByValBool(CellFrom->GetBoolVal());
                                break;
                            case StringTypeN:
                                CellTo->SetByValBool(CellFrom->GetBoolVal());
                                CellTo->SetByValString(CellFrom->ToString());
                                break;
                            case DoubleArrayTypeN:
                                CellTo->SetByValBool(CellFrom->GetBoolVal());
                                CellFrom->GetDoubleArr(DoubleArr, LenFrom);
                                CellTo->SetByArrDouble(DoubleArr, LenFrom);
                                break;
                            case FloatArrayTypeN:
                                CellTo->SetByValBool(CellFrom->GetBoolVal());
                                CellFrom->GetFloatArr(FloatArr, LenFrom);
                                CellTo->SetByArrFloat(FloatArr, LenFrom);
                                //CellFrom->GetFloatArr(  FloatArr,   LenFrom);
                                //CellTo->SetByArrFloat(FloatArr, LenFrom);
                                break;
                            case IntArrayTypeN:
                                CellTo->SetByValBool(CellFrom->GetBoolVal());
                                CellFrom->GetIntArr(IntArr, LenFrom);
                                CellTo->SetByArrInt(IntArr, LenFrom);
                                break;
                            case BoolArrayTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                                CellFrom->GetBoolArr(BoolArr, LenFrom);
                                CellTo->SetByArrBool(BoolArr, LenFrom);
                                break;
                            case StringArrayTypeN:
                                CellTo->SetByValBool(CellFrom->GetBoolVal());
                                CellFrom->ToStringArr(StringArr, LenFrom);
                                CellTo->SetByArrString(StringArr, LenFrom);
                                break;
                            case UniqueIntValKeeperTypeN:
                                //NOp;
                                break;
                            case DoubleItemsDBFieldHeaderCellTypeN://ne done!
                                //NOp;
                                break;
                            case IntItemsDBFieldHeaderCellTypeN://ne done!
                                //NOp;
                                break;
                            case StringItemsDBFieldHeaderCellTypeN://ne done!
                                //NOp;
                                break;
                        }//switch
                        break;
                    case StringTypeN:
                        switch (TypeTo)
                        {
                            case DoubleTypeN:
                                //CellTo->SetByValBool(CellFrom->GetBoolVal());
                                CellTo->SetByValString(CellFrom->ToString());
                                break;
                            case FloatTypeN:
                                CellTo->SetByValString(CellFrom->ToString());
                                CellTo->SetByValFloat(CellFrom->GetFloatVal());
                                break;
                            case IntTypeN:
                                CellTo->SetByValString(CellFrom->ToString());
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                                break;
                            case BoolTypeN:
                                CellTo->SetByValString(CellFrom->ToString());
                                CellTo->SetByValBool(CellFrom->GetBoolVal());
                                break;
                            case StringTypeN:
                                CellTo->SetByValString(CellFrom->ToString());
                                //CellTo->SetByValBool(CellFrom->GetBoolVal());
                                break;
                            case DoubleArrayTypeN:
                                CellTo->SetByValString(CellFrom->ToString());
                                CellFrom->GetDoubleArr(DoubleArr, LenFrom);
                                CellTo->SetByArrDouble(DoubleArr, LenFrom);
                                break;
                            case FloatArrayTypeN:
                                CellTo->SetByValString(CellFrom->ToString());
                                CellFrom->GetFloatArr(FloatArr, LenFrom);
                                CellTo->SetByArrFloat(FloatArr, LenFrom);
                                break;
                            case IntArrayTypeN:
                                CellTo->SetByValString(CellFrom->ToString());
                                CellFrom->GetIntArr(IntArr, LenFrom);
                                CellTo->SetByArrInt(IntArr, LenFrom);
                                break;
                            case BoolArrayTypeN:
                                CellTo->SetByValString(CellFrom->ToString());
                                CellFrom->GetBoolArr(BoolArr, LenFrom);
                                CellTo->SetByArrBool(BoolArr, LenFrom);
                                break;
                            case StringArrayTypeN:
                                CellTo->SetByValString(CellFrom->ToString());
                                CellFrom->ToStringArr(StringArr, LenFrom);
                                CellTo->SetByArrString(StringArr, LenFrom);
                                break;
                            case UniqueIntValKeeperTypeN:
                                //NOp;
                                break;
                            case DoubleItemsDBFieldHeaderCellTypeN://ne done!
                                //NOp;
                                break;
                            case IntItemsDBFieldHeaderCellTypeN://ne done!
                                //NOp;
                                break;
                            case StringItemsDBFieldHeaderCellTypeN://ne done!
                                //NOp;
                                break;
                        }//switch
                        break;
                    case DoubleArrayTypeN:
                        switch (TypeTo)
                        {
                            case DoubleTypeN:
                                CellTo->SetByValDouble(CellFrom->GetDoubleVal());
                                //CellFrom->GetDoubleArr(  DoubleArr,   LenFrom);
                                //CellTo->SetByArrDouble(DoubleArr, LenFrom);
                                break;
                            case FloatTypeN:
                                CellFrom->GetDoubleArr(DoubleArr, LenFrom);
                                CellTo->SetByArrDouble(DoubleArr, LenFrom);
                                CellTo->SetByValFloat(CellFrom->GetFloatVal());
                                break;
                            case IntTypeN:
                                CellFrom->GetDoubleArr(DoubleArr, LenFrom);
                                CellTo->SetByArrDouble(DoubleArr, LenFrom);
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                                break;
                            case BoolTypeN:
                                CellFrom->GetDoubleArr(DoubleArr, LenFrom);
                                CellTo->SetByArrDouble(DoubleArr, LenFrom);
                                CellTo->SetByValBool(CellFrom->GetBoolVal());
                                break;
                            case StringTypeN:
                                CellTo->SetByValString(CellFrom->ToString());
                                CellFrom->GetDoubleArr(DoubleArr, LenFrom);
                                CellTo->SetByArrDouble(DoubleArr, LenFrom);
                                break;
                            case DoubleArrayTypeN:
                                //CellTo->SetByValString(CellFrom->ToString());
                                CellFrom->GetDoubleArr(DoubleArr, LenFrom);
                                CellTo->SetByArrDouble(DoubleArr, LenFrom);
                                break;
                            case FloatArrayTypeN:
                                CellFrom->GetDoubleArr(DoubleArr, LenFrom);
                                CellTo->SetByArrDouble(DoubleArr, LenFrom);
                                CellFrom->GetFloatArr(FloatArr, LenFrom);
                                CellTo->SetByArrFloat(FloatArr, LenFrom);
                                break;
                            case IntArrayTypeN:
                                CellFrom->GetDoubleArr(DoubleArr, LenFrom);
                                CellTo->SetByArrDouble(DoubleArr, LenFrom);
                                CellFrom->GetIntArr(IntArr, LenFrom);
                                CellTo->SetByArrInt(IntArr, LenFrom);
                                break;
                            case BoolArrayTypeN:
                                CellFrom->GetDoubleArr(DoubleArr, LenFrom);
                                CellTo->SetByArrDouble(DoubleArr, LenFrom);
                                CellFrom->GetBoolArr(BoolArr, LenFrom);
                                CellTo->SetByArrBool(BoolArr, LenFrom);
                                break;
                            case StringArrayTypeN:
                                CellFrom->GetDoubleArr(DoubleArr, LenFrom);
                                CellTo->SetByArrDouble(DoubleArr, LenFrom);
                                CellFrom->ToStringArr(StringArr, LenFrom);
                                CellTo->SetByArrString(StringArr, LenFrom);
                                break;
                            case UniqueIntValKeeperTypeN:
                                //NOp;
                                break;
                            case DoubleItemsDBFieldHeaderCellTypeN://ne done!
                                //NOp;
                                break;
                            case IntItemsDBFieldHeaderCellTypeN://ne done!
                                //NOp;
                                break;
                            case StringItemsDBFieldHeaderCellTypeN://ne done!
                                //NOp;
                                break;
                        }//switch
                        break;
                    case FloatArrayTypeN:
                        switch (TypeTo)
                        {
                            case DoubleTypeN:
                                CellTo->SetByValDouble(CellFrom->GetDoubleVal());
                                CellFrom->GetFloatArr(FloatArr, LenFrom);
                                CellTo->SetByArrFloat(FloatArr, LenFrom);
                                break;
                            case FloatTypeN:
                                CellTo->SetByValFloat(CellFrom->GetFloatVal());
                                CellFrom->GetFloatArr(FloatArr, LenFrom);
                                CellTo->SetByArrFloat(FloatArr, LenFrom);
                                break;
                            case IntTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                                CellFrom->GetFloatArr(FloatArr, LenFrom);
                                CellTo->SetByArrFloat(FloatArr, LenFrom);
                                break;
                            case BoolTypeN:
                                CellFrom->GetFloatArr(FloatArr, LenFrom);
                                CellTo->SetByArrFloat(FloatArr, LenFrom);
                                CellTo->SetByValBool(CellFrom->GetBoolVal());
                                break;
                            case StringTypeN:
                                CellTo->SetByValString(CellFrom->ToString());
                                CellFrom->GetFloatArr(FloatArr, LenFrom);
                                CellTo->SetByArrFloat(FloatArr, LenFrom);
                                break;
                            case DoubleArrayTypeN:
                                CellFrom->GetDoubleArr(DoubleArr, LenFrom);
                                CellTo->SetByArrDouble(DoubleArr, LenFrom);
                                CellFrom->GetFloatArr(FloatArr, LenFrom);
                                CellTo->SetByArrFloat(FloatArr, LenFrom);
                                break;
                            case FloatArrayTypeN:
                                //CellFrom->GetDoubleArr(  DoubleArr,   LenFrom);
                                //CellTo->SetByArrDouble(DoubleArr, LenFrom);
                                CellFrom->GetFloatArr(FloatArr, LenFrom);
                                CellTo->SetByArrFloat(FloatArr, LenFrom);
                                break;
                            case IntArrayTypeN:
                                CellFrom->GetFloatArr(FloatArr, LenFrom);
                                CellTo->SetByArrFloat(FloatArr, LenFrom);
                                CellFrom->GetIntArr(IntArr, LenFrom);
                                CellTo->SetByArrInt(IntArr, LenFrom);
                                break;
                            case BoolArrayTypeN:
                                CellFrom->GetFloatArr(FloatArr, LenFrom);
                                CellTo->SetByArrFloat(FloatArr, LenFrom);
                                CellFrom->GetBoolArr(BoolArr, LenFrom);
                                CellTo->SetByArrBool(BoolArr, LenFrom);
                                break;
                            case StringArrayTypeN:
                                CellFrom->GetFloatArr(FloatArr, LenFrom);
                                CellTo->SetByArrFloat(FloatArr, LenFrom);
                                CellFrom->ToStringArr(StringArr, LenFrom);
                                CellTo->SetByArrString(StringArr, LenFrom);
                                break;
                            case UniqueIntValKeeperTypeN:
                                //NOp;
                                break;
                            case DoubleItemsDBFieldHeaderCellTypeN://ne done!
                                //NOp;
                                break;
                            case IntItemsDBFieldHeaderCellTypeN://ne done!
                                //NOp;
                                break;
                            case StringItemsDBFieldHeaderCellTypeN://ne done!
                                //NOp;
                                break;
                        }//switch
                        break;
                    case IntArrayTypeN:
                        switch (TypeTo)
                        {
                            case DoubleTypeN:
                                CellTo->SetByValDouble(CellFrom->GetDoubleVal());
                                CellFrom->GetIntArr(IntArr, LenFrom);
                                CellTo->SetByArrInt(IntArr, LenFrom);
                                break;
                            case FloatTypeN:
                                CellTo->SetByValFloat(CellFrom->GetFloatVal());
                                CellFrom->GetIntArr(IntArr, LenFrom);
                                CellTo->SetByArrInt(IntArr, LenFrom);
                                break;
                            case IntTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                                CellFrom->GetIntArr(IntArr, LenFrom);
                                CellTo->SetByArrInt(IntArr, LenFrom);
                                break;
                            case BoolTypeN:
                                CellFrom->GetIntArr(IntArr, LenFrom);
                                CellTo->SetByArrInt(IntArr, LenFrom);
                                CellTo->SetByValBool(CellFrom->GetBoolVal());
                                break;
                            case StringTypeN:
                                CellTo->SetByValString(CellFrom->ToString());
                                CellFrom->GetIntArr(IntArr, LenFrom);
                                CellTo->SetByArrInt(IntArr, LenFrom);
                                break;
                            case DoubleArrayTypeN:
                                CellFrom->GetDoubleArr(DoubleArr, LenFrom);
                                CellTo->SetByArrDouble(DoubleArr, LenFrom);
                                CellFrom->GetIntArr(IntArr, LenFrom);
                                CellTo->SetByArrInt(IntArr, LenFrom);
                                break;
                            case FloatArrayTypeN:
                                CellFrom->GetIntArr(IntArr, LenFrom);
                                CellTo->SetByArrInt(IntArr, LenFrom);
                                CellFrom->GetFloatArr(FloatArr, LenFrom);
                                CellTo->SetByArrFloat(FloatArr, LenFrom);
                                break;
                            case IntArrayTypeN:
                                //CellFrom->GetFloatArr(  FloatArr,   LenFrom);
                                //CellTo->SetByArrFloat(FloatArr, LenFrom);
                                CellFrom->GetIntArr(IntArr, LenFrom);
                                CellTo->SetByArrInt(IntArr, LenFrom);
                                break;
                            case BoolArrayTypeN:
                                CellFrom->GetIntArr(IntArr, LenFrom);
                                CellTo->SetByArrInt(IntArr, LenFrom);
                                CellFrom->GetBoolArr(BoolArr, LenFrom);
                                CellTo->SetByArrBool(BoolArr, LenFrom);
                                break;
                            case StringArrayTypeN:
                                CellFrom->GetIntArr(IntArr, LenFrom);
                                CellTo->SetByArrInt(IntArr, LenFrom);
                                CellFrom->ToStringArr(StringArr, LenFrom);
                                CellTo->SetByArrString(StringArr, LenFrom);
                                break;
                            case UniqueIntValKeeperTypeN:
                                //NOp;
                                break;
                            case DoubleItemsDBFieldHeaderCellTypeN://ne done!
                                //NOp;
                                break;
                            case IntItemsDBFieldHeaderCellTypeN://ne done!
                                //NOp;
                                break;
                            case StringItemsDBFieldHeaderCellTypeN://ne done!
                                //NOp;
                                break;
                        }//switch
                        break;
                    case BoolArrayTypeN:
                        switch (TypeTo)
                        {
                            case DoubleTypeN:
                                CellTo->SetByValDouble(CellFrom->GetDoubleVal());
                                CellFrom->GetBoolArr(BoolArr, LenFrom);
                                CellTo->SetByArrBool(BoolArr, LenFrom);
                                break;
                            case FloatTypeN:
                                CellTo->SetByValFloat(CellFrom->GetFloatVal());
                                CellFrom->GetBoolArr(BoolArr, LenFrom);
                                CellTo->SetByArrBool(BoolArr, LenFrom);
                                break;
                            case IntTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                                CellFrom->GetBoolArr(BoolArr, LenFrom);
                                CellTo->SetByArrBool(BoolArr, LenFrom);
                                break;
                            case BoolTypeN:
                                CellFrom->GetBoolArr(BoolArr, LenFrom);
                                CellTo->SetByArrBool(BoolArr, LenFrom);
                                CellTo->SetByValBool(CellFrom->GetBoolVal());
                                break;
                            case StringTypeN:
                                CellTo->SetByValString(CellFrom->ToString());
                                CellFrom->GetBoolArr(BoolArr, LenFrom);
                                CellTo->SetByArrBool(BoolArr, LenFrom);
                                break;
                            case DoubleArrayTypeN:
                                CellFrom->GetDoubleArr(DoubleArr, LenFrom);
                                CellTo->SetByArrDouble(DoubleArr, LenFrom);
                                CellFrom->GetBoolArr(BoolArr, LenFrom);
                                CellTo->SetByArrBool(BoolArr, LenFrom);
                                break;
                            case FloatArrayTypeN:
                                CellFrom->GetBoolArr(BoolArr, LenFrom);
                                CellTo->SetByArrBool(BoolArr, LenFrom);
                                CellFrom->GetFloatArr(FloatArr, LenFrom);
                                CellTo->SetByArrFloat(FloatArr, LenFrom);
                                break;
                            case IntArrayTypeN:
                                CellFrom->GetIntArr(IntArr, LenFrom);
                                CellTo->SetByArrInt(IntArr, LenFrom);
                                CellFrom->GetBoolArr(BoolArr, LenFrom);
                                CellTo->SetByArrBool(BoolArr, LenFrom);
                                break;
                            case BoolArrayTypeN:
                                //CellFrom->GetIntArr(  IntArr,   LenFrom);
                                //CellTo->SetByArrInt(IntArr, LenFrom);
                                CellFrom->GetBoolArr(BoolArr, LenFrom);
                                CellTo->SetByArrBool(BoolArr, LenFrom);
                                break;
                            case StringArrayTypeN:
                                CellFrom->GetBoolArr(BoolArr, LenFrom);
                                CellTo->SetByArrBool(BoolArr, LenFrom);
                                CellFrom->ToStringArr(StringArr, LenFrom);
                                CellTo->SetByArrString(StringArr, LenFrom);
                                break;
                            case UniqueIntValKeeperTypeN:
                                //NOp;
                                break;
                            case DoubleItemsDBFieldHeaderCellTypeN://ne done!
                                //NOp;
                                break;
                            case IntItemsDBFieldHeaderCellTypeN://ne done!
                                //NOp;
                                break;
                            case StringItemsDBFieldHeaderCellTypeN://ne done!
                                //NOp;
                                break;
                        }//switch
                        break;
                    case StringArrayTypeN:
                        switch (TypeTo)
                        {
                            case DoubleTypeN:
                                CellTo->SetByValDouble(CellFrom->GetDoubleVal());
                                CellFrom->ToStringArr(StringArr, LenFrom);
                                CellTo->SetByArrString(StringArr, LenFrom);
                                break;
                            case FloatTypeN:
                                CellTo->SetByValFloat(CellFrom->GetFloatVal());
                                CellFrom->ToStringArr(StringArr, LenFrom);
                                CellTo->SetByArrString(StringArr, LenFrom);
                                break;
                            case IntTypeN:
                                CellTo->SetByValString(CellFrom->ToString());
                                CellFrom->ToStringArr(StringArr, LenFrom);
                                CellTo->SetByArrInt(IntArr, LenFrom);
                                break;
                            case BoolTypeN:
                                CellFrom->ToStringArr(StringArr, LenFrom);
                                CellTo->SetByArrString(StringArr, LenFrom);
                                CellTo->SetByValBool(CellFrom->GetBoolVal());
                                break;
                            case StringTypeN:
                                CellTo->SetByValString(CellFrom->ToString());
                                CellFrom->ToStringArr(StringArr, LenFrom);
                                CellTo->SetByArrString(StringArr, LenFrom);
                                break;
                            case DoubleArrayTypeN:
                                CellFrom->GetDoubleArr(DoubleArr, LenFrom);
                                CellTo->SetByArrDouble(DoubleArr, LenFrom);
                                CellFrom->ToStringArr(StringArr, LenFrom);
                                CellTo->SetByArrString(StringArr, LenFrom);
                                break;
                            case FloatArrayTypeN:
                                CellFrom->ToStringArr(StringArr, LenFrom);
                                CellTo->SetByArrString(StringArr, LenFrom);
                                CellFrom->GetFloatArr(FloatArr, LenFrom);
                                CellTo->SetByArrFloat(FloatArr, LenFrom);
                                break;
                            case IntArrayTypeN:
                                CellFrom->GetIntArr(IntArr, LenFrom);
                                CellTo->SetByArrInt(IntArr, LenFrom);
                                CellFrom->ToStringArr(StringArr, LenFrom);
                                CellTo->SetByArrString(StringArr, LenFrom);
                                break;
                            case BoolArrayTypeN:
                                CellFrom->ToStringArr(StringArr, LenFrom);
                                CellTo->SetByArrString(StringArr, LenFrom);
                                CellFrom->GetBoolArr(BoolArr, LenFrom);
                                CellTo->SetByArrBool(BoolArr, LenFrom);
                                break;
                            case StringArrayTypeN:
                                //CellFrom->ToStringArr(  StringArr,   LenFrom);
                                //CellTo->SetByArrString(StringArr, LenFrom);
                                CellFrom->ToStringArr(StringArr, LenFrom);
                                CellTo->SetByArrString(StringArr, LenFrom);
                                break;
                            case UniqueIntValKeeperTypeN:
                                //NOp;
                                break;
                            case DoubleItemsDBFieldHeaderCellTypeN://ne done!
                                //NOp;
                                break;
                            case IntItemsDBFieldHeaderCellTypeN://ne done!
                                //NOp;
                                break;
                            case StringItemsDBFieldHeaderCellTypeN://ne done!
                                //NOp;
                                break;
                        }//switch
                        break;
                    case UniqueIntValKeeperTypeN:
                        switch (TypeTo)
                        {
                            case DoubleTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                                break;
                            case FloatTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                                break;
                            case IntTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                                break;
                            case BoolTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                                break;
                            case StringTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                                break;
                            case DoubleArrayTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                                break;
                            case FloatArrayTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                                break;
                            case IntArrayTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                                break;
                            case BoolArrayTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                                break;
                            case StringArrayTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                                break;
                            case UniqueIntValKeeperTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                                break;
                            case DoubleItemsDBFieldHeaderCellTypeN://ne done!
                                //NOp;
                                break;
                            case IntItemsDBFieldHeaderCellTypeN://ne done!
                                //NOp;
                                break;
                            case StringItemsDBFieldHeaderCellTypeN://ne done!
                                //NOp;
                                break;
                        }//switch
                    break;
                    case DoubleItemsDBFieldHeaderCellTypeN: //ne done!
                        switch (TypeTo)
                        {
                            case DoubleTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                            break;
                            case FloatTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                            break;
                            case IntTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                            break;
                            case BoolTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                            break;
                            case StringTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                            break;
                            case DoubleArrayTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                            break;
                            case FloatArrayTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                            break;
                            case IntArrayTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                            break;
                            case BoolArrayTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                            break;
                            case StringArrayTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                            break;
                            case UniqueIntValKeeperTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                            break;
                            case DoubleItemsDBFieldHeaderCellTypeN://ne done!
                            //NOp;
                            break;
                            case IntItemsDBFieldHeaderCellTypeN://ne done!
                            //NOp;
                            break;
                            case StringItemsDBFieldHeaderCellTypeN://ne done!
                            //NOp;
                            break;
                    }//switch
                    break;
                    case IntItemsDBFieldHeaderCellTypeN: //ne done!
                        switch (TypeTo)
                        {
                            case DoubleTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                            break;
                            case FloatTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                            break;
                            case IntTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                            break;
                            case BoolTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                            break;
                            case StringTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                            break;
                            case DoubleArrayTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                            break;
                            case FloatArrayTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                            break;
                            case IntArrayTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                            break;
                            case BoolArrayTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                            break;
                            case StringArrayTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                            break;
                            case UniqueIntValKeeperTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                            break;
                            case DoubleItemsDBFieldHeaderCellTypeN://ne done!
                                //NOp;
                            break;
                            case IntItemsDBFieldHeaderCellTypeN://ne done!
                                //NOp;
                            break;
                            case StringItemsDBFieldHeaderCellTypeN://ne done!
                                //NOp;
                            break;
                        }//switch
                    break;
                    case StringItemsDBFieldHeaderCellTypeN: //ne done!
                        switch (TypeTo)
                        {
                            case DoubleTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                            break;
                            case FloatTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                            break;
                            case IntTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                            break;
                            case BoolTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                            break;
                            case StringTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                            break;
                            case DoubleArrayTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                            break;
                            case FloatArrayTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                            break;
                            case IntArrayTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                            break;
                            case BoolArrayTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                            break;
                            case StringArrayTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                            break;
                            case UniqueIntValKeeperTypeN:
                                CellTo->SetByValInt(CellFrom->GetIntVal());
                            break;
                            case DoubleItemsDBFieldHeaderCellTypeN://ne done!
                                //NOp;
                            break;
                            case IntItemsDBFieldHeaderCellTypeN://ne done!
                                //NOp;
                            break;
                            case StringItemsDBFieldHeaderCellTypeN://ne done!
                                //NOp;
                            break;
                        }//switch
                    break;
                }//switch
                this->cell=CellTo;
            }
             void DataCell::AssignBy(DataCell obj)
            {
                TDataCell *ObjCell = obj.GetCell();
                AssignBy(ObjCell);
            }

             DataCell& DataCell::operator=(double val){
                Assign(val);
                return(*this);
             }
             DataCell& DataCell::operator=(float val){
                 Assign(val);
                 return(*this);
              }
             DataCell& DataCell::operator=(int val){
                 Assign(val);
                 return(*this);
              }
             DataCell& DataCell::operator=(bool val){
                 Assign(val);
                 return(*this);
              }
             DataCell& DataCell::operator=(QString val){
                 Assign(val);
                 return(*this);
              }


            //
             // void DataCell::SetType(TypeCell*cellExt){
             //     TypeCell *CellOfType=new TypeCell();
             //     if(cellExt!=NULL)*CellOfType=*cellExt;
             //     SetTypeN(CellOfType->GetTypeN(), CellOfType->GetLength());
             //     delete CellOfType;
             // }

             void DataCell::SetTypeN(int TypeN, /*TableCellAccessConfiguration *cfgExt*/int Length, int PreserveVal)
            {
                int TypeNPrev;//, Len;
                double* DoubleArr = NULL;
                float* FloatArr = NULL;
                int* IntArr = NULL;
                bool* BoolArr = NULL;
                QString* StringArr = NULL;
                TDataCell *BufCell = NULL;
                //TableCellAccessConfiguration *cfg=NULL;
                //if (cfgExt != NULL) cfg = cfgExt; //qu s'abl?
                //else cfg = new TableCellAccessConfiguration();
                if(this->cell!=NULL && this->cell->GetTypeN()!=TypeN){
                    //if (cell!=NULL && cfg->PreserveVal)
                    if (this->cell!=NULL && PreserveVal==1)
                    {
                        //if(cell!=NULL && cell->GetTypeN()!=TypeN){
                            TypeNPrev=cell->GetTypeN();
                            switch (TypeNPrev){
                                case DoubleTypeN:
                                    BufCell = new TCellDouble(cell->GetDoubleVal());
                                break;
                                case FloatTypeN:
                                    BufCell = new TCellFloat(cell->GetFloatVal());
                                break;
                                case IntTypeN:
                                    BufCell = new TCellInt(cell->GetIntVal());
                                break;
                                case BoolTypeN:
                                    BufCell = new TCellBool(cell->GetBoolVal());
                                break;
                                case StringTypeN:
                                    BufCell = new TCellString(cell->ToString());
                                break;
                                case DoubleArrayTypeN:
                                    cell->GetDoubleArr(DoubleArr, Length);
                                    BufCell = new TCellDoubleArr(DoubleArr, Length);
                                break;
                                case FloatArrayTypeN:
                                    cell->GetFloatArr(FloatArr, Length);
                                    BufCell = new TCellFloatArr(FloatArr, Length);
                                break;
                                case IntArrayTypeN:
                                    cell->GetIntArr(IntArr, Length);
                                    BufCell = new TCellIntArr(IntArr, Length);
                                break;
                                case BoolArrayTypeN:
                                    cell->GetBoolArr(BoolArr, Length);
                                    BufCell = new TCellBoolArr(BoolArr, Length);
                                break;
                                case StringArrayTypeN:
                                    cell->ToStringArr(StringArr, Length);
                                    BufCell = new TCellStringArr(StringArr, Length);
                                break;
                            }

                            *BufCell = *cell;
                            delete cell;
                        //}
                    }
                    switch (TypeN)
                    {
                        case DoubleTypeN:
                            //if(!cfg->PreserveVal) cell = new TCellDouble();
                            if(!PreserveVal==1) cell = new TCellDouble();
                            else cell = new TCellDouble(BufCell->GetDoubleVal());
                        break;
                        case FloatTypeN:
                            cell = new TCellFloat();
                            //if (cfg->PreserveVal) cell->SetByValFloat(BufCell->GetFloatVal());
                            if (PreserveVal==1) cell->SetByValFloat(BufCell->GetFloatVal());
                        break;
                        case IntTypeN:
                            cell = new TCellInt();
                            //if (cfg->PreserveVal) cell->SetByValInt(BufCell->GetIntVal());
                            if (PreserveVal==1) cell->SetByValInt(BufCell->GetIntVal());
                        break;
                        case BoolTypeN:
                            cell = new TCellBool();
                            //if (cfg->PreserveVal) cell->SetByValBool(BufCell->GetBoolVal());
                            if (PreserveVal==1) cell->SetByValBool(BufCell->GetBoolVal());
                        break;
                        case StringTypeN:
                            cell = new TCellString();
                            //if (cfg->PreserveVal) cell->SetByValString(BufCell->ToString());
                            if (PreserveVal==1) cell->SetByValString(BufCell->ToString());
                        break;
                        //case UniqueIntValKeeperTypeN:
                        //    cell = new TCellUniqueNumKeeper(cfg->UniqueIntVal);
                        //    if (cfg->PreserveVal) cell->SetByValInt(BufCell->GetIntVal());
                        //break;
                        case DoubleArrayTypeN:
                            //if (cfg->PreserveVal) BufCell->GetDoubleArr(DoubleArr, cfg->LengthOfArrCellTypes);
                            if (PreserveVal=1) BufCell->GetDoubleArr(DoubleArr, Length);
                            //cell = new TCellDoubleArr(DoubleArr, cfg->LengthOfArrCellTypes);
                            cell = new TCellDoubleArr(DoubleArr, Length);
                        break;
                        case FloatArrayTypeN:
                            //if (cfg->PreserveVal) BufCell->GetFloatArr(FloatArr, cfg->LengthOfArrCellTypes);
                            if (PreserveVal==1) BufCell->GetFloatArr(FloatArr, Length);
                            //cell = new TCellFloatArr(FloatArr, cfg->LengthOfArrCellTypes);
                            cell = new TCellFloatArr(FloatArr, Length);
                        break;
                        case IntArrayTypeN:
                            //if (cfg->PreserveVal) BufCell->GetIntArr(IntArr, cfg->LengthOfArrCellTypes);
                            if (PreserveVal==1) BufCell->GetIntArr(IntArr, Length);
                            //cell = new TCellIntArr(IntArr, cfg->LengthOfArrCellTypes);
                            cell = new TCellIntArr(IntArr, Length);
                        break;
                        case BoolArrayTypeN:
                            //if (cfg->PreserveVal) BufCell->GetBoolArr(BoolArr, cfg->LengthOfArrCellTypes);
                            if (PreserveVal==1) BufCell->GetBoolArr(BoolArr, Length);
                            //cell = new TCellBoolArr(BoolArr, cfg->LengthOfArrCellTypes);
                            cell = new TCellBoolArr(BoolArr, Length);
                        break;
                        case StringArrayTypeN:
                            //if (cfg->PreserveVal) BufCell->ToStringArr(StringArr, cfg->LengthOfArrCellTypes);
                            if (PreserveVal==1) BufCell->ToStringArr(StringArr, Length);
                            //cell = new TCellStringArr(BoolArr, cfg->LengthOfArrCellTypes);
                            cell = new TCellStringArr(BoolArr, Length);
                        break;
                    }
                    //if(cfg!=NULL)delete cfg;
                    if(BufCell!=NULL) delete BufCell;
                    //
                    if(DoubleArr != NULL) delete[]DoubleArr;
                    if(FloatArr != NULL) delete[]FloatArr;
                    if(IntArr != NULL) delete[]IntArr;
                    if(BoolArr != NULL) delete[]BoolArr;
                    if(StringArr != NULL) delete[]BoolArr;
                }
            }
            //
             void DataCell::SetValAndTypeDouble(double val)
            {
                if (cell != NULL && cell->GetTypeN() != DoubleTypeN)
                {
                    cell = new TCellDouble(val);
                }
                else
                {
                    cell->SetByValDouble(val);
                }
            }
             void DataCell::SetValAndTypeFloat(float val)
            {
                if (cell != NULL && cell->GetTypeN() != FloatTypeN)
                {
                    cell = new TCellFloat(val);
                }
                else
                {
                    cell->SetByValFloat(val);
                }
            }
             void DataCell::SetValAndTypeInt(int val)
            {
                if (cell != NULL && cell->GetTypeN() != IntTypeN)
                {
                    cell = new TCellInt(val);
                }
                else
                {
                    cell->SetByValInt(val);
                }
            }
             void DataCell::SetValAndTypeBool(bool val)
            {
                if (cell != NULL && cell->GetTypeN() != BoolTypeN)
                {
                    cell = new TCellBool(val);
                }
                else
                {
                    cell->SetByValBool(val);
                }
            }
             void DataCell::SetValAndTypeString(QString val)
            {
                if (cell != NULL && cell->GetTypeN() != StringTypeN)
                {
                    cell = new TCellString(val);
                }
                else
                {
                    cell->SetByValString(val);
                }
            }
             void DataCell::SetArrAndTypeDouble(double* arr, int Length)
            {
                if (cell != NULL && cell->GetTypeN() != DoubleArrayTypeN)
                {
                    cell = new TCellDoubleArr(arr, Length);
                }
                else
                {
                    cell->SetByArrDouble(arr, Length);
                }
            }
             void DataCell::SetArrAndTypeFloat(float* arr, int Length)
            {
                if (cell != NULL && cell->GetTypeN() != FloatArrayTypeN)
                {
                    cell = new TCellFloatArr(arr, Length);
                }
                else
                {
                    cell->SetByArrFloat(arr, Length);
                }
            }
             void DataCell::SetArrAndTypeInt(int* arr, int Length)
            {
                if (cell != NULL && cell->GetTypeN() != IntArrayTypeN)
                {
                    cell = new TCellIntArr(arr, Length);
                }
                else
                {
                    cell->SetByArrInt(arr, Length);
                }
            }
             void DataCell::SetArrAndTypeBool(bool* arr, int Length)
            {
                if (cell != NULL && cell->GetTypeN() != BoolArrayTypeN)
                {
                    cell = new TCellBoolArr(arr, Length);
                }
                else
                {
                    cell->SetByArrBool(arr, Length);
                }
            }
             void DataCell::SetArrAndTypeString(QString* arr, int Length)
            {
                if (cell != NULL && cell->GetTypeN() != StringArrayTypeN)
                {
                    cell = new TCellStringArr(arr, Length);
                }
                else
                {
                    cell->SetByArrString(arr, Length);
                }
            }
            // void DataCell::SetValAndTypeUniqueIntNumKeeper(int val)
           //{
            //    cell = new TCellUniqueNumKeeper(val);
            //}
            //
             void DataCell::SetByValDouble(double val)
            {
                cell->SetByValDouble(val);
            }
             void DataCell::SetByValFloat(float val)
            {
                cell->SetByValFloat(val);
            }
             void DataCell::SetByValInt(int val)
            {
                cell->SetByValInt(val);
            }
             void DataCell::SetByValBool(bool val)
            {
                cell->SetByValBool(val);
            }
             void DataCell::SetByValString(QString val)
            {
                cell->SetByValString(val);
            }
            //
             void DataCell::SetByValDoubleN(double val, int N)
            {
                cell->SetByValDoubleN(val, N);
            }
             void DataCell::SetByValFloatN(float val, int N)
            {
                cell->SetByValFloatN(val, N);
            }
             void DataCell::SetByValIntN(int val, int N)
            {
                cell->SetByValIntN(val, N);
            }
             void DataCell::SetByValBoolN(bool val, int N)
            {
                cell->SetByValBoolN(val, N);
            }
             void DataCell::SetByValStringN(QString val, int N)
            {
                cell->SetByValStringN(val, N);
            }
            //
             void DataCell::SetByArrDouble(double* val, int Length)
            {
                cell->SetByArrDouble(val, Length);
            }
             void DataCell::SetByArrFloat(float* val, int Length)
            {
                cell->SetByArrFloat(val, Length);
            }
             void DataCell::SetByArrInt(int* val, int Length)
            {
                cell->SetByArrInt(val, Length);
            }
             void DataCell::SetByArrBool(bool* val, int Length)
            {
                cell->SetByArrBool(val, Length);
            }
             void DataCell::SetByArrString(QString* val, int Length)
            {
                cell->SetByArrString(val, Length);
            }
            //
             int DataCell::GetErstItemNByStringVal(QString val)
            {
                int N = 0;
                for (int i = GetLength(); i >= 1; i--)
                {
                    if(val==(ToStringN(i))) N=i;
                }
                return N;
            }
             void DataCell::SetActiveNByStringVal(QString val){
                int N = 0;
                for (int i = GetLength(); i >= 1; i--)
                {
                    if(val==(ToStringN(i))) N=i;
                }
                if(N!=0) SetActiveN(N);
            }
            //
             QString DataCell::GetNameN(int N) {
                return cell->GetNameN(N);
            }
             QString DataCell::GetName1()
            {
                return cell->GetName1();
            }
             QString DataCell::GetName2() {
                return cell->GetName2();
            }
            //QString DataCell::GetName3() {
            //    return cell->GetName3();
            //}
            //void DataCell::GetNames(QString*&Arr, int &QItems)
            //{
            //    cell->GetNames(Arr, QItems);
            //}
            //int DataCell::GetLengthOfNamesList()
            //{
            //    return cell->GetLengthOfNamesList();
            //}
            //

             /*

              DataCell DataCell::operator +(DataCell obj1, DataCell obj2){
                DataCell sum = new DataCell();
                double* DoubleArr = NULL;
                float* FloatArr = NULL;
                int* IntArr = NULL;
                bool* BoolArr = NULL;
                QString* StringArr = NULL;
                int Type1N, Type2N, Length1, Length2;
                if (obj1 != NULL)
                {
                    if (obj2 != NULL) //else NOp;
                    {
                        Type1N = obj1.GetTypeN();
                        Type2N = obj2.GetTypeN();
                        switch (Type1N)
                        {
                            case DoubleTypeN:
                                switch (Type2N)
                                {
                                    case DoubleTypeN:
                                        sum = new DataCell(obj1.GetDoubleVal() + obj2.GetDoubleVal());
                                        break;
                                    case FloatTypeN:
                                        //sum = new DataCell(obj1.GetFloatVal() + obj2.GetFloatVal());
                                        sum = new DataCell(obj1.GetDoubleVal() + obj2.GetDoubleVal());
                                        break;
                                    case IntTypeN:
                                        //sum = new DataCell(obj1.GetIntVal() + obj2.GetIntVal());
                                        sum = new DataCell(obj1.GetDoubleVal() + obj2.GetDoubleVal());
                                        break;
                                    case BoolTypeN:
                                        //sum = new DataCell(obj1.GetBoolVal() && obj2.GetBoolVal());
                                        sum = new DataCell(obj1.GetDoubleVal() + obj2.GetDoubleVal());
                                        break;
                                    case StringTypeN:
                                        //sum = new DataCell(obj1.ToString() + obj2.ToString());
                                        sum = new DataCell(obj1.GetDoubleVal() + obj2.GetDoubleVal());
                                        break;
                                    case DoubleArrayTypeN:
                                        Length1 = obj1.GetLength(); //1
                                        Length2 = obj2.GetLength();
                                        DoubleArr = new double[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            DoubleArr[i - 1] = obj1.GetDoubleValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            DoubleArr[i +Length1- 1] = obj2.GetDoubleValN(i);
                                        }
                                        sum = new DataCell(DoubleArr, Length1 + Length2);
                                        break;
                                    case FloatArrayTypeN: //ob double longer r' float: s'nee'd array of > long vars
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        DoubleArr = new double[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            DoubleArr[i - 1] = obj1.GetDoubleValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            DoubleArr[i +Length1- 1] = obj2.GetDoubleValN(i);
                                        }
                                        sum = new DataCell(DoubleArr, Length1 + Length2);
                                        break;
                                    case IntArrayTypeN://ob double longer r' float: s'nee'd array of > long vars
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        DoubleArr = new double[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            DoubleArr[i - 1] = obj1.GetDoubleValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            DoubleArr[i +Length1- 1] = obj2.GetDoubleValN(i);
                                        }
                                        sum = new DataCell(DoubleArr, Length1 + Length2);
                                        break;
                                    case BoolArrayTypeN: //ob double longer r' float: s'nee'd array of > long vars
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        DoubleArr = new double[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            DoubleArr[i - 1] = obj1.GetDoubleValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            DoubleArr[i +Length1- 1] = obj2.GetDoubleValN(i);
                                        }
                                        sum = new DataCell(DoubleArr, Length1 + Length2);
                                        break;
                                    case StringArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        DoubleArr = new double[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            DoubleArr[i - 1] = obj1.GetDoubleValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            DoubleArr[i +Length1- 1] = obj2.GetDoubleValN(i);
                                        }
                                        sum = new DataCell(DoubleArr, Length1 + Length2);
                                        //
                                        //Length1 = obj1.GetLength();
                                        //Length2 = obj2.GetLength();
                                        //StringArr = new string[Length1 + Length2];
                                        //for (int i = 1; i <= Length1; i++){
                                        //    StringArr[i - 1] = obj1.ToStringN(i);
                                        //}
                                        //for (int i = 1; i <= Length2; i++)
                                        //{
                                        //    StringArr[i + Length1 - 1] = obj2.ToStringN(i);
                                        //}
                                        //sum = new DataCell(StringArr, Length1 + Length2);
                                        break;
                                    case UniqueIntValKeeperTypeN:
                                        //NOp;
                                        break;
                                }//switch
                                break;
                            case FloatTypeN:
                                switch (Type2N)
                                {
                                    case DoubleTypeN:
                                        sum = new DataCell(obj1.GetDoubleVal() + obj2.GetDoubleVal());
                                        break;
                                    case FloatTypeN:
                                        //sum = new DataCell(obj1.GetFloatVal() + obj2.GetFloatVal());
                                        sum = new DataCell(obj1.GetFloatVal() + obj2.GetFloatVal());
                                        break;
                                    case IntTypeN:
                                        //sum = new DataCell(obj1.GetIntVal() + obj2.GetIntVal());
                                        sum = new DataCell(obj1.GetFloatVal() + obj2.GetFloatVal());
                                        break;
                                    case BoolTypeN:
                                        //sum = new DataCell(obj1.GetBoolVal() && obj2.GetBoolVal());
                                        sum = new DataCell(obj1.GetFloatVal() + obj2.GetFloatVal());
                                        break;
                                    case StringTypeN:
                                        //sum = new DataCell(obj1.ToString() + obj2.ToString());
                                        sum = new DataCell(obj1.GetFloatVal() + obj2.GetFloatVal());
                                        break;
                                    case DoubleArrayTypeN:
                                        //Length1 = obj1.GetLength();
                                        //Length2 = obj2.GetLength();
                                        //DoubleArr = new double[Length1 + Length2];
                                        //for (int i = 1; i <= Length1; i++){
                                        //    DoubleArr[i - 1] = obj1.GetDoubleValN(i);
                                        //}
                                        //for (int i = 1; i <= Length2; i++)
                                        //{
                                        //    DoubleArr[i +Length1- 1] = obj2.GetDoubleValN(i);
                                        //}
                                        //sum = new DataCell(DoubleArr, Length1 + Length2);
                                        //
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        FloatArr = new float[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            FloatArr[i - 1] = obj1.GetFloatValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            FloatArr[i + Length1 - 1] = obj2.GetFloatValN(i);
                                        }
                                        sum = new DataCell(FloatArr, Length1 + Length2);
                                        break;
                                    case FloatArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        FloatArr = new float[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            FloatArr[i - 1] = obj1.GetFloatValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            FloatArr[i + Length1 - 1] = obj2.GetFloatValN(i);
                                        }
                                        sum = new DataCell(FloatArr, Length1 + Length2);
                                        //CellFrom.GetFloatArr(  FloatArr,   LenFrom);
                                        //CellTo.SetByArrFloat(FloatArr, LenFrom);
                                        break;
                                    case IntArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        FloatArr = new float[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            FloatArr[i - 1] = obj1.GetFloatValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            FloatArr[i + Length1 - 1] = obj2.GetFloatValN(i);
                                        }
                                        sum = new DataCell(FloatArr, Length1 + Length2);
                                        break;
                                    case BoolArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        FloatArr = new float[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            FloatArr[i - 1] = obj1.GetFloatValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            FloatArr[i + Length1 - 1] = obj2.GetFloatValN(i);
                                        }
                                        sum = new DataCell(FloatArr, Length1 + Length2);
                                        break;
                                    case StringArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        FloatArr = new float[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            FloatArr[i - 1] = obj1.GetFloatValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            FloatArr[i + Length1 - 1] = obj2.GetFloatValN(i);
                                        }
                                        sum = new DataCell(FloatArr, Length1 + Length2);
                                        //
                                        //Length1 = obj1.GetLength();
                                        //Length2 = obj2.GetLength();
                                        //StringArr = new string[Length1 + Length2];
                                        //for (int i = 1; i <= Length1; i++){
                                        //    StringArr[i - 1] = obj1.ToStringN(i);
                                        //}
                                        //for (int i = 1; i <= Length2; i++)
                                        //{
                                        //    StringArr[i + Length1 - 1] = obj2.ToStringN(i);
                                        //}
                                        //sum = new DataCell(StringArr, Length1 + Length2);
                                        break;
                                    case UniqueIntValKeeperTypeN:
                                        //NOp;
                                        break;
                                }//switch
                                break;
                            case IntTypeN:
                                switch (Type2N)
                                {
                                    case DoubleTypeN:
                                        sum = new DataCell(obj1.GetDoubleVal() + obj2.GetDoubleVal());
                                        break;
                                    case FloatTypeN:
                                        //sum = new DataCell(obj1.GetFloatVal() + obj2.GetFloatVal());
                                        sum = new DataCell(obj1.GetFloatVal() + obj2.GetFloatVal());
                                        break;
                                    case IntTypeN:
                                        //sum = new DataCell(obj1.GetIntVal() + obj2.GetIntVal());
                                        sum = new DataCell(obj1.GetIntVal() + obj2.GetIntVal());
                                        break;
                                    case BoolTypeN:
                                        //sum = new DataCell(obj1.GetBoolVal() && obj2.GetBoolVal());
                                        sum = new DataCell(obj1.GetIntVal() + obj2.GetIntVal());
                                        break;
                                    case StringTypeN:
                                        //sum = new DataCell(obj1.GetIntVal() + obj2.GetIntVal());
                                        sum = new DataCell(obj1.GetIntVal() + obj2.GetIntVal());
                                        break;
                                    case DoubleArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        DoubleArr = new double[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            DoubleArr[i - 1] = obj1.GetDoubleValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            DoubleArr[i +Length1- 1] = obj2.GetDoubleValN(i);
                                        }
                                        sum = new DataCell(DoubleArr, Length1 + Length2);
                                        break;
                                    case FloatArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        FloatArr = new float[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            FloatArr[i - 1] = obj1.GetFloatValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            FloatArr[i + Length1 - 1] = obj2.GetFloatValN(i);
                                        }
                                        sum = new DataCell(FloatArr, Length1 + Length2);
                                        //CellFrom.GetFloatArr(  FloatArr,   LenFrom);
                                        //CellTo.SetByArrFloat(FloatArr, LenFrom);
                                        break;
                                    case IntArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        IntArr = new int[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            IntArr[i - 1] = obj1.GetIntValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            IntArr[i + Length1 - 1] = obj2.GetIntValN(i);
                                        }
                                        sum = new DataCell(IntArr, Length1 + Length2);
                                        break;
                                    case BoolArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        IntArr = new int[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            IntArr[i - 1] = obj1.GetIntValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            IntArr[i + Length1 - 1] = obj2.GetIntValN(i);
                                        }
                                        sum = new DataCell(IntArr, Length1 + Length2);
                                        break;
                                    case StringArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        IntArr = new int[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            IntArr[i - 1] = obj1.GetIntValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            IntArr[i + Length1 - 1] = obj2.GetIntValN(i);
                                        }
                                        sum = new DataCell(IntArr, Length1 + Length2);
                                        //
                                        //Length1 = obj1.GetLength();
                                        //Length2 = obj2.GetLength();
                                        //StringArr = new string[Length1 + Length2];
                                        //for (int i = 1; i <= Length1; i++){
                                        //    StringArr[i - 1] = obj1.ToStringN(i);
                                        //}
                                        //for (int i = 1; i <= Length2; i++)
                                        //{
                                        //    StringArr[i + Length1 - 1] = obj2.ToStringN(i);
                                        //}
                                        //sum = new DataCell(StringArr, Length1 + Length2);
                                        break;
                                    case UniqueIntValKeeperTypeN:
                                        //NOp;
                                        break;
                                }//switch
                                break;
                            case BoolTypeN:
                                switch (Type2N)
                                {
                                    case DoubleTypeN:
                                        sum = new DataCell(obj1.GetBoolVal() && obj2.GetBoolVal());
                                        break;
                                    case FloatTypeN:
                                        //sum = new DataCell(obj1.GetFloatVal() + obj2.GetFloatVal());
                                        sum = new DataCell(obj1.GetBoolVal() && obj2.GetBoolVal());
                                        break;
                                    case IntTypeN:
                                        //sum = new DataCell(obj1.GetIntVal() + obj2.GetIntVal());
                                        sum = new DataCell(obj1.GetBoolVal() && obj2.GetBoolVal());
                                        break;
                                    case BoolTypeN:
                                        //sum = new DataCell(obj1.GetBoolVal() && obj2.GetBoolVal());
                                        sum = new DataCell(obj1.GetBoolVal() && obj2.GetBoolVal());
                                        break;
                                    case StringTypeN:
                                        //sum = new DataCell(obj1.GetIntVal() + obj2.GetIntVal());
                                        sum = new DataCell(obj1.GetBoolVal() && obj2.GetBoolVal());
                                        break;
                                    case DoubleArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        BoolArr = new bool[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            BoolArr[i - 1] = obj1.GetBoolValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            BoolArr[i + Length1 - 1] = obj2.GetBoolValN(i);
                                        }
                                        sum = new DataCell(BoolArr, Length1 + Length2);
                                        break;
                                    case FloatArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        BoolArr = new bool[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            BoolArr[i - 1] = obj1.GetBoolValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            BoolArr[i + Length1 - 1] = obj2.GetBoolValN(i);
                                        }
                                        sum = new DataCell(FloatArr, Length1 + Length2);
                                        //CellFrom.GetFloatArr(  FloatArr,   LenFrom);
                                        //CellTo.SetByArrFloat(FloatArr, LenFrom);
                                        break;
                                    case IntArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        BoolArr = new bool[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            BoolArr[i - 1] = obj1.GetBoolValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            BoolArr[i + Length1 - 1] = obj2.GetBoolValN(i);
                                        }
                                        sum = new DataCell(FloatArr, Length1 + Length2);
                                        break;
                                    case BoolArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        IntArr = new int[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            IntArr[i - 1] = obj1.GetIntValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            IntArr[i + Length1 - 1] = obj2.GetIntValN(i);
                                        }
                                        sum = new DataCell(IntArr, Length1 + Length2);
                                        break;
                                    case StringArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        IntArr = new int[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            IntArr[i - 1] = obj1.GetIntValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            IntArr[i + Length1 - 1] = obj2.GetIntValN(i);
                                        }
                                        sum = new DataCell(IntArr, Length1 + Length2);
                                        //
                                        //Length1 = obj1.GetLength();
                                        //Length2 = obj2.GetLength();
                                        //StringArr = new string[Length1 + Length2];
                                        //for (int i = 1; i <= Length1; i++){
                                        //    StringArr[i - 1] = obj1.ToStringN(i);
                                        //}
                                        //for (int i = 1; i <= Length2; i++)
                                        //{
                                        //    StringArr[i + Length1 - 1] = obj2.ToStringN(i);
                                        //}
                                        //sum = new DataCell(StringArr, Length1 + Length2);
                                    break;
                                    case UniqueIntValKeeperTypeN:
                                        //NOp;
                                    break;
                                }//switch
                                break;
                            case StringTypeN:
                                switch (Type2N)
                                {
                                    case DoubleTypeN:
                                        sum = new DataCell(obj1.ToString() + obj2.ToString());
                                        break;
                                    case FloatTypeN:
                                        sum = new DataCell(obj1.ToString() + obj2.ToString());
                                        break;
                                    case IntTypeN:
                                        sum = new DataCell(obj1.ToString() + obj2.ToString());
                                        break;
                                    case BoolTypeN:
                                        sum = new DataCell(obj1.ToString() + obj2.ToString());
                                        break;
                                    case StringTypeN:
                                        sum = new DataCell(obj1.ToString() + obj2.ToString());
                                        //CellTo.SetByValBool(CellFrom.GetBoolVal());
                                        break;
                                    case DoubleArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        StringArr = new string[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            StringArr[i - 1] = obj1.ToStringN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            StringArr[i + Length1 - 1] = obj2.ToStringN(i);
                                        }
                                        sum = new DataCell(StringArr, Length1 + Length2);
                                        break;
                                    case FloatArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        StringArr = new string[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            StringArr[i - 1] = obj1.ToStringN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            StringArr[i + Length1 - 1] = obj2.ToStringN(i);
                                        }
                                        sum = new DataCell(StringArr, Length1 + Length2);
                                        break;
                                    case IntArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        StringArr = new string[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            StringArr[i - 1] = obj1.ToStringN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            StringArr[i + Length1 - 1] = obj2.ToStringN(i);
                                        }
                                        sum = new DataCell(StringArr, Length1 + Length2);
                                        break;
                                    case BoolArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        StringArr = new string[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            StringArr[i - 1] = obj1.ToStringN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            StringArr[i + Length1 - 1] = obj2.ToStringN(i);
                                        }
                                        sum = new DataCell(StringArr, Length1 + Length2);
                                        break;
                                    case StringArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        StringArr = new string[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            StringArr[i - 1] = obj1.ToStringN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            StringArr[i + Length1 - 1] = obj2.ToStringN(i);
                                        }
                                        sum = new DataCell(StringArr, Length1 + Length2);
                                        break;
                                    case UniqueIntValKeeperTypeN:
                                        //NOp;
                                        break;
                                }//switch
                                break;
                            case DoubleArrayTypeN:
                                switch (Type2N)
                                {
                                    case DoubleTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        DoubleArr = new double[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            DoubleArr[i - 1] = obj1.GetDoubleValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            DoubleArr[i + Length1 - 1] = obj2.GetDoubleValN(i);
                                        }
                                        sum = new DataCell(StringArr, Length1 + Length2);
                                        break;
                                    case FloatTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        DoubleArr = new double[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            DoubleArr[i - 1] = obj1.GetDoubleValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            DoubleArr[i + Length1 - 1] = obj2.GetDoubleValN(i);
                                        }
                                        sum = new DataCell(StringArr, Length1 + Length2);
                                        break;
                                    case IntTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        DoubleArr = new double[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            DoubleArr[i - 1] = obj1.GetDoubleValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            DoubleArr[i + Length1 - 1] = obj2.GetDoubleValN(i);
                                        }
                                        sum = new DataCell(StringArr, Length1 + Length2);
                                        break;
                                    case BoolTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        DoubleArr = new double[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            DoubleArr[i - 1] = obj1.GetDoubleValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            DoubleArr[i + Length1 - 1] = obj2.GetDoubleValN(i);
                                        }
                                        sum = new DataCell(StringArr, Length1 + Length2);
                                        break;
                                    case StringTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        DoubleArr = new double[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            DoubleArr[i - 1] = obj1.GetDoubleValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            DoubleArr[i + Length1 - 1] = obj2.GetDoubleValN(i);
                                        }
                                        sum = new DataCell(StringArr, Length1 + Length2);
                                        break;
                                    case DoubleArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        DoubleArr = new double[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            DoubleArr[i - 1] = obj1.GetDoubleValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            DoubleArr[i + Length1 - 1] = obj2.GetDoubleValN(i);
                                        }
                                        sum = new DataCell(StringArr, Length1 + Length2);
                                        break;
                                    case FloatArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        DoubleArr = new double[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            DoubleArr[i - 1] = obj1.GetDoubleValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            DoubleArr[i + Length1 - 1] = obj2.GetDoubleValN(i);
                                        }
                                        sum = new DataCell(StringArr, Length1 + Length2);
                                        break;
                                    case IntArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        DoubleArr = new double[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            DoubleArr[i - 1] = obj1.GetDoubleValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            DoubleArr[i + Length1 - 1] = obj2.GetDoubleValN(i);
                                        }
                                        sum = new DataCell(StringArr, Length1 + Length2);
                                        break;
                                    case BoolArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        DoubleArr = new double[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            DoubleArr[i - 1] = obj1.GetDoubleValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            DoubleArr[i + Length1 - 1] = obj2.GetDoubleValN(i);
                                        }
                                        sum = new DataCell(StringArr, Length1 + Length2);
                                        break;
                                    case StringArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        DoubleArr = new double[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            DoubleArr[i - 1] = obj1.GetDoubleValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            DoubleArr[i + Length1 - 1] = obj2.GetDoubleValN(i);
                                        }
                                        sum = new DataCell(StringArr, Length1 + Length2);
                                        break;
                                    case UniqueIntValKeeperTypeN:
                                        //NOp;
                                        break;
                                }//switch
                                break;
                            //mark5
                            case FloatArrayTypeN:
                                switch (Type2N)
                                {
                                    case DoubleTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        DoubleArr = new double[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            DoubleArr[i - 1] = obj1.GetDoubleValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            DoubleArr[i + Length1 - 1] = obj2.GetDoubleValN(i);
                                        }
                                        sum = new DataCell(StringArr, Length1 + Length2);
                                        break;
                                    case FloatTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        FloatArr = new float[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            FloatArr[i - 1] = obj1.GetFloatValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            FloatArr[i + Length1 - 1] = obj2.GetFloatValN(i);
                                        }
                                        sum = new DataCell(FloatArr, Length1 + Length2);
                                        break;
                                    case IntTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        FloatArr = new float[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            FloatArr[i - 1] = obj1.GetFloatValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            FloatArr[i + Length1 - 1] = obj2.GetFloatValN(i);
                                        }
                                        sum = new DataCell(FloatArr, Length1 + Length2);
                                        break;
                                    case BoolTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        FloatArr = new float[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            FloatArr[i - 1] = obj1.GetFloatValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            FloatArr[i + Length1 - 1] = obj2.GetFloatValN(i);
                                        }
                                        sum = new DataCell(FloatArr, Length1 + Length2);
                                        break;
                                    case StringTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        FloatArr = new float[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            FloatArr[i - 1] = obj1.GetFloatValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            FloatArr[i + Length1 - 1] = obj2.GetFloatValN(i);
                                        }
                                        sum = new DataCell(FloatArr, Length1 + Length2);
                                        break;
                                    case DoubleArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        DoubleArr = new double[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            DoubleArr[i - 1] = obj1.GetDoubleValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            DoubleArr[i + Length1 - 1] = obj2.GetDoubleValN(i);
                                        }
                                        sum = new DataCell(StringArr, Length1 + Length2);
                                        break;
                                    case FloatArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        FloatArr = new float[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            FloatArr[i - 1] = obj1.GetFloatValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            FloatArr[i + Length1 - 1] = obj2.GetFloatValN(i);
                                        }
                                        sum = new DataCell(FloatArr, Length1 + Length2);
                                        break;
                                    case IntArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        FloatArr = new float[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            FloatArr[i - 1] = obj1.GetFloatValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            FloatArr[i + Length1 - 1] = obj2.GetFloatValN(i);
                                        }
                                        sum = new DataCell(FloatArr, Length1 + Length2);
                                        break;
                                    case BoolArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        FloatArr = new float[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            FloatArr[i - 1] = obj1.GetFloatValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            FloatArr[i + Length1 - 1] = obj2.GetFloatValN(i);
                                        }
                                        sum = new DataCell(FloatArr, Length1 + Length2);
                                        break;
                                    case StringArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        FloatArr = new float[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            FloatArr[i - 1] = obj1.GetFloatValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            FloatArr[i + Length1 - 1] = obj2.GetFloatValN(i);
                                        }
                                        sum = new DataCell(FloatArr, Length1 + Length2);
                                        break;
                                    case UniqueIntValKeeperTypeN:
                                        //NOp;
                                        break;
                                }//switch
                                break;
                            case IntArrayTypeN:
                                switch (Type2N)
                                {
                                    case DoubleTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        DoubleArr = new double[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            DoubleArr[i - 1] = obj1.GetDoubleValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            DoubleArr[i + Length1 - 1] = obj2.GetDoubleValN(i);
                                        }
                                        sum = new DataCell(DoubleArr, Length1 + Length2);
                                        break;
                                    case FloatTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        FloatArr = new float[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            FloatArr[i - 1] = obj1.GetFloatValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            FloatArr[i + Length1 - 1] = obj2.GetFloatValN(i);
                                        }
                                        sum = new DataCell(FloatArr, Length1 + Length2);
                                        break;
                                    case IntTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        IntArr = new int[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            IntArr[i - 1] = obj1.GetIntValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            IntArr[i + Length1 - 1] = obj2.GetIntValN(i);
                                        }
                                        sum = new DataCell(IntArr, Length1 + Length2);
                                        break;
                                    case BoolTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        IntArr = new int[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            IntArr[i - 1] = obj1.GetIntValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            IntArr[i + Length1 - 1] = obj2.GetIntValN(i);
                                        }
                                        sum = new DataCell(IntArr, Length1 + Length2);
                                        break;
                                    case StringTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        IntArr = new int[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            IntArr[i - 1] = obj1.GetIntValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            IntArr[i + Length1 - 1] = obj2.GetIntValN(i);
                                        }
                                        sum = new DataCell(IntArr, Length1 + Length2);
                                        break;
                                    case DoubleArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        DoubleArr = new double[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            DoubleArr[i - 1] = obj1.GetDoubleValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            DoubleArr[i + Length1 - 1] = obj2.GetDoubleValN(i);
                                        }
                                        sum = new DataCell(DoubleArr, Length1 + Length2);
                                        break;
                                    case FloatArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        FloatArr = new float[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            FloatArr[i - 1] = obj1.GetFloatValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            FloatArr[i + Length1 - 1] = obj2.GetFloatValN(i);
                                        }
                                        sum = new DataCell(FloatArr, Length1 + Length2);
                                        break;
                                    case IntArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        IntArr = new int[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            IntArr[i - 1] = obj1.GetIntValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            IntArr[i + Length1 - 1] = obj2.GetIntValN(i);
                                        }
                                        sum = new DataCell(IntArr, Length1 + Length2);
                                        break;
                                    case BoolArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        IntArr = new int[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            IntArr[i - 1] = obj1.GetIntValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            IntArr[i + Length1 - 1] = obj2.GetIntValN(i);
                                        }
                                        sum = new DataCell(IntArr, Length1 + Length2);
                                        break;
                                    case StringArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        IntArr = new int[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            IntArr[i - 1] = obj1.GetIntValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            IntArr[i + Length1 - 1] = obj2.GetIntValN(i);
                                        }
                                        sum = new DataCell(IntArr, Length1 + Length2);
                                        break;
                                    case UniqueIntValKeeperTypeN:
                                        //NOp;
                                        break;
                                }//switch
                                break;
                            case BoolArrayTypeN:
                                switch (Type2N)
                                {
                                    case DoubleTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        DoubleArr = new double[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            DoubleArr[i - 1] = obj1.GetDoubleValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            DoubleArr[i + Length1 - 1] = obj2.GetDoubleValN(i);
                                        }
                                        sum = new DataCell(DoubleArr, Length1 + Length2);
                                        break;
                                    case FloatTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        FloatArr = new float[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            FloatArr[i - 1] = obj1.GetFloatValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            FloatArr[i + Length1 - 1] = obj2.GetFloatValN(i);
                                        }
                                        sum = new DataCell(FloatArr, Length1 + Length2);
                                        break;
                                    case IntTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        IntArr = new int[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            IntArr[i - 1] = obj1.GetIntValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            IntArr[i + Length1 - 1] = obj2.GetIntValN(i);
                                        }
                                        sum = new DataCell(IntArr, Length1 + Length2);
                                        break;
                                    case BoolTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        BoolArr = new bool[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            BoolArr[i - 1] = obj1.GetBoolValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            BoolArr[i + Length1 - 1] = obj2.GetBoolValN(i);
                                        }
                                        sum = new DataCell(BoolArr, Length1 + Length2);
                                        break;
                                    case StringTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        BoolArr = new bool[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            BoolArr[i - 1] = obj1.GetBoolValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            BoolArr[i + Length1 - 1] = obj2.GetBoolValN(i);
                                        }
                                        sum = new DataCell(BoolArr, Length1 + Length2);
                                        break;
                                    case DoubleArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        BoolArr = new bool[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            BoolArr[i - 1] = obj1.GetBoolValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            BoolArr[i + Length1 - 1] = obj2.GetBoolValN(i);
                                        }
                                        sum = new DataCell(BoolArr, Length1 + Length2);
                                        break;
                                    case FloatArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        BoolArr = new bool[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            BoolArr[i - 1] = obj1.GetBoolValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            BoolArr[i + Length1 - 1] = obj2.GetBoolValN(i);
                                        }
                                        sum = new DataCell(BoolArr, Length1 + Length2);
                                        break;
                                    case IntArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        BoolArr = new bool[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            BoolArr[i - 1] = obj1.GetBoolValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            BoolArr[i + Length1 - 1] = obj2.GetBoolValN(i);
                                        }
                                        sum = new DataCell(BoolArr, Length1 + Length2);
                                        break;
                                    case BoolArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        BoolArr = new bool[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            BoolArr[i - 1] = obj1.GetBoolValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            BoolArr[i + Length1 - 1] = obj2.GetBoolValN(i);
                                        }
                                        sum = new DataCell(BoolArr, Length1 + Length2);
                                        break;
                                    case StringArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        BoolArr = new bool[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            BoolArr[i - 1] = obj1.GetBoolValN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            BoolArr[i + Length1 - 1] = obj2.GetBoolValN(i);
                                        }
                                        sum = new DataCell(BoolArr, Length1 + Length2);
                                        break;
                                    case UniqueIntValKeeperTypeN:
                                        //NOp;
                                        break;
                                }//switch
                                break;
                            case StringArrayTypeN:
                                switch (Type2N)
                                {
                                    case DoubleTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        StringArr = new string[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            StringArr[i - 1] = obj1.ToStringN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            StringArr[i + Length1 - 1] = obj2.ToStringN(i);
                                        }
                                        sum = new DataCell(StringArr, Length1 + Length2);
                                        break;
                                    case FloatTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        StringArr = new string[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            StringArr[i - 1] = obj1.ToStringN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            StringArr[i + Length1 - 1] = obj2.ToStringN(i);
                                        }
                                        sum = new DataCell(StringArr, Length1 + Length2);
                                        break;
                                    case IntTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        StringArr = new string[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            StringArr[i - 1] = obj1.ToStringN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            StringArr[i + Length1 - 1] = obj2.ToStringN(i);
                                        }
                                        sum = new DataCell(StringArr, Length1 + Length2);
                                        break;
                                    case BoolTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        StringArr = new string[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            StringArr[i - 1] = obj1.ToStringN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            StringArr[i + Length1 - 1] = obj2.ToStringN(i);
                                        }
                                        sum = new DataCell(StringArr, Length1 + Length2);
                                        break;
                                    case StringTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        StringArr = new string[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            StringArr[i - 1] = obj1.ToStringN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            StringArr[i + Length1 - 1] = obj2.ToStringN(i);
                                        }
                                        sum = new DataCell(StringArr, Length1 + Length2);
                                        break;
                                    case DoubleArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        StringArr = new string[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            StringArr[i - 1] = obj1.ToStringN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            StringArr[i + Length1 - 1] = obj2.ToStringN(i);
                                        }
                                        sum = new DataCell(StringArr, Length1 + Length2);
                                        break;
                                    case FloatArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        StringArr = new string[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            StringArr[i - 1] = obj1.ToStringN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            StringArr[i + Length1 - 1] = obj2.ToStringN(i);
                                        }
                                        sum = new DataCell(StringArr, Length1 + Length2);
                                        break;
                                    case IntArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        StringArr = new string[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            StringArr[i - 1] = obj1.ToStringN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            StringArr[i + Length1 - 1] = obj2.ToStringN(i);
                                        }
                                        sum = new DataCell(StringArr, Length1 + Length2);
                                        break;
                                    case BoolArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        StringArr = new string[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            StringArr[i - 1] = obj1.ToStringN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            StringArr[i + Length1 - 1] = obj2.ToStringN(i);
                                        }
                                        sum = new DataCell(StringArr, Length1 + Length2);
                                        break;
                                    case StringArrayTypeN:
                                        Length1 = obj1.GetLength();
                                        Length2 = obj2.GetLength();
                                        StringArr = new string[Length1 + Length2];
                                        for (int i = 1; i <= Length1; i++){
                                            StringArr[i - 1] = obj1.ToStringN(i);
                                        }
                                        for (int i = 1; i <= Length2; i++)
                                        {
                                            StringArr[i + Length1 - 1] = obj2.ToStringN(i);
                                        }
                                        sum = new DataCell(StringArr, Length1 + Length2);
                                        break;
                                    case UniqueIntValKeeperTypeN:
                                        //NOp;
                                        break;
                                }//switch
                                break;
                            case UniqueIntValKeeperTypeN:
                                switch (Type2N)
                                {
                                    case DoubleTypeN:
                                        //CellTo.SetByValInt(CellFrom.GetIntVal());
                                        break;
                                    case FloatTypeN:
                                        //CellTo.SetByValInt(CellFrom.GetIntVal());
                                        break;
                                    case IntTypeN:
                                        //CellTo.SetByValInt(CellFrom.GetIntVal());
                                        break;
                                    case BoolTypeN:
                                        //CellTo.SetByValInt(CellFrom.GetIntVal());
                                        break;
                                    case StringTypeN:
                                        //CellTo.SetByValInt(CellFrom.GetIntVal());
                                        break;
                                    case DoubleArrayTypeN:
                                        //CellTo.SetByValInt(CellFrom.GetIntVal());
                                        break;
                                    case FloatArrayTypeN:
                                        //CellTo.SetByValInt(CellFrom.GetIntVal());
                                        break;
                                    case IntArrayTypeN:
                                        //CellTo.SetByValInt(CellFrom.GetIntVal());
                                        break;
                                    case BoolArrayTypeN:
                                        //CellTo.SetByValInt(CellFrom.GetIntVal());
                                        break;
                                    case StringArrayTypeN:
                                        //CellTo.SetByValInt(CellFrom.GetIntVal());
                                        break;
                                    case UniqueIntValKeeperTypeN:
                                        //CellTo.SetByValInt(CellFrom.GetIntVal());
                                        break;
                                }//switch
                                break;
                        }//switch
                    }
                    else sum.Assign(obj1);
                }
                else sum.Assign(obj2);
                return sum;
            }//operator +

            */

            //
            /* void SetNameN(string name, int N) { this->cell.SetNameN(name, N); }
             void SetName1(string name) { this->cell.SetName1(name); }
             void SetName2(string name) { this->cell.SetName2(name); }
             void SetName3(string name) { this->cell.SetName3(name); }
             void SetNames(string[] Arr, int Q){this->cell.SetNames(Arr, Q);}
             string GetNameN(int N) { return this->cell.GetNameN(N); }
             string GetName1() { return this->cell.GetName1(); }
             string GetName2() { return this->cell.GetName2(); }
             string GetName3() { return this->cell.GetName3(); }
             void GetNames(  string[] Arr,   int QItems){this->cell.GetNames(  Arr,   QItems);}
             int GetLengthOfNamesList() { return this->cell.GetLengthOfNamesList();}*/
            //
            DataCell DataCell::ReturnCopy()
             {
                 TDataCell* cell=NULL;
                 DataCell RCell;
                 int TypeN = this->GetTypeN(), QItems=this->GetLength(),
                 //QNames=this->GetLengthOfNamesList(),
                 ActiveN=this->GetActiveN();
                 double* ItemsDbl=NULL;
                 float* ItemsFlt=NULL;
                 int* ItemsInt=NULL;
                 bool* ItemsBool=NULL;
                 QString* ItemsStr=NULL;
                 QString* Names=NULL;
                 //
                 std::vector<QString>items;
                 //;
                 TDBTableContent*DBTableContent;
                 TDBTableHeader*TDBTableHeader;
                 TDBFieldContent*DBFieldContent;
                 TDBFieldConnectedTable*DBFieldConnectedTable;
                 TDBFieldHeader*DBFieldHeader;
                 //
                 switch (TypeN)
                 {
                     case DoubleTypeN:
                         cell=new TCellDouble(this->GetDoubleVal());
                         break;
                     case FloatTypeN:
                         cell=new TCellFloat(this->GetFloatVal());
                         break;
                     case IntTypeN:
                         cell=new TCellInt(this->GetIntVal());
                         break;
                     case BoolTypeN:
                          cell=new TCellBool(this->GetBoolVal());
                          break;
                     case StringTypeN:
                          cell=new TCellString(this->ToString());
                          break;
                     case DoubleArrayTypeN:
                          this->GetDoubleArr(  ItemsDbl,   QItems);
                          cell=new TCellDoubleArr(ItemsDbl, QItems);
                          break;
                     case FloatArrayTypeN:
                          this->GetFloatArr(  ItemsFlt,   QItems);
                          cell=new TCellFloatArr(ItemsFlt, QItems);
                          break;
                     case IntArrayTypeN:
                         this->GetIntArr(  ItemsInt,   QItems);
                         cell=new TCellIntArr(ItemsInt, QItems);
                         break;
                     case BoolArrayTypeN:
                         this->GetBoolArr(  ItemsBool,   QItems);
                         cell=new TCellBoolArr(ItemsBool, QItems);
                         break;
                     case StringArrayTypeN:
                         this->ToStringArr(  ItemsStr,   QItems);
                         cell=new TCellStringArr(ItemsStr, QItems);
                          break;
                     //case TableConsts.UniqueIntValKeeperTypeN:
                     //     this->GetIntArr(  ItemsInt,   QItems);
                     //     cell=new DataCell(ItemsInt, QItems);
                     //     break;
                     case DoubleItemsDBFieldHeaderCellTypeN:
                         this->GetDoubleArr(  ItemsDbl,   QItems);
                         this->GetNames(  Names,   QNames);
                         cell=new TDBCOlHeader_Items_Double(ItemsDbl, QItems);
                         break;
                     case IntItemsDBFieldHeaderCellTypeN:
                         this->GetIntArr(  ItemsInt,   QItems);
                         this->GetNames(  Names,   QNames);
                         cell = new TDBCOlHeader_Items_Int(ItemsInt, QItems);
                         break;
                     case StringItemsDBFieldHeaderCellTypeN:
                         this->ToStringArr(  ItemsStr,   QItems);
                         this->GetNames(  Names,   QNames);
                         cell = new TDBCOlHeader_Items_String(ItemsStr, QItems);
                         break;
                  }//switch
                 if (TypeNIsCorrectArrayTypeN(TypeN)) cell->SetActiveN(ActiveN);
                 RCell.AssignBy(cell);
                 return RCell;//*cell;
             }
//



    // class DataCell:ICloneable       //redefinition
    //        {
    //            TDataCell cell;
    //             DataCell() {
    //                cell = NULL;
    //                SetDefault0();
    //            }
            //
    //DataCell::DataCell() {
    //    cell = NULL;
    //    SetDefault0();
   // }


