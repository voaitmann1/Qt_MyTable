#include <QCoreApplication>
//
#include "datacell.h"
//#include<stdio.h>
#include<conio.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //
    const char*pch;
    DataCell cell, cell1, cell2;
    QString s;
    std::string sarr;
    //
    double xd=2.2;
    int xi=4;
    QString xs="qt string";
    //
    cell.Assign(5.5);
    s=cell.ToString();
    sarr=s.toStdString();
    //pch=sarr.data();
    pch=sarr.c_str();
    printf("Cell=%s\n",pch);
    //
    cell.Assign("string data");
    s=cell.ToString();
    sarr=s.toStdString();
    pch=sarr.c_str();
    printf("Cell=%s\n",pch);
    //
    printf("assign cell1 by cell\n");
    cell1=cell;
    s=cell1.ToString();
    sarr=s.toStdString();
    pch=sarr.c_str();
    printf("Cell1=%s\n",pch);
    //
    s="string data";
    cell.Assign(s);
    s=cell.ToString();
    sarr=s.toStdString();
    //pch=sarr.data();
    pch=sarr.c_str();
    printf("Cell=%s\n",pch);
    //
    printf("assign cell1 = double val\n");
    cell1=xd;
    s=cell1.ToString();
    sarr=s.toStdString();
    //pch=sarr.data();
    pch=sarr.c_str();
    printf("Cell1=%s\n",pch);
    //
    printf("assign cell1 = int val\n");
    cell1=xi;
    s=cell1.ToString();
    sarr=s.toStdString();
    //pch=sarr.data();
    pch=sarr.c_str();
    printf("Cell1=%s\n",pch);
    //
    printf("assign cell1 = QString val\n");
    cell1=xs;
    s=cell1.ToString();
    sarr=s.toStdString();
    //pch=sarr.data();
    pch=sarr.c_str();
    printf("Cell1=%s\n",pch);
    //
    printf("assign cell by cell1\n");
    cell=cell1;
    s=cell.ToString();
    sarr=s.toStdString();
    //pch=sarr.data();
    pch=sarr.c_str();
    printf("Cell=%s\n",pch);
    //
    //

    //
    //printf("\npress any key to exit\n");
    //getch();

     return a.exec();

}
