//SKWork.dll源代码
extern "C" _declspec(dllexport) double kaoqin(double a,double b,double c);
extern "C" _declspec(dllexport) double nandu(double a,double b,double c,double d,double e,double f);
extern "C" _declspec(dllexport) double timu(double a,double b,double c);
#include<math.h>
#include<iostream>
using namespace std;
double kaoqin(double a,double b,double c)
{
	return abs(8*sin(a/5)+8+b-c/10);
}
double nandu(double a,double b,double c,double d,double e,double f)
{
	return 100*exp(d*(1+((double)a-(e/(double)f))/(e/(double)f)))*(0.6*(double)b+1)/((0.5*(double)c+1)*(sin((double)c/5)+1));
}
double timu(double a,double b,double c)
{
	return (-1)*(double)a+fabs(1/(1*(double)b+2*a+0.5-3*c));
}
