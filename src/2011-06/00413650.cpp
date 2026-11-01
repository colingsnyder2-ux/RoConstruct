// from server: 45% by atomic.potato
struct CComObjectNoLock {
    void Method(int, int, int, int, int, int, int, int, int);
};

extern "C" void __stdcall sub_407740(int);

extern int g_00c0a3a4;
extern int g_00c0a3ac;
extern char g_00c0a398;

void __stdcall sub_00413650(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
    int ecx = g_00c0a3a4;
    int eax = 0;
    if (ecx == 0 || g_00c0a3ac == eax)
    {
        sub_407740(a9);
        ecx = g_00c0a3a4;
    }
    if (ecx != 0)
    {
        int edx = *(int*)ecx;
        int (*fn)(int, int, int, int, int, int, int, int, int) = *(int (**)(int, int, int, int, int, int, int, int, int))(edx + 0x2c);
        fn(ecx, a1, a2, a3, a4, a5, a6, a7, a8);
    }
}
