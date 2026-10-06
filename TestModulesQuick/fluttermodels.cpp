#include "fluttermodels.h"

//FlutterModels::FlutterModels()
//{

//}

//class ThrownCorper{
//    double g;
    ThrownCorper::ThrownCorper(){
        this->g=9.81;
        //vy, vx, y, x
    }
    double ThrownCorper::Eq1RPVy(int n, double t, const double*y){
        return -1*this->g;//vy
    }
    double ThrownCorper::Eq2RPVx(int n, double t, const double*y){
        return 0;//vx
    }
    double ThrownCorper::Eq3RPY(int n, double t, const double*y){
        return y[1-1];//y
    }
    double ThrownCorper::Eq4RPX(int n, double t, const double*y){
        return y[2-1];//x
    }
    std::vector<double> ThrownCorper::Calc_ByAngle(double t, double V0, double AngleDeg, double y0, double x0, double t0, double dt){//, TValsShowHide*vsh){
        std::vector<double> q0;
        double Vy, Vx;
        //writeln(vsh, "Calc_ByAngle starts working");
        //writeln(vsh, "t="+FloatToStr(t)+" V0="+FloatToStr(V0)+" angle[deg]="+FloatToStr(AngleDeg)+" y0="+FloatToStr(y0)+" x0="+FloatToStr(x0)+" t0="+FloatToStr(t0)+" dt="+FloatToStr(dt));
        Vy=V0*sin(AngleDeg*M_PI/180);
        Vx=V0*cos(AngleDeg*M_PI/180);
        //writeln(vsh, "Vy="+FloatToStr(Vy)+" Vx="+FloatToStr(Vx)+" y0="+FloatToStr(y0)+" x0="+FloatToStr(x0));
        q0.push_back(Vy);
        q0.push_back(Vx);
        q0.push_back(y0);
        q0.push_back(x0);
        //writeln(vsh, "q0=["+FloatToStr(q0[0])+", "+FloatToStr(q0[1])+", "+FloatToStr(q0[2])+", "+FloatToStr(q0[3])+"]");
        //writeln(vsh,"going to: Calc_As1stOrderSys will start working");
        q0=this->Calc_As1stOrderSys(q0.data(), t, t0, dt);//, vsh);
        //writeln(vsh,"Calc_ByAngle finishes working");
        return q0;
    }
    // std::vector<double>            Calc_As1stOrderSys(double*q0, double t, double t0=0, double dt=1E-6);//, TValsShowHide*vsh=NULL);
    std::vector<double> ThrownCorper::Calc_As1stOrderSys(double*q0, double t, double t0,   double dt){//, TValsShowHide*vsh){
        std::vector<double>R;
        int QEq=4;
        //writeln(vsh,"Calc_As1stOrderSys sterts working");
        //writeln(vsh, "q0=["+FloatToStr(q0[0])+", "+FloatToStr(q0[1])+", "+FloatToStr(q0[2])+", "+FloatToStr(q0[3])+"]");
        //writeln(vsh, "t="+FloatToStr(t)+" t0="+FloatToStr(t0)+" dt="+FloatToStr(dt));
        using std::placeholders::_1;
        using std::placeholders::_2;
        using std::placeholders::_3;
        //

        std::vector<std::function<double(int, double, const double*)>> fArray = {
            std::bind(&ThrownCorper::Eq1RPVy, this, _1, _2, _3),
            std::bind(&ThrownCorper::Eq2RPVx, this, _1, _2, _3),
            std::bind(&ThrownCorper::Eq3RPY,  this, _1, _2, _3),
            std::bind(&ThrownCorper::Eq4RPX,  this, _1, _2, _3)
        };

        //
        //const int n = 4;
        //
        //writeln(vsh,"Going to: RungeFull will soon stert working");
        //
        R = RungeFull(4, q0, fArray, dt, t0, t);//, vsh);
        //
        //writeln(vsh,"Calc_As1stOrderSys finishes working");
        //
        return R;
    }

    //
    //void Calc_ByAngle(double*q, const TItersPrecision&ItersPrecision, double t, double V0, double AngleDeg, double y0, double x0=0, double t0=0, TValsShowHide*vsh=NULL);
    void ThrownCorper::Calc_ByAngle(double*q, const TItersPrecision&ItersPrecision, double t, double V0, double AngleDeg, double y0, double x0, double t0){//, TValsShowHide*vsh){
        double Vy, Vx;
        double dt=ItersPrecision.GetCorrectedStepLength(t0, t);
        //writeln(vsh, "Calc_ByAngle starts working");
        //writeln(vsh, "t="+FloatToStr(t)+" V0="+FloatToStr(V0)+" angle[deg]="+FloatToStr(AngleDeg)+" y0="+FloatToStr(y0)+" x0="+FloatToStr(x0)+" t0="+FloatToStr(t0)+" dt="+FloatToStr(dt));
        Vy=V0*sin(AngleDeg*M_PI/180);
        Vx=V0*cos(AngleDeg*M_PI/180);
        //writeln(vsh, "Vy="+FloatToStr(Vy)+" Vx="+FloatToStr(Vx)+" y0="+FloatToStr(y0)+" x0="+FloatToStr(x0));
        q[1-1]=Vy;
        q[2-1]=Vx;
        q[3-1]=y0;
        q[4-1]=x0;
        //writeln(vsh, "q0=["+FloatToStr(q[0])+", "+FloatToStr(q[1])+", "+FloatToStr(q[2])+", "+FloatToStr(q[3])+"]");
        //writeln(vsh,"going to: Calc_As1stOrderSys will start working");
        this->Calc_As1stOrderSys(ItersPrecision,q,  t, t0);//, vsh);
        //writeln(vsh,"Calc_ByAngle finishes working");
    }


    //void             Calc_As1stOrderSys(const TItersPrecision&ItersPrecision, double*q0, double t, double t0=0);//, TValsShowHide*vsh=NULL);
    void ThrownCorper::Calc_As1stOrderSys(const TItersPrecision&ItersPrecision, double*q, double t, double t0){//, TValsShowHide*vsh){
        std::vector<double>R;
        int QEq=4;
        //writeln(vsh,"Calc_As1stOrderSys sterts working");
        double dt=ItersPrecision.GetCorrectedStepLength(t0, t);
       // writeln(vsh, "q0=["+FloatToStr(q[0])+", "+FloatToStr(q[1])+", "+FloatToStr(q[2])+", "+FloatToStr(q[3])+"]");
       // writeln(vsh, "t="+FloatToStr(t)+" t0="+FloatToStr(t0)+" dt="+FloatToStr(dt));
        using std::placeholders::_1;
        using std::placeholders::_2;
        using std::placeholders::_3;
        //
        std::vector<std::function<double(int, double, const double*)>> fArray = {
            std::bind(&ThrownCorper::Eq1RPVy, this, _1, _2, _3),
            std::bind(&ThrownCorper::Eq2RPVx, this, _1, _2, _3),
            std::bind(&ThrownCorper::Eq3RPY,  this, _1, _2, _3),
            std::bind(&ThrownCorper::Eq4RPX,  this, _1, _2, _3)
        };
        //
        //const int n = 4;
        //
        //writeln(vsh,"Going to: RungeFull will soon stert working");
        //
        //void RungeFull_VPP_PrecCls(int Q, double*y, const std::vector<ODEFunc>&fArray, double t0, double t2, const TItersPrecision&ItersPrecision, TValsShowHide*vsh=NULL);
        RungeFull_VPP_PrecCls(4, q, fArray, t0,  t, ItersPrecision);//, vsh);
        //
       // writeln(vsh,"Calc_As1stOrderSys finishes working");
        //
        //return R;
    }
    //
    void ThrownCorper::Calc_As1stOrderSys_VPP(double*q, double t, double t0, double dt){
        using std::placeholders::_1;
        using std::placeholders::_2;
        using std::placeholders::_3;
        //
        std::vector<std::function<double(int, double, const double*)>> fArray = {
            std::bind(&ThrownCorper::Eq1RPVy, this, _1, _2, _3),
            std::bind(&ThrownCorper::Eq2RPVx, this, _1, _2, _3),
            std::bind(&ThrownCorper::Eq3RPY,  this, _1, _2, _3),
            std::bind(&ThrownCorper::Eq4RPX,  this, _1, _2, _3)
        };
        //RungeFull_VPP_PrecCls(4, q, fArray, t0,  t, ItersPrecision);//not
        //void RungeFull_VPP_PrecVal(int Q, double*y, const std::vector<ODEFunc>&fArray, double t0, double t2, double h);
        //void RungeFull_VPP_PrecVal(int Q, double*y, const std::vector<ODEFunc>&fArray, double t0, double t2, double h, TValsShowHide*vsh=NULL);
               RungeFull_VPP_PrecVal(    4,        q,                            fArray,        t0,         t,       dt);//, TValsShowHide*vsh=NULL);
    }

    void ThrownCorper::SetIniConds(double*q0, double V0, double AngleDeg, double H, double x0){
        double Vy=V0*sin(M_PI*AngleDeg/180);
        double Vx=V0*sin(M_PI*AngleDeg/180);
        //if(q0!=NULL){
        //    delete[]q0;
        //}
        //q0=new double[4];
        // Os gut f'dyn.arrr, ma owi static array. Or std::vector, ic ha var L, ma ety su L mut'tc aso
        q0[1-1]=Vy;
        q0[2-1]=Vx;
        q0[3-1]=H;
        q0[4-1]=x0;
    }

//};

/*

    Flutter_IsolatedBladeNoFriction_Data::Flutter_IsolatedBladeNoFriction_Data(){
   // public:
    //Ini params
    double sigma_param,  //p 359 - dist btwn axe o'ax'l hinge et weight ebnter - ms'b ini param uz blade
        sigma_f_param, // p 356 - dist btwn focus et rigidity axis - ms'b ini param uz blade
        theta0, // p 360 angle of setting o'blade's butt => r_=min (or spec)
        d_frict,//=0.35,//frict coef, steel-steel, ob tams Lager => ms'b steel-steel rolling
        c_ctrl; //p 360 - rigidity coef o'controlling sys
    double
       here_r,
       here_r_;
    int
     profN_cur,
     profN_next,
     N_M_prev,
     N_M_next;
    //TPosInSucc M_Pos_cur, M_Pos_next;
    //double alfa_cur, alfa_next, v_cur, v_next, //no not ob es Segment()
    double
       M_cur,
       M_next;
    //segment seg_cur, seg_next;
    double
       gamma0_param,
       i0_param,
       dCy_dalfa,
       dCy_dalfa_next,
       dCy_dalfa_cur,
       x0_param,     // p 356 - dist btw vorn edge et rigidity center
       chi_param,//=_k, //flap compens'z val, p 366 //not chi, chi_sr, khi
       p_kr,// = sqrt(c_ctrl/I_osh),  // p. 360: proper frecuency  of krut vibrs of blade
       b_param_,
       b_param_next,
       b_param_cur,
       w_;// = w / p_kr;
    double
       c12,
       c21,
       d11,
       d12,
       d21,
       d22,
       b11,
       b12,
       b22;
    double
      c21_SubIn,//=0,
      d11_SubInt,//=0,
      d12_SubInt,//=0,
      d21_SubInt,//=0,
      d22_SubInt1,//=0,
      d22_SubInt2,//=0,
      b12_SubInt,//=0,
      b22_SubInt;//=0;
    std::vector<double>
      alfas_cur,
      alfas_next,
      Ms_cur,
      Ms_next,
      CysForMCur,
      CysForMNext,
      M_toInterp,
      Cy_toInterp,
      ReX,
      ImX;
    double CurVal;
    double
       A1,
       B1,
       B2,
       C1,
       C2,
       D1,
       D2,
       Cp4,
       Cp3,
       Cp2,
       Cp1,
       Cp0;
    double
      __lambdaI_Re[2],
      __lambdaI_Im[2],
      __lambdaII_Re[2],
      __lambdaII_Im[2],
      lambdaI_Re[2],
      lambdaI_Im[2],
      lambdaII_Re[2],
      lambdaII_Im[2];
    double
        _q1,
        _p1,
        _q2,
        _p2,
        cfL,
        cfM,
        _w_fl_cr_1,
        _w_fl_cr_2,
       _p_fl_cr_1,
       _p_fl_cr_2,
       _w_diverg;
    // f'num solv flutter o'single isol'd blade FSIB:
    double
    //system 1 (mil vol 1 #2.19),
    //Equation1 with beta"!=0, fi"==0
    fsib_C_S1E1beta2=1;
    fsib_C_S1E1beta1=d11*w_,//iqv if w
    fsib_C_S1E1beta0=w_*w_,//iqv if w
    fsib_C_S1E1fi2=c12,
    fsib_C_S1E1fi1=d12*w_,//iqv if w
    fsib_C_S1E1fi0=b12*w_*w_,//iqv if w
    //Equation 2 with beta"==0, fi"!=0
    fsib_C_S1E2beta2=c21,
    fsib_C_S1E2beta1=d21*w_,
    fsib_C_S1E2beta0=(chi_param*p_kr*p_kr+c21*w_*w_),//iqv qre chi_param et p_kr
    fsib_C_S1E2fi2=1,
    fsib_C_S1E2fi1=d22*w_*w_;
    fsib_C_S1E2fi0=(p_kr*p_kr+b22*w_*w_),
    //system 2, solv'd r'2nd derivs
    //equation beta
    fsib_C_S2Ebeta_beta2,//=1,//,
    fsib_C_S2Ebeta_beta1,
    fsib_C_S2Ebeta_beta0,
    fsib_C_S2Ebeta_fi2,
    fsib_C_S2Ebeta_fi1,
    fsib_C_S2Ebeta_fi0,
    fsib_C_S2Efi_beta2,
    fsib_C_S2Efi_beta1,
    fsib_C_S2Efi_beta0,
    fsib_C_S2Efi_fi2,//=1,
    fsib_C_S2Efi_fi1,
    fsib_C_S2Efi_fi0;
    //Flutter_IsolatedBladeNoFriction_Data();
//};
}
Flutter_IsolatedBladeNoFriction_Data::Flutter_IsolatedBladeNoFriction_Data(bool check){
   double CrpS1E1, CrpS1E2, CrpS2E1, CrpS2E2;
   double _d2beta=-394, _d2fi=5, _dbeta=3, _dfi=7, _beta=-1, _fi=9;
    // public:
    //Ini params
   // double
    //    sigma_param,  //p 359 - dist btwn axe o'ax'l hinge et weight ebnter - ms'b ini param uz blade
    //    sigma_f_param, // p 356 - dist btwn focus et rigidity axis - ms'b ini param uz blade
    //    theta0, // p 360 angle of setting o'blade's butt => r_=min (or spec)
    //    d_frict,//=0.35,//frict coef, steel-steel, ob tams Lager => ms'b steel-steel rolling
    //    c_ctrl; //p 360 - rigidity coef o'controlling sys
   // double
    //   here_r,
    //   here_r_;
    //int
    // profN_cur,
    // profN_next,
    // N_M_prev,
    // N_M_next;
    //TPosInSucc M_Pos_cur, M_Pos_next;
    //double alfa_cur, alfa_next, v_cur, v_next, //no not ob es Segment()
    //double
    // M_cur,
    //  M_next;
    //segment seg_cur, seg_next;
    //vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
   // double
    // gamma0_param,
     //  i0_param,
     // dCy_dalfa,
    //  dCy_dalfa_next,
     //  dCy_dalfa_cur,
     //  x0_param,     // p 356 - dist btw vorn edge et rigidity center
       chi_param=441.75;//-883.5;//=_k, //flap compens'z val, p 366 //not chi, chi_sr, khi
      p_kr=-2;// = sqrt(c_ctrl/I_osh),  // p. 360: proper frecuency  of krut vibrs of blade
     //  b_param_,
     //  b_param_next,
     //  b_param_cur,
       w_=2;// = w / p_kr;
    //double
       c12=4;
       c21=-5;
       d11=1;
       d12=6;
       d21=-6;
       d22=-3;
       b11=10000000000000;
       b12=8;
       b22=-4;
    //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    //double
    //  c21_SubIn,//=0,
    //  d11_SubInt,//=0,
    //  d12_SubInt,//=0,
    //  d21_SubInt,//=0,
    //  d22_SubInt1,//=0,
    //  d22_SubInt2,//=0,
    //  b12_SubInt,//=0,
    //  b22_SubInt;//=0;
    //std::vector<double>
    //  alfas_cur,
    //  alfas_next,
    //  Ms_cur,
    //  Ms_next,
    //  CysForMCur,
    //  CysForMNext,
    //  M_toInterp,
    //  Cy_toInterp,
    //  ReX,
    //  ImX;
    //double CurVal;
    //double
    //   A1,
    //   B1,
    //   B2,
    //   C1,
    //   C2,
    //   D1,
    //   D2,
    //   Cp4,
    //   Cp3,
    //   Cp2,
    //   Cp1,
    //   Cp0;
    //double
    //__lambdaI_Re[2],
    // __lambdaI_Im[2],
    // __lambdaII_Re[2],
    // __lambdaII_Im[2],
    // lambdaI_Re[2],
    // lambdaI_Im[2],
    // lambdaII_Re[2],
    //lambdaII_Im[2];
    //double
    //   _q1,
   //   _p1,
   //    _q2,
   //    _p2,
   //   cfL,
   //    cfM,
   //    _w_fl_cr_1,
   //    _w_fl_cr_2,
   //   _p_fl_cr_1,
   //   _p_fl_cr_2,
   //  _w_diverg;
    // f'num solv flutter o'single isol'd blade FSIB:
    //double
    //system 1 (mil vol 1 #2.19),
    //Equation1 with beta"!=0, fi"==0
    //std::cout<<"Equation1 with beta''!=0, fi''==0 "<<std::endl;
    fsib_C_S1E1beta2=1;//=1;//=1,
    //std::cout<<"fsib_C_S1E1beta2=1= "<<fsib_C_S1E1beta2<<std::endl;
    fsib_C_S1E1beta1=d11*w_;//iqv if w //2
    //std::cout<<"fsib_C_S1E1beta1=2= "<<fsib_C_S1E1beta1<<std::endl;
    fsib_C_S1E1beta0=w_*w_;//iqv if w //4
    //std::cout<<"fsib_C_S1E1beta0=4= "<<fsib_C_S1E1beta0<<std::endl;
    fsib_C_S1E1fi2=c12;//4
    //std::cout<<"fsib_C_S1E1fi2=4= "<<fsib_C_S1E1fi2<<std::endl;
    fsib_C_S1E1fi1=d12*w_,//iqv if w //12
    //std::cout<<"fsib_C_S1E1fi1=12= "<<fsib_C_S1E1fi1<<std::endl;
    fsib_C_S1E1fi0=b12*w_*w_;//iqv if w //32
    //std::cout<<"fsib_C_S1E1fi0=32= "<<fsib_C_S1E1fi0<<std::endl;
    //Equation 2 with beta"==0, fi"!=0
    //std::cout<<"Equation2 with fi''!=0, beta''==0"<<std::endl;
    fsib_C_S1E2beta2=c21;//-5
    //std::cout<<"fsib_C_S1E2beta2=-5= "<<fsib_C_S1E2beta2<<std::endl;
    fsib_C_S1E2beta1=d21*w_;//-12
    //std::cout<<"fsib_C_S1E2beta1=-12= "<<fsib_C_S1E2beta1<<std::endl;
    fsib_C_S1E2beta0=(chi_param*p_kr*p_kr + c21*w_*w_);//1747//iqv qre chi_param et p_kr
    //std::cout<<"fsib_C_S1E2beta0=1747= "<<fsib_C_S1E2beta0<<std::endl;
    fsib_C_S1E2fi2=1;
    //std::cout<<"fsib_C_S1E2fi2=1= "<<fsib_C_S1E2fi2<<std::endl;
    fsib_C_S1E2fi1=d22*w_*w_;//-12
    //std::cout<<"fsib_C_S1E2fi1=-12= "<<fsib_C_S1E2fi1<<std::endl;
    fsib_C_S1E2fi0=(p_kr*p_kr+b22*w_*w_);//-12
    //std::cout<<"fsib_C_S1E2fi0=-12= "<<fsib_C_S1E2fi0<<std::endl;
    //
    //CrpS1E1= fsib_C_S1E1beta2*_d2beta + fsib_C_S1E1beta1*_dbeta + fsib_C_S1E1beta0*_beta + fsib_C_S1E1beta1*_dbeta + fsib_C_S1E1beta0*_beta;
    //
    //system 2, solv'd r'2nd derivs
    //equation beta
    //fsib_C_S2Ebeta_beta2;
    //fsib_C_S2Ebeta_beta1;
    //fsib_C_S2Ebeta_beta0;
    //fsib_C_S2Ebeta_fi2;
    //fsib_C_S2Ebeta_fi0;
    //equation fi
    //fsib_C_S2Efi_beta2=1;
    //fsib_C_S2Efi_beta1;
    //fsib_C_S2Efi_beta0;
    //fsib_C_S2Efi_fi2;
    //fsib_C_S2Efi_fi0;
    //Flutter_IsolatedBladeNoFriction_Data();
    //
    //std::cout<<"System to solve ut express 2nd derivs"<<std::endl;
    //std::cout<<"Coefs 2nd derivs"<<std::endl;
    this->fsib_S1LinReDerivs2E1_C_beta2 = this->fsib_C_S1E1beta2;
    //std::cout<<"S1LinReDerivs2E1_C_beta2=1= "<<fsib_S1LinReDerivs2E1_C_beta2<<std::endl;
    this->fsib_S1LinReDerivs2E2_C_beta2 = this->fsib_C_S1E2beta2;
    //std::cout<<"fsib_S1LinReDerivs2E2_C_beta2=-5= "<<fsib_S1LinReDerivs2E2_C_beta2<<std::endl;
    this->fsib_S1LinReDerivs2E1_C_fi2   = this->fsib_C_S1E1fi2;
    //std::cout<<"fsib_S1LinReDerivs2E1_C_fi2=4= "<<fsib_S1LinReDerivs2E1_C_fi2<<std::endl;
    this->fsib_S1LinReDerivs2E2_C_fi2   = this->fsib_C_S1E2fi2;
    //std::cout<<"fsib_S1LinReDerivs2E2_C_fi2=1= "<<fsib_S1LinReDerivs2E2_C_fi2<<std::endl;
    //std::cout<<"RPs"<<std::endl;
    //                                          f_S1LinReDerivs2E1_RP(double beta_1, double fi_1, double beta, double fi)
    this->fsib_S1LinReDerivs2E1_RP_beta = this->f_fsib_S1LinReDerivs2E1_RP(_dbeta, _dfi, _beta, _fi);
    //std::cout<<"fsib_S1LinReDerivs2E1_RP_beta=-374= "<<fsib_S1LinReDerivs2E1_RP_beta<<std::endl;
    this->fsib_S1LinReDerivs2E2_RP_fi   = this->f_fsib_S1LinReDerivs2E2_RP(_dbeta, _dfi, _beta, _fi);
    //std::cout<<"fsib_S1LinReDerivs2E2_RP_fi=1975= "<<fsib_S1LinReDerivs2E2_RP_fi<<std::endl;
    //std::cout<<"Sys det"<<std::endl;
    this->S1LinReDerivs2_det_sys=this->fsib_S1LinReDerivs2E1_C_beta2*this->fsib_S1LinReDerivs2E2_C_fi2-this->fsib_S1LinReDerivs2E1_C_fi2*this->fsib_S1LinReDerivs2E2_C_beta2;
    //std::cout<<"S1LinReDerivs2_det_sys=21= "<<S1LinReDerivs2_det_sys<<std::endl;
    //ad amda os gut, ma ab amda ...
    //std::cout<<"beta det"<<std::endl;
    this->S1LinReDerivs2_det_beta=this->f_fsib_S1LinReDerivs2_det_beta2(_dbeta, _dfi, _beta, _fi);
    //std::cout<<"S1LinReDerivs2_det_beta=-8274= "<<S1LinReDerivs2_det_beta<<std::endl;
    //std::cout<<"fi det"<<std::endl;
    this->S1LinReDerivs2_det_fi=this->f_fsib_S1LinReDerivs2_det_fi2(_dbeta, _dfi, _beta, _fi);
    //std::cout<<"S1LinReDerivs2_det_fi=105= "<<S1LinReDerivs2_det_fi<<std::endl;
    //
    //std::cout<<"Final, check of rights parts - ms'b zeros"<<std::endl;
    this->S2Ebeta_RP = _d2beta - f_fsib_S2LinReDerivs2E1_RP_beta(_dbeta, _dfi, _beta, _fi);
    //std::cout<<"S2Ebeta_RP=0= "<<S2Ebeta_RP<<std::endl;
    this->S2Efi_RP = _d2fi   - f_fsib_S2LinReDerivs2E2_RP_fi  (_dbeta, _dfi, _beta, _fi);
    //std::cout<<"S2Efi_RP=0= "<<S2Efi_RP<<std::endl;
    //std::cout<<"Constructor finishes working"<<std::endl;
//};
}
//
double Flutter_IsolatedBladeNoFriction_Data::f_fsib_S1LinReDerivs2E1_RP(double beta_1, double fi_1, double beta, double fi){
    double y;
    //std::cout<<"f_S1LinReDerivs2E1_RP starts working"<<std::endl;
    //std::cout<<"beta_1=3= "<<beta_1<<" fi_1=7= "<<fi_1<<" beta=-1= "<<beta<<" fi=7= "<<fi<<std::endl;
    //std::cout<<"fsib_C_S1E1beta1=2= "<<fsib_C_S1E1beta1<<" fsib_C_S1E1fi1=12= "<<fsib_C_S1E1fi1<<" fsib_C_S1E1beta0=4= "<<fsib_C_S1E1beta0<<" fsib_C_S1E1fi0=32= "<<fsib_C_S1E1fi0<<std::endl;
    y=(this->fsib_C_S1E1beta1*beta_1 +this->fsib_C_S1E1fi1*fi_1 +this->fsib_C_S1E1beta0*beta +this->fsib_C_S1E1fi0*fi)*(-1);
    //std::cout<<"y="<<y<<" f_S1LinReDerivs2E1_RP finishes working"<<std::endl;
    return y;
}

double Flutter_IsolatedBladeNoFriction_Data::f_fsib_S1LinReDerivs2E2_RP(double beta_1, double fi_1, double beta, double fi){
    double y;
    //std::cout<<"f_S1LinReDerivs2E2_RP starts working"<<std::endl;
    //std::cout<<"beta_1=3= "<<beta_1<<" fi_1=7= "<<fi_1<<" beta=-1= "<<beta<<" fi=7= "<<fi<<std::endl;
    //std::cout<<"fsib_C_S1E2beta1=-12= "<<fsib_C_S1E2beta1<<" fsib_C_S1E2fi1=-12= "<<fsib_C_S1E2fi1<<" fsib_C_S1E2beta0=1747= "<<fsib_C_S1E2beta0<<" fsib_C_S1E2fi0=-12= "<<fsib_C_S1E2fi0<<std::endl;
    y=(this->fsib_C_S1E2beta1*beta_1 +this->fsib_C_S1E2fi1*fi_1+this->fsib_C_S1E2beta0*beta +this->fsib_C_S1E2fi0*fi)*(-1);
    //std::cout<<"y="<<y<<" f_S1LinReDerivs2E2_RP finishes working"<<std::endl;
    return y;
}

double Flutter_IsolatedBladeNoFriction_Data::f_fsib_S1LinReDerivs2_det_beta2(double beta_1, double fi_1, double beta, double fi){
    double y=0;
    //std::cout<<"f_S1LinReDerivs2_det_beta2 starts working"<<std::endl;
    y=this->f_fsib_S1LinReDerivs2E1_RP(beta_1, fi_1, beta, fi)*
      this->fsib_S1LinReDerivs2E2_C_fi2-
      this->f_fsib_S1LinReDerivs2E2_RP(beta_1, fi_1, beta, fi)*
      this->fsib_S1LinReDerivs2E1_C_fi2;
    //std::cout<<"y="<<y<<" f_S1LinReDerivs2_det_beta2 finishes working"<<std::endl;
    return y;
}
double Flutter_IsolatedBladeNoFriction_Data::f_fsib_S1LinReDerivs2_det_fi2(double beta_1, double fi_1, double beta, double fi){
    double y=0;
    //std::cout<<"f_S1LinReDerivs2_det_fi2 starts working"<<std::endl;
    y=this->f_fsib_S1LinReDerivs2E2_RP(beta_1, fi_1, beta, fi)*
      this->fsib_S1LinReDerivs2E1_C_beta2-
      this->f_fsib_S1LinReDerivs2E1_RP(beta_1, fi_1, beta, fi)*
      this->fsib_S1LinReDerivs2E2_C_beta2;
    //std::cout<<"y="<<y<<" f_S1LinReDerivs2_det_fi2 finishes working"<<std::endl;
    return y;
}
//
//
double Flutter_IsolatedBladeNoFriction_Data::f_fsib_S2LinReDerivs2E1_RP_beta(double beta_1, double fi_1, double beta, double fi){
    double y=0;
    //std::cout<<"f_S2LinReDerivs2E1_RP_beta starts working"<<std::endl;
    //std::cout<<"sys det="<<this->S1LinReDerivs2_det_sys<<std::endl;
    if(this->S1LinReDerivs2_det_sys!=0){
        y=this->f_fsib_S1LinReDerivs2_det_beta2(beta_1, fi_1, beta, fi)/this->S1LinReDerivs2_det_sys;
    }else{
        //std::cout<<"sys det =0, returning 0"<<std::endl;
    }
    //std::cout<<"y="<<y<<" f_S2LinReDerivs2E1_RP_beta finishes working"<<std::endl;
    return y;
}
double Flutter_IsolatedBladeNoFriction_Data::f_fsib_S2LinReDerivs2E2_RP_fi(double beta_1, double fi_1, double beta, double fi){
    double y=0;
    //std::cout<<"f_S2LinReDerivs2E2_RP_fi starts working"<<std::endl;
    //std::cout<<"sys det="<<this->S1LinReDerivs2_det_sys<<std::endl;
    if(this->S1LinReDerivs2_det_sys!=0){
        y=this->f_fsib_S1LinReDerivs2_det_fi2(beta_1, fi_1, beta, fi)/this->S1LinReDerivs2_det_sys;
    }else{
        //std::cout<<"sys det =0, returning 0"<<std::endl;
    }
    //std::cout<<"y="<<y<<" f_S2LinReDerivs2E2_RP_fi finishes working"<<std::endl;
    return y;
}


double Flutter_IsolatedBladeNoFriction_Data::f_fsib_S3E1_RP_dbeta(double*X){
    double beta_1=X[1-1], fi_1=X[2-1], beta=X[3-1], fi=X[4-1], y;
    y=this->f_fsib_S2LinReDerivs2E1_RP_beta(beta_1, fi_1, beta, fi);
    return y;
}

double Flutter_IsolatedBladeNoFriction_Data::f_fsib_S3E2_RP_dfi(double*X){
    double beta_1=X[1-1], fi_1=X[2-1], beta=X[3-1], fi=X[4-1], y;
    y=this->f_fsib_S2LinReDerivs2E2_RP_fi(beta_1, fi_1, beta, fi);
    return y;
}

double Flutter_IsolatedBladeNoFriction_Data::f_fsib_S3E3_RP_beta(double*X){
    double beta_1=X[1-1], fi_1=X[2-1], beta=X[3-1], fi=X[4-1], y;
    y=beta_1;
    return y;
}

double Flutter_IsolatedBladeNoFriction_Data::f_fsib_S3E4_RP_fi(double*X){
    double beta_1=X[1-1], fi_1=X[2-1], beta=X[3-1], fi=X[4-1], y;
    y=fi_1;
    return y;
}
*/

//--------------------------------------------------------------------------------




void Flutter_IsolatedBladeNoFriction_Data_v1_ParamsIniForCalcEquations::SetTestValues(){
    //double d11, w, c12, d12, b12, d22, p_cr, b22, c21, d21, chi_param
    this->d11=1;
    this->w=2;
    this->c12=4;
    this->d12=6;
    this->b12=8;
    this->d22=-3;
    this->p_cr=-2;
    this->b22=-4;
    this->c21=-5;
    this->d21=-6;
    this->chi_param=441.75;
}


//void Flutter_IsolatedBladeNoFriction_Data_v1::CalcIniIni(){
//    i0_param = data.I_osh / data.I_gsh;
//    dCy_dalfa=0;
//}
Flutter_IsolatedBladeNoFriction_Data_v1_IncomingHelicParams::Flutter_IsolatedBladeNoFriction_Data_v1_IncomingHelicParams(){
    //n'vikt
}

Flutter_IsolatedBladeNoFriction_Data_v1_IniExt::Flutter_IsolatedBladeNoFriction_Data_v1_IniExt(){
    //n'vikt
}



Flutter_IsolatedBladeNoFriction_Data_v1_ParamsIniForCalcEquations::Flutter_IsolatedBladeNoFriction_Data_v1_ParamsIniForCalcEquations(){
    //double d11, w, c12, d12, b12, d22, p_cr, b22, c21, d21, chi_param
    this->d11=0;
    this->w=0;
    this->c12=0;
    this->d12=0;
    this->b12=0;
    this->d22=0;
    this->p_cr=0;
    this->b22=0;
    this->c21=0;
    this->d21=0;
    this->chi_param=0;
}


Flutter_IsolatedBladeNoFriction_Data_v1_Results::Flutter_IsolatedBladeNoFriction_Data_v1_Results(){

}

//class HelicParamsSupplFlutter{
//  public:
//    double c_ctrl,
//           lagerKfr, lagerR;
HelicParamsSupplFlutter::HelicParamsSupplFlutter(){
    this->c_ctrl=0;
    this->lagerKfr=0.006;// f'rolic et 0.003 f'spheric;
    this->lagerR=10E-2;//m=10cm, I n'ved
}

QString HelicParamsSupplFlutter::ToString(){
   QString s="", sc, sn;
   sc="c_ctrl=";
   sn.setNum(this->c_ctrl);
   s=s+sc;
   s=s+sn;
   s=s+" ";
   sc="lagerR=";
   sn.setNum(this->lagerR);
   s=s+sc;
   s=s+sn;
   s=s+" ";
   sc="lagerKfr=";
   sn.setNum(this->lagerKfr);
   s=s+sc;
   s=s+sn;
   return s;
}

//};

//class BladeParamsSupplFlutter{
//  public:
//    std::vector<std::vector<double>> WeightCentersLine, RigidityCentersLine;
//    int RigidityCentersLineTypeN;
BladeParamsSupplFlutter::BladeParamsSupplFlutter(){
    std::vector<double>WeightSectCenter, RigiditySectCenter;
    int QWeightLineSects=41, QRigidityLineSects=41;
    //double _x_weight_typical=0.25;
    //double _x_rigidity_typical=0.25;
    double _x_weight_profile=0.25,   _x_weight_Butt=0.2,   _x_weight_End=0.3;
    double _x_rigidity_profile=0.25, _x_rigidity_Butt=0.2, _x_rigidity_End=0.3;
    double _r;
    double R=10644;
    this->RigidityCentersLineTypeN=1;
    // сечения:	mr.Num=		    0	    1 	    2	    3	    4	    5	    6	    7	    8	    9	    10	    11	    12	    13	    14	    15	    16	    17	    18	    19	    20	    21	    22	    23	    24	    25	    26	    27	    28	    29	    30	    31	    32	    33	    34	    35	    36	    37	    38	    39	    40
    //Радиус, м:	mr.r=		2.048	2.263	2.478	2.693	2.908	3.122	3.337	3.552	3.767	3.982	4.197	4.412	4.627	4.842	5.057	5.271	5.486	5.701	5.916	6.131	6.346	6.561	6.776	6.991	7.206	7.420	7.635	7.850	8.065	8.280	8.495	8.710	8.925	9.140	9.355	9.569	9.784	9.999	10.214	10.429	10.644
    //mi8.mr
    //  /mr.stiff3=     300000  		жесткость крутильная отн.ОШ (приведенная жесткость системы управления)
    //  /mr.flapStiff=	20000		жесткость изгибная в плоскости взмаха
    //mi8-2023.hs
    //mr.D=      21288 мм       диаметр несущего винта (используется только для отображения);
    for(int i=1; i<=2; i++){//forming size of single center line element
        WeightSectCenter.push_back(0);
        RigiditySectCenter.push_back(0);
    }
    //
    //
    //-1;
    _r=2/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_Butt);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_Butt);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=0
    _r=2.048/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=1
    _r=2.263/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=2
    _r=2.478/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=3
    _r=2.693/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=4
    _r=2.908/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=5
    _r=3.122/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=6
    _r=3.337/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=7
    _r=3.552/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=8
    _r=3.767/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=9
    _r=3.9827/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=10
    _r=4.197/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=11
    _r=4.412/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=12
    _r=4.627/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=13
    _r=4.842/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=14
    _r=5.057/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=15
    _r=5.271/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=16
    _r=5.486/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=17
    _r=5.701/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=18
    _r=5.916/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=19
    _r=6.131/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=20
    _r=6.346/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=21
    _r=6.561/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=22
    _r=6.776/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=23
    _r=6.991/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=24
    _r=7.206/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=25
    _r=7.420/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=26
    _r=7.635/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=27
    _r=7.850/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=28
    _r=8.065/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=29
    _r=8.280/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=30
    _r=8.495/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=31
    _r=8.710/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=32
    _r=8.925/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=33
    _r=9.140/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=34
    _r=9.355/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=35
    _r=9.569/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=36
    _r=9.784/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=37
    _r=9.999/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=38
    _r=10.214/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=39
    _r=10.429/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=40
    _r=10.644/R;
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
    //i=40
    _r=10.644/R;//=1
    WeightSectCenter.clear();
    RigiditySectCenter.clear();
    WeightSectCenter.push_back(_r);
    WeightSectCenter.push_back(_x_weight_profile);
    RigiditySectCenter.push_back(_r);
    RigiditySectCenter.push_back(_x_rigidity_profile);
    this->WeightCentersLine.push_back(WeightSectCenter);
    this->RigidityCentersLine.push_back(RigiditySectCenter);
}

void BladeParamsSupplFlutter::SetRigidityLineNull(){
    this->RigidityCentersLine.clear();
}

void BladeParamsSupplFlutter::SetWeightsLineNull(){
    this->WeightCentersLine.clear();
}

QString BladeParamsSupplFlutter::RigidityCentersLineToString(){
    QString s="Rigidity centers line: ", sc, snn, snr1, snr2, snb1;
    int L=this->WeightCentersLine.size();
    snn.setNum(L);
    sc=" sects given: ";
    s=s+snn;
    s=s+sc;
    if(this->RigidityCentersLineTypeN==1){
        for(int i=1; i<=L; i++){
            sc="S.";
            snn.setNum(i);
            sc=sc+snn;
            sc=sc+":(_r=";
            snr1.setNum(this->RigidityCentersLine[i-1][1-1]);
            sc=sc+snr1;
            sc=sc+", _b=";
            snb1.setNum(this->RigidityCentersLine[i-1][2-1]);
            sc=sc+snb1;
            sc=sc+") ";
            s=s+sc;
        }
    }else if(this->RigidityCentersLineTypeN==2){
        for(int i=1; i<=L; i++){
            sc="S.";
            snn.setNum(i);
            sc=sc+snn;
            sc=sc+":(_r1=";
            snr1.setNum(this->RigidityCentersLine[i-1][1-1]);
            sc=sc+snr1;
            sc=sc+"...r2=";
            snr2.setNum(this->RigidityCentersLine[i-1][2-1]);
            sc=sc+snr2;
            sc=sc+", _b=";
            snb1.setNum(this->RigidityCentersLine[i-1][3-1]);
            sc=sc+snb1;
            sc=sc+") ";
            s=s+sc;
        }
    }
    return s;
}

QString  BladeParamsSupplFlutter::BladeParamsSupplFlutter::WeightCentersLineToString(){
    QString s="Weight centers line: ", sc, snn, snr1, snr2, snb1;
    int L=this->WeightCentersLine.size();
    snn.setNum(L);
    sc=" sects given: ";
    s=s+snn;
    s=s+sc;
    if(this->WeightCentersLineTypeN==1){
        for(int i=1; i<=L; i++){
            sc="S.";
            snn.setNum(i);
            sc=sc+snn;
            sc=sc+":(_r=";
            snr1.setNum(this->WeightCentersLine[i-1][1-1]);
            sc=sc+snr1;
            sc=sc+", _b=";
            snb1.setNum(this->WeightCentersLine[i-1][2-1]);
            sc=sc+snb1;
            sc=sc+") ";
            s=s+sc;
        }
    }else if(this->WeightCentersLineTypeN==2){
        for(int i=1; i<=L; i++){
            sc="S.";
            snn.setNum(i);
            sc=sc+snn;
            sc=sc+":(_r1=";
            snr1.setNum(this->WeightCentersLine[i-1][1-1]);
            sc=sc+snr1;
            sc=sc+"...r2=";
            snr2.setNum(this->WeightCentersLine[i-1][2-1]);
            sc=sc+snr2;
            sc=sc+", _b=";
            snb1.setNum(this->WeightCentersLine[i-1][3-1]);
            sc=sc+snb1;
            sc=sc+") ";
            s=s+sc;
        }
    }
    return s;
}

//class FlutterModeParams{
//  public:
//    double fiAfl, pfl;
FlutterModeParams::FlutterModeParams(){
    this->fiAfl=0;
    this->pfl=0;
}
QString FlutterModeParams::ToString(){
    QString s="", sn, sc;
    sc="fi(A)=";
    sn.setNum(this->fiAfl);
    s=s+sc;
    s=s+sn;
    s=s+" ";
    sc="p(fl)=";
    sn.setNum(this->pfl);
    s=s+sc;
    s=s+sn;
    return s;
}

//};

IncomingParamsFlutter::IncomingParamsFlutter(){
    this->b7=0;
    this->chi_param=0;
    this->I_gsh=0;
    this->I_osh=0;
    this->mlp=0;
    this->R=0;
    this->ro=0;
    this->Sb0=0;
    this->sigma=0;
    this->w=0;
}
//void IncomingParamsFlutter::SetNull(){
//    this->b7=0;
//    this->chi_param=0;
//    this->I_gsh=0;
//    this->I_osh=0;
//    this->mlp=0;
//    this->R=0;
//    this->ro=0;
//    this->Sb0=0;
//    this->sigma=0;
//    this->w=0;
//}

//void IncomingParamsFlutter::SetTestVals(){

//}

//--------------------------------------------------------------------------------

//void Flutter_IsolatedBladeNoFriction_Data_v1::CalcIniIni(){
//    i0_param = data.I_osh / data.I_gsh;
//    dCy_dalfa=0;
//}
Flutter_IsolatedBladeNoFriction_Data_v1::Flutter_IsolatedBladeNoFriction_Data_v1(){
    //wu gut assign all zeros
    this->RigidityCentersLineTypeN=1; //or 2 - ety may be ma mer maqes;
    // I see hin 4 vrns:
    // 1) pairs of: _r, _x
    // 2) medium in bounds: _r_min, _r_max, _x_med
    // 3) bounds and hic vals: _r_min, _x_for_r_min, _r_max, _x_for_r_max
    // 4) hystogram of trapetiums: krum'g o'_x s'lin lam sect, odd et next even s'1 column o'1sect, D can ha idq _x, even et next odd can ha idq _r, ma atal _x
    this->d_frict=0; // see pg 377, mid fmls (3.6) et (3.7)
}

void Flutter_IsolatedBladeNoFriction_Data_v1::SetIniHelicData(const Flutter_IsolatedBladeNoFriction_Data_v1_IncomingHelicParams&data){
    this->b7=data.b7;
    this->chi_param=data.chi_param;
    //this->c_ctrl=data.c_ctrl;
    //this->d_frict=data.d_frict;
    this->I_gsh=data.I_gsh;
    this->I_osh=data.I_osh;
    this->mlp=data.mlp;
    this->R=data.R;
    this->ro=data.ro;
    this->sigma=data.sigma;
    //this->sigma_f=data.sigma_f;
    this->w=data.w;
    //this->x0=data.x0;
    this->Sb0=data.Sb0;
}

void Flutter_IsolatedBladeNoFriction_Data_v1::SetIniExtData(const Flutter_IsolatedBladeNoFriction_Data_v1_IniExt&data){
    this->c_ctrl=data.c_ctrl;
    this->d_frict=data.d_frict;
    this->sigma_f=data.sigma_f;
    this->x0=data.x0;
}

void Flutter_IsolatedBladeNoFriction_Data_v1::SetBladeSupplData(const BladeParamsSupplFlutter&data){
    this->RigidityCentersLine=data.RigidityCentersLine;
    this->RigidityCentersLineTypeN=data.RigidityCentersLineTypeN;
    this->WeightCentersLine=data.WeightCentersLine;
    this->WeightCentersLineTypeN=data.WeightCentersLineTypeN;
}


void Flutter_IsolatedBladeNoFriction_Data_v1::SetHelicSupplData(const HelicParamsSupplFlutter&data){
    this->c_ctrl=data.c_ctrl;
    this->lagerR=data.lagerR;
    this->lagerKFr=data.lagerKfr;
}

void Flutter_IsolatedBladeNoFriction_Data_v1::SetFlutterModeParams(const FlutterModeParams&data){
    //this->x=data.x;
    this->fiAfl=data.fiAfl;
    this->pfl=data.pfl;
}

void Flutter_IsolatedBladeNoFriction_Data_v1::SetIncomingParams(const IncomingParamsFlutter&data){
    //this->x=data.x;
    this->b7=data.b7;
    this->chi_param=data.chi_param;
    //this->c_ctrl=data.c_ctrl;
    //this->d_frict=data.d_frict;
    this->I_gsh=data.I_gsh;
    this->I_osh=data.I_osh;
    this->mlp=data.mlp;
    this->R=data.R;
    this->ro=data.ro;
    this->sigma=data.sigma;
    //this->sigma_f=data.sigma_f;
    this->w=data.w;
    //this->x0=data.x0;
    this->Sb0=data.Sb0;//for friction!
}


void Flutter_IsolatedBladeNoFriction_Data_v1::SetIniKynemConds(std::vector<double>&IniKynemConds){//, double v1_wBeta, double v2_wFi, double v3_Beta, double v4_Fi){
    //double f_Eq1_RP_wBeta(int n, double t, const double*y);
    //double f_Eq2_RP_wFi(int n, double t, const double*y);
    //double f_Eq3_RP_Beta(int n, double t, const double*y);
    //double f_Eq4_RP_Fi(int n, double t, const double*y);
    double v1_wBeta, v2_wFi, v3_Beta, v4_Fi;
    v1_wBeta=0;
    v2_wFi=1E-6;
    v3_Beta=0;
    v4_Fi=0;
    IniKynemConds.push_back(v1_wBeta);
    IniKynemConds.push_back(v2_wFi);
    IniKynemConds.push_back(v3_Beta);
    IniKynemConds.push_back(v4_Fi);
}

//void                                        Calc1_IntegrateBySects(double M_cur, double M_next, int QM,  double MACHs[5][CM][3], int QAlfas, double ALPHAs[5][Ca][3], double _Cy[5][CM][Ca], double _Mz[5][CM][Ca], int QSects, const int*ProfN,  const double*bh, const double*r, double _x_ref=0);
void Flutter_IsolatedBladeNoFriction_Data_v1::Calc1_IntegrateBySects(double M_cur, double M_next, int QMs, double MACHs[5][CM][3], int QAlfas, double ALPHAs[5][Ca][3], double _Cy[5][CM][Ca], double _Mz[5][CM][Ca], int QSects, const int*prof_N, const double*bh, const double*r, double _x_ref){
    void Calc2_char();
    //nSec- QSects, Ca - QAlfas, CM - QMs
    double  CurVal;
    double b_param_cur, b_param_next, dCy_dalfa_cur, dCy_dalfa_next;
    int profN_cur, profN_next, N_M_prev, N_M_next;
    TPosInSucc M_Pos_cur, M_Pos_next;
    //
    i0_param = I_osh / I_gsh;
    dCy_dalfa=0;
    //
    // AD params from blowing data
    //
    for(int secN=0; secN<QSects-1; secN++){//integral cycle
        b_param_cur=bh[secN];   // b_param_next, b_param_cur
        b_param_next=bh[secN+1];  //b_param_next, b_param_cur
        //
        //  def'n dCy/dalfa for cur et next sects
        profN_cur=prof_N[secN];
        profN_next=prof_N[secN+1];
        for(int j=1; j<=QAlfas; j++){
            alfas_cur.push_back(ALPHAs[profN_cur-1][j-1][1-1]);//3. - uz Cy, not Cx et Mz
            alfas_next.push_back(ALPHAs[profN_next-1][j-1][1-1]);//3. - uz Cy, not Cx et Mz
        }
        for(int j=1; j<=QMs; j++){
            Ms_cur.push_back (MACHs[profN_cur -1][j-1][1-1]);//3. - uz Cy, not Cx et Mz
            Ms_next.push_back(MACHs[profN_next-1][j-1][1-1]);//3. - uz Cy, not Cx et Mz
        }
        //seg_cur=this->Segment(secN, psi, beta1, dbeta1, gama1, dgama1, dfi7);
        //seg_next=this->Segment(secN+1, psi, beta1, dbeta1, gama1, dgama1, dfi7);
        //calc dCy_dalfa uz cur
        //M_cur=seg_cur.M;
        M_Pos_cur=PosInSucc(Ms_cur, M_cur);
        if(M_Pos_cur.EqualN>0){
            for(int j=1; j<=QAlfas; j++){
                CysForMCur.push_back(_Cy[profN_cur-1][M_Pos_cur.EqualN-1][j-1]);
                MzsForMCur.push_back(_Mz[profN_cur-1][M_Pos_cur.EqualN-1][j-1]);
                        //MzsForMNext
            }
        }else{
            if(M_Pos_cur.isLess){
               N_M_prev=1;
               N_M_next=2;
           }else if(M_Pos_cur.isGreater){
               N_M_prev=QMs-1;
               N_M_next=QMs;
           }else{
               N_M_prev=M_Pos_cur.lessN;
               N_M_next=M_Pos_cur.lessN+1;
           }
           M_toInterp.push_back(MACHs[profN_cur-1][N_M_prev-1][1-1]);
           M_toInterp.push_back(MACHs[profN_cur-1][N_M_next-1][1-1]);
           for(int j=1; j<=QAlfas; j++){
               Cy_toInterp.clear();
               Mz_toInterp.clear();
               Cy_toInterp.push_back(_Cy[profN_cur-1][N_M_prev-1][j-1]);
               Cy_toInterp.push_back(_Cy[profN_cur-1][N_M_next-1][j-1]);
               CurVal=LinInterp(M_toInterp, Cy_toInterp, M_cur);
               CysForMCur.push_back(CurVal); //interpolated by M
               CurVal=LinInterp(M_toInterp, Mz_toInterp, M_cur);
               MzsForMCur.push_back(CurVal);
           }
        }
        //
        CurVal=0;//vil utf S ak b coef, ic ns'not, ma s'calc'd co k(a) coef
        //void LinearApproximation(const std::vector<double>&X, const std::vector<double>&Y, double&a, double&b);
        LinearApproximation(alfas_cur, CysForMCur, dCy_dalfa_cur, CurVal);//Nu -> dCy_dalfa_cur <- s'ved
        //
        //calc dCy_dalfa uz next
        //M_next=seg_next.M;//nu os param
        M_Pos_next=PosInSucc(Ms_next, M_next);
        if(M_Pos_next.EqualN>0){
            for(int j=1; j<=QAlfas; j++){
                CysForMNext.push_back(_Cy[profN_next-1][M_Pos_next.EqualN-1][j-1]);
                MzsForMNext.push_back(_Mz[profN_cur-1][M_Pos_cur.EqualN-1][j-1]);
            }
        }else{
            if(M_Pos_next.isLess){
               N_M_prev=1;
               N_M_next=2;
           }else if(M_Pos_next.isGreater){
               N_M_prev=QMs-1;
               N_M_next=QMs;
           }else{
               N_M_prev=M_Pos_cur.lessN;
               N_M_next=M_Pos_cur.lessN+1;
           }
           M_toInterp.clear();
           M_toInterp.push_back(MACHs[profN_cur-1][N_M_prev-1][1-1]);
           M_toInterp.push_back(MACHs[profN_cur-1][N_M_next-1][1-1]);
           for(int j=1; j<=QAlfas; j++){
               Cy_toInterp.clear();
               Mz_toInterp.clear();
               Cy_toInterp.push_back(_Cy[profN_next-1][N_M_prev-1][j-1]);
               Cy_toInterp.push_back(_Cy[profN_next-1][N_M_next-1][j-1]);
               CurVal=LinInterp(M_toInterp, Cy_toInterp, M_next);
               CysForMNext.push_back(CurVal);
               CurVal=LinInterp(M_toInterp, Mz_toInterp, M_next);
               MzsForMNext.push_back(CurVal);
           }
        }
        //
        CurVal=0;//vil utf S ak b coef, ic ns'not, ma s'calc'd co k(a) coef. Ors param f'b ns'not f'math, ma S'not f'fn, ic calc ety k(a), ic s'not f'math
        //void LinearApproximation(const std::vector<double>&X, const std::vector<double>&Y, double&a, double&b);
        LinearApproximation(alfas_next, CysForMNext, dCy_dalfa_next, CurVal);//Nu dCy_dalfa_next s'ved
        //
        CurVal = (mlp*sigma* (r[secN]+r[secN+1]) /2* (r[secN+1]-r[secN]));
        c21_SubInt+=CurVal;
        //
        //
        CurVal = (b_param_cur*r[secN]*r[secN]*r[secN] *dCy_dalfa_cur + b_param_next*r[secN+1]*r[secN+1]*r[secN+1]) *dCy_dalfa_next /2* (r[secN+1]-r[secN]); //error: b is blade, ne chord!
        d11_SubInt+=CurVal;
        //
        //
        CurVal = ((b_param_cur*b_param_cur*r[secN]*r[secN]) * (3.0/4.0-x0/b_param_cur) *dCy_dalfa_cur + (b_param_next*b_param_next*r[secN+1]*r[secN+1]) * (3.0/4.0-x0/b_param_next) *dCy_dalfa_next) /2* (r[secN+1]-r[secN]);
        d12_SubInt+=CurVal;
        //
        //
        CurVal = (b_param_cur*r[secN]*r[secN] *dCy_dalfa_cur + b_param_next*r[secN+1]*r[secN+1]) *dCy_dalfa_next /2* (r[secN+1]-r[secN]) * sigma_f;
        d21_SubInt+=CurVal;
        //
        //
        CurVal = (b_param_cur*b_param_cur*b_param_cur*r[secN] + b_param_next*b_param_next*b_param_next*r[secN+1]) /2* (r[secN+1]-r[secN]);
        d22_SubInt1+=CurVal;
        //
        CurVal = ( (b_param_cur*b_param_cur*r[secN]) * (3.0/4.0-x0/b_param_cur) *dCy_dalfa_cur
                   +
                   (b_param_next*b_param_next*r[secN+1]) * (3.0/4.0-x0/b_param_next) *dCy_dalfa_next
                 ) /2* (r[secN+1]-r[secN]) * sigma_f;
        d22_SubInt2+=CurVal;
        //
        //
        CurVal = (b_param_cur*r[secN]*r[secN]*r[secN] + b_param_next*r[secN+1]*r[secN+1]*r[secN+1]) /2* (r[secN+1]-r[secN]);
        b12_SubInt+=CurVal;
        //
        //
        CurVal = (b_param_cur*r[secN]*r[secN] + b_param_next*r[secN+1]*r[secN+1]) /2* (r[secN+1]-r[secN]) * sigma_f;
        b22_SubInt+=CurVal;
        //
        //S'not dCy/dalfa uz gamma0 - tam no integral, tam s'not integr'l val
        dCy_dalfa += (dCy_dalfa_cur+dCy_dalfa_next) /2* (r[secN+1]-r[secN]);
        //
    }//intrgral cycle
    //
    gamma0_param=dCy_dalfa*ro*b7*R*R*R*R/(2*I_gsh);
    //
    c21=-1/I_osh*c21_SubInt;
    c12=i0_param*c21;
    d11=dCy_dalfa/2*ro/I_gsh*d11_SubInt;
    d12=-dCy_dalfa/2*ro/I_gsh*d12_SubInt;
    d21=-dCy_dalfa/2*ro/I_gsh*d21_SubInt;
    d22=1/I_osh*(M_PI/16*ro*d22_SubInt1 + dCy_dalfa*ro/2*d22_SubInt2) + d_frict;
    b12=-dCy_dalfa/2*ro/I_gsh*b12_SubInt+i0_param*c21;
    b22=1+dCy_dalfa/2*ro/I_gsh*b22_SubInt;
}//fn Calc1
void Flutter_IsolatedBladeNoFriction_Data_v1::Calc2_char(){
    double eps=1E-7;
    //
    double denom,//=C1*C1+A1*(A1*D1-B1*C1),
           numeratL,//=C1*(2*C2-A1*B2)+A1*(A1*D2-B1*C2),
           numeratM;//=C2*(C2-A1*B2);
    //
    //A1=1/(1-i0_param*c21*c21)*(d11+d12-c12*d21-c21*d12);//pg363
    //B1=1/(1-i0_param*c21*c21)*(1+b22+d11*d22-b12*c21-d12*d21-c12*c21);
    //B2=1/(1-i0_param*c21*c21)*(1-chi_param*c12);
    //C1=1/(1-i0_param*c21*c21)*(d22+d11*b22-b12*d21-c21*d12);
    //C2=1/(1-i0_param*c21*c21)*(d11-chi_param*d12);
    //D1=1/(1-i0_param*c21*c21)*(b22-b12*c21);
    //D2=1/(1-i0_param*c21*c21)*(1-chi_param*b12);
    //
    denom=1-this->i0_param*this->c21*this->c21;
    this->A1=1/denom*(this->d11 + this->d22 - this->c12 * this->d21 - this->c21 * this->d12);
    this->B1=1/denom*(1+this->b22 + this->d11 * this->d22 - this->b12 * this->c21-this->d12  *this->d21 - this->c12 * this->c21);
    this->B1=1/denom*(1-this->chi_param * this->c12);
    this->C1=1/denom*(this->d22 + this->d11 * this->b22 - this->b12 * this->d21 - this->c21 * this->d12);
    this->C2=1/denom*(this->d11 - this->chi_param * this->d12);
    this->D1=1/denom*(this->b22 - this->b12 * this->c21);
    this->D2=1/denom*(1-this->chi_param * this->b12);
    //
    //Cp4=1;
    //Cp3=A1*w;
    //Cp2=B1*w*w+B2;
    //Cp1=(C1*w*w+C2)*w;
    //Cp0=D1*w*w*w*w+D2*w*w;
    //
    this->Cp4 = 1;
    this->Cp3 = this->A1*this->w;
    this->Cp2 = this->B1*this->w*this->w + this->B2;
    this->Cp1 = (this->C1*this->w*this->w+this->C2)*this->w;
    this->Cp0 = this->D1 * this->w*this->w*this->w*this->w + this->D2 * this->w*this->w;
    //
    //int EquationOf4thPower(double c4, double c3, double c2, double c1, double c0, std::vector<double>&ReX, std::vector<double>&ReY);
    EquationOf4thPower(Cp4, Cp3, Cp2, Cp1, Cp0, ReX, ImX);
    //
    //if(ImX[1-1]==0 && ImX[2-1]==0 && ImX[3-1]==0 && ImX[4-1]2==0){
    //
    //}else if(ImX[4-1]==0 && ImX[3-1]==0 && ImX[1-1]!=0 && ImX[2-1]!=0){
    //    if(fApprET(ImX[1-1], -ImX[2-1], eps) && fApprET(ReX[1-1], ReX[2-1], eps)){
    //
    //    }else{
    //        //Error!: ms'be complex-conjugated
    //    }
    //}else if(ImX[4-1]==0 && ImX[2-1]==0 && ImX[1-1]!=0 && ImX[3-1]!=0){
    //    if(fApprET(ImX[1-1], -ImX[3-1], eps) && fApprET(ReX[1-1], ReX[3-1], eps)){
    //
    //    }else{
    //        //Error!: ms'be complex-conjugated
    //    }
    //}else if(ImX[4-1]==0 && ImX[1-1]==0 && ImX[2-1]!=0 && ImX[3-1]!=0){
    //    if(fApprET(ImX[2-1], -ImX[3-1], eps) && fApprET(ReX[2-1], ReX[3-1], eps)){
    //
    //    }else{
    //        //Error!: ms'be complex-conjugated
    //    }
    //}else if(ImX[3-1]==0 && ImX[2-1]==0 && ImX[4-1]!=0 && ImX[1-1]!=0){
    //    if(fApprET(ImX[1-1], -ImX[4-1], eps) && fApprET(ReX[1-1], ReX[4-1], eps)){
    //
    //    }else{
    //        //Error!: ms'be complex-conjugated
    //    }
    //}else if(ImX[3-1]==0 && ImX[1-1]==0 && ImX[4-1]!=0 && ImX[2-1]!=0){
    //    if(fApprET(ImX[2-1], -ImX[4-1], eps) && fApprET(ReX[2-1], ReX[4-1], eps)){
    //
    //    }else{
    //        //Error!: ms'be complex-conjugated
    //    }
    //}else if(ImX[2-1]==0 && ImX[1-1]==0 && ImX[4-1]!=0 && ImX[3-1]!=0){
    //    if(fApprET(ImX[3-1], -ImX[4-1], eps) && fApprET(ReX[3-1], ReX[4-1], eps)){
    //
    //    }else{
    //        //Error!: ms'be complex-conjugated
    //    }
    //}else if(ImX[1-1]!=0 && ImX[2-1]!=0 && ImX[3-1]!=0 && ImX[4-1!=0]){
    //    if(fApprET(ImX[1-1], -ImX[2-1], eps) && fApprET(ImX[3-1], -ImX[4-1], eps) && fApprET(ReX[1-1], ReX[2-1], eps) && fApprET(ReX[3-1], ReX[4-1], eps)){
    //
    //    }else if(fApprET(ImX[1-1], -ImX[3-1], eps) && fApprET(ImX[2-1], -ImX[4-1], eps) && fApprET(ReX[1-1], ReX[3-1], eps) && fApprET(ReX[2-1], ReX[4-1], eps)){
    //
    //        }else if(fApprET(ImX[1-1], -ImX[4-1], eps) && fApprET(ImX[2-1], -ImX[3-1], eps) && fApprET(ReX[1-1], ReX[4-1], eps) && fApprET(ReX[2-1], ReX[3-1], eps)){
    //
    //        }else{
    //             //Error!: ms'be complex-conjugated
    //        }
    //    }
    //}//if Re, Im
    //
    //Let be so. Re(lambdaII) can be
    if(fApprET(ImX[1-1], 0, eps) && fApprET(ImX[2-1], 0, eps) && fApprET(ImX[3-1], 0, eps) && fApprET(ImX[4-1], 0, eps)){
        //so n'ms'b

    }else if(fApprET(ImX[4-1], 0, eps) &&  fApprET(ImX[3-1], 0, eps) && fApprNE(ImX[1-1], 0, eps) && fApprNE(ImX[2-1], 0, eps)){
        if(fApprET(ImX[1-1], -ImX[2-1], eps) && fApprET(ReX[1-1], ReX[2-1], eps)){
            lambdaI_Im[1-1]=0;
            lambdaI_Im[2-1]=0;
            lambdaI_Re[1-1]=0;
            lambdaI_Re[2-1]=0;
            //
            lambdaII_Im[1-1]=0;
            lambdaII_Im[2-1]=0;
            lambdaII_Re[1-1]=0;
            lambdaII_Re[2-1]=0;
        }else{
            //Error!: ms'be complex-conjugated
        }
    }else if(fApprET(ImX[4-1], 0, eps) && fApprET(ImX[2-1], 0, eps) && fApprNE(ImX[1-1], 0, eps) && fApprNE(ImX[3-1], 0, eps)){
        if(fApprET(ImX[1-1], -ImX[3-1], eps) && fApprET(ReX[1-1], ReX[3-1], eps)){

        }else{
            //Error!: ms'be complex-conjugated
        }
    }else if(fApprET(ImX[4-1], 0, eps) && fApprET(ImX[1-1], 0, eps) && fApprNE(ImX[2-1], 0, eps) && fApprNE(ImX[3-1], 0, eps)){
        if(fApprET(ImX[2-1], -ImX[3-1], eps) && fApprET(ReX[2-1], ReX[3-1], eps)){

        }else{
            //Error!: ms'be complex-conjugated
        }
    }else if(fApprET(ImX[3-1], 0, eps) && fApprET(ImX[2-1], 0, eps) && fApprNE(ImX[4-1], 0, eps) && fApprNE(ImX[1-1], 0, eps)){
        if(fApprET(ImX[1-1], -ImX[4-1], eps) && fApprET(ReX[1-1], ReX[4-1], eps)){

        }else{
            //Error!: ms'be complex-conjugated
        }
    }else if(fApprET(ImX[3-1], 0, eps) && fApprET(ImX[1-1], 0, eps) && fApprNE(ImX[4-1], 0, eps) && fApprNE(ImX[2-1], 0, eps)){
        if(fApprET(ImX[2-1], -ImX[4-1], eps) && fApprET(ReX[2-1], ReX[4-1], eps)){

        }else{
            //Error!: ms'be complex-conjugated
        }
    }else if(fApprET(ImX[2-1], 0, eps) && fApprET(ImX[1-1], 0, eps) && fApprNE(ImX[4-1], 0, eps) && fApprNE(ImX[3-1], 0, eps)){
        if(fApprET(ImX[3-1], -ImX[4-1], eps) && fApprET(ReX[3-1], ReX[4-1], eps)){

        }else{
            //Error!: ms'be complex-conjugated
        }
    }else if(fApprNE(ImX[1-1], 0, eps) && fApprNE(ImX[2-1], 0, eps) && fApprNE(ImX[3-1], 0, eps) && fApprNE(ImX[4-1], 0, eps)){
        if(fApprET(ImX[1-1], -ImX[2-1], eps) && fApprET(ImX[3-1], -ImX[4-1], eps) && fApprET(ReX[1-1], ReX[2-1], eps) && fApprET(ReX[3-1], ReX[4-1], eps)){
            lambdaI_Re[1-1]=ReX[1-1];
            lambdaI_Im[1-1]=ImX[1-1];
            lambdaI_Re[2-1]=ReX[2-1];
            lambdaI_Im[2-1]=ImX[2-1];
            //
            lambdaII_Re[1-1]=ReX[3-1];
            lambdaII_Im[1-1]=ImX[3-1];
            lambdaII_Re[2-1]=ReX[4-1];
            lambdaII_Im[2-1]=ImX[4-1];
            //ma mab lambda I et II ms'b exchanged
        }else if(fApprET(ImX[1-1], -ImX[3-1], eps) && fApprET(ImX[2-1], -ImX[4-1], eps) && fApprET(ReX[1-1], ReX[3-1], eps) && fApprET(ReX[2-1], ReX[4-1], eps)){
            lambdaI_Re[1-1]=ReX[1-1];
            lambdaI_Im[1-1]=ImX[1-1];
            lambdaI_Re[2-1]=ReX[3-1];
            lambdaI_Im[2-1]=ImX[3-1];
            //
            lambdaII_Re[1-1]=ReX[2-1];
            lambdaII_Im[1-1]=ImX[2-1];
            lambdaII_Re[2-1]=ReX[4-1];
            lambdaII_Im[2-1]=ImX[4-1];
            //ma mab lambda I et II ms'b exchanged
        }else if(fApprET(ImX[1-1], -ImX[4-1], eps) && fApprET(ImX[2-1], -ImX[3-1], eps) && fApprET(ReX[1-1], ReX[4-1], eps) && fApprET(ReX[2-1], ReX[3-1], eps)){
            lambdaI_Re[1-1]=ReX[1-1];
            lambdaI_Im[1-1]=ImX[1-1];
            lambdaI_Re[2-1]=ReX[4-1];
            lambdaI_Im[2-1]=ImX[4-1];
            //
            lambdaII_Re[1-1]=ReX[2-1];
            lambdaII_Im[1-1]=ImX[2-1];
            lambdaII_Re[2-1]=ReX[3-1];
            lambdaII_Im[2-1]=ImX[3-1];
            //ma mab lambda I et II ms'b exchanged
        }else{
             //Error!: ms'be complex-conjugated
        }
    }//if Re, Im
    //
    denom=C1*C1+A1*(A1*D1-B1*C1),
    numeratL=C1*(2*C2-A1*B2)+A1*(A1*D2-B1*C2),
    numeratM=C2*(C2-A1*B2);
    if(denom!=0){
        this->L=0.5*numeratL/denom;
        this->M=numeratM/denom;
    }else{
        //error
    }
    this->L=0.5*((C1*(2*C2-A1*B2)+A1*(A1*D2-B1*C2))/(C1*C1));
}
//



//void Flutter_IsolatedBladeNoFriction_Data_v1::Calc3_critParams(){
//    double denom=C1*C1+A1*(A1*D1-B1*C1),
//           numeratL=C1*(2*C2-A1*B2)+A1*(A1*D2-B1*C2),
//           numeratM=C2*(C2-A1*B2);
//    if(denom!=0){
//        this->L=0.5*numeratL/denom;
//        this->M=numeratM/denom;
//    }else{
//        //error
//    }
//    this->L=0.5*((C1*(2*C2-A1*B2)+A1*(A1*D2-B1*C2))/(C1*C1));
//}

void Flutter_IsolatedBladeNoFriction_Data_v1::Calc4_UDECoefs_IniSys1(const Flutter_IsolatedBladeNoFriction_Data_v1_ParamsIniForCalcEquations&data){
    this->C_S1E1_beta2 = 1;
    this->C_S1E1_beta1 = data.d11*data.w;
    this->C_S1E1_beta0 = data.w*data.w;

    this->C_S1E1_fi2 = data.c12;
    this->C_S1E1_fi1 = data.d12*data.w;;
    this->C_S1E1_fi0 = data.b12*data.w*data.w;
    //
    this->C_S1E2_fi2 = 1;
    this->C_S1E2_fi1 = data.d22*data.w*data.w;
    this->C_S1E2_fi0 = data.p_cr*data.p_cr + data.b22*data.w*data.w;//data.chi_param;

    this->C_S1E2_beta2 = data.c21;
    this->C_S1E2_beta1 = data.d21*data.w;;
    this->C_S1E2_beta0 = data.chi_param * data.p_cr*data.p_cr + data.c21 * data.w*data.w;
    //
}
void Flutter_IsolatedBladeNoFriction_Data_v1::Calc5_UDECoefs_EqvSys2(){
    double SysDet;
    //
    SysDet = this->C_S1E1_beta2 * this->C_S1E2_fi2 - this->C_S1E2_beta2 * this->C_S1E1_fi2;
    //
    this->C_S2EBeta_beta1=(this->C_S1E2_beta1 * this->C_S1E1_fi2 - this->C_S1E2_fi2 * this->C_S1E1_beta1)/SysDet;
    this->C_S2EBeta_fi1=(this->C_S1E2_fi2*  this->C_S1E2_fi1 - this->C_S1E2_fi2 * this->C_S1E1_fi1)/SysDet;
    this->C_S2EBeta_beta0=(this->C_S1E1_fi2 * this->C_S1E2_beta0 - this->C_S1E2_fi2 * this->C_S1E1_beta0)/SysDet;
    this->C_S2EBeta_fi0=(this->C_S1E1_fi2 * this->C_S1E2_fi0 - this->C_S1E2_fi2 * this->C_S1E1_fi0)/SysDet;
    this->C_S2EFi_beta1=(this->C_S1E2_beta2 * this->C_S1E1_beta1 - this->C_S1E2_beta2 * this->C_S1E1_fi2)/SysDet;
    this->C_S2EFi_fi1=(this->C_S1E2_beta2 * this->C_S1E1_fi1 - this->C_S1E1_beta2 * this->C_S1E2_fi1)/SysDet;
    this->C_S2EFi_beta0=(this->C_S1E2_beta2 * this->C_S1E1_beta0 - this->C_S1E1_beta2 * this->C_S1E2_beta0)/SysDet;
    this->C_S2EFi_fi0=(this->C_S1E2_beta2 * this->C_S1E1_fi0 - this->C_S1E1_beta2 * this->C_S1E2_fi0)/SysDet;
    //
}
void Flutter_IsolatedBladeNoFriction_Data_v1::TestUDECoefs_EqvSys2(){
    Flutter_IsolatedBladeNoFriction_Data_v1_ParamsIniForCalcEquations data;
    data.SetTestValues();
    //
    double beta_2, beta_1, beta_0, fi_2, fi_1, fi_0;
    //
    this->C_S1E1_beta2 = 1;
    this->C_S1E1_beta1 = data.d11*data.w;
    this->C_S1E1_beta0 = data.w*data.w;

    this->C_S1E1_fi2 = data.c12;
    this->C_S1E1_fi1 = data.d12*data.w;;
    this->C_S1E1_fi0 = data.b12*data.w*data.w;
    //
    this->C_S1E2_fi2 = 1;
    this->C_S1E2_fi1 = data.d22*data.w*data.w;
    this->C_S1E2_fi0 = data.p_cr*data.p_cr+data.b22*data.w*data.w;

    this->C_S1E2_beta2 = data.c21;
    this->C_S1E2_beta1 = data.d21*data.w;;
    this->C_S1E2_beta0 = data.chi_param*data.p_cr*data.p_cr+data.c21*data.w*data.w;
    //
    this->Calc5_UDECoefs_EqvSys2();
    //
}
//
double Flutter_IsolatedBladeNoFriction_Data_v1::f_S1E1_RP(double wBeta, double wFi, double Beta, double Fi){
    double rslt=(this->C_S1E1_beta1 * wBeta + this->C_S1E1_beta0 * Beta + this->C_S1E1_fi1 * wFi + this->C_S1E1_fi0 * Fi)*(-1);
    return rslt;
}

double Flutter_IsolatedBladeNoFriction_Data_v1::f_S1E2_RP(double wBeta, double wFi, double Beta, double Fi){
    double rslt=(this->C_S1E2_beta1 * wBeta + this->C_S1E2_beta0 * Beta + this->C_S1E2_fi1 * wFi + this->C_S1E2_fi0  *Fi)*(-1);
    return rslt;
}
//
double Flutter_IsolatedBladeNoFriction_Data_v1::f_S2EBeta_RP(double wBeta, double wFi,double Beta, double Fi){
    double rp1=0, rp2=0;
    double detSys, detBeta, detFi;
    double S1LinReDerivs2E1_C_beta2=this->C_S1E1_beta2,
           S1LinReDerivs2E2_C_beta2=this->C_S1E2_beta2,
           S1LinReDerivs2E1_C_fi2=this->C_S1E1_fi2,
           S1LinReDerivs2E2_C_fi2=this->C_S1E2_fi2,
           S1LinReDerivs2E1_RP=this->C_S1E1_beta1*wBeta+this->C_S1E1_beta0*Beta + this->C_S1E1_fi1*wFi+this->C_S1E1_fi0*Fi,
           S1LinReDerivs2E2_RP=this->C_S1E2_beta1*wBeta+this->C_S1E2_beta0*Beta + this->C_S1E2_fi1*wFi+this->C_S1E2_fi0*Fi;
    detSys=S1LinReDerivs2E1_C_beta2*S1LinReDerivs2E2_C_fi2-S1LinReDerivs2E1_C_fi2*S1LinReDerivs2E2_C_beta2;
    detBeta=S1LinReDerivs2E1_RP*S1LinReDerivs2E2_C_fi2-S1LinReDerivs2E1_C_fi2*S1LinReDerivs2E2_RP;
    detFi=S1LinReDerivs2E1_C_beta2*S1LinReDerivs2E2_RP-S1LinReDerivs2E1_RP*S1LinReDerivs2E2_C_beta2;
    if(detSys!=0){
        rp1=detBeta/detSys;
        rp2=detFi/detSys;
    }//else wu gut Seidel method
    return rp1;
}
double Flutter_IsolatedBladeNoFriction_Data_v1::f_S2EFi_RP(double wBeta, double wFi,double Beta, double Fi){
    double rp1=0, rp2=0;
    double detSys, detBeta, detFi;
    double S1LinReDerivs2E1_C_beta2=this->C_S1E1_beta2,
           S1LinReDerivs2E2_C_beta2=this->C_S1E2_beta2,
           S1LinReDerivs2E1_C_fi2=this->C_S1E1_fi2,
           S1LinReDerivs2E2_C_fi2=this->C_S1E2_fi2,
           S1LinReDerivs2E1_RP=this->C_S1E1_beta1*wBeta+this->C_S1E1_beta0*Beta + this->C_S1E1_fi1*wFi+this->C_S1E1_fi0*Fi,
           S1LinReDerivs2E2_RP=this->C_S1E2_beta1*wBeta+this->C_S1E2_beta0*Beta + this->C_S1E2_fi1*wFi+this->C_S1E2_fi0*Fi;
    detSys=S1LinReDerivs2E1_C_beta2*S1LinReDerivs2E2_C_fi2-S1LinReDerivs2E1_C_fi2*S1LinReDerivs2E2_C_beta2;
    detBeta=S1LinReDerivs2E1_RP*S1LinReDerivs2E2_C_fi2-S1LinReDerivs2E1_C_fi2*S1LinReDerivs2E2_RP;
    detFi=S1LinReDerivs2E1_C_beta2*S1LinReDerivs2E2_RP-S1LinReDerivs2E1_RP*S1LinReDerivs2E2_C_beta2;
    if(detSys!=0){
        rp1=detBeta/detSys;
        rp2=detFi/detSys;
    }//else wu gut Seidel method
    return rp2;
}
//
//double Flutter_IsolatedBladeNoFriction_Data_v1::f_S2EBeta_RP(double wBeta, double wFi, double Beta, double Fi){
//    double rslt = this->C_S2EBeta_beta1 * wBeta + this->C_S2EBeta_beta0 * Beta + this->C_S2EBeta_fi1 * wFi + this->C_S2EBeta_fi0 * Fi;
//    return rslt;
//}

//double Flutter_IsolatedBladeNoFriction_Data_v1::f_S2EFi_RP(double wBeta, double wFi, double Beta, double Fi){
//    double rslt = this->C_S2EFi_beta1 * wBeta + this->C_S2EFi_beta0 * Beta + this->C_S2EFi_fi1 * wFi + this->C_S2EFi_fi0 * Fi;
//    return rslt;
//}

//
double Flutter_IsolatedBladeNoFriction_Data_v1::f_Eq1_RP_wBeta(int n, double t, const double*y){
    double wBeta=y[1-1], wFi=y[2-1], Beta=y[3-1], Fi=y[4-1], rslt;
    rslt=this->f_S2EBeta_RP(wBeta, wFi, Beta, Fi);
    return rslt;
}

double Flutter_IsolatedBladeNoFriction_Data_v1::f_Eq2_RP_wFi(int n, double t, const double*y){
    double wBeta=y[1-1], wFi=y[2-1], Beta=y[3-1], Fi=y[4-1], rslt;
    rslt=this->f_S2EFi_RP(wBeta, wFi, Beta, Fi);
    return rslt;
}

double Flutter_IsolatedBladeNoFriction_Data_v1::f_Eq3_RP_Beta(int n, double t, const double*y){
    double wBeta=y[1-1], wFi=y[2-1], Beta=y[3-1], Fi=y[4-1], rslt;
    rslt=wBeta;
    return rslt;
}

double Flutter_IsolatedBladeNoFriction_Data_v1::f_Eq4_RP_Fi(int n, double t, const double*y){
    double wBeta=y[1-1], wFi=y[2-1], Beta=y[3-1], Fi=y[4-1], rslt;
    rslt=wFi;
    return rslt;
}

Flutter_IsolatedBladeNoFriction_Data_v1_ParamsIniForCalcEquations Flutter_IsolatedBladeNoFriction_Data_v1::GetParamsForEquations(){
    Flutter_IsolatedBladeNoFriction_Data_v1_ParamsIniForCalcEquations data;
    //
    data.b12=this->b12;
    data.b22=this->b22;
    data.c12=this->c12;
    data.c21=this->c21;
    data.chi_param=this->chi_param;
    data.d11=this->d11;
    data.d12=this->d12;
    data.d21=this->d21;
    data.d22=this->d22;
    data.p_cr=this->p_cr;
    data.w=this->w;//q'tak?
    //
    return data;
}

Flutter_IsolatedBladeNoFriction_Data_v1_Results Flutter_IsolatedBladeNoFriction_Data_v1::CalcAll(const Flutter_IsolatedBladeNoFriction_Data_v1_IncomingHelicParams&HelicData, const Flutter_IsolatedBladeNoFriction_Data_v1_IniExt&data){
    Flutter_IsolatedBladeNoFriction_Data_v1_Results resData;
    Flutter_IsolatedBladeNoFriction_Data_v1_ParamsIniForCalcEquations dataForEqs;
    //set1
    //void SetIniHelicData(const Flutter_IsolatedBladeNoFriction_Data_v1_IncomingHelicParams&data){
    //  class Flutter_IsolatedBladeNoFriction_Data_v1_IncomingHelicParams{
    //  public:
    //  double I_osh, I_gsh, mlp, sigma, ro, R, b7, chi_param, w ;
    //    //double c_ctrl, d_fric, x0, sigma_f;
    //    Flutter_IsolatedBladeNoFriction_Data_v1_IncomingHelicParams();
    //};
    this->b7        = HelicData.b7;
    this->chi_param = HelicData.chi_param;
    this->I_gsh     = HelicData.I_gsh;
    this->I_osh     = HelicData.I_osh;
    this->mlp       = HelicData.mlp;
    this->R         = HelicData.R;
    this->ro        = HelicData.ro;
    this->sigma     = HelicData.sigma;
    this->w         = HelicData.w;
    //}
    //void Flutter_IsolatedBladeNoFriction_Data_v1::SetIniExtData(const Flutter_IsolatedBladeNoFriction_Data_v1_IniExt&data){
    this->c_ctrl=data.c_ctrl;
    this->d_frict=data.d_frict;
    this->sigma_f=data.sigma_f;
    this->x0=data.x0;
    //}
    //
    //
    //return resData;
    //}
    //void Flutter_IsolatedBladeNoFriction_Data_v1::Calc1_IntegrateBySects(double M_cur, double M_next, int QMs, const double***MACH, int QAlfas, const double***ALPHA, const double***_Cy, int QSects, const int*prof_N, const double*bh, const double*r){
    //nSec- QSects, Ca - QAlfas, CM - QMs
    double  CurVal;
    double b_param_cur, b_param_next, dCy_dalfa_cur, dCy_dalfa_next;
    int profN_cur, profN_next, N_M_prev, N_M_next;
    TPosInSucc M_Pos_cur, M_Pos_next;
    //
    i0_param = I_osh / I_gsh;
    dCy_dalfa=0;
    //
    // AD params from blowing data
    //
//    for(int secN=0; secN<QSects-1; secN++){//integral cycle
//        b_param_cur=bh[secN];   // b_param_next, b_param_cur
//        b_param_next=bh[secN+1];  //b_param_next, b_param_cur
//        //
//        //  def'n dCy/dalfa for cur et next sects
//        profN_cur=prof_N[secN];
//        profN_next=prof_N[secN+1];
//        for(int j=1; j<=QAlfas; j++){
//            alfas_cur.push_back(ALPHA[profN_cur-1][j-1][1-1]);//3. - uz Cy, not Cx et Mz
//            alfas_next.push_back(ALPHA[profN_next-1][j-1][1-1]);//3. - uz Cy, not Cx et Mz
//        }
//        for(int j=1; j<=QMs; j++){
//            Ms_cur.push_back (MACH[profN_cur -1][j-1][1-1]);//3. - uz Cy, not Cx et Mz
//            Ms_next.push_back(MACH[profN_next-1][j-1][1-1]);//3. - uz Cy, not Cx et Mz
//        }
//        //seg_cur=this->Segment(secN, psi, beta1, dbeta1, gama1, dgama1, dfi7);
//        //seg_next=this->Segment(secN+1, psi, beta1, dbeta1, gama1, dgama1, dfi7);
//        //calc dCy_dalfa uz cur
//        //M_cur=seg_cur.M;
//        M_Pos_cur=PosInSucc(Ms_cur, M_cur);
//        if(M_Pos_cur.EqualN>0){
//            for(int j=1; j<=QAlfas; j++){
//                CysForMCur.push_back(_Cy[profN_cur-1][M_Pos_cur.EqualN-1][j-1]);
//            }
//        }else{
//            if(M_Pos_cur.isLess){
//               N_M_prev=1;
//               N_M_next=2;
//           }else if(M_Pos_cur.isGreater){
//               N_M_prev=QMs-1;
//               N_M_next=QMs;
//           }else{
//               N_M_prev=M_Pos_cur.lessN;
//               N_M_next=M_Pos_cur.lessN+1;
//           }
//           M_toInterp.push_back(MACHs[profN_cur-1][N_M_prev-1][1-1]);
//           M_toInterp.push_back(MACHs[profN_cur-1][N_M_next-1][1-1]);
//           for(int j=1; j<=QAlfas; j++){
//               Cy_toInterp.clear();
//               Cy_toInterp.push_back(_Cy[profN_cur-1][N_M_prev-1][j-1]);
//               Cy_toInterp.push_back(_Cy[profN_cur-1][N_M_next-1][j-1]);
//               CurVal=LinInterp(M_toInterp, Cy_toInterp, M_cur);
//               CysForMCur.push_back(CurVal); //interpolated by M
//           }
//        }
//        //
//        CurVal=0;//vil utf S ak b coef, ic ns'not, ma s'calc'd co k(a) coef
//        //void LinearApproximation(const std::vector<double>&X, const std::vector<double>&Y, double&a, double&b);
//        LinearApproximation(alfas_cur, CysForMCur, dCy_dalfa_cur, CurVal);//Nu -> dCy_dalfa_cur <- s'ved
//        //
//        //calc dCy_dalfa uz next
//        //M_next=seg_next.M;//nu os param
//        M_Pos_next=PosInSucc(Ms_next, M_next);
//        if(M_Pos_next.EqualN>0){
//            for(int j=1; j<=QAlfas; j++){
//                CysForMNext.push_back(_Cy[profN_next-1][M_Pos_next.EqualN-1][j-1]);
//            }
//        }else{
//            if(M_Pos_next.isLess){
//               N_M_prev=1;
//               N_M_next=2;
//           }else if(M_Pos_next.isGreater){
//               N_M_prev=QMs-1;
//               N_M_next=QMs;
//           }else{
//               N_M_prev=M_Pos_cur.lessN;
//               N_M_next=M_Pos_cur.lessN+1;
//           }
//           M_toInterp.clear();
//           M_toInterp.push_back(MACH[profN_cur-1][N_M_prev-1][1-1]);
//           M_toInterp.push_back(MACH[profN_cur-1][N_M_next-1][1-1]);
//           for(int j=1; j<=QAlfas; j++){
//               Cy_toInterp.clear();
//               Cy_toInterp.push_back(_Cy[profN_next-1][N_M_prev-1][j-1]);
//               Cy_toInterp.push_back(_Cy[profN_next-1][N_M_next-1][j-1]);
//               CurVal=LinInterp(M_toInterp, Cy_toInterp, M_next);
//               CysForMNext.push_back(CurVal);
//           }
//        }
//        //
//        CurVal=0;//vil utf S ak b coef, ic ns'not, ma s'calc'd co k(a) coef. Ors param f'b ns'not f'math, ma S'not f'fn, ic calc ety k(a), ic s'not f'math
//        //void LinearApproximation(const std::vector<double>&X, const std::vector<double>&Y, double&a, double&b);
//        LinearApproximation(alfas_next, CysForMNext, dCy_dalfa_next, CurVal);//Nu dCy_dalfa_next s'ved
//        //
//        CurVal = (mlp*sigma* (r[secN]+r[secN+1]) /2* (r[secN+1]-r[secN]));
//        c21_SubInt+=CurVal;
//        //
//        //
//        CurVal = (b_param_cur*r[secN]*r[secN]*r[secN] *dCy_dalfa_cur + b_param_next*r[secN+1]*r[secN+1]*r[secN+1]) *dCy_dalfa_next /2* (r[secN+1]-r[secN]); //error: b is blade, ne chord!
//        d11_SubInt+=CurVal;
//        //
//        //
//        CurVal = ((b_param_cur*b_param_cur*r[secN]*r[secN]) * (3.0/4.0-x0/b_param_cur) *dCy_dalfa_cur + (b_param_next*b_param_next*r[secN+1]*r[secN+1]) * (3.0/4.0-x0/b_param_next) *dCy_dalfa_next) /2* (r[secN+1]-r[secN]);
//        d12_SubInt+=CurVal;
//        //
//        //
//        CurVal = (b_param_cur*r[secN]*r[secN] *dCy_dalfa_cur + b_param_next*r[secN+1]*r[secN+1]) *dCy_dalfa_next /2* (r[secN+1]-r[secN]) * sigma_f;
//        d21_SubInt+=CurVal;
//        //
//        //
//        CurVal = (b_param_cur*b_param_cur*b_param_cur*r[secN] + b_param_next*b_param_next*b_param_next*r[secN+1]) /2* (r[secN+1]-r[secN]);
//        d22_SubInt1+=CurVal;
//        //
//        CurVal = ( (b_param_cur*b_param_cur*r[secN]) * (3.0/4.0-x0/b_param_cur) *dCy_dalfa_cur
//                   +
//                   (b_param_next*b_param_next*r[secN+1]) * (3.0/4.0-x0/b_param_next) *dCy_dalfa_next
//                 ) /2* (r[secN+1]-r[secN]) * sigma_f;
//        d22_SubInt2+=CurVal;
//        //
//        //
//        CurVal = (b_param_cur*r[secN]*r[secN]*r[secN] + b_param_next*r[secN+1]*r[secN+1]*r[secN+1]) /2* (r[secN+1]-r[secN]);
//        b12_SubInt+=CurVal;
//        //
//        //
//        CurVal = (b_param_cur*r[secN]*r[secN] + b_param_next*r[secN+1]*r[secN+1]) /2* (r[secN+1]-r[secN]) * sigma_f;
//        b22_SubInt+=CurVal;
//        //
//        //S'not dCy/dalfa uz gamma0 - tam no integral, tam s'not integr'l val
//        dCy_dalfa += (dCy_dalfa_cur+dCy_dalfa_next) /2* (r[secN+1]-r[secN]);
//        //
//    }//intrgral cycle
    //
    gamma0_param=dCy_dalfa*ro*b7*R*R*R*R/(2*I_gsh);
    //
    c21=-1/I_osh*c21_SubInt;
    c12=i0_param*c21;
    d11=dCy_dalfa/2*ro/I_gsh*d11_SubInt;
    d12=-dCy_dalfa/2*ro/I_gsh*d12_SubInt;
    d21=-dCy_dalfa/2*ro/I_gsh*d21_SubInt;
    d22=1/I_osh*(M_PI/16*ro*d22_SubInt1 + dCy_dalfa*ro/2*d22_SubInt2) + d_frict;
    b12=-dCy_dalfa/2*ro/I_gsh*b12_SubInt+i0_param*c21;
    b22=1+dCy_dalfa/2*ro/I_gsh*b22_SubInt;
    //}//fn Calc1
    //void Flutter_IsolatedBladeNoFriction_Data_v1::Calc2_char(){
    double eps=1E-7;
    //
    //A1=1/(1-i0_param*c21*c21)*(d11+d12-c12*d21-c21*d12);//pg363
    //B1=1/(1-i0_param*c21*c21)*(1+b22+d11*d22-b12*c21-d12*d21-c12*c21);
    //B2=1/(1-i0_param*c21*c21)*(1-chi_param*c12);
    //C1=1/(1-i0_param*c21*c21)*(d22+d11*b22-b12*d21-c21*d12);
    //C2=1/(1-i0_param*c21*c21)*(d11-chi_param*d12);
    //D1=1/(1-i0_param*c21*c21)*(b22-b12*c21);
    //D2=1/(1-i0_param*c21*c21)*(1-chi_param*b12);
    //
    double denom=1-this->i0_param*this->c21*this->c21;
    this->A1=1/denom*(this->d11+this->d22-this->c12*this->d21-this->c21*this->d12);
    this->B1=1/denom*(1+this->b22+this->d11*this->d22-this->b12*this->c21-this->d12*this->d21-this->c12*this->c21);
    this->B1=1/denom*(1-this->chi_param*this->c12);
    this->C1=1/denom*(this->d22+this->d11*this->b22-this->b12*this->d21-this->c21*this->d12);
    this->C2=1/denom*(this->d11-this->chi_param*this->d12);
    this->D1=1/denom*(this->b22-this->b12*this->c21);
    this->D2=1/denom*(1-this->chi_param*this->b12);
    //
    //Cp4=1;
    //Cp3=A1*w;
    //Cp2=B1*w*w+B2;
    //Cp1=(C1*w*w+C2)*w;
    //Cp0=D1*w*w*w*w+D2*w*w;
    //
    this->Cp4=1;
    this->Cp3=this->A1*this->w;
    this->Cp2=this->B1*this->w*this->w+this->B2;
    this->Cp1=(this->C1*this->w*this->w+this->C2)*this->w;
    this->Cp0=this->D1*this->w*this->w*this->w*this->w+this->D2*this->w*this->w;
    //
    //int EquationOf4thPower(double c4, double c3, double c2, double c1, double c0, std::vector<double>&ReX, std::vector<double>&ReY);
    EquationOf4thPower(Cp4, Cp3, Cp2, Cp1, Cp0, ReX, ImX);
    //
    //if(ImX[1-1]==0 && ImX[2-1]==0 && ImX[3-1]==0 && ImX[4-1]2==0){
    //
    //}else if(ImX[4-1]==0 && ImX[3-1]==0 && ImX[1-1]!=0 && ImX[2-1]!=0){
    //    if(fApprET(ImX[1-1], -ImX[2-1], eps) && fApprET(ReX[1-1], ReX[2-1], eps)){
    //
    //    }else{
    //        //Error!: ms'be complex-conjugated
    //    }
    //}else if(ImX[4-1]==0 && ImX[2-1]==0 && ImX[1-1]!=0 && ImX[3-1]!=0){
    //    if(fApprET(ImX[1-1], -ImX[3-1], eps) && fApprET(ReX[1-1], ReX[3-1], eps)){
    //
    //    }else{
    //        //Error!: ms'be complex-conjugated
    //    }
    //}else if(ImX[4-1]==0 && ImX[1-1]==0 && ImX[2-1]!=0 && ImX[3-1]!=0){
    //    if(fApprET(ImX[2-1], -ImX[3-1], eps) && fApprET(ReX[2-1], ReX[3-1], eps)){
    //
    //    }else{
    //        //Error!: ms'be complex-conjugated
    //    }
    //}else if(ImX[3-1]==0 && ImX[2-1]==0 && ImX[4-1]!=0 && ImX[1-1]!=0){
    //    if(fApprET(ImX[1-1], -ImX[4-1], eps) && fApprET(ReX[1-1], ReX[4-1], eps)){
    //
    //    }else{
    //        //Error!: ms'be complex-conjugated
    //    }
    //}else if(ImX[3-1]==0 && ImX[1-1]==0 && ImX[4-1]!=0 && ImX[2-1]!=0){
    //    if(fApprET(ImX[2-1], -ImX[4-1], eps) && fApprET(ReX[2-1], ReX[4-1], eps)){
    //
    //    }else{
    //        //Error!: ms'be complex-conjugated
    //    }
    //}else if(ImX[2-1]==0 && ImX[1-1]==0 && ImX[4-1]!=0 && ImX[3-1]!=0){
    //    if(fApprET(ImX[3-1], -ImX[4-1], eps) && fApprET(ReX[3-1], ReX[4-1], eps)){
    //
    //    }else{
    //        //Error!: ms'be complex-conjugated
    //    }
    //}else if(ImX[1-1]!=0 && ImX[2-1]!=0 && ImX[3-1]!=0 && ImX[4-1!=0]){
    //    if(fApprET(ImX[1-1], -ImX[2-1], eps) && fApprET(ImX[3-1], -ImX[4-1], eps) && fApprET(ReX[1-1], ReX[2-1], eps) && fApprET(ReX[3-1], ReX[4-1], eps)){
    //
    //    }else if(fApprET(ImX[1-1], -ImX[3-1], eps) && fApprET(ImX[2-1], -ImX[4-1], eps) && fApprET(ReX[1-1], ReX[3-1], eps) && fApprET(ReX[2-1], ReX[4-1], eps)){
    //
    //        }else if(fApprET(ImX[1-1], -ImX[4-1], eps) && fApprET(ImX[2-1], -ImX[3-1], eps) && fApprET(ReX[1-1], ReX[4-1], eps) && fApprET(ReX[2-1], ReX[3-1], eps)){
    //
    //        }else{
    //             //Error!: ms'be complex-conjugated
    //        }
    //    }
    //}//if Re, Im
    //
    //Let be so. Re(lambdaII) can be
    if(fApprET(ImX[1-1], 0, eps) && fApprET(ImX[2-1], 0, eps) && fApprET(ImX[3-1], 0, eps) && fApprET(ImX[4-1], 0, eps)){
        //so n'ms'b
         }else if(fApprET(ImX[4-1], 0, eps) &&  fApprET(ImX[3-1], 0, eps) && fApprNE(ImX[1-1], 0, eps) && fApprNE(ImX[2-1], 0, eps)){
        if(fApprET(ImX[1-1], -ImX[2-1], eps) && fApprET(ReX[1-1], ReX[2-1], eps)){
            lambdaI_Im[1-1]=0;
            lambdaI_Im[2-1]=0;
            lambdaI_Re[1-1]=0;
            lambdaI_Re[2-1]=0;
            //
            lambdaII_Im[1-1]=0;
            lambdaII_Im[2-1]=0;
            lambdaII_Re[1-1]=0;
            lambdaII_Re[2-1]=0;
        }else{
            //Error!: ms'be complex-conjugated
        }
    }else if(fApprET(ImX[4-1], 0, eps) && fApprET(ImX[2-1], 0, eps) && fApprNE(ImX[1-1], 0, eps) && fApprNE(ImX[3-1], 0, eps)){
        if(fApprET(ImX[1-1], -ImX[3-1], eps) && fApprET(ReX[1-1], ReX[3-1], eps)){

        }else{
            //Error!: ms'be complex-conjugated
        }
    }else if(fApprET(ImX[4-1], 0, eps) && fApprET(ImX[1-1], 0, eps) && fApprNE(ImX[2-1], 0, eps) && fApprNE(ImX[3-1], 0, eps)){
        if(fApprET(ImX[2-1], -ImX[3-1], eps) && fApprET(ReX[2-1], ReX[3-1], eps)){

        }else{
            //Error!: ms'be complex-conjugated
        }
    }else if(fApprET(ImX[3-1], 0, eps) && fApprET(ImX[2-1], 0, eps) && fApprNE(ImX[4-1], 0, eps) && fApprNE(ImX[1-1], 0, eps)){
        if(fApprET(ImX[1-1], -ImX[4-1], eps) && fApprET(ReX[1-1], ReX[4-1], eps)){

        }else{
            //Error!: ms'be complex-conjugated
        }
    }else if(fApprET(ImX[3-1], 0, eps) && fApprET(ImX[1-1], 0, eps) && fApprNE(ImX[4-1], 0, eps) && fApprNE(ImX[2-1], 0, eps)){
        if(fApprET(ImX[2-1], -ImX[4-1], eps) && fApprET(ReX[2-1], ReX[4-1], eps)){

        }else{
            //Error!: ms'be complex-conjugated
        }
    }else if(fApprET(ImX[2-1], 0, eps) && fApprET(ImX[1-1], 0, eps) && fApprNE(ImX[4-1], 0, eps) && fApprNE(ImX[3-1], 0, eps)){
        if(fApprET(ImX[3-1], -ImX[4-1], eps) && fApprET(ReX[3-1], ReX[4-1], eps)){

        }else{
            //Error!: ms'be complex-conjugated
        }
    }else if(fApprNE(ImX[1-1], 0, eps) && fApprNE(ImX[2-1], 0, eps) && fApprNE(ImX[3-1], 0, eps) && fApprNE(ImX[4-1], 0, eps)){
        if(fApprET(ImX[1-1], -ImX[2-1], eps) && fApprET(ImX[3-1], -ImX[4-1], eps) && fApprET(ReX[1-1], ReX[2-1], eps) && fApprET(ReX[3-1], ReX[4-1], eps)){
            lambdaI_Re[1-1]=ReX[1-1];
            lambdaI_Im[1-1]=ImX[1-1];
            lambdaI_Re[2-1]=ReX[2-1];
            lambdaI_Im[2-1]=ImX[2-1];
            //
            lambdaII_Re[1-1]=ReX[3-1];
            lambdaII_Im[1-1]=ImX[3-1];
            lambdaII_Re[2-1]=ReX[4-1];
            lambdaII_Im[2-1]=ImX[4-1];
            //ma mab lambda I et II ms'b exchanged
        }else if(fApprET(ImX[1-1], -ImX[3-1], eps) && fApprET(ImX[2-1], -ImX[4-1], eps) && fApprET(ReX[1-1], ReX[3-1], eps) && fApprET(ReX[2-1], ReX[4-1], eps)){
            lambdaI_Re[1-1]=ReX[1-1];
            lambdaI_Im[1-1]=ImX[1-1];
            lambdaI_Re[2-1]=ReX[3-1];
            lambdaI_Im[2-1]=ImX[3-1];
            //
            lambdaII_Re[1-1]=ReX[2-1];
            lambdaII_Im[1-1]=ImX[2-1];
            lambdaII_Re[2-1]=ReX[4-1];
            lambdaII_Im[2-1]=ImX[4-1];
            //ma mab lambda I et II ms'b exchanged
        }else if(fApprET(ImX[1-1], -ImX[4-1], eps) && fApprET(ImX[2-1], -ImX[3-1], eps) && fApprET(ReX[1-1], ReX[4-1], eps) && fApprET(ReX[2-1], ReX[3-1], eps)){
            lambdaI_Re[1-1]=ReX[1-1];
            lambdaI_Im[1-1]=ImX[1-1];
            lambdaI_Re[2-1]=ReX[4-1];
            lambdaI_Im[2-1]=ImX[4-1];
            //
            lambdaII_Re[1-1]=ReX[2-1];
            lambdaII_Im[1-1]=ImX[2-1];
            lambdaII_Re[2-1]=ReX[3-1];
            lambdaII_Im[2-1]=ImX[3-1];
            //ma mab lambda I et II ms'b exchanged
        }else{
             //Error!: ms'be complex-conjugated
        }
    }//if Re, Im
    //}
}
/*
class Flutter_IsolatedBladeNoFriction_Data_v1{
  public:
    //double dCydalfa_cur, dCydalfa_next;
    //
    std::vector<std::vector<double>> GravityCentersLine, RigityCentersLine;
*/
double Flutter_IsolatedBladeNoFriction_Data_v1::RigidityCenterOfSectionAt(double _r){//xRig=x0, sigma_f = x0-xRig
    double _x, _x1, _x2;
    int Q=this->RigidityCentersLine.size();
    std::vector<double>_R, _X;
    int N;
    //TPosInSucc PosInSucc1(double*X, int Q, double x, double eps=0);
    //TPosInSucc PosInSucc(std::vector<double>X, double x, double eps=0);
    TPosInSucc Pos;
    // I see hin 4 vrns:
    // 1) pairs of: _r, _x
    // 2) medium in bounds: _r_min, _r_max, _x_med
    // 3) bounds and hic vals: _r_min, _x_for_r_min, _r_max, _x_for_r_max
    // 4) hystogram of trapetiums: krum'g o'_x s'lin lam sect, odd et next even s'1 column o'1sect, D can ha idq _x, even et next odd can ha idq _r, ma atal _x

    switch(RigidityCentersLineTypeN){
        case 1:
            for(int i=1; i<=Q; i++){
                _R.push_back(this->RigidityCentersLine[i-1][1-1]);
                _X.push_back(RigidityCentersLine[i-1][2-1]);
            }
            _x=LinInterp(_R, _X, _r);
        break;
        case 2:
            for(int i=1; i<=Q; i++){
                _R.push_back(this->RigidityCentersLine[i-1][1-1]);
                _R.push_back(this->RigidityCentersLine[i-1][2-1]);
            }
            Pos=PosInSucc(_R, _r);
            if(Pos.isLess){
                _x=this->RigidityCentersLine[1-1][3-1];
            }else if(Pos.isGreater){
                _x=this->RigidityCentersLine[Q-1][3-1];
            }else if(Pos.EqualN>0){
                if(Pos.EqualN%2==0){
                    N=Pos.EqualN/2;
                }else{
                    N=(Pos.EqualN+1)/2;
                }
                _x=this->RigidityCentersLine[N-1][3-1];
            }else if(Pos.lessN>0){
                if(Pos.lessN%2!=0){//within section
                    N=(Pos.lessN+1)/2;
                    _x=this->RigidityCentersLine[N-1][3-1];
                }else{//between sections
                    N=(Pos.lessN+1)/2;
                    _x1=this->RigidityCentersLine[N-1][3-1];
                    _x2=this->RigidityCentersLine[N+1-1][3-1];
                    _x= _x1 <= _x2 ? _x1 : _x2;
                }
            }
        break;
        //case 3:
        //
        //break;
        //case 4:
        //
        //break;
    }
    return _x;
}

double Flutter_IsolatedBladeNoFriction_Data_v1::WeightCenterOfSectionAt(double _r){//xRig=x0, sigma_f = x0-xRig
    double _x, _x1, _x2;
    int Q=this->WeightCentersLine.size();
    std::vector<double>_R, _X;
    int N;
    //TPosInSucc PosInSucc1(double*X, int Q, double x, double eps=0);
    //TPosInSucc PosInSucc(std::vector<double>X, double x, double eps=0);
    TPosInSucc Pos;
    // I see hin 4 vrns:
    // 1) pairs of: _r, _x
    // 2) medium in bounds: _r_min, _r_max, _x_med
    // 3) bounds and hic vals: _r_min, _x_for_r_min, _r_max, _x_for_r_max
    // 4) hystogram of trapetiums: krum'g o'_x s'lin lam sect, odd et next even s'1 column o'1sect, D can ha idq _x, even et next odd can ha idq _r, ma atal _x

    switch(this->RigidityCentersLineTypeN){
        case 1:
            for(int i=1; i<=Q; i++){
                _R.push_back(this->WeightCentersLine[i-1][1-1]);
                _X.push_back(WeightCentersLine[i-1][2-1]);
            }
            _x=LinInterp(_R, _X, _r);
        break;
        case 2:
            for(int i=1; i<=Q; i++){
                _R.push_back(this->WeightCentersLine[i-1][1-1]);
                _R.push_back(this->WeightCentersLine[i-1][2-1]);
            }
            Pos=PosInSucc(_R, _r);
            if(Pos.isLess){
                _x=this->WeightCentersLine[1-1][3-1];
            }else if(Pos.isGreater){
                _x=this->WeightCentersLine[Q-1][3-1];
            }else if(Pos.EqualN>0){
                if(Pos.EqualN%2==0){
                    N=Pos.EqualN/2;
                }else{
                    N=(Pos.EqualN+1)/2;
                }
                _x=this->WeightCentersLine[N-1][3-1];
            }else if(Pos.lessN>0){
                if(Pos.lessN%2!=0){//within sexction
                    N=(Pos.lessN+1)/2;
                    _x=this->WeightCentersLine[N-1][3-1];
                }else{//between sections
                    N=(Pos.lessN+1)/2;
                    _x1=this->WeightCentersLine[N-1][3-1];
                    _x2=this->WeightCentersLine[N+1-1][3-1];
                    _x= _x1 <= _x2 ? _x1 : _x2;
                }
            }
        break;
        //case 3:
        //
        //break;
        //case 4:
        //
        //break;
    }
    return _x;
}

double Flutter_IsolatedBladeNoFriction_Data_v1::CalcFrictionCoefficient(double fiAfl, double pfl){
    double a_fr;
    a_fr= this->lagerKFr*this->lagerR*this->Sb0;
    return a_fr;
}

int Flutter_IsolatedBladeNoFriction_Data_v1::SetIniDataByTextFileReadingBySearch(QString infileName){
    //IncomingParamsFlutter dataIncomingFlutter;//tam no data, tic data go ab calc in main prg.
    BladeParamsSupplFlutter dataBladeSupplFlutter;
    HelicParamsSupplFlutter dataHelicSupplFlutter;
    FlutterModeParams dataFlutterMode;
    //char*fName=infileName.toStdString().c_str();//invalid conv from char* to char*
    std::vector<int>NsTmp;
    std::vector<float>RigiditySectsBounds, RigiditySectsSecondBounds, RigiditySectsLoc,// RigidityLineSect,
                      WeightSectsBounds,   WeightSectsSecondBounds,   WeightSectsLoc;//,   WeightLineSect;
    std::vector<double> RigidityLineSect,   WeightLineSect;
    int rigidityCentersLineLength, weightCentersLineLength, rL2, wL2;
    FILE*f=NULL;
    QTextStream *in;
    bool readerror = false;
    int ErrorPositionLast=0, countErrors=0;
    QFile inifile(infileName);
    float floatVal;
    this->RigidityCentersLineSetNull();
    this->WeightsCentersLineSetNull();
    dataBladeSupplFlutter.SetRigidityLineNull();
    dataBladeSupplFlutter.SetWeightsLineNull();
    //dataBladeSupplFlutter.SetNull();
    if(inifile.open( QIODevice::ReadOnly | QIODevice::Text ))
    {
        in = new QTextStream(&inifile);
        //
        if(f_find_int(in,"RigidityDataMode=",dataBladeSupplFlutter.RigidityCentersLineTypeN)) {
            readerror=true;
            //toMemo("start    not found");
            ErrorPositionLast=1;
            countErrors++;
        }
        if(f_find_vectorInt(in, "srN=", NsTmp)) {
            readerror=true;
            //toMemo("mr.prof not found in " + infileName); }
            ErrorPositionLast=2;
            countErrors++;
        }

        if(f_find_vectorFloat(in, "_r_sr1=", RigiditySectsBounds)) {
            readerror=true;
            //toMemo("mr.dfi  not found in " + infileName);
            ErrorPositionLast=3;
            countErrors++;
        }
        if(f_find_vectorFloat(in, "_b_sr=", RigiditySectsLoc)) {
            readerror=true;
            //toMemo("mr.dfi  not found in " + infileName);
            ErrorPositionLast=4;
            countErrors++;
        }
        rigidityCentersLineLength=RigiditySectsBounds.size();
        if(f_find_vectorFloat(in, "_r_sw1=", WeightSectsBounds)) {
            readerror=true;
            //toMemo("mr.dfi  not found in " + infileName);
            ErrorPositionLast=5;
            countErrors++;
        }
        if(f_find_vectorFloat(in, "_b_sw=", WeightSectsLoc)) {
            readerror=true;
            //toMemo("mr.dfi  not found in " + infileName);
            ErrorPositionLast=6;
            countErrors++;
        }
        weightCentersLineLength=WeightSectsBounds.size();
        if(dataBladeSupplFlutter.RigidityCentersLineTypeN==1){
            //NOp
        }else if(dataBladeSupplFlutter.RigidityCentersLineTypeN==2){
            if(f_find_vectorFloat(in, "_r_sr2=", RigiditySectsSecondBounds)) {
                readerror=true;
                ErrorPositionLast=7;
                countErrors++;
            }
            rL2=RigiditySectsSecondBounds.size();
            if(f_find_vectorFloat(in, "_r_sw2=", WeightSectsSecondBounds)) {
                readerror=true;
                ErrorPositionLast=8;
                countErrors++;
            }
            wL2=WeightSectsSecondBounds.size();
        }
        if(dataBladeSupplFlutter.RigidityCentersLineTypeN==1){
            for(int i=1; i<=rigidityCentersLineLength; i++){
                RigidityLineSect.clear();
                RigidityLineSect.push_back((double)RigiditySectsBounds[i-1]);
                //RigidityLineSect.push_back(RigiditySectsSecondBounds[i-1]);
                RigidityLineSect.push_back((double)RigiditySectsLoc[i-1]);
                //
                dataBladeSupplFlutter.RigidityCentersLine.push_back(RigidityLineSect);
            }
            for(int i=1; i<=weightCentersLineLength; i++){
                RigidityLineSect.clear();
                WeightLineSect.push_back(RigiditySectsBounds[i-1]);
                //RigidityLineSect.push_back(RigiditySectsSecondBounds[i-1]);
                WeightLineSect.push_back(RigiditySectsLoc[i-1]);
                //
                dataBladeSupplFlutter.WeightCentersLine.push_back(WeightLineSect);
            }
        }else if(dataBladeSupplFlutter.RigidityCentersLineTypeN==2){
            for(int i=1; i<=rigidityCentersLineLength; i++){
                RigidityLineSect.clear();
                RigidityLineSect.push_back((double)RigiditySectsBounds[i-1]);
                RigidityLineSect.push_back((double)RigiditySectsSecondBounds[i-1]);
                RigidityLineSect.push_back((double)RigiditySectsLoc[i-1]);
                //
                dataBladeSupplFlutter.RigidityCentersLine.push_back(RigidityLineSect);
            }
        }
        //
        if(f_find_float(in, "CtrlSysRotRigidity=", floatVal)) {
            //toMemo("x_f  not found");//I ha no tic method
            ErrorPositionLast=9;
            countErrors++;
        }else{
            dataHelicSupplFlutter.c_ctrl=floatVal;
        }
        if(f_find_float(in, "LagerR=", floatVal)) {
            //toMemo("x_f  not found");//I ha no tic method
            ErrorPositionLast=10;
            countErrors++;
        }else{
            dataHelicSupplFlutter.lagerR=floatVal;
        }
        if(f_find_float(in, "LagerKFrict=", floatVal)) {
            //toMemo("x_f  not found");//I ha no tic method
            ErrorPositionLast=11;
            countErrors++;
        }else{
            dataHelicSupplFlutter.lagerKfr=floatVal;
        }
        //
        if(f_find_float(in, "fiAfl=", floatVal)) {
            //toMemo("x_f  not found");//I ha no tic method
            ErrorPositionLast=10;
            countErrors++;
        }else{
            dataFlutterMode.fiAfl=floatVal;
        }
        if(f_find_float(in, "pFl=", floatVal)) {
            //toMemo("x_f  not found");//I ha no tic method
            ErrorPositionLast=11;
            countErrors++;
        }else{
            dataFlutterMode.pfl=floatVal;
        }
        //
        inifile.close();
        //
        this->SetBladeSupplData(dataBladeSupplFlutter);
        this->SetHelicSupplData(dataHelicSupplFlutter);
        this->SetFlutterModeParams(dataFlutterMode);
    }
    else
    {
        readerror=true;
        //toMemo("cannot open " + infileName);
        //toLogf("cannot open " + infileName);
    }
    return countErrors;//readerror;//countErrors;//ErrorPositionLast;
}

HelicParamsSupplFlutter Flutter_IsolatedBladeNoFriction_Data_v1::GetHelicParamsSupplFlutter(){
    HelicParamsSupplFlutter data;
    data.c_ctrl=this->c_ctrl;
    data.lagerR=this->lagerR;
    data.lagerKfr=this->lagerKFr;
    return data;
}

BladeParamsSupplFlutter Flutter_IsolatedBladeNoFriction_Data_v1::GetBladeParamsSupplFlutter(){
    BladeParamsSupplFlutter data;
    data.RigidityCentersLine=this->RigidityCentersLine;
    data.RigidityCentersLineTypeN=this->RigidityCentersLineTypeN;
    data.WeightCentersLine=this->WeightCentersLine;
    data.WeightCentersLineTypeN=this->WeightCentersLineTypeN;
    return data;
}

FlutterModeParams Flutter_IsolatedBladeNoFriction_Data_v1::GetFlutterModeParams(){
    FlutterModeParams data;
    data.fiAfl=this->fiAfl;
    data.pfl=this->pfl;
    return data;
}

IncomingParamsFlutter Flutter_IsolatedBladeNoFriction_Data_v1::GetIncomingParams(){
    IncomingParamsFlutter data;
    data.b7=this->b7;
    data.chi_param=this->chi_param;
    data.I_gsh=this->I_gsh;
    data.I_osh=this->I_osh;
    data.mlp=this->mlp;
    data.R=this->R;
    data.ro=this->ro;
    data.Sb0=this->Sb0;
    data.sigma=this->sigma;
    data.w=this->w;
    return data;
}

void Flutter_IsolatedBladeNoFriction_Data_v1::RigidityCentersLineSetNull(){
    this->RigidityCentersLine.clear();
}

void Flutter_IsolatedBladeNoFriction_Data_v1::WeightsCentersLineSetNull(){
    this->WeightCentersLine.clear();
}



//};

//void Flutter_IsolatedBladeNoFriction_Data_v1::CalcSingleIntegrationStepBySections(double rCur, double rNext, int Q, double*Cys_cur, double*alfas_cur, double*Cys_next,double* alfas_next, double t){

//}

//void SumUpIntegrationBySections();
