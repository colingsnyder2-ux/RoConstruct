// from server: 39% by atomic.potato
extern "C" int __stdcall helper(int);

extern "C" {
    typedef int (__cdecl *fnptr)(int, int, float, int, int, float, int, int);
    extern fnptr g_fn;
}

int __stdcall func_008ac338(int a, int b, float c, int d, int e, float f, int g, int h)
{
    helper(1);
    return g_fn(a, b, c, d, e, f, g, h);
}
