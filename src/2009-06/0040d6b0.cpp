// from server: 100% by why2
struct CIDEBrowserView {
    void f();
};

void CIDEBrowserView::f() {
    char* p = *(char**)((char*)this + 0xf0);
    void** vtbl = *(void***)p;
    void (__stdcall *fn)(char*) = (void (__stdcall *)(char*))vtbl[7];
    fn(p);
}
