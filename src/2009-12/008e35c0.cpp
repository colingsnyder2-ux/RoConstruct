// from server: 100% by atomic.potato
extern "C" void * __stdcall Function_008c0270(void *, int);

struct CXTShadowWnd
{
    void f(void *);
    void g(void *);
};

void CXTShadowWnd::f(void *arg)
{
    void *value = Function_008c0270(arg, 0);
    g(value);
}
