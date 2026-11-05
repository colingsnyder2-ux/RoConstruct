// from server: 100% by colin
struct CSelectionTreeCtrl;

extern "C" int __stdcall func_006a0e9c(int, int, int, int);

struct Inner
{
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
    virtual void vfunc4();
    virtual int vfunc5(int, int, int, int);
};

extern Inner* g_96c238;

int __stdcall func_00422960(int a, int b, int c, int d)
{
    if (func_006a0e9c(a, b, c, d))
        return 1;
    if (g_96c238 == 0)
        return 0;
    return g_96c238->vfunc5(a, b, c, d);
}
