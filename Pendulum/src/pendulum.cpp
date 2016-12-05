#include <iostream>
#include <math.h>

using namespace std;

float g1(float,float,float);
float g2(float,float,float);
static float q, b, w0;

int main(){

    //cout << " Podaj nazwe pliku wejsciowego: ";
    //cin.getline(name_r,20);
    //cout << " Podaj nazwe pliku wyjsciowego: ";
    //cin.getline(name_w,20);

    double y1,y2,y1_old,y2_old;
    double h, q, b, w0;
    int n=1000;

    // q -> sila tarcia,  b -> sila wymuszajaca, w0 -> czestosc sily wymuszajacej

    cin >> h >>q >> b >> w0 >> y1_old >> y2_old;

    double t, k11, k12, k21, k22, k31, k32, k41, k42, kat;
    for(int i=0; i*h<50; i++){
        t=h*i;
        y1 = y1_old;
        y2 = y2_old;

        k11 = h*g1(y1,y2,t);
        k12 = h*g2(y1,y2,t);

        k21 = h*g1(y1+k11/2,y2+k12/2,t+h/2);
        k22 = h*g2(y1+k11/2,y2+k12/2,t+h/2);

        k31 = h*g1(y1+k21/2,y2+k22/2,t+h/2);
        k32 = h*g2(y1+k21/2,y2+k22/2,t+h/2);

        k41 = h*g1(y1+k31,y2+k32,t+h);
        k42 = h*g2(y1+k31,y2+k32,t+h);

        y1_old = y1+(1.0/6.0)*(k11+2*k21+2*k31+k41);
        y2_old = y2+(1.0/6.0)*(k12+2*k22+2*k32+k42);
        kat = sin(y1_old);
        y1_old = asin(kat);
        cout << t << "   "<< y1_old << "       " << y2_old << endl;
    }
    return 0;
}

float g1(float y1,float y2, float t){
    return y2;
}

float g2(float y1,float y2, float t){
    return b*cos(w0*t)-(q*y2)-sin(y1);
}
