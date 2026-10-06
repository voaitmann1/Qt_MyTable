#ifndef TVALSSHOWHIDE_H
#define TVALSSHOWHIDE_H


class TValsShowHide{
  public:
    int Show1Hide0;
    bool ConsoleInterface;
 //   QTextBrowser*TxtFld;
    FILE*f;
    //
    TValsShowHide();
    void EnableWriting();
    void DisableWriting();
    void write(char*s);
    void write(QString str);
    void writeln(char*s);
    void writeln(QString str);
};

void writeln(TValsShowHide *VSH, char*s);
void writeln(TValsShowHide *VSH, QString str);

#endif // TVALSSHOWHIDE_H
