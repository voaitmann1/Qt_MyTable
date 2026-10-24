#ifndef MYMATHLIB_H
#define MYMATHLIB_H

#include<math.h>
#include<vector>
//#include"mylib.h"//zB for FloatToSte
//#include"myarraylib.h"
#include<functional>
//#include"array2dlib.h"
//#include"serviceclasses.h"
#include<qstring>

//class MyMathLib
//{
//public:
//    MyMathLib();
//};

//const double _PI=3.1415927;

/*const int MatrixTypeN_P2S=121;
const int MatrixTypeN_P2L=122;
const int MatrixTypeN_P2A=123;
const int MatrixTypeN_V2S=221;
const int MatrixTypeN_V2L=222;
const int MatrixTypeN_V2A=223;
const int MatrixTypeN_P1S=111;
const int MatrixTypeN_P1L=112;
const int MatrixTypeN_P1A=113;
const int MatrixTypeN_V1S=211;
const int MatrixTypeN_V1L=212;
const int MatrixTypeN_V1A=213;
const int MatrixTypeN_Default=MatrixTypeN_V2L;*/

double NaturalPower(double x, int pow);//multypl;y definition iof NaturalPower

class Stats_double{
public:
    double mx, mn, meean, disp, MeanQuadrDev, sum;
    Stats_double();
    void CalcStats(double*x, int Q);
    void CalcStats(int*x, int Q);
};
class Stats_float{
public:
    float mx, mn, meean, disp, MeanQuadrDev, sum;
    Stats_float();
    void CalcStats(float*x, int Q);
    void CalcStats(int*x, int Q);
};
class Stats_int{
public:
    int mx, mn, sum;
    Stats_int();
    void CalcStats(int*x, int Q);
};

class TItersPrecision{
public:
    double precision;
    int MaxQIters;
    int Priority_1ItersQuantity2Precision3And4Or;//Or means precision is wished but only if iterations quantity is no more than given
    TItersPrecision(double precision=1E-6, int MaxQIters=10, int Priority_1ItersQuantity2Precision3And4Or=4);
    bool ContinieIterations(double precision, int QIters)const;
    //
    std::vector<double>GetSectionsBounds(double LB, double HB)const;
    //
    int GetCorrectedQIters(double LB, double HB)const;
    double GetCorrectedStepLength(double LB, double HB)const;
    //
    TItersPrecision GetCorrectedForBounds(double LB, double HB)const;
};

class MathApprox{
public:
    double precision;//=1E-9;
    MathApprox(double precision=0);
    bool ET(double x1, double x2);

    bool GT(double x1, double x2);
    bool LT(double x1, double x2);
    bool NE(double x1, double x2);
    bool GE(double x1, double x2);
    bool LE(double x1, double x2);
    bool isPositive(double x);
    bool isNegative(double x);
    bool isZero(double x);
    bool isNonZero(double x);
};

bool fApprET(double x1, double x2, double precision);
bool fApprGT(double x1, double x2, double precision);
bool fApprLT(double x1, double x2, double precision);
bool fApprNE(double x1, double x2, double precision);
bool fApprGE(double x1, double x2, double precision);
bool fApprLE(double x1, double x2, double precision);
bool fApprPositive(double x, double precision);
bool fApprNegative(double x, double precision);
bool fApprZero(double x, double precision);
bool fApprNonZero(double x, double precision);

struct TPosInSucc{
     bool isLess, isWithin, isGreater;
     int EqualN, lessN;
};

TPosInSucc PosInSucc1(double*X, int Q, double x, double eps=0);
TPosInSucc PosInSucc(std::vector<double>X, double x, double eps=0);

double LinInterp(double*X, double*Y, int Q, double x, double eps=0);
double LinInterp(std::vector<double>X, std::vector<double>Y, double x, double eps=0);
double LinInterp2D(std::vector<std::vector<double>>Y, std::vector<double>Xext, std::vector<double>Xine, double xe, double xi,  double eps=0);

double Integr_Trapez_SimpleByElementsArray(std::vector<double>X, std::vector<double>Y);
double Integr_Trapez_SimpleByElementsArray(double*X, double*Y, int Q);

std::vector<double>GetSectionsBounds(double LB, double HB, int Q, double SectL=0, int SectL1Q2And3Or4=2, bool QOfSectsNotSectsBounds=true);

//void CalcDigits(int num, int digits[], /*int&order=0,*/ int SysBase=10, bool AsInNum=false);
void CalcDigits(int num, int digits[], int&order, int SysBase=10);//, TValsShowHide*vsh=NULL);//, bool AsInNum=false);

double IntPower(double a, int b);
int NaturalPower(int a, int b);

//QString ComplexNumberToString(double ReX, double ImX);

double MyArctan(double x, double y, double eps = 0);
//
void EquationQuadratic(std::vector<double>C, std::vector<double>&ReX, std::vector<double>&ImX);
void EquationQuadratic(double a, double b, double c, std::vector<double>&ReX, std::vector<double>&ImX);
//void EquationQuadratic(double C[], std::vector<double>&ReX, std::vector<double>&ImX);
void EquationQuadratic(double*C, std::vector<double>&ReX, std::vector<double>&ImX);
void EquationQuadratic(double BToA, double CToA, std::vector<double>&ReX, std::vector<double>&ImX);

void EquationCubic(std::vector<double>C, std::vector<double>&ReX, std::vector<double>&ImX);
//void EquationCubic(double C[], std::vector<double>&ReX, std::vector<double>&ImX);
void EquationCubic(double*C, std::vector<double>&ReX, std::vector<double>&ImX);
void EquationCubic(double c3, double c2, double c1, double c0, std::vector<double>&ReX, std::vector<double>&ImX);
void EquationCubic(double C2ToC3, double C1ToC3, double C0ToC3, std::vector<double>&ReX, std::vector<double>&ImX);

int EquationOf4thPower(std::vector<double>C, std::vector<double>&ReX, std::vector<double>&ImX);
//int EquationOf4thPower(double C[], std::vector<double>&ReX, std::vector<double>&ImX);
int EquationOf4thPower(double*C, std::vector<double>&ReX, std::vector<double>&ImX);
int EquationOf4thPower(double C3To4, double C2To4, double C1To4, double C0To4, std::vector<double>&ReX, std::vector<double>&ImX);
int EquationOf4thPower(double c4, double c3, double c2, double c1, double c0, std::vector<double>&ReX, std::vector<double>&ReY);

class TPairOfReOrComplexNum{
public:
    double x, y;
    TPairOfReOrComplexNum(double x, double y);
    double GetRe();
    double GetIm();
    double GetFi();
    double GetR();
};

class PolyEq{
  private:
    std::vector<double> C, ReX, ImX;
    void Generate();
    void CalcSolution();
  public:
    //std::vector<double> C, ReX, ImX;
    //
    PolyEq();
    PolyEq(double*vals, int QVals, bool ByCoefsNotByRealRoots=true);
    PolyEq(const PolyEq&obj);
    ~PolyEq();
    //
    void Assign(const PolyEq&obj);
    //
    PolyEq& operator =(const PolyEq&obj);
    //
    void SetEquationsCoefficientsNsETPowerAndCalcSolution(double*c, int coefsQuantity);
    void GenerateEquationByRealRootsAndCalcSolution(double*ReX, int order);
    void SetEquationAndCalcSolution(double*vals, int QVals, bool ByCoefsNotByRealRoots=true);
    //
    void EquationQuadratic(double a, double b, double c, std::vector<double>&ReX, std::vector<double>&ImX);
    void EquationCubic(double c3, double c2, double c1, double c0, std::vector<double>&ReX, std::vector<double>&ImX);
    int  EquationOf4thPower(double c4, double c3, double c2, double c1, double c0, std::vector<double>&ReX, std::vector<double>&ImX);
    //
    std::vector<double> GetReX();
    std::vector<double> GetImX();
    std::vector<double> GetCoefs();
    void GetRoots(std::vector<double>&ReX, std::vector<double>&ImX);
    void SetOrderAndClear(int order);
    int GetOrder();
    QString EquationToString();
    QString SolutionToString();
};

//---------------------------------------------------------------------------

void LinearApproximation(double*X, double*Y, int Q, double&a, double&b);
void LinearApproximation(const std::vector<double>&X, const std::vector<double>&Y, double&a, double&b);

double arctg2(double x, double y);

bool   CheckIfRowsAreLinearDependent(double *x1, double *x2, int Q, double eps=1E-7);
double CalcHowRowsAreLinearDependent(double *x1, double *x2, int Q, double eps=1E-7);

//void GetSubArrayNs(int Q, int&QReqCalcd, int&preN1, int&preN2, int&ownN1, int&ownN2, int&ForOwnN1, int&ForOwnN2, int&postN1, int&postN2, int FromN=1, int QReqGiven=0, int QDefaultsBefore=0);

//std::vector<double>GetSubArrayOfNums(double*X, int Q,                    int FromN=1, int QReqGiven=0, int QDefaultsBefore=0, double DefaultVal=0);
//std::vector<double>GetSubArrayOfNums(double*X, int Q, double*X2, int Q2, int FromN=1, int QReqGiven=0, int QDefaultsBefore=0, double DefaultVal=0);

//------------------------------------------------------------------------------------------------------

class ComplexNum{
    double re, im;
public:
    ComplexNum(double re=0, double im=0);
    ComplexNum(const ComplexNum&obj);
    void Assign(const ComplexNum&obj);
    ~ComplexNum();
    ComplexNum& operator = (const ComplexNum&obj);
    double SetDecart(double re=0, double im=0);
    double SetPolar(double fi=0, double r=0);
    double GetRe()const;
    double GetIm()const;
    double GetFi()const;
    double GetR()const;
    ComplexNum GetConjugated()const;
    void GetPolar(double&r, double&fi)const;
    void ChangeRe(double val);
    void ChangeIm(double val);
    void ChangeFi(double val);
    void ChangeR(double val);
    //ComplexNum& operator + (const ComplexNum&obj);
    //ComplexNum& operator - (const ComplexNum&obj);
    //ComplexNum& operator * (const ComplexNum&obj);
    //ComplexNum& operator / (const ComplexNum&obj);
    //ComplexNum& operator * (double val);
    ComplexNum& operator += (const ComplexNum&obj);
    ComplexNum& operator -= (const ComplexNum&obj);
    ComplexNum& operator *= (const ComplexNum&obj);
    ComplexNum& operator /= (const ComplexNum&obj);
    ComplexNum& operator *= (double val);
    ComplexNum& operator /= (double val);
    bool operator ==(const ComplexNum&obj);
    bool operator !=(const ComplexNum&obj);
    bool IsConjugated(const ComplexNum&obj);
    bool IsZero(double precis=1E-7);
    QString ToString();
};

ComplexNum operator + (const ComplexNum&x1, const ComplexNum&x2);
ComplexNum operator - (const ComplexNum&x1, const ComplexNum&x2);
ComplexNum operator * (const ComplexNum&x1, const ComplexNum&x2);
ComplexNum operator / (const ComplexNum&x1, const ComplexNum&x2);

//------------------------------------------------------------

//typedef double (*ODEFunc)(int, double, const double*);
typedef std::function<double(int, double, const double*)>ODEFunc;


std::vector<double> RungeSingleStep(int Q, double*y, const std::vector<ODEFunc>&fArray, double h, double t);//, TValsShowHide*vsh=NULL);
std::vector<double> RungeFull(      int Q, double*y, const std::vector<ODEFunc>&fArray, double h, double t0, double t);//, TValsShowHide*vsh=NULL);

void RungeSingleStep_VPP_PrecVal(int n, double*y, const std::vector<ODEFunc>&fArray, double t0, double h);//, TValsShowHide*vsh=NULL);
void RungeSingleStep_VPP_PrecCls(int n, double*y, const std::vector<ODEFunc>&fArray, double t0,  const TItersPrecision&ItersPrecision);//, TValsShowHide*vsh=NULL);
std::vector<double> RungeSingleStep_RSV_PrecCls(int n, double*y, const std::vector<ODEFunc>&fArray, double t0, const TItersPrecision&ItersPrecision);//, TValsShowHide*vsh=NULL);

void RungeFull_VPP_PrecVal(int Q, double*y, const std::vector<ODEFunc>&fArray, double t0, double t2, double h);//, TValsShowHide*vsh=NULL);
void RungeFull_VPP_PrecCls(int Q, double*y, const std::vector<ODEFunc>&fArray, double t0, double t2, const TItersPrecision&ItersPrecision);//, TValsShowHide*vsh=NULL);
std::vector<double> RungeFull_RSV_PrecCls(int Q, double*y, const std::vector<ODEFunc>&fArray, double t0, double t2, const TItersPrecision&ItersPrecision);//, TValsShowHide*vsh=NULL);

//std::vector<double> RungeSingleStep1(int Q, double*y, ODEFunc*fArray1, double h, double t);
//std::vector<double> RungeFull1(      int Q, double*y, ODEFunc*fArray1, double h, double t0, double t);

std::vector<double>PolynomeEqGenerator(double*ReX, int Q);

std::vector<std::vector<int>>ComplexArrayFindConjugated(int Q, double*ReX, double*ImX, double precision=0);

#endif // MYMATHLIB_H
