// from server: 54% by atomic.potato
typedef int (__thiscall *Getter)(void *, void *);

extern "C" int __cdecl sub_006a39c0(void *, int);

struct S_func_006cd760
{
    int f(int a1);
};

int S_func_006cd760::f(int a1)
{
    void *p = *(void **)((char *)this + 0x1c);
    Getter getter = *(Getter *)((char *)p + 0);
    int value = getter(p, &a1);
    return sub_006a39c0(this, value);
}
