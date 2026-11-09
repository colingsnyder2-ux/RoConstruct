// from server: 40% by atomic.potato
struct GuiTarget {
    char pad0[8];
    void* field8;
    char padC[4];
    void* field10;
    void __cdecl method(void* a, void* b, void* c, void* d);
};

void GuiTarget::method(void* a, void* b, void* c, void* d) {
    if (field10 != 0) {
        void** vtbl = *(void***)field8;
        void (__stdcall *fn)(void*, void*, void*, void*, void*) = (void (__stdcall *)(void*, void*, void*, void*, void*))vtbl[0];
        fn((char*)this + 8, a, b, c, d);
    }
}
