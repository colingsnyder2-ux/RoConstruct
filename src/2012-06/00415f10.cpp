// from server: 74% by atomic.potato
struct CIDEBrowserView {
    char pad[0x2b0];
    char field_2b0[4];
    void invoke();
};

extern "C" void* __stdcall sub_b2479c(void*, const char*);
extern "C" void* __stdcall sub_b24798(void*, int, int, int, int, int);
extern "C" void __cdecl sub_9823f6(void*, void*);

void CIDEBrowserView::invoke() {
    void* p = sub_b2479c(field_2b0, "RBXAuthenticationNegotiation:");
    if (p) {
        void* q = sub_b24798(field_2b0, 0, 0, 0, 0, 0);
        sub_9823f6(this, q);
    }
}
