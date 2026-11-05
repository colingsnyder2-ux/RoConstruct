// from server: 86% by atomic.potato
typedef int (__stdcall *Func)(void*);

extern Func g_func;

struct CWebToolbox
{
    int pad;
    int value;
    void f(int);
};

void CWebToolbox::f(int)
{
    if (!g_func(this))
        value |= 0x1844017;
}
