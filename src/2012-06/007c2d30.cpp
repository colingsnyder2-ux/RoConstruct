// from server: 88% by atomic.potato
struct S;

extern "C" void __cdecl sub_758440(S *, float);

struct S
{
    void f(float);
};

unsigned char g_00e31abe;

void S::f(float value)
{
    if (g_00e31abe)
        return;

    void *p = *(void **)((char *)this + 0x84);
    void *q = *(void **)p;
    sub_758440((S *)((char *)this + 0x84 + (unsigned long)q), value);
}
