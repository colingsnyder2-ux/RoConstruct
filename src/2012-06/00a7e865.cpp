// from server: 10% by 41k
struct S {
    double f(double, double);
};

extern "C" double __stdcall helper(double);
extern "C" double __declspec(dllimport) tail(double);

double S::f(double x, double y) {
    helper(1.0);
    return tail(x);
}
