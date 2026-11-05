// from server: 42% by atomic.potato
extern "C" void __cdecl sub_a814d5(int);

extern "C" void __stdcall imported_QQVW(float, float, float);

struct S
{
    void f(float, float, float);
};

void S::f(float a, float b, float c)
{
    sub_a814d5(1);
    imported_QQVW(a, b, c);
}
