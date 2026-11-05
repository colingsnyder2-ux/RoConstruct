// from server: 23% by atomic.potato
extern "C" void __cdecl sub_008af41a(int);

extern "C" int __stdcall imported_call(
    int, float, int, float, int);

struct S
{
    int f(int, float, int, float, int);
};

int S::f(int a, float b, int c, float d, int e)
{
    sub_008af41a(1);
    return imported_call(a, b, c, d, e);
}
