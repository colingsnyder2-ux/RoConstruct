// from server: 68% by atomic.potato
struct S
{
    void __cdecl f(int a, int b);
};

extern "C" void __cdecl sub_532f10(int*, int);
extern "C" void __cdecl sub_53a180(int*);

void __cdecl S::f(int a, int b)
{
    int x;
    sub_532f10(&x, a);
    if (*((int*)((char*)this + 4)) != 0)
        sub_53a180(&x);
}
