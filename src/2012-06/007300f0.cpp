// from server: 93% by atomic.potato
struct S
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    void set();
};

extern "C" void __cdecl f();

void S::set()
{
    a = 0xba7154;
    b = 0xba714c;
    e = 0xba7140;
    f = 0xba7134;
    ::f();
}
