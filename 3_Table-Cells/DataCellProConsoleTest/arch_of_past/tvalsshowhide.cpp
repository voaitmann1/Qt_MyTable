#include "tvalsshowhide.h"

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
