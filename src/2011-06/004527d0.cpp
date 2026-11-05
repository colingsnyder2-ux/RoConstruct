// from server: 68% by atomic.potato
struct CRenderSettings {
    char pad0[0x24];
    unsigned int count;
    char pad1[0x60];
    void** items;
};

struct EnumDesc {
    int tag;
    void* value;
};

extern "C" void* __cdecl operator_new(unsigned int size);

struct W4GraphicsMode {
    bool get(unsigned int index, EnumDesc** out);
};

bool W4GraphicsMode::get(unsigned int index, EnumDesc** out) {
    void* value;
    bool found;
    if (index < ((CRenderSettings*)this)->count) {
        value = ((CRenderSettings*)this)->items[index];
        found = true;
    } else {
        value = *(void**)((char*)out + 4);
        found = false;
    }
    EnumDesc* desc = (EnumDesc*)operator_new(8);
    if (desc) {
        desc->tag = 0xa6cbac;
        desc->value = value;
    } else {
        desc = 0;
    }
    EnumDesc* old = *out;
    if (out != (EnumDesc**)&out) {
        old = *out;
        *out = desc;
    }
    if (old) {
        void** vtbl = *(void***)old;
        void (*dtor)(void*, int) = (void (*)(void*, int))vtbl[0];
        dtor(old, 1);
    }
    return found;
}
