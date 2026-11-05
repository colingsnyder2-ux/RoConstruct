// from server: 50% by atomic.potato
typedef unsigned short wchar16;

extern "C" wchar16 __stdcall do_global_lower(wchar16);

struct S
{
    int f(int);
};

int S::f(int a)
{
    wchar16 x = do_global_lower((wchar16)*(int *)((char *)a + 0x10));
    wchar16 y = do_global_lower((wchar16)*(int *)((char *)a + 0x14));
    return x == y ? (int)y : (int)x;
}
