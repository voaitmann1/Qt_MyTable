
#ifndef FLUTTERMODELS_H
#define FLUTTERMODELS_H

#include"mymathlib.h"
//#include<iostream>
//#include<functional>


//class FlutterModels
//{
//public:
//    FlutterModels();
//};

class ThrownCorper{
    double g;
public:
    ThrownCorper();
    //ThrownCorp(){//so also works well
    //    g=9.81;
    //}
    double Eq1RPVy(int n, double t, const double*y);
    double Eq2RPVx(int n, double t, const double*y);
    double Eq3RPY(int n, double t, const double*y);
    double Eq4RPX(int n, double t, const double*y);

    std::vector<double>Calc_ByAngle(double t, double V0, double AngleDeg, double y0, double x0=0, double t0=0, double dt=1E-6, TValsShowHide*vsh=NULL);
    std::vector<double>Calc_As1stOrderSys(double*q0, double t, double t0=0, double dt=1E-6, TValsShowHide*vsh=NULL);
    //
    void Calc_ByAngle(double*q, const TItersPrecision&ItersPrecision, double t, double V0, double AngleDeg, double y0, double x0=0, double t0=0, TValsShowHide*vsh=NULL);
    void Calc_As1stOrderSys(const TItersPrecision&ItersPrecision, double*q0, double t, double t0=0, TValsShowHide*vsh=NULL);

};


/*class Flutter_IsolatedBladeNoFriction_Data{
    public:
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
    double gamma0_param,
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
           d11, d12, d21, d22, b11, b12, b22;
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
    fsib_C_S1E1beta2,//=1,
    fsib_C_S1E1beta1,//=d11*w,//iqv if w
    fsib_C_S1E1beta0,//=w*w,//iqv if w
    fsib_C_S1E1fi2,//=c12,
    fsib_C_S1E1fi1,//=d12*w,//iqv if w
    fsib_C_S1E1fi0,//=b12*w*w,//iqv if w
    //Equation 2 with beta"==0, fi"!=0
    fsib_C_S1E2beta2=c21,
    fsib_C_S1E2beta1=d21*w_,
    fsib_C_S1E2beta0,//=(chi_param*p_kr*p_kr+c21*w*w),//iqv qre chi_param et p_kr
    fsib_C_S1E2fi2,//=1,
    fsib_C_S1E2fi1,//=d22*w*w,
    fsib_C_S1E2fi0,//=(p_kr*p_kr+b22*w*w),
    //system 2, solv'd r'2nd derivs
    //equation beta
    fsib_C_S2Ebeta_beta2,
    fsib_C_S2Ebeta_beta1,
    fsib_C_S2Ebeta_beta0,
    fsib_C_S2Ebeta_fi2,
    fsib_C_S2Ebeta_fi1,
    fsib_C_S2Ebeta_fi0,
    //equation fi
    fsib_C_S2Efi_beta2,
    fsib_C_S2Efi_beta1,
    fsib_C_S2Efi_beta0,
    fsib_C_S2Efi_fi2,
    fsib_C_S2Efi_fi1,
    fsib_C_S2Efi_fi0;
    //
    double
            fsib_S1LinReDerivs2E1_C_beta2, fsib_S1LinReDerivs2E1_C_fi2, fsib_S1LinReDerivs2E1_RP_beta,

            fsib_S1LinReDerivs2E2_C_beta2, fsib_S1LinReDerivs2E2_C_fi2, fsib_S1LinReDerivs2E2_RP_fi,

            S1LinReDerivs2_det_sys,

            S1LinReDerivs2_det_beta, S1LinReDerivs2_det_fi,
            S2Ebeta_RP, S2Efi_RP;
           //S1LinReDerivs2E1_RP_beta2
    //
    Flutter_IsolatedBladeNoFriction_Data();
    Flutter_IsolatedBladeNoFriction_Data(bool check);
    ~Flutter_IsolatedBladeNoFriction_Data(){}
    //
    double f_fsib_S1LinReDerivs2E1_RP(double beta_1, double fi_1, double beta, double fi);
    double f_fsib_S1LinReDerivs2E2_RP(double beta_1, double fi_1, double beta, double fi);
    //
    double f_fsib_S1LinReDerivs2_det_beta2(double beta_1, double fi_1, double beta, double fi);
    double f_fsib_S1LinReDerivs2_det_fi2(double beta_1, double fi_1, double beta, double fi);
    //
    double f_fsib_S2LinReDerivs2E1_RP_beta(double beta_1, double fi_1, double beta, double fi);
    double f_fsib_S2LinReDerivs2E2_RP_fi(double beta_1, double fi_1, double beta, double fi);
    //
    double f_fsib_S3E1_RP_dbeta(double*X);
    double f_fsib_S3E2_RP_dfi(double*X);
    double f_fsib_S3E3_RP_beta(double*X);
    double f_fsib_S3E4_RP_fi(double*X);
};

double FlutIsolBldNoFr_ES2ord2Vars_d2Beta(double Beta, double WBeta, double Fi, double WFi, const Flutter_IsolatedBladeNoFriction_Data&data);
double FlutIsolBldNoFr_ESS2ord2Vars_d2Fi(double Beta, double WBeta, double Fi, double WFi, const Flutter_IsolatedBladeNoFriction_Data&data);
double FlutIsolBldNoFr_ES1ord4Vars_dWBeta();
double FlutIsolBldNoFr_ES1ord4Vars_dWFi();
double FlutIsolBldNoFr_ES1ord4Vars_dBeta();
double FlutIsolBldNoFr_ES1ord4Vars_dFi();
*/

class Flutter_IsolatedBladeNoFriction_Data_v1_IncomingHelicParams{
public:
    double I_osh, I_gsh, mlp, sigma,  ro, R, b7, chi_param, w ;
    //double c_ctrl, d_fric, x0, sigma_f;
    Flutter_IsolatedBladeNoFriction_Data_v1_IncomingHelicParams();

};

class Flutter_IsolatedBladeNoFriction_Data_v1_IniExt{
public:
    //double I_osh, I_gsh, mlp, sigma, ro, R, b7, chi_param, w ;
    double c_ctrl, d_frict, x0, sigma_f;
    Flutter_IsolatedBladeNoFriction_Data_v1_IniExt();

};

class Flutter_IsolatedBladeNoFriction_Data_v1_ParamsIniForCalcEquations{
public:
    double d11, w, c12, d12, b12, d22, p_cr, b22, c21, d21, chi_param ;
    Flutter_IsolatedBladeNoFriction_Data_v1_ParamsIniForCalcEquations();
    void SetTestValues();
};

class Flutter_IsolatedBladeNoFriction_Data_v1_Results{
public:
    double p_cr, p_fl, w__fl, p__fl, w__div;
    double lambda1_Re, lambda1_Im, lambda2_Re, lambda2_Im;
    Flutter_IsolatedBladeNoFriction_Data_v1_Results();
};

class Flutter_IsolatedBladeNoFriction_Data_v1{
  public:
    //double dCydalfa_cur, dCydalfa_next;
    //
    //vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
    //double M_cur, M_next;//params
    //double*bh;
    //int nSec;//params;
    double I_osh, I_gsh, mlp, sigma, x0, sigma_f, ro, R, b7, chi_param, w ;
    double c_ctrl, d_frict;
    //
    double dCy_dalfa, i0_param, gamma0_param;
    double p_cr;
    double b_param_cur, b_param_next;
    double c21_SubInt, d11_SubInt, d12_SubInt, d21_SubInt, d22_SubInt1, d22_SubInt2, b12_SubInt, b22_SubInt;//, dCy_dalfa_SubInt;
    std::vector<double> Ms_cur, Ms_next, alfas_cur, alfas_next, CysForMCur, CysForMNext, M_toInterp, Cy_toInterp;
    std::vector<double>ReX, ImX;
    double Cp4, Cp3, Cp2, Cp1, Cp0;
    double
    c12, c21, d11, d12, d21, d22, b12, b22,
    A1, B1, B2, C1, C2, D1, D2;
    double lambdaI_Re[2], lambdaI_Im[2], lambdaII_Re[2], lambdaII_Im[2];
    double L, M;
    double _p_fl, _w_fl, _w_div;
    //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    double C_S1E1_beta2, C_S1E1_fi2, C_S1E1_beta1, C_S1E1_fi1, C_S1E1_beta0, C_S1E1_fi0,
           C_S1E2_beta2, C_S1E2_fi2, C_S1E2_beta1, C_S1E2_fi1, C_S1E2_beta0, C_S1E2_fi0;
    double                           C_S2EBeta_beta1, C_S2EBeta_fi1, C_S2EBeta_beta0, C_S2EBeta_fi0,
                                     C_S2EFi_beta1,   C_S2EFi_fi1,   C_S2EFi_beta0,   C_S2EFi_fi0;
    //*************************************************************************************************************
    //public:
    Flutter_IsolatedBladeNoFriction_Data_v1();
    //
    void SetIniHelicData(const Flutter_IsolatedBladeNoFriction_Data_v1_IncomingHelicParams&data);
    void SetIniExtData(const Flutter_IsolatedBladeNoFriction_Data_v1_IniExt&data);
    void Calc1_IntegrateBySects(double M_cur, double M_next, int QM, const double***MACHs, int QAlfas, const double***ALPHAs, const double***_Cy,int QSects, const int*ProfN, const double*bh, const double*r);
    void Calc2_char();
    void Calc3_critParams();
    void Calc4_UDECoefs_IniSys1(const Flutter_IsolatedBladeNoFriction_Data_v1_ParamsIniForCalcEquations&data);
    void Calc5_UDECoefs_EqvSys2();
    void TestUDECoefs_EqvSys2();
    //
    Flutter_IsolatedBladeNoFriction_Data_v1_ParamsIniForCalcEquations GetParamsForEquations();
    //
    double f_S1E1_RP(double wBeta, double wFi,double Beta, double Fi);
    double f_S1E2_RP(double wBeta, double wFi,double Beta, double Fi);
    //
    double f_S2EBeta_RP(double wBeta, double wFi,double Beta, double Fi);
    double f_S2EFi_RP(double wBeta, double wFi,double Beta, double Fi);
    //
    double f_Eq1_RP_wBeta(int n, double t, const double*y);
    double f_Eq2_RP_wFi(int n, double t, const double*y);
    double f_Eq3_RP_Beta(int n, double t, const double*y);
    double f_Eq4_RP_Fi(int n, double t, const double*y);
    //
    std::vector<double>GetDeviations(std::vector<double>q0, double t, double t0, const TItersPrecision&ItersPerecision);
    void CalcDeviations(double fi0, double beta0, double w_fi0, double w_beta0, double t, double fi, double beta, double w_fi, double w_beta, double t0, const TItersPrecision&ItersPerecision);
};

#endif // FLUTTERMODELS_H
