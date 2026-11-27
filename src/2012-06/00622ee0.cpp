// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
extern "C" __declspec(dllimport) double __cdecl modf(double, double*);
double f(float x, float* ip) { double i; double fr = modf(x, &i); *ip = (float)i; return fr; }
