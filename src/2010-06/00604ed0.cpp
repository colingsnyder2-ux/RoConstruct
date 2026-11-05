// from server: 74% by atomic.potato
struct VWorkspaceRefPropDescriptor {
    char pad[0x20];
    void* field20;
    void invoke(void* a, void* b);
};

extern "C" void* __cdecl sub_00604e80(void* p);

void VWorkspaceRefPropDescriptor::invoke(void* a, void* b) {
    void* v;
    if (a) {
        v = sub_00604e80(a);
    } else {
        v = 0;
    }
    void* p = field20;
    void* q = *(void**)p;
    void (*fn)(void*, void*, void*) = *(void (**)(void*, void*, void*))((char*)q + 0x10);
    fn(p, v, b);
}
