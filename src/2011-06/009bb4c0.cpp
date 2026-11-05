// from server: 45% by atomic.potato
extern "C" void __cdecl sub_009ba410(short, short, short, int);

struct seg_009b0000
{
    void f(short, short, short, int);
};

void seg_009b0000::f(short a, short b, short c, int d)
{
    sub_009ba410(a, b, c, d);
}
