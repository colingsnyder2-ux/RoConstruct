// from server: 100% by atomic.potato
extern "C" int __stdcall sub_007f3c0e(void*);

struct CIDEBrowserView
{
    void f(int* value);
};

void CIDEBrowserView::f(int* value)
{
    if (!sub_007f3c0e(value))
        value[1] |= 0x01844016;
}
