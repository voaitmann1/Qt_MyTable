#include "tests1.h"


//tests1::tests1()
//{
//
//}

//class ThrownCorper{
//    double g;


double fRungeTest1RPE1(int n, double t, const double*y){
    double g=9.81;
    return -g;
}

double fRungeTest1RPE2(int n, double t, const double*y){
    return 0;
}

double fRungeTest1RPE3(int n, double t, const double*y){
    return y[1-1];
}

double fRungeTest1RPE4(int n, double t, const double*y){
    return y[2-1];
}

void TestRungeSimple(){
    double V=4/sqrt(2)*2.0,//4,//20,
           AngleDeg=45,//30,
           g=9.81,
           Tfin0=2,
           dt0=0.1,
           H=6,
           Tfin=2, dt=0.1, tCur=0;
    //ODEFunc fArray[]={fRungeTest1RPE1, fRungeTest1RPE2, fRungeTest1RPE3, fRungeTest1RPE4};
    std::vector<ODEFunc> fArray={fRungeTest1RPE1, fRungeTest1RPE2, fRungeTest1RPE3, fRungeTest1RPE4};
    std::cout<<"Testing RungeKutta method UDE integrating"<<std::endl;//vy, vx, y, x
    std::cout<<"Corp thrown by angle to horisont, V="<<V<<" AngleDeg="<<AngleDeg<<std::endl;
    std::cout<<"t0="<<Tfin<<" dt=h="<<dt<<std::endl;
    std::cout<<"Ini sys of 2nd order:"<<std::endl;
    std::cout<<"d2y/dt2=G"<<std::endl;
    std::cout<<"d2x/dt2=0"<<std::endl;
    std::cout<<"Eqv sys of 1st order:"<<std::endl;
    std::cout<<"dVy/dt=-G/m=-g"<<std::endl;
    std::cout<<"dVx/dt=0"<<std::endl;
    std::cout<<"dx/dt=Vx"<<std::endl;
    std::cout<<"dy/dt=Vy"<<std::endl;
    std::cout<<"Solution:"<<std::endl;
    double Vy, Vx, Y, X;
    int Q=2*2, StepN=0;
    std::vector<double>yr, yr0;
    double ymin, ymax;
    //double*y=new double[Q];
    std::cout<<"Vars Zug are: Vy, Vx, y, x"<<std::endl;
    Vy=V*sin(AngleDeg*M_PI/180);
    Vx=V*cos(AngleDeg*M_PI/180);
    Y=H;
    X=0;
    yr.push_back(Vy);
    yr.push_back(Vx);
    yr.push_back(Y);
    yr.push_back(X);
    ymin=Y;
    ymax=X;
    //
    //std::vector<double> RungeFull(      int Q, double*y, ODEFunc*fArray, double h, double t0, double t);
    //RungeFull(                                Q,        y,         fArray, dt,               0,     Tfin);
    std::cout<<"StepN"<<StepN<<" tCur="<<tCur<<"(1) Vy="<<yr[1-1]<<"(2) Vx="<<yr[2-1]<<"(3) y="<<yr[3-1]<<"(4) x="<<yr[4-1]<<std::endl;
    for(StepN=1; StepN<=20; StepN++){
        tCur+=dt;
        //yr0=yr;
        yr=RungeSingleStep(Q, yr.data(), fArray, dt, tCur);
        Vy=yr[1-1];
        Vx=yr[2-1];
        Y =yr[3-1];
        X =yr[4-1];
        std::cout<<"StepN"<<StepN<<" tCur="<<tCur<<" Vy="<<Vy<<" Vx="<<Vx<<" y="<<Y<<" x="<<X<<std::endl;
        if(Y<ymin){
            ymin=Y;
        }
        if(Y>ymax){
            ymax=Y;
        }
    }
    std::cout<<std::endl;
    std::cout<<"SingleProcess result:"<<std::endl;
    StepN=0;
    tCur=0;
    Vy=V*sin(AngleDeg*M_PI/180);
    Vx=V*cos(AngleDeg*M_PI/180);
    Y=H;
    X=0;
    yr.clear();
    yr.push_back(Vy);
    yr.push_back(Vx);
    yr.push_back(Y);
    yr.push_back(X);
    std::cout<<"StepN"<<StepN<<" t="<<Tfin<<" Vy="<<Vy<<" Vx="<<Vx<<" y="<<Y<<" x="<<X<<std::endl;
    yr=RungeFull(Q, yr.data(), fArray, dt0, tCur, Tfin);
    Vy=yr[1-1];
    Vx=yr[2-1];
    Y =yr[3-1];
    X =yr[4-1];
    std::cout<<" t="<<Tfin<<" Vy="<<Vy<<" Vx="<<Vx<<" y="<<Y<<" x="<<X<<std::endl;
}//

void TestRungeClass(){
    ThrownCorper corp;
    TValsShowHide vsh;
    std::vector<double>yr;
    std::cout<<"TestRungeClass (vReturning) starts working"<<std::endl;
    std::cout<<"Testing Runge with class methods"<<std::endl;
    double V=4/sqrt(2)*2.0,//4,//20,
           AngleDeg=45,//30,
           g=9.81,
           Tfin0=2,
           dt0=0.1,
           H=6,
           Tfin=2, dt=0.1, tCur=0;
    vsh.ConsoleInterface=true;
    vsh.EnableWriting();
    double Vy, Vx, Y, X;
    writeln(&vsh,"(1) Vy="+FloatToStr(V*sin(AngleDeg*M_PI/180))+"(2) Vx="+FloatToStr(V*cos(AngleDeg*M_PI/180))+"(3) y="+FloatToStr(H)+"(4) x="+FloatToStr(0.0000));
    std::cout<<"1) Vy="<<V*sin(AngleDeg*M_PI/180)<<"(2) Vx="<<V*cos(AngleDeg*M_PI/180)<<"(3) y="<<H<<"(4) x="<<0<<std::endl;
    yr=corp.Calc_ByAngle(2, V, AngleDeg, H, 0, 0, dt0);//, &vsh);
    std::cout<<yr.size()<<" values returned"<<std::endl;
    Vy=yr[1-1];
    Vx=yr[2-1];
    Y =yr[3-1];
    X =yr[4-1];
    std::cout<<"Answer: t="<<Tfin<<" Vy="<<Vy<<" Vx="<<Vx<<" y="<<Y<<" x="<<X<<std::endl;
    std::cout<<"TestRungeClass (vReturning) finishes working"<<std::endl;
}

void TestRungeClass_vVoid(){
    ThrownCorper corp;
    TValsShowHide vsh;
    double yr[4];//std::vector<double>yr;
    std::cout<<"TestRungeClass (vVoid) starts working"<<std::endl;
    std::cout<<"Testing Runge with class methods"<<std::endl;
    double V=4/sqrt(2)*2.0,//4,//20,
           AngleDeg=45,//30,
           g=9.81,
           Tfin0=2,
           dt0=0.1,
           H=6,
           Tfin=2, dt=0.1, tCur=0;
    vsh.ConsoleInterface=true;
    vsh.EnableWriting();
    double Vy, Vx, Y=H, X=0;
    writeln(&vsh,"(1) Vy="+FloatToStr(V*sin(AngleDeg*M_PI/180))+"(2) Vx="+FloatToStr(V*cos(AngleDeg*M_PI/180))+"(3) y="+FloatToStr(H)+"(4) x="+FloatToStr(0.0000));
    //std::cout<<"1) Vy="<<V*sin(AngleDeg*M_PI/180)<<"(2) Vx="<<V*cos(AngleDeg*M_PI/180)<<"(3) y="<<H<<"(4) x="<<X<<std::endl;
    //yr[1-1]=Vy;
    //yr[2-1]=Vx;
   // yr[3-1]=Y;
    //yr[4-1]=X;
    //^ that worked. Ma I vil >gut
    corp.SetIniConds(yr, V, AngleDeg, H, X);
    Vy=yr[1-1];
    Vx=yr[2-1];
    Y=yr[3-1];
    X=yr[4-1];
    std::cout<<"checking ini conds: Vy="<<V*sin(AngleDeg*M_PI/180)<<"(2) Vx="<<V*cos(AngleDeg*M_PI/180)<<"(3) y="<<H<<"(4) x="<<X<<std::endl;
    //yr=corp.Calc_ByAngle(2, V, AngleDeg, H, 0, 0, dt0);//, &vsh);
    //void ThrownCorper::Calc_As1stOrderSys_VPP(double*q, double t, double t0, double dt)
    corp.                Calc_As1stOrderSys_VPP(      yr,     Tfin,      tCur,       dt0);
    //std::cout<<yr.size()<<" values returned"<<std::endl;
    Vy=yr[1-1];
    Vx=yr[2-1];
    Y =yr[3-1];
    X =yr[4-1];
    std::cout<<"Answer: t="<<Tfin<<" Vy="<<Vy<<" Vx="<<Vx<<" y="<<Y<<" x="<<X<<std::endl;
    std::cout<<"TestRungeClass (vVoid) finishes working"<<std::endl;
}

void TestPolynomialEqsPowerFrom2To4(){
    std::cout<<"Testing equations: generation and solving"<<std::endl;
    std::vector<double>ReX, C, ImX;
    int order, ErrN;
    double cc;
    ReX.push_back(5);
    ReX.push_back(6);
    ReX.push_back(7);
    ReX.push_back(4);
    order=ReX.size();
    std::cout<<"Equation of "<<order<<": "<<std::endl;
    std::cout<<"Let roots be:"<<std::endl;
    for(int i=1; i<=order-1; i++){
        std::cout<<ReX[i-1];
        std::cout<<"; ";
    }
    std::cout<<ReX[order-1]<<std::endl;
    //
    std::cout<<"Generating equation:"<<std::endl;
    //
    C=PolynomeEqGenerator(ReX.data(), ReX.size());
    //
    ReX.clear();
    //
    for(int ordN=order; ordN>=0; ordN--){
        cc=C[ordN];
        if(C[ordN]!=0){
            if(cc>=0 && ordN<order){
                std::cout<<" + ";
            }
            if(C[ordN-1]!=1.0){
                std::cout<<cc;
            }
            if(ordN>=1){
                std::cout<<"X";
                if(ordN>=2){
                    std::cout<<"^"<<ordN;
                }
            }
        }
    }
    std::cout<<" = 0 "<<std::endl;
    //
    std::cout<<"Solving equation:"<<std::endl;
    //
    switch(order){
        case 2:
            EquationQuadratic(C.data(), ReX, ImX);//works well
            //EquationQuadratic(C, ReX, ImX);//works well
        break;
        case 3:
            EquationCubic(C.data(), ReX, ImX);
        break;
        case 4:
            ErrN=EquationOf4thPower(C.data(), ReX, ImX);
        break;
    }
    //
    std::cout<<"Answer:"<<std::endl;
    //
    for(int i=1; i<=order; i++){
        std::cout<<i<<") ReX="<<ReX[i-1]<<"; ImX="<<ImX[i-1]<<std::endl;
    }
}

void TestPolynomialEqsPowerFrom2To4_AsClass(){
    std::cout<<"Testing equations: generation and solving - As class"<<std::endl;
    PolyEq eqn;
    std::vector<double>ReX, C, ImX;
    int order, ErrN;
    double cc;
    ReX.push_back(5);
    ReX.push_back(6);
    ReX.push_back(7);
    ReX.push_back(4);
    order=ReX.size();
    std::cout<<"Generating equation of "<<order<<" power, whish has roots:"<<std::endl;
    for(int i=1; i<=order; i++){
        std::cout<<ReX[i-1]<<"; ";
    }
    std::cout<<std::endl;
    //
    eqn.SetEquationAndCalcSolution(ReX.data(), ReX.size(), false);
    std::cout<<"Equation generated:"<<std::endl;
    std::cout<<eqn.EquationToString().toStdString()<<std::endl;
    std::cout<<"Answer:"<<std::endl;
    ReX.clear();
    ImX.clear();
    C.clear();
    eqn.GetRoots(ReX, ImX);
    //
    for(int i=1; i<=order; i++){
        std::cout<<i<<") ReX="<<ReX[i-1]<<"; ImX="<<ImX[i-1]<<std::endl;
    }
    std::cout<<eqn.SolutionToString().toStdString()<<std::endl;
    //
    std::cout<<std::endl<<"Solving 2nd equation of "<<order<<" power, whish has coefs:"<<std::endl;
    C.clear();
    //C.push_back(1);
    //C.push_back(-22);
    //C.push_back(179);
    //C.push_back(-638);
    //C.push_back(840);
    //
    C.push_back(840);
    C.push_back(-638);
    C.push_back(179);
    C.push_back(-22);
    C.push_back(1);
    eqn.SetEquationAndCalcSolution(C.data(), C.size());
    std::cout<<"Equation given:"<<std::endl;
    std::cout<<eqn.EquationToString().toStdString()<<std::endl;
    std::cout<<"Answer:"<<std::endl;
    ReX.clear();
    ImX.clear();
    C.clear();
    eqn.GetRoots(ReX, ImX);
    //
    for(int i=1; i<=order; i++){
        std::cout<<i<<") ReX="<<ReX[i-1]<<"; ImX="<<ImX[i-1]<<std::endl;
    }
    std::cout<<eqn.SolutionToString().toStdString()<<std::endl;
    //
    std::cout<<std::endl<<"Solving 3rd equation of "<<order<<" power, whish has coefs:"<<std::endl;
    C.clear();
    C.push_back(1);
    C.push_back(-22);
    C.push_back(179);
    C.push_back(-638);
    C.push_back(840);
    //
    //C.push_back(840);
    //C.push_back(-638);
    //C.push_back(179);
    //C.push_back(-22);
    //C.push_back(1);
    eqn.SetEquationAndCalcSolution(C.data(), C.size());
    std::cout<<"Equation given:"<<std::endl;
    std::cout<<eqn.EquationToString().toStdString()<<std::endl;
    std::cout<<"Answer:"<<std::endl;
    ReX.clear();
    ImX.clear();
    C.clear();
    eqn.GetRoots(ReX, ImX);
    //
    for(int i=1; i<=order; i++){
        std::cout<<i<<") ReX="<<ReX[i-1]<<"; ImX="<<ImX[i-1]<<std::endl;
    }
    std::cout<<eqn.SolutionToString().toStdString()<<std::endl;
    //
    order=3;
    ReX.clear();
    ImX.clear();
    C.clear();
    std::cout<<std::endl<<"Solving 4th equation of "<<order<<" power, by its functions, working with data not only of class, but also external:"<<std::endl;
    std::cout<<"Equation of 3th power: X^3+3*X^2+3*X+1=0"<<std::endl;
    eqn.EquationCubic(1, 3, 3, 1, ReX, ImX);
    std::cout<<"Answer:"<<std::endl;
    for(int i=1; i<=order; i++){
        std::cout<<i<<") ReX="<<ReX[i-1]<<"; ImX="<<ImX[i-1]<<std::endl;
    }
    //
    order=4;
    ReX.clear();
    ImX.clear();
    C.clear();
    std::cout<<std::endl<<"Solving 5th equation of "<<order<<" power, by its functions, working with data not only of class, but also external:"<<std::endl;
    std::cout<<"Equation of 4th power: X^4 + 20*X^3 + 1*X^2 + 10*X + 180 =0"<<std::endl;
    eqn.EquationOf4thPower(1, 20, 1, 10, 180, ReX, ImX);
    std::cout<<"Answer:"<<std::endl;
    for(int i=1; i<=order; i++){
        std::cout<<i<<") ReX="<<ReX[i-1]<<"; ImX="<<ImX[i-1]<<std::endl;
    }
}



void TestPolynomialEqsPowerFrom2To4_AsClass_complex(){
    std::cout<<"Testing equations: solving - As class (here - complex roots)"<<std::endl;
    PolyEq eqn;
    std::vector<double>ReX, C, ImX;
    int order, ErrN;
    double cc;
    ReX.push_back(5);
    ReX.push_back(6);
    ReX.push_back(7);
    ReX.push_back(4);
    order=ReX.size();

    std::cout<<std::endl<<"Solving 2nd equation of "<<order<<" power, whish has coefs:"<<std::endl;
    C.clear();
    //C.push_back(1);
    //C.push_back(-10);
    //C.push_back(46);
    //C.push_back(-90);
    //C.push_back(125);
    //
    C.push_back(125);
    C.push_back(-90);
    C.push_back(46);
    C.push_back(-10);
    C.push_back(1);
    eqn.SetEquationAndCalcSolution(C.data(), C.size());
    std::cout<<"Equation given:"<<std::endl;
    std::cout<<"(Solution should be: 1+-2i, 4+-s3i)"<<std::endl;
    std::cout<<eqn.EquationToString().toStdString()<<std::endl;
    std::cout<<"Answer:"<<std::endl;
    ReX.clear();
    ImX.clear();
    C.clear();
    eqn.GetRoots(ReX, ImX);
    //
    for(int i=1; i<=order; i++){
        std::cout<<i<<") ReX="<<ReX[i-1]<<"; ImX="<<ImX[i-1]<<std::endl;
    }
    std::cout<<eqn.SolutionToString().toStdString()<<std::endl;
    //
    std::cout<<std::endl<<"Solving 3rd equation of "<<order<<" power, whish has coefs:"<<std::endl;
    C.clear();
    C.push_back(1);
    C.push_back(-22);
    C.push_back(179);
    C.push_back(-638);
    C.push_back(840);
    //
    //C.push_back(840);
    //C.push_back(-638);
    //C.push_back(179);
    //C.push_back(-22);
    //C.push_back(1);
    eqn.SetEquationAndCalcSolution(C.data(), C.size());
    std::cout<<"Equation given:"<<std::endl;
    std::cout<<eqn.EquationToString().toStdString()<<std::endl;
    std::cout<<"Answer:"<<std::endl;
    ReX.clear();
    ImX.clear();
    C.clear();
    eqn.GetRoots(ReX, ImX);
    //
    for(int i=1; i<=order; i++){
        std::cout<<i<<") ReX="<<ReX[i-1]<<"; ImX="<<ImX[i-1]<<std::endl;
    }
    std::cout<<eqn.SolutionToString().toStdString()<<std::endl;
    //
    order=3;
    ReX.clear();
    ImX.clear();
    C.clear();
    std::cout<<std::endl<<"Solving 4th equation of "<<order<<" power, by its functions, working with data not only of class, but also external:"<<std::endl;
    std::cout<<"Equation of 3th power: X^3+3*X^2+3*X+1=0"<<std::endl;
    eqn.EquationCubic(1, 3, 3, 1, ReX, ImX);
    std::cout<<"Answer:"<<std::endl;
    for(int i=1; i<=order; i++){
        std::cout<<i<<") ReX="<<ReX[i-1]<<"; ImX="<<ImX[i-1]<<std::endl;
    }
    //
    order=4;
    ReX.clear();
    ImX.clear();
    C.clear();
    std::cout<<std::endl<<"Solving 5th equation of "<<order<<" power, by its functions, working with data not only of class, but also external:"<<std::endl;
    std::cout<<"Equation of 4th power: X^4 + 20*X^3 + 1*X^2 + 10*X + 180 =0"<<std::endl;
    eqn.EquationOf4thPower(1, 20, 1, 10, 180, ReX, ImX);
    std::cout<<"Answer:"<<std::endl;
    for(int i=1; i<=order; i++){
        std::cout<<i<<") ReX="<<ReX[i-1]<<"; ImX="<<ImX[i-1]<<std::endl;
    }
}


void TestComplexNum(){
    double k=20;
    ComplexNum x1(3, 2), x2(4,-1);
    std::cout<<"x1="<<x1.ToString().toStdString()<<" x2="<<x2.ToString().toStdString()<<" k="<<FloatToStr(k).toStdString()<<std::endl;
    ComplexNum
        ya=x1+x2,
        ys=x1-x2,
        ym=x1*x2,
        ymr1=x1*k,
        ymr2=k*x2,
        yd=x1/x2;
    //x1/=x2;
    //std::cout<<"x1="<<x1.ToString().toStdString()<<" x2="<<x2.ToString().toStdString()<<" k="<<FloatToStr(k).toStdString()<<std::endl;
    std::cout<<"ya=x1+x2="<<ya.ToString().toStdString()<<std::endl;
    std::cout<<"ys=x1-x2="<<ys.ToString().toStdString()<<std::endl;
    std::cout<<"ym=x1*x2="<<ym.ToString().toStdString()<<std::endl;
    std::cout<<"yd=x1/x2="<<yd.ToString().toStdString()<<std::endl;
    std::cout<<"ymr1=x1*k="<<ymr1.ToString().toStdString()<<std::endl;
    std::cout<<"ymr2=k*x2="<<ymr2.ToString().toStdString()<<std::endl;
    x1/=x2;
    std::cout<<"x1/=x2="<<x1.ToString().toStdString()<<std::endl;
}

/*
void TestFlutterModel_SingleIsolatedBladeNoFriction_v1(){
    bool b;
    Flutter_IsolatedBladeNoFriction_Data data0(b);//error, ma nu no err
    //std::cout<<"Testing dyn"<<std::endl;
    //Flutter_IsolatedBladeNoFriction_Data*dataD=new Flutter_IsolatedBladeNoFriction_Data(b);
    //delete dataD;
    //std::cout<<"Testing stat"<<std::endl;
    //Flutter_IsolatedBladeNoFriction_Data data(b);
    std::cout<<"Testing finished"<<std::endl;
}
*/

void TestFlutterModel_SingleIsolatedBladeNoFriction_v2(){
    double beta_2=-394, beta_1=3, beta=-1, fi_2=5, fi_1=7, fi=9,
           RP_S1_E1, RP_S1_E2,
           RP_S2_ord2_EBeta, RP_S2_ord2_EFi,
           RP_S2_ord1_E1, RP_S2_ord1_E2, RP_S2_ord1_E3, RP_S2_ord1_E4,
           det_beta_1, det_fi_1;
    double t=0;
    // double arr[8];
    double arr[4];
    Flutter_IsolatedBladeNoFriction_Data_v1 model;
    Flutter_IsolatedBladeNoFriction_Data_v1_IncomingHelicParams iniData;
    Flutter_IsolatedBladeNoFriction_Data_v1_ParamsIniForCalcEquations coefsIni1, coefsIni2;
    std::cout<<"TestFlutterModel_SingleIsolatedBladeNoFriction_v2 starts working"<<std::endl;
    model.SetIniHelicData(iniData);
    coefsIni2.SetTestValues();
    model.Calc4_UDECoefs_IniSys1(coefsIni2);
    RP_S1_E1=model.f_S1E1_RP(beta_1, fi_1, beta, fi);
    RP_S1_E2=model.f_S1E2_RP(beta_1, fi_1, beta, fi);
    //
    RP_S2_ord2_EBeta=model.f_S2EBeta_RP(beta_1, fi_1, beta, fi);
    RP_S2_ord2_EFi=model.f_S2EFi_RP(beta_1, fi_1, beta, fi);
    std::cout<<"First system"<<std::endl;
    std::cout<<"beta\" = RP1(beta', beta, fi ',fi)"<<std::endl;
    std::cout<<"fi\" = RP2(beta', beta, fi ',fi)"<<std::endl;
    std::cout<<"System solved as lin rel its 2nd derivs - sys of 2 equations of 2nd order:"<<std::endl;
    std::cout<<"w_beta'="<<beta_2<<" Rp1="<<RP_S2_ord2_EBeta<<std::endl;
    std::cout<<"w_fi'  ="<<fi_2<<" Rp2="<<RP_S2_ord2_EFi<<std::endl;
    std::cout<<"System of 2 equqtions of 1st order:"<<std::endl;
    arr[1-1]=beta_1;
    arr[2-1]=fi_1;
    arr[3-1]=beta;
    arr[4-1]=fi;
    std::cout<<"w_fi' ="<<beta_2<<"  = RP1(beta', beta, fi ',fi)="<<model.f_Eq1_RP_wBeta(4, t, arr)<<std::endl;
    std::cout<<"w_fi' ="<<fi_2<<"  = RP2(beta', beta, fi ',fi)="<<model.f_Eq2_RP_wFi(4, t, arr)<<std::endl;
    std::cout<<"beta' ="<<beta_1<<"  = RP3(beta', beta, fi ',fi)="<<model.f_Eq3_RP_Beta(4, t, arr)<<std::endl;
    std::cout<<"fi' ="<<fi_1<<"  = RP3(beta', beta, fi ',fi)="<<model.f_Eq4_RP_Fi(4, t, arr)<<std::endl;
    //
    std::cout<<"TestFlutterModel_SingleIsolatedBladeNoFriction_v2 finishes working"<<std::endl;
}

void TestReadCSVLine(){
    //ReadCsvLine(QString line, std::vector<QString>delims, int MoreThanOneDelim_Empty0_SingleDelim1=0);
    QString line1="12.4,7,5,,,,5",
            line2=" 12 ; 3.5 ; 34;",
            line3=" 12 ; 3.5 ; 34",
            line4="12 ; 3.5 ; 34;";
    int QW, QD;
    TValsShowHide vsh;
    //TValsShowHide*vsh;=NULL:
    vsh.DisableWriting();
    //vsh.EnableWriting();
    vsh.ConsoleInterface=true;
    std::vector<QString>delims, words;
    std::cout<<"Test reqading CSV line starts working"<<std::endl;
    delims.push_back(";");
    delims.push_back(" ");
    delims.push_back(",");
    std::cout<<"Delims:"<<std::endl;
    QD=delims.size();
    std::cout<<QD<<" elements"<<std::endl;
    for(int i=1; i<=QD; i++){
        std::cout<<delims[i-1].toStdString()+" ";
        std::cout<<std::endl;
    }
    //std::cout<<std::endl;

    std::cout<<"reading line1: "+line1.toStdString()+"(2 delims = empty word between, first delim = first empty, last delim = last empty)"<<std::endl;
    //words=ReadCsvLine2(line1, delims, 0);
    words=ReadCsvLine2(line1, delims, 0, &vsh);
    //VectorStdCout(T*x, int Q, std::string delim="; ", bool represent2DNot1D=false)
    //VectorStdCout(words.data(), words.size(), "; ", false);
    QW=words.size();
    std::cout<<QW<<" elements"<<std::endl;
    for(int i=1; i<=QW; i++){
        std::cout<<words[i-1].toStdString()+" ";
        std::cout<<std::endl;
    }
    //std::cout<<std::endl;
    words.clear();
    std::cout<<"reading line1: "+line1.toStdString()+"( >1 delims = 1 long delim)"<<std::endl;
    //words=ReadCsvLine(line1, delims, 1);
    words=ReadCsvLine2(line1, delims, 1, &vsh);
    QW=words.size();
    std::cout<<QW<<" elements"<<std::endl;
    for(int i=1; i<=QW; i++){
        std::cout<<words[i-1].toStdString()+" ";
        std::cout<<std::endl;
    }
    words.clear();
    //std::cout<<std::endl;

    //
    std::cout<<"reading line2: "+line2.toStdString()+"(2 delims = empty word between, first delim = first empty, last delim = last empty)"<<std::endl;
    //words=ReadCsvLine(line2, delims, 0);
    words=ReadCsvLine2(line2, delims, 0, &vsh);
    QW=words.size();
    std::cout<<QW<<" elements"<<std::endl;
    for(int i=1; i<=QW; i++){
        std::cout<<words[i-1].toStdString()+" ";
        std::cout<<std::endl;
    }
    //std::cout<<std::endl;
    words.clear();
    std::cout<<"reading line2: "+line2.toStdString()+"( >1 delims = 1 long delim)"<<std::endl;
    //words=ReadCsvLine(line2, delims, 1);
    words=ReadCsvLine2(line2, delims, 1, &vsh);
    QW=words.size();
    std::cout<<QW<<" elements"<<std::endl;
    for(int i=1; i<=QW; i++){
        std::cout<<words[i-1].toStdString()+" ";
        std::cout<<std::endl;
    }
    //std::cout<<std::endl;
    words.clear();
    //

    std::cout<<"reading line3: "+line3.toStdString()+"(2 delims = empty word between, first delim = first empty, last delim = last empty)"<<std::endl;
    //words=ReadCsvLine(line1, delims, 0);
    words=ReadCsvLine2(line3, delims, 0, &vsh);
    QW=words.size();
    std::cout<<QW<<" elements"<<std::endl;
    for(int i=1; i<=QW; i++){
        std::cout<<words[i-1].toStdString()+" ";
        std::cout<<std::endl;
    }
    //std::cout<<std::endl;
    words.clear();
    std::cout<<"reading line3: "+line3.toStdString()+"( >1 delims = 1 long delim)"<<std::endl;
    //words=ReadCsvLine(line1, delims, 1);
    words=ReadCsvLine2(line3, delims, 1, &vsh);
    QW=words.size();
    std::cout<<QW<<" elements"<<std::endl;
    for(int i=1; i<=QW; i++){
        std::cout<<words[i-1].toStdString()+" ";
        std::cout<<std::endl;
    }
    //std::cout<<std::endl;
    words.clear();

    //

    std::cout<<"reading line4: "+line4.toStdString()+"(2 delims = empty word between, first delim = first empty, last delim = last empty)"<<std::endl;
    //words=ReadCsvLine(line4, delims, 0);
    words=ReadCsvLine2(line4, delims, 0, &vsh);
    QW=words.size();
    std::cout<<QW<<" elements"<<std::endl;
    for(int i=1; i<=QW; i++){
        std::cout<<words[i-1].toStdString()+" ";
        std::cout<<std::endl;
    }
    //std::cout<<std::endl;
    words.clear();
    std::cout<<"reading line4: "+line4.toStdString()+"( >1 delims = 1 long delim)"<<std::endl;
    //words=ReadCsvLine(line4, delims, 1);
    words=ReadCsvLine2(line4, delims, 1, &vsh);
    QW=words.size();
    std::cout<<QW<<" elements"<<std::endl;
    for(int i=1; i<=QW; i++){
        std::cout<<words[i-1].toStdString()+" ";
        std::cout<<std::endl;
    }
    //std::cout<<std::endl;
    words.clear();

    std::cout<<"Test reqading CSV line finishes working"<<std::endl;
}

void TestReadingTextFileLineByLine(){
    std::cout<<"TestReadingTextFileLineByLine starts working"<<std::endl;
    std::string fNames="C:\\temp\\1.txt";
    std::vector<std::string>lines;

    lines=ReadFileLines(fNames.c_str());
    int Q=lines.size();
    std::cout<<"File "<<fNames<<" is read. "<<Q<<" lines found:"<<std::endl;
    for(int i=1; i<=Q; i++){
        std::cout<<lines[i-1]<<std::endl;
    }

   std::cout<<"TestReadingTextFileLineByLine finishes working"<<std::endl;
}

void TestReadingTextFileByKeyWordsSearch(){
    QString fullFileName="D:\\helisim\\ini\\FlutterModelData.txt";
    Flutter_IsolatedBladeNoFriction_Data_v1 flModel;
    //IncomingParamsFlutter IncomingParams;
    BladeParamsSupplFlutter BladeParams;
    HelicParamsSupplFlutter HelicParams;
    FlutterModeParams ModeParams;
    int countErrors=0;
    //bool thereare
    std::cout<<"TestReadingTextFileByKeyWordsSearch starts working "<<std::endl;
    std::cout<<"Given: "<<std::endl;
    std::cout<<"BladeParamsSupplFlutter: "<<std::endl;
    std::cout<<BladeParams.RigidityCentersLineToString().toStdString()<<std::endl;
    std::cout<<"HelicParamsSupplFlutter: "<<std::endl;
    std::cout<<HelicParams.ToString().toStdString()<<std::endl;
    std::cout<<"FlutterModeParams: "<<std::endl;
    std::cout<<ModeParams.ToString().toStdString()<<std::endl;
    countErrors=flModel.SetIniDataByTextFileReadingBySearch(fullFileName);
    //IncomingParams=flModel.GetIncomingParams();
    BladeParams=flModel.GetBladeParamsSupplFlutter();
    HelicParams=flModel.GetHelicParamsSupplFlutter();
    ModeParams=flModel.GetFlutterModeParams();
    std::cout<<"Read from file (Errors: "<<countErrors<<"): "<<std::endl;
    std::cout<<"BladeParamsSupplFlutter: "<<std::endl;
    std::cout<<BladeParams.RigidityCentersLineToString().toStdString()<<std::endl;
    std::cout<<"HelicParamsSupplFlutter: "<<std::endl;
    std::cout<<HelicParams.ToString().toStdString()<<std::endl;
    std::cout<<"FlutterModeParams: "<<std::endl;
    std::cout<<ModeParams.ToString().toStdString()<<std::endl;
    std::cout<<"TestReadingTextFileByKeyWordsSearch finishes working "<<std::endl;
}

void Test1DArrPtr_SubArrayByLs(){
    int asL=11;
    QString curS, defaultLeft=" ", defaultRight=".",
            as[]={"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven"};
    std::vector<int>LsOwn={3, 3, 5,       4,      4,      3,     5,       5,       4,      3,     6};
    QString alphabet_qs="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string stdstr, ss1=alphabet_qs.toStdString();
    std::vector<char>curV, v1(ss1.begin(), ss1.end());
    int FirstN, Qreq, QDfltsBefore, curL, L1=v1.size(), vsh;
    char ch, *pch1;
    //const char *pch;
    //char*pch1;
    char cfltLft=' ', dfltRght='.';
    //
    TDataShiftParams dsp;
    //
    FirstN=dsp.FirstN;
    Qreq=dsp.Lreq;
    QDfltsBefore=dsp.QDefaultsBefore;
    //
    //
    //----------------------------------------------
    for(int i=1; i<=asL; i++){
        curS=as[i-1];
        stdstr=curS.toStdString();
        curV=Arr1D_GetSubArr_ByLs(stdstr.c_str(), LsOwn[i-1], dfltRght, FirstN, Qreq, QDfltsBefore);
        curL=curV.size();
        printf("%d) (%d) ", i, curL);
        for(int j=1; j<=curL; j++){
            ch=curV[j-1];
            printf("%c", ch);
        }
        printf("\n");
    }
    //----------------------------------------------
    Qreq=6;
    for(int i=1; i<=asL; i++){
        curS=as[i-1];
        stdstr=curS.toStdString();
        curV=Arr1D_GetSubArr_ByLs(stdstr.c_str(), LsOwn[i-1], dfltRght, FirstN, Qreq, QDfltsBefore);
        curL=curV.size();
        printf("%d) (%d) ", i, curL);
        for(int j=1; j<=curL; j++){
            ch=curV[j-1];
            printf("%c", ch);
        }
        printf("\n");
    }

    //----------------------------------------------
    FirstN=2;
    QDfltsBefore=4;
    //----------------------------------------------
    //template<typename T> std::vector<T> Arr1D_GetSubArr_ByLs(T*x, int Q, T DefaultVal, int FirstN=1, int Qreq=0, int QDfltsBefore=0){//no vector specific
    Qreq=20;
    for(int i=1; i<=asL; i++){
        curS=as[i-1];
        stdstr=curS.toStdString();
        //pch=curS.toStdString().c_str();
        //pch1=pch;
        curV=Arr1D_GetSubArr_ByLs(stdstr.c_str(), LsOwn[i-1], dfltRght, FirstN, Qreq, QDfltsBefore);
        curL=curV.size();
        printf("%d) (%d) ", i, curL);
        for(int j=1; j<=curL; j++){
            ch=curV[j-1];
            printf("%c", ch);
        }
        printf("\n");
    }
    //---------------------------------------------
    Qreq=7;
    for(int i=1; i<=asL; i++){
        curS=as[i-1];
        stdstr=curS.toStdString();
        //pch=curS.toStdString().c_str();
        //pch1=pch;
        curV=Arr1D_GetSubArr_ByLs(stdstr.c_str(), LsOwn[i-1], dfltRght, FirstN, Qreq, QDfltsBefore);
        curL=curV.size();
        printf("%d) (%d) ", i, curL);
        for(int j=1; j<=curL; j++){
            ch=curV[j-1];
            printf("%c", ch);
        }
        printf("\n");
    }
    //--------------------------------------------------
    /*
    Qreq=8;
    FirstN=4;
    for(int i=1; i<=asL; i++){
        curS=as[i-1];
        stdstr=curS.toStdString();
        //pch=curS.toStdString().c_str();
        //pch1=pch;
        curV=Arr1D_GetSubArr_ByLs(stdstr.c_str(), LsOwn[i-1], dfltRght, FirstN, Qreq, QDfltsBefore);
        curL=curV.size();
        printf("%d) (%d) ", i, curL);
        for(int j=1; j<=curL; j++){
            ch=curV[j-1];
            printf("%c", ch);
        }
        printf("\n");
    }
    */
    //===================================================
    //template<typename T> std::vector<T> Arr1D_GetSubArr_ByLs(const T*x, int Q, T*x2, int Q2, T DefaultVal, int FirstN=1, int Qreq=0, int QDfltsBefore=0, int vsh=1)
    //----------------------------------------------
    printf("hilfsVector: ");
    for(int i=1; i<=L1; i++){
        ch=v1[i-1];
        printf("%c", ch);
    }
    printf("\n");
    //
    FirstN=dsp.FirstN;
    Qreq=dsp.Lreq;
    QDfltsBefore=dsp.QDefaultsBefore;
    dsp.Set(FirstN, QDfltsBefore, Qreq);
    printf("DataShiftParams: %s\n", dsp.ToString().toStdString().c_str());
    //
    vsh=0;
    //
    printf("\n Eleven numbers: \n");
    for(int i=1; i<=asL; i++){
        curS=as[i-1];
        stdstr=curS.toStdString();
        //curV=Arr1D_GetSubArr_ByLs(stdstr.c_str(), LsOwn[i-1], dfltRght, FirstN, Qreq, QDfltsBefore);
        //                         (stdstr.c_str(), LsOwn[i-1], dfltRght, FirstN, Qreq, QDfltsBefore);
        curV=Arr1D_GetSubArr_ByLs(stdstr.c_str(), LsOwn[i-1], v1.data(), L1, dfltRght, FirstN, Qreq, QDfltsBefore, vsh);
        curL=curV.size();
        printf("%d) (%d) ", i, curL);
        for(int j=1; j<=curL; j++){
            ch=curV[j-1];
            printf("%c", ch);
        }
        printf("\n");
    }
    //
    FirstN=4;
    Qreq=8;
    QDfltsBefore=4;
    //
    dsp.Set(FirstN, QDfltsBefore, Qreq);
    printf("DataShiftParams: %s\n", dsp.ToString().toStdString().c_str());
    dsp.Set();
    //
    vsh=0;
    //
    printf("\n Eleven numbers: \n");
    for(int i=1; i<=asL; i++){
        curS=as[i-1];
        stdstr=curS.toStdString();
        //curV=Arr1D_GetSubArr_ByLs(stdstr.c_str(), LsOwn[i-1], dfltRght, FirstN, Qreq, QDfltsBefore);
        //                         (stdstr.c_str(), LsOwn[i-1], dfltRght, FirstN, Qreq, QDfltsBefore);
        curV=Arr1D_GetSubArr_ByLs(stdstr.c_str(), LsOwn[i-1], v1.data(), L1, dfltRght, FirstN, Qreq, QDfltsBefore, vsh);
        curL=curV.size();
        printf("%d) (%d) ", i, curL);
        for(int j=1; j<=curL; j++){
            ch=curV[j-1];
            printf("%c", ch);
        }
        printf("\n");
    }
    //
    FirstN=dsp.FirstN;
    Qreq=dsp.Lreq;
    QDfltsBefore=dsp.QDefaultsBefore;
    dsp.Set(FirstN, QDfltsBefore, Qreq);
    printf("DataShiftParams: %s\n", dsp.ToString().toStdString().c_str());
    //
    vsh=0;
    //
    printf("\n Eleven numbers: \n");
    for(int i=1; i<=asL; i++){
        curS=as[i-1];
        stdstr=curS.toStdString();
        //curV=Arr1D_GetSubArr_ByLs(stdstr.c_str(), LsOwn[i-1], dfltRght, FirstN, Qreq, QDfltsBefore);
        //                         (stdstr.c_str(), LsOwn[i-1], dfltRght, FirstN, Qreq, QDfltsBefore);
        curV=Arr1D_GetSubArr_ByLs(stdstr.c_str(), LsOwn[i-1], v1.data(), L1, dfltRght, FirstN, Qreq, QDfltsBefore, vsh);
        curL=curV.size();
        printf("%d) (%d) ", i, curL);
        for(int j=1; j<=curL; j++){
            ch=curV[j-1];
            printf("%c", ch);
        }
        printf("\n");
    }
    //
    FirstN=4;
    Qreq=6;
    QDfltsBefore=2;
    //
    dsp.Set(FirstN, QDfltsBefore, Qreq);
    printf("DataShiftParams: %s\n", dsp.ToString().toStdString().c_str());
    dsp.Set();
    //
    vsh=0;
    //
    printf("\n Eleven numbers: \n");
    for(int i=1; i<=asL; i++){
        curS=as[i-1];
        stdstr=curS.toStdString();
        //curV=Arr1D_GetSubArr_ByLs(stdstr.c_str(), LsOwn[i-1], dfltRght, FirstN, Qreq, QDfltsBefore);
        //                         (stdstr.c_str(), LsOwn[i-1], dfltRght, FirstN, Qreq, QDfltsBefore);
        curV=Arr1D_GetSubArr_ByLs(stdstr.c_str(), LsOwn[i-1], v1.data(), L1, dfltRght, FirstN, Qreq, QDfltsBefore, vsh);
        curL=curV.size();
        printf("%d) (%d) ", i, curL);
        for(int j=1; j<=curL; j++){
            ch=curV[j-1];
            printf("%c", ch);
        }
        printf("\n");
    }
    //
    FirstN=4;
    Qreq=6;
    QDfltsBefore=3;
    //
    dsp.Set(FirstN, QDfltsBefore, Qreq);
    printf("DataShiftParams: %s\n", dsp.ToString().toStdString().c_str());
    dsp.Set();
    //
    vsh=0;
    //
    printf("\n Eleven numbers: \n");
    for(int i=1; i<=asL; i++){
        curS=as[i-1];
        stdstr=curS.toStdString();
        //curV=Arr1D_GetSubArr_ByLs(stdstr.c_str(), LsOwn[i-1], dfltRght, FirstN, Qreq, QDfltsBefore);
        //                         (stdstr.c_str(), LsOwn[i-1], dfltRght, FirstN, Qreq, QDfltsBefore);
        curV=Arr1D_GetSubArr_ByLs(stdstr.c_str(), LsOwn[i-1], v1.data(), L1, dfltRght, FirstN, Qreq, QDfltsBefore, vsh);
        curL=curV.size();
        printf("%d) (%d) ", i, curL);
        for(int j=1; j<=curL; j++){
            ch=curV[j-1];
            printf("%c", ch);
        }
        printf("\n");
    }
}//fn test subArr by Ls

void Test1DArraysPtr_1(){
    std::vector<int>Ns;
    int arr[]= {10, 20, 30, 40, 50, 60, 70};
    int Q1=7, Q2;
    int val=100, N;
    int*arrp, *p1;
    int arr2[]= {10, 20, 30};
    //arrp=arr; //so I can't chamge size and ref to old;
    arrp=new int[Q1];
    for(int i=1; i<=Q1; i++) arrp[i-1]=arr[i-1];
    printf("Now arr1D is:\n");
    for(int i=1; i<=Q1; i++){
        std::cout<<"x["<<i<<"]="<<arrp[i-1]<<"; ";
    }
    std::cout<<std::endl;
    //--------------------------------------------------------------
    //template<typename T> void Arr1D_SetVal_OrFill(T*&x, int Q, const T&val, int N_AllIf0){
    N=3;
    Arr1D_SetVal_OrFill(arrp, Q1, val, N);
    printf("Setting val %d to N %d. Now arr1D is:\n", val, N);
    for(int i=1; i<=Q1; i++){
        std::cout<<"x["<<i<<"]="<<arrp[i-1]<<"; ";
    }
    std::cout<<std::endl;
    N=-3;
    Arr1D_SetVal_OrFill(arrp, Q1, val, N);
    printf("Setting val %d to N %d. Now arr1D is:\n", val, N);
    for(int i=1; i<=Q1; i++){
        std::cout<<"x["<<i<<"]="<<arrp[i-1]<<"; ";
    }
    std::cout<<std::endl;
    N=0;
    Arr1D_SetVal_OrFill(arrp, Q1, val, N);
    printf("Setting val %d to N %d. Now arr1D is:\n", val, N);
    for(int i=1; i<=Q1; i++){
        std::cout<<"x["<<i<<"]="<<arrp[i-1]<<"; ";
    }
    std::cout<<std::endl;
    printf("Returning vals\n", val, N);
    delete[]arrp;
    arrp=arr;
    for(int i=1; i<=Q1; i++){
        std::cout<<"x["<<i<<"]="<<arr[i-1]<<"; ";
    }
    std::cout<<std::endl;
    for(int i=1; i<=Q1; i++){
        std::cout<<"x["<<i<<"]="<<arrp[i-1]<<"; ";
    }
    std::cout<<std::endl;
    //-----------------------------------------
    //template<typename T> void Arr1D_SetSize(T*&x, int Q1, int Q2, T DefaultVal)
    Q2=5;
    Arr1D_SetSize(arrp,Q1, Q2, 0);
    printf("new L=%d\n", Q2);
    for(int i=1; i<=Q2; i++){
        std::cout<<"x["<<i<<"]="<<arrp[i-1]<<"; ";
    }
    std::cout<<std::endl;
    val=0;
    Q1=8;
    Arr1D_SetSize(arrp,Q1, Q2, val);
    printf("new L=%d\n", Q2);
    for(int i=1; i<=Q2; i++){
        std::cout<<"x["<<i<<"]="<<arrp[i-1]<<"; ";
    }
    std::cout<<std::endl;
    arrp[6-1]=10;
    arrp[7-1]=70;
    arrp[8-1]=10;
    printf("x6=%d x7=%d x8=%d\n", arrp[6-1], arrp[7-1], arrp[8-1]);
    for(int i=1; i<=Q2; i++){
        std::cout<<"x["<<i<<"]="<<arrp[i-1]<<"; ";
    }
    std::cout<<std::endl;
    Q1=8;
    val=10;
    printf("Search for val=%d:\n", val);
    Ns=Arr1D_SeekVal(arrp, Q1, val);
    Q2=Ns.size();
    if(Q2==0){
        std::cout<<"Not found\n";
    }else{
        std::cout<<"Found "<<Q2<<" Ns: ";
        for(int i=1; i<=Q2; i++){
            std::cout<<Ns[i-1]<<"; ";
        }
        std::cout<<std::endl;
    }
    val=0;
    printf("Search for val=%d:\n", val);
    Ns=Arr1D_SeekVal(arrp, Q1, val);
    Q2=Ns.size();
    if(Q2==0){
        std::cout<<"Not found\n";
    }else{
        std::cout<<"Found "<<Q2<<" Ns: ";
        for(int i=1; i<=Q2; i++){
            std::cout<<Ns[i-1]<<"; ";
        }
        std::cout<<std::endl;
    }
    //...................................................
    //Arr1D_SeekSubArr(T*where, int whereQ, T*what, int whatQ, bool IsReversed=false)
    arrp[6-1]=10;
    arrp[7-1]=20;
    arrp[8-1]=30;
    printf("x6=%d x7=%d x8=%d\n", arrp[6-1], arrp[7-1], arrp[8-1]);
    for(int i=1; i<=Q1; i++){
        std::cout<<"x["<<i<<"]="<<arrp[i-1]<<"; ";
    }
    std::cout<<std::endl;
    val=0;
    Q1=8;
    Q2=3;
    p1=arr2;
    printf("Search for array:\n");
    for(int i=1; i<=Q2; i++){
        std::cout<<"x["<<i<<"]="<<p1[i-1]<<"; ";
    }
    std::cout<<std::endl;
    Ns=Arr1D_SeekSubArr(arrp, Q1, p1, Q2, false);
    Q2=Ns.size();
    if(Q2==0){
        std::cout<<"Not found\n";
    }else{
        std::cout<<"Found "<<Q2<<" Ns: ";
        for(int i=1; i<=Q2; i++){
            std::cout<<Ns[i-1]<<"; ";
        }
        std::cout<<std::endl;
    }
    // below - non-working:
    arrp[6-1]=30;
    arrp[7-1]=20;
    arrp[8-1]=10;
    p1[1-1]=30;
    p1[2-1]=20;
    p1[3-1]=10;
    printf("x6=%d x7=%d x8=%d\n", arrp[6-1], arrp[7-1], arrp[8-1]);
    for(int i=1; i<=Q1; i++){
        std::cout<<"x["<<i<<"]="<<arrp[i-1]<<"; ";
    }
    std::cout<<std::endl;
    val=0;
    Q1=8;
    Q2=3;
    p1=arr2;
    printf("Search for array reversed:\n");
    for(int i=1; i<=Q2; i++){
        std::cout<<"x["<<i<<"]="<<p1[i-1]<<"; ";
    }
    std::cout<<std::endl;
    Ns=Arr1D_SeekSubArr(arrp, Q1, p1, Q2, true);
    Q2=Ns.size();
    if(Q2==0){
        std::cout<<"Not found\n";
    }else{
        std::cout<<"Found "<<Q2<<" Ns: ";
        for(int i=1; i<=Q2; i++){
            std::cout<<Ns[i-1]<<"; ";
        }
        std::cout<<std::endl;
    }
    p1[1-1]=10;
    p1[2-1]=20;
    p1[3-1]=30;
    printf("x6=%d x7=%d x8=%d\n", arrp[6-1], arrp[7-1], arrp[8-1]);
    for(int i=1; i<=Q1; i++){
        std::cout<<"x["<<i<<"]="<<arrp[i-1]<<"; ";
    }
    std::cout<<std::endl;
    val=0;
    Q1=8;
    Q2=3;
    p1=arr2;
    printf("Search for array reversed:\n");
    for(int i=1; i<=Q2; i++){
        std::cout<<"x["<<i<<"]="<<p1[i-1]<<"; ";
    }
    std::cout<<std::endl;
    Ns=Arr1D_SeekSubArr(arrp, Q1, p1, Q2, true);
    Q2=Ns.size();
    if(Q2==0){
        std::cout<<"Not found\n";
    }else{
        std::cout<<"Found "<<Q2<<" Ns: ";
        for(int i=1; i<=Q2; i++){
            std::cout<<Ns[i-1]<<"; ";
        }
        std::cout<<std::endl;
    }
    //-----------------------------------------
    //template<typename T> void Arr1D_DelN(T*&x, int&Q, int N)
    N=6;
    printf("Deleting in Array:\n");
    for(int i=1; i<=Q1; i++){
        std::cout<<"x["<<i<<"]="<<arrp[i-1]<<"; ";
    }
    std::cout<<std::endl;
    Arr1D_DelN(arrp, Q1, N);
    printf("After deleting N%d habemus:\n", N);
    for(int i=1; i<=Q1; i++){
        std::cout<<"x["<<i<<"]="<<arrp[i-1]<<"; ";
    }
    std::cout<<std::endl;
    N=7;
    printf("Deleting in Array:\n");
    for(int i=1; i<=Q1; i++){
        std::cout<<"x["<<i<<"]="<<arrp[i-1]<<"; ";
    }
    std::cout<<std::endl;
    Arr1D_DelN(arrp, Q1, N);
    printf("After deleting N%d habemus:\n", N);
    for(int i=1; i<=Q1; i++){
        std::cout<<"x["<<i<<"]="<<arrp[i-1]<<"; ";
    }
    std::cout<<std::endl;
    N=1;
    printf("Deleting in Array:\n");
    for(int i=1; i<=Q1; i++){
        std::cout<<"x["<<i<<"]="<<arrp[i-1]<<"; ";
    }
    std::cout<<std::endl;
    Arr1D_DelN(arrp, Q1, N);
    printf("After deleting N%d habemus:\n", N);
    for(int i=1; i<=Q1; i++){
        std::cout<<"x["<<i<<"]="<<arrp[i-1]<<"; ";
    }
    std::cout<<std::endl;
    //
    printf("Inserting to Array:\n");
    N=1;
    val=10;
    for(int i=1; i<=Q1; i++){
        std::cout<<"x["<<i<<"]="<<arrp[i-1]<<"; ";
    }
    std::cout<<std::endl;
    //void Arr1D_InsToN_v1(T*&x, int&Q, int N, const T&val)
    Arr1D_InsToN_v2(arrp, Q1, N, val);
    printf("Array afrter inserting val= %d to N %d:\n", val , N);
    for(int i=1; i<=Q1; i++){
        std::cout<<"x["<<i<<"]="<<arrp[i-1]<<"; ";
    }
    printf("Inserting to Array:\n");
    N=2;
    val=20;
    for(int i=1; i<=Q1; i++){
        std::cout<<"x["<<i<<"]="<<arrp[i-1]<<"; ";
    }
    std::cout<<std::endl;
    //void Arr1D_InsToN_v1(T*&x, int&Q, int N, const T&val)
    Arr1D_InsToN_v2(arrp, Q1, N, val);
    printf("Array afrter inserting val= %d to N %d:\n", val , N);
    for(int i=1; i<=Q1; i++){
        std::cout<<"x["<<i<<"]="<<arrp[i-1]<<"; ";
    }
    std::cout<<std::endl;
    //
    printf("Deleting from Array:\n");
    N=2;
    for(int i=1; i<=Q1; i++){
        std::cout<<"x["<<i<<"]="<<arrp[i-1]<<"; ";
    }
    std::cout<<std::endl;
    Arr1D_DelN(arrp, Q1, N);
    printf("After deleting N%d habemus:\n", N);
    for(int i=1; i<=Q1; i++){
        std::cout<<"x["<<i<<"]="<<arrp[i-1]<<"; ";
    }
    std::cout<<std::endl;
    printf("Deleting from Array:\n");
    N=1;
    for(int i=1; i<=Q1; i++){
        std::cout<<"x["<<i<<"]="<<arrp[i-1]<<"; ";
    }
    std::cout<<std::endl;
    Arr1D_DelN(arrp, Q1, N);
    printf("After deleting N%d habemus:\n", N);
    for(int i=1; i<=Q1; i++){
        std::cout<<"x["<<i<<"]="<<arrp[i-1]<<"; ";
    }
    std::cout<<std::endl;
    //
    printf("Inserting to Array:\n");
    N=1;
    val=10;
    for(int i=1; i<=Q1; i++){
        std::cout<<"x["<<i<<"]="<<arrp[i-1]<<"; ";
    }
    std::cout<<std::endl;
    //void Arr1D_InsToN_v1(T*&x, int&Q, int N, const T&val)
    Arr1D_InsToN_v1(arrp, Q1, N, val);
    printf("Array afrter inserting val= %d to N %d:\n", val , N);
    for(int i=1; i<=Q1; i++){
        std::cout<<"x["<<i<<"]="<<arrp[i-1]<<"; ";
    }
    std::cout<<std::endl;
    printf("Inserting to Array:\n");
    N=2;
    val=20;
    for(int i=1; i<=Q1; i++){
        std::cout<<"x["<<i<<"]="<<arrp[i-1]<<"; ";
    }
    std::cout<<std::endl;
    Arr1D_InsToN_v1(arrp, Q1, N, val);
    printf("Array afrter inserting val= %d to N %d:\n", val , N);
    for(int i=1; i<=Q1; i++){
        std::cout<<"x["<<i<<"]="<<arrp[i-1]<<"; ";
    }
    std::cout<<std::endl;
    std::cout<<"Arr1D_InsToN_v1() tests also fns: Add() and Swap()"<<std::endl;
    //
    //template<typename T> void Arr1D_ConcatAdding(T*&x1, int& Q1, T*x2, int Q2, T DefaultVal, TDataShiftParams*DataShiftParam=NULL, int vsh=0)
    printf("Concat adding to array:\n");
    Q2=3;
    for(int i=1; i<=Q1; i++){
        std::cout<<"x["<<i<<"]="<<arrp[i-1]<<"; ";
    }
    std::cout<<std::endl;
    printf("an array:\n");
    for(int i=1; i<=Q2; i++){
        std::cout<<"x["<<i<<"]="<<arr2[i-1]<<"; ";
    }
    std::cout<<std::endl;
    TDataShiftParams DataShiftParams;
    DataShiftParams.FirstN=2;
    DataShiftParams.Lreq=6;//0;
    DataShiftParams.QDefaultsBefore=3;
    wprintf(L"by:  %ls\n",DataShiftParams.ToString().toStdWString().c_str());
    Arr1D_ConcatAdding(arrp, Q1, arr2, Q2, 0, &DataShiftParams, 0);
    printf("Habemus array L=%d:\n", Q1);
    for(int i=1; i<=Q1; i++){
        std::cout<<"x["<<i<<"]="<<arrp[i-1]<<"; ";
    }
    std::cout<<std::endl;
    for(int i=1; i<=DataShiftParams.Lreq; i++){
        Arr1D_DelN(arrp, Q1, 14);
    }
    printf("After del:\n");
    for(int i=1; i<=Q1; i++){
        std::cout<<"x["<<i<<"]="<<arrp[i-1]<<"; ";
    }
    std::cout<<std::endl;
    std::vector<int>vec= Arr1D_Concat(arrp, Q1, arr2, Q2, 0, &DataShiftParams);
    printf("After Concat:\n");
    Q2=vec.size();
    for(int i=1; i<=Q2; i++){
        std::cout<<"x["<<i<<"]="<<vec[i-1]<<"; ";
    }
    std::cout<<std::endl;
    printf("To reverse:\n");
    for(int i=1; i<=Q1; i++){
        std::cout<<"x["<<i<<"]="<<arrp[i-1]<<"; ";
    }
    std::cout<<std::endl;
    Arr1D_Reverse(arrp, Q1);
    printf("After reverse Once:\n");
    for(int i=1; i<=Q1; i++){
        std::cout<<"x["<<i<<"]="<<arrp[i-1]<<"; ";
    }
    std::cout<<std::endl;
    Arr1D_Reverse(arrp, Q1);
    printf("After reverse Twice:\n");
    for(int i=1; i<=Q1; i++){
        std::cout<<"x["<<i<<"]="<<arrp[i-1]<<"; ";
    }
    std::cout<<std::endl;
    val=60;
    Arr1D_Add(arrp, Q1, val);
    printf("After adding valal=%d:\n", val);
    for(int i=1; i<=Q1; i++){
        std::cout<<"x["<<i<<"]="<<arrp[i-1]<<"; ";
    }
    std::cout<<std::endl;
    Arr1D_Reverse(arrp, Q1);
    printf("After reverse Once:\n");
    for(int i=1; i<=Q1; i++){
        std::cout<<"x["<<i<<"]="<<arrp[i-1]<<"; ";
    }
    std::cout<<std::endl;
    Arr1D_Reverse(arrp, Q1);
    printf("After reverse Twice:\n");
    for(int i=1; i<=Q1; i++){
        std::cout<<"x["<<i<<"]="<<arrp[i-1]<<"; ";
    }
    std::cout<<std::endl;
    printf("To Shift Cyclely:\n");
    for(int i=1; i<=Q1; i++){
        std::cout<<"x["<<i<<"]="<<arrp[i-1]<<"; ";
    }
    std::cout<<std::endl;
    for(int k=1; k<=Q1; k++){
        Arr1D_ShiftCyclelyToEnd(arrp, Q1);
        printf("After Shift to the end:\n");
        for(int i=1; i<=Q1; i++){
            std::cout<<"x["<<i<<"]="<<arrp[i-1]<<"; ";
        }
        std::cout<<std::endl;
    }
    for(int k=1; k<=Q1; k++){
        Arr1D_ShiftCyclelyToBegin(arrp, Q1);
        printf("After Shift to the begin:\n");
        for(int i=1; i<=Q1; i++){
            std::cout<<"x["<<i<<"]="<<arrp[i-1]<<"; ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
    //-----------------------------------------
    delete[]arrp;
}

void TestArr2DInitio(){
    printf("\n\nTesting 2D array initio\n\n");
    Array2D_EIR<int> arr2D;
    arr2D.SetTypeN(ARR2D_TYPE_V1D_RECTANGULAR);
    arr2D.SetSize(0, 3, 4);
    for(int ERNN=1; ERNN<=3; ERNN++){
        for(int IRNN=1; IRNN<=4; IRNN++){
            arr2D.SetElement(ERNN*10+IRNN, ERNN, IRNN);
        }
    }
    arr2D.ShowToConsole();
    printf("\nTestArr2DInitio finishes working\n\n");
}
