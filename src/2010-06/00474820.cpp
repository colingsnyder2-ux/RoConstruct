// from server: 72% by atomic.potato
extern "C" void __stdcall func_00436ee0(void *);

extern "C" int __stdcall PostMessageA(void *, unsigned int, unsigned int, long);

struct CScriptReviewView
{
    int f(int);
};

int CScriptReviewView::f(int)
{
    void *p = *(void **)((char *)this + 0x380);
    if (p)
    {
        func_00436ee0(p);
        return 0;
    }

    void *window = *(void **)((char *)this + 0x20);
    if (window)
        PostMessageA(window, 0x465, 0, 0);

    return 0;
}
