// from server: 45% by atomic.potato
extern "C" void __stdcall XTextHost_Call(void *, void *);

struct XTextHost
{
    XTextHost * __cdecl f(void *, void *);
};

XTextHost *XTextHost::f(void *a, void *b)
{
    XTextHost *self = this;
    XTextHost_Call(a, b);
    return self;
}
