// from server: 82% by atomic.potato
typedef int HRESULT;

struct VTable
{
    int pad0;
    int pad1;
    HRESULT (__stdcall *Release)(void *);
};

struct S
{
    void *vftable;
    int unknown4;
    void *mediaType;
    int f();
};

extern "C" void __stdcall operator_delete(void *);

int S::f()
{
    void *p = (char *)mediaType + 12;
    vftable = (void *)0x00b64118;
    VTable *v = *(VTable **)p;
    v->Release(p);
    if (*((unsigned char *)(&p) + 8) & 1)
        operator_delete(this);
    return (int)this;
}
