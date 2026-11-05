// from server: 100% by king_originala
extern "C" __int64 __stdcall divide64(unsigned long, unsigned long, unsigned long, unsigned long);
extern const double scale;

struct S {
    char padding[0x268];
    volatile unsigned long low;
    volatile unsigned long high;
    double f();
};

double S::f() {
    unsigned long lo = low;
    unsigned long hi = high;
    return static_cast<double>(divide64(lo, hi, 1000, 0)) * scale;
}
