// from server: 27% by atomic.potato
extern "C" void __cdecl sub_a814d5(int);

extern "C" void __stdcall sub_e08694(
    float, float, int, float, float, int);

struct S
{
    void f(float, float, int, float, float, int);
};

void S::f(float a, float b, int c, float d, float e, int f)
{
    sub_a814d5(1);
    sub_e08694(a, b, c, d, e, f);
}
