// from server: 100% by atomic.potato
struct TToolVerb
{
    int pad0;
    int pad1;
    int pad2;
    int pad3;
    char f();
};

extern "C" int __cdecl sub_7f5286(int);
extern "C" int (__thiscall *sub_98b768)(int, int);

char TToolVerb::f()
{
    int a;
    int b;

    a = *(int *)((char *)this + 12);
    b = *(int *)((char *)a + 0xa90);
    a = *(int *)((char *)b + 0x1b4);
    if (a)
    {
        a = sub_7f5286(a);
        return sub_98b768(0xb3f46c, a);
    }
    return 0;
}
