// from server: 100% by atomic.potato
struct CIDEBrowserView
{
    void f(int, int*);
    void f();
};

void CIDEBrowserView::f(int a, int* b)
{
    struct T
    {
        char pad[252];
        int value;
    };

    T* p = *(T**)((char*)a + 12);
    if (p->value == 5)
    {
        f();
        *b = 1;
    }
}
