// from server: 41% by atomic.potato
extern "C" void __cdecl func_008af41a(int);

extern "C" int __stdcall imported_func(
    int, int, int, int, int, float);

struct S {
    int f(int, int, int, int, int, float);
};

int S::f(int a, int b, int c, int d, int e, float g)
{
    func_008af41a(1);
    return imported_func(a, b, c, d, e, g);
}
