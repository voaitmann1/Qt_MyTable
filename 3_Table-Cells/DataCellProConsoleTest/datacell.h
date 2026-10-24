#ifndef DATACELL_H
#define DATACELL_H

#include"mylib.h"
#include"numberparse.h"
#include "typeinfo.h"
#include "tableinfo.h"
#include "mystringlib.h"
#include "array2dlib.h"


class TDBTableContent{
public:
    QString DBNameInSys;
    QString DBSysName;
    int DBSysN;
    QString FileFullName;
    //
    TDBTableContent();
    //
    QString ToString(QString delim="; ", bool names=false);
    void SetByValString(QString data, QString delim="; ", bool names=false);
    void ToStringArr(QString*&Arr,  int&QItems);
    void SetByArrString(QString*arr, int Q=4, int FromN=1);
    //
    void SetDBNaAmeInSys(QString DBNameInSys);
    QString GetDBNAmeInSys();
    void SetDBSysName(QString DBSysName);
    QString GetGetDBSysName();
    void SetDBSysN(int DBSysN);
    int GetDBSysN();
    void SetFileFullName(QString FileFullName);
    QString GetFileFullName();
};
class   TDBTableHeader{
public:
    QString TableNameInDB;
    TDBTableContent*DBTableContent;
    //
    TDBTableHeader(QString TableNameInDB="", TDBTableContent*DBTableContent=NULL);
    TDBTableHeader(const TDBTableHeader&obj);
    ~TDBTableHeader();
    //
    void Assign(const TDBTableHeader&obj);
    TDBTableHeader& operator =(const TDBTableHeader&obj);
    //
    QString ToString(QString delim="; ", bool names=false);
    void SetByValString(QString data, QString delim="; ", bool names=false);
    void ToStringArr(QString*&Arr,  int&QItems);
    void SetByArrString(QString*arr, int Q=5, int FromN=1);
    //
    void SetDBNaAmeInSys(QString DBNameInSys);
    QString GetDBNAmeInSys();
    void SetDBSysName(QString DBSysName);
    QString GetGetDBSysName();
    void SetDBSysN(int DBSysN);
    int GetDBSysN();
    void SetFileFullName(QString FileFullName);
    QString GetFileFullName();
    //void SetTableNameInDB(QString TableNameInDB);
    //QString GetTableNameInDB();
    //
    QString GetTableNameInDB();
    void SetTableNameInDB(QString TableNameInDB);
    TDBTableContent*GetDBTableContent();
    void SetDBTableContent(TDBTableContent*DBTableContent);
};
class TDBFieldContent{
public:
    QString TypeName;
    int TypeN;
    int Length;
    int CharNum;//DBFieldCharacteristicsNumber
    bool isAutoIncrement, isKeyField, isNotNull, isCounter;
    //
    TDBFieldContent();
    //
    QString ToString(QString delim="; ", bool names=false);
    void SetByValString(QString data, QString delim="; ", bool names=false);
    void ToStringArr(QString*&Arr,  int&QItems);
    void SetByArrString(QString*arr, int Q=5, int FromN=1);
    //
    QString GetTypeName();
    void SetTypeName(QString TypeName);
    int GetTypeN();
    void SetTypeN(int TypeN);
    int GetLength();
    void SetLength(int length);
    int GetCharNum();
    void SetCharNum(int CharNum);
    bool GetIfIsAutoIncrement();
    void SetIfIsAutoIncrement(bool val);
    bool GetIfIsNotNull();
    void SetIfIsNotNull(bool val);
    bool GetIfIsKeyField();
    void SetIfIsKeyField(bool val);
    bool GetIfIsCounter();
    void SetIfIsCounter(bool val);
};
class TDBFieldConnectedTable{
public:
    QString DBTableName, ContentFieldName, KeyFieldName;
    //
    TDBFieldConnectedTable(QString DBTableName="", QString ContentFieldName="", QString KeyFieldName="");
    //
    QString ToString(QString delim="; ", bool names=false);
    void SetByValString(QString data, QString delim="; ", bool names=false);
    void ToStringArr(QString*&Arr,  int&QItems);
    void SetByArrString(QString*arr, int Q=5, int FromN=1);
};
class TDBFieldHeader{
public:
    QString FieldlNameInDBTable;
    TDBFieldContent*DBFieldContent;
    TDBFieldConnectedTable*DBFieldConnectedTable;
    //
    TDBFieldHeader(QString FieldlNameInDBTable="", TDBFieldContent*DBColContent=NULL);
    TDBFieldHeader(const TDBFieldHeader&obj);
    //
    void Assign(const TDBFieldHeader&obj);
    TDBFieldHeader operator =(const TDBFieldHeader&obj);
    //
    QString ToString(QString delim="; ", bool names=false);
    void SetByValString(QString data, QString delim="; ", bool names=false);
    void ToStringArr(QString*&Arr,  int&QItems);
    void SetByArrString(QString*arr, int Q=5, int FromN=1);
    //
    QString GetTypeName();
    void SetTypeName(QString TypeName);
    int GetTypeN();
    void SetTypeN(int TypeN);
    int GetLength();
    void SetLength(int length);
    int GetCharNum();
    void SetCharNum(int CharNum);
    bool GetIfIsAutoIncrement();
    void SetIfIsAutoIncrement(bool val);
    bool GetIfIsNotNull();
    void SetIfIsNotNull(bool val);
    bool GetIfIsKeyField();
    void SetIfIsKeyField(bool val);
    bool GetIfIsCounter();
    void SetIfIsCounter(bool val);
    //QString GetFieldlNameInDBTable();
    //void SetFieldlNameInDBTable(QString FieldlNameInDBTable);
    //
    QString GetFieldlNameInDBTable();
    TDBFieldContent*GetDBFieldContent();
    TDBFieldConnectedTable*GetDBFieldConnectedTable();
    void SetFieldlNameInDBTable(QString FieldlNameInDBTable);
    void SetDBFieldContent(TDBFieldContent*DBFieldContent);
    void SetDBFieldConnectedTable(TDBFieldConnectedTable*DBFieldConnectedTable);
};



class TDataCell{
    //
    public:
    //
    virtual void construct(int n=1)=0;
    //virtual ~TDataCell();//=0;
    //
            virtual int GetTypeN()=0;
            virtual int GetActiveN()=0;
            virtual void SetActiveN(int N)=0;
            virtual int GetLength() =0;
            virtual void SetLength(int L) =0;
            //
            virtual double GetDoubleVal() =0;
            virtual float GetFloatVal() =0;
            virtual int GetIntVal() =0;
            virtual bool GetBoolVal() =0;
            virtual  QString ToString() =0;
            //
            virtual double GetDoubleValN(int N) =0;
            virtual float GetFloatValN(int N) =0;
            virtual int GetIntValN(int N) =0;
            virtual bool GetBoolValN(int N) =0;
            virtual QString ToStringN(int N) =0;
            //
            //virtual QStringGetNameN(int N) =0;//for db1
            //
            virtual void SetByValDouble(double val) =0;
            virtual void SetByValFloat(float val) =0;
            virtual void SetByValInt(int val) =0;
            virtual void SetByValBool(bool val) =0;
            virtual void SetByValString(QString val) =0;
            //
            //virtual   void SetByValStringName(string val) =0;//for db2
            //
            virtual void SetByValDoubleN(double val, int N) =0;
            virtual void SetByValFloatN(float val, int N) =0;
            virtual void SetByValIntN(int val, int N) =0;
            virtual void SetByValBoolN(bool val, int N) =0;
            virtual void SetByValStringN(QString val, int N) =0;
            //
            //virtual   void SetByValStringNameN(string val, int N) =0;//for db3
            //
            virtual void SetVal(double val) =0;
            virtual void SetVal(int val) =0;
            virtual void SetVal(bool val) =0;
            virtual void SetVal(QString val) =0;
            //
            //virtual   void SetValToName(string val) =0;//for db4
            //
            virtual   void SetValN(double val, int N) =0;
            virtual   void SetValN(int val, int N) =0;
            virtual   void SetValN(bool val, int N) =0;
            virtual   void SetValN(QString val, int N) =0;
            //
            //virtual   void SetValToNameN(string val, int N) =0;//for db5
            //
            virtual   void SetByArrDouble(double* val, int Q) =0;
            virtual   void SetByArrFloat(float* val, int Q) =0;
            virtual   void SetByArrInt(int* val, int Q) =0;
            virtual   void SetByArrBool(bool* val, int Q) =0;
            virtual   void SetByArrString(QString* val, int Q) =0;
            //
            //virtual   void SetByArrStringToNames(string[] val, int Q) =0;//for db6
            //
            virtual   void SetByArr(double* val, int Q) =0;
            virtual   void SetByArr(int* val, int Q) =0;
            virtual   void SetByArr(bool* val, int Q) =0;
            virtual   void SetByArr(QString* val, int Q) =0;
            //
            //virtual   void SetByArrToNames(QString* val, int Q) =0;//for db6
            //
            virtual   void AddOrInsDoubleVal(double val, int N) =0;
            virtual   void AddOrInsFloatVal(float val, int N) =0;
            virtual   void AddOrInsIntVal(int val, int N) =0;
            virtual   void AddOrInsBoolVal(bool val, int N) =0;
            virtual   void AddOrInsStringVal(QString val, int N) =0;
            //
            //virtual   void AddOrInsStringValToNames(string* val, int Q) =0;//for db7
            //
            //
            virtual void GetDoubleArr( double*&Arr,  int&QItems) =0;
            virtual void GetFloatArr( float*&Arr,  int&QItems) =0;
            virtual void GetIntArr( int*&Arr,  int&QItems) =0;
            virtual void GetBoolArr( bool*&Arr,  int&QItems) =0;
            virtual void ToStringArr( QString*&Arr,  int&QItems) =0;
            //
            //
            virtual void DelValN(int N) =0;
            //
            //
            virtual void SetNameN(QString name, int N) =0;
            virtual void SetName1(QString name) =0;
            virtual void SetName2(QString name) =0;
            //virtual void SetName3(QString name) =0;
            //virtual void SetNames(QString* Arr, int Q) =0;
            virtual QString GetNameN(int N) =0;
            virtual QString GetName1() =0;
            virtual QString GetName2() =0;
            //virtual QString GetName3() =0;
            //virtual void GetNames(QString*&Arr,  int&QItems) =0;
            //virtual int GetLengthOfNamesList() =0;
            //
            virtual void SetItems(QString*items, int Q, int ActiveN=1);
            virtual void GetItems(QString*&items, int&Q);
            virtual void SetItem(QString item, int itemN=-1);
            virtual void InsItem(QString item, int itemN=-1);
            virtual void AddItem(QString item);
            virtual void DelItem(int itemN=-1);
            virtual QString GetItem(int itemN=-1);
            virtual int GetLengthOfItemsList();
            //
            //virtual InsDoubleValN(double val, int N) =0;
            //virtual InsFloatValN(float val, int N) =0;
            //virtual InsIntValN(int val, int N) =0;
            //virtual InsBoolValN(bool val, int N) =0;
            //virtual InsStringValN(string val, int N) =0;
            //
            //virtual AddDoubleValN(double val, int N) =0;
            //virtual AddFloatValN(float val, int N) =0;
            //virtual AddIntValN(int val, int N) =0;
            //virtual AddBoolValN(bool val, int N) =0;
            //virtual AddStringValN(string val, int N) =0;
            //
            //virtual  object Clone() =0;
};

    class TCellDouble:public TDataCell
    {
        double val;
        //
        public:
        TCellDouble();
        TCellDouble(double val);
        TCellDouble(float val);
        TCellDouble(int val);
        TCellDouble(bool val);
        TCellDouble(QString val);
        //
        TCellDouble(double* val, int Q) ;
        TCellDouble(float* val, int Q);
        TCellDouble(int* val, int Q);
        TCellDouble(bool* val, int Q);
        TCellDouble(QString* val, int Q);
        //
        //        TCellDouble(TCellDouble&obj);
        //        //
        //        TCellDouble& operator =(TCellDouble&obj);
        //        //
        //        void Assign(TCellDouble&obj);
        //
        virtual void construct(int n=1);
        //
        virtual int GetTypeN();
        virtual int GetActiveN();
        virtual void SetActiveN(int N);
        virtual int GetLength();
        virtual void SetLength(int L);
        //
        virtual double GetDoubleVal();
        virtual float GetFloatVal();
        virtual int GetIntVal();
        virtual bool GetBoolVal();
        virtual QString ToString();
        //
        virtual double GetDoubleValN(int N);
        virtual float GetFloatValN(int N);
        virtual int GetIntValN(int N);
        virtual bool GetBoolValN(int N);
        virtual QString ToStringN(int N);
        //
        virtual void SetByValDouble(double val);
        virtual void SetByValFloat(float val);
        virtual void SetByValInt(int val);
        virtual void SetByValBool(bool val);
        virtual void SetByValString(QString val);
        //
        virtual void SetByValDoubleN(double val, int N);
        virtual void SetByValFloatN(float val, int N);
        virtual void SetByValIntN(int val, int N);
        virtual void SetByValBoolN(bool val, int N);
        virtual void SetByValStringN(QString val, int N);
        //
        virtual void SetVal(double val);
        virtual void SetVal(int val);
        virtual void SetVal(bool val);
        virtual void SetVal(QString val);
        //
        virtual void SetValN(double val, int N);
        virtual void SetValN(int val, int N);
        virtual void SetValN(bool val, int N);
        virtual void SetValN(QString val, int N);
        //
        virtual void SetByArrDouble(double* val, int Q);
        virtual void SetByArrFloat(float*val, int Q);
        virtual void SetByArrInt(int* val, int Q);
        virtual void SetByArrBool(bool* val, int Q);
        virtual void SetByArrString(QString*val, int Q);
        //
        virtual void SetByArr(double* val, int Q);
        virtual void SetByArr(int* val, int Q);
        virtual void SetByArr(bool* val, int Q);
        virtual void SetByArr(QString* val, int Q);
        //
        virtual void AddOrInsDoubleVal(double val, int N);
        virtual void AddOrInsFloatVal(float val, int N);
        virtual void AddOrInsIntVal(int val, int N);
        virtual void AddOrInsBoolVal(bool val, int N);
        virtual void AddOrInsStringVal(QString val, int N);
        //
        virtual void DelValN(int N);
        //
        virtual void GetDoubleArr(double*&Arr,  int&QItems);
        virtual void GetFloatArr(float*&Arr, int&QItems);
        virtual void GetIntArr(int*&Arr, int&QItems);
        virtual void GetBoolArr(bool*&Arr, int&QItems);
        virtual void ToStringArr(QString*&Arr, int&QItems);
        //
        virtual void SetNameN(QString name, int N);
        virtual void SetName1(QString name);
        virtual void SetName2(QString name);
        //virtual void SetName3(QString name);
        //virtual void SetNames(QString* Arr, int Q);
        virtual QString GetNameN(int N);
        virtual QString GetName();//!
        virtual QString GetName1();
        virtual QString GetName2();
        //virtual QString GetName3();
        //virtual void GetNames(QString*&Arr, int&QItems);
        //virtual int GetLengthOfNamesList();
        //
        //
        virtual void SetItems(QString*items, int Q, int ActiveN=1);
        virtual void GetItems(QString*&items, int&Q);
        virtual void SetItem(QString item, int itemN=-1);
        virtual void InsItem(QString item, int itemN=-1);
        virtual void AddItem(QString item);
        virtual void DelItem(int itemN=-1);
        virtual QString GetItem(int itemN=-1);
        virtual int GetLengthOfItemsList();
        //
    };//cl TCellDouble

    class TCellFloat:public TDataCell
    {
        float val;
        //
        public:
        TCellFloat();
        TCellFloat(double val);
        TCellFloat(float val);
        TCellFloat(int val);
        TCellFloat(bool val);
        TCellFloat(QString val);
        //
        TCellFloat(double* val, int Q) ;
        TCellFloat(float* val, int Q);
        TCellFloat(int* val, int Q);
        TCellFloat(bool* val, int Q);
        TCellFloat(QString* val, int Q);
        //
//        TCellFloat(TCellFloat&obj);
//        //
//        TCellFloat& operator =(TCellFloat&obj);
//        //
//        void Assign(TCellFloat&obj);

        //
        virtual void construct(int n=1);
        //
        virtual int GetTypeN();
        virtual int GetActiveN();
        virtual void SetActiveN(int N);
        virtual int GetLength();
        virtual void SetLength(int L);
        //
        virtual double GetDoubleVal();
        virtual float GetFloatVal();
        virtual int GetIntVal();
        virtual bool GetBoolVal();
        virtual QString ToString();
        //
        virtual double GetDoubleValN(int N);
        virtual float GetFloatValN(int N);
        virtual int GetIntValN(int N);
        virtual bool GetBoolValN(int N);
        virtual QString ToStringN(int N);
        //
        virtual void SetByValDouble(double val);
        virtual void SetByValFloat(float val);
        virtual void SetByValInt(int val);
        virtual void SetByValBool(bool val);
        virtual void SetByValString(QString val);
        //
        virtual void SetByValDoubleN(double val, int N);
        virtual void SetByValFloatN(float val, int N);
        virtual void SetByValIntN(int val, int N);
        virtual void SetByValBoolN(bool val, int N);
        virtual void SetByValStringN(QString val, int N);
        //
        virtual void SetVal(double val);
        virtual void SetVal(int val);
        virtual void SetVal(bool val);
        virtual void SetVal(QString val);
        //
        virtual void SetValN(double val, int N);
        virtual void SetValN(int val, int N);
        virtual void SetValN(bool val, int N);
        virtual void SetValN(QString val, int N);
        //
        virtual void SetByArrDouble(double* val, int Q);
        virtual void SetByArrFloat(float*val, int Q);
        virtual void SetByArrInt(int* val, int Q);
        virtual void SetByArrBool(bool* val, int Q);
        virtual void SetByArrString(QString*val, int Q);
        //
        virtual void SetByArr(double* val, int Q);
        virtual void SetByArr(int* val, int Q);
        virtual void SetByArr(bool* val, int Q);
        virtual void SetByArr(QString* val, int Q);
        //
        virtual void AddOrInsDoubleVal(double val, int N);
        virtual void AddOrInsFloatVal(float val, int N);
        virtual void AddOrInsIntVal(int val, int N);
        virtual void AddOrInsBoolVal(bool val, int N);
        virtual void AddOrInsStringVal(QString val, int N);
        //
        virtual void DelValN(int N);
        //
        virtual void GetDoubleArr(double*&Arr,  int&QItems);
        virtual void GetFloatArr(float*&Arr, int&QItems);
        virtual void GetIntArr(int*&Arr, int&QItems);
        virtual void GetBoolArr(bool*&Arr, int&QItems);
        virtual void ToStringArr(QString*&Arr, int&QItems);
        //
        virtual void SetNameN(QString name, int N);
        virtual void SetName1(QString name);
        virtual void SetName2(QString name);
        //virtual void SetName3(QString name);
        //virtual void SetNames(QString* Arr, int Q);
        virtual QString GetNameN(int N);
        virtual QString GetName1();
        virtual QString GetName2();
        //virtual QString GetName3();
        //virtual void GetNames(QString*&Arr, int&QItems);
        //virtual int GetLengthOfNamesList();
        //
        //
        virtual void SetItems(QString*items, int Q, int ActiveN=1);
        virtual void GetItems(QString*&items, int&Q);
        virtual void SetItem(QString item, int itemN=-1);
        virtual void InsItem(QString item, int itemN=-1);
        virtual void AddItem(QString item);
        virtual void DelItem(int itemN=-1);
        virtual QString GetItem(int itemN=-1);
        virtual int GetLengthOfItemsList();
    };//cl TCellFloat


    class TCellInt:public TDataCell
    {
        int val;
        //
        public:
        TCellInt();
        TCellInt(double val);
        TCellInt(float val);
        TCellInt(int val);
        TCellInt(bool val);
        TCellInt(QString val);
        //
        TCellInt(double* val, int Q) ;
        TCellInt(float* val, int Q);
        TCellInt(int* val, int Q);
        TCellInt(bool* val, int Q);
        TCellInt(QString* val, int Q);
        //
//        TCellInt(TCellInt&obj);
//        //
//        TCellInt& operator =(TCellInt&obj);
//        //
//        void Assign(TCellInt&obj);

        //
        virtual void construct(int n=1);
        //
        virtual int GetTypeN();
        virtual int GetActiveN();
        virtual void SetActiveN(int N);
        virtual int GetLength();
        virtual void SetLength(int L);
        //
        virtual double GetDoubleVal();
        virtual float GetFloatVal();
        virtual int GetIntVal();
        virtual bool GetBoolVal();
        virtual QString ToString();
        //
        virtual double GetDoubleValN(int N);
        virtual float GetFloatValN(int N);
        virtual int GetIntValN(int N);
        virtual bool GetBoolValN(int N);
        virtual QString ToStringN(int N);
        //
        virtual void SetByValDouble(double val);
        virtual void SetByValFloat(float val);
        virtual void SetByValInt(int val);
        virtual void SetByValBool(bool val);
        virtual void SetByValString(QString val);
        //
        virtual void SetByValDoubleN(double val, int N);
        virtual void SetByValFloatN(float val, int N);
        virtual void SetByValIntN(int val, int N);
        virtual void SetByValBoolN(bool val, int N);
        virtual void SetByValStringN(QString val, int N);
        //
        virtual void SetVal(double val);
        virtual void SetVal(int val);
        virtual void SetVal(bool val);
        virtual void SetVal(QString val);
        //
        virtual void SetValN(double val, int N);
        virtual void SetValN(int val, int N);
        virtual void SetValN(bool val, int N);
        virtual void SetValN(QString val, int N);
        //
        virtual void SetByArrDouble(double* val, int Q);
        virtual void SetByArrFloat(float*val, int Q);
        virtual void SetByArrInt(int* val, int Q);
        virtual void SetByArrBool(bool* val, int Q);
        virtual void SetByArrString(QString*val, int Q);
        //
        virtual void SetByArr(double* val, int Q);
        virtual void SetByArr(int* val, int Q);
        virtual void SetByArr(bool* val, int Q);
        virtual void SetByArr(QString* val, int Q);
        //
        virtual void AddOrInsDoubleVal(double val, int N);
        virtual void AddOrInsFloatVal(float val, int N);
        virtual void AddOrInsIntVal(int val, int N);
        virtual void AddOrInsBoolVal(bool val, int N);
        virtual void AddOrInsStringVal(QString val, int N);
        //
        virtual void DelValN(int N);
        //
        virtual void GetDoubleArr(double*&Arr,  int&QItems);
        virtual void GetFloatArr(float*&Arr, int&QItems);
        virtual void GetIntArr(int*&Arr, int&QItems);
        virtual void GetBoolArr(bool*&Arr, int&QItems);
        virtual void ToStringArr(QString*&Arr, int&QItems);
        //
        virtual void SetNameN(QString name, int N);
        virtual void SetName1(QString name);
        virtual void SetName2(QString name);
        //virtual void SetName3(QString name);
        //virtual void SetNames(QString* Arr, int Q);
        virtual QString GetNameN(int N);
        virtual QString GetName1();
        virtual QString GetName2();
        //virtual QString GetName3();
        //virtual void GetNames(QString*&Arr, int&QItems);
        //virtual int GetLengthOfNamesList();
        //
        //
        virtual void SetItems(QString*items, int Q, int ActiveN=1);
        virtual void GetItems(QString*&items, int&Q);
        virtual void SetItem(QString item, int itemN=-1);
        virtual void InsItem(QString item, int itemN=-1);
        virtual void AddItem(QString item);
        virtual void DelItem(int itemN=-1);
        virtual QString GetItem(int itemN=-1);
        virtual int GetLengthOfItemsList();
    };//cl TCellInt

    class TCellBool:public TDataCell
    {
        bool val;
        //
        public:
        TCellBool();
        TCellBool(double val);
        TCellBool(float val);
        TCellBool(int val);
        TCellBool(bool val);
        TCellBool(QString val);
        //
        TCellBool(double* val, int Q) ;
        TCellBool(float* val, int Q);
        TCellBool(int* val, int Q);
        TCellBool(bool* val, int Q);
        TCellBool(QString* val, int Q);
        //
//        TCelBool(TCelBool&obj);
//        //
//        TCelBool& operator =(TCelBool&obj);
//        //
//        void Assign(TCelBool&obj);

        //
        virtual void construct(int n=1);
        //
        virtual int GetTypeN();
        virtual int GetActiveN();
        virtual void SetActiveN(int N);
        virtual int GetLength();
        virtual void SetLength(int L);
        //
        virtual double GetDoubleVal();
        virtual float GetFloatVal();
        virtual int GetIntVal();
        virtual bool GetBoolVal();
        virtual QString ToString();
        //
        virtual double GetDoubleValN(int N);
        virtual float GetFloatValN(int N);
        virtual int GetIntValN(int N);
        virtual bool GetBoolValN(int N);
        virtual QString ToStringN(int N);
        //
        virtual void SetByValDouble(double val);
        virtual void SetByValFloat(float val);
        virtual void SetByValInt(int val);
        virtual void SetByValBool(bool val);
        virtual void SetByValString(QString val);
        //
        virtual void SetByValDoubleN(double val, int N);
        virtual void SetByValFloatN(float val, int N);
        virtual void SetByValIntN(int val, int N);
        virtual void SetByValBoolN(bool val, int N);
        virtual void SetByValStringN(QString val, int N);
        //
        virtual void SetVal(double val);
        virtual void SetVal(int val);
        virtual void SetVal(bool val);
        virtual void SetVal(QString val);
        //
        virtual void SetValN(double val, int N);
        virtual void SetValN(int val, int N);
        virtual void SetValN(bool val, int N);
        virtual void SetValN(QString val, int N);
        //
        virtual void SetByArrDouble(double* val, int Q);
        virtual void SetByArrFloat(float*val, int Q);
        virtual void SetByArrInt(int* val, int Q);
        virtual void SetByArrBool(bool* val, int Q);
        virtual void SetByArrString(QString*val, int Q);
        //
        virtual void SetByArr(double* val, int Q);
        virtual void SetByArr(int* val, int Q);
        virtual void SetByArr(bool* val, int Q);
        virtual void SetByArr(QString* val, int Q);
        //
        virtual void AddOrInsDoubleVal(double val, int N);
        virtual void AddOrInsFloatVal(float val, int N);
        virtual void AddOrInsIntVal(int val, int N);
        virtual void AddOrInsBoolVal(bool val, int N);
        virtual void AddOrInsStringVal(QString val, int N);
        //
        virtual void DelValN(int N);
        //
        virtual void GetDoubleArr(double*&Arr,  int&QItems);
        virtual void GetFloatArr(float*&Arr, int&QItems);
        virtual void GetIntArr(int*&Arr, int&QItems);
        virtual void GetBoolArr(bool*&Arr, int&QItems);
        virtual void ToStringArr(QString*&Arr, int&QItems);
        //
        virtual void SetNameN(QString name, int N);
        virtual void SetName1(QString name);
        virtual void SetName2(QString name);
        //virtual void SetName3(QString name);
       // virtual void SetNames(QString* Arr, int Q);
        virtual QString GetNameN(int N);
        virtual QString GetName1();
        virtual QString GetName2();
        //virtual QString GetName3();
        //virtual void GetNames(QString*&Arr, int&QItems);
        //virtual int GetLengthOfNamesList();
        //
        //
        virtual void SetItems(QString*items, int Q, int ActiveN=1);
        virtual void GetItems(QString*&items, int&Q);
        virtual void SetItem(QString item, int itemN=-1);
        virtual void InsItem(QString item, int itemN=-1);
        virtual void AddItem(QString item);
        virtual void DelItem(int itemN=-1);
        virtual QString GetItem(int itemN=-1);
        virtual int GetLengthOfItemsList();
    };//cl TCellBool

    class TCellString:public TDataCell
    {
        QString val;
        //
        public:
        TCellString();
        TCellString(double val);
        TCellString(float val);
        TCellString(int val);
        TCellString(bool val);
        TCellString(QString val);
        //
        TCellString(double* val, int Q) ;
        TCellString(float* val, int Q);
        TCellString(int* val, int Q);
        TCellString(bool* val, int Q);
        TCellString(QString* val, int Q);
        //
//        TCelBool(TCelBool&obj);
//        //
//        TCelBool& operator =(TCelBool&obj);
//        //
//        void Assign(TCelBool&obj);

        //
        virtual void construct(int n=1);
        //
        virtual int GetTypeN();
        virtual int GetActiveN();
        virtual void SetActiveN(int N);
        virtual int GetLength();
        virtual void SetLength(int L);
        //
        virtual double GetDoubleVal();
        virtual float GetFloatVal();
        virtual int GetIntVal();
        virtual bool GetBoolVal();
        virtual QString ToString();
        //
        virtual double GetDoubleValN(int N);
        virtual float GetFloatValN(int N);
        virtual int GetIntValN(int N);
        virtual bool GetBoolValN(int N);
        virtual QString ToStringN(int N);
        //
        virtual void SetByValDouble(double val);
        virtual void SetByValFloat(float val);
        virtual void SetByValInt(int val);
        virtual void SetByValBool(bool val);
        virtual void SetByValString(QString val);
        //
        virtual void SetByValDoubleN(double val, int N);
        virtual void SetByValFloatN(float val, int N);
        virtual void SetByValIntN(int val, int N);
        virtual void SetByValBoolN(bool val, int N);
        virtual void SetByValStringN(QString val, int N);
        //
        virtual void SetVal(double val);
        virtual void SetVal(int val);
        virtual void SetVal(bool val);
        virtual void SetVal(QString val);
        //
        virtual void SetValN(double val, int N);
        virtual void SetValN(int val, int N);
        virtual void SetValN(bool val, int N);
        virtual void SetValN(QString val, int N);
        //
        virtual void SetByArrDouble(double* val, int Q);
        virtual void SetByArrFloat(float*val, int Q);
        virtual void SetByArrInt(int* val, int Q);
        virtual void SetByArrBool(bool* val, int Q);
        virtual void SetByArrString(QString*val, int Q);
        //
        virtual void SetByArr(double* val, int Q);
        virtual void SetByArr(int* val, int Q);
        virtual void SetByArr(bool* val, int Q);
        virtual void SetByArr(QString* val, int Q);
        //
        virtual void AddOrInsDoubleVal(double val, int N);
        virtual void AddOrInsFloatVal(float val, int N);
        virtual void AddOrInsIntVal(int val, int N);
        virtual void AddOrInsBoolVal(bool val, int N);
        virtual void AddOrInsStringVal(QString val, int N);
        //
        virtual void DelValN(int N);
        //
        virtual void GetDoubleArr(double*&Arr,  int&QItems);
        virtual void GetFloatArr(float*&Arr, int&QItems);
        virtual void GetIntArr(int*&Arr, int&QItems);
        virtual void GetBoolArr(bool*&Arr, int&QItems);
        virtual void ToStringArr(QString*&Arr, int&QItems);
        //
        virtual void SetNameN(QString name, int N);
        virtual void SetName1(QString name);
        virtual void SetName2(QString name);
        //virtual void SetName3(QString name);
        //virtual void SetNames(QString* Arr, int Q);
        virtual QString GetNameN(int N);
        virtual QString GetName1();
        virtual QString GetName2();
        //virtual QString GetName3();
        //virtual void GetNames(QString*&Arr, int&QItems);
        //virtual int GetLengthOfNamesList();
        //
        //
        virtual void SetItems(QString*items, int Q, int ActiveN=1);
        virtual void GetItems(QString*&items, int&Q);
        virtual void SetItem(QString item, int itemN=-1);
        virtual void InsItem(QString item, int itemN=-1);
        virtual void AddItem(QString item);
        virtual void DelItem(int itemN=-1);
        virtual QString GetItem(int itemN=-1);
        virtual int GetLengthOfItemsList();
    };//cl TCellString


    class TCellDoubleArr:public TDataCell
    {
        //double val;
        std::vector<double>content;
        int ActiveN, Length;
        //
        public:
        TCellDoubleArr();
        TCellDoubleArr(double val);
        TCellDoubleArr(float val);
        TCellDoubleArr(int val);
        TCellDoubleArr(bool val);
        TCellDoubleArr(QString val);
        //
        TCellDoubleArr(double* val, int Q) ;
        TCellDoubleArr(float* val, int Q);
        TCellDoubleArr(int* val, int Q);
        TCellDoubleArr(bool* val, int Q);
        TCellDoubleArr(QString* val, int Q);
        //
//        TCellDoubleArr(TCellDoubleArr&obj);
//        //
//        TCellDoubleArr& operator =(TCellDoubleArr&obj);
//        //
//        void Assign(TCellDoubleArr&obj);

        //
        virtual void construct(int n=1);
        //
        virtual int GetTypeN();
        virtual int GetActiveN();
        virtual void SetActiveN(int N);
        virtual int GetLength();
        virtual void SetLength(int L);
        //
        virtual double GetDoubleVal();
        virtual float GetFloatVal();
        virtual int GetIntVal();
        virtual bool GetBoolVal();
        virtual QString ToString();
        //
        virtual double GetDoubleValN(int N);
        virtual float GetFloatValN(int N);
        virtual int GetIntValN(int N);
        virtual bool GetBoolValN(int N);
        virtual QString ToStringN(int N);
        //
        virtual void SetByValDouble(double val);
        virtual void SetByValFloat(float val);
        virtual void SetByValInt(int val);
        virtual void SetByValBool(bool val);
        virtual void SetByValString(QString val);
        //
        virtual void SetByValDoubleN(double val, int N);
        virtual void SetByValFloatN(float val, int N);
        virtual void SetByValIntN(int val, int N);
        virtual void SetByValBoolN(bool val, int N);
        virtual void SetByValStringN(QString val, int N);
        //
        virtual void SetVal(double val);
        virtual void SetVal(int val);
        virtual void SetVal(bool val);
        virtual void SetVal(QString val);
        //
        virtual void SetValN(double val, int N);
        virtual void SetValN(int val, int N);
        virtual void SetValN(bool val, int N);
        virtual void SetValN(QString val, int N);
        //
        virtual void SetByArrDouble(double* val, int Q);
        virtual void SetByArrFloat(float*val, int Q);
        virtual void SetByArrInt(int* val, int Q);
        virtual void SetByArrBool(bool* val, int Q);
        virtual void SetByArrString(QString*val, int Q);
        //
        virtual void SetByArr(double* val, int Q);
        virtual void SetByArr(int* val, int Q);
        virtual void SetByArr(bool* val, int Q);
        virtual void SetByArr(QString* val, int Q);
        //
        virtual void AddOrInsDoubleVal(double val, int N);
        virtual void AddOrInsFloatVal(float val, int N);
        virtual void AddOrInsIntVal(int val, int N);
        virtual void AddOrInsBoolVal(bool val, int N);
        virtual void AddOrInsStringVal(QString val, int N);
        //
        virtual void DelValN(int N);
        //
        virtual void GetDoubleArr(double*&Arr,  int&QItems);
        virtual void GetFloatArr(float*&Arr, int&QItems);
        virtual void GetIntArr(int*&Arr, int&QItems);
        virtual void GetBoolArr(bool*&Arr, int&QItems);
        virtual void ToStringArr(QString*&Arr, int&QItems);
        //
        virtual void SetNameN(QString name, int N);
        virtual void SetName1(QString name);
        virtual void SetName2(QString name);
        //virtual void SetName3(QString name);
        //virtual void SetNames(QString* Arr, int Q);
        virtual QString GetNameN(int N);
        virtual QString GetName1();
        virtual QString GetName2();
        //virtual QString GetName3();
        //virtual void GetNames(QString*&Arr, int&QItems);
        //virtual int GetLengthOfNamesList();
        //
        //
        virtual void SetItems(QString*items, int Q, int ActiveN=1);
        virtual void GetItems(QString*&items, int&Q);
        virtual void SetItem(QString item, int itemN=-1);
        virtual void InsItem(QString item, int itemN=-1);
        virtual void AddItem(QString item);
        virtual void DelItem(int itemN=-1);
        virtual QString GetItem(int itemN=-1);
        virtual int GetLengthOfItemsList();
    };//cl TCellDoubleArr



    class TCellFloatArr:public TDataCell
    {
        //double val;
        std::vector<float>content;
        int ActiveN, Length;
        //
        public:
        TCellFloatArr();
        TCellFloatArr(double val);
        TCellFloatArr(float val);
        TCellFloatArr(int val);
        TCellFloatArr(bool val);
        TCellFloatArr(QString val);
        //
        TCellFloatArr(double* val, int Q) ;
        TCellFloatArr(float* val, int Q);
        TCellFloatArr(int* val, int Q);
        TCellFloatArr(bool* val, int Q);
        TCellFloatArr(QString* val, int Q);
        //
//        TCellFloatArr(TCellFloatArr&obj);
//        //
//        TCellFloatArr& operator =(TCellFloatArr&obj);
//        //
//        void Assign(TCellFloatArr&obj);

        //
        virtual void construct(int n=1);
        //
        virtual int GetTypeN();
        virtual int GetActiveN();
        virtual void SetActiveN(int N);
        virtual int GetLength();
        virtual void SetLength(int L);
        //
        virtual double GetDoubleVal();
        virtual float GetFloatVal();
        virtual int GetIntVal();
        virtual bool GetBoolVal();
        virtual QString ToString();
        //
        virtual double GetDoubleValN(int N);
        virtual float GetFloatValN(int N);
        virtual int GetIntValN(int N);
        virtual bool GetBoolValN(int N);
        virtual QString ToStringN(int N);
        //
        virtual void SetByValDouble(double val);
        virtual void SetByValFloat(float val);
        virtual void SetByValInt(int val);
        virtual void SetByValBool(bool val);
        virtual void SetByValString(QString val);
        //
        virtual void SetByValDoubleN(double val, int N);
        virtual void SetByValFloatN(float val, int N);
        virtual void SetByValIntN(int val, int N);
        virtual void SetByValBoolN(bool val, int N);
        virtual void SetByValStringN(QString val, int N);
        //
        virtual void SetVal(double val);
        virtual void SetVal(int val);
        virtual void SetVal(bool val);
        virtual void SetVal(QString val);
        //
        virtual void SetValN(double val, int N);
        virtual void SetValN(int val, int N);
        virtual void SetValN(bool val, int N);
        virtual void SetValN(QString val, int N);
        //
        virtual void SetByArrDouble(double* val, int Q);
        virtual void SetByArrFloat(float*val, int Q);
        virtual void SetByArrInt(int* val, int Q);
        virtual void SetByArrBool(bool* val, int Q);
        virtual void SetByArrString(QString*val, int Q);
        //
        virtual void SetByArr(double* val, int Q);
        virtual void SetByArr(int* val, int Q);
        virtual void SetByArr(bool* val, int Q);
        virtual void SetByArr(QString* val, int Q);
        //
        virtual void AddOrInsDoubleVal(double val, int N);
        virtual void AddOrInsFloatVal(float val, int N);
        virtual void AddOrInsIntVal(int val, int N);
        virtual void AddOrInsBoolVal(bool val, int N);
        virtual void AddOrInsStringVal(QString val, int N);
        //
        virtual void DelValN(int N);
        //
        virtual void GetDoubleArr(double*&Arr,  int&QItems);
        virtual void GetFloatArr(float*&Arr, int&QItems);
        virtual void GetIntArr(int*&Arr, int&QItems);
        virtual void GetBoolArr(bool*&Arr, int&QItems);
        virtual void ToStringArr(QString*&Arr, int&QItems);
        //
        virtual void SetNameN(QString name, int N);
        virtual void SetName1(QString name);
        virtual void SetName2(QString name);
        //virtual void SetName3(QString name);
        //virtual void SetNames(QString* Arr, int Q);
        virtual QString GetNameN(int N);
        virtual QString GetName1();
        virtual QString GetName2();
        //virtual QString GetName3();
        //virtual void GetNames(QString*&Arr, int&QItems);
        //virtual int GetLengthOfNamesList();
        //
        //
        virtual void SetItems(QString*items, int Q, int ActiveN=1);
        virtual void GetItems(QString*&items, int&Q);
        virtual void SetItem(QString item, int itemN=-1);
        virtual void InsItem(QString item, int itemN=-1);
        virtual void AddItem(QString item);
        virtual void DelItem(int itemN=-1);
        virtual QString GetItem(int itemN=-1);
        virtual int GetLengthOfItemsList();
        //
    };//cl TCellFloatArr

    class TCellIntArr:public TDataCell
    {
        //double val;
        std::vector<int>content;
        int ActiveN, Length;
        //
        public:
        TCellIntArr();
        TCellIntArr(double val);
        TCellIntArr(float val);
        TCellIntArr(int val);
        TCellIntArr(bool val);
        TCellIntArr(QString val);
        //
        TCellIntArr(double* val, int Q) ;
        TCellIntArr(float* val, int Q);
        TCellIntArr(int* val, int Q);
        TCellIntArr(bool* val, int Q);
        TCellIntArr(QString* val, int Q);
        //
//        TCellIntArr(TCellIntArr&obj);
//        //
//        TCellIntArr& operator =(TCellIntArr&obj);
//        //
//        void Assign(TCellIntArr&obj);

        //
        virtual void construct(int n=1);
        //
        virtual int GetTypeN();
        virtual int GetActiveN();
        virtual void SetActiveN(int N);
        virtual int GetLength();
        virtual void SetLength(int L);
        //
        virtual double GetDoubleVal();
        virtual float GetFloatVal();
        virtual int GetIntVal();
        virtual bool GetBoolVal();
        virtual QString ToString();
        //
        virtual double GetDoubleValN(int N);
        virtual float GetFloatValN(int N);
        virtual int GetIntValN(int N);
        virtual bool GetBoolValN(int N);
        virtual QString ToStringN(int N);
        //
        virtual void SetByValDouble(double val);
        virtual void SetByValFloat(float val);
        virtual void SetByValInt(int val);
        virtual void SetByValBool(bool val);
        virtual void SetByValString(QString val);
        //
        virtual void SetByValDoubleN(double val, int N);
        virtual void SetByValFloatN(float val, int N);
        virtual void SetByValIntN(int val, int N);
        virtual void SetByValBoolN(bool val, int N);
        virtual void SetByValStringN(QString val, int N);
        //
        virtual void SetVal(double val);
        virtual void SetVal(int val);
        virtual void SetVal(bool val);
        virtual void SetVal(QString val);
        //
        virtual void SetValN(double val, int N);
        virtual void SetValN(int val, int N);
        virtual void SetValN(bool val, int N);
        virtual void SetValN(QString val, int N);
        //
        virtual void SetByArrDouble(double* val, int Q);
        virtual void SetByArrFloat(float*val, int Q);
        virtual void SetByArrInt(int* val, int Q);
        virtual void SetByArrBool(bool* val, int Q);
        virtual void SetByArrString(QString*val, int Q);
        //
        virtual void SetByArr(double* val, int Q);
        virtual void SetByArr(int* val, int Q);
        virtual void SetByArr(bool* val, int Q);
        virtual void SetByArr(QString* val, int Q);
        //
        virtual void AddOrInsDoubleVal(double val, int N);
        virtual void AddOrInsFloatVal(float val, int N);
        virtual void AddOrInsIntVal(int val, int N);
        virtual void AddOrInsBoolVal(bool val, int N);
        virtual void AddOrInsStringVal(QString val, int N);
        //
        virtual void DelValN(int N);
        //
        virtual void GetDoubleArr(double*&Arr,  int&QItems);
        virtual void GetFloatArr(float*&Arr, int&QItems);
        virtual void GetIntArr(int*&Arr, int&QItems);
        virtual void GetBoolArr(bool*&Arr, int&QItems);
        virtual void ToStringArr(QString*&Arr, int&QItems);
        //
        virtual void SetNameN(QString name, int N);
        virtual void SetName1(QString name);
        virtual void SetName2(QString name);
        virtual void SetName3(QString name);
        //virtual void SetNames(QString* Arr, int Q);
        virtual QString GetNameN(int N);
        virtual QString GetName1();
        virtual QString GetName2();
        //virtual QString GetName3();
        //virtual void GetNames(QString*&Arr, int&QItems);
        //virtual int GetLengthOfNamesList();
        //
        //
        virtual void SetItems(QString*items, int Q, int ActiveN=1);
        virtual void GetItems(QString*&items, int&Q);
        virtual void SetItem(QString item, int itemN=-1);
        virtual void InsItem(QString item, int itemN=-1);
        virtual void AddItem(QString item);
        virtual void DelItem(int itemN=-1);
        virtual QString GetItem(int itemN=-1);
        virtual int GetLengthOfItemsList();
        //
    };//cl TCellIntArr

    class TCellBoolArr:public TDataCell
    {
        //double val;
        std::vector<bool>content;
        int ActiveN, Length;
        //
        public:
        TCellBoolArr();
        TCellBoolArr(double val);
        TCellBoolArr(float val);
        TCellBoolArr(int val);
        TCellBoolArr(bool val);
        TCellBoolArr(QString val);
        //
        TCellBoolArr(double* val, int Q) ;
        TCellBoolArr(float* val, int Q);
        TCellBoolArr(int* val, int Q);
        TCellBoolArr(bool* val, int Q);
        TCellBoolArr(QString* val, int Q);
        //
//        TCellBoolArr(TCellBoolArr&obj);
//        //
//        TCellBoolArr& operator =(TCellBoolArr&obj);
//        //
//        void Assign(TCellBoolArr&obj);

        //
        virtual void construct(int n=1);
        //
        virtual int GetTypeN();
        virtual int GetActiveN();
        virtual void SetActiveN(int N);
        virtual int GetLength();
        virtual void SetLength(int L);
        //
        virtual double GetDoubleVal();
        virtual float GetFloatVal();
        virtual int GetIntVal();
        virtual bool GetBoolVal();
        virtual QString ToString();
        //
        virtual double GetDoubleValN(int N);
        virtual float GetFloatValN(int N);
        virtual int GetIntValN(int N);
        virtual bool GetBoolValN(int N);
        virtual QString ToStringN(int N);
        //
        virtual void SetByValDouble(double val);
        virtual void SetByValFloat(float val);
        virtual void SetByValInt(int val);
        virtual void SetByValBool(bool val);
        virtual void SetByValString(QString val);
        //
        virtual void SetByValDoubleN(double val, int N);
        virtual void SetByValFloatN(float val, int N);
        virtual void SetByValIntN(int val, int N);
        virtual void SetByValBoolN(bool val, int N);
        virtual void SetByValStringN(QString val, int N);
        //
        virtual void SetVal(double val);
        virtual void SetVal(int val);
        virtual void SetVal(bool val);
        virtual void SetVal(QString val);
        //
        virtual void SetValN(double val, int N);
        virtual void SetValN(int val, int N);
        virtual void SetValN(bool val, int N);
        virtual void SetValN(QString val, int N);
        //
        virtual void SetByArrDouble(double* val, int Q);
        virtual void SetByArrFloat(float*val, int Q);
        virtual void SetByArrInt(int* val, int Q);
        virtual void SetByArrBool(bool* val, int Q);
        virtual void SetByArrString(QString*val, int Q);
        //
        virtual void SetByArr(double* val, int Q);
        virtual void SetByArr(int* val, int Q);
        virtual void SetByArr(bool* val, int Q);
        virtual void SetByArr(QString* val, int Q);
        //
        virtual void AddOrInsDoubleVal(double val, int N);
        virtual void AddOrInsFloatVal(float val, int N);
        virtual void AddOrInsIntVal(int val, int N);
        virtual void AddOrInsBoolVal(bool val, int N);
        virtual void AddOrInsStringVal(QString val, int N);
        //
        virtual void DelValN(int N);
        //
        virtual void GetDoubleArr(double*&Arr,  int&QItems);
        virtual void GetFloatArr(float*&Arr, int&QItems);
        virtual void GetIntArr(int*&Arr, int&QItems);
        virtual void GetBoolArr(bool*&Arr, int&QItems);
        virtual void ToStringArr(QString*&Arr, int&QItems);
        //
        virtual void SetNameN(QString name, int N);
        virtual void SetName1(QString name);
        virtual void SetName2(QString name);
       // virtual void SetName3(QString name);
        //virtual void SetNames(QString* Arr, int Q);
        virtual QString GetNameN(int N);
        virtual QString GetName1();
        virtual QString GetName2();
        //virtual QString GetName3();
        //virtual void GetNames(QString*&Arr, int&QItems);
        //virtual int GetLengthOfNamesList();
        //
        //
        virtual void SetItems(QString*items, int Q, int ActiveN=1);
        virtual void GetItems(QString*&items, int&Q);
        virtual void SetItem(QString item, int itemN=-1);
        virtual void InsItem(QString item, int itemN=-1);
        virtual void AddItem(QString item);
        virtual void DelItem(int itemN=-1);
        virtual QString GetItem(int itemN=-1);
        virtual int GetLengthOfItemsList();
        //
    };//cl TCellBoolArr


    class TCellStringArr:public TDataCell
    {
        //double val;
        std::vector<QString>content;
        int ActiveN, Length;
        //
        public:
        TCellStringArr();
        TCellStringArr(double val);
        TCellStringArr(float val);
        TCellStringArr(int val);
        TCellStringArr(bool val);
        TCellStringArr(QString val);
        //
        TCellStringArr(double* val, int Q) ;
        TCellStringArr(float* val, int Q);
        TCellStringArr(int* val, int Q);
        TCellStringArr(bool* val, int Q);
        TCellStringArr(QString* val, int Q);
        //
//        TCellStringArr(TCellStringArr&obj);
//        //
//        TCellStringArr& operator =(TCellStringArr&obj);
//        //
//        void Assign(TCellStringArr&obj);

        //
        virtual void construct(int n=1);
        //
        virtual int GetTypeN();
        virtual int GetActiveN();
        virtual void SetActiveN(int N);
        virtual int GetLength();
        virtual void SetLength(int L);
        //
        virtual double GetDoubleVal();
        virtual float GetFloatVal();
        virtual int GetIntVal();
        virtual bool GetBoolVal();
        virtual QString ToString();
        //
        virtual double GetDoubleValN(int N);
        virtual float GetFloatValN(int N);
        virtual int GetIntValN(int N);
        virtual bool GetBoolValN(int N);
        virtual QString ToStringN(int N);
        //
        virtual void SetByValDouble(double val);
        virtual void SetByValFloat(float val);
        virtual void SetByValInt(int val);
        virtual void SetByValBool(bool val);
        virtual void SetByValString(QString val);
        //
        virtual void SetByValDoubleN(double val, int N);
        virtual void SetByValFloatN(float val, int N);
        virtual void SetByValIntN(int val, int N);
        virtual void SetByValBoolN(bool val, int N);
        virtual void SetByValStringN(QString val, int N);
        //
        virtual void SetVal(double val);
        virtual void SetVal(int val);
        virtual void SetVal(bool val);
        virtual void SetVal(QString val);
        //
        virtual void SetValN(double val, int N);
        virtual void SetValN(int val, int N);
        virtual void SetValN(bool val, int N);
        virtual void SetValN(QString val, int N);
        //
        virtual void SetByArrDouble(double* val, int Q);
        virtual void SetByArrFloat(float*val, int Q);
        virtual void SetByArrInt(int* val, int Q);
        virtual void SetByArrBool(bool* val, int Q);
        virtual void SetByArrString(QString*val, int Q);
        //
        virtual void SetByArr(double* val, int Q);
        virtual void SetByArr(int* val, int Q);
        virtual void SetByArr(bool* val, int Q);
        virtual void SetByArr(QString* val, int Q);
        //
        virtual void AddOrInsDoubleVal(double val, int N);
        virtual void AddOrInsFloatVal(float val, int N);
        virtual void AddOrInsIntVal(int val, int N);
        virtual void AddOrInsBoolVal(bool val, int N);
        virtual void AddOrInsStringVal(QString val, int N);
        //
        virtual void DelValN(int N);
        //
        virtual void GetDoubleArr(double*&Arr,  int&QItems);
        virtual void GetFloatArr(float*&Arr, int&QItems);
        virtual void GetIntArr(int*&Arr, int&QItems);
        virtual void GetBoolArr(bool*&Arr, int&QItems);
        virtual void ToStringArr(QString*&Arr, int&QItems);
        //
        virtual void SetNameN(QString name, int N);
        virtual void SetName1(QString name);
        virtual void SetName2(QString name);
        //virtual void SetName3(QString name);
        //virtual void SetNames(QString* Arr, int Q);
        virtual QString GetNameN(int N);
        virtual QString GetName1();
        virtual QString GetName2();
        //virtual QString GetName3();
        //virtual void GetNames(QString*&Arr, int&QItems);
        //virtual int GetLengthOfNamesList();
        //
        //
        virtual void SetItems(QString*items, int Q, int ActiveN=1);
        virtual void GetItems(QString*&items, int&Q);
        virtual void SetItem(QString item, int itemN=-1);
        virtual void InsItem(QString item, int itemN=-1);
        virtual void AddItem(QString item);
        virtual void DelItem(int itemN=-1);
        virtual QString GetItem(int itemN=-1);
        virtual int GetLengthOfItemsList();
        //
    };//cl TCellStringArr


    class TDBCOlHeader_Items_Double:public TDataCell
    {
        //double val;
        std::vector<double>content;
        std::vector<QString>names;
        int ActiveN_ByDefault, LengthOfItemsSet, LengthOfNamesSet;
        //
        public:
        TDBCOlHeader_Items_Double();
        //TDBCOlHeader_Items_Double(double val);
        //TDBCOlHeader_Items_Double(float val);
        //TDBCOlHeader_Items_Double(int val);
        //TDBCOlHeader_Items_Double(bool val);
        //TDBCOlHeader_Items_Double(QString val);
        //
        TDBCOlHeader_Items_Double(double* val, int Q) ;
        //TDBCOlHeader_Items_Double(float* val, int Q);
        //TDBCOlHeader_Items_Double(int* val, int Q);
        //TDBCOlHeader_Items_Double(bool* val, int Q);
        //TDBCOlHeader_Items_Double(QString* val, int Q);
        //
        TDBCOlHeader_Items_Double(double* val, int QItems, QString* name, int QNames);
        //
        //   TCellDoubleArr(TCellDoubleArr&obj);
        //   //
        //   TCellDoubleArr& operator =(TCellDoubleArr&obj);
        //   //
        //   void Assign(TCellDoubleArr&obj);
        //
        virtual void construct(int n=1);
        //
        virtual int GetTypeN();
        virtual int GetActiveN();
        virtual void SetActiveN(int N);
        virtual int GetLength();
        virtual void SetLength(int L);
        //
        virtual double GetDoubleVal();
        virtual float GetFloatVal();
        virtual int GetIntVal();
        virtual bool GetBoolVal();
        virtual QString ToString();
        //
        virtual double GetDoubleValN(int N);
        virtual float GetFloatValN(int N);
        virtual int GetIntValN(int N);
        virtual bool GetBoolValN(int N);
        virtual QString ToStringN(int N);
        //
        virtual void SetByValDouble(double val);
        virtual void SetByValFloat(float val);
        virtual void SetByValInt(int val);
        virtual void SetByValBool(bool val);
        virtual void SetByValString(QString val);
        //
        virtual void SetByValDoubleN(double val, int N);
        virtual void SetByValFloatN(float val, int N);
        virtual void SetByValIntN(int val, int N);
        virtual void SetByValBoolN(bool val, int N);
        virtual void SetByValStringN(QString val, int N);
        //
        virtual void SetVal(double val);
        virtual void SetVal(int val);
        virtual void SetVal(bool val);
        virtual void SetVal(QString val);
        //
        virtual void SetValN(double val, int N);
        virtual void SetValN(int val, int N);
        virtual void SetValN(bool val, int N);
        virtual void SetValN(QString val, int N);
        //
        virtual void SetByArrDouble(double* val, int Q);
        virtual void SetByArrFloat(float*val, int Q);
        virtual void SetByArrInt(int* val, int Q);
        virtual void SetByArrBool(bool* val, int Q);
        virtual void SetByArrString(QString*val, int Q);
        //
        virtual void SetByArr(double* val, int Q);
        virtual void SetByArr(int* val, int Q);
        virtual void SetByArr(bool* val, int Q);
        virtual void SetByArr(QString* val, int Q);
        //
        virtual void AddOrInsDoubleVal(double val, int N);
        virtual void AddOrInsFloatVal(float val, int N);
        virtual void AddOrInsIntVal(int val, int N);
        virtual void AddOrInsBoolVal(bool val, int N);
        virtual void AddOrInsStringVal(QString val, int N);
        //
        virtual void DelValN(int N);
        //
        virtual void GetDoubleArr(double*&Arr,  int&QItems);
        virtual void GetFloatArr(float*&Arr, int&QItems);
        virtual void GetIntArr(int*&Arr, int&QItems);
        virtual void GetBoolArr(bool*&Arr, int&QItems);
        virtual void ToStringArr(QString*&Arr, int&QItems);
        //
        virtual void SetNameN(QString name, int N);
        virtual void SetName1(QString name);
        virtual void SetName2(QString name);
        //virtual void SetName3(QString name);
        //virtual void SetNames(QString* Arr, int Q);
        virtual QString GetNameN(int N);
        virtual QString GetName1();
        virtual QString GetName2();
        //virtual QString GetName3();
        //virtual void GetNames(QString*&Arr, int&QItems);
        //virtual int GetLengthOfNamesList();
        //
        virtual void SetItems(QString*items, int Q, int ActiveN=1);
        virtual void GetItems(QString*&items, int&Q);
        virtual void SetItem(QString item, int itemN=-1);
        virtual void InsItem(QString item, int itemN=-1);
        virtual void AddItem(QString item);
        virtual void DelItem(int itemN=-1);
        virtual QString GetItem(int itemN=-1);
        virtual int GetLengthOfItemsList();
        //
        //
    };//cl TDBCOlHeader_Items_Double

class TDBCOlHeader_Items_Int:public TDataCell
{
    //double val;
    std::vector<int>content;
    std::vector<QString>names;
    int ActiveN_ByDefault, LengthOfItemsSet, LengthOfNamesSet;
    //
    public:
    TDBCOlHeader_Items_Int();
    //TDBCOlHeader_Items_Int(double val);
    //TDBCOlHeader_Items_Int(float val);
    //TDBCOlHeader_Items_Int(int val);
    //TDBCOlHeader_Items_Int(bool val);
    //TDBCOlHeader_Items_Int(QString val);
    //
    //TDBCOlHeader_Items_Int(double* val, int Q) ;
    //TDBCOlHeader_Items_Int(float* val, int Q);
    TDBCOlHeader_Items_Int(int* val, int Q);
    //TDBCOlHeader_Items_Int(bool* val, int Q);
    //TDBCOlHeader_Items_Int(QString* val, int Q);
    //
    TDBCOlHeader_Items_Int(int* val, int QItems, QString* name, int QNames);
    //
    //   TCellDoubleArr(TCellDoubleArr&obj);
    //   //
    //   TCellDoubleArr& operator =(TCellDoubleArr&obj);
    //   //
    //   void Assign(TCellDoubleArr&obj);
    //
    virtual void construct(int n=1);
    //
    virtual int GetTypeN();
    virtual int GetActiveN();
    virtual void SetActiveN(int N);
    virtual int GetLength();
    virtual void SetLength(int L);
    //
    virtual double GetDoubleVal();
    virtual float GetFloatVal();
    virtual int GetIntVal();
    virtual bool GetBoolVal();
    virtual QString ToString();
    //
    virtual double GetDoubleValN(int N);
    virtual float GetFloatValN(int N);
    virtual int GetIntValN(int N);
    virtual bool GetBoolValN(int N);
    virtual QString ToStringN(int N);
    //
    virtual void SetByValDouble(double val);
    virtual void SetByValFloat(float val);
    virtual void SetByValInt(int val);
    virtual void SetByValBool(bool val);
    virtual void SetByValString(QString val);
    //
    virtual void SetByValDoubleN(double val, int N);
    virtual void SetByValFloatN(float val, int N);
    virtual void SetByValIntN(int val, int N);
    virtual void SetByValBoolN(bool val, int N);
    virtual void SetByValStringN(QString val, int N);
    //
    virtual void SetVal(double val);
    virtual void SetVal(int val);
    virtual void SetVal(bool val);
    virtual void SetVal(QString val);
    //
    virtual void SetValN(double val, int N);
    virtual void SetValN(int val, int N);
    virtual void SetValN(bool val, int N);
    virtual void SetValN(QString val, int N);
    //
    virtual void SetByArrDouble(double* val, int Q);
    virtual void SetByArrFloat(float*val, int Q);
    virtual void SetByArrInt(int* val, int Q);
    virtual void SetByArrBool(bool* val, int Q);
    virtual void SetByArrString(QString*val, int Q);
    //
    virtual void SetByArr(double* val, int Q);
    virtual void SetByArr(int* val, int Q);
    virtual void SetByArr(bool* val, int Q);
    virtual void SetByArr(QString* val, int Q);
    //
    virtual void AddOrInsDoubleVal(double val, int N);
    virtual void AddOrInsFloatVal(float val, int N);
    virtual void AddOrInsIntVal(int val, int N);
    virtual void AddOrInsBoolVal(bool val, int N);
    virtual void AddOrInsStringVal(QString val, int N);
    //
    virtual void DelValN(int N);
    //
    virtual void GetDoubleArr(double*&Arr,  int&QItems);
    virtual void GetFloatArr(float*&Arr, int&QItems);
    virtual void GetIntArr(int*&Arr, int&QItems);
    virtual void GetBoolArr(bool*&Arr, int&QItems);
    virtual void ToStringArr(QString*&Arr, int&QItems);
    //
    virtual void SetNameN(QString name, int N);
    virtual void SetName1(QString name);
    virtual void SetName2(QString name);
    //virtual void SetName3(QString name);
    //virtual void SetNames(QString* Arr, int Q);
    virtual QString GetNameN(int N);
    virtual QString GetName1();
    virtual QString GetName2();
    //virtual QString GetName3();
    //virtual void GetNames(QString*&Arr, int&QItems);
    //virtual int GetLengthOfNamesList();
    //
    virtual void SetItems(QString*items, int Q, int ActiveN=1);
    virtual void GetItems(QString*&items, int&Q);
    virtual void SetItem(QString item, int itemN=-1);
    virtual void InsItem(QString item, int itemN=-1);
    virtual void AddItem(QString item);
    virtual void DelItem(int itemN=-1);
    virtual QString GetItem(int itemN=-1);
    virtual int GetLengthOfItemsList();
    //
    //
};//cl TDBCOlHeader_Items_Int

class TDBCOlHeader_Items_String:public TDataCell
{
    //double val;
    std::vector<QString>content;
    std::vector<QString>names;
    int ActiveN_ByDefault, LengthOfItemsSet, LengthOfNamesSet;
    //
    public:
    TDBCOlHeader_Items_String();
    //TDBCOlHeader_Items_String(double val);
    //TDBCOlHeader_Items_String(float val);
    //TDBCOlHeader_Items_String(int val);
    //TDBCOlHeader_Items_String(bool val);
    //TDBCOlHeader_Items_String(QString val);
    //
    //TDBCOlHeader_Items_String(double* val, int Q) ;
    //TDBCOlHeader_Items_String(float* val, int Q);
    //TDBCOlHeader_Items_String(int* val, int Q);
    //TDBCOlHeader_Items_String(bool* val, int Q);
    TDBCOlHeader_Items_String(QString* val, int Q);
    //
    TDBCOlHeader_Items_String(QString* val, int QVals, QString* name, int QNames);
    //
    //   TCellDoubleArr(TCellDoubleArr&obj);
    //   //
    //   TCellDoubleArr& operator =(TCellDoubleArr&obj);
    //   //
    //   void Assign(TCellDoubleArr&obj);
    //
    virtual void construct(int n=1);
    //
    virtual int GetTypeN();
    virtual int GetActiveN();
    virtual void SetActiveN(int N);
    virtual int GetLength();
    virtual void SetLength(int L);
    //
    virtual double GetDoubleVal();
    virtual float GetFloatVal();
    virtual int GetIntVal();
    virtual bool GetBoolVal();
    virtual QString ToString();
    //
    virtual double GetDoubleValN(int N);
    virtual float GetFloatValN(int N);
    virtual int GetIntValN(int N);
    virtual bool GetBoolValN(int N);
    virtual QString ToStringN(int N);
    //
    virtual void SetByValDouble(double val);
    virtual void SetByValFloat(float val);
    virtual void SetByValInt(int val);
    virtual void SetByValBool(bool val);
    virtual void SetByValString(QString val);
    //
    virtual void SetByValDoubleN(double val, int N);
    virtual void SetByValFloatN(float val, int N);
    virtual void SetByValIntN(int val, int N);
    virtual void SetByValBoolN(bool val, int N);
    virtual void SetByValStringN(QString val, int N);
    //
    virtual void SetVal(double val);
    virtual void SetVal(int val);
    virtual void SetVal(bool val);
    virtual void SetVal(QString val);
    //
    virtual void SetValN(double val, int N);
    virtual void SetValN(int val, int N);
    virtual void SetValN(bool val, int N);
    virtual void SetValN(QString val, int N);
    //
    virtual void SetByArrDouble(double* val, int Q);
    virtual void SetByArrFloat(float*val, int Q);
    virtual void SetByArrInt(int* val, int Q);
    virtual void SetByArrBool(bool* val, int Q);
    virtual void SetByArrString(QString*val, int Q);
    //
    virtual void SetByArr(double* val, int Q);
    virtual void SetByArr(int* val, int Q);
    virtual void SetByArr(bool* val, int Q);
    virtual void SetByArr(QString* val, int Q);
    //
    virtual void AddOrInsDoubleVal(double val, int N);
    virtual void AddOrInsFloatVal(float val, int N);
    virtual void AddOrInsIntVal(int val, int N);
    virtual void AddOrInsBoolVal(bool val, int N);
    virtual void AddOrInsStringVal(QString val, int N);
    //
    virtual void DelValN(int N);
    //
    virtual void GetDoubleArr(double*&Arr,  int&QItems);
    virtual void GetFloatArr(float*&Arr, int&QItems);
    virtual void GetIntArr(int*&Arr, int&QItems);
    virtual void GetBoolArr(bool*&Arr, int&QItems);
    virtual void ToStringArr(QString*&Arr, int&QItems);
    //
    virtual void SetNameN(QString name, int N);
    virtual void SetName1(QString name);
    virtual void SetName2(QString name);
    //virtual void SetName3(QString name);
    //virtual void SetNames(QString* Arr, int Q);
    virtual QString GetNameN(int N);
    virtual QString GetName1();
    virtual QString GetName2();
    //virtual QString GetName3();
    //virtual void GetNames(QString*&Arr, int&QItems);
    //virtual int GetLengthOfNamesList();
    //
    virtual void SetItems(QString*items, int Q, int ActiveN=1);
    virtual void GetItems(QString*&items, int&Q);
    virtual void SetItem(QString item, int itemN=-1);
    virtual void InsItem(QString item, int itemN=-1);
    virtual void AddItem(QString item);
    virtual void DelItem(int itemN=-1);
    virtual QString GetItem(int itemN=-1);
    virtual int GetLengthOfItemsList();
    //
    //
};//cl TDBCOlHeader_Items_String

class TCellDBTableHeader:public TDataCell
{
    QString TableNameToDisplay;
    TDBTableHeader*DBTableData;
    //int ActiveN_ByDefault, LengthOfItemsSet, LengthOfNamesSet;
    //
    public:
    TCellDBTableHeader();
    //TDBCOlHeader_Items_String(double val);
    //TDBCOlHeader_Items_String(float val);
    //TDBCOlHeader_Items_String(int val);
    //TDBCOlHeader_Items_String(bool val);
    //TDBCOlHeader_Items_String(QString val);
    //
    //TDBCOlHeader_Items_String(double* val, int Q) ;
    //TDBCOlHeader_Items_String(float* val, int Q);
    //TDBCOlHeader_Items_String(int* val, int Q);
    //TDBCOlHeader_Items_String(bool* val, int Q);
    TCellDBTableHeader(QString* val, int Q);
    //
    TCellDBTableHeader(QString* val, int QVals, QString* name, int QNames);
    //
    //   TCellDoubleArr(TCellDoubleArr&obj);
    //   //
    //   TCellDoubleArr& operator =(TCellDoubleArr&obj);
    //   //
    //   void Assign(TCellDoubleArr&obj);
    //
    virtual void construct(int n=1);
    //
    virtual int GetTypeN();
    virtual int GetActiveN();
    virtual void SetActiveN(int N);
    virtual int GetLength();
    virtual void SetLength(int L);
    //
    virtual double GetDoubleVal();
    virtual float GetFloatVal();
    virtual int GetIntVal();
    virtual bool GetBoolVal();
    virtual QString ToString();
    //
    virtual double GetDoubleValN(int N);
    virtual float GetFloatValN(int N);
    virtual int GetIntValN(int N);
    virtual bool GetBoolValN(int N);
    virtual QString ToStringN(int N);
    //
    virtual void SetByValDouble(double val);
    virtual void SetByValFloat(float val);
    virtual void SetByValInt(int val);
    virtual void SetByValBool(bool val);
    virtual void SetByValString(QString val);
    //
    virtual void SetByValDoubleN(double val, int N);
    virtual void SetByValFloatN(float val, int N);
    virtual void SetByValIntN(int val, int N);
    virtual void SetByValBoolN(bool val, int N);
    virtual void SetByValStringN(QString val, int N);
    //
    virtual void SetVal(double val);
    virtual void SetVal(int val);
    virtual void SetVal(bool val);
    virtual void SetVal(QString val);
    //
    virtual void SetValN(double val, int N);
    virtual void SetValN(int val, int N);
    virtual void SetValN(bool val, int N);
    virtual void SetValN(QString val, int N);
    //
    virtual void SetByArrDouble(double* val, int Q);
    virtual void SetByArrFloat(float*val, int Q);
    virtual void SetByArrInt(int* val, int Q);
    virtual void SetByArrBool(bool* val, int Q);
    virtual void SetByArrString(QString*val, int Q);
    //
    virtual void SetByArr(double* val, int Q);
    virtual void SetByArr(int* val, int Q);
    virtual void SetByArr(bool* val, int Q);
    virtual void SetByArr(QString* val, int Q);
    //
    virtual void AddOrInsDoubleVal(double val, int N);
    virtual void AddOrInsFloatVal(float val, int N);
    virtual void AddOrInsIntVal(int val, int N);
    virtual void AddOrInsBoolVal(bool val, int N);
    virtual void AddOrInsStringVal(QString val, int N);
    //
    virtual void DelValN(int N);
    //
    virtual void GetDoubleArr(double*&Arr,  int&QItems);
    virtual void GetFloatArr(float*&Arr, int&QItems);
    virtual void GetIntArr(int*&Arr, int&QItems);
    virtual void GetBoolArr(bool*&Arr, int&QItems);
    virtual void ToStringArr(QString*&Arr, int&QItems);
    //
    virtual void SetNameN(QString name, int N);
    virtual void SetName1(QString name);
    virtual void SetName2(QString name);
    //virtual void SetName3(QString name);
    //virtual void SetNames(QString* Arr, int Q);
    virtual QString GetNameN(int N);
    virtual QString GetName1();
    virtual QString GetName2();
    //virtual QString GetName3();
    //virtual void GetNames(QString*&Arr, int&QItems);
    //virtual int GetLengthOfNamesList();
    //
    virtual void SetItems(QString*items, int Q, int ActiveN=1);
    virtual void GetItems(QString*&items, int&Q);
    virtual void SetItem(QString item, int itemN=-1);
    virtual void InsItem(QString item, int itemN=-1);
    virtual void AddItem(QString item);
    virtual void DelItem(int itemN=-1);
    virtual QString GetItem(int itemN=-1);
    virtual int GetLengthOfItemsList();
    //
    //
};//cl TCellDBTableHeader

class TCellDBRowHeader:public TDataCell
{
    QString ColNameToDisplay;
    std::vector<QString>items;
    TDBFieldHeader*DBFieldData;
    //int ActiveN_ByDefault, LengthOfItemsSet, LengthOfNamesSet;
    //
    public:
    TCellDBRowHeader();
    //TDBCOlHeader_Items_String(double val);
    //TDBCOlHeader_Items_String(float val);
    //TDBCOlHeader_Items_String(int val);
    //TDBCOlHeader_Items_String(bool val);
    //TDBCOlHeader_Items_String(QString val);
    //
    //TDBCOlHeader_Items_String(double* val, int Q) ;
    //TDBCOlHeader_Items_String(float* val, int Q);
    //TDBCOlHeader_Items_String(int* val, int Q);
    //TDBCOlHeader_Items_String(bool* val, int Q);
    TCellDBRowHeader(QString* val, int Q);
    //
    TCellDBRowHeader(QString* val, int QVals, QString* name, int QNames);
    //
    //   TCellDoubleArr(TCellDoubleArr&obj);
    //   //
    //   TCellDoubleArr& operator =(TCellDoubleArr&obj);
    //   //
    //   void Assign(TCellDoubleArr&obj);
    //
    virtual void construct(int n=1);
    //
    virtual int GetTypeN();
    virtual int GetActiveN();
    virtual void SetActiveN(int N);
    virtual int GetLength();
    virtual void SetLength(int L);
    //
    virtual double GetDoubleVal();
    virtual float GetFloatVal();
    virtual int GetIntVal();
    virtual bool GetBoolVal();
    virtual QString ToString();
    //
    virtual double GetDoubleValN(int N);
    virtual float GetFloatValN(int N);
    virtual int GetIntValN(int N);
    virtual bool GetBoolValN(int N);
    virtual QString ToStringN(int N);
    //
    virtual void SetByValDouble(double val);
    virtual void SetByValFloat(float val);
    virtual void SetByValInt(int val);
    virtual void SetByValBool(bool val);
    virtual void SetByValString(QString val);
    //
    virtual void SetByValDoubleN(double val, int N);
    virtual void SetByValFloatN(float val, int N);
    virtual void SetByValIntN(int val, int N);
    virtual void SetByValBoolN(bool val, int N);
    virtual void SetByValStringN(QString val, int N);
    //
    virtual void SetVal(double val);
    virtual void SetVal(int val);
    virtual void SetVal(bool val);
    virtual void SetVal(QString val);
    //
    virtual void SetValN(double val, int N);
    virtual void SetValN(int val, int N);
    virtual void SetValN(bool val, int N);
    virtual void SetValN(QString val, int N);
    //
    virtual void SetByArrDouble(double* val, int Q);
    virtual void SetByArrFloat(float*val, int Q);
    virtual void SetByArrInt(int* val, int Q);
    virtual void SetByArrBool(bool* val, int Q);
    virtual void SetByArrString(QString*val, int Q);
    //
    virtual void SetByArr(double* val, int Q);
    virtual void SetByArr(int* val, int Q);
    virtual void SetByArr(bool* val, int Q);
    virtual void SetByArr(QString* val, int Q);
    //
    virtual void AddOrInsDoubleVal(double val, int N);
    virtual void AddOrInsFloatVal(float val, int N);
    virtual void AddOrInsIntVal(int val, int N);
    virtual void AddOrInsBoolVal(bool val, int N);
    virtual void AddOrInsStringVal(QString val, int N);
    //
    virtual void DelValN(int N);
    //
    virtual void GetDoubleArr(double*&Arr,  int&QItems);
    virtual void GetFloatArr(float*&Arr, int&QItems);
    virtual void GetIntArr(int*&Arr, int&QItems);
    virtual void GetBoolArr(bool*&Arr, int&QItems);
    virtual void ToStringArr(QString*&Arr, int&QItems);
    //
    virtual void SetNameN(QString name, int N);
    virtual void SetName1(QString name);
    virtual void SetName2(QString name);
    //virtual void SetName3(QString name);
    //virtual void SetNames(QString* Arr, int Q);
    virtual QString GetNameN(int N);
    virtual QString GetName1();
    virtual QString GetName2();
    //virtual QString GetName3();
    //virtual void GetNames(QString*&Arr, int&QItems);
    //virtual int GetLengthOfNamesList();
    //
    virtual void SetItems(QString*items, int Q, int ActiveN=1);
    virtual void GetItems(QString*&items, int&Q);
    virtual void SetItem(QString item, int itemN=-1);
    virtual void InsItem(QString item, int itemN=-1);
    virtual void AddItem(QString item);
    virtual void DelItem(int itemN=-1);
    virtual QString GetItem(int itemN=-1);
    virtual int GetLengthOfItemsList();
    //
    //
};//cl TCellDBRowHeader


    class DataCell
    {
        //TDataCell* cell;
        public:
        TDataCell* cell;
        //
        DataCell();
        //
        DataCell(double val);
        DataCell(float val);
        DataCell(int val);
        DataCell(bool val);
        DataCell(QString val);
        DataCell(double* arr, int Length);
        DataCell(float* arr, int Length);
        DataCell(int* arr, int Length);
        DataCell(bool* arr, int Length);
        DataCell(QString* arr, int Length);
        DataCell(int val, bool ConstNotVar);
        DataCell(int TypeN, int N);
        //DataCell(DataCellTypeInfo TypeInf);
        //DataCell(TypeCell TypeInf);
        DataCell(TypeCell *TypeInf);
        //
        void SetDefault0();
        //
        TDataCell* GetCell();
        //DataCell GetCell();
            //
        //DataCellTypeInfo GetTypeInfo();
        //TypeCell GetTypeInfo();
        TypeCell* GetTypeInfo();
        //void SetTypeAndDefaultValByTypeInf(DataCellTypeInfo TypeInf, bool PreserveVal=false);
        void SetTypeAndDefaultValByTypeInf(TypeCell *TypeInf, bool PreserveVal=false);
        //
        double GetDoubleVal();
        float GetFloatVal();
        int GetIntVal();
        bool GetBoolVal();
        QString ToString();
        //
        void GetDoubleArr(double*&vals, int&count);
        void GetFloatArr(float*&vals, int&count);
        void GetIntArr(int*&vals, int&count);
        void GetBoolArr(bool*&vals, int&count);
        void ToStringArr(QString*&vals, int&count);
        //
        double GetDoubleValN(int N);
        float GetFloatValN(int N);
        int GetIntValN(int N);
        bool GetBoolValN(int N);
        QString ToStringN(int N);
        //
        void SetVal(double val);
        void SetVal(int val);
        void SetVal(bool val);
        void SetVal(QString val);
        //
        void SetValN(double val, int N);
        void SetValN(float val, int N);
        void SetValN(int val, int N);
        void SetValN(bool val, int N);
        void SetValN(QString val, int N);
        //
        int GetTypeN();
        int GetLength();
        int GetActiveN();
        //
        void SetActiveN(int N);
        void SetLength(int Length);
        //
        //void SetTypeN(int TypeN, TableCellAccessConfiguration *cfg);
        void SetTypeN(int TypeN,int Len=1, int PreserveVal=1);
        void SetType(TypeCell *TypeInf);
        //
        void DelValN(int N);
        //
        void AddOrInsDoubleVal(double val, int N);
        void AddOrInsFloatVal(float val, int N);
        void AddOrInsIntVal(int val, int N);
        void AddOrInsBoolVal(bool val, int N);
        void AddOrInsStringVal(QString val, int N);
        //
        void Assign(double val);
        void Assign(float val);
        void Assign(int val);
        void Assign(bool val);
        void Assign(QString val);
        void Assign(double val, int N);
        void Assign(float val, int N);
        void Assign(int val, int N);
        void Assign(bool val, int N);
        void Assign(QString val, int N);
        void Assign(double* val, int count);
        void Assign(float* val, int count);
        void Assign(int* val, int count);
        void Assign(bool* val, int count);
        void Assign(QString* val, int count);
        void Assign(double* val, int count, QString name1, QString name2, QString name3);
        void Assign(QString* val, int count, QString name1, QString name2, QString name3);
        void Assign(double* val, int countItems, QString* names, int countNames);
        void Assign(float* val, int countItems, QString* names, int countNames);
        void Assign(int* val, int countItems, QString* names, int countNames);
        void Assign(QString* val, int countItems, QString* names, int countNames);
        void Assign(TDataCell* obj);
        void Assign(DataCell obj);
        void AssignBy(TDataCell* CellFrom);
        void AssignBy(DataCell obj);
        //
        DataCell& operator=(double val);
        DataCell& operator=(float val);
        DataCell& operator=(int val);
        DataCell& operator=(bool val);
        DataCell& operator=(QString val);

            //
            void SetValAndTypeDouble(double val);
            void SetValAndTypeFloat(float val);
            void SetValAndTypeInt(int val);
            void SetValAndTypeBool(bool val);
            void SetValAndTypeString(QString val);
            void SetArrAndTypeDouble(double* arr, int Length);
            void SetArrAndTypeFloat(float* arr, int Length);
            void SetArrAndTypeInt(int* arr, int Length);
            void SetArrAndTypeBool(bool* arr, int Length);
            void SetArrAndTypeString(QString* arr, int Length);
            void SetValAndTypeUniqueIntNumKeeper(int val);
            //
            void SetByValDouble(double val);
            void SetByValFloat(float val);
            void SetByValInt(int val);
            void SetByValBool(bool val);
            void SetByValString(QString val);
            //
            void SetByValDoubleN(double val, int N);
            void SetByValFloatN(float val, int N);
            void SetByValIntN(int val, int N);
            void SetByValBoolN(bool val, int N);
            void SetByValStringN(QString val, int N);
            //
            void SetByArrDouble(double* val, int Length);
            void SetByArrFloat(float* val, int Length);
            void SetByArrInt(int* val, int Length);
            void SetByArrBool(bool* val, int Length);
            void SetByArrString(QString* val, int Length);
            //
            int GetErstItemNByStringVal(QString val);
            void SetActiveNByStringVal(QString val);
            //
            QString GetNameN(int N);
            QString GetName1();
            QString GetName2();
            //QString GetName3();
            //void GetNames(QString*&Arr, int&QItems);
            //int GetLengthOfNamesList();
            //
            virtual void SetItems(QString*items, int Q, int ActiveN=1);
            virtual void GetItems(QString*&items, int&Q);
            virtual void SetItem(QString item, int itemN=-1);
            virtual void InsItem(QString item, int itemN=-1);
            virtual void AddItem(QString item);
            virtual void DelItem(int itemN=-1);
            virtual QString GetItem(int itemN=-1);
            virtual int GetLengthOfItemsList();
            //
            //
            DataCell& operator +(DataCell& obj);
            //
            /*void SetNameN(string name, int N) { this.cell.SetNameN(name, N); }
            void SetName1(string name) { this.cell.SetName1(name); }
            void SetName2(string name) { this.cell.SetName2(name); }
            void SetName3(string name) { this.cell.SetName3(name); }
            void SetNames(string[] Arr, int Q){this.cell.SetNames(Arr, Q);}
            string GetNameN(int N) { return this.cell.GetNameN(N); }
            string GetName1() { return this.cell.GetName1(); }
            string GetName2() { return this.cell.GetName2(); }
            string GetName3() { return this.cell.GetName3(); }
            void GetNames(ref string[] Arr, ref int QItems){this.cell.GetNames(ref Arr, ref QItems);}
            int GetLengthOfNamesList() { return this.cell.GetLengthOfNamesList();}*/
            //
            DataCell ReturnCopy();
            //void SetFromGridCellValueOnly(DataGridViewCell gridCell, TableReadingTypesParams TypesParams);
        };//cl DataCell


             DataCell operator +(DataCell obj1, DataCell obj2);

#endif // DATACELL_H
