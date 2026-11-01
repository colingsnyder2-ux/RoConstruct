// from server: 89% by atomic.potato
extern "C" int __stdcall G1_func_007f3e30(void *, void *);

struct CXTSplitterWnd
{
    int f(void *, void *);
};

int CXTSplitterWnd::f(void *a, void *b)
{
    if (*(unsigned char *)((char *)this + 0x108) & 8)
        return 0x12;
    return G1_func_007f3e30(a, b);
}
