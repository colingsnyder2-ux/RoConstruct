// from server: 77% by atomic.potato
extern "C" int sub_495f40(void *);
extern "C" int __cdecl sub_983b6a(int);
extern "C" void (__cdecl *sub_b229ec)(int);

struct S
{
    int *value;
    int f();
};

int S::f()
{
    int v = sub_495f40((void *)value[0x2b1]);
    if (v)
    {
        v = sub_983b6a(v);
        sub_b229ec(v);
    }
    return 0;
}
