#include "mystringlib.h"

//MyStringLib::MyStringLib()
//{
//
//}
//class TStringFormat{
//   public:
//    //
//    //int QBeforeHeader, QBetweenHeaderAndGeneral, QBetweenGeneral, QAfter;
//    //
//    bool HiddenArePartOfWorkSpace;//true
//    //
//    int QSpaceCharsBefore;//0
//    int QPtrCharsBefore;//2
//    int QHiddenPointerCharsBefore;//2
//    int WorkSpace;//
//    int QHiddenPointerCharsAfter;//2
//    int QPtrCharsAfter;//2
//    int QSpaceCharsAfter;//0
//  //
//  QString SpaceBefore,  //nil
//          PointerBefore,  //>>
//          HiddenPointerBefore, //..
//          SpaceAfter, //nil
//          PointerAfter, //<-
//          HiddenPointerAfter;//..
//  //
//  int Alignment_Left1Right2MiddleLeft3MiddleRight4;
//  //
    TStringFormat::TStringFormat(){ SetDefault();}
    void TStringFormat::SetDefault(){
        HiddenArePartOfWorkSpace=true;
        //
        QSpaceCharsBefore=0;
        QPtrCharsBefore=2;
        QHiddenPtrCharsBefore=2;
        WorkSpace=5;
        QHiddenPtrCharsAfter=2;
        QPtrCharsAfter=2;
        QSpaceCharsAfter=0;
        //
        Alignment_Left1Right2MiddleLeft3MiddleRight4=1;
        //
        SpaceBefore="";
        PointerBefore=">>";
        HiddenPtrBefore="..";
        SpaceAfter="";
        PointerAfter="<-";
        HiddenPtrAfter="..";
        OneCharFillLeft="";
        OneCharFillRight=".";
    }
     QString TStringFormat::GetAnyChars(QString orig, int LLim){
         QString s;
         int L1=orig.length();
         if(L1>LLim)s=orig.mid(L1-LLim+1,LLim);
         else if(L1<LLim){
            s=orig;
            for(int i=1; i<=(L1-LLim); i++) s=s+" ";
         }
         //if()
         return s;
     }

    QString TStringFormat::GetLeftPtr(){
        return GetAnyChars(this->PointerBefore, this->QPtrCharsBefore);
    }
    QString TStringFormat::GetRightPtr(){
        return GetAnyChars(this->PointerAfter, this->QPtrCharsAfter);
    }
    QString TStringFormat::GetLeftHiddenPtr(){
        return GetAnyChars(this->HiddenPtrBefore, this->QHiddenPtrCharsBefore);
    }
    QString TStringFormat::GetRightHiddenPtr(){
        return GetAnyChars(this->HiddenPtrAfter, this->QHiddenPtrCharsAfter);
    }
    QString TStringFormat::GetSpaceBefore(){
        return GetAnyChars(this->SpaceBefore, this->QSpaceCharsBefore);
    }
    QString TStringFormat::GetSpaceAfter(){
        return GetAnyChars(this->SpaceAfter, this->QSpaceCharsAfter);
    }
    void TStringFormat::SetMaxLength(int L){
        this->WorkSpace=L-this->QSpaceCharsBefore-this->QPtrCharsBefore-this->QPtrCharsAfter-this->QSpaceCharsAfter;
        if(!this->HiddenArePartOfWorkSpace){
           this->WorkSpace=this->WorkSpace-this->QHiddenPtrCharsBefore-this->QHiddenPtrCharsAfter;
        }
    }
    void TStringFormat::SetWorkSpaceMin(int L){
        this->WorkSpace=L;
    }
    //int TStringFormat::GetWorkspaceMinLength();
    //int TStringFormat::GetShownTextLength();
    int TStringFormat::GetMaxLength(){
        int L;
        L=this->WorkSpace+this->QSpaceCharsBefore+this->QPtrCharsBefore+this->QPtrCharsAfter+this->QSpaceCharsAfter;
        if(!this->HiddenArePartOfWorkSpace){
           L=L+this->QHiddenPtrCharsBefore+this->QHiddenPtrCharsAfter;
        }
        return L;
    }
//};
    //
QString FormatText(QString aText, int Length, int QHiddenLeft, bool IsSelected, TStringFormat*formatExt){
    QString s;
    TStringFormat format;
    QString text;
    int ModeRight_Precise1AlignShort2HideBack3;
    int dL, dLLeft, dLRight, RealWorkspaceL, RightRest, QHiddenRight, SpaceToAlign;
    //format def
    if(formatExt!=NULL) format=(*(formatExt));
    //else default constr
    format.SetMaxLength(Length);
    //
    RightRest=aText.length();//first
    if(QHiddenLeft>0){
        //if(QHiddenLeft<aText.length())text=aText.mid(QHiddenLeft+1,aText.length()-QHiddenLeft);
        RightRest=RightRest-QHiddenLeft;
        if(format.HiddenArePartOfWorkSpace){
            RealWorkspaceL=RealWorkspaceL-format.QHiddenPtrCharsBefore;
        }//else RealWorkspaceL=format.WorkSpace
    }
    if(RightRest<=RealWorkspaceL){
        QHiddenRight=0;
        SpaceToAlign=RealWorkspaceL-RightRest;
    }else{
        SpaceToAlign=0;
        QHiddenRight=RightRest-RealWorkspaceL;//first
        if(format.HiddenArePartOfWorkSpace){
            RealWorkspaceL=RealWorkspaceL-format.QHiddenPtrCharsAfter;
            QHiddenRight+=format.QHiddenPtrCharsAfter;
        }//else RealWorkspaceL=format.WorkSpace
    }
    //1.start
    s="";
    //2.separator
    if(format.QSpaceCharsBefore>0) s=s+format.GetSpaceBefore();
    //3.pointer
    if(format.QPtrCharsBefore>0){
        if(IsSelected){
            s=s+format.GetLeftPtr();
        }else{
            for(int i=1; i<=format.QPtrCharsBefore; i++) s=s+" ";
        }
    }
    //4.Hidden
    if(format.HiddenArePartOfWorkSpace==false || (QHiddenLeft>0 && format.QHiddenPtrCharsBefore>0)){
        if(QHiddenLeft>0) s=s+format.GetLeftHiddenPtr();//ja! so! QHiddenLeft 2x ob may be !=0 if Hidden ne part of WQorkspace
        else{
            for(int i=1; i<=format.QHiddenPtrCharsBefore; i++) s=s+" ";
        }
    }//else Nop;
    //5.text ipse, maybe aligned
    if(QHiddenLeft<=0) text=aText.mid(0, RealWorkspaceL);
    else text=aText.mid(QHiddenLeft+1,RealWorkspaceL);
    if(SpaceToAlign<=0){
        s=s+text;
    }else{//if shorter
        switch(format.Alignment_Left1Right2MiddleLeft3MiddleRight4){
            case 1:
                s=text;
                dLLeft=0;
                dLRight=dL;
                for(int i=1; i<=dLRight; i++){
                    s=s+format.OneCharFillRight.mid(1,1);
                }
            break;
            case 2:
                dLLeft=dL;
                dLRight=0;
                for(int i=1; i<=dLLeft; i++){
                    s=s+format.OneCharFillLeft.mid(1,1);
                }
                s=text;
            break;
            case 3:
                if(dL % 2==0){
                    dLLeft=dL/2;
                    dLRight=dL/2;
                }else{
                    dLLeft=(dL-1)/2;
                    dLRight=dLLeft+1;
                }
                for(int i=1; i<=dLLeft; i++){
                    s=s+format.OneCharFillLeft.mid(1,1);
                }
                s=s+text;
                for(int i=1; i<=dLRight; i++){
                    s=s+format.OneCharFillRight.mid(1,1);
                }
            break;
            case 4:
                if(dL % 2==0){
                    dLLeft=dL/2;
                    dLRight=dL/2;
                }else{
                    dLRight=(dL-1)/2;
                    dLLeft=dLRight+1;
                }
                for(int i=1; i<=dLLeft; i++){
                    s=s+format.OneCharFillLeft.mid(1,1);
                }
                s=s+text;
                for(int i=1; i<=dLRight; i++){
                    s=s+format.OneCharFillRight.mid(1,1);
                }
            break;
        }//switch
    }
    //6.Hidden after
    if(format.HiddenArePartOfWorkSpace==false || (QHiddenRight>0 && format.QHiddenPtrCharsBefore>0)){
        if(QHiddenRight>0) s=s+format.GetRightHiddenPtr();//ja! so! QHiddenLeft 2x ob may be !=0 if Hidden ne part of WQorkspace
        else{
            for(int i=1; i<=format.QHiddenPtrCharsAfter; i++) s=s+" ";
        }
    }//else Nop;
    //7. pointer after
    if(format.QPtrCharsAfter>0) s=s+format.GetRightPtr();
    //8.separator
    if(format.QSpaceCharsAfter>0) s=s+format.GetSpaceAfter();
    //9.separator
    if(format.QSpaceCharsAfter>0) s=s+format.GetSpaceAfter();
    //
    return s;
}
