// from server: 50% by atomic.potato
extern "C" int __cdecl fn_6272d0(int);
extern "C" int __cdecl fn_627310(int);

struct AdornRbxGfx
{
    void f(int, int);
    void fn_4c35d0(int, int);
};

struct AdornRbxGfx *g_adorn;

void AdornRbxGfx::fn_4c35d0(int, int)
{
}

void AdornRbxGfx::f(int a, int b)
{
    int x = fn_6272d0(a);
    int y = fn_627310(x);
    fn_4c35d0(y, b);
}
