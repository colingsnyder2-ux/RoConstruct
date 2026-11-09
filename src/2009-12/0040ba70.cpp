// from server: 50% by atomic.potato
typedef unsigned char BYTE;

struct S
{
    int f(int);
    void *vptr;
    void *pad[6];
    void *callback;
};

extern "C" unsigned char __cdecl sub_40a5d0(int);

int S::f(int a)
{
    unsigned char b = sub_40a5d0(a);
    void **p = (void **)callback;
    return ((int (__thiscall *)(void *, unsigned char, int))p[4])(callback, b, a);
}
