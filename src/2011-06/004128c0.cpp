// from server: 43% by atomic.potato
extern "C" int G1_func_00A426B0(void*);

struct CIDEBrowserView
{
    int f(void*);
};

int CIDEBrowserView::f(void* p)
{
    int v = G1_func_00A426B0((char*)this + 0x2b0);
    return ((int (__stdcall *)(void*, int))(*(void**) *(void**)p))(p, v == 0);
}
