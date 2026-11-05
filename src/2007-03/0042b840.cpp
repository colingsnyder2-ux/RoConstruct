// from server: 100% by tester
struct CLuaHtmlView {
    int unknown0[61];
    void* field_f4;
    int GetSomething(void** out);
};

int CLuaHtmlView::GetSomething(void** out) {
    if (out == 0) {
        return 0x80004003;
    }
    *out = field_f4;
    void* p = field_f4;
    if (p != 0) {
        void** vtable = *(void***)p;
        void (__stdcall *fn)(void*) = (void (__stdcall *)(void*))vtable[1];
        fn(p);
    }
    return 0;
}
