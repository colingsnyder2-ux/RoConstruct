// from server: 74% by atomic.potato
extern "C" void* __cdecl sub_6342F0(void*);

struct VInstance {
    void* field0;
    char pad[0x1C];
    void* field20;
    void method(int, void*);
};

void VInstance::method(int a, void* b) {
    void* v;
    if (b) {
        v = sub_6342F0(b);
    } else {
        v = 0;
    }
    void* p = field20;
    void** vt = *(void***)p;
    void (*fn)(void*, int, void*) = (void (*)(void*, int, void*))vt[4];
    fn(p, a, v);
}
