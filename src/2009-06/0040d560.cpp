// from server: 100% by why2
struct CIDEBrowserView
{
    char pad[0xf0];
    void* field_f0;
    void Release();
};

void CIDEBrowserView::Release()
{
    void* p = field_f0;
    void** vtbl = *(void***)p;
    void (__stdcall *fn)(void*) = (void (__stdcall *)(void*))vtbl[0x30 / 4];
    fn(p);
}
