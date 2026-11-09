// from server: 34% by atomic.potato
struct S {
    int f(int);
    void *field;
};

typedef int (__thiscall *Fn)(void *, int);
extern "C" void __cdecl sub_409c20(void *, unsigned char);

int S::f(int value)
{
    void *p = *(void **)((char *)this + 0x1c);
    unsigned char result = ((Fn)(*(unsigned long *)p + 0x0c))(p, value);
    sub_409c20((char *)this + 4, result);
    return 0;
}
