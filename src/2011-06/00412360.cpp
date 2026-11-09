// from server: 100% by atomic.potato
struct CIDEBrowserView
{
    void f(void *);
};

extern "C" int __stdcall sub_0080A40C(void *);

void CIDEBrowserView::f(void *p)
{
    if (!sub_0080A40C(p))
        *(unsigned int *)((unsigned char *)p + 4) |= 0x01844016;
}
