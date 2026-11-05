// from server: 74% by atomic.potato
extern "C" void* __cdecl sub_680470(void*);

struct VModelInstance {
    char pad[0x20];
    void* field20;
    void method(int, void*);
};

void VModelInstance::method(int a, void* b) {
    void* v;
    if (b) {
        v = sub_680470(b);
    } else {
        v = 0;
    }
    void* p = field20;
    void** vt = *(void***)p;
    void (*fn)(void*, int, void*) = (void (*)(void*, int, void*))vt[4];
    fn(p, a, v);
}
