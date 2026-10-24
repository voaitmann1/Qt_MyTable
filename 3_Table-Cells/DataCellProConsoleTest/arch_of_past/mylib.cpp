#include "mylib.h"

#include"qstring.h"

//MyLib::MyLib()
//{

//}


int BoolToInt(bool x){
    int y;
    bool b=BoolValByDefault;
    if(b){
        if(!x) y=0;
        else y=1;
    }else{
        if(x) y=1;
        else y=0;
    }
    return y;
}

int IntOfBool(bool x){return BoolToInt(x);}

bool IntToBool(int x){
    int y;
    bool b=BoolValByDefault;
    if(b){
        y=true;
        if(x==0) y=false;
    }else{
        y=false;
        if(x==1) y=true;
    }
    return y;
}

bool BoolOfInt(int x){return IntToBool(x);}

QString FloatToStr(float x){
    QString str;
    str.setNum(x);
    return str;
}
QString FloatToStr(double x){
    QString str;
    str.setNum(x);
    return str;
}
QString IntToStr(int x){
    QString str;
    str.setNum(x);
    return str;
}

bool IsTrueWord(QString word){
    bool b=false;
    int L=word.length();
    if(L==1){
         if(word.mid(1-1, 1)=="1"){
             b=true;
         }
         else if(word.mid(1-1, 1)=="+"){
             b=true;
         }
    }
    if(L==3){
         if(
                 (word.mid(1-1, 1)=="y" || word.mid(1-1, 1)=="Y")
                 &&
                 (word.mid(1-1, 1)=="e" || word.mid(1-1, 1)=="E")
                 &&
                 (word.mid(1-1, 1)=="s" || word.mid(1-1, 1)=="S")
         ){
             b=true;
         }
    }
    if(L==4){
         if(
                 (word.mid(1-1, 1)=="t" || word.mid(1-1, 1)=="T")
                 &&
                 (word.mid(1-1, 1)=="r" || word.mid(1-1, 1)=="R")
                 &&
                 (word.mid(1-1, 1)=="u" || word.mid(1-1, 1)=="U")
                 &&
                 (word.mid(1-1, 1)=="e" || word.mid(1-1, 1)=="E")
         ){
             b=true;
         }
    }
    return b;
}
bool IsFalseWord(QString word){
    bool b=false;
    int L=word.length();
    if(L==1){
         if(word.mid(1-1, 1)=="0"){
             b=true;
         }
         else if(word.mid(1-1, 1)=="-"){
             b=true;
         }
    }
    if(L==2){
         if(
                 (word.mid(1-1, 1)=="n" || word.mid(1-1, 1)=="N")
                 &&
                 (word.mid(1-1, 1)=="o" || word.mid(1-1, 1)=="O")
         ){
             b=true;
         }
    }
    if(L==5){
         if(
                 (word.mid(1-1, 1)=="f" || word.mid(1-1, 1)=="F")
                 &&
                 (word.mid(1-1, 1)=="a" || word.mid(1-1, 1)=="A")
                 &&
                 (word.mid(1-1, 1)=="l" || word.mid(1-1, 1)=="L")
                 &&
                 (word.mid(1-1, 1)=="s" || word.mid(1-1, 1)=="S")
                 &&
                 (word.mid(1-1, 1)=="e" || word.mid(1-1, 1)=="E")
         ){
             b=true;
         }
    }
    return b;
}

int IsMathFunction(QString word){
    int N=0;
    int L=word.length();
    if(L==4){
       if(
           (word.mid(1-1,1)=="s" || word.mid(1-1,1)=="S")
               &&
           (word.mid(2-1,1)=="i" || word.mid(2-1,1)=="I")
               &&
           (word.mid(3-1,1)=="n" || word.mid(3-1,1)=="N")
               &&
           (word.mid(4-1,1)=="h" || word.mid(4-1,1)=="H")
         )N=21;
         //else r=false;
       if(
           (word.mid(1-1,1)=="c" || word.mid(1-1,1)=="C")
               &&
           (word.mid(2-1,1)=="o" || word.mid(2-1,1)=="O")
               &&
           (word.mid(3-1,1)=="s" || word.mid(3-1,1)=="S")
               &&
           (word.mid(4-1,1)=="h" || word.mid(4-1,1)=="H")
         )N=22;
         //else r=false;
       if(
           (word.mid(1-1,1)=="t" || word.mid(1-1,1)=="T")
               &&
           (word.mid(2-1,1)=="a" || word.mid(2-1,1)=="A")
               &&
           (word.mid(3-1,1)=="n" || word.mid(3-1,1)=="N")
               &&
           (word.mid(4-1,1)=="h" || word.mid(4-1,1)=="H")
         )N=23;
         //else r=false;
       if(
           (word.mid(1-1,1)=="s" || word.mid(1-1,1)=="S")
               &&
           (word.mid(2-1,1)=="i" || word.mid(2-1,1)=="I")
               &&
           (word.mid(3-1,1)=="g" || word.mid(3-1,1)=="G")
               &&
           (word.mid(4-1,1)=="h" || word.mid(4-1,1)=="N")
         )N=24;
         //else r=false;
        if(
            (word.mid(1-1,1)=="a" || word.mid(1-1,1)=="A")
                    &&
            (word.mid(2-1,1)=="s" || word.mid(2-1,1)=="S")
                    &&
            (word.mid(3-1,1)=="i" || word.mid(3-1,1)=="I")
                &&
            (word.mid(4-1,1)=="n" || word.mid(4-1,1)=="N")
           )N=24;
              //else r=false;
        if(
            (word.mid(1-1,1)=="a" || word.mid(1-1,1)=="A")
                &&
            (word.mid(2-1,1)=="c" || word.mid(2-1,1)=="C")
                &&
            (word.mid(3-1,1)=="o" || word.mid(3-1,1)=="O")
                &&
             (word.mid(4-1,1)=="s" || word.mid(4-1,1)=="S")
           )N=24;
              //else r=false;
        if(
            (word.mid(1-1,1)=="a" || word.mid(1-1,1)=="A")
                &&
            (word.mid(2-1,1)=="t" || word.mid(2-1,1)=="T")
                &&
            (word.mid(3-1,1)=="a" || word.mid(3-1,1)=="A")
                &&
            (word.mid(4-1,1)=="n" || word.mid(4-1,1)=="N")
           )N=24;
           //else r=false;
        if(
            (word.mid(1-1,1)=="a" || word.mid(1-1,1)=="A")
                &&
            (word.mid(2-1,1)=="c" || word.mid(2-1,1)=="C")
                &&
            (word.mid(3-1,1)=="t" || word.mid(3-1,1)=="T")
                &&
            (word.mid(4-1,1)=="g" || word.mid(4-1,1)=="G")
           )N=24;
           //else r=false;
        if(
            (word.mid(1-1,1)=="a" || word.mid(1-1,1)=="A")
                &&
            (word.mid(2-1,1)=="c" || word.mid(2-1,1)=="C")
                &&
            (word.mid(3-1,1)=="t" || word.mid(3-1,1)=="T")
                &&
            (word.mid(4-1,1)=="h" || word.mid(4-1,1)=="H")
           )N=24;
           //else r=false;
        if(
            (word.mid(1-1,1)=="f" || word.mid(1-1,1)=="F")
                &&
            (word.mid(2-1,1)=="a" || word.mid(2-1,1)=="A")
                &&
            (word.mid(3-1,1)=="c" || word.mid(3-1,1)=="C")
                &&
            (word.mid(4-1,1)=="t" || word.mid(4-1,1)=="T")
           )N=24;
           //else r=false;
        if(
            (word.mid(1-1,1)=="f" || word.mid(1-1,1)=="F")
                &&
            (word.mid(2-1,1)=="r" || word.mid(2-1,1)=="R")
                &&
            (word.mid(3-1,1)=="a" || word.mid(3-1,1)=="A")
                &&
            (word.mid(4-1,1)=="c" || word.mid(4-1,1)=="C")
           )N=24;
           //else r=false;
        if(
            (word.mid(1-1,1)=="m" || word.mid(1-1,1)=="M")
                &&
            (word.mid(2-1,1)=="e" || word.mid(2-1,1)=="E")
                &&
            (word.mid(3-1,1)=="a" || word.mid(3-1,1)=="A")
                &&
            (word.mid(4-1,1)=="n" || word.mid(4-1,1)=="N")
           )N=24;
           //else r=false;
        if(
            (word.mid(1-1,1)=="r" || word.mid(1-1,1)=="R")
                &&
            (word.mid(2-1,1)=="o" || word.mid(2-1,1)=="O")
                &&
            (word.mid(3-1,1)=="o" || word.mid(3-1,1)=="O")
                &&
            (word.mid(4-1,1)=="t" || word.mid(4-1,1)=="T")
           )N=24;
           //else r=false;
        if(
            (word.mid(1-1,1)=="s" || word.mid(1-1,1)=="S")
                &&
            (word.mid(2-1,1)=="q" || word.mid(2-1,1)=="Q")
                &&
            (word.mid(3-1,1)=="r" || word.mid(3-1,1)=="R")
                &&
            (word.mid(4-1,1)=="t" || word.mid(4-1,1)=="T")
           )N=24;
           //else r=false;
        if(
            (word.mid(1-1,1)=="r" || word.mid(1-1,1)=="R")
                &&
            (word.mid(2-1,1)=="e" || word.mid(2-1,1)=="E")
                &&
            (word.mid(3-1,1)=="s" || word.mid(3-1,1)=="S")
                &&
            (word.mid(4-1,1)=="t" || word.mid(4-1,1)=="T")
           )N=24;
           //else r=false;
    }
    if(L==3){
       if(
           (word.mid(1-1,1)=="s" || word.mid(1-1,1)=="S")
               &&
           (word.mid(2-1,1)=="i" || word.mid(2-1,1)=="I")
               &&
           (word.mid(3-1,1)=="n" || word.mid(3-1,1)=="N")
         )N=10;
         //else r=false;
       if(
            (word.mid(1-1,1)=="c" || word.mid(1-1,1)=="C")
                &&
            (word.mid(2-1,1)=="o" || word.mid(2-1,1)=="O")
                &&
            (word.mid(3-1,1)=="s" || word.mid(3-1,1)=="S")
          )N=11;
          //else r=false;
        if(
            (word.mid(1-1,1)=="t" || word.mid(1-1,1)=="T")
                &&
            (word.mid(2-1,1)=="a" || word.mid(2-1,1)=="A")
                &&
            (word.mid(3-1,1)=="n" || word.mid(3-1,1)=="N")
          )N=12;
          //else r=false;
        if(
            (word.mid(1-1,1)=="c" || word.mid(1-1,1)=="C")
                &&
            (word.mid(2-1,1)=="t" || word.mid(2-1,1)=="T")
                &&
            (word.mid(3-1,1)=="g" || word.mid(3-1,1)=="G")
          )N=13;
        if(
            (word.mid(1-1,1)=="a" || word.mid(1-1,1)=="A")
                &&
            (word.mid(2-1,1)=="t" || word.mid(2-1,1)=="T")
                &&
            (word.mid(3-1,1)=="g" || word.mid(3-1,1)=="G")
          )N=13;
          //else r=false;
        if(
            (word.mid(1-1,1)=="e" || word.mid(1-1,1)=="E")
                &&
            (word.mid(2-1,1)=="x" || word.mid(2-1,1)=="X")
                &&
            (word.mid(3-1,1)=="p" || word.mid(3-1,1)=="P")
          )N=13;
          //else r=false;
        if(
            (word.mid(1-1,1)=="l" || word.mid(1-1,1)=="L")
                &&
            (word.mid(2-1,1)=="o" || word.mid(2-1,1)=="O")
                &&
            (word.mid(3-1,1)=="g" || word.mid(3-1,1)=="G")
          )N=13;
          //else r=false;
        if(
            (word.mid(1-1,1)=="c" || word.mid(1-1,1)=="C")
                &&
            (word.mid(2-1,1)=="t" || word.mid(2-1,1)=="T")
                &&
            (word.mid(3-1,1)=="h" || word.mid(3-1,1)=="H")
          )N=13;
          //else r=false;
        if(
            (word.mid(1-1,1)=="a" || word.mid(1-1,1)=="A")
                &&
            (word.mid(2-1,1)=="s" || word.mid(2-1,1)=="S")
                &&
            (word.mid(3-1,1)=="h" || word.mid(3-1,1)=="H")
          )N=13;
          //else r=false;
        if(
            (word.mid(1-1,1)=="a" || word.mid(1-1,1)=="A")
                &&
            (word.mid(2-1,1)=="c" || word.mid(2-1,1)=="c")
                &&
            (word.mid(3-1,1)=="h" || word.mid(3-1,1)=="H")
          )N=13;
          //else r=false;
        if(
            (word.mid(1-1,1)=="a" || word.mid(1-1,1)=="A")
                &&
            (word.mid(2-1,1)=="t" || word.mid(2-1,1)=="T")
                &&
            (word.mid(3-1,1)=="h" || word.mid(3-1,1)=="H")
          )N=13;
          //else r=false;
        if(
            (word.mid(1-1,1)=="p" || word.mid(1-1,1)=="P")
                &&
            (word.mid(2-1,1)=="o" || word.mid(2-1,1)=="O")
                &&
            (word.mid(3-1,1)=="w" || word.mid(3-1,1)=="W")
          )N=13;
          //else r=false;
        if(
            (word.mid(1-1,1)=="s" || word.mid(1-1,1)=="S")
                &&
            (word.mid(2-1,1)=="q" || word.mid(2-1,1)=="Q")
                &&
            (word.mid(3-1,1)=="r" || word.mid(3-1,1)=="R")
          )N=13;
          //else r=false;
        if(
            (word.mid(1-1,1)=="a" || word.mid(1-1,1)=="A")
                &&
            (word.mid(2-1,1)=="b" || word.mid(2-1,1)=="B")
                &&
            (word.mid(3-1,1)=="s" || word.mid(3-1,1)=="S")
          )N=13;
          //else r=false;
        if(
            (word.mid(1-1,1)=="i" || word.mid(1-1,1)=="I")
                &&
            (word.mid(2-1,1)=="n" || word.mid(2-1,1)=="N")
                &&
            (word.mid(3-1,1)=="t" || word.mid(3-1,1)=="T")
          )N=13;
          //else r=false;
        if(
            (word.mid(1-1,1)=="m" || word.mid(1-1,1)=="M")
                &&
            (word.mid(2-1,1)=="i" || word.mid(2-1,1)=="I")
                &&
            (word.mid(3-1,1)=="n" || word.mid(3-1,1)=="N")
          )N=13;
          //else r=false;
        if(
            (word.mid(1-1,1)=="m" || word.mid(1-1,1)=="M")
                &&
            (word.mid(2-1,1)=="a" || word.mid(2-1,1)=="A")
                &&
            (word.mid(3-1,1)=="x" || word.mid(3-1,1)=="X")
          )N=13;
          //else r=false;
        if(
            (word.mid(1-1,1)=="a" || word.mid(1-1,1)=="A")
                &&
            (word.mid(2-1,1)=="v" || word.mid(2-1,1)=="V")
                &&
            (word.mid(3-1,1)=="e" || word.mid(3-1,1)=="E")
          )N=13;
          //else r=false;
    }
    if(L==2){
        if(
            (word.mid(1-1,1)=="l" || word.mid(1-1,1)=="L")
                &&
            (word.mid(2-1,1)=="g" || word.mid(2-1,1)=="G")
          )N=11;
         //else r=false;
        if(
            (word.mid(1-1,1)=="l" || word.mid(1-1,1)=="L")
                &&
            (word.mid(2-1,1)=="n" || word.mid(2-1,1)=="N")
          )N=11;
         //else r=false;
        if(
            (word.mid(1-1,1)=="s" || word.mid(1-1,1)=="S")
                &&
            (word.mid(2-1,1)=="h" || word.mid(2-1,1)=="H")
          )N=11;
         //else r=false;
        if(
            (word.mid(1-1,1)=="c" || word.mid(1-1,1)=="C")
                &&
            (word.mid(2-1,1)=="h" || word.mid(2-1,1)=="H")
          )N=11;
         //else r=false;
        if(
            (word.mid(1-1,1)=="t" || word.mid(1-1,1)=="T")
                &&
            (word.mid(2-1,1)=="h" || word.mid(2-1,1)=="H")
          )N=11;
         //else r=false;
        if(
            (word.mid(1-1,1)=="g" || word.mid(1-1,1)=="G")
                &&
            (word.mid(2-1,1)=="t" || word.mid(2-1,1)=="T")
          )N=11;
         //else r=false;
        if(
            (word.mid(1-1,1)=="g" || word.mid(1-1,1)=="G")
                &&
            (word.mid(2-1,1)=="e" || word.mid(2-1,1)=="E")
          )N=11;
         //else r=false;
        if(
            (word.mid(1-1,1)=="l" || word.mid(1-1,1)=="L")
                &&
            (word.mid(2-1,1)=="t" || word.mid(2-1,1)=="T")
          )N=11;
         //else r=false;
        if(
            (word.mid(1-1,1)=="l" || word.mid(1-1,1)=="L")
                &&
            (word.mid(2-1,1)=="e" || word.mid(2-1,1)=="E")
          )N=11;
         //else r=false;
        if(
            (word.mid(1-1,1)=="e" || word.mid(1-1,1)=="E")
                &&
            (word.mid(2-1,1)=="t" || word.mid(2-1,1)=="T")
          )N=11;
         //else r=false;
        if(
            (word.mid(1-1,1)=="e" || word.mid(1-1,1)=="E")
                &&
            (word.mid(2-1,1)=="q" || word.mid(2-1,1)=="Q")
          )N=11;
         //else r=false;
        if(
            (word.mid(1-1,1)=="n" || word.mid(1-1,1)=="N")
                &&
            (word.mid(2-1,1)=="e" || word.mid(2-1,1)=="E")
          )N=11;
         //else r=false;
    }
    if(L==1){
        if(
            (word.mid(1-1,1)=="!" || word.mid(1-1,1)=="!")
          )N=11;
    }
    return N;
}



char*ReadLine(FILE*f){
    int CountLength=0;
    char ch, ChArr[200], *ChPtr=NULL;
    do{
        fscanf(f,"%c", &ch);
        //printf("%c",ch);
        if((ch!='\n')&&(ch!='\0')&&!feof(f)){
            CountLength++;
            ChArr[CountLength-1]=ch;
        }
    }while((ch!='\n')&&(ch!='\0')&&!feof(f)/*&&(ch!='@')*/);
    ChArr[CountLength-1+1]='\0';
    //if(CountLength!='\0')ChPtr=ChArr;
    //printf("\n");
    if(CountLength!=0)ChPtr=ChArr;
    return ChPtr;
}

//char*ReadLine(FILE*f, int Show1Hide0, bool ConsoleInterface, TMemo*M){
//    int CountLength=0;
//    char ch, ChArr[200], *ChPtr=NULL, ChArrSngl[5];
//    if(Show1Hide0){
//        if(ConsoleInterface)printf("ReadLine starts working\n");
//        if(M!=NULL)M->Lines->Add("ReadLine starts working");
//    }
//    do{
//        fscanf(f,"%c", &ch);

//        if((ch!='\n')&&(ch!='\0')&&!feof(f)){
//            CountLength++;
//            ChArr[CountLength-1]=ch;
//            if(Show1Hide0){
//                if(ConsoleInterface)printf("%c",ch);
//                if(M!=NULL){
//                    ChArrSngl[0]=ch; ChArrSngl[1]='\0';
//                    M->Lines->Add(AnsiString(ChArrSngl));
//                }
//            }
//        }
//        else{
//           if(ch=='\n'){
//               if(Show1Hide0){
//                   if(ConsoleInterface){
//                        printf("\n");
//                        printf("%s","\\n");
//                   }
//                   if(M!=NULL){
//                       ChArrSngl[0]='\\'; ChArrSngl[1]='n';   ChArrSngl[1]='\0';
//                       M->Lines->Add(AnsiString(ChArrSngl));
//                   }
//               }
//           }
//           if(ch=='\0'){
//               if(Show1Hide0){
//                   if(ConsoleInterface){
//                        printf("\n");
//                        printf("%s","\\0");
//                   }
//                   if(M!=NULL){
//                       ChArrSngl[0]='\\'; ChArrSngl[1]='0';   ChArrSngl[1]='\0';
//                       M->Lines->Add(AnsiString(ChArrSngl));
//                   }
//               }
//           }
//           if(feof(f)){
//                if(Show1Hide0){
//                   if(ConsoleInterface){
//                        printf("\n");
//                        printf("End of file reached");
//                   }
//                   if(M!=NULL){
//                       strcpy(ChArrSngl,"EOF\0");
//                       M->Lines->Add(AnsiString(ChArrSngl));
//                   }
//               }
//           }
//        }
//    }while((ch!='\n')&&(ch!='\0')&&!feof(f)/*&&(ch!='@')*/);
//    ChArr[CountLength-1+1]='\0';
//    //if(CountLength!='\0')ChPtr=ChArr;
//    //printf("\n");
//    if(CountLength!=0)ChPtr=ChArr;
//    if(Show1Hide0){
//        if(ConsoleInterface)printf("ReadLine finishes working\n");
//        if(M!=NULL)M->Lines->Add("ReadLine finishes working");
//    }
//    return ChPtr;
//}

int CharPtrToArr(char*ptr, char Arr[]){
    int count=0, SignificantLength=0;
    char cur;
    do{
        count++;
        cur=(*(ptr+count-1));
        //printf("%c",cur);
        Arr[count-1]=cur;
        if((cur!='\0')&&(cur!='\n')){
            SignificantLength++;
        }
    }while((cur!='\0')&&(cur!='\n'));
    //printf("assigning finished\n");
    return SignificantLength;
}

double ReadLineAsRealNum(FILE*f){
    double x;
    fscanf(f,"%f\n",&x);
    return x;
}
double ReadLineAsDouble(FILE*f){
    double x;
    fscanf(f,"%fl\n",&x);
    return x;
}
float ReadLineAsFloat(FILE*f){
    double x;
    fscanf(f,"%f\n",&x);
    return x;
}
float ReadLineAsInt(FILE*f){
    double x;
    fscanf(f,"%d\n",&x);
    return x;
}

//------------------------------------------------------------------------------------

/*
TValsShowHide::TValsShowHide(){
    Show1Hide0=0;
    ConsoleInterface=false;
    //TxtFld=NULL;
    //G=NULL; //(reserved)
    f=NULL;
}
void TValsShowHide::EnableWriting(){Show1Hide0=1;}
void TValsShowHide::DisableWriting(){Show1Hide0=0;}


void TValsShowHide::write(char*s){
    //char cta[255];
    //strcpy(cta,s);
        if(Show1Hide0==1){
            //if(ConsoleInterface) printf(s);
            if(ConsoleInterface) printf("%s",s);
            //if(TxtFld!=NULL) TxtFld->append(QString(s));
            if(f!=NULL) fprintf(f,"%s",s);
        }
}

void TValsShowHide::write(QString str){
    //char cta[255];
    //strcpy(cta,s);
    const char*pch=str.toStdString().c_str();
        if(Show1Hide0==1){
            //if(ConsoleInterface) printf(str.c_str());
            if(ConsoleInterface) printf("%s",pch);
            //if(TxtFld!=NULL) TxtFld->append(str);
            if(f!=NULL) fprintf(f,"%s",pch);
        }
}

void TValsShowHide::writeln(char*s){
    //char cta[255];
    //strcpy(cta,s);
        if(Show1Hide0==1){
            if(ConsoleInterface) printf("%s\n",s);
            //if(TxtFld!=NULL) TxtFld->append(QString(s));
            if(f!=NULL) fprintf(f,"%s\n",s);
        }
}

void TValsShowHide::writeln(QString str){
    //char cta[255];
    //strcpy(cta,s);
    const char*pch=str.toStdString().c_str();
        if(Show1Hide0==1){
            if(ConsoleInterface) printf("%s\n",pch);
            //if(TxtFld!=NULL) TxtFld->append(str);
            if(f!=NULL) fprintf(f,"%s\n",pch);
        }
}
*/
//
//
/*
void writeln(TValsShowHide*w,char*pch){
    //QString *s=new QString(pch);
    QString s=pch;
    if(w!=NULL){
        if(w->Show1Hide0!=0){
            if(w->ConsoleInterface)printf("%s\n",pch);
            if(w->f!=NULL)fprintf(w->f,"%s\n",pch);
            //if(w->TxtFld!=NULL)w->TxtFld->append(s);
        }
    }
    //delete s;
}
void writeln(TValsShowHide*w, QString s){
    const char*pch=s.toStdString().c_str();
    if(w!=NULL){
        if(w->Show1Hide0!=0){
            if(w->ConsoleInterface)printf("%s\n",pch);
            if(w->f!=NULL)fprintf(w->f,"%s\n",pch);
            //if(w->TxtFld!=NULL)w->TxtFld->append(s);
        }
    }
}
*/


