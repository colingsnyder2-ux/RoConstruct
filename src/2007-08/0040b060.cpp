// from server: 100% by colin
struct CNullDoc {
    char pad[0xec];
    void* field_ec;
    void method();
};

void CNullDoc::method() {
    void* p = field_ec;
    void** vtbl = *(void***)p;
    void (__stdcall *fn)(void*) = (void (__stdcall *)(void*))vtbl[8];
    fn(p);
}
