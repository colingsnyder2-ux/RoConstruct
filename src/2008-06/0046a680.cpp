// from server: 100% by atomic.potato
struct CWebToolbox
{
    void f(void *);
};

extern "C" int __stdcall func_006a0a34(void *);

void CWebToolbox::f(void *p)
{
    if (!func_006a0a34(p))
        *(int *)((char *)p + 4) |= 0x1844017;
}
