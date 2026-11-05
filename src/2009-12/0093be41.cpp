// from server: 46% by atomic.potato
typedef unsigned long DWORD;

extern "C" void __cdecl f007f49a4(void *, unsigned int, unsigned int, DWORD);

struct S
{
    void f();
};

DWORD g0098b6e4;

void S::f()
{
    char local[720];
    f007f49a4(local, 0x1c, 6, g0098b6e4);
}
