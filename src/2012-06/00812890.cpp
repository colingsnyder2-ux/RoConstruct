// from server: 79% by atomic.potato
struct S
{
    void f();
    int a;
    int b;
    int c;
    int d;
    int e;
};

extern "C" void __cdecl continuation();

void S::f()
{
    a = 0xbc6524;
    b = 0xbc6518;
    c = 0xbc650c;
    d = 0xbc6500;
    e = 0xbc64d4;
    continuation();
}
