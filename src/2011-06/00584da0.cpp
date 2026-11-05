// from server: 42% by atomic.potato
extern "C" int* __cdecl sub_584d80(int);

struct S
{
    void __cdecl f(int, int);
};

void __cdecl S::f(int a, int b)
{
    int* p = sub_584d80(a);
    if (p)
        *p = b;
}
