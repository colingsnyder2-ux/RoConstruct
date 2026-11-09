// from server: 45% by atomic.potato
extern "C" void __cdecl sub_0092f470(short, short, short, int);

struct seg_00930000
{
    void __thiscall f(short, short, short, int);
};

void __thiscall seg_00930000::f(short a, short b, short c, int d)
{
    sub_0092f470(a, b, c, d);
}
