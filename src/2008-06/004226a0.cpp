// from server: 100% by tester
struct CSelectionTreeCtrl
{
    char pad[0x5c];
    void* field_5c;
};

struct Inner
{
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
    virtual void vfunc4(void*);
};

void __stdcall func_0041f7e0(CSelectionTreeCtrl* self, int* arg2)
{
    Inner* p = (Inner*)self->field_5c;
    p->vfunc4(*(void**)((char*)self + 0xc));
    *arg2 = 0;
}
