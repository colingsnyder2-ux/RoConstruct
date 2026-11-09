// from server: 100% by atomic.potato
typedef unsigned long DWORD;

extern "C" void __cdecl continuation();

struct S
{
    int a;
    int b;
    int pad[4];
    int c;
    int d;

    void f();
};

void S::f()
{
    *(DWORD*)0x00b7b620 = 0;
    a = 0x009d6f4c;
    b = 0x009d6f40;
    c = 0x009d6f34;
    d = 0x009d6f2c;
    continuation();
}
