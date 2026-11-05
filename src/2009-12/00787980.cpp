// from server: 85% by atomic.potato
struct S
{
    int a;
    int b;
    S(int);
};

extern "C" void __stdcall f1(S *);
extern "C" void __stdcall f2(S *);

S::S(int x)
{
    a = 0x9e9b3c;
    b = 0x9e9b24;
    f1(this);
    if (x & 1)
        f2(this);
}
