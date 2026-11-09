// from server: 72% by atomic.potato
struct EnumDesc {
    char pad0[0x24];
    unsigned int count;
    char pad1[0x60];
    void** items;
    void* operator_new(unsigned int);
    void operator_delete(void*);
    bool assign(unsigned int index, void** out);
};

bool EnumDesc::assign(unsigned int index, void** out) {
    void* value;
    bool found;
    if (index < count) {
        value = items[index];
        found = true;
    } else {
        value = *out;
        found = false;
    }
    void* node = operator_new(8);
    if (node) {
        *(void**)node = (void*)0xa8ed40;
        *(void**)((char*)node + 4) = value;
    } else {
        node = 0;
    }
    void* old = *out;
    if (out != &old) {
        old = *out;
        *out = node;
    }
    if (old) {
        void** vtbl = *(void***)old;
        void (*dtor)(void*, int) = (void (*)(void*, int))vtbl[0];
        dtor(old, 1);
    }
    return found;
}
