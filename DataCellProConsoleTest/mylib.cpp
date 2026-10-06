#include "mylib.h"

void writeln(TValsShowHide*w, /*const*/ char*pch){
    //QString *s=new QString(pch);
    QString s=pch;
    QString qs=QString(pch);
    if(w!=NULL){
        if(w->Show1Hide0!=0){
            if(w->ConsoleInterface)printf("%s\n",pch);
            if(w->f!=NULL)fprintf(w->f,"%s\n",pch);
            //if(w->TxtFld!=NULL)w->TxtFld->append(s);
            //if(w->TxtFld!=NULL)w->TxtFld->append(qs);
        }
    }
    //delete s;
}
void writeln(TValsShowHide*w, std::string s){
    const char*pch=s.c_str();
    QString qs=QString(pch);
    if(w!=NULL){
        if(w->Show1Hide0!=0){
            if(w->ConsoleInterface)printf("%s\n",pch);
            if(w->f!=NULL)fprintf(w->f,"%s\n",pch);
            //if(w->TxtFld!=NULL)w->TxtFld->append(s);
            //if(w->TxtFld!=NULL)w->TxtFld->append(qs);
        }
    }
}
void writeln(TValsShowHide*w, QString s){
   // const char*pch=(s.toStdString()).c_str();
    //std::string ss=s.toStdString();
    //char charr1[400], charr2[400];
    //ss=s.toStdString();
    ////charr1=s.toStdString().c_str();//incomp types
    ////charr2=ss.c_str();//incomp types
    //const char*pch1=ss.c_str();
    std::string ss=s.toStdString();
    const char*pch=ss.c_str();
    if(w!=NULL){
        if(w->Show1Hide0!=0){
            if(w->ConsoleInterface)printf("%s\n",pch);
            if(w->f!=NULL)fprintf(w->f,"%s\n",pch);
            //if(w->TxtFld!=NULL)w->TxtFld->append(s);
        }
    }
}

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
                 (word.mid(2-1, 1)=="e" || word.mid(2-1, 1)=="E")
                 &&
                 (word.mid(3-1, 1)=="s" || word.mid(3-1, 1)=="S")
         ){
             b=true;
         }
    }
    if(L==4){
         if(
                 (word.mid(1-1, 1)=="t" || word.mid(1-1, 1)=="T")
                 &&
                 (word.mid(2-1, 1)=="r" || word.mid(2-1, 1)=="R")
                 &&
                 (word.mid(3-1, 1)=="u" || word.mid(3-1, 1)=="U")
                 &&
                 (word.mid(4-1, 1)=="e" || word.mid(4-1, 1)=="E")
         ){
             b=true;
         }
    }
    return b;
}
bool IsTrueWord(char word[]){
    bool b=false;
    int L=strlen(word);
    if(L==1){
         if(word[1-1]=='1'){
             b=true;
         }
         else if(word[1-1]=='+'){
             b=true;
         }
    }
    if(L==3){
         if(
                 (word[1-1]=='y' || word[1-1]=='Y')
                 &&
                 (word[2-1]=='e' || word[2-1]=='E')
                 &&
                 (word[3-1]=='s' || word[3-1]=='S')
         ){
             b=true;
         }
    }
    if(L==4){
         if(
                 (word[1-1]=='t' || word[1-1]=='T')
                 &&
                 (word[2-1]=='r' || word[2-1]=='"')
                 &&
                 (word[3-1]=='u' || word[3-1]=='U')
                 &&
                 (word[4-1]=='e' || word[4-1]=='E')
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

bool IsFalseWord(char word[]){
    bool b=false;
    int L=strlen(word);
    if(L==1){
         if(word[1-1]=='0'){
             b=true;
         }
         else if(word[1-1]=='-'){
             b=true;
         }
    }
    if(L==2){
         if(
                 (word[1-1]=='n' || word[1-1]=='N')
                 &&
                 (word[2-1]=='o' || word[2-1]=='O')
         ){
             b=true;
         }
    }
    if(L==5){
         if(
                 (word[1-1]=='f' || word[1-1]=='F')
                 &&
                 (word[2-1]=='a' || word[2-1]=='A')
                 &&
                 (word[3-1]=='l' || word[3-1]=='L')
                 &&
                 (word[4-1]=='s' || word[4-1]=='S')
                 &&
                 (word[5-1]=='e' || word[5-1]=='E')
         ){
             b=true;
         }
    }
    return b;
}

std::vector<int>GetListOfNsByRange(int N1, int N2, int L){
    std::vector<int>Ns;
    int N2min;
    if(N1==0)N1=L;
    if(N2==0) N2=N1;
    if(N1<0)N1=L+N1+1;
    if(N2<0) N2=L+N2+1;
    if(L==0) L=N2;
    if(N2<=L)N2min=N2;
    else N2min=L;
    //
    if(N2>0){
       if(N1<0){
           for(int i=1; i<=-N1; i++){
               Ns.push_back(0);
           }
       }
       if(N2>=N1){
           for(int i=N1; i<=N2min; i++){
               Ns.push_back(i);
           }
           for(int i=N2min+1; i<=L; i++){
                Ns.push_back(0);
           }
       }else{
           for(int i=N1; i>=N2; i--){
               Ns.push_back(i);
           }
       }
    }
    return Ns;
}

TValsShowHide::TValsShowHide(){
    DisableWriting();
    this->ConsoleInterface=true;
    this->f=NULL;
}
TValsShowHide::~TValsShowHide(){
    //if(this->f!=NULL)delete this->f;//no need: V ne fy new oper
}
void TValsShowHide::Assign(const TValsShowHide&obj){
    this->ConsoleInterface=obj.ConsoleInterface;
    this->Show1Hide0=obj.Show1Hide0;
    this->f=obj.f;
    //
}
//void TValsShowHide::Assign(const TValsShowHide&obj){
void TValsShowHide::SetShow1Hide0(int Show1Hide0){
    this->Show1Hide0=Show1Hide0;
}
void TValsShowHide::EnableWriting(){
    this->Show1Hide0=1;
}
void TValsShowHide::DisableWriting(){
    this->Show1Hide0=0;
}
