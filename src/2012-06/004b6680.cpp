// from server: 61% by atomic.potato
struct CEnumPins
{
    void Next(int *p);
};

extern "C" void __stdcall sub_4B9300(void *);

void CEnumPins::Next(int *p)
{
    int *obj = *(int **)((char *)p + 0xc);
    int (*fn1)(void *) = *(int (**)(void *))((char *)*(int **)obj + 0x14);
    *(int *)((char *)p + 0x10) = fn1(obj);
    obj = *(int **)((char *)p + 0xc);
    int (*fn2)(void *) = *(int (**)(void *))((char *)*(int **)obj + 0x18);
    *(int *)((char *)p + 8) = fn2(obj);
    *(int *)((char *)p + 4) = 0;
    sub_4B9300((char *)p + 0x18);
}
