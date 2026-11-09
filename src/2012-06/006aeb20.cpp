// from server: 33% by atomic.potato
typedef unsigned int DWORD;

extern "C" void __stdcall sub_6AD1B0(void *, void *, void *, void *);
extern "C" void __stdcall sub_5715D0(void *, void *);
extern "C" void *__cdecl sub_7092A0();

struct BoundFuncDesc
{
    char padding[0x30];
    void *field30;
    void *field34;
    void *field38;
    void invoke(void *, void *, void *, void *, void *, void *, void *);
};

void BoundFuncDesc::invoke(void *a, void *b, void *c, void *d, void *e, void *f, void *g)
{
    sub_6AD1B0(this, a, b, c);
    field30 = d;
    field34 = e;
    field38 = 0;
    char buf[0x44];
    buf[0x14] = 1;
    void *p = buf;
    *(void **)p = sub_7092A0();
    *(void **)((char *)p + 4) = 0;
    sub_5715D0(this, f);
}
