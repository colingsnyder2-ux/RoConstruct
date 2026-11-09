// from server: 70% by atomic.potato
extern "C" void __cdecl sub_40d380(void *);

struct S {
    int v0;
    int v1;
    int v2;
    int v3;
    int v4;
    int f(void *);
};

int S::f(void *p)
{
    sub_40d380(p);
    v4 = 0x00b43c34;
    v0 = 0x00b44320;
    v3 = 0x00b44318;
    v4 = 0x00b44308;
    return (int)this;
}
