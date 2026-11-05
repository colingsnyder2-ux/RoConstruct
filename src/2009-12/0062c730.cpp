// from server: 100% by atomic.potato
struct S
{
    char padding[0x78];
    double value;
    double f();
};

extern "C" S *__cdecl sub_007e7820();

double S::f()
{
    return sub_007e7820()->value;
}
