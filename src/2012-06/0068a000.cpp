// from server: 46% by atomic.potato
extern "C" int __cdecl sub_00689b40(void *, void *);

struct S
{
    int f(void *, void *);
};

int S::f(void *a, void *b)
{
    unsigned char buffer[24];
    void *p = *(void **)((char *)this + 0x28);
    int *vtable = *(int **)p;
    sub_00689b40(buffer, b);
    return ((int (__thiscall *)(void *, void *, void *))vtable[3])(p, a, buffer);
}
