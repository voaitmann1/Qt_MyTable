#include "numberparse.h"



//NumberParse::NumberParse()
//{

//}



/*
void SetNumberDataNull(  TNumberParts&data){
     data.IntPartAsWritten=0;
     data.FracPartAsWritten=0;//dbl;
     data.OrderAsWritten=0;
     data.MantissaAsMathRules =0;//dbl;
     data.IntPartAsMathRules=0;
     data.FracPartAsMathRules=0;
     data.MantissaAsWritten =0;//dbl;
     data.IntPartWhole=0;
     data.FracPartWhole=0;//dbl;
     data.MantissaWhole=0;//dbl;
     data.Order=0;
     data.NumberHasPositiveSign=true;
     data.OrderHasPositiveSign=true;
     //data.OrderOfIntPart=0;
     //data.OrderOfFracPart=0;
     //data.
}
void WriteNumberParts(TNumberParts data, TValsShowHide*vsh){
    writeln(vsh,"IntPartAsWritten="+IntToStr(data.IntPartAsWritten));
    writeln(vsh,"FracPartAsWritten="+FloatToStr(data.FracPartAsWritten));
    writeln(vsh,"OrderAsWritten="+FloatToStr(data.OrderAsWritten));
    writeln(vsh,"MantissaAsMathRules="+FloatToStr(data.MantissaAsMathRules));
    writeln(vsh,"IntPartAsMathRules="+IntToStr(data.IntPartAsMathRules));
    writeln(vsh,"FracPartAsMathRules="+FloatToStr(data.FracPartAsMathRules));
    writeln(vsh,"MantissaAsWritten="+FloatToStr(data.MantissaAsWritten));
    writeln(vsh,"IntPartWhole="+FloatToStr(data.IntPartWhole));
    writeln(vsh,"FracPartWhole="+FloatToStr(data.FracPartWhole));
    writeln(vsh,"MantissaWhole="+FloatToStr(data.MantissaWhole));
    writeln(vsh,"Order="+IntToStr(data.Order));
    writeln(vsh,"NumberHasPositiveSign="+IntToStr(BoolToInt(data.NumberHasPositiveSign)));
    writeln(vsh,"OrderHasPositiveSign="+IntToStr(BoolToInt(data.OrderHasPositiveSign)));
};
*/
TNumberParts::TNumberParts(){
    this->SetNull();
}
void TNumberParts::SetNull(){
     this->IntPartAsWritten=0;
     this->FracPartAsWritten=0;//dbl;
     this->OrderAsWritten=0;
     this->MantissaAsMathRules =0;//dbl;
     this->IntPartAsMathRules=0;
     this->FracPartAsMathRules=0;
     this->MantissaAsWritten =0;//dbl;
     this->IntPartWhole=0;
     this->FracPartWhole=0;//dbl;
     this->MantissaWhole=0;//dbl;
     this->Order=0;
     this->NumberHasPositiveSign=true;
     this->OrderHasPositiveSign=true;
}
void TNumberParts::ShowText(TValsShowHide*vsh){
    QString s;
    //
//    s.setNum(this->IntPartAsWritten);
//    writeln(vsh,"IntPartAsWritten="+IntToStr(this->IntPartAsWritten));
//    s.setNum(this->FracPartAsWritten);
//    writeln(vsh,"FracPartAsWritten="+FloatToStr(this->FracPartAsWritten));
//    s.setNum(this->OrderAsWritten);
//    writeln(vsh,"OrderAsWritten="+FloatToStr(this->OrderAsWritten));
//    s.setNum(this->MantissaAsMathRules);
//    writeln(vsh,"MantissaAsMathRules="+FloatToStr(this->MantissaAsMathRules));
//    s.setNum(this->IntPartAsMathRules);
//    writeln(vsh,"IntPartAsMathRules="+IntToStr(this->IntPartAsMathRules));
//    s.setNum(this->FracPartAsMathRules);
//    writeln(vsh,"FracPartAsMathRules="+FloatToStr(this->FracPartAsMathRules));
//    s.setNum(this->MantissaAsWritten);
//    writeln(vsh,"MantissaAsWritten="+FloatToStr(this->MantissaAsWritten));
//    s.setNum(this->IntPartWhole);
//    writeln(vsh,"IntPartWhole="+FloatToStr(this->IntPartWhole));
//    s.setNum(this->FracPartWhole);
//    writeln(vsh,"FracPartWhole="+FloatToStr(this->FracPartWhole));
//    s.setNum(this->MantissaWhole);
//    writeln(vsh,"MantissaWhole="+FloatToStr(this->MantissaWhole));
//    s.setNum(this->Order);
//    writeln(vsh,"Order="+IntToStr(this->Order));
//    s.setNum(BoolToInt(this->NumberHasPositiveSign));
//    writeln(vsh,"NumberHasPositiveSign="+IntToStr(BoolToInt(this->NumberHasPositiveSign)));
//    writeln(vsh,"OrderHasPositiveSign="+IntToStr(BoolToInt(this->OrderHasPositiveSign)));
    //
    s.setNum(this->IntPartAsWritten);
    writeln(vsh,"IntPartAsWritten="+s);
    s.setNum(this->FracPartAsWritten);
    writeln(vsh,"FracPartAsWritten="+s);
    s.setNum(this->OrderAsWritten);
    writeln(vsh,"OrderAsWritten="+s);
    s.setNum(this->MantissaAsMathRules);
    writeln(vsh,"MantissaAsMathRules="+s);
    s.setNum(this->IntPartAsMathRules);
    writeln(vsh,"IntPartAsMathRules="+s);
    s.setNum(this->FracPartAsMathRules);
    writeln(vsh,"FracPartAsMathRules="+s);
    s.setNum(this->MantissaAsWritten);
    writeln(vsh,"MantissaAsWritten="+s);
    s.setNum(this->IntPartWhole);
    writeln(vsh,"IntPartWhole="+s);
    s.setNum(this->FracPartWhole);
    writeln(vsh,"FracPartWhole="+s);
    s.setNum(this->MantissaWhole);
    writeln(vsh,"MantissaWhole="+s);
    s.setNum(this->Order);
    writeln(vsh,"Order="+s);
    s.setNum(BoolToInt(this->NumberHasPositiveSign));
    writeln(vsh,"NumberHasPositiveSign="+s);
    s.setNum(BoolToInt(this->OrderHasPositiveSign));
    writeln(vsh,"OrderHasPositiveSign="+s);
};



void IntPartDet(double x, int&ip, double&IntPartFP){
    ip=0;
    IntPartFP=0;
    while(!((IntPartFP<=x)&&((IntPartFP+1)>x))){
        IntPartFP+=1;
        ip++;
    }
}
int IntPart(double x){
    double z=0;
    int ip=0;
    IntPartDet(x, ip, z);
    return ip;
}
TNumberParts SeparateNum(double x, TValsShowHide*vsh, int BaseDec){
    double z=0, x1=fabs(x);//, IntPartF, Mantissa;//, FracPartOfInt, FracPartOfFrac;
    int ord=1;
    TNumberParts NumberData;
    //SetNumberDataNull(NumberData);
    if(x<0){
        NumberData.NumberHasPositiveSign=false;
    }
    if(x1<1){
        NumberData.OrderHasPositiveSign=false;
    }
    if(x1>=1){
        while(z<x1){
            z+=1;
            NumberData.IntPartWhole+=1;
            //NumberData.Order+=1;
        }
        if(z>x1){
            z-=1;
            NumberData.IntPartWhole-=1;
            //NumberData.Order-=1;
        }
        //NumberData.Order=(NumberData.IntPartWhole/BaseDec);
        while(ord<NumberData.IntPartWhole){
            ord*=BaseDec;
            NumberData.Order++;
        }
        if(ord>NumberData.IntPartWhole){
             ord/=BaseDec;
            NumberData.Order--;
        }
        NumberData.FracPartWhole=x1-(double)NumberData.IntPartWhole;
        NumberData.MantissaWhole= (double)NumberData.IntPartWhole+NumberData.FracPartWhole;
        //
        z=x1;
        while(z>BaseDec){
             z/=BaseDec;
        }
        if(z<1){
             z*=BaseDec;
        }
        //
        //NumberData.MantissaAsMathRules=z;
        //NumberData.IntPartAsMathRules=IntPart(z);
        //NumberData.FracPartAsMathRules=z-(double)NumberData.IntPartAsMathRules;
        //NumberData.MantissaAsMathRules=(double)NumberData.IntPartAsMathRules+ NumberData.FracPartAsMathRules;
    }else{  //x1<1
         z=x1;
         while(z<1){
             z*=BaseDec;
             NumberData.Order+=1;
         }
         if(z>BaseDec){
             z/=BaseDec;
             NumberData.Order-=1;
         }
         //NumberData.Order=(NumberData.IntPartWhole/BaseDec);
         NumberData.IntPartWhole=0;
         NumberData.FracPartWhole=x1;
         NumberData.MantissaWhole= x1;//(double)NumberData.IntPartWhole+NumberData.FracPartWhole;
         //
         //NumberData.IntPartAsMathRules=IntPart(z);
         //NumberData.FracPartAsMathRules=z-(double)NumberData.IntPartAsMathRules;
         //NumberData.MantissaAsMathRules=(double)NumberData.IntPartAsMathRules+ NumberData.FracPartAsMathRules;
    }
    NumberData.MantissaAsMathRules=z;
    NumberData.IntPartAsMathRules=IntPart(z);
    NumberData.FracPartAsMathRules=z-(double)NumberData.IntPartAsMathRules;
    //
    NumberData.IntPartAsWritten=NumberData.IntPartWhole;
    NumberData.FracPartAsWritten=NumberData.FracPartWhole;
    NumberData.MantissaAsWritten= NumberData.MantissaWhole;
    NumberData.OrderAsWritten= NumberData.Order;
    return NumberData;
}
void SeparateNum(double x, int&IntPartOfNum, double&FracPartOfNum, int&IntPartOfMant, double&FracPartOfMant, int&Order, int&Sgn, int&OrdSgn, int BaseDec){
    double z=0, x1=fabs(x), IntPartF, Mantissa;//, FracPartOfInt, FracPartOfFrac;
    TNumberParts NumberData;
    //23,45 =23+0,45 = 2,345E+1
    //initio
    IntPartOfNum=0;
    FracPartOfNum=0;
    IntPartOfMant=0;
    FracPartOfMant=0;
    Order=0;
    Sgn=1;
    OrdSgn=1;
    //signs
    if(x==0){
        IntPartOfNum=0;
        FracPartOfNum=0;
        IntPartOfMant=0;
        FracPartOfMant=0;
        Order=0;
        Sgn=1;
        OrdSgn=1;
    }else{
        if(x<0)Sgn=0;    else Sgn=1;
        if(x1<1)OrdSgn=0; else OrdSgn=1;
        //int part of num
        //IntPartOfNum=0;
        //while(!((z<x1)&&((z+1)>x1))){
        //    z=z+1;
        //    IntPartOfNum++;
        //}
        //IntPartF=z;
        IntPartDet(x1,IntPartOfNum,IntPartF);
        //Frac part of num
        FracPartOfNum=x1-IntPartF;
        //FracPartOfNum=x1-IntPartOfNum;
        //Mantissa & order
        Mantissa=x1;//IntPartF;
        Order=0;
        if(OrdSgn==1){
            Mantissa=x1;
            while(Mantissa>=BaseDec){
                Mantissa/=BaseDec;
                Order++;
            }
        }else{ // OrdSgn==0
            while(Mantissa<1){
                Mantissa*=BaseDec;
                Order++;
            }
        }
        //int part of mantissa
        //IntPartOfMant=0;
        //z=0;
        //while(!((z<Mantissa)&&((z+1)>Mantissa))){
        //    z=z+1;
        //    IntPartOfMant++;
        //}
        //IntPartF=z;
        IntPartDet(Mantissa,IntPartOfMant,IntPartF);
        FracPartOfMant=Mantissa-IntPartF;
    }
    //
    NumberData.MantissaWhole=Mantissa;
    NumberData.IntPartWhole= IntPartOfNum;
    NumberData.FracPartWhole= FracPartOfNum;
    NumberData.Order= Order;
}




void IntToDigits(int x, int&Order, int digit[], int BaseDec, bool SortNatural){
    int Sgn, x1=abs(x), Mantissa, y, z, CurDigit;
    if(x<0)Sgn=0;    else Sgn=1;
    Order=0;
    Mantissa=x1;
    Order=0;
    //if(OrdSgn==1){  //always so, becuause it is int
        Mantissa=x1;
        while(Mantissa>=BaseDec){
            Mantissa/=BaseDec;
            Order++;
        }
    //}
    y=x1;
    for(int i=1; i<=Order; i++){
        y/=BaseDec;//int part
        z=y/BaseDec;
        CurDigit=y-z*BaseDec;
        digit[i]=CurDigit;
    }
    digit[0]=x1-(x1/BaseDec)*BaseDec;
    if(SortNatural){
        VectorReverse(digit, Order+1);
    }
}
//new:
void RealToDigits_UsualMantAndOrd(double x, int&Order, int&OrderLength, int mant_digit[], int ord_digit[],  int QAftComma, int BaseDec, bool SortNatural){
    double z;
    int y;//, OrderFictive=0;
    TNumberParts NumberParts;
    NumberParts=SeparateNum(x, NULL, BaseDec);
    z=NumberParts.MantissaAsMathRules*IntPower(BaseDec, QAftComma);
    y=IntPart(z);
    IntToDigits(y, Order, mant_digit, BaseDec);
    IntToDigits(NumberParts.Order, OrderLength, ord_digit, BaseDec);
}
//new:
void RealToDigits_IntAndFracSepar(double x, int&Order, int int_digit[], int frac_digit[], int QAftComma, int BaseDec, bool SortNatural){
    double z;
    int y, OrderFictive=0;
    TNumberParts NumberParts;
    NumberParts=SeparateNum(x, NULL, BaseDec);
    IntToDigits(NumberParts.IntPartWhole, Order, int_digit, BaseDec);
    z=NumberParts.FracPartWhole*IntPower(BaseDec, QAftComma);
    y=IntPart(z);
    IntToDigits(y, OrderFictive, frac_digit, BaseDec);
}
//as was:
/*void RealToDigits_UsualMantAndOrd(double x, int&Order, int&OrderLength, int mant_digit[], int ord_digit[],  int QAftComma, int BaseDec){
    double IntPartR=0, y=x;
    int IntPart=0;
    int IntPartOfNum; double FracPartOfNum; int IntPartOfMant; double FracPartOfMant;  int Sgn; int OrdSgn;
    SeparateNum(x, IntPartOfNum, FracPartOfNum, IntPartOfMant, FracPartOfMant, Order, Sgn, OrdSgn, BaseDec);
    for(int i=1; i<=QAftComma; i++){
        y*=BaseDec;
    }
    IntPartDet(y, IntPart, IntPartR);
    IntToDigits(y, Order, mant_digit, BaseDec);
    IntToDigits(Order, OrderLength, ord_digit, BaseDec);
} */
//as was:
/*
void RealToDigits_IntAndFracSepar(double x, int&Order, int int_digit[], int frac_digit[], int QAftComma, int BaseDec){
    double IntPartR=0, y=x, OrderFictive;
    //int IntPart=0;
    int IntPartOfNum=0; double FracPartOfNum=0; int IntPartOfMant=0; double FracPartOfMant=0;  int Sgn=0; int OrdSgn=0;
    //int NeededPartOfFracPart;
    SeparateNum(x, BaseDec, IntPartOfNum, FracPartOfNum, IntPartOfMant, FracPartOfMant, Order, Sgn, OrdSgn);
    y=FracPartOfNum;
    for(int i=1; i<=QAftComma; i++) y*=BaseDec;
    //IntPartDet(y, IntPart, IntPartR);
    IntToDigits(y, Order, int_digit, BaseDec);
    //
    //NeededPartOfFracPart=IntPart(x);
    OrderFictive=QAftComma;
    IntToDigits(y, Order, int_digit, BaseDec);
}
*/
QString IntToStringSimple(int x, int BaseDec){
    QString s="", c;
    bool SortNatural=true;
    int arr1[50], arr2[50], Order=0, OrderLength=0;
    IntToDigits(x, Order, arr1, BaseDec);
    if(x<0)s="-";
    for(int i=1; i<=Order+1; i++){
        c=DigitSign(arr1[i-1], BaseDec);  //c=DigitSign(arr[i-1], BaseDec);
        c.setNum(arr1[i-1]); // c.setNum(arr[i-1]);
        s=s+c;
    }
    return s;
}

QString RealToString(double x, int Repr_IntAndFrac0_ExpAfOrderLim1_ExpAnyhow2,  int QAftComma, int OrdAfWhichExp, int BaseDec){
    QString rslt, cur, rsltIntAndFrac, rsltExp;
    int digit_mant[80], digit_ord[12], digit_int[50], digit_frac[50];
    int Order=0, OrderLength=0;
    RealToDigits_UsualMantAndOrd(x, Order, OrderLength, digit_mant, digit_ord, QAftComma, BaseDec, true);
    RealToDigits_IntAndFracSepar(x, Order, digit_int, digit_frac, QAftComma, BaseDec, true);
    rsltIntAndFrac="";
    if(x<0) rsltIntAndFrac="-";
    for(int i=1; i<=Order+1; i++){
        cur=IntToStr(digit_int[i-1]);
        rsltIntAndFrac=rsltIntAndFrac+cur;
    }
    rsltIntAndFrac=rsltIntAndFrac+".";
    for(int i=1; i<=QAftComma; i++){
        cur=IntToStr(digit_frac[i-1]);
        rsltIntAndFrac=rsltIntAndFrac+cur;
    }
    rsltExp="";
    if(x<0) rsltExp="-";
    cur=IntToStr(digit_mant[1-1]);
    rsltExp=rsltExp+cur;
    rsltExp=rsltExp+".";
    for(int i=2; i<=QAftComma; i++){
        cur=IntToStr(digit_mant[i-1]);
        rsltExp=rsltExp+cur;
    }
    if(BaseDec<=14)rsltExp=rsltExp+"E";
    else rsltExp=rsltExp+"@";
    if(x<1) rsltExp=rsltExp+"-";
    else if(Order>0) rsltExp=rsltExp+"+";
    for(int i=1; i<=OrderLength+1; i++){
        cur=IntToStr(digit_ord[i-1]);
        rsltExp=rsltExp+cur;
    }
    switch(Repr_IntAndFrac0_ExpAfOrderLim1_ExpAnyhow2){
        case 0:
            rslt=rsltIntAndFrac;
        break;
        case 1:
            if(Order<OrdAfWhichExp) rslt=rsltIntAndFrac;
            else rslt=rsltExp;
        break;
        case 2:
            rslt=rsltExp;
        break;
    }
    return rslt;
}

/*void IntToChars(int x, int BaseDec, int&len, int digit[], char ch[]){
    int Order=0, Sgn, OrdSgn, x1=abs(x), Mantissa, y, n;
    if(x<0)Sgn=0;    else Sgn=1;
    if(x1<1)OrdSgn=0; else OrdSgn=1;
    Mantissa=x1;
    Order=0;
    if(OrdSgn==1){
        Mantissa=x1;
        while(Mantissa>=BaseDec){
            Mantissa/=BaseDec;
            Order++;
        }
    }else{ // OrdSgn==0
        while(Mantissa<1){
            Mantissa*=BaseDec;
            Order++;
        }
    }
    y=x1;
    for(int i=1; i<=Order; i++){
        y/=BaseDec;//int part
        digit[i-1]=x1-(i-1)*BaseDec;
    }
}*/
//void NumToChars(double x, int BaseDec, int QCharsAftCommaRequired, int&len, char UsualNum[], char MantOrd[]){
//    int IntPartOfNum=0; double FracPartOfNum=0; int IntPartOfMant=0; double FracPartOfMant=0; int Order=0; int Sgn=0; int OrdSgn=0;
//    SeparateNum(x, BaseDec, IntPartOfNum, FracPartOfNum, IntPartOfMant, FracPartOfMant, Order, Sgn, OrdSgn);
//    len=1;//"."
//    if(Sgn==1)len++;
//    if(OrdSgn==1)len++;

//}

//-----------------------------------------------------------------------------

char DigitSignCh(int digit, int baseDec){
    char r;
    if(digit==0){
        r='0';
    }
    if(digit==1){
        //if(baseDec!=27)r='0';
        //else r='A';
        if(baseDec==27 || baseDec==8)r='A';
        else r='1';
    }
    if(digit==2){
        //if(baseDec!=27)r='2';
        //else r='B';
        if(baseDec==27 || baseDec==8)r='B';
        else r='2';
    }
    if(digit==3){
        //if(baseDec!=27)r='3';
        //else r='C';
        if(baseDec==27 || baseDec==8)r='C';
        else r='3';
    }
    if(digit==4){
        //if(baseDec!=27)r='4';
        //else r='D';
        if(baseDec==27 || baseDec==8)r='D';
        else r='4';
    }
    if(digit==5){
        //if(baseDec!=27)r='5';
        //else r='E';
        if(baseDec==27 || baseDec==8)r='E';
        else r='5';
    }
    if(digit==6){
        //if(baseDec!=27)r='6';
        //else r='F';
        if(baseDec==27 || baseDec==8)r='F';
        else r='6';
    }
    if(digit==7){
        //if(baseDec!=27)r='7';
        //else r='G';
        if(baseDec==27 || baseDec==8)r='G';
        else r='7';
    }
    if(digit==8){
        //if(baseDec!=27)r='8';
        //else r='H';
        if(baseDec==27 || baseDec==8)r='H';
        else r='8';
    }
    if(digit==9){
        //if(baseDec!=27)r='9';
        //else r='I';
        if(baseDec==27 || baseDec==8)r='I';
        else r='9';
    }
    //
    if(digit==10){
        if(baseDec==27)r='J';
        else r='A';
    }
    if(digit==11){
        if(baseDec==27)r='K';
        else r='B';
    }
    if(digit==12){
        if(baseDec==27)r='L';
        else r='C';
    }
    if(digit==13){
        if(baseDec==27)r='M';
        else r='D';
    }
    if(digit==14){
        if(baseDec==27)r='N';
        else r='E';
    }
    if(digit==15){
        if(baseDec==27)r='O';
        else r='F';
    }
    //
    if(digit==16){
        if(baseDec==27)r='P';
        else r='G';
    }
    if(digit==17){
        if(baseDec==27)r='Q';
        else r='H';
    }
    if(digit==18){
        if(baseDec==27)r='R';
        else r='I';
    }
    if(digit==19){
        if(baseDec==27)r='S';
        else r='J';
    }
    if(digit==20){
        if(baseDec==27)r='T';
        else r='K';
    }
    if(digit==21){
        if(baseDec==27)r='U';
        else r='L';
    }
    if(digit==22){
        if(baseDec==27)r='V';
        else r='M';
    }
    if(digit==23){
        if(baseDec==27)r='W';
        else r='N';
    }
    if(digit==24){
        if(baseDec==27)r='X';
        else r='O';
    }
    if(digit==25){
        if(baseDec==27)r='Y';
        else r='P';
    }
    if(digit==26){
        if(baseDec==27)r='Z';
        else r='Q';
    }
    //
    if(digit==27) r='R';
    if(digit==28) r='S';
    if(digit==29) r='T';
    if(digit==30) r='U';
    if(digit==31) r='V';
    if(digit==32) r='W';
    if(digit==33) r='X';
    if(digit==34) r='Y';
    if(digit==35) r='Z';
    //
    if(digit>=baseDec)r='?';
    //
    return r;
}

QString DigitSign(int digit, int baseDec){
    QString r;
    if(digit==0){
        r="0";
    }
    if(digit==1){
        //if(baseDec!=27)r="0";
        //else r="A";
        if(baseDec==27 || baseDec==8)r="A";
        else r="1";
    }
    if(digit==2){
        //if(baseDec!=27)r="2";
        //else r="B";
        if(baseDec==27 || baseDec==8)r="B";
        else r="2";
    }
    if(digit==3){
        //if(baseDec!=27)r="3";
        //else r="C";
        if(baseDec==27 || baseDec==8)r="C";
        else r="3";
    }
    if(digit==4){
        //if(baseDec!=27)r="4";
        //else r="D";
        if(baseDec==27 || baseDec==8)r="D";
        else r="4";
    }
    if(digit==5){
        //if(baseDec!=27)r="5";
        //else r="E";
        if(baseDec==27 || baseDec==8)r="E";
        else r="5";
    }
    if(digit==6){
        //if(baseDec!=27)r="6";
        //else r="F";
        if(baseDec==27 || baseDec==8)r="F";
        else r="6";
    }
    if(digit==7){
        //if(baseDec!=27)r="7";
        //else r="G";
        if(baseDec==27 || baseDec==8)r="G";
        else r="7";
    }
    if(digit==8){
        //if(baseDec!=27)r="8";
        //else r="H";
        if(baseDec==27 || baseDec==8)r="H";
        else r="8";
    }
    //
    if(digit==9){
        //if(baseDec!=27)r="9";
        //else r="I";
        if(baseDec==27 || baseDec==8)r="I";
        else r="9";
    }
    //
    if(digit==10){
        if(baseDec==27)r="J";
        else r="A";
    }
    if(digit==11){
        if(baseDec==27)r="K";
        else r="B";
    }
    if(digit==12){
        if(baseDec==27)r="L";
        else r="C";
    }
    if(digit==13){
        if(baseDec==27)r="M";
        else r="D";
    }
    if(digit==14){
        if(baseDec==27)r="N";
        else r="E";
    }
    if(digit==15){
        if(baseDec==27)r="O";
        else r="F";
    }
    //
    if(digit==16){
        if(baseDec==27)r="P";
        else r="G";
    }
    if(digit==17){
        if(baseDec==27)r="Q";
        else r="H";
    }
    if(digit==18){
        if(baseDec==27)r="R";
        else r="I";
    }
    if(digit==19){
        if(baseDec==27)r="S";
        else r="J";
    }
    if(digit==20){
        if(baseDec==27)r="T";
        else r="K";
    }
    if(digit==21){
        if(baseDec==27)r="U";
        else r="L";
    }
    if(digit==22){
        if(baseDec==27)r="V";
        else r="M";
    }
    if(digit==23){
        if(baseDec==27)r="W";
        else r="N";
    }
    if(digit==24){
        if(baseDec==27)r="X";
        else r="O";
    }
    if(digit==25){
        if(baseDec==27)r="Y";
        else r="P";
    }
    if(digit==26){
        if(baseDec==27)r="Z";
        else r="Q";
    }
    //
    if(digit==27)r="R";
    if(digit==28)r="S";
    if(digit==29)r="T";
    if(digit==30)r="U";
    if(digit==31)r="V";
    if(digit==32)r="W";
    if(digit==33)r="X";
    if(digit==34)r="Y";
    if(digit==35)r="Z";
    //
    if(digit>=baseDec)r="-1";
    //
    return r;
}

QString ExcelColumnByN(int N){
    QString S;
    int Order=0;
    int digit[3];
    int m=N/27;
    int n=N+m;
    if(n%27==0)n++;
    //S=IntToStr(N)+"=";
    S="";
    if(N<=0)S="?";
    else{
        //void IntToDigits(int x, int&Order, int digit[], int BaseDec=10);
        //IntToDigits(n, 27, Order, digit);
        IntToDigits(n, Order, digit, 27);
        for(int i=Order+1; i>=1; i--){
            S+=DigitSign(digit[i-1], 27);
        }
    }
    return S;
}
int ExcelColN(QString Col){
    int ColN=0;
    QString s;
    bool contin=true;
    while(!(/*ColN>=256 ||*/ ExcelColumnByN(ColN)==Col))ColN++;
    //while(contin){
    //     ColN++;
    //     s=ExcelColumnByN(ColN);
    //     if(s==Col || ColN==256)contin=false;
    //}
    return ColN;
}


int DigitOf(QString s, int baseDec){
    int digit=-1;
    QString r;
    if(s=="0"){
        digit=0;
    }
    if(s=="1"){
        if(baseDec!=27 || baseDec!=8)digit=1;
    }
    if(s=="2"){
        if(baseDec!=27 || baseDec!=8)digit=2;
    }
    if(s=="3"){
        if(baseDec!=27 || baseDec!=8)digit=3;
    }
    if(s=="4"){
        if(baseDec!=27 || baseDec!=8)digit=4;
    }
    if(s=="5"){
        if(baseDec!=27 || baseDec!=8)digit=5;
    }
    if(s=="6"){
        if(baseDec!=27 || baseDec!=8)digit=6;
    }
    if(s=="7"){
        if(baseDec!=27 || baseDec!=8)digit=7;
    }
    if(s=="8"){
        if(baseDec!=27 || baseDec!=8)digit=8;
    }
    //
    if(s=="9"){
        if(baseDec!=27)digit=9;
    }
    //
    if(s=="A"){
        if(baseDec==27|| baseDec==8)digit=1;
        else digit=10;
    }
    if(s=="B"){
        if(baseDec==27|| baseDec==8)digit=2;
        else digit=11;
    }
    if(s=="C"){
        if(baseDec==27|| baseDec==8)digit=3;
        else digit=12;
    }
    if(s=="D"){
        if(baseDec==27|| baseDec==8)digit=4;
        else digit=13;
    }
    if(s=="E"){
        if(baseDec==27|| baseDec==8)digit=5;
        else digit=14;
    }
    if(s=="F"){
        if(baseDec==27|| baseDec==8)digit=6;
        else digit=15;
    }
    if(s=="G"){
        if(baseDec==27|| baseDec==8)digit=7;
        else digit=16;
    }
    if(s=="H"){
        if(baseDec==27|| baseDec==8)digit=8;
        else digit=17;
    }
    //
    if(s=="I"){
        if(baseDec==27)digit=9;
        else digit=18;
    }
    if(s=="J"){
        if(baseDec==27)digit=10;
        else digit=19;
    }
    if(s=="K"){
        if(baseDec==27)digit=11;
        else digit=20;
    }
    if(s=="L"){
        if(baseDec==27)digit=12;
        else digit=21;
    }
    if(s=="M"){
        if(baseDec==27)digit=13;
        else digit=22;
    }
    if(s=="N"){
        if(baseDec==27)digit=14;
        else digit=23;
    }
    if(s=="O"){
        if(baseDec==27)digit=15;
        else digit=24;
    }
    if(s=="P"){
        if(baseDec==27)digit=16;
        else digit=25;
    }
    if(s=="Q"){
        if(baseDec==27)digit=17;
        else digit=26;
    }
    if(s=="R"){
        if(baseDec==27)digit=18;
        else digit=27;
    }
    //
    if(s=="S"){
        if(baseDec==27)digit=19;
        else digit=28;
    }
    if(s=="T"){
        if(baseDec==27)digit=20;
        else digit=29;
    }
    //
    if(s=="U"){
        if(baseDec==27)digit=21;
        else digit=30;
    }
    if(s=="V"){
        if(baseDec==27)digit=22;
        else digit=31;
    }
    if(s=="W"){
        if(baseDec==27)digit=23;
        else digit=32;
    }
    if(s=="X"){
        if(baseDec==27)digit=24;
        else digit=33;
    }
    if(s=="Y"){
        if(baseDec==27)digit=25;
        else digit=34;
    }
    if(s=="Z"){
        if(baseDec==27)digit=26;
        else digit=35;
    }
    //
    if(digit>=baseDec)digit=-1;
    //
    return digit;
}
bool IsDigit(QString s, int baseDec){return (DigitOf(s,baseDec)!=-1);}
void ExcelCellCoordsFromAddress(QString CellSign, int&LineN, int&ColN){
    QString CurStr, ColSign;
    int L=CellSign.length(), d;
    ColSign=""; LineN=0;
    for(int i=1; i<=L; i++){
        CurStr=CellSign.mid(i,1);
        d=DigitOf(CurStr,10);
        if(d==-1)ColSign+=CurStr;
        else LineN=LineN*10+d;
    }
    ColN=ExcelColN(ColSign);
}

//-----------------------------------------------------------------------------

bool IsComma(QString x){
    return (x=="."||x==",");
}
bool IsOrderMark(QString x){
    return (x=="E"||x=="e"||x=="#"||x=="@");
}
bool IsOrderMark(QString x, int BaseDec){
    bool b;
    b=( (x=="#"||x=="@") || ( (x=="E"||x=="e")&&(BaseDec<=14) ) );
    return b;
}
//double NumberParse(QStringx, int FracPartLenReq, int baseDec, bool ZeroForFracNecessary, int&IntPart,  double&FracPart, int&NeededFrac, int&Order, bool&Sign, int&ErstError){
TNumberParts StrNumberParse(QString x, TValsShowHide*vsh, int BaseDec){
    TNumberParts NumParts;
    int NowInt1Frac2Ord3=1, digit=-1, LenOfFrPrt=0;//, FrPrtInt=0;
    QString s, prev_s, qw="E";
    double FrcPrt=0;
    bool OrderIsPositive=true;
    //
    double y;
    bool Sign, ZeroForFracNecessary;
    int ErstError;
    //
    NumParts.IntPartAsWritten=0;
    NumParts.Order=0;
    NumParts.FracPartAsWritten=0;
    NumParts.MantissaAsWritten=0;
    //
    NumParts.MantissaAsMathRules=0;
    NumParts.IntPartAsMathRules=0;
    NumParts.FracPartAsMathRules=0;
    NumParts.MantissaAsWritten=0;
    //
    NumParts.Order=0;//Order=0;
    Sign=true;
    writeln(vsh,x);
    for(int i=1; i<=x.length(); i++){
        if(i>1)prev_s=s;
        s=x.mid(i,1);
        writeln(vsh,s);
        if(IsOrderMark(s,BaseDec)){
            if(NowInt1Frac2Ord3<3){
                NowInt1Frac2Ord3=3;
                writeln(vsh,"now order");
            }else{
                //error
                writeln(vsh,"IncorrectSym");
            }
        }
        if(s=="-"){
           //if(IsOrderMark(prev_s,baseDec)) OrderIsPositive=false; //also gut
           if(NowInt1Frac2Ord3==3 && NumParts.Order==0){
              OrderIsPositive=false;
              writeln(vsh,"Negative Order");
           }else if(i==1){
              Sign=false;
              writeln(vsh,"Negative Number");
           }else{
              // error
              writeln(vsh,"IncorrectSym");
           }
        }
        if(s=="+"){
           //if(IsOrderMark(prev_s,baseDec)) OrderIsPositive=true; //also gut
           if(NowInt1Frac2Ord3==3 && NumParts.Order==0){
              OrderIsPositive=true;
              writeln(vsh,"Positive Order");
           }else if(i==1){
               Sign=true;
               writeln(vsh,"Positive Number");
           }else{
               //error
               writeln(vsh,"IncorrectSym");
           }
        }
        if(s=="."||s==","){
            if(NowInt1Frac2Ord3==1){
                NowInt1Frac2Ord3=2;
                writeln(vsh,"Now Frac part");
            }else{
                ErstError=i;
                writeln(vsh,"IncorrectSym");
            }
            //
            if((i==1||(i==2&&!IsDigit(prev_s)))&&ZeroForFracNecessary){
                ErstError=i;
                writeln(vsh,"IncorrectSym");
            }
        }
        digit=DigitOf(s,BaseDec);
        //writeln(vsh,"Digit="+IntToStr(digit));
        if(digit!=-1){
            writeln(vsh,"Digit="+IntToStr(digit));
            if(NowInt1Frac2Ord3==1){
                NumParts.IntPartAsWritten=NumParts.IntPartAsWritten*BaseDec+digit;//IntPart=IntPart*baseDec+digit;
                writeln(vsh,"NowIntPart="+IntToStr(NumParts.IntPartAsWritten));
            }else if(NowInt1Frac2Ord3==2){
                LenOfFrPrt++;
                //FrPrtInt=FrPrtInt*baseDec+digit;
                NumParts.FracPartAsWritten+=digit*IntPower(BaseDec,-LenOfFrPrt);
                //NumParts.FracPartAsWritten=NumParts.FracPartAsWritten/baseDec+digit;//FrcPrt=FrcPrt/baseDec+digit;
                writeln(vsh,"NowFracPart="+FloatToStr(NumParts.FracPartAsWritten));
            }else if(NowInt1Frac2Ord3==3){
                NumParts.Order=NumParts.Order*BaseDec+digit;
                writeln(vsh,"NowOrder="+IntToStr(NumParts.Order));
            }
        }
    }
    if(!OrderIsPositive)NumParts.Order=-NumParts.Order;
    NumParts.NumberHasPositiveSign=Sign;
    NumParts.OrderHasPositiveSign=OrderIsPositive;
    y=(NumParts.IntPartAsWritten+NumParts.FracPartAsWritten)*IntPower(BaseDec,NumParts.Order);
    if(Sign==false)y=-y;
    //return y;
    return NumParts;
}

double StrToReal(QString s,  TValsShowHide*vsh, int BaseDec){
    double y;
    TNumberParts NumParts;
    NumParts= StrNumberParse(s, vsh, BaseDec);
    bool Sign=(NumParts.NumberHasPositiveSign==true);
    y=(NumParts.IntPartAsMathRules+NumParts.FracPartAsMathRules)*IntPower(BaseDec,NumParts.Order);
    if(Sign==false)y=-y;
    return y;
}
int StrToInt(QString s,  TValsShowHide*vsh, int BaseDec){
    //double y;
    int z;
    TNumberParts NumParts;
    NumParts= StrNumberParse(s, vsh, BaseDec);
    bool Sign=(NumParts.NumberHasPositiveSign==true);
    //y=(NumParts.IntPartAsMathRules+NumParts.FracPartAsMathRules)*IntPower(BaseDec,NumParts.Order);
    //if(Sign==false)y=-y;
    z=NumParts.IntPartAsMathRules*IntPower(BaseDec,NumParts.Order);
    if(Sign==false)z=-z;
    return z;
}

/*QStringRealToString(double x, int Repr_IntAndFrac0_ExpAfOrderLim1_ExpAnyhow2,  int QAftComma, int OrdAfWhichExp, int BaseDec){
    QStringst r;
    int Order=0;
    str="";
    if(x<0)str=str+"-";
    return str;
} */
