// from server: 52% by atomic.potato
extern "C" void *__cdecl sub_0098211a(unsigned int);
extern "C" void __cdecl sub_006cb830(void *, void *);
extern "C" void __cdecl sub_00746ce0(void *, int, void *);

struct S
{
    void f();
};

void S::f()
{
    char *p = (char *)this;
    sub_006cb830(p, (void *)0xdb4af8);
    *(void **)p = (void *)0xbaaae8;

    char *q = p + 0x34;
    void *n = sub_0098211a(0x18);
    *(void **)(q + 4) = n;
    *(char *)((char *)n + 0x15) = 1;
    *(void **)((char *)n + 4) = n;
    *(void **)n = n;
    *(void **)((char *)n + 8) = n;
    *(void **)(q + 8) = 0;

    q = p + 0x40;
    n = sub_0098211a(0x18);
    *(void **)(q + 4) = n;
    *(char *)((char *)n + 0x15) = 1;
    *(void **)((char *)n + 4) = n;
    *(void **)n = n;
    *(void **)((char *)n + 8) = n;
    *(void **)(q + 8) = 0;

    *(void **)(p + 0x50) = 0;
    *(void **)(p + 0x54) = 0;
    *(void **)(p + 0x58) = 0;
    *(void **)(p + 0x60) = 0;
    *(void **)(p + 0x64) = 0;
    *(void **)(p + 0x68) = 0;
    *(void **)(p + 0x70) = 0;
    *(void **)(p + 0x74) = 0;
    *(void **)(p + 0x78) = 0;
    *(void **)(p + 0x80) = 0;
    *(void **)(p + 0x84) = 0;
    *(void **)(p + 0x88) = 0;
    *(void **)(p + 0x90) = 0;
    *(void **)(p + 0x94) = 0;
    *(void **)(p + 0x98) = 0;
    *(void **)(p + 0xa0) = 0;
    *(void **)(p + 0xa4) = 0;
    *(void **)(p + 0xa8) = 0;

    sub_00746ce0(p, 8, (void *)0xb4719c);
    sub_00746ce0(p, 1, (void *)0xb5583c);
    sub_00746ce0(p, 2, (void *)0xb55840);
}
