#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>
#include<conio.h>
#include <math.h>


float g1(float,float,float);
float g2(float,float,float,float,float,float);

int main()
{
char name_w[20]={"output-wahadlo.txt"},name_r[20]={"Kutta.txt"};
cout << "*** Wahadlo - metoda Rungego-Kutty ***\n";
cout <<"----------------------------------------------------\n";
//cout << " Podaj nazwe pliku wejsciowego: ";
//cin.getline(name_r,20);
//cout << " Podaj nazwe pliku wyjsciowego: ";
//cin.getline(name_w,20);

float y1,y2,y1_old=0.0,y2_old=3.0;
float h=0.05, q=0.0, b=0.0, w0=0.0;
int n=1000;

// q -> sila tarcia,  b -> sila wymuszajaca, w0 -> czestosc sily wymuszajacej

ifstream read(name_r,ios::in);
read >> q >> b >> w0 >> y1_old >> y2_old;
read.close();

ofstream write(name_w,ios::out);

for(int i=0; i<n; i++) 
        {
        float t=h*i;
        y1=y1_old;
        y2=y2_old;
        float k11=h*g1(y1,y2,t);
        float k12=h*g2(y1,y2,t,q,b,w0);
        float k21=h*g1(y1+k11/2,y2+k12/2,t+h/2); 
        float k22=h*g2(y1+k11/2,y2+k12/2,t+h/2,q,b,w0); 
        float k31=h*g1(y1+k21/2,y2+k22/2,t+h/2); 
        float k32=h*g2(y1+k21/2,y2+k22/2,t+h/2,q,b,w0); 
        float k41=h*g1(y1+k31,y2+k32,t+h); 
        float k42=h*g2(y1+k31,y2+k32,t+h,q,b,w0);
        y1_old=y1+(1.0/6.0)*(k11+2*k21+2*k31+k41);
        y2_old=y2+(1.0/6.0)*(k12+2*k22+2*k32+k42);
        float kat=sin(y1_old);
        y1_old=asin(kat); 
        write << t << "   "<< y1_old << "       " << y2_old <<"  \n   ";   
        }
write.close();
cout << "END";
getch(); 
return 0;
}

float g1(float y1,float y2, float t)
{
return y2;     
}

float g2(float y1,float y2, float t, float q, float b, float w0)
{
float g=b*cos(w0*t)-(q*y2)-sin(y1);  
return g;    
}

