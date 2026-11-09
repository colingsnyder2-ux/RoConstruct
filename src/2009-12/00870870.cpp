// from server: 90% by atomic.potato
struct S
{
    int value;
    int a;
    int b;
    int c;
    int d;
    int f();
};

extern "C" void __stdcall sub_870670(S*, int);

int S::f()
{
    value = 0x00A00DB0;
    sub_870670((S*)((char*)this + 0x14), 10);
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    return (int)this;
}
