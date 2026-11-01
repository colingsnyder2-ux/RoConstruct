// from server: 100% by atomic.potato
typedef int BOOL;

extern "C" BOOL __stdcall sub_4057F0(int, int, int, int);

extern int g_0096C268;

struct S
{
    BOOL f(int);
};

BOOL S::f(int value)
{
    return sub_4057F0(g_0096C268, 0x77, value, 0);
}
