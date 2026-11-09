// from server: 61% by atomic.potato
extern "C" void* __stdcall sub_8DE090(void*);

struct S {
    char pad[0x2c];
    void* field_2c;
    void method(void* a, void* b);
};

void S::method(void* a, void* b) {
    void* v;
    if (a) {
        v = sub_8DE090(a);
    } else {
        v = 0;
    }
    void* p = field_2c;
    void** vt = *(void***)p;
    void (*fn)(void*, void*, void*) = (void (*)(void*, void*, void*))vt[3];
    fn(p, b, v);
}
