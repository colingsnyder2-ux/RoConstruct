// from server: 63% by atomic.potato
extern "C" void __cdecl sub_4e1300(void *, void *);
extern "C" void __cdecl sub_4ea1c0(void *);

struct S {
    void __cdecl value(void *);
};

void __cdecl S::value(void *p)
{
    char buffer[8];
    sub_4e1300(p, buffer);
    if (*((int *)((char *)p + 4)) != 0)
        sub_4ea1c0(buffer);
}
