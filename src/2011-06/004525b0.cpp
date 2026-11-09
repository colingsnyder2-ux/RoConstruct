// from server: 74% by atomic.potato
struct CRenderSettings {
    char pad0[0x24];
    unsigned int count;
    char pad1[0x60];
    void** items;
    bool getSample(unsigned int index, void** out);
};

extern "C" void* __cdecl operator_new(unsigned int size);

bool CRenderSettings::getSample(unsigned int index, void** out) {
    void* value;
    bool found;
    if (index < count) {
        value = items[index];
        found = true;
    } else {
        value = *out;
        found = false;
    }
    void* obj = operator_new(8);
    if (obj) {
        *(void**)obj = (void*)0xa6cb7c;
        *(void**)((char*)obj + 4) = value;
    } else {
        obj = 0;
    }
    void* old = *out;
    *out = obj;
    if (old) {
        void** vtbl = *(void***)old;
        void (*fn)(void*, int) = (void (*)(void*, int))vtbl[0];
        fn(old, 1);
    }
    return found;
}
