// from server: 52% by atomic.potato
struct S
{
    int f();
    int pad0[3];
};

extern "C" int __cdecl sub_495f40(void *);
extern "C" int __cdecl sub_983b6a(int);
extern "C" int (__cdecl *sub_b229ec)(int);

int S::f()
{
    int v = sub_495f40(*(int **)((char *)this + 0xc + 0xac4));
    if (!v)
        return 0;
    v = sub_983b6a(v);
    return sub_b229ec(v);
}
