// from server: 59% by atomic.potato
extern "C" int __cdecl sub_4480f0(int, int*);

struct S
{
    int pad[7];
    void* descriptor;
    int f(int, int);
};

int S::f(int a, int b)
{
    void* p = descriptor;
    int value = sub_4480f0(b, &b);
    typedef int (__thiscall *Fn)(void*, int, int);
    Fn fn = *(Fn*)((char*)*(void**)p + 16);
    fn(p, a, value);
    return value;
}
