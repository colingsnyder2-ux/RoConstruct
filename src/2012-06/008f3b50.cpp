// from server: 74% by atomic.potato
extern "C" void* __cdecl sub_68ECB0(void*);

struct VModelInstance {
    char pad[0x2c];
    void* field_2c;
    void method(int, void*);
};

void VModelInstance::method(int a, void* b) {
    void* v;
    if (b) {
        v = sub_68ECB0(b);
    } else {
        v = 0;
    }
    void* p = field_2c;
    void** vt = *(void***)p;
    void (*fn)(void*, int, void*) = (void (*)(void*, int, void*))vt[3];
    fn(p, a, v);
}
