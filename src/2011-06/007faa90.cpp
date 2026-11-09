// from server: 60% by atomic.potato
extern "C" int __stdcall sub_91D1E0(int, int, int, int);

struct S
{
    int __cdecl f(int *p);
};

int S::f(int *p)
{
    int a = 0;
    int b = 0;
    int c = 0;
    sub_91D1E0(0x100, 0, (int)&a, (int)&b);
    *p = b;
    return 0;
}
