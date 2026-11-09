// from server: 47% by atomic.potato
struct S {
    char pad[0x20];
    void* field20;
    void method(void*);
};

extern "C" void* __stdcall sub_7218F0(void*);

void S::method(void* arg) {
    void* v;
    if (arg) {
        v = sub_7218F0(arg);
    } else {
        v = 0;
    }
    void** p = (void**)field20;
    void (*fn)(void*, void*) = (void (*)(void*, void*))p[3];
    fn(field20, v);
}
