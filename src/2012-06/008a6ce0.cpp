// from server: 53% by atomic.potato
struct S
{
    int f();
};

extern "C" int __cdecl sub_495f40(void *);
extern "C" int __cdecl sub_983b6a(int);
extern "C" int (__cdecl *sub_b229ec)(void *, int);

int S::f()
{
    int a = sub_495f40(*(void **)((char *)this + 0x0c));
    if (!a)
        return 0;
    return sub_b229ec((void *)0x00dec618, sub_983b6a(a));
}
