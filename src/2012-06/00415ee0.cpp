// from server: 88% by atomic.potato
extern "C" void __stdcall func_004157e0();

struct CIDEBrowserView
{
    void func(void* a, int* b);
};

void CIDEBrowserView::func(void* a, int* b)
{
    void* p = *(void**)((char*)a + 12);
    if (*(int*)((char*)p + 252) == 5)
    {
        func_004157e0();
        *b = 1;
    }
}
