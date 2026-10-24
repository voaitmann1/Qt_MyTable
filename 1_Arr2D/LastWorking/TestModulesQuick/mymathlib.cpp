#include "mymathlib.h"

//MyMathLib::MyMathLib()

//class Stats_double{
//public:
//    double mx, mn, meean, disp, MeanQuadrDev;
    Stats_double::Stats_double(){
       mx=0; mn=0; meean=0; disp=0; MeanQuadrDev=0; sum=0;
    }

    void Stats_double::CalcStats(double*x, int Q){
        sum=0;
        for(int i=1; i<=Q; i++){
            if(i==1 || (i>1 && mx>x[i-1])){
                mx=x[i-1];
            }
            if(i==1 || (i>1 && mn<x[i-1])){
                mn=x[i-1];
            }
            sum+=x[i-1];
        }
    }

    void Stats_double::CalcStats(int*x, int Q){

    }

//};
//class Stats_float{
//public:
//    float mx, mn, meean, disp, MeanQuadrDev;
    Stats_float::Stats_float(){
       mx=0; mn=0; meean=0; disp=0; MeanQuadrDev=0; sum=0;
    }
    void Stats_float::CalcStats(float*x, int Q){
        sum=0;
        for(int i=1; i<=Q; i++){
            if(i==1 || (i>1 && mx>x[i-1])){
                mx=x[i-1];
            }
            if(i==1 || (i>1 && mn<x[i-1])){
                mn=x[i-1];
            }
            sum+=x[i-1];
        }
    }
    void Stats_float::CalcStats(int*x, int Q){

    }
//};
//class Stats_int{
//public:
//    int mx, mn;
    Stats_int::Stats_int(){
       mx=0; mn=0; //meean=0; disp=0; MeanQuadrDev=0;
       sum=0;
    }
    void Stats_int::CalcStats(int*x, int Q){
        sum=0;
        for(int i=1; i<=Q; i++){
            if(i==1 || (i>1 && mx>x[i-1])){
                mx=x[i-1];
            }
            if(i==1 || (i>1 && mn<x[i-1])){
                mn=x[i-1];
            }
            sum+=x[i-1];
        }
    }
//};

double NaturalPower(double x, int pow){
    double y=1;
    if(pow>0){
        for(int i=1; i<=pow; i++){
            y*=x;
        }
    }else if(pow<0){
        for(int i=1; i<=-pow; i++){
            y/=x;
        }
    }
    return y;
}

TPosInSucc PosInSucc1(double*X, int Q, double x, double eps){
    TPosInSucc pos;
    MathApprox appr(eps);
    pos.isLess=false;
    pos.isGreater=false;
    pos.isWithin-false;
    pos.EqualN=0;
    pos.lessN=0;
    //
    if(x<X[1-1]){
        pos.isLess=true;
    }else if(x>X[Q-1]){
       pos.isGreater=true;
    }else{
        pos.isWithin=true;
        for(int i=1; i<=Q; i++){
            if(appr.ET(X[i-1], x)){
                pos.EqualN=i;
                break;
            }
        }
        if(pos.EqualN==0){
            for(int i=1; i<=Q-1; i++){
                if(appr.LT(X[i-1], x) && appr.GT(X[i+1-1], x)){
                    pos.lessN=i;
                    break;
                }
            }
        }
    }
    return pos;
}

TPosInSucc PosInSucc(std::vector<double>X, double x, double eps){
    TPosInSucc pos;
    MathApprox appr(eps);
    int Q=X.size();
    pos.isLess=false;
    pos.isGreater=false;
    pos.isWithin-false;
    pos.EqualN=0;
    pos.lessN=0;
    //
    if(x<X[1-1]){
        pos.isLess=true;
    }else if(x>X[Q-1]){
       pos.isGreater=true;
    }else{
        pos.isWithin=true;
        for(int i=1; i<=Q; i++){
            if(appr.ET(X[i-1], x)){
                pos.EqualN=i;
                break;
            }
        }
        if(pos.EqualN==0){
            for(int i=1; i<=Q-1; i++){
                if(appr.LT(X[i-1], x) && appr.GT(X[i+1-1], x)){
                    pos.lessN=i;
                    break;
                }
            }
        }
    }
    return pos;
    //return PosInSucc1(X.data(), X.size(), x, eps);
}

double LinInterp(double*X, double*Y, int Q, double x, double eps){
    TPosInSucc pos=PosInSucc1(X, Q, x, eps);
    double y=0, y1, y2, x1, x2, k;
    if(pos.EqualN>0){
        y=Y[pos.EqualN-1];
    }else{
        if(pos.isLess){
            x1=X[1-1];
            x2=X[2-1];
            y1=Y[1-1];
            y2=Y[2-1];
        }else if(pos.isGreater){
            x1=X[Q-1-1];
            x2=X[Q-1];
            y1=Y[Q-1-1];
            y2=Y[Q-1];
        }else if(pos.lessN>0){
            x1=X[pos.lessN-1];
            x2=X[pos.lessN+1-1];
            y1=X[pos.lessN-1];
            y2=X[pos.lessN+1-1];
        }
        k=(y2-y1)/(x2-x1);
        y=k*(x-x1)+y1;
    }
    return y;
}

double LinInterp(std::vector<double>X, std::vector<double>Y, double x, double eps){
     int Q=X.size();
     double y=0;
    TPosInSucc pos=PosInSucc(X, x, eps);
    double  y1, y2, x1, x2, k;
    if(pos.EqualN>0){
        y=Y[pos.EqualN-1];
    }else{
        if(pos.isLess){
            x1=X[1-1];
            x2=X[2-1];
            y1=Y[1-1];
            y2=Y[2-1];
        }else if(pos.isGreater){
            x1=X[Q-1-1];
            x2=X[Q-1];
            y1=Y[Q-1-1];
            y2=Y[Q-1];
        }else if(pos.lessN>0){
            x1=X[pos.lessN-1];
            x2=X[pos.lessN+1-1];
            y1=X[pos.lessN-1];
            y2=X[pos.lessN+1-1];
        }
        k=(y2-y1)/(x2-x1);
        y=k*(x-x1)+y1;
    }
    return y;
    //y= LinInterp(X.data(), Y.data(), Q, x, eps);
    //return LinInterp(X.data(), Y.data(), Q, x, eps);
    //return y;
}

double LinInterp2D(std::vector<std::vector<double>>Arr2D, std::vector<double>Xext, std::vector<double>Xine, double xe, double xi, double eps){
    TPosInSucc posExt=PosInSucc(Xext, xe, eps), posIne=PosInSucc(Xine, xi, eps);
    double y0, y;
    std::vector<double>X0, X, Y0, Y;
    int Q=Arr2D.size(), L=Arr2D[1-1].size();
    X=Xine;
    if(posExt.EqualN>0){
        Y=Arr2D[posExt.EqualN-1];
    }else{
        if(posExt.isLess){
            X0.clear();
            X0.push_back(Xext[1-1]);
            X0.push_back(Xext[2-1]);
            for(int i=1; i<=L; i++){
                Y0.clear();
                Y0.push_back(Arr2D[1-1][i-1]);
                Y0.push_back(Arr2D[2-1][i-1]);
                //
                y0=LinInterp(X0, Y0, xe, eps);
                Y.push_back(y0);
            }
        }else if(posExt.isGreater){
            X0.clear();
            X0.push_back(Xext[Q-1-1]);
            X0.push_back(Xext[Q-1]);
            for(int i=1; i<=L; i++){
                Y0.clear();
                Y0.push_back(Arr2D[Q-1-1][i-1]);
                Y0.push_back(Arr2D[Q-1][i-1]);
                //
                y0=LinInterp(X0, Y0, xe, eps);
                Y.push_back(y0);
            }
        }else if(posExt.lessN>0){
            X0.clear();
            X0.push_back(Xext[posExt.lessN-1]);
            X0.push_back(Xext[posExt.lessN+1-1]);
            for(int i=1; i<=L; i++){
                Y0.clear();
                Y0.push_back(Arr2D[posExt.lessN-1][i-1]);
                Y0.push_back(Arr2D[posExt.lessN+1-1][i-1]);
                //
                y0=LinInterp(X0, Y0, xe, eps);
                Y.push_back(y0);
            }
        }
        y=LinInterp(X, Y, xi, eps);
    }
    return y;
}

std::vector<double>GetSectionsBounds(double LB, double HB, int Q, bool QOfSectsNotSectsBounds){
    std::vector<double>Y;
    int QSects, QSectsBounds;
    double SectL, y;
    QSects = QOfSectsNotSectsBounds==true ? Q : Q-1;
    QSectsBounds=QSects+1;
    SectL=(HB-LB)/QSects;
    Y.push_back(LB);
    for(int SectBoundN=1; SectBoundN<=QSectsBounds; SectBoundN++){
        y=LB+SectL*(SectBoundN-1);
        if(SectBoundN>1 && SectBoundN<QSectsBounds){
            Y.push_back(y);
        }
    }
    Y.push_back(HB);
    return Y;
}


double Integr_Trapez_SimpleByElementsArray(std::vector<double>X, std::vector<double>Y){
    double ys=0, c1, c2, dx;
    int Q=Y.size();
    for(int i=1; i<=Q-1; i++){
        dx=X[i+1-1]-X[i-1];
        c1=(Y[i+1-1]+Y[i-1])/2;
        c2=c1*dx;
        ys+=c2;
    }
    return ys;
}

double Integr_Trapez_SimpleByElementsArray(double*X, double*Y, int Q){
    double ys=0, c1, c2, dx;
    //int Q=Y.size();
    for(int i=1; i<=Q-1; i++){
        dx=X[i+1-1]-X[i-1];
        c1=(Y[i+1-1]+Y[i-1])/2;
        c2=c1*dx;
        ys+=c2;
    }
    return ys;
}


void CalcDigits(int num, int digits[], int&order, int SysBase){//, TValsShowHide*vsh){//, bool AsInNum){
    int digit, z;
    z=num>=0?num:-num;
    //if(z>SysBase)
    order=-1;
    //writeln(vsh,"CalcDigits starts working. Try number "+IntToStr(z));
    while(z>=SysBase){
        order++;
        digit=z%SysBase;
        digits[order]=digit;
        //writeln(vsh,"z="+IntToStr(z)+" > Sys base="+IntToStr(SysBase)+" => digit="+IntToStr(digit));
        z=(z-digit)/SysBase;
    }
    order++;
    digit=z;
    digits[order]=digit;
    //writeln(vsh,"z="+IntToStr(z)+" > Sys base="+IntToStr(SysBase)+" => digit="+IntToStr(digit)+" order="+IntToStr(order));
}

double IntPower(double a, int b){
    double y=1;
    if(b>=0){
        for(int i=1; i<=b; i++){
            y*=a;
        }
    }else{
        for(int i=1; i<=b; i++){
            y/=a;
        }
    }
    return y;
}

int NaturalPower(int a, int b){
   int y=1;
   for(int i=1; i<=b; i++){
       y*=a;
   }
   return y;
}

/*QString ComplexNumberToString(double ReX, double ImX){
    QString s, sRe, sIm;
    sRe.setNum(ReX);
    sIm.setNum(ImX);
    if(ImX!=0){
        s+="(";
        s+=sRe;
        if(ImX>=0){
            s+=" + ";
        }
        s+=sIm;
        s+="*i)";
    }else{
        s=sRe;
    }
    return s;
}*/

//class TItersPrecision{
//public:
//    double precision;
//    int MaxQIters;
//    int Priority_1QI2Eps3And4Or;
TItersPrecision::TItersPrecision(double precision, int MaxQIters, int Priority_1QI2Eps3And4Or){
    this->precision=precision;
    this->MaxQIters=MaxQIters;
    this->Priority_1ItersQuantity2Precision3And4Or=Priority_1QI2Eps3And4Or;
}
bool TItersPrecision::ContinieIterations(double precision, int QIters)const{
    bool contin=true;
    switch(this->Priority_1ItersQuantity2Precision3And4Or){
        case 1:
            contin=(QIters>=this->MaxQIters);
        break;
        case 2:
            contin=(precision<=this->precision);
        break;
        case 3:
            contin=(QIters>=this->MaxQIters && QIters>=this->MaxQIters);
        break;
        case 4:
            contin=(QIters>=this->MaxQIters || QIters>=this->MaxQIters);
        break;
    }
    return contin;
}
std::vector<double> TItersPrecision::GetSectionsBounds(double LB, double HB)const{
    std::vector<double> bounds;
    int QIters;
    double StepL1;
    bool contin;
    StepL1=(HB-LB)/this->MaxQIters;
    //if(StepL1>this->precision){
    switch(this->Priority_1ItersQuantity2Precision3And4Or){
        case 1:
            QIters = this->MaxQIters;
            StepL1=(HB-LB)/this->MaxQIters;
        break;
        case 2:
            QIters=2;
            //RealQ=this->MaxQIters;
            StepL1=(HB-LB)/this->MaxQIters;
            while(StepL1 > this->precision){
                QIters++;
                StepL1=(HB-LB)/QIters;
            }
        break;
        case 3:
            QIters=2;
            //RealQ=this->MaxQIters;
            StepL1=(HB-LB)/this->MaxQIters;
            contin=(QIters>=this->MaxQIters && QIters>=this->MaxQIters);
            while(contin){
                QIters++;
                StepL1=(HB-LB)/QIters;
                contin=(QIters>=this->MaxQIters && QIters>=this->MaxQIters);
            }
        break;
        case 4:
            QIters=2;
            StepL1=(HB-LB)/this->MaxQIters;
            contin=(QIters>=this->MaxQIters || QIters>=this->MaxQIters);
            while(contin){
                QIters++;
                StepL1=(HB-LB)/QIters;
                contin=(QIters>=this->MaxQIters || QIters>=this->MaxQIters);
            }
        break;
    }
    //}
    bounds.push_back(LB);
    for(int i=1; i<=QIters-1; i++){
        bounds.push_back(LB+i*StepL1);
    }
    bounds.push_back(HB);
    return bounds;
}

int TItersPrecision::GetCorrectedQIters(double LB, double HB)const{
    std::vector<double>row=this->GetSectionsBounds(LB, HB);
    int QIters=row.size();
    return QIters;
}

double TItersPrecision::GetCorrectedStepLength(double LB, double HB)const{
    std::vector<double>row=this->GetSectionsBounds(LB, HB);
    double delta=row[2-1]-row[1-1];
    return delta;
}

//
TItersPrecision TItersPrecision::GetCorrectedForBounds(double LB, double HB)const{
    TItersPrecision data;
    data.Priority_1ItersQuantity2Precision3And4Or=this->Priority_1ItersQuantity2Precision3And4Or;
    data.MaxQIters=this->GetCorrectedQIters(LB, HB);
    data.precision=this->GetCorrectedStepLength(LB, HB);
    return data;
}

//};

//class MathApprox{
//public:
//    double precision=1E-9;
    MathApprox::MathApprox(double precision){
        this->precision=precision;
    }
    bool MathApprox::ET(double x1, double x2){
        bool verdict=false;
        if(fabs(x1-x2)<this->precision){
            verdict=true;
        }
        return verdict;
    }
    bool MathApprox::GT(double x1, double x2){
        bool verdict=false;
        if(x1>x2 && fabs(x1-x2)>this->precision){
            verdict=true;
        }
        return verdict;
    }
    bool MathApprox::LT(double x1, double x2){
        bool verdict=false;
        if(x1<x2 && fabs(x2-x1)>this->precision){
            verdict=true;
        }
        return verdict;
    }
    bool MathApprox::NE(double x1, double x2){ return(!(this->ET(x1, x2)));}
    bool MathApprox::GE(double x1, double x2){ return(!(this->LT(x1, x2)));}
    bool MathApprox::LE(double x1, double x2){ return(!(this->GT(x1, x2)));}

    bool MathApprox::isPositive(double x){ return this->GT(x, 0); }
    bool MathApprox::isNegative(double x){ return this->LT(x, 0); }
    bool MathApprox::isZero(double x){ return this->ET(x, 0); }
    bool MathApprox::isNonZero(double x){ return this->NE(x, 0); }

    //

    bool fApprET(double x1, double x2, double precision){
        bool verdict=false;
        if(fabs(x1-x2)<precision){
            verdict=true;
        }
        return verdict;
    }
    bool fApprGT(double x1, double x2, double precision){
        bool verdict=false;
        if(x1>x2 && fabs(x1-x2)>precision){
            verdict=true;
        }
        return verdict;
    }
    bool fApprLT(double x1, double x2, double precision){
        bool verdict=false;
        if(x1<x2 && fabs(x2-x1)>precision){
            verdict=true;
        }
        return verdict;
    }
    bool fApprNE(double x1, double x2, double precision){ return(!(fApprET(x1, x2, precision))); }
    bool fApprGE(double x1, double x2, double precision){ return(!(fApprLT(x1, x2, precision))); }
    bool fApprLE(double x1, double x2, double precision){ return(!(fApprGT(x1, x2, precision))); }
    //
    bool fApprPositive(double x, double precision){ return(!(fApprGT(x, 0, precision))); }
    bool fApprNegative(double x, double precision){ return(!(fApprLT(x, 0, precision))); }
    bool fApprZero(double x, double precision){ return(!(fApprET(x, 0, precision))); }
    bool fApprNonZero(double x, double precision){ return(!(fApprNE(x, 0, precision))); }

    //------------------------------------------------------------------------------------------

    TPairOfReOrComplexNum::TPairOfReOrComplexNum(double x, double y){
        this->x=x;
        this->y=y;
    }
    double TPairOfReOrComplexNum::GetRe(){
        return x;
    }
    double TPairOfReOrComplexNum::GetIm(){
        return y;
    }
    double TPairOfReOrComplexNum::GetFi(){
        double R=this->GetR();
        double rslt=0;
        if(x!=0 && y!=0){
            rslt=asin(y/R);
        }
        return rslt;
    }
    double TPairOfReOrComplexNum::GetR(){
        return sqrt(x*x+y*y);
    }

    //------------------------------------------------------------------------------------------

    void EquationQuadratic(std::vector<double>C, std::vector<double>&ReX, std::vector<double>&ImX){
        double a, b, c, d, re_x, im_x;
        ReX.clear();
        ImX.clear();
        a=C[2];
        b=C[1];
        c=C[0];
        EquationQuadratic(a, b, c, ReX, ImX);
    }
    //void EquationQuadratic(double C[], std::vector<double>&ReX, std::vector<double>&ImX){
    void EquationQuadratic(double*C, std::vector<double>&ReX, std::vector<double>&ImX){
        double a, b, c;//, d, re_x, im_x;
        ReX.clear();
        ImX.clear();
        a=C[2];
        b=C[1];
        c=C[0];
        EquationQuadratic(a, b, c, ReX, ImX);
    }
    void EquationQuadratic(double BToA, double CToA, std::vector<double>&ReX, std::vector<double>&ImX){
        double a, b, c;//, d, re_x, im_x;
        ReX.clear();
        ImX.clear();
        a=1;
        b=BToA;
        c=CToA;
        EquationQuadratic(a, b, c, ReX, ImX);
    }
    void EquationQuadratic(double a, double b, double c, std::vector<double>&ReX, std::vector<double>&ImX){
        //double a, b, c;
        double d, re_x, im_x;
        ReX.clear();
        ImX.clear();
        //a=C[2];
        //b=C[1];
        //c=C[0];
        d=b*b-4*a*c;
        if(a!=0){
            if(d<0){
                re_x=-b/2/a;
                ReX.push_back(re_x);
                ReX.push_back(re_x);
                im_x=sqrt(-d)/2/a;
                ImX.push_back(-im_x);
                ImX.push_back(im_x);
            }else{
                re_x=(-b-sqrt(d))/2/a;
                ReX.push_back(re_x);
                re_x=(-b+sqrt(d))/2/a;
                ReX.push_back(re_x);
                ImX.push_back(0);
                ImX.push_back(0);
            }
        }
    }
    void EquationCubic(std::vector<double>C, std::vector<double>&ReX, std::vector<double>&ImX){
        double c3, c2, c1, c0;
        c0=C[0];
        c1=C[1];
        c2=C[2];
        c3=C[3];
        EquationCubic(c3, c2, c1, c0, ReX, ImX);
    }
    //void EquationCubic(double C[], std::vector<double>&ReX, std::vector<double>&ImX){
    void EquationCubic(double*C, std::vector<double>&ReX, std::vector<double>&ImX){
        double c3, c2, c1, c0;
        c0=C[0];
        c1=C[1];
        c2=C[2];
        c3=C[3];
        EquationCubic(c3, c2, c1, c0, ReX, ImX);
    }
void EquationCubic(double c3, double c2, double c1, double c0, std::vector<double>&ReX, std::vector<double>&ImX){
    double d, re_x, im_x, Re1, Re2, Im2, Re3, Im3;
    //s=new string[6];
    //s[1-1]="c3="+c3.ToString()+" c2="+c2.ToString()+" c1="+c1.ToString()+" c0="+c0.ToString();
    double a, b, c, A, B, p, q, Q, alfa, CosAlfa, ReY1, ReY2, ReY3;
    a=c2/c3; b=c1/c3; c=c0/c3;
    p=-a*a/3+b;
    q=2*a*a*a/27-a*b/3+c;
    Q=p*p*p/27+q*q/4;
    B = 0;
    CosAlfa = 0;
    alfa = 0;
    A = 0;
    //s[2-1]="p="+p.ToString()+" q="+q.ToString()+" Q="+Q.ToString();
    if(Q<0){
       // s[3-1]="Equation has 3 real not equal roots";
        CosAlfa=-q/(2*sqrt(-(p/3)*(p/3)*(p/3)));
        alfa=acos(CosAlfa);
        ReY1 = 2.0 * sqrt(-(p / 3.0)) * cos(alfa / 3.0);
        ReY2 = 2 * sqrt(-(p / 3)) * cos(alfa / 3 + 2 *M_PI / 3);
        ReY3 = 2 * sqrt(-(p / 3)) * cos(alfa / 3 - 2 *M_PI / 3);
        Im2=0;
        Im3=0;
    }else{
        //if(Q>0)s[3-1]="Equation has 1 real and 2 complex roots";
        //else  s[3-1]="Equation has 3 real roots, min 2 of them are equal";
        if ((-q / 2 + sqrt(Q)) >= 0){
            A = pow((-q / 2 + sqrt(Q)), 1 / 3.0);
        }else{
            A = -pow(-(-q / 2 + sqrt(Q)), 1 / 3.0);
        }
        if ((-q / 2 - sqrt(Q)) >= 0){
            B = pow((-q / 2 - sqrt(Q)), 1 / 3.0);
        }else{
            B = -pow(-(-q / 2 - sqrt(Q)), 1 / 3.0);
        }
        ReY1=A+B;
        //Im1=0;
        ReY2=-(A+B)/2;
        Im2 = (A - B) / 2.0 * sqrt(3);
        ReY3=ReY2;
        Im3=-Im2;
    }
    //s[4-1]="-(p/3)*(p/3)*(p/3)="+(-(p/3)*(p/3)*(p/3)).ToString()+" ";
    //if(!(Q<0))s[4-1]+=" A="+A.ToString()+" B="+B.ToString();
    //else s[4-1]+=" can't calculate A & B ";
    //if (!(Q > 0)) s[4 - 1] += " Cos(alfa)= " + (CosAlfa).ToString() + " alfa=" + (alfa).ToString();
    //else s[4-1]+=" can't calculate cos & alfa ";
    //s[5 - 1] += " ReY1=" + (ReY1).ToString() + " ReY2=" + (ReY2).ToString() + " ReY3=" + (ReY3).ToString();
    Re1=ReY1-a/3;
    Re2=ReY2-a/3;
    Re3=ReY3-a/3;
    //s[6 - 1] += " Re1=" + (Re1).ToString() + " Re2=" + (Re2).ToString() + " Re3=" + (Re3).ToString();
    ReX.push_back(Re1);
    ImX.push_back(0);
    ReX.push_back(Re2);
    ImX.push_back(Im2);
    ReX.push_back(Re3);
    ImX.push_back(Im3);
}
void EquationCubic(double C2ToC3, double C1ToC3, double C0ToC3, std::vector<double>&ReX, std::vector<double>&ImX){
    EquationCubic(1, C2ToC3, C1ToC3, C0ToC3, ReX, ImX);
}
//
int EquationOf4thPower(std::vector<double>C, std::vector<double>&ReX, std::vector<double>&ImX){
    double c4, c3, c2, c1, c0;
    c0=C[0];
    c1=C[1];
    c2=C[2];
    c3=C[3];
    c4=C[4];
    int ErrN;
    ErrN= EquationOf4thPower(c4, c3, c2, c1, c0, ReX, ImX);
    return ErrN;
}
//int EquationOf4thPower(double C[], std::vector<double>&ReX, std::vector<double>&ImX){
int EquationOf4thPower(double*C, std::vector<double>&ReX, std::vector<double>&ImX){
    double c4, c3, c2, c1, c0;
    c0=C[0];
    c1=C[1];
    c2=C[2];
    c3=C[3];
    c4=C[4];
    int ErrN;
    ErrN= EquationOf4thPower(c4, c3, c2, c1, c0, ReX, ImX);
    return ErrN;
}
int EquationOf4thPower(double C3To4, double C2To4, double C1To4, double C0To4, std::vector<double>&ReX, std::vector<double>&ImX){
    double c4, c3, c2, c1, c0;
    c0=C0To4;
    c1=C1To4;
    c2=C2To4;
    c3=C3To4;
    c4=1;
    int ErrN;
    ErrN= EquationOf4thPower(c4, c3, c2, c1, c0, ReX, ImX);
    return ErrN;
}
int EquationOf4thPower(double c4, double c3, double c2, double c1, double c0, std::vector<double>&ReX, std::vector<double>&ImX){
            double e2pD;
            bool AllRight=true;
            int ErrN=0;
            std::vector<double>ResolvRe, ResolvIm;
            std::vector<double> EqPow2N1Re, EqPow2N1Im, EqPow2N2Re,EqPow2N2Im;
            //string[] si=new string[27];
            //string []ResolveStr=null;
            double Re1, Im1, Re2, Im2, Re3, Im3, Re4, Im4;
            double ResolvC3, ResolvC2, ResolvC1, ResolvC0;//, CubicReRoot1;
            double Eq1C2,  Eq1C1, Eq1C0, Eq2C2,  Eq2C1, Eq2C0;
            double Root1Eq1Re1, Root1Eq1Im1, Root2Eq1Re2, Root2Eq1Im2,
               Root3Eq2Re1, Root3Eq2Im1, Root4Eq2Re2, Root4Eq2Im2,
               ResolvRe1, ResolvRe2, ResolvIm2, ResolvRe3, ResolvIm3;
            double p,q,r;
            double a=c3/c4, b=c2/c4, c=c1/c4, d=c0/c4;
            //
            e2pD = 0; ResolvRe1 = 0; ResolvRe2 = 0; ResolvIm2 = 0; ResolvRe3 = 0;
            ResolvIm3 = 0; Root3Eq2Re1 = 0; Root3Eq2Im1 = 0; Root4Eq2Re2 = 0; Root4Eq2Im2 = 0;
            Root1Eq1Re1 = 0; Root1Eq1Im1 = 0; Root2Eq1Re2 = 0; Root2Eq1Im2 = 0;
            //Root1Eq2Re1 = 0; Root1Eq2Im1 = 0; Root2Eq2Re2 = 0; Root2Eq2Im2 = 0;
            //
            p=b-3*a*a/8;
            q=a*a*a/8-a*b/2+c;
            r=-3*a*a*a*a/256+a*a*b/16-c*a/4+d;
            ResolvC3=2;
            ResolvC2=-p;
            ResolvC1=-2*r;
            ResolvC0=r*p-q*q/4;
            //si[1-1]="Supplementary Coefficients p="+p.ToString()+" q="+q.ToString()+" r="+r.ToString();
           // si[2-1]="Cubic resolvent: "+ResolvC3.ToString()+"*y^3+"+ResolvC2.ToString()+"*y^2+"+ResolvC1.ToString()+"*y+"+ResolvC0.ToString()+"=0";
            //CubicEquation(ResolvC3, ResolvC2, ResolvC1, ResolvC0, ref ReolvRe1, ref ResolvRe2, ref ResolvIm2, ref ResolvRe3, ref ResolvIm3, ref ResolveStr);
            EquationCubic(ResolvC3, ResolvC2, ResolvC1, ResolvC0, ResolvRe, ResolvIm);
            ResolvRe1=ResolvRe[1-1];
            ResolvRe2=ResolvRe[2-1];
            ResolvIm2=ResolvIm[2-1];
            ResolvRe3=ResolvRe[3-1];
            ResolvIm3=ResolvIm[3-1];
            //si[3-1]="1st Solution of Cubic Resolvent: "+ResolvRe1.ToString();
            //si[4-1]="Checking: "+(ResolvC3*ResolvRe1*ResolvRe1*ResolvRe1+ResolvC2*ResolvRe1*ResolvRe1+ResolvC1*ResolvRe1+ResolvC0).ToString();
            //si[5-1]=ResolveStr[1-1];
            //si[6-1]=ResolveStr[2-1];
            //    si[7-1]=ResolveStr[3-1];
            //si[8-1]=ResolveStr[4-1];
            //si[9-1]=ResolveStr[5-1];
            //    si[10-1]=ResolveStr[6-1];
            //si[11-1]="It was info from cubic resolvent. Now again equation of 4th power";
            if(ResolvRe1<=p/2){
                //MessageBox.Show("Equation can't be replaced by equivalent quadratic equations with real coefs!");
                AllRight=false;
                Root1Eq1Re1=666; Root1Eq1Im1=666; Root2Eq1Re2=666; Root2Eq1Im2=666;
                Root3Eq2Re1=666; Root3Eq2Im1=666; Root4Eq2Re2=666; Root4Eq2Im2=666;
                //si[12-1]="can't calculate the real coefs of equivalent cuadratic equations";
                //si[13-1]="2y1-p=2*"+ResolvRe1.ToString()+"-"+p.ToString()+"="+(2*ResolvRe1-p).ToString();
                //for(int i=14; i<=27; i++){
                //    si[14-1]=" ";
                //}
            }else{
                //si[12-1]="No problem with solution";
                Eq1C2=1;
                Eq1C1=-sqrt(2*ResolvRe1-p);
                Eq1C0 = q / (2 * sqrt(2 * ResolvRe1 - p)) + ResolvRe1;
                //si[13-1]="First quadratic equation: "+Eq1C2.ToString()+"*x^2+"+Eq1C1.ToString()+"*x+"+Eq1C0.ToString()+"=0";
                Eq2C2=Eq1C2;
                Eq2C1=-Eq1C1;
                Eq2C0=-q/(2*sqrt(2*ResolvRe1-p))+ResolvRe1;
                //si[14-1]="Second quadratic equation: "+Eq2C2.ToString()+"*x^2+"+Eq2C1.ToString()+"*x+"+Eq2C0.ToString()+"=0";
                //QuadraticEquation(Eq1C2, Eq1C1, Eq1C0, ref e2pD,  ref Root1Eq1Re1, ref Root1Eq1Im1, ref Root2Eq1Re2, ref Root2Eq1Im2);
                //QuadraticEquation(Eq2C2, Eq2C1, Eq2C0, ref e2pD,  ref Root3Eq2Re1, ref Root3Eq2Im1, ref Root4Eq2Re2, ref Root4Eq2Im2);
                EquationQuadratic(Eq1C2, Eq1C1, Eq1C0, EqPow2N1Re, EqPow2N1Im);
                EquationQuadratic(Eq2C2, Eq2C1, Eq2C0, EqPow2N2Re, EqPow2N2Im);
                Root1Eq1Re1=EqPow2N1Re[1-1];
                Root1Eq1Im1=EqPow2N1Im[1-1];
                Root2Eq1Re2=EqPow2N1Re[2-1];
                Root2Eq1Im2=EqPow2N1Im[2-1];
                //
                Root3Eq2Re1=EqPow2N2Re[1-1];
                Root3Eq2Im1=EqPow2N2Im[1-1];
                Root4Eq2Re2=EqPow2N2Re[2-1];
                Root4Eq2Im2=EqPow2N2Im[2-1];
                //si[15-1]="ANSWER:";
                //si[16-1]="1st Y: ";
                //if(Root1Eq1Im1==0){
                //    si[16-1]+=Root1Eq1Re1.ToString();
                //}else{
                //    si[16-1]+=Root1Eq1Re1.ToString()+"+i*"+Root1Eq1Im1.ToString();
                //}
                //si[17-1]="2nd Y: ";
                //if(Root2Eq1Im2==0){
                //    si[17-1]+=Root2Eq1Re2.ToString();
                //}else{
                //    si[17-1]+=Root2Eq1Re2.ToString()+"+i*"+Root2Eq1Im2.ToString();
                //}
                //si[18-1]="3rd Y: ";
                //if (Root3Eq2Im1 == 0)
                //{
                //    si[18 - 1] += Root3Eq2Re1.ToString();
                //}
                //else
                //{
                //    si[18 - 1] += Root3Eq2Re1.ToString() + "+i*" + Root3Eq2Im1.ToString();
                //}
                //si[19-1]="4th Y: ";
                //if(Root4Eq2Im2==0){
                //    si[19-1]+=Root4Eq2Re2.ToString();
                //}else{
                //    si[19-1]+=Root4Eq2Re2.ToString()+"+i*"+Root4Eq2Im2.ToString();
                //}
                //
                Root1Eq1Re1-=a/4;
                Root2Eq1Re2-=a/4;
                Root3Eq2Re1-=a/4;
                Root4Eq2Re2-=a/4;
                //si[20-1]="1st Root: ";
                //if(Root1Eq1Im1==0){
                //    si[20-1]+=Root1Eq1Re1.ToString();
                //}else{
                //    si[20-1]+=Root1Eq1Re1.ToString()+"+i*"+Root1Eq1Im1.ToString();
                //}
                //si[21-1]="2nd Root: ";
                //if(Root2Eq1Im2==0){
                //    si[21-1]+=Root2Eq1Re2.ToString();
                //}else{
                //    si[21 - 1] += Root2Eq1Re2.ToString() + "+i*" + Root2Eq1Im2.ToString();
                //}
                //si[22-1]="3rd Root: ";
                //if(Root3Eq2Im1==0){
                //    si[22 - 1] += Root3Eq2Re1.ToString();
                //}else{
                //    si[22-1]+=Root3Eq2Re1.ToString()+"+i*"+Root3Eq2Im1.ToString();
                //}
                //si[23-1]="4th Root: ";
                //if(Root4Eq2Im2==0){
                //    si[23-1]+=Root4Eq2Re2.ToString();
                //}else{
                //    si[23 - 1] += Root4Eq2Re2.ToString() + "+i*" + Root4Eq2Im2.ToString();
                //}
                //
                //if(Root1Eq1Im1==0){
                //    si[24-1]="Checking Root 1: "+(Root1Eq1Re1*Root1Eq1Re1*Root1Eq1Re1*Root1Eq1Re1+a*Root1Eq1Re1*Root1Eq1Re1*Root1Eq1Re1+b*Root1Eq1Re1*Root1Eq1Re1+c*Root1Eq1Re1+d).ToString();
                //}else{
                //    si[24-1]="  ";
                //}
                //if(Root2Eq1Im2==0){
                //    si[25 - 1] = "Checking Root 2: " + (Root2Eq1Re2 * Root2Eq1Re2 * Root2Eq1Re2 * Root2Eq1Re2 + a * Root2Eq1Re2 * Root2Eq1Re2 * Root2Eq1Re2 + b * Root2Eq1Re2 * Root2Eq1Re2 + c * Root2Eq1Re2 + d).ToString();
                //}else{
                //    si[25-1]="  ";
                //}
                //if(Root3Eq2Im1==0){
                //    si[26 - 1] = "Checking Root 3: " + (Root3Eq2Re1 * Root3Eq2Re1 * Root3Eq2Re1 * Root3Eq2Re1 + a * Root3Eq2Re1 * Root3Eq2Re1 * Root3Eq2Re1 + b * Root3Eq2Re1 * Root3Eq2Re1 + c * Root3Eq2Re1 + d).ToString();
                //}else{
                //    si[26-1]="  ";
                //}
                //if(Root4Eq2Im2==0){
                //    si[27 - 1] = "Checking Root 4: " + (Root4Eq2Re2 * Root4Eq2Re2 * Root4Eq2Re2 * Root4Eq2Re2 + a * Root4Eq2Re2 * Root4Eq2Re2 * Root4Eq2Re2 + b * Root4Eq2Re2 * Root4Eq2Re2 + c * Root4Eq2Re2 + d).ToString();
                //}else{
                //    si[27-1]="  ";
                //}
            }
            Re1=Root1Eq1Re1; Im1=Root1Eq1Im1; Re2=Root2Eq1Re2; Im2=Root2Eq1Im2;
            Re3=Root3Eq2Re1; Im3=Root3Eq2Im1; Re4=Root4Eq2Re2; Im4=Root4Eq2Im2;
            //s=si;
            ReX.push_back(Re1);
            ReX.push_back(Re2);
            ReX.push_back(Re3);
            ReX.push_back(Re4);
            ImX.push_back(Im1);
            ImX.push_back(Im2);
            ImX.push_back(Im3);
            ImX.push_back(Im4);
            if(AllRight)ErrN=0;
            return ErrN;
        }

//class PolyEq{
//private:
//    std::vector<double> C, ReX, ImX;
void PolyEq::Generate(){
    std::vector<double>c;
    int ord=this->GetOrder(), QRoots;
    double K=1;
    double a30, a31, a32, a33,
           a40, a41, a42, a43, a44,
           a50, a51, a52, a53, a54, a55,
           a60, a61, a62, a63, a64, a65, a66,
           a70, a71, a72, a73, a74, a75, a76, a77;
    if (QRoots >= 2 && QRoots <= 4){
        ord = QRoots;
        for (int i = 1; i <= QRoots+1; i++){
            c.push_back(0);
        }
        if(QRoots>2){
            a33 = K * 1;
            a32 = -K * (ReX[1 - 1] + ReX[2 - 1] + ReX[3 - 1]);
            a31 = K * (ReX[1 - 1] + ReX[2 - 1]) * +ReX[3 - 1] + ReX[1 - 1] * ReX[2 - 1];
            a30 = -K * (ReX[1 - 1] * ReX[2 - 1] * ReX[3 - 1]);
        }
        if(QRoots>3){
            a44 = a33;
            a43 = a32 - ReX[4 - 1] * a33;
            a43 = -K * (ReX[1 - 1] + ReX[2 - 1] + ReX[3 - 1] + ReX[4 - 1]);
            a42 = a31 - ReX[4 - 1] * a32;
            a42 = K * ((ReX[1 - 1] + ReX[2 - 1]) * ReX[3 - 1] + ReX[1 - 1] * ReX[2 - 1] + ReX[4 - 1] * (ReX[1 - 1] + ReX[2 - 1] + ReX[3 - 1]));
            a41 = a30 - ReX[4 - 1] * a31;
            a40 = -ReX[4 - 1] * a30;
            a40 = K * ReX[1 - 1] * ReX[2 - 1] * ReX[3 - 1] * ReX[4 - 1];
        }
        //
        switch (QRoots){
            case 2:
                c[0]=ReX[1 - 1] * ReX[2 - 1];
                c[1]=-(ReX[1 - 1] + ReX[2 - 1]);
                c[2]=1;
            break;
            case 3:
                c[0] = a30;
                c[1] = a31;
                c[2] = a32;
                c[3] = a33;
            break;
            case 4:
                c[0] = a40;
                c[1] = a41;
                c[2] = a42;
                c[3] = a43;
                c[4] = a44;
            break;
            case 5:
            break;
            case 6:
            break;
        }
        this->C=c;
    }
    //return c;
}

void PolyEq::CalcSolution(){
    int order=this->GetOrder(), ErrNo=0;
    switch(order){
        case 2:
            EquationQuadratic(this->C[2], this->C[1], this->C[0], this->ReX, this->ImX);
        break;
        case 3:
            EquationCubic(this->C[3], this->C[2], this->C[1], this->C[0], this->ReX, this->ImX);
        break;
        case 4:
            ErrNo=EquationOf4thPower(this->C[4], this->C[3], this->C[2], this->C[1], this->C[0], this->ReX, this->ImX);
        break;
    }
}
//void PolyEq::EquationQuadratic(double a, double b, double c, std::vector<double>&ReX, std::vector<double>&ImX){
//    //double a, b, c;
//    double d, re_x, im_x;
//    ReX.clear();
//    ImX.clear();
//    d=b*b-4*a*c;
//    if(a!=0){
//        if(d<0){
//            re_x=-b/2/a;
//            ReX.push_back(re_x);
//            ReX.push_back(re_x);
//            im_x=sqrt(-d)/2/a;
//            ImX.push_back(-im_x);
//            ImX.push_back(im_x);
//        }else{
//            re_x=(-b-sqrt(d))/2/a;
//            ReX.push_back(re_x);
//            re_x=(-b+sqrt(d))/2/a;
//            ReX.push_back(re_x);
//            ImX.push_back(0);
//            ImX.push_back(0);
//        }
//    }
//}
//void PolyEq::EquationCubic(double c3, double c2, double c1, double c0, std::vector<double>&ReX, std::vector<double>&ImX){
//    double d, re_x, im_x, Re1, Re2, Im2, Re3, Im3;
//    //
//    double a, b, c, A, B, p, q, Q, alfa, CosAlfa, ReY1, ReY2, ReY3;
//    a=c2/c3; b=c1/c3; c=c0/c3;
//    p=-a*a/3+b;
//    q=2*a*a*a/27-a*b/3+c;
//    Q=p*p*p/27+q*q/4;
//    B = 0;
//    CosAlfa = 0;
//    alfa = 0;
//    A = 0;
//    //
//    if(Q<0){
//       // s[3-1]="Equation has 3 real not equal roots";
//        CosAlfa=-q/(2*sqrt(-(p/3)*(p/3)*(p/3)));
//        alfa=acos(CosAlfa);
//        ReY1 = 2.0 * sqrt(-(p / 3.0)) * cos(alfa / 3.0);
//        ReY2 = 2 * sqrt(-(p / 3)) * cos(alfa / 3 + 2 *M_PI / 3);
//        ReY3 = 2 * sqrt(-(p / 3)) * cos(alfa / 3 - 2 *M_PI / 3);
//        Im2=0;
//        Im3=0;
//    }else{
//        //if(Q>0)s[3-1]="Equation has 1 real and 2 complex roots";
//        //else  s[3-1]="Equation has 3 real roots, min 2 of them are equal";
//        if ((-q / 2 + sqrt(Q)) >= 0){
//            A = pow((-q / 2 + sqrt(Q)), 1 / 3.0);
//        }else{
//            A = -pow(-(-q / 2 + sqrt(Q)), 1 / 3.0);
//        }
//        if ((-q / 2 - sqrt(Q)) >= 0){
//            B = pow((-q / 2 - sqrt(Q)), 1 / 3.0);
//        }else{
//            B = -pow(-(-q / 2 - sqrt(Q)), 1 / 3.0);
//        }
//        ReY1=A+B;
//        //Im1=0;
//        ReY2=-(A+B)/2;
//        Im2 = (A - B) / 2.0 * sqrt(3);
//        ReY3=ReY2;
//        Im3=-Im2;
//    }
//    //
//    Re1=ReY1-a/3;
//    Re2=ReY2-a/3;
//    Re3=ReY3-a/3;
//    //
//    ReX.push_back(Re1);
//    ImX.push_back(0);
//    ReX.push_back(Re2);
//    ImX.push_back(Im2);
//    ReX.push_back(Re3);
//    ImX.push_back(Im3);
//}

//int  PolyEq::EquationOf4thPower(double c4, double c3, double c2, double c1, double c0, std::vector<double>&ReX, std::vector<double>&ReY){
//    double e2pD;
//    bool AllRight=true;
//    int ErrN=0;
//    std::vector<double>ResolvRe, ResolvIm;
//    std::vector<double> EqPow2N1Re, EqPow2N1Im, EqPow2N2Re,EqPow2N2Im;
//    double Re1, Im1, Re2, Im2, Re3, Im3, Re4, Im4;
//    double ResolvC3, ResolvC2, ResolvC1, ResolvC0;//, CubicReRoot1;
//    double Eq1C2,  Eq1C1, Eq1C0, Eq2C2,  Eq2C1, Eq2C0;
//    double Root1Eq1Re1, Root1Eq1Im1, Root2Eq1Re2, Root2Eq1Im2,
//       Root3Eq2Re1, Root3Eq2Im1, Root4Eq2Re2, Root4Eq2Im2,
//       ResolvRe1, ResolvRe2, ResolvIm2, ResolvRe3, ResolvIm3;
//    double p,q,r;
//    double a=c3/c4, b=c2/c4, c=c1/c4, d=c0/c4;
//    //
//    e2pD = 0; ResolvRe1 = 0; ResolvRe2 = 0; ResolvIm2 = 0; ResolvRe3 = 0;
//    ResolvIm3 = 0; Root3Eq2Re1 = 0; Root3Eq2Im1 = 0; Root4Eq2Re2 = 0; Root4Eq2Im2 = 0;
//    Root1Eq1Re1 = 0; Root1Eq1Im1 = 0; Root2Eq1Re2 = 0; Root2Eq1Im2 = 0;
//    //
//    p=b-3*a*a/8;
//    q=a*a*a/8-a*b/2+c;
//    r=-3*a*a*a*a/256+a*a*b/16-c*a/4+d;
//    ResolvC3=2;
//    ResolvC2=-p;
//    ResolvC1=-2*r;
//    ResolvC0=r*p-q*q/4;
//    //
//    EquationCubic(ResolvC3, ResolvC2, ResolvC1, ResolvC0, ResolvRe, ResolvIm);
//    ResolvRe1=ResolvRe[1-1];
//    ResolvRe2=ResolvRe[2-1];
//    ResolvIm2=ResolvIm[2-1];
//    ResolvRe3=ResolvRe[3-1];
//    ResolvIm3=ResolvIm[3-1];
//    //
//    if(ResolvRe1<=p/2){
//        AllRight=false;
//        Root1Eq1Re1=666; Root1Eq1Im1=666; Root2Eq1Re2=666; Root2Eq1Im2=666;
//        Root3Eq2Re1=666; Root3Eq2Im1=666; Root4Eq2Re2=666; Root4Eq2Im2=666;
//    }else{
//        Eq1C2=1;
//        Eq1C1=-sqrt(2*ResolvRe1-p);
//        Eq1C0 = q / (2 * sqrt(2 * ResolvRe1 - p)) + ResolvRe1;
//        //
//        Eq2C2=Eq1C2;
//        Eq2C1=-Eq1C1;
//        Eq2C0=-q/(2*sqrt(2*ResolvRe1-p))+ResolvRe1;
//        //
//        EquationQuadratic(Eq1C2, Eq1C1, Eq1C0, EqPow2N1Re, EqPow2N1Im);
//        EquationQuadratic(Eq2C2, Eq2C1, Eq2C0, EqPow2N2Re, EqPow2N2Im);
//        Root1Eq1Re1=EqPow2N1Re[1-1];
//        Root1Eq1Im1=EqPow2N1Im[1-1];
//        Root2Eq1Re2=EqPow2N1Re[2-1];
//        Root2Eq1Im2=EqPow2N1Im[2-1];
//        //
//        Root3Eq2Re1=EqPow2N2Re[1-1];
//        Root3Eq2Im1=EqPow2N2Im[1-1];
//        Root4Eq2Re2=EqPow2N2Re[2-1];
//        Root4Eq2Im2=EqPow2N2Im[2-1];
//        //
//        Root1Eq1Re1-=a/4;
//        Root2Eq1Re2-=a/4;
//        Root3Eq2Re1-=a/4;
//        Root4Eq2Re2-=a/4;
//    }
//    Re1=Root1Eq1Re1; Im1=Root1Eq1Im1; Re2=Root2Eq1Re2; Im2=Root2Eq1Im2;
//    Re3=Root3Eq2Re1; Im3=Root3Eq2Im1; Re4=Root4Eq2Re2; Im4=Root4Eq2Im2;
//    //s=si;
//    ReX.push_back(Re1);
//    ReX.push_back(Re2);
//    ReX.push_back(Re3);
//    ReX.push_back(Re4);
//    ImX.push_back(Im1);
//    ImX.push_back(Im2);
//    ImX.push_back(Im3);
//    ImX.push_back(Im4);
//    if(AllRight)ErrN=0;
//    return ErrN;
//}
//    public:
    //
    PolyEq::PolyEq(){}//ob vects
    PolyEq::PolyEq(double*vals, int QVals, bool ByCoefsNotByRealRoots){
        //construct();
        this->SetEquationAndCalcSolution(vals, QVals, ByCoefsNotByRealRoots);
    }
    PolyEq::PolyEq(const PolyEq&obj){
        //construct();
        this->Assign(obj);
    }
    PolyEq::~PolyEq(){}////ob vects
    //
    void PolyEq::Assign(const PolyEq&obj){
        this->C=obj.C;
        this->ReX=obj.ReX;
        this->ImX=obj.ImX;
    }
    //
    PolyEq& PolyEq::operator =(const PolyEq&obj){
        this->Assign(obj);
        return*this;
    }

    //
    void PolyEq::SetEquationsCoefficientsNsETPowerAndCalcSolution(double*c, int coefsQuantity){
        double val;
        if(coefsQuantity>=2+1 && coefsQuantity<=4+1){
            this->C.clear();
            this->ReX.clear();
            this->ImX.clear();
            if(c!=NULL){
                for(int i=1; i<=coefsQuantity; i++){
                    val=c[i-1];
                    this->C.push_back(val);
                }
            }else{
                for(int i=1; i<=coefsQuantity; i++){
                    this->C.push_back(0);
                }
            }
        }
        this->CalcSolution();
    }

    void PolyEq::GenerateEquationByRealRootsAndCalcSolution(double*ReX, int order){
        double val;
        if(order>=2 && order<=4){
            this->C.clear();
            this->ReX.clear();
            this->ImX.clear();
            if(ReX!=NULL){
                for(int i=1; i<=order; i++){
                    val=ReX[i-1];
                    this->ReX.push_back(val);
                }
            }else{
                for(int i=1; i<=order; i++){
                    this->ReX.push_back(0);
                }
            }
            for(int i=1; i<=order; i++){
                this->ImX.push_back(0);
            }
            //for(int i=1; i<=order+1; i++){
            //    this->С.push_back(0);
            //}//ja ma n'nod
        }
        this->Generate();
        this->CalcSolution();
    }

    void PolyEq::SetEquationAndCalcSolution(double*vals, int QVals, bool ByCoefsNotByRealRoots){
        if(ByCoefsNotByRealRoots){
            this->SetEquationsCoefficientsNsETPowerAndCalcSolution(vals, QVals);
        }else{
            this->GenerateEquationByRealRootsAndCalcSolution(vals, QVals);
        }
    }
    //
    void PolyEq::EquationQuadratic(double a, double b, double c, std::vector<double>&ReX, std::vector<double>&ImX){
        //double a, b, c;
        double d, re_x, im_x;
        ReX.clear();
        ImX.clear();
        d=b*b-4*a*c;
        if(a!=0){
            if(d<0){
                re_x=-b/2/a;
                ReX.push_back(re_x);
                ReX.push_back(re_x);
                im_x=sqrt(-d)/2/a;
                ImX.push_back(-im_x);
                ImX.push_back(im_x);
            }else{
                re_x=(-b-sqrt(d))/2/a;
                ReX.push_back(re_x);
                re_x=(-b+sqrt(d))/2/a;
                ReX.push_back(re_x);
                ImX.push_back(0);
                ImX.push_back(0);
            }
        }
    }
    void PolyEq::EquationCubic(double c3, double c2, double c1, double c0, std::vector<double>&ReX, std::vector<double>&ImX){
        double d, re_x, im_x, Re1, Re2, Im2, Re3, Im3;
        //
        double a, b, c, A, B, p, q, Q, alfa, CosAlfa, ReY1, ReY2, ReY3;
        a=c2/c3; b=c1/c3; c=c0/c3;
        p=-a*a/3+b;
        q=2*a*a*a/27-a*b/3+c;
        Q=p*p*p/27+q*q/4;
        B = 0;
        CosAlfa = 0;
        alfa = 0;
        A = 0;
        //
        if(Q<0){
           // s[3-1]="Equation has 3 real not equal roots";
            CosAlfa=-q/(2*sqrt(-(p/3)*(p/3)*(p/3)));
            alfa=acos(CosAlfa);
            ReY1 = 2.0 * sqrt(-(p / 3.0)) * cos(alfa / 3.0);
            ReY2 = 2 * sqrt(-(p / 3)) * cos(alfa / 3 + 2 *M_PI / 3);
            ReY3 = 2 * sqrt(-(p / 3)) * cos(alfa / 3 - 2 *M_PI / 3);
            Im2=0;
            Im3=0;
        }else{
            //if(Q>0)s[3-1]="Equation has 1 real and 2 complex roots";
            //else  s[3-1]="Equation has 3 real roots, min 2 of them are equal";
            if ((-q / 2 + sqrt(Q)) >= 0){
                A = pow((-q / 2 + sqrt(Q)), 1 / 3.0);
            }else{
                A = -pow(-(-q / 2 + sqrt(Q)), 1 / 3.0);
            }
            if ((-q / 2 - sqrt(Q)) >= 0){
                B = pow((-q / 2 - sqrt(Q)), 1 / 3.0);
            }else{
                B = -pow(-(-q / 2 - sqrt(Q)), 1 / 3.0);
            }
            ReY1=A+B;
            //Im1=0;
            ReY2=-(A+B)/2;
            Im2 = (A - B) / 2.0 * sqrt(3);
            ReY3=ReY2;
            Im3=-Im2;
        }
        //
        Re1=ReY1-a/3;
        Re2=ReY2-a/3;
        Re3=ReY3-a/3;
        //
        ReX.push_back(Re1);
        ImX.push_back(0);
        ReX.push_back(Re2);
        ImX.push_back(Im2);
        ReX.push_back(Re3);
        ImX.push_back(Im3);
    }

    int PolyEq::EquationOf4thPower(double c4, double c3, double c2, double c1, double c0, std::vector<double>&ReX, std::vector<double>&ImX){
        double e2pD;
        bool AllRight=true;
        int ErrN=0;
        std::vector<double>ResolvRe, ResolvIm;
        std::vector<double> EqPow2N1Re, EqPow2N1Im, EqPow2N2Re,EqPow2N2Im;
        double Re1, Im1, Re2, Im2, Re3, Im3, Re4, Im4;
        double ResolvC3, ResolvC2, ResolvC1, ResolvC0;//, CubicReRoot1;
        double Eq1C2,  Eq1C1, Eq1C0, Eq2C2,  Eq2C1, Eq2C0;
        double Root1Eq1Re1, Root1Eq1Im1, Root2Eq1Re2, Root2Eq1Im2,
           Root3Eq2Re1, Root3Eq2Im1, Root4Eq2Re2, Root4Eq2Im2,
           ResolvRe1, ResolvRe2, ResolvIm2, ResolvRe3, ResolvIm3;
        double p,q,r;
        double a=c3/c4, b=c2/c4, c=c1/c4, d=c0/c4;
        //
        e2pD = 0; ResolvRe1 = 0; ResolvRe2 = 0; ResolvIm2 = 0; ResolvRe3 = 0;
        ResolvIm3 = 0; Root3Eq2Re1 = 0; Root3Eq2Im1 = 0; Root4Eq2Re2 = 0; Root4Eq2Im2 = 0;
        Root1Eq1Re1 = 0; Root1Eq1Im1 = 0; Root2Eq1Re2 = 0; Root2Eq1Im2 = 0;
        //
        p=b-3*a*a/8;
        q=a*a*a/8-a*b/2+c;
        r=-3*a*a*a*a/256+a*a*b/16-c*a/4+d;
        ResolvC3=2;
        ResolvC2=-p;
        ResolvC1=-2*r;
        ResolvC0=r*p-q*q/4;
        //
        EquationCubic(ResolvC3, ResolvC2, ResolvC1, ResolvC0, ResolvRe, ResolvIm);
        ResolvRe1=ResolvRe[1-1];
        ResolvRe2=ResolvRe[2-1];
        ResolvIm2=ResolvIm[2-1];
        ResolvRe3=ResolvRe[3-1];
        ResolvIm3=ResolvIm[3-1];
        //
        if(ResolvRe1<=p/2){
            AllRight=false;
            Root1Eq1Re1=666; Root1Eq1Im1=666; Root2Eq1Re2=666; Root2Eq1Im2=666;
            Root3Eq2Re1=666; Root3Eq2Im1=666; Root4Eq2Re2=666; Root4Eq2Im2=666;
        }else{
            Eq1C2=1;
            Eq1C1=-sqrt(2*ResolvRe1-p);
            Eq1C0 = q / (2 * sqrt(2 * ResolvRe1 - p)) + ResolvRe1;
            //
            Eq2C2=Eq1C2;
            Eq2C1=-Eq1C1;
            Eq2C0=-q/(2*sqrt(2*ResolvRe1-p))+ResolvRe1;
            //
            EquationQuadratic(Eq1C2, Eq1C1, Eq1C0, EqPow2N1Re, EqPow2N1Im);
            EquationQuadratic(Eq2C2, Eq2C1, Eq2C0, EqPow2N2Re, EqPow2N2Im);
            Root1Eq1Re1=EqPow2N1Re[1-1];
            Root1Eq1Im1=EqPow2N1Im[1-1];
            Root2Eq1Re2=EqPow2N1Re[2-1];
            Root2Eq1Im2=EqPow2N1Im[2-1];
            //
            Root3Eq2Re1=EqPow2N2Re[1-1];
            Root3Eq2Im1=EqPow2N2Im[1-1];
            Root4Eq2Re2=EqPow2N2Re[2-1];
            Root4Eq2Im2=EqPow2N2Im[2-1];
            //
            Root1Eq1Re1-=a/4;
            Root2Eq1Re2-=a/4;
            Root3Eq2Re1-=a/4;
            Root4Eq2Re2-=a/4;
        }
        Re1=Root1Eq1Re1; Im1=Root1Eq1Im1; Re2=Root2Eq1Re2; Im2=Root2Eq1Im2;
        Re3=Root3Eq2Re1; Im3=Root3Eq2Im1; Re4=Root4Eq2Re2; Im4=Root4Eq2Im2;
        //s=si;
        ReX.push_back(Re1);
        ReX.push_back(Re2);
        ReX.push_back(Re3);
        ReX.push_back(Re4);
        ImX.push_back(Im1);
        ImX.push_back(Im2);
        ImX.push_back(Im3);
        ImX.push_back(Im4);
        if(AllRight)ErrN=0;
        return ErrN;
    }
    //
    std::vector<double> PolyEq::GetReX(){ return this->ReX; }
    std::vector<double> PolyEq::GetImX(){ return this->ImX; }
    std::vector<double> PolyEq::GetCoefs(){ return this->C; }
    void PolyEq::GetRoots(std::vector<double>&ReX, std::vector<double>&ImX){
        ReX=this->ReX;
        ImX=this->ImX;
    }
    void PolyEq::SetOrderAndClear(int order){
        this->C.clear();
        this->ReX.clear();
        this->ImX.clear();
        for(int i=1; i<=order; i++){
            this->C.push_back(0);
            this->ReX.push_back(0);
            this->ImX.push_back(0);
        }
        this->C.push_back(0);
    }
    int PolyEq::GetOrder(){
        return this->C.size()-1;
    }
    QString PolyEq::EquationToString(){
        QString s, sn;
        double val;
        int order=this->GetOrder();
        for(int i=order; i>=0; i--){
            val=this->C[i];
            if(val!=0){
                if(val>0 && i<order){
                    s+="+";
                }
                if(!((val==1 || val==-1) && i>0)){
                    sn.setNum(val);
                    s+=sn;
                    if(i>0){
                        s+="*";
                    }
                }
                if(i>=1){
                    s+="X";
                }
                if(i>1){
                    s+="^";
                    sn.setNum(i);
                    s+=sn;
                }
            }
        }
        s+="=0";
        return s;
    }
    QString PolyEq::SolutionToString(){
        QString s, sn;
        double re, im;
        int order=this->GetOrder();
        for(int i=1; i<=order; i++){
            re=this->ReX[i-1];
            im=this->ImX[i-1];
            sn.setNum(i);
            s+="X[";
            s+=sn;
            s+="]=";
            if(re!=0 && re!=1 && re!=-1){
                sn.setNum(re);
                s+=sn;
            }
            if(im!=0){
                if(im>0 && re!=0){
                    s+="+";
                }
                if(im!=1 && im!=-1){
                    sn.setNum(im);
                    s+=sn;
                    if(i>0){
                        s+="*";
                    }
                }
                s+="i";
            }
            if(i<order){
                s+="; ";
            }
        }
        return s;
    }

//};

//---------------------------------------------------------------------

void LinearApproximation(double*X, double*Y, int Qini, double&a, double&b){
    double meanY=0, sumSquaredDiff=0, stdDevY;
    int Q;
    std::vector<double> newX, newY;
    double sumX=0;
    double sumY=0;
    double sumXY = 0.0;
    double sumX2 = 0.0;
    for(int i=1; i<=Qini; i++){
        meanY+=Y[i-1];
    }
    meanY/=Q;
    for(int i=1; i<=Qini; i++){
        sumSquaredDiff+=(Y[i-1]-meanY)*(Y[i-1]-meanY);
    }
    stdDevY = sqrt(sumSquaredDiff / Qini);
    const double threshold = 2.0 * stdDevY;
    for(int i=1; i<=Qini; i++){
        if(abs(Y[i] - meanY) <= threshold){
            newX.push_back(X[i-1]);
            newY.push_back(Y[i-1]);
        }
    }
    Q=newX.size();
    for(int i=1; i<=Q; i++){
        sumX+=newX[i-1];
        sumY+=newY[i-1];
        sumXY+=newX[i-1]*newY[i-1];
        sumX2+=newX[i-1]*newX[i-1];
    }
    a = (Q * sumXY - sumX * sumY) / (Q * sumX2 - sumX * sumX);
    b = (sumY - a * sumX) / Q;

}

void LinearApproximation(const std::vector<double>&X, const std::vector<double>&Y, double&a, double&b){
    double meanY, sumSquaredDiff;
    std::vector<double>X1=X, Y1=Y;
    int Q=X.size();
    if(X.size()!=Y.size() || X.empty()){
        //NOp
        a=0;
        b=0;
    }else{
        //void LinearApproximation(double*&X, double*Y, int Qini, double&a, double&b)
        LinearApproximation(X1.data(), Y1.data(), X.size(), a, b);
    }
}


double arctg2(double x, double y){
    double R=0, absval;
    int QuadrantN=0;
    if(x=0 && y!=0){

    }else if(y==0 &&x!=0){
        R=0;
    }else{
        if(x>0 && y>0){
            QuadrantN=1;
        }else if(x<0 && y>0){
            QuadrantN=2;
        }else if(x<0 && y<0){
            QuadrantN=3;
        }else if(x>0 && y<0){
            QuadrantN=4;
        }
        absval=fabs(y/x);
        switch(QuadrantN){
            case 1:
                R=absval;
            break;
            case 2:
                R=M_PI-absval;
            break;
            case 3:
                R=M_PI+absval;
            break;
            case 4:
                R=2*M_PI-absval;
            break;
        }
    }
    return R;
}

double CalcHowRowsAreLinearDependent(double *x1, double *x2, int Q, double eps){
    double k1=0, k2=0, val1, val2;
    val1=x1[1-1];
    val2=x2[1-1];
    bool check=true, contin;
    int N=1;
    val1=x1[N-1];
    val2=x2[N-1];
    if(val1==0 || val2==0){
        k2=0;
        check=false;
    }else{
        k1=val1/val2;
    }
    contin=check;
    while(contin){
        N++;
        if(N>=Q){
            contin=false;
        }
        val1=x1[N-1];
        val2=x2[N-1];
        if(val1==0 || val2==0){
            check=false;
        }else{
            k2=val1/val2;
            if(k1!=k2){
                check=false;
            }
        }
        if(check==false){
            contin=false;
        }
    }//while
    if(check==false){
        k1=0;
    }
    return k1;
}//fn
bool CheckIfRowsAreLinearDependent(double *x1, double *x2, int Q, double eps){
    double k1=0, k2=0, val1, val2;
    val1=x1[1-1];
    val2=x2[1-1];
    bool check=true, contin;
    int N=1;
    val1=x1[N-1];
    val2=x2[N-1];
    if(val1==0 || val2==0){
        k2=0;
        check=false;
    }else{
        k1=val1/val2;
    }
    contin=check;
    while(contin){
        N++;
        if(N>=Q){
            contin=false;
        }
        val1=x1[N-1];
        val2=x2[N-1];
        if(val1==0 || val2==0){
            check=false;
        }else{
            k2=val1/val2;
            if(k1!=k2){
                check=false;
            }
        }
        if(check==false){
            contin=false;
        }
    }//while
    if(check==false){
        k1=0;
    }
    return check;
}//fn

//-------------------------------------------------------------------------------------------------------------

//void GetSubArrayNs(int Q, int&QReqCalcd, int&preN1, int&preN2, int&ownN1, int&ownN2, int&ForOwnN1, int&ForOwnN2, int&postN1, int&postN2, int FromN, int QReqGiven, int QDefaultsBefore){
//    int QPost=0, QOwnRe=0 ;//re means rest or really
//    if(QReqGiven==0){
//        QReqCalcd=QDefaultsBefore+Q-FromN+1;
//    }else{//QReqGiven>0
//        QReqCalcd=QReqGiven;
//        if(QDefaultsBefore>=QReqGiven || FromN>Q){
//            //pre only
//            preN1=1;
//            preN2=QReqGiven;
//        }else{
//            //smth else xpt pre
//            preN1 = QDefaultsBefore>0 ? 1 : 0;
//            preN2=QDefaultsBefore;
//            ownN1=FromN;
//            ForOwnN1=preN2+1;
//            if(QDefaultsBefore+Q-FromN+1<QReqGiven){
//                //post exist, QOwn - full except FromN
//                QOwnRe=Q-FromN+1;
//                QPost=QReqGiven-QDefaultsBefore-QOwnRe;
//                postN1=ForOwnN2+1;
//                postN2=QReqGiven;
//            }else{//QDefaultsBefore+Q-FromN+1>=QReqGiven
//                //no post, own is all ic ns'pre, not full or full
//                QOwnRe=QReqGiven-QDefaultsBefore;
//                //ForOwnN2=QReqGiven;
//            }
//            ownN2=FromN-1+QOwnRe;
//            ForOwnN2=ForOwnN1+QOwnRe-1;
//        }
//    }//cases
//}//fn

//std::vector<double>GetSubArrayOfNums(double*X, int Q, int FromN, int QReqGiven, int QDefaultsBefore, double DefaultVal){
//    std::vector<double>Y;
//    double val;
//    int preN1=0, preN2=0, ownN1=0, ownN2=0, ForOwnN1=0, ForOwnN2=0, postN1=0, postN2=0;
//    int QReqCalcd;
//    //void GetSubArrayNs(int Q, int&QReqCalcd, int&preN1, int&preN2, int&ownN1, int&ownN2, int&ForOwnN1, int&ForOwnN2, int&postN1, int&postN2, int FromN=1, int QReqGiven=0, int QDefaultsBefore=0){
//          GetSubArrayNs(     Q,     QReqCalcd,     preN1,     preN2,     ownN1,     ownN2,     ForOwnN1,     ForOwnN2,     postN1,     postN2,     FromN,       QReqGiven,       QDefaultsBefore);
//    if(preN2>0){
//       for(int i=preN1; i<=preN2; i++){
//           Y.push_back(DefaultVal);
//       }
//    }
//    if(ownN2>0){
//        for(int i=preN1; i<=preN2; i++){
//            val=X[i-1];
//            Y.push_back(val);
//        }
//    }
//    if(postN2>0){
//       for(int i=postN1; i<=postN2; i++){
//           Y.push_back(DefaultVal);
//       }
//    }
//    return Y;
//}

//std::vector<double>GetSubArrayOfNums(double*X, int Q, double*X2, int Q2, int FromN, int QReqGiven, int QDefaultsBefore, double DefaultVal){
//    std::vector<double>Y;
//    double val;
//    int preN1=0, preN2=0, ownN1=0, ownN2=0, ForOwnN1=0, ForOwnN2=0, postN1=0, postN2=0;
//    int QReqCalcd;
//    int minN;
//    //void GetSubArrayNs(int Q, int&QReqCalcd, int&preN1, int&preN2, int&ownN1, int&ownN2, int&ForOwnN1, int&ForOwnN2, int&postN1, int&postN2, int FromN=1, int QReqGiven=0, int QDefaultsBefore=0){
//          GetSubArrayNs(     Q,     QReqCalcd,     preN1,     preN2,     ownN1,     ownN2,     ForOwnN1,     ForOwnN2,     postN1,     postN2,     FromN,       QReqGiven,       QDefaultsBefore);
//    if(preN2>0){
//       minN = preN2>Q2 ? preN2 : Q2;
//       for(int i=preN1; i<=minN; i++){
//           val=X2[i-1];
//           Y.push_back(val);
//       }
//       for(int i=minN+1; i<=preN2; i++){
//           Y.push_back(DefaultVal);
//       }
//    }
//    if(ownN2>0){
//        for(int i=preN1; i<=preN2; i++){
//            val=X[i-1];
//            Y.push_back(val);
//        }
//    }
//    if(postN2>0){
//        if(Q2<postN1){
//            for(int i=postN1; i<=postN2; i++){
//                Y.push_back(DefaultVal);
//            }
//        }else{
//            minN = postN2 >= Q2 ? postN2 : Q2;
//            for(int i=postN1; i<=minN; i++){
//                val=X[i-1];
//                Y.push_back(val);
//            }
//            for(int i=minN+1; i<=postN2; i++){
//                 Y.push_back(DefaultVal);
//            }
//        }
//    }
//    return Y;
//}

//-------------------------------------------------------------------------------------------------------------

//class ComplexNum{
//    double re, im;
//public:
    ComplexNum::ComplexNum(double re, double im){
        this->SetDecart(re, im);
    }

    ComplexNum::ComplexNum(const ComplexNum&obj){
        this->SetDecart(obj.re, obj.im);
    }

    void ComplexNum::Assign(const ComplexNum&obj){
        this->SetDecart(obj.re, obj.im);
    }

    ComplexNum::~ComplexNum(){}
    ComplexNum& ComplexNum::operator = (const ComplexNum&obj){
        this->Assign(obj);
        return(*(this));
    }

    double ComplexNum::SetDecart(double re, double im){
        this->re=re;
        this->im=im;
    }

    double ComplexNum::SetPolar(double fi, double r){
        this->re=r*cos(fi);
        this->im=r*sin(fi);
    }

    double ComplexNum::GetRe()const{
        return this->re;
    }

    double ComplexNum::GetIm()const{
        return this->im;
    }
    void ComplexNum::GetPolar(double&r, double&fi)const{
        r=sqrt(this->re*this->re + this->im*this->im);
        fi=arctg2(this->re, this->im);
    }

    double ComplexNum::GetFi()const{
        double r=0, fi=0;
        this->GetPolar(r, fi);
        return fi;
    }

    double ComplexNum::GetR()const{
        double r=0, fi=0;
        this->GetPolar(r, fi);
        return r;
    }
    void ComplexNum::ChangeRe(double val){
        this->re=val;
    }

    void ComplexNum::ChangeIm(double val){
        this->im=val;
    }
    void ComplexNum::ChangeFi(double val){
        double r=GetR();
        this->SetPolar(val, r);
    }
    ComplexNum ComplexNum::GetConjugated()const{
        ComplexNum y(this->re, -this->im);
        return y;
    }

    void ComplexNum::ChangeR(double val){
        double fi=GetFi();
        this->SetPolar(fi, val);
    }
    //ComplexNum& ComplexNum::operator + (const ComplexNum&obj){
    //    this->re+=obj.re;
    //    this->im+=obj.im;
    //    return*this;
    //}

    //ComplexNum& ComplexNum::operator - (const ComplexNum&obj){
    //    this->re-=obj.re;
    //    this->im-=obj.im;
    //    return*this;
    //}
    //ComplexNum& ComplexNum::operator * (const ComplexNum&obj){
    //    this->re = this->re * obj.re + this->im * obj.im;
    //    this->im = this->re * obj.im - this->im * obj.re;
    //    return*this;
    //}
    //ComplexNum& ComplexNum::operator / (const ComplexNum&obj){
    //    double denominator=this->re*this->re+this->im*this->im;
    //    this->re = this->re * obj.re - this->im * obj.im;
    //    this->im = this->re * obj.im + this->im * obj.re;
    //    this->re/=denominator;
    //    this->im/=denominator;
    //    return*this;
    //}
    //ComplexNum& ComplexNum::operator * (double val){
    //    this->re*=val;
    //    this->im*=val;
    //    return (*(this));
    //}

    ComplexNum& ComplexNum::operator += (const ComplexNum&obj){
        double re2=obj.GetRe(), im2=obj.GetIm();
        this->re+=re2;
        this->im+=im2;
        return *this;
    }

    ComplexNum& ComplexNum::operator -= (const ComplexNum&obj){
        double re2=obj.GetRe(), im2=obj.GetIm();
        this->re-=re2;
        this->im-=im2;
        return *this;
    }
    ComplexNum& ComplexNum::operator *= (const ComplexNum&obj){
        double re2=obj.GetRe(), im2=obj.GetIm();
        this->re=this->re*re2-this->im*im2;
        this->im=this->re*im2+this->im*re2;
        return *this;
    }

    ComplexNum& ComplexNum::operator *= (double k){
        this->re*=k;
        this->im*=k;
        return *this;
    }

    ComplexNum& ComplexNum::operator /= (const ComplexNum&obj){
        double re2=obj.GetRe(), im2=obj.GetIm(), im2cjg=-im2, denom=re2*re2-im2*im2cjg, reR;
        if(denom!=0){
            reR=(this->re*re2-im2cjg*this->im)/denom;
            this->im=(this->re*im2cjg+this->im*re2)/denom;
            this->re=reR;//ob re utf'd ov
        }
        return *this;
    }

    bool ComplexNum::operator == (const ComplexNum&obj){
        return (this->re == obj.re && this->im == obj.im);
    }

    bool ComplexNum::operator != (const ComplexNum&obj){
        return !(this->re == obj.re && this->im == obj.im);
    }

    bool ComplexNum::IsConjugated(const ComplexNum&obj){
        return(this->re==obj.re && this->im==-obj.im);
    }

    bool ComplexNum::IsZero(double precis){
        double R=this->GetR();
        bool verdict=(fabs(R)<=precis);
        return verdict;
    }
    QString ComplexNum::ToString(){
        QString s, sn;
        sn.setNum(this->re);
        //sn=FloatToStr(this->re);
        s+=sn;
        if(this->im!=0){
            if(this->im>0){
                s+="+";
                if(this->im!=1){
                    //sn=FloatToStr(this->im);
                    sn.setNum(this->im);
                    s+=sn;
                    //s+="*";
                }
            }else if(this->im==-1){
                s+="-";
            }
            s+="i";
        }
        return s;
    }


//};

ComplexNum operator + (const ComplexNum&x1, const ComplexNum&x2){
    double re1=x1.GetRe(),
           re2=x2.GetRe(),
           im1=x1.GetIm(),
           im2=x2.GetIm(),
           re, im;
    ComplexNum y;
    re=re1+re2;
    im=im1+im2;
    //ComplexNum y(re, im);
    y.ChangeRe(re);
    y.ChangeIm(im);
    return y;
}

ComplexNum operator - (const ComplexNum&x1, const ComplexNum&x2){
    double re1=x1.GetRe(),
           re2=x2.GetRe(),
           im1=x1.GetIm(),
           im2=x2.GetIm(),
           re, im;
    ComplexNum y;
    re=re1-re2;
    im=im1-im2;
    //ComplexNum y(re, im);
    y.ChangeRe(re);
    y.ChangeIm(im);
    return y;
}
ComplexNum operator * (const ComplexNum&x1, double x2){
    double re1=x1.GetRe(),
           im1=x1.GetIm(),
           re, im;
    ComplexNum y;
    re=re1*x2;
    im=im1*x2;
    //ComplexNum y(re, im);
    y.ChangeRe(re);
    y.ChangeIm(im);
    return y;
}
ComplexNum operator * (double x1, const ComplexNum&x2){
    double re2=x2.GetRe(),  im2=x2.GetIm(),  re, im;
    ComplexNum y;
    re=re2*x1;
    im=im2*x1;
    //ComplexNum y(re, im);
    y.ChangeRe(re);
    y.ChangeIm(im);
    return y;
}
ComplexNum operator * (const ComplexNum&x1, const ComplexNum&x2){
    double re1=x1.GetRe(), re2=x2.GetRe(), im1=x1.GetIm(), im2=x2.GetIm(), re, im;
    ComplexNum y;
    re=re1*re2-im1*im2;
    im=re1*im2+re2*im1;
    //ComplexNum y(re, im);
    y.ChangeRe(re);
    y.ChangeIm(im);
    return y;
}
ComplexNum operator / (const ComplexNum&x1, const ComplexNum&x2){
    double re1=x1.GetRe(), re2=x2.GetRe(), im1=x1.GetIm(), im2=x2.GetIm(), re, im, denom;
    ComplexNum y;
    ComplexNum conj2=x2.GetConjugated(), denomCmplx=x2*conj2;
    denom=denomCmplx.GetRe();
    if(denom!=0){
        y=x1*conj2;//qob n'arb
        //y*=(1/denom);
        y*=(1.0/denom);
    }
    return y;
}



//============================================================================================================================

bool RowsAreLinearlyDependent(std::vector<double>row1, std::vector<double>row2, double precision){
    bool b=true, contin;
    double k1, kcur;
    int Nc, L1=row1.size(), L2=row2.size();
    if(L1>0 || L1!=L2){
        for(int i=1; i<=L1; i++){
            //bool fApprZero(double x, double precision);
            if(fApprZero(row1[i-1], precision) || fApprZero(row2[i-1], precision)){
                b=false;
            }
        }
        if(b){
            k1=row1[1-1]/row2[1-1];
            for(int i=2; i<=L1; i++){
                kcur=row1[i-1]/row2[i-1];
                //bool fApprNE(double x1, double x2, double precision);
                if(fApprNE(kcur, k1, precision)){
                    b=false;
                }
            }
        }
    }
    return b;
}

//------------------------------------------------------------------------------------------------------------------------------

std::vector<double> RungeSingleStep(int n, double*y, const std::vector<ODEFunc>&fArray, double h, double t){//, TValsShowHide*vsh){
    //writeln(vsh,"RungeSingleStep starts working");
    //writeln(vsh,"h="+FloatToStr(h)+" t="+FloatToStr(t));
    double *k1 = new double[n];
    double *k2 = new double[n];
    double *k3 = new double[n];
    double *k4 = new double[n];
    double *yTmp = new double[n];
    std::vector<double>yr;
    double yc;
    double val1, val2, val3, val4;
    //
    val1=fArray[1-1](n, t, y);
    val2=fArray[2-1](n, t, y);
    val3=fArray[3-1](n, t, y);
    val4=fArray[4-1](n, t, y);
    //writeln(vsh,"Calc y");
    for(int i=0; i<n; i++){
        yr.push_back(y[i]);
        //writeln(vsh,IntToStr(i)+") "+FloatToStr(yr[i]));
    }
    //k1
    //writeln(vsh,"Calc k1: k1(y[i])=f(t, y[i])");
    for(int i=0; i<n; i++){
        //k1[i]=h*fArray[i](n, t, y);
        yc=fArray[i](n, t, y);
        k1[i]=yc;
        yc=k1[i];
        //writeln(vsh,IntToStr(i)+") "+FloatToStr(k1[i]));
    }
    //k2
    //writeln(vsh,"Calc k2: k2(y[i])=f(t+h/2, y[i]+h*k1[i])");
    for(int i=0; i<n; i++){
        yTmp[i]=y[i]+h*k1[i]/2.0;
        //writeln(vsh,IntToStr(i)+") yTmp="+FloatToStr(k1[i]));
    }
    for(int i=0; i<n; i++){
        k2[i]=fArray[i](n, t+h/2, yTmp);
        yc=k2[i];
        //writeln(vsh,IntToStr(i)+") k2="+FloatToStr(k2[i]));
    }
    //k3
    //writeln(vsh,"Calc k3: k3(y[i])=f(t+h/2, y[i]+h*k2[i])");
    for(int i=0; i<n; i++){
        yTmp[i]=y[i]+h*k2[i]/2.0;
        //writeln(vsh,IntToStr(i)+") yTmp="+FloatToStr(k1[i]));
    }
    for(int i=0; i<n; i++){
        k3[i]=fArray[i](n, t+h/2, yTmp);
        yc=k3[i];
        //writeln(vsh,IntToStr(i)+") k3="+FloatToStr(k3[i]));
    }
    //k4
    //writeln(vsh,"Calc k4: k4(y[i])=f(t+h, y[i]+h*k3[i])");
    for(int i=0; i<n; i++){
        yTmp[i]=y[i]+h*k3[i];
    }
    for(int i=0; i<n; i++){
        k4[i]=fArray[i](n, t+h, yTmp);
        yc=k4[i];
    }
    //result
    //writeln(vsh,"Summing up: y1 += h * (k1[i]+ 2*k2[i] + 2*k3[i] + k4[i])/6)");
    for(int i=0; i<n; i++){
        //y[i] += h* (k1[i]+ 2*k2[i] + 2*k3[i] + k4[i])/6;
        //yc += h* (k1[i]+ 2*k2[i] + 2*k3[i] + k4[i])/6;
        yc = h * (k1[i]+ 2*k2[i] + 2*k3[i] + k4[i])/6;
        //yr.push_back(yc);
        yr[i]+=yc;
        //writeln(vsh,IntToStr(i)+") yr="+FloatToStr(k3[i]));
    }
    //clear memory
    delete[]k1;
    delete[]k2;
    delete[]k3;
    delete[]k4;
    delete[]yTmp;
    //
    return yr;
}



std::vector<double> RungeFull(int Q, double*y, const std::vector<ODEFunc>&fArray, double h, double t0, double t2){//, TValsShowHide*vsh){
    double hf=h, t;
    std::vector<double>yr;
    int QSteps=2;
    //
    //writeln(vsh, "RungeFull starts working");
    //writeln(vsh, "Q="+IntToStr(Q)+" h="+FloatToStr(h)+" t0="+FloatToStr(t0)+" t2="+FloatToStr(t2));
    //writeln(vsh, "Determining quantity of staps and step length: step must be no longer than "+FloatToStr(h));
    //
    while(1.0*(t2-t0)/QSteps>h){
        QSteps++;
        hf=(t2-t0)/QSteps;
    }
    //
    //writeln(vsh, "Was given step length:"+FloatToStr(h)+" Now: step length="+FloatToStr(hf)+" Steps quantity: "+IntToStr(QSteps));
    //
    for(int i=1; i<=Q; i++){
        yr.push_back(y[i-1]);
    }
    //
    //writeln(vsh, "Starting calculation:");
    //writeln(vsh, "Initial conditions:");
    //if(vsh!=NULL){
    //    for(int i=1; i<=Q; i++){
   //         writeln(vsh, "q0["+IntToStr(i)+"]="+FloatToStr(yr[i-1]));
    //    }
    //}
    //
    t=t0;
    for(int i=1; i<=QSteps; i++){
        t+=hf;
        //writeln(vsh,"Step "+IntToStr(i)+" t="+FloatToStr(t));
        //
        yr.clear();
        //
        //yr=RungeSingleStep(Q, yr.data(), fArray, hf, t-hf);
        yr=RungeSingleStep(Q, y, fArray, hf, t-hf);
        //
        for(int j=1; j<=Q; j++){
            y[j-1]=yr[j-1];
        }
        //
        //if(vsh!=NULL){
            //for(int j=1; j<=Q; j++){
            //    writeln(vsh,"yr["+IntToStr(j)+"]="+FloatToStr(yr[j-1]));
            //}
        //}
    }
    //writeln(vsh, "RungeFull: Answer:");
    //for(int i=1; i<=Q; i++){
    //    writeln(vsh, "yr["+IntToStr(i)+"]="+FloatToStr(yr[i-1]));
    //}
    //writeln(vsh, "RungeFull finishes working. Returning answer");
    return yr;
}

//Runge et RungeFull are tested gut

//----------

//Runge et RungeFull are not tested yet


std::vector<double> RungeFull_RCV_PrecCls(int Q, double*y, const std::vector<ODEFunc>&fArray, double t0, double t2, const TItersPrecision&Itersprecision){//, TValsShowHide*vsh){
    double t, hf=Itersprecision.GetCorrectedStepLength(t0, t2);
    std::vector<double>yr;
    int QSteps=Itersprecision.GetCorrectedQIters(t0, t2);
    //
    //writeln(vsh, "RungeFull starts working");
    //writeln(vsh, "Q="+IntToStr(Q)+" h="+FloatToStr(h)+" t0="+FloatToStr(t0)+" t2="+FloatToStr(t2));
    //writeln(vsh, "Determining quantity of staps and step length: step must be no longer than "+FloatToStr(h));
    //
    //while(1.0*(t2-t0)/QSteps>h){
    //    QSteps++;
    //    hf=(t2-t0)/QSteps;
    //}
    //
    //writeln(vsh, " Now: step length="+FloatToStr(hf)+" Steps quantity: "+IntToStr(QSteps));
    //
    for(int i=1; i<=Q; i++){
        yr.push_back(y[i-1]);
    }
    //
    //writeln(vsh, "Starting calculation:");
    //writeln(vsh, "Initial conditions:");
    //if(vsh!=NULL){
    //    for(int i=1; i<=Q; i++){
    //        writeln(vsh, "q0["+IntToStr(i)+"]="+FloatToStr(yr[i-1]));
    //    }
    //}
    //
    t=t0;
    for(int i=1; i<=QSteps; i++){
        t+=hf;
        //writeln(vsh,"Step "+IntToStr(i)+" t="+FloatToStr(t));
        //
        yr.clear();
        //
        //yr=RungeSingleStep(Q, yr.data(), fArray, hf, t-hf);
        yr=RungeSingleStep(Q, y, fArray, hf, t-hf);
        //
        for(int j=1; j<=Q; j++){
            y[j-1]=yr[j-1];
        }
        //
        //if(vsh!=NULL){
        //    for(int j=1; j<=Q; j++){
        //        writeln(vsh,"yr["+IntToStr(j)+"]="+FloatToStr(yr[j-1]));
        //    }
        //}
    }
    //writeln(vsh, "RungeFull: Answer:");
    //for(int i=1; i<=Q; i++){
    //    writeln(vsh, "yr["+IntToStr(i)+"]="+FloatToStr(yr[i-1]));
    //}
    //writeln(vsh, "RungeFull finishes working. Returning answer");
    return yr;
}





void RungeSingleStep_VPP(int n, double*y, const std::vector<ODEFunc>&fArray, double t0, double h){//, TValsShowHide*vsh){
    //void ptr param
    //writeln(vsh,"RungeSingleStep starts working");
    //writeln(vsh,"h="+FloatToStr(h)+" t="+FloatToStr(t0));
    double *k1 = new double[n];
    double *k2 = new double[n];
    double *k3 = new double[n];
    double *k4 = new double[n];
    double *yTmp = new double[n];
    //std::vector<double>yr;
    double yc;
    double val1, val2, val3, val4;
    //
    val1=fArray[1-1](n, t0, y);
    val2=fArray[2-1](n, t0, y);
    val3=fArray[3-1](n, t0, y);
    val4=fArray[4-1](n, t0, y);
    //writeln(vsh,"Calc y");
   // for(int i=0; i<n; i++){
   //     //yr.push_back(y[i]);
   //     writeln(vsh,IntToStr(i)+") "+FloatToStr(y[i]));
   // }
    //k1
    //writeln(vsh,"Calc k1: k1(y[i])=f(t, y[i])");
    for(int i=0; i<n; i++){
        //k1[i]=h*fArray[i](n, t, y);
        yc=fArray[i](n, t0, y);
        k1[i]=yc;
        yc=k1[i];
        //writeln(vsh,IntToStr(i)+") "+FloatToStr(k1[i]));
    }
    //k2
    //writeln(vsh,"Calc k2: k2(y[i])=f(t+h/2, y[i]+h*k1[i])");
    for(int i=0; i<n; i++){
        yTmp[i]=y[i]+h*k1[i]/2.0;
        //writeln(vsh,IntToStr(i)+") yTmp="+FloatToStr(k1[i]));
    }
    for(int i=0; i<n; i++){
        k2[i]=fArray[i](n, t0+h/2, yTmp);
        yc=k2[i];
        //writeln(vsh,IntToStr(i)+") k2="+FloatToStr(k2[i]));
    }
    //k3
    //writeln(vsh,"Calc k3: k3(y[i])=f(t+h/2, y[i]+h*k2[i])");
    for(int i=0; i<n; i++){
        yTmp[i]=y[i]+h*k2[i]/2.0;
        //writeln(vsh,IntToStr(i)+") yTmp="+FloatToStr(k1[i]));
    }
    for(int i=0; i<n; i++){
        k3[i]=fArray[i](n, t0+h/2, yTmp);
        yc=k3[i];
        //writeln(vsh,IntToStr(i)+") k3="+FloatToStr(k3[i]));
    }
    //k4
    //writeln(vsh,"Calc k4: k4(y[i])=f(t+h, y[i]+h*k3[i])");
    for(int i=0; i<n; i++){
        yTmp[i]=y[i]+h*k3[i];
    }
    for(int i=0; i<n; i++){
        k4[i]=fArray[i](n, t0+h, yTmp);
        yc=k4[i];
    }
    //result
    //writeln(vsh,"Summing up: y += h * (k1[i]+ 2*k2[i] + 2*k3[i] + k4[i])/6)");
    for(int i=0; i<n; i++){
        //y[i] += h* (k1[i]+ 2*k2[i] + 2*k3[i] + k4[i])/6;
        //yc += h* (k1[i]+ 2*k2[i] + 2*k3[i] + k4[i])/6;
        yc = h * (k1[i]+ 2*k2[i] + 2*k3[i] + k4[i])/6;
        //yr.push_back(yc);
        y[i]+=yc;
        //writeln(vsh,IntToStr(i)+") yr="+FloatToStr(k3[i]));
    }
    //clear memory
    delete[]k1;
    delete[]k2;
    delete[]k3;
    delete[]k4;
    delete[]yTmp;
    //
    //return yr;
}

//TItersPrecision ItersPrecision;
void RungeFull_VPP_PrecVal(int Q, double*y, const std::vector<ODEFunc>&fArray, double h, double t0, double t2){//, TValsShowHide*vsh){
    double t;
    double hf=h;
    int QSteps=2;
    //writeln(vsh, "RungeFull starts working");
    //writeln(vsh, "Q="+IntToStr(Q)+" h="+FloatToStr(h)+" t0="+FloatToStr(t0)+" t2="+FloatToStr(t2));
   // writeln(vsh, "Determining quantity of staps and step length: step must be no longer than "+FloatToStr(h));
    //
    while(1.0*(t2-t0)/QSteps>h){
        QSteps++;
        hf=(t2-t0)/QSteps;
    }
    //
    //writeln(vsh, "RungeFull starts working");
    //writeln(vsh, "Given: t0="+FloatToStr(t0)+" t2="+FloatToStr(t2));
    //writeln(vsh, "Given: Q="+IntToStr(Q)+" h="+FloatToStr(h));
    ////writeln(vsh, "Determining quantity of staps and step length: step must be no longer than "+FloatToStr(h));
    //writeln(vsh, "Now: Steps quantity: "+IntToStr(QSteps)+" Step length: "+FloatToStr(hf));
    //
    //writeln(vsh, "Starting calculation:");
    //writeln(vsh, "Initial conditions:");
    //if(vsh!=NULL){
    //    for(int i=1; i<=Q; i++){
    //        writeln(vsh, "q0["+IntToStr(i)+"]="+FloatToStr(y[i-1]));
    //    }
    //}
    //
    t=t0;
    for(int i=1; i<=QSteps; i++){
        t+=hf;
        //writeln(vsh,"Step "+IntToStr(i)+" t="+FloatToStr(t));
        //
        //void RungeSingleStep_VPP(int n, double*y, const std::vector<ODEFunc>&fArray, double t0, double h, TValsShowHide*vsh
        RungeSingleStep_VPP(Q, y, fArray, t-hf, hf);//, vsh);
        //
        //if(vsh!=NULL){
        //    for(int j=1; j<=Q; j++){
        //        writeln(vsh,"y["+IntToStr(j)+"]="+FloatToStr(y[j-1]));
        //    }
        //}
    }//for
    //writeln(vsh, "RungeFull: Answer:");
    //for(int i=1; i<=Q; i++){
    //    writeln(vsh, "y["+IntToStr(i)+"]="+FloatToStr(y[i-1]));
    //}
    //writeln(vsh, "RungeFull finishes working. Returning answer");
    ////return yr;
}

//N'nod, s'nod nur h, et whole class s'nod nur in RungeFull
//void RungeSingleStep_VPP_PrecCls(int n, double*y, const std::vector<ODEFunc>&fArray, double t0, const TItersPrecision&ItersPrecisio, TValsShowHide*vsh){
//    //void ptr param
//    //double h=ItersPrecisio.GetCorrectedStepLength(t0, t2);
//    double h=ItersPrecisio.precision;
//    //
//    writeln(vsh,"RungeSingleStep starts working");
//    writeln(vsh,"h="+FloatToStr(h)+" t="+FloatToStr(t0));
//    double *k1 = new double[n];
//    double *k2 = new double[n];
//    double *k3 = new double[n];
//    double *k4 = new double[n];
//    double *yTmp = new double[n];
//    //std::vector<double>yr;
//    double yc;
//    double val1, val2, val3, val4;
//    //
//    val1=fArray[1-1](n, t0, y);
//    val2=fArray[2-1](n, t0, y);
//    val3=fArray[3-1](n, t0, y);
//    val4=fArray[4-1](n, t0, y);
//    writeln(vsh,"Calc y");
//    for(int i=0; i<n; i++){
//        //yr.push_back(y[i]);
//        writeln(vsh,IntToStr(i)+") "+FloatToStr(y[i]));
//    }
//    //k1
//    writeln(vsh,"Calc k1: k1(y[i])=f(t, y[i])");
//    for(int i=0; i<n; i++){
//        //k1[i]=h*fArray[i](n, t, y);//no, h mul in end em all
//        yc=fArray[i](n, t0, y);
//        k1[i]=yc;
//        yc=k1[i];
//        writeln(vsh,IntToStr(i)+") "+FloatToStr(k1[i]));
//    }
//    //k2
//    writeln(vsh,"Calc k2: k2(y[i])=f(t+h/2, y[i]+h*k1[i])");
//    for(int i=0; i<n; i++){
//        yTmp[i]=y[i]+h*k1[i]/2.0;
//        writeln(vsh,IntToStr(i)+") yTmp="+FloatToStr(k1[i]));
//    }
//    for(int i=0; i<n; i++){
//        k2[i]=fArray[i](n, t0+h/2, yTmp);
//        yc=k2[i];
//        writeln(vsh,IntToStr(i)+") k2="+FloatToStr(k2[i]));
//    }
//    //k3
//    writeln(vsh,"Calc k3: k3(y[i])=f(t+h/2, y[i]+h*k2[i])");
//    for(int i=0; i<n; i++){
//        yTmp[i]=y[i]+h*k2[i]/2.0;
//        writeln(vsh,IntToStr(i)+") yTmp="+FloatToStr(k1[i]));
//    }
//    for(int i=0; i<n; i++){
//        k3[i]=fArray[i](n, t0+h/2, yTmp);
//        yc=k3[i];
//        writeln(vsh,IntToStr(i)+") k3="+FloatToStr(k3[i]));
//    }
//    //k4
//    writeln(vsh,"Calc k4: k4(y[i])=f(t+h, y[i]+h*k3[i])");
//    for(int i=0; i<n; i++){
//        yTmp[i]=y[i]+h*k3[i];
//    }
//    for(int i=0; i<n; i++){
//        k4[i]=fArray[i](n, t0+h, yTmp);
//        yc=k4[i];
//    }
//    //result
//    writeln(vsh,"Summing up: y += h * (k1[i]+ 2*k2[i] + 2*k3[i] + k4[i])/6)");
//    for(int i=0; i<n; i++){
//        //y[i] += h* (k1[i]+ 2*k2[i] + 2*k3[i] + k4[i])/6;
//        //yc += h* (k1[i]+ 2*k2[i] + 2*k3[i] + k4[i])/6;
//        yc = h * (k1[i]+ 2*k2[i] + 2*k3[i] + k4[i])/6;
//        //yr.push_back(yc);
//        y[i]+=yc;
//        writeln(vsh,IntToStr(i)+") yr="+FloatToStr(k3[i]));
//    }
//    //clear memory
//    delete[]k1;
//    delete[]k2;
//    delete[]k3;
//    delete[]k4;
//    delete[]yTmp;
//    //
//    //return yr;
//}

//TItersPrecision ItersPrecision;
void RungeFull_VPP_PrecCls(int Q, double*y, const std::vector<ODEFunc>&fArray, double t0, double t2, const TItersPrecision&ItersPrecision){//, TValsShowHide*vsh){
    double t;
    double hf=ItersPrecision.GetCorrectedStepLength(t0, t2);
    int QSteps=ItersPrecision.GetCorrectedQIters(t0, t2);
    //
    //writeln(vsh, "RungeFull starts working");
   //writeln(vsh, "Given: t0="+FloatToStr(t0)+" t2="+FloatToStr(t2));
    //writeln(vsh, "Given: Q="+IntToStr(Q)+" h="+FloatToStr(ItersPrecision.precision));
    ////writeln(vsh, "Determining quantity of staps and step length: step must be no longer than "+FloatToStr(h));
    //writeln(vsh, "Now: Steps quantity: "+IntToStr(QSteps)+" Step length: "+FloatToStr(hf));
    //
    //writeln(vsh, "Starting calculation:");
   // writeln(vsh, "Initial conditions:");
    //if(vsh!=NULL){
    //    for(int i=1; i<=Q; i++){
    //        writeln(vsh, "q0["+IntToStr(i)+"]="+FloatToStr(y[i-1]));
    //    }
    //}
    //
    t=t0;
    for(int i=1; i<=QSteps; i++){
        t+=hf;
        //writeln(vsh,"Step "+IntToStr(i)+" t="+FloatToStr(t));
        //
        //void RungeSingleStep_VPP(int n, double*y, const std::vector<ODEFunc>&fArray, double t0, double h, TValsShowHide*vsh
        RungeSingleStep_VPP(Q, y, fArray, t-hf, hf);//, vsh);
        //
        //if(vsh!=NULL){
        //    for(int j=1; j<=Q; j++){
        //        writeln(vsh,"y["+IntToStr(j)+"]="+FloatToStr(y[j-1]));
        //    }
       // }
    }//for
    //writeln(vsh, "RungeFull: Answer:");
    //for(int i=1; i<=Q; i++){
    //    writeln(vsh, "y["+IntToStr(i)+"]="+FloatToStr(y[i-1]));
    //}
    //writeln(vsh, "RungeFull finishes working. Returning answer");
    ////return yr;
}



//std::vector<double> RungeSingleStep_RSV_PrecCls(int n, double*y, const std::vector<ODEFunc>&fArray, const TItersPrecision&ItersPrecisio, double t, TValsShowHide*vsh){
//    double h=ItersPrecisio.precision;
//    writeln(vsh,"RungeSingleStep starts working");
//    writeln(vsh,"h="+FloatToStr(h)+" t="+FloatToStr(t));
//    double *k1 = new double[n];
//    double *k2 = new double[n];
//    double *k3 = new double[n];
//    double *k4 = new double[n];
//    double *yTmp = new double[n];
//    std::vector<double>yr;
//    double yc;
//    double val1, val2, val3, val4;
//    //
//    val1=fArray[1-1](n, t, y);
//    val2=fArray[2-1](n, t, y);
//    val3=fArray[3-1](n, t, y);
//    val4=fArray[4-1](n, t, y);
//    writeln(vsh,"Calc y");
//    for(int i=0; i<n; i++){
//        yr.push_back(y[i]);
//        writeln(vsh,IntToStr(i)+") "+FloatToStr(yr[i]));
//    }
//    //k1
//    writeln(vsh,"Calc k1: k1(y[i])=f(t, y[i])");
//    for(int i=0; i<n; i++){
//        //k1[i]=h*fArray[i](n, t, y);
//        yc=fArray[i](n, t, y);
//        k1[i]=yc;
//        yc=k1[i];
//        writeln(vsh,IntToStr(i)+") "+FloatToStr(k1[i]));
//    }
//    //k2
//    writeln(vsh,"Calc k2: k2(y[i])=f(t+h/2, y[i]+h*k1[i])");
//    for(int i=0; i<n; i++){
//        yTmp[i]=y[i]+h*k1[i]/2.0;
//        writeln(vsh,IntToStr(i)+") yTmp="+FloatToStr(k1[i]));
//    }
//    for(int i=0; i<n; i++){
//        k2[i]=fArray[i](n, t+h/2, yTmp);
//        yc=k2[i];
//        writeln(vsh,IntToStr(i)+") k2="+FloatToStr(k2[i]));
//    }
//    //k3
//    writeln(vsh,"Calc k3: k3(y[i])=f(t+h/2, y[i]+h*k2[i])");
//    for(int i=0; i<n; i++){
//        yTmp[i]=y[i]+h*k2[i]/2.0;
//        writeln(vsh,IntToStr(i)+") yTmp="+FloatToStr(k1[i]));
//    }
//    for(int i=0; i<n; i++){
//        k3[i]=fArray[i](n, t+h/2, yTmp);
//        yc=k3[i];
//        writeln(vsh,IntToStr(i)+") k3="+FloatToStr(k3[i]));
//    }
//    //k4
//    writeln(vsh,"Calc k4: k4(y[i])=f(t+h, y[i]+h*k3[i])");
//    for(int i=0; i<n; i++){
//        yTmp[i]=y[i]+h*k3[i];
//    }
//    for(int i=0; i<n; i++){
//        k4[i]=fArray[i](n, t+h, yTmp);
//        yc=k4[i];
//    }
//    //result
//    writeln(vsh,"Summing up: y1 += h * (k1[i]+ 2*k2[i] + 2*k3[i] + k4[i])/6)");
//    for(int i=0; i<n; i++){
//        //y[i] += h* (k1[i]+ 2*k2[i] + 2*k3[i] + k4[i])/6;
//        //yc += h* (k1[i]+ 2*k2[i] + 2*k3[i] + k4[i])/6;
//        yc = h * (k1[i]+ 2*k2[i] + 2*k3[i] + k4[i])/6;
//        //yr.push_back(yc);
//        yr[i]+=yc;
//        writeln(vsh,IntToStr(i)+") yr="+FloatToStr(k3[i]));
//    }
//    //clear memory
//    delete[]k1;
//    delete[]k2;
//    delete[]k3;
//    delete[]k4;
//    delete[]yTmp;
//    //
//    return yr;
//}





//-----------------------------------------------------------------------------------------------------------------

std::vector<double>PolynomeEqGenerator(double*ReX, int QRoots){
    std::vector<double>c;
    int ord;
    double K=1;
    double a30, a31, a32, a33,
           a40, a41, a42, a43, a44,
           a50, a51, a52, a53, a54, a55,
           a60, a61, a62, a63, a64, a65, a66,
           a70, a71, a72, a73, a74, a75, a76, a77;
    if (QRoots >= 2 && QRoots <= 4){
        ord = QRoots;
        //this.c = new double[ord + 1];
        //this.ReX = new double[QRoots];
        //this.ImX = new double[QRoots];
        //for (int i = 1; i <= QRoots; i++)
        //{
        //    this.ReX[i - 1] = ReX[i - 1];
        //    this.ImX[i - 1] = 0;
        //}
        //
        for (int i = 1; i <= QRoots+1; i++){
            c.push_back(0);
        }
        //et so s'>gut ut iqv
        //for (int i = 1; i <= QRoots; i++){
        //    c.push_back(ReX[i-1]);
        //}
        //c.push_back(0);
        //
        if(QRoots>2){
            a33 = K * 1;
            a32 = -K * (ReX[1 - 1] + ReX[2 - 1] + ReX[3 - 1]);
            a31 = K * (ReX[1 - 1] + ReX[2 - 1]) * +ReX[3 - 1] + ReX[1 - 1] * ReX[2 - 1];
            a30 = -K * (ReX[1 - 1] * ReX[2 - 1] * ReX[3 - 1]);
        }
        if(QRoots>3){
            a44 = a33;
            a43 = a32 - ReX[4 - 1] * a33;
            a43 = -K * (ReX[1 - 1] + ReX[2 - 1] + ReX[3 - 1] + ReX[4 - 1]);
            a42 = a31 - ReX[4 - 1] * a32;
            a42 = K * ((ReX[1 - 1] + ReX[2 - 1]) * ReX[3 - 1] + ReX[1 - 1] * ReX[2 - 1] + ReX[4 - 1] * (ReX[1 - 1] + ReX[2 - 1] + ReX[3 - 1]));
            a41 = a30 - ReX[4 - 1] * a31;
            a40 = -ReX[4 - 1] * a30;
            a40 = K * ReX[1 - 1] * ReX[2 - 1] * ReX[3 - 1] * ReX[4 - 1];
        }
        //
        switch (QRoots){
            case 2:
                c[0]=ReX[1 - 1] * ReX[2 - 1];
                c[1]=-(ReX[1 - 1] + ReX[2 - 1]);
                c[2]=1;
            break;
            case 3:
                c[0] = a30;
                c[1] = a31;
                c[2] = a32;
                c[3] = a33;
            break;
            case 4:
                c[0] = a40;
                c[1] = a41;
                c[2] = a42;
                c[3] = a43;
                c[4] = a44;
            break;
            case 5:
            break;
            case 6:
            break;
        }
    }
    return c;
}

std::vector<std::vector<int>>ComplexArrayFindConjugated(int Q, double*ReX, double*ImX, double precision){
    std::vector<int>pair;
    std::vector<std::vector<int>>Pairs;
    for(int i=1; i<=Q-1; i++){
        for(int j=i+1; j<=Q; j++){
            if(fApprET(ReX[i-1], ReX[j-1], precision)  && fApprET(ImX[i-1], -ImX[j-1], precision) && fApprNE(ImX[i-1], 0, precision) && fApprNE(ImX[j-1], 0, precision)){
                pair.clear();
                pair.push_back(i);
                pair.push_back(j);
                Pairs.push_back(pair);
            }
        }
    }
    return Pairs;
}
