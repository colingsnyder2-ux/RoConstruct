// from server: 76% by atomic.potato
extern void G1_func_004a1aa0(void *);
extern void G2_func_004356f0(void *, void *);

struct CScriptDoc
{
    void f(void *);
};

void CScriptDoc::f(void *arg)
{
    G1_func_004a1aa0(this);
    G2_func_004356f0(*(void **)((char *)this + 0x54), arg);
}
