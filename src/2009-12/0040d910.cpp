// from server: 88% by atomic.potato
struct CIDEBrowserView
{
    void Update(CIDEBrowserView *view, int *value);
};

extern void G1_func_0040d2e0();

void CIDEBrowserView::Update(CIDEBrowserView *view, int *value)
{
    if (*(int *)(*(int *)((char *)view + 0x0c) + 0xfc) == 5)
    {
        G1_func_0040d2e0();
        *value = 1;
    }
}
