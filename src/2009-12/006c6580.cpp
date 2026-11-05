// from server: 100% by atomic.potato
extern "C" void __cdecl continuation();

struct S
{
    int a;
    int b;
    int pad0[4];
    int c;
    int d;

    void f();
};

int g;

void S::f()
{
    g = 0;
    a = 0x9d7294;
    b = 0x9d7288;
    c = 0x9d727c;
    d = 0x9d7274;
    continuation();
}
