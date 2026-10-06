#include "mymathlib.h"

//MyMathLib::MyMathLib()
//{

//}

double IntPower(double x, int pow){
    double y=1;
    if(pow==0) y=1;
    else if(pow==1) y=x;
    else if(pow>0){
        for(int i=1; i<=pow; i++) y*=x;
    }else{//pow<0
        for(int i=1; i<=pow; i++) y/=x;
    }
    return y;
}
//float IntPower(float x, int pow){
//    float y=1;
//    if(pow==0) y=1;
//    else if(pow==1) y=x;
//    else if(pow>0){
//        for(int i=1; i<=pow; i++) y*=x;
//    }else{//pow<0
//        for(int i=1; i<=-pow; i++) y/=x;
//    }
//    return y;
//}
//int IntPower(int x, int pow){
//    int y=1;
//    if(pow==0) y=1;
//    else if(pow==1) y=x;
//    else if(pow>0){
//        for(int i=1; i<=pow; i++) y*=x;
//    }else{//pow<0
//        for(int i=1; i<=-pow; i++) y*=x;
//    }
//    return y;
//}
