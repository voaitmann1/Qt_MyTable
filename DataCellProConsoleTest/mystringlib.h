#ifndef MYSTRINGLIB_H
#define MYSTRINGLIB_H


//class MyStringLib
//{
//public:
//    MyStringLib();
//};

#include"mylib.h"
//#include
//class MyStringLib
//{
//public:
//    MyStringLib();
//};

class TStringFormat{
   public:
    //
    //int QBeforeHeader, QBetweenHeaderAndGeneral, QBetweenGeneral, QAfter;
    //
    bool HiddenArePartOfWorkSpace;//true
    //
    int QSpaceCharsBefore;//0
    int QPtrCharsBefore;//2
    int QHiddenPtrCharsBefore;//2
    int WorkSpace;//
    int QHiddenPtrCharsAfter;//2
    int QPtrCharsAfter;//2
    int QSpaceCharsAfter;//0
    //
    QString SpaceBefore,  //nil
            PointerBefore,  //>>
            HiddenPtrBefore, //..
            SpaceAfter, //nil
            PointerAfter, //<-
            HiddenPtrAfter,//..
            //
            OneCharFillLeft,//" "
            OneCharFillRight;//.
    //
    int Alignment_Left1Right2MiddleLeft3MiddleRight4;
    //
    TStringFormat();
    void SetDefault();
    QString GetAnyChars(QString orig, int LLim);
    QString GetLeftPtr();
    QString GetRightPtr();
    QString GetLeftHiddenPtr();
    QString GetRightHiddenPtr();
    QString GetSpaceBefore();
    QString GetSpaceAfter();
    void SetMaxLength(int L);
    void SetWorkSpaceMin(int L);
    //int GetWorkspaceMinLength();
    //int GetShownTextLength();
    int GetMaxLength();
};
//
QString FormatText_AlignShort(QString aText, int Length, int Alignment_Left1Right2MiddleLeft3MiddleRight4, QString OneCharFillRight=" ", QString OneCharFillLeft=" ", int QHiddenLeft=0);
QString FormatText_CutLong(QString aText, int Length, bool IsSelected=false, int QHiddenLeft=0, TStringFormat*format=NULL);
//
QString FormatText(QString aText, int Length, int QHiddenLeft, bool IsSelected, TStringFormat*formatExt);

#endif // MYSTRINGLIB_H
