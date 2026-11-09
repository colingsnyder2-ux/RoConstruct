// from server: 74% by atomic.potato
struct S_005ca000 {
    char pad0[0x24];
    unsigned int count;
    char pad1[0x60];
    void** items;
    bool f(unsigned int idx, void** out);
};

extern "C" void* __cdecl alloc_0080a05e(int);

bool S_005ca000::f(unsigned int idx, void** out) {
    void* item;
    bool ok;
    if (idx < count) {
        item = items[idx];
        ok = true;
    } else {
        item = *out;
        ok = false;
    }
    void* p = alloc_0080a05e(8);
    if (p) {
        *(void**)p = (void*)0xa8f340;
        *((void**)p + 1) = item;
    } else {
        p = 0;
    }
    void* old = *out;
    *out = p;
    if (old) {
        void** vt = *(void***)old;
        void (*fn)(void*, int) = (void (*)(void*, int))vt[0];
        fn(old, 1);
    }
    return ok;
}
