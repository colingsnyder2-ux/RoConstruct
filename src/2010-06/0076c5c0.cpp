// from server: 0% by atomic.potato
struct Slot {
    int a;
    int b;
    int c;
    char pad[0x40];
    char flag;
    char flag2;
};

extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl sub_76C140(void*, int);

Slot* __cdecl make_slot(int a, int b, int c, int d, char e)
{
    Slot* p = (Slot*)operator_new(0x50);
    if (p)
    {
        p->a = a;
        p->b = b;
        p->c = c;
        sub_76C140(&p->pad[0], d);
        p->flag = e;
        p->flag2 = 0;
    }
    return p;
}
