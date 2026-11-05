// from server: 75% by atomic.potato
extern "C" void __cdecl sub_781b60(void *);

struct S
{
    int f();
};

int S::f()
{
    char *p = (char *)this;
    sub_781b60(*(void **)(p - 0x24));
    void **v = *(void ***)(p - 0x44);
    ((void (__thiscall *)(void *))v[14])(p - 0x44);
    return 0;
}
